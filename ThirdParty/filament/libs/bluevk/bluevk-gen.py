#!/usr/bin/python3

# Copyright (C) 2022 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
----------------------------------------------------------------------------------------------------
WARNING:

When running this script, be sure to also update headers in bluevk/include as described below.
Also, do not update vk_platform.h or accidentally add unused hpp headers.
----------------------------------------------------------------------------------------------------

Generates C++ code that binds Vulkan entry points at run time and provides enum-to-string
conversion operators. By default this fetches the latest vk.xml from github; note that
the XML needs to be consistent with the Vulkan headers that live in bluevk/include/vulkan,
which are obtained from:

https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/main/include/vulkan/vulkan_core.h

If the XML file is inconsistent with the checked-in header files, compile errors can result
such as missing enumeration values, or "type not found" errors.

TODO: To reduce globals and conditional branching, it would be nice if BlueVK were to implement
actual functions rather than declaring function pointers, similar to BlueGL. However this may be
tricky because Instance-specific fuctions must be loaded via vkGetInstanceProcAddr, not dlsym.
"""

import argparse
import os
import re
import xml.etree.ElementTree as etree
import urllib.request
from collections import OrderedDict
from collections import namedtuple
from datetime import datetime

VkFunction = namedtuple('VkFunction', ['name', 'type', 'group'])

VK_XML_URL = "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/main/registry/vk.xml"

COPYRIGHT_HEADER = '''/*
 * Copyright (C) %(year)d The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**********************************************************************************************
 * Generated by bluevk/bluevk-gen.py
 * DO NOT EDIT
 **********************************************************************************************/

''' % {
    'year':       datetime.now().year,
}

HEADER_FILE_TEMPLATE = COPYRIGHT_HEADER + '''
#ifndef TNT_FILAMENT_BLUEVK_H
#define TNT_FILAMENT_BLUEVK_H

#define VK_ENABLE_BETA_EXTENSIONS

// BlueVK dynamically loads all function pointers, so it cannot allow function prototypes, which
// would assume static linking for Vulkan entry points.
#if defined(VULKAN_H_) && !defined(VK_NO_PROTOTYPES)
#error Please do not include vulkan.h when using BlueVK
#endif

// Even though we don't use function prototypes, we still need to include vulkan.h for all Vulkan
// types, including the PFN_ types.
#ifndef VULKAN_H_
    #ifndef VK_NO_PROTOTYPES
    #define VK_NO_PROTOTYPES
    #endif
    #include <vulkan/vulkan.h>
#endif

#include "third_party/filament/libs/utils/include/utils/unwindows.h"

namespace bluevk {

    // Returns false if BlueGL could not find the Vulkan shared library.
    bool initialize();

    void bindInstance(VkInstance instance);

%(FUNCTION_POINTERS)s

} // namespace bluevk

#if !defined(NDEBUG)
#include "third_party/filament/libs/utils/include/utils/Log.h"
%(ENUM_DECLS)s
#endif

#endif // TNT_FILAMENT_BLUEVK_H
'''

CPP_FILE_TEMPLATE = COPYRIGHT_HEADER + '''
#include <bluevk/BlueVK.h>

namespace bluevk {

static void loadLoaderFunctions(void* context, PFN_vkVoidFunction (*loadcb)(void*, const char*));
static void loadInstanceFunctions(void* context, PFN_vkVoidFunction (*loadcb)(void*, const char*));
static void loadDeviceFunctions(void* context, PFN_vkVoidFunction (*loadcb)(void*, const char*));
static PFN_vkVoidFunction vkGetInstanceProcAddrWrapper(void* context, const char* name);
static PFN_vkVoidFunction vkGetDeviceProcAddrWrapper(void* context, const char* name);

// OS Dependent.
extern bool loadLibrary();
extern void* getInstanceProcAddr();

bool initialize() {
    if (!loadLibrary()) {
        return false;
    }

    vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr) getInstanceProcAddr();
    loadLoaderFunctions(nullptr, vkGetInstanceProcAddrWrapper);
    return true;
}

void bindInstance(VkInstance instance) {
    loadInstanceFunctions(instance, vkGetInstanceProcAddrWrapper);
    loadDeviceFunctions(instance, vkGetInstanceProcAddrWrapper);
}

static PFN_vkVoidFunction vkGetInstanceProcAddrWrapper(void* context, const char* name) {
    return vkGetInstanceProcAddr((VkInstance) context, name);
}

static PFN_vkVoidFunction vkGetDeviceProcAddrWrapper(void* context, const char* name) {
    return vkGetDeviceProcAddr((VkDevice) context, name);
}

static void loadLoaderFunctions(void* context, PFN_vkVoidFunction (*loadcb)(void*, const char*)) {
%(LOADER_FUNCTIONS)s
}

static void loadInstanceFunctions(void* context, PFN_vkVoidFunction (*loadcb)(void*, const char*)) {
%(INSTANCE_FUNCTIONS)s
}

static void loadDeviceFunctions(void* context, PFN_vkVoidFunction (*loadcb)(void*, const char*)) {
%(DEVICE_FUNCTIONS)s
}

%(FUNCTION_POINTERS)s

} // namespace bluevk

#if !defined(NDEBUG)
#include "third_party/filament/libs/utils/include/utils/Log.h"
%(ENUM_DEFS)s
#endif

'''

def isAncestor(types, name, base):
    """
    Returns true if 'base' is an ancestor of 'name'.
    Particularly useful for checking if a given Vulkan type descends from VkDevice or VkInstance.
    """
    if name == base:
        return True
    type = types.get(name)
    if type is None:
        return False
    parent = type.get('parent')
    if not parent:
        return False
    return isAncestor(types, parent, base)

def consumeXML(spec):
    print('Consuming XML...')

    # First build a list of function groups. Function groups are things like
    # "VK_API_VERSION_1_1" or "VK_NV_external_memory_win32".
    command_groups = OrderedDict()
    for feature in spec.findall('feature'):
        key = feature.get('name')
        cmdrefs = feature.findall('require/command')
        command_groups[key] = [cmdref.get('name') for cmdref in cmdrefs]
    for ext in sorted(spec.findall('extensions/extension'), key=lambda ext: ext.get('name')):
        name = ext.get('name')
        for req in ext.findall('require'):
            reqs = [name]
            if req.get('feature'):
                reqs.append(req.get('feature'))
            if req.get('extension'):
                reqs.append(req.get('extension'))
            key = ' && '.join(reqs)
            if len(reqs) > 1:
                key = '({})'.format(key)
            cmdrefs = req.findall('command')
            command_groups.setdefault(key, []).extend([cmdref.get('name') for cmdref in cmdrefs])

    # Build a list of unnecessary types that should be skipped to avoid codegen problems. Many of
    # these types seem to be only partially defined in the XML spec, or defined in a manner that
    # is inconsistent with other types.
    provisional_types = set([
        'VkFullScreenExclusiveEXT',
    ])
    for ext in spec.findall('extensions/extension'):
        if ext.get('platform') == 'provisional':
            for req in ext.findall('require'):
                for enum in req.findall('type'):
                    provisional_types.add(enum.get('name'))

    # If the same function exists in more than one function group, consolidate them.
    commands_to_groups = OrderedDict()
    for (group, cmdnames) in command_groups.items():
        for name in cmdnames:
            commands_to_groups.setdefault(name, []).append(group)
    for (group, cmdnames) in command_groups.items():
        command_groups[group] = [name for name in cmdnames if len(commands_to_groups[name]) == 1]
    for (name, groups) in commands_to_groups.items():
        if len(groups) == 1:
            continue
        key = ' || '.join(groups)
        command_groups.setdefault(key, []).append(name)
    del commands_to_groups

    # Build a mapping from function names to XML descriptions, honoring aliases.
    commands = {}
    for cmd in spec.findall('commands/command'):
        if not cmd.get('alias'):
            name = cmd.findtext('proto/name')
            commands[name] = cmd
    for cmd in spec.findall('commands/command'):
        if cmd.get('alias'):
            name = cmd.get('name')
            commands[name] = commands[cmd.get('alias')]

    # Look at types to find ancestors of VkDevice and VkInstance, and to find all enums.
    types = {}
    enum_types = []
    for type in spec.findall('types/type'):
        name = type.findtext('name')
        if name:
            types[name] = type
        if type.get('category') == 'enum':
            enum_types.append(type.get('name'))
    print('{} enums'.format(len(enum_types)))

    # Look at all enumerants.
    enum_vals = OrderedDict()
    flag_vals = OrderedDict()
    for enums in spec.findall('enums'):
        # Skip over weird hardcoded constants
        if not enums.get('type'): continue
        name = enums.get('name')
        if name not in enum_types: continue
        if name in provisional_types: continue

        # Special handling for single-bit flags
        if enums.get('type') == 'bitmask':
            print('FLAGS ' + name)
            flag_vals[name] = []
            for val in enums:
                # Skip over comments
                if val.tag != 'enum': continue
                value = 0
                if val.get('value'):
                    value = int(val.get('value'), 16)
                elif val.get('bitpos'):
                    value = 1 << int(val.get('bitpos'))
                value = '0x%08x' % value
                print('\t' + value + ' ' + val.get('name'))
                flag_vals[name].append((val.get('name'), value))
            continue

        print(name)
        enum_vals[name] = []
        for val in enums:
            # Skip over comments
            if val.tag != 'enum': continue
            # Skip over intermingled single-bit flags
            if not val.get('value'): continue
            print('\t' + val.get('value') + ' ' + val.get('name'))
            enum_vals[name].append(val.get('name'))

    # Finally, build the VkFunction objects.
    function_groups = OrderedDict()
    for (group, cmdnames) in command_groups.items():
        function_group = function_groups.setdefault(group, OrderedDict())
        for name in sorted(cmdnames):
            cmd = commands[name]
            type = cmd.findtext('param[1]/type')
            if name == 'vkGetDeviceProcAddr':
                type = 'VkInstance'
            if isAncestor(types, type, 'VkDevice'):
                ftype = 'device'
            elif isAncestor(types, type, 'VkInstance'):
                ftype = 'instance'
            elif type != '':
                ftype = 'loader'
            function_group[name] = VkFunction(name = name, type = ftype, group = group)
    return function_groups, enum_vals, flag_vals

def produceHeader(function_groups, enum_vals, flag_vals, output_dir):
    fullpath = os.path.join(output_dir, 'bluevk/BlueVK.h')
    print('\nProducing header %s...' % fullpath)
    enum_decls = []
    decls = []
    for (enum_name, vals) in enum_vals.items():
        enum_decls.append('utils::io::ostream& operator<<(utils::io::ostream& out, ' +
            'const {}& value);'.format(enum_name))
    for (group, functions) in function_groups.items():
        if not len(functions):
            continue
        preproc_expr = re.sub(r'(VK_[A-Za-z_0-9]+)', r'defined(\1)', group)
        decls.append('#if ' + preproc_expr)
        for (name, fn) in functions.items():
            decls.append("extern PFN_%(name)s %(name)s;" % {'name': fn.name})
        decls.append('#endif // ' + preproc_expr)
    with open(fullpath, 'w') as file:
        file.write(HEADER_FILE_TEMPLATE % {
            'ENUM_DECLS': '\n'.join(enum_decls),
            'FUNCTION_POINTERS': '\n'.join(decls)})

def produceCpp(function_groups, enum_vals, flag_vals, output_dir):
    fullpath = os.path.join(output_dir, 'BlueVK.cpp')
    print('\nProducing source %s...' % fullpath)
    enum_defs = []
    loader_functions = []
    instance_functions = []
    device_functions = []
    function_pointers = []
    for (enum_name, vals) in enum_vals.items():
        enum_defs.append('utils::io::ostream& operator<<(utils::io::ostream& out, ' +
            'const {}& value) {{'.format(enum_name))
        enum_defs.append('    switch (value) {')
        for val in vals:
            enum_defs.append('        case {0}: out << "{0}"; break;'.format(val))
        # Always include a "default" to catch aliases (such as MAX_ENUM) and eliminate warnings.
        enum_defs.append('        default: out << "UNKNOWN"; break;')
        enum_defs.append('    }')
        enum_defs.append('    return out;')
        enum_defs.append('}')
    for (group, functions) in function_groups.items():
        if not len(functions):
            continue
        preproc_expr = re.sub(r'(VK_[A-Za-z_0-9]+)', r'defined(\1)', group)

        has_instance = False
        has_device = False
        has_loader = False
        for (name, fn) in functions.items():
            if fn.type == 'instance':
                has_instance = True
            elif fn.type == 'device':
                has_device = True
            elif fn.type == 'loader':
                has_loader = True

        function_pointers.append('#if ' + preproc_expr)
        if has_instance:
            instance_functions.append('#if ' + preproc_expr)
        if has_device:
            device_functions.append('#if ' + preproc_expr)
        if has_loader:
            loader_functions.append('#if ' + preproc_expr)

        for (name, fn) in functions.items():
            # Emit the function definition.
            function_pointers.append("PFN_%(name)s %(name)s;" % {'name': fn.name})

            # This function pointer is already manually loaded, so do not emit the loader call.
            if name == 'vkGetInstanceProcAddr':
                continue

            # Emit the loader call.
            loadfn = '    %(name)s = (PFN_%(name)s) loadcb(context, "%(name)s");' % {
                'name': fn.name }
            if fn.type == 'instance':
                instance_functions.append(loadfn)
            elif fn.type == 'device':
                device_functions.append(loadfn)
            elif fn.type == 'loader':
                loader_functions.append(loadfn)

        function_pointers.append('#endif // ' + preproc_expr)
        if has_instance:
            instance_functions.append('#endif // ' + preproc_expr)
        if has_device:
            device_functions.append('#endif // ' + preproc_expr)
        if has_loader:
            loader_functions.append('#endif // ' + preproc_expr)

    with open(fullpath, 'w') as file:
        file.write(CPP_FILE_TEMPLATE % {
            'ENUM_DEFS': '\n'.join(enum_defs),
            'LOADER_FUNCTIONS': '\n'.join(loader_functions),
            'INSTANCE_FUNCTIONS': '\n'.join(instance_functions),
            'DEVICE_FUNCTIONS': '\n'.join(device_functions),
            'FUNCTION_POINTERS': '\n'.join(function_pointers)})

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Blue Vulkan bindings generator.')
    parser.add_argument('-I', '--include', help='Parent location for bluevk/BlueVK.h')
    parser.add_argument('-o', '--output', help='Output directory for BlueVK.cpp')
    parser.add_argument('-s', '--specpath', help='Vulkan XML specification')
    args = parser.parse_args()

    spec = open(args.specpath, 'r') if args.specpath else urllib.request.urlopen(VK_XML_URL)
    spec_tree = etree.parse(spec)
    function_groups, enum_vals, flag_vals = consumeXML(spec_tree)

    include_dir = args.include if args.include else os.path.join(os.getcwd(), 'include')
    produceHeader(function_groups, enum_vals, flag_vals, include_dir)

    output_dir  = args.output if args.output else os.path.join(os.getcwd(), 'src')
    produceCpp(function_groups, enum_vals, flag_vals, output_dir)

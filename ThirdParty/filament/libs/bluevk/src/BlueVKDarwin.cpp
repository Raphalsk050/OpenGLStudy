

#include "third_party/filament/libs/utils/include/utils/Panic.h"

#include <dlfcn.h>

namespace bluevk {

static void* module = nullptr;

bool loadLibrary() {
#ifdef FILAMENT_VKLIBRARY_PATH
    const char* dylibPath = FILAMENT_VKLIBRARY_PATH;
#else
    const char* dylibPath = "libvulkan.1.dylib";
#endif

    module = dlopen(dylibPath, RTLD_NOW | RTLD_LOCAL);
    FILAMENT_CHECK_POSTCONDITION(module != nullptr)
            << "BlueVK is unable to load entry points: " << dlerror() << ".\n"
               "Install the LunarG SDK with 'System Global Installation' and reboot.\n";
    return module != nullptr;
}

void* getInstanceProcAddr() {
    return dlsym(module, "vkGetInstanceProcAddr");
}

} // namespace bluevk

load("@bazel_skylib//rules:build_test.bzl", "build_test")
load(
    "//third_party/filament:filament.bzl",
    "copy_files",
    "filament_copts",
    "filament_defines",
    "filament_dependees",
    "if_android",
    "if_apple",
    "if_linux_aarch64",
    "if_linux_desktop",
    "if_linux_headless",
    "if_linux_or_android",
    "if_linux_x86_64",
    "if_macos",
    "if_vulkan",
    "if_wasm",
    "if_windows",
    "uberarchive_args",
)

licenses(["notice"])

package(
    default_applicable_licenses = ["//third_party/filament:license"],
    default_visibility = ["//visibility:public"],
    features = [
        "-use_header_modules",  # Incompatible with -std=c++14.
    ],
)

exports_files([
    "gltfio/materials/base.mat.in",
    "gltfio/materials/base.spec.in",
])

cc_library(
    name = "math_hdrs",
    srcs = ["math/src/dummy.cpp"],
    hdrs = glob(["math/include/**"]),
    copts = filament_copts(),
    defines = filament_defines(),
    alwayslink = 1,
)

cc_library(
    name = "math",
    copts = filament_copts(),
    defines = filament_defines(),
    linkstatic = 1,
    deps = [":math_hdrs"],
    alwayslink = 1,
)

cc_library(
    name = "math_io",
    srcs = glob(["mathio/src/**"]),
    hdrs = glob(["mathio/include/**"]),
    copts = filament_copts(),
    defines = filament_defines(),
    includes = ["mathio/include"],
    linkstatic = 1,
    deps = [":math_hdrs"],
    alwayslink = 1,
)

cc_library(
    name = "utils_hdrs",
    hdrs = [
        "utils/include/utils/Allocator.h",
        "utils/include/utils/BinaryTreeArray.h",
        "utils/include/utils/BitmaskEnum.h",
        "utils/include/utils/CString.h",
        "utils/include/utils/CallStack.h",
        "utils/include/utils/Condition.h",
        "utils/include/utils/CountDownLatch.h",
        "utils/include/utils/Entity.h",
        "utils/include/utils/EntityInstance.h",
        "utils/include/utils/EntityManager.h",
        "utils/include/utils/FixedCapacityVector.h",
        "utils/include/utils/FixedCircularBuffer.h",
        "utils/include/utils/Hash.h",
        "utils/include/utils/Invocable.h",
        "utils/include/utils/JobSystem.h",
        "utils/include/utils/Log.h",
        "utils/include/utils/Mutex.h",
        "utils/include/utils/NameComponentManager.h",
        "utils/include/utils/Panic.h",
        "utils/include/utils/Path.h",
        "utils/include/utils/PrivateImplementation.h",
        "utils/include/utils/PrivateImplementation-impl.h",
        "utils/include/utils/Profiler.h",
        "utils/include/utils/QuadTree.h",
        "utils/include/utils/Range.h",
        "utils/include/utils/RangeMap.h",
        "utils/include/utils/SingleInstanceComponentManager.h",
        "utils/include/utils/Slice.h",
        "utils/include/utils/StructureOfArrays.h",
        "utils/include/utils/Systrace.h",
        "utils/include/utils/ThermalManager.h",
        "utils/include/utils/ThreadUtils.h",
        "utils/include/utils/WorkStealingDequeue.h",
        "utils/include/utils/algorithm.h",
        "utils/include/utils/android/PerformanceHintManager.h",
        "utils/include/utils/api_level.h",
        "utils/include/utils/architecture.h",
        "utils/include/utils/ashmem.h",
        "utils/include/utils/bitset.h",
        "utils/include/utils/compiler.h",
        "utils/include/utils/compressed_pair.h",
        "utils/include/utils/debug.h",
        "utils/include/utils/memalign.h",
        "utils/include/utils/ostream.h",
        "utils/include/utils/sstream.h",
        "utils/include/utils/string.h",
        "utils/include/utils/trap.h",
        "utils/include/utils/unwindows.h",
        "utils/include/utils/vector.h",
    ] + if_windows([
        "utils/include/utils/win32/stdtypes.h",
    ]) + if_android(
        [
            "utils/include/utils/android/ThermalManager.h",
            "utils/include/utils/linux/Mutex.h",
            "utils/include/utils/linux/Condition.h",
        ],
        [
            "utils/include/utils/generic/ThermalManager.h",
            "utils/include/utils/generic/Mutex.h",
            "utils/include/utils/generic/Condition.h",
        ],
    ),
    copts = filament_copts(),
    defines = filament_defines(),
    textual_hdrs = [
        "utils/include/utils/Zip2Iterator.h",
    ] + if_android([
        "utils/include/utils/android/Systrace.h",
    ]) + if_apple([
        "utils/include/utils/darwin/Systrace.h",
    ]),
    deps = ["@robin_map"],
    alwayslink = 1,
)

objc_library(
    name = "utils_path",
    srcs = ["utils/src/darwin/Path.mm"],
    hdrs = ["utils/include/utils/Path.h"],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = ["utils/include"],
    textual_hdrs = ["utils/include/utils/compiler.h"],
)

cc_library(
    name = "utils",
    srcs = [
        "utils/include/utils/CyclicBarrier.h",
        "utils/include/utils/NameComponentManager.h",
        "utils/src/Allocator.cpp",
        "utils/src/CString.cpp",
        "utils/src/CallStack.cpp",
        "utils/src/CountDownLatch.cpp",
        "utils/src/CyclicBarrier.cpp",
        "utils/src/EntityManager.cpp",
        "utils/src/EntityManagerImpl.h",
        "utils/src/JobSystem.cpp",
        "utils/src/Log.cpp",
        "utils/src/NameComponentManager.cpp",
        "utils/src/Panic.cpp",
        "utils/src/Path.cpp",
        "utils/src/Profiler.cpp",
        "utils/src/ThreadUtils.cpp",
        "utils/src/api_level.cpp",
        "utils/src/architecture.cpp",
        "utils/src/ashmem.cpp",
        "utils/src/debug.cpp",
        "utils/src/linux/Path.cpp",
        "utils/src/ostream.cpp",
        "utils/src/ostream_.h",
        "utils/src/sstream.cpp",
        "utils/src/string.cpp",
    ] + if_linux_or_android([
        "utils/src/linux/futex.h",
    ]) + if_android([
        "utils/src/android/PerformanceHintManager.cpp",
        "utils/src/android/Systrace.cpp",
        "utils/src/android/ThermalManager.cpp",
        "utils/src/linux/Condition.cpp",
        "utils/src/linux/Mutex.cpp",
    ]) + if_windows([
        "utils/src/win32/Path.cpp",
    ]) + if_apple([
        "utils/src/darwin/Systrace.cpp",
    ]) + if_wasm([
        "utils/src/web/Path.cpp",
    ]),
    copts = filament_copts(),
    defines = filament_defines(),
    linkopts = if_linux_or_android([
        "-ldl",
    ]),
    linkstatic = 1,
    deps = [
        ":utils_hdrs",
        "@robin_map",
    ] + if_apple([":utils_path"]),
    alwayslink = 1,
)

cc_library(
    name = "filabridge_hdrs",
    hdrs = glob([
        "filabridge/include/**/*.h",
    ]),
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "filabridge/include",
    ],
    linkstatic = 1,
    deps = [
        ":math_hdrs",
        ":utils_hdrs",
        "//third_party/filament/filament/backend:backend_hdrs",
        "//third_party/filament/filament/backend:driver_enums",
        "@robin_map",
    ],
    alwayslink = 1,
)

# Filament tool/runtime common code
cc_library(
    name = "filabridge",
    srcs = glob([
        "filabridge/src/**/*.cpp",
    ]),
    copts = filament_copts(),
    defines = filament_defines(),
    linkstatic = 1,
    textual_hdrs = glob([
        "filabridge/src/**/*.h",
    ]),
    deps = [
        ":filabridge_hdrs",
        ":math_hdrs",
        ":utils_hdrs",
        "//third_party/filament/filament/backend:driver_enums",
        "@robin_map",
    ],
    alwayslink = 1,
)

cc_library(
    name = "image_hdrs",
    hdrs = [
        "image/include/image/ColorTransform.h",
        "image/include/image/ImageOps.h",
        "image/include/image/ImageSampler.h",
        "image/include/image/Ktx1Bundle.h",
        "image/include/image/LinearImage.h",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "image/include",
    ],
    linkstatic = 1,
    deps = [
        ":filabridge_hdrs",
        ":math_hdrs",
        ":utils_hdrs",
        "//third_party/filament/filament:filament_hdrs",
    ],
    alwayslink = 1,
)

cc_library(
    name = "image",
    srcs = [
        "image/src/ImageOps.cpp",
        "image/src/ImageSampler.cpp",
        "image/src/Ktx1Bundle.cpp",
        "image/src/LinearImage.cpp",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    linkstatic = 1,
    deps = [
        ":image_hdrs",
        ":math_hdrs",
        ":utils",
        ":utils_hdrs",
    ],
    alwayslink = 1,
)

cc_library(
    name = "ktxreader",
    srcs = [
        "ktxreader/src/Ktx1Reader.cpp",
        "ktxreader/src/Ktx2Reader.cpp",
    ],
    hdrs = [
        "ktxreader/include/ktxreader/Ktx1Reader.h",
        "ktxreader/include/ktxreader/Ktx2Reader.h",
    ],
    # b/308454739: library depended by a linkstatic=0 cc_library cannot use
    # -fvisibility=hidden.
    copts = filament_copts() + ["-fvisibility=default"],
    defines = filament_defines(),
    includes = [
        "ktxreader/include",
    ],
    linkstatic = 1,
    deps = [
        ":image_hdrs",
        ":utils_hdrs",
        "//third_party/filament/filament:filament_hdrs",
        "@basis_universal",
        "@basis_universal//:basisu_headers_lib",
    ],
    alwayslink = 1,
)

cc_library(
    name = "ktxreader_hdrs",
    hdrs = [
        "ktxreader/include/ktxreader/Ktx1Reader.h",
        "ktxreader/include/ktxreader/Ktx2Reader.h",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "ktxreader/include",
    ],
    deps = [
        ":image_hdrs",
        ":utils_hdrs",
        "//third_party/filament/filament:filament_hdrs",
    ],
    alwayslink = 1,
)

# Filament image serialization library.
cc_library(
    name = "imageio",
    srcs = [
        "imageio/src/HDRDecoder.cpp",
        "imageio/src/ImageDecoder.cpp",
        "imageio/src/ImageDiffer.cpp",
        "imageio/src/ImageEncoder.cpp",
    ],
    hdrs = [
        "imageio/include/imageio/HDRDecoder.h",
        "imageio/include/imageio/ImageDecoder.h",
        "imageio/include/imageio/ImageDiffer.h",
        "imageio/include/imageio/ImageEncoder.h",
    ],
    copts = filament_copts() + [
        "-fexceptions",
    ],
    defines = filament_defines(),
    includes = [
        "imageio/include",
    ],
    linkopts = select({
        "@platforms//os:linux": [],
        "@platforms//os:android": [],
        "//conditions:default": [],
    }),
    textual_hdrs = glob([
        "imageio/src/**/*.h",
    ]),
    deps = [
        ":filabridge_hdrs",
        ":image",
        ":image_hdrs",
        ":math_hdrs",
        ":utils_hdrs",
        "@png",
        "@tinyexr",
    ],
    alwayslink = 1,
)

cc_library(
    name = "imageio_basis_encoder",
    srcs = [
        "imageio/src/BasisEncoder.cpp",
    ],
    hdrs = [
        "imageio/include/imageio/BasisEncoder.h",
    ],
    copts = filament_copts() + [
        "-fexceptions",
    ],
    defines = filament_defines(),
    includes = [
        "imageio/include",
    ],
    linkopts = select({
        "@platforms//os:linux": [],
        "@platforms//os:android": [],
        "//conditions:default": [],
    }),
    textual_hdrs = glob([
        "imageio/src/**/*.h",
    ]),
    deps = [
        ":image_hdrs",
        ":utils_hdrs",
        "@basis_universal",
        "@basis_universal//:basisu_headers_lib",
    ],
    alwayslink = 1,
)

cc_library(
    name = "ibl_hdrs",
    hdrs = [
        "ibl/include/ibl/Cubemap.h",
        "ibl/include/ibl/CubemapIBL.h",
        "ibl/include/ibl/CubemapSH.h",
        "ibl/include/ibl/CubemapUtils.h",
        "ibl/include/ibl/Image.h",
        "ibl/include/ibl/utilities.h",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "ibl/include",
    ],
    deps = [
        ":math_hdrs",
        ":utils_hdrs",
    ],
    alwayslink = 1,
)

cc_library(
    name = "ibl",
    srcs = [
        "ibl/src/Cubemap.cpp",
        "ibl/src/CubemapIBL.cpp",
        "ibl/src/CubemapSH.cpp",
        "ibl/src/CubemapUtils.cpp",
        "ibl/src/CubemapUtilsImpl.h",
        "ibl/src/Image.cpp",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    linkstatic = 1,
    deps = [
        ":ibl_hdrs",
        ":math_hdrs",
        ":utils_hdrs",
    ],
    alwayslink = 1,
)

cc_library(
    name = "geometry",
    srcs = [
        "geometry/src/MikktspaceImpl.cpp",
        "geometry/src/MikktspaceImpl.h",
        "geometry/src/SurfaceOrientation.cpp",
        "geometry/src/TangentSpaceMesh.cpp",
        "geometry/src/TangentSpaceMeshInternal.h",
        "geometry/src/Transcoder.cpp",
    ],
    hdrs = [
        "geometry/include/geometry/SurfaceOrientation.h",
        "geometry/include/geometry/TangentSpaceMesh.h",
        "geometry/include/geometry/Transcoder.h",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "geometry/include",
    ],
    linkstatic = 1,
    deps = [
        ":math_hdrs",
        ":utils",
        ":utils_hdrs",
        "@meshoptimizer",
        "@mikktspace",
    ],
    alwayslink = 1,
)

# This header cannot be independently compiled, so it needs to be a textual_hdrs.
cc_library(
    name = "filamat_builtinResource",
    linkstatic = 1,
    textual_hdrs = [
        "filamat/src/sca/builtinResource.h",
    ],
    alwayslink = 1,
)

# Filament data serialization library.
cc_library(
    name = "filaflat",
    srcs = glob([
        "filaflat/src/**/*.cpp",
        "filaflat/src/**/*.h",
    ]),
    hdrs = glob([
        "filaflat/include/**/*.h",
    ]),
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "filaflat/include",
    ],
    linkstatic = 1,
    deps = [
        ":filabridge_hdrs",
        ":utils_hdrs",
        "//third_party/filament/filament/backend:driver_enums",
        "@robin_map",
    ] + if_vulkan(["//third_party/smol_v:smol-v"]),
    alwayslink = 1,
)

# Filament material builder library.
cc_library(
    name = "filamat",
    srcs = glob([
        "filamat/src/**/*.cpp",
    ]),
    hdrs = glob([
        "filamat/include/**/*.h",
    ]),
    copts = filament_copts() + [
        "-Ithird_party/glslang/glslang/Include",
        "-Ithird_party/glslang/glslang/MachineIndependent",
        "-Ithird_party/glslang/glslang/Public",
        "-Ithird_party/glslang/SPIRV",
        "-Wno-uninitialized",
        "-fexceptions",
    ],
    defines = filament_defines(),
    includes = [
        "filamat/include",
        "filamat/src",  # TODO(bendoherty) this is needed by matedit for eiff/ headers
    ],
    linkstatic = 1,
    textual_hdrs = glob([
        "filamat/src/**/*.h",
    ]),
    deps = [
        ":filabridge",
        ":filabridge_hdrs",
        ":math_hdrs",
        ":utils",
        ":utils_hdrs",
        "//third_party/filament/filament:generated_shaders",
        "//third_party/filament/filament/backend:backend_hdrs",
        "//third_party/filament/filament/backend:driver_enums",
        "@glslang",
        "@glslang//:SPIRV",
        "@smol_v//:smol-v",
        "@spirv_cross//:spirv_cross_lib",
        "@spirv_tools",
        "@spirv_tools//:spirv_tools_opt",
    ],
    alwayslink = 1,
)

cc_library(
    name = "filamat_samplerbindingmap",
    hdrs = [
        "filamat/src/SamplerBindingMap.h",
    ],
    copts = filament_copts() + [
        "-Wno-uninitialized",
    ],
    defines = filament_defines(),
    linkstatic = 1,
    deps = [
        ":filabridge_hdrs",
    ],
    alwayslink = 1,
)

# Filament GL Extension wrangling library.
cc_library(
    name = "bluegl",
    srcs = [
        "bluegl/src/BlueGL.cpp",
    ] + if_linux_aarch64([
        "bluegl/src/BlueGLCoreLinuxAArch64Impl.S",
    ]) + if_linux_x86_64([
        "bluegl/src/BlueGLCoreLinuxImpl.S",
    ]) + if_linux_desktop([
        "bluegl/src/BlueGLLinux.cpp",
    ]) + if_linux_headless([
        "bluegl/src/BlueGLLinuxEGL.cpp",
    ]) + if_windows([
        "bluegl/src/BlueGLWindows.cpp",
        "bluegl/src/BlueGLCoreWindowsImpl.S",
    ]) + if_macos([
        "bluegl/src/BlueGLDarwin.cpp",
        "bluegl/src/BlueGLCoreDarwinImpl.S",
    ]),
    hdrs = [
        "bluegl/include/bluegl/BlueGL.h",
        "bluegl/include/bluegl/BlueGLDefines.h",
    ],
    copts = filament_copts() + select({
        "//conditions:default": [
            "-Wa,--noexecstack",
        ],
    }),
    defines = filament_defines(),
    includes = [
        "bluegl/include",
    ],
    linkstatic = 1,
    textual_hdrs = [
        "bluegl/src/private_BlueGL.h",
        "bluegl/include/GL/glcorearb.h",
        "bluegl/include/GL/glext.h",
        "bluegl/include/GL/wglext.h",
    ],
    deps = if_linux_headless(
        [
            "//third_party/GL:EGL_headers",
        ],
        otherwise = [
        ],
    ),
    alwayslink = 1,
)

bluevk_textual_base_hdrs = [
    "bluevk/include/vk_video/vulkan_video_codec_h264std.h",
    "bluevk/include/vk_video/vulkan_video_codec_h264std_decode.h",
    "bluevk/include/vk_video/vulkan_video_codec_h264std_encode.h",
    "bluevk/include/vk_video/vulkan_video_codec_h265std.h",
    "bluevk/include/vk_video/vulkan_video_codec_h265std_decode.h",
    "bluevk/include/vk_video/vulkan_video_codec_h265std_encode.h",
    "bluevk/include/vk_video/vulkan_video_codecs_common.h",
    "bluevk/include/vulkan/vk_platform.h",
    "bluevk/include/vulkan/vulkan.h",
    "bluevk/include/vulkan/vulkan_ggp.h",
    "bluevk/include/vulkan/vulkan_android.h",
    "bluevk/include/vulkan/vulkan_beta.h",
    "bluevk/include/vulkan/vulkan_core.h",
    "bluevk/include/vulkan/vulkan_vi.h",
    "bluevk/include/vulkan/vulkan_wayland.h",
    "bluevk/include/vulkan/vulkan_xcb.h",
    "bluevk/include/vulkan/vulkan_xlib.h",
    "bluevk/include/vulkan/vulkan_xlib_xrandr.h",
]

cc_library(
    name = "bluevk_hdrs",
    hdrs = [
        "bluevk/include/bluevk/BlueVK.h",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "bluevk/include",
    ],
    textual_hdrs = bluevk_textual_base_hdrs + if_macos([
        "bluevk/include/vulkan/vulkan_macos.h",
    ]) + if_windows([
        "bluevk/include/vulkan/vulkan_win32.h",
    ]),
    deps = [
        ":utils_hdrs",
    ],
    alwayslink = 1,
)

# BlueVK library, Filament Vulkan wrangling library.
[
    cc_library(
        name = "%s" % lib_name,
        srcs = [
            "bluevk/src/BlueVK.cpp",
        ] + if_linux_or_android([
            "bluevk/src/BlueVKLinuxAndroid.cpp",
        ]) + if_windows([
            "bluevk/src/BlueVKWindows.cpp",
        ]) + if_macos([
            "bluevk/src/BlueVKDarwin.cpp",
        ]),
        hdrs = [
            "bluevk/include/bluevk/BlueVK.h",
        ],
        copts = filament_copts() + select({
            "//conditions:default": [
                "-Wa,--noexecstack",
            ],
        }),
        defines = filament_defines() + extra_defines,
        includes = [
            "bluevk/include",
        ],
        linkstatic = 1,
        textual_hdrs = bluevk_textual_base_hdrs + if_macos([
            "bluevk/include/vulkan/vulkan_macos.h",
        ]) + if_windows([
            "bluevk/include/vulkan/vulkan_win32.h",
        ]),
        deps = [
            ":utils_hdrs",
        ],
        alwayslink = 1,
    )
    for lib_name, extra_defines in [
        (
            "bluevk",
            if_linux_desktop(["FILAMENT_SUPPORTS_XLIB"]),
        ),
        (
            "bluevk_swiftshader",
            ["FILAMENT_VKLIBRARY_PATH=\\\"libvk_swiftshader.so\\\""],
        ),
        ("bluevk_headless", []),
    ]
]

# This generates uiBlit and uiBlitExternal materials for all platforms. But
# uiBlitExternal should be optimized out on non-Android devices. Hopefully?
genrule(
    name = "generate_filagui_materials",
    srcs = [
        "filagui/src/materials/uiBlit.mat",
        "filagui/src/materials/uiBlitExternal.mat",
    ],
    outs = [
        "generated/resources/filagui_resources.h",
        "generated/resources/filagui_resources.c",
        "generated/resources/uiBlit.filamat",
        "generated/resources/uiBlitExternal.filamat",
    ],
    cmd = "MATC=$(location //third_party/filament/tools:matc) && " +
          "RESGEN=$(location //third_party/filament/tools:resgen) && " +
          "DEPLOY=`dirname $(location generated/resources/uiBlit.filamat)` && " +
          "$$MATC -a all -p all -o $$DEPLOY/uiBlit.filamat $(location filagui/src/materials/uiBlit.mat) && " +
          "$$MATC -a all -p mobile -o $$DEPLOY/uiBlitExternal.filamat $(location filagui/src/materials/uiBlitExternal.mat) && " +
          "$$RESGEN -x $$DEPLOY -c -p filagui_resources $$DEPLOY/uiBlit.filamat $$DEPLOY/uiBlitExternal.filamat",
    tools = [
        "//third_party/filament/tools:matc",
        "//third_party/filament/tools:resgen",
    ],
)

cc_library(
    name = "generated_filagui_materials",
    srcs = [
        "generated/resources/filagui_resources.c",
    ],
    hdrs = [],
    copts = filament_copts(False),
    data = [],
    includes = ["generated"],
    linkstatic = 1,
    textual_hdrs = [
        "generated/resources/filagui_resources.h",
    ],
    alwayslink = 1,
)

# Filament GUI helper library.
cc_library(
    name = "filagui",
    srcs = glob([
        "filagui/src/**/*.cpp",
        "filagui/src/**/*.h",
    ]),
    hdrs = glob([
        "filagui/include/**/*.h",
    ]),
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "filagui/include",
    ],
    linkstatic = 1,
    textual_hdrs = ["generated/resources/filagui_resources.h"],
    deps = [
        ":filabridge",
        ":filaflat",
        ":filamat",
        ":generated_filagui_materials",
        ":math_hdrs",
        ":utils_hdrs",
        "//third_party/filament/filament:filament_hdrs",
        "@dear_imgui",
        "@robin_map",
    ],
    alwayslink = 1,
)

# Filament ubershader archives library.
cc_library(
    name = "uberz",
    srcs = glob([
        "uberz/src/*.cpp",
    ]),
    hdrs = glob([
        "uberz/include/uberz/*.h",
    ]),
    copts = filament_copts() + [
        "-Ithird_party/glslang/glslang/Include",
        "-Ithird_party/glslang/glslang/MachineIndependent",
        "-Ithird_party/glslang/glslang/Public",
        "-Ithird_party/glslang/SPIRV",
        "-Wno-uninitialized",
    ],
    defines = filament_defines(),
    includes = [
        "uberz/include",
    ],
    linkstatic = 1,
    deps = [
        ":filabridge",
        ":filabridge_hdrs",
        ":utils",
        ":utils_hdrs",
        "@robin_map",
        "@zstdlib",
    ],
    alwayslink = 1,
)

# TODO(prideout): this step can be removed after adding an explicit input feature to uberz
copy_files(
    name = "uberarchive_core_inputs",
    srcs = [
        ":gltfio/materials/base.mat.in",
        ":gltfio/materials/base.spec.in",
    ],
    outs = [
        "generated/resources/core.mat",
        "generated/resources/core.spec",
    ],
)

genrule(
    name = "uberarchive_core",
    srcs = [
        "generated/resources/core.mat",
        "generated/resources/core.spec",
    ],
    outs = ["generated/resources/core.uberz"],
    cmd = "MATC=$(location //third_party/filament/tools:matc) && " +
          "UBERZ=$(location //third_party/filament/tools:uberz) && " +
          "DEPLOY=`dirname $(location generated/resources/core.uberz)` && " +
          "$$MATC " + uberarchive_args("lit", "opaque") + " -a all -p all -o $$DEPLOY/core.filamat $$DEPLOY/core.mat && " +
          "$$UBERZ " + uberarchive_args("lit", "opaque") + " -o $$DEPLOY/core.uberz $$DEPLOY/core",
    tools = [
        "//third_party/filament/tools:matc",
        "//third_party/filament/tools:uberz",
    ],
)

# Filament glTF loader library.
cc_library(
    name = "gltfio",
    srcs = glob(
        [
            "gltfio/src/*.cpp",
            "gltfio/src/*.h",
            "gltfio/src/extended/*.cpp",
            "gltfio/src/extended/*.h",
        ],
        exclude = [
            "gltfio/src/Ktx2Provider.cpp",
        ],
    ),
    hdrs = glob([
        "gltfio/include/gltfio/*.h",
    ]),
    defines = filament_defines() + [
        "GLTFIO_DRACO_SUPPORTED=0",
        "FILAMENT_WASM_THREADS",
    ],
    includes = [
        "gltfio/include",
    ],
    linkstatic = 1,
    deps = [
        ":filamat",
        ":geometry",
        ":math_hdrs",
        ":uberz",
        ":utils_hdrs",
        "//third_party/cgltf",
        "//third_party/filament/filament:filament_hdrs",
        "//third_party/filament/filament/backend:pixel_buffer_descriptor",
        "//third_party/hat_trie",
        "@meshoptimizer",
        "@robin_map",
        "@stblib//:stb_image",
        "@zstdlib",
    ],
    alwayslink = 1,
)

build_test(
    name = "gltfio_build_test",
    targets = [":gltfio"],
)

genrule(
    name = "generate_matdbg_resources",
    srcs = [
        "matdbg/web/index.html",
        "matdbg/web/app.js",
        "matdbg/web/api.js",
    ],
    outs = [
        "generated/resources/matdbg_resources.h",
        "generated/resources/matdbg_resources.c",
    ],
    cmd = "RESGEN=$(location //third_party/filament/tools:resgen) && " +
          "DEPLOY=`dirname $(location generated/resources/matdbg_resources.h)` && " +
          "WEB_DIR=`dirname $(location matdbg/web/index.html)` && " +
          "$$RESGEN -t -x $$DEPLOY -c -p matdbg_resources " +
          "$$WEB_DIR/index.html $$WEB_DIR/app.js $$WEB_DIR/api.js",
    tools = [
        "//third_party/filament/tools:resgen",
    ],
)

cc_library(
    name = "generated_matdbg_resources",
    srcs = [
        "generated/resources/matdbg_resources.c",
    ],
    hdrs = [],
    copts = filament_copts(False),
    data = [],
    includes = ["generated"],
    linkstatic = 1,
    textual_hdrs = [
        "generated/resources/matdbg_resources.h",
    ],
    deps = [":generate_matdbg_resources"],
    alwayslink = 1,
)

cc_library(
    name = "matdbg",
    srcs = [
        "matdbg/src/ApiHandler.cpp",
        "matdbg/src/CommonWriter.cpp",
        "matdbg/src/DebugServer.cpp",
        "matdbg/src/JsonWriter.cpp",
        "matdbg/src/ShaderExtractor.cpp",
        "matdbg/src/ShaderInfo.cpp",
        "matdbg/src/ShaderReplacer.cpp",
        "matdbg/src/TextWriter.cpp",
    ],
    hdrs = [
        "matdbg/include/matdbg/DebugServer.h",
        "matdbg/include/matdbg/JsonWriter.h",
        "matdbg/include/matdbg/ShaderExtractor.h",
        "matdbg/include/matdbg/ShaderInfo.h",
        "matdbg/include/matdbg/ShaderReplacer.h",
        "matdbg/include/matdbg/TextWriter.h",
    ],
    copts = filament_copts() + [
        "-Ithird_party/glslang/glslang/Include",
        "-Ithird_party/glslang/glslang/MachineIndependent",
        "-Ithird_party/glslang/glslang/Public",
        "-Ithird_party/glslang/SPIRV",
        "-Ithird_party/filament/libs/filamat/src",
    ],
    defines = filament_defines(),
    includes = [
        "matdbg/include",
    ],
    linkstatic = 1,
    textual_hdrs = [
        "matdbg/src/ApiHandler.h",
        "matdbg/src/CommonWriter.h",
        "filamat/src/eiff/ChunkContainer.h",
        "generated/resources/matdbg_resources.h",
    ],
    deps = [
        ":filabridge_hdrs",
        ":filaflat",
        ":filamat",
        ":generated_matdbg_resources",
        ":utils_hdrs",
        "//third_party/civetweb:civetserver",
        "//third_party/filament/filament:filament_hdrs",
        "//third_party/filament/filament/backend:driver_enums",
        "@glslang",
        "@glslang//:SPIRV",
        "@robin_map",
        "@spirv_cross//:spirv_cross_lib",
        "@spirv_tools",
        "@spirv_tools//:spirv_tools_opt",
    ],
    alwayslink = 1,
)

# TODO(bendoherty): Don't blindly pass "-a all -p all" to matc.
genrule(
    name = "generate_iblprefilter_materials",
    srcs = [
        "iblprefilter/src/materials/equirectToCube.mat",
        "iblprefilter/src/materials/generateKernel.mat",
        "iblprefilter/src/materials/iblprefilter.mat",
    ],
    outs = [
        "generated/resources/iblprefilter_materials.h",
        "generated/resources/iblprefilter_materials.c",
        "generated/resources/equirectToCube.filamat",
        "generated/resources/generateKernel.filamat",
        "generated/resources/iblprefilter.filamat",
    ],
    cmd = "MATC=$(location //third_party/filament/tools:matc) && " +
          "RESGEN=$(location //third_party/filament/tools:resgen) && " +
          "DEPLOY=`dirname $(location generated/resources/equirectToCube.filamat)` && " +
          "$$MATC -a all -p all -o $$DEPLOY/equirectToCube.filamat $(location iblprefilter/src/materials/equirectToCube.mat) && " +
          "$$MATC -a all -p all -o $$DEPLOY/generateKernel.filamat $(location iblprefilter/src/materials/generateKernel.mat) && " +
          "$$MATC -a all -p all -o $$DEPLOY/iblprefilter.filamat $(location iblprefilter/src/materials/iblprefilter.mat) && " +
          "$$RESGEN -x $$DEPLOY -c -p iblprefilter_materials " +
          "$$DEPLOY/equirectToCube.filamat " +
          "$$DEPLOY/generateKernel.filamat " +
          "$$DEPLOY/iblprefilter.filamat",
    tools = [
        "//third_party/filament/tools:matc",
        "//third_party/filament/tools:resgen",
    ],
)

cc_library(
    name = "generated_iblprefilter_materials",
    srcs = [
        "generated/resources/iblprefilter_materials.c",
    ],
    hdrs = [],
    copts = filament_copts(False),
    data = [],
    includes = ["generated"],
    linkstatic = 1,
    textual_hdrs = [
        "generated/resources/iblprefilter_materials.h",
    ],
    alwayslink = 1,
)

cc_library(
    name = "iblprefilter",
    srcs = [
        "iblprefilter/src/IBLPrefilterContext.cpp",
    ],
    hdrs = [
        "iblprefilter/include/filament-iblprefilter/IBLPrefilterContext.h",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "iblprefilter/include",
    ],
    linkstatic = 1,
    textual_hdrs = ["generated/resources/iblprefilter_materials.h"],
    deps = [
        ":filabridge_hdrs",
        ":generated_iblprefilter_materials",
        ":math_hdrs",
        ":utils_hdrs",
        "//third_party/filament/filament:filament_hdrs",
        "//third_party/filament/filament/backend:driver_enums",
    ],
    alwayslink = 1,
)

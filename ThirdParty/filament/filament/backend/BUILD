load(
    "//third_party/filament:filament.bzl",
    "filament_copts",
    "filament_defines",
    "filament_dependees",
    "if_android",
    "if_apple",
    "if_desktop",
    "if_ios",
    "if_linux",
    "if_linux_desktop",
    "if_linux_headless",
    "if_linux_headless_or_android",
    "if_macos",
    "if_vulkan",
    "if_wasm",
    "if_windows",
)

licenses(["notice"])

package(
    default_applicable_licenses = ["//third_party/filament:license"],
    default_visibility = ["//visibility:public"],
    features = [
        "-use_header_modules",  # Incompatible with -fno-rtti
    ],
)

cc_library(
    name = "driver_enums",
    hdrs = [
        "include/backend/DriverEnums.h",
        "include/backend/Platform.h",
        "include/backend/PresentCallable.h",
    ],
    includes = [
        "include",
    ],
    deps = [
        "//third_party/filament/libs:math_hdrs",
        "//third_party/filament/libs:utils_hdrs",
    ],
    alwayslink = 1,
)

cc_library(
    name = "platform",
    hdrs = [
        "include/backend/Platform.h",
    ],
    includes = [
        "include",
    ],
    deps = [
        ":driver_enums",
        "//third_party/filament/libs:utils_hdrs",
    ],
    alwayslink = 1,
)

cc_library(
    name = "backend_utils",
    srcs = [
        "src/BackendUtils.cpp",
    ],
    hdrs = [
        "include/private/backend/BackendUtils.h",
        "src/DataReshaper.h",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "include",
    ],
    linkstatic = True,
    deps = [
        ":driver_enums",
        ":pixel_buffer_descriptor",
        "//third_party/filament/libs:math_hdrs",
        "//third_party/filament/libs:utils_hdrs",
    ],
    alwayslink = 1,
)

cc_library(
    name = "pixel_buffer_descriptor",
    hdrs = [
        "include/backend/BufferDescriptor.h",
        "include/backend/PixelBufferDescriptor.h",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "include",
    ],
    linkstatic = True,
    deps = [
        ":driver_enums",
        "//third_party/filament/libs:utils_hdrs",
    ],
    alwayslink = 1,
)

cc_library(
    name = "virtual_machine_env",
    srcs = [
        "src/VirtualMachineEnv.cpp",
    ],
    hdrs = [
        "include/private/backend/VirtualMachineEnv.h",
    ],
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "include",
    ],
    linkstatic = True,
    deps = [
        "//third_party/filament/libs:utils_hdrs",
    ] + if_linux([
        "@bazel_tools//tools/jdk:jni",
    ]),
    alwayslink = 1,
)

backend_srcs = [
    "include/private/backend/CircularBuffer.h",
    "include/private/backend/CommandBufferQueue.h",
    "include/private/backend/CommandStream.h",
    "include/private/backend/Driver.h",
    "include/private/backend/DriverAPI.inc",
    "include/private/backend/DriverApi.h",
    "include/private/backend/HandleAllocator.h",
    "include/private/backend/PlatformFactory.h",
    "include/private/backend/SamplerGroup.h",
    "src/BlobCacheKey.cpp",
    "src/BlobCacheKey.h",
    "src/Callable.cpp",
    "src/CallbackManager.cpp",
    "src/CallbackManager.h",
    "src/CircularBuffer.cpp",
    "src/CommandBufferQueue.cpp",
    "src/CommandStream.cpp",
    "src/CommandStreamDispatcher.h",
    "src/CompilerThreadPool.cpp",
    "src/CompilerThreadPool.h",
    "src/Driver.cpp",
    "src/DriverBase.h",
    "src/Handle.cpp",
    "src/HandleAllocator.cpp",
    "src/ostream.cpp",
    "src/Platform.cpp",
    "src/PlatformFactory.cpp",
    "src/Program.cpp",
    "src/SamplerGroup.cpp",
    "src/noop/NoopDriver.cpp",
    "src/noop/PlatformNoop.cpp",
]

backend_opengl_srcs = backend_srcs + [
    "src/opengl/OpenGLBlobCache.cpp",
    "src/opengl/OpenGLBlobCache.h",
    "src/opengl/GLUtils.cpp",
    "src/opengl/GLUtils.h",
    "src/opengl/OpenGLContext.cpp",
    "src/opengl/OpenGLDriver.cpp",
    "src/opengl/OpenGLPlatform.cpp",
    "src/opengl/OpenGLProgram.cpp",
    "src/opengl/OpenGLDriverFactory.h",
    "src/opengl/OpenGLProgram.h",
    "src/opengl/OpenGLTimerQuery.cpp",
    "src/opengl/OpenGLTimerQuery.h",
    "src/opengl/ShaderCompilerService.cpp",
    "src/opengl/ShaderCompilerService.h",
    "src/opengl/gl_headers.cpp",
    "src/opengl/gl_headers.h",
]

backend_metal_srcs = backend_srcs + [
    "src/metal/MetalBlitter.mm",
    "src/metal/MetalBuffer.mm",
    "src/metal/MetalBufferPool.mm",
    "src/metal/MetalContext.mm",
    "src/metal/MetalDriver.mm",
    "src/metal/MetalEnums.mm",
    "src/metal/MetalExternalImage.mm",
    "src/metal/MetalHandles.mm",
    "src/metal/MetalPlatform.mm",
    "src/metal/MetalResourceTracker.cpp",
    "src/metal/MetalShaderCompiler.mm",
    "src/metal/MetalState.mm",
    "src/metal/MetalTimerQuery.mm",
    "src/metal/MetalUtils.mm",
]

backend_vulkan_srcs = [
    "src/noop/NoopDriver.cpp",
    "src/noop/PlatformNoop.cpp",
    "src/Callable.cpp",
    "src/CallbackManager.cpp",
    "src/CallbackManager.h",
    "src/CircularBuffer.cpp",
    "src/CommandBufferQueue.cpp",
    "src/CommandStream.cpp",
    "src/CommandStreamDispatcher.h",
    "src/Driver.cpp",
    "src/DriverBase.h",
    "src/Handle.cpp",
    "src/ostream.cpp",
    "src/Platform.cpp",
    "src/vulkan/caching/VulkanDescriptorSetManager.cpp",
    "src/vulkan/caching/VulkanDescriptorSetManager.h",
    "src/vulkan/caching/VulkanPipelineLayoutCache.cpp",
    "src/vulkan/caching/VulkanPipelineLayoutCache.h",
    "src/vulkan/platform/VulkanPlatform.cpp",
    "src/vulkan/platform/VulkanPlatformSwapChainImpl.cpp",
    "src/vulkan/platform/VulkanPlatformSwapChainImpl.h",
    "src/vulkan/spirv/VulkanSpirvUtils.cpp",
    "src/vulkan/spirv/VulkanSpirvUtils.h",
    "src/PlatformFactory.cpp",
    "src/Program.cpp",
    "src/SamplerGroup.cpp",
    "src/HandleAllocator.cpp",
    "src/vulkan/VulkanBlitter.cpp",
    "src/vulkan/VulkanBlitter.h",
    "src/vulkan/VulkanBuffer.cpp",
    "src/vulkan/VulkanBuffer.h",
    "src/vulkan/VulkanCommands.cpp",
    "src/vulkan/VulkanCommands.h",
    "src/vulkan/VulkanConstants.h",
    "src/vulkan/VulkanContext.cpp",
    "src/vulkan/VulkanContext.h",
    "src/vulkan/VulkanDriver.cpp",
    "src/vulkan/VulkanDriverFactory.h",
    "src/vulkan/VulkanDriver.h",
    "src/vulkan/VulkanFboCache.cpp",
    "src/vulkan/VulkanFboCache.h",
    "src/vulkan/VulkanHandles.cpp",
    "src/vulkan/VulkanHandles.h",
    "src/vulkan/VulkanImageUtility.cpp",
    "src/vulkan/VulkanImageUtility.h",
    "src/vulkan/VulkanMemory.h",
    "src/vulkan/VulkanPipelineCache.cpp",
    "src/vulkan/VulkanPipelineCache.h",
    "src/vulkan/VulkanResourceAllocator.h",
    "src/vulkan/VulkanResources.h",
    "src/vulkan/VulkanResources.cpp",
    "src/vulkan/VulkanSamplerCache.cpp",
    "src/vulkan/VulkanSamplerCache.h",
    "src/vulkan/VulkanStagePool.cpp",
    "src/vulkan/VulkanStagePool.h",
    "src/vulkan/VulkanSwapChain.cpp",
    "src/vulkan/VulkanSwapChain.h",
    "src/vulkan/VulkanReadPixels.h",
    "src/vulkan/VulkanReadPixels.cpp",
    "src/vulkan/VulkanTexture.cpp",
    "src/vulkan/VulkanTexture.h",
    "src/vulkan/VulkanUtility.cpp",
    "src/vulkan/VulkanUtility.h",
]

backend_vulkan_objc_srcs = backend_vulkan_srcs + if_apple(
    [
        "src/vulkan/platform/VulkanPlatformApple.mm",
    ],
)

backend_opengl_objc_srcs = backend_opengl_srcs + if_ios(
    [
        "src/opengl/platforms/CocoaTouchExternalImage.h",
        "src/opengl/platforms/CocoaTouchExternalImage.mm",
        "src/opengl/platforms/PlatformCocoaTouchGL.mm",
    ],
    [
        "src/opengl/platforms/CocoaExternalImage.h",
        "src/opengl/platforms/CocoaExternalImage.mm",
        "src/opengl/platforms/PlatformCocoaGL.mm",
    ],
)

backend_textual_hdrs_base = [
    "include/private/backend/CircularBuffer.h",
    "include/private/backend/CommandBufferQueue.h",
    "include/private/backend/CommandStream.h",
    "include/private/backend/Dispatcher.h",
    "include/private/backend/Driver.h",
    "include/private/backend/DriverAPI.inc",
    "include/private/backend/DriverApi.h",
    "include/private/backend/HandleAllocator.h",
    "include/private/backend/PlatformFactory.h",
    "include/private/backend/SamplerGroup.h",
    "src/CommandStreamDispatcher.h",
    "src/DataReshaper.h",
    "src/DriverBase.h",
    "src/metal/MetalBlitter.h",
    "src/metal/MetalBuffer.h",
    "src/metal/MetalBufferPool.h",
    "src/metal/MetalContext.h",
    "src/metal/MetalDriver.h",
    "src/metal/MetalDriverFactory.h",
    "src/metal/MetalEnums.h",
    "src/metal/MetalExternalImage.h",
    "src/metal/MetalHandles.h",
    "src/metal/MetalPlatform.h",
    "src/metal/MetalResourceTracker.h",
    "src/metal/MetalShaderCompiler.h",
    "src/metal/MetalState.h",
    "src/metal/MetalTimerQuery.h",
    "src/metal/MetalUtils.h",
    "src/noop/NoopDriver.h",
    "src/noop/PlatformNoop.h",
]

backend_textual_hdrs = backend_textual_hdrs_base + [
    "src/opengl/GLBufferObject.h",
    "src/opengl/GLTexture.h",
    "src/opengl/NullGLES.h",
    "src/opengl/OpenGLDriver.h",
    "src/opengl/OpenGLContext.h",
    "src/opengl/OpenGLTimerQuery.h",
]

cc_library(
    name = "backend_hdrs",
    hdrs = [
        "include/backend/AcquiredImage.h",
        "include/backend/CallbackHandler.h",
        "include/backend/DriverApiForward.h",
        "include/backend/Handle.h",
        "include/backend/PipelineState.h",
        "include/backend/Platform.h",
        "include/backend/Program.h",
        "include/backend/SamplerDescriptor.h",
        "include/backend/TargetBufferInfo.h",
        "include/backend/platforms/OpenGLPlatform.h",
    ] + if_linux_headless_or_android([
        "include/backend/platforms/PlatformEGL.h",
    ]) + if_ios([
        "include/backend/platforms/PlatformCocoaTouchGL.h",
    ]) + if_macos([
        "include/backend/platforms/PlatformCocoaGL.h",
    ]) + if_android([
        "include/backend/platforms/PlatformEGLAndroid.h",
    ]) + if_windows([
        "include/backend/platforms/PlatformWGL.h",
    ]) + if_wasm([
        "include/backend/platforms/PlatformWebGL.h",
    ]) + if_linux_desktop([
        "include/backend/platforms/PlatformGLX.h",
    ]) + if_linux_headless([
        "include/backend/platforms/PlatformEGLHeadless.h",
    ]) + if_vulkan([
        "include/backend/platforms/VulkanPlatform.h",
    ]),
    copts = filament_copts(),
    defines = filament_defines(),
    includes = ["include"],
    linkstatic = 1,
    textual_hdrs = backend_textual_hdrs,
    visibility = [
        "//:__subpackages__",
        "//third_party/draco/src/draco/visualization:__subpackages__",
        "//third_party/filament:__subpackages__",
        "//video/accelerators/vulkan/mediapipe/platform:__subpackages__",
    ],
    deps = [
        ":driver_enums",
        ":pixel_buffer_descriptor",
        "//third_party/filament/libs:math_hdrs",
        "//third_party/filament/libs:utils_hdrs",
    ] + if_desktop([
        "//third_party/filament/libs:bluegl",
    ]) + if_linux_desktop([
    ]) + if_linux_headless([
        "//third_party/GL:EGL_headers",
    ]) + if_vulkan([
        "//third_party/filament/libs:bluevk_hdrs",
    ]),
    alwayslink = 1,
)

# Filament backend library for non-mac OpenGL
cc_library(
    name = "backend_opengl_default",
    srcs = backend_opengl_srcs + if_linux_headless_or_android([
        "src/opengl/platforms/PlatformEGL.cpp",
    ]) + if_android([
        "src/opengl/platforms/ExternalStreamManagerAndroid.cpp",
        "src/opengl/platforms/ExternalStreamManagerAndroid.h",
        "src/opengl/platforms/PlatformEGLAndroid.cpp",
    ]) + if_windows([
        "src/opengl/platforms/PlatformWGL.cpp",
    ]) + if_wasm([
        "src/opengl/platforms/PlatformWebGL.cpp",
    ]) + if_linux_desktop([
        "src/opengl/platforms/PlatformGLX.cpp",
    ]) + if_linux_headless([
        "src/opengl/platforms/PlatformEGLHeadless.cpp",
    ]),
    copts = filament_copts(),
    defines = filament_defines() + [
        "FILAMENT_SUPPORTS_OPENGL=1",
    ] + if_linux_headless(
        ["FILAMENT_SUPPORTS_EGL_ON_LINUX"],
        otherwise = ["FILAMENT_SUPPORTS_X11"],
    ),
    includes = [
        "src",
    ],
    linkstatic = True,
    textual_hdrs = backend_textual_hdrs,
    deps = [
        ":backend_hdrs",
        ":backend_utils",
        ":driver_enums",
        ":pixel_buffer_descriptor",
        "//third_party/filament/libs:math_hdrs",
        "//third_party/filament/libs:utils",
        "//third_party/filament/libs:utils_hdrs",
        "@robin_map",
    ] + if_desktop([
        "//third_party/filament/libs:bluegl",
    ]) + if_linux_desktop([
    ]) + if_linux_headless([
        "//third_party/GL:EGL_headers",
    ]) + if_android([
        ":virtual_machine_env",
    ]),
    alwayslink = 1,
)

genrule(
    name = "generate_vkshaders",
    srcs = [
        "src/vulkan/BlitDepth.vs",
        "src/vulkan/BlitDepth.fs",
    ],
    outs = [
        "generated/vkshaders/vkshaders.c",
        "generated/vkshaders/vkshaders.h",
        "generated/vkshaders/BlitDepthVs.spv",
        "generated/vkshaders/BlitDepthFs.spv",
    ],
    cmd = "MATC=$(location //third_party/filament:matc) && " +
          "RESGEN=$(location //third_party/filament:resgen) && " +
          "DEPLOY=`dirname $(location generated/vkshaders/vkshaders.c)` && " +
          "$$MATC --raw -o $$DEPLOY/BlitDepthVs.spv $(location src/vulkan/BlitDepth.vs) && " +
          "$$MATC --raw -o $$DEPLOY/BlitDepthFs.spv $(location src/vulkan/BlitDepth.fs) && " +
          "$$RESGEN -cp vkshaders --deploy=$$DEPLOY $$DEPLOY/BlitDepthVs.spv $$DEPLOY/BlitDepthFs.spv",
    tools = [
        "//third_party/filament:matc",
        "//third_party/filament:resgen",
    ],
)

cc_library(
    name = "generated_vkshaders",
    srcs = [
        "generated/vkshaders/vkshaders.c",
    ],
    hdrs = [],
    copts = filament_copts(False),
    data = [],
    includes = ["generated"],
    linkstatic = 1,
    textual_hdrs = [
        "generated/vkshaders/vkshaders.h",
    ],
    alwayslink = 1,
)

# Filament backend library for including Vulkan inside of Linux builds.
[
    cc_library(
        name = "%s" % lib_name,
        srcs = backend_vulkan_srcs + [
            "src/vulkan/platform/VulkanPlatformAndroidLinuxWindows.cpp",
        ],
        copts = filament_copts(),
        defines = filament_defines() + [
            "FILAMENT_DRIVER_SUPPORTS_VULKAN",
        ] + extra_defines,
        includes = [
            "src",
        ],
        linkstatic = True,
        textual_hdrs = backend_textual_hdrs,
        deps = deps + [
            ":backend_hdrs",
            ":backend_utils",
            ":driver_enums",
            ":generated_vkshaders",
            ":pixel_buffer_descriptor",
            "//third_party/filament/libs:math_hdrs",
            "//third_party/filament/libs:utils",
            "//third_party/filament/libs:utils_hdrs",
            "//third_party/spirv_headers:spirv_cpp_headers",
            "@robin_map",
            "@smol_v//:smol-v",
        ],
        alwayslink = 1,
    )
    for lib_name, extra_defines, deps in [
        (
            "backend_vulkan_for_linux",
            [
                "FILAMENT_SUPPORTS_X11",
            ] + if_linux_desktop([
                "FILAMENT_SUPPORTS_XLIB",
            ]),
            [
                "//third_party/filament/libs:bluevk",  # This should come early in the dep list.
            ] + if_linux_desktop([
            ]),
        ),
        (
            "backend_vulkan_for_linux_headless",
            [
                "FILAMENT_SUPPORTS_X11",
            ],
            [
                "//third_party/filament/libs:bluevk_headless",  # This should come early in the dep list.
            ] + if_linux_desktop([
            ]),
        ),
        # Filament backend library for non-mac vulkan swiftshader
        (
            "backend_vulkan_swiftshader_default",
            [
                "FILAMENT_USE_SWIFTSHADER",
            ] + if_linux_desktop([
                "FILAMENT_SUPPORTS_X11",
            ]),
            [
                "//third_party/filament/libs:bluevk_swiftshader",  # This should come early in the dep list.
            ],
        ),
        # Filament backend library for Android
        (
            "backend_vulkan_android",
            [
            ],
            [
                "//third_party/filament/libs:bluevk",  # This should come early in the dep list.
            ],
        ),
    ]
]

# Filament driver for OpenGL on Cocoa (iOS or macOS)
objc_library(
    name = "backend_opengl_objc",
    srcs = backend_opengl_objc_srcs,
    copts = filament_copts(),
    defines = filament_defines() + ["FILAMENT_SUPPORTS_OPENGL=1"],
    features = ["-layering_check"],
    includes = [
        "src",
        "src/opengl",
    ],
    textual_hdrs = backend_textual_hdrs,
    deps = [
        ":backend_hdrs",
        ":backend_utils",
        ":driver_enums",
        "//third_party/apple_frameworks:CoreGraphics",
        "//third_party/apple_frameworks:CoreVideo",
        "//third_party/filament/libs:utils",
    ] + if_ios(
        [],
        [
            "//third_party/filament/libs:bluegl",
        ],
    ),
)

# Filament driver for Metal + MacOS.
objc_library(
    name = "backend_metal_objc",
    srcs = backend_metal_srcs,
    copts = filament_copts(),
    defines = filament_defines() + ["FILAMENT_SUPPORTS_METAL=1"],
    features = ["-layering_check"],
    includes = [
        "src",
    ],
    textual_hdrs = backend_textual_hdrs_base,
    deps = [
        ":backend_hdrs",
        ":backend_utils",
        "//third_party/filament/filament:filament_hdrs",
        "//third_party/filament/libs:utils",
    ] + if_ios(
        [],
        ["//third_party/filament/libs:bluegl"],
    ),
)

# Filament driver for Vulkan on Cocoa (iOS or macOS)
objc_library(
    name = "backend_vulkan_swiftshader_objc",
    srcs = backend_vulkan_objc_srcs,
    copts = filament_copts(),
    defines = filament_defines(),
    includes = [
        "src",
        "src/vulkan",
    ],
    textual_hdrs = backend_textual_hdrs,
    deps = [
        ":generated_vkshaders",
        "//third_party/apple_frameworks:CoreVideo",
        "//third_party/filament/libs:utils",
    ] + if_ios(
        [],
        [
            "//third_party/filament/libs:bluevk_swiftshader",
        ],
    ),
)

cc_library(
    name = "backend_opengl_private_hdrs",
    copts = filament_copts(),
    defines = filament_defines(),
    includes = ["src"],
    linkstatic = 1,
    textual_hdrs = [
        "src/opengl/OpenGLDriver.h",
        "src/opengl/OpenGLBlobCache.h",
        "src/opengl/OpenGLContext.h",
        "src/opengl/ShaderCompilerService.h",
        "src/BlobCacheKey.h",
        "src/CallbackManager.h",
        "src/CompilerThreadPool.h",
        "src/DriverBase.h",
        "include/backend/DriverEnums.h",
        "include/private/backend/BackendUtils.h",
        "include/private/backend/Driver.h",
        "include/private/backend/CommandStream.h",
        "include/private/backend/CommandBufferQueue.h",
        "include/private/backend/DriverApi.h",
        "include/private/backend/HandleAllocator.h",
        "include/private/backend/CircularBuffer.h",
        "include/private/backend/PlatformFactory.h",
        "include/private/backend/SamplerGroup.h",
        "include/private/backend/DriverAPI.inc",
        "src/opengl/GLUtils.h",
        "src/opengl/gl_headers.h",
        "src/opengl/NullGLES.h",
    ],
    visibility = [
        "//:__subpackages__",
        "//third_party/draco/src/draco/visualization/backend:__subpackages__",
        "//third_party/filament:__subpackages__",
    ],
    deps = [
        "//third_party/filament/libs:math_hdrs",
    ],
    alwayslink = 1,
)

alias(
    name = "backend_opengl",
    actual = if_apple(":backend_opengl_objc", ":backend_opengl_default"),
)

alias(
    name = "backend_metal",
    actual = ":backend_metal_objc",
)

alias(
    name = "backend_vulkan_swiftshader",
    actual = if_apple(":backend_vulkan_swiftshader_objc", ":backend_vulkan_swiftshader_default"),
)


#include <backend/platforms/VulkanPlatform.h>
#include <backend/DriverEnums.h>

#include "vulkan/VulkanConstants.h"
#include "vulkan/VulkanDriverFactory.h"

#include "third_party/filament/libs/utils/include/utils/Panic.h"

#include <bluevk/BlueVK.h>

#include <tuple>

#include <stdint.h>
#include <stddef.h>

#if defined(__linux__) || defined(__FreeBSD__)
#define LINUX_OR_FREEBSD 1
#endif

// Platform specific includes and defines
#if defined(__ANDROID__)
    #include <android/native_window.h>
#elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
    #include <dlfcn.h>
    namespace {
        typedef struct _wl {
            struct wl_display* display;
            struct wl_surface* surface;
            uint32_t width;
            uint32_t height;
        } wl;
    }// anonymous namespace
#elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_X11)
    // TODO: we should allow for headless on Linux explicitly. Right now this is the headless path
    // (with no FILAMENT_SUPPORTS_XCB or FILAMENT_SUPPORTS_XLIB).
    #include <dlfcn.h>
    #if defined(FILAMENT_SUPPORTS_XCB)
        #include <xcb/xcb.h>
        namespace {
            typedef xcb_connection_t* (*XCB_CONNECT)(const char* displayname, int* screenp);
        }
    #endif
    #if defined(FILAMENT_SUPPORTS_XLIB)
        #include <X11/Xlib.h>
        namespace {
            typedef Display* (*X11_OPEN_DISPLAY)(const char*);
        }
    #endif
    static constexpr const char* LIBRARY_X11 = "libX11.so.6";
    namespace {
        struct XEnv {
        #if defined(FILAMENT_SUPPORTS_XCB)
            XCB_CONNECT xcbConnect;
            xcb_connection_t* connection;
        #endif
        #if defined(FILAMENT_SUPPORTS_XLIB)
            X11_OPEN_DISPLAY openDisplay;
            Display* display;
        #endif
            void* library = nullptr;
        } g_x11_vk;
    }// anonymous namespace
#elif defined(WIN32)
    // No platform specific includes
#else
    // Not a supported Vulkan platform
#endif

using namespace bluevk;

namespace filament::backend {

VulkanPlatform::ExtensionSet VulkanPlatform::getSwapchainInstanceExtensions() {
    VulkanPlatform::ExtensionSet const ret = {
#if defined(__ANDROID__)
        VK_KHR_ANDROID_SURFACE_EXTENSION_NAME,
#elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
        VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
#elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_X11)
    #if defined(FILAMENT_SUPPORTS_XCB)
        VK_KHR_XCB_SURFACE_EXTENSION_NAME,
    #endif
    #if defined(FILAMENT_SUPPORTS_XLIB)
        VK_KHR_XLIB_SURFACE_EXTENSION_NAME,
    #endif
#elif defined(WIN32)
        VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
#endif
    };
    return ret;
}

VulkanPlatform::SurfaceBundle VulkanPlatform::createVkSurfaceKHR(void* nativeWindow,
        VkInstance instance, uint64_t flags) noexcept {
    VkSurfaceKHR surface;

    // On certain platforms, the extent of the surface cannot be queried from Vulkan. In those
    // situations, we allow the frontend to pass in the extent to use in creating the swap
    // chains. Platform implementation should set extent to 0 if they do not expect to set the
    // swap chain extent.
    VkExtent2D extent;

    #if defined(__ANDROID__)
        VkAndroidSurfaceCreateInfoKHR const createInfo{
                .sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR,
                .window = (ANativeWindow*) nativeWindow,
        };
        VkResult const result = vkCreateAndroidSurfaceKHR(instance, &createInfo, VKALLOC,
                (VkSurfaceKHR*) &surface);
        FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS) << "vkCreateAndroidSurfaceKHR error.";
    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
        wl* ptrval = reinterpret_cast<wl*>(nativeWindow);
        extent.width = ptrval->width;
        extent.height = ptrval->height;

        VkWaylandSurfaceCreateInfoKHR const createInfo = {
                .sType = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR,
                .pNext = NULL,
                .flags = 0,
                .display = ptrval->display,
                .surface = ptrval->surface,
        };
        VkResult const result = vkCreateWaylandSurfaceKHR(instance, &createInfo, VKALLOC,
                (VkSurfaceKHR*) &surface);
        FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS) << "vkCreateWaylandSurfaceKHR error.";
    #elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_X11)
        if (g_x11_vk.library == nullptr) {
            g_x11_vk.library = dlopen(LIBRARY_X11, RTLD_LOCAL | RTLD_NOW);
            FILAMENT_CHECK_PRECONDITION(g_x11_vk.library) << "Unable to open X11 library.";
            #if defined(FILAMENT_SUPPORTS_XCB)
                g_x11_vk.xcbConnect = (XCB_CONNECT) dlsym(g_x11_vk.library, "xcb_connect");
                int screen;
                g_x11_vk.connection = g_x11_vk.xcbConnect(nullptr, &screen);
            #endif
            #if defined(FILAMENT_SUPPORTS_XLIB)
                g_x11_vk.openDisplay = (X11_OPEN_DISPLAY) dlsym(g_x11_vk.library, "XOpenDisplay");
                g_x11_vk.display = g_x11_vk.openDisplay(NULL);
                FILAMENT_CHECK_PRECONDITION(g_x11_vk.display) << "Unable to open X11 display.";
            #endif
        }
        #if defined(FILAMENT_SUPPORTS_XCB) || defined(FILAMENT_SUPPORTS_XLIB)
            bool useXcb = false;
        #endif
        #if defined(FILAMENT_SUPPORTS_XCB)
            #if defined(FILAMENT_SUPPORTS_XLIB)
                useXcb = (flags & SWAP_CHAIN_CONFIG_ENABLE_XCB) != 0;
            #else
                useXcb = true;
            #endif
            if (useXcb) {
                FILAMENT_CHECK_POSTCONDITION(vkCreateXcbSurfaceKHR)
                        << "Unable to load vkCreateXcbSurfaceKHR function.";

                VkXcbSurfaceCreateInfoKHR const createInfo = {
                        .sType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR,
                        .connection = g_x11_vk.connection,
                        .window = (xcb_window_t) reinterpret_cast<uint64_t>(nativeWindow),
                };
                VkResult const result = vkCreateXcbSurfaceKHR(instance, &createInfo, VKALLOC,
                        (VkSurfaceKHR*) &surface);
                FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS)
                        << "vkCreateXcbSurfaceKHR error.";
            }
        #endif
        #if defined(FILAMENT_SUPPORTS_XLIB)
            if (!useXcb) {
                FILAMENT_CHECK_POSTCONDITION(vkCreateXlibSurfaceKHR)
                        << "Unable to load vkCreateXlibSurfaceKHR function.";

                VkXlibSurfaceCreateInfoKHR const createInfo = {
                        .sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR,
                        .dpy = g_x11_vk.display,
                        .window = (Window) nativeWindow,
                };
                VkResult const result = vkCreateXlibSurfaceKHR(instance, &createInfo, VKALLOC,
                        (VkSurfaceKHR*) &surface);
                FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS)
                        << "vkCreateXlibSurfaceKHR error.";
            }
        #endif
    #elif defined(WIN32)
        VkWin32SurfaceCreateInfoKHR const createInfo = {
            .sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
            .hinstance = GetModuleHandle(nullptr),
            .hwnd = (HWND) nativeWindow,
        };
        VkResult const result = vkCreateWin32SurfaceKHR(instance, &createInfo, nullptr,
                (VkSurfaceKHR*) &surface);
        FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS) << "vkCreateWin32SurfaceKHR error.";
    #endif
    return std::make_tuple(surface, extent);
}

} // namespace filament::backend

#undef LINUX_OR_FREEBSD

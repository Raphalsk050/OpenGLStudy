


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
#if defined(VK_VERSION_1_0)
    vkCreateInstance = (PFN_vkCreateInstance) loadcb(context, "vkCreateInstance");
    vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties) loadcb(context, "vkEnumerateInstanceExtensionProperties");
    vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties) loadcb(context, "vkEnumerateInstanceLayerProperties");
#endif // defined(VK_VERSION_1_0)
#if defined(VK_VERSION_1_1)
    vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion) loadcb(context, "vkEnumerateInstanceVersion");
#endif // defined(VK_VERSION_1_1)
}

static void loadInstanceFunctions(void* context, PFN_vkVoidFunction (*loadcb)(void*, const char*)) {
#if defined(VK_VERSION_1_0)
    vkCreateDevice = (PFN_vkCreateDevice) loadcb(context, "vkCreateDevice");
    vkDestroyInstance = (PFN_vkDestroyInstance) loadcb(context, "vkDestroyInstance");
    vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties) loadcb(context, "vkEnumerateDeviceExtensionProperties");
    vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties) loadcb(context, "vkEnumerateDeviceLayerProperties");
    vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices) loadcb(context, "vkEnumeratePhysicalDevices");
    vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr) loadcb(context, "vkGetDeviceProcAddr");
    vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures) loadcb(context, "vkGetPhysicalDeviceFeatures");
    vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties) loadcb(context, "vkGetPhysicalDeviceFormatProperties");
    vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties) loadcb(context, "vkGetPhysicalDeviceImageFormatProperties");
    vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties) loadcb(context, "vkGetPhysicalDeviceMemoryProperties");
    vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties) loadcb(context, "vkGetPhysicalDeviceProperties");
    vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties) loadcb(context, "vkGetPhysicalDeviceQueueFamilyProperties");
    vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties) loadcb(context, "vkGetPhysicalDeviceSparseImageFormatProperties");
#endif // defined(VK_VERSION_1_0)
#if defined(VK_VERSION_1_1)
    vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups) loadcb(context, "vkEnumeratePhysicalDeviceGroups");
    vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties) loadcb(context, "vkGetPhysicalDeviceExternalBufferProperties");
    vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties) loadcb(context, "vkGetPhysicalDeviceExternalFenceProperties");
    vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties) loadcb(context, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2) loadcb(context, "vkGetPhysicalDeviceFeatures2");
    vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2) loadcb(context, "vkGetPhysicalDeviceFormatProperties2");
    vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2) loadcb(context, "vkGetPhysicalDeviceImageFormatProperties2");
    vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2) loadcb(context, "vkGetPhysicalDeviceMemoryProperties2");
    vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2) loadcb(context, "vkGetPhysicalDeviceProperties2");
    vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2) loadcb(context, "vkGetPhysicalDeviceQueueFamilyProperties2");
    vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2) loadcb(context, "vkGetPhysicalDeviceSparseImageFormatProperties2");
#endif // defined(VK_VERSION_1_1)
#if defined(VK_VERSION_1_3)
    vkGetPhysicalDeviceToolProperties = (PFN_vkGetPhysicalDeviceToolProperties) loadcb(context, "vkGetPhysicalDeviceToolProperties");
#endif // defined(VK_VERSION_1_3)
#if defined(VK_EXT_acquire_drm_display)
    vkAcquireDrmDisplayEXT = (PFN_vkAcquireDrmDisplayEXT) loadcb(context, "vkAcquireDrmDisplayEXT");
    vkGetDrmDisplayEXT = (PFN_vkGetDrmDisplayEXT) loadcb(context, "vkGetDrmDisplayEXT");
#endif // defined(VK_EXT_acquire_drm_display)
#if defined(VK_EXT_acquire_xlib_display)
    vkAcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT) loadcb(context, "vkAcquireXlibDisplayEXT");
    vkGetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT) loadcb(context, "vkGetRandROutputDisplayEXT");
#endif // defined(VK_EXT_acquire_xlib_display)
#if defined(VK_EXT_calibrated_timestamps)
    vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT) loadcb(context, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
#endif // defined(VK_EXT_calibrated_timestamps)
#if defined(VK_EXT_debug_report)
    vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT) loadcb(context, "vkCreateDebugReportCallbackEXT");
    vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT) loadcb(context, "vkDebugReportMessageEXT");
    vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT) loadcb(context, "vkDestroyDebugReportCallbackEXT");
#endif // defined(VK_EXT_debug_report)
#if defined(VK_EXT_debug_utils)
    vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT) loadcb(context, "vkCreateDebugUtilsMessengerEXT");
    vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT) loadcb(context, "vkDestroyDebugUtilsMessengerEXT");
    vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT) loadcb(context, "vkSubmitDebugUtilsMessageEXT");
#endif // defined(VK_EXT_debug_utils)
#if defined(VK_EXT_direct_mode_display)
    vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT) loadcb(context, "vkReleaseDisplayEXT");
#endif // defined(VK_EXT_direct_mode_display)
#if defined(VK_EXT_directfb_surface)
    vkCreateDirectFBSurfaceEXT = (PFN_vkCreateDirectFBSurfaceEXT) loadcb(context, "vkCreateDirectFBSurfaceEXT");
    vkGetPhysicalDeviceDirectFBPresentationSupportEXT = (PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT) loadcb(context, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
#endif // defined(VK_EXT_directfb_surface)
#if defined(VK_EXT_display_surface_counter)
    vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT) loadcb(context, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
#endif // defined(VK_EXT_display_surface_counter)
#if defined(VK_EXT_full_screen_exclusive)
    vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT) loadcb(context, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
#endif // defined(VK_EXT_full_screen_exclusive)
#if defined(VK_EXT_headless_surface)
    vkCreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT) loadcb(context, "vkCreateHeadlessSurfaceEXT");
#endif // defined(VK_EXT_headless_surface)
#if defined(VK_EXT_metal_surface)
    vkCreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT) loadcb(context, "vkCreateMetalSurfaceEXT");
#endif // defined(VK_EXT_metal_surface)
#if defined(VK_EXT_sample_locations)
    vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT) loadcb(context, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
#endif // defined(VK_EXT_sample_locations)
#if defined(VK_EXT_tooling_info)
    vkGetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT) loadcb(context, "vkGetPhysicalDeviceToolPropertiesEXT");
#endif // defined(VK_EXT_tooling_info)
#if defined(VK_FUCHSIA_imagepipe_surface)
    vkCreateImagePipeSurfaceFUCHSIA = (PFN_vkCreateImagePipeSurfaceFUCHSIA) loadcb(context, "vkCreateImagePipeSurfaceFUCHSIA");
#endif // defined(VK_FUCHSIA_imagepipe_surface)
#if defined(VK_GGP_stream_descriptor_surface)
    vkCreateStreamDescriptorSurfaceGGP = (PFN_vkCreateStreamDescriptorSurfaceGGP) loadcb(context, "vkCreateStreamDescriptorSurfaceGGP");
#endif // defined(VK_GGP_stream_descriptor_surface)
#if defined(VK_KHR_android_surface)
    vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR) loadcb(context, "vkCreateAndroidSurfaceKHR");
#endif // defined(VK_KHR_android_surface)
#if defined(VK_KHR_device_group_creation)
    vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR) loadcb(context, "vkEnumeratePhysicalDeviceGroupsKHR");
#endif // defined(VK_KHR_device_group_creation)
#if defined(VK_KHR_display)
    vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR) loadcb(context, "vkCreateDisplayModeKHR");
    vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR) loadcb(context, "vkCreateDisplayPlaneSurfaceKHR");
    vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR) loadcb(context, "vkGetDisplayModePropertiesKHR");
    vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR) loadcb(context, "vkGetDisplayPlaneCapabilitiesKHR");
    vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR) loadcb(context, "vkGetDisplayPlaneSupportedDisplaysKHR");
    vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR) loadcb(context, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR) loadcb(context, "vkGetPhysicalDeviceDisplayPropertiesKHR");
#endif // defined(VK_KHR_display)
#if defined(VK_KHR_external_fence_capabilities)
    vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR) loadcb(context, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
#endif // defined(VK_KHR_external_fence_capabilities)
#if defined(VK_KHR_external_memory_capabilities)
    vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR) loadcb(context, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
#endif // defined(VK_KHR_external_memory_capabilities)
#if defined(VK_KHR_external_semaphore_capabilities)
    vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR) loadcb(context, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
#endif // defined(VK_KHR_external_semaphore_capabilities)
#if defined(VK_KHR_fragment_shading_rate)
    vkGetPhysicalDeviceFragmentShadingRatesKHR = (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR) loadcb(context, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
#endif // defined(VK_KHR_fragment_shading_rate)
#if defined(VK_KHR_get_display_properties2)
    vkGetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR) loadcb(context, "vkGetDisplayModeProperties2KHR");
    vkGetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR) loadcb(context, "vkGetDisplayPlaneCapabilities2KHR");
    vkGetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR) loadcb(context, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    vkGetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR) loadcb(context, "vkGetPhysicalDeviceDisplayProperties2KHR");
#endif // defined(VK_KHR_get_display_properties2)
#if defined(VK_KHR_get_physical_device_properties2)
    vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR) loadcb(context, "vkGetPhysicalDeviceFeatures2KHR");
    vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR) loadcb(context, "vkGetPhysicalDeviceFormatProperties2KHR");
    vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR) loadcb(context, "vkGetPhysicalDeviceImageFormatProperties2KHR");
    vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR) loadcb(context, "vkGetPhysicalDeviceMemoryProperties2KHR");
    vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR) loadcb(context, "vkGetPhysicalDeviceProperties2KHR");
    vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR) loadcb(context, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR) loadcb(context, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
#endif // defined(VK_KHR_get_physical_device_properties2)
#if defined(VK_KHR_get_surface_capabilities2)
    vkGetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR) loadcb(context, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    vkGetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR) loadcb(context, "vkGetPhysicalDeviceSurfaceFormats2KHR");
#endif // defined(VK_KHR_get_surface_capabilities2)
#if defined(VK_KHR_performance_query)
    vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR) loadcb(context, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR) loadcb(context, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
#endif // defined(VK_KHR_performance_query)
#if defined(VK_KHR_surface)
    vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR) loadcb(context, "vkDestroySurfaceKHR");
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR) loadcb(context, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR) loadcb(context, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR) loadcb(context, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR) loadcb(context, "vkGetPhysicalDeviceSurfaceSupportKHR");
#endif // defined(VK_KHR_surface)
#if defined(VK_KHR_video_queue)
    vkGetPhysicalDeviceVideoCapabilitiesKHR = (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR) loadcb(context, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
    vkGetPhysicalDeviceVideoFormatPropertiesKHR = (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR) loadcb(context, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
#endif // defined(VK_KHR_video_queue)
#if defined(VK_KHR_wayland_surface)
    vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR) loadcb(context, "vkCreateWaylandSurfaceKHR");
    vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR) loadcb(context, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
#endif // defined(VK_KHR_wayland_surface)
#if defined(VK_KHR_win32_surface)
    vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR) loadcb(context, "vkCreateWin32SurfaceKHR");
    vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR) loadcb(context, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
#endif // defined(VK_KHR_win32_surface)
#if defined(VK_KHR_xcb_surface)
    vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR) loadcb(context, "vkCreateXcbSurfaceKHR");
    vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR) loadcb(context, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
#endif // defined(VK_KHR_xcb_surface)
#if defined(VK_KHR_xlib_surface)
    vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR) loadcb(context, "vkCreateXlibSurfaceKHR");
    vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR) loadcb(context, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif // defined(VK_KHR_xlib_surface)
#if defined(VK_MVK_ios_surface)
    vkCreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK) loadcb(context, "vkCreateIOSSurfaceMVK");
#endif // defined(VK_MVK_ios_surface)
#if defined(VK_MVK_macos_surface)
    vkCreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK) loadcb(context, "vkCreateMacOSSurfaceMVK");
#endif // defined(VK_MVK_macos_surface)
#if defined(VK_NN_vi_surface)
    vkCreateViSurfaceNN = (PFN_vkCreateViSurfaceNN) loadcb(context, "vkCreateViSurfaceNN");
#endif // defined(VK_NN_vi_surface)
#if defined(VK_NV_acquire_winrt_display)
    vkAcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV) loadcb(context, "vkAcquireWinrtDisplayNV");
    vkGetWinrtDisplayNV = (PFN_vkGetWinrtDisplayNV) loadcb(context, "vkGetWinrtDisplayNV");
#endif // defined(VK_NV_acquire_winrt_display)
#if defined(VK_NV_cooperative_matrix)
    vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV) loadcb(context, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
#endif // defined(VK_NV_cooperative_matrix)
#if defined(VK_NV_coverage_reduction_mode)
    vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV) loadcb(context, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
#endif // defined(VK_NV_coverage_reduction_mode)
#if defined(VK_NV_external_memory_capabilities)
    vkGetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV) loadcb(context, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
#endif // defined(VK_NV_external_memory_capabilities)
#if defined(VK_QNX_screen_surface)
    vkCreateScreenSurfaceQNX = (PFN_vkCreateScreenSurfaceQNX) loadcb(context, "vkCreateScreenSurfaceQNX");
    vkGetPhysicalDeviceScreenPresentationSupportQNX = (PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX) loadcb(context, "vkGetPhysicalDeviceScreenPresentationSupportQNX");
#endif // defined(VK_QNX_screen_surface)
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
    vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) loadcb(context, "vkGetPhysicalDevicePresentRectanglesKHR");
#endif // (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
}

static void loadDeviceFunctions(void* context, PFN_vkVoidFunction (*loadcb)(void*, const char*)) {
#if defined(VK_VERSION_1_0)
    vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers) loadcb(context, "vkAllocateCommandBuffers");
    vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets) loadcb(context, "vkAllocateDescriptorSets");
    vkAllocateMemory = (PFN_vkAllocateMemory) loadcb(context, "vkAllocateMemory");
    vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer) loadcb(context, "vkBeginCommandBuffer");
    vkBindBufferMemory = (PFN_vkBindBufferMemory) loadcb(context, "vkBindBufferMemory");
    vkBindImageMemory = (PFN_vkBindImageMemory) loadcb(context, "vkBindImageMemory");
    vkCmdBeginQuery = (PFN_vkCmdBeginQuery) loadcb(context, "vkCmdBeginQuery");
    vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass) loadcb(context, "vkCmdBeginRenderPass");
    vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets) loadcb(context, "vkCmdBindDescriptorSets");
    vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer) loadcb(context, "vkCmdBindIndexBuffer");
    vkCmdBindPipeline = (PFN_vkCmdBindPipeline) loadcb(context, "vkCmdBindPipeline");
    vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers) loadcb(context, "vkCmdBindVertexBuffers");
    vkCmdBlitImage = (PFN_vkCmdBlitImage) loadcb(context, "vkCmdBlitImage");
    vkCmdClearAttachments = (PFN_vkCmdClearAttachments) loadcb(context, "vkCmdClearAttachments");
    vkCmdClearColorImage = (PFN_vkCmdClearColorImage) loadcb(context, "vkCmdClearColorImage");
    vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage) loadcb(context, "vkCmdClearDepthStencilImage");
    vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer) loadcb(context, "vkCmdCopyBuffer");
    vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage) loadcb(context, "vkCmdCopyBufferToImage");
    vkCmdCopyImage = (PFN_vkCmdCopyImage) loadcb(context, "vkCmdCopyImage");
    vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer) loadcb(context, "vkCmdCopyImageToBuffer");
    vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults) loadcb(context, "vkCmdCopyQueryPoolResults");
    vkCmdDispatch = (PFN_vkCmdDispatch) loadcb(context, "vkCmdDispatch");
    vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect) loadcb(context, "vkCmdDispatchIndirect");
    vkCmdDraw = (PFN_vkCmdDraw) loadcb(context, "vkCmdDraw");
    vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed) loadcb(context, "vkCmdDrawIndexed");
    vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect) loadcb(context, "vkCmdDrawIndexedIndirect");
    vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect) loadcb(context, "vkCmdDrawIndirect");
    vkCmdEndQuery = (PFN_vkCmdEndQuery) loadcb(context, "vkCmdEndQuery");
    vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass) loadcb(context, "vkCmdEndRenderPass");
    vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands) loadcb(context, "vkCmdExecuteCommands");
    vkCmdFillBuffer = (PFN_vkCmdFillBuffer) loadcb(context, "vkCmdFillBuffer");
    vkCmdNextSubpass = (PFN_vkCmdNextSubpass) loadcb(context, "vkCmdNextSubpass");
    vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier) loadcb(context, "vkCmdPipelineBarrier");
    vkCmdPushConstants = (PFN_vkCmdPushConstants) loadcb(context, "vkCmdPushConstants");
    vkCmdResetEvent = (PFN_vkCmdResetEvent) loadcb(context, "vkCmdResetEvent");
    vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool) loadcb(context, "vkCmdResetQueryPool");
    vkCmdResolveImage = (PFN_vkCmdResolveImage) loadcb(context, "vkCmdResolveImage");
    vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants) loadcb(context, "vkCmdSetBlendConstants");
    vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias) loadcb(context, "vkCmdSetDepthBias");
    vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds) loadcb(context, "vkCmdSetDepthBounds");
    vkCmdSetEvent = (PFN_vkCmdSetEvent) loadcb(context, "vkCmdSetEvent");
    vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth) loadcb(context, "vkCmdSetLineWidth");
    vkCmdSetScissor = (PFN_vkCmdSetScissor) loadcb(context, "vkCmdSetScissor");
    vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask) loadcb(context, "vkCmdSetStencilCompareMask");
    vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference) loadcb(context, "vkCmdSetStencilReference");
    vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask) loadcb(context, "vkCmdSetStencilWriteMask");
    vkCmdSetViewport = (PFN_vkCmdSetViewport) loadcb(context, "vkCmdSetViewport");
    vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer) loadcb(context, "vkCmdUpdateBuffer");
    vkCmdWaitEvents = (PFN_vkCmdWaitEvents) loadcb(context, "vkCmdWaitEvents");
    vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp) loadcb(context, "vkCmdWriteTimestamp");
    vkCreateBuffer = (PFN_vkCreateBuffer) loadcb(context, "vkCreateBuffer");
    vkCreateBufferView = (PFN_vkCreateBufferView) loadcb(context, "vkCreateBufferView");
    vkCreateCommandPool = (PFN_vkCreateCommandPool) loadcb(context, "vkCreateCommandPool");
    vkCreateComputePipelines = (PFN_vkCreateComputePipelines) loadcb(context, "vkCreateComputePipelines");
    vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool) loadcb(context, "vkCreateDescriptorPool");
    vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout) loadcb(context, "vkCreateDescriptorSetLayout");
    vkCreateEvent = (PFN_vkCreateEvent) loadcb(context, "vkCreateEvent");
    vkCreateFence = (PFN_vkCreateFence) loadcb(context, "vkCreateFence");
    vkCreateFramebuffer = (PFN_vkCreateFramebuffer) loadcb(context, "vkCreateFramebuffer");
    vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines) loadcb(context, "vkCreateGraphicsPipelines");
    vkCreateImage = (PFN_vkCreateImage) loadcb(context, "vkCreateImage");
    vkCreateImageView = (PFN_vkCreateImageView) loadcb(context, "vkCreateImageView");
    vkCreatePipelineCache = (PFN_vkCreatePipelineCache) loadcb(context, "vkCreatePipelineCache");
    vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout) loadcb(context, "vkCreatePipelineLayout");
    vkCreateQueryPool = (PFN_vkCreateQueryPool) loadcb(context, "vkCreateQueryPool");
    vkCreateRenderPass = (PFN_vkCreateRenderPass) loadcb(context, "vkCreateRenderPass");
    vkCreateSampler = (PFN_vkCreateSampler) loadcb(context, "vkCreateSampler");
    vkCreateSemaphore = (PFN_vkCreateSemaphore) loadcb(context, "vkCreateSemaphore");
    vkCreateShaderModule = (PFN_vkCreateShaderModule) loadcb(context, "vkCreateShaderModule");
    vkDestroyBuffer = (PFN_vkDestroyBuffer) loadcb(context, "vkDestroyBuffer");
    vkDestroyBufferView = (PFN_vkDestroyBufferView) loadcb(context, "vkDestroyBufferView");
    vkDestroyCommandPool = (PFN_vkDestroyCommandPool) loadcb(context, "vkDestroyCommandPool");
    vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool) loadcb(context, "vkDestroyDescriptorPool");
    vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout) loadcb(context, "vkDestroyDescriptorSetLayout");
    vkDestroyDevice = (PFN_vkDestroyDevice) loadcb(context, "vkDestroyDevice");
    vkDestroyEvent = (PFN_vkDestroyEvent) loadcb(context, "vkDestroyEvent");
    vkDestroyFence = (PFN_vkDestroyFence) loadcb(context, "vkDestroyFence");
    vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer) loadcb(context, "vkDestroyFramebuffer");
    vkDestroyImage = (PFN_vkDestroyImage) loadcb(context, "vkDestroyImage");
    vkDestroyImageView = (PFN_vkDestroyImageView) loadcb(context, "vkDestroyImageView");
    vkDestroyPipeline = (PFN_vkDestroyPipeline) loadcb(context, "vkDestroyPipeline");
    vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache) loadcb(context, "vkDestroyPipelineCache");
    vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout) loadcb(context, "vkDestroyPipelineLayout");
    vkDestroyQueryPool = (PFN_vkDestroyQueryPool) loadcb(context, "vkDestroyQueryPool");
    vkDestroyRenderPass = (PFN_vkDestroyRenderPass) loadcb(context, "vkDestroyRenderPass");
    vkDestroySampler = (PFN_vkDestroySampler) loadcb(context, "vkDestroySampler");
    vkDestroySemaphore = (PFN_vkDestroySemaphore) loadcb(context, "vkDestroySemaphore");
    vkDestroyShaderModule = (PFN_vkDestroyShaderModule) loadcb(context, "vkDestroyShaderModule");
    vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle) loadcb(context, "vkDeviceWaitIdle");
    vkEndCommandBuffer = (PFN_vkEndCommandBuffer) loadcb(context, "vkEndCommandBuffer");
    vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges) loadcb(context, "vkFlushMappedMemoryRanges");
    vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers) loadcb(context, "vkFreeCommandBuffers");
    vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets) loadcb(context, "vkFreeDescriptorSets");
    vkFreeMemory = (PFN_vkFreeMemory) loadcb(context, "vkFreeMemory");
    vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements) loadcb(context, "vkGetBufferMemoryRequirements");
    vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment) loadcb(context, "vkGetDeviceMemoryCommitment");
    vkGetDeviceQueue = (PFN_vkGetDeviceQueue) loadcb(context, "vkGetDeviceQueue");
    vkGetEventStatus = (PFN_vkGetEventStatus) loadcb(context, "vkGetEventStatus");
    vkGetFenceStatus = (PFN_vkGetFenceStatus) loadcb(context, "vkGetFenceStatus");
    vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements) loadcb(context, "vkGetImageMemoryRequirements");
    vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements) loadcb(context, "vkGetImageSparseMemoryRequirements");
    vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout) loadcb(context, "vkGetImageSubresourceLayout");
    vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData) loadcb(context, "vkGetPipelineCacheData");
    vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults) loadcb(context, "vkGetQueryPoolResults");
    vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity) loadcb(context, "vkGetRenderAreaGranularity");
    vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges) loadcb(context, "vkInvalidateMappedMemoryRanges");
    vkMapMemory = (PFN_vkMapMemory) loadcb(context, "vkMapMemory");
    vkMergePipelineCaches = (PFN_vkMergePipelineCaches) loadcb(context, "vkMergePipelineCaches");
    vkQueueBindSparse = (PFN_vkQueueBindSparse) loadcb(context, "vkQueueBindSparse");
    vkQueueSubmit = (PFN_vkQueueSubmit) loadcb(context, "vkQueueSubmit");
    vkQueueWaitIdle = (PFN_vkQueueWaitIdle) loadcb(context, "vkQueueWaitIdle");
    vkResetCommandBuffer = (PFN_vkResetCommandBuffer) loadcb(context, "vkResetCommandBuffer");
    vkResetCommandPool = (PFN_vkResetCommandPool) loadcb(context, "vkResetCommandPool");
    vkResetDescriptorPool = (PFN_vkResetDescriptorPool) loadcb(context, "vkResetDescriptorPool");
    vkResetEvent = (PFN_vkResetEvent) loadcb(context, "vkResetEvent");
    vkResetFences = (PFN_vkResetFences) loadcb(context, "vkResetFences");
    vkSetEvent = (PFN_vkSetEvent) loadcb(context, "vkSetEvent");
    vkUnmapMemory = (PFN_vkUnmapMemory) loadcb(context, "vkUnmapMemory");
    vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets) loadcb(context, "vkUpdateDescriptorSets");
    vkWaitForFences = (PFN_vkWaitForFences) loadcb(context, "vkWaitForFences");
#endif // defined(VK_VERSION_1_0)
#if defined(VK_VERSION_1_1)
    vkBindBufferMemory2 = (PFN_vkBindBufferMemory2) loadcb(context, "vkBindBufferMemory2");
    vkBindImageMemory2 = (PFN_vkBindImageMemory2) loadcb(context, "vkBindImageMemory2");
    vkCmdDispatchBase = (PFN_vkCmdDispatchBase) loadcb(context, "vkCmdDispatchBase");
    vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask) loadcb(context, "vkCmdSetDeviceMask");
    vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate) loadcb(context, "vkCreateDescriptorUpdateTemplate");
    vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion) loadcb(context, "vkCreateSamplerYcbcrConversion");
    vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate) loadcb(context, "vkDestroyDescriptorUpdateTemplate");
    vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion) loadcb(context, "vkDestroySamplerYcbcrConversion");
    vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2) loadcb(context, "vkGetBufferMemoryRequirements2");
    vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport) loadcb(context, "vkGetDescriptorSetLayoutSupport");
    vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures) loadcb(context, "vkGetDeviceGroupPeerMemoryFeatures");
    vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2) loadcb(context, "vkGetDeviceQueue2");
    vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2) loadcb(context, "vkGetImageMemoryRequirements2");
    vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2) loadcb(context, "vkGetImageSparseMemoryRequirements2");
    vkTrimCommandPool = (PFN_vkTrimCommandPool) loadcb(context, "vkTrimCommandPool");
    vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate) loadcb(context, "vkUpdateDescriptorSetWithTemplate");
#endif // defined(VK_VERSION_1_1)
#if defined(VK_VERSION_1_2)
    vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2) loadcb(context, "vkCmdBeginRenderPass2");
    vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount) loadcb(context, "vkCmdDrawIndexedIndirectCount");
    vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount) loadcb(context, "vkCmdDrawIndirectCount");
    vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2) loadcb(context, "vkCmdEndRenderPass2");
    vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2) loadcb(context, "vkCmdNextSubpass2");
    vkCreateRenderPass2 = (PFN_vkCreateRenderPass2) loadcb(context, "vkCreateRenderPass2");
    vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress) loadcb(context, "vkGetBufferDeviceAddress");
    vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress) loadcb(context, "vkGetBufferOpaqueCaptureAddress");
    vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress) loadcb(context, "vkGetDeviceMemoryOpaqueCaptureAddress");
    vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue) loadcb(context, "vkGetSemaphoreCounterValue");
    vkResetQueryPool = (PFN_vkResetQueryPool) loadcb(context, "vkResetQueryPool");
    vkSignalSemaphore = (PFN_vkSignalSemaphore) loadcb(context, "vkSignalSemaphore");
    vkWaitSemaphores = (PFN_vkWaitSemaphores) loadcb(context, "vkWaitSemaphores");
#endif // defined(VK_VERSION_1_2)
#if defined(VK_VERSION_1_3)
    vkCmdBeginRendering = (PFN_vkCmdBeginRendering) loadcb(context, "vkCmdBeginRendering");
    vkCmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2) loadcb(context, "vkCmdBindVertexBuffers2");
    vkCmdBlitImage2 = (PFN_vkCmdBlitImage2) loadcb(context, "vkCmdBlitImage2");
    vkCmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2) loadcb(context, "vkCmdCopyBuffer2");
    vkCmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2) loadcb(context, "vkCmdCopyBufferToImage2");
    vkCmdCopyImage2 = (PFN_vkCmdCopyImage2) loadcb(context, "vkCmdCopyImage2");
    vkCmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2) loadcb(context, "vkCmdCopyImageToBuffer2");
    vkCmdEndRendering = (PFN_vkCmdEndRendering) loadcb(context, "vkCmdEndRendering");
    vkCmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2) loadcb(context, "vkCmdPipelineBarrier2");
    vkCmdResetEvent2 = (PFN_vkCmdResetEvent2) loadcb(context, "vkCmdResetEvent2");
    vkCmdResolveImage2 = (PFN_vkCmdResolveImage2) loadcb(context, "vkCmdResolveImage2");
    vkCmdSetCullMode = (PFN_vkCmdSetCullMode) loadcb(context, "vkCmdSetCullMode");
    vkCmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable) loadcb(context, "vkCmdSetDepthBiasEnable");
    vkCmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable) loadcb(context, "vkCmdSetDepthBoundsTestEnable");
    vkCmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp) loadcb(context, "vkCmdSetDepthCompareOp");
    vkCmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable) loadcb(context, "vkCmdSetDepthTestEnable");
    vkCmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable) loadcb(context, "vkCmdSetDepthWriteEnable");
    vkCmdSetEvent2 = (PFN_vkCmdSetEvent2) loadcb(context, "vkCmdSetEvent2");
    vkCmdSetFrontFace = (PFN_vkCmdSetFrontFace) loadcb(context, "vkCmdSetFrontFace");
    vkCmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable) loadcb(context, "vkCmdSetPrimitiveRestartEnable");
    vkCmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology) loadcb(context, "vkCmdSetPrimitiveTopology");
    vkCmdSetRasterizerDiscardEnable = (PFN_vkCmdSetRasterizerDiscardEnable) loadcb(context, "vkCmdSetRasterizerDiscardEnable");
    vkCmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount) loadcb(context, "vkCmdSetScissorWithCount");
    vkCmdSetStencilOp = (PFN_vkCmdSetStencilOp) loadcb(context, "vkCmdSetStencilOp");
    vkCmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable) loadcb(context, "vkCmdSetStencilTestEnable");
    vkCmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount) loadcb(context, "vkCmdSetViewportWithCount");
    vkCmdWaitEvents2 = (PFN_vkCmdWaitEvents2) loadcb(context, "vkCmdWaitEvents2");
    vkCmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2) loadcb(context, "vkCmdWriteTimestamp2");
    vkCreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot) loadcb(context, "vkCreatePrivateDataSlot");
    vkDestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot) loadcb(context, "vkDestroyPrivateDataSlot");
    vkGetDeviceBufferMemoryRequirements = (PFN_vkGetDeviceBufferMemoryRequirements) loadcb(context, "vkGetDeviceBufferMemoryRequirements");
    vkGetDeviceImageMemoryRequirements = (PFN_vkGetDeviceImageMemoryRequirements) loadcb(context, "vkGetDeviceImageMemoryRequirements");
    vkGetDeviceImageSparseMemoryRequirements = (PFN_vkGetDeviceImageSparseMemoryRequirements) loadcb(context, "vkGetDeviceImageSparseMemoryRequirements");
    vkGetPrivateData = (PFN_vkGetPrivateData) loadcb(context, "vkGetPrivateData");
    vkQueueSubmit2 = (PFN_vkQueueSubmit2) loadcb(context, "vkQueueSubmit2");
    vkSetPrivateData = (PFN_vkSetPrivateData) loadcb(context, "vkSetPrivateData");
#endif // defined(VK_VERSION_1_3)
#if defined(VK_AMD_buffer_marker)
    vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD) loadcb(context, "vkCmdWriteBufferMarkerAMD");
#endif // defined(VK_AMD_buffer_marker)
#if defined(VK_AMD_display_native_hdr)
    vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD) loadcb(context, "vkSetLocalDimmingAMD");
#endif // defined(VK_AMD_display_native_hdr)
#if defined(VK_AMD_draw_indirect_count)
    vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD) loadcb(context, "vkCmdDrawIndexedIndirectCountAMD");
    vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD) loadcb(context, "vkCmdDrawIndirectCountAMD");
#endif // defined(VK_AMD_draw_indirect_count)
#if defined(VK_AMD_shader_info)
    vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD) loadcb(context, "vkGetShaderInfoAMD");
#endif // defined(VK_AMD_shader_info)
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
    vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID) loadcb(context, "vkGetAndroidHardwareBufferPropertiesANDROID");
    vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID) loadcb(context, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)
#if defined(VK_ANDROID_native_buffer)
    vkAcquireImageANDROID = (PFN_vkAcquireImageANDROID) loadcb(context, "vkAcquireImageANDROID");
    vkGetSwapchainGrallocUsage2ANDROID = (PFN_vkGetSwapchainGrallocUsage2ANDROID) loadcb(context, "vkGetSwapchainGrallocUsage2ANDROID");
    vkGetSwapchainGrallocUsageANDROID = (PFN_vkGetSwapchainGrallocUsageANDROID) loadcb(context, "vkGetSwapchainGrallocUsageANDROID");
    vkQueueSignalReleaseImageANDROID = (PFN_vkQueueSignalReleaseImageANDROID) loadcb(context, "vkQueueSignalReleaseImageANDROID");
#endif // defined(VK_ANDROID_native_buffer)
#if defined(VK_EXT_buffer_device_address)
    vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT) loadcb(context, "vkGetBufferDeviceAddressEXT");
#endif // defined(VK_EXT_buffer_device_address)
#if defined(VK_EXT_calibrated_timestamps)
    vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT) loadcb(context, "vkGetCalibratedTimestampsEXT");
#endif // defined(VK_EXT_calibrated_timestamps)
#if defined(VK_EXT_color_write_enable)
    vkCmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT) loadcb(context, "vkCmdSetColorWriteEnableEXT");
#endif // defined(VK_EXT_color_write_enable)
#if defined(VK_EXT_conditional_rendering)
    vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT) loadcb(context, "vkCmdBeginConditionalRenderingEXT");
    vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT) loadcb(context, "vkCmdEndConditionalRenderingEXT");
#endif // defined(VK_EXT_conditional_rendering)
#if defined(VK_EXT_debug_marker)
    vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT) loadcb(context, "vkCmdDebugMarkerBeginEXT");
    vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT) loadcb(context, "vkCmdDebugMarkerEndEXT");
    vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT) loadcb(context, "vkCmdDebugMarkerInsertEXT");
    vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT) loadcb(context, "vkDebugMarkerSetObjectNameEXT");
    vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT) loadcb(context, "vkDebugMarkerSetObjectTagEXT");
#endif // defined(VK_EXT_debug_marker)
#if defined(VK_EXT_debug_utils)
    vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT) loadcb(context, "vkCmdBeginDebugUtilsLabelEXT");
    vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT) loadcb(context, "vkCmdEndDebugUtilsLabelEXT");
    vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT) loadcb(context, "vkCmdInsertDebugUtilsLabelEXT");
    vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT) loadcb(context, "vkQueueBeginDebugUtilsLabelEXT");
    vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT) loadcb(context, "vkQueueEndDebugUtilsLabelEXT");
    vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT) loadcb(context, "vkQueueInsertDebugUtilsLabelEXT");
    vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT) loadcb(context, "vkSetDebugUtilsObjectNameEXT");
    vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT) loadcb(context, "vkSetDebugUtilsObjectTagEXT");
#endif // defined(VK_EXT_debug_utils)
#if defined(VK_EXT_discard_rectangles)
    vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT) loadcb(context, "vkCmdSetDiscardRectangleEXT");
#endif // defined(VK_EXT_discard_rectangles)
#if defined(VK_EXT_display_control)
    vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT) loadcb(context, "vkDisplayPowerControlEXT");
    vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT) loadcb(context, "vkGetSwapchainCounterEXT");
    vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT) loadcb(context, "vkRegisterDeviceEventEXT");
    vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT) loadcb(context, "vkRegisterDisplayEventEXT");
#endif // defined(VK_EXT_display_control)
#if defined(VK_EXT_extended_dynamic_state)
    vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT) loadcb(context, "vkCmdBindVertexBuffers2EXT");
    vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT) loadcb(context, "vkCmdSetCullModeEXT");
    vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT) loadcb(context, "vkCmdSetDepthBoundsTestEnableEXT");
    vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT) loadcb(context, "vkCmdSetDepthCompareOpEXT");
    vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT) loadcb(context, "vkCmdSetDepthTestEnableEXT");
    vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT) loadcb(context, "vkCmdSetDepthWriteEnableEXT");
    vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT) loadcb(context, "vkCmdSetFrontFaceEXT");
    vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT) loadcb(context, "vkCmdSetPrimitiveTopologyEXT");
    vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT) loadcb(context, "vkCmdSetScissorWithCountEXT");
    vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT) loadcb(context, "vkCmdSetStencilOpEXT");
    vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT) loadcb(context, "vkCmdSetStencilTestEnableEXT");
    vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT) loadcb(context, "vkCmdSetViewportWithCountEXT");
#endif // defined(VK_EXT_extended_dynamic_state)
#if defined(VK_EXT_extended_dynamic_state2)
    vkCmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT) loadcb(context, "vkCmdSetDepthBiasEnableEXT");
    vkCmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT) loadcb(context, "vkCmdSetLogicOpEXT");
    vkCmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT) loadcb(context, "vkCmdSetPatchControlPointsEXT");
    vkCmdSetPrimitiveRestartEnableEXT = (PFN_vkCmdSetPrimitiveRestartEnableEXT) loadcb(context, "vkCmdSetPrimitiveRestartEnableEXT");
    vkCmdSetRasterizerDiscardEnableEXT = (PFN_vkCmdSetRasterizerDiscardEnableEXT) loadcb(context, "vkCmdSetRasterizerDiscardEnableEXT");
#endif // defined(VK_EXT_extended_dynamic_state2)
#if defined(VK_EXT_external_memory_host)
    vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT) loadcb(context, "vkGetMemoryHostPointerPropertiesEXT");
#endif // defined(VK_EXT_external_memory_host)
#if defined(VK_EXT_full_screen_exclusive)
    vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT) loadcb(context, "vkAcquireFullScreenExclusiveModeEXT");
    vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT) loadcb(context, "vkReleaseFullScreenExclusiveModeEXT");
#endif // defined(VK_EXT_full_screen_exclusive)
#if defined(VK_EXT_hdr_metadata)
    vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT) loadcb(context, "vkSetHdrMetadataEXT");
#endif // defined(VK_EXT_hdr_metadata)
#if defined(VK_EXT_host_query_reset)
    vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT) loadcb(context, "vkResetQueryPoolEXT");
#endif // defined(VK_EXT_host_query_reset)
#if defined(VK_EXT_image_compression_control)
    vkGetImageSubresourceLayout2EXT = (PFN_vkGetImageSubresourceLayout2EXT) loadcb(context, "vkGetImageSubresourceLayout2EXT");
#endif // defined(VK_EXT_image_compression_control)
#if defined(VK_EXT_image_drm_format_modifier)
    vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT) loadcb(context, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif // defined(VK_EXT_image_drm_format_modifier)
#if defined(VK_EXT_line_rasterization)
    vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT) loadcb(context, "vkCmdSetLineStippleEXT");
#endif // defined(VK_EXT_line_rasterization)
#if defined(VK_EXT_metal_objects)
    vkExportMetalObjectsEXT = (PFN_vkExportMetalObjectsEXT) loadcb(context, "vkExportMetalObjectsEXT");
#endif // defined(VK_EXT_metal_objects)
#if defined(VK_EXT_multi_draw)
    vkCmdDrawMultiEXT = (PFN_vkCmdDrawMultiEXT) loadcb(context, "vkCmdDrawMultiEXT");
    vkCmdDrawMultiIndexedEXT = (PFN_vkCmdDrawMultiIndexedEXT) loadcb(context, "vkCmdDrawMultiIndexedEXT");
#endif // defined(VK_EXT_multi_draw)
#if defined(VK_EXT_pageable_device_local_memory)
    vkSetDeviceMemoryPriorityEXT = (PFN_vkSetDeviceMemoryPriorityEXT) loadcb(context, "vkSetDeviceMemoryPriorityEXT");
#endif // defined(VK_EXT_pageable_device_local_memory)
#if defined(VK_EXT_pipeline_properties)
    vkGetPipelinePropertiesEXT = (PFN_vkGetPipelinePropertiesEXT) loadcb(context, "vkGetPipelinePropertiesEXT");
#endif // defined(VK_EXT_pipeline_properties)
#if defined(VK_EXT_private_data)
    vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT) loadcb(context, "vkCreatePrivateDataSlotEXT");
    vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT) loadcb(context, "vkDestroyPrivateDataSlotEXT");
    vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT) loadcb(context, "vkGetPrivateDataEXT");
    vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT) loadcb(context, "vkSetPrivateDataEXT");
#endif // defined(VK_EXT_private_data)
#if defined(VK_EXT_sample_locations)
    vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT) loadcb(context, "vkCmdSetSampleLocationsEXT");
#endif // defined(VK_EXT_sample_locations)
#if defined(VK_EXT_transform_feedback)
    vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT) loadcb(context, "vkCmdBeginQueryIndexedEXT");
    vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT) loadcb(context, "vkCmdBeginTransformFeedbackEXT");
    vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT) loadcb(context, "vkCmdBindTransformFeedbackBuffersEXT");
    vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT) loadcb(context, "vkCmdDrawIndirectByteCountEXT");
    vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT) loadcb(context, "vkCmdEndQueryIndexedEXT");
    vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT) loadcb(context, "vkCmdEndTransformFeedbackEXT");
#endif // defined(VK_EXT_transform_feedback)
#if defined(VK_EXT_validation_cache)
    vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT) loadcb(context, "vkCreateValidationCacheEXT");
    vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT) loadcb(context, "vkDestroyValidationCacheEXT");
    vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT) loadcb(context, "vkGetValidationCacheDataEXT");
    vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT) loadcb(context, "vkMergeValidationCachesEXT");
#endif // defined(VK_EXT_validation_cache)
#if defined(VK_EXT_vertex_input_dynamic_state)
    vkCmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT) loadcb(context, "vkCmdSetVertexInputEXT");
#endif // defined(VK_EXT_vertex_input_dynamic_state)
#if defined(VK_FUCHSIA_buffer_collection)
    vkCreateBufferCollectionFUCHSIA = (PFN_vkCreateBufferCollectionFUCHSIA) loadcb(context, "vkCreateBufferCollectionFUCHSIA");
    vkDestroyBufferCollectionFUCHSIA = (PFN_vkDestroyBufferCollectionFUCHSIA) loadcb(context, "vkDestroyBufferCollectionFUCHSIA");
    vkGetBufferCollectionPropertiesFUCHSIA = (PFN_vkGetBufferCollectionPropertiesFUCHSIA) loadcb(context, "vkGetBufferCollectionPropertiesFUCHSIA");
    vkSetBufferCollectionBufferConstraintsFUCHSIA = (PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA) loadcb(context, "vkSetBufferCollectionBufferConstraintsFUCHSIA");
    vkSetBufferCollectionImageConstraintsFUCHSIA = (PFN_vkSetBufferCollectionImageConstraintsFUCHSIA) loadcb(context, "vkSetBufferCollectionImageConstraintsFUCHSIA");
#endif // defined(VK_FUCHSIA_buffer_collection)
#if defined(VK_FUCHSIA_external_memory)
    vkGetMemoryZirconHandleFUCHSIA = (PFN_vkGetMemoryZirconHandleFUCHSIA) loadcb(context, "vkGetMemoryZirconHandleFUCHSIA");
    vkGetMemoryZirconHandlePropertiesFUCHSIA = (PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA) loadcb(context, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
#endif // defined(VK_FUCHSIA_external_memory)
#if defined(VK_FUCHSIA_external_semaphore)
    vkGetSemaphoreZirconHandleFUCHSIA = (PFN_vkGetSemaphoreZirconHandleFUCHSIA) loadcb(context, "vkGetSemaphoreZirconHandleFUCHSIA");
    vkImportSemaphoreZirconHandleFUCHSIA = (PFN_vkImportSemaphoreZirconHandleFUCHSIA) loadcb(context, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif // defined(VK_FUCHSIA_external_semaphore)
#if defined(VK_GOOGLE_display_timing)
    vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE) loadcb(context, "vkGetPastPresentationTimingGOOGLE");
    vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE) loadcb(context, "vkGetRefreshCycleDurationGOOGLE");
#endif // defined(VK_GOOGLE_display_timing)
#if defined(VK_HUAWEI_invocation_mask)
    vkCmdBindInvocationMaskHUAWEI = (PFN_vkCmdBindInvocationMaskHUAWEI) loadcb(context, "vkCmdBindInvocationMaskHUAWEI");
#endif // defined(VK_HUAWEI_invocation_mask)
#if defined(VK_HUAWEI_subpass_shading)
    vkCmdSubpassShadingHUAWEI = (PFN_vkCmdSubpassShadingHUAWEI) loadcb(context, "vkCmdSubpassShadingHUAWEI");
    vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = (PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI) loadcb(context, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI");
#endif // defined(VK_HUAWEI_subpass_shading)
#if defined(VK_INTEL_performance_query)
    vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL) loadcb(context, "vkAcquirePerformanceConfigurationINTEL");
    vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL) loadcb(context, "vkCmdSetPerformanceMarkerINTEL");
    vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL) loadcb(context, "vkCmdSetPerformanceOverrideINTEL");
    vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL) loadcb(context, "vkCmdSetPerformanceStreamMarkerINTEL");
    vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL) loadcb(context, "vkGetPerformanceParameterINTEL");
    vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL) loadcb(context, "vkInitializePerformanceApiINTEL");
    vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL) loadcb(context, "vkQueueSetPerformanceConfigurationINTEL");
    vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL) loadcb(context, "vkReleasePerformanceConfigurationINTEL");
    vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL) loadcb(context, "vkUninitializePerformanceApiINTEL");
#endif // defined(VK_INTEL_performance_query)
#if defined(VK_KHR_acceleration_structure)
    vkBuildAccelerationStructuresKHR = (PFN_vkBuildAccelerationStructuresKHR) loadcb(context, "vkBuildAccelerationStructuresKHR");
    vkCmdBuildAccelerationStructuresIndirectKHR = (PFN_vkCmdBuildAccelerationStructuresIndirectKHR) loadcb(context, "vkCmdBuildAccelerationStructuresIndirectKHR");
    vkCmdBuildAccelerationStructuresKHR = (PFN_vkCmdBuildAccelerationStructuresKHR) loadcb(context, "vkCmdBuildAccelerationStructuresKHR");
    vkCmdCopyAccelerationStructureKHR = (PFN_vkCmdCopyAccelerationStructureKHR) loadcb(context, "vkCmdCopyAccelerationStructureKHR");
    vkCmdCopyAccelerationStructureToMemoryKHR = (PFN_vkCmdCopyAccelerationStructureToMemoryKHR) loadcb(context, "vkCmdCopyAccelerationStructureToMemoryKHR");
    vkCmdCopyMemoryToAccelerationStructureKHR = (PFN_vkCmdCopyMemoryToAccelerationStructureKHR) loadcb(context, "vkCmdCopyMemoryToAccelerationStructureKHR");
    vkCmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR) loadcb(context, "vkCmdWriteAccelerationStructuresPropertiesKHR");
    vkCopyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR) loadcb(context, "vkCopyAccelerationStructureKHR");
    vkCopyAccelerationStructureToMemoryKHR = (PFN_vkCopyAccelerationStructureToMemoryKHR) loadcb(context, "vkCopyAccelerationStructureToMemoryKHR");
    vkCopyMemoryToAccelerationStructureKHR = (PFN_vkCopyMemoryToAccelerationStructureKHR) loadcb(context, "vkCopyMemoryToAccelerationStructureKHR");
    vkCreateAccelerationStructureKHR = (PFN_vkCreateAccelerationStructureKHR) loadcb(context, "vkCreateAccelerationStructureKHR");
    vkDestroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR) loadcb(context, "vkDestroyAccelerationStructureKHR");
    vkGetAccelerationStructureBuildSizesKHR = (PFN_vkGetAccelerationStructureBuildSizesKHR) loadcb(context, "vkGetAccelerationStructureBuildSizesKHR");
    vkGetAccelerationStructureDeviceAddressKHR = (PFN_vkGetAccelerationStructureDeviceAddressKHR) loadcb(context, "vkGetAccelerationStructureDeviceAddressKHR");
    vkGetDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR) loadcb(context, "vkGetDeviceAccelerationStructureCompatibilityKHR");
    vkWriteAccelerationStructuresPropertiesKHR = (PFN_vkWriteAccelerationStructuresPropertiesKHR) loadcb(context, "vkWriteAccelerationStructuresPropertiesKHR");
#endif // defined(VK_KHR_acceleration_structure)
#if defined(VK_KHR_bind_memory2)
    vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR) loadcb(context, "vkBindBufferMemory2KHR");
    vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR) loadcb(context, "vkBindImageMemory2KHR");
#endif // defined(VK_KHR_bind_memory2)
#if defined(VK_KHR_buffer_device_address)
    vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR) loadcb(context, "vkGetBufferDeviceAddressKHR");
    vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR) loadcb(context, "vkGetBufferOpaqueCaptureAddressKHR");
    vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR) loadcb(context, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
#endif // defined(VK_KHR_buffer_device_address)
#if defined(VK_KHR_copy_commands2)
    vkCmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR) loadcb(context, "vkCmdBlitImage2KHR");
    vkCmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR) loadcb(context, "vkCmdCopyBuffer2KHR");
    vkCmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR) loadcb(context, "vkCmdCopyBufferToImage2KHR");
    vkCmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR) loadcb(context, "vkCmdCopyImage2KHR");
    vkCmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR) loadcb(context, "vkCmdCopyImageToBuffer2KHR");
    vkCmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR) loadcb(context, "vkCmdResolveImage2KHR");
#endif // defined(VK_KHR_copy_commands2)
#if defined(VK_KHR_create_renderpass2)
    vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR) loadcb(context, "vkCmdBeginRenderPass2KHR");
    vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR) loadcb(context, "vkCmdEndRenderPass2KHR");
    vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR) loadcb(context, "vkCmdNextSubpass2KHR");
    vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR) loadcb(context, "vkCreateRenderPass2KHR");
#endif // defined(VK_KHR_create_renderpass2)
#if defined(VK_KHR_deferred_host_operations)
    vkCreateDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR) loadcb(context, "vkCreateDeferredOperationKHR");
    vkDeferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR) loadcb(context, "vkDeferredOperationJoinKHR");
    vkDestroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR) loadcb(context, "vkDestroyDeferredOperationKHR");
    vkGetDeferredOperationMaxConcurrencyKHR = (PFN_vkGetDeferredOperationMaxConcurrencyKHR) loadcb(context, "vkGetDeferredOperationMaxConcurrencyKHR");
    vkGetDeferredOperationResultKHR = (PFN_vkGetDeferredOperationResultKHR) loadcb(context, "vkGetDeferredOperationResultKHR");
#endif // defined(VK_KHR_deferred_host_operations)
#if defined(VK_KHR_descriptor_update_template)
    vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR) loadcb(context, "vkCreateDescriptorUpdateTemplateKHR");
    vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR) loadcb(context, "vkDestroyDescriptorUpdateTemplateKHR");
    vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR) loadcb(context, "vkUpdateDescriptorSetWithTemplateKHR");
#endif // defined(VK_KHR_descriptor_update_template)
#if defined(VK_KHR_device_group)
    vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR) loadcb(context, "vkCmdDispatchBaseKHR");
    vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR) loadcb(context, "vkCmdSetDeviceMaskKHR");
    vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR) loadcb(context, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
#endif // defined(VK_KHR_device_group)
#if defined(VK_KHR_display_swapchain)
    vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR) loadcb(context, "vkCreateSharedSwapchainsKHR");
#endif // defined(VK_KHR_display_swapchain)
#if defined(VK_KHR_draw_indirect_count)
    vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR) loadcb(context, "vkCmdDrawIndexedIndirectCountKHR");
    vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR) loadcb(context, "vkCmdDrawIndirectCountKHR");
#endif // defined(VK_KHR_draw_indirect_count)
#if defined(VK_KHR_dynamic_rendering)
    vkCmdBeginRenderingKHR = (PFN_vkCmdBeginRenderingKHR) loadcb(context, "vkCmdBeginRenderingKHR");
    vkCmdEndRenderingKHR = (PFN_vkCmdEndRenderingKHR) loadcb(context, "vkCmdEndRenderingKHR");
#endif // defined(VK_KHR_dynamic_rendering)
#if defined(VK_KHR_external_fence_fd)
    vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR) loadcb(context, "vkGetFenceFdKHR");
    vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR) loadcb(context, "vkImportFenceFdKHR");
#endif // defined(VK_KHR_external_fence_fd)
#if defined(VK_KHR_external_fence_win32)
    vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR) loadcb(context, "vkGetFenceWin32HandleKHR");
    vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR) loadcb(context, "vkImportFenceWin32HandleKHR");
#endif // defined(VK_KHR_external_fence_win32)
#if defined(VK_KHR_external_memory_fd)
    vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR) loadcb(context, "vkGetMemoryFdKHR");
    vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR) loadcb(context, "vkGetMemoryFdPropertiesKHR");
#endif // defined(VK_KHR_external_memory_fd)
#if defined(VK_KHR_external_memory_win32)
    vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR) loadcb(context, "vkGetMemoryWin32HandleKHR");
    vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR) loadcb(context, "vkGetMemoryWin32HandlePropertiesKHR");
#endif // defined(VK_KHR_external_memory_win32)
#if defined(VK_KHR_external_semaphore_fd)
    vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR) loadcb(context, "vkGetSemaphoreFdKHR");
    vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR) loadcb(context, "vkImportSemaphoreFdKHR");
#endif // defined(VK_KHR_external_semaphore_fd)
#if defined(VK_KHR_external_semaphore_win32)
    vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR) loadcb(context, "vkGetSemaphoreWin32HandleKHR");
    vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR) loadcb(context, "vkImportSemaphoreWin32HandleKHR");
#endif // defined(VK_KHR_external_semaphore_win32)
#if defined(VK_KHR_fragment_shading_rate)
    vkCmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR) loadcb(context, "vkCmdSetFragmentShadingRateKHR");
#endif // defined(VK_KHR_fragment_shading_rate)
#if defined(VK_KHR_get_memory_requirements2)
    vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR) loadcb(context, "vkGetBufferMemoryRequirements2KHR");
    vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR) loadcb(context, "vkGetImageMemoryRequirements2KHR");
    vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR) loadcb(context, "vkGetImageSparseMemoryRequirements2KHR");
#endif // defined(VK_KHR_get_memory_requirements2)
#if defined(VK_KHR_maintenance1)
    vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR) loadcb(context, "vkTrimCommandPoolKHR");
#endif // defined(VK_KHR_maintenance1)
#if defined(VK_KHR_maintenance3)
    vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR) loadcb(context, "vkGetDescriptorSetLayoutSupportKHR");
#endif // defined(VK_KHR_maintenance3)
#if defined(VK_KHR_maintenance4)
    vkGetDeviceBufferMemoryRequirementsKHR = (PFN_vkGetDeviceBufferMemoryRequirementsKHR) loadcb(context, "vkGetDeviceBufferMemoryRequirementsKHR");
    vkGetDeviceImageMemoryRequirementsKHR = (PFN_vkGetDeviceImageMemoryRequirementsKHR) loadcb(context, "vkGetDeviceImageMemoryRequirementsKHR");
    vkGetDeviceImageSparseMemoryRequirementsKHR = (PFN_vkGetDeviceImageSparseMemoryRequirementsKHR) loadcb(context, "vkGetDeviceImageSparseMemoryRequirementsKHR");
#endif // defined(VK_KHR_maintenance4)
#if defined(VK_KHR_performance_query)
    vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR) loadcb(context, "vkAcquireProfilingLockKHR");
    vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR) loadcb(context, "vkReleaseProfilingLockKHR");
#endif // defined(VK_KHR_performance_query)
#if defined(VK_KHR_pipeline_executable_properties)
    vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR) loadcb(context, "vkGetPipelineExecutableInternalRepresentationsKHR");
    vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR) loadcb(context, "vkGetPipelineExecutablePropertiesKHR");
    vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR) loadcb(context, "vkGetPipelineExecutableStatisticsKHR");
#endif // defined(VK_KHR_pipeline_executable_properties)
#if defined(VK_KHR_present_wait)
    vkWaitForPresentKHR = (PFN_vkWaitForPresentKHR) loadcb(context, "vkWaitForPresentKHR");
#endif // defined(VK_KHR_present_wait)
#if defined(VK_KHR_push_descriptor)
    vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR) loadcb(context, "vkCmdPushDescriptorSetKHR");
#endif // defined(VK_KHR_push_descriptor)
#if (defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline))
    vkCmdTraceRaysIndirect2KHR = (PFN_vkCmdTraceRaysIndirect2KHR) loadcb(context, "vkCmdTraceRaysIndirect2KHR");
#endif // (defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline))
#if defined(VK_KHR_ray_tracing_pipeline)
    vkCmdSetRayTracingPipelineStackSizeKHR = (PFN_vkCmdSetRayTracingPipelineStackSizeKHR) loadcb(context, "vkCmdSetRayTracingPipelineStackSizeKHR");
    vkCmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR) loadcb(context, "vkCmdTraceRaysIndirectKHR");
    vkCmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR) loadcb(context, "vkCmdTraceRaysKHR");
    vkCreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR) loadcb(context, "vkCreateRayTracingPipelinesKHR");
    vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR) loadcb(context, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR) loadcb(context, "vkGetRayTracingShaderGroupHandlesKHR");
    vkGetRayTracingShaderGroupStackSizeKHR = (PFN_vkGetRayTracingShaderGroupStackSizeKHR) loadcb(context, "vkGetRayTracingShaderGroupStackSizeKHR");
#endif // defined(VK_KHR_ray_tracing_pipeline)
#if defined(VK_KHR_sampler_ycbcr_conversion)
    vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR) loadcb(context, "vkCreateSamplerYcbcrConversionKHR");
    vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR) loadcb(context, "vkDestroySamplerYcbcrConversionKHR");
#endif // defined(VK_KHR_sampler_ycbcr_conversion)
#if defined(VK_KHR_shared_presentable_image)
    vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR) loadcb(context, "vkGetSwapchainStatusKHR");
#endif // defined(VK_KHR_shared_presentable_image)
#if defined(VK_KHR_swapchain)
    vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR) loadcb(context, "vkAcquireNextImageKHR");
    vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR) loadcb(context, "vkCreateSwapchainKHR");
    vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR) loadcb(context, "vkDestroySwapchainKHR");
    vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR) loadcb(context, "vkGetSwapchainImagesKHR");
    vkQueuePresentKHR = (PFN_vkQueuePresentKHR) loadcb(context, "vkQueuePresentKHR");
#endif // defined(VK_KHR_swapchain)
#if defined(VK_KHR_synchronization2)
    vkCmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR) loadcb(context, "vkCmdPipelineBarrier2KHR");
    vkCmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR) loadcb(context, "vkCmdResetEvent2KHR");
    vkCmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR) loadcb(context, "vkCmdSetEvent2KHR");
    vkCmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR) loadcb(context, "vkCmdWaitEvents2KHR");
    vkCmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR) loadcb(context, "vkCmdWriteTimestamp2KHR");
    vkQueueSubmit2KHR = (PFN_vkQueueSubmit2KHR) loadcb(context, "vkQueueSubmit2KHR");
#endif // defined(VK_KHR_synchronization2)
#if (defined(VK_KHR_synchronization2) && defined(VK_AMD_buffer_marker))
    vkCmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD) loadcb(context, "vkCmdWriteBufferMarker2AMD");
#endif // (defined(VK_KHR_synchronization2) && defined(VK_AMD_buffer_marker))
#if (defined(VK_KHR_synchronization2) && defined(VK_NV_device_diagnostic_checkpoints))
    vkGetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV) loadcb(context, "vkGetQueueCheckpointData2NV");
#endif // (defined(VK_KHR_synchronization2) && defined(VK_NV_device_diagnostic_checkpoints))
#if defined(VK_KHR_timeline_semaphore)
    vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR) loadcb(context, "vkGetSemaphoreCounterValueKHR");
    vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR) loadcb(context, "vkSignalSemaphoreKHR");
    vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR) loadcb(context, "vkWaitSemaphoresKHR");
#endif // defined(VK_KHR_timeline_semaphore)
#if defined(VK_KHR_video_decode_queue)
    vkCmdDecodeVideoKHR = (PFN_vkCmdDecodeVideoKHR) loadcb(context, "vkCmdDecodeVideoKHR");
#endif // defined(VK_KHR_video_decode_queue)
#if defined(VK_KHR_video_encode_queue)
    vkCmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR) loadcb(context, "vkCmdEncodeVideoKHR");
#endif // defined(VK_KHR_video_encode_queue)
#if defined(VK_KHR_video_queue)
    vkBindVideoSessionMemoryKHR = (PFN_vkBindVideoSessionMemoryKHR) loadcb(context, "vkBindVideoSessionMemoryKHR");
    vkCmdBeginVideoCodingKHR = (PFN_vkCmdBeginVideoCodingKHR) loadcb(context, "vkCmdBeginVideoCodingKHR");
    vkCmdControlVideoCodingKHR = (PFN_vkCmdControlVideoCodingKHR) loadcb(context, "vkCmdControlVideoCodingKHR");
    vkCmdEndVideoCodingKHR = (PFN_vkCmdEndVideoCodingKHR) loadcb(context, "vkCmdEndVideoCodingKHR");
    vkCreateVideoSessionKHR = (PFN_vkCreateVideoSessionKHR) loadcb(context, "vkCreateVideoSessionKHR");
    vkCreateVideoSessionParametersKHR = (PFN_vkCreateVideoSessionParametersKHR) loadcb(context, "vkCreateVideoSessionParametersKHR");
    vkDestroyVideoSessionKHR = (PFN_vkDestroyVideoSessionKHR) loadcb(context, "vkDestroyVideoSessionKHR");
    vkDestroyVideoSessionParametersKHR = (PFN_vkDestroyVideoSessionParametersKHR) loadcb(context, "vkDestroyVideoSessionParametersKHR");
    vkGetVideoSessionMemoryRequirementsKHR = (PFN_vkGetVideoSessionMemoryRequirementsKHR) loadcb(context, "vkGetVideoSessionMemoryRequirementsKHR");
    vkUpdateVideoSessionParametersKHR = (PFN_vkUpdateVideoSessionParametersKHR) loadcb(context, "vkUpdateVideoSessionParametersKHR");
#endif // defined(VK_KHR_video_queue)
#if defined(VK_NVX_binary_import)
    vkCmdCuLaunchKernelNVX = (PFN_vkCmdCuLaunchKernelNVX) loadcb(context, "vkCmdCuLaunchKernelNVX");
    vkCreateCuFunctionNVX = (PFN_vkCreateCuFunctionNVX) loadcb(context, "vkCreateCuFunctionNVX");
    vkCreateCuModuleNVX = (PFN_vkCreateCuModuleNVX) loadcb(context, "vkCreateCuModuleNVX");
    vkDestroyCuFunctionNVX = (PFN_vkDestroyCuFunctionNVX) loadcb(context, "vkDestroyCuFunctionNVX");
    vkDestroyCuModuleNVX = (PFN_vkDestroyCuModuleNVX) loadcb(context, "vkDestroyCuModuleNVX");
#endif // defined(VK_NVX_binary_import)
#if defined(VK_NVX_image_view_handle)
    vkGetImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX) loadcb(context, "vkGetImageViewAddressNVX");
    vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX) loadcb(context, "vkGetImageViewHandleNVX");
#endif // defined(VK_NVX_image_view_handle)
#if defined(VK_NV_clip_space_w_scaling)
    vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV) loadcb(context, "vkCmdSetViewportWScalingNV");
#endif // defined(VK_NV_clip_space_w_scaling)
#if defined(VK_NV_device_diagnostic_checkpoints)
    vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV) loadcb(context, "vkCmdSetCheckpointNV");
    vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV) loadcb(context, "vkGetQueueCheckpointDataNV");
#endif // defined(VK_NV_device_diagnostic_checkpoints)
#if defined(VK_NV_device_generated_commands)
    vkCmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV) loadcb(context, "vkCmdBindPipelineShaderGroupNV");
    vkCmdExecuteGeneratedCommandsNV = (PFN_vkCmdExecuteGeneratedCommandsNV) loadcb(context, "vkCmdExecuteGeneratedCommandsNV");
    vkCmdPreprocessGeneratedCommandsNV = (PFN_vkCmdPreprocessGeneratedCommandsNV) loadcb(context, "vkCmdPreprocessGeneratedCommandsNV");
    vkCreateIndirectCommandsLayoutNV = (PFN_vkCreateIndirectCommandsLayoutNV) loadcb(context, "vkCreateIndirectCommandsLayoutNV");
    vkDestroyIndirectCommandsLayoutNV = (PFN_vkDestroyIndirectCommandsLayoutNV) loadcb(context, "vkDestroyIndirectCommandsLayoutNV");
    vkGetGeneratedCommandsMemoryRequirementsNV = (PFN_vkGetGeneratedCommandsMemoryRequirementsNV) loadcb(context, "vkGetGeneratedCommandsMemoryRequirementsNV");
#endif // defined(VK_NV_device_generated_commands)
#if defined(VK_NV_external_memory_rdma)
    vkGetMemoryRemoteAddressNV = (PFN_vkGetMemoryRemoteAddressNV) loadcb(context, "vkGetMemoryRemoteAddressNV");
#endif // defined(VK_NV_external_memory_rdma)
#if defined(VK_NV_external_memory_win32)
    vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV) loadcb(context, "vkGetMemoryWin32HandleNV");
#endif // defined(VK_NV_external_memory_win32)
#if defined(VK_NV_fragment_shading_rate_enums)
    vkCmdSetFragmentShadingRateEnumNV = (PFN_vkCmdSetFragmentShadingRateEnumNV) loadcb(context, "vkCmdSetFragmentShadingRateEnumNV");
#endif // defined(VK_NV_fragment_shading_rate_enums)
#if defined(VK_NV_mesh_shader)
    vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV) loadcb(context, "vkCmdDrawMeshTasksIndirectCountNV");
    vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV) loadcb(context, "vkCmdDrawMeshTasksIndirectNV");
    vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV) loadcb(context, "vkCmdDrawMeshTasksNV");
#endif // defined(VK_NV_mesh_shader)
#if defined(VK_NV_ray_tracing)
    vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV) loadcb(context, "vkBindAccelerationStructureMemoryNV");
    vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV) loadcb(context, "vkCmdBuildAccelerationStructureNV");
    vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV) loadcb(context, "vkCmdCopyAccelerationStructureNV");
    vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV) loadcb(context, "vkCmdTraceRaysNV");
    vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV) loadcb(context, "vkCmdWriteAccelerationStructuresPropertiesNV");
    vkCompileDeferredNV = (PFN_vkCompileDeferredNV) loadcb(context, "vkCompileDeferredNV");
    vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV) loadcb(context, "vkCreateAccelerationStructureNV");
    vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV) loadcb(context, "vkCreateRayTracingPipelinesNV");
    vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV) loadcb(context, "vkDestroyAccelerationStructureNV");
    vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV) loadcb(context, "vkGetAccelerationStructureHandleNV");
    vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV) loadcb(context, "vkGetAccelerationStructureMemoryRequirementsNV");
    vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV) loadcb(context, "vkGetRayTracingShaderGroupHandlesNV");
#endif // defined(VK_NV_ray_tracing)
#if defined(VK_NV_scissor_exclusive)
    vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV) loadcb(context, "vkCmdSetExclusiveScissorNV");
#endif // defined(VK_NV_scissor_exclusive)
#if defined(VK_NV_shading_rate_image)
    vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV) loadcb(context, "vkCmdBindShadingRateImageNV");
    vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV) loadcb(context, "vkCmdSetCoarseSampleOrderNV");
    vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV) loadcb(context, "vkCmdSetViewportShadingRatePaletteNV");
#endif // defined(VK_NV_shading_rate_image)
#if defined(VK_VALVE_descriptor_set_host_mapping)
    vkGetDescriptorSetHostMappingVALVE = (PFN_vkGetDescriptorSetHostMappingVALVE) loadcb(context, "vkGetDescriptorSetHostMappingVALVE");
    vkGetDescriptorSetLayoutHostMappingInfoVALVE = (PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE) loadcb(context, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
#endif // defined(VK_VALVE_descriptor_set_host_mapping)
#if (defined(VK_EXT_full_screen_exclusive) && defined(VK_KHR_device_group)) || (defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1))
    vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT) loadcb(context, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif // (defined(VK_EXT_full_screen_exclusive) && defined(VK_KHR_device_group)) || (defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1))
#if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_push_descriptor) && defined(VK_KHR_descriptor_update_template))
    vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR) loadcb(context, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif // (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_push_descriptor) && defined(VK_KHR_descriptor_update_template))
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
    vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) loadcb(context, "vkGetDeviceGroupPresentCapabilitiesKHR");
    vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) loadcb(context, "vkGetDeviceGroupSurfacePresentModesKHR");
#endif // (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
#if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
    vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR) loadcb(context, "vkAcquireNextImage2KHR");
#endif // (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
}

#if defined(VK_VERSION_1_0)
PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
PFN_vkAllocateMemory vkAllocateMemory;
PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
PFN_vkBindBufferMemory vkBindBufferMemory;
PFN_vkBindImageMemory vkBindImageMemory;
PFN_vkCmdBeginQuery vkCmdBeginQuery;
PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
PFN_vkCmdBindPipeline vkCmdBindPipeline;
PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
PFN_vkCmdBlitImage vkCmdBlitImage;
PFN_vkCmdClearAttachments vkCmdClearAttachments;
PFN_vkCmdClearColorImage vkCmdClearColorImage;
PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
PFN_vkCmdCopyImage vkCmdCopyImage;
PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;
PFN_vkCmdDispatch vkCmdDispatch;
PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect;
PFN_vkCmdDraw vkCmdDraw;
PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
PFN_vkCmdEndQuery vkCmdEndQuery;
PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
PFN_vkCmdExecuteCommands vkCmdExecuteCommands;
PFN_vkCmdFillBuffer vkCmdFillBuffer;
PFN_vkCmdNextSubpass vkCmdNextSubpass;
PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
PFN_vkCmdPushConstants vkCmdPushConstants;
PFN_vkCmdResetEvent vkCmdResetEvent;
PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
PFN_vkCmdResolveImage vkCmdResolveImage;
PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds;
PFN_vkCmdSetEvent vkCmdSetEvent;
PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
PFN_vkCmdSetScissor vkCmdSetScissor;
PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask;
PFN_vkCmdSetStencilReference vkCmdSetStencilReference;
PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask;
PFN_vkCmdSetViewport vkCmdSetViewport;
PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer;
PFN_vkCmdWaitEvents vkCmdWaitEvents;
PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
PFN_vkCreateBuffer vkCreateBuffer;
PFN_vkCreateBufferView vkCreateBufferView;
PFN_vkCreateCommandPool vkCreateCommandPool;
PFN_vkCreateComputePipelines vkCreateComputePipelines;
PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
PFN_vkCreateDevice vkCreateDevice;
PFN_vkCreateEvent vkCreateEvent;
PFN_vkCreateFence vkCreateFence;
PFN_vkCreateFramebuffer vkCreateFramebuffer;
PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
PFN_vkCreateImage vkCreateImage;
PFN_vkCreateImageView vkCreateImageView;
PFN_vkCreateInstance vkCreateInstance;
PFN_vkCreatePipelineCache vkCreatePipelineCache;
PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
PFN_vkCreateQueryPool vkCreateQueryPool;
PFN_vkCreateRenderPass vkCreateRenderPass;
PFN_vkCreateSampler vkCreateSampler;
PFN_vkCreateSemaphore vkCreateSemaphore;
PFN_vkCreateShaderModule vkCreateShaderModule;
PFN_vkDestroyBuffer vkDestroyBuffer;
PFN_vkDestroyBufferView vkDestroyBufferView;
PFN_vkDestroyCommandPool vkDestroyCommandPool;
PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
PFN_vkDestroyDevice vkDestroyDevice;
PFN_vkDestroyEvent vkDestroyEvent;
PFN_vkDestroyFence vkDestroyFence;
PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
PFN_vkDestroyImage vkDestroyImage;
PFN_vkDestroyImageView vkDestroyImageView;
PFN_vkDestroyInstance vkDestroyInstance;
PFN_vkDestroyPipeline vkDestroyPipeline;
PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
PFN_vkDestroyQueryPool vkDestroyQueryPool;
PFN_vkDestroyRenderPass vkDestroyRenderPass;
PFN_vkDestroySampler vkDestroySampler;
PFN_vkDestroySemaphore vkDestroySemaphore;
PFN_vkDestroyShaderModule vkDestroyShaderModule;
PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
PFN_vkEndCommandBuffer vkEndCommandBuffer;
PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
PFN_vkFreeMemory vkFreeMemory;
PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment;
PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
PFN_vkGetDeviceQueue vkGetDeviceQueue;
PFN_vkGetEventStatus vkGetEventStatus;
PFN_vkGetFenceStatus vkGetFenceStatus;
PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements;
PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity;
PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
PFN_vkMapMemory vkMapMemory;
PFN_vkMergePipelineCaches vkMergePipelineCaches;
PFN_vkQueueBindSparse vkQueueBindSparse;
PFN_vkQueueSubmit vkQueueSubmit;
PFN_vkQueueWaitIdle vkQueueWaitIdle;
PFN_vkResetCommandBuffer vkResetCommandBuffer;
PFN_vkResetCommandPool vkResetCommandPool;
PFN_vkResetDescriptorPool vkResetDescriptorPool;
PFN_vkResetEvent vkResetEvent;
PFN_vkResetFences vkResetFences;
PFN_vkSetEvent vkSetEvent;
PFN_vkUnmapMemory vkUnmapMemory;
PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
PFN_vkWaitForFences vkWaitForFences;
#endif // defined(VK_VERSION_1_0)
#if defined(VK_VERSION_1_1)
PFN_vkBindBufferMemory2 vkBindBufferMemory2;
PFN_vkBindImageMemory2 vkBindImageMemory2;
PFN_vkCmdDispatchBase vkCmdDispatchBase;
PFN_vkCmdSetDeviceMask vkCmdSetDeviceMask;
PFN_vkCreateDescriptorUpdateTemplate vkCreateDescriptorUpdateTemplate;
PFN_vkCreateSamplerYcbcrConversion vkCreateSamplerYcbcrConversion;
PFN_vkDestroyDescriptorUpdateTemplate vkDestroyDescriptorUpdateTemplate;
PFN_vkDestroySamplerYcbcrConversion vkDestroySamplerYcbcrConversion;
PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
PFN_vkEnumeratePhysicalDeviceGroups vkEnumeratePhysicalDeviceGroups;
PFN_vkGetBufferMemoryRequirements2 vkGetBufferMemoryRequirements2;
PFN_vkGetDescriptorSetLayoutSupport vkGetDescriptorSetLayoutSupport;
PFN_vkGetDeviceGroupPeerMemoryFeatures vkGetDeviceGroupPeerMemoryFeatures;
PFN_vkGetDeviceQueue2 vkGetDeviceQueue2;
PFN_vkGetImageMemoryRequirements2 vkGetImageMemoryRequirements2;
PFN_vkGetImageSparseMemoryRequirements2 vkGetImageSparseMemoryRequirements2;
PFN_vkGetPhysicalDeviceExternalBufferProperties vkGetPhysicalDeviceExternalBufferProperties;
PFN_vkGetPhysicalDeviceExternalFenceProperties vkGetPhysicalDeviceExternalFenceProperties;
PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vkGetPhysicalDeviceExternalSemaphoreProperties;
PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
PFN_vkGetPhysicalDeviceImageFormatProperties2 vkGetPhysicalDeviceImageFormatProperties2;
PFN_vkGetPhysicalDeviceMemoryProperties2 vkGetPhysicalDeviceMemoryProperties2;
PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
PFN_vkTrimCommandPool vkTrimCommandPool;
PFN_vkUpdateDescriptorSetWithTemplate vkUpdateDescriptorSetWithTemplate;
#endif // defined(VK_VERSION_1_1)
#if defined(VK_VERSION_1_2)
PFN_vkCmdBeginRenderPass2 vkCmdBeginRenderPass2;
PFN_vkCmdDrawIndexedIndirectCount vkCmdDrawIndexedIndirectCount;
PFN_vkCmdDrawIndirectCount vkCmdDrawIndirectCount;
PFN_vkCmdEndRenderPass2 vkCmdEndRenderPass2;
PFN_vkCmdNextSubpass2 vkCmdNextSubpass2;
PFN_vkCreateRenderPass2 vkCreateRenderPass2;
PFN_vkGetBufferDeviceAddress vkGetBufferDeviceAddress;
PFN_vkGetBufferOpaqueCaptureAddress vkGetBufferOpaqueCaptureAddress;
PFN_vkGetDeviceMemoryOpaqueCaptureAddress vkGetDeviceMemoryOpaqueCaptureAddress;
PFN_vkGetSemaphoreCounterValue vkGetSemaphoreCounterValue;
PFN_vkResetQueryPool vkResetQueryPool;
PFN_vkSignalSemaphore vkSignalSemaphore;
PFN_vkWaitSemaphores vkWaitSemaphores;
#endif // defined(VK_VERSION_1_2)
#if defined(VK_VERSION_1_3)
PFN_vkCmdBeginRendering vkCmdBeginRendering;
PFN_vkCmdBindVertexBuffers2 vkCmdBindVertexBuffers2;
PFN_vkCmdBlitImage2 vkCmdBlitImage2;
PFN_vkCmdCopyBuffer2 vkCmdCopyBuffer2;
PFN_vkCmdCopyBufferToImage2 vkCmdCopyBufferToImage2;
PFN_vkCmdCopyImage2 vkCmdCopyImage2;
PFN_vkCmdCopyImageToBuffer2 vkCmdCopyImageToBuffer2;
PFN_vkCmdEndRendering vkCmdEndRendering;
PFN_vkCmdPipelineBarrier2 vkCmdPipelineBarrier2;
PFN_vkCmdResetEvent2 vkCmdResetEvent2;
PFN_vkCmdResolveImage2 vkCmdResolveImage2;
PFN_vkCmdSetCullMode vkCmdSetCullMode;
PFN_vkCmdSetDepthBiasEnable vkCmdSetDepthBiasEnable;
PFN_vkCmdSetDepthBoundsTestEnable vkCmdSetDepthBoundsTestEnable;
PFN_vkCmdSetDepthCompareOp vkCmdSetDepthCompareOp;
PFN_vkCmdSetDepthTestEnable vkCmdSetDepthTestEnable;
PFN_vkCmdSetDepthWriteEnable vkCmdSetDepthWriteEnable;
PFN_vkCmdSetEvent2 vkCmdSetEvent2;
PFN_vkCmdSetFrontFace vkCmdSetFrontFace;
PFN_vkCmdSetPrimitiveRestartEnable vkCmdSetPrimitiveRestartEnable;
PFN_vkCmdSetPrimitiveTopology vkCmdSetPrimitiveTopology;
PFN_vkCmdSetRasterizerDiscardEnable vkCmdSetRasterizerDiscardEnable;
PFN_vkCmdSetScissorWithCount vkCmdSetScissorWithCount;
PFN_vkCmdSetStencilOp vkCmdSetStencilOp;
PFN_vkCmdSetStencilTestEnable vkCmdSetStencilTestEnable;
PFN_vkCmdSetViewportWithCount vkCmdSetViewportWithCount;
PFN_vkCmdWaitEvents2 vkCmdWaitEvents2;
PFN_vkCmdWriteTimestamp2 vkCmdWriteTimestamp2;
PFN_vkCreatePrivateDataSlot vkCreatePrivateDataSlot;
PFN_vkDestroyPrivateDataSlot vkDestroyPrivateDataSlot;
PFN_vkGetDeviceBufferMemoryRequirements vkGetDeviceBufferMemoryRequirements;
PFN_vkGetDeviceImageMemoryRequirements vkGetDeviceImageMemoryRequirements;
PFN_vkGetDeviceImageSparseMemoryRequirements vkGetDeviceImageSparseMemoryRequirements;
PFN_vkGetPhysicalDeviceToolProperties vkGetPhysicalDeviceToolProperties;
PFN_vkGetPrivateData vkGetPrivateData;
PFN_vkQueueSubmit2 vkQueueSubmit2;
PFN_vkSetPrivateData vkSetPrivateData;
#endif // defined(VK_VERSION_1_3)
#if defined(VK_AMD_buffer_marker)
PFN_vkCmdWriteBufferMarkerAMD vkCmdWriteBufferMarkerAMD;
#endif // defined(VK_AMD_buffer_marker)
#if defined(VK_AMD_display_native_hdr)
PFN_vkSetLocalDimmingAMD vkSetLocalDimmingAMD;
#endif // defined(VK_AMD_display_native_hdr)
#if defined(VK_AMD_draw_indirect_count)
PFN_vkCmdDrawIndexedIndirectCountAMD vkCmdDrawIndexedIndirectCountAMD;
PFN_vkCmdDrawIndirectCountAMD vkCmdDrawIndirectCountAMD;
#endif // defined(VK_AMD_draw_indirect_count)
#if defined(VK_AMD_shader_info)
PFN_vkGetShaderInfoAMD vkGetShaderInfoAMD;
#endif // defined(VK_AMD_shader_info)
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
PFN_vkGetAndroidHardwareBufferPropertiesANDROID vkGetAndroidHardwareBufferPropertiesANDROID;
PFN_vkGetMemoryAndroidHardwareBufferANDROID vkGetMemoryAndroidHardwareBufferANDROID;
#endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)
#if defined(VK_ANDROID_native_buffer)
PFN_vkAcquireImageANDROID vkAcquireImageANDROID;
PFN_vkGetSwapchainGrallocUsage2ANDROID vkGetSwapchainGrallocUsage2ANDROID;
PFN_vkGetSwapchainGrallocUsageANDROID vkGetSwapchainGrallocUsageANDROID;
PFN_vkQueueSignalReleaseImageANDROID vkQueueSignalReleaseImageANDROID;
#endif // defined(VK_ANDROID_native_buffer)
#if defined(VK_EXT_acquire_drm_display)
PFN_vkAcquireDrmDisplayEXT vkAcquireDrmDisplayEXT;
PFN_vkGetDrmDisplayEXT vkGetDrmDisplayEXT;
#endif // defined(VK_EXT_acquire_drm_display)
#if defined(VK_EXT_acquire_xlib_display)
PFN_vkAcquireXlibDisplayEXT vkAcquireXlibDisplayEXT;
PFN_vkGetRandROutputDisplayEXT vkGetRandROutputDisplayEXT;
#endif // defined(VK_EXT_acquire_xlib_display)
#if defined(VK_EXT_buffer_device_address)
PFN_vkGetBufferDeviceAddressEXT vkGetBufferDeviceAddressEXT;
#endif // defined(VK_EXT_buffer_device_address)
#if defined(VK_EXT_calibrated_timestamps)
PFN_vkGetCalibratedTimestampsEXT vkGetCalibratedTimestampsEXT;
PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
#endif // defined(VK_EXT_calibrated_timestamps)
#if defined(VK_EXT_color_write_enable)
PFN_vkCmdSetColorWriteEnableEXT vkCmdSetColorWriteEnableEXT;
#endif // defined(VK_EXT_color_write_enable)
#if defined(VK_EXT_conditional_rendering)
PFN_vkCmdBeginConditionalRenderingEXT vkCmdBeginConditionalRenderingEXT;
PFN_vkCmdEndConditionalRenderingEXT vkCmdEndConditionalRenderingEXT;
#endif // defined(VK_EXT_conditional_rendering)
#if defined(VK_EXT_debug_marker)
PFN_vkCmdDebugMarkerBeginEXT vkCmdDebugMarkerBeginEXT;
PFN_vkCmdDebugMarkerEndEXT vkCmdDebugMarkerEndEXT;
PFN_vkCmdDebugMarkerInsertEXT vkCmdDebugMarkerInsertEXT;
PFN_vkDebugMarkerSetObjectNameEXT vkDebugMarkerSetObjectNameEXT;
PFN_vkDebugMarkerSetObjectTagEXT vkDebugMarkerSetObjectTagEXT;
#endif // defined(VK_EXT_debug_marker)
#if defined(VK_EXT_debug_report)
PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;
PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
#endif // defined(VK_EXT_debug_report)
#if defined(VK_EXT_debug_utils)
PFN_vkCmdBeginDebugUtilsLabelEXT vkCmdBeginDebugUtilsLabelEXT;
PFN_vkCmdEndDebugUtilsLabelEXT vkCmdEndDebugUtilsLabelEXT;
PFN_vkCmdInsertDebugUtilsLabelEXT vkCmdInsertDebugUtilsLabelEXT;
PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
PFN_vkQueueBeginDebugUtilsLabelEXT vkQueueBeginDebugUtilsLabelEXT;
PFN_vkQueueEndDebugUtilsLabelEXT vkQueueEndDebugUtilsLabelEXT;
PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabelEXT;
PFN_vkSetDebugUtilsObjectNameEXT vkSetDebugUtilsObjectNameEXT;
PFN_vkSetDebugUtilsObjectTagEXT vkSetDebugUtilsObjectTagEXT;
PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessageEXT;
#endif // defined(VK_EXT_debug_utils)
#if defined(VK_EXT_direct_mode_display)
PFN_vkReleaseDisplayEXT vkReleaseDisplayEXT;
#endif // defined(VK_EXT_direct_mode_display)
#if defined(VK_EXT_directfb_surface)
PFN_vkCreateDirectFBSurfaceEXT vkCreateDirectFBSurfaceEXT;
PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT vkGetPhysicalDeviceDirectFBPresentationSupportEXT;
#endif // defined(VK_EXT_directfb_surface)
#if defined(VK_EXT_discard_rectangles)
PFN_vkCmdSetDiscardRectangleEXT vkCmdSetDiscardRectangleEXT;
#endif // defined(VK_EXT_discard_rectangles)
#if defined(VK_EXT_display_control)
PFN_vkDisplayPowerControlEXT vkDisplayPowerControlEXT;
PFN_vkGetSwapchainCounterEXT vkGetSwapchainCounterEXT;
PFN_vkRegisterDeviceEventEXT vkRegisterDeviceEventEXT;
PFN_vkRegisterDisplayEventEXT vkRegisterDisplayEventEXT;
#endif // defined(VK_EXT_display_control)
#if defined(VK_EXT_display_surface_counter)
PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vkGetPhysicalDeviceSurfaceCapabilities2EXT;
#endif // defined(VK_EXT_display_surface_counter)
#if defined(VK_EXT_extended_dynamic_state)
PFN_vkCmdBindVertexBuffers2EXT vkCmdBindVertexBuffers2EXT;
PFN_vkCmdSetCullModeEXT vkCmdSetCullModeEXT;
PFN_vkCmdSetDepthBoundsTestEnableEXT vkCmdSetDepthBoundsTestEnableEXT;
PFN_vkCmdSetDepthCompareOpEXT vkCmdSetDepthCompareOpEXT;
PFN_vkCmdSetDepthTestEnableEXT vkCmdSetDepthTestEnableEXT;
PFN_vkCmdSetDepthWriteEnableEXT vkCmdSetDepthWriteEnableEXT;
PFN_vkCmdSetFrontFaceEXT vkCmdSetFrontFaceEXT;
PFN_vkCmdSetPrimitiveTopologyEXT vkCmdSetPrimitiveTopologyEXT;
PFN_vkCmdSetScissorWithCountEXT vkCmdSetScissorWithCountEXT;
PFN_vkCmdSetStencilOpEXT vkCmdSetStencilOpEXT;
PFN_vkCmdSetStencilTestEnableEXT vkCmdSetStencilTestEnableEXT;
PFN_vkCmdSetViewportWithCountEXT vkCmdSetViewportWithCountEXT;
#endif // defined(VK_EXT_extended_dynamic_state)
#if defined(VK_EXT_extended_dynamic_state2)
PFN_vkCmdSetDepthBiasEnableEXT vkCmdSetDepthBiasEnableEXT;
PFN_vkCmdSetLogicOpEXT vkCmdSetLogicOpEXT;
PFN_vkCmdSetPatchControlPointsEXT vkCmdSetPatchControlPointsEXT;
PFN_vkCmdSetPrimitiveRestartEnableEXT vkCmdSetPrimitiveRestartEnableEXT;
PFN_vkCmdSetRasterizerDiscardEnableEXT vkCmdSetRasterizerDiscardEnableEXT;
#endif // defined(VK_EXT_extended_dynamic_state2)
#if defined(VK_EXT_external_memory_host)
PFN_vkGetMemoryHostPointerPropertiesEXT vkGetMemoryHostPointerPropertiesEXT;
#endif // defined(VK_EXT_external_memory_host)
#if defined(VK_EXT_full_screen_exclusive)
PFN_vkAcquireFullScreenExclusiveModeEXT vkAcquireFullScreenExclusiveModeEXT;
PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT vkGetPhysicalDeviceSurfacePresentModes2EXT;
PFN_vkReleaseFullScreenExclusiveModeEXT vkReleaseFullScreenExclusiveModeEXT;
#endif // defined(VK_EXT_full_screen_exclusive)
#if defined(VK_EXT_hdr_metadata)
PFN_vkSetHdrMetadataEXT vkSetHdrMetadataEXT;
#endif // defined(VK_EXT_hdr_metadata)
#if defined(VK_EXT_headless_surface)
PFN_vkCreateHeadlessSurfaceEXT vkCreateHeadlessSurfaceEXT;
#endif // defined(VK_EXT_headless_surface)
#if defined(VK_EXT_host_query_reset)
PFN_vkResetQueryPoolEXT vkResetQueryPoolEXT;
#endif // defined(VK_EXT_host_query_reset)
#if defined(VK_EXT_image_compression_control)
PFN_vkGetImageSubresourceLayout2EXT vkGetImageSubresourceLayout2EXT;
#endif // defined(VK_EXT_image_compression_control)
#if defined(VK_EXT_image_drm_format_modifier)
PFN_vkGetImageDrmFormatModifierPropertiesEXT vkGetImageDrmFormatModifierPropertiesEXT;
#endif // defined(VK_EXT_image_drm_format_modifier)
#if defined(VK_EXT_line_rasterization)
PFN_vkCmdSetLineStippleEXT vkCmdSetLineStippleEXT;
#endif // defined(VK_EXT_line_rasterization)
#if defined(VK_EXT_metal_objects)
PFN_vkExportMetalObjectsEXT vkExportMetalObjectsEXT;
#endif // defined(VK_EXT_metal_objects)
#if defined(VK_EXT_metal_surface)
PFN_vkCreateMetalSurfaceEXT vkCreateMetalSurfaceEXT;
#endif // defined(VK_EXT_metal_surface)
#if defined(VK_EXT_multi_draw)
PFN_vkCmdDrawMultiEXT vkCmdDrawMultiEXT;
PFN_vkCmdDrawMultiIndexedEXT vkCmdDrawMultiIndexedEXT;
#endif // defined(VK_EXT_multi_draw)
#if defined(VK_EXT_pageable_device_local_memory)
PFN_vkSetDeviceMemoryPriorityEXT vkSetDeviceMemoryPriorityEXT;
#endif // defined(VK_EXT_pageable_device_local_memory)
#if defined(VK_EXT_pipeline_properties)
PFN_vkGetPipelinePropertiesEXT vkGetPipelinePropertiesEXT;
#endif // defined(VK_EXT_pipeline_properties)
#if defined(VK_EXT_private_data)
PFN_vkCreatePrivateDataSlotEXT vkCreatePrivateDataSlotEXT;
PFN_vkDestroyPrivateDataSlotEXT vkDestroyPrivateDataSlotEXT;
PFN_vkGetPrivateDataEXT vkGetPrivateDataEXT;
PFN_vkSetPrivateDataEXT vkSetPrivateDataEXT;
#endif // defined(VK_EXT_private_data)
#if defined(VK_EXT_sample_locations)
PFN_vkCmdSetSampleLocationsEXT vkCmdSetSampleLocationsEXT;
PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT vkGetPhysicalDeviceMultisamplePropertiesEXT;
#endif // defined(VK_EXT_sample_locations)
#if defined(VK_EXT_tooling_info)
PFN_vkGetPhysicalDeviceToolPropertiesEXT vkGetPhysicalDeviceToolPropertiesEXT;
#endif // defined(VK_EXT_tooling_info)
#if defined(VK_EXT_transform_feedback)
PFN_vkCmdBeginQueryIndexedEXT vkCmdBeginQueryIndexedEXT;
PFN_vkCmdBeginTransformFeedbackEXT vkCmdBeginTransformFeedbackEXT;
PFN_vkCmdBindTransformFeedbackBuffersEXT vkCmdBindTransformFeedbackBuffersEXT;
PFN_vkCmdDrawIndirectByteCountEXT vkCmdDrawIndirectByteCountEXT;
PFN_vkCmdEndQueryIndexedEXT vkCmdEndQueryIndexedEXT;
PFN_vkCmdEndTransformFeedbackEXT vkCmdEndTransformFeedbackEXT;
#endif // defined(VK_EXT_transform_feedback)
#if defined(VK_EXT_validation_cache)
PFN_vkCreateValidationCacheEXT vkCreateValidationCacheEXT;
PFN_vkDestroyValidationCacheEXT vkDestroyValidationCacheEXT;
PFN_vkGetValidationCacheDataEXT vkGetValidationCacheDataEXT;
PFN_vkMergeValidationCachesEXT vkMergeValidationCachesEXT;
#endif // defined(VK_EXT_validation_cache)
#if defined(VK_EXT_vertex_input_dynamic_state)
PFN_vkCmdSetVertexInputEXT vkCmdSetVertexInputEXT;
#endif // defined(VK_EXT_vertex_input_dynamic_state)
#if defined(VK_FUCHSIA_buffer_collection)
PFN_vkCreateBufferCollectionFUCHSIA vkCreateBufferCollectionFUCHSIA;
PFN_vkDestroyBufferCollectionFUCHSIA vkDestroyBufferCollectionFUCHSIA;
PFN_vkGetBufferCollectionPropertiesFUCHSIA vkGetBufferCollectionPropertiesFUCHSIA;
PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA vkSetBufferCollectionBufferConstraintsFUCHSIA;
PFN_vkSetBufferCollectionImageConstraintsFUCHSIA vkSetBufferCollectionImageConstraintsFUCHSIA;
#endif // defined(VK_FUCHSIA_buffer_collection)
#if defined(VK_FUCHSIA_external_memory)
PFN_vkGetMemoryZirconHandleFUCHSIA vkGetMemoryZirconHandleFUCHSIA;
PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA vkGetMemoryZirconHandlePropertiesFUCHSIA;
#endif // defined(VK_FUCHSIA_external_memory)
#if defined(VK_FUCHSIA_external_semaphore)
PFN_vkGetSemaphoreZirconHandleFUCHSIA vkGetSemaphoreZirconHandleFUCHSIA;
PFN_vkImportSemaphoreZirconHandleFUCHSIA vkImportSemaphoreZirconHandleFUCHSIA;
#endif // defined(VK_FUCHSIA_external_semaphore)
#if defined(VK_FUCHSIA_imagepipe_surface)
PFN_vkCreateImagePipeSurfaceFUCHSIA vkCreateImagePipeSurfaceFUCHSIA;
#endif // defined(VK_FUCHSIA_imagepipe_surface)
#if defined(VK_GGP_stream_descriptor_surface)
PFN_vkCreateStreamDescriptorSurfaceGGP vkCreateStreamDescriptorSurfaceGGP;
#endif // defined(VK_GGP_stream_descriptor_surface)
#if defined(VK_GOOGLE_display_timing)
PFN_vkGetPastPresentationTimingGOOGLE vkGetPastPresentationTimingGOOGLE;
PFN_vkGetRefreshCycleDurationGOOGLE vkGetRefreshCycleDurationGOOGLE;
#endif // defined(VK_GOOGLE_display_timing)
#if defined(VK_HUAWEI_invocation_mask)
PFN_vkCmdBindInvocationMaskHUAWEI vkCmdBindInvocationMaskHUAWEI;
#endif // defined(VK_HUAWEI_invocation_mask)
#if defined(VK_HUAWEI_subpass_shading)
PFN_vkCmdSubpassShadingHUAWEI vkCmdSubpassShadingHUAWEI;
PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI;
#endif // defined(VK_HUAWEI_subpass_shading)
#if defined(VK_INTEL_performance_query)
PFN_vkAcquirePerformanceConfigurationINTEL vkAcquirePerformanceConfigurationINTEL;
PFN_vkCmdSetPerformanceMarkerINTEL vkCmdSetPerformanceMarkerINTEL;
PFN_vkCmdSetPerformanceOverrideINTEL vkCmdSetPerformanceOverrideINTEL;
PFN_vkCmdSetPerformanceStreamMarkerINTEL vkCmdSetPerformanceStreamMarkerINTEL;
PFN_vkGetPerformanceParameterINTEL vkGetPerformanceParameterINTEL;
PFN_vkInitializePerformanceApiINTEL vkInitializePerformanceApiINTEL;
PFN_vkQueueSetPerformanceConfigurationINTEL vkQueueSetPerformanceConfigurationINTEL;
PFN_vkReleasePerformanceConfigurationINTEL vkReleasePerformanceConfigurationINTEL;
PFN_vkUninitializePerformanceApiINTEL vkUninitializePerformanceApiINTEL;
#endif // defined(VK_INTEL_performance_query)
#if defined(VK_KHR_acceleration_structure)
PFN_vkBuildAccelerationStructuresKHR vkBuildAccelerationStructuresKHR;
PFN_vkCmdBuildAccelerationStructuresIndirectKHR vkCmdBuildAccelerationStructuresIndirectKHR;
PFN_vkCmdBuildAccelerationStructuresKHR vkCmdBuildAccelerationStructuresKHR;
PFN_vkCmdCopyAccelerationStructureKHR vkCmdCopyAccelerationStructureKHR;
PFN_vkCmdCopyAccelerationStructureToMemoryKHR vkCmdCopyAccelerationStructureToMemoryKHR;
PFN_vkCmdCopyMemoryToAccelerationStructureKHR vkCmdCopyMemoryToAccelerationStructureKHR;
PFN_vkCmdWriteAccelerationStructuresPropertiesKHR vkCmdWriteAccelerationStructuresPropertiesKHR;
PFN_vkCopyAccelerationStructureKHR vkCopyAccelerationStructureKHR;
PFN_vkCopyAccelerationStructureToMemoryKHR vkCopyAccelerationStructureToMemoryKHR;
PFN_vkCopyMemoryToAccelerationStructureKHR vkCopyMemoryToAccelerationStructureKHR;
PFN_vkCreateAccelerationStructureKHR vkCreateAccelerationStructureKHR;
PFN_vkDestroyAccelerationStructureKHR vkDestroyAccelerationStructureKHR;
PFN_vkGetAccelerationStructureBuildSizesKHR vkGetAccelerationStructureBuildSizesKHR;
PFN_vkGetAccelerationStructureDeviceAddressKHR vkGetAccelerationStructureDeviceAddressKHR;
PFN_vkGetDeviceAccelerationStructureCompatibilityKHR vkGetDeviceAccelerationStructureCompatibilityKHR;
PFN_vkWriteAccelerationStructuresPropertiesKHR vkWriteAccelerationStructuresPropertiesKHR;
#endif // defined(VK_KHR_acceleration_structure)
#if defined(VK_KHR_android_surface)
PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;
#endif // defined(VK_KHR_android_surface)
#if defined(VK_KHR_bind_memory2)
PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR;
PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR;
#endif // defined(VK_KHR_bind_memory2)
#if defined(VK_KHR_buffer_device_address)
PFN_vkGetBufferDeviceAddressKHR vkGetBufferDeviceAddressKHR;
PFN_vkGetBufferOpaqueCaptureAddressKHR vkGetBufferOpaqueCaptureAddressKHR;
PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR vkGetDeviceMemoryOpaqueCaptureAddressKHR;
#endif // defined(VK_KHR_buffer_device_address)
#if defined(VK_KHR_copy_commands2)
PFN_vkCmdBlitImage2KHR vkCmdBlitImage2KHR;
PFN_vkCmdCopyBuffer2KHR vkCmdCopyBuffer2KHR;
PFN_vkCmdCopyBufferToImage2KHR vkCmdCopyBufferToImage2KHR;
PFN_vkCmdCopyImage2KHR vkCmdCopyImage2KHR;
PFN_vkCmdCopyImageToBuffer2KHR vkCmdCopyImageToBuffer2KHR;
PFN_vkCmdResolveImage2KHR vkCmdResolveImage2KHR;
#endif // defined(VK_KHR_copy_commands2)
#if defined(VK_KHR_create_renderpass2)
PFN_vkCmdBeginRenderPass2KHR vkCmdBeginRenderPass2KHR;
PFN_vkCmdEndRenderPass2KHR vkCmdEndRenderPass2KHR;
PFN_vkCmdNextSubpass2KHR vkCmdNextSubpass2KHR;
PFN_vkCreateRenderPass2KHR vkCreateRenderPass2KHR;
#endif // defined(VK_KHR_create_renderpass2)
#if defined(VK_KHR_deferred_host_operations)
PFN_vkCreateDeferredOperationKHR vkCreateDeferredOperationKHR;
PFN_vkDeferredOperationJoinKHR vkDeferredOperationJoinKHR;
PFN_vkDestroyDeferredOperationKHR vkDestroyDeferredOperationKHR;
PFN_vkGetDeferredOperationMaxConcurrencyKHR vkGetDeferredOperationMaxConcurrencyKHR;
PFN_vkGetDeferredOperationResultKHR vkGetDeferredOperationResultKHR;
#endif // defined(VK_KHR_deferred_host_operations)
#if defined(VK_KHR_descriptor_update_template)
PFN_vkCreateDescriptorUpdateTemplateKHR vkCreateDescriptorUpdateTemplateKHR;
PFN_vkDestroyDescriptorUpdateTemplateKHR vkDestroyDescriptorUpdateTemplateKHR;
PFN_vkUpdateDescriptorSetWithTemplateKHR vkUpdateDescriptorSetWithTemplateKHR;
#endif // defined(VK_KHR_descriptor_update_template)
#if defined(VK_KHR_device_group)
PFN_vkCmdDispatchBaseKHR vkCmdDispatchBaseKHR;
PFN_vkCmdSetDeviceMaskKHR vkCmdSetDeviceMaskKHR;
PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR vkGetDeviceGroupPeerMemoryFeaturesKHR;
#endif // defined(VK_KHR_device_group)
#if defined(VK_KHR_device_group_creation)
PFN_vkEnumeratePhysicalDeviceGroupsKHR vkEnumeratePhysicalDeviceGroupsKHR;
#endif // defined(VK_KHR_device_group_creation)
#if defined(VK_KHR_display)
PFN_vkCreateDisplayModeKHR vkCreateDisplayModeKHR;
PFN_vkCreateDisplayPlaneSurfaceKHR vkCreateDisplayPlaneSurfaceKHR;
PFN_vkGetDisplayModePropertiesKHR vkGetDisplayModePropertiesKHR;
PFN_vkGetDisplayPlaneCapabilitiesKHR vkGetDisplayPlaneCapabilitiesKHR;
PFN_vkGetDisplayPlaneSupportedDisplaysKHR vkGetDisplayPlaneSupportedDisplaysKHR;
PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vkGetPhysicalDeviceDisplayPropertiesKHR;
#endif // defined(VK_KHR_display)
#if defined(VK_KHR_display_swapchain)
PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;
#endif // defined(VK_KHR_display_swapchain)
#if defined(VK_KHR_draw_indirect_count)
PFN_vkCmdDrawIndexedIndirectCountKHR vkCmdDrawIndexedIndirectCountKHR;
PFN_vkCmdDrawIndirectCountKHR vkCmdDrawIndirectCountKHR;
#endif // defined(VK_KHR_draw_indirect_count)
#if defined(VK_KHR_dynamic_rendering)
PFN_vkCmdBeginRenderingKHR vkCmdBeginRenderingKHR;
PFN_vkCmdEndRenderingKHR vkCmdEndRenderingKHR;
#endif // defined(VK_KHR_dynamic_rendering)
#if defined(VK_KHR_external_fence_capabilities)
PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR vkGetPhysicalDeviceExternalFencePropertiesKHR;
#endif // defined(VK_KHR_external_fence_capabilities)
#if defined(VK_KHR_external_fence_fd)
PFN_vkGetFenceFdKHR vkGetFenceFdKHR;
PFN_vkImportFenceFdKHR vkImportFenceFdKHR;
#endif // defined(VK_KHR_external_fence_fd)
#if defined(VK_KHR_external_fence_win32)
PFN_vkGetFenceWin32HandleKHR vkGetFenceWin32HandleKHR;
PFN_vkImportFenceWin32HandleKHR vkImportFenceWin32HandleKHR;
#endif // defined(VK_KHR_external_fence_win32)
#if defined(VK_KHR_external_memory_capabilities)
PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR vkGetPhysicalDeviceExternalBufferPropertiesKHR;
#endif // defined(VK_KHR_external_memory_capabilities)
#if defined(VK_KHR_external_memory_fd)
PFN_vkGetMemoryFdKHR vkGetMemoryFdKHR;
PFN_vkGetMemoryFdPropertiesKHR vkGetMemoryFdPropertiesKHR;
#endif // defined(VK_KHR_external_memory_fd)
#if defined(VK_KHR_external_memory_win32)
PFN_vkGetMemoryWin32HandleKHR vkGetMemoryWin32HandleKHR;
PFN_vkGetMemoryWin32HandlePropertiesKHR vkGetMemoryWin32HandlePropertiesKHR;
#endif // defined(VK_KHR_external_memory_win32)
#if defined(VK_KHR_external_semaphore_capabilities)
PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
#endif // defined(VK_KHR_external_semaphore_capabilities)
#if defined(VK_KHR_external_semaphore_fd)
PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHR;
PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHR;
#endif // defined(VK_KHR_external_semaphore_fd)
#if defined(VK_KHR_external_semaphore_win32)
PFN_vkGetSemaphoreWin32HandleKHR vkGetSemaphoreWin32HandleKHR;
PFN_vkImportSemaphoreWin32HandleKHR vkImportSemaphoreWin32HandleKHR;
#endif // defined(VK_KHR_external_semaphore_win32)
#if defined(VK_KHR_fragment_shading_rate)
PFN_vkCmdSetFragmentShadingRateKHR vkCmdSetFragmentShadingRateKHR;
PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR vkGetPhysicalDeviceFragmentShadingRatesKHR;
#endif // defined(VK_KHR_fragment_shading_rate)
#if defined(VK_KHR_get_display_properties2)
PFN_vkGetDisplayModeProperties2KHR vkGetDisplayModeProperties2KHR;
PFN_vkGetDisplayPlaneCapabilities2KHR vkGetDisplayPlaneCapabilities2KHR;
PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
PFN_vkGetPhysicalDeviceDisplayProperties2KHR vkGetPhysicalDeviceDisplayProperties2KHR;
#endif // defined(VK_KHR_get_display_properties2)
#if defined(VK_KHR_get_memory_requirements2)
PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR;
PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR;
PFN_vkGetImageSparseMemoryRequirements2KHR vkGetImageSparseMemoryRequirements2KHR;
#endif // defined(VK_KHR_get_memory_requirements2)
#if defined(VK_KHR_get_physical_device_properties2)
PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR;
PFN_vkGetPhysicalDeviceFormatProperties2KHR vkGetPhysicalDeviceFormatProperties2KHR;
PFN_vkGetPhysicalDeviceImageFormatProperties2KHR vkGetPhysicalDeviceImageFormatProperties2KHR;
PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR;
PFN_vkGetPhysicalDeviceProperties2KHR vkGetPhysicalDeviceProperties2KHR;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR vkGetPhysicalDeviceQueueFamilyProperties2KHR;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
#endif // defined(VK_KHR_get_physical_device_properties2)
#if defined(VK_KHR_get_surface_capabilities2)
PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR vkGetPhysicalDeviceSurfaceCapabilities2KHR;
PFN_vkGetPhysicalDeviceSurfaceFormats2KHR vkGetPhysicalDeviceSurfaceFormats2KHR;
#endif // defined(VK_KHR_get_surface_capabilities2)
#if defined(VK_KHR_maintenance1)
PFN_vkTrimCommandPoolKHR vkTrimCommandPoolKHR;
#endif // defined(VK_KHR_maintenance1)
#if defined(VK_KHR_maintenance3)
PFN_vkGetDescriptorSetLayoutSupportKHR vkGetDescriptorSetLayoutSupportKHR;
#endif // defined(VK_KHR_maintenance3)
#if defined(VK_KHR_maintenance4)
PFN_vkGetDeviceBufferMemoryRequirementsKHR vkGetDeviceBufferMemoryRequirementsKHR;
PFN_vkGetDeviceImageMemoryRequirementsKHR vkGetDeviceImageMemoryRequirementsKHR;
PFN_vkGetDeviceImageSparseMemoryRequirementsKHR vkGetDeviceImageSparseMemoryRequirementsKHR;
#endif // defined(VK_KHR_maintenance4)
#if defined(VK_KHR_performance_query)
PFN_vkAcquireProfilingLockKHR vkAcquireProfilingLockKHR;
PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
PFN_vkReleaseProfilingLockKHR vkReleaseProfilingLockKHR;
#endif // defined(VK_KHR_performance_query)
#if defined(VK_KHR_pipeline_executable_properties)
PFN_vkGetPipelineExecutableInternalRepresentationsKHR vkGetPipelineExecutableInternalRepresentationsKHR;
PFN_vkGetPipelineExecutablePropertiesKHR vkGetPipelineExecutablePropertiesKHR;
PFN_vkGetPipelineExecutableStatisticsKHR vkGetPipelineExecutableStatisticsKHR;
#endif // defined(VK_KHR_pipeline_executable_properties)
#if defined(VK_KHR_present_wait)
PFN_vkWaitForPresentKHR vkWaitForPresentKHR;
#endif // defined(VK_KHR_present_wait)
#if defined(VK_KHR_push_descriptor)
PFN_vkCmdPushDescriptorSetKHR vkCmdPushDescriptorSetKHR;
#endif // defined(VK_KHR_push_descriptor)
#if (defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline))
PFN_vkCmdTraceRaysIndirect2KHR vkCmdTraceRaysIndirect2KHR;
#endif // (defined(VK_KHR_ray_tracing_maintenance1) && defined(VK_KHR_ray_tracing_pipeline))
#if defined(VK_KHR_ray_tracing_pipeline)
PFN_vkCmdSetRayTracingPipelineStackSizeKHR vkCmdSetRayTracingPipelineStackSizeKHR;
PFN_vkCmdTraceRaysIndirectKHR vkCmdTraceRaysIndirectKHR;
PFN_vkCmdTraceRaysKHR vkCmdTraceRaysKHR;
PFN_vkCreateRayTracingPipelinesKHR vkCreateRayTracingPipelinesKHR;
PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
PFN_vkGetRayTracingShaderGroupHandlesKHR vkGetRayTracingShaderGroupHandlesKHR;
PFN_vkGetRayTracingShaderGroupStackSizeKHR vkGetRayTracingShaderGroupStackSizeKHR;
#endif // defined(VK_KHR_ray_tracing_pipeline)
#if defined(VK_KHR_sampler_ycbcr_conversion)
PFN_vkCreateSamplerYcbcrConversionKHR vkCreateSamplerYcbcrConversionKHR;
PFN_vkDestroySamplerYcbcrConversionKHR vkDestroySamplerYcbcrConversionKHR;
#endif // defined(VK_KHR_sampler_ycbcr_conversion)
#if defined(VK_KHR_shared_presentable_image)
PFN_vkGetSwapchainStatusKHR vkGetSwapchainStatusKHR;
#endif // defined(VK_KHR_shared_presentable_image)
#if defined(VK_KHR_surface)
PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
#endif // defined(VK_KHR_surface)
#if defined(VK_KHR_swapchain)
PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
PFN_vkQueuePresentKHR vkQueuePresentKHR;
#endif // defined(VK_KHR_swapchain)
#if defined(VK_KHR_synchronization2)
PFN_vkCmdPipelineBarrier2KHR vkCmdPipelineBarrier2KHR;
PFN_vkCmdResetEvent2KHR vkCmdResetEvent2KHR;
PFN_vkCmdSetEvent2KHR vkCmdSetEvent2KHR;
PFN_vkCmdWaitEvents2KHR vkCmdWaitEvents2KHR;
PFN_vkCmdWriteTimestamp2KHR vkCmdWriteTimestamp2KHR;
PFN_vkQueueSubmit2KHR vkQueueSubmit2KHR;
#endif // defined(VK_KHR_synchronization2)
#if (defined(VK_KHR_synchronization2) && defined(VK_AMD_buffer_marker))
PFN_vkCmdWriteBufferMarker2AMD vkCmdWriteBufferMarker2AMD;
#endif // (defined(VK_KHR_synchronization2) && defined(VK_AMD_buffer_marker))
#if (defined(VK_KHR_synchronization2) && defined(VK_NV_device_diagnostic_checkpoints))
PFN_vkGetQueueCheckpointData2NV vkGetQueueCheckpointData2NV;
#endif // (defined(VK_KHR_synchronization2) && defined(VK_NV_device_diagnostic_checkpoints))
#if defined(VK_KHR_timeline_semaphore)
PFN_vkGetSemaphoreCounterValueKHR vkGetSemaphoreCounterValueKHR;
PFN_vkSignalSemaphoreKHR vkSignalSemaphoreKHR;
PFN_vkWaitSemaphoresKHR vkWaitSemaphoresKHR;
#endif // defined(VK_KHR_timeline_semaphore)
#if defined(VK_KHR_video_decode_queue)
PFN_vkCmdDecodeVideoKHR vkCmdDecodeVideoKHR;
#endif // defined(VK_KHR_video_decode_queue)
#if defined(VK_KHR_video_encode_queue)
PFN_vkCmdEncodeVideoKHR vkCmdEncodeVideoKHR;
#endif // defined(VK_KHR_video_encode_queue)
#if defined(VK_KHR_video_queue)
PFN_vkBindVideoSessionMemoryKHR vkBindVideoSessionMemoryKHR;
PFN_vkCmdBeginVideoCodingKHR vkCmdBeginVideoCodingKHR;
PFN_vkCmdControlVideoCodingKHR vkCmdControlVideoCodingKHR;
PFN_vkCmdEndVideoCodingKHR vkCmdEndVideoCodingKHR;
PFN_vkCreateVideoSessionKHR vkCreateVideoSessionKHR;
PFN_vkCreateVideoSessionParametersKHR vkCreateVideoSessionParametersKHR;
PFN_vkDestroyVideoSessionKHR vkDestroyVideoSessionKHR;
PFN_vkDestroyVideoSessionParametersKHR vkDestroyVideoSessionParametersKHR;
PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR vkGetPhysicalDeviceVideoCapabilitiesKHR;
PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR vkGetPhysicalDeviceVideoFormatPropertiesKHR;
PFN_vkGetVideoSessionMemoryRequirementsKHR vkGetVideoSessionMemoryRequirementsKHR;
PFN_vkUpdateVideoSessionParametersKHR vkUpdateVideoSessionParametersKHR;
#endif // defined(VK_KHR_video_queue)
#if defined(VK_KHR_wayland_surface)
PFN_vkCreateWaylandSurfaceKHR vkCreateWaylandSurfaceKHR;
PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif // defined(VK_KHR_wayland_surface)
#if defined(VK_KHR_win32_surface)
PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif // defined(VK_KHR_win32_surface)
#if defined(VK_KHR_xcb_surface)
PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR;
PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif // defined(VK_KHR_xcb_surface)
#if defined(VK_KHR_xlib_surface)
PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif // defined(VK_KHR_xlib_surface)
#if defined(VK_MVK_ios_surface)
PFN_vkCreateIOSSurfaceMVK vkCreateIOSSurfaceMVK;
#endif // defined(VK_MVK_ios_surface)
#if defined(VK_MVK_macos_surface)
PFN_vkCreateMacOSSurfaceMVK vkCreateMacOSSurfaceMVK;
#endif // defined(VK_MVK_macos_surface)
#if defined(VK_NN_vi_surface)
PFN_vkCreateViSurfaceNN vkCreateViSurfaceNN;
#endif // defined(VK_NN_vi_surface)
#if defined(VK_NVX_binary_import)
PFN_vkCmdCuLaunchKernelNVX vkCmdCuLaunchKernelNVX;
PFN_vkCreateCuFunctionNVX vkCreateCuFunctionNVX;
PFN_vkCreateCuModuleNVX vkCreateCuModuleNVX;
PFN_vkDestroyCuFunctionNVX vkDestroyCuFunctionNVX;
PFN_vkDestroyCuModuleNVX vkDestroyCuModuleNVX;
#endif // defined(VK_NVX_binary_import)
#if defined(VK_NVX_image_view_handle)
PFN_vkGetImageViewAddressNVX vkGetImageViewAddressNVX;
PFN_vkGetImageViewHandleNVX vkGetImageViewHandleNVX;
#endif // defined(VK_NVX_image_view_handle)
#if defined(VK_NV_acquire_winrt_display)
PFN_vkAcquireWinrtDisplayNV vkAcquireWinrtDisplayNV;
PFN_vkGetWinrtDisplayNV vkGetWinrtDisplayNV;
#endif // defined(VK_NV_acquire_winrt_display)
#if defined(VK_NV_clip_space_w_scaling)
PFN_vkCmdSetViewportWScalingNV vkCmdSetViewportWScalingNV;
#endif // defined(VK_NV_clip_space_w_scaling)
#if defined(VK_NV_cooperative_matrix)
PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
#endif // defined(VK_NV_cooperative_matrix)
#if defined(VK_NV_coverage_reduction_mode)
PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;
#endif // defined(VK_NV_coverage_reduction_mode)
#if defined(VK_NV_device_diagnostic_checkpoints)
PFN_vkCmdSetCheckpointNV vkCmdSetCheckpointNV;
PFN_vkGetQueueCheckpointDataNV vkGetQueueCheckpointDataNV;
#endif // defined(VK_NV_device_diagnostic_checkpoints)
#if defined(VK_NV_device_generated_commands)
PFN_vkCmdBindPipelineShaderGroupNV vkCmdBindPipelineShaderGroupNV;
PFN_vkCmdExecuteGeneratedCommandsNV vkCmdExecuteGeneratedCommandsNV;
PFN_vkCmdPreprocessGeneratedCommandsNV vkCmdPreprocessGeneratedCommandsNV;
PFN_vkCreateIndirectCommandsLayoutNV vkCreateIndirectCommandsLayoutNV;
PFN_vkDestroyIndirectCommandsLayoutNV vkDestroyIndirectCommandsLayoutNV;
PFN_vkGetGeneratedCommandsMemoryRequirementsNV vkGetGeneratedCommandsMemoryRequirementsNV;
#endif // defined(VK_NV_device_generated_commands)
#if defined(VK_NV_external_memory_capabilities)
PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
#endif // defined(VK_NV_external_memory_capabilities)
#if defined(VK_NV_external_memory_rdma)
PFN_vkGetMemoryRemoteAddressNV vkGetMemoryRemoteAddressNV;
#endif // defined(VK_NV_external_memory_rdma)
#if defined(VK_NV_external_memory_win32)
PFN_vkGetMemoryWin32HandleNV vkGetMemoryWin32HandleNV;
#endif // defined(VK_NV_external_memory_win32)
#if defined(VK_NV_fragment_shading_rate_enums)
PFN_vkCmdSetFragmentShadingRateEnumNV vkCmdSetFragmentShadingRateEnumNV;
#endif // defined(VK_NV_fragment_shading_rate_enums)
#if defined(VK_NV_mesh_shader)
PFN_vkCmdDrawMeshTasksIndirectCountNV vkCmdDrawMeshTasksIndirectCountNV;
PFN_vkCmdDrawMeshTasksIndirectNV vkCmdDrawMeshTasksIndirectNV;
PFN_vkCmdDrawMeshTasksNV vkCmdDrawMeshTasksNV;
#endif // defined(VK_NV_mesh_shader)
#if defined(VK_NV_ray_tracing)
PFN_vkBindAccelerationStructureMemoryNV vkBindAccelerationStructureMemoryNV;
PFN_vkCmdBuildAccelerationStructureNV vkCmdBuildAccelerationStructureNV;
PFN_vkCmdCopyAccelerationStructureNV vkCmdCopyAccelerationStructureNV;
PFN_vkCmdTraceRaysNV vkCmdTraceRaysNV;
PFN_vkCmdWriteAccelerationStructuresPropertiesNV vkCmdWriteAccelerationStructuresPropertiesNV;
PFN_vkCompileDeferredNV vkCompileDeferredNV;
PFN_vkCreateAccelerationStructureNV vkCreateAccelerationStructureNV;
PFN_vkCreateRayTracingPipelinesNV vkCreateRayTracingPipelinesNV;
PFN_vkDestroyAccelerationStructureNV vkDestroyAccelerationStructureNV;
PFN_vkGetAccelerationStructureHandleNV vkGetAccelerationStructureHandleNV;
PFN_vkGetAccelerationStructureMemoryRequirementsNV vkGetAccelerationStructureMemoryRequirementsNV;
PFN_vkGetRayTracingShaderGroupHandlesNV vkGetRayTracingShaderGroupHandlesNV;
#endif // defined(VK_NV_ray_tracing)
#if defined(VK_NV_scissor_exclusive)
PFN_vkCmdSetExclusiveScissorNV vkCmdSetExclusiveScissorNV;
#endif // defined(VK_NV_scissor_exclusive)
#if defined(VK_NV_shading_rate_image)
PFN_vkCmdBindShadingRateImageNV vkCmdBindShadingRateImageNV;
PFN_vkCmdSetCoarseSampleOrderNV vkCmdSetCoarseSampleOrderNV;
PFN_vkCmdSetViewportShadingRatePaletteNV vkCmdSetViewportShadingRatePaletteNV;
#endif // defined(VK_NV_shading_rate_image)
#if defined(VK_QNX_screen_surface)
PFN_vkCreateScreenSurfaceQNX vkCreateScreenSurfaceQNX;
PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX vkGetPhysicalDeviceScreenPresentationSupportQNX;
#endif // defined(VK_QNX_screen_surface)
#if defined(VK_VALVE_descriptor_set_host_mapping)
PFN_vkGetDescriptorSetHostMappingVALVE vkGetDescriptorSetHostMappingVALVE;
PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE vkGetDescriptorSetLayoutHostMappingInfoVALVE;
#endif // defined(VK_VALVE_descriptor_set_host_mapping)
#if (defined(VK_EXT_full_screen_exclusive) && defined(VK_KHR_device_group)) || (defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1))
PFN_vkGetDeviceGroupSurfacePresentModes2EXT vkGetDeviceGroupSurfacePresentModes2EXT;
#endif // (defined(VK_EXT_full_screen_exclusive) && defined(VK_KHR_device_group)) || (defined(VK_EXT_full_screen_exclusive) && defined(VK_VERSION_1_1))
#if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_push_descriptor) && defined(VK_KHR_descriptor_update_template))
PFN_vkCmdPushDescriptorSetWithTemplateKHR vkCmdPushDescriptorSetWithTemplateKHR;
#endif // (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1)) || (defined(VK_KHR_push_descriptor) && defined(VK_KHR_descriptor_update_template))
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
PFN_vkGetDeviceGroupPresentCapabilitiesKHR vkGetDeviceGroupPresentCapabilitiesKHR;
PFN_vkGetDeviceGroupSurfacePresentModesKHR vkGetDeviceGroupSurfacePresentModesKHR;
PFN_vkGetPhysicalDevicePresentRectanglesKHR vkGetPhysicalDevicePresentRectanglesKHR;
#endif // (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
#if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
PFN_vkAcquireNextImage2KHR vkAcquireNextImage2KHR;
#endif // (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))

} // namespace bluevk

#if !defined(NDEBUG)
#include "third_party/filament/libs/utils/include/utils/Log.h"
utils::io::ostream& operator<<(utils::io::ostream& out, const VkImageLayout& value) {
    switch (value) {
        case VK_IMAGE_LAYOUT_UNDEFINED: out << "VK_IMAGE_LAYOUT_UNDEFINED"; break;
        case VK_IMAGE_LAYOUT_GENERAL: out << "VK_IMAGE_LAYOUT_GENERAL"; break;
        case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL: out << "VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL"; break;
        case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL: out << "VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL"; break;
        case VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL: out << "VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL"; break;
        case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL: out << "VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL"; break;
        case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL: out << "VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL"; break;
        case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL: out << "VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL"; break;
        case VK_IMAGE_LAYOUT_PREINITIALIZED: out << "VK_IMAGE_LAYOUT_PREINITIALIZED"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkAttachmentLoadOp& value) {
    switch (value) {
        case VK_ATTACHMENT_LOAD_OP_LOAD: out << "VK_ATTACHMENT_LOAD_OP_LOAD"; break;
        case VK_ATTACHMENT_LOAD_OP_CLEAR: out << "VK_ATTACHMENT_LOAD_OP_CLEAR"; break;
        case VK_ATTACHMENT_LOAD_OP_DONT_CARE: out << "VK_ATTACHMENT_LOAD_OP_DONT_CARE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkAttachmentStoreOp& value) {
    switch (value) {
        case VK_ATTACHMENT_STORE_OP_STORE: out << "VK_ATTACHMENT_STORE_OP_STORE"; break;
        case VK_ATTACHMENT_STORE_OP_DONT_CARE: out << "VK_ATTACHMENT_STORE_OP_DONT_CARE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkImageType& value) {
    switch (value) {
        case VK_IMAGE_TYPE_1D: out << "VK_IMAGE_TYPE_1D"; break;
        case VK_IMAGE_TYPE_2D: out << "VK_IMAGE_TYPE_2D"; break;
        case VK_IMAGE_TYPE_3D: out << "VK_IMAGE_TYPE_3D"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkImageTiling& value) {
    switch (value) {
        case VK_IMAGE_TILING_OPTIMAL: out << "VK_IMAGE_TILING_OPTIMAL"; break;
        case VK_IMAGE_TILING_LINEAR: out << "VK_IMAGE_TILING_LINEAR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkImageViewType& value) {
    switch (value) {
        case VK_IMAGE_VIEW_TYPE_1D: out << "VK_IMAGE_VIEW_TYPE_1D"; break;
        case VK_IMAGE_VIEW_TYPE_2D: out << "VK_IMAGE_VIEW_TYPE_2D"; break;
        case VK_IMAGE_VIEW_TYPE_3D: out << "VK_IMAGE_VIEW_TYPE_3D"; break;
        case VK_IMAGE_VIEW_TYPE_CUBE: out << "VK_IMAGE_VIEW_TYPE_CUBE"; break;
        case VK_IMAGE_VIEW_TYPE_1D_ARRAY: out << "VK_IMAGE_VIEW_TYPE_1D_ARRAY"; break;
        case VK_IMAGE_VIEW_TYPE_2D_ARRAY: out << "VK_IMAGE_VIEW_TYPE_2D_ARRAY"; break;
        case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY: out << "VK_IMAGE_VIEW_TYPE_CUBE_ARRAY"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkCommandBufferLevel& value) {
    switch (value) {
        case VK_COMMAND_BUFFER_LEVEL_PRIMARY: out << "VK_COMMAND_BUFFER_LEVEL_PRIMARY"; break;
        case VK_COMMAND_BUFFER_LEVEL_SECONDARY: out << "VK_COMMAND_BUFFER_LEVEL_SECONDARY"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkComponentSwizzle& value) {
    switch (value) {
        case VK_COMPONENT_SWIZZLE_IDENTITY: out << "VK_COMPONENT_SWIZZLE_IDENTITY"; break;
        case VK_COMPONENT_SWIZZLE_ZERO: out << "VK_COMPONENT_SWIZZLE_ZERO"; break;
        case VK_COMPONENT_SWIZZLE_ONE: out << "VK_COMPONENT_SWIZZLE_ONE"; break;
        case VK_COMPONENT_SWIZZLE_R: out << "VK_COMPONENT_SWIZZLE_R"; break;
        case VK_COMPONENT_SWIZZLE_G: out << "VK_COMPONENT_SWIZZLE_G"; break;
        case VK_COMPONENT_SWIZZLE_B: out << "VK_COMPONENT_SWIZZLE_B"; break;
        case VK_COMPONENT_SWIZZLE_A: out << "VK_COMPONENT_SWIZZLE_A"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDescriptorType& value) {
    switch (value) {
        case VK_DESCRIPTOR_TYPE_SAMPLER: out << "VK_DESCRIPTOR_TYPE_SAMPLER"; break;
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER: out << "VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER"; break;
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE: out << "VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE"; break;
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE: out << "VK_DESCRIPTOR_TYPE_STORAGE_IMAGE"; break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER: out << "VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER"; break;
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER: out << "VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER"; break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER: out << "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER"; break;
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER: out << "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER"; break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC: out << "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC"; break;
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC: out << "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC"; break;
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT: out << "VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkQueryType& value) {
    switch (value) {
        case VK_QUERY_TYPE_OCCLUSION: out << "VK_QUERY_TYPE_OCCLUSION"; break;
        case VK_QUERY_TYPE_PIPELINE_STATISTICS: out << "VK_QUERY_TYPE_PIPELINE_STATISTICS"; break;
        case VK_QUERY_TYPE_TIMESTAMP: out << "VK_QUERY_TYPE_TIMESTAMP"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkBorderColor& value) {
    switch (value) {
        case VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK: out << "VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK"; break;
        case VK_BORDER_COLOR_INT_TRANSPARENT_BLACK: out << "VK_BORDER_COLOR_INT_TRANSPARENT_BLACK"; break;
        case VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK: out << "VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK"; break;
        case VK_BORDER_COLOR_INT_OPAQUE_BLACK: out << "VK_BORDER_COLOR_INT_OPAQUE_BLACK"; break;
        case VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE: out << "VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE"; break;
        case VK_BORDER_COLOR_INT_OPAQUE_WHITE: out << "VK_BORDER_COLOR_INT_OPAQUE_WHITE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPipelineBindPoint& value) {
    switch (value) {
        case VK_PIPELINE_BIND_POINT_GRAPHICS: out << "VK_PIPELINE_BIND_POINT_GRAPHICS"; break;
        case VK_PIPELINE_BIND_POINT_COMPUTE: out << "VK_PIPELINE_BIND_POINT_COMPUTE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPipelineCacheHeaderVersion& value) {
    switch (value) {
        case VK_PIPELINE_CACHE_HEADER_VERSION_ONE: out << "VK_PIPELINE_CACHE_HEADER_VERSION_ONE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPrimitiveTopology& value) {
    switch (value) {
        case VK_PRIMITIVE_TOPOLOGY_POINT_LIST: out << "VK_PRIMITIVE_TOPOLOGY_POINT_LIST"; break;
        case VK_PRIMITIVE_TOPOLOGY_LINE_LIST: out << "VK_PRIMITIVE_TOPOLOGY_LINE_LIST"; break;
        case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP: out << "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP"; break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST: out << "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST"; break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP: out << "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP"; break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN: out << "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN"; break;
        case VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY: out << "VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY"; break;
        case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY: out << "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY"; break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY: out << "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY"; break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY: out << "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY"; break;
        case VK_PRIMITIVE_TOPOLOGY_PATCH_LIST: out << "VK_PRIMITIVE_TOPOLOGY_PATCH_LIST"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSharingMode& value) {
    switch (value) {
        case VK_SHARING_MODE_EXCLUSIVE: out << "VK_SHARING_MODE_EXCLUSIVE"; break;
        case VK_SHARING_MODE_CONCURRENT: out << "VK_SHARING_MODE_CONCURRENT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkIndexType& value) {
    switch (value) {
        case VK_INDEX_TYPE_UINT16: out << "VK_INDEX_TYPE_UINT16"; break;
        case VK_INDEX_TYPE_UINT32: out << "VK_INDEX_TYPE_UINT32"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkFilter& value) {
    switch (value) {
        case VK_FILTER_NEAREST: out << "VK_FILTER_NEAREST"; break;
        case VK_FILTER_LINEAR: out << "VK_FILTER_LINEAR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSamplerMipmapMode& value) {
    switch (value) {
        case VK_SAMPLER_MIPMAP_MODE_NEAREST: out << "VK_SAMPLER_MIPMAP_MODE_NEAREST"; break;
        case VK_SAMPLER_MIPMAP_MODE_LINEAR: out << "VK_SAMPLER_MIPMAP_MODE_LINEAR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSamplerAddressMode& value) {
    switch (value) {
        case VK_SAMPLER_ADDRESS_MODE_REPEAT: out << "VK_SAMPLER_ADDRESS_MODE_REPEAT"; break;
        case VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT: out << "VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT"; break;
        case VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE: out << "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE"; break;
        case VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER: out << "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkCompareOp& value) {
    switch (value) {
        case VK_COMPARE_OP_NEVER: out << "VK_COMPARE_OP_NEVER"; break;
        case VK_COMPARE_OP_LESS: out << "VK_COMPARE_OP_LESS"; break;
        case VK_COMPARE_OP_EQUAL: out << "VK_COMPARE_OP_EQUAL"; break;
        case VK_COMPARE_OP_LESS_OR_EQUAL: out << "VK_COMPARE_OP_LESS_OR_EQUAL"; break;
        case VK_COMPARE_OP_GREATER: out << "VK_COMPARE_OP_GREATER"; break;
        case VK_COMPARE_OP_NOT_EQUAL: out << "VK_COMPARE_OP_NOT_EQUAL"; break;
        case VK_COMPARE_OP_GREATER_OR_EQUAL: out << "VK_COMPARE_OP_GREATER_OR_EQUAL"; break;
        case VK_COMPARE_OP_ALWAYS: out << "VK_COMPARE_OP_ALWAYS"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPolygonMode& value) {
    switch (value) {
        case VK_POLYGON_MODE_FILL: out << "VK_POLYGON_MODE_FILL"; break;
        case VK_POLYGON_MODE_LINE: out << "VK_POLYGON_MODE_LINE"; break;
        case VK_POLYGON_MODE_POINT: out << "VK_POLYGON_MODE_POINT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkFrontFace& value) {
    switch (value) {
        case VK_FRONT_FACE_COUNTER_CLOCKWISE: out << "VK_FRONT_FACE_COUNTER_CLOCKWISE"; break;
        case VK_FRONT_FACE_CLOCKWISE: out << "VK_FRONT_FACE_CLOCKWISE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkBlendFactor& value) {
    switch (value) {
        case VK_BLEND_FACTOR_ZERO: out << "VK_BLEND_FACTOR_ZERO"; break;
        case VK_BLEND_FACTOR_ONE: out << "VK_BLEND_FACTOR_ONE"; break;
        case VK_BLEND_FACTOR_SRC_COLOR: out << "VK_BLEND_FACTOR_SRC_COLOR"; break;
        case VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR: out << "VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR"; break;
        case VK_BLEND_FACTOR_DST_COLOR: out << "VK_BLEND_FACTOR_DST_COLOR"; break;
        case VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR: out << "VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR"; break;
        case VK_BLEND_FACTOR_SRC_ALPHA: out << "VK_BLEND_FACTOR_SRC_ALPHA"; break;
        case VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA: out << "VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA"; break;
        case VK_BLEND_FACTOR_DST_ALPHA: out << "VK_BLEND_FACTOR_DST_ALPHA"; break;
        case VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA: out << "VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA"; break;
        case VK_BLEND_FACTOR_CONSTANT_COLOR: out << "VK_BLEND_FACTOR_CONSTANT_COLOR"; break;
        case VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR: out << "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR"; break;
        case VK_BLEND_FACTOR_CONSTANT_ALPHA: out << "VK_BLEND_FACTOR_CONSTANT_ALPHA"; break;
        case VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA: out << "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA"; break;
        case VK_BLEND_FACTOR_SRC_ALPHA_SATURATE: out << "VK_BLEND_FACTOR_SRC_ALPHA_SATURATE"; break;
        case VK_BLEND_FACTOR_SRC1_COLOR: out << "VK_BLEND_FACTOR_SRC1_COLOR"; break;
        case VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR: out << "VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR"; break;
        case VK_BLEND_FACTOR_SRC1_ALPHA: out << "VK_BLEND_FACTOR_SRC1_ALPHA"; break;
        case VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA: out << "VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkBlendOp& value) {
    switch (value) {
        case VK_BLEND_OP_ADD: out << "VK_BLEND_OP_ADD"; break;
        case VK_BLEND_OP_SUBTRACT: out << "VK_BLEND_OP_SUBTRACT"; break;
        case VK_BLEND_OP_REVERSE_SUBTRACT: out << "VK_BLEND_OP_REVERSE_SUBTRACT"; break;
        case VK_BLEND_OP_MIN: out << "VK_BLEND_OP_MIN"; break;
        case VK_BLEND_OP_MAX: out << "VK_BLEND_OP_MAX"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkStencilOp& value) {
    switch (value) {
        case VK_STENCIL_OP_KEEP: out << "VK_STENCIL_OP_KEEP"; break;
        case VK_STENCIL_OP_ZERO: out << "VK_STENCIL_OP_ZERO"; break;
        case VK_STENCIL_OP_REPLACE: out << "VK_STENCIL_OP_REPLACE"; break;
        case VK_STENCIL_OP_INCREMENT_AND_CLAMP: out << "VK_STENCIL_OP_INCREMENT_AND_CLAMP"; break;
        case VK_STENCIL_OP_DECREMENT_AND_CLAMP: out << "VK_STENCIL_OP_DECREMENT_AND_CLAMP"; break;
        case VK_STENCIL_OP_INVERT: out << "VK_STENCIL_OP_INVERT"; break;
        case VK_STENCIL_OP_INCREMENT_AND_WRAP: out << "VK_STENCIL_OP_INCREMENT_AND_WRAP"; break;
        case VK_STENCIL_OP_DECREMENT_AND_WRAP: out << "VK_STENCIL_OP_DECREMENT_AND_WRAP"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkLogicOp& value) {
    switch (value) {
        case VK_LOGIC_OP_CLEAR: out << "VK_LOGIC_OP_CLEAR"; break;
        case VK_LOGIC_OP_AND: out << "VK_LOGIC_OP_AND"; break;
        case VK_LOGIC_OP_AND_REVERSE: out << "VK_LOGIC_OP_AND_REVERSE"; break;
        case VK_LOGIC_OP_COPY: out << "VK_LOGIC_OP_COPY"; break;
        case VK_LOGIC_OP_AND_INVERTED: out << "VK_LOGIC_OP_AND_INVERTED"; break;
        case VK_LOGIC_OP_NO_OP: out << "VK_LOGIC_OP_NO_OP"; break;
        case VK_LOGIC_OP_XOR: out << "VK_LOGIC_OP_XOR"; break;
        case VK_LOGIC_OP_OR: out << "VK_LOGIC_OP_OR"; break;
        case VK_LOGIC_OP_NOR: out << "VK_LOGIC_OP_NOR"; break;
        case VK_LOGIC_OP_EQUIVALENT: out << "VK_LOGIC_OP_EQUIVALENT"; break;
        case VK_LOGIC_OP_INVERT: out << "VK_LOGIC_OP_INVERT"; break;
        case VK_LOGIC_OP_OR_REVERSE: out << "VK_LOGIC_OP_OR_REVERSE"; break;
        case VK_LOGIC_OP_COPY_INVERTED: out << "VK_LOGIC_OP_COPY_INVERTED"; break;
        case VK_LOGIC_OP_OR_INVERTED: out << "VK_LOGIC_OP_OR_INVERTED"; break;
        case VK_LOGIC_OP_NAND: out << "VK_LOGIC_OP_NAND"; break;
        case VK_LOGIC_OP_SET: out << "VK_LOGIC_OP_SET"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkInternalAllocationType& value) {
    switch (value) {
        case VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE: out << "VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSystemAllocationScope& value) {
    switch (value) {
        case VK_SYSTEM_ALLOCATION_SCOPE_COMMAND: out << "VK_SYSTEM_ALLOCATION_SCOPE_COMMAND"; break;
        case VK_SYSTEM_ALLOCATION_SCOPE_OBJECT: out << "VK_SYSTEM_ALLOCATION_SCOPE_OBJECT"; break;
        case VK_SYSTEM_ALLOCATION_SCOPE_CACHE: out << "VK_SYSTEM_ALLOCATION_SCOPE_CACHE"; break;
        case VK_SYSTEM_ALLOCATION_SCOPE_DEVICE: out << "VK_SYSTEM_ALLOCATION_SCOPE_DEVICE"; break;
        case VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE: out << "VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPhysicalDeviceType& value) {
    switch (value) {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER: out << "VK_PHYSICAL_DEVICE_TYPE_OTHER"; break;
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: out << "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU"; break;
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU: out << "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU"; break;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU: out << "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU"; break;
        case VK_PHYSICAL_DEVICE_TYPE_CPU: out << "VK_PHYSICAL_DEVICE_TYPE_CPU"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkVertexInputRate& value) {
    switch (value) {
        case VK_VERTEX_INPUT_RATE_VERTEX: out << "VK_VERTEX_INPUT_RATE_VERTEX"; break;
        case VK_VERTEX_INPUT_RATE_INSTANCE: out << "VK_VERTEX_INPUT_RATE_INSTANCE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkFormat& value) {
    switch (value) {
        case VK_FORMAT_UNDEFINED: out << "VK_FORMAT_UNDEFINED"; break;
        case VK_FORMAT_R4G4_UNORM_PACK8: out << "VK_FORMAT_R4G4_UNORM_PACK8"; break;
        case VK_FORMAT_R4G4B4A4_UNORM_PACK16: out << "VK_FORMAT_R4G4B4A4_UNORM_PACK16"; break;
        case VK_FORMAT_B4G4R4A4_UNORM_PACK16: out << "VK_FORMAT_B4G4R4A4_UNORM_PACK16"; break;
        case VK_FORMAT_R5G6B5_UNORM_PACK16: out << "VK_FORMAT_R5G6B5_UNORM_PACK16"; break;
        case VK_FORMAT_B5G6R5_UNORM_PACK16: out << "VK_FORMAT_B5G6R5_UNORM_PACK16"; break;
        case VK_FORMAT_R5G5B5A1_UNORM_PACK16: out << "VK_FORMAT_R5G5B5A1_UNORM_PACK16"; break;
        case VK_FORMAT_B5G5R5A1_UNORM_PACK16: out << "VK_FORMAT_B5G5R5A1_UNORM_PACK16"; break;
        case VK_FORMAT_A1R5G5B5_UNORM_PACK16: out << "VK_FORMAT_A1R5G5B5_UNORM_PACK16"; break;
        case VK_FORMAT_R8_UNORM: out << "VK_FORMAT_R8_UNORM"; break;
        case VK_FORMAT_R8_SNORM: out << "VK_FORMAT_R8_SNORM"; break;
        case VK_FORMAT_R8_USCALED: out << "VK_FORMAT_R8_USCALED"; break;
        case VK_FORMAT_R8_SSCALED: out << "VK_FORMAT_R8_SSCALED"; break;
        case VK_FORMAT_R8_UINT: out << "VK_FORMAT_R8_UINT"; break;
        case VK_FORMAT_R8_SINT: out << "VK_FORMAT_R8_SINT"; break;
        case VK_FORMAT_R8_SRGB: out << "VK_FORMAT_R8_SRGB"; break;
        case VK_FORMAT_R8G8_UNORM: out << "VK_FORMAT_R8G8_UNORM"; break;
        case VK_FORMAT_R8G8_SNORM: out << "VK_FORMAT_R8G8_SNORM"; break;
        case VK_FORMAT_R8G8_USCALED: out << "VK_FORMAT_R8G8_USCALED"; break;
        case VK_FORMAT_R8G8_SSCALED: out << "VK_FORMAT_R8G8_SSCALED"; break;
        case VK_FORMAT_R8G8_UINT: out << "VK_FORMAT_R8G8_UINT"; break;
        case VK_FORMAT_R8G8_SINT: out << "VK_FORMAT_R8G8_SINT"; break;
        case VK_FORMAT_R8G8_SRGB: out << "VK_FORMAT_R8G8_SRGB"; break;
        case VK_FORMAT_R8G8B8_UNORM: out << "VK_FORMAT_R8G8B8_UNORM"; break;
        case VK_FORMAT_R8G8B8_SNORM: out << "VK_FORMAT_R8G8B8_SNORM"; break;
        case VK_FORMAT_R8G8B8_USCALED: out << "VK_FORMAT_R8G8B8_USCALED"; break;
        case VK_FORMAT_R8G8B8_SSCALED: out << "VK_FORMAT_R8G8B8_SSCALED"; break;
        case VK_FORMAT_R8G8B8_UINT: out << "VK_FORMAT_R8G8B8_UINT"; break;
        case VK_FORMAT_R8G8B8_SINT: out << "VK_FORMAT_R8G8B8_SINT"; break;
        case VK_FORMAT_R8G8B8_SRGB: out << "VK_FORMAT_R8G8B8_SRGB"; break;
        case VK_FORMAT_B8G8R8_UNORM: out << "VK_FORMAT_B8G8R8_UNORM"; break;
        case VK_FORMAT_B8G8R8_SNORM: out << "VK_FORMAT_B8G8R8_SNORM"; break;
        case VK_FORMAT_B8G8R8_USCALED: out << "VK_FORMAT_B8G8R8_USCALED"; break;
        case VK_FORMAT_B8G8R8_SSCALED: out << "VK_FORMAT_B8G8R8_SSCALED"; break;
        case VK_FORMAT_B8G8R8_UINT: out << "VK_FORMAT_B8G8R8_UINT"; break;
        case VK_FORMAT_B8G8R8_SINT: out << "VK_FORMAT_B8G8R8_SINT"; break;
        case VK_FORMAT_B8G8R8_SRGB: out << "VK_FORMAT_B8G8R8_SRGB"; break;
        case VK_FORMAT_R8G8B8A8_UNORM: out << "VK_FORMAT_R8G8B8A8_UNORM"; break;
        case VK_FORMAT_R8G8B8A8_SNORM: out << "VK_FORMAT_R8G8B8A8_SNORM"; break;
        case VK_FORMAT_R8G8B8A8_USCALED: out << "VK_FORMAT_R8G8B8A8_USCALED"; break;
        case VK_FORMAT_R8G8B8A8_SSCALED: out << "VK_FORMAT_R8G8B8A8_SSCALED"; break;
        case VK_FORMAT_R8G8B8A8_UINT: out << "VK_FORMAT_R8G8B8A8_UINT"; break;
        case VK_FORMAT_R8G8B8A8_SINT: out << "VK_FORMAT_R8G8B8A8_SINT"; break;
        case VK_FORMAT_R8G8B8A8_SRGB: out << "VK_FORMAT_R8G8B8A8_SRGB"; break;
        case VK_FORMAT_B8G8R8A8_UNORM: out << "VK_FORMAT_B8G8R8A8_UNORM"; break;
        case VK_FORMAT_B8G8R8A8_SNORM: out << "VK_FORMAT_B8G8R8A8_SNORM"; break;
        case VK_FORMAT_B8G8R8A8_USCALED: out << "VK_FORMAT_B8G8R8A8_USCALED"; break;
        case VK_FORMAT_B8G8R8A8_SSCALED: out << "VK_FORMAT_B8G8R8A8_SSCALED"; break;
        case VK_FORMAT_B8G8R8A8_UINT: out << "VK_FORMAT_B8G8R8A8_UINT"; break;
        case VK_FORMAT_B8G8R8A8_SINT: out << "VK_FORMAT_B8G8R8A8_SINT"; break;
        case VK_FORMAT_B8G8R8A8_SRGB: out << "VK_FORMAT_B8G8R8A8_SRGB"; break;
        case VK_FORMAT_A8B8G8R8_UNORM_PACK32: out << "VK_FORMAT_A8B8G8R8_UNORM_PACK32"; break;
        case VK_FORMAT_A8B8G8R8_SNORM_PACK32: out << "VK_FORMAT_A8B8G8R8_SNORM_PACK32"; break;
        case VK_FORMAT_A8B8G8R8_USCALED_PACK32: out << "VK_FORMAT_A8B8G8R8_USCALED_PACK32"; break;
        case VK_FORMAT_A8B8G8R8_SSCALED_PACK32: out << "VK_FORMAT_A8B8G8R8_SSCALED_PACK32"; break;
        case VK_FORMAT_A8B8G8R8_UINT_PACK32: out << "VK_FORMAT_A8B8G8R8_UINT_PACK32"; break;
        case VK_FORMAT_A8B8G8R8_SINT_PACK32: out << "VK_FORMAT_A8B8G8R8_SINT_PACK32"; break;
        case VK_FORMAT_A8B8G8R8_SRGB_PACK32: out << "VK_FORMAT_A8B8G8R8_SRGB_PACK32"; break;
        case VK_FORMAT_A2R10G10B10_UNORM_PACK32: out << "VK_FORMAT_A2R10G10B10_UNORM_PACK32"; break;
        case VK_FORMAT_A2R10G10B10_SNORM_PACK32: out << "VK_FORMAT_A2R10G10B10_SNORM_PACK32"; break;
        case VK_FORMAT_A2R10G10B10_USCALED_PACK32: out << "VK_FORMAT_A2R10G10B10_USCALED_PACK32"; break;
        case VK_FORMAT_A2R10G10B10_SSCALED_PACK32: out << "VK_FORMAT_A2R10G10B10_SSCALED_PACK32"; break;
        case VK_FORMAT_A2R10G10B10_UINT_PACK32: out << "VK_FORMAT_A2R10G10B10_UINT_PACK32"; break;
        case VK_FORMAT_A2R10G10B10_SINT_PACK32: out << "VK_FORMAT_A2R10G10B10_SINT_PACK32"; break;
        case VK_FORMAT_A2B10G10R10_UNORM_PACK32: out << "VK_FORMAT_A2B10G10R10_UNORM_PACK32"; break;
        case VK_FORMAT_A2B10G10R10_SNORM_PACK32: out << "VK_FORMAT_A2B10G10R10_SNORM_PACK32"; break;
        case VK_FORMAT_A2B10G10R10_USCALED_PACK32: out << "VK_FORMAT_A2B10G10R10_USCALED_PACK32"; break;
        case VK_FORMAT_A2B10G10R10_SSCALED_PACK32: out << "VK_FORMAT_A2B10G10R10_SSCALED_PACK32"; break;
        case VK_FORMAT_A2B10G10R10_UINT_PACK32: out << "VK_FORMAT_A2B10G10R10_UINT_PACK32"; break;
        case VK_FORMAT_A2B10G10R10_SINT_PACK32: out << "VK_FORMAT_A2B10G10R10_SINT_PACK32"; break;
        case VK_FORMAT_R16_UNORM: out << "VK_FORMAT_R16_UNORM"; break;
        case VK_FORMAT_R16_SNORM: out << "VK_FORMAT_R16_SNORM"; break;
        case VK_FORMAT_R16_USCALED: out << "VK_FORMAT_R16_USCALED"; break;
        case VK_FORMAT_R16_SSCALED: out << "VK_FORMAT_R16_SSCALED"; break;
        case VK_FORMAT_R16_UINT: out << "VK_FORMAT_R16_UINT"; break;
        case VK_FORMAT_R16_SINT: out << "VK_FORMAT_R16_SINT"; break;
        case VK_FORMAT_R16_SFLOAT: out << "VK_FORMAT_R16_SFLOAT"; break;
        case VK_FORMAT_R16G16_UNORM: out << "VK_FORMAT_R16G16_UNORM"; break;
        case VK_FORMAT_R16G16_SNORM: out << "VK_FORMAT_R16G16_SNORM"; break;
        case VK_FORMAT_R16G16_USCALED: out << "VK_FORMAT_R16G16_USCALED"; break;
        case VK_FORMAT_R16G16_SSCALED: out << "VK_FORMAT_R16G16_SSCALED"; break;
        case VK_FORMAT_R16G16_UINT: out << "VK_FORMAT_R16G16_UINT"; break;
        case VK_FORMAT_R16G16_SINT: out << "VK_FORMAT_R16G16_SINT"; break;
        case VK_FORMAT_R16G16_SFLOAT: out << "VK_FORMAT_R16G16_SFLOAT"; break;
        case VK_FORMAT_R16G16B16_UNORM: out << "VK_FORMAT_R16G16B16_UNORM"; break;
        case VK_FORMAT_R16G16B16_SNORM: out << "VK_FORMAT_R16G16B16_SNORM"; break;
        case VK_FORMAT_R16G16B16_USCALED: out << "VK_FORMAT_R16G16B16_USCALED"; break;
        case VK_FORMAT_R16G16B16_SSCALED: out << "VK_FORMAT_R16G16B16_SSCALED"; break;
        case VK_FORMAT_R16G16B16_UINT: out << "VK_FORMAT_R16G16B16_UINT"; break;
        case VK_FORMAT_R16G16B16_SINT: out << "VK_FORMAT_R16G16B16_SINT"; break;
        case VK_FORMAT_R16G16B16_SFLOAT: out << "VK_FORMAT_R16G16B16_SFLOAT"; break;
        case VK_FORMAT_R16G16B16A16_UNORM: out << "VK_FORMAT_R16G16B16A16_UNORM"; break;
        case VK_FORMAT_R16G16B16A16_SNORM: out << "VK_FORMAT_R16G16B16A16_SNORM"; break;
        case VK_FORMAT_R16G16B16A16_USCALED: out << "VK_FORMAT_R16G16B16A16_USCALED"; break;
        case VK_FORMAT_R16G16B16A16_SSCALED: out << "VK_FORMAT_R16G16B16A16_SSCALED"; break;
        case VK_FORMAT_R16G16B16A16_UINT: out << "VK_FORMAT_R16G16B16A16_UINT"; break;
        case VK_FORMAT_R16G16B16A16_SINT: out << "VK_FORMAT_R16G16B16A16_SINT"; break;
        case VK_FORMAT_R16G16B16A16_SFLOAT: out << "VK_FORMAT_R16G16B16A16_SFLOAT"; break;
        case VK_FORMAT_R32_UINT: out << "VK_FORMAT_R32_UINT"; break;
        case VK_FORMAT_R32_SINT: out << "VK_FORMAT_R32_SINT"; break;
        case VK_FORMAT_R32_SFLOAT: out << "VK_FORMAT_R32_SFLOAT"; break;
        case VK_FORMAT_R32G32_UINT: out << "VK_FORMAT_R32G32_UINT"; break;
        case VK_FORMAT_R32G32_SINT: out << "VK_FORMAT_R32G32_SINT"; break;
        case VK_FORMAT_R32G32_SFLOAT: out << "VK_FORMAT_R32G32_SFLOAT"; break;
        case VK_FORMAT_R32G32B32_UINT: out << "VK_FORMAT_R32G32B32_UINT"; break;
        case VK_FORMAT_R32G32B32_SINT: out << "VK_FORMAT_R32G32B32_SINT"; break;
        case VK_FORMAT_R32G32B32_SFLOAT: out << "VK_FORMAT_R32G32B32_SFLOAT"; break;
        case VK_FORMAT_R32G32B32A32_UINT: out << "VK_FORMAT_R32G32B32A32_UINT"; break;
        case VK_FORMAT_R32G32B32A32_SINT: out << "VK_FORMAT_R32G32B32A32_SINT"; break;
        case VK_FORMAT_R32G32B32A32_SFLOAT: out << "VK_FORMAT_R32G32B32A32_SFLOAT"; break;
        case VK_FORMAT_R64_UINT: out << "VK_FORMAT_R64_UINT"; break;
        case VK_FORMAT_R64_SINT: out << "VK_FORMAT_R64_SINT"; break;
        case VK_FORMAT_R64_SFLOAT: out << "VK_FORMAT_R64_SFLOAT"; break;
        case VK_FORMAT_R64G64_UINT: out << "VK_FORMAT_R64G64_UINT"; break;
        case VK_FORMAT_R64G64_SINT: out << "VK_FORMAT_R64G64_SINT"; break;
        case VK_FORMAT_R64G64_SFLOAT: out << "VK_FORMAT_R64G64_SFLOAT"; break;
        case VK_FORMAT_R64G64B64_UINT: out << "VK_FORMAT_R64G64B64_UINT"; break;
        case VK_FORMAT_R64G64B64_SINT: out << "VK_FORMAT_R64G64B64_SINT"; break;
        case VK_FORMAT_R64G64B64_SFLOAT: out << "VK_FORMAT_R64G64B64_SFLOAT"; break;
        case VK_FORMAT_R64G64B64A64_UINT: out << "VK_FORMAT_R64G64B64A64_UINT"; break;
        case VK_FORMAT_R64G64B64A64_SINT: out << "VK_FORMAT_R64G64B64A64_SINT"; break;
        case VK_FORMAT_R64G64B64A64_SFLOAT: out << "VK_FORMAT_R64G64B64A64_SFLOAT"; break;
        case VK_FORMAT_B10G11R11_UFLOAT_PACK32: out << "VK_FORMAT_B10G11R11_UFLOAT_PACK32"; break;
        case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32: out << "VK_FORMAT_E5B9G9R9_UFLOAT_PACK32"; break;
        case VK_FORMAT_D16_UNORM: out << "VK_FORMAT_D16_UNORM"; break;
        case VK_FORMAT_X8_D24_UNORM_PACK32: out << "VK_FORMAT_X8_D24_UNORM_PACK32"; break;
        case VK_FORMAT_D32_SFLOAT: out << "VK_FORMAT_D32_SFLOAT"; break;
        case VK_FORMAT_S8_UINT: out << "VK_FORMAT_S8_UINT"; break;
        case VK_FORMAT_D16_UNORM_S8_UINT: out << "VK_FORMAT_D16_UNORM_S8_UINT"; break;
        case VK_FORMAT_D24_UNORM_S8_UINT: out << "VK_FORMAT_D24_UNORM_S8_UINT"; break;
        case VK_FORMAT_D32_SFLOAT_S8_UINT: out << "VK_FORMAT_D32_SFLOAT_S8_UINT"; break;
        case VK_FORMAT_BC1_RGB_UNORM_BLOCK: out << "VK_FORMAT_BC1_RGB_UNORM_BLOCK"; break;
        case VK_FORMAT_BC1_RGB_SRGB_BLOCK: out << "VK_FORMAT_BC1_RGB_SRGB_BLOCK"; break;
        case VK_FORMAT_BC1_RGBA_UNORM_BLOCK: out << "VK_FORMAT_BC1_RGBA_UNORM_BLOCK"; break;
        case VK_FORMAT_BC1_RGBA_SRGB_BLOCK: out << "VK_FORMAT_BC1_RGBA_SRGB_BLOCK"; break;
        case VK_FORMAT_BC2_UNORM_BLOCK: out << "VK_FORMAT_BC2_UNORM_BLOCK"; break;
        case VK_FORMAT_BC2_SRGB_BLOCK: out << "VK_FORMAT_BC2_SRGB_BLOCK"; break;
        case VK_FORMAT_BC3_UNORM_BLOCK: out << "VK_FORMAT_BC3_UNORM_BLOCK"; break;
        case VK_FORMAT_BC3_SRGB_BLOCK: out << "VK_FORMAT_BC3_SRGB_BLOCK"; break;
        case VK_FORMAT_BC4_UNORM_BLOCK: out << "VK_FORMAT_BC4_UNORM_BLOCK"; break;
        case VK_FORMAT_BC4_SNORM_BLOCK: out << "VK_FORMAT_BC4_SNORM_BLOCK"; break;
        case VK_FORMAT_BC5_UNORM_BLOCK: out << "VK_FORMAT_BC5_UNORM_BLOCK"; break;
        case VK_FORMAT_BC5_SNORM_BLOCK: out << "VK_FORMAT_BC5_SNORM_BLOCK"; break;
        case VK_FORMAT_BC6H_UFLOAT_BLOCK: out << "VK_FORMAT_BC6H_UFLOAT_BLOCK"; break;
        case VK_FORMAT_BC6H_SFLOAT_BLOCK: out << "VK_FORMAT_BC6H_SFLOAT_BLOCK"; break;
        case VK_FORMAT_BC7_UNORM_BLOCK: out << "VK_FORMAT_BC7_UNORM_BLOCK"; break;
        case VK_FORMAT_BC7_SRGB_BLOCK: out << "VK_FORMAT_BC7_SRGB_BLOCK"; break;
        case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK: out << "VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK"; break;
        case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK: out << "VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK"; break;
        case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK: out << "VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK"; break;
        case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK: out << "VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK"; break;
        case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK: out << "VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK"; break;
        case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK: out << "VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK"; break;
        case VK_FORMAT_EAC_R11_UNORM_BLOCK: out << "VK_FORMAT_EAC_R11_UNORM_BLOCK"; break;
        case VK_FORMAT_EAC_R11_SNORM_BLOCK: out << "VK_FORMAT_EAC_R11_SNORM_BLOCK"; break;
        case VK_FORMAT_EAC_R11G11_UNORM_BLOCK: out << "VK_FORMAT_EAC_R11G11_UNORM_BLOCK"; break;
        case VK_FORMAT_EAC_R11G11_SNORM_BLOCK: out << "VK_FORMAT_EAC_R11G11_SNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_4x4_UNORM_BLOCK: out << "VK_FORMAT_ASTC_4x4_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_4x4_SRGB_BLOCK: out << "VK_FORMAT_ASTC_4x4_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_5x4_UNORM_BLOCK: out << "VK_FORMAT_ASTC_5x4_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_5x4_SRGB_BLOCK: out << "VK_FORMAT_ASTC_5x4_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_5x5_UNORM_BLOCK: out << "VK_FORMAT_ASTC_5x5_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_5x5_SRGB_BLOCK: out << "VK_FORMAT_ASTC_5x5_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_6x5_UNORM_BLOCK: out << "VK_FORMAT_ASTC_6x5_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_6x5_SRGB_BLOCK: out << "VK_FORMAT_ASTC_6x5_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_6x6_UNORM_BLOCK: out << "VK_FORMAT_ASTC_6x6_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_6x6_SRGB_BLOCK: out << "VK_FORMAT_ASTC_6x6_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_8x5_UNORM_BLOCK: out << "VK_FORMAT_ASTC_8x5_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_8x5_SRGB_BLOCK: out << "VK_FORMAT_ASTC_8x5_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_8x6_UNORM_BLOCK: out << "VK_FORMAT_ASTC_8x6_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_8x6_SRGB_BLOCK: out << "VK_FORMAT_ASTC_8x6_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_8x8_UNORM_BLOCK: out << "VK_FORMAT_ASTC_8x8_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_8x8_SRGB_BLOCK: out << "VK_FORMAT_ASTC_8x8_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_10x5_UNORM_BLOCK: out << "VK_FORMAT_ASTC_10x5_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_10x5_SRGB_BLOCK: out << "VK_FORMAT_ASTC_10x5_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_10x6_UNORM_BLOCK: out << "VK_FORMAT_ASTC_10x6_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_10x6_SRGB_BLOCK: out << "VK_FORMAT_ASTC_10x6_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_10x8_UNORM_BLOCK: out << "VK_FORMAT_ASTC_10x8_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_10x8_SRGB_BLOCK: out << "VK_FORMAT_ASTC_10x8_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_10x10_UNORM_BLOCK: out << "VK_FORMAT_ASTC_10x10_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_10x10_SRGB_BLOCK: out << "VK_FORMAT_ASTC_10x10_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_12x10_UNORM_BLOCK: out << "VK_FORMAT_ASTC_12x10_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_12x10_SRGB_BLOCK: out << "VK_FORMAT_ASTC_12x10_SRGB_BLOCK"; break;
        case VK_FORMAT_ASTC_12x12_UNORM_BLOCK: out << "VK_FORMAT_ASTC_12x12_UNORM_BLOCK"; break;
        case VK_FORMAT_ASTC_12x12_SRGB_BLOCK: out << "VK_FORMAT_ASTC_12x12_SRGB_BLOCK"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkStructureType& value) {
    switch (value) {
        case VK_STRUCTURE_TYPE_APPLICATION_INFO: out << "VK_STRUCTURE_TYPE_APPLICATION_INFO"; break;
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO: out << "VK_STRUCTURE_TYPE_SUBMIT_INFO"; break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO: out << "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO"; break;
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE: out << "VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE"; break;
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO: out << "VK_STRUCTURE_TYPE_BIND_SPARSE_INFO"; break;
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_FENCE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO: out << "VK_STRUCTURE_TYPE_EVENT_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO: out << "VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO: out << "VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO: out << "VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO: out << "VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: out << "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO: out << "VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO: out << "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO: out << "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO: out << "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO"; break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET: out << "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET"; break;
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET: out << "VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET"; break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO: out << "VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO: out << "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO: out << "VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO: out << "VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO"; break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO: out << "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO"; break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO: out << "VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO"; break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO: out << "VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO"; break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER: out << "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER"; break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER: out << "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER"; break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER: out << "VK_STRUCTURE_TYPE_MEMORY_BARRIER"; break;
        case VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO"; break;
        case VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO: out << "VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSubpassContents& value) {
    switch (value) {
        case VK_SUBPASS_CONTENTS_INLINE: out << "VK_SUBPASS_CONTENTS_INLINE"; break;
        case VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS: out << "VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkResult& value) {
    switch (value) {
        case VK_SUCCESS: out << "VK_SUCCESS"; break;
        case VK_NOT_READY: out << "VK_NOT_READY"; break;
        case VK_TIMEOUT: out << "VK_TIMEOUT"; break;
        case VK_EVENT_SET: out << "VK_EVENT_SET"; break;
        case VK_EVENT_RESET: out << "VK_EVENT_RESET"; break;
        case VK_INCOMPLETE: out << "VK_INCOMPLETE"; break;
        case VK_ERROR_OUT_OF_HOST_MEMORY: out << "VK_ERROR_OUT_OF_HOST_MEMORY"; break;
        case VK_ERROR_OUT_OF_DEVICE_MEMORY: out << "VK_ERROR_OUT_OF_DEVICE_MEMORY"; break;
        case VK_ERROR_INITIALIZATION_FAILED: out << "VK_ERROR_INITIALIZATION_FAILED"; break;
        case VK_ERROR_DEVICE_LOST: out << "VK_ERROR_DEVICE_LOST"; break;
        case VK_ERROR_MEMORY_MAP_FAILED: out << "VK_ERROR_MEMORY_MAP_FAILED"; break;
        case VK_ERROR_LAYER_NOT_PRESENT: out << "VK_ERROR_LAYER_NOT_PRESENT"; break;
        case VK_ERROR_EXTENSION_NOT_PRESENT: out << "VK_ERROR_EXTENSION_NOT_PRESENT"; break;
        case VK_ERROR_FEATURE_NOT_PRESENT: out << "VK_ERROR_FEATURE_NOT_PRESENT"; break;
        case VK_ERROR_INCOMPATIBLE_DRIVER: out << "VK_ERROR_INCOMPATIBLE_DRIVER"; break;
        case VK_ERROR_TOO_MANY_OBJECTS: out << "VK_ERROR_TOO_MANY_OBJECTS"; break;
        case VK_ERROR_FORMAT_NOT_SUPPORTED: out << "VK_ERROR_FORMAT_NOT_SUPPORTED"; break;
        case VK_ERROR_FRAGMENTED_POOL: out << "VK_ERROR_FRAGMENTED_POOL"; break;
        case VK_ERROR_UNKNOWN: out << "VK_ERROR_UNKNOWN"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDynamicState& value) {
    switch (value) {
        case VK_DYNAMIC_STATE_VIEWPORT: out << "VK_DYNAMIC_STATE_VIEWPORT"; break;
        case VK_DYNAMIC_STATE_SCISSOR: out << "VK_DYNAMIC_STATE_SCISSOR"; break;
        case VK_DYNAMIC_STATE_LINE_WIDTH: out << "VK_DYNAMIC_STATE_LINE_WIDTH"; break;
        case VK_DYNAMIC_STATE_DEPTH_BIAS: out << "VK_DYNAMIC_STATE_DEPTH_BIAS"; break;
        case VK_DYNAMIC_STATE_BLEND_CONSTANTS: out << "VK_DYNAMIC_STATE_BLEND_CONSTANTS"; break;
        case VK_DYNAMIC_STATE_DEPTH_BOUNDS: out << "VK_DYNAMIC_STATE_DEPTH_BOUNDS"; break;
        case VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK: out << "VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK"; break;
        case VK_DYNAMIC_STATE_STENCIL_WRITE_MASK: out << "VK_DYNAMIC_STATE_STENCIL_WRITE_MASK"; break;
        case VK_DYNAMIC_STATE_STENCIL_REFERENCE: out << "VK_DYNAMIC_STATE_STENCIL_REFERENCE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDescriptorUpdateTemplateType& value) {
    switch (value) {
        case VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET: out << "VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkObjectType& value) {
    switch (value) {
        case VK_OBJECT_TYPE_UNKNOWN: out << "VK_OBJECT_TYPE_UNKNOWN"; break;
        case VK_OBJECT_TYPE_INSTANCE: out << "VK_OBJECT_TYPE_INSTANCE"; break;
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE: out << "VK_OBJECT_TYPE_PHYSICAL_DEVICE"; break;
        case VK_OBJECT_TYPE_DEVICE: out << "VK_OBJECT_TYPE_DEVICE"; break;
        case VK_OBJECT_TYPE_QUEUE: out << "VK_OBJECT_TYPE_QUEUE"; break;
        case VK_OBJECT_TYPE_SEMAPHORE: out << "VK_OBJECT_TYPE_SEMAPHORE"; break;
        case VK_OBJECT_TYPE_COMMAND_BUFFER: out << "VK_OBJECT_TYPE_COMMAND_BUFFER"; break;
        case VK_OBJECT_TYPE_FENCE: out << "VK_OBJECT_TYPE_FENCE"; break;
        case VK_OBJECT_TYPE_DEVICE_MEMORY: out << "VK_OBJECT_TYPE_DEVICE_MEMORY"; break;
        case VK_OBJECT_TYPE_BUFFER: out << "VK_OBJECT_TYPE_BUFFER"; break;
        case VK_OBJECT_TYPE_IMAGE: out << "VK_OBJECT_TYPE_IMAGE"; break;
        case VK_OBJECT_TYPE_EVENT: out << "VK_OBJECT_TYPE_EVENT"; break;
        case VK_OBJECT_TYPE_QUERY_POOL: out << "VK_OBJECT_TYPE_QUERY_POOL"; break;
        case VK_OBJECT_TYPE_BUFFER_VIEW: out << "VK_OBJECT_TYPE_BUFFER_VIEW"; break;
        case VK_OBJECT_TYPE_IMAGE_VIEW: out << "VK_OBJECT_TYPE_IMAGE_VIEW"; break;
        case VK_OBJECT_TYPE_SHADER_MODULE: out << "VK_OBJECT_TYPE_SHADER_MODULE"; break;
        case VK_OBJECT_TYPE_PIPELINE_CACHE: out << "VK_OBJECT_TYPE_PIPELINE_CACHE"; break;
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT: out << "VK_OBJECT_TYPE_PIPELINE_LAYOUT"; break;
        case VK_OBJECT_TYPE_RENDER_PASS: out << "VK_OBJECT_TYPE_RENDER_PASS"; break;
        case VK_OBJECT_TYPE_PIPELINE: out << "VK_OBJECT_TYPE_PIPELINE"; break;
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT: out << "VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT"; break;
        case VK_OBJECT_TYPE_SAMPLER: out << "VK_OBJECT_TYPE_SAMPLER"; break;
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL: out << "VK_OBJECT_TYPE_DESCRIPTOR_POOL"; break;
        case VK_OBJECT_TYPE_DESCRIPTOR_SET: out << "VK_OBJECT_TYPE_DESCRIPTOR_SET"; break;
        case VK_OBJECT_TYPE_FRAMEBUFFER: out << "VK_OBJECT_TYPE_FRAMEBUFFER"; break;
        case VK_OBJECT_TYPE_COMMAND_POOL: out << "VK_OBJECT_TYPE_COMMAND_POOL"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSemaphoreType& value) {
    switch (value) {
        case VK_SEMAPHORE_TYPE_BINARY: out << "VK_SEMAPHORE_TYPE_BINARY"; break;
        case VK_SEMAPHORE_TYPE_TIMELINE: out << "VK_SEMAPHORE_TYPE_TIMELINE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPresentModeKHR& value) {
    switch (value) {
        case VK_PRESENT_MODE_IMMEDIATE_KHR: out << "VK_PRESENT_MODE_IMMEDIATE_KHR"; break;
        case VK_PRESENT_MODE_MAILBOX_KHR: out << "VK_PRESENT_MODE_MAILBOX_KHR"; break;
        case VK_PRESENT_MODE_FIFO_KHR: out << "VK_PRESENT_MODE_FIFO_KHR"; break;
        case VK_PRESENT_MODE_FIFO_RELAXED_KHR: out << "VK_PRESENT_MODE_FIFO_RELAXED_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkColorSpaceKHR& value) {
    switch (value) {
        case VK_COLOR_SPACE_SRGB_NONLINEAR_KHR: out << "VK_COLOR_SPACE_SRGB_NONLINEAR_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkTimeDomainEXT& value) {
    switch (value) {
        case VK_TIME_DOMAIN_DEVICE_EXT: out << "VK_TIME_DOMAIN_DEVICE_EXT"; break;
        case VK_TIME_DOMAIN_CLOCK_MONOTONIC_EXT: out << "VK_TIME_DOMAIN_CLOCK_MONOTONIC_EXT"; break;
        case VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT: out << "VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT"; break;
        case VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_EXT: out << "VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDebugReportObjectTypeEXT& value) {
    switch (value) {
        case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT"; break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT: out << "VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDeviceMemoryReportEventTypeEXT& value) {
    switch (value) {
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT: out << "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT"; break;
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT: out << "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT"; break;
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT: out << "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT"; break;
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT: out << "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT"; break;
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT: out << "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkRasterizationOrderAMD& value) {
    switch (value) {
        case VK_RASTERIZATION_ORDER_STRICT_AMD: out << "VK_RASTERIZATION_ORDER_STRICT_AMD"; break;
        case VK_RASTERIZATION_ORDER_RELAXED_AMD: out << "VK_RASTERIZATION_ORDER_RELAXED_AMD"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkValidationCheckEXT& value) {
    switch (value) {
        case VK_VALIDATION_CHECK_ALL_EXT: out << "VK_VALIDATION_CHECK_ALL_EXT"; break;
        case VK_VALIDATION_CHECK_SHADERS_EXT: out << "VK_VALIDATION_CHECK_SHADERS_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkValidationFeatureEnableEXT& value) {
    switch (value) {
        case VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT: out << "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT"; break;
        case VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT: out << "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT"; break;
        case VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT: out << "VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT"; break;
        case VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT: out << "VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT"; break;
        case VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT: out << "VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkValidationFeatureDisableEXT& value) {
    switch (value) {
        case VK_VALIDATION_FEATURE_DISABLE_ALL_EXT: out << "VK_VALIDATION_FEATURE_DISABLE_ALL_EXT"; break;
        case VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT: out << "VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT"; break;
        case VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT: out << "VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT"; break;
        case VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT: out << "VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT"; break;
        case VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT: out << "VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT"; break;
        case VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT: out << "VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT"; break;
        case VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT: out << "VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT"; break;
        case VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT: out << "VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkIndirectCommandsTokenTypeNV& value) {
    switch (value) {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV: out << "VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV"; break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV: out << "VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV"; break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV: out << "VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV"; break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV: out << "VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV"; break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV: out << "VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV"; break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV: out << "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV"; break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV: out << "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV"; break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV: out << "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDisplayPowerStateEXT& value) {
    switch (value) {
        case VK_DISPLAY_POWER_STATE_OFF_EXT: out << "VK_DISPLAY_POWER_STATE_OFF_EXT"; break;
        case VK_DISPLAY_POWER_STATE_SUSPEND_EXT: out << "VK_DISPLAY_POWER_STATE_SUSPEND_EXT"; break;
        case VK_DISPLAY_POWER_STATE_ON_EXT: out << "VK_DISPLAY_POWER_STATE_ON_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDeviceEventTypeEXT& value) {
    switch (value) {
        case VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT: out << "VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDisplayEventTypeEXT& value) {
    switch (value) {
        case VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT: out << "VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkViewportCoordinateSwizzleNV& value) {
    switch (value) {
        case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV: out << "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV"; break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV: out << "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV"; break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV: out << "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV"; break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV: out << "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV"; break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV: out << "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV"; break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV: out << "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV"; break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV: out << "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV"; break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV: out << "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDiscardRectangleModeEXT& value) {
    switch (value) {
        case VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT: out << "VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT"; break;
        case VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT: out << "VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPointClippingBehavior& value) {
    switch (value) {
        case VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES: out << "VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES"; break;
        case VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY: out << "VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSamplerReductionMode& value) {
    switch (value) {
        case VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE: out << "VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE"; break;
        case VK_SAMPLER_REDUCTION_MODE_MIN: out << "VK_SAMPLER_REDUCTION_MODE_MIN"; break;
        case VK_SAMPLER_REDUCTION_MODE_MAX: out << "VK_SAMPLER_REDUCTION_MODE_MAX"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkTessellationDomainOrigin& value) {
    switch (value) {
        case VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT: out << "VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT"; break;
        case VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT: out << "VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSamplerYcbcrModelConversion& value) {
    switch (value) {
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY: out << "VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY"; break;
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY: out << "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY"; break;
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709: out << "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709"; break;
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601: out << "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601"; break;
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020: out << "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSamplerYcbcrRange& value) {
    switch (value) {
        case VK_SAMPLER_YCBCR_RANGE_ITU_FULL: out << "VK_SAMPLER_YCBCR_RANGE_ITU_FULL"; break;
        case VK_SAMPLER_YCBCR_RANGE_ITU_NARROW: out << "VK_SAMPLER_YCBCR_RANGE_ITU_NARROW"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkChromaLocation& value) {
    switch (value) {
        case VK_CHROMA_LOCATION_COSITED_EVEN: out << "VK_CHROMA_LOCATION_COSITED_EVEN"; break;
        case VK_CHROMA_LOCATION_MIDPOINT: out << "VK_CHROMA_LOCATION_MIDPOINT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkBlendOverlapEXT& value) {
    switch (value) {
        case VK_BLEND_OVERLAP_UNCORRELATED_EXT: out << "VK_BLEND_OVERLAP_UNCORRELATED_EXT"; break;
        case VK_BLEND_OVERLAP_DISJOINT_EXT: out << "VK_BLEND_OVERLAP_DISJOINT_EXT"; break;
        case VK_BLEND_OVERLAP_CONJOINT_EXT: out << "VK_BLEND_OVERLAP_CONJOINT_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkCoverageModulationModeNV& value) {
    switch (value) {
        case VK_COVERAGE_MODULATION_MODE_NONE_NV: out << "VK_COVERAGE_MODULATION_MODE_NONE_NV"; break;
        case VK_COVERAGE_MODULATION_MODE_RGB_NV: out << "VK_COVERAGE_MODULATION_MODE_RGB_NV"; break;
        case VK_COVERAGE_MODULATION_MODE_ALPHA_NV: out << "VK_COVERAGE_MODULATION_MODE_ALPHA_NV"; break;
        case VK_COVERAGE_MODULATION_MODE_RGBA_NV: out << "VK_COVERAGE_MODULATION_MODE_RGBA_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkCoverageReductionModeNV& value) {
    switch (value) {
        case VK_COVERAGE_REDUCTION_MODE_MERGE_NV: out << "VK_COVERAGE_REDUCTION_MODE_MERGE_NV"; break;
        case VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV: out << "VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkValidationCacheHeaderVersionEXT& value) {
    switch (value) {
        case VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT: out << "VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkShaderInfoTypeAMD& value) {
    switch (value) {
        case VK_SHADER_INFO_TYPE_STATISTICS_AMD: out << "VK_SHADER_INFO_TYPE_STATISTICS_AMD"; break;
        case VK_SHADER_INFO_TYPE_BINARY_AMD: out << "VK_SHADER_INFO_TYPE_BINARY_AMD"; break;
        case VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD: out << "VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkQueueGlobalPriorityKHR& value) {
    switch (value) {
        case VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR: out << "VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR"; break;
        case VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR: out << "VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR"; break;
        case VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR: out << "VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR"; break;
        case VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR: out << "VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkConservativeRasterizationModeEXT& value) {
    switch (value) {
        case VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT: out << "VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT"; break;
        case VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT: out << "VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT"; break;
        case VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT: out << "VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkVendorId& value) {
    switch (value) {
        case VK_VENDOR_ID_VIV: out << "VK_VENDOR_ID_VIV"; break;
        case VK_VENDOR_ID_VSI: out << "VK_VENDOR_ID_VSI"; break;
        case VK_VENDOR_ID_KAZAN: out << "VK_VENDOR_ID_KAZAN"; break;
        case VK_VENDOR_ID_CODEPLAY: out << "VK_VENDOR_ID_CODEPLAY"; break;
        case VK_VENDOR_ID_MESA: out << "VK_VENDOR_ID_MESA"; break;
        case VK_VENDOR_ID_POCL: out << "VK_VENDOR_ID_POCL"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkDriverId& value) {
    switch (value) {
        case VK_DRIVER_ID_AMD_PROPRIETARY: out << "VK_DRIVER_ID_AMD_PROPRIETARY"; break;
        case VK_DRIVER_ID_AMD_OPEN_SOURCE: out << "VK_DRIVER_ID_AMD_OPEN_SOURCE"; break;
        case VK_DRIVER_ID_MESA_RADV: out << "VK_DRIVER_ID_MESA_RADV"; break;
        case VK_DRIVER_ID_NVIDIA_PROPRIETARY: out << "VK_DRIVER_ID_NVIDIA_PROPRIETARY"; break;
        case VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS: out << "VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS"; break;
        case VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA: out << "VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA"; break;
        case VK_DRIVER_ID_IMAGINATION_PROPRIETARY: out << "VK_DRIVER_ID_IMAGINATION_PROPRIETARY"; break;
        case VK_DRIVER_ID_QUALCOMM_PROPRIETARY: out << "VK_DRIVER_ID_QUALCOMM_PROPRIETARY"; break;
        case VK_DRIVER_ID_ARM_PROPRIETARY: out << "VK_DRIVER_ID_ARM_PROPRIETARY"; break;
        case VK_DRIVER_ID_GOOGLE_SWIFTSHADER: out << "VK_DRIVER_ID_GOOGLE_SWIFTSHADER"; break;
        case VK_DRIVER_ID_GGP_PROPRIETARY: out << "VK_DRIVER_ID_GGP_PROPRIETARY"; break;
        case VK_DRIVER_ID_BROADCOM_PROPRIETARY: out << "VK_DRIVER_ID_BROADCOM_PROPRIETARY"; break;
        case VK_DRIVER_ID_MESA_LLVMPIPE: out << "VK_DRIVER_ID_MESA_LLVMPIPE"; break;
        case VK_DRIVER_ID_MOLTENVK: out << "VK_DRIVER_ID_MOLTENVK"; break;
        case VK_DRIVER_ID_COREAVI_PROPRIETARY: out << "VK_DRIVER_ID_COREAVI_PROPRIETARY"; break;
        case VK_DRIVER_ID_JUICE_PROPRIETARY: out << "VK_DRIVER_ID_JUICE_PROPRIETARY"; break;
        case VK_DRIVER_ID_VERISILICON_PROPRIETARY: out << "VK_DRIVER_ID_VERISILICON_PROPRIETARY"; break;
        case VK_DRIVER_ID_MESA_TURNIP: out << "VK_DRIVER_ID_MESA_TURNIP"; break;
        case VK_DRIVER_ID_MESA_V3DV: out << "VK_DRIVER_ID_MESA_V3DV"; break;
        case VK_DRIVER_ID_MESA_PANVK: out << "VK_DRIVER_ID_MESA_PANVK"; break;
        case VK_DRIVER_ID_SAMSUNG_PROPRIETARY: out << "VK_DRIVER_ID_SAMSUNG_PROPRIETARY"; break;
        case VK_DRIVER_ID_MESA_VENUS: out << "VK_DRIVER_ID_MESA_VENUS"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkShadingRatePaletteEntryNV& value) {
    switch (value) {
        case VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV"; break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV: out << "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkCoarseSampleOrderTypeNV& value) {
    switch (value) {
        case VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV: out << "VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV"; break;
        case VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV: out << "VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV"; break;
        case VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV: out << "VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV"; break;
        case VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV: out << "VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkCopyAccelerationStructureModeKHR& value) {
    switch (value) {
        case VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR: out << "VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR"; break;
        case VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR: out << "VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR"; break;
        case VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR: out << "VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR"; break;
        case VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR: out << "VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkBuildAccelerationStructureModeKHR& value) {
    switch (value) {
        case VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR: out << "VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR"; break;
        case VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR: out << "VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkAccelerationStructureTypeKHR& value) {
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR: out << "VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR"; break;
        case VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR: out << "VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR"; break;
        case VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR: out << "VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkGeometryTypeKHR& value) {
    switch (value) {
        case VK_GEOMETRY_TYPE_TRIANGLES_KHR: out << "VK_GEOMETRY_TYPE_TRIANGLES_KHR"; break;
        case VK_GEOMETRY_TYPE_AABBS_KHR: out << "VK_GEOMETRY_TYPE_AABBS_KHR"; break;
        case VK_GEOMETRY_TYPE_INSTANCES_KHR: out << "VK_GEOMETRY_TYPE_INSTANCES_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkAccelerationStructureMemoryRequirementsTypeNV& value) {
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV: out << "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV"; break;
        case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV: out << "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV"; break;
        case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV: out << "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkAccelerationStructureBuildTypeKHR& value) {
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR: out << "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR"; break;
        case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR: out << "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR"; break;
        case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR: out << "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkRayTracingShaderGroupTypeKHR& value) {
    switch (value) {
        case VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR: out << "VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR"; break;
        case VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR: out << "VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR"; break;
        case VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR: out << "VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkAccelerationStructureCompatibilityKHR& value) {
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR: out << "VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR"; break;
        case VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR: out << "VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkShaderGroupShaderKHR& value) {
    switch (value) {
        case VK_SHADER_GROUP_SHADER_GENERAL_KHR: out << "VK_SHADER_GROUP_SHADER_GENERAL_KHR"; break;
        case VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR: out << "VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR"; break;
        case VK_SHADER_GROUP_SHADER_ANY_HIT_KHR: out << "VK_SHADER_GROUP_SHADER_ANY_HIT_KHR"; break;
        case VK_SHADER_GROUP_SHADER_INTERSECTION_KHR: out << "VK_SHADER_GROUP_SHADER_INTERSECTION_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkMemoryOverallocationBehaviorAMD& value) {
    switch (value) {
        case VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD: out << "VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD"; break;
        case VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD: out << "VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD"; break;
        case VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD: out << "VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkScopeNV& value) {
    switch (value) {
        case VK_SCOPE_DEVICE_NV: out << "VK_SCOPE_DEVICE_NV"; break;
        case VK_SCOPE_WORKGROUP_NV: out << "VK_SCOPE_WORKGROUP_NV"; break;
        case VK_SCOPE_SUBGROUP_NV: out << "VK_SCOPE_SUBGROUP_NV"; break;
        case VK_SCOPE_QUEUE_FAMILY_NV: out << "VK_SCOPE_QUEUE_FAMILY_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkComponentTypeNV& value) {
    switch (value) {
        case VK_COMPONENT_TYPE_FLOAT16_NV: out << "VK_COMPONENT_TYPE_FLOAT16_NV"; break;
        case VK_COMPONENT_TYPE_FLOAT32_NV: out << "VK_COMPONENT_TYPE_FLOAT32_NV"; break;
        case VK_COMPONENT_TYPE_FLOAT64_NV: out << "VK_COMPONENT_TYPE_FLOAT64_NV"; break;
        case VK_COMPONENT_TYPE_SINT8_NV: out << "VK_COMPONENT_TYPE_SINT8_NV"; break;
        case VK_COMPONENT_TYPE_SINT16_NV: out << "VK_COMPONENT_TYPE_SINT16_NV"; break;
        case VK_COMPONENT_TYPE_SINT32_NV: out << "VK_COMPONENT_TYPE_SINT32_NV"; break;
        case VK_COMPONENT_TYPE_SINT64_NV: out << "VK_COMPONENT_TYPE_SINT64_NV"; break;
        case VK_COMPONENT_TYPE_UINT8_NV: out << "VK_COMPONENT_TYPE_UINT8_NV"; break;
        case VK_COMPONENT_TYPE_UINT16_NV: out << "VK_COMPONENT_TYPE_UINT16_NV"; break;
        case VK_COMPONENT_TYPE_UINT32_NV: out << "VK_COMPONENT_TYPE_UINT32_NV"; break;
        case VK_COMPONENT_TYPE_UINT64_NV: out << "VK_COMPONENT_TYPE_UINT64_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPerformanceCounterScopeKHR& value) {
    switch (value) {
        case VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR: out << "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR"; break;
        case VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR: out << "VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR"; break;
        case VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR: out << "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPerformanceCounterUnitKHR& value) {
    switch (value) {
        case VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR"; break;
        case VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR: out << "VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPerformanceCounterStorageKHR& value) {
    switch (value) {
        case VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR: out << "VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR"; break;
        case VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR: out << "VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR"; break;
        case VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR: out << "VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR"; break;
        case VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR: out << "VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR"; break;
        case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR: out << "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR"; break;
        case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR: out << "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPerformanceConfigurationTypeINTEL& value) {
    switch (value) {
        case VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL: out << "VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkQueryPoolSamplingModeINTEL& value) {
    switch (value) {
        case VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL: out << "VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPerformanceOverrideTypeINTEL& value) {
    switch (value) {
        case VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL: out << "VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL"; break;
        case VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL: out << "VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPerformanceParameterTypeINTEL& value) {
    switch (value) {
        case VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL: out << "VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL"; break;
        case VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL: out << "VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPerformanceValueTypeINTEL& value) {
    switch (value) {
        case VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL: out << "VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL"; break;
        case VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL: out << "VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL"; break;
        case VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL: out << "VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL"; break;
        case VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL: out << "VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL"; break;
        case VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL: out << "VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkShaderFloatControlsIndependence& value) {
    switch (value) {
        case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY: out << "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY"; break;
        case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL: out << "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL"; break;
        case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE: out << "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkPipelineExecutableStatisticFormatKHR& value) {
    switch (value) {
        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR: out << "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR"; break;
        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR: out << "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR"; break;
        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR: out << "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR"; break;
        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR: out << "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkLineRasterizationModeEXT& value) {
    switch (value) {
        case VK_LINE_RASTERIZATION_MODE_DEFAULT_EXT: out << "VK_LINE_RASTERIZATION_MODE_DEFAULT_EXT"; break;
        case VK_LINE_RASTERIZATION_MODE_RECTANGULAR_EXT: out << "VK_LINE_RASTERIZATION_MODE_RECTANGULAR_EXT"; break;
        case VK_LINE_RASTERIZATION_MODE_BRESENHAM_EXT: out << "VK_LINE_RASTERIZATION_MODE_BRESENHAM_EXT"; break;
        case VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_EXT: out << "VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkFragmentShadingRateCombinerOpKHR& value) {
    switch (value) {
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR: out << "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR"; break;
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR: out << "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR"; break;
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR: out << "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR"; break;
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR: out << "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR"; break;
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR: out << "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkFragmentShadingRateNV& value) {
    switch (value) {
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV: out << "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV: out << "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV: out << "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV: out << "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV: out << "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV: out << "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV: out << "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV: out << "VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV: out << "VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV: out << "VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV: out << "VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV: out << "VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkFragmentShadingRateTypeNV& value) {
    switch (value) {
        case VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV: out << "VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV"; break;
        case VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV: out << "VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkSubpassMergeStatusEXT& value) {
    switch (value) {
        case VK_SUBPASS_MERGE_STATUS_MERGED_EXT: out << "VK_SUBPASS_MERGE_STATUS_MERGED_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT: out << "VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT"; break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT: out << "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkProvokingVertexModeEXT& value) {
    switch (value) {
        case VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT: out << "VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT"; break;
        case VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT: out << "VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
utils::io::ostream& operator<<(utils::io::ostream& out, const VkAccelerationStructureMotionInstanceTypeNV& value) {
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV: out << "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV"; break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV: out << "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV"; break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV: out << "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV"; break;
        default: out << "UNKNOWN"; break;
    }
    return out;
}
#endif


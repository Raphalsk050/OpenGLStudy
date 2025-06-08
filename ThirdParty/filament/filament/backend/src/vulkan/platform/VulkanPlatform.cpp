
#include "backend/platforms/VulkanPlatform.h"

#include <backend/DriverEnums.h>

#include "vulkan/platform/VulkanPlatformSwapChainImpl.h"
#include "vulkan/VulkanConstants.h"
#include "vulkan/VulkanDriver.h"
#include "vulkan/VulkanUtility.h"

#include <bluevk/BlueVK.h>
#include "third_party/filament/libs/utils/include/utils/PrivateImplementation-impl.h"
#include "third_party/filament/libs/utils/include/utils/Panic.h"

#define SWAPCHAIN_RET_FUNC(func, handle, ...)                                                      \
    if (mImpl->mSurfaceSwapChains.find(handle) != mImpl->mSurfaceSwapChains.end()) {               \
        return static_cast<VulkanPlatformSurfaceSwapChain*>(handle)->func(__VA_ARGS__);            \
    } else if (mImpl->mHeadlessSwapChains.find(handle) != mImpl->mHeadlessSwapChains.end()) {      \
        return static_cast<VulkanPlatformHeadlessSwapChain*>(handle)->func(__VA_ARGS__);           \
    } else {                                                                                       \
        PANIC_PRECONDITION("Bad handle for swapchain");                                            \
        return {};                                                                                 \
    }

using namespace utils;
using namespace bluevk;

namespace filament::backend {

namespace {

constexpr uint32_t const INVALID_VK_INDEX = 0xFFFFFFFF;

using ExtensionSet = VulkanPlatform::ExtensionSet;

inline bool setContains(ExtensionSet const& set, utils::CString const& extension) {
    return set.find(extension) != set.end();
};

#if FVK_ENABLED(FVK_DEBUG_VALIDATION)
// These strings need to be allocated outside a function stack
const std::string_view DESIRED_LAYERS[] = {
        "VK_LAYER_KHRONOS_validation",
#if FVK_ENABLED(FVK_DEBUG_DUMP_API)
        "VK_LAYER_LUNARG_api_dump",
#endif
#if defined(ENABLE_RENDERDOC)
        "VK_LAYER_RENDERDOC_Capture",
#endif
};

FixedCapacityVector<const char*> getEnabledLayers() {
    constexpr size_t kMaxEnabledLayersCount = sizeof(DESIRED_LAYERS) / sizeof(DESIRED_LAYERS[0]);

    const FixedCapacityVector<VkLayerProperties> availableLayers
            = filament::backend::enumerate(vkEnumerateInstanceLayerProperties);

    auto enabledLayers = FixedCapacityVector<const char*>::with_capacity(kMaxEnabledLayersCount);
    for (auto const& desired: DESIRED_LAYERS) {
        for (const VkLayerProperties& layer: availableLayers) {
            const std::string_view availableLayer(layer.layerName);
            if (availableLayer == desired) {
                enabledLayers.push_back(desired.data());
                break;
            }
        }
    }
    return enabledLayers;
}
#endif // FVK_EANBLED(FVK_DEBUG_VALIDATION)

void printDeviceInfo(VkInstance instance, VkPhysicalDevice device) {
    // Print some driver or MoltenVK information if it is available.
    if (vkGetPhysicalDeviceProperties2) {
        VkPhysicalDeviceDriverProperties driverProperties = {
                .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES,
        };
        VkPhysicalDeviceProperties2 physicalDeviceProperties2 = {
                .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2,
                .pNext = &driverProperties,
        };
        vkGetPhysicalDeviceProperties2(device, &physicalDeviceProperties2);
        FVK_LOGI << "Vulkan device driver: " << driverProperties.driverName << " "
                      << driverProperties.driverInfo << utils::io::endl;
    }

    VkPhysicalDeviceProperties deviceProperties;
    vkGetPhysicalDeviceProperties(device, &deviceProperties);

    // Print out some properties of the GPU for diagnostic purposes.
    //
    // Ideally, the vendors register their vendor ID's with Khronos so that apps can make an
    // id => string mapping. However, in practice this hasn't happened. At the time of this
    // writing the gpuinfo database has the following ID's:
    //
    //     0x1002 - AMD
    //     0x1010 - ImgTec
    //     0x10DE - NVIDIA
    //     0x13B5 - ARM
    //     0x106B - APPLE
    //     0x5143 - Qualcomm
    //     0x8086 - INTEL
    //
    // Since we don't have any vendor-specific workarounds yet, there's no need to make this
    // mapping in code. The "deviceName" string informally reveals the marketing name for the
    // GPU. (e.g., Quadro)
    const uint32_t driverVersion = deviceProperties.driverVersion;
    const uint32_t vendorID = deviceProperties.vendorID;
    const uint32_t deviceID = deviceProperties.deviceID;
    const int major = VK_VERSION_MAJOR(deviceProperties.apiVersion);
    const int minor = VK_VERSION_MINOR(deviceProperties.apiVersion);

    const FixedCapacityVector<VkPhysicalDevice> physicalDevices
            = filament::backend::enumerate(vkEnumeratePhysicalDevices, instance);

    FVK_LOGI << "Selected physical device '" << deviceProperties.deviceName << "' from "
                  << physicalDevices.size() << " physical devices. "
                  << "(vendor " << utils::io::hex << vendorID << ", "
                  << "device " << deviceID << ", "
                  << "driver " << driverVersion << ", " << utils::io::dec << "api " << major << "."
                  << minor << ")" << utils::io::endl;
}

#if FVK_ENABLED(FVK_DEBUG_VALIDATION)
void printDepthFormats(VkPhysicalDevice device) {
    // For diagnostic purposes, print useful information about available depth formats.
    // Note that Vulkan is more constrained than OpenGL ES 3.1 in this area.
    const VkFormatFeatureFlags required = VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT
                                              | VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
    FVK_LOGI << "Sampleable depth formats: ";
    for (VkFormat format : ALL_VK_FORMATS) {
        VkFormatProperties props;
        vkGetPhysicalDeviceFormatProperties(device, format, &props);
        if ((props.optimalTilingFeatures & required) == required) {
            FVK_LOGI << format << " ";
        }
    }
    FVK_LOGI << utils::io::endl;
}
#endif

ExtensionSet getInstanceExtensions(ExtensionSet const& externallyRequiredExts = {}) {
    ExtensionSet const TARGET_EXTS = {
        // Request all cross-platform extensions.
        VK_KHR_SURFACE_EXTENSION_NAME,
        VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME,

    // Request these if available.
#if FVK_ENABLED(FVK_DEBUG_DEBUG_UTILS)
        VK_EXT_DEBUG_UTILS_EXTENSION_NAME,
#endif
        VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME,

#if FVK_ENABLED(FVK_DEBUG_VALIDATION)
        VK_EXT_DEBUG_REPORT_EXTENSION_NAME,
#endif
    };
    ExtensionSet exts;
    FixedCapacityVector<VkExtensionProperties> const availableExts =
            filament::backend::enumerate(vkEnumerateInstanceExtensionProperties,
    for (auto const& extension: extensions) {
        utils::CString name { extension.extensionName };

        // To workaround an Adreno bug where the extension name could be of 0 length.
        if (name.size() == 0) {
            continue;
        }

        if (setContains(TARGET_EXTS, name)) {
            exts.insert(name);
        }
    }
    return exts;
}

VkInstance createInstance(ExtensionSet const& requiredExts) {
    VkInstance instance;
    VkInstanceCreateInfo instanceCreateInfo = {};
    bool validationFeaturesSupported = false;

#if FVK_ENABLED(FVK_DEBUG_VALIDATION)
    auto const enabledLayers = getEnabledLayers();
    if (!enabledLayers.empty()) {
        // If layers are supported, Check if VK_EXT_validation_features is supported.
        FixedCapacityVector<VkExtensionProperties> const availableValidationExts
                = filament::backend::enumerate(vkEnumerateInstanceExtensionProperties,
                        "VK_LAYER_KHRONOS_validation");
        for (auto const& extProps: availableValidationExts) {
            if (!strcmp(extProps.extensionName, VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME)) {
                validationFeaturesSupported = true;
                break;
            }
        }
        instanceCreateInfo.enabledLayerCount = (uint32_t) enabledLayers.size();
        instanceCreateInfo.ppEnabledLayerNames = enabledLayers.data();
    } else {
#if defined(__ANDROID__)
        FVK_LOGD << "Validation layers are not available; did you set jniLibs in your "
                 << "gradle file?" << utils::io::endl;
#else
        FVK_LOGD << "Validation layer not available; did you install the Vulkan SDK?\n"
                 << "Please ensure that VK_LAYER_PATH is set correctly." << utils::io::endl;
#endif // __ANDROID__

    }
#endif // FVK_ENABLED(FVK_DEBUG_VALIDATION)

    // The Platform class can require 1 or 2 instance extensions, plus we'll request at most 5
    // instance extensions here in the common code. So that's a max of 7.
    static constexpr uint32_t MAX_INSTANCE_EXTENSION_COUNT = 8;
    const char* ppEnabledExtensions[MAX_INSTANCE_EXTENSION_COUNT];
    uint32_t enabledExtensionCount = 0;

    if (validationFeaturesSupported) {
        ppEnabledExtensions[enabledExtensionCount++] = VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME;
    }
    // Request platform-specific extensions.
    for (auto const& requiredExt: requiredExts) {
        assert_invariant(enabledExtensionCount < MAX_INSTANCE_EXTENSION_COUNT);
        ppEnabledExtensions[enabledExtensionCount++] = requiredExt.data();
    }

    // Create the Vulkan instance.
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pEngineName = "Filament";
    appInfo.apiVersion
            = VK_MAKE_API_VERSION(0, FVK_REQUIRED_VERSION_MAJOR, FVK_REQUIRED_VERSION_MINOR, 0);
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;
    instanceCreateInfo.enabledExtensionCount = enabledExtensionCount;
    instanceCreateInfo.ppEnabledExtensionNames = ppEnabledExtensions;
    if (setContains(requiredExts, VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME)) {
        instanceCreateInfo.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    }

    VkValidationFeaturesEXT features = {};
    VkValidationFeatureEnableEXT enables[] = {
            VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT,
            VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT,
    };
    if (validationFeaturesSupported) {
        features.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
        features.enabledValidationFeatureCount = sizeof(enables) / sizeof(enables[0]);
        features.pEnabledValidationFeatures = enables;
        instanceCreateInfo.pNext = &features;
    }

    VkResult result = vkCreateInstance(&instanceCreateInfo, VKALLOC, &instance);
    FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS)
            << "Unable to create Vulkan instance. Result=" << result;
    return instance;
}

VkDevice createLogicalDevice(VkPhysicalDevice physicalDevice,
        VkPhysicalDeviceFeatures const& features, uint32_t graphicsQueueFamilyIndex,
        ExtensionSet const& deviceExtensions) {
    VkDevice device;
    VkDeviceQueueCreateInfo deviceQueueCreateInfo[1] = {};
    const float queuePriority[] = {1.0f};
    VkDeviceCreateInfo deviceCreateInfo = {};
    FixedCapacityVector<const char*> requestExtensions;
    requestExtensions.reserve(deviceExtensions.size() + 1);

    // TODO: We don't really need this if we only ever expect headless swapchains.
    requestExtensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
    for (auto const& ext: deviceExtensions) {
        requestExtensions.push_back(ext.data());
    }
    deviceQueueCreateInfo->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    deviceQueueCreateInfo->queueFamilyIndex = graphicsQueueFamilyIndex;
    deviceQueueCreateInfo->queueCount = 1;
    deviceQueueCreateInfo->pQueuePriorities = &queuePriority[0];
    deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceCreateInfo.queueCreateInfoCount = 1;
    deviceCreateInfo.pQueueCreateInfos = deviceQueueCreateInfo;

    // We could simply enable all supported features, but since that may have performance
    // consequences let's just enable the features we need.
    VkPhysicalDeviceFeatures enabledFeatures{
            .samplerAnisotropy = features.samplerAnisotropy,
            .textureCompressionETC2 = features.textureCompressionETC2,
            .textureCompressionBC = features.textureCompressionBC,
            .shaderClipDistance = features.shaderClipDistance,
    };

    deviceCreateInfo.pEnabledFeatures = &enabledFeatures;
    deviceCreateInfo.enabledExtensionCount = (uint32_t) requestExtensions.size();
    deviceCreateInfo.ppEnabledExtensionNames = requestExtensions.data();

    void* pNext = nullptr;
    VkPhysicalDevicePortabilitySubsetFeaturesKHR portability = {
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR,
            .pNext = nullptr,
            .imageViewFormatSwizzle = VK_TRUE,
            .mutableComparisonSamplers = VK_TRUE,
    };
    if (setContains(deviceExtensions, VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME)) {
        portability.pNext = pNext;
        pNext = &portability;
    }

    VkPhysicalDeviceMultiviewFeaturesKHR multiview = {
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR,
            .pNext = nullptr,
            .multiview = VK_TRUE,
            .multiviewGeometryShader = VK_FALSE,
            .multiviewTessellationShader = VK_FALSE
    };
    if (setContains(deviceExtensions, VK_KHR_MULTIVIEW_EXTENSION_NAME)) {
        multiview.pNext = pNext;
        pNext = &multiview;
    }

    deviceCreateInfo.pNext = pNext;

    VkResult result = vkCreateDevice(physicalDevice, &deviceCreateInfo, VKALLOC, &device);
    FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS) << "vkCreateDevice error=" << result << ".";

    return device;
}

// This method is used to enable/disable extensions based on external factors (i.e.
// driver/device workarounds).
std::tuple<ExtensionSet, ExtensionSet> pruneExtensions(VkPhysicalDevice device,
        ExtensionSet const& instExts, ExtensionSet const& deviceExts) {
    ExtensionSet newInstExts = instExts;
    ExtensionSet newDeviceExts = deviceExts;

#if FVK_ENABLED(FVK_DEBUG_DEBUG_UTILS)
    // debugUtils and debugMarkers extensions are used mutually exclusively.
    if (setContains(newInstExts, VK_EXT_DEBUG_UTILS_EXTENSION_NAME) &&
            setContains(newInstExts, VK_EXT_DEBUG_MARKER_EXTENSION_NAME)) {
        newDeviceExts.erase(VK_EXT_DEBUG_MARKER_EXTENSION_NAME);
    }
#endif

#if FVK_ENABLED(FVK_DEBUG_VALIDATION)
    // debugMarker must also request debugReport the instance extension. So check if that's present.
    if (setContains(newInstExts, VK_EXT_DEBUG_MARKER_EXTENSION_NAME) &&
            !setContains(newInstExts, VK_EXT_DEBUG_MARKER_EXTENSION_NAME)) {
        newDeviceExts.erase(VK_EXT_DEBUG_MARKER_EXTENSION_NAME);
    }
#endif

    return std::tuple(newInstExts, newDeviceExts);
}

FixedCapacityVector<VkQueueFamilyProperties> getPhysicalDeviceQueueFamilyPropertiesHelper(
        VkPhysicalDevice device) {
    uint32_t queueFamiliesCount;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamiliesCount, nullptr);
    FixedCapacityVector<VkQueueFamilyProperties> queueFamiliesProperties(queueFamiliesCount);
    if (queueFamiliesCount > 0) {
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamiliesCount,
                queueFamiliesProperties.data());
    }
    return queueFamiliesProperties;
}

uint32_t identifyGraphicsQueueFamilyIndex(VkPhysicalDevice physicalDevice) {
    const FixedCapacityVector<VkQueueFamilyProperties> queueFamiliesProperties
            = getPhysicalDeviceQueueFamilyPropertiesHelper(physicalDevice);
    uint32_t graphicsQueueFamilyIndex = INVALID_VK_INDEX;
    for (uint32_t j = 0; j < queueFamiliesProperties.size(); ++j) {
        VkQueueFamilyProperties props = queueFamiliesProperties[j];
        if (props.queueCount != 0 && props.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            graphicsQueueFamilyIndex = j;
            break;
        }
    }
    return graphicsQueueFamilyIndex;
}

// Provide a preference ordering of device types.
// Enum based on:
// https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkPhysicalDeviceType.html
inline int deviceTypeOrder(VkPhysicalDeviceType deviceType) {
    switch (deviceType) {
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            return 5;
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
            return 4;
        case VK_PHYSICAL_DEVICE_TYPE_CPU:
            return 3;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            return 2;
        case VK_PHYSICAL_DEVICE_TYPE_OTHER:
            return 1;
        default:
            FVK_LOGW << "deviceTypeOrder: Unexpected deviceType: " << deviceType
                     << utils::io::endl;
            return -1;
    }
}

VkPhysicalDevice selectPhysicalDevice(VkInstance instance,
        VulkanPlatform::Customization::GPUPreference const& gpuPreference) {
    FixedCapacityVector<VkPhysicalDevice> const physicalDevices =
            filament::backend::enumerate(vkEnumeratePhysicalDevices, instance);
    struct DeviceInfo {
        VkPhysicalDevice device = VK_NULL_HANDLE;
        VkPhysicalDeviceType deviceType = VK_PHYSICAL_DEVICE_TYPE_OTHER;
        int8_t index = -1;
        std::string_view name;
    };
    FixedCapacityVector<DeviceInfo> deviceList(physicalDevices.size());

    for (size_t deviceInd = 0; deviceInd < physicalDevices.size(); ++deviceInd) {
        auto const candidateDevice = physicalDevices[deviceInd];
        VkPhysicalDeviceProperties targetDeviceProperties;
        vkGetPhysicalDeviceProperties(candidateDevice, &targetDeviceProperties);

        int const major = VK_VERSION_MAJOR(targetDeviceProperties.apiVersion);
        int const minor = VK_VERSION_MINOR(targetDeviceProperties.apiVersion);

        // Does the device support the required Vulkan level?
        if (major < FVK_REQUIRED_VERSION_MAJOR) {
            continue;
        }
        if (major == FVK_REQUIRED_VERSION_MAJOR && minor < FVK_REQUIRED_VERSION_MINOR) {
            continue;
        }

        // Does the device have any command queues that support graphics?
        // In theory, we should also ensure that the device supports presentation of our
        // particular VkSurface, but we don't have a VkSurface yet, so we'll skip this requirement.
        if (identifyGraphicsQueueFamilyIndex(candidateDevice) == INVALID_VK_INDEX) {
            continue;
        }

        // Does the device support the VK_KHR_swapchain extension?
        FixedCapacityVector<VkExtensionProperties> const extensions
                = filament::backend::enumerate(vkEnumerateDeviceExtensionProperties,

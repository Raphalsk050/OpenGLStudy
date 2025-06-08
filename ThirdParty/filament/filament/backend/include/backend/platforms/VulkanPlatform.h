
#ifndef TNT_FILAMENT_BACKEND_PLATFORMS_VULKANPLATFORM_H
#define TNT_FILAMENT_BACKEND_PLATFORMS_VULKANPLATFORM_H

#include <backend/Platform.h>

#include <bluevk/BlueVK.h>

#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/Hash.h"
#include "third_party/filament/libs/utils/include/utils/PrivateImplementation.h"

#include <tuple>
#include <unordered_set>

#include <stddef.h>
#include <stdint.h>

namespace filament::backend {

using SwapChain = Platform::SwapChain;

struct VulkanPlatformPrivate;

class VulkanPlatform : public Platform, utils::PrivateImplementation<VulkanPlatformPrivate> {
public:

    struct ExtensionHashFn {
        std::size_t operator()(utils::CString const& s) const noexcept {
            return std::hash<std::string>{}(s.data());
        }
    };
    // Utility for managing device or instance extensions during initialization.
    using ExtensionSet = std::unordered_set<utils::CString, ExtensionHashFn>;

    struct VulkanSharedContext {
        VkInstance instance = VK_NULL_HANDLE;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkDevice logicalDevice = VK_NULL_HANDLE;
        uint32_t graphicsQueueFamilyIndex = 0xFFFFFFFF;
        // In the usual case, the client needs to allocate at least one more graphics queue
        // for Filament, and this index is the param to pass into vkGetDeviceQueue. In the case
        // where the gpu only has one graphics queue. Then the client needs to ensure that no
        // concurrent access can occur.
        uint32_t graphicsQueueIndex = 0xFFFFFFFF;
    };

    using SwapChainPtr = Platform::SwapChain*;

    struct SwapChainBundle {
        utils::FixedCapacityVector<VkImage> colors;
        VkImage depth = VK_NULL_HANDLE;
        VkFormat colorFormat = VK_FORMAT_UNDEFINED;
        VkFormat depthFormat = VK_FORMAT_UNDEFINED;
        VkExtent2D extent = {0, 0};
    };

    struct ImageSyncData {
        static constexpr uint32_t INVALID_IMAGE_INDEX = UINT32_MAX;

        // The index of the next image as returned by vkAcquireNextImage or equivalent.
        uint32_t imageIndex = INVALID_IMAGE_INDEX;

        // Semaphore to be signaled once the image is available.
        VkSemaphore imageReadySemaphore = VK_NULL_HANDLE;

        // A function called right before vkQueueSubmit. After this call, the image must be 
        // available. This pointer can be null if imageReadySemaphore is not VK_NULL_HANDLE.
        std::function<void(SwapChainPtr handle)> explicitImageReadyWait = nullptr;
    };

    VulkanPlatform();

    ~VulkanPlatform() override;

    Driver* createDriver(void* sharedContext,
            Platform::DriverConfig const& driverConfig) noexcept override;

    int getOSVersion() const noexcept override {
        return 0;
    }

    // ----------------------------------------------------
    // ---------- Platform Customization options ----------
    struct Customization {
        struct GPUPreference {
            utils::CString deviceName;
            int8_t index = -1;
        } gpu;

        bool isSRGBSwapChainSupported = true;

        bool flushAndWaitOnWindowResize = true;

        bool transitionSwapChainImageLayoutForPresent = true;
    };

    virtual Customization getCustomization() const noexcept {
        return {};
    }

    // -------- End platform customization options --------
    // ----------------------------------------------------

    virtual SwapChainBundle getSwapChainBundle(SwapChainPtr handle);

    virtual VkResult acquire(SwapChainPtr handle, ImageSyncData* outImageSyncData);

    virtual VkResult present(SwapChainPtr handle, uint32_t index, VkSemaphore finishedDrawing);

    virtual bool hasResized(SwapChainPtr handle);

    virtual VkResult recreate(SwapChainPtr handle);

    virtual SwapChainPtr createSwapChain(void* nativeWindow, uint64_t flags = 0,
            VkExtent2D extent = {0, 0});

    virtual ExtensionSet getRequiredInstanceExtensions() { return {}; }

    virtual void destroy(SwapChainPtr handle);

    virtual void terminate();

    VkInstance getInstance() const noexcept;

    VkDevice getDevice() const noexcept;

    VkPhysicalDevice getPhysicalDevice() const noexcept;

    uint32_t getGraphicsQueueFamilyIndex() const noexcept;

    uint32_t getGraphicsQueueIndex() const noexcept;

    VkQueue getGraphicsQueue() const noexcept;

private:
    static ExtensionSet getSwapchainInstanceExtensions();

    // Platform dependent helper methods
    using SurfaceBundle = std::tuple<VkSurfaceKHR, VkExtent2D>;
    static SurfaceBundle createVkSurfaceKHR(void* nativeWindow, VkInstance instance,
            uint64_t flags) noexcept;

    friend struct VulkanPlatformPrivate;
};

}// namespace filament::backend

#endif// TNT_FILAMENT_BACKEND_PLATFORMS_VULKANPLATFORM_H

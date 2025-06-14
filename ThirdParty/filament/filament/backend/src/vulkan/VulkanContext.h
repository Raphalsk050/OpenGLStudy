
#ifndef TNT_FILAMENT_BACKEND_VULKANCONTEXT_H
#define TNT_FILAMENT_BACKEND_VULKANCONTEXT_H

#include "VulkanConstants.h"
#include "VulkanImageUtility.h"
#include "VulkanUtility.h"

#include "third_party/filament/libs/utils/include/utils/bitset.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"
#include "third_party/filament/libs/utils/include/utils/Slice.h"

#include <memory>

VK_DEFINE_HANDLE(VmaAllocator)
VK_DEFINE_HANDLE(VmaPool)

namespace filament::backend {

struct VulkanRenderTarget;
struct VulkanSwapChain;
struct VulkanTexture;
class VulkanStagePool;
struct VulkanTimerQuery;
struct VulkanCommandBuffer;

struct VulkanAttachment {
    VulkanTexture* texture = nullptr;
    uint8_t level = 0;
    uint16_t layer = 0;

    bool isDepth() const;
    VkImage getImage() const;
    VkFormat getFormat() const;
    VulkanLayout getLayout() const;
    VkExtent2D getExtent2D() const;
    VkImageView getImageView();
    // TODO: maybe embed aspect into the attachment or texture itself.
    VkImageSubresourceRange getSubresourceRange() const;
};

class VulkanTimestamps {
public:
    using QueryResult = std::array<uint64_t, 4>;

    VulkanTimestamps(VkDevice device);
    ~VulkanTimestamps();

    // Not copy-able.
    VulkanTimestamps(VulkanTimestamps const&) = delete;
    VulkanTimestamps& operator=(VulkanTimestamps const&) = delete;

    std::tuple<uint32_t, uint32_t> getNextQuery();
    void clearQuery(uint32_t queryIndex);

    void beginQuery(VulkanCommandBuffer const* commands, VulkanTimerQuery* query);
    void endQuery(VulkanCommandBuffer const* commands, VulkanTimerQuery const* query);
    QueryResult getResult(VulkanTimerQuery const* query);

private:
    VkDevice mDevice;
    VkQueryPool mPool;
    utils::bitset32 mUsed;
    utils::Mutex mMutex;
};

struct VulkanRenderPass {
    VulkanRenderTarget* renderTarget;
    VkRenderPass renderPass;
    RenderPassParams params;
    int currentSubpass;
};

// This is a collection of immutable data about the vulkan context. This actual handles to the
// context are stored in VulkanPlatform.
struct VulkanContext {
public:
    inline uint32_t selectMemoryType(uint32_t flags, VkFlags reqs) const {
        for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; i++) {
            if (flags & 1) {
                if ((mMemoryProperties.memoryTypes[i].propertyFlags & reqs) == reqs) {
                    return i;
                }
            }
            flags >>= 1;
        }
        return (uint32_t) VK_MAX_MEMORY_TYPES;
    }

    inline VkFormatList const& getAttachmentDepthStencilFormats() const {
        return mDepthStencilFormats;
    }

    inline VkFormatList const& getBlittableDepthStencilFormats() const {
        return mBlittableDepthStencilFormats;
    }

    inline VkPhysicalDeviceLimits const& getPhysicalDeviceLimits() const noexcept {
        return mPhysicalDeviceProperties.limits;
    }

    inline uint32_t getPhysicalDeviceVendorId() const noexcept {
        return mPhysicalDeviceProperties.vendorID;
    }

    inline bool isImageCubeArraySupported() const noexcept {
        return mPhysicalDeviceFeatures.imageCubeArray == VK_TRUE;
    }

    inline bool isDebugMarkersSupported() const noexcept {
        return mDebugMarkersSupported;
    }

    inline bool isDebugUtilsSupported() const noexcept {
        return mDebugUtilsSupported;
    }

    inline bool isMultiviewEnabled() const noexcept {
        return mMultiviewEnabled;
    }

    inline bool isClipDistanceSupported() const noexcept {
        return mPhysicalDeviceFeatures.shaderClipDistance == VK_TRUE;
    }

private:
    VkPhysicalDeviceMemoryProperties mMemoryProperties = {};
    VkPhysicalDeviceProperties mPhysicalDeviceProperties = {};
    VkPhysicalDeviceFeatures mPhysicalDeviceFeatures = {};
    bool mDebugMarkersSupported = false;
    bool mDebugUtilsSupported = false;
    bool mMultiviewEnabled = false;

    VkFormatList mDepthStencilFormats;
    VkFormatList mBlittableDepthStencilFormats;

    // For convenience so that VulkanPlatform can initialize the private fields.
    friend class VulkanPlatform;
};

}// namespace filament::backend

#endif// TNT_FILAMENT_BACKEND_VULKANCONTEXT_H

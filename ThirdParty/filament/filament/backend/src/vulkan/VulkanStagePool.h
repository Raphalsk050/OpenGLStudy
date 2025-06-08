
#ifndef TNT_FILAMENT_BACKEND_VULKANSTAGEPOOL_H
#define TNT_FILAMENT_BACKEND_VULKANSTAGEPOOL_H

#include "VulkanCommands.h"
#include "VulkanContext.h"
#include "VulkanMemory.h"

#include <map>
#include <unordered_set>

namespace filament::backend {

// Immutable POD representing a shared CPU-GPU staging area.
struct VulkanStage {
    VmaAllocation memory;
    VkBuffer buffer;
    uint32_t capacity;
    mutable uint64_t lastAccessed;
};

struct VulkanStageImage {
    VkFormat format;
    uint32_t width;
    uint32_t height;
    mutable uint64_t lastAccessed;
    VmaAllocation memory;
    VkImage image;
};

// Manages a pool of stages, periodically releasing stages that have been unused for a while.
// This class manages two types of host-mappable staging areas: buffer stages and image stages.
class VulkanStagePool {
public:
    VulkanStagePool(VmaAllocator allocator, VulkanCommands* commands);

    // Finds or creates a stage whose capacity is at least the given number of bytes.
    // The stage is automatically released back to the pool after TIME_BEFORE_EVICTION frames.
    VulkanStage const* acquireStage(uint32_t numBytes);

    // Images have VK_IMAGE_LAYOUT_GENERAL and must not be transitioned to any other layout
    VulkanStageImage const* acquireImage(PixelDataFormat format, PixelDataType type,
            uint32_t width, uint32_t height);

    // Evicts old unused stages and bumps the current frame number.
    void gc() noexcept;

    // Destroys all unused stages and asserts that there are no stages currently in use.
    // This should be called while the context's VkDevice is still alive.
    void terminate() noexcept;

private:
    VmaAllocator mAllocator;
    VulkanCommands* mCommands;

    // Use an ordered multimap for quick (capacity => stage) lookups using lower_bound().
    std::multimap<uint32_t, VulkanStage const*> mFreeStages;

    // Simple unordered set for stashing a list of in-use stages that can be reclaimed later.
    std::unordered_set<VulkanStage const*> mUsedStages;

    std::unordered_set<VulkanStageImage const*> mFreeImages;
    std::unordered_set<VulkanStageImage const*> mUsedImages;

    // Store the current "time" (really just a frame count) and LRU eviction parameters.
    uint64_t mCurrentFrame = 0;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_VULKANSTAGEPOOL_H

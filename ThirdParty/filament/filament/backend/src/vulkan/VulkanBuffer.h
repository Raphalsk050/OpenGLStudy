
#ifndef TNT_FILAMENT_BACKEND_VULKANBUFFER_H
#define TNT_FILAMENT_BACKEND_VULKANBUFFER_H

#include "VulkanContext.h"
#include "VulkanStagePool.h"
#include "VulkanMemory.h"

namespace filament::backend {

// Encapsulates a Vulkan buffer, its attached DeviceMemory and a staging area.
class VulkanBuffer {
public:
    VulkanBuffer(VmaAllocator allocator, VulkanStagePool& stagePool, VkBufferUsageFlags usage,
            uint32_t numBytes);
    ~VulkanBuffer();
    void loadFromCpu(VkCommandBuffer cmdbuf, const void* cpuData, uint32_t byteOffset,
            uint32_t numBytes);
    VkBuffer getGpuBuffer() const {
        return mGpuBuffer;
    }

private:
    VmaAllocator mAllocator;
    VulkanStagePool& mStagePool;

    VmaAllocation mGpuMemory = VK_NULL_HANDLE;
    VkBuffer mGpuBuffer = VK_NULL_HANDLE;
    VkBufferUsageFlags mUsage = {};
    uint32_t mUpdatedBytes = 0;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_VULKANBUFFER_H

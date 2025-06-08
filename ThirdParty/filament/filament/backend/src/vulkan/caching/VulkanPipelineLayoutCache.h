
#ifndef TNT_FILAMENT_BACKEND_VULKANPIPELINELAYOUTCACHE_H
#define TNT_FILAMENT_BACKEND_VULKANPIPELINELAYOUTCACHE_H

#include <vulkan/VulkanHandles.h>
#include <bluevk/BlueVK.h>

#include "third_party/filament/libs/utils/include/utils/Hash.h"

#include "robin_map/include/tsl/robin_map.h"

namespace filament::backend {

class VulkanPipelineLayoutCache {
public:
    VulkanPipelineLayoutCache(VkDevice device, VulkanResourceAllocator* allocator)
        : mDevice(device),
          mAllocator(allocator),
          mTimestamp(0) {}

    void terminate() noexcept;

    struct PushConstantKey {
        uint8_t stage;// We have one set of push constant per shader stage (fragment, vertex, etc).
        uint8_t size;
        // Note that there is also an offset parameter for push constants, but
        // we always assume our update range will have the offset 0.
    };

    struct PipelineLayoutKey {
        using DescriptorSetLayoutArray = std::array<VkDescriptorSetLayout,
                VulkanDescriptorSetLayout::UNIQUE_DESCRIPTOR_SET_COUNT>;
        DescriptorSetLayoutArray descSetLayouts = {};                   // 8 * 3
        PushConstantKey pushConstant[Program::SHADER_TYPE_COUNT] = {};  // 2 * 3
        uint16_t padding = 0;
    };
    static_assert(sizeof(PipelineLayoutKey) == 32);

    VulkanPipelineLayoutCache(VulkanPipelineLayoutCache const&) = delete;
    VulkanPipelineLayoutCache& operator=(VulkanPipelineLayoutCache const&) = delete;

    // A pipeline layout depends on the descriptor set layout and the push constant ranges, which
    // are described in the program.
    VkPipelineLayout getLayout(VulkanDescriptorSetLayoutList const& descriptorSetLayouts,
            VulkanProgram* program);

private:
    using Timestamp = uint64_t;
    struct PipelineLayoutCacheEntry {
        VkPipelineLayout handle;
        Timestamp lastUsed;
    };

    using PipelineLayoutKeyHashFn = utils::hash::MurmurHashFn<PipelineLayoutKey>;
    struct PipelineLayoutKeyEqual {
        bool operator()(PipelineLayoutKey const& k1, PipelineLayoutKey const& k2) const {
            return 0 == memcmp((const void*) &k1, (const void*) &k2, sizeof(PipelineLayoutKey));
        }
    };

    using PipelineLayoutMap = tsl::robin_map<PipelineLayoutKey, PipelineLayoutCacheEntry,
            PipelineLayoutKeyHashFn, PipelineLayoutKeyEqual>;

    VkDevice mDevice;
    VulkanResourceAllocator* mAllocator;
    Timestamp mTimestamp;
    PipelineLayoutMap mPipelineLayouts;
};

}

#endif // TNT_FILAMENT_BACKEND_VULKANPIPELINECACHE_H

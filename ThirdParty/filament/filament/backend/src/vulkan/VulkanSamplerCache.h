
#ifndef TNT_FILAMENT_BACKEND_VULKANSAMPLERCACHE_H
#define TNT_FILAMENT_BACKEND_VULKANSAMPLERCACHE_H

#include "VulkanContext.h"
#include "VulkanUtility.h"

#include "robin_map/include/tsl/robin_map.h"

namespace filament::backend {

// Simple manager for VkSampler objects.
class VulkanSamplerCache {
public:
    explicit VulkanSamplerCache(VkDevice device);
    VkSampler getSampler(SamplerParams params) noexcept;
    void terminate() noexcept;
private:
    VkDevice mDevice;
    tsl::robin_map<SamplerParams, VkSampler, SamplerParams::Hasher, SamplerParams::EqualTo> mCache;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_VULKANSAMPLERCACHE_H

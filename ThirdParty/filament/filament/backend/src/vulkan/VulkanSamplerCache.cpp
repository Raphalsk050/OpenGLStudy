
#include "vulkan/VulkanSamplerCache.h"

#include "third_party/filament/libs/utils/include/utils/Panic.h"

using namespace bluevk;

namespace filament::backend {

constexpr inline VkSamplerAddressMode getWrapMode(SamplerWrapMode mode) noexcept {
    switch (mode) {
        case SamplerWrapMode::REPEAT:
            return VK_SAMPLER_ADDRESS_MODE_REPEAT;
        case SamplerWrapMode::CLAMP_TO_EDGE:
            return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
        case SamplerWrapMode::MIRRORED_REPEAT:
            return VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT;
    }
}

constexpr inline VkFilter getFilter(SamplerMinFilter filter) noexcept {
    switch (filter) {
        case SamplerMinFilter::NEAREST:
            return VK_FILTER_NEAREST;
        case SamplerMinFilter::LINEAR:
            return VK_FILTER_LINEAR;
        case SamplerMinFilter::NEAREST_MIPMAP_NEAREST:
            return VK_FILTER_NEAREST;
        case SamplerMinFilter::LINEAR_MIPMAP_NEAREST:
            return VK_FILTER_LINEAR;
        case SamplerMinFilter::NEAREST_MIPMAP_LINEAR:
            return VK_FILTER_NEAREST;
        case SamplerMinFilter::LINEAR_MIPMAP_LINEAR:
            return VK_FILTER_LINEAR;
    }
}

constexpr inline VkFilter getFilter(SamplerMagFilter filter) noexcept {
    switch (filter) {
        case SamplerMagFilter::NEAREST:
            return VK_FILTER_NEAREST;
        case SamplerMagFilter::LINEAR:
            return VK_FILTER_LINEAR;
    }
}

constexpr inline VkSamplerMipmapMode getMipmapMode(SamplerMinFilter filter) noexcept {
    switch (filter) {
        case SamplerMinFilter::NEAREST:
            return VK_SAMPLER_MIPMAP_MODE_NEAREST;
        case SamplerMinFilter::LINEAR:
            return VK_SAMPLER_MIPMAP_MODE_NEAREST;
        case SamplerMinFilter::NEAREST_MIPMAP_NEAREST:
            return VK_SAMPLER_MIPMAP_MODE_NEAREST;
        case SamplerMinFilter::LINEAR_MIPMAP_NEAREST:
            return VK_SAMPLER_MIPMAP_MODE_NEAREST;
        case SamplerMinFilter::NEAREST_MIPMAP_LINEAR:
            return VK_SAMPLER_MIPMAP_MODE_LINEAR;
        case SamplerMinFilter::LINEAR_MIPMAP_LINEAR:
            return VK_SAMPLER_MIPMAP_MODE_LINEAR;
    }
}

constexpr inline float getMaxLod(SamplerMinFilter filter) noexcept {
    switch (filter) {
        case SamplerMinFilter::NEAREST:
        case SamplerMinFilter::LINEAR:
            // The Vulkan spec recommends a max LOD of 0.25 to "disable" mipmapping.
            // See "Mapping of OpenGL to Vulkan filter modes" in the VK Spec.
            return 0.25f;
        case SamplerMinFilter::NEAREST_MIPMAP_NEAREST:
        case SamplerMinFilter::LINEAR_MIPMAP_NEAREST:
        case SamplerMinFilter::NEAREST_MIPMAP_LINEAR:
        case SamplerMinFilter::LINEAR_MIPMAP_LINEAR:
            return VK_LOD_CLAMP_NONE;
    }
}

constexpr inline VkBool32 getCompareEnable(SamplerCompareMode mode) noexcept {
    return mode == SamplerCompareMode::NONE ? VK_FALSE : VK_TRUE;
}

VulkanSamplerCache::VulkanSamplerCache(VkDevice device)
    : mDevice(device) {}

VkSampler VulkanSamplerCache::getSampler(SamplerParams params) noexcept {
    auto iter = mCache.find(params);
    if (UTILS_LIKELY(iter != mCache.end())) {
        return iter->second;
    }
    VkSamplerCreateInfo samplerInfo {
        .sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
        .magFilter = getFilter(params.filterMag),
        .minFilter = getFilter(params.filterMin),
        .mipmapMode = getMipmapMode(params.filterMin),
        .addressModeU = getWrapMode(params.wrapS),
        .addressModeV = getWrapMode(params.wrapT),
        .addressModeW = getWrapMode(params.wrapR),
        .anisotropyEnable = params.anisotropyLog2 == 0 ? 0u : 1u,
        .maxAnisotropy = (float)(1u << params.anisotropyLog2),
        .compareEnable = getCompareEnable(params.compareMode),
        .compareOp = getCompareOp(params.compareFunc),
        .minLod = 0.0f,
        .maxLod = getMaxLod(params.filterMin),
        .borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK,
        .unnormalizedCoordinates = VK_FALSE
    };
    VkSampler sampler;
    VkResult error = vkCreateSampler(mDevice, &samplerInfo, VKALLOC, &sampler);
    FILAMENT_CHECK_POSTCONDITION(!error) << "Unable to create sampler.";
    mCache.insert({params, sampler});
    return sampler;
}

void VulkanSamplerCache::terminate() noexcept {
    for (auto pair : mCache) {
        vkDestroySampler(mDevice, pair.second, VKALLOC);
    }
    mCache.clear();
}

} // namespace filament::backend

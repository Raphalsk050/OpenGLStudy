
#ifndef TNT_FILAMENT_BACKEND_VULKANHANDLES_H
#define TNT_FILAMENT_BACKEND_VULKANHANDLES_H

// This needs to be at the top
#include "DriverBase.h"

#include "VulkanBuffer.h"
#include "VulkanResources.h"
#include "VulkanSwapChain.h"
#include "VulkanTexture.h"
#include "VulkanUtility.h"

#include <private/backend/SamplerGroup.h>
#include <backend/Program.h>

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"
#include "third_party/filament/libs/utils/include/utils/StructureOfArrays.h"

namespace filament::backend {

using namespace descset;

class VulkanTimestamps;

struct VulkanDescriptorSetLayout : public VulkanResource {
    static constexpr uint8_t UNIQUE_DESCRIPTOR_SET_COUNT = 3;

    // The bitmask representation of a set layout.
    struct Bitmask {
        UniformBufferBitmask ubo = 0;         // 4 bytes
        UniformBufferBitmask dynamicUbo = 0;  // 4 bytes
        SamplerBitmask sampler = 0;           // 8 bytes
        InputAttachmentBitmask inputAttachment = 0; // 1 bytes

        // Because we're using this struct as hash key, must make it's 8-bytes aligned, with no
        // unaccounted bytes.
        uint8_t padding0 = 0; // 1 bytes
        uint16_t padding1 = 0;// 2 bytes
        uint32_t padding2 = 0;// 4 bytes

        bool operator==(Bitmask const& right) const {
            return ubo == right.ubo && dynamicUbo == right.dynamicUbo && sampler == right.sampler &&
                   inputAttachment == right.inputAttachment;
        }

        static Bitmask fromBackendLayout(descset::DescriptorSetLayout const& layout);
    };

    // This is a convenience struct to quickly check layout compatibility in terms of descriptor set
    // pools.
    struct Count {
        uint32_t ubo = 0;
        uint32_t dynamicUbo = 0;
        uint32_t sampler = 0;
        uint32_t inputAttachment = 0;

        bool operator==(Count const& right) const noexcept {
            return ubo == right.ubo && dynamicUbo == right.dynamicUbo && sampler == right.sampler &&
                   inputAttachment == right.inputAttachment;
        }

        static inline Count fromLayoutBitmask(Bitmask const& mask) {
            return {
                    .ubo = countBits(collapseStages(mask.ubo)),
                    .dynamicUbo = countBits(collapseStages(mask.dynamicUbo)),
                    .sampler = countBits(collapseStages(mask.sampler)),
                    .inputAttachment = countBits(collapseStages(mask.inputAttachment)),
            };
        }

        Count operator*(uint16_t mult) const noexcept {
            // TODO: check for overflow.

            Count ret;
            ret.ubo = ubo * mult;
            ret.dynamicUbo = dynamicUbo * mult;
            ret.sampler = sampler * mult;
            ret.inputAttachment = inputAttachment * mult;
            return ret;
        }
    };

    static_assert(sizeof(Bitmask) % 8 == 0);

    explicit VulkanDescriptorSetLayout(VkDevice device, VkDescriptorSetLayoutCreateInfo const& info,
            Bitmask const& bitmask);

    ~VulkanDescriptorSetLayout();

    VkDevice const mDevice;
    VkDescriptorSetLayout const vklayout;
    Bitmask const bitmask;

    // This is a convenience struct so that we don't have to iterate through all the bits of the
    // bitmask (which correspondings to binding indices).
    struct _Bindings {
        utils::FixedCapacityVector<uint8_t> const ubo;
        utils::FixedCapacityVector<uint8_t> const dynamicUbo;
        utils::FixedCapacityVector<uint8_t> const sampler;
        utils::FixedCapacityVector<uint8_t> const inputAttachment;
    } bindings;

    Count const count;

private:

    template <typename MaskType>
    utils::FixedCapacityVector<uint8_t> bits(MaskType mask) {
        utils::FixedCapacityVector<uint8_t> ret =
                utils::FixedCapacityVector<uint8_t>::with_capacity(countBits(mask));
        for (uint8_t i = 0; i < sizeof(mask) * 4; ++i) {
            if (mask & (1 << i)) {
                ret.push_back(i);
            }
        }
        return ret;
    }

    _Bindings getBindings(Bitmask const& bitmask) {
        auto const uboCollapsed = collapseStages(bitmask.ubo);
        auto const dynamicUboCollapsed = collapseStages(bitmask.dynamicUbo);
        auto const samplerCollapsed = collapseStages(bitmask.sampler);
        auto const inputAttachmentCollapsed = collapseStages(bitmask.inputAttachment);
        return {
            bits(uboCollapsed),
            bits(dynamicUboCollapsed),
            bits(samplerCollapsed),
            bits(inputAttachmentCollapsed),
        };
    }
};

using VulkanDescriptorSetLayoutList = std::array<Handle<VulkanDescriptorSetLayout>,
        VulkanDescriptorSetLayout::UNIQUE_DESCRIPTOR_SET_COUNT>;

struct VulkanDescriptorSet : public VulkanResource {
public:
    // Because we need to recycle descriptor sets not used, we allow for a callback that the "Pool"
    // can use to repackage the vk handle.
    using OnRecycle = std::function<void()>;

    VulkanDescriptorSet(VulkanResourceAllocator* allocator,
            VkDescriptorSet rawSet, OnRecycle&& onRecycleFn)
        : VulkanResource(VulkanResourceType::DESCRIPTOR_SET),
          resources(allocator),
          vkSet(rawSet),
          mOnRecycleFn(std::move(onRecycleFn)) {}

    ~VulkanDescriptorSet() {
        if (mOnRecycleFn) {
            mOnRecycleFn();
        }
    }

    // TODO: maybe change to fixed size for performance.
    VulkanAcquireOnlyResourceManager resources;
    VkDescriptorSet const vkSet;

private:
    OnRecycle mOnRecycleFn;
};

using VulkanDescriptorSetList = std::array<Handle<VulkanDescriptorSet>,
        VulkanDescriptorSetLayout::UNIQUE_DESCRIPTOR_SET_COUNT>;

using PushConstantNameArray = utils::FixedCapacityVector<char const*>;
using PushConstantNameByStage = std::array<PushConstantNameArray, Program::SHADER_TYPE_COUNT>;

struct PushConstantDescription {

    explicit PushConstantDescription(backend::Program const& program) noexcept;

    VkPushConstantRange const* getVkRanges() const noexcept { return mRanges; }

    uint32_t getVkRangeCount() const noexcept { return mRangeCount; }

    void write(VulkanCommands* commands, VkPipelineLayout layout, backend::ShaderStage stage,
            uint8_t index, backend::PushConstantVariant const& value);

private:
    static constexpr uint32_t ENTRY_SIZE = sizeof(uint32_t);

    utils::FixedCapacityVector<backend::ConstantType> mTypes[Program::SHADER_TYPE_COUNT];
    VkPushConstantRange mRanges[Program::SHADER_TYPE_COUNT];
    uint32_t mRangeCount;
};

struct VulkanProgram : public HwProgram, VulkanResource {

    using BindingList = CappedArray<uint16_t, MAX_SAMPLER_COUNT>;

    VulkanProgram(VkDevice device, Program const& builder) noexcept;

    ~VulkanProgram();

    inline VkShaderModule getVertexShader() const {
        return mInfo->shaders[0];
    }

    inline VkShaderModule getFragmentShader() const { return mInfo->shaders[1]; }

    inline utils::FixedCapacityVector<uint16_t> const& getBindingToSamplerIndex() const {
        return mInfo->bindingToSamplerIndex;
    }

    // Get a list of the sampler binding indices so that we don't have to loop through all possible
    // samplers.
    inline BindingList const& getBindings() const { return mInfo->bindings; }

    // TODO: this is currently not used. This will replace getLayoutDescriptionList below.
    // inline descset::DescriptorSetLayout const& getLayoutDescription() const {
    //    return mInfo->layout;
    // }
    // In the usual case, we would have just one layout per program. But in the current setup, we
    // have a set/layout for each descriptor type. This will be changed in the future.
    using LayoutDescriptionList = std::array<descset::DescriptorSetLayout,
            VulkanDescriptorSetLayout::UNIQUE_DESCRIPTOR_SET_COUNT>;
    inline LayoutDescriptionList const& getLayoutDescriptionList() const { return mInfo->layouts; }

    inline uint32_t getPushConstantRangeCount() const {
        return mInfo->pushConstantDescription.getVkRangeCount();
    }

    inline VkPushConstantRange const* getPushConstantRanges() const {
        return mInfo->pushConstantDescription.getVkRanges();
    }

    inline void writePushConstant(VulkanCommands* commands, VkPipelineLayout layout,
            backend::ShaderStage stage, uint8_t index, backend::PushConstantVariant const& value) {
        mInfo->pushConstantDescription.write(commands, layout, stage, index, value);
    }

#if FVK_ENABLED_DEBUG_SAMPLER_NAME
    inline utils::FixedCapacityVector<std::string> const& getBindingToName() const {
        return mInfo->bindingToName;
    }
#endif

    // TODO: handle compute shaders.
    // The expected order of shaders - from frontend to backend - is vertex, fragment, compute.
    static constexpr uint8_t const MAX_SHADER_MODULES = 2;

private:
    struct PipelineInfo {
        explicit PipelineInfo(backend::Program const& program) noexcept
            : bindingToSamplerIndex(MAX_SAMPLER_COUNT, 0xffff),
              pushConstantDescription(program)
#if FVK_ENABLED_DEBUG_SAMPLER_NAME
            , bindingToName(MAX_SAMPLER_COUNT, "")
#endif
            {}

        BindingList bindings;

        // We store the samplerGroupIndex as the top 8-bit and the index within each group as the lower 8-bit.
        utils::FixedCapacityVector<uint16_t> bindingToSamplerIndex;
        VkShaderModule shaders[MAX_SHADER_MODULES] = { VK_NULL_HANDLE };

        // TODO: Use this instead of `layouts` after Filament-side Descriptor Set API is in place.
        // descset::DescriptorSetLayout layout;
        LayoutDescriptionList layouts;

        PushConstantDescription pushConstantDescription;

#if FVK_ENABLED_DEBUG_SAMPLER_NAME
        // We store the sampler name mapped from binding index (only for debug purposes).
        utils::FixedCapacityVector<std::string> bindingToName;
#endif

    };

    PipelineInfo* mInfo;
    VkDevice mDevice = VK_NULL_HANDLE;
};

// The render target bundles together a set of attachments, each of which can have one of the
// following ownership semantics:
//
// - The attachment's VkImage is shared and the owner is VulkanSwapChain (mOffscreen = false).
// - The attachment's VkImage is shared and the owner is VulkanTexture   (mOffscreen = true).
//
// We use private inheritance to shield clients from the width / height fields in HwRenderTarget,
// which are not representative when this is the default render target.
struct VulkanRenderTarget : private HwRenderTarget, VulkanResource {
    // Creates an offscreen render target.
    VulkanRenderTarget(VkDevice device, VkPhysicalDevice physicalDevice,
            VulkanContext const& context, VmaAllocator allocator,
            VulkanCommands* commands, uint32_t width, uint32_t height,
            uint8_t samples, VulkanAttachment color[MRT::MAX_SUPPORTED_RENDER_TARGET_COUNT],
            VulkanAttachment depthStencil[2], VulkanStagePool& stagePool);

    // Creates a special "default" render target (i.e. associated with the swap chain)
    explicit VulkanRenderTarget();

    void transformClientRectToPlatform(VkRect2D* bounds) const;
    void transformClientRectToPlatform(VkViewport* bounds) const;
    VkExtent2D getExtent() const;
    // We return references in the following methods to avoid a copy.
    VulkanAttachment& getColor(int target);
    VulkanAttachment& getMsaaColor(int target);
    VulkanAttachment& getDepth();
    VulkanAttachment& getMsaaDepth();
    uint8_t getColorTargetCount(const VulkanRenderPass& pass) const;
    uint8_t getSamples() const { return mSamples; }
    bool hasDepth() const { return mDepth.texture; }
    bool isSwapChain() const { return !mOffscreen; }
    void bindToSwapChain(VulkanSwapChain& surf);

private:
    VulkanAttachment mColor[MRT::MAX_SUPPORTED_RENDER_TARGET_COUNT] = {};
    VulkanAttachment mDepth = {};
    VulkanAttachment mMsaaAttachments[MRT::MAX_SUPPORTED_RENDER_TARGET_COUNT] = {};
    VulkanAttachment mMsaaDepthAttachment = {};
    const bool mOffscreen : 1;
    uint8_t mSamples : 7;
};

struct VulkanBufferObject;

struct VulkanVertexBufferInfo : public HwVertexBufferInfo, VulkanResource {
    VulkanVertexBufferInfo(uint8_t bufferCount, uint8_t attributeCount,
            AttributeArray const& attributes);

    inline VkVertexInputAttributeDescription const* getAttribDescriptions() const {
        return mInfo.mSoa.data<PipelineInfo::ATTRIBUTE_DESCRIPTION>();
    }

    inline VkVertexInputBindingDescription const* getBufferDescriptions() const {
        return mInfo.mSoa.data<PipelineInfo::BUFFER_DESCRIPTION>();
    }

    inline int8_t const* getAttributeToBuffer() const {
        return mInfo.mSoa.data<PipelineInfo::ATTRIBUTE_TO_BUFFER_INDEX>();
    }

    inline VkDeviceSize const* getOffsets() const {
        return mInfo.mSoa.data<PipelineInfo::OFFSETS>();
    }

    size_t getAttributeCount() const noexcept {
        return mInfo.mSoa.size();
    }

private:
    struct PipelineInfo {

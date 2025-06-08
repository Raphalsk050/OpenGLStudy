
#include "VulkanResources.h"
#include "VulkanHandles.h"
#include "VulkanResourceAllocator.h"
#include "VulkanPipelineCache.h"

namespace filament::backend {

void deallocateResource(VulkanResourceAllocator* allocator, VulkanResourceType type,
        HandleBase::HandleId id) {

    if (IS_HEAP_ALLOC_TYPE(type)) {
        return;
    }

    switch (type) {
        case VulkanResourceType::BUFFER_OBJECT:
            allocator->destruct<VulkanBufferObject>(Handle<HwBufferObject>(id));
            break;
        case VulkanResourceType::INDEX_BUFFER:
            allocator->destruct<VulkanIndexBuffer>(Handle<HwIndexBuffer>(id));
            break;
        case VulkanResourceType::PROGRAM:
            allocator->destruct<VulkanProgram>(Handle<HwProgram>(id));
            break;
        case VulkanResourceType::RENDER_TARGET:
            allocator->destruct<VulkanRenderTarget>(Handle<HwRenderTarget>(id));
            break;
        case VulkanResourceType::SAMPLER_GROUP:
            allocator->destruct<VulkanSamplerGroup>(Handle<HwSamplerGroup>(id));
            break;
        case VulkanResourceType::SWAP_CHAIN:
            allocator->destruct<VulkanSwapChain>(Handle<HwSwapChain>(id));
            break;
        case VulkanResourceType::TEXTURE:
            allocator->destruct<VulkanTexture>(Handle<HwTexture>(id));
            break;
        case VulkanResourceType::TIMER_QUERY:
            allocator->destruct<VulkanTimerQuery>(Handle<HwTimerQuery>(id));
            break;
        case VulkanResourceType::VERTEX_BUFFER_INFO:
            allocator->destruct<VulkanVertexBufferInfo>(Handle<HwVertexBufferInfo>(id));
            break;
        case VulkanResourceType::VERTEX_BUFFER:
            allocator->destruct<VulkanVertexBuffer>(Handle<HwVertexBuffer>(id));
            break;
        case VulkanResourceType::RENDER_PRIMITIVE:
            allocator->destruct<VulkanRenderPrimitive>(Handle<VulkanRenderPrimitive>(id));
            break;
        case VulkanResourceType::DESCRIPTOR_SET_LAYOUT:
            allocator->destruct<VulkanDescriptorSetLayout>(Handle<VulkanDescriptorSetLayout>(id));
            break;
        case VulkanResourceType::DESCRIPTOR_SET:
            allocator->destruct<VulkanDescriptorSet>(Handle<VulkanDescriptorSet>(id));
            break;

        // If the resource is heap allocated, then the resource manager just skip refcounted
        // destruction.
        case VulkanResourceType::FENCE:
        case VulkanResourceType::HEAP_ALLOCATED:
        case VulkanResourceType::END_TYPE:
            break;
    }
}

} // namespace filament::backend

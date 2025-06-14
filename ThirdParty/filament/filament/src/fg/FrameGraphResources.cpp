
#include "fg/FrameGraph.h"
#include "fg/FrameGraphResources.h"
#include "fg/details/PassNode.h"
#include "fg/details/ResourceNode.h"

namespace filament {

FrameGraphResources::FrameGraphResources(FrameGraph& fg, PassNode& passNode) noexcept
    : mFrameGraph(fg), mPassNode(passNode) {
}

const char* FrameGraphResources::getPassName() const noexcept {
    return mPassNode.getName();
}

// this perhaps weirdly returns a reference, this is to express the fact that if this method
// fails, it has to assert (or throw), it can't return for e.g. a nullptr, because the public
// API doesn't return pointers.
// We still use FILAMENT_CHECK_PRECONDITION() because these failures are due to post conditions not met.
VirtualResource& FrameGraphResources::getResource(FrameGraphHandle handle) const {
    FILAMENT_CHECK_PRECONDITION(handle) << "Uninitialized handle when using FrameGraphResources.";

    VirtualResource* const resource = mFrameGraph.getResource(handle);

    auto& declaredHandles = mPassNode.mDeclaredHandles;
    const bool hasReadOrWrite = declaredHandles.find(handle.index) != declaredHandles.cend();

    FILAMENT_CHECK_PRECONDITION(hasReadOrWrite)
            << "Pass \"" << mPassNode.getName() << "\" didn't declare any access to resource \""
            << resource->name << "\"";

    assert_invariant(resource->refcount);

    return *resource;
}

FrameGraphResources::RenderPassInfo FrameGraphResources::getRenderPassInfo(uint32_t id) const {
    // this cast is safe because this can only be called from a RenderPassNode
    RenderPassNode const& renderPassNode = static_cast<RenderPassNode const&>(mPassNode);
    RenderPassNode::RenderPassData const* pRenderPassData = renderPassNode.getRenderPassData(id);

    FILAMENT_CHECK_PRECONDITION(pRenderPassData) << "using invalid RenderPass index " << id
                                                 << " in Pass \"" << mPassNode.getName() << "\"";

    return { pRenderPassData->backend.target, pRenderPassData->backend.params };
}

} // namespace filament

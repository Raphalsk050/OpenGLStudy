
#ifndef TNT_FILAMENT_FG_FRAMEGRAPHRESOURCES_H
#define TNT_FILAMENT_FG_FRAMEGRAPHRESOURCES_H

#include "fg/details/Resource.h"
#include "fg/FrameGraphId.h"

#include "backend/DriverEnums.h"
#include "backend/Handle.h"

namespace filament {

class FrameGraph;
class PassNode;
class VirtualResource;
struct FrameGraphRenderPass;

class FrameGraphResources {
public:
    FrameGraphResources(FrameGraph& fg, PassNode& passNode) noexcept;
    FrameGraphResources(FrameGraphResources const&) = delete;
    FrameGraphResources& operator=(FrameGraphResources const&) = delete;

    struct RenderPassInfo {
        backend::Handle<backend::HwRenderTarget> target;
        backend::RenderPassParams params;
    };

    const char* getPassName() const noexcept;

    template<typename RESOURCE>
    RESOURCE const& get(FrameGraphId<RESOURCE> handle) const;

    template<typename RESOURCE>
    typename RESOURCE::Descriptor const& getDescriptor(FrameGraphId<RESOURCE> handle) const;

    template<typename RESOURCE>
    typename RESOURCE::SubResourceDescriptor const& getSubResourceDescriptor(
            FrameGraphId<RESOURCE> handle) const;

    template<typename RESOURCE>
    typename RESOURCE::Usage const& getUsage(FrameGraphId<RESOURCE> handle) const;

    template<typename RESOURCE>
    void detach(FrameGraphId<RESOURCE> handle,
            RESOURCE* pOutResource, typename RESOURCE::Descriptor* pOutDescriptor) const;

    RenderPassInfo getRenderPassInfo(uint32_t id = 0u) const;

    backend::Handle<backend::HwTexture> getTexture(FrameGraphId<FrameGraphTexture> handle) const {
        return get(handle).handle;
    }

private:
    VirtualResource& getResource(FrameGraphHandle handle) const;

    FrameGraph& mFrameGraph;
    PassNode& mPassNode;
};

// ------------------------------------------------------------------------------------------------

template<typename RESOURCE>
RESOURCE const& FrameGraphResources::get(FrameGraphId<RESOURCE> handle) const {
    return static_cast<Resource<RESOURCE> const&>(getResource(handle)).resource;
}

template<typename RESOURCE>
typename RESOURCE::Descriptor const& FrameGraphResources::getDescriptor(
        FrameGraphId<RESOURCE> handle) const {
    return static_cast<Resource<RESOURCE> const&>(getResource(handle)).descriptor;
}

template<typename RESOURCE>
typename RESOURCE::SubResourceDescriptor const& FrameGraphResources::getSubResourceDescriptor(
        FrameGraphId<RESOURCE> handle) const {
    return static_cast<Resource<RESOURCE> const&>(getResource(handle)).subResourceDescriptor;
}

template<typename RESOURCE>
typename RESOURCE::Usage const& FrameGraphResources::getUsage(
        FrameGraphId<RESOURCE> handle) const {
    return static_cast<Resource<RESOURCE> const&>(getResource(handle)).usage;
}

template<typename RESOURCE>
void FrameGraphResources::detach(FrameGraphId<RESOURCE> handle, RESOURCE* pOutResource,
        typename RESOURCE::Descriptor* pOutDescriptor) const {
    Resource<RESOURCE>& concrete = static_cast<Resource<RESOURCE>&>(getResource(handle));
    concrete.detached = true;
    assert_invariant(pOutResource);
    *pOutResource = concrete.resource;
    if (pOutDescriptor) {
        *pOutDescriptor = concrete.descriptor;
    }
}

} // namespace filament

#endif //TNT_FILAMENT_FG_FRAMEGRAPHRESOURCES_H


#ifndef TNT_FILAMENT_FG_FRAMEGRAPH_H
#define TNT_FILAMENT_FG_FRAMEGRAPH_H

#include "Allocators.h"

#include "fg/Blackboard.h"
#include "fg/FrameGraphId.h"
#include "fg/FrameGraphPass.h"
#include "fg/FrameGraphRenderPass.h"
#include "fg/FrameGraphTexture.h"

#include "fg/details/DependencyGraph.h"
#include "fg/details/Resource.h"
#include "fg/details/Utilities.h"

#include "backend/DriverApiForward.h"

#include <backend/DriverEnums.h>
#include <backend/Handle.h>

#include <functional>

namespace filament {

class ResourceAllocatorInterface;

class FrameGraphPassExecutor;
class PassNode;
class ResourceNode;
class VirtualResource;

class FrameGraph {
public:

    class Builder {
    public:
        Builder(Builder const&) = delete;
        Builder& operator=(Builder const&) = delete;

        uint32_t declareRenderPass(const char* name,
                FrameGraphRenderPass::Descriptor const& desc);

        FrameGraphId<FrameGraphTexture> declareRenderPass(
                FrameGraphId<FrameGraphTexture> color, uint32_t* index = nullptr);

        template<typename RESOURCE>
        FrameGraphId<RESOURCE> create(const char* name,
                typename RESOURCE::Descriptor const& desc = {}) noexcept {
            return mFrameGraph.create<RESOURCE>(name, desc);
        }


        template<typename RESOURCE>
        inline FrameGraphId<RESOURCE> createSubresource(FrameGraphId<RESOURCE> parent,
                const char* name,
                typename RESOURCE::SubResourceDescriptor const& desc = {}) noexcept {
            return mFrameGraph.createSubresource<RESOURCE>(parent, name, desc);
        }


        template<typename RESOURCE>
        inline FrameGraphId<RESOURCE> read(FrameGraphId<RESOURCE> input,
                typename RESOURCE::Usage usage = RESOURCE::DEFAULT_R_USAGE) {
            return mFrameGraph.read<RESOURCE>(mPassNode, input, usage);
        }

        template<typename RESOURCE>
        [[nodiscard]] FrameGraphId<RESOURCE> write(FrameGraphId<RESOURCE> input,
                typename RESOURCE::Usage usage = RESOURCE::DEFAULT_W_USAGE) {
            return mFrameGraph.write<RESOURCE>(mPassNode, input, usage);
        }

        void sideEffect() noexcept;

        template<typename RESOURCE>
        typename RESOURCE::Descriptor const& getDescriptor(FrameGraphId<RESOURCE> handle) const {
            return static_cast<Resource<RESOURCE> const*>(
                    mFrameGraph.getResource(handle))->descriptor;
        }

        template<typename RESOURCE>
        typename RESOURCE::SubResourceDescriptor const& getSubResourceDescriptor(FrameGraphId<RESOURCE> handle) const {
            return static_cast<Resource<RESOURCE> const*>(
                    mFrameGraph.getResource(handle))->subResourceDescriptor;
        }

        const char* getName(FrameGraphHandle handle) const noexcept;


        FrameGraphId<FrameGraphTexture> createTexture(const char* name,
                FrameGraphTexture::Descriptor const& desc = {}) noexcept {
            return create<FrameGraphTexture>(name, desc);
        }

        FrameGraphId<FrameGraphTexture> sample(FrameGraphId<FrameGraphTexture> input) {
            return read(input, FrameGraphTexture::Usage::SAMPLEABLE);
        }

    private:
        friend class FrameGraph;
        Builder(FrameGraph& fg, PassNode* passNode) noexcept;
        ~Builder() noexcept = default;
        FrameGraph& mFrameGraph;
        PassNode* const mPassNode;
    };

    // --------------------------------------------------------------------------------------------

    enum class Mode {
        UNPROTECTED,
        PROTECTED,
    };

    explicit FrameGraph(ResourceAllocatorInterface& resourceAllocator,
            Mode mode = Mode::UNPROTECTED);
    FrameGraph(FrameGraph const&) = delete;
    FrameGraph& operator=(FrameGraph const&) = delete;
    ~FrameGraph() noexcept;

    Blackboard const& getBlackboard() const noexcept { return mBlackboard; }

    template<typename Data, typename Setup, typename Execute>
    FrameGraphPass<Data>& addPass(const char* name, Setup setup, Execute&& execute);

    template<typename Data, typename Setup>
    FrameGraphPass<Data>& addPass(const char* name, Setup setup);

    template<typename Execute>
    void addTrivialSideEffectPass(const char* name, Execute&& execute);

    FrameGraph& compile() noexcept;

    void execute(backend::DriverApi& driver) noexcept;

    template<typename RESOURCE>
    FrameGraphId<RESOURCE> forwardResource(FrameGraphId<RESOURCE> resource,
            FrameGraphId<RESOURCE> replacedResource);

    template<typename RESOURCE>
    FrameGraphId<RESOURCE> forwardResource(char const* name,
            typename RESOURCE::Descriptor const& desc,
            FrameGraphId<RESOURCE> replacedResource);

    template<typename RESOURCE>
    FrameGraphId<RESOURCE> forwardResource(char const* name,
            typename RESOURCE::Descriptor const& desc,
            typename RESOURCE::SubResourceDescriptor const& subdesc,
            FrameGraphId<RESOURCE> replacedResource);

    template<typename RESOURCE>
    void present(FrameGraphId<RESOURCE> input);

    template<typename RESOURCE>
    FrameGraphId<RESOURCE> import(const char* name,
            typename RESOURCE::Descriptor const& desc,
            typename RESOURCE::Usage usage,
            const RESOURCE& resource) noexcept;

    FrameGraphId<FrameGraphTexture> import(const char* name,
            FrameGraphRenderPass::ImportDescriptor const& desc,
            backend::Handle<backend::HwRenderTarget> target);


    bool isValid(FrameGraphHandle handle) const;

    bool isCulled(FrameGraphPassBase const& pass) const noexcept;

    template<typename RESOURCE>
    typename RESOURCE::Descriptor const& getDescriptor(FrameGraphId<RESOURCE> handle) const {
        return static_cast<Resource<RESOURCE> const*>(getResource(handle))->descriptor;
    }

    template<typename RESOURCE>
    typename RESOURCE::SubResourceDescriptor const& getSubResourceDescriptor(FrameGraphId<RESOURCE> handle) const {
        return static_cast<Resource<RESOURCE> const*>(getResource(handle))->subResourceDescriptor;
    }

    bool isAcyclic() const noexcept;

    //! export a graphviz view of the graph
    void export_graphviz(utils::io::ostream& out, const char* name = nullptr);

private:
    friend class FrameGraphResources;
    friend class PassNode;
    friend class ResourceNode;
    friend class RenderPassNode;

    LinearAllocatorArena& getArena() noexcept { return mArena; }
    DependencyGraph& getGraph() noexcept { return mGraph; }
    ResourceAllocatorInterface& getResourceAllocator() noexcept { return mResourceAllocator; }

    struct ResourceSlot {
        using Version = FrameGraphHandle::Version;
        using Index = int16_t;
        Index rid = 0;    // VirtualResource* index in mResources
        Index nid = 0;    // ResourceNode* index in mResourceNodes
        Index sid =-1;    // ResourceNode* index in mResourceNodes for reading subresource's parent
        Version version = 0;
    };
    void reset() noexcept;
    void addPresentPass(const std::function<void(Builder&)>& setup) noexcept;
    Builder addPassInternal(const char* name, FrameGraphPassBase* base) noexcept;
    FrameGraphHandle createNewVersion(FrameGraphHandle handle) noexcept;
    ResourceNode* createNewVersionForSubresourceIfNeeded(ResourceNode* node) noexcept;
    FrameGraphHandle addResourceInternal(VirtualResource* resource) noexcept;
    FrameGraphHandle addSubResourceInternal(FrameGraphHandle parent, VirtualResource* resource) noexcept;
    FrameGraphHandle readInternal(FrameGraphHandle handle, PassNode* passNode,
            const std::function<bool(ResourceNode*, VirtualResource*)>& connect);
    FrameGraphHandle writeInternal(FrameGraphHandle handle, PassNode* passNode,
            const std::function<bool(ResourceNode*, VirtualResource*)>& connect);
    FrameGraphHandle forwardResourceInternal(FrameGraphHandle resourceHandle,
            FrameGraphHandle replaceResourceHandle);

    void assertValid(FrameGraphHandle handle) const;

    template<typename RESOURCE>
    FrameGraphId<RESOURCE> create(char const* name,
            typename RESOURCE::Descriptor const& desc) noexcept;

    template<typename RESOURCE>
    FrameGraphId<RESOURCE> createSubresource(FrameGraphId<RESOURCE> parent,
            char const* name, typename RESOURCE::SubResourceDescriptor const& desc) noexcept;

    template<typename RESOURCE>
    FrameGraphId<RESOURCE> read(PassNode* passNode,
            FrameGraphId<RESOURCE> input, typename RESOURCE::Usage usage);

    template<typename RESOURCE>
    FrameGraphId<RESOURCE> write(PassNode* passNode,
            FrameGraphId<RESOURCE> input, typename RESOURCE::Usage usage);

    ResourceSlot& getResourceSlot(FrameGraphHandle handle) noexcept {
        assert_invariant((size_t)handle.index < mResourceSlots.size());
        assert_invariant((size_t)mResourceSlots[handle.index].rid < mResources.size());
        assert_invariant((size_t)mResourceSlots[handle.index].nid < mResourceNodes.size());
        return mResourceSlots[handle.index];
    }

    ResourceSlot const& getResourceSlot(FrameGraphHandle handle) const noexcept {
        return const_cast<FrameGraph*>(this)->getResourceSlot(handle);
    }

    VirtualResource* getResource(FrameGraphHandle handle) noexcept {
        assert_invariant(handle.isInitialized());
        ResourceSlot const& slot = getResourceSlot(handle);
        assert_invariant((size_t)slot.rid < mResources.size());
        return mResources[slot.rid];
    }

    ResourceNode* getActiveResourceNode(FrameGraphHandle handle) noexcept {
        assert_invariant(handle);
        ResourceSlot const& slot = getResourceSlot(handle);
        assert_invariant((size_t)slot.nid < mResourceNodes.size());
        return mResourceNodes[slot.nid];
    }

    VirtualResource const* getResource(FrameGraphHandle handle) const noexcept {
        return const_cast<FrameGraph*>(this)->getResource(handle);
    }

    ResourceNode const* getResourceNode(FrameGraphHandle handle) const noexcept {
        return const_cast<FrameGraph*>(this)->getActiveResourceNode(handle);
    }

    void destroyInternal() noexcept;

    Blackboard mBlackboard;
    ResourceAllocatorInterface& mResourceAllocator;
    LinearAllocatorArena mArena;
    DependencyGraph mGraph;
    const Mode mMode;

    Vector<ResourceSlot> mResourceSlots;
    Vector<VirtualResource*> mResources;
    Vector<ResourceNode*> mResourceNodes;
    Vector<PassNode*> mPassNodes;
    Vector<PassNode*>::iterator mActivePassNodesEnd;
};

template<typename Data, typename Setup, typename Execute>
FrameGraphPass<Data>& FrameGraph::addPass(char const* name, Setup setup, Execute&& execute) {
    static_assert(sizeof(Execute) < 2048, "Execute() lambda is capturing too much data.");

    // create the FrameGraph pass
    auto* const pass = mArena.make<FrameGraphPassConcrete<Data, Execute>>(std::forward<Execute>(execute));

    Builder builder(addPassInternal(name, pass));
    setup(builder, const_cast<Data&>(pass->getData()));

    // return a reference to the pass to the user
    return *pass;
}

template<typename Data, typename Setup>
FrameGraphPass<Data>& FrameGraph::addPass(char const* name, Setup setup) {
    // create the FrameGraph pass without an execute stage
    auto* const pass = mArena.make<FrameGraphPass<Data>>();

    Builder builder(addPassInternal(name, pass));
    setup(builder, const_cast<Data&>(pass->getData()));

    // return a reference to the pass to the user
    return *pass;
}

template<typename Execute>
void FrameGraph::addTrivialSideEffectPass(char const* name, Execute&& execute) {
    addPass<Empty>(name, [](FrameGraph::Builder& builder, auto&) { builder.sideEffect(); },
            [execute](FrameGraphResources const&, auto const&, backend::DriverApi& driver) {
                execute(driver);
            });
}

template<typename RESOURCE>
void FrameGraph::present(FrameGraphId<RESOURCE> input) {
    // present doesn't add any usage flags, only a dependency
    addPresentPass([&](Builder& builder) { builder.read(input, {}); });
}

template<typename RESOURCE>
FrameGraphId<RESOURCE> FrameGraph::create(char const* name,
        typename RESOURCE::Descriptor const& desc) noexcept {
    VirtualResource* vresource(mArena.make<Resource<RESOURCE>>(name, desc));
    return FrameGraphId<RESOURCE>(addResourceInternal(vresource));
}

template<typename RESOURCE>
FrameGraphId<RESOURCE> FrameGraph::createSubresource(FrameGraphId<RESOURCE> parent,
        char const* name, typename RESOURCE::SubResourceDescriptor const& desc) noexcept {
    auto* parentResource = static_cast<Resource<RESOURCE>*>(getResource(parent));
    VirtualResource* vresource(mArena.make<Resource<RESOURCE>>(parentResource, name, desc));
    return FrameGraphId<RESOURCE>(addSubResourceInternal(parent, vresource));
}

template<typename RESOURCE>
FrameGraphId<RESOURCE> FrameGraph::import(char const* name,
        typename RESOURCE::Descriptor const& desc,
        typename RESOURCE::Usage usage,
        RESOURCE const& resource) noexcept {
    VirtualResource* vresource(mArena.make<ImportedResource<RESOURCE>>(name, desc, usage, resource));
    return FrameGraphId<RESOURCE>(addResourceInternal(vresource));
}

template<typename RESOURCE>
FrameGraphId<RESOURCE> FrameGraph::read(PassNode* passNode, FrameGraphId<RESOURCE> input,
        typename RESOURCE::Usage usage) {
    FrameGraphId<RESOURCE> result(readInternal(input, passNode,
            [this, passNode, usage](ResourceNode* node, VirtualResource* vrsrc) {
                Resource<RESOURCE>* resource = static_cast<Resource<RESOURCE>*>(vrsrc);
                return resource->connect(mGraph, node, passNode, usage);
            }));
    return result;
}

template<typename RESOURCE>
FrameGraphId<RESOURCE> FrameGraph::write(PassNode* passNode, FrameGraphId<RESOURCE> input,
        typename RESOURCE::Usage usage) {
    FrameGraphId<RESOURCE> result(writeInternal(input, passNode,
            [this, passNode, usage](ResourceNode* node, VirtualResource* vrsrc) {
                Resource<RESOURCE>* resource = static_cast<Resource<RESOURCE>*>(vrsrc);
                return resource->connect(mGraph, passNode, node, usage);
            }));
    return result;
}

template<typename RESOURCE>
FrameGraphId<RESOURCE> FrameGraph::forwardResource(FrameGraphId<RESOURCE> resource,
        FrameGraphId<RESOURCE> replacedResource) {
    return FrameGraphId<RESOURCE>(forwardResourceInternal(resource, replacedResource));
}

template<typename RESOURCE>
FrameGraphId<RESOURCE> FrameGraph::forwardResource(char const* name,
        typename RESOURCE::Descriptor const& desc,
        FrameGraphId<RESOURCE> replacedResource) {
    FrameGraphId<RESOURCE> handle = create<RESOURCE>(name, desc);
    return forwardResource(handle, replacedResource);
}

template<typename RESOURCE>
FrameGraphId<RESOURCE> FrameGraph::forwardResource(char const* name,
        typename RESOURCE::Descriptor const& desc,
        typename RESOURCE::SubResourceDescriptor const& subdesc,
        FrameGraphId<RESOURCE> replacedResource) {
    FrameGraphId<RESOURCE> handle = create<RESOURCE>(name, desc);
    handle = createSubresource<RESOURCE>(handle, name, subdesc);
    return forwardResource(handle, replacedResource);
}

// ------------------------------------------------------------------------------------------------


extern template void FrameGraph::present(FrameGraphId<FrameGraphTexture> input);

extern template FrameGraphId<FrameGraphTexture> FrameGraph::create(char const* name,
        FrameGraphTexture::Descriptor const& desc) noexcept;

extern template FrameGraphId<FrameGraphTexture> FrameGraph::createSubresource(FrameGraphId<FrameGraphTexture> parent,
        char const* name, FrameGraphTexture::SubResourceDescriptor const& desc) noexcept;

extern template FrameGraphId<FrameGraphTexture> FrameGraph::import(char const* name,
        FrameGraphTexture::Descriptor const& desc, FrameGraphTexture::Usage usage, FrameGraphTexture const& resource) noexcept;

extern template FrameGraphId<FrameGraphTexture> FrameGraph::read(PassNode* passNode,
        FrameGraphId<FrameGraphTexture> input, FrameGraphTexture::Usage usage);

extern template FrameGraphId<FrameGraphTexture> FrameGraph::write(PassNode* passNode,
        FrameGraphId<FrameGraphTexture> input, FrameGraphTexture::Usage usage);

extern template FrameGraphId<FrameGraphTexture> FrameGraph::forwardResource(
        FrameGraphId<FrameGraphTexture> resource, FrameGraphId<FrameGraphTexture> replacedResource);

} // namespace filament

#endif //TNT_FILAMENT_FG_FRAMEGRAPH_H

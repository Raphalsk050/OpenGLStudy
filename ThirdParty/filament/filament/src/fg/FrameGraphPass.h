
#ifndef TNT_FILAMENT_FG_FRAMEGRAPHPASS_H
#define TNT_FILAMENT_FG_FRAMEGRAPHPASS_H

#include "backend/DriverApiForward.h"

#include "fg/FrameGraphResources.h"

#include "third_party/filament/libs/utils/include/utils/Allocator.h"

namespace filament {

class FrameGraphPassExecutor {
    friend class FrameGraph;
    friend class PassNode;
    friend class RenderPassNode;

protected:
    virtual void execute(FrameGraphResources const& resources, backend::DriverApi& driver) noexcept = 0;

public:
    FrameGraphPassExecutor() noexcept = default;
    virtual ~FrameGraphPassExecutor() noexcept;
    FrameGraphPassExecutor(FrameGraphPassExecutor const&) = delete;
    FrameGraphPassExecutor& operator = (FrameGraphPassExecutor const&) = delete;
};

class FrameGraphPassBase : protected FrameGraphPassExecutor {
    friend class FrameGraph;
    friend class PassNode;
    friend class RenderPassNode;
    PassNode* mNode = nullptr;
    void setNode(PassNode* node) noexcept { mNode = node; }
    PassNode const& getNode() const noexcept { return *mNode; }

public:
    using FrameGraphPassExecutor::FrameGraphPassExecutor;
    ~FrameGraphPassBase() noexcept override;
};

template<typename Data>
class FrameGraphPass : public FrameGraphPassBase {
    friend class FrameGraph;

    // allow our allocators to instantiate us
    template<typename, typename, typename, typename>
    friend class utils::Arena;

    void execute(FrameGraphResources const&, backend::DriverApi&) noexcept override {}

protected:
    FrameGraphPass() = default;
    Data mData;

public:
    Data const& getData() const noexcept { return mData; }
    Data const* operator->() const { return &mData; }
};

template<typename Data, typename Execute>
class FrameGraphPassConcrete : public FrameGraphPass<Data> {
    friend class FrameGraph;

    // allow our allocators to instantiate us
    template<typename, typename, typename, typename>
    friend class utils::Arena;

    explicit FrameGraphPassConcrete(Execute&& execute) noexcept
            : mExecute(std::move(execute)) {
    }

    void execute(FrameGraphResources const& resources, backend::DriverApi& driver) noexcept final {
        mExecute(resources, this->mData, driver);
    }

    Execute mExecute;
};

} // namespace filament

#endif //TNT_FILAMENT_FG_FRAMEGRAPHPASS_H


#ifndef TNT_FILAMENT_DETAILS_RENDERER_H
#define TNT_FILAMENT_DETAILS_RENDERER_H

#include "downcast.h"

#include "Allocators.h"
#include "FrameInfo.h"
#include "FrameSkipper.h"
#include "PostProcessManager.h"
#include "RenderPass.h"

#include "details/SwapChain.h"

#include "backend/DriverApiForward.h"

#include <filament/Renderer.h>
#include <filament/Viewport.h>

#include <backend/DriverEnums.h>
#include <backend/Handle.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Allocator.h"

#include "third_party/filament/libs/math/include/math/vec4.h"

#include "robin_map/include/tsl/robin_set.h"

#include <algorithm>
#include <chrono>
#include <functional>
#include <utility>

#include <stddef.h>
#include <stdint.h>

namespace filament {

namespace backend {
class Driver;
} // namespace backend

class FEngine;
class FRenderTarget;
class FView;

class FRenderer : public Renderer {
    static constexpr unsigned MAX_FRAMETIME_HISTORY = 32u;

public:
    explicit FRenderer(FEngine& engine);

    ~FRenderer() noexcept;

    void terminate(FEngine& engine);

    FEngine& getEngine() const noexcept { return mEngine; }

    math::float4 getShaderUserTime() const { return mShaderUserTime; }

    void resetUserTime();

    // renders a single standalone view. The view must have a a custom rendertarget.
    void renderStandaloneView(FView const* view);


    void setPresentationTime(int64_t monotonic_clock_ns);

    void setVsyncTime(uint64_t steadyClockTimeNano) noexcept;

    // start a frame
    bool beginFrame(FSwapChain* swapChain, uint64_t vsyncSteadyClockTimeNano);

    // end a frame
    void endFrame();

    // render a view. must be called between beginFrame/enfFrame.
    void render(FView const* view);

    // read pixel from the current swapchain. must be called between beginFrame/enfFrame.
    void readPixels(uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
            backend::PixelBufferDescriptor&& buffer);

    // read pixel from a rendertarget. must be called between beginFrame/enfFrame.
    void readPixels(FRenderTarget* renderTarget,
            uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
            backend::PixelBufferDescriptor&& buffer);

    // blits the current swapchain to another one
    void copyFrame(FSwapChain* dstSwapChain, Viewport const& dstViewport,
            Viewport const& srcViewport, CopyFrameFlag flags);


    void setDisplayInfo(DisplayInfo const& info) noexcept {
        mDisplayInfo.refreshRate = info.refreshRate;
    }

    void setFrameRateOptions(FrameRateOptions const& options) noexcept {
        FrameRateOptions& frameRateOptions = mFrameRateOptions;
        frameRateOptions = options;

        // History can't be more than 31 frames (~0.5s), make it odd.
        frameRateOptions.history = std::min(frameRateOptions.history / 2u * 2u + 1u,
                MAX_FRAMETIME_HISTORY);

        // History must at least be 3 frames
        frameRateOptions.history = std::max(frameRateOptions.history, uint8_t(3));

        frameRateOptions.interval = std::max(uint8_t(1), frameRateOptions.interval);

        // headroom can't be larger than frame time, or less than 0
        frameRateOptions.headRoomRatio = std::min(frameRateOptions.headRoomRatio, 1.0f);
        frameRateOptions.headRoomRatio = std::max(frameRateOptions.headRoomRatio, 0.0f);
    }

    void setClearOptions(const ClearOptions& options) {
        mClearOptions = options;
    }

    ClearOptions const& getClearOptions() const noexcept {
        return mClearOptions;
    }

private:
    friend class Renderer;
    using Command = RenderPass::Command;
    using clock = std::chrono::steady_clock;
    using Epoch = clock::time_point;
    using duration = clock::duration;

    backend::TargetBufferFlags getClearFlags() const noexcept;
    void initializeClearFlags() noexcept;

    backend::TextureFormat getHdrFormat(const FView& view, bool translucent) const noexcept;
    backend::TextureFormat getLdrFormat(bool translucent) const noexcept;

    Epoch getUserEpoch() const { return mUserEpoch; }
    double getUserTime() const noexcept {
        duration const d = clock::now() - getUserEpoch();
        // convert the duration (whatever it is) to a duration in seconds encoded as double
        return std::chrono::duration<double>(d).count();
    }

    std::pair<backend::Handle<backend::HwRenderTarget>, backend::TargetBufferFlags>
            getRenderTarget(FView const& view) const noexcept;

    void recordHighWatermark(size_t watermark) noexcept {
        mCommandsHighWatermark = std::max(mCommandsHighWatermark, watermark);
    }

    size_t getCommandsHighWatermark() const noexcept {
        return mCommandsHighWatermark;
    }

    void renderInternal(FView const* view);
    void renderJob(RootArenaScope& rootArenaScope, FView& view);

    // keep a reference to our engine
    FEngine& mEngine;
    FrameSkipper mFrameSkipper;
    backend::Handle<backend::HwRenderTarget> mRenderTargetHandle;
    FSwapChain* mSwapChain = nullptr;
    size_t mCommandsHighWatermark = 0;
    uint32_t mFrameId = 0;
    uint32_t mViewRenderedCount = 0;
    FrameInfoManager mFrameInfoManager;
    backend::TextureFormat mHdrTranslucent;
    backend::TextureFormat mHdrQualityMedium;
    backend::TextureFormat mHdrQualityHigh;
    bool mIsRGB8Supported : 1;
    Epoch mUserEpoch;
    math::float4 mShaderUserTime{};
    DisplayInfo mDisplayInfo;
    FrameRateOptions mFrameRateOptions;
    ClearOptions mClearOptions;
    backend::TargetBufferFlags mDiscardStartFlags{};
    backend::TargetBufferFlags mClearFlags{};
    tsl::robin_set<FRenderTarget*> mPreviousRenderTargets;
    std::function<void()> mBeginFrameInternal;
    uint64_t mVsyncSteadyClockTimeNano = 0;
};

FILAMENT_DOWNCAST(Renderer)

} // namespace filament

#endif // TNT_FILAMENT_DETAILS_RENDERER_H


//! \file

#ifndef TNT_FILAMENT_RENDERER_H
#define TNT_FILAMENT_RENDERER_H

#include <filament/FilamentAPI.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/vec4.h"

#include <stdint.h>

namespace filament {

class Engine;
class RenderTarget;
class SwapChain;
class View;
class Viewport;

namespace backend {
class PixelBufferDescriptor;
} // namespace backend

class UTILS_PUBLIC Renderer : public FilamentAPI {
public:

    struct DisplayInfo {
        // refresh-rate of the display in Hz. set to 0 for offscreen or turn off frame-pacing.
        float refreshRate = 60.0f;

        UTILS_DEPRECATED uint64_t presentationDeadlineNanos = 0;
        UTILS_DEPRECATED uint64_t vsyncOffsetNanos = 0;
    };

    struct FrameRateOptions {
        float headRoomRatio = 0.0f;        //!< additional headroom for the GPU
        float scaleRate = 1.0f / 8.0f;     //!< rate at which the system reacts to load changes
        uint8_t history = 15;              //!< history size
        uint8_t interval = 1;              //!< desired frame interval in unit of 1.0 / DisplayInfo::refreshRate
    };

    struct ClearOptions {
        math::float4 clearColor = {};

        bool clear = false;

        bool discard = true;
    };

    void setDisplayInfo(const DisplayInfo& info) noexcept;

    void setFrameRateOptions(FrameRateOptions const& options) noexcept;

    void setClearOptions(const ClearOptions& options);

    ClearOptions const& getClearOptions() const noexcept;

    Engine* UTILS_NONNULL getEngine() noexcept;

    inline Engine const* UTILS_NONNULL getEngine() const noexcept {
        return const_cast<Renderer *>(this)->getEngine();
    }

    using CopyFrameFlag = uint32_t;

    static constexpr CopyFrameFlag COMMIT = 0x1;
    static constexpr CopyFrameFlag SET_PRESENTATION_TIME = 0x2;
    static constexpr CopyFrameFlag CLEAR = 0x4;


    void setVsyncTime(uint64_t steadyClockTimeNano) noexcept;

    bool beginFrame(SwapChain* UTILS_NONNULL swapChain,
            uint64_t vsyncSteadyClockTimeNano = 0u);

    void setPresentationTime(int64_t monotonic_clock_ns);

    void render(View const* UTILS_NONNULL view);

    void copyFrame(SwapChain* UTILS_NONNULL dstSwapChain, Viewport const& dstViewport,
            Viewport const& srcViewport, uint32_t flags = 0);

    void readPixels(uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
            backend::PixelBufferDescriptor&& buffer);

    void endFrame();


    void readPixels(RenderTarget* UTILS_NONNULL renderTarget,
            uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
            backend::PixelBufferDescriptor&& buffer);

    void renderStandaloneView(View const* UTILS_NONNULL view);


    double getUserTime() const;

    void resetUserTime();

protected:
    // prevent heap allocation
    ~Renderer() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_RENDERER_H


#include "details/Renderer.h"

#include "details/Engine.h"
#include "details/View.h"

namespace filament {

using namespace math;
using namespace backend;

Engine* Renderer::getEngine() noexcept {
    return &downcast(this)->getEngine();
}

void Renderer::render(View const* view) {
    downcast(this)->render(downcast(view));
}

void Renderer::setPresentationTime(int64_t monotonic_clock_ns) {
    downcast(this)->setPresentationTime(monotonic_clock_ns);
}

bool Renderer::beginFrame(SwapChain* swapChain, uint64_t vsyncSteadyClockTimeNano) {
    return downcast(this)->beginFrame(downcast(swapChain), vsyncSteadyClockTimeNano);
}

void Renderer::copyFrame(SwapChain* dstSwapChain, filament::Viewport const& dstViewport,
        filament::Viewport const& srcViewport, CopyFrameFlag flags) {
    downcast(this)->copyFrame(downcast(dstSwapChain), dstViewport, srcViewport, flags);
}

void Renderer::readPixels(uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
        PixelBufferDescriptor&& buffer) {
    downcast(this)->readPixels(xoffset, yoffset, width, height, std::move(buffer));
}

void Renderer::readPixels(RenderTarget* renderTarget,
        uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
        PixelBufferDescriptor&& buffer) {
    downcast(this)->readPixels(downcast(renderTarget),
            xoffset, yoffset, width, height, std::move(buffer));
}

void Renderer::endFrame() {
    downcast(this)->endFrame();
}

double Renderer::getUserTime() const {
    return downcast(this)->getUserTime();
}

void Renderer::resetUserTime() {
    downcast(this)->resetUserTime();
}

void Renderer::setDisplayInfo(const DisplayInfo& info) noexcept {
    downcast(this)->setDisplayInfo(info);
}

void Renderer::setFrameRateOptions(FrameRateOptions const& options) noexcept {
    downcast(this)->setFrameRateOptions(options);
}

void Renderer::setClearOptions(const ClearOptions& options) {
    downcast(this)->setClearOptions(options);
}

Renderer::ClearOptions const& Renderer::getClearOptions() const noexcept {
    return downcast(this)->getClearOptions();
}

void Renderer::renderStandaloneView(View const* view) {
    downcast(this)->renderStandaloneView(downcast(view));
}

void Renderer::setVsyncTime(uint64_t steadyClockTimeNano) noexcept {
    downcast(this)->setVsyncTime(steadyClockTimeNano);
}

} // namespace filament

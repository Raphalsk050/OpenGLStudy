
#include <backend/platforms/PlatformWebGL.h>

namespace filament::backend {

using namespace backend;

Driver* PlatformWebGL::createDriver(void* const sharedGLContext,
        const Platform::DriverConfig& driverConfig) noexcept {
    return OpenGLPlatform::createDefaultDriver(this, sharedGLContext, driverConfig);
}

int PlatformWebGL::getOSVersion() const noexcept {
    return 0;
}

void PlatformWebGL::terminate() noexcept {
}

Platform::SwapChain* PlatformWebGL::createSwapChain(
        void* nativeWindow, uint64_t flags) noexcept {
    return (SwapChain*)nativeWindow;
}

Platform::SwapChain* PlatformWebGL::createSwapChain(
        uint32_t width, uint32_t height, uint64_t flags) noexcept {
    // TODO: implement headless SwapChain
    return nullptr;
}

void PlatformWebGL::destroySwapChain(Platform::SwapChain* swapChain) noexcept {
}

bool PlatformWebGL::makeCurrent(ContextType type, SwapChain* drawSwapChain,
        SwapChain* readSwapChain) noexcept {
    return true;
}

void PlatformWebGL::commit(Platform::SwapChain* swapChain) noexcept {
}

} // namespace filament::backend


#ifndef TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_WEBGL_H
#define TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_WEBGL_H

#include <stdint.h>

#include <backend/platforms/OpenGLPlatform.h>

#include <backend/DriverEnums.h>

namespace filament::backend {

class PlatformWebGL : public OpenGLPlatform {
protected:
    // --------------------------------------------------------------------------------------------
    // Platform Interface

    Driver* createDriver(void* sharedGLContext,
            const Platform::DriverConfig& driverConfig) noexcept override;

    int getOSVersion() const noexcept override;

    // --------------------------------------------------------------------------------------------
    // OpenGLPlatform Interface

    void terminate() noexcept override;

    SwapChain* createSwapChain(void* nativewindow, uint64_t flags) noexcept override;
    SwapChain* createSwapChain(uint32_t width, uint32_t height, uint64_t flags) noexcept override;
    void destroySwapChain(SwapChain* swapChain) noexcept override;
    bool makeCurrent(ContextType type, SwapChain* drawSwapChain, SwapChain* readSwapChain) noexcept override;
    void commit(SwapChain* swapChain) noexcept override;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_WEBGL_H

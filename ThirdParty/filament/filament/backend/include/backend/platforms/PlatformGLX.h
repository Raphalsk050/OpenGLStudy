
#ifndef TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_GLX_H
#define TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_GLX_H

#include <stdint.h>

#include "bluegl/BlueGL.h"
#include <GL/glx.h>

#include <backend/platforms/OpenGLPlatform.h>

#include <backend/DriverEnums.h>

#include <vector>

namespace filament::backend {

class PlatformGLX : public OpenGLPlatform {
protected:
    // --------------------------------------------------------------------------------------------
    // Platform Interface

    Driver* createDriver(void* sharedGLContext,
            const DriverConfig& driverConfig) noexcept override;

    int getOSVersion() const noexcept final override { return 0; }

    // --------------------------------------------------------------------------------------------
    // OpenGLPlatform Interface

    void terminate() noexcept override;

    SwapChain* createSwapChain(void* nativewindow, uint64_t flags) noexcept override;
    SwapChain* createSwapChain(uint32_t width, uint32_t height, uint64_t flags) noexcept override;
    void destroySwapChain(SwapChain* swapChain) noexcept override;
    bool makeCurrent(ContextType type, SwapChain* drawSwapChain, SwapChain* readSwapChain) noexcept override;
    void commit(SwapChain* swapChain) noexcept override;

private:
    Display *mGLXDisplay;
    GLXContext mGLXContext;
    GLXFBConfig* mGLXConfig;
    GLXPbuffer mDummySurface;
    std::vector<GLXPbuffer> mPBuffers;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_GLX_H

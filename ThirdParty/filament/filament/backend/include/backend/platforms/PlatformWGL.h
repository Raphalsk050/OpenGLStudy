
#ifndef TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_WGL_H
#define TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_WGL_H

#include <stdint.h>

#include <windows.h>
#include "third_party/filament/libs/utils/include/utils/unwindows.h"

#include <backend/platforms/OpenGLPlatform.h>
#include <backend/DriverEnums.h>

#include <vector>

namespace filament::backend {

class PlatformWGL : public OpenGLPlatform {
protected:
    // --------------------------------------------------------------------------------------------
    // Platform Interface

    Driver* createDriver(void* sharedGLContext,
            const Platform::DriverConfig& driverConfig) noexcept override;

    int getOSVersion() const noexcept final override { return 0; }

    // --------------------------------------------------------------------------------------------
    // OpenGLPlatform Interface

    void terminate() noexcept override;

    bool isExtraContextSupported() const noexcept override;
    void createContext(bool shared) override;

    SwapChain* createSwapChain(void* nativewindow, uint64_t flags) noexcept override;
    SwapChain* createSwapChain(uint32_t width, uint32_t height, uint64_t flags) noexcept override;
    void destroySwapChain(SwapChain* swapChain) noexcept override;
    bool makeCurrent(ContextType type, SwapChain* drawSwapChain, SwapChain* readSwapChain) noexcept override;
    void commit(SwapChain* swapChain) noexcept override;

protected:
    HGLRC mContext = NULL;
    HWND mHWnd = NULL;
    HDC mWhdc = NULL;
    PIXELFORMATDESCRIPTOR mPfd = {};
    std::vector<HGLRC> mAdditionalContexts;
    std::vector<int> mAttribs;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_GLX_H

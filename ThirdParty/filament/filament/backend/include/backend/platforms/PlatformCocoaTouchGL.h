
#ifndef TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_COCOA_TOUCH_GL_H
#define TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_COCOA_TOUCH_GL_H

#include <stdint.h>

#include <backend/platforms/OpenGLPlatform.h>

#include <backend/DriverEnums.h>

namespace filament::backend {

struct PlatformCocoaTouchGLImpl;

class PlatformCocoaTouchGL : public OpenGLPlatform {
public:
    PlatformCocoaTouchGL();
    ~PlatformCocoaTouchGL() noexcept override;

    // --------------------------------------------------------------------------------------------
    // Platform Interface

    Driver* createDriver(void* sharedGLContext,
            const Platform::DriverConfig& driverConfig) noexcept override;

    int getOSVersion() const noexcept final { return 0; }

    // --------------------------------------------------------------------------------------------
    // OpenGLPlatform Interface

    void terminate() noexcept override;

    uint32_t getDefaultFramebufferObject() noexcept override;

    bool isExtraContextSupported() const noexcept override;
    void createContext(bool shared) override;

    SwapChain* createSwapChain(void* nativewindow, uint64_t flags) noexcept override;
    SwapChain* createSwapChain(uint32_t width, uint32_t height, uint64_t flags) noexcept override;
    void destroySwapChain(SwapChain* swapChain) noexcept override;
    bool makeCurrent(ContextType type, SwapChain* drawSwapChain, SwapChain* readSwapChain) noexcept override;
    void commit(SwapChain* swapChain) noexcept override;

    OpenGLPlatform::ExternalTexture* createExternalImageTexture() noexcept override;
    void destroyExternalImage(ExternalTexture* texture) noexcept override;
    void retainExternalImage(void* externalImage) noexcept override;
    bool setExternalImage(void* externalImage, ExternalTexture* texture) noexcept override;

private:
    PlatformCocoaTouchGLImpl* pImpl = nullptr;
};

using ContextManager = PlatformCocoaTouchGL;

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_COCOA_TOUCH_GL_H

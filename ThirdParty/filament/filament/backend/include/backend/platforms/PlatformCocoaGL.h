
#ifndef TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_COCOA_GL_H
#define TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_COCOA_GL_H

#include <backend/DriverEnums.h>
#include <backend/platforms/OpenGLPlatform.h>

#include <stdint.h>

namespace filament::backend {

struct PlatformCocoaGLImpl;

class PlatformCocoaGL : public OpenGLPlatform {
public:
    PlatformCocoaGL();
    ~PlatformCocoaGL() noexcept override;

protected:
    // --------------------------------------------------------------------------------------------
    // Platform Interface

    Driver* createDriver(void* sharedContext,
            const Platform::DriverConfig& driverConfig) noexcept override;

    // Currently returns 0
    int getOSVersion() const noexcept override;

    bool pumpEvents() noexcept override;

    // --------------------------------------------------------------------------------------------
    // OpenGLPlatform Interface

    bool isExtraContextSupported() const noexcept override;
    void createContext(bool shared) override;

    void terminate() noexcept override;

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
    PlatformCocoaGLImpl* pImpl = nullptr;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_COCOA_GL_H

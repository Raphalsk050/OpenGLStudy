
#ifndef TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_EGL_H
#define TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_EGL_H

#include <backend/DriverEnums.h>
#include <backend/Platform.h>
#include <backend/platforms/OpenGLPlatform.h>

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>

#include "third_party/filament/libs/utils/include/utils/Invocable.h"

#include <initializer_list>
#include <utility>
#include <vector>

#include <stddef.h>
#include <stdint.h>

namespace filament::backend {

class PlatformEGL : public OpenGLPlatform {
public:

    PlatformEGL() noexcept;

    // Return true if we're on an OpenGL platform (as opposed to OpenGL ES). false by default.
    virtual bool isOpenGL() const noexcept;

protected:
    // --------------------------------------------------------------------------------------------
    // Helper for EGL configs and attributes parameters

    class Config {
    public:
        Config();
        Config(std::initializer_list<std::pair<EGLint, EGLint>> list);
        EGLint& operator[](EGLint name);
        EGLint operator[](EGLint name) const;
        void erase(EGLint name) noexcept;
        EGLint const* data() const noexcept {
            return reinterpret_cast<EGLint const*>(mConfig.data());
        }
        size_t size() const noexcept {
            return mConfig.size();
        }
    private:
        std::vector<std::pair<EGLint, EGLint>> mConfig = {{ EGL_NONE, EGL_NONE }};
    };

    // --------------------------------------------------------------------------------------------
    // Platform Interface

    Driver* createDriver(void* sharedContext,
            const Platform::DriverConfig& driverConfig) noexcept override;

    int getOSVersion() const noexcept override;

    // --------------------------------------------------------------------------------------------
    // OpenGLPlatform Interface

    bool isExtraContextSupported() const noexcept override;
    void createContext(bool shared) override;
    void releaseContext() noexcept override;

    void terminate() noexcept override;

    bool isProtectedContextSupported() const noexcept override;

    bool isSRGBSwapChainSupported() const noexcept override;
    SwapChain* createSwapChain(void* nativewindow, uint64_t flags) noexcept override;
    SwapChain* createSwapChain(uint32_t width, uint32_t height, uint64_t flags) noexcept override;
    void destroySwapChain(SwapChain* swapChain) noexcept override;
    bool isSwapChainProtected(SwapChain* swapChain) noexcept override;

    ContextType getCurrentContextType() const noexcept override;

    bool makeCurrent(ContextType type,
            SwapChain* drawSwapChain,
            SwapChain* readSwapChain) noexcept override;

    void makeCurrent(SwapChain* drawSwapChain, SwapChain* readSwapChain,
            utils::Invocable<void()> preContextChange,
            utils::Invocable<void(size_t index)> postContextChange) noexcept override;

    void commit(SwapChain* swapChain) noexcept override;

    bool canCreateFence() noexcept override;
    Fence* createFence() noexcept override;
    void destroyFence(Fence* fence) noexcept override;
    FenceStatus waitFence(Fence* fence, uint64_t timeout) noexcept override;

    OpenGLPlatform::ExternalTexture* createExternalImageTexture() noexcept override;
    void destroyExternalImage(ExternalTexture* texture) noexcept override;
    bool setExternalImage(void* externalImage, ExternalTexture* texture) noexcept override;

    static void logEglError(const char* name) noexcept;
    static void logEglError(const char* name, EGLint error) noexcept;
    static const char* getEglErrorName(EGLint error) noexcept;

    static void clearGlError() noexcept;


    EGLContext getContextForType(ContextType type) const noexcept;

    // makes the draw and read surface current without changing the current context
    EGLBoolean makeCurrent(EGLSurface drawSurface, EGLSurface readSurface) noexcept {
        return egl.makeCurrent(drawSurface, readSurface);
    }

    // makes context current and set draw and read surfaces to EGL_NO_SURFACE
    EGLBoolean makeCurrent(EGLContext context) noexcept {
        return egl.makeCurrent(context, mEGLDummySurface, mEGLDummySurface);
    }

    // TODO: this should probably use getters instead.
    EGLDisplay mEGLDisplay = EGL_NO_DISPLAY;
    EGLContext mEGLContext = EGL_NO_CONTEXT;
    EGLContext mEGLContextProtected = EGL_NO_CONTEXT;
    EGLSurface mEGLDummySurface = EGL_NO_SURFACE;
    ContextType mCurrentContextType = ContextType::NONE;
    // mEGLConfig is valid only if ext.egl.KHR_no_config_context is false
    EGLConfig mEGLConfig = EGL_NO_CONFIG_KHR;
    Config mContextAttribs;
    std::vector<EGLContext> mAdditionalContexts;

    // supported extensions detected at runtime
    struct {
        struct {
            bool OES_EGL_image_external_essl3 = false;
        } gl;
        struct {
            bool ANDROID_recordable = false;
            bool KHR_create_context = false;
            bool KHR_gl_colorspace = false;
            bool KHR_no_config_context = false;
            bool KHR_surfaceless_context = false;
            bool EXT_protected_content = false;
        } egl;
    } ext;

    struct SwapChainEGL : public Platform::SwapChain {
        EGLSurface sur = EGL_NO_SURFACE;
        Config attribs{};
        EGLNativeWindowType nativeWindow{};
        EGLConfig config{};
        uint64_t flags{};
    };

    void initializeGlExtensions() noexcept;

protected:
    EGLConfig findSwapChainConfig(uint64_t flags, bool window, bool pbuffer) const;

private:
    class EGL {
        EGLDisplay& mEGLDisplay;
        EGLSurface mCurrentDrawSurface = EGL_NO_SURFACE;
        EGLSurface mCurrentReadSurface = EGL_NO_SURFACE;
        EGLContext mCurrentContext = EGL_NO_CONTEXT;
    public:
        explicit EGL(EGLDisplay& dpy) : mEGLDisplay(dpy) {}
        EGLBoolean makeCurrent(EGLContext context,
                EGLSurface drawSurface, EGLSurface readSurface) noexcept;

        EGLBoolean makeCurrent(EGLSurface drawSurface, EGLSurface readSurface) noexcept {
            return makeCurrent(mCurrentContext, drawSurface, readSurface);
        }
    } egl{ mEGLDisplay };
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_EGL_H

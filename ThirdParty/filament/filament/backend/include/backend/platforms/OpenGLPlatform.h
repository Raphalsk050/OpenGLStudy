
#ifndef TNT_FILAMENT_BACKEND_PRIVATE_OPENGLPLATFORM_H
#define TNT_FILAMENT_BACKEND_PRIVATE_OPENGLPLATFORM_H

#include <backend/AcquiredImage.h>
#include <backend/DriverEnums.h>
#include <backend/Platform.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Invocable.h"

#include <stddef.h>
#include <stdint.h>

namespace filament::backend {

class Driver;

class OpenGLPlatform : public Platform {
protected:

    static Driver* UTILS_NULLABLE createDefaultDriver(OpenGLPlatform* UTILS_NONNULL platform,
            void* UTILS_NULLABLE sharedContext, const DriverConfig& driverConfig);

    ~OpenGLPlatform() noexcept override;

public:

    struct ExternalTexture {
        unsigned int target;            // GLenum target
        unsigned int id;                // GLuint id
    };

    virtual void terminate() noexcept = 0;

    virtual bool isSRGBSwapChainSupported() const noexcept;

    virtual bool isProtectedContextSupported() const noexcept;

    virtual SwapChain* UTILS_NULLABLE createSwapChain(
            void* UTILS_NULLABLE nativeWindow, uint64_t flags) noexcept = 0;

    virtual SwapChain* UTILS_NULLABLE createSwapChain(
            uint32_t width, uint32_t height, uint64_t flags) noexcept = 0;

    virtual void destroySwapChain(SwapChain* UTILS_NONNULL swapChain) noexcept = 0;

    virtual TargetBufferFlags getPreservedFlags(SwapChain* UTILS_NONNULL swapChain) noexcept;

    virtual bool isSwapChainProtected(Platform::SwapChain* UTILS_NONNULL swapChain) noexcept;

    virtual uint32_t getDefaultFramebufferObject() noexcept;

    virtual void beginFrame(
            int64_t monotonic_clock_ns,
            int64_t refreshIntervalNs,
            uint32_t frameId) noexcept;

    virtual void endFrame(
            uint32_t frameId) noexcept;

    enum class ContextType {
        NONE,           //!< No current context
        UNPROTECTED,    //!< current context is unprotected
        PROTECTED       //!< current context supports protected content
    };

    virtual ContextType getCurrentContextType() const noexcept;

    virtual bool makeCurrent(ContextType type,
            SwapChain* UTILS_NONNULL drawSwapChain,
            SwapChain* UTILS_NONNULL readSwapChain) noexcept = 0;

    virtual void makeCurrent(
            SwapChain* UTILS_NONNULL drawSwapChain,
            SwapChain* UTILS_NONNULL readSwapChain,
            utils::Invocable<void()> preContextChange,
            utils::Invocable<void(size_t index)> postContextChange) noexcept;

    virtual void preCommit() noexcept;

    virtual void commit(SwapChain* UTILS_NONNULL swapChain) noexcept = 0;

    virtual void setPresentationTime(int64_t presentationTimeInNanosecond) noexcept;

    // --------------------------------------------------------------------------------------------
    // Fence support

    virtual bool canCreateFence() noexcept;

    virtual Fence* UTILS_NULLABLE createFence() noexcept;

    virtual void destroyFence(Fence* UTILS_NONNULL fence) noexcept;

    virtual backend::FenceStatus waitFence(Fence* UTILS_NONNULL fence, uint64_t timeout) noexcept;


    // --------------------------------------------------------------------------------------------
    // Streaming support

    virtual Stream* UTILS_NULLABLE createStream(void* UTILS_NULLABLE nativeStream) noexcept;

    virtual void destroyStream(Stream* UTILS_NONNULL stream) noexcept;

    virtual void attach(Stream* UTILS_NONNULL stream, intptr_t tname) noexcept;

    virtual void detach(Stream* UTILS_NONNULL stream) noexcept;

    virtual void updateTexImage(Stream* UTILS_NONNULL stream,
            int64_t* UTILS_NONNULL timestamp) noexcept;


    // --------------------------------------------------------------------------------------------
    // External Image support

    virtual ExternalTexture* UTILS_NULLABLE createExternalImageTexture() noexcept;

    virtual void destroyExternalImage(ExternalTexture* UTILS_NONNULL texture) noexcept;

    // called on the application thread to allow Filament to take ownership of the image

    virtual void retainExternalImage(void* UTILS_NONNULL externalImage) noexcept;

    virtual bool setExternalImage(void* UTILS_NONNULL externalImage,
            ExternalTexture* UTILS_NONNULL texture) noexcept;

    virtual AcquiredImage transformAcquiredImage(AcquiredImage source) noexcept;

    // --------------------------------------------------------------------------------------------

    virtual bool isExtraContextSupported() const noexcept;

    virtual void createContext(bool shared);

    virtual void releaseContext() noexcept;
};

} // namespace filament

#endif // TNT_FILAMENT_BACKEND_PRIVATE_OPENGLPLATFORM_H

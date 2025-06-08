
#include <backend/platforms/OpenGLPlatform.h>

#include "OpenGLDriverFactory.h"

#include <backend/AcquiredImage.h>
#include <backend/DriverEnums.h>
#include <backend/Platform.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/utils/include/utils/Invocable.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

namespace filament::backend {

Driver* OpenGLPlatform::createDefaultDriver(OpenGLPlatform* platform,
        void* sharedContext, const Platform::DriverConfig& driverConfig) {
    return OpenGLDriverFactory::create(platform, sharedContext, driverConfig);
}

OpenGLPlatform::~OpenGLPlatform() noexcept = default;

void OpenGLPlatform::makeCurrent(SwapChain* drawSwapChain, SwapChain* readSwapChain,
        utils::Invocable<void()>, utils::Invocable<void(size_t)>) noexcept {
    makeCurrent(getCurrentContextType(), drawSwapChain, readSwapChain);
}

bool OpenGLPlatform::isProtectedContextSupported() const noexcept {
    return false;
}

bool OpenGLPlatform::isSRGBSwapChainSupported() const noexcept {
    return false;
}

uint32_t OpenGLPlatform::getDefaultFramebufferObject() noexcept {
    return 0;
}

void OpenGLPlatform::beginFrame(int64_t monotonic_clock_ns, int64_t refreshIntervalNs,
        uint32_t frameId) noexcept {
}

void OpenGLPlatform::endFrame(uint32_t frameId) noexcept {
}

void OpenGLPlatform::preCommit() noexcept {
}

OpenGLPlatform::ContextType OpenGLPlatform::getCurrentContextType() const noexcept {
    return ContextType::UNPROTECTED;
}

void OpenGLPlatform::setPresentationTime(
        UTILS_UNUSED int64_t presentationTimeInNanosecond) noexcept {
}


bool OpenGLPlatform::canCreateFence() noexcept {
    return false;
}

Platform::Fence* OpenGLPlatform::createFence() noexcept {
    return nullptr;
}

void OpenGLPlatform::destroyFence(
        UTILS_UNUSED Fence* fence) noexcept {
}

FenceStatus OpenGLPlatform::waitFence(
        UTILS_UNUSED Fence* fence,
        UTILS_UNUSED uint64_t timeout) noexcept {
    return FenceStatus::ERROR;
}


Platform::Stream* OpenGLPlatform::createStream(
        UTILS_UNUSED void* nativeStream) noexcept {
    return nullptr;
}

void OpenGLPlatform::destroyStream(
        UTILS_UNUSED Stream* stream) noexcept {
}

void OpenGLPlatform::attach(
        UTILS_UNUSED Stream* stream,
        UTILS_UNUSED intptr_t tname) noexcept {
}

void OpenGLPlatform::detach(
        UTILS_UNUSED Stream* stream) noexcept {
}

void OpenGLPlatform::updateTexImage(
        UTILS_UNUSED Stream* stream,
        UTILS_UNUSED int64_t* timestamp) noexcept {
}


OpenGLPlatform::ExternalTexture* OpenGLPlatform::createExternalImageTexture() noexcept {
    return nullptr;
}

void OpenGLPlatform::destroyExternalImage(
        UTILS_UNUSED ExternalTexture* texture) noexcept {
}

void OpenGLPlatform::retainExternalImage(
        UTILS_UNUSED void* externalImage) noexcept {
}

bool OpenGLPlatform::setExternalImage(
        UTILS_UNUSED void* externalImage,
        UTILS_UNUSED ExternalTexture* texture) noexcept {
    return false;
}

AcquiredImage OpenGLPlatform::transformAcquiredImage(AcquiredImage source) noexcept {
    return source;
}

TargetBufferFlags OpenGLPlatform::getPreservedFlags(UTILS_UNUSED SwapChain*) noexcept {
    return TargetBufferFlags::NONE;
}

bool OpenGLPlatform::isSwapChainProtected(UTILS_UNUSED SwapChain*) noexcept {
    return false;
}

bool OpenGLPlatform::isExtraContextSupported() const noexcept {
    return false;
}

void OpenGLPlatform::createContext(bool) {
}

void OpenGLPlatform::releaseContext() noexcept {
}

} // namespace filament::backend

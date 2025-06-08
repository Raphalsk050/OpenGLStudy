
#include "details/SwapChain.h"

#include "details/Engine.h"

#include <filament/SwapChain.h>

#include <backend/CallbackHandler.h>

#include "third_party/filament/libs/utils/include/utils/Invocable.h"

#include <new>
#include <utility>

#include <stdint.h>

namespace filament {

FSwapChain::FSwapChain(FEngine& engine, void* nativeWindow, uint64_t flags)
        : mEngine(engine), mNativeWindow(nativeWindow), mConfigFlags(initFlags(engine, flags)) {
    mHwSwapChain = engine.getDriverApi().createSwapChain(nativeWindow, flags);
}

FSwapChain::FSwapChain(FEngine& engine, uint32_t width, uint32_t height, uint64_t flags)
        : mEngine(engine), mWidth(width), mHeight(height), mConfigFlags(initFlags(engine, flags)) {
    mHwSwapChain = engine.getDriverApi().createSwapChainHeadless(width, height, flags);
}

void FSwapChain::recreateWithNewFlags(FEngine& engine, uint64_t flags) noexcept {
    flags = initFlags(engine, flags);
    if (flags != mConfigFlags) {
        FEngine::DriverApi& driver = engine.getDriverApi();
        driver.destroySwapChain(mHwSwapChain);
        mConfigFlags = flags;
        if (mNativeWindow) {
            mHwSwapChain = driver.createSwapChain(mNativeWindow, flags);
        } else {
            mHwSwapChain = driver.createSwapChainHeadless(mWidth, mHeight, flags);
        }
    }
}

uint64_t FSwapChain::initFlags(FEngine& engine, uint64_t flags) noexcept {
    if (!isSRGBSwapChainSupported(engine)) {
        flags &= ~CONFIG_SRGB_COLORSPACE;
    }
    if (!isProtectedContentSupported(engine)) {
        flags &= ~CONFIG_PROTECTED_CONTENT;
    }
    return flags;
}

void FSwapChain::terminate(FEngine& engine) noexcept {
    engine.getDriverApi().destroySwapChain(mHwSwapChain);
}

void FSwapChain::setFrameScheduledCallback(
        backend::CallbackHandler* handler, FrameScheduledCallback&& callback) {
    mFrameScheduledCallbackIsSet = bool(callback);
    mEngine.getDriverApi().setFrameScheduledCallback(mHwSwapChain, handler, std::move(callback));
}

bool FSwapChain::isFrameScheduledCallbackSet() const noexcept {
    return mFrameScheduledCallbackIsSet;
}

void FSwapChain::setFrameCompletedCallback(
        backend::CallbackHandler* handler, FrameCompletedCallback&& callback) noexcept {
    using namespace std::placeholders;
    auto boundCallback = std::bind(std::move(callback), this);
    mEngine.getDriverApi().setFrameCompletedCallback(mHwSwapChain, handler, std::move(boundCallback));
}

bool FSwapChain::isSRGBSwapChainSupported(FEngine& engine) noexcept {
    return engine.getDriverApi().isSRGBSwapChainSupported();
}

bool FSwapChain::isProtectedContentSupported(FEngine& engine) noexcept {
    return engine.getDriverApi().isProtectedContentSupported();
}

} // namespace filament

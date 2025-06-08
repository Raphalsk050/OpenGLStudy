
#include "details/SwapChain.h"

#include "details/Engine.h"

#include <backend/CallbackHandler.h>

#include <utility>

namespace filament {

void* SwapChain::getNativeWindow() const noexcept {
    return downcast(this)->getNativeWindow();
}

void SwapChain::setFrameScheduledCallback(
        backend::CallbackHandler* handler, FrameScheduledCallback&& callback) {
    downcast(this)->setFrameScheduledCallback(handler, std::move(callback));
}

bool SwapChain::isFrameScheduledCallbackSet() const noexcept {
    return downcast(this)->isFrameScheduledCallbackSet();
}

void SwapChain::setFrameCompletedCallback(backend::CallbackHandler* handler,
            utils::Invocable<void(SwapChain*)>&& callback) noexcept {
    return downcast(this)->setFrameCompletedCallback(handler, std::move(callback));
}

bool SwapChain::isSRGBSwapChainSupported(Engine& engine) noexcept {
    return FSwapChain::isSRGBSwapChainSupported(downcast(engine));
}

bool SwapChain::isProtectedContentSupported(Engine& engine) noexcept {
    return FSwapChain::isProtectedContentSupported(downcast(engine));
}

} // namespace filament

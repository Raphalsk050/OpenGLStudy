
#ifndef TNT_FILAMENT_SWAPCHAIN_H
#define TNT_FILAMENT_SWAPCHAIN_H

#include <filament/FilamentAPI.h>

#include <backend/CallbackHandler.h>
#include <backend/DriverEnums.h>
#include <backend/PresentCallable.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Invocable.h"

#include <stdint.h>

namespace filament {

class Engine;

class UTILS_PUBLIC SwapChain : public FilamentAPI {
public:
    using FrameScheduledCallback = backend::FrameScheduledCallback;
    using FrameCompletedCallback = utils::Invocable<void(SwapChain* UTILS_NONNULL)>;

    static const uint64_t CONFIG_TRANSPARENT = backend::SWAP_CHAIN_CONFIG_TRANSPARENT;

    static const uint64_t CONFIG_READABLE = backend::SWAP_CHAIN_CONFIG_READABLE;

    static const uint64_t CONFIG_ENABLE_XCB = backend::SWAP_CHAIN_CONFIG_ENABLE_XCB;

    static const uint64_t CONFIG_APPLE_CVPIXELBUFFER =
            backend::SWAP_CHAIN_CONFIG_APPLE_CVPIXELBUFFER;

    static constexpr uint64_t CONFIG_SRGB_COLORSPACE = backend::SWAP_CHAIN_CONFIG_SRGB_COLORSPACE;

    static constexpr uint64_t CONFIG_HAS_STENCIL_BUFFER = backend::SWAP_CHAIN_CONFIG_HAS_STENCIL_BUFFER;

    static constexpr uint64_t CONFIG_PROTECTED_CONTENT = backend::SWAP_CHAIN_CONFIG_PROTECTED_CONTENT;

    static bool isProtectedContentSupported(Engine& engine) noexcept;

    static bool isSRGBSwapChainSupported(Engine& engine) noexcept;

    void* UTILS_NULLABLE getNativeWindow() const noexcept;

    void setFrameScheduledCallback(backend::CallbackHandler* UTILS_NULLABLE handler = nullptr,
            FrameScheduledCallback&& callback = {});

    bool isFrameScheduledCallbackSet() const noexcept;

    void setFrameCompletedCallback(backend::CallbackHandler* UTILS_NULLABLE handler = nullptr,
            FrameCompletedCallback&& callback = {}) noexcept;


protected:
    // prevent heap allocation
    ~SwapChain() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_SWAPCHAIN_H

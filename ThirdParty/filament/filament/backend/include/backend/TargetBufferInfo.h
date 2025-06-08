
#ifndef TNT_FILAMENT_BACKEND_TARGETBUFFERINFO_H
#define TNT_FILAMENT_BACKEND_TARGETBUFFERINFO_H

#include <backend/Handle.h>

#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include <stddef.h>
#include <stdint.h>

namespace filament::backend {

//! \privatesection

struct TargetBufferInfo {
    // note: the parameters of this constructor are not in the order of this structure's fields
    TargetBufferInfo(Handle<HwTexture> handle, uint8_t level, uint16_t layer, uint8_t baseViewIndex) noexcept
        : handle(handle), baseViewIndex(baseViewIndex), level(level), layer(layer) {
    }

    TargetBufferInfo(Handle<HwTexture> handle, uint8_t level, uint16_t layer) noexcept
            : handle(handle), level(level), layer(layer) {
    }

    TargetBufferInfo(Handle<HwTexture> handle, uint8_t level) noexcept
            : handle(handle), level(level) {
    }

    TargetBufferInfo(Handle<HwTexture> handle) noexcept // NOLINT(*-explicit-constructor)
            : handle(handle) {
    }

    TargetBufferInfo() noexcept = default;

    // texture to be used as render target
    Handle<HwTexture> handle;

    // Starting layer index for multiview. This value is only used when the `layerCount` for the
    // render target is greater than 1.
    uint8_t baseViewIndex = 0;

    // level to be used
    uint8_t level = 0;

    // For cubemaps and 3D textures. See TextureCubemapFace for the face->layer mapping
    uint16_t layer = 0;
};

class MRT {
public:
    static constexpr uint8_t MIN_SUPPORTED_RENDER_TARGET_COUNT = 4u;

    // When updating this, make sure to also take care of RenderTarget.java
    static constexpr uint8_t MAX_SUPPORTED_RENDER_TARGET_COUNT = 8u;

private:
    TargetBufferInfo mInfos[MAX_SUPPORTED_RENDER_TARGET_COUNT];

public:
    TargetBufferInfo const& operator[](size_t i) const noexcept {
        return mInfos[i];
    }

    TargetBufferInfo& operator[](size_t i) noexcept {
        return mInfos[i];
    }

    MRT() noexcept = default;

    MRT(TargetBufferInfo const& color) noexcept // NOLINT(hicpp-explicit-conversions, *-explicit-constructor)
            : mInfos{ color } {
    }

    MRT(TargetBufferInfo const& color0, TargetBufferInfo const& color1) noexcept
            : mInfos{ color0, color1 } {
    }

    MRT(TargetBufferInfo const& color0, TargetBufferInfo const& color1,
        TargetBufferInfo const& color2) noexcept
            : mInfos{ color0, color1, color2 } {
    }

    MRT(TargetBufferInfo const& color0, TargetBufferInfo const& color1,
        TargetBufferInfo const& color2, TargetBufferInfo const& color3) noexcept
            : mInfos{ color0, color1, color2, color3 } {
    }

    // this is here for backward compatibility
    MRT(Handle<HwTexture> handle, uint8_t level, uint16_t layer) noexcept
            : mInfos{{ handle, level, layer, 0 }} {
    }
};

} // namespace filament::backend

#if !defined(NDEBUG)
utils::io::ostream& operator<<(utils::io::ostream& out, const filament::backend::TargetBufferInfo& tbi);
utils::io::ostream& operator<<(utils::io::ostream& out, const filament::backend::MRT& mrt);
#endif

#endif //TNT_FILAMENT_BACKEND_TARGETBUFFERINFO_H

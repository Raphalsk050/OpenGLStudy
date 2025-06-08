
//! \file

#ifndef TNT_FILAMENT_RENDERTARGET_H
#define TNT_FILAMENT_RENDERTARGET_H

#include <filament/FilamentAPI.h>

#include <backend/DriverEnums.h>
#include <backend/TargetBufferInfo.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <stddef.h>
#include <stdint.h>

namespace filament {

class FRenderTarget;

class Engine;
class Texture;

class UTILS_PUBLIC RenderTarget : public FilamentAPI {
    struct BuilderDetails;

public:
    using CubemapFace = backend::TextureCubemapFace;

    static constexpr uint8_t MAX_SUPPORTED_COLOR_ATTACHMENTS_COUNT =
            backend::MRT::MAX_SUPPORTED_RENDER_TARGET_COUNT;

    enum class AttachmentPoint : uint8_t {
        COLOR0 = 0,          //!< identifies the 1st color attachment
        COLOR1 = 1,          //!< identifies the 2nd color attachment
        COLOR2 = 2,          //!< identifies the 3rd color attachment
        COLOR3 = 3,          //!< identifies the 4th color attachment
        COLOR4 = 4,          //!< identifies the 5th color attachment
        COLOR5 = 5,          //!< identifies the 6th color attachment
        COLOR6 = 6,          //!< identifies the 7th color attachment
        COLOR7 = 7,          //!< identifies the 8th color attachment
        DEPTH  = MAX_SUPPORTED_COLOR_ATTACHMENTS_COUNT,   //!< identifies the depth attachment
        COLOR  = COLOR0,     //!< identifies the 1st color attachment
    };

    //! Use Builder to construct a RenderTarget object instance
    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& texture(AttachmentPoint attachment, Texture* UTILS_NULLABLE texture) noexcept;

        Builder& mipLevel(AttachmentPoint attachment, uint8_t level) noexcept;

        Builder& face(AttachmentPoint attachment, CubemapFace face) noexcept;

        Builder& layer(AttachmentPoint attachment, uint32_t layer) noexcept;

        RenderTarget* UTILS_NONNULL build(Engine& engine);

    private:
        friend class FRenderTarget;
    };

    Texture* UTILS_NULLABLE getTexture(AttachmentPoint attachment) const noexcept;

    uint8_t getMipLevel(AttachmentPoint attachment) const noexcept;

    CubemapFace getFace(AttachmentPoint attachment) const noexcept;

    uint32_t getLayer(AttachmentPoint attachment) const noexcept;

    uint8_t getSupportedColorAttachmentsCount() const noexcept;

protected:
    // prevent heap allocation
    ~RenderTarget() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_RENDERTARGET_H

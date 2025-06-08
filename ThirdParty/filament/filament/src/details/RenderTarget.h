
#ifndef TNT_FILAMENT_DETAILS_RENDERTAGET_H
#define TNT_FILAMENT_DETAILS_RENDERTAGET_H

#include "downcast.h"

#include <backend/Handle.h>

#include <filament/RenderTarget.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament {

class FEngine;
class FTexture;

class FRenderTarget : public RenderTarget {
public:
    using HwHandle = backend::Handle<backend::HwRenderTarget>;

    struct Attachment {
        FTexture* texture = nullptr;
        uint8_t mipLevel = 0;
        CubemapFace face = RenderTarget::CubemapFace::POSITIVE_X;
        uint32_t layer = 0;
    };

    FRenderTarget(FEngine& engine, const Builder& builder);

    void terminate(FEngine& engine);

    HwHandle getHwHandle() const noexcept { return mHandle; }

    Attachment getAttachment(AttachmentPoint attachment) const noexcept {
        return mAttachments[(int) attachment];
    }

    backend::TargetBufferFlags getAttachmentMask() const noexcept {
        return mAttachmentMask;
    }

    backend::TargetBufferFlags getSampleableAttachmentsMask() const noexcept {
        return mSampleableAttachmentsMask;
    }

    uint8_t getSupportedColorAttachmentsCount() const noexcept {
        return mSupportedColorAttachmentsCount;
    }

    bool hasSampleableDepth() const noexcept;

private:
    friend class RenderTarget;
    static constexpr size_t ATTACHMENT_COUNT = MAX_SUPPORTED_COLOR_ATTACHMENTS_COUNT + 1u;
    Attachment mAttachments[ATTACHMENT_COUNT];
    HwHandle mHandle{};
    backend::TargetBufferFlags mAttachmentMask = {};
    backend::TargetBufferFlags mSampleableAttachmentsMask = {};
    const uint8_t mSupportedColorAttachmentsCount;
};

FILAMENT_DOWNCAST(RenderTarget)

} // namespace filament

#endif // TNT_FILAMENT_DETAILS_RENDERTARGET_H

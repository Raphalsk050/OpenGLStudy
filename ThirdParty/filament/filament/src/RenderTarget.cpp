
#include "details/RenderTarget.h"

#include "details/Texture.h"

namespace filament {

using namespace backend;

Texture* RenderTarget::getTexture(AttachmentPoint attachment) const noexcept {
    return downcast(this)->getAttachment(attachment).texture;
}

uint8_t RenderTarget::getMipLevel(AttachmentPoint attachment) const noexcept {
    return downcast(this)->getAttachment(attachment).mipLevel;
}

RenderTarget::CubemapFace RenderTarget::getFace(AttachmentPoint attachment) const noexcept {
    return downcast(this)->getAttachment(attachment).face;
}

uint32_t RenderTarget::getLayer(AttachmentPoint attachment) const noexcept {
    return downcast(this)->getAttachment(attachment).layer;
}

uint8_t RenderTarget::getSupportedColorAttachmentsCount() const noexcept {
    return downcast(this)->getSupportedColorAttachmentsCount();
}

} // namespace filament

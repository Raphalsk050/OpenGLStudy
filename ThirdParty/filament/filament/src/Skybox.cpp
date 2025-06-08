
#include "details/Skybox.h"

#include "details/Texture.h"

namespace filament {

void Skybox::setLayerMask(uint8_t select, uint8_t values) noexcept {
    downcast(this)->setLayerMask(select, values);
}

uint8_t Skybox::getLayerMask() const noexcept {
    return downcast(this)->getLayerMask();
}

float Skybox::getIntensity() const noexcept {
    return downcast(this)->getIntensity();
}

void Skybox::setColor(math::float4 color) noexcept {
    downcast(this)->setColor(color);
}

Texture const* Skybox::getTexture() const noexcept {
    return downcast(this)->getTexture();
}

} // namespace filament

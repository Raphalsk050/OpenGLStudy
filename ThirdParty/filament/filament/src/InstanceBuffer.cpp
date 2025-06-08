
#include "details/InstanceBuffer.h"

namespace filament {

size_t InstanceBuffer::getInstanceCount() const noexcept {
    return downcast(this)->getInstanceCount();
}

void InstanceBuffer::setLocalTransforms(
        math::mat4f const* localTransforms, size_t count, size_t offset) {
    downcast(this)->setLocalTransforms(localTransforms, count, offset);
}

} // namespace filament

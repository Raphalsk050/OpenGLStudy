
#include "details/BufferObject.h"

#include "details/Engine.h"

#include "FilamentAPI-impl.h"

namespace filament {

void BufferObject::setBuffer(Engine& engine,
        BufferObject::BufferDescriptor&& buffer, uint32_t byteOffset) {
    downcast(this)->setBuffer(downcast(engine), std::move(buffer), byteOffset);
}

size_t BufferObject::getByteCount() const noexcept {
    return downcast(this)->getByteCount();
}

} // namespace filament

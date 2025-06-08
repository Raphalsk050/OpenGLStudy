
#include "details/IndexBuffer.h"

#include "details/Engine.h"

namespace filament {

void IndexBuffer::setBuffer(Engine& engine,
        IndexBuffer::BufferDescriptor&& buffer, uint32_t byteOffset) {
    downcast(this)->setBuffer(downcast(engine), std::move(buffer), byteOffset);
}

size_t IndexBuffer::getIndexCount() const noexcept {
    return downcast(this)->getIndexCount();
}

} // namespace filament

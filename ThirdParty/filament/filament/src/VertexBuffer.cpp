
#include "details/VertexBuffer.h"

#include "details/Engine.h"

namespace filament {

size_t VertexBuffer::getVertexCount() const noexcept {
    return downcast(this)->getVertexCount();
}

void VertexBuffer::setBufferAt(Engine& engine, uint8_t bufferIndex,
        backend::BufferDescriptor&& buffer, uint32_t byteOffset) {
    downcast(this)->setBufferAt(downcast(engine), bufferIndex, std::move(buffer), byteOffset);
}

void VertexBuffer::setBufferObjectAt(Engine& engine, uint8_t bufferIndex,
        BufferObject const* bufferObject) {
    downcast(this)->setBufferObjectAt(downcast(engine), bufferIndex, downcast(bufferObject));
}

} // namespace filament

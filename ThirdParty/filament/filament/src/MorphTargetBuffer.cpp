
#include "details/MorphTargetBuffer.h"

#include "details/Engine.h"

namespace filament {

void MorphTargetBuffer::setPositionsAt(Engine& engine, size_t targetIndex,
        math::float3 const* positions, size_t count, size_t offset) {
    downcast(this)->setPositionsAt(downcast(engine), targetIndex, positions, count, offset);
}

void MorphTargetBuffer::setPositionsAt(Engine& engine, size_t targetIndex,
        math::float4 const* positions, size_t count, size_t offset) {
    downcast(this)->setPositionsAt(downcast(engine), targetIndex, positions, count, offset);
}

void MorphTargetBuffer::setTangentsAt(Engine& engine, size_t targetIndex,
        math::short4 const* tangents, size_t count, size_t offset) {
    downcast(this)->setTangentsAt(downcast(engine), targetIndex, tangents, count, offset);
}

size_t MorphTargetBuffer::getVertexCount() const noexcept {
    return downcast(this)->getVertexCount();
}

size_t MorphTargetBuffer::getCount() const noexcept {
    return downcast(this)->getCount();
}

} // namespace filament


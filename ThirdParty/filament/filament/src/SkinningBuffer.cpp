
#include "details/SkinningBuffer.h"

#include "details/Engine.h"

namespace filament {

using namespace backend;
using namespace math;

void SkinningBuffer::setBones(Engine& engine,
        RenderableManager::Bone const* transforms, size_t count, size_t offset) {
    downcast(this)->setBones(downcast(engine), transforms, count, offset);
}

void SkinningBuffer::setBones(Engine& engine,
        math::mat4f const* transforms, size_t count, size_t offset) {
    downcast(this)->setBones(downcast(engine), transforms, count, offset);
}

size_t SkinningBuffer::getBoneCount() const noexcept {
    return downcast(this)->getBoneCount();
}

} // namespace filament


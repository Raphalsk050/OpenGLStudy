
#include "private/backend/SamplerGroup.h"

#include "private/backend/DriverApi.h"

#include "backend/BufferDescriptor.h"

namespace filament::backend {

// create a sampler buffer
SamplerGroup::SamplerGroup(size_t count) noexcept
        : mBuffer(count) {
}

SamplerGroup::SamplerGroup(const SamplerGroup& rhs) noexcept :
    mBuffer(rhs.mBuffer), mDirty(true) {
}

SamplerGroup& SamplerGroup::operator=(const SamplerGroup& rhs) noexcept {
    if (this != &rhs) {
        mBuffer = rhs.mBuffer;
        mDirty = true;
    }
    return *this;
}

void SamplerGroup::setSampler(size_t index, SamplerDescriptor sampler) noexcept {
    if (UTILS_LIKELY(index < mBuffer.size())) {
        // We cannot compare two texture handles to determine if an update is needed. Texture
        // handles are (quickly) recycled and therefore can't be used for that purpose. e.g. if a
        // texture is destroyed, its handle could be reused quickly by another texture.
        // TODO: find a way to avoid marking dirty if the texture does not change.
        mBuffer[index] = sampler;
        mDirty = true;
    }
}

BufferDescriptor SamplerGroup::toBufferDescriptor(DriverApi& driver) const noexcept {
    BufferDescriptor p;
    p.size = mBuffer.size() * sizeof(SamplerDescriptor);
    p.buffer = driver.allocate(p.size); // TODO: use out-of-line buffer if too large
    memcpy(p.buffer, static_cast<const void*>(mBuffer.data()), p.size); // inlined
    clean();
    return p;
}

#if !defined(NDEBUG)
utils::io::ostream& operator<<(utils::io::ostream& out, const SamplerGroup& rhs) {
    return out << "SamplerGroup(size=" << rhs.getSize() << ")";
}
#endif

} // namespace filament::backend

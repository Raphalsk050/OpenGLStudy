
#ifndef TNT_FILAMENT_DETAILS_MORPHTARGETBUFFER_H
#define TNT_FILAMENT_DETAILS_MORPHTARGETBUFFER_H

#include "downcast.h"

#include <filament/MorphTargetBuffer.h>

#include "backend/DriverApiForward.h"

#include "private/backend/SamplerGroup.h"

#include <backend/Handle.h>

#include "third_party/filament/libs/utils/include/utils/Allocator.h"

#include <stddef.h>
#include <stdint.h>

namespace filament {

class FEngine;

class FMorphTargetBuffer : public MorphTargetBuffer {
public:
    class EmptyMorphTargetBuilder : public MorphTargetBuffer::Builder {
    public:
        EmptyMorphTargetBuilder();
    };

    FMorphTargetBuffer(FEngine& engine, const Builder& builder);

    // frees driver resources, object becomes invalid
    void terminate(FEngine& engine);

    void setPositionsAt(FEngine& engine, size_t targetIndex,
            math::float3 const* positions, size_t count, size_t offset);

    void setPositionsAt(FEngine& engine, size_t targetIndex,
            math::float4 const* positions, size_t count, size_t offset);

    void setTangentsAt(FEngine& engine, size_t targetIndex,
            math::short4 const* tangents, size_t count, size_t offset);

    inline size_t getVertexCount() const noexcept { return mVertexCount; }
    inline size_t getCount() const noexcept { return mCount; }

    backend::TextureHandle getPositionsHandle() const noexcept {
        return mPbHandle;
    }

    backend::TextureHandle getTangentsHandle() const noexcept {
        return mTbHandle;
    }

    inline backend::Handle<backend::HwSamplerGroup> getHwHandle() const noexcept { return mSbHandle; }

private:
    void updateDataAt(backend::DriverApi& driver, backend::Handle <backend::HwTexture> handle,
            backend::PixelDataFormat format, backend::PixelDataType type, const char* out,
            size_t elementSize, size_t targetIndex, size_t count, size_t offset);

    backend::Handle<backend::HwSamplerGroup> mSbHandle;
    backend::Handle<backend::HwTexture> mPbHandle;
    backend::Handle<backend::HwTexture> mTbHandle;
    size_t mVertexCount;
    size_t mCount;
};

FILAMENT_DOWNCAST(MorphTargetBuffer)

} // namespace filament

#endif //TNT_FILAMENT_DETAILS_MORPHTARGETBUFFER_H

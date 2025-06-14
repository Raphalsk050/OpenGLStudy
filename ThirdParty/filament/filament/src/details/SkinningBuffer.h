
#ifndef TNT_FILAMENT_DETAILS_SKINNINGBUFFER_H
#define TNT_FILAMENT_DETAILS_SKINNINGBUFFER_H

#include "downcast.h"
#include <filament/SkinningBuffer.h>

#include "private/filament/EngineEnums.h"
#include "private/filament/UibStructs.h"

#include <backend/DriverApiForward.h>

#include <backend/Handle.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/math/include/math/vec2.h"

// for gtest
class FilamentTest_Bones_Test;

namespace filament {

class FEngine;
class FRenderableManager;

class FSkinningBuffer : public SkinningBuffer {
public:
    FSkinningBuffer(FEngine& engine, const Builder& builder);

    // frees driver resources, object becomes invalid
    void terminate(FEngine& engine);

    void setBones(FEngine& engine, RenderableManager::Bone const* transforms, size_t count, size_t offset);
    void setBones(FEngine& engine, math::mat4f const* transforms, size_t count, size_t offset);
    size_t getBoneCount() const noexcept { return mBoneCount; }

    // round count to the size of the UBO in the shader
    static size_t getPhysicalBoneCount(size_t count) noexcept {
        static_assert((CONFIG_MAX_BONE_COUNT & (CONFIG_MAX_BONE_COUNT - 1)) == 0);
        return (count + CONFIG_MAX_BONE_COUNT - 1) & ~(CONFIG_MAX_BONE_COUNT - 1);
    }

    backend::Handle<backend::HwSamplerGroup> setIndicesAndWeights(FEngine& engine,
            math::float2 const* pairs, size_t count);

private:
    friend class ::FilamentTest_Bones_Test;
    friend class SkinningBuffer;
    friend class FRenderableManager;

    static void setBones(FEngine& engine, backend::Handle<backend::HwBufferObject> handle,
            RenderableManager::Bone const* transforms, size_t boneCount, size_t offset) noexcept;

    static void setBones(FEngine& engine, backend::Handle<backend::HwBufferObject> handle,
            math::mat4f const* transforms, size_t boneCount, size_t offset) noexcept;

    static PerRenderableBoneUib::BoneData makeBone(math::mat4f transform) noexcept;

    backend::Handle<backend::HwBufferObject> getHwHandle() const noexcept {
        return mHandle;
    }

    struct HandleIndicesAndWeights{
        backend::Handle<backend::HwSamplerGroup> sampler;
        backend::Handle<backend::HwTexture> texture;
    };
    static HandleIndicesAndWeights createIndicesAndWeightsHandle(FEngine& engine,
            size_t count);
    static void setIndicesAndWeightsData(FEngine& engine,
          backend::Handle<backend::HwTexture> textureHandle,
          const utils::FixedCapacityVector<math::float2>& pairs,
          size_t count);

    backend::Handle<backend::HwBufferObject> mHandle;
    uint32_t mBoneCount;
};

FILAMENT_DOWNCAST(SkinningBuffer)

} // namespace filament

#endif //TNT_FILAMENT_DETAILS_SKINNINGBUFFER_H

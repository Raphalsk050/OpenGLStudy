
#ifndef TNT_FILAMENT_DETAILS_INSTANCEBUFFER_H
#define TNT_FILAMENT_DETAILS_INSTANCEBUFFER_H

#include "downcast.h"

#include <filament/InstanceBuffer.h>

#include <backend/Handle.h>

#include "third_party/filament/libs/math/include/math/mat4.h"

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

namespace filament {

class FEngine;

struct PerRenderableData;

class FInstanceBuffer : public InstanceBuffer {
public:
    FInstanceBuffer(FEngine& engine, const Builder& builder);

    void terminate(FEngine& engine);

    inline size_t getInstanceCount() const noexcept { return mInstanceCount; }

    void setLocalTransforms(math::mat4f const* localTransforms, size_t count, size_t offset);

    void prepare(FEngine& engine, math::mat4f rootTransform, const PerRenderableData& ubo,
            backend::Handle<backend::HwBufferObject> handle);

private:
    friend class RenderableManager;

    utils::FixedCapacityVector<math::mat4f> mLocalTransforms;
    size_t mInstanceCount;
};

FILAMENT_DOWNCAST(InstanceBuffer)

} // namespace filament

#endif //TNT_FILAMENT_DETAILS_INSTANCEBUFFER_H

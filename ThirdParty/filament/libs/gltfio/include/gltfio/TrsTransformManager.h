
#ifndef GLTFIO_TRSTRANSFORMMANAGER_H
#define GLTFIO_TRSTRANSFORMMANAGER_H

#include <filament/FilamentAPI.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/EntityInstance.h"
#include "third_party/filament/libs/math/include/math/quat.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/mat4.h"

using namespace filament::math;

namespace utils {
class Entity;
} // namespace utils

namespace filament::gltfio {

class FTrsTransformManager;

class UTILS_PUBLIC TrsTransformManager {
public:
    using Instance = utils::EntityInstance<TrsTransformManager>;
    using Entity = utils::Entity;

    bool hasComponent(Entity e) const noexcept;

    Instance getInstance(Entity e) const noexcept;

    void create(Entity entity);
    void create(Entity entity, const float3& translation, const quatf& rotation,
            const float3& scale);  //!< \overload

    void destroy(Entity e) noexcept;

    void setTranslation(Instance ci, const float3& translation) noexcept;
    const float3& getTranslation(Instance ci) const noexcept;

    void setRotation(Instance ci, const quatf& rotation) noexcept;
    const quatf& getRotation(Instance ci) const noexcept;

    void setScale(Instance ci, const float3& scale) noexcept;
    const float3& getScale(Instance ci) const noexcept;

    void setTrs(Instance ci, const float3& translation, const quatf& rotation,
            const float3& scale) noexcept;
    const mat4f getTransform(Instance ci) const noexcept;

protected:
    TrsTransformManager() noexcept = default;
    ~TrsTransformManager() = default;

public:
    TrsTransformManager(TrsTransformManager const&) = delete;
    TrsTransformManager(TrsTransformManager&&) = delete;
    TrsTransformManager& operator=(TrsTransformManager const&) = delete;
    TrsTransformManager& operator=(TrsTransformManager&&) = delete;
};

} // namespace filament::gltfio

#endif // GLTFIO_TRSTRANSFORMMANAGER_H

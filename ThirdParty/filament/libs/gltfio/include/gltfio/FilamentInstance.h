
#ifndef GLTFIO_FILAMENTINSTANCE_H
#define GLTFIO_FILAMENTINSTANCE_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Entity.h"

#include <filament/Box.h>

namespace filament {
class MaterialInstance;
}

namespace filament::gltfio {

class Animator;
class FilamentAsset;

class UTILS_PUBLIC FilamentInstance {
public:
    FilamentAsset const* getAsset() const noexcept;

    const utils::Entity* getEntities() const noexcept;

    size_t getEntityCount() const noexcept;

    void applyMaterialVariant(size_t variantIndex) noexcept;

    size_t getMaterialVariantCount() const noexcept;

    const char* getMaterialVariantName(size_t variantIndex) const noexcept;

    Animator* getAnimator() noexcept;

    size_t getSkinCount() const noexcept;

    const char* getSkinNameAt(size_t skinIndex) const noexcept;

    size_t getJointCountAt(size_t skinIndex) const noexcept;

    const utils::Entity* getJointsAt(size_t skinIndex) const noexcept;

    void attachSkin(size_t skinIndex, utils::Entity target) noexcept;

    void detachSkin(size_t skinIndex, utils::Entity target) noexcept;

    math::mat4f const* getInverseBindMatricesAt(size_t skinIndex) const;

    void recomputeBoundingBoxes();

    Aabb getBoundingBox() const noexcept;

    MaterialInstance* const* getMaterialInstances() noexcept;

    void detachMaterialInstances();
};

} // namespace filament::gltfio

#endif // GLTFIO_FILAMENTINSTANCE_H

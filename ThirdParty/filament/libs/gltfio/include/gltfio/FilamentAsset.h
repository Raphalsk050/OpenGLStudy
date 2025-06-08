
#ifndef GLTFIO_FILAMENTASSET_H
#define GLTFIO_FILAMENTASSET_H

#include <filament/Box.h>
#include <filament/TextureSampler.h>

#include <gltfio/NodeManager.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Entity.h"

namespace filament {
    class Camera;
    class Engine;
    class MaterialInstance;
    class Scene;
}

namespace filament::gltfio {

class Animator;
class FilamentInstance;

class UTILS_PUBLIC FilamentAsset {
public:
    using Entity = utils::Entity;
    using SceneMask = NodeManager::SceneMask;

    const Entity* getEntities() const noexcept;

    size_t getEntityCount() const noexcept;

    const Entity* getLightEntities() const noexcept;

    size_t getLightEntityCount() const noexcept;

    const utils::Entity* getRenderableEntities() const noexcept;

    size_t getRenderableEntityCount() const noexcept;

    const Entity* getCameraEntities() const noexcept;

    size_t getCameraEntityCount() const noexcept;

    Entity getRoot() const noexcept;

    Entity popRenderable() noexcept;

    size_t popRenderables(Entity* entities, size_t count) noexcept;

    size_t getResourceUriCount() const noexcept;

    filament::Aabb getBoundingBox() const noexcept;

    Entity getFirstEntityByName(const char* name) noexcept;

    size_t getEntitiesByName(const char* name, Entity* entities,
            size_t maxCount) const noexcept;

    size_t getEntitiesByPrefix(const char* prefix, Entity* entities,
            size_t maxCount) const noexcept;

    const char* getMorphTargetNameAt(Entity entity, size_t targetIndex) const noexcept;

    size_t getMorphTargetCountAt(Entity entity) const noexcept;

    Entity getWireframe() noexcept;

    filament::Engine* getEngine() const noexcept;

    void releaseSourceData() noexcept;

    const void* getSourceAsset() noexcept;

    size_t getSceneCount() const noexcept;

    const char* getSceneName(size_t sceneIndex) const noexcept;

    void addEntitiesToScene(filament::Scene& targetScene, const Entity* entities, size_t count,
            SceneMask sceneFilter) const;

    void detachFilamentComponents() noexcept;

    bool areFilamentComponentsDetached() const noexcept;

    FilamentInstance* getInstance() noexcept {
        return getAssetInstanceCount() > 0 ? getAssetInstances()[0] : nullptr;
    }

};

} // namespace filament::gltfio

#endif // GLTFIO_FILAMENTASSET_H

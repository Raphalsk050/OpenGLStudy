
//! \file

#ifndef TNT_FILAMENT_SCENE_H
#define TNT_FILAMENT_SCENE_H

#include <filament/FilamentAPI.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Invocable.h"

#include <stddef.h>

namespace utils {
    class Entity;
} // namespace utils

namespace filament {

class IndirectLight;
class Skybox;

class UTILS_PUBLIC Scene : public FilamentAPI {
public:

    void setSkybox(Skybox* UTILS_NULLABLE skybox) noexcept;

    Skybox* UTILS_NULLABLE getSkybox() const noexcept;

    void setIndirectLight(IndirectLight* UTILS_NULLABLE ibl) noexcept;

    IndirectLight* UTILS_NULLABLE getIndirectLight() const noexcept;

    void addEntity(utils::Entity entity);

    void addEntities(const utils::Entity* UTILS_NONNULL entities, size_t count);

    void remove(utils::Entity entity);

    void removeEntities(const utils::Entity* UTILS_NONNULL entities, size_t count);

    size_t getEntityCount() const noexcept;

    size_t getRenderableCount() const noexcept;

    size_t getLightCount() const noexcept;

    bool hasEntity(utils::Entity entity) const noexcept;

    void forEach(utils::Invocable<void(utils::Entity entity)>&& functor) const noexcept;

protected:
    // prevent heap allocation
    ~Scene() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_SCENE_H

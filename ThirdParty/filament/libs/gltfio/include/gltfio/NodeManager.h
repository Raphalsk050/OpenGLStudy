
#ifndef GLTFIO_NODEMANAGER_H
#define GLTFIO_NODEMANAGER_H

#include <filament/FilamentAPI.h>

#include "third_party/filament/libs/utils/include/utils/bitset.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/EntityInstance.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

namespace utils {
class Entity;
} // namespace utils

namespace filament::gltfio {

class FNodeManager;

class UTILS_PUBLIC NodeManager {
public:
    using Instance = utils::EntityInstance<NodeManager>;
    using Entity = utils::Entity;
    using CString = utils::CString;
    using SceneMask = utils::bitset32;

    static constexpr size_t MAX_SCENE_COUNT = 32;

    bool hasComponent(Entity e) const noexcept;

    Instance getInstance(Entity e) const noexcept;

    void create(Entity entity);

    void destroy(Entity e) noexcept;

    void setMorphTargetNames(Instance ci, utils::FixedCapacityVector<CString> names) noexcept;
    const utils::FixedCapacityVector<CString>& getMorphTargetNames(Instance ci) const noexcept;

    void setExtras(Instance ci, CString extras) noexcept;
    const CString& getExtras(Instance ci) const noexcept;

    void setSceneMembership(Instance ci, SceneMask scenes) noexcept;
    SceneMask getSceneMembership(Instance ci) const noexcept;

protected:
    NodeManager() noexcept = default;
    ~NodeManager() = default;

public:
    NodeManager(NodeManager const&) = delete;
    NodeManager(NodeManager&&) = delete;
    NodeManager& operator=(NodeManager const&) = delete;
    NodeManager& operator=(NodeManager&&) = delete;
};

} // namespace filament::gltfio


#endif // GLTFIO_NODEMANAGER_H

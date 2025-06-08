
#ifndef TNT_UTILS_NAMECOMPONENTMANAGER_H
#define TNT_UTILS_NAMECOMPONENTMANAGER_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/Entity.h"
#include "third_party/filament/libs/utils/include/utils/EntityInstance.h"
#include "third_party/filament/libs/utils/include/utils/SingleInstanceComponentManager.h"

#include <stddef.h>

namespace utils {

class EntityManager;

class UTILS_PUBLIC NameComponentManager : private SingleInstanceComponentManager<utils::CString> {
public:
    using Instance = EntityInstance<NameComponentManager>;

    explicit NameComponentManager(EntityManager& em);
    ~NameComponentManager();

    using SingleInstanceComponentManager::hasComponent;

    Instance getInstance(Entity e) const noexcept {
        return { SingleInstanceComponentManager::getInstance(e) };
    }

    void addComponent(Entity e);

    void removeComponent(Entity e);

    void setName(Instance instance, const char* name) noexcept;

    const char* getName(Instance instance) const noexcept;

    void gc(EntityManager& em) noexcept {
        SingleInstanceComponentManager<utils::CString>::gc(em, [this](Entity e) {
            removeComponent(e);
        });
    }
};

} // namespace utils

#endif // TNT_UTILS_NAMECOMPONENTMANAGER_H

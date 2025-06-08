
#include "third_party/filament/libs/utils/include/utils/NameComponentManager.h"
#include "third_party/filament/libs/utils/include/utils/EntityManager.h"

namespace utils {

static constexpr size_t NAME = 0;

NameComponentManager::NameComponentManager(EntityManager&) {
}

NameComponentManager::~NameComponentManager() = default;

void NameComponentManager::setName(Instance instance, const char* name) noexcept {
    if (instance) {
        elementAt<NAME>(instance) = CString{ name };
    }
}

const char* NameComponentManager::getName(Instance instance) const noexcept {
    return elementAt<NAME>(instance).c_str();
}

void NameComponentManager::addComponent(Entity e) {
    SingleInstanceComponentManager::addComponent(e);
}

void NameComponentManager::removeComponent(Entity e) {
    SingleInstanceComponentManager::removeComponent(e);
}

} // namespace utils

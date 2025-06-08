
#include "third_party/filament/libs/utils/include/utils/EntityManager.h"

#include "EntityManagerImpl.h"

#include <new>

namespace utils {

EntityManager::Listener::~Listener() noexcept = default;

EntityManager::EntityManager()
        : mGens(new uint8_t[RAW_INDEX_COUNT]) {
    // initialize all the generations to 0
    std::fill_n(mGens, RAW_INDEX_COUNT, 0);
}

EntityManager::~EntityManager() {
    delete [] mGens;
}

EntityManager& EntityManager::get() noexcept {
    // note: we leak the EntityManager because it's more important that it survives everything else
    // the leak is really not a problem because the process is terminating anyway.
    static EntityManagerImpl* instance = new(std::nothrow) EntityManagerImpl;
    return *instance;
}

void EntityManager::create(size_t n, Entity* entities) {
    static_cast<EntityManagerImpl *>(this)->create(n, entities);
}

void EntityManager::destroy(size_t n, Entity* entities) noexcept {
    static_cast<EntityManagerImpl *>(this)->destroy(n, entities);
}

void EntityManager::registerListener(EntityManager::Listener* l) noexcept {
    static_cast<EntityManagerImpl *>(this)->registerListener(l);
}

void EntityManager::unregisterListener(EntityManager::Listener* l) noexcept {
    static_cast<EntityManagerImpl *>(this)->unregisterListener(l);
}

size_t EntityManager::getEntityCount() const noexcept {
    return static_cast<EntityManagerImpl const *>(this)->getEntityCount();
}

#if FILAMENT_UTILS_TRACK_ENTITIES
std::vector<Entity> EntityManager::getActiveEntities() const {
    return static_cast<EntityManagerImpl const *>(this)->getActiveEntities();
}

void EntityManager::dumpActiveEntities(utils::io::ostream& out) const {
    static_cast<EntityManagerImpl const *>(this)->dumpActiveEntities(out);
}

#endif

} // namespace utils

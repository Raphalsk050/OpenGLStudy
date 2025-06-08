
#ifndef TNT_UTILS_ENTITYMANAGER_H
#define TNT_UTILS_ENTITYMANAGER_H

#include "third_party/filament/libs/utils/include/utils/Entity.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#ifndef FILAMENT_UTILS_TRACK_ENTITIES
#define FILAMENT_UTILS_TRACK_ENTITIES false
#endif

#if FILAMENT_UTILS_TRACK_ENTITIES
#include "third_party/filament/libs/utils/include/utils/ostream.h"
#include <vector>
#endif

namespace utils {

class UTILS_PUBLIC EntityManager {
public:
    // Get the global EntityManager. It is recommended to cache this value.
    // Thread Safe.
    static EntityManager& get() noexcept;

    class Listener {
    public:
        virtual void onEntitiesDestroyed(size_t n, Entity const* entities) noexcept = 0;
    protected:
        virtual ~Listener() noexcept;
    };

    // maximum number of entities that can exist at the same time
    static size_t getMaxEntityCount() noexcept {
        // because index 0 is reserved, we only have 2^GENERATION_SHIFT - 1 valid indices
        return RAW_INDEX_COUNT - 1;
    }

    // number of active Entities
    size_t getEntityCount() const noexcept;

    // Create n entities. Thread safe.
    void create(size_t n, Entity* entities);

    // destroys n entities. Thread safe.
    void destroy(size_t n, Entity* entities) noexcept;

    // Create a new Entity. Thread safe.
    // Return Entity.isNull() if the entity cannot be allocated.
    Entity create() {
        Entity e;
        create(1, &e);
        return e;
    }

    // Destroys an Entity. Thread safe.
    void destroy(Entity e) noexcept {
        destroy(1, &e);
    }

    // Return whether the given Entity has been destroyed (false) or not (true).
    // Thread safe.
    bool isAlive(Entity e) const noexcept {
        assert(getIndex(e) < RAW_INDEX_COUNT);
        return (!e.isNull()) && (getGeneration(e) == mGens[getIndex(e)]);
    }

    // Registers a listener to be called when an entity is destroyed. Thread safe.
    // If the listener is already registered, this method has no effect.
    void registerListener(Listener* l) noexcept;

    // unregisters a listener.
    void unregisterListener(Listener* l) noexcept;



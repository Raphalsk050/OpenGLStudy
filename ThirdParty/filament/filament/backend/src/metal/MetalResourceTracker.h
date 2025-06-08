
#ifndef TNT_METALRESOURCETRACKER_H
#define TNT_METALRESOURCETRACKER_H

#include "robin_map/include/tsl/robin_map.h"
#include "robin_map/include/tsl/robin_set.h"

#include <functional>
#include <mutex>

namespace filament {
namespace backend {

class MetalResourceTracker {
public:
    using CommandBuffer = void*;
    using Resource = const void*;
    using ResourceDeleter = std::function<void(Resource)>;

    bool trackResource(CommandBuffer buffer, Resource resource, ResourceDeleter deleter);

    void clearResources(CommandBuffer buffer);

private:
    struct ResourceEntry {
        Resource resource;
        ResourceDeleter deleter;

        bool operator==(const ResourceEntry& rhs) const noexcept {
            return resource == rhs.resource;
        }
    };

    struct ResourceEntryHash {
        size_t operator()(const ResourceEntry& entry) const noexcept {
            return std::hash<Resource>{}(entry.resource);
        }
    };

    using ResourcesKey = CommandBuffer;
    using Resources = tsl::robin_set<ResourceEntry, ResourceEntryHash>;
    tsl::robin_map<ResourcesKey, Resources> mResources;

    // Synchronizes access to the map.
    // trackResource and clearResources may be called on separate threads (the engine thread and a
    // Metal callback thread, for example).
    std::mutex mMutex;
};

} // namespace backend
} // namespace filament

#endif //TNT_METALRESOURCETRACKER_H

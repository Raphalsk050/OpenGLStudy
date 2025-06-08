
#include "MetalResourceTracker.h"

#include "third_party/filament/libs/utils/include/utils/debug.h"

namespace filament {
namespace backend {

bool MetalResourceTracker::trackResource(CommandBuffer buffer, Resource resource,
        ResourceDeleter deleter) {
    std::lock_guard<std::mutex> lock(mMutex);

    auto found = mResources.find(buffer);
    if (found == mResources.end()) {
        Resources& resourcesForBuffer = mResources[buffer] = {};
        resourcesForBuffer.insert({resource, deleter});
        return true;
    }

    assert_invariant(found != mResources.end());
    Resources& resources = found.value();
    auto inserted = resources.insert({resource, deleter});
    return inserted.second;
}

void MetalResourceTracker::clearResources(CommandBuffer buffer) {
    std::lock_guard<std::mutex> lock(mMutex);

    auto found = mResources.find(buffer);
    if (found == mResources.end()) {
        return;
    }

    for (const auto& resource : found.value()) {
        resource.deleter(resource.resource);
    }
    mResources.erase(found);
}

} // namespace backend
} // namespace filament

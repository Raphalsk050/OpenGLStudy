
#ifndef TNT_FILAMENT_DRIVER_METALSTAGEPOOL_H
#define TNT_FILAMENT_DRIVER_METALSTAGEPOOL_H

#include <Metal/Metal.h>

#include "MetalBuffer.h"

#include <map>
#include <mutex>
#include <unordered_set>

namespace filament {
namespace backend {

struct MetalContext;

// Immutable POD representing a shared CPU-GPU buffer.
struct MetalBufferPoolEntry {
    TrackedMetalBuffer buffer;
    size_t capacity;
    mutable uint64_t lastAccessed;
    mutable uint32_t referenceCount;
};

class MetalBumpAllocator {
public:
    MetalBumpAllocator(id<MTLDevice> device, size_t capacity);

    std::pair<id<MTLBuffer>, size_t> allocateStagingArea(size_t size);

    size_t getCapacity() const noexcept { return mCapacity; }

private:
    id<MTLDevice> mDevice;
    TrackedMetalBuffer mCurrentUploadBuffer = nil;
    size_t mHead = 0;
    size_t mCapacity;
};

// Manages a pool of Metal buffers, periodically releasing ones that have been unused for awhile.
class MetalBufferPool {
public:
    explicit MetalBufferPool(MetalContext& context) noexcept : mContext(context) {}

    // Finds or creates a buffer whose capacity is at least the given number of bytes.
    MetalBufferPoolEntry const* acquireBuffer(size_t numBytes);

    // Increments the reference count of the buffer.
    void retainBuffer(MetalBufferPoolEntry const *stage) noexcept;

    // Decrements the reference count of the buffer, returning the given buffer back to the pool if
    // the count is 0.
    void releaseBuffer(MetalBufferPoolEntry const *stage) noexcept;

    // Evicts old unused buffers and bumps the current frame number.
    void gc() noexcept;

    // Destroys all unused buffers.
    void reset() noexcept;

private:
    MetalContext& mContext;

    // Synchronizes access to mFreeStages, mUsedStages, and mutable data inside MetalBufferPoolEntrys.
    // acquireBuffer and releaseBuffer may be called on separate threads (the engine thread and a
    // Metal callback thread, for example).
    std::mutex mMutex;

    // Use an ordered multimap for quick (capacity => stage) lookups using lower_bound().
    std::multimap<size_t, MetalBufferPoolEntry const*> mFreeStages;

    // Simple unordered set for stashing a list of in-use stages that can be reclaimed later.
    // In theory this need not exist, but is useful for validation and ensuring no leaks.
    std::unordered_set<MetalBufferPoolEntry const*> mUsedStages;

    // Store the current "time" (really just a frame count) and LRU eviction parameters.
    // An atomic is necessary as mCurrentFrame is incremented in gc() (called on
    // the driver thread) and read from acquireBuffer() and releaseBuffer(),
    // which may be called on non-driver threads.
    std::atomic<uint64_t> mCurrentFrame = 0;
    static constexpr uint32_t TIME_BEFORE_EVICTION = 10;
};

} // namespace backend
} // namespace filament

#endif // TNT_FILAMENT_DRIVER_METALSTAGEPOOL_H

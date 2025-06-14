
#ifndef TNT_FILAMENT_BACKEND_VULKANRESOURCEALLOCATOR_H
#define TNT_FILAMENT_BACKEND_VULKANRESOURCEALLOCATOR_H

#include "VulkanConstants.h"
#include "VulkanHandles.h"

#include <private/backend/HandleAllocator.h>

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/Log.h"

#include <type_traits>
#include <unordered_set>

namespace filament::backend {

#define RESOURCE_TYPE_COUNT (static_cast<int>(VulkanResourceType::END_TYPE))
#define DEBUG_RESOURCE_LEAKS FVK_ENABLED(FVK_DEBUG_RESOURCE_LEAK)

#if DEBUG_RESOURCE_LEAKS
    #define TRACK_INCREMENT()                                           \
    if (!IS_HEAP_ALLOC_TYPE(obj->getType())) {                          \
        mDebugOnlyResourceCount[static_cast<size_t>(obj->getType())]++; \
    }
    #define TRACK_DECREMENT()                                           \
    if (!IS_HEAP_ALLOC_TYPE(obj->getType())) {                          \
        mDebugOnlyResourceCount[static_cast<size_t>(obj->getType())]--; \
    }
#else
    // No-op
    #define TRACK_INCREMENT()
    #define TRACK_DECREMENT()
#endif

class VulkanResourceAllocator {
public:
    using AllocatorImpl = HandleAllocatorVK;
    VulkanResourceAllocator(size_t arenaSize, bool disableUseAfterFreeCheck)
        : mHandleAllocatorImpl("Handles", arenaSize, disableUseAfterFreeCheck)
#if DEBUG_RESOURCE_LEAKS
        , mDebugOnlyResourceCount(RESOURCE_TYPE_COUNT) {
        std::memset(mDebugOnlyResourceCount.data(), 0, sizeof(size_t) * RESOURCE_TYPE_COUNT);
    }
#else
    {}
#endif

    template<typename D, typename... ARGS>
    inline Handle<D> initHandle(ARGS&&... args) noexcept {
        auto handle = mHandleAllocatorImpl.allocateAndConstruct<D>(std::forward<ARGS>(args)...);
        auto obj = handle_cast<D*>(handle);
        obj->initResource(handle.getId());
        TRACK_INCREMENT();
        return handle;
    }

    template<typename D>
    inline Handle<D> allocHandle() noexcept {
        return mHandleAllocatorImpl.allocate<D>();
    }

    template<typename D, typename B, typename... ARGS>
    inline typename std::enable_if<std::is_base_of<B, D>::value, D>::type* construct(
            Handle<B> const& handle, ARGS&&... args) noexcept {
        auto obj = mHandleAllocatorImpl.construct<D, B>(handle, std::forward<ARGS>(args)...);
        obj->initResource(handle.getId());
        TRACK_INCREMENT();
        return obj;
    }

    template<typename Dp, typename B>
    inline typename std::enable_if_t<
            std::is_pointer_v<Dp> && std::is_base_of_v<B, typename std::remove_pointer_t<Dp>>, Dp>
    handle_cast(Handle<B>& handle) noexcept {
        return mHandleAllocatorImpl.handle_cast<Dp, B>(handle);
    }

    template<typename Dp, typename B>
    inline typename std::enable_if_t<
            std::is_pointer_v<Dp> && std::is_base_of_v<B, typename std::remove_pointer_t<Dp>>, Dp>
    handle_cast(Handle<B> const& handle) noexcept {
        return mHandleAllocatorImpl.handle_cast<Dp, B>(handle);
    }

    template<typename D, typename B>
    inline void destruct(Handle<B> handle) noexcept {
        auto obj = handle_cast<D*>(handle);
        TRACK_DECREMENT();
        mHandleAllocatorImpl.deallocate(handle, obj);
    }

private:
    AllocatorImpl mHandleAllocatorImpl;

#if DEBUG_RESOURCE_LEAKS
public:
    void print() {
        FVK_LOGD << "Resource Allocator state (debug only)" << utils::io::endl;
        for (size_t i = 0; i < RESOURCE_TYPE_COUNT; i++) {
            FVK_LOGD << "[" << i << "]=" << mDebugOnlyResourceCount[i] << utils::io::endl;
        }
        FVK_LOGD << "+++++++++++++++++++++++++++++++++++++" << utils::io::endl;
    }
private:
    utils::FixedCapacityVector<size_t> mDebugOnlyResourceCount;
#endif

};

#undef TRACK_INCREMENT
#undef TRACK_DECREMENT
#undef DEBUG_RESOURCE_LEAKS

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_VULKANRESOURCEALLOCATOR_H

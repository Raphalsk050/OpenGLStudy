
#ifndef TNT_FILAMENT_DRIVER_METALBUFFER_H
#define TNT_FILAMENT_DRIVER_METALBUFFER_H

#include "MetalContext.h"
#include "MetalPlatform.h"

#include <backend/DriverEnums.h>

#include <Metal/Metal.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <utility>
#include <memory>
#include <atomic>
#include <chrono>

namespace filament::backend {

class ScopedAllocationTimer {
public:
    ScopedAllocationTimer(const char* name) : mBeginning(clock_t::now()), mName(name) {}
    ~ScopedAllocationTimer() {
        using namespace std::literals::chrono_literals;
        static constexpr std::chrono::seconds LONG_TIME_THRESHOLD = 10s;

        auto end = clock_t::now();
        std::chrono::duration<double, std::micro> allocationTimeMicroseconds = end - mBeginning;

        if (UTILS_UNLIKELY(allocationTimeMicroseconds > LONG_TIME_THRESHOLD)) {
            if (platform && platform->hasDebugUpdateStatFunc()) {
                char buffer[64];
                snprintf(buffer, sizeof(buffer), "filament.metal.long_buffer_allocation_time.%s",
                        mName);
                platform->debugUpdateStat(
                        buffer, static_cast<uint64_t>(allocationTimeMicroseconds.count()));
            }
        }
    }

    static void setPlatform(MetalPlatform* p) { platform = p; }

private:
    typedef std::chrono::steady_clock clock_t;

    static MetalPlatform* platform;

    std::chrono::time_point<clock_t> mBeginning;
    const char* mName;
};

class TrackedMetalBuffer {
public:

    static constexpr size_t EXCESS_BUFFER_COUNT = 30000;

    enum class Type {
        NONE = 0,
        GENERIC = 1,
        RING = 2,
        STAGING = 3,
    };
    static constexpr size_t TypeCount = 3;

    static constexpr auto toIndex(Type t) {
        assert_invariant(t != Type::NONE);
        switch (t) {
            case Type::NONE:
            case Type::GENERIC:
                return 0;
            case Type::RING:
                return 1;
            case Type::STAGING:
                return 2;
        }
    }

    TrackedMetalBuffer() noexcept : mBuffer(nil) {}
    TrackedMetalBuffer(nullptr_t) noexcept : mBuffer(nil) {}
    TrackedMetalBuffer(id<MTLBuffer> buffer, Type type) : mBuffer(buffer), mType(type) {
        assert_invariant(type != Type::NONE);
        if (buffer) {
            aliveBuffers[toIndex(type)]++;
            mType = type;
            if (getAliveBuffers() >= EXCESS_BUFFER_COUNT) {
                if (platform && platform->hasDebugUpdateStatFunc()) {
                    platform->debugUpdateStat("filament.metal.excess_buffers_allocated",
                            TrackedMetalBuffer::getAliveBuffers());
                }
            }
        }
    }

    ~TrackedMetalBuffer() {
        if (mBuffer) {
            assert_invariant(mType != Type::NONE);
            aliveBuffers[toIndex(mType)]--;
        }
    }

    TrackedMetalBuffer(TrackedMetalBuffer&&) = delete;
    TrackedMetalBuffer(TrackedMetalBuffer const&) = delete;
    TrackedMetalBuffer& operator=(TrackedMetalBuffer const&) = delete;

    TrackedMetalBuffer& operator=(TrackedMetalBuffer&& rhs) noexcept {
        swap(rhs);
        return *this;
    }

    id<MTLBuffer> get() const noexcept { return mBuffer; }
    operator bool() const noexcept { return bool(mBuffer); }

    static uint64_t getAliveBuffers() {
        uint64_t sum = 0;
        for (const auto& v : aliveBuffers) {
            sum += v;
        }
        return sum;
    }

    static uint64_t getAliveBuffers(Type type) {
        assert_invariant(type != Type::NONE);
        return aliveBuffers[toIndex(type)];
    }
    static void setPlatform(MetalPlatform* p) { platform = p; }

private:
    void swap(TrackedMetalBuffer& other) noexcept {
        std::swap(mBuffer, other.mBuffer);
        std::swap(mType, other.mType);
    }

    id<MTLBuffer> mBuffer;
    Type mType = Type::NONE;

    static MetalPlatform* platform;
    static std::array<uint64_t, TypeCount> aliveBuffers;
};

class MetalBuffer {
public:

    MetalBuffer(MetalContext& context, BufferObjectBinding bindingType, BufferUsage usage,
         size_t size, bool forceGpuBuffer = false);
    ~MetalBuffer();

    MetalBuffer(const MetalBuffer& rhs) = delete;
    MetalBuffer& operator=(const MetalBuffer& rhs) = delete;

    size_t getSize() const noexcept { return mBufferSize; }

    void copyIntoBuffer(void* src, size_t size, size_t byteOffset);
    void copyIntoBufferUnsynchronized(void* src, size_t size, size_t byteOffset);

    id<MTLBuffer> getGpuBufferForDraw(id<MTLCommandBuffer> cmdBuffer) noexcept;

    void* getCpuBuffer() const noexcept { return mCpuBuffer; }

    enum Stage : uint8_t {
        VERTEX      = 1u << 0u,
        FRAGMENT    = 1u << 1u,
        COMPUTE     = 1u << 2u
    };

    static void bindBuffers(id<MTLCommandBuffer> cmdBuffer, id<MTLCommandEncoder> encoder,
            size_t bufferStart, uint8_t stages, MetalBuffer* const* buffers, size_t const* offsets,
            size_t count);

private:

    enum class UploadStrategy {
        POOL,
        BUMP_ALLOCATOR,
    };

    void uploadWithPoolBuffer(void* src, size_t size, size_t byteOffset) const;
    void uploadWithBumpAllocator(void* src, size_t size, size_t byteOffset) const;

    UploadStrategy mUploadStrategy;
    TrackedMetalBuffer mBuffer;
    size_t mBufferSize = 0;
    void* mCpuBuffer = nullptr;
    MetalContext& mContext;
};

template <typename TYPE>
static inline TYPE align(TYPE p, size_t alignment) noexcept {
    // alignment must be a power-of-two
    assert(alignment && !(alignment & alignment-1));
    return (TYPE)((p + alignment - 1) & ~(alignment - 1));
}

class MetalRingBuffer {
public:
    // In practice, MetalRingBuffer is used for argument buffers, which are kept in the constant
    // address space. Constant buffers have specific alignment requirements when specifying an
    // offset.
#if defined(IOS)
#if TARGET_OS_SIMULATOR
    // The iOS simulator has differing alignment requirements.
    static constexpr auto METAL_CONSTANT_BUFFER_OFFSET_ALIGNMENT = 256;
#else
    static constexpr auto METAL_CONSTANT_BUFFER_OFFSET_ALIGNMENT = 4;
#endif  // TARGET_OS_SIMULATOR
#else
    static constexpr auto METAL_CONSTANT_BUFFER_OFFSET_ALIGNMENT = 32;
#endif
    static inline auto computeSlotSize(MTLSizeAndAlign layout) {
         return align(align(layout.size, layout.align), METAL_CONSTANT_BUFFER_OFFSET_ALIGNMENT);
    }

    MetalRingBuffer(id<MTLDevice> device, MTLResourceOptions options, MTLSizeAndAlign layout,
            NSUInteger slotCount)
        : mDevice(device),
          mAuxBuffer(nil),
          mBufferOptions(options),
          mSlotSizeBytes(computeSlotSize(layout)),
          mSlotCount(slotCount) {
        ScopedAllocationTimer timer("ring");
        mBuffer = { [device newBufferWithLength:mSlotSizeBytes * mSlotCount options:mBufferOptions],
            TrackedMetalBuffer::Type::RING };
        assert_invariant(mBuffer);
    }

    std::pair<id<MTLBuffer>, NSUInteger> createNewAllocation(id<MTLCommandBuffer> cmdBuffer) {
        const auto occupiedSlots = mOccupiedSlots->load(std::memory_order_relaxed);
        assert_invariant(occupiedSlots <= mSlotCount);
        if (UTILS_UNLIKELY(occupiedSlots == mSlotCount)) {
            // We don't have any room left, so we fall back to creating a one-off aux buffer.
            // If we already have an aux buffer, it will get freed here, unless it has been retained
            // by a MTLCommandBuffer. In that case, it will be freed when the command buffer
            // finishes executing.
            {
                ScopedAllocationTimer timer("ring");
                mAuxBuffer = { [mDevice newBufferWithLength:mSlotSizeBytes options:mBufferOptions],
                    TrackedMetalBuffer::Type::RING };
            }
            assert_invariant(mAuxBuffer);
            return { mAuxBuffer.get(), 0 };
        }
        mCurrentSlot = (mCurrentSlot + 1) % mSlotCount;
        mOccupiedSlots->fetch_add(1, std::memory_order_relaxed);

        // Release the previous allocation.
        if (UTILS_UNLIKELY(mAuxBuffer)) {
            mAuxBuffer = nil;
        } else {
            // Capture the mOccupiedSlots var via a weak_ptr because the MetalRingBuffer could be
            // destructed before the block executes.
            std::weak_ptr<AtomicCounterType> slots = mOccupiedSlots;
            [cmdBuffer addCompletedHandler:^(id<MTLCommandBuffer> buffer) {
                if (auto s = slots.lock()) {
                    s->fetch_sub(1, std::memory_order_relaxed);
                }
            }];
        }
        return getCurrentAllocation();
    }

    std::pair<id<MTLBuffer>, NSUInteger> getCurrentAllocation() const {
        if (UTILS_UNLIKELY(mAuxBuffer)) {
            return { mAuxBuffer.get(), 0 };
        }
        return { mBuffer.get(), mCurrentSlot * mSlotSizeBytes };
    }

    bool canAccomodateLayout(MTLSizeAndAlign layout) const {
        return mSlotSizeBytes >= computeSlotSize(layout);
    }

private:
    id<MTLDevice> mDevice;
    TrackedMetalBuffer mBuffer;
    TrackedMetalBuffer mAuxBuffer;

    MTLResourceOptions mBufferOptions;

    NSUInteger mSlotSizeBytes;
    NSUInteger mSlotCount;

    NSUInteger mCurrentSlot = 0;
    using AtomicCounterType = std::atomic<NSUInteger>;
    std::shared_ptr<AtomicCounterType> mOccupiedSlots = std::make_shared<AtomicCounterType>(1);
};

} // namespace filament::backend

#endif

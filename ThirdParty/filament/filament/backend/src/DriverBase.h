
#ifndef TNT_FILAMENT_DRIVER_DRIVERBASE_H
#define TNT_FILAMENT_DRIVER_DRIVERBASE_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/CString.h"

#include <backend/Platform.h>

#include <backend/BufferDescriptor.h>
#include <backend/DriverEnums.h>
#include <backend/CallbackHandler.h>

#include "private/backend/Dispatcher.h"
#include "private/backend/Driver.h"

#include <condition_variable>
#include <memory>
#include <mutex>
#include <thread>
#include <utility>
#include <vector>

#include <stdint.h>

namespace filament::backend {

struct AcquiredImage;


struct HwBase {
};


struct HwVertexBufferInfo : public HwBase {
    uint8_t bufferCount{};                //   1
    uint8_t attributeCount{};             //   1
    bool padding[2]{};                    //   2
    HwVertexBufferInfo() noexcept = default;
    HwVertexBufferInfo(uint8_t bufferCount, uint8_t attributeCount) noexcept
            : bufferCount(bufferCount),
              attributeCount(attributeCount) {
    }
};

struct HwVertexBuffer : public HwBase {
    uint32_t vertexCount{};               //   4
    uint8_t bufferObjectsVersion{0xff};   //   1
    bool padding[3]{};                    //   2
    HwVertexBuffer() noexcept = default;
    explicit HwVertexBuffer(uint32_t vertextCount) noexcept
            : vertexCount(vertextCount) {
    }
};

struct HwBufferObject : public HwBase {
    uint32_t byteCount{};

    HwBufferObject() noexcept = default;
    explicit HwBufferObject(uint32_t byteCount) noexcept : byteCount(byteCount) {}
};

struct HwIndexBuffer : public HwBase {
    uint32_t count : 27;
    uint32_t elementSize : 5;

    HwIndexBuffer() noexcept : count{}, elementSize{} { }
    HwIndexBuffer(uint8_t elementSize, uint32_t indexCount) noexcept :
            count(indexCount), elementSize(elementSize) {
        // we could almost store elementSize on 4 bits because it's never > 16 and never 0
        assert_invariant(elementSize > 0 && elementSize <= 16);
        assert_invariant(indexCount < (1u << 27));
    }
};

struct HwRenderPrimitive : public HwBase {
    PrimitiveType type = PrimitiveType::TRIANGLES;
};

struct HwProgram : public HwBase {
    utils::CString name;
    explicit HwProgram(utils::CString name) noexcept : name(std::move(name)) { }
    HwProgram() noexcept = default;
};

struct HwSamplerGroup : public HwBase {
    HwSamplerGroup() noexcept = default;
};

struct HwTexture : public HwBase {
    uint32_t width{};
    uint32_t height{};
    uint32_t depth{};
    SamplerType target{};
    uint8_t levels : 4;  // This allows up to 15 levels (max texture size of 32768 x 32768)
    uint8_t samples : 4; // Sample count per pixel (should always be a power of 2)
    TextureFormat format{};
    uint8_t reserved0 = 0;
    TextureUsage usage{};
    uint16_t reserved1 = 0;
    HwStream* hwStream = nullptr;

    HwTexture() noexcept : levels{}, samples{} {}
    HwTexture(backend::SamplerType target, uint8_t levels, uint8_t samples,
              uint32_t width, uint32_t height, uint32_t depth, TextureFormat fmt, TextureUsage usage) noexcept
            : width(width), height(height), depth(depth),
              target(target), levels(levels), samples(samples), format(fmt), usage(usage) { }
};

struct HwRenderTarget : public HwBase {
    uint32_t width{};
    uint32_t height{};
    HwRenderTarget() noexcept = default;
    HwRenderTarget(uint32_t w, uint32_t h) : width(w), height(h) { }
};

struct HwFence : public HwBase {
    Platform::Fence* fence = nullptr;
};

struct HwSwapChain : public HwBase {
    Platform::SwapChain* swapChain = nullptr;
};

struct HwStream : public HwBase {
    Platform::Stream* stream = nullptr;
    StreamType streamType = StreamType::ACQUIRED;
    uint32_t width{};
    uint32_t height{};

    HwStream() noexcept = default;
    explicit HwStream(Platform::Stream* stream) noexcept
            : stream(stream), streamType(StreamType::NATIVE) {
    }
};

struct HwTimerQuery : public HwBase {
};


class DriverBase : public Driver {
public:
    DriverBase() noexcept;
    ~DriverBase() noexcept override;

    void purge() noexcept final;

    // Helpers...
    struct CallbackData {
        CallbackData(CallbackData const &) = delete;
        CallbackData(CallbackData&&) = delete;
        CallbackData& operator=(CallbackData const &) = delete;
        CallbackData& operator=(CallbackData&&) = delete;
        void* storage[8] = {};
        static CallbackData* obtain(DriverBase* allocator);
        static void release(CallbackData* data);
    protected:
        CallbackData() = default;
    };

    template<typename T>
    void scheduleCallback(CallbackHandler* handler, T&& functor) {
        CallbackData* data = CallbackData::obtain(this);
        static_assert(sizeof(T) <= sizeof(data->storage), "functor too large");
        new(data->storage) T(std::forward<T>(functor));
        scheduleCallback(handler, data, (CallbackHandler::Callback)[](void* data) {
            CallbackData* details = static_cast<CallbackData*>(data);
            void* user = details->storage;
            T& functor = *static_cast<T*>(user);
            functor();
            functor.~T();
            CallbackData::release(details);
        });
    }

    void scheduleCallback(CallbackHandler* handler, void* user, CallbackHandler::Callback callback);

    // --------------------------------------------------------------------------------------------
    // Privates
    // --------------------------------------------------------------------------------------------

protected:
    class CallbackDataDetails;

    inline void scheduleDestroy(BufferDescriptor&& buffer) noexcept {
        if (buffer.hasCallback()) {
            scheduleDestroySlow(std::move(buffer));
        }
    }

    void scheduleDestroySlow(BufferDescriptor&& buffer) noexcept;

    void scheduleRelease(AcquiredImage const& image) noexcept;

    void debugCommandBegin(CommandStream* cmds, bool synchronous, const char* methodName) noexcept override;
    void debugCommandEnd(CommandStream* cmds, bool synchronous, const char* methodName) noexcept override;

private:
    std::mutex mPurgeLock;
    std::vector<std::pair<void*, CallbackHandler::Callback>> mCallbacks;

    std::thread mServiceThread;
    std::mutex mServiceThreadLock;
    std::condition_variable mServiceThreadCondition;
    std::vector<std::tuple<CallbackHandler*, CallbackHandler::Callback, void*>> mServiceThreadCallbackQueue;
    bool mExitRequested = false;
};


} // namespace backend::filament

#endif // TNT_FILAMENT_DRIVER_DRIVERBASE_H

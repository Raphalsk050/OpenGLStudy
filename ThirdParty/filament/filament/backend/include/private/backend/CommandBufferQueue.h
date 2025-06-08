
#ifndef TNT_FILAMENT_BACKEND_PRIVATE_COMMANDBUFFERQUEUE_H
#define TNT_FILAMENT_BACKEND_PRIVATE_COMMANDBUFFERQUEUE_H

#include "private/backend/CircularBuffer.h"

#include "third_party/filament/libs/utils/include/utils/Condition.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"

#include <vector>

#include <stddef.h>
#include <stdint.h>

namespace filament::backend {

class CommandBufferQueue {
    struct Range {
        void* begin;
        void* end;
    };

    const size_t mRequiredSize;

    CircularBuffer mCircularBuffer;

    // space available in the circular buffer

    mutable utils::Mutex mLock;
    mutable utils::Condition mCondition;
    mutable std::vector<Range> mCommandBuffersToExecute;
    size_t mFreeSpace = 0;
    size_t mHighWatermark = 0;
    uint32_t mExitRequested = 0;
    bool mPaused = false;

    static constexpr uint32_t EXIT_REQUESTED = 0x31415926;

public:
    // requiredSize: guaranteed available space after flush()
    CommandBufferQueue(size_t requiredSize, size_t bufferSize, bool paused);
    ~CommandBufferQueue();

    CircularBuffer& getCircularBuffer() noexcept { return mCircularBuffer; }
    CircularBuffer const& getCircularBuffer() const noexcept { return mCircularBuffer; }

    size_t getCapacity() const noexcept { return mRequiredSize; }

    size_t getHighWatermark() const noexcept { return mHighWatermark; }

    // wait for commands to be available and returns an array containing these commands
    std::vector<Range> waitForCommands() const;

    // return the memory used by this command buffer to the circular buffer
    // WARNING: releaseBuffer() must be called in sequence of the Slices returned by
    // waitForCommands()
    void releaseBuffer(Range const& buffer);

    // all commands buffers (Slices) written to this point are returned by waitForCommand(). This
    // call blocks until the CircularBuffer has at least mRequiredSize bytes available.
    void flush() noexcept;

    // returns from waitForCommands() immediately.
    void requestExit();

    // suspend or unsuspend the queue.
    bool isPaused() const noexcept;
    void setPaused(bool paused);

    bool isExitRequested() const;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_PRIVATE_COMMANDBUFFERQUEUE_H

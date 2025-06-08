
#include "private/backend/CommandBufferQueue.h"
#include "private/backend/CircularBuffer.h"
#include "private/backend/CommandStream.h"

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Log.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"
#include "third_party/filament/libs/utils/include/utils/Panic.h"
#include "third_party/filament/libs/utils/include/utils/Systrace.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"

#include <algorithm>
#include <mutex>
#include <iterator>
#include <utility>
#include <vector>

#include <stddef.h>
#include <stdint.h>

using namespace utils;

namespace filament::backend {

CommandBufferQueue::CommandBufferQueue(size_t requiredSize, size_t bufferSize, bool paused)
        : mRequiredSize((requiredSize + (CircularBuffer::getBlockSize() - 1u)) & ~(CircularBuffer::getBlockSize() -1u)),
          mCircularBuffer(bufferSize),
          mFreeSpace(mCircularBuffer.size()),
          mPaused(paused) {
    assert_invariant(mCircularBuffer.size() > requiredSize);
}

CommandBufferQueue::~CommandBufferQueue() {
    assert_invariant(mCommandBuffersToExecute.empty());
}

void CommandBufferQueue::requestExit() {
    std::lock_guard<utils::Mutex> const lock(mLock);
    mExitRequested = EXIT_REQUESTED;
    mCondition.notify_one();
}

bool CommandBufferQueue::isPaused() const noexcept {
    std::lock_guard<utils::Mutex> const lock(mLock);
    return mPaused;
}

void CommandBufferQueue::setPaused(bool paused) {
    std::lock_guard<utils::Mutex> const lock(mLock);
    if (paused) {
        mPaused = true;
    } else {
        mPaused = false;
        mCondition.notify_one();
    }
}

bool CommandBufferQueue::isExitRequested() const {
    std::lock_guard<utils::Mutex> const lock(mLock);
    return (bool)mExitRequested;
}


void CommandBufferQueue::flush() noexcept {
    SYSTRACE_CALL();

    CircularBuffer& circularBuffer = mCircularBuffer;
    if (circularBuffer.empty()) {
        return;
    }

    // add the terminating command
    // always guaranteed to have enough space for the NoopCommand
    new(circularBuffer.allocate(sizeof(NoopCommand))) NoopCommand(nullptr);

    const size_t requiredSize = mRequiredSize;

    // get the current buffer
    auto const [begin, end] = circularBuffer.getBuffer();

    assert_invariant(circularBuffer.empty());

    // size of the current buffer
    size_t const used = std::distance(
            static_cast<char const*>(begin), static_cast<char const*>(end));

    std::unique_lock<utils::Mutex> lock(mLock);
    mCommandBuffersToExecute.push_back({ begin, end });
    mCondition.notify_one();

    // circular buffer is too small, we corrupted the stream
    FILAMENT_CHECK_POSTCONDITION(used <= mFreeSpace) <<
            "Backend CommandStream overflow. Commands are corrupted and unrecoverable.\n"
            "Please increase minCommandBufferSizeMB inside the Config passed to Engine::create.\n"
            "Space used at this time: " << used <<
            " bytes, overflow: " << used - mFreeSpace << " bytes";

    // wait until there is enough space in the buffer
    mFreeSpace -= used;
    if (UTILS_UNLIKELY(mFreeSpace < requiredSize)) {


#ifndef NDEBUG
        size_t const totalUsed = circularBuffer.size() - mFreeSpace;
        slog.d << "CommandStream used too much space (will block): "
                << "needed space " << requiredSize << " out of " << mFreeSpace
                << ", totalUsed=" << totalUsed << ", current=" << used
                << ", queue size=" << mCommandBuffersToExecute.size() << " buffers"
                << io::endl;

        mHighWatermark = std::max(mHighWatermark, totalUsed);
#endif

        SYSTRACE_NAME("waiting: CircularBuffer::flush()");

        FILAMENT_CHECK_POSTCONDITION(!mPaused) <<
                "CommandStream is full, but since the rendering thread is paused, "
                "the buffer cannot flush and we will deadlock. Instead, abort.";

        mCondition.wait(lock, [this, requiredSize]() -> bool {
            // TODO: on macOS, we need to call pumpEvents from time to time
            return mFreeSpace >= requiredSize;
        });
    }
}

std::vector<CommandBufferQueue::Range> CommandBufferQueue::waitForCommands() const {
    if (!UTILS_HAS_THREADING) {
        return std::move(mCommandBuffersToExecute);
    }
    std::unique_lock<utils::Mutex> lock(mLock);
    while ((mCommandBuffersToExecute.empty() || mPaused) && !mExitRequested) {
        mCondition.wait(lock);
    }
    return std::move(mCommandBuffersToExecute);
}

void CommandBufferQueue::releaseBuffer(CommandBufferQueue::Range const& buffer) {
    std::lock_guard<utils::Mutex> const lock(mLock);
    mFreeSpace += uintptr_t(buffer.end) - uintptr_t(buffer.begin);
    mCondition.notify_one();
}

} // namespace filament::backend

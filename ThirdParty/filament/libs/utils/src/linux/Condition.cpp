
#include "third_party/filament/libs/utils/include/utils/linux/Condition.h"

#include "futex.h"

namespace utils {

std::cv_status Condition::wait_until(Mutex* lock,
        bool realtimeClock, struct timespec* ts) noexcept {
    if (ts && ts->tv_sec < 0) {
        return std::cv_status::timeout;
    }
    uint32_t old_state = mState.load(std::memory_order_relaxed);
    lock->unlock();
    int status = linuxutil::futex_wait_ex(&mState, false, old_state, realtimeClock, ts);
    lock->lock();
    return (status == -ETIMEDOUT) ? std::cv_status::timeout : std::cv_status::no_timeout;
}

void Condition::pulse(int threadCount) noexcept {
    mState.fetch_add(1, std::memory_order_relaxed);
    linuxutil::futex_wake_ex(&mState, false, threadCount);
}

} // namespace utils

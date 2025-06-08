
#ifndef TNT_UTILS_LINUX_MUTEX_H
#define TNT_UTILS_LINUX_MUTEX_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <atomic>

#include <stdint.h>

namespace utils {


class Mutex {
public:
    constexpr Mutex() noexcept = default;
    Mutex(const Mutex&) = delete;
    Mutex& operator=(const Mutex&) = delete;

    void lock() noexcept {
        uint32_t old_state = UNLOCKED;
        if (UTILS_UNLIKELY(!mState.compare_exchange_strong(old_state,
                LOCKED, std::memory_order_acquire, std::memory_order_relaxed))) {
            wait();
        }
    }

    void unlock() noexcept {
        if (UTILS_UNLIKELY(mState.exchange(UNLOCKED, std::memory_order_release) == LOCKED_CONTENDED)) {
            wake();
        }
    }

private:
    enum {
        UNLOCKED = 0, LOCKED = 1, LOCKED_CONTENDED = 2
    };
    std::atomic<uint32_t> mState = { UNLOCKED };

    void wait() noexcept;
    void wake() noexcept;
};

} // namespace utils

#endif // TNT_UTILS_LINUX_MUTEX_H

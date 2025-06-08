
#ifndef TNT_UTILS_COUNTDOWNLATCH_H
#define TNT_UTILS_COUNTDOWNLATCH_H

// note: we use our version of mutex/condition to keep this public header STL free
#include "third_party/filament/libs/utils/include/utils/Condition.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"

#include <stdint.h>
#include <stddef.h>

namespace utils {

class CountDownLatch {
public:
    explicit CountDownLatch(size_t count) noexcept;
    ~CountDownLatch() = default;

    void await() noexcept;

    void latch() noexcept;

    void reset(size_t new_count) noexcept;

    size_t getCount() const noexcept;

    CountDownLatch() = delete;
    CountDownLatch(const CountDownLatch&) = delete;
    CountDownLatch& operator=(const CountDownLatch&) = delete;

private:
    uint32_t m_initial_count;
    uint32_t m_remaining_count;
    mutable Mutex m_lock;
    mutable Condition m_cv;
};

} // namespace utils

#endif // TNT_UTILS_COUNTDOWNLATCH_H

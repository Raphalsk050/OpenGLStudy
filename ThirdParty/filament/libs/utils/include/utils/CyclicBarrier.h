
#ifndef TNT_UTILS_CYCLIC_BARRIER_H
#define TNT_UTILS_CYCLIC_BARRIER_H

#include <stddef.h>

// note: we use our version of mutex/condition to keep this public header STL free
#include "third_party/filament/libs/utils/include/utils/Condition.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"

namespace utils {

class CyclicBarrier {
public:
    explicit CyclicBarrier(size_t num_threads) noexcept;

    size_t getThreadCount() const noexcept;

    size_t getWaitingThreadCount() const noexcept;

    void await() noexcept;

    void reset() noexcept;

    CyclicBarrier() = delete;
    CyclicBarrier(const CyclicBarrier&) = delete;
    CyclicBarrier& operator=(const CyclicBarrier&) = delete;

private:
    enum class State {
        TRAP, RELEASE
    };

    const size_t m_num_threads;
    mutable Mutex m_lock;
    mutable Condition m_cv;

    State m_state = State::TRAP;
    size_t m_trapped_threads = 0;
    size_t m_released_threads = 0;
};

} // namespace utils

#endif // TNT_UTILS_CYCLIC_BARRIER_H

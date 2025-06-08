
#ifndef TNT_UTILS_LINUX_CONDITION_H
#define TNT_UTILS_LINUX_CONDITION_H

#include <atomic>
#include <chrono>
#include <condition_variable> // for cv_status
#include <limits>
#include <mutex> // for unique_lock

#include "third_party/filament/libs/utils/include/utils/linux/Mutex.h"

#include <time.h>

namespace utils {


class Condition {
public:
    Condition() noexcept = default;
    Condition(const Condition&) = delete;
    Condition& operator=(const Condition&) = delete;

    void notify_all() noexcept {
        pulse(std::numeric_limits<int>::max());
    }

    void notify_one() noexcept {
        pulse(1);
    }

    void notify_n(size_t n) noexcept {
        if (n > 0) pulse(n);
    }

    void wait(std::unique_lock<Mutex>& lock) noexcept {
        wait_until(lock.mutex(), false, nullptr);
    }

    template <class P>
    void wait(std::unique_lock<Mutex>& lock, P predicate) {
        while (!predicate()) {
            wait(lock);
        }
    }

    template<typename D>
    std::cv_status wait_until(std::unique_lock<Mutex>& lock,
            const std::chrono::time_point<std::chrono::steady_clock, D>& timeout_time) noexcept {
        // convert to nanoseconds
        uint64_t ns = std::chrono::duration<uint64_t, std::nano>(timeout_time.time_since_epoch()).count();
        using sec_t = decltype(timespec::tv_sec);
        using nsec_t = decltype(timespec::tv_nsec);
        timespec ts{ sec_t(ns / 1000000000), nsec_t(ns % 1000000000) };
        return wait_until(lock.mutex(), false, &ts);
    }

    template<typename D>
    std::cv_status wait_until(std::unique_lock<Mutex>& lock,
            const std::chrono::time_point<std::chrono::system_clock, D>& timeout_time) noexcept {
        // convert to nanoseconds
        uint64_t ns = std::chrono::duration<uint64_t, std::nano>(timeout_time.time_since_epoch()).count();
        using sec_t = decltype(timespec::tv_sec);
        using nsec_t = decltype(timespec::tv_nsec);
        timespec ts{ sec_t(ns / 1000000000), nsec_t(ns % 1000000000) };
        return wait_until(lock.mutex(), true, &ts);
    }

    template<typename C, typename D, typename P>
    bool wait_until(std::unique_lock<Mutex>& lock,
            const std::chrono::time_point<C, D>& timeout_time, P predicate) noexcept {
        while (!predicate()) {
            if (wait_until(lock, timeout_time) == std::cv_status::timeout) {
                return predicate();
            }
        }
        return true;
    }

    template<typename R, typename Period>
    std::cv_status wait_for(std::unique_lock<Mutex>& lock,
            const std::chrono::duration<R, Period>& rel_time) noexcept {
        return wait_until(lock, std::chrono::steady_clock::now() + rel_time);
    }

    template<typename R, typename Period, typename P>
    bool wait_for(std::unique_lock<Mutex>& lock,
            const std::chrono::duration<R, Period>& rel_time, P pred) noexcept {
        return wait_until(lock, std::chrono::steady_clock::now() + rel_time, std::move(pred));
    }

private:
    std::atomic<uint32_t> mState = { 0 };

    void pulse(int threadCount) noexcept;

    std::cv_status wait_until(Mutex* lock,
            bool realtimeClock, timespec* ts) noexcept;
};

} // namespace utils

#endif // TNT_UTILS_LINUX_CONDITION_H

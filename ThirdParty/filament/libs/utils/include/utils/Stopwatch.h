
#ifndef TNT_UTILS_STOPWATCH_H
#define TNT_UTILS_STOPWATCH_H

#include "third_party/filament/libs/utils/include/utils/Log.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include <chrono>
#include <limits>
#include <ratio>

#include <stddef.h>

namespace utils {


template<typename Clock = std::chrono::steady_clock>
class Stopwatch {
public:
    using duration = typename Clock::duration;
    using time_point = typename Clock::time_point;

private:
    time_point mStart;
    duration mMinLap = std::numeric_limits<duration>::max();
    duration mMaxLap{};
    std::chrono::duration<double, std::nano> mAvgLap{};
    size_t mCount = 0;
    const char* mName = nullptr;

public:
    // Create a Stopwatch with a name and clock
    explicit Stopwatch(const char* name) noexcept: mName(name) {}

    // Logs min/avg/max lap time
    ~Stopwatch() noexcept;

    // start the stopwatch
    inline void start() noexcept {
        mStart = Clock::now();
    }

    // stop the stopwatch
    inline void stop() noexcept {
        auto d = Clock::now() - mStart;
        mMinLap = std::min(mMinLap, d);
        mMaxLap = std::max(mMaxLap, d);
        mAvgLap = (mAvgLap * mCount + d) / (mCount + 1);
        mCount++;
    }

    // get the minimum lap time recorded
    duration getMinLapTime() const noexcept { return mMinLap; }

    // get the maximum lap time recorded
    duration getMaxLapTime() const noexcept { return mMaxLap; }

    // get the average lap time
    duration getAverageLapTime() const noexcept { return mAvgLap; }
};

template<typename Clock>
Stopwatch<Clock>::~Stopwatch() noexcept {
    slog.d << "Stopwatch \"" << mName << "\" : ["
           << mMinLap.count() << ", "
           << std::chrono::duration_cast<duration>(mAvgLap).count() << ", "
           << mMaxLap.count() << "] ns" << io::endl;
}

template<typename Stopwatch>
class AutoStopwatch {
    Stopwatch& stopwatch;
public:
    inline explicit AutoStopwatch(Stopwatch& stopwatch) noexcept: stopwatch(stopwatch) {
        stopwatch.start();
    }

    inline ~AutoStopwatch() noexcept { stopwatch.stop(); }
};

} // namespace utils

#endif // TNT_UTILS_STOPWATCH_H

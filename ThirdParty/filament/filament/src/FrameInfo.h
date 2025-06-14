
#ifndef TNT_FILAMENT_FRAMEINFO_H
#define TNT_FILAMENT_FRAMEINFO_H

#include "backend/Handle.h"
#include <private/backend/DriverApi.h>

#include <array>
#include <chrono>

#include <stdint.h>

namespace filament {
class FEngine;

struct FrameInfo {
    using duration = std::chrono::duration<float, std::milli>;
    duration frameTime{};            // frame period
    duration denoisedFrameTime{};    // frame period (median filter)
    bool valid = false;
};

class FrameInfoManager {
    static constexpr size_t POOL_COUNT = 4;
    static constexpr size_t MAX_FRAMETIME_HISTORY = 31u;

public:
    using duration = FrameInfo::duration;

    struct Config {
        uint32_t historySize;
    };

    explicit FrameInfoManager(backend::DriverApi& driver) noexcept;

    ~FrameInfoManager() noexcept;
    void terminate(backend::DriverApi& driver) noexcept;

    // call this immediately after "make current"
    void beginFrame(backend::DriverApi& driver, Config const& config, uint32_t frameId) noexcept;

    // call this immediately before "swap buffers"
    void endFrame(backend::DriverApi& driver) noexcept;

    FrameInfo const& getLastFrameInfo() const noexcept {
        return mFrameTimeHistory[0];
    }

    duration getLastFrameTime() const noexcept {
        return getLastFrameInfo().frameTime;
    }

private:
    void update(Config const& config, duration lastFrameTime) noexcept;
    backend::Handle<backend::HwTimerQuery> mQueries[POOL_COUNT];
    duration mFrameTime{};
    uint32_t mIndex = 0;
    uint32_t mLast = 0;

    std::array<FrameInfo, MAX_FRAMETIME_HISTORY> mFrameTimeHistory;
    uint32_t mFrameTimeHistorySize = 0;
};


} // namespace filament

#endif // TNT_FILAMENT_FRAMEINFO_H

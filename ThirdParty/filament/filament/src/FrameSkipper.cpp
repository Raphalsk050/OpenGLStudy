
#include "FrameSkipper.h"

#include "third_party/filament/libs/utils/include/utils/Log.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"

namespace filament {

using namespace utils;
using namespace backend;

FrameSkipper::FrameSkipper(size_t latency) noexcept
        : mLast(latency - 1) {
    assert_invariant(latency <= MAX_FRAME_LATENCY);
}

FrameSkipper::~FrameSkipper() noexcept = default;

void FrameSkipper::terminate(DriverApi& driver) noexcept {
    for (auto fence : mDelayedFences) {
        if (fence) {
            driver.destroyFence(fence);
        }
    }
}

bool FrameSkipper::beginFrame(DriverApi& driver) noexcept {
    auto& fences = mDelayedFences;
    auto fence = fences.front();
    if (fence) {
        auto status = driver.getFenceStatus(fence);
        if (status == FenceStatus::TIMEOUT_EXPIRED) {
            // Sync not ready, skip frame
            return false;
        }
        assert_invariant(status == FenceStatus::CONDITION_SATISFIED);
        driver.destroyFence(fence);
    }
    // shift all fences down by 1
    std::move(fences.begin() + 1, fences.end(), fences.begin());
    fences.back() = {};
    return true;
}

void FrameSkipper::endFrame(DriverApi& driver) noexcept {
    // If the user produced a new frame despite the fact that the previous one wasn't finished
    // (i.e. FrameSkipper::beginFrame() returned false), we need to make sure to replace
    // a fence that might be here already)
    auto& fence = mDelayedFences[mLast];
    if (fence) {
        driver.destroyFence(fence);
    }
    fence = driver.createFence();
}

} // namespace filament

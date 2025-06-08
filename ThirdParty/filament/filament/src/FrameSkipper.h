
#ifndef TNT_FILAMENT_DETAILS_FRAMESKIPPER_H
#define TNT_FILAMENT_DETAILS_FRAMESKIPPER_H

#include <backend/Handle.h>
#include <private/backend/DriverApi.h>

#include <array>

namespace filament {

class FrameSkipper {
    static constexpr size_t MAX_FRAME_LATENCY = 3;
public:
    explicit FrameSkipper(size_t latency = 2) noexcept;
    ~FrameSkipper() noexcept;

    void terminate(backend::DriverApi& driver) noexcept;

    // Returns false if we need to skip this frame, because the GPU is running behind the CPU;
    // In that case, don't call render endFrame()
    // Returns true if rendering can proceed. Always call endFrame() when done.
    bool beginFrame(backend::DriverApi& driver) noexcept;

    void endFrame(backend::DriverApi& driver) noexcept;

private:
    using Container = std::array<backend::Handle<backend::HwFence>, MAX_FRAME_LATENCY>;
    mutable Container mDelayedFences{};
    size_t mLast;
};

} // namespace filament

#endif // TNT_FILAMENT_DETAILS_FRAMESKIPPER_H

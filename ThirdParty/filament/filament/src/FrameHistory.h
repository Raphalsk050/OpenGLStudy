
#ifndef TNT_FILAMENT_FRAMEHISTORY_H
#define TNT_FILAMENT_FRAMEHISTORY_H

#include <fg/FrameGraphId.h>
#include <fg/FrameGraphTexture.h>

#include "third_party/filament/libs/math/include/math/mat4.h"

namespace filament {

// This is where we store all the history of a frame
// when adding things here, please update:
//      FView::commitFrameHistory()
struct FrameHistoryEntry {
    struct TemporalAA{
        FrameGraphTexture color;
        FrameGraphTexture::Descriptor desc;
        math::mat4 projection;     // world space to clip space
        math::float2 jitter{};
        uint32_t frameId = 0;   // used for halton sequence
    } taa;
    struct {
        FrameGraphTexture color;
        FrameGraphTexture::Descriptor desc;
        math::mat4 projection;
    } ssr;
};

template<typename T, size_t SIZE>
class TFrameHistory {
public:
    // history size
    constexpr size_t size() const noexcept { return mContainer.size(); }

    // most recent frame history entry
    T const& front() const noexcept { return mContainer.front(); }
    T& front() noexcept { return mContainer.front(); }

    // oldest frame history entry
    T const& back() const noexcept { return mContainer.back(); }
    T& back() noexcept { return mContainer.back(); }

    // access by index
    T const& operator[](size_t n) const noexcept { return mContainer[n]; }
    T& operator[](size_t n) noexcept { return mContainer[n]; }

    // the current frame info, this is where we store the current frame information
    T& getCurrent() noexcept {
        return mCurrentEntry;
    }

    const T& getCurrent() const noexcept {
        return mCurrentEntry;
    }

    T& getPrevious() noexcept {
        return mContainer[0];
    }

    const T& getPrevious() const noexcept {
        return mContainer[0];
    }

    // This pushes the current frame info to the FIFO, effectively destroying
    // the oldest state (note: only the structure is destroyed, handles stored in it may
    // have to be destroyed prior to calling this).
    void commit() noexcept {
        auto& container = mContainer;
        if (SIZE > 1u) {
            std::move_backward(container.begin(), container.end() - 1, container.end());
        }
        container.front() = std::move(mCurrentEntry);
        mCurrentEntry = {};
    }

private:
    T mCurrentEntry{};
    std::array<T, SIZE> mContainer;
};

using FrameHistory = TFrameHistory<FrameHistoryEntry, 1u>;

} // namespace filament

#endif // TNT_FILAMENT_FRAMEHISTORY_H

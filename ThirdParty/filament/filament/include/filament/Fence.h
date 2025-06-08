
//! \file

#ifndef TNT_FILAMENT_FENCE_H
#define TNT_FILAMENT_FENCE_H

#include <filament/FilamentAPI.h>

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <stdint.h>

namespace filament {

class UTILS_PUBLIC Fence : public FilamentAPI {
public:
    //! Special \p timeout value to disable wait()'s timeout.
    static constexpr uint64_t FENCE_WAIT_FOR_EVER = backend::FENCE_WAIT_FOR_EVER;

    //! Error codes for Fence::wait()
    using FenceStatus = backend::FenceStatus;

    enum class Mode : uint8_t {
        FLUSH,          //!< The command stream is flushed
        DONT_FLUSH      //!< The command stream is not flushed
    };

    FenceStatus wait(Mode mode = Mode::FLUSH, uint64_t timeout = FENCE_WAIT_FOR_EVER);

    static FenceStatus waitAndDestroy(Fence* UTILS_NONNULL fence, Mode mode = Mode::FLUSH);

protected:
    // prevent heap allocation
    ~Fence() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_FENCE_H


//! \file

#ifndef TNT_FILAMENT_VIEWPORT_H
#define TNT_FILAMENT_VIEWPORT_H

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <stddef.h>
#include <stdint.h>

namespace filament {

class UTILS_PUBLIC Viewport : public backend::Viewport {
public:
    Viewport() noexcept : backend::Viewport{} {}

    Viewport(int32_t left, int32_t bottom, uint32_t width, uint32_t height) noexcept
            : backend::Viewport{ left, bottom, width, height } {
    }

    bool empty() const noexcept { return !width || !height; }

private:
    friend bool operator==(Viewport const& lhs, Viewport const& rhs) noexcept {
        return (&rhs == &lhs) ||
               (rhs.left == lhs.left && rhs.bottom == lhs.bottom &&
                rhs.width == lhs.width && rhs.height == lhs.height);
    }

    friend bool operator!=(Viewport const& lhs, Viewport const& rhs) noexcept {
        return !(rhs == lhs);
    }
};

} // namespace filament

#endif // TNT_FILAMENT_VIEWPORT_H

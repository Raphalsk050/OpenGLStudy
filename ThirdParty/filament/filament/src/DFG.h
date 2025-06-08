
#ifndef TNT_FILAMENT_DETAILS_DFG_H
#define TNT_FILAMENT_DETAILS_DFG_H

#include <backend/Handle.h>

#include "details/Texture.h"

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament {

class FEngine;

#if !defined(FILAMENT_DFG_LUT_SIZE)
#define FILAMENT_DFG_LUT_SIZE 128
#endif

class DFG {
public:
    explicit DFG() noexcept = default;

    DFG(DFG const& rhs) = delete;
    DFG(DFG&& rhs) = delete;
    DFG& operator=(DFG const& rhs) = delete;
    DFG& operator=(DFG&& rhs) = delete;

    void init(FEngine& engine) noexcept;

    size_t getLutSize() const noexcept {
        return DFG_LUT_SIZE;
    }

    bool isValid() const noexcept {
        return mLUT != nullptr;
    }

    backend::Handle<backend::HwTexture> getTexture() const noexcept {
        return mLUT->getHwHandle();
    }

    void terminate(FEngine& engine) noexcept;

private:
    FTexture* mLUT = nullptr;

    // make sure to use the right size here
    static constexpr size_t DFG_LUT_SIZE = FILAMENT_DFG_LUT_SIZE;

    // this lookup table is generated with cmgen
    static const uint16_t DFG_LUT[];
};

#undef FILAMENT_DFG_LUT_SIZE

} // namespace filament

#endif // TNT_FILAMENT_DETAILS_DFG_H

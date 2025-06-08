
#ifndef TNT_FILAMENT_DETAILS_COLORGRADING_H
#define TNT_FILAMENT_DETAILS_COLORGRADING_H

#include "downcast.h"

#include <backend/DriverEnums.h>
#include <backend/Handle.h>

#include <filament/ColorGrading.h>

#include "third_party/filament/libs/math/include/math/mathfwd.h"

namespace filament {

class FEngine;

class FColorGrading : public ColorGrading {
public:
    FColorGrading(FEngine& engine, const Builder& builder);
    FColorGrading(const FColorGrading& rhs) = delete;
    FColorGrading& operator=(const FColorGrading& rhs) = delete;

    ~FColorGrading() noexcept;

    // frees driver resources, object becomes invalid
    void terminate(FEngine& engine);

    backend::TextureHandle getHwHandle() const noexcept { return mLutHandle; }

    uint32_t getDimension() const noexcept { return mDimension; }

private:
    backend::TextureHandle mLutHandle;
    uint32_t mDimension;
};

FILAMENT_DOWNCAST(ColorGrading)

} // namespace filament

#endif //TNT_FILAMENT_DETAILS_COLORGRADING_H

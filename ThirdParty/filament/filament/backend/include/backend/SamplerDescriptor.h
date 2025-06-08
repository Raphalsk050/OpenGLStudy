
//! \file

#ifndef TNT_FILAMENT_BACKEND_SAMPLERDESCRIPTOR_H
#define TNT_FILAMENT_BACKEND_SAMPLERDESCRIPTOR_H

#include <backend/DriverEnums.h>
#include <backend/Handle.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament::backend {

struct UTILS_PUBLIC SamplerDescriptor {
    Handle<HwTexture> t;
    SamplerParams s{};
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_SAMPLERDESCRIPTOR_H

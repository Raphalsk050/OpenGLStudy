
//! \file

#ifndef TNT_FILAMENT_BACKEND_PLATFORM_FACTORY_H
#define TNT_FILAMENT_BACKEND_PLATFORM_FACTORY_H

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament::backend {

class Platform;

class UTILS_PUBLIC PlatformFactory  {
public:

    static Platform* create(backend::Backend* backendHint) noexcept;

    static void destroy(Platform** platform) noexcept;
};

} // namespace filament

#endif // TNT_FILAMENT_BACKEND_PLATFORM_FACTORY_H

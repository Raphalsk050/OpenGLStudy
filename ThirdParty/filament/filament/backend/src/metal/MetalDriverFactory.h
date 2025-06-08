
#ifndef TNT_FILAMENT_DRIVER_METALDRIVERFACTORY_H
#define TNT_FILAMENT_DRIVER_METALDRIVERFACTORY_H

#include <backend/Platform.h>

namespace filament {
namespace backend {
class MetalPlatform;
class Driver;

class MetalDriverFactory {
public:
    static Driver* create(MetalPlatform* platform, const Platform::DriverConfig& driverConfig);
};

} // namespace backend
} // namespace filament

#endif //TNT_FILAMENT_DRIVER_METALDRIVERFACTORY_H

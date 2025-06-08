
#ifndef TNT_FILAMENT_BACKEND_VULKANDRIVERFACTORY_H
#define TNT_FILAMENT_BACKEND_VULKANDRIVERFACTORY_H

#include <backend/Platform.h>

#include <stdint.h>

namespace filament::backend {

class VulkanPlatform;
class Driver;

class VulkanDriverFactory {
public:
    static Driver* create(VulkanPlatform* platform,
            const char* const* ppEnabledExtensions, uint32_t enabledExtensionCount,
            const Platform::DriverConfig& driverConfig) noexcept;
};

} // namespace filament::backend

#endif //TNT_FILAMENT_BACKEND_VULKANDRIVERFACTORY_H


#include "noop/PlatformNoop.h"

#include "noop/NoopDriver.h"

namespace filament::backend {

Driver* PlatformNoop::createDriver(void* const sharedGLContext, const Platform::DriverConfig& driverConfig) noexcept {
    return NoopDriver::create();
}

} // namespace filament

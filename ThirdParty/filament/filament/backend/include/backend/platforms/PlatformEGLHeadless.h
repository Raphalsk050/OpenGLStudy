
#ifndef TNT_FILAMENT_DRIVER_OPENGL_PLATFORM_EGL_HEADLESS_H
#define TNT_FILAMENT_DRIVER_OPENGL_PLATFORM_EGL_HEADLESS_H

#include "PlatformEGL.h"

namespace filament::backend {

class PlatformEGLHeadless : public PlatformEGL {
public:
    PlatformEGLHeadless() noexcept;

    Driver* createDriver(void* sharedContext,
            const Platform::DriverConfig& driverConfig) noexcept override;

protected:
    bool isOpenGL() const noexcept override;
};

} // namespace filament

#endif // TNT_FILAMENT_DRIVER_OPENGL_PLATFORM_EGL_HEADLESS_H

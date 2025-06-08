
#include <backend/platforms/PlatformEGLHeadless.h>

#include "opengl/GLUtils.h"

#include <EGL/egl.h>
#include <EGL/eglext.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Log.h"
#include "third_party/filament/libs/utils/include/utils/Panic.h"

using namespace utils;

namespace filament {
using namespace backend;

PlatformEGLHeadless::PlatformEGLHeadless() noexcept
        : PlatformEGL() {
}

bool PlatformEGLHeadless::isOpenGL() const noexcept {
    return  true;
}

backend::Driver* PlatformEGLHeadless::createDriver(void* sharedContext,
        const Platform::DriverConfig& driverConfig) noexcept {
    EGLBoolean bindAPI = eglBindAPI(EGL_OPENGL_API);
    if (UTILS_UNLIKELY(!bindAPI)) {
        slog.e << "eglBindAPI EGL_OPENGL_API failed" << io::endl;
        return nullptr;
    }
    int bindBlueGL = bluegl::bind();
    if (UTILS_UNLIKELY(bindBlueGL != 0)) {
        slog.e << "bluegl bind failed" << io::endl;
        return nullptr;
    }

    return PlatformEGL::createDriver(sharedContext, driverConfig);
}

} // namespace filament

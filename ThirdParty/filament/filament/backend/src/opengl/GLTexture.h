
#ifndef TNT_FILAMENT_BACKEND_OPENGL_GLTEXTURE_H
#define TNT_FILAMENT_BACKEND_OPENGL_GLTEXTURE_H

#include "DriverBase.h"

#include "gl_headers.h"

#include <backend/platforms/OpenGLPlatform.h>

#include <stdint.h>

namespace filament::backend {

struct GLTexture : public HwTexture {
    using HwTexture::HwTexture;
    struct GL {
        GL() noexcept : imported(false), sidecarSamples(1), reserved1(0) {}
        GLuint id = 0;          // texture or renderbuffer id
        GLenum target = 0;
        GLenum internalFormat = 0;
        GLuint sidecarRenderBufferMS = 0;  // multi-sample sidecar renderbuffer

        // texture parameters go here too
        GLfloat anisotropy = 1.0;
        int8_t baseLevel = 127;
        int8_t maxLevel = -1;
        uint8_t reserved0 = 0;
        bool imported           : 1;
        uint8_t sidecarSamples  : 4;
        uint8_t reserved1       : 3;
    } gl;

    OpenGLPlatform::ExternalTexture* externalTexture = nullptr;
};


} // namespace filament::backend

#endif //TNT_FILAMENT_BACKEND_OPENGL_GLTEXTURE_H

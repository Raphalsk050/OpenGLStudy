
#ifndef TNT_FILAMENT_BACKEND_OPENGL_GLBUFFEROBJECT_H
#define TNT_FILAMENT_BACKEND_OPENGL_GLBUFFEROBJECT_H

#include "DriverBase.h"

#include "gl_headers.h"

#include <backend/DriverEnums.h>

#include <stdint.h>

namespace filament::backend {

struct GLBufferObject : public HwBufferObject {
    using HwBufferObject::HwBufferObject;
    GLBufferObject(uint32_t size,
            BufferObjectBinding bindingType, BufferUsage usage) noexcept
            : HwBufferObject(size), usage(usage), bindingType(bindingType) {
    }

    struct {
        GLuint id;
        union {
            GLenum binding;
            void* buffer;
        };
    } gl;
    BufferUsage usage;
    BufferObjectBinding bindingType;
    uint16_t age = 0;
};

} // namespace filament::backend

#endif //TNT_FILAMENT_BACKEND_OPENGL_GLBUFFEROBJECT_H

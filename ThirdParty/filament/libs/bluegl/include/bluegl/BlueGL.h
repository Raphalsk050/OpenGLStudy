

#ifndef TNT_FILAMENT_BLUEGL__H
#define TNT_FILAMENT_BLUEGL__H


// MSVC includes .../Windows Kits\10\Include\10.0.17763.0\um\GL/gl.h, with gl APIs conflicting with
// bluegl\include\GL/glcorearb.h, causing errors for OpenGL APIs such as:
// error C2375:  'glBindTexture': redefinition; different linkage
#ifndef FILAMENT_PLATFORM_WGL
    #define GL_GLEXT_PROTOTYPES 1
#endif


#include <GL/glcorearb.h>
#include <GL/glext.h>

#if defined(WIN32)

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#ifdef far
#undef far
#endif

#ifdef near
#undef near
#endif

#ifdef ERROR
#undef ERROR
#endif

#ifdef OPAQUE
#undef OPAQUE
#endif

#ifdef TRANSPARENT
#undef TRANSPARENT
#endif

#ifdef PURE
#undef PURE
#endif

#endif

namespace bluegl {

int bind();

void unbind();


} // namespace bluegl

#endif // TNT_FILAMENT_BLUEGL__H

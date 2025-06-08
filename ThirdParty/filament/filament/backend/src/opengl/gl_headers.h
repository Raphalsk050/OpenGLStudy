
#ifndef TNT_FILAMENT_BACKEND_OPENGL_GL_HEADERS_H
#define TNT_FILAMENT_BACKEND_OPENGL_GL_HEADERS_H



#if defined(__ANDROID__) || defined(FILAMENT_USE_EXTERNAL_GLES3) || defined(__EMSCRIPTEN__)

    #if defined(__EMSCRIPTEN__)
    #   include <GLES3/gl3.h>
    #else
//    #   include <GLES2/gl2.h>
    #   include <GLES3/gl31.h>
    #endif
    #include <GLES2/gl2ext.h>

    // For development and debugging purpose only, we want to support compiling this backend
    // with ES2 only headers, in this case (i.e. we have VERSION_2 but not VERSION_3+),
    // we define FILAMENT_SILENCE_NOT_SUPPORTED_BY_ES2 with the purpose of compiling out
    // code that cannot be compiled with ES2 headers. In production, this code is compiled in but
    // is never executed thanks to runtime checks or asserts.
    #if defined(GL_ES_VERSION_2_0) && !defined(GL_ES_VERSION_3_0)
    #   define FILAMENT_SILENCE_NOT_SUPPORTED_BY_ES2
    #endif

#elif defined(IOS)

    #define GLES_SILENCE_DEPRECATION

    #include <OpenGLES/ES3/gl.h>
    #include <OpenGLES/ES3/glext.h>

#else

    // bluegl exposes symbols prefixed with bluegl_ to avoid clashing with clients that also link
    // against GL.
    // This header re-defines GL function names with the bluegl_ prefix.
    // For example:
    //   #define glFunction bluegl_glFunction
    // This header must come before <bluegl/BlueGL.h>.
    #include <bluegl/BlueGLDefines.h>
    #include <bluegl/BlueGL.h>

#endif


#if defined(GL_ES_VERSION_2_0)  // this basically means all versions of GLES

#if defined(IOS)

// iOS headers only provide prototypes, nothing to do.

#else

#define FILAMENT_IMPORT_ENTRY_POINTS


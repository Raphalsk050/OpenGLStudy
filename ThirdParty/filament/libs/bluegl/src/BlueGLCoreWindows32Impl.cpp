

#include <bluegl/BlueGL.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void* __blue_glCore_glCullFace;
void APIENTRY bluegl_glCullFace (GLenum mode) {
    typedef void (APIENTRYP PFN_glCullFace) (GLenum mode);
    return ((PFN_glCullFace)__blue_glCore_glCullFace)(mode);
}

extern void* __blue_glCore_glFrontFace;
void APIENTRY bluegl_glFrontFace (GLenum mode) {
    typedef void (APIENTRYP PFN_glFrontFace) (GLenum mode);
    return ((PFN_glFrontFace)__blue_glCore_glFrontFace)(mode);
}

extern void* __blue_glCore_glHint;
void APIENTRY bluegl_glHint (GLenum target, GLenum mode) {
    typedef void (APIENTRYP PFN_glHint) (GLenum target, GLenum mode);
    return ((PFN_glHint)__blue_glCore_glHint)(target, mode);
}

extern void* __blue_glCore_glLineWidth;
void APIENTRY bluegl_glLineWidth (GLfloat width) {
    typedef void (APIENTRYP PFN_glLineWidth) (GLfloat width);
    return ((PFN_glLineWidth)__blue_glCore_glLineWidth)(width);
}

extern void* __blue_glCore_glPointSize;
void APIENTRY bluegl_glPointSize (GLfloat size) {
    typedef void (APIENTRYP PFN_glPointSize) (GLfloat size);
    return ((PFN_glPointSize)__blue_glCore_glPointSize)(size);
}

extern void* __blue_glCore_glPolygonMode;
void APIENTRY bluegl_glPolygonMode (GLenum face, GLenum mode) {
    typedef void (APIENTRYP PFN_glPolygonMode) (GLenum face, GLenum mode);
    return ((PFN_glPolygonMode)__blue_glCore_glPolygonMode)(face, mode);
}

extern void* __blue_glCore_glScissor;
void APIENTRY bluegl_glScissor (GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glScissor) (GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glScissor)__blue_glCore_glScissor)(x, y, width, height);
}

extern void* __blue_glCore_glTexParameterf;
void APIENTRY bluegl_glTexParameterf (GLenum target, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glTexParameterf) (GLenum target, GLenum pname, GLfloat param);
    return ((PFN_glTexParameterf)__blue_glCore_glTexParameterf)(target, pname, param);
}

extern void* __blue_glCore_glTexParameterfv;
void APIENTRY bluegl_glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glTexParameterfv) (GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glTexParameterfv)__blue_glCore_glTexParameterfv)(target, pname, params);
}

extern void* __blue_glCore_glTexParameteri;
void APIENTRY bluegl_glTexParameteri (GLenum target, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glTexParameteri) (GLenum target, GLenum pname, GLint param);
    return ((PFN_glTexParameteri)__blue_glCore_glTexParameteri)(target, pname, param);
}

extern void* __blue_glCore_glTexParameteriv;
void APIENTRY bluegl_glTexParameteriv (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glTexParameteriv) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glTexParameteriv)__blue_glCore_glTexParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glTexImage1D;
void APIENTRY bluegl_glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexImage1D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexImage1D)__blue_glCore_glTexImage1D)(target, level, internalformat, width, border, format, type, pixels);
}

extern void* __blue_glCore_glTexImage2D;
void APIENTRY bluegl_glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexImage2D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexImage2D)__blue_glCore_glTexImage2D)(target, level, internalformat, width, height, border, format, type, pixels);
}

extern void* __blue_glCore_glDrawBuffer;
void APIENTRY bluegl_glDrawBuffer (GLenum buf) {
    typedef void (APIENTRYP PFN_glDrawBuffer) (GLenum buf);
    return ((PFN_glDrawBuffer)__blue_glCore_glDrawBuffer)(buf);
}

extern void* __blue_glCore_glClear;
void APIENTRY bluegl_glClear (GLbitfield mask) {
    typedef void (APIENTRYP PFN_glClear) (GLbitfield mask);
    return ((PFN_glClear)__blue_glCore_glClear)(mask);
}

extern void* __blue_glCore_glClearColor;
void APIENTRY bluegl_glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    typedef void (APIENTRYP PFN_glClearColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    return ((PFN_glClearColor)__blue_glCore_glClearColor)(red, green, blue, alpha);
}

extern void* __blue_glCore_glClearStencil;
void APIENTRY bluegl_glClearStencil (GLint s) {
    typedef void (APIENTRYP PFN_glClearStencil) (GLint s);
    return ((PFN_glClearStencil)__blue_glCore_glClearStencil)(s);
}

extern void* __blue_glCore_glClearDepth;
void APIENTRY bluegl_glClearDepth (GLdouble depth) {
    typedef void (APIENTRYP PFN_glClearDepth) (GLdouble depth);
    return ((PFN_glClearDepth)__blue_glCore_glClearDepth)(depth);
}

extern void* __blue_glCore_glStencilMask;
void APIENTRY bluegl_glStencilMask (GLuint mask) {
    typedef void (APIENTRYP PFN_glStencilMask) (GLuint mask);
    return ((PFN_glStencilMask)__blue_glCore_glStencilMask)(mask);
}

extern void* __blue_glCore_glColorMask;
void APIENTRY bluegl_glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    typedef void (APIENTRYP PFN_glColorMask) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    return ((PFN_glColorMask)__blue_glCore_glColorMask)(red, green, blue, alpha);
}

extern void* __blue_glCore_glDepthMask;
void APIENTRY bluegl_glDepthMask (GLboolean flag) {
    typedef void (APIENTRYP PFN_glDepthMask) (GLboolean flag);
    return ((PFN_glDepthMask)__blue_glCore_glDepthMask)(flag);
}

extern void* __blue_glCore_glDisable;
void APIENTRY bluegl_glDisable (GLenum cap) {
    typedef void (APIENTRYP PFN_glDisable) (GLenum cap);
    return ((PFN_glDisable)__blue_glCore_glDisable)(cap);
}

extern void* __blue_glCore_glEnable;
void APIENTRY bluegl_glEnable (GLenum cap) {
    typedef void (APIENTRYP PFN_glEnable) (GLenum cap);
    return ((PFN_glEnable)__blue_glCore_glEnable)(cap);
}

extern void* __blue_glCore_glFinish;
void APIENTRY bluegl_glFinish (void) {
    typedef void (APIENTRYP PFN_glFinish) (void);
    return ((PFN_glFinish)__blue_glCore_glFinish)();
}

extern void* __blue_glCore_glFlush;
void APIENTRY bluegl_glFlush (void) {
    typedef void (APIENTRYP PFN_glFlush) (void);
    return ((PFN_glFlush)__blue_glCore_glFlush)();
}

extern void* __blue_glCore_glBlendFunc;
void APIENTRY bluegl_glBlendFunc (GLenum sfactor, GLenum dfactor) {
    typedef void (APIENTRYP PFN_glBlendFunc) (GLenum sfactor, GLenum dfactor);
    return ((PFN_glBlendFunc)__blue_glCore_glBlendFunc)(sfactor, dfactor);
}

extern void* __blue_glCore_glLogicOp;
void APIENTRY bluegl_glLogicOp (GLenum opcode) {
    typedef void (APIENTRYP PFN_glLogicOp) (GLenum opcode);
    return ((PFN_glLogicOp)__blue_glCore_glLogicOp)(opcode);
}

extern void* __blue_glCore_glStencilFunc;
void APIENTRY bluegl_glStencilFunc (GLenum func, GLint ref, GLuint mask) {
    typedef void (APIENTRYP PFN_glStencilFunc) (GLenum func, GLint ref, GLuint mask);
    return ((PFN_glStencilFunc)__blue_glCore_glStencilFunc)(func, ref, mask);
}

extern void* __blue_glCore_glStencilOp;
void APIENTRY bluegl_glStencilOp (GLenum fail, GLenum zfail, GLenum zpass) {
    typedef void (APIENTRYP PFN_glStencilOp) (GLenum fail, GLenum zfail, GLenum zpass);
    return ((PFN_glStencilOp)__blue_glCore_glStencilOp)(fail, zfail, zpass);
}

extern void* __blue_glCore_glDepthFunc;
void APIENTRY bluegl_glDepthFunc (GLenum func) {
    typedef void (APIENTRYP PFN_glDepthFunc) (GLenum func);
    return ((PFN_glDepthFunc)__blue_glCore_glDepthFunc)(func);
}

extern void* __blue_glCore_glPixelStoref;
void APIENTRY bluegl_glPixelStoref (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glPixelStoref) (GLenum pname, GLfloat param);
    return ((PFN_glPixelStoref)__blue_glCore_glPixelStoref)(pname, param);
}

extern void* __blue_glCore_glPixelStorei;
void APIENTRY bluegl_glPixelStorei (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glPixelStorei) (GLenum pname, GLint param);
    return ((PFN_glPixelStorei)__blue_glCore_glPixelStorei)(pname, param);
}

extern void* __blue_glCore_glReadBuffer;
void APIENTRY bluegl_glReadBuffer (GLenum src) {
    typedef void (APIENTRYP PFN_glReadBuffer) (GLenum src);
    return ((PFN_glReadBuffer)__blue_glCore_glReadBuffer)(src);
}

extern void* __blue_glCore_glReadPixels;
void APIENTRY bluegl_glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) {
    typedef void (APIENTRYP PFN_glReadPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
    return ((PFN_glReadPixels)__blue_glCore_glReadPixels)(x, y, width, height, format, type, pixels);
}

extern void* __blue_glCore_glGetBooleanv;
void APIENTRY bluegl_glGetBooleanv (GLenum pname, GLboolean *data) {
    typedef void (APIENTRYP PFN_glGetBooleanv) (GLenum pname, GLboolean *data);
    return ((PFN_glGetBooleanv)__blue_glCore_glGetBooleanv)(pname, data);
}

extern void* __blue_glCore_glGetDoublev;
void APIENTRY bluegl_glGetDoublev (GLenum pname, GLdouble *data) {
    typedef void (APIENTRYP PFN_glGetDoublev) (GLenum pname, GLdouble *data);
    return ((PFN_glGetDoublev)__blue_glCore_glGetDoublev)(pname, data);
}

extern void* __blue_glCore_glGetError;
GLenum APIENTRY bluegl_glGetError (void) {
    typedef GLenum (APIENTRYP PFN_glGetError) (void);
    return ((PFN_glGetError)__blue_glCore_glGetError)();
}

extern void* __blue_glCore_glGetFloatv;
void APIENTRY bluegl_glGetFloatv (GLenum pname, GLfloat *data) {
    typedef void (APIENTRYP PFN_glGetFloatv) (GLenum pname, GLfloat *data);
    return ((PFN_glGetFloatv)__blue_glCore_glGetFloatv)(pname, data);
}

extern void* __blue_glCore_glGetIntegerv;
void APIENTRY bluegl_glGetIntegerv (GLenum pname, GLint *data) {
    typedef void (APIENTRYP PFN_glGetIntegerv) (GLenum pname, GLint *data);
    return ((PFN_glGetIntegerv)__blue_glCore_glGetIntegerv)(pname, data);
}

extern void* __blue_glCore_glGetString;
const GLubyte *APIENTRY bluegl_glGetString (GLenum name) {
    typedef const GLubyte *(APIENTRYP PFN_glGetString) (GLenum name);
    return ((PFN_glGetString)__blue_glCore_glGetString)(name);
}

extern void* __blue_glCore_glGetTexImage;
void APIENTRY bluegl_glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, void *pixels) {
    typedef void (APIENTRYP PFN_glGetTexImage) (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
    return ((PFN_glGetTexImage)__blue_glCore_glGetTexImage)(target, level, format, type, pixels);
}

extern void* __blue_glCore_glGetTexParameterfv;
void APIENTRY bluegl_glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetTexParameterfv) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetTexParameterfv)__blue_glCore_glGetTexParameterfv)(target, pname, params);
}

extern void* __blue_glCore_glGetTexParameteriv;
void APIENTRY bluegl_glGetTexParameteriv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTexParameteriv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetTexParameteriv)__blue_glCore_glGetTexParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glGetTexLevelParameterfv;
void APIENTRY bluegl_glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetTexLevelParameterfv) (GLenum target, GLint level, GLenum pname, GLfloat *params);
    return ((PFN_glGetTexLevelParameterfv)__blue_glCore_glGetTexLevelParameterfv)(target, level, pname, params);
}

extern void* __blue_glCore_glGetTexLevelParameteriv;
void APIENTRY bluegl_glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTexLevelParameteriv) (GLenum target, GLint level, GLenum pname, GLint *params);
    return ((PFN_glGetTexLevelParameteriv)__blue_glCore_glGetTexLevelParameteriv)(target, level, pname, params);
}

extern void* __blue_glCore_glIsEnabled;
GLboolean APIENTRY bluegl_glIsEnabled (GLenum cap) {
    typedef GLboolean (APIENTRYP PFN_glIsEnabled) (GLenum cap);
    return ((PFN_glIsEnabled)__blue_glCore_glIsEnabled)(cap);
}

extern void* __blue_glCore_glDepthRange;
void APIENTRY bluegl_glDepthRange (GLdouble near, GLdouble far) {
    typedef void (APIENTRYP PFN_glDepthRange) (GLdouble near, GLdouble far);
    return ((PFN_glDepthRange)__blue_glCore_glDepthRange)(near, far);
}

extern void* __blue_glCore_glViewport;
void APIENTRY bluegl_glViewport (GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glViewport) (GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glViewport)__blue_glCore_glViewport)(x, y, width, height);
}

extern void* __blue_glCore_glDrawArrays;
void APIENTRY bluegl_glDrawArrays (GLenum mode, GLint first, GLsizei count) {
    typedef void (APIENTRYP PFN_glDrawArrays) (GLenum mode, GLint first, GLsizei count);
    return ((PFN_glDrawArrays)__blue_glCore_glDrawArrays)(mode, first, count);
}

extern void* __blue_glCore_glDrawElements;
void APIENTRY bluegl_glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices) {
    typedef void (APIENTRYP PFN_glDrawElements) (GLenum mode, GLsizei count, GLenum type, const void *indices);
    return ((PFN_glDrawElements)__blue_glCore_glDrawElements)(mode, count, type, indices);
}

extern void* __blue_glCore_glGetPointerv;
void APIENTRY bluegl_glGetPointerv (GLenum pname, void **params) {
    typedef void (APIENTRYP PFN_glGetPointerv) (GLenum pname, void **params);
    return ((PFN_glGetPointerv)__blue_glCore_glGetPointerv)(pname, params);
}

extern void* __blue_glCore_glPolygonOffset;
void APIENTRY bluegl_glPolygonOffset (GLfloat factor, GLfloat units) {
    typedef void (APIENTRYP PFN_glPolygonOffset) (GLfloat factor, GLfloat units);
    return ((PFN_glPolygonOffset)__blue_glCore_glPolygonOffset)(factor, units);
}

extern void* __blue_glCore_glCopyTexImage1D;
void APIENTRY bluegl_glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    typedef void (APIENTRYP PFN_glCopyTexImage1D) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    return ((PFN_glCopyTexImage1D)__blue_glCore_glCopyTexImage1D)(target, level, internalformat, x, y, width, border);
}

extern void* __blue_glCore_glCopyTexImage2D;
void APIENTRY bluegl_glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    typedef void (APIENTRYP PFN_glCopyTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    return ((PFN_glCopyTexImage2D)__blue_glCore_glCopyTexImage2D)(target, level, internalformat, x, y, width, height, border);
}

extern void* __blue_glCore_glCopyTexSubImage1D;
void APIENTRY bluegl_glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyTexSubImage1D)__blue_glCore_glCopyTexSubImage1D)(target, level, xoffset, x, y, width);
}

extern void* __blue_glCore_glCopyTexSubImage2D;
void APIENTRY bluegl_glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyTexSubImage2D)__blue_glCore_glCopyTexSubImage2D)(target, level, xoffset, yoffset, x, y, width, height);
}

extern void* __blue_glCore_glTexSubImage1D;
void APIENTRY bluegl_glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexSubImage1D)__blue_glCore_glTexSubImage1D)(target, level, xoffset, width, format, type, pixels);
}

extern void* __blue_glCore_glTexSubImage2D;
void APIENTRY bluegl_glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexSubImage2D)__blue_glCore_glTexSubImage2D)(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

extern void* __blue_glCore_glBindTexture;
void APIENTRY bluegl_glBindTexture (GLenum target, GLuint texture) {
    typedef void (APIENTRYP PFN_glBindTexture) (GLenum target, GLuint texture);
    return ((PFN_glBindTexture)__blue_glCore_glBindTexture)(target, texture);
}

extern void* __blue_glCore_glDeleteTextures;
void APIENTRY bluegl_glDeleteTextures (GLsizei n, const GLuint *textures) {
    typedef void (APIENTRYP PFN_glDeleteTextures) (GLsizei n, const GLuint *textures);
    return ((PFN_glDeleteTextures)__blue_glCore_glDeleteTextures)(n, textures);
}

extern void* __blue_glCore_glGenTextures;
void APIENTRY bluegl_glGenTextures (GLsizei n, GLuint *textures) {
    typedef void (APIENTRYP PFN_glGenTextures) (GLsizei n, GLuint *textures);
    return ((PFN_glGenTextures)__blue_glCore_glGenTextures)(n, textures);
}

extern void* __blue_glCore_glIsTexture;
GLboolean APIENTRY bluegl_glIsTexture (GLuint texture) {
    typedef GLboolean (APIENTRYP PFN_glIsTexture) (GLuint texture);
    return ((PFN_glIsTexture)__blue_glCore_glIsTexture)(texture);
}

extern void* __blue_glCore_glDrawRangeElements;
void APIENTRY bluegl_glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) {
    typedef void (APIENTRYP PFN_glDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
    return ((PFN_glDrawRangeElements)__blue_glCore_glDrawRangeElements)(mode, start, end, count, type, indices);
}

extern void* __blue_glCore_glTexImage3D;
void APIENTRY bluegl_glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexImage3D)__blue_glCore_glTexImage3D)(target, level, internalformat, width, height, depth, border, format, type, pixels);
}

extern void* __blue_glCore_glTexSubImage3D;
void APIENTRY bluegl_glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexSubImage3D)__blue_glCore_glTexSubImage3D)(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

extern void* __blue_glCore_glCopyTexSubImage3D;
void APIENTRY bluegl_glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyTexSubImage3D)__blue_glCore_glCopyTexSubImage3D)(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

extern void* __blue_glCore_glActiveTexture;
void APIENTRY bluegl_glActiveTexture (GLenum texture) {
    typedef void (APIENTRYP PFN_glActiveTexture) (GLenum texture);
    return ((PFN_glActiveTexture)__blue_glCore_glActiveTexture)(texture);
}

extern void* __blue_glCore_glSampleCoverage;
void APIENTRY bluegl_glSampleCoverage (GLfloat value, GLboolean invert) {
    typedef void (APIENTRYP PFN_glSampleCoverage) (GLfloat value, GLboolean invert);
    return ((PFN_glSampleCoverage)__blue_glCore_glSampleCoverage)(value, invert);
}

extern void* __blue_glCore_glCompressedTexImage3D;
void APIENTRY bluegl_glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexImage3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexImage3D)__blue_glCore_glCompressedTexImage3D)(target, level, internalformat, width, height, depth, border, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexImage2D;
void APIENTRY bluegl_glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexImage2D)__blue_glCore_glCompressedTexImage2D)(target, level, internalformat, width, height, border, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexImage1D;
void APIENTRY bluegl_glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexImage1D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexImage1D)__blue_glCore_glCompressedTexImage1D)(target, level, internalformat, width, border, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexSubImage3D;
void APIENTRY bluegl_glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexSubImage3D)__blue_glCore_glCompressedTexSubImage3D)(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexSubImage2D;
void APIENTRY bluegl_glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexSubImage2D)__blue_glCore_glCompressedTexSubImage2D)(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexSubImage1D;
void APIENTRY bluegl_glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexSubImage1D)__blue_glCore_glCompressedTexSubImage1D)(target, level, xoffset, width, format, imageSize, data);
}

extern void* __blue_glCore_glGetCompressedTexImage;
void APIENTRY bluegl_glGetCompressedTexImage (GLenum target, GLint level, void *img) {
    typedef void (APIENTRYP PFN_glGetCompressedTexImage) (GLenum target, GLint level, void *img);
    return ((PFN_glGetCompressedTexImage)__blue_glCore_glGetCompressedTexImage)(target, level, img);
}

extern void* __blue_glCore_glBlendFuncSeparate;
void APIENTRY bluegl_glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    typedef void (APIENTRYP PFN_glBlendFuncSeparate) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
    return ((PFN_glBlendFuncSeparate)__blue_glCore_glBlendFuncSeparate)(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

extern void* __blue_glCore_glMultiDrawArrays;
void APIENTRY bluegl_glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) {
    typedef void (APIENTRYP PFN_glMultiDrawArrays) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
    return ((PFN_glMultiDrawArrays)__blue_glCore_glMultiDrawArrays)(mode, first, count, drawcount);
}

extern void* __blue_glCore_glMultiDrawElements;
void APIENTRY bluegl_glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) {
    typedef void (APIENTRYP PFN_glMultiDrawElements) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
    return ((PFN_glMultiDrawElements)__blue_glCore_glMultiDrawElements)(mode, count, type, indices, drawcount);
}

extern void* __blue_glCore_glPointParameterf;
void APIENTRY bluegl_glPointParameterf (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glPointParameterf) (GLenum pname, GLfloat param);
    return ((PFN_glPointParameterf)__blue_glCore_glPointParameterf)(pname, param);
}

extern void* __blue_glCore_glPointParameterfv;
void APIENTRY bluegl_glPointParameterfv (GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glPointParameterfv) (GLenum pname, const GLfloat *params);
    return ((PFN_glPointParameterfv)__blue_glCore_glPointParameterfv)(pname, params);
}

extern void* __blue_glCore_glPointParameteri;
void APIENTRY bluegl_glPointParameteri (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glPointParameteri) (GLenum pname, GLint param);
    return ((PFN_glPointParameteri)__blue_glCore_glPointParameteri)(pname, param);
}

extern void* __blue_glCore_glPointParameteriv;
void APIENTRY bluegl_glPointParameteriv (GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glPointParameteriv) (GLenum pname, const GLint *params);
    return ((PFN_glPointParameteriv)__blue_glCore_glPointParameteriv)(pname, params);
}

extern void* __blue_glCore_glBlendColor;
void APIENTRY bluegl_glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    typedef void (APIENTRYP PFN_glBlendColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    return ((PFN_glBlendColor)__blue_glCore_glBlendColor)(red, green, blue, alpha);
}

extern void* __blue_glCore_glBlendEquation;
void APIENTRY bluegl_glBlendEquation (GLenum mode) {
    typedef void (APIENTRYP PFN_glBlendEquation) (GLenum mode);
    return ((PFN_glBlendEquation)__blue_glCore_glBlendEquation)(mode);
}

extern void* __blue_glCore_glGenQueries;
void APIENTRY bluegl_glGenQueries (GLsizei n, GLuint *ids) {
    typedef void (APIENTRYP PFN_glGenQueries) (GLsizei n, GLuint *ids);
    return ((PFN_glGenQueries)__blue_glCore_glGenQueries)(n, ids);
}

extern void* __blue_glCore_glDeleteQueries;
void APIENTRY bluegl_glDeleteQueries (GLsizei n, const GLuint *ids) {
    typedef void (APIENTRYP PFN_glDeleteQueries) (GLsizei n, const GLuint *ids);
    return ((PFN_glDeleteQueries)__blue_glCore_glDeleteQueries)(n, ids);
}

extern void* __blue_glCore_glIsQuery;
GLboolean APIENTRY bluegl_glIsQuery (GLuint id) {
    typedef GLboolean (APIENTRYP PFN_glIsQuery) (GLuint id);
    return ((PFN_glIsQuery)__blue_glCore_glIsQuery)(id);
}

extern void* __blue_glCore_glBeginQuery;
void APIENTRY bluegl_glBeginQuery (GLenum target, GLuint id) {
    typedef void (APIENTRYP PFN_glBeginQuery) (GLenum target, GLuint id);
    return ((PFN_glBeginQuery)__blue_glCore_glBeginQuery)(target, id);
}

extern void* __blue_glCore_glEndQuery;
void APIENTRY bluegl_glEndQuery (GLenum target) {
    typedef void (APIENTRYP PFN_glEndQuery) (GLenum target);
    return ((PFN_glEndQuery)__blue_glCore_glEndQuery)(target);
}

extern void* __blue_glCore_glGetQueryiv;
void APIENTRY bluegl_glGetQueryiv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetQueryiv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetQueryiv)__blue_glCore_glGetQueryiv)(target, pname, params);
}

extern void* __blue_glCore_glGetQueryObjectiv;
void APIENTRY bluegl_glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetQueryObjectiv) (GLuint id, GLenum pname, GLint *params);
    return ((PFN_glGetQueryObjectiv)__blue_glCore_glGetQueryObjectiv)(id, pname, params);
}

extern void* __blue_glCore_glGetQueryObjectuiv;
void APIENTRY bluegl_glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetQueryObjectuiv) (GLuint id, GLenum pname, GLuint *params);
    return ((PFN_glGetQueryObjectuiv)__blue_glCore_glGetQueryObjectuiv)(id, pname, params);
}

extern void* __blue_glCore_glBindBuffer;
void APIENTRY bluegl_glBindBuffer (GLenum target, GLuint buffer) {
    typedef void (APIENTRYP PFN_glBindBuffer) (GLenum target, GLuint buffer);
    return ((PFN_glBindBuffer)__blue_glCore_glBindBuffer)(target, buffer);
}

extern void* __blue_glCore_glDeleteBuffers;
void APIENTRY bluegl_glDeleteBuffers (GLsizei n, const GLuint *buffers) {
    typedef void (APIENTRYP PFN_glDeleteBuffers) (GLsizei n, const GLuint *buffers);
    return ((PFN_glDeleteBuffers)__blue_glCore_glDeleteBuffers)(n, buffers);
}

extern void* __blue_glCore_glGenBuffers;
void APIENTRY bluegl_glGenBuffers (GLsizei n, GLuint *buffers) {
    typedef void (APIENTRYP PFN_glGenBuffers) (GLsizei n, GLuint *buffers);
    return ((PFN_glGenBuffers)__blue_glCore_glGenBuffers)(n, buffers);
}

extern void* __blue_glCore_glIsBuffer;
GLboolean APIENTRY bluegl_glIsBuffer (GLuint buffer) {
    typedef GLboolean (APIENTRYP PFN_glIsBuffer) (GLuint buffer);
    return ((PFN_glIsBuffer)__blue_glCore_glIsBuffer)(buffer);
}

extern void* __blue_glCore_glBufferData;
void APIENTRY bluegl_glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage) {
    typedef void (APIENTRYP PFN_glBufferData) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
    return ((PFN_glBufferData)__blue_glCore_glBufferData)(target, size, data, usage);
}

extern void* __blue_glCore_glBufferSubData;
void APIENTRY bluegl_glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data) {
    typedef void (APIENTRYP PFN_glBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
    return ((PFN_glBufferSubData)__blue_glCore_glBufferSubData)(target, offset, size, data);
}

extern void* __blue_glCore_glGetBufferSubData;
void APIENTRY bluegl_glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, void *data) {
    typedef void (APIENTRYP PFN_glGetBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
    return ((PFN_glGetBufferSubData)__blue_glCore_glGetBufferSubData)(target, offset, size, data);
}

extern void* __blue_glCore_glMapBuffer;
void *APIENTRY bluegl_glMapBuffer (GLenum target, GLenum access) {
    typedef void *(APIENTRYP PFN_glMapBuffer) (GLenum target, GLenum access);
    return ((PFN_glMapBuffer)__blue_glCore_glMapBuffer)(target, access);
}

extern void* __blue_glCore_glUnmapBuffer;
GLboolean APIENTRY bluegl_glUnmapBuffer (GLenum target) {
    typedef GLboolean (APIENTRYP PFN_glUnmapBuffer) (GLenum target);
    return ((PFN_glUnmapBuffer)__blue_glCore_glUnmapBuffer)(target);
}

extern void* __blue_glCore_glGetBufferParameteriv;
void APIENTRY bluegl_glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetBufferParameteriv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetBufferParameteriv)__blue_glCore_glGetBufferParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glGetBufferPointerv;
void APIENTRY bluegl_glGetBufferPointerv (GLenum target, GLenum pname, void **params) {
    typedef void (APIENTRYP PFN_glGetBufferPointerv) (GLenum target, GLenum pname, void **params);
    return ((PFN_glGetBufferPointerv)__blue_glCore_glGetBufferPointerv)(target, pname, params);
}

extern void* __blue_glCore_glBlendEquationSeparate;
void APIENTRY bluegl_glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha) {
    typedef void (APIENTRYP PFN_glBlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha);
    return ((PFN_glBlendEquationSeparate)__blue_glCore_glBlendEquationSeparate)(modeRGB, modeAlpha);
}

extern void* __blue_glCore_glDrawBuffers;
void APIENTRY bluegl_glDrawBuffers (GLsizei n, const GLenum *bufs) {
    typedef void (APIENTRYP PFN_glDrawBuffers) (GLsizei n, const GLenum *bufs);
    return ((PFN_glDrawBuffers)__blue_glCore_glDrawBuffers)(n, bufs);
}

extern void* __blue_glCore_glStencilOpSeparate;
void APIENTRY bluegl_glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    typedef void (APIENTRYP PFN_glStencilOpSeparate) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
    return ((PFN_glStencilOpSeparate)__blue_glCore_glStencilOpSeparate)(face, sfail, dpfail, dppass);
}

extern void* __blue_glCore_glStencilFuncSeparate;
void APIENTRY bluegl_glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask) {
    typedef void (APIENTRYP PFN_glStencilFuncSeparate) (GLenum face, GLenum func, GLint ref, GLuint mask);
    return ((PFN_glStencilFuncSeparate)__blue_glCore_glStencilFuncSeparate)(face, func, ref, mask);
}

extern void* __blue_glCore_glStencilMaskSeparate;
void APIENTRY bluegl_glStencilMaskSeparate (GLenum face, GLuint mask) {
    typedef void (APIENTRYP PFN_glStencilMaskSeparate) (GLenum face, GLuint mask);
    return ((PFN_glStencilMaskSeparate)__blue_glCore_glStencilMaskSeparate)(face, mask);
}

extern void* __blue_glCore_glAttachShader;
void APIENTRY bluegl_glAttachShader (GLuint program, GLuint shader) {
    typedef void (APIENTRYP PFN_glAttachShader) (GLuint program, GLuint shader);
    return ((PFN_glAttachShader)__blue_glCore_glAttachShader)(program, shader);
}

extern void* __blue_glCore_glBindAttribLocation;
void APIENTRY bluegl_glBindAttribLocation (GLuint program, GLuint index, const GLchar *name) {
    typedef void (APIENTRYP PFN_glBindAttribLocation) (GLuint program, GLuint index, const GLchar *name);
    return ((PFN_glBindAttribLocation)__blue_glCore_glBindAttribLocation)(program, index, name);
}

extern void* __blue_glCore_glCompileShader;
void APIENTRY bluegl_glCompileShader (GLuint shader) {
    typedef void (APIENTRYP PFN_glCompileShader) (GLuint shader);
    return ((PFN_glCompileShader)__blue_glCore_glCompileShader)(shader);
}

extern void* __blue_glCore_glCreateProgram;
GLuint APIENTRY bluegl_glCreateProgram (void) {
    typedef GLuint (APIENTRYP PFN_glCreateProgram) (void);
    return ((PFN_glCreateProgram)__blue_glCore_glCreateProgram)();
}

extern void* __blue_glCore_glCreateShader;
GLuint APIENTRY bluegl_glCreateShader (GLenum type) {
    typedef GLuint (APIENTRYP PFN_glCreateShader) (GLenum type);
    return ((PFN_glCreateShader)__blue_glCore_glCreateShader)(type);
}

extern void* __blue_glCore_glDeleteProgram;
void APIENTRY bluegl_glDeleteProgram (GLuint program) {
    typedef void (APIENTRYP PFN_glDeleteProgram) (GLuint program);
    return ((PFN_glDeleteProgram)__blue_glCore_glDeleteProgram)(program);
}

extern void* __blue_glCore_glDeleteShader;
void APIENTRY bluegl_glDeleteShader (GLuint shader) {
    typedef void (APIENTRYP PFN_glDeleteShader) (GLuint shader);
    return ((PFN_glDeleteShader)__blue_glCore_glDeleteShader)(shader);
}

extern void* __blue_glCore_glDetachShader;
void APIENTRY bluegl_glDetachShader (GLuint program, GLuint shader) {
    typedef void (APIENTRYP PFN_glDetachShader) (GLuint program, GLuint shader);
    return ((PFN_glDetachShader)__blue_glCore_glDetachShader)(program, shader);
}

extern void* __blue_glCore_glDisableVertexAttribArray;
void APIENTRY bluegl_glDisableVertexAttribArray (GLuint index) {
    typedef void (APIENTRYP PFN_glDisableVertexAttribArray) (GLuint index);
    return ((PFN_glDisableVertexAttribArray)__blue_glCore_glDisableVertexAttribArray)(index);
}

extern void* __blue_glCore_glEnableVertexAttribArray;
void APIENTRY bluegl_glEnableVertexAttribArray (GLuint index) {
    typedef void (APIENTRYP PFN_glEnableVertexAttribArray) (GLuint index);
    return ((PFN_glEnableVertexAttribArray)__blue_glCore_glEnableVertexAttribArray)(index);
}

extern void* __blue_glCore_glGetActiveAttrib;
void APIENTRY bluegl_glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {
    typedef void (APIENTRYP PFN_glGetActiveAttrib) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
    return ((PFN_glGetActiveAttrib)__blue_glCore_glGetActiveAttrib)(program, index, bufSize, length, size, type, name);
}

extern void* __blue_glCore_glGetActiveUniform;
void APIENTRY bluegl_glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {
    typedef void (APIENTRYP PFN_glGetActiveUniform) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
    return ((PFN_glGetActiveUniform)__blue_glCore_glGetActiveUniform)(program, index, bufSize, length, size, type, name);
}

extern void* __blue_glCore_glGetAttachedShaders;
void APIENTRY bluegl_glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) {
    typedef void (APIENTRYP PFN_glGetAttachedShaders) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
    return ((PFN_glGetAttachedShaders)__blue_glCore_glGetAttachedShaders)(program, maxCount, count, shaders);
}

extern void* __blue_glCore_glGetAttribLocation;
GLint APIENTRY bluegl_glGetAttribLocation (GLuint program, const GLchar *name) {
    typedef GLint (APIENTRYP PFN_glGetAttribLocation) (GLuint program, const GLchar *name);
    return ((PFN_glGetAttribLocation)__blue_glCore_glGetAttribLocation)(program, name);
}

extern void* __blue_glCore_glGetProgramiv;
void APIENTRY bluegl_glGetProgramiv (GLuint program, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetProgramiv) (GLuint program, GLenum pname, GLint *params);
    return ((PFN_glGetProgramiv)__blue_glCore_glGetProgramiv)(program, pname, params);
}

extern void* __blue_glCore_glGetProgramInfoLog;
void APIENTRY bluegl_glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    typedef void (APIENTRYP PFN_glGetProgramInfoLog) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    return ((PFN_glGetProgramInfoLog)__blue_glCore_glGetProgramInfoLog)(program, bufSize, length, infoLog);
}

extern void* __blue_glCore_glGetShaderiv;
void APIENTRY bluegl_glGetShaderiv (GLuint shader, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetShaderiv) (GLuint shader, GLenum pname, GLint *params);
    return ((PFN_glGetShaderiv)__blue_glCore_glGetShaderiv)(shader, pname, params);
}

extern void* __blue_glCore_glGetShaderInfoLog;
void APIENTRY bluegl_glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    typedef void (APIENTRYP PFN_glGetShaderInfoLog) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    return ((PFN_glGetShaderInfoLog)__blue_glCore_glGetShaderInfoLog)(shader, bufSize, length, infoLog);
}

extern void* __blue_glCore_glGetShaderSource;
void APIENTRY bluegl_glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) {
    typedef void (APIENTRYP PFN_glGetShaderSource) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
    return ((PFN_glGetShaderSource)__blue_glCore_glGetShaderSource)(shader, bufSize, length, source);
}

extern void* __blue_glCore_glGetUniformLocation;
GLint APIENTRY bluegl_glGetUniformLocation (GLuint program, const GLchar *name) {
    typedef GLint (APIENTRYP PFN_glGetUniformLocation) (GLuint program, const GLchar *name);
    return ((PFN_glGetUniformLocation)__blue_glCore_glGetUniformLocation)(program, name);
}

extern void* __blue_glCore_glGetUniformfv;
void APIENTRY bluegl_glGetUniformfv (GLuint program, GLint location, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetUniformfv) (GLuint program, GLint location, GLfloat *params);
    return ((PFN_glGetUniformfv)__blue_glCore_glGetUniformfv)(program, location, params);
}

extern void* __blue_glCore_glGetUniformiv;
void APIENTRY bluegl_glGetUniformiv (GLuint program, GLint location, GLint *params) {
    typedef void (APIENTRYP PFN_glGetUniformiv) (GLuint program, GLint location, GLint *params);
    return ((PFN_glGetUniformiv)__blue_glCore_glGetUniformiv)(program, location, params);
}

extern void* __blue_glCore_glGetVertexAttribdv;
void APIENTRY bluegl_glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribdv) (GLuint index, GLenum pname, GLdouble *params);
    return ((PFN_glGetVertexAttribdv)__blue_glCore_glGetVertexAttribdv)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribfv;
void APIENTRY bluegl_glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribfv) (GLuint index, GLenum pname, GLfloat *params);
    return ((PFN_glGetVertexAttribfv)__blue_glCore_glGetVertexAttribfv)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribiv;
void APIENTRY bluegl_glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribiv) (GLuint index, GLenum pname, GLint *params);
    return ((PFN_glGetVertexAttribiv)__blue_glCore_glGetVertexAttribiv)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribPointerv;
void APIENTRY bluegl_glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer) {
    typedef void (APIENTRYP PFN_glGetVertexAttribPointerv) (GLuint index, GLenum pname, void **pointer);
    return ((PFN_glGetVertexAttribPointerv)__blue_glCore_glGetVertexAttribPointerv)(index, pname, pointer);
}

extern void* __blue_glCore_glIsProgram;
GLboolean APIENTRY bluegl_glIsProgram (GLuint program) {
    typedef GLboolean (APIENTRYP PFN_glIsProgram) (GLuint program);
    return ((PFN_glIsProgram)__blue_glCore_glIsProgram)(program);
}

extern void* __blue_glCore_glIsShader;
GLboolean APIENTRY bluegl_glIsShader (GLuint shader) {
    typedef GLboolean (APIENTRYP PFN_glIsShader) (GLuint shader);
    return ((PFN_glIsShader)__blue_glCore_glIsShader)(shader);
}

extern void* __blue_glCore_glLinkProgram;
void APIENTRY bluegl_glLinkProgram (GLuint program) {
    typedef void (APIENTRYP PFN_glLinkProgram) (GLuint program);
    return ((PFN_glLinkProgram)__blue_glCore_glLinkProgram)(program);
}

extern void* __blue_glCore_glShaderSource;
void APIENTRY bluegl_glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) {
    typedef void (APIENTRYP PFN_glShaderSource) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
    return ((PFN_glShaderSource)__blue_glCore_glShaderSource)(shader, count, string, length);
}

extern void* __blue_glCore_glUseProgram;
void APIENTRY bluegl_glUseProgram (GLuint program) {
    typedef void (APIENTRYP PFN_glUseProgram) (GLuint program);
    return ((PFN_glUseProgram)__blue_glCore_glUseProgram)(program);
}

extern void* __blue_glCore_glUniform1f;
void APIENTRY bluegl_glUniform1f (GLint location, GLfloat v0) {
    typedef void (APIENTRYP PFN_glUniform1f) (GLint location, GLfloat v0);
    return ((PFN_glUniform1f)__blue_glCore_glUniform1f)(location, v0);
}

extern void* __blue_glCore_glUniform2f;
void APIENTRY bluegl_glUniform2f (GLint location, GLfloat v0, GLfloat v1) {
    typedef void (APIENTRYP PFN_glUniform2f) (GLint location, GLfloat v0, GLfloat v1);
    return ((PFN_glUniform2f)__blue_glCore_glUniform2f)(location, v0, v1);
}

extern void* __blue_glCore_glUniform3f;
void APIENTRY bluegl_glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    typedef void (APIENTRYP PFN_glUniform3f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    return ((PFN_glUniform3f)__blue_glCore_glUniform3f)(location, v0, v1, v2);
}

extern void* __blue_glCore_glUniform4f;
void APIENTRY bluegl_glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    typedef void (APIENTRYP PFN_glUniform4f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    return ((PFN_glUniform4f)__blue_glCore_glUniform4f)(location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glUniform1i;
void APIENTRY bluegl_glUniform1i (GLint location, GLint v0) {
    typedef void (APIENTRYP PFN_glUniform1i) (GLint location, GLint v0);
    return ((PFN_glUniform1i)__blue_glCore_glUniform1i)(location, v0);
}

extern void* __blue_glCore_glUniform2i;
void APIENTRY bluegl_glUniform2i (GLint location, GLint v0, GLint v1) {
    typedef void (APIENTRYP PFN_glUniform2i) (GLint location, GLint v0, GLint v1);
    return ((PFN_glUniform2i)__blue_glCore_glUniform2i)(location, v0, v1);
}

extern void* __blue_glCore_glUniform3i;
void APIENTRY bluegl_glUniform3i (GLint location, GLint v0, GLint v1, GLint v2) {
    typedef void (APIENTRYP PFN_glUniform3i) (GLint location, GLint v0, GLint v1, GLint v2);
    return ((PFN_glUniform3i)__blue_glCore_glUniform3i)(location, v0, v1, v2);
}

extern void* __blue_glCore_glUniform4i;
void APIENTRY bluegl_glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    typedef void (APIENTRYP PFN_glUniform4i) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    return ((PFN_glUniform4i)__blue_glCore_glUniform4i)(location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glUniform1fv;
void APIENTRY bluegl_glUniform1fv (GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniform1fv) (GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glUniform1fv)__blue_glCore_glUniform1fv)(location, count, value);
}

extern void* __blue_glCore_glUniform2fv;
void APIENTRY bluegl_glUniform2fv (GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniform2fv) (GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glUniform2fv)__blue_glCore_glUniform2fv)(location, count, value);
}

extern void* __blue_glCore_glUniform3fv;
void APIENTRY bluegl_glUniform3fv (GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniform3fv) (GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glUniform3fv)__blue_glCore_glUniform3fv)(location, count, value);
}

extern void* __blue_glCore_glUniform4fv;
void APIENTRY bluegl_glUniform4fv (GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniform4fv) (GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glUniform4fv)__blue_glCore_glUniform4fv)(location, count, value);
}

extern void* __blue_glCore_glUniform1iv;
void APIENTRY bluegl_glUniform1iv (GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glUniform1iv) (GLint location, GLsizei count, const GLint *value);
    return ((PFN_glUniform1iv)__blue_glCore_glUniform1iv)(location, count, value);
}

extern void* __blue_glCore_glUniform2iv;
void APIENTRY bluegl_glUniform2iv (GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glUniform2iv) (GLint location, GLsizei count, const GLint *value);
    return ((PFN_glUniform2iv)__blue_glCore_glUniform2iv)(location, count, value);
}

extern void* __blue_glCore_glUniform3iv;
void APIENTRY bluegl_glUniform3iv (GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glUniform3iv) (GLint location, GLsizei count, const GLint *value);
    return ((PFN_glUniform3iv)__blue_glCore_glUniform3iv)(location, count, value);
}

extern void* __blue_glCore_glUniform4iv;
void APIENTRY bluegl_glUniform4iv (GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glUniform4iv) (GLint location, GLsizei count, const GLint *value);
    return ((PFN_glUniform4iv)__blue_glCore_glUniform4iv)(location, count, value);
}

extern void* __blue_glCore_glUniformMatrix2fv;
void APIENTRY bluegl_glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix2fv)__blue_glCore_glUniformMatrix2fv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix3fv;
void APIENTRY bluegl_glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix3fv)__blue_glCore_glUniformMatrix3fv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix4fv;
void APIENTRY bluegl_glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix4fv)__blue_glCore_glUniformMatrix4fv)(location, count, transpose, value);
}

extern void* __blue_glCore_glValidateProgram;
void APIENTRY bluegl_glValidateProgram (GLuint program) {
    typedef void (APIENTRYP PFN_glValidateProgram) (GLuint program);
    return ((PFN_glValidateProgram)__blue_glCore_glValidateProgram)(program);
}

extern void* __blue_glCore_glVertexAttrib1d;
void APIENTRY bluegl_glVertexAttrib1d (GLuint index, GLdouble x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1d) (GLuint index, GLdouble x);
    return ((PFN_glVertexAttrib1d)__blue_glCore_glVertexAttrib1d)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1dv;
void APIENTRY bluegl_glVertexAttrib1dv (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1dv) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib1dv)__blue_glCore_glVertexAttrib1dv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib1f;
void APIENTRY bluegl_glVertexAttrib1f (GLuint index, GLfloat x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1f) (GLuint index, GLfloat x);
    return ((PFN_glVertexAttrib1f)__blue_glCore_glVertexAttrib1f)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1fv;
void APIENTRY bluegl_glVertexAttrib1fv (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1fv) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib1fv)__blue_glCore_glVertexAttrib1fv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib1s;
void APIENTRY bluegl_glVertexAttrib1s (GLuint index, GLshort x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1s) (GLuint index, GLshort x);
    return ((PFN_glVertexAttrib1s)__blue_glCore_glVertexAttrib1s)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1sv;
void APIENTRY bluegl_glVertexAttrib1sv (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1sv) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib1sv)__blue_glCore_glVertexAttrib1sv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2d;
void APIENTRY bluegl_glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2d) (GLuint index, GLdouble x, GLdouble y);
    return ((PFN_glVertexAttrib2d)__blue_glCore_glVertexAttrib2d)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2dv;
void APIENTRY bluegl_glVertexAttrib2dv (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2dv) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib2dv)__blue_glCore_glVertexAttrib2dv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2f;
void APIENTRY bluegl_glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2f) (GLuint index, GLfloat x, GLfloat y);
    return ((PFN_glVertexAttrib2f)__blue_glCore_glVertexAttrib2f)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2fv;
void APIENTRY bluegl_glVertexAttrib2fv (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2fv) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib2fv)__blue_glCore_glVertexAttrib2fv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2s;
void APIENTRY bluegl_glVertexAttrib2s (GLuint index, GLshort x, GLshort y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2s) (GLuint index, GLshort x, GLshort y);
    return ((PFN_glVertexAttrib2s)__blue_glCore_glVertexAttrib2s)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2sv;
void APIENTRY bluegl_glVertexAttrib2sv (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2sv) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib2sv)__blue_glCore_glVertexAttrib2sv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3d;
void APIENTRY bluegl_glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glVertexAttrib3d)__blue_glCore_glVertexAttrib3d)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3dv;
void APIENTRY bluegl_glVertexAttrib3dv (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3dv) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib3dv)__blue_glCore_glVertexAttrib3dv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3f;
void APIENTRY bluegl_glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3f) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glVertexAttrib3f)__blue_glCore_glVertexAttrib3f)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3fv;
void APIENTRY bluegl_glVertexAttrib3fv (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3fv) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib3fv)__blue_glCore_glVertexAttrib3fv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3s;
void APIENTRY bluegl_glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3s) (GLuint index, GLshort x, GLshort y, GLshort z);
    return ((PFN_glVertexAttrib3s)__blue_glCore_glVertexAttrib3s)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3sv;
void APIENTRY bluegl_glVertexAttrib3sv (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3sv) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib3sv)__blue_glCore_glVertexAttrib3sv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4Nbv;
void APIENTRY bluegl_glVertexAttrib4Nbv (GLuint index, const GLbyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4Nbv) (GLuint index, const GLbyte *v);
    return ((PFN_glVertexAttrib4Nbv)__blue_glCore_glVertexAttrib4Nbv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4Niv;
void APIENTRY bluegl_glVertexAttrib4Niv (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4Niv) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttrib4Niv)__blue_glCore_glVertexAttrib4Niv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4Nsv;
void APIENTRY bluegl_glVertexAttrib4Nsv (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4Nsv) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib4Nsv)__blue_glCore_glVertexAttrib4Nsv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4Nub;
void APIENTRY bluegl_glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4Nub) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    return ((PFN_glVertexAttrib4Nub)__blue_glCore_glVertexAttrib4Nub)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4Nubv;
void APIENTRY bluegl_glVertexAttrib4Nubv (GLuint index, const GLubyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4Nubv) (GLuint index, const GLubyte *v);
    return ((PFN_glVertexAttrib4Nubv)__blue_glCore_glVertexAttrib4Nubv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4Nuiv;
void APIENTRY bluegl_glVertexAttrib4Nuiv (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4Nuiv) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttrib4Nuiv)__blue_glCore_glVertexAttrib4Nuiv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4Nusv;
void APIENTRY bluegl_glVertexAttrib4Nusv (GLuint index, const GLushort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4Nusv) (GLuint index, const GLushort *v);
    return ((PFN_glVertexAttrib4Nusv)__blue_glCore_glVertexAttrib4Nusv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4bv;
void APIENTRY bluegl_glVertexAttrib4bv (GLuint index, const GLbyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4bv) (GLuint index, const GLbyte *v);
    return ((PFN_glVertexAttrib4bv)__blue_glCore_glVertexAttrib4bv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4d;
void APIENTRY bluegl_glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glVertexAttrib4d)__blue_glCore_glVertexAttrib4d)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4dv;
void APIENTRY bluegl_glVertexAttrib4dv (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4dv) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib4dv)__blue_glCore_glVertexAttrib4dv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4f;
void APIENTRY bluegl_glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4f) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glVertexAttrib4f)__blue_glCore_glVertexAttrib4f)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4fv;
void APIENTRY bluegl_glVertexAttrib4fv (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4fv) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib4fv)__blue_glCore_glVertexAttrib4fv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4iv;
void APIENTRY bluegl_glVertexAttrib4iv (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4iv) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttrib4iv)__blue_glCore_glVertexAttrib4iv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4s;
void APIENTRY bluegl_glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4s) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
    return ((PFN_glVertexAttrib4s)__blue_glCore_glVertexAttrib4s)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4sv;
void APIENTRY bluegl_glVertexAttrib4sv (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4sv) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib4sv)__blue_glCore_glVertexAttrib4sv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4ubv;
void APIENTRY bluegl_glVertexAttrib4ubv (GLuint index, const GLubyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4ubv) (GLuint index, const GLubyte *v);
    return ((PFN_glVertexAttrib4ubv)__blue_glCore_glVertexAttrib4ubv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4uiv;
void APIENTRY bluegl_glVertexAttrib4uiv (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4uiv) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttrib4uiv)__blue_glCore_glVertexAttrib4uiv)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4usv;
void APIENTRY bluegl_glVertexAttrib4usv (GLuint index, const GLushort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4usv) (GLuint index, const GLushort *v);
    return ((PFN_glVertexAttrib4usv)__blue_glCore_glVertexAttrib4usv)(index, v);
}

extern void* __blue_glCore_glVertexAttribPointer;
void APIENTRY bluegl_glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
    return ((PFN_glVertexAttribPointer)__blue_glCore_glVertexAttribPointer)(index, size, type, normalized, stride, pointer);
}

extern void* __blue_glCore_glUniformMatrix2x3fv;
void APIENTRY bluegl_glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix2x3fv)__blue_glCore_glUniformMatrix2x3fv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix3x2fv;
void APIENTRY bluegl_glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix3x2fv)__blue_glCore_glUniformMatrix3x2fv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix2x4fv;
void APIENTRY bluegl_glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix2x4fv)__blue_glCore_glUniformMatrix2x4fv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix4x2fv;
void APIENTRY bluegl_glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix4x2fv)__blue_glCore_glUniformMatrix4x2fv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix3x4fv;
void APIENTRY bluegl_glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix3x4fv)__blue_glCore_glUniformMatrix3x4fv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix4x3fv;
void APIENTRY bluegl_glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix4x3fv)__blue_glCore_glUniformMatrix4x3fv)(location, count, transpose, value);
}

extern void* __blue_glCore_glColorMaski;
void APIENTRY bluegl_glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
    typedef void (APIENTRYP PFN_glColorMaski) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
    return ((PFN_glColorMaski)__blue_glCore_glColorMaski)(index, r, g, b, a);
}

extern void* __blue_glCore_glGetBooleani_v;
void APIENTRY bluegl_glGetBooleani_v (GLenum target, GLuint index, GLboolean *data) {
    typedef void (APIENTRYP PFN_glGetBooleani_v) (GLenum target, GLuint index, GLboolean *data);
    return ((PFN_glGetBooleani_v)__blue_glCore_glGetBooleani_v)(target, index, data);
}

extern void* __blue_glCore_glGetIntegeri_v;
void APIENTRY bluegl_glGetIntegeri_v (GLenum target, GLuint index, GLint *data) {
    typedef void (APIENTRYP PFN_glGetIntegeri_v) (GLenum target, GLuint index, GLint *data);
    return ((PFN_glGetIntegeri_v)__blue_glCore_glGetIntegeri_v)(target, index, data);
}

extern void* __blue_glCore_glEnablei;
void APIENTRY bluegl_glEnablei (GLenum target, GLuint index) {
    typedef void (APIENTRYP PFN_glEnablei) (GLenum target, GLuint index);
    return ((PFN_glEnablei)__blue_glCore_glEnablei)(target, index);
}

extern void* __blue_glCore_glDisablei;
void APIENTRY bluegl_glDisablei (GLenum target, GLuint index) {
    typedef void (APIENTRYP PFN_glDisablei) (GLenum target, GLuint index);
    return ((PFN_glDisablei)__blue_glCore_glDisablei)(target, index);
}

extern void* __blue_glCore_glIsEnabledi;
GLboolean APIENTRY bluegl_glIsEnabledi (GLenum target, GLuint index) {
    typedef GLboolean (APIENTRYP PFN_glIsEnabledi) (GLenum target, GLuint index);
    return ((PFN_glIsEnabledi)__blue_glCore_glIsEnabledi)(target, index);
}

extern void* __blue_glCore_glBeginTransformFeedback;
void APIENTRY bluegl_glBeginTransformFeedback (GLenum primitiveMode) {
    typedef void (APIENTRYP PFN_glBeginTransformFeedback) (GLenum primitiveMode);
    return ((PFN_glBeginTransformFeedback)__blue_glCore_glBeginTransformFeedback)(primitiveMode);
}

extern void* __blue_glCore_glEndTransformFeedback;
void APIENTRY bluegl_glEndTransformFeedback (void) {
    typedef void (APIENTRYP PFN_glEndTransformFeedback) (void);
    return ((PFN_glEndTransformFeedback)__blue_glCore_glEndTransformFeedback)();
}

extern void* __blue_glCore_glBindBufferRange;
void APIENTRY bluegl_glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glBindBufferRange) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    return ((PFN_glBindBufferRange)__blue_glCore_glBindBufferRange)(target, index, buffer, offset, size);
}

extern void* __blue_glCore_glBindBufferBase;
void APIENTRY bluegl_glBindBufferBase (GLenum target, GLuint index, GLuint buffer) {
    typedef void (APIENTRYP PFN_glBindBufferBase) (GLenum target, GLuint index, GLuint buffer);
    return ((PFN_glBindBufferBase)__blue_glCore_glBindBufferBase)(target, index, buffer);
}

extern void* __blue_glCore_glTransformFeedbackVaryings;
void APIENTRY bluegl_glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) {
    typedef void (APIENTRYP PFN_glTransformFeedbackVaryings) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
    return ((PFN_glTransformFeedbackVaryings)__blue_glCore_glTransformFeedbackVaryings)(program, count, varyings, bufferMode);
}

extern void* __blue_glCore_glGetTransformFeedbackVarying;
void APIENTRY bluegl_glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) {
    typedef void (APIENTRYP PFN_glGetTransformFeedbackVarying) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
    return ((PFN_glGetTransformFeedbackVarying)__blue_glCore_glGetTransformFeedbackVarying)(program, index, bufSize, length, size, type, name);
}

extern void* __blue_glCore_glClampColor;
void APIENTRY bluegl_glClampColor (GLenum target, GLenum clamp) {
    typedef void (APIENTRYP PFN_glClampColor) (GLenum target, GLenum clamp);
    return ((PFN_glClampColor)__blue_glCore_glClampColor)(target, clamp);
}

extern void* __blue_glCore_glBeginConditionalRender;
void APIENTRY bluegl_glBeginConditionalRender (GLuint id, GLenum mode) {
    typedef void (APIENTRYP PFN_glBeginConditionalRender) (GLuint id, GLenum mode);
    return ((PFN_glBeginConditionalRender)__blue_glCore_glBeginConditionalRender)(id, mode);
}

extern void* __blue_glCore_glEndConditionalRender;
void APIENTRY bluegl_glEndConditionalRender (void) {
    typedef void (APIENTRYP PFN_glEndConditionalRender) (void);
    return ((PFN_glEndConditionalRender)__blue_glCore_glEndConditionalRender)();
}

extern void* __blue_glCore_glVertexAttribIPointer;
void APIENTRY bluegl_glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexAttribIPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glVertexAttribIPointer)__blue_glCore_glVertexAttribIPointer)(index, size, type, stride, pointer);
}

extern void* __blue_glCore_glGetVertexAttribIiv;
void APIENTRY bluegl_glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribIiv) (GLuint index, GLenum pname, GLint *params);
    return ((PFN_glGetVertexAttribIiv)__blue_glCore_glGetVertexAttribIiv)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribIuiv;
void APIENTRY bluegl_glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribIuiv) (GLuint index, GLenum pname, GLuint *params);
    return ((PFN_glGetVertexAttribIuiv)__blue_glCore_glGetVertexAttribIuiv)(index, pname, params);
}

extern void* __blue_glCore_glVertexAttribI1i;
void APIENTRY bluegl_glVertexAttribI1i (GLuint index, GLint x) {
    typedef void (APIENTRYP PFN_glVertexAttribI1i) (GLuint index, GLint x);
    return ((PFN_glVertexAttribI1i)__blue_glCore_glVertexAttribI1i)(index, x);
}

extern void* __blue_glCore_glVertexAttribI2i;
void APIENTRY bluegl_glVertexAttribI2i (GLuint index, GLint x, GLint y) {
    typedef void (APIENTRYP PFN_glVertexAttribI2i) (GLuint index, GLint x, GLint y);
    return ((PFN_glVertexAttribI2i)__blue_glCore_glVertexAttribI2i)(index, x, y);
}

extern void* __blue_glCore_glVertexAttribI3i;
void APIENTRY bluegl_glVertexAttribI3i (GLuint index, GLint x, GLint y, GLint z) {
    typedef void (APIENTRYP PFN_glVertexAttribI3i) (GLuint index, GLint x, GLint y, GLint z);
    return ((PFN_glVertexAttribI3i)__blue_glCore_glVertexAttribI3i)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttribI4i;
void APIENTRY bluegl_glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w) {
    typedef void (APIENTRYP PFN_glVertexAttribI4i) (GLuint index, GLint x, GLint y, GLint z, GLint w);
    return ((PFN_glVertexAttribI4i)__blue_glCore_glVertexAttribI4i)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttribI1ui;
void APIENTRY bluegl_glVertexAttribI1ui (GLuint index, GLuint x) {
    typedef void (APIENTRYP PFN_glVertexAttribI1ui) (GLuint index, GLuint x);
    return ((PFN_glVertexAttribI1ui)__blue_glCore_glVertexAttribI1ui)(index, x);
}

extern void* __blue_glCore_glVertexAttribI2ui;
void APIENTRY bluegl_glVertexAttribI2ui (GLuint index, GLuint x, GLuint y) {
    typedef void (APIENTRYP PFN_glVertexAttribI2ui) (GLuint index, GLuint x, GLuint y);
    return ((PFN_glVertexAttribI2ui)__blue_glCore_glVertexAttribI2ui)(index, x, y);
}

extern void* __blue_glCore_glVertexAttribI3ui;
void APIENTRY bluegl_glVertexAttribI3ui (GLuint index, GLuint x, GLuint y, GLuint z) {
    typedef void (APIENTRYP PFN_glVertexAttribI3ui) (GLuint index, GLuint x, GLuint y, GLuint z);
    return ((PFN_glVertexAttribI3ui)__blue_glCore_glVertexAttribI3ui)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttribI4ui;
void APIENTRY bluegl_glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    typedef void (APIENTRYP PFN_glVertexAttribI4ui) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    return ((PFN_glVertexAttribI4ui)__blue_glCore_glVertexAttribI4ui)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttribI1iv;
void APIENTRY bluegl_glVertexAttribI1iv (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI1iv) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttribI1iv)__blue_glCore_glVertexAttribI1iv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI2iv;
void APIENTRY bluegl_glVertexAttribI2iv (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI2iv) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttribI2iv)__blue_glCore_glVertexAttribI2iv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI3iv;
void APIENTRY bluegl_glVertexAttribI3iv (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI3iv) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttribI3iv)__blue_glCore_glVertexAttribI3iv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4iv;
void APIENTRY bluegl_glVertexAttribI4iv (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4iv) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttribI4iv)__blue_glCore_glVertexAttribI4iv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI1uiv;
void APIENTRY bluegl_glVertexAttribI1uiv (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI1uiv) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttribI1uiv)__blue_glCore_glVertexAttribI1uiv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI2uiv;
void APIENTRY bluegl_glVertexAttribI2uiv (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI2uiv) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttribI2uiv)__blue_glCore_glVertexAttribI2uiv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI3uiv;
void APIENTRY bluegl_glVertexAttribI3uiv (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI3uiv) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttribI3uiv)__blue_glCore_glVertexAttribI3uiv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4uiv;
void APIENTRY bluegl_glVertexAttribI4uiv (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4uiv) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttribI4uiv)__blue_glCore_glVertexAttribI4uiv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4bv;
void APIENTRY bluegl_glVertexAttribI4bv (GLuint index, const GLbyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4bv) (GLuint index, const GLbyte *v);
    return ((PFN_glVertexAttribI4bv)__blue_glCore_glVertexAttribI4bv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4sv;
void APIENTRY bluegl_glVertexAttribI4sv (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4sv) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttribI4sv)__blue_glCore_glVertexAttribI4sv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4ubv;
void APIENTRY bluegl_glVertexAttribI4ubv (GLuint index, const GLubyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4ubv) (GLuint index, const GLubyte *v);
    return ((PFN_glVertexAttribI4ubv)__blue_glCore_glVertexAttribI4ubv)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4usv;
void APIENTRY bluegl_glVertexAttribI4usv (GLuint index, const GLushort *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4usv) (GLuint index, const GLushort *v);
    return ((PFN_glVertexAttribI4usv)__blue_glCore_glVertexAttribI4usv)(index, v);
}

extern void* __blue_glCore_glGetUniformuiv;
void APIENTRY bluegl_glGetUniformuiv (GLuint program, GLint location, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetUniformuiv) (GLuint program, GLint location, GLuint *params);
    return ((PFN_glGetUniformuiv)__blue_glCore_glGetUniformuiv)(program, location, params);
}

extern void* __blue_glCore_glBindFragDataLocation;
void APIENTRY bluegl_glBindFragDataLocation (GLuint program, GLuint color, const GLchar *name) {
    typedef void (APIENTRYP PFN_glBindFragDataLocation) (GLuint program, GLuint color, const GLchar *name);
    return ((PFN_glBindFragDataLocation)__blue_glCore_glBindFragDataLocation)(program, color, name);
}

extern void* __blue_glCore_glGetFragDataLocation;
GLint APIENTRY bluegl_glGetFragDataLocation (GLuint program, const GLchar *name) {
    typedef GLint (APIENTRYP PFN_glGetFragDataLocation) (GLuint program, const GLchar *name);
    return ((PFN_glGetFragDataLocation)__blue_glCore_glGetFragDataLocation)(program, name);
}

extern void* __blue_glCore_glUniform1ui;
void APIENTRY bluegl_glUniform1ui (GLint location, GLuint v0) {
    typedef void (APIENTRYP PFN_glUniform1ui) (GLint location, GLuint v0);
    return ((PFN_glUniform1ui)__blue_glCore_glUniform1ui)(location, v0);
}

extern void* __blue_glCore_glUniform2ui;
void APIENTRY bluegl_glUniform2ui (GLint location, GLuint v0, GLuint v1) {
    typedef void (APIENTRYP PFN_glUniform2ui) (GLint location, GLuint v0, GLuint v1);
    return ((PFN_glUniform2ui)__blue_glCore_glUniform2ui)(location, v0, v1);
}

extern void* __blue_glCore_glUniform3ui;
void APIENTRY bluegl_glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2) {
    typedef void (APIENTRYP PFN_glUniform3ui) (GLint location, GLuint v0, GLuint v1, GLuint v2);
    return ((PFN_glUniform3ui)__blue_glCore_glUniform3ui)(location, v0, v1, v2);
}

extern void* __blue_glCore_glUniform4ui;
void APIENTRY bluegl_glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    typedef void (APIENTRYP PFN_glUniform4ui) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    return ((PFN_glUniform4ui)__blue_glCore_glUniform4ui)(location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glUniform1uiv;
void APIENTRY bluegl_glUniform1uiv (GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glUniform1uiv) (GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glUniform1uiv)__blue_glCore_glUniform1uiv)(location, count, value);
}

extern void* __blue_glCore_glUniform2uiv;
void APIENTRY bluegl_glUniform2uiv (GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glUniform2uiv) (GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glUniform2uiv)__blue_glCore_glUniform2uiv)(location, count, value);
}

extern void* __blue_glCore_glUniform3uiv;
void APIENTRY bluegl_glUniform3uiv (GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glUniform3uiv) (GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glUniform3uiv)__blue_glCore_glUniform3uiv)(location, count, value);
}

extern void* __blue_glCore_glUniform4uiv;
void APIENTRY bluegl_glUniform4uiv (GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glUniform4uiv) (GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glUniform4uiv)__blue_glCore_glUniform4uiv)(location, count, value);
}

extern void* __blue_glCore_glTexParameterIiv;
void APIENTRY bluegl_glTexParameterIiv (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glTexParameterIiv) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glTexParameterIiv)__blue_glCore_glTexParameterIiv)(target, pname, params);
}

extern void* __blue_glCore_glTexParameterIuiv;
void APIENTRY bluegl_glTexParameterIuiv (GLenum target, GLenum pname, const GLuint *params) {
    typedef void (APIENTRYP PFN_glTexParameterIuiv) (GLenum target, GLenum pname, const GLuint *params);
    return ((PFN_glTexParameterIuiv)__blue_glCore_glTexParameterIuiv)(target, pname, params);
}

extern void* __blue_glCore_glGetTexParameterIiv;
void APIENTRY bluegl_glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTexParameterIiv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetTexParameterIiv)__blue_glCore_glGetTexParameterIiv)(target, pname, params);
}

extern void* __blue_glCore_glGetTexParameterIuiv;
void APIENTRY bluegl_glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetTexParameterIuiv) (GLenum target, GLenum pname, GLuint *params);
    return ((PFN_glGetTexParameterIuiv)__blue_glCore_glGetTexParameterIuiv)(target, pname, params);
}

extern void* __blue_glCore_glClearBufferiv;
void APIENTRY bluegl_glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value) {
    typedef void (APIENTRYP PFN_glClearBufferiv) (GLenum buffer, GLint drawbuffer, const GLint *value);
    return ((PFN_glClearBufferiv)__blue_glCore_glClearBufferiv)(buffer, drawbuffer, value);
}

extern void* __blue_glCore_glClearBufferuiv;
void APIENTRY bluegl_glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value) {
    typedef void (APIENTRYP PFN_glClearBufferuiv) (GLenum buffer, GLint drawbuffer, const GLuint *value);
    return ((PFN_glClearBufferuiv)__blue_glCore_glClearBufferuiv)(buffer, drawbuffer, value);
}

extern void* __blue_glCore_glClearBufferfv;
void APIENTRY bluegl_glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glClearBufferfv) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
    return ((PFN_glClearBufferfv)__blue_glCore_glClearBufferfv)(buffer, drawbuffer, value);
}

extern void* __blue_glCore_glClearBufferfi;
void APIENTRY bluegl_glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
    typedef void (APIENTRYP PFN_glClearBufferfi) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
    return ((PFN_glClearBufferfi)__blue_glCore_glClearBufferfi)(buffer, drawbuffer, depth, stencil);
}

extern void* __blue_glCore_glGetStringi;
const GLubyte *APIENTRY bluegl_glGetStringi (GLenum name, GLuint index) {
    typedef const GLubyte *(APIENTRYP PFN_glGetStringi) (GLenum name, GLuint index);
    return ((PFN_glGetStringi)__blue_glCore_glGetStringi)(name, index);
}

extern void* __blue_glCore_glIsRenderbuffer;
GLboolean APIENTRY bluegl_glIsRenderbuffer (GLuint renderbuffer) {
    typedef GLboolean (APIENTRYP PFN_glIsRenderbuffer) (GLuint renderbuffer);
    return ((PFN_glIsRenderbuffer)__blue_glCore_glIsRenderbuffer)(renderbuffer);
}

extern void* __blue_glCore_glBindRenderbuffer;
void APIENTRY bluegl_glBindRenderbuffer (GLenum target, GLuint renderbuffer) {
    typedef void (APIENTRYP PFN_glBindRenderbuffer) (GLenum target, GLuint renderbuffer);
    return ((PFN_glBindRenderbuffer)__blue_glCore_glBindRenderbuffer)(target, renderbuffer);
}

extern void* __blue_glCore_glDeleteRenderbuffers;
void APIENTRY bluegl_glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers) {
    typedef void (APIENTRYP PFN_glDeleteRenderbuffers) (GLsizei n, const GLuint *renderbuffers);
    return ((PFN_glDeleteRenderbuffers)__blue_glCore_glDeleteRenderbuffers)(n, renderbuffers);
}

extern void* __blue_glCore_glGenRenderbuffers;
void APIENTRY bluegl_glGenRenderbuffers (GLsizei n, GLuint *renderbuffers) {
    typedef void (APIENTRYP PFN_glGenRenderbuffers) (GLsizei n, GLuint *renderbuffers);
    return ((PFN_glGenRenderbuffers)__blue_glCore_glGenRenderbuffers)(n, renderbuffers);
}

extern void* __blue_glCore_glRenderbufferStorage;
void APIENTRY bluegl_glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glRenderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glRenderbufferStorage)__blue_glCore_glRenderbufferStorage)(target, internalformat, width, height);
}

extern void* __blue_glCore_glGetRenderbufferParameteriv;
void APIENTRY bluegl_glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetRenderbufferParameteriv)__blue_glCore_glGetRenderbufferParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glIsFramebuffer;
GLboolean APIENTRY bluegl_glIsFramebuffer (GLuint framebuffer) {
    typedef GLboolean (APIENTRYP PFN_glIsFramebuffer) (GLuint framebuffer);
    return ((PFN_glIsFramebuffer)__blue_glCore_glIsFramebuffer)(framebuffer);
}

extern void* __blue_glCore_glBindFramebuffer;
void APIENTRY bluegl_glBindFramebuffer (GLenum target, GLuint framebuffer) {
    typedef void (APIENTRYP PFN_glBindFramebuffer) (GLenum target, GLuint framebuffer);
    return ((PFN_glBindFramebuffer)__blue_glCore_glBindFramebuffer)(target, framebuffer);
}

extern void* __blue_glCore_glDeleteFramebuffers;
void APIENTRY bluegl_glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers) {
    typedef void (APIENTRYP PFN_glDeleteFramebuffers) (GLsizei n, const GLuint *framebuffers);
    return ((PFN_glDeleteFramebuffers)__blue_glCore_glDeleteFramebuffers)(n, framebuffers);
}

extern void* __blue_glCore_glGenFramebuffers;
void APIENTRY bluegl_glGenFramebuffers (GLsizei n, GLuint *framebuffers) {
    typedef void (APIENTRYP PFN_glGenFramebuffers) (GLsizei n, GLuint *framebuffers);
    return ((PFN_glGenFramebuffers)__blue_glCore_glGenFramebuffers)(n, framebuffers);
}

extern void* __blue_glCore_glCheckFramebufferStatus;
GLenum APIENTRY bluegl_glCheckFramebufferStatus (GLenum target) {
    typedef GLenum (APIENTRYP PFN_glCheckFramebufferStatus) (GLenum target);
    return ((PFN_glCheckFramebufferStatus)__blue_glCore_glCheckFramebufferStatus)(target);
}

extern void* __blue_glCore_glFramebufferTexture1D;
void APIENTRY bluegl_glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glFramebufferTexture1D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    return ((PFN_glFramebufferTexture1D)__blue_glCore_glFramebufferTexture1D)(target, attachment, textarget, texture, level);
}

extern void* __blue_glCore_glFramebufferTexture2D;
void APIENTRY bluegl_glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glFramebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    return ((PFN_glFramebufferTexture2D)__blue_glCore_glFramebufferTexture2D)(target, attachment, textarget, texture, level);
}

extern void* __blue_glCore_glFramebufferTexture3D;
void APIENTRY bluegl_glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
    typedef void (APIENTRYP PFN_glFramebufferTexture3D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
    return ((PFN_glFramebufferTexture3D)__blue_glCore_glFramebufferTexture3D)(target, attachment, textarget, texture, level, zoffset);
}

extern void* __blue_glCore_glFramebufferRenderbuffer;
void APIENTRY bluegl_glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    typedef void (APIENTRYP PFN_glFramebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    return ((PFN_glFramebufferRenderbuffer)__blue_glCore_glFramebufferRenderbuffer)(target, attachment, renderbuffertarget, renderbuffer);
}

extern void* __blue_glCore_glGetFramebufferAttachmentParameteriv;
void APIENTRY bluegl_glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
    return ((PFN_glGetFramebufferAttachmentParameteriv)__blue_glCore_glGetFramebufferAttachmentParameteriv)(target, attachment, pname, params);
}

extern void* __blue_glCore_glGenerateMipmap;
void APIENTRY bluegl_glGenerateMipmap (GLenum target) {
    typedef void (APIENTRYP PFN_glGenerateMipmap) (GLenum target);
    return ((PFN_glGenerateMipmap)__blue_glCore_glGenerateMipmap)(target);
}

extern void* __blue_glCore_glBlitFramebuffer;
void APIENTRY bluegl_glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    typedef void (APIENTRYP PFN_glBlitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    return ((PFN_glBlitFramebuffer)__blue_glCore_glBlitFramebuffer)(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

extern void* __blue_glCore_glRenderbufferStorageMultisample;
void APIENTRY bluegl_glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glRenderbufferStorageMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glRenderbufferStorageMultisample)__blue_glCore_glRenderbufferStorageMultisample)(target, samples, internalformat, width, height);
}

extern void* __blue_glCore_glFramebufferTextureLayer;
void APIENTRY bluegl_glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    typedef void (APIENTRYP PFN_glFramebufferTextureLayer) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
    return ((PFN_glFramebufferTextureLayer)__blue_glCore_glFramebufferTextureLayer)(target, attachment, texture, level, layer);
}

extern void* __blue_glCore_glMapBufferRange;
void *APIENTRY bluegl_glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    typedef void *(APIENTRYP PFN_glMapBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
    return ((PFN_glMapBufferRange)__blue_glCore_glMapBufferRange)(target, offset, length, access);
}

extern void* __blue_glCore_glFlushMappedBufferRange;
void APIENTRY bluegl_glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length) {
    typedef void (APIENTRYP PFN_glFlushMappedBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length);
    return ((PFN_glFlushMappedBufferRange)__blue_glCore_glFlushMappedBufferRange)(target, offset, length);
}

extern void* __blue_glCore_glBindVertexArray;
void APIENTRY bluegl_glBindVertexArray (GLuint array) {
    typedef void (APIENTRYP PFN_glBindVertexArray) (GLuint array);
    return ((PFN_glBindVertexArray)__blue_glCore_glBindVertexArray)(array);
}

extern void* __blue_glCore_glDeleteVertexArrays;
void APIENTRY bluegl_glDeleteVertexArrays (GLsizei n, const GLuint *arrays) {
    typedef void (APIENTRYP PFN_glDeleteVertexArrays) (GLsizei n, const GLuint *arrays);
    return ((PFN_glDeleteVertexArrays)__blue_glCore_glDeleteVertexArrays)(n, arrays);
}

extern void* __blue_glCore_glGenVertexArrays;
void APIENTRY bluegl_glGenVertexArrays (GLsizei n, GLuint *arrays) {
    typedef void (APIENTRYP PFN_glGenVertexArrays) (GLsizei n, GLuint *arrays);
    return ((PFN_glGenVertexArrays)__blue_glCore_glGenVertexArrays)(n, arrays);
}

extern void* __blue_glCore_glIsVertexArray;
GLboolean APIENTRY bluegl_glIsVertexArray (GLuint array) {
    typedef GLboolean (APIENTRYP PFN_glIsVertexArray) (GLuint array);
    return ((PFN_glIsVertexArray)__blue_glCore_glIsVertexArray)(array);
}

extern void* __blue_glCore_glDrawArraysInstanced;
void APIENTRY bluegl_glDrawArraysInstanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
    typedef void (APIENTRYP PFN_glDrawArraysInstanced) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
    return ((PFN_glDrawArraysInstanced)__blue_glCore_glDrawArraysInstanced)(mode, first, count, instancecount);
}

extern void* __blue_glCore_glDrawElementsInstanced;
void APIENTRY bluegl_glDrawElementsInstanced (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) {
    typedef void (APIENTRYP PFN_glDrawElementsInstanced) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
    return ((PFN_glDrawElementsInstanced)__blue_glCore_glDrawElementsInstanced)(mode, count, type, indices, instancecount);
}

extern void* __blue_glCore_glTexBuffer;
void APIENTRY bluegl_glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer) {
    typedef void (APIENTRYP PFN_glTexBuffer) (GLenum target, GLenum internalformat, GLuint buffer);
    return ((PFN_glTexBuffer)__blue_glCore_glTexBuffer)(target, internalformat, buffer);
}

extern void* __blue_glCore_glPrimitiveRestartIndex;
void APIENTRY bluegl_glPrimitiveRestartIndex (GLuint index) {
    typedef void (APIENTRYP PFN_glPrimitiveRestartIndex) (GLuint index);
    return ((PFN_glPrimitiveRestartIndex)__blue_glCore_glPrimitiveRestartIndex)(index);
}

extern void* __blue_glCore_glCopyBufferSubData;
void APIENTRY bluegl_glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glCopyBufferSubData) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    return ((PFN_glCopyBufferSubData)__blue_glCore_glCopyBufferSubData)(readTarget, writeTarget, readOffset, writeOffset, size);
}

extern void* __blue_glCore_glGetUniformIndices;
void APIENTRY bluegl_glGetUniformIndices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) {
    typedef void (APIENTRYP PFN_glGetUniformIndices) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
    return ((PFN_glGetUniformIndices)__blue_glCore_glGetUniformIndices)(program, uniformCount, uniformNames, uniformIndices);
}

extern void* __blue_glCore_glGetActiveUniformsiv;
void APIENTRY bluegl_glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetActiveUniformsiv) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
    return ((PFN_glGetActiveUniformsiv)__blue_glCore_glGetActiveUniformsiv)(program, uniformCount, uniformIndices, pname, params);
}

extern void* __blue_glCore_glGetActiveUniformName;
void APIENTRY bluegl_glGetActiveUniformName (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) {
    typedef void (APIENTRYP PFN_glGetActiveUniformName) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
    return ((PFN_glGetActiveUniformName)__blue_glCore_glGetActiveUniformName)(program, uniformIndex, bufSize, length, uniformName);
}

extern void* __blue_glCore_glGetUniformBlockIndex;
GLuint APIENTRY bluegl_glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName) {
    typedef GLuint (APIENTRYP PFN_glGetUniformBlockIndex) (GLuint program, const GLchar *uniformBlockName);
    return ((PFN_glGetUniformBlockIndex)__blue_glCore_glGetUniformBlockIndex)(program, uniformBlockName);
}

extern void* __blue_glCore_glGetActiveUniformBlockiv;
void APIENTRY bluegl_glGetActiveUniformBlockiv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetActiveUniformBlockiv) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
    return ((PFN_glGetActiveUniformBlockiv)__blue_glCore_glGetActiveUniformBlockiv)(program, uniformBlockIndex, pname, params);
}

extern void* __blue_glCore_glGetActiveUniformBlockName;
void APIENTRY bluegl_glGetActiveUniformBlockName (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) {
    typedef void (APIENTRYP PFN_glGetActiveUniformBlockName) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
    return ((PFN_glGetActiveUniformBlockName)__blue_glCore_glGetActiveUniformBlockName)(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

extern void* __blue_glCore_glUniformBlockBinding;
void APIENTRY bluegl_glUniformBlockBinding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
    typedef void (APIENTRYP PFN_glUniformBlockBinding) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
    return ((PFN_glUniformBlockBinding)__blue_glCore_glUniformBlockBinding)(program, uniformBlockIndex, uniformBlockBinding);
}

extern void* __blue_glCore_glDrawElementsBaseVertex;
void APIENTRY bluegl_glDrawElementsBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) {
    typedef void (APIENTRYP PFN_glDrawElementsBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
    return ((PFN_glDrawElementsBaseVertex)__blue_glCore_glDrawElementsBaseVertex)(mode, count, type, indices, basevertex);
}

extern void* __blue_glCore_glDrawRangeElementsBaseVertex;
void APIENTRY bluegl_glDrawRangeElementsBaseVertex (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) {
    typedef void (APIENTRYP PFN_glDrawRangeElementsBaseVertex) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
    return ((PFN_glDrawRangeElementsBaseVertex)__blue_glCore_glDrawRangeElementsBaseVertex)(mode, start, end, count, type, indices, basevertex);
}

extern void* __blue_glCore_glDrawElementsInstancedBaseVertex;
void APIENTRY bluegl_glDrawElementsInstancedBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) {
    typedef void (APIENTRYP PFN_glDrawElementsInstancedBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
    return ((PFN_glDrawElementsInstancedBaseVertex)__blue_glCore_glDrawElementsInstancedBaseVertex)(mode, count, type, indices, instancecount, basevertex);
}

extern void* __blue_glCore_glMultiDrawElementsBaseVertex;
void APIENTRY bluegl_glMultiDrawElementsBaseVertex (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) {
    typedef void (APIENTRYP PFN_glMultiDrawElementsBaseVertex) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
    return ((PFN_glMultiDrawElementsBaseVertex)__blue_glCore_glMultiDrawElementsBaseVertex)(mode, count, type, indices, drawcount, basevertex);
}

extern void* __blue_glCore_glProvokingVertex;
void APIENTRY bluegl_glProvokingVertex (GLenum mode) {
    typedef void (APIENTRYP PFN_glProvokingVertex) (GLenum mode);
    return ((PFN_glProvokingVertex)__blue_glCore_glProvokingVertex)(mode);
}

extern void* __blue_glCore_glFenceSync;
GLsync APIENTRY bluegl_glFenceSync (GLenum condition, GLbitfield flags) {
    typedef GLsync (APIENTRYP PFN_glFenceSync) (GLenum condition, GLbitfield flags);
    return ((PFN_glFenceSync)__blue_glCore_glFenceSync)(condition, flags);
}

extern void* __blue_glCore_glIsSync;
GLboolean APIENTRY bluegl_glIsSync (GLsync sync) {
    typedef GLboolean (APIENTRYP PFN_glIsSync) (GLsync sync);
    return ((PFN_glIsSync)__blue_glCore_glIsSync)(sync);
}

extern void* __blue_glCore_glDeleteSync;
void APIENTRY bluegl_glDeleteSync (GLsync sync) {
    typedef void (APIENTRYP PFN_glDeleteSync) (GLsync sync);
    return ((PFN_glDeleteSync)__blue_glCore_glDeleteSync)(sync);
}

extern void* __blue_glCore_glClientWaitSync;
GLenum APIENTRY bluegl_glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout) {
    typedef GLenum (APIENTRYP PFN_glClientWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
    return ((PFN_glClientWaitSync)__blue_glCore_glClientWaitSync)(sync, flags, timeout);
}

extern void* __blue_glCore_glWaitSync;
void APIENTRY bluegl_glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout) {
    typedef void (APIENTRYP PFN_glWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
    return ((PFN_glWaitSync)__blue_glCore_glWaitSync)(sync, flags, timeout);
}

extern void* __blue_glCore_glGetInteger64v;
void APIENTRY bluegl_glGetInteger64v (GLenum pname, GLint64 *data) {
    typedef void (APIENTRYP PFN_glGetInteger64v) (GLenum pname, GLint64 *data);
    return ((PFN_glGetInteger64v)__blue_glCore_glGetInteger64v)(pname, data);
}

extern void* __blue_glCore_glGetSynciv;
void APIENTRY bluegl_glGetSynciv (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) {
    typedef void (APIENTRYP PFN_glGetSynciv) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
    return ((PFN_glGetSynciv)__blue_glCore_glGetSynciv)(sync, pname, bufSize, length, values);
}

extern void* __blue_glCore_glGetInteger64i_v;
void APIENTRY bluegl_glGetInteger64i_v (GLenum target, GLuint index, GLint64 *data) {
    typedef void (APIENTRYP PFN_glGetInteger64i_v) (GLenum target, GLuint index, GLint64 *data);
    return ((PFN_glGetInteger64i_v)__blue_glCore_glGetInteger64i_v)(target, index, data);
}

extern void* __blue_glCore_glGetBufferParameteri64v;
void APIENTRY bluegl_glGetBufferParameteri64v (GLenum target, GLenum pname, GLint64 *params) {
    typedef void (APIENTRYP PFN_glGetBufferParameteri64v) (GLenum target, GLenum pname, GLint64 *params);
    return ((PFN_glGetBufferParameteri64v)__blue_glCore_glGetBufferParameteri64v)(target, pname, params);
}

extern void* __blue_glCore_glFramebufferTexture;
void APIENTRY bluegl_glFramebufferTexture (GLenum target, GLenum attachment, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glFramebufferTexture) (GLenum target, GLenum attachment, GLuint texture, GLint level);
    return ((PFN_glFramebufferTexture)__blue_glCore_glFramebufferTexture)(target, attachment, texture, level);
}

extern void* __blue_glCore_glTexImage2DMultisample;
void APIENTRY bluegl_glTexImage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    typedef void (APIENTRYP PFN_glTexImage2DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    return ((PFN_glTexImage2DMultisample)__blue_glCore_glTexImage2DMultisample)(target, samples, internalformat, width, height, fixedsamplelocations);
}

extern void* __blue_glCore_glTexImage3DMultisample;
void APIENTRY bluegl_glTexImage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    typedef void (APIENTRYP PFN_glTexImage3DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    return ((PFN_glTexImage3DMultisample)__blue_glCore_glTexImage3DMultisample)(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

extern void* __blue_glCore_glGetMultisamplefv;
void APIENTRY bluegl_glGetMultisamplefv (GLenum pname, GLuint index, GLfloat *val) {
    typedef void (APIENTRYP PFN_glGetMultisamplefv) (GLenum pname, GLuint index, GLfloat *val);
    return ((PFN_glGetMultisamplefv)__blue_glCore_glGetMultisamplefv)(pname, index, val);
}

extern void* __blue_glCore_glSampleMaski;
void APIENTRY bluegl_glSampleMaski (GLuint maskNumber, GLbitfield mask) {
    typedef void (APIENTRYP PFN_glSampleMaski) (GLuint maskNumber, GLbitfield mask);
    return ((PFN_glSampleMaski)__blue_glCore_glSampleMaski)(maskNumber, mask);
}

extern void* __blue_glCore_glBindFragDataLocationIndexed;
void APIENTRY bluegl_glBindFragDataLocationIndexed (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) {
    typedef void (APIENTRYP PFN_glBindFragDataLocationIndexed) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
    return ((PFN_glBindFragDataLocationIndexed)__blue_glCore_glBindFragDataLocationIndexed)(program, colorNumber, index, name);
}

extern void* __blue_glCore_glGetFragDataIndex;
GLint APIENTRY bluegl_glGetFragDataIndex (GLuint program, const GLchar *name) {
    typedef GLint (APIENTRYP PFN_glGetFragDataIndex) (GLuint program, const GLchar *name);
    return ((PFN_glGetFragDataIndex)__blue_glCore_glGetFragDataIndex)(program, name);
}

extern void* __blue_glCore_glGenSamplers;
void APIENTRY bluegl_glGenSamplers (GLsizei count, GLuint *samplers) {
    typedef void (APIENTRYP PFN_glGenSamplers) (GLsizei count, GLuint *samplers);
    return ((PFN_glGenSamplers)__blue_glCore_glGenSamplers)(count, samplers);
}

extern void* __blue_glCore_glDeleteSamplers;
void APIENTRY bluegl_glDeleteSamplers (GLsizei count, const GLuint *samplers) {
    typedef void (APIENTRYP PFN_glDeleteSamplers) (GLsizei count, const GLuint *samplers);
    return ((PFN_glDeleteSamplers)__blue_glCore_glDeleteSamplers)(count, samplers);
}

extern void* __blue_glCore_glIsSampler;
GLboolean APIENTRY bluegl_glIsSampler (GLuint sampler) {
    typedef GLboolean (APIENTRYP PFN_glIsSampler) (GLuint sampler);
    return ((PFN_glIsSampler)__blue_glCore_glIsSampler)(sampler);
}

extern void* __blue_glCore_glBindSampler;
void APIENTRY bluegl_glBindSampler (GLuint unit, GLuint sampler) {
    typedef void (APIENTRYP PFN_glBindSampler) (GLuint unit, GLuint sampler);
    return ((PFN_glBindSampler)__blue_glCore_glBindSampler)(unit, sampler);
}

extern void* __blue_glCore_glSamplerParameteri;
void APIENTRY bluegl_glSamplerParameteri (GLuint sampler, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glSamplerParameteri) (GLuint sampler, GLenum pname, GLint param);
    return ((PFN_glSamplerParameteri)__blue_glCore_glSamplerParameteri)(sampler, pname, param);
}

extern void* __blue_glCore_glSamplerParameteriv;
void APIENTRY bluegl_glSamplerParameteriv (GLuint sampler, GLenum pname, const GLint *param) {
    typedef void (APIENTRYP PFN_glSamplerParameteriv) (GLuint sampler, GLenum pname, const GLint *param);
    return ((PFN_glSamplerParameteriv)__blue_glCore_glSamplerParameteriv)(sampler, pname, param);
}

extern void* __blue_glCore_glSamplerParameterf;
void APIENTRY bluegl_glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glSamplerParameterf) (GLuint sampler, GLenum pname, GLfloat param);
    return ((PFN_glSamplerParameterf)__blue_glCore_glSamplerParameterf)(sampler, pname, param);
}

extern void* __blue_glCore_glSamplerParameterfv;
void APIENTRY bluegl_glSamplerParameterfv (GLuint sampler, GLenum pname, const GLfloat *param) {
    typedef void (APIENTRYP PFN_glSamplerParameterfv) (GLuint sampler, GLenum pname, const GLfloat *param);
    return ((PFN_glSamplerParameterfv)__blue_glCore_glSamplerParameterfv)(sampler, pname, param);
}

extern void* __blue_glCore_glSamplerParameterIiv;
void APIENTRY bluegl_glSamplerParameterIiv (GLuint sampler, GLenum pname, const GLint *param) {
    typedef void (APIENTRYP PFN_glSamplerParameterIiv) (GLuint sampler, GLenum pname, const GLint *param);
    return ((PFN_glSamplerParameterIiv)__blue_glCore_glSamplerParameterIiv)(sampler, pname, param);
}

extern void* __blue_glCore_glSamplerParameterIuiv;
void APIENTRY bluegl_glSamplerParameterIuiv (GLuint sampler, GLenum pname, const GLuint *param) {
    typedef void (APIENTRYP PFN_glSamplerParameterIuiv) (GLuint sampler, GLenum pname, const GLuint *param);
    return ((PFN_glSamplerParameterIuiv)__blue_glCore_glSamplerParameterIuiv)(sampler, pname, param);
}

extern void* __blue_glCore_glGetSamplerParameteriv;
void APIENTRY bluegl_glGetSamplerParameteriv (GLuint sampler, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetSamplerParameteriv) (GLuint sampler, GLenum pname, GLint *params);
    return ((PFN_glGetSamplerParameteriv)__blue_glCore_glGetSamplerParameteriv)(sampler, pname, params);
}

extern void* __blue_glCore_glGetSamplerParameterIiv;
void APIENTRY bluegl_glGetSamplerParameterIiv (GLuint sampler, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetSamplerParameterIiv) (GLuint sampler, GLenum pname, GLint *params);
    return ((PFN_glGetSamplerParameterIiv)__blue_glCore_glGetSamplerParameterIiv)(sampler, pname, params);
}

extern void* __blue_glCore_glGetSamplerParameterfv;
void APIENTRY bluegl_glGetSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetSamplerParameterfv) (GLuint sampler, GLenum pname, GLfloat *params);
    return ((PFN_glGetSamplerParameterfv)__blue_glCore_glGetSamplerParameterfv)(sampler, pname, params);
}

extern void* __blue_glCore_glGetSamplerParameterIuiv;
void APIENTRY bluegl_glGetSamplerParameterIuiv (GLuint sampler, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetSamplerParameterIuiv) (GLuint sampler, GLenum pname, GLuint *params);
    return ((PFN_glGetSamplerParameterIuiv)__blue_glCore_glGetSamplerParameterIuiv)(sampler, pname, params);
}

extern void* __blue_glCore_glQueryCounter;
void APIENTRY bluegl_glQueryCounter (GLuint id, GLenum target) {
    typedef void (APIENTRYP PFN_glQueryCounter) (GLuint id, GLenum target);
    return ((PFN_glQueryCounter)__blue_glCore_glQueryCounter)(id, target);
}

extern void* __blue_glCore_glGetQueryObjecti64v;
void APIENTRY bluegl_glGetQueryObjecti64v (GLuint id, GLenum pname, GLint64 *params) {
    typedef void (APIENTRYP PFN_glGetQueryObjecti64v) (GLuint id, GLenum pname, GLint64 *params);
    return ((PFN_glGetQueryObjecti64v)__blue_glCore_glGetQueryObjecti64v)(id, pname, params);
}

extern void* __blue_glCore_glGetQueryObjectui64v;
void APIENTRY bluegl_glGetQueryObjectui64v (GLuint id, GLenum pname, GLuint64 *params) {
    typedef void (APIENTRYP PFN_glGetQueryObjectui64v) (GLuint id, GLenum pname, GLuint64 *params);
    return ((PFN_glGetQueryObjectui64v)__blue_glCore_glGetQueryObjectui64v)(id, pname, params);
}

extern void* __blue_glCore_glVertexAttribDivisor;
void APIENTRY bluegl_glVertexAttribDivisor (GLuint index, GLuint divisor) {
    typedef void (APIENTRYP PFN_glVertexAttribDivisor) (GLuint index, GLuint divisor);
    return ((PFN_glVertexAttribDivisor)__blue_glCore_glVertexAttribDivisor)(index, divisor);
}

extern void* __blue_glCore_glVertexAttribP1ui;
void APIENTRY bluegl_glVertexAttribP1ui (GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    typedef void (APIENTRYP PFN_glVertexAttribP1ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    return ((PFN_glVertexAttribP1ui)__blue_glCore_glVertexAttribP1ui)(index, type, normalized, value);
}

extern void* __blue_glCore_glVertexAttribP1uiv;
void APIENTRY bluegl_glVertexAttribP1uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value) {
    typedef void (APIENTRYP PFN_glVertexAttribP1uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    return ((PFN_glVertexAttribP1uiv)__blue_glCore_glVertexAttribP1uiv)(index, type, normalized, value);
}

extern void* __blue_glCore_glVertexAttribP2ui;
void APIENTRY bluegl_glVertexAttribP2ui (GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    typedef void (APIENTRYP PFN_glVertexAttribP2ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    return ((PFN_glVertexAttribP2ui)__blue_glCore_glVertexAttribP2ui)(index, type, normalized, value);
}

extern void* __blue_glCore_glVertexAttribP2uiv;
void APIENTRY bluegl_glVertexAttribP2uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value) {
    typedef void (APIENTRYP PFN_glVertexAttribP2uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    return ((PFN_glVertexAttribP2uiv)__blue_glCore_glVertexAttribP2uiv)(index, type, normalized, value);
}

extern void* __blue_glCore_glVertexAttribP3ui;
void APIENTRY bluegl_glVertexAttribP3ui (GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    typedef void (APIENTRYP PFN_glVertexAttribP3ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    return ((PFN_glVertexAttribP3ui)__blue_glCore_glVertexAttribP3ui)(index, type, normalized, value);
}

extern void* __blue_glCore_glVertexAttribP3uiv;
void APIENTRY bluegl_glVertexAttribP3uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value) {
    typedef void (APIENTRYP PFN_glVertexAttribP3uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    return ((PFN_glVertexAttribP3uiv)__blue_glCore_glVertexAttribP3uiv)(index, type, normalized, value);
}

extern void* __blue_glCore_glVertexAttribP4ui;
void APIENTRY bluegl_glVertexAttribP4ui (GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    typedef void (APIENTRYP PFN_glVertexAttribP4ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
    return ((PFN_glVertexAttribP4ui)__blue_glCore_glVertexAttribP4ui)(index, type, normalized, value);
}

extern void* __blue_glCore_glVertexAttribP4uiv;
void APIENTRY bluegl_glVertexAttribP4uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value) {
    typedef void (APIENTRYP PFN_glVertexAttribP4uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
    return ((PFN_glVertexAttribP4uiv)__blue_glCore_glVertexAttribP4uiv)(index, type, normalized, value);
}

extern void* __blue_glCore_glMinSampleShading;
void APIENTRY bluegl_glMinSampleShading (GLfloat value) {
    typedef void (APIENTRYP PFN_glMinSampleShading) (GLfloat value);
    return ((PFN_glMinSampleShading)__blue_glCore_glMinSampleShading)(value);
}

extern void* __blue_glCore_glBlendEquationi;
void APIENTRY bluegl_glBlendEquationi (GLuint buf, GLenum mode) {
    typedef void (APIENTRYP PFN_glBlendEquationi) (GLuint buf, GLenum mode);
    return ((PFN_glBlendEquationi)__blue_glCore_glBlendEquationi)(buf, mode);
}

extern void* __blue_glCore_glBlendEquationSeparatei;
void APIENTRY bluegl_glBlendEquationSeparatei (GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
    typedef void (APIENTRYP PFN_glBlendEquationSeparatei) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    return ((PFN_glBlendEquationSeparatei)__blue_glCore_glBlendEquationSeparatei)(buf, modeRGB, modeAlpha);
}

extern void* __blue_glCore_glBlendFunci;
void APIENTRY bluegl_glBlendFunci (GLuint buf, GLenum src, GLenum dst) {
    typedef void (APIENTRYP PFN_glBlendFunci) (GLuint buf, GLenum src, GLenum dst);
    return ((PFN_glBlendFunci)__blue_glCore_glBlendFunci)(buf, src, dst);
}

extern void* __blue_glCore_glBlendFuncSeparatei;
void APIENTRY bluegl_glBlendFuncSeparatei (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    typedef void (APIENTRYP PFN_glBlendFuncSeparatei) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    return ((PFN_glBlendFuncSeparatei)__blue_glCore_glBlendFuncSeparatei)(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

extern void* __blue_glCore_glDrawArraysIndirect;
void APIENTRY bluegl_glDrawArraysIndirect (GLenum mode, const void *indirect) {
    typedef void (APIENTRYP PFN_glDrawArraysIndirect) (GLenum mode, const void *indirect);
    return ((PFN_glDrawArraysIndirect)__blue_glCore_glDrawArraysIndirect)(mode, indirect);
}

extern void* __blue_glCore_glDrawElementsIndirect;
void APIENTRY bluegl_glDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect) {
    typedef void (APIENTRYP PFN_glDrawElementsIndirect) (GLenum mode, GLenum type, const void *indirect);
    return ((PFN_glDrawElementsIndirect)__blue_glCore_glDrawElementsIndirect)(mode, type, indirect);
}

extern void* __blue_glCore_glUniform1d;
void APIENTRY bluegl_glUniform1d (GLint location, GLdouble x) {
    typedef void (APIENTRYP PFN_glUniform1d) (GLint location, GLdouble x);
    return ((PFN_glUniform1d)__blue_glCore_glUniform1d)(location, x);
}

extern void* __blue_glCore_glUniform2d;
void APIENTRY bluegl_glUniform2d (GLint location, GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glUniform2d) (GLint location, GLdouble x, GLdouble y);
    return ((PFN_glUniform2d)__blue_glCore_glUniform2d)(location, x, y);
}

extern void* __blue_glCore_glUniform3d;
void APIENTRY bluegl_glUniform3d (GLint location, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glUniform3d) (GLint location, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glUniform3d)__blue_glCore_glUniform3d)(location, x, y, z);
}

extern void* __blue_glCore_glUniform4d;
void APIENTRY bluegl_glUniform4d (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glUniform4d) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glUniform4d)__blue_glCore_glUniform4d)(location, x, y, z, w);
}

extern void* __blue_glCore_glUniform1dv;
void APIENTRY bluegl_glUniform1dv (GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniform1dv) (GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glUniform1dv)__blue_glCore_glUniform1dv)(location, count, value);
}

extern void* __blue_glCore_glUniform2dv;
void APIENTRY bluegl_glUniform2dv (GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniform2dv) (GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glUniform2dv)__blue_glCore_glUniform2dv)(location, count, value);
}

extern void* __blue_glCore_glUniform3dv;
void APIENTRY bluegl_glUniform3dv (GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniform3dv) (GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glUniform3dv)__blue_glCore_glUniform3dv)(location, count, value);
}

extern void* __blue_glCore_glUniform4dv;
void APIENTRY bluegl_glUniform4dv (GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniform4dv) (GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glUniform4dv)__blue_glCore_glUniform4dv)(location, count, value);
}

extern void* __blue_glCore_glUniformMatrix2dv;
void APIENTRY bluegl_glUniformMatrix2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glUniformMatrix2dv)__blue_glCore_glUniformMatrix2dv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix3dv;
void APIENTRY bluegl_glUniformMatrix3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glUniformMatrix3dv)__blue_glCore_glUniformMatrix3dv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix4dv;
void APIENTRY bluegl_glUniformMatrix4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glUniformMatrix4dv)__blue_glCore_glUniformMatrix4dv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix2x3dv;
void APIENTRY bluegl_glUniformMatrix2x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix2x3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glUniformMatrix2x3dv)__blue_glCore_glUniformMatrix2x3dv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix2x4dv;
void APIENTRY bluegl_glUniformMatrix2x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix2x4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glUniformMatrix2x4dv)__blue_glCore_glUniformMatrix2x4dv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix3x2dv;
void APIENTRY bluegl_glUniformMatrix3x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix3x2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glUniformMatrix3x2dv)__blue_glCore_glUniformMatrix3x2dv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix3x4dv;
void APIENTRY bluegl_glUniformMatrix3x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix3x4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glUniformMatrix3x4dv)__blue_glCore_glUniformMatrix3x4dv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix4x2dv;
void APIENTRY bluegl_glUniformMatrix4x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix4x2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glUniformMatrix4x2dv)__blue_glCore_glUniformMatrix4x2dv)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix4x3dv;
void APIENTRY bluegl_glUniformMatrix4x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix4x3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glUniformMatrix4x3dv)__blue_glCore_glUniformMatrix4x3dv)(location, count, transpose, value);
}

extern void* __blue_glCore_glGetUniformdv;
void APIENTRY bluegl_glGetUniformdv (GLuint program, GLint location, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetUniformdv) (GLuint program, GLint location, GLdouble *params);
    return ((PFN_glGetUniformdv)__blue_glCore_glGetUniformdv)(program, location, params);
}

extern void* __blue_glCore_glGetSubroutineUniformLocation;
GLint APIENTRY bluegl_glGetSubroutineUniformLocation (GLuint program, GLenum shadertype, const GLchar *name) {
    typedef GLint (APIENTRYP PFN_glGetSubroutineUniformLocation) (GLuint program, GLenum shadertype, const GLchar *name);
    return ((PFN_glGetSubroutineUniformLocation)__blue_glCore_glGetSubroutineUniformLocation)(program, shadertype, name);
}

extern void* __blue_glCore_glGetSubroutineIndex;
GLuint APIENTRY bluegl_glGetSubroutineIndex (GLuint program, GLenum shadertype, const GLchar *name) {
    typedef GLuint (APIENTRYP PFN_glGetSubroutineIndex) (GLuint program, GLenum shadertype, const GLchar *name);
    return ((PFN_glGetSubroutineIndex)__blue_glCore_glGetSubroutineIndex)(program, shadertype, name);
}

extern void* __blue_glCore_glGetActiveSubroutineUniformiv;
void APIENTRY bluegl_glGetActiveSubroutineUniformiv (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values) {
    typedef void (APIENTRYP PFN_glGetActiveSubroutineUniformiv) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
    return ((PFN_glGetActiveSubroutineUniformiv)__blue_glCore_glGetActiveSubroutineUniformiv)(program, shadertype, index, pname, values);
}

extern void* __blue_glCore_glGetActiveSubroutineUniformName;
void APIENTRY bluegl_glGetActiveSubroutineUniformName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name) {
    typedef void (APIENTRYP PFN_glGetActiveSubroutineUniformName) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
    return ((PFN_glGetActiveSubroutineUniformName)__blue_glCore_glGetActiveSubroutineUniformName)(program, shadertype, index, bufsize, length, name);
}

extern void* __blue_glCore_glGetActiveSubroutineName;
void APIENTRY bluegl_glGetActiveSubroutineName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name) {
    typedef void (APIENTRYP PFN_glGetActiveSubroutineName) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
    return ((PFN_glGetActiveSubroutineName)__blue_glCore_glGetActiveSubroutineName)(program, shadertype, index, bufsize, length, name);
}

extern void* __blue_glCore_glUniformSubroutinesuiv;
void APIENTRY bluegl_glUniformSubroutinesuiv (GLenum shadertype, GLsizei count, const GLuint *indices) {
    typedef void (APIENTRYP PFN_glUniformSubroutinesuiv) (GLenum shadertype, GLsizei count, const GLuint *indices);
    return ((PFN_glUniformSubroutinesuiv)__blue_glCore_glUniformSubroutinesuiv)(shadertype, count, indices);
}

extern void* __blue_glCore_glGetUniformSubroutineuiv;
void APIENTRY bluegl_glGetUniformSubroutineuiv (GLenum shadertype, GLint location, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetUniformSubroutineuiv) (GLenum shadertype, GLint location, GLuint *params);
    return ((PFN_glGetUniformSubroutineuiv)__blue_glCore_glGetUniformSubroutineuiv)(shadertype, location, params);
}

extern void* __blue_glCore_glGetProgramStageiv;
void APIENTRY bluegl_glGetProgramStageiv (GLuint program, GLenum shadertype, GLenum pname, GLint *values) {
    typedef void (APIENTRYP PFN_glGetProgramStageiv) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
    return ((PFN_glGetProgramStageiv)__blue_glCore_glGetProgramStageiv)(program, shadertype, pname, values);
}

extern void* __blue_glCore_glPatchParameteri;
void APIENTRY bluegl_glPatchParameteri (GLenum pname, GLint value) {
    typedef void (APIENTRYP PFN_glPatchParameteri) (GLenum pname, GLint value);
    return ((PFN_glPatchParameteri)__blue_glCore_glPatchParameteri)(pname, value);
}

extern void* __blue_glCore_glPatchParameterfv;
void APIENTRY bluegl_glPatchParameterfv (GLenum pname, const GLfloat *values) {
    typedef void (APIENTRYP PFN_glPatchParameterfv) (GLenum pname, const GLfloat *values);
    return ((PFN_glPatchParameterfv)__blue_glCore_glPatchParameterfv)(pname, values);
}

extern void* __blue_glCore_glBindTransformFeedback;
void APIENTRY bluegl_glBindTransformFeedback (GLenum target, GLuint id) {
    typedef void (APIENTRYP PFN_glBindTransformFeedback) (GLenum target, GLuint id);
    return ((PFN_glBindTransformFeedback)__blue_glCore_glBindTransformFeedback)(target, id);
}

extern void* __blue_glCore_glDeleteTransformFeedbacks;
void APIENTRY bluegl_glDeleteTransformFeedbacks (GLsizei n, const GLuint *ids) {
    typedef void (APIENTRYP PFN_glDeleteTransformFeedbacks) (GLsizei n, const GLuint *ids);
    return ((PFN_glDeleteTransformFeedbacks)__blue_glCore_glDeleteTransformFeedbacks)(n, ids);
}

extern void* __blue_glCore_glGenTransformFeedbacks;
void APIENTRY bluegl_glGenTransformFeedbacks (GLsizei n, GLuint *ids) {
    typedef void (APIENTRYP PFN_glGenTransformFeedbacks) (GLsizei n, GLuint *ids);
    return ((PFN_glGenTransformFeedbacks)__blue_glCore_glGenTransformFeedbacks)(n, ids);
}

extern void* __blue_glCore_glIsTransformFeedback;
GLboolean APIENTRY bluegl_glIsTransformFeedback (GLuint id) {
    typedef GLboolean (APIENTRYP PFN_glIsTransformFeedback) (GLuint id);
    return ((PFN_glIsTransformFeedback)__blue_glCore_glIsTransformFeedback)(id);
}

extern void* __blue_glCore_glPauseTransformFeedback;
void APIENTRY bluegl_glPauseTransformFeedback (void) {
    typedef void (APIENTRYP PFN_glPauseTransformFeedback) (void);
    return ((PFN_glPauseTransformFeedback)__blue_glCore_glPauseTransformFeedback)();
}

extern void* __blue_glCore_glResumeTransformFeedback;
void APIENTRY bluegl_glResumeTransformFeedback (void) {
    typedef void (APIENTRYP PFN_glResumeTransformFeedback) (void);
    return ((PFN_glResumeTransformFeedback)__blue_glCore_glResumeTransformFeedback)();
}

extern void* __blue_glCore_glDrawTransformFeedback;
void APIENTRY bluegl_glDrawTransformFeedback (GLenum mode, GLuint id) {
    typedef void (APIENTRYP PFN_glDrawTransformFeedback) (GLenum mode, GLuint id);
    return ((PFN_glDrawTransformFeedback)__blue_glCore_glDrawTransformFeedback)(mode, id);
}

extern void* __blue_glCore_glDrawTransformFeedbackStream;
void APIENTRY bluegl_glDrawTransformFeedbackStream (GLenum mode, GLuint id, GLuint stream) {
    typedef void (APIENTRYP PFN_glDrawTransformFeedbackStream) (GLenum mode, GLuint id, GLuint stream);
    return ((PFN_glDrawTransformFeedbackStream)__blue_glCore_glDrawTransformFeedbackStream)(mode, id, stream);
}

extern void* __blue_glCore_glBeginQueryIndexed;
void APIENTRY bluegl_glBeginQueryIndexed (GLenum target, GLuint index, GLuint id) {
    typedef void (APIENTRYP PFN_glBeginQueryIndexed) (GLenum target, GLuint index, GLuint id);
    return ((PFN_glBeginQueryIndexed)__blue_glCore_glBeginQueryIndexed)(target, index, id);
}

extern void* __blue_glCore_glEndQueryIndexed;
void APIENTRY bluegl_glEndQueryIndexed (GLenum target, GLuint index) {
    typedef void (APIENTRYP PFN_glEndQueryIndexed) (GLenum target, GLuint index);
    return ((PFN_glEndQueryIndexed)__blue_glCore_glEndQueryIndexed)(target, index);
}

extern void* __blue_glCore_glGetQueryIndexediv;
void APIENTRY bluegl_glGetQueryIndexediv (GLenum target, GLuint index, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetQueryIndexediv) (GLenum target, GLuint index, GLenum pname, GLint *params);
    return ((PFN_glGetQueryIndexediv)__blue_glCore_glGetQueryIndexediv)(target, index, pname, params);
}

extern void* __blue_glCore_glReleaseShaderCompiler;
void APIENTRY bluegl_glReleaseShaderCompiler (void) {
    typedef void (APIENTRYP PFN_glReleaseShaderCompiler) (void);
    return ((PFN_glReleaseShaderCompiler)__blue_glCore_glReleaseShaderCompiler)();
}

extern void* __blue_glCore_glShaderBinary;
void APIENTRY bluegl_glShaderBinary (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) {
    typedef void (APIENTRYP PFN_glShaderBinary) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
    return ((PFN_glShaderBinary)__blue_glCore_glShaderBinary)(count, shaders, binaryformat, binary, length);
}

extern void* __blue_glCore_glGetShaderPrecisionFormat;
void APIENTRY bluegl_glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) {
    typedef void (APIENTRYP PFN_glGetShaderPrecisionFormat) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
    return ((PFN_glGetShaderPrecisionFormat)__blue_glCore_glGetShaderPrecisionFormat)(shadertype, precisiontype, range, precision);
}

extern void* __blue_glCore_glDepthRangef;
void APIENTRY bluegl_glDepthRangef (GLfloat n, GLfloat f) {
    typedef void (APIENTRYP PFN_glDepthRangef) (GLfloat n, GLfloat f);
    return ((PFN_glDepthRangef)__blue_glCore_glDepthRangef)(n, f);
}

extern void* __blue_glCore_glClearDepthf;
void APIENTRY bluegl_glClearDepthf (GLfloat d) {
    typedef void (APIENTRYP PFN_glClearDepthf) (GLfloat d);
    return ((PFN_glClearDepthf)__blue_glCore_glClearDepthf)(d);
}

extern void* __blue_glCore_glGetProgramBinary;
void APIENTRY bluegl_glGetProgramBinary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) {
    typedef void (APIENTRYP PFN_glGetProgramBinary) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
    return ((PFN_glGetProgramBinary)__blue_glCore_glGetProgramBinary)(program, bufSize, length, binaryFormat, binary);
}

extern void* __blue_glCore_glProgramBinary;
void APIENTRY bluegl_glProgramBinary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) {
    typedef void (APIENTRYP PFN_glProgramBinary) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
    return ((PFN_glProgramBinary)__blue_glCore_glProgramBinary)(program, binaryFormat, binary, length);
}

extern void* __blue_glCore_glProgramParameteri;
void APIENTRY bluegl_glProgramParameteri (GLuint program, GLenum pname, GLint value) {
    typedef void (APIENTRYP PFN_glProgramParameteri) (GLuint program, GLenum pname, GLint value);
    return ((PFN_glProgramParameteri)__blue_glCore_glProgramParameteri)(program, pname, value);
}

extern void* __blue_glCore_glUseProgramStages;
void APIENTRY bluegl_glUseProgramStages (GLuint pipeline, GLbitfield stages, GLuint program) {
    typedef void (APIENTRYP PFN_glUseProgramStages) (GLuint pipeline, GLbitfield stages, GLuint program);
    return ((PFN_glUseProgramStages)__blue_glCore_glUseProgramStages)(pipeline, stages, program);
}

extern void* __blue_glCore_glActiveShaderProgram;
void APIENTRY bluegl_glActiveShaderProgram (GLuint pipeline, GLuint program) {
    typedef void (APIENTRYP PFN_glActiveShaderProgram) (GLuint pipeline, GLuint program);
    return ((PFN_glActiveShaderProgram)__blue_glCore_glActiveShaderProgram)(pipeline, program);
}

extern void* __blue_glCore_glCreateShaderProgramv;
GLuint APIENTRY bluegl_glCreateShaderProgramv (GLenum type, GLsizei count, const GLchar *const*strings) {
    typedef GLuint (APIENTRYP PFN_glCreateShaderProgramv) (GLenum type, GLsizei count, const GLchar *const*strings);
    return ((PFN_glCreateShaderProgramv)__blue_glCore_glCreateShaderProgramv)(type, count, strings);
}

extern void* __blue_glCore_glBindProgramPipeline;
void APIENTRY bluegl_glBindProgramPipeline (GLuint pipeline) {
    typedef void (APIENTRYP PFN_glBindProgramPipeline) (GLuint pipeline);
    return ((PFN_glBindProgramPipeline)__blue_glCore_glBindProgramPipeline)(pipeline);
}

extern void* __blue_glCore_glDeleteProgramPipelines;
void APIENTRY bluegl_glDeleteProgramPipelines (GLsizei n, const GLuint *pipelines) {
    typedef void (APIENTRYP PFN_glDeleteProgramPipelines) (GLsizei n, const GLuint *pipelines);
    return ((PFN_glDeleteProgramPipelines)__blue_glCore_glDeleteProgramPipelines)(n, pipelines);
}

extern void* __blue_glCore_glGenProgramPipelines;
void APIENTRY bluegl_glGenProgramPipelines (GLsizei n, GLuint *pipelines) {
    typedef void (APIENTRYP PFN_glGenProgramPipelines) (GLsizei n, GLuint *pipelines);
    return ((PFN_glGenProgramPipelines)__blue_glCore_glGenProgramPipelines)(n, pipelines);
}

extern void* __blue_glCore_glIsProgramPipeline;
GLboolean APIENTRY bluegl_glIsProgramPipeline (GLuint pipeline) {
    typedef GLboolean (APIENTRYP PFN_glIsProgramPipeline) (GLuint pipeline);
    return ((PFN_glIsProgramPipeline)__blue_glCore_glIsProgramPipeline)(pipeline);
}

extern void* __blue_glCore_glGetProgramPipelineiv;
void APIENTRY bluegl_glGetProgramPipelineiv (GLuint pipeline, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetProgramPipelineiv) (GLuint pipeline, GLenum pname, GLint *params);
    return ((PFN_glGetProgramPipelineiv)__blue_glCore_glGetProgramPipelineiv)(pipeline, pname, params);
}

extern void* __blue_glCore_glProgramUniform1i;
void APIENTRY bluegl_glProgramUniform1i (GLuint program, GLint location, GLint v0) {
    typedef void (APIENTRYP PFN_glProgramUniform1i) (GLuint program, GLint location, GLint v0);
    return ((PFN_glProgramUniform1i)__blue_glCore_glProgramUniform1i)(program, location, v0);
}

extern void* __blue_glCore_glProgramUniform1iv;
void APIENTRY bluegl_glProgramUniform1iv (GLuint program, GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1iv) (GLuint program, GLint location, GLsizei count, const GLint *value);
    return ((PFN_glProgramUniform1iv)__blue_glCore_glProgramUniform1iv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform1f;
void APIENTRY bluegl_glProgramUniform1f (GLuint program, GLint location, GLfloat v0) {
    typedef void (APIENTRYP PFN_glProgramUniform1f) (GLuint program, GLint location, GLfloat v0);
    return ((PFN_glProgramUniform1f)__blue_glCore_glProgramUniform1f)(program, location, v0);
}

extern void* __blue_glCore_glProgramUniform1fv;
void APIENTRY bluegl_glProgramUniform1fv (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glProgramUniform1fv)__blue_glCore_glProgramUniform1fv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform1d;
void APIENTRY bluegl_glProgramUniform1d (GLuint program, GLint location, GLdouble v0) {
    typedef void (APIENTRYP PFN_glProgramUniform1d) (GLuint program, GLint location, GLdouble v0);
    return ((PFN_glProgramUniform1d)__blue_glCore_glProgramUniform1d)(program, location, v0);
}

extern void* __blue_glCore_glProgramUniform1dv;
void APIENTRY bluegl_glProgramUniform1dv (GLuint program, GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glProgramUniform1dv)__blue_glCore_glProgramUniform1dv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform1ui;
void APIENTRY bluegl_glProgramUniform1ui (GLuint program, GLint location, GLuint v0) {
    typedef void (APIENTRYP PFN_glProgramUniform1ui) (GLuint program, GLint location, GLuint v0);
    return ((PFN_glProgramUniform1ui)__blue_glCore_glProgramUniform1ui)(program, location, v0);
}

extern void* __blue_glCore_glProgramUniform1uiv;
void APIENTRY bluegl_glProgramUniform1uiv (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glProgramUniform1uiv)__blue_glCore_glProgramUniform1uiv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2i;
void APIENTRY bluegl_glProgramUniform2i (GLuint program, GLint location, GLint v0, GLint v1) {
    typedef void (APIENTRYP PFN_glProgramUniform2i) (GLuint program, GLint location, GLint v0, GLint v1);
    return ((PFN_glProgramUniform2i)__blue_glCore_glProgramUniform2i)(program, location, v0, v1);
}

extern void* __blue_glCore_glProgramUniform2iv;
void APIENTRY bluegl_glProgramUniform2iv (GLuint program, GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2iv) (GLuint program, GLint location, GLsizei count, const GLint *value);
    return ((PFN_glProgramUniform2iv)__blue_glCore_glProgramUniform2iv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2f;
void APIENTRY bluegl_glProgramUniform2f (GLuint program, GLint location, GLfloat v0, GLfloat v1) {
    typedef void (APIENTRYP PFN_glProgramUniform2f) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
    return ((PFN_glProgramUniform2f)__blue_glCore_glProgramUniform2f)(program, location, v0, v1);
}

extern void* __blue_glCore_glProgramUniform2fv;
void APIENTRY bluegl_glProgramUniform2fv (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glProgramUniform2fv)__blue_glCore_glProgramUniform2fv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2d;
void APIENTRY bluegl_glProgramUniform2d (GLuint program, GLint location, GLdouble v0, GLdouble v1) {
    typedef void (APIENTRYP PFN_glProgramUniform2d) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
    return ((PFN_glProgramUniform2d)__blue_glCore_glProgramUniform2d)(program, location, v0, v1);
}

extern void* __blue_glCore_glProgramUniform2dv;
void APIENTRY bluegl_glProgramUniform2dv (GLuint program, GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glProgramUniform2dv)__blue_glCore_glProgramUniform2dv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2ui;
void APIENTRY bluegl_glProgramUniform2ui (GLuint program, GLint location, GLuint v0, GLuint v1) {
    typedef void (APIENTRYP PFN_glProgramUniform2ui) (GLuint program, GLint location, GLuint v0, GLuint v1);
    return ((PFN_glProgramUniform2ui)__blue_glCore_glProgramUniform2ui)(program, location, v0, v1);
}

extern void* __blue_glCore_glProgramUniform2uiv;
void APIENTRY bluegl_glProgramUniform2uiv (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glProgramUniform2uiv)__blue_glCore_glProgramUniform2uiv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3i;
void APIENTRY bluegl_glProgramUniform3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
    typedef void (APIENTRYP PFN_glProgramUniform3i) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
    return ((PFN_glProgramUniform3i)__blue_glCore_glProgramUniform3i)(program, location, v0, v1, v2);
}

extern void* __blue_glCore_glProgramUniform3iv;
void APIENTRY bluegl_glProgramUniform3iv (GLuint program, GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3iv) (GLuint program, GLint location, GLsizei count, const GLint *value);
    return ((PFN_glProgramUniform3iv)__blue_glCore_glProgramUniform3iv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3f;
void APIENTRY bluegl_glProgramUniform3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    typedef void (APIENTRYP PFN_glProgramUniform3f) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    return ((PFN_glProgramUniform3f)__blue_glCore_glProgramUniform3f)(program, location, v0, v1, v2);
}

extern void* __blue_glCore_glProgramUniform3fv;
void APIENTRY bluegl_glProgramUniform3fv (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glProgramUniform3fv)__blue_glCore_glProgramUniform3fv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3d;
void APIENTRY bluegl_glProgramUniform3d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) {
    typedef void (APIENTRYP PFN_glProgramUniform3d) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
    return ((PFN_glProgramUniform3d)__blue_glCore_glProgramUniform3d)(program, location, v0, v1, v2);
}

extern void* __blue_glCore_glProgramUniform3dv;
void APIENTRY bluegl_glProgramUniform3dv (GLuint program, GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glProgramUniform3dv)__blue_glCore_glProgramUniform3dv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3ui;
void APIENTRY bluegl_glProgramUniform3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
    typedef void (APIENTRYP PFN_glProgramUniform3ui) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
    return ((PFN_glProgramUniform3ui)__blue_glCore_glProgramUniform3ui)(program, location, v0, v1, v2);
}

extern void* __blue_glCore_glProgramUniform3uiv;
void APIENTRY bluegl_glProgramUniform3uiv (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glProgramUniform3uiv)__blue_glCore_glProgramUniform3uiv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4i;
void APIENTRY bluegl_glProgramUniform4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    typedef void (APIENTRYP PFN_glProgramUniform4i) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    return ((PFN_glProgramUniform4i)__blue_glCore_glProgramUniform4i)(program, location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glProgramUniform4iv;
void APIENTRY bluegl_glProgramUniform4iv (GLuint program, GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4iv) (GLuint program, GLint location, GLsizei count, const GLint *value);
    return ((PFN_glProgramUniform4iv)__blue_glCore_glProgramUniform4iv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4f;
void APIENTRY bluegl_glProgramUniform4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    typedef void (APIENTRYP PFN_glProgramUniform4f) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    return ((PFN_glProgramUniform4f)__blue_glCore_glProgramUniform4f)(program, location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glProgramUniform4fv;
void APIENTRY bluegl_glProgramUniform4fv (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glProgramUniform4fv)__blue_glCore_glProgramUniform4fv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4d;
void APIENTRY bluegl_glProgramUniform4d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) {
    typedef void (APIENTRYP PFN_glProgramUniform4d) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
    return ((PFN_glProgramUniform4d)__blue_glCore_glProgramUniform4d)(program, location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glProgramUniform4dv;
void APIENTRY bluegl_glProgramUniform4dv (GLuint program, GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glProgramUniform4dv)__blue_glCore_glProgramUniform4dv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4ui;
void APIENTRY bluegl_glProgramUniform4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    typedef void (APIENTRYP PFN_glProgramUniform4ui) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    return ((PFN_glProgramUniform4ui)__blue_glCore_glProgramUniform4ui)(program, location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glProgramUniform4uiv;
void APIENTRY bluegl_glProgramUniform4uiv (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glProgramUniform4uiv)__blue_glCore_glProgramUniform4uiv)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2fv;
void APIENTRY bluegl_glProgramUniformMatrix2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix2fv)__blue_glCore_glProgramUniformMatrix2fv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3fv;
void APIENTRY bluegl_glProgramUniformMatrix3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix3fv)__blue_glCore_glProgramUniformMatrix3fv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4fv;
void APIENTRY bluegl_glProgramUniformMatrix4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix4fv)__blue_glCore_glProgramUniformMatrix4fv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2dv;
void APIENTRY bluegl_glProgramUniformMatrix2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix2dv)__blue_glCore_glProgramUniformMatrix2dv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3dv;
void APIENTRY bluegl_glProgramUniformMatrix3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix3dv)__blue_glCore_glProgramUniformMatrix3dv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4dv;
void APIENTRY bluegl_glProgramUniformMatrix4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix4dv)__blue_glCore_glProgramUniformMatrix4dv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2x3fv;
void APIENTRY bluegl_glProgramUniformMatrix2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2x3fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix2x3fv)__blue_glCore_glProgramUniformMatrix2x3fv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3x2fv;
void APIENTRY bluegl_glProgramUniformMatrix3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3x2fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix3x2fv)__blue_glCore_glProgramUniformMatrix3x2fv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2x4fv;
void APIENTRY bluegl_glProgramUniformMatrix2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2x4fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix2x4fv)__blue_glCore_glProgramUniformMatrix2x4fv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4x2fv;
void APIENTRY bluegl_glProgramUniformMatrix4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4x2fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix4x2fv)__blue_glCore_glProgramUniformMatrix4x2fv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3x4fv;
void APIENTRY bluegl_glProgramUniformMatrix3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3x4fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix3x4fv)__blue_glCore_glProgramUniformMatrix3x4fv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4x3fv;
void APIENTRY bluegl_glProgramUniformMatrix4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4x3fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix4x3fv)__blue_glCore_glProgramUniformMatrix4x3fv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2x3dv;
void APIENTRY bluegl_glProgramUniformMatrix2x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2x3dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix2x3dv)__blue_glCore_glProgramUniformMatrix2x3dv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3x2dv;
void APIENTRY bluegl_glProgramUniformMatrix3x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3x2dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix3x2dv)__blue_glCore_glProgramUniformMatrix3x2dv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2x4dv;
void APIENTRY bluegl_glProgramUniformMatrix2x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2x4dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix2x4dv)__blue_glCore_glProgramUniformMatrix2x4dv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4x2dv;
void APIENTRY bluegl_glProgramUniformMatrix4x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4x2dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix4x2dv)__blue_glCore_glProgramUniformMatrix4x2dv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3x4dv;
void APIENTRY bluegl_glProgramUniformMatrix3x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3x4dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix3x4dv)__blue_glCore_glProgramUniformMatrix3x4dv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4x3dv;
void APIENTRY bluegl_glProgramUniformMatrix4x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4x3dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix4x3dv)__blue_glCore_glProgramUniformMatrix4x3dv)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glValidateProgramPipeline;
void APIENTRY bluegl_glValidateProgramPipeline (GLuint pipeline) {
    typedef void (APIENTRYP PFN_glValidateProgramPipeline) (GLuint pipeline);
    return ((PFN_glValidateProgramPipeline)__blue_glCore_glValidateProgramPipeline)(pipeline);
}

extern void* __blue_glCore_glGetProgramPipelineInfoLog;
void APIENTRY bluegl_glGetProgramPipelineInfoLog (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    typedef void (APIENTRYP PFN_glGetProgramPipelineInfoLog) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    return ((PFN_glGetProgramPipelineInfoLog)__blue_glCore_glGetProgramPipelineInfoLog)(pipeline, bufSize, length, infoLog);
}

extern void* __blue_glCore_glVertexAttribL1d;
void APIENTRY bluegl_glVertexAttribL1d (GLuint index, GLdouble x) {
    typedef void (APIENTRYP PFN_glVertexAttribL1d) (GLuint index, GLdouble x);
    return ((PFN_glVertexAttribL1d)__blue_glCore_glVertexAttribL1d)(index, x);
}

extern void* __blue_glCore_glVertexAttribL2d;
void APIENTRY bluegl_glVertexAttribL2d (GLuint index, GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glVertexAttribL2d) (GLuint index, GLdouble x, GLdouble y);
    return ((PFN_glVertexAttribL2d)__blue_glCore_glVertexAttribL2d)(index, x, y);
}

extern void* __blue_glCore_glVertexAttribL3d;
void APIENTRY bluegl_glVertexAttribL3d (GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glVertexAttribL3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glVertexAttribL3d)__blue_glCore_glVertexAttribL3d)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttribL4d;
void APIENTRY bluegl_glVertexAttribL4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glVertexAttribL4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glVertexAttribL4d)__blue_glCore_glVertexAttribL4d)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttribL1dv;
void APIENTRY bluegl_glVertexAttribL1dv (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL1dv) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttribL1dv)__blue_glCore_glVertexAttribL1dv)(index, v);
}

extern void* __blue_glCore_glVertexAttribL2dv;
void APIENTRY bluegl_glVertexAttribL2dv (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL2dv) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttribL2dv)__blue_glCore_glVertexAttribL2dv)(index, v);
}

extern void* __blue_glCore_glVertexAttribL3dv;
void APIENTRY bluegl_glVertexAttribL3dv (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL3dv) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttribL3dv)__blue_glCore_glVertexAttribL3dv)(index, v);
}

extern void* __blue_glCore_glVertexAttribL4dv;
void APIENTRY bluegl_glVertexAttribL4dv (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL4dv) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttribL4dv)__blue_glCore_glVertexAttribL4dv)(index, v);
}

extern void* __blue_glCore_glVertexAttribLPointer;
void APIENTRY bluegl_glVertexAttribLPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexAttribLPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glVertexAttribLPointer)__blue_glCore_glVertexAttribLPointer)(index, size, type, stride, pointer);
}

extern void* __blue_glCore_glGetVertexAttribLdv;
void APIENTRY bluegl_glGetVertexAttribLdv (GLuint index, GLenum pname, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribLdv) (GLuint index, GLenum pname, GLdouble *params);
    return ((PFN_glGetVertexAttribLdv)__blue_glCore_glGetVertexAttribLdv)(index, pname, params);
}

extern void* __blue_glCore_glViewportArrayv;
void APIENTRY bluegl_glViewportArrayv (GLuint first, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glViewportArrayv) (GLuint first, GLsizei count, const GLfloat *v);
    return ((PFN_glViewportArrayv)__blue_glCore_glViewportArrayv)(first, count, v);
}

extern void* __blue_glCore_glViewportIndexedf;
void APIENTRY bluegl_glViewportIndexedf (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
    typedef void (APIENTRYP PFN_glViewportIndexedf) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
    return ((PFN_glViewportIndexedf)__blue_glCore_glViewportIndexedf)(index, x, y, w, h);
}

extern void* __blue_glCore_glViewportIndexedfv;
void APIENTRY bluegl_glViewportIndexedfv (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glViewportIndexedfv) (GLuint index, const GLfloat *v);
    return ((PFN_glViewportIndexedfv)__blue_glCore_glViewportIndexedfv)(index, v);
}

extern void* __blue_glCore_glScissorArrayv;
void APIENTRY bluegl_glScissorArrayv (GLuint first, GLsizei count, const GLint *v) {
    typedef void (APIENTRYP PFN_glScissorArrayv) (GLuint first, GLsizei count, const GLint *v);
    return ((PFN_glScissorArrayv)__blue_glCore_glScissorArrayv)(first, count, v);
}

extern void* __blue_glCore_glScissorIndexed;
void APIENTRY bluegl_glScissorIndexed (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glScissorIndexed) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
    return ((PFN_glScissorIndexed)__blue_glCore_glScissorIndexed)(index, left, bottom, width, height);
}

extern void* __blue_glCore_glScissorIndexedv;
void APIENTRY bluegl_glScissorIndexedv (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glScissorIndexedv) (GLuint index, const GLint *v);
    return ((PFN_glScissorIndexedv)__blue_glCore_glScissorIndexedv)(index, v);
}

extern void* __blue_glCore_glDepthRangeArrayv;
void APIENTRY bluegl_glDepthRangeArrayv (GLuint first, GLsizei count, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glDepthRangeArrayv) (GLuint first, GLsizei count, const GLdouble *v);
    return ((PFN_glDepthRangeArrayv)__blue_glCore_glDepthRangeArrayv)(first, count, v);
}

extern void* __blue_glCore_glDepthRangeIndexed;
void APIENTRY bluegl_glDepthRangeIndexed (GLuint index, GLdouble n, GLdouble f) {
    typedef void (APIENTRYP PFN_glDepthRangeIndexed) (GLuint index, GLdouble n, GLdouble f);
    return ((PFN_glDepthRangeIndexed)__blue_glCore_glDepthRangeIndexed)(index, n, f);
}

extern void* __blue_glCore_glGetFloati_v;
void APIENTRY bluegl_glGetFloati_v (GLenum target, GLuint index, GLfloat *data) {
    typedef void (APIENTRYP PFN_glGetFloati_v) (GLenum target, GLuint index, GLfloat *data);
    return ((PFN_glGetFloati_v)__blue_glCore_glGetFloati_v)(target, index, data);
}

extern void* __blue_glCore_glGetDoublei_v;
void APIENTRY bluegl_glGetDoublei_v (GLenum target, GLuint index, GLdouble *data) {
    typedef void (APIENTRYP PFN_glGetDoublei_v) (GLenum target, GLuint index, GLdouble *data);
    return ((PFN_glGetDoublei_v)__blue_glCore_glGetDoublei_v)(target, index, data);
}

extern void* __blue_glCore_glDrawArraysInstancedBaseInstance;
void APIENTRY bluegl_glDrawArraysInstancedBaseInstance (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) {
    typedef void (APIENTRYP PFN_glDrawArraysInstancedBaseInstance) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
    return ((PFN_glDrawArraysInstancedBaseInstance)__blue_glCore_glDrawArraysInstancedBaseInstance)(mode, first, count, instancecount, baseinstance);
}

extern void* __blue_glCore_glDrawElementsInstancedBaseInstance;
void APIENTRY bluegl_glDrawElementsInstancedBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance) {
    typedef void (APIENTRYP PFN_glDrawElementsInstancedBaseInstance) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
    return ((PFN_glDrawElementsInstancedBaseInstance)__blue_glCore_glDrawElementsInstancedBaseInstance)(mode, count, type, indices, instancecount, baseinstance);
}

extern void* __blue_glCore_glDrawElementsInstancedBaseVertexBaseInstance;
void APIENTRY bluegl_glDrawElementsInstancedBaseVertexBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) {
    typedef void (APIENTRYP PFN_glDrawElementsInstancedBaseVertexBaseInstance) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
    return ((PFN_glDrawElementsInstancedBaseVertexBaseInstance)__blue_glCore_glDrawElementsInstancedBaseVertexBaseInstance)(mode, count, type, indices, instancecount, basevertex, baseinstance);
}

extern void* __blue_glCore_glGetInternalformativ;
void APIENTRY bluegl_glGetInternalformativ (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) {
    typedef void (APIENTRYP PFN_glGetInternalformativ) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
    return ((PFN_glGetInternalformativ)__blue_glCore_glGetInternalformativ)(target, internalformat, pname, bufSize, params);
}

extern void* __blue_glCore_glGetActiveAtomicCounterBufferiv;
void APIENTRY bluegl_glGetActiveAtomicCounterBufferiv (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetActiveAtomicCounterBufferiv) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
    return ((PFN_glGetActiveAtomicCounterBufferiv)__blue_glCore_glGetActiveAtomicCounterBufferiv)(program, bufferIndex, pname, params);
}

extern void* __blue_glCore_glBindImageTexture;
void APIENTRY bluegl_glBindImageTexture (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {
    typedef void (APIENTRYP PFN_glBindImageTexture) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
    return ((PFN_glBindImageTexture)__blue_glCore_glBindImageTexture)(unit, texture, level, layered, layer, access, format);
}

extern void* __blue_glCore_glMemoryBarrier;
void APIENTRY bluegl_glMemoryBarrier (GLbitfield barriers) {
    typedef void (APIENTRYP PFN_glMemoryBarrier) (GLbitfield barriers);
    return ((PFN_glMemoryBarrier)__blue_glCore_glMemoryBarrier)(barriers);
}

extern void* __blue_glCore_glTexStorage1D;
void APIENTRY bluegl_glTexStorage1D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
    typedef void (APIENTRYP PFN_glTexStorage1D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
    return ((PFN_glTexStorage1D)__blue_glCore_glTexStorage1D)(target, levels, internalformat, width);
}

extern void* __blue_glCore_glTexStorage2D;
void APIENTRY bluegl_glTexStorage2D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glTexStorage2D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glTexStorage2D)__blue_glCore_glTexStorage2D)(target, levels, internalformat, width, height);
}

extern void* __blue_glCore_glTexStorage3D;
void APIENTRY bluegl_glTexStorage3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
    typedef void (APIENTRYP PFN_glTexStorage3D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    return ((PFN_glTexStorage3D)__blue_glCore_glTexStorage3D)(target, levels, internalformat, width, height, depth);
}

extern void* __blue_glCore_glDrawTransformFeedbackInstanced;
void APIENTRY bluegl_glDrawTransformFeedbackInstanced (GLenum mode, GLuint id, GLsizei instancecount) {
    typedef void (APIENTRYP PFN_glDrawTransformFeedbackInstanced) (GLenum mode, GLuint id, GLsizei instancecount);
    return ((PFN_glDrawTransformFeedbackInstanced)__blue_glCore_glDrawTransformFeedbackInstanced)(mode, id, instancecount);
}

extern void* __blue_glCore_glDrawTransformFeedbackStreamInstanced;
void APIENTRY bluegl_glDrawTransformFeedbackStreamInstanced (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) {
    typedef void (APIENTRYP PFN_glDrawTransformFeedbackStreamInstanced) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
    return ((PFN_glDrawTransformFeedbackStreamInstanced)__blue_glCore_glDrawTransformFeedbackStreamInstanced)(mode, id, stream, instancecount);
}

extern void* __blue_glCore_glClearBufferData;
void APIENTRY bluegl_glClearBufferData (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glClearBufferData) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
    return ((PFN_glClearBufferData)__blue_glCore_glClearBufferData)(target, internalformat, format, type, data);
}

extern void* __blue_glCore_glClearBufferSubData;
void APIENTRY bluegl_glClearBufferSubData (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glClearBufferSubData) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
    return ((PFN_glClearBufferSubData)__blue_glCore_glClearBufferSubData)(target, internalformat, offset, size, format, type, data);
}

extern void* __blue_glCore_glDispatchCompute;
void APIENTRY bluegl_glDispatchCompute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {
    typedef void (APIENTRYP PFN_glDispatchCompute) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
    return ((PFN_glDispatchCompute)__blue_glCore_glDispatchCompute)(num_groups_x, num_groups_y, num_groups_z);
}

extern void* __blue_glCore_glDispatchComputeIndirect;
void APIENTRY bluegl_glDispatchComputeIndirect (GLintptr indirect) {
    typedef void (APIENTRYP PFN_glDispatchComputeIndirect) (GLintptr indirect);
    return ((PFN_glDispatchComputeIndirect)__blue_glCore_glDispatchComputeIndirect)(indirect);
}

extern void* __blue_glCore_glCopyImageSubData;
void APIENTRY bluegl_glCopyImageSubData (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
    typedef void (APIENTRYP PFN_glCopyImageSubData) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
    return ((PFN_glCopyImageSubData)__blue_glCore_glCopyImageSubData)(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}

extern void* __blue_glCore_glFramebufferParameteri;
void APIENTRY bluegl_glFramebufferParameteri (GLenum target, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glFramebufferParameteri) (GLenum target, GLenum pname, GLint param);
    return ((PFN_glFramebufferParameteri)__blue_glCore_glFramebufferParameteri)(target, pname, param);
}

extern void* __blue_glCore_glGetFramebufferParameteriv;
void APIENTRY bluegl_glGetFramebufferParameteriv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetFramebufferParameteriv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetFramebufferParameteriv)__blue_glCore_glGetFramebufferParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glGetInternalformati64v;
void APIENTRY bluegl_glGetInternalformati64v (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params) {
    typedef void (APIENTRYP PFN_glGetInternalformati64v) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
    return ((PFN_glGetInternalformati64v)__blue_glCore_glGetInternalformati64v)(target, internalformat, pname, bufSize, params);
}

extern void* __blue_glCore_glInvalidateTexSubImage;
void APIENTRY bluegl_glInvalidateTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) {
    typedef void (APIENTRYP PFN_glInvalidateTexSubImage) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
    return ((PFN_glInvalidateTexSubImage)__blue_glCore_glInvalidateTexSubImage)(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

extern void* __blue_glCore_glInvalidateTexImage;
void APIENTRY bluegl_glInvalidateTexImage (GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glInvalidateTexImage) (GLuint texture, GLint level);
    return ((PFN_glInvalidateTexImage)__blue_glCore_glInvalidateTexImage)(texture, level);
}

extern void* __blue_glCore_glInvalidateBufferSubData;
void APIENTRY bluegl_glInvalidateBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr length) {
    typedef void (APIENTRYP PFN_glInvalidateBufferSubData) (GLuint buffer, GLintptr offset, GLsizeiptr length);
    return ((PFN_glInvalidateBufferSubData)__blue_glCore_glInvalidateBufferSubData)(buffer, offset, length);
}

extern void* __blue_glCore_glInvalidateBufferData;
void APIENTRY bluegl_glInvalidateBufferData (GLuint buffer) {
    typedef void (APIENTRYP PFN_glInvalidateBufferData) (GLuint buffer);
    return ((PFN_glInvalidateBufferData)__blue_glCore_glInvalidateBufferData)(buffer);
}

extern void* __blue_glCore_glInvalidateFramebuffer;
void APIENTRY bluegl_glInvalidateFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments) {
    typedef void (APIENTRYP PFN_glInvalidateFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
    return ((PFN_glInvalidateFramebuffer)__blue_glCore_glInvalidateFramebuffer)(target, numAttachments, attachments);
}

extern void* __blue_glCore_glInvalidateSubFramebuffer;
void APIENTRY bluegl_glInvalidateSubFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glInvalidateSubFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glInvalidateSubFramebuffer)__blue_glCore_glInvalidateSubFramebuffer)(target, numAttachments, attachments, x, y, width, height);
}

extern void* __blue_glCore_glMultiDrawArraysIndirect;
void APIENTRY bluegl_glMultiDrawArraysIndirect (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride) {
    typedef void (APIENTRYP PFN_glMultiDrawArraysIndirect) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
    return ((PFN_glMultiDrawArraysIndirect)__blue_glCore_glMultiDrawArraysIndirect)(mode, indirect, drawcount, stride);
}

extern void* __blue_glCore_glMultiDrawElementsIndirect;
void APIENTRY bluegl_glMultiDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride) {
    typedef void (APIENTRYP PFN_glMultiDrawElementsIndirect) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
    return ((PFN_glMultiDrawElementsIndirect)__blue_glCore_glMultiDrawElementsIndirect)(mode, type, indirect, drawcount, stride);
}

extern void* __blue_glCore_glGetProgramInterfaceiv;
void APIENTRY bluegl_glGetProgramInterfaceiv (GLuint program, GLenum programInterface, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetProgramInterfaceiv) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
    return ((PFN_glGetProgramInterfaceiv)__blue_glCore_glGetProgramInterfaceiv)(program, programInterface, pname, params);
}

extern void* __blue_glCore_glGetProgramResourceIndex;
GLuint APIENTRY bluegl_glGetProgramResourceIndex (GLuint program, GLenum programInterface, const GLchar *name) {
    typedef GLuint (APIENTRYP PFN_glGetProgramResourceIndex) (GLuint program, GLenum programInterface, const GLchar *name);
    return ((PFN_glGetProgramResourceIndex)__blue_glCore_glGetProgramResourceIndex)(program, programInterface, name);
}

extern void* __blue_glCore_glGetProgramResourceName;
void APIENTRY bluegl_glGetProgramResourceName (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) {
    typedef void (APIENTRYP PFN_glGetProgramResourceName) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
    return ((PFN_glGetProgramResourceName)__blue_glCore_glGetProgramResourceName)(program, programInterface, index, bufSize, length, name);
}

extern void* __blue_glCore_glGetProgramResourceiv;
void APIENTRY bluegl_glGetProgramResourceiv (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params) {
    typedef void (APIENTRYP PFN_glGetProgramResourceiv) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
    return ((PFN_glGetProgramResourceiv)__blue_glCore_glGetProgramResourceiv)(program, programInterface, index, propCount, props, bufSize, length, params);
}

extern void* __blue_glCore_glGetProgramResourceLocation;
GLint APIENTRY bluegl_glGetProgramResourceLocation (GLuint program, GLenum programInterface, const GLchar *name) {
    typedef GLint (APIENTRYP PFN_glGetProgramResourceLocation) (GLuint program, GLenum programInterface, const GLchar *name);
    return ((PFN_glGetProgramResourceLocation)__blue_glCore_glGetProgramResourceLocation)(program, programInterface, name);
}

extern void* __blue_glCore_glGetProgramResourceLocationIndex;
GLint APIENTRY bluegl_glGetProgramResourceLocationIndex (GLuint program, GLenum programInterface, const GLchar *name) {
    typedef GLint (APIENTRYP PFN_glGetProgramResourceLocationIndex) (GLuint program, GLenum programInterface, const GLchar *name);
    return ((PFN_glGetProgramResourceLocationIndex)__blue_glCore_glGetProgramResourceLocationIndex)(program, programInterface, name);
}

extern void* __blue_glCore_glShaderStorageBlockBinding;
void APIENTRY bluegl_glShaderStorageBlockBinding (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) {
    typedef void (APIENTRYP PFN_glShaderStorageBlockBinding) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
    return ((PFN_glShaderStorageBlockBinding)__blue_glCore_glShaderStorageBlockBinding)(program, storageBlockIndex, storageBlockBinding);
}

extern void* __blue_glCore_glTexBufferRange;
void APIENTRY bluegl_glTexBufferRange (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glTexBufferRange) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    return ((PFN_glTexBufferRange)__blue_glCore_glTexBufferRange)(target, internalformat, buffer, offset, size);
}

extern void* __blue_glCore_glTexStorage2DMultisample;
void APIENTRY bluegl_glTexStorage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    typedef void (APIENTRYP PFN_glTexStorage2DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    return ((PFN_glTexStorage2DMultisample)__blue_glCore_glTexStorage2DMultisample)(target, samples, internalformat, width, height, fixedsamplelocations);
}

extern void* __blue_glCore_glTexStorage3DMultisample;
void APIENTRY bluegl_glTexStorage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    typedef void (APIENTRYP PFN_glTexStorage3DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    return ((PFN_glTexStorage3DMultisample)__blue_glCore_glTexStorage3DMultisample)(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

extern void* __blue_glCore_glTextureView;
void APIENTRY bluegl_glTextureView (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
    typedef void (APIENTRYP PFN_glTextureView) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
    return ((PFN_glTextureView)__blue_glCore_glTextureView)(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}

extern void* __blue_glCore_glBindVertexBuffer;
void APIENTRY bluegl_glBindVertexBuffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
    typedef void (APIENTRYP PFN_glBindVertexBuffer) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    return ((PFN_glBindVertexBuffer)__blue_glCore_glBindVertexBuffer)(bindingindex, buffer, offset, stride);
}

extern void* __blue_glCore_glVertexAttribFormat;
void APIENTRY bluegl_glVertexAttribFormat (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
    typedef void (APIENTRYP PFN_glVertexAttribFormat) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    return ((PFN_glVertexAttribFormat)__blue_glCore_glVertexAttribFormat)(attribindex, size, type, normalized, relativeoffset);
}

extern void* __blue_glCore_glVertexAttribIFormat;
void APIENTRY bluegl_glVertexAttribIFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    typedef void (APIENTRYP PFN_glVertexAttribIFormat) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    return ((PFN_glVertexAttribIFormat)__blue_glCore_glVertexAttribIFormat)(attribindex, size, type, relativeoffset);
}

extern void* __blue_glCore_glVertexAttribLFormat;
void APIENTRY bluegl_glVertexAttribLFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    typedef void (APIENTRYP PFN_glVertexAttribLFormat) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    return ((PFN_glVertexAttribLFormat)__blue_glCore_glVertexAttribLFormat)(attribindex, size, type, relativeoffset);
}

extern void* __blue_glCore_glVertexAttribBinding;
void APIENTRY bluegl_glVertexAttribBinding (GLuint attribindex, GLuint bindingindex) {
    typedef void (APIENTRYP PFN_glVertexAttribBinding) (GLuint attribindex, GLuint bindingindex);
    return ((PFN_glVertexAttribBinding)__blue_glCore_glVertexAttribBinding)(attribindex, bindingindex);
}

extern void* __blue_glCore_glVertexBindingDivisor;
void APIENTRY bluegl_glVertexBindingDivisor (GLuint bindingindex, GLuint divisor) {
    typedef void (APIENTRYP PFN_glVertexBindingDivisor) (GLuint bindingindex, GLuint divisor);
    return ((PFN_glVertexBindingDivisor)__blue_glCore_glVertexBindingDivisor)(bindingindex, divisor);
}

extern void* __blue_glCore_glDebugMessageControl;
void APIENTRY bluegl_glDebugMessageControl (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) {
    typedef void (APIENTRYP PFN_glDebugMessageControl) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
    return ((PFN_glDebugMessageControl)__blue_glCore_glDebugMessageControl)(source, type, severity, count, ids, enabled);
}

extern void* __blue_glCore_glDebugMessageInsert;
void APIENTRY bluegl_glDebugMessageInsert (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) {
    typedef void (APIENTRYP PFN_glDebugMessageInsert) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
    return ((PFN_glDebugMessageInsert)__blue_glCore_glDebugMessageInsert)(source, type, id, severity, length, buf);
}

extern void* __blue_glCore_glDebugMessageCallback;
void APIENTRY bluegl_glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam) {
    typedef void (APIENTRYP PFN_glDebugMessageCallback) (GLDEBUGPROC callback, const void *userParam);
    return ((PFN_glDebugMessageCallback)__blue_glCore_glDebugMessageCallback)(callback, userParam);
}

extern void* __blue_glCore_glGetDebugMessageLog;
GLuint APIENTRY bluegl_glGetDebugMessageLog (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) {
    typedef GLuint (APIENTRYP PFN_glGetDebugMessageLog) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
    return ((PFN_glGetDebugMessageLog)__blue_glCore_glGetDebugMessageLog)(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

extern void* __blue_glCore_glPushDebugGroup;
void APIENTRY bluegl_glPushDebugGroup (GLenum source, GLuint id, GLsizei length, const GLchar *message) {
    typedef void (APIENTRYP PFN_glPushDebugGroup) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
    return ((PFN_glPushDebugGroup)__blue_glCore_glPushDebugGroup)(source, id, length, message);
}

extern void* __blue_glCore_glPopDebugGroup;
void APIENTRY bluegl_glPopDebugGroup (void) {
    typedef void (APIENTRYP PFN_glPopDebugGroup) (void);
    return ((PFN_glPopDebugGroup)__blue_glCore_glPopDebugGroup)();
}

extern void* __blue_glCore_glObjectLabel;
void APIENTRY bluegl_glObjectLabel (GLenum identifier, GLuint name, GLsizei length, const GLchar *label) {
    typedef void (APIENTRYP PFN_glObjectLabel) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
    return ((PFN_glObjectLabel)__blue_glCore_glObjectLabel)(identifier, name, length, label);
}

extern void* __blue_glCore_glGetObjectLabel;
void APIENTRY bluegl_glGetObjectLabel (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) {
    typedef void (APIENTRYP PFN_glGetObjectLabel) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
    return ((PFN_glGetObjectLabel)__blue_glCore_glGetObjectLabel)(identifier, name, bufSize, length, label);
}

extern void* __blue_glCore_glObjectPtrLabel;
void APIENTRY bluegl_glObjectPtrLabel (const void *ptr, GLsizei length, const GLchar *label) {
    typedef void (APIENTRYP PFN_glObjectPtrLabel) (const void *ptr, GLsizei length, const GLchar *label);
    return ((PFN_glObjectPtrLabel)__blue_glCore_glObjectPtrLabel)(ptr, length, label);
}

extern void* __blue_glCore_glGetObjectPtrLabel;
void APIENTRY bluegl_glGetObjectPtrLabel (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) {
    typedef void (APIENTRYP PFN_glGetObjectPtrLabel) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
    return ((PFN_glGetObjectPtrLabel)__blue_glCore_glGetObjectPtrLabel)(ptr, bufSize, length, label);
}

extern void* __blue_glCore_glBufferStorage;
void APIENTRY bluegl_glBufferStorage (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags) {
    typedef void (APIENTRYP PFN_glBufferStorage) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
    return ((PFN_glBufferStorage)__blue_glCore_glBufferStorage)(target, size, data, flags);
}

extern void* __blue_glCore_glClearTexImage;
void APIENTRY bluegl_glClearTexImage (GLuint texture, GLint level, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glClearTexImage) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
    return ((PFN_glClearTexImage)__blue_glCore_glClearTexImage)(texture, level, format, type, data);
}

extern void* __blue_glCore_glClearTexSubImage;
void APIENTRY bluegl_glClearTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glClearTexSubImage) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
    return ((PFN_glClearTexSubImage)__blue_glCore_glClearTexSubImage)(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}

extern void* __blue_glCore_glBindBuffersBase;
void APIENTRY bluegl_glBindBuffersBase (GLenum target, GLuint first, GLsizei count, const GLuint *buffers) {
    typedef void (APIENTRYP PFN_glBindBuffersBase) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
    return ((PFN_glBindBuffersBase)__blue_glCore_glBindBuffersBase)(target, first, count, buffers);
}

extern void* __blue_glCore_glBindBuffersRange;
void APIENTRY bluegl_glBindBuffersRange (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes) {
    typedef void (APIENTRYP PFN_glBindBuffersRange) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
    return ((PFN_glBindBuffersRange)__blue_glCore_glBindBuffersRange)(target, first, count, buffers, offsets, sizes);
}

extern void* __blue_glCore_glBindTextures;
void APIENTRY bluegl_glBindTextures (GLuint first, GLsizei count, const GLuint *textures) {
    typedef void (APIENTRYP PFN_glBindTextures) (GLuint first, GLsizei count, const GLuint *textures);
    return ((PFN_glBindTextures)__blue_glCore_glBindTextures)(first, count, textures);
}

extern void* __blue_glCore_glBindSamplers;
void APIENTRY bluegl_glBindSamplers (GLuint first, GLsizei count, const GLuint *samplers) {
    typedef void (APIENTRYP PFN_glBindSamplers) (GLuint first, GLsizei count, const GLuint *samplers);
    return ((PFN_glBindSamplers)__blue_glCore_glBindSamplers)(first, count, samplers);
}

extern void* __blue_glCore_glBindImageTextures;
void APIENTRY bluegl_glBindImageTextures (GLuint first, GLsizei count, const GLuint *textures) {
    typedef void (APIENTRYP PFN_glBindImageTextures) (GLuint first, GLsizei count, const GLuint *textures);
    return ((PFN_glBindImageTextures)__blue_glCore_glBindImageTextures)(first, count, textures);
}

extern void* __blue_glCore_glBindVertexBuffers;
void APIENTRY bluegl_glBindVertexBuffers (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) {
    typedef void (APIENTRYP PFN_glBindVertexBuffers) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
    return ((PFN_glBindVertexBuffers)__blue_glCore_glBindVertexBuffers)(first, count, buffers, offsets, strides);
}

extern void* __blue_glCore_glClipControl;
void APIENTRY bluegl_glClipControl (GLenum origin, GLenum depth) {
    typedef void (APIENTRYP PFN_glClipControl) (GLenum origin, GLenum depth);
    return ((PFN_glClipControl)__blue_glCore_glClipControl)(origin, depth);
}

extern void* __blue_glCore_glCreateTransformFeedbacks;
void APIENTRY bluegl_glCreateTransformFeedbacks (GLsizei n, GLuint *ids) {
    typedef void (APIENTRYP PFN_glCreateTransformFeedbacks) (GLsizei n, GLuint *ids);
    return ((PFN_glCreateTransformFeedbacks)__blue_glCore_glCreateTransformFeedbacks)(n, ids);
}

extern void* __blue_glCore_glTransformFeedbackBufferBase;
void APIENTRY bluegl_glTransformFeedbackBufferBase (GLuint xfb, GLuint index, GLuint buffer) {
    typedef void (APIENTRYP PFN_glTransformFeedbackBufferBase) (GLuint xfb, GLuint index, GLuint buffer);
    return ((PFN_glTransformFeedbackBufferBase)__blue_glCore_glTransformFeedbackBufferBase)(xfb, index, buffer);
}

extern void* __blue_glCore_glTransformFeedbackBufferRange;
void APIENTRY bluegl_glTransformFeedbackBufferRange (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glTransformFeedbackBufferRange) (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    return ((PFN_glTransformFeedbackBufferRange)__blue_glCore_glTransformFeedbackBufferRange)(xfb, index, buffer, offset, size);
}

extern void* __blue_glCore_glGetTransformFeedbackiv;
void APIENTRY bluegl_glGetTransformFeedbackiv (GLuint xfb, GLenum pname, GLint *param) {
    typedef void (APIENTRYP PFN_glGetTransformFeedbackiv) (GLuint xfb, GLenum pname, GLint *param);
    return ((PFN_glGetTransformFeedbackiv)__blue_glCore_glGetTransformFeedbackiv)(xfb, pname, param);
}

extern void* __blue_glCore_glGetTransformFeedbacki_v;
void APIENTRY bluegl_glGetTransformFeedbacki_v (GLuint xfb, GLenum pname, GLuint index, GLint *param) {
    typedef void (APIENTRYP PFN_glGetTransformFeedbacki_v) (GLuint xfb, GLenum pname, GLuint index, GLint *param);
    return ((PFN_glGetTransformFeedbacki_v)__blue_glCore_glGetTransformFeedbacki_v)(xfb, pname, index, param);
}

extern void* __blue_glCore_glGetTransformFeedbacki64_v;
void APIENTRY bluegl_glGetTransformFeedbacki64_v (GLuint xfb, GLenum pname, GLuint index, GLint64 *param) {
    typedef void (APIENTRYP PFN_glGetTransformFeedbacki64_v) (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
    return ((PFN_glGetTransformFeedbacki64_v)__blue_glCore_glGetTransformFeedbacki64_v)(xfb, pname, index, param);
}

extern void* __blue_glCore_glCreateBuffers;
void APIENTRY bluegl_glCreateBuffers (GLsizei n, GLuint *buffers) {
    typedef void (APIENTRYP PFN_glCreateBuffers) (GLsizei n, GLuint *buffers);
    return ((PFN_glCreateBuffers)__blue_glCore_glCreateBuffers)(n, buffers);
}

extern void* __blue_glCore_glNamedBufferStorage;
void APIENTRY bluegl_glNamedBufferStorage (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) {
    typedef void (APIENTRYP PFN_glNamedBufferStorage) (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
    return ((PFN_glNamedBufferStorage)__blue_glCore_glNamedBufferStorage)(buffer, size, data, flags);
}

extern void* __blue_glCore_glNamedBufferData;
void APIENTRY bluegl_glNamedBufferData (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) {
    typedef void (APIENTRYP PFN_glNamedBufferData) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
    return ((PFN_glNamedBufferData)__blue_glCore_glNamedBufferData)(buffer, size, data, usage);
}

extern void* __blue_glCore_glNamedBufferSubData;
void APIENTRY bluegl_glNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) {
    typedef void (APIENTRYP PFN_glNamedBufferSubData) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
    return ((PFN_glNamedBufferSubData)__blue_glCore_glNamedBufferSubData)(buffer, offset, size, data);
}

extern void* __blue_glCore_glCopyNamedBufferSubData;
void APIENTRY bluegl_glCopyNamedBufferSubData (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glCopyNamedBufferSubData) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    return ((PFN_glCopyNamedBufferSubData)__blue_glCore_glCopyNamedBufferSubData)(readBuffer, writeBuffer, readOffset, writeOffset, size);
}

extern void* __blue_glCore_glClearNamedBufferData;
void APIENTRY bluegl_glClearNamedBufferData (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glClearNamedBufferData) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
    return ((PFN_glClearNamedBufferData)__blue_glCore_glClearNamedBufferData)(buffer, internalformat, format, type, data);
}

extern void* __blue_glCore_glClearNamedBufferSubData;
void APIENTRY bluegl_glClearNamedBufferSubData (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glClearNamedBufferSubData) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
    return ((PFN_glClearNamedBufferSubData)__blue_glCore_glClearNamedBufferSubData)(buffer, internalformat, offset, size, format, type, data);
}

extern void* __blue_glCore_glMapNamedBuffer;
void *APIENTRY bluegl_glMapNamedBuffer (GLuint buffer, GLenum access) {
    typedef void *(APIENTRYP PFN_glMapNamedBuffer) (GLuint buffer, GLenum access);
    return ((PFN_glMapNamedBuffer)__blue_glCore_glMapNamedBuffer)(buffer, access);
}

extern void* __blue_glCore_glMapNamedBufferRange;
void *APIENTRY bluegl_glMapNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    typedef void *(APIENTRYP PFN_glMapNamedBufferRange) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
    return ((PFN_glMapNamedBufferRange)__blue_glCore_glMapNamedBufferRange)(buffer, offset, length, access);
}

extern void* __blue_glCore_glUnmapNamedBuffer;
GLboolean APIENTRY bluegl_glUnmapNamedBuffer (GLuint buffer) {
    typedef GLboolean (APIENTRYP PFN_glUnmapNamedBuffer) (GLuint buffer);
    return ((PFN_glUnmapNamedBuffer)__blue_glCore_glUnmapNamedBuffer)(buffer);
}

extern void* __blue_glCore_glFlushMappedNamedBufferRange;
void APIENTRY bluegl_glFlushMappedNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length) {
    typedef void (APIENTRYP PFN_glFlushMappedNamedBufferRange) (GLuint buffer, GLintptr offset, GLsizeiptr length);
    return ((PFN_glFlushMappedNamedBufferRange)__blue_glCore_glFlushMappedNamedBufferRange)(buffer, offset, length);
}

extern void* __blue_glCore_glGetNamedBufferParameteriv;
void APIENTRY bluegl_glGetNamedBufferParameteriv (GLuint buffer, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedBufferParameteriv) (GLuint buffer, GLenum pname, GLint *params);
    return ((PFN_glGetNamedBufferParameteriv)__blue_glCore_glGetNamedBufferParameteriv)(buffer, pname, params);
}

extern void* __blue_glCore_glGetNamedBufferParameteri64v;
void APIENTRY bluegl_glGetNamedBufferParameteri64v (GLuint buffer, GLenum pname, GLint64 *params) {
    typedef void (APIENTRYP PFN_glGetNamedBufferParameteri64v) (GLuint buffer, GLenum pname, GLint64 *params);
    return ((PFN_glGetNamedBufferParameteri64v)__blue_glCore_glGetNamedBufferParameteri64v)(buffer, pname, params);
}

extern void* __blue_glCore_glGetNamedBufferPointerv;
void APIENTRY bluegl_glGetNamedBufferPointerv (GLuint buffer, GLenum pname, void **params) {
    typedef void (APIENTRYP PFN_glGetNamedBufferPointerv) (GLuint buffer, GLenum pname, void **params);
    return ((PFN_glGetNamedBufferPointerv)__blue_glCore_glGetNamedBufferPointerv)(buffer, pname, params);
}

extern void* __blue_glCore_glGetNamedBufferSubData;
void APIENTRY bluegl_glGetNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) {
    typedef void (APIENTRYP PFN_glGetNamedBufferSubData) (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
    return ((PFN_glGetNamedBufferSubData)__blue_glCore_glGetNamedBufferSubData)(buffer, offset, size, data);
}

extern void* __blue_glCore_glCreateFramebuffers;
void APIENTRY bluegl_glCreateFramebuffers (GLsizei n, GLuint *framebuffers) {
    typedef void (APIENTRYP PFN_glCreateFramebuffers) (GLsizei n, GLuint *framebuffers);
    return ((PFN_glCreateFramebuffers)__blue_glCore_glCreateFramebuffers)(n, framebuffers);
}

extern void* __blue_glCore_glNamedFramebufferRenderbuffer;
void APIENTRY bluegl_glNamedFramebufferRenderbuffer (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    typedef void (APIENTRYP PFN_glNamedFramebufferRenderbuffer) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    return ((PFN_glNamedFramebufferRenderbuffer)__blue_glCore_glNamedFramebufferRenderbuffer)(framebuffer, attachment, renderbuffertarget, renderbuffer);
}

extern void* __blue_glCore_glNamedFramebufferParameteri;
void APIENTRY bluegl_glNamedFramebufferParameteri (GLuint framebuffer, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glNamedFramebufferParameteri) (GLuint framebuffer, GLenum pname, GLint param);
    return ((PFN_glNamedFramebufferParameteri)__blue_glCore_glNamedFramebufferParameteri)(framebuffer, pname, param);
}

extern void* __blue_glCore_glNamedFramebufferTexture;
void APIENTRY bluegl_glNamedFramebufferTexture (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glNamedFramebufferTexture) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
    return ((PFN_glNamedFramebufferTexture)__blue_glCore_glNamedFramebufferTexture)(framebuffer, attachment, texture, level);
}

extern void* __blue_glCore_glNamedFramebufferTextureLayer;
void APIENTRY bluegl_glNamedFramebufferTextureLayer (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    typedef void (APIENTRYP PFN_glNamedFramebufferTextureLayer) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
    return ((PFN_glNamedFramebufferTextureLayer)__blue_glCore_glNamedFramebufferTextureLayer)(framebuffer, attachment, texture, level, layer);
}

extern void* __blue_glCore_glNamedFramebufferDrawBuffer;
void APIENTRY bluegl_glNamedFramebufferDrawBuffer (GLuint framebuffer, GLenum buf) {
    typedef void (APIENTRYP PFN_glNamedFramebufferDrawBuffer) (GLuint framebuffer, GLenum buf);
    return ((PFN_glNamedFramebufferDrawBuffer)__blue_glCore_glNamedFramebufferDrawBuffer)(framebuffer, buf);
}

extern void* __blue_glCore_glNamedFramebufferDrawBuffers;
void APIENTRY bluegl_glNamedFramebufferDrawBuffers (GLuint framebuffer, GLsizei n, const GLenum *bufs) {
    typedef void (APIENTRYP PFN_glNamedFramebufferDrawBuffers) (GLuint framebuffer, GLsizei n, const GLenum *bufs);
    return ((PFN_glNamedFramebufferDrawBuffers)__blue_glCore_glNamedFramebufferDrawBuffers)(framebuffer, n, bufs);
}

extern void* __blue_glCore_glNamedFramebufferReadBuffer;
void APIENTRY bluegl_glNamedFramebufferReadBuffer (GLuint framebuffer, GLenum src) {
    typedef void (APIENTRYP PFN_glNamedFramebufferReadBuffer) (GLuint framebuffer, GLenum src);
    return ((PFN_glNamedFramebufferReadBuffer)__blue_glCore_glNamedFramebufferReadBuffer)(framebuffer, src);
}

extern void* __blue_glCore_glInvalidateNamedFramebufferData;
void APIENTRY bluegl_glInvalidateNamedFramebufferData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments) {
    typedef void (APIENTRYP PFN_glInvalidateNamedFramebufferData) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
    return ((PFN_glInvalidateNamedFramebufferData)__blue_glCore_glInvalidateNamedFramebufferData)(framebuffer, numAttachments, attachments);
}

extern void* __blue_glCore_glInvalidateNamedFramebufferSubData;
void APIENTRY bluegl_glInvalidateNamedFramebufferSubData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glInvalidateNamedFramebufferSubData) (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glInvalidateNamedFramebufferSubData)__blue_glCore_glInvalidateNamedFramebufferSubData)(framebuffer, numAttachments, attachments, x, y, width, height);
}

extern void* __blue_glCore_glClearNamedFramebufferiv;
void APIENTRY bluegl_glClearNamedFramebufferiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value) {
    typedef void (APIENTRYP PFN_glClearNamedFramebufferiv) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
    return ((PFN_glClearNamedFramebufferiv)__blue_glCore_glClearNamedFramebufferiv)(framebuffer, buffer, drawbuffer, value);
}

extern void* __blue_glCore_glClearNamedFramebufferuiv;
void APIENTRY bluegl_glClearNamedFramebufferuiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value) {
    typedef void (APIENTRYP PFN_glClearNamedFramebufferuiv) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
    return ((PFN_glClearNamedFramebufferuiv)__blue_glCore_glClearNamedFramebufferuiv)(framebuffer, buffer, drawbuffer, value);
}

extern void* __blue_glCore_glClearNamedFramebufferfv;
void APIENTRY bluegl_glClearNamedFramebufferfv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glClearNamedFramebufferfv) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
    return ((PFN_glClearNamedFramebufferfv)__blue_glCore_glClearNamedFramebufferfv)(framebuffer, buffer, drawbuffer, value);
}

extern void* __blue_glCore_glClearNamedFramebufferfi;
void APIENTRY bluegl_glClearNamedFramebufferfi (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
    typedef void (APIENTRYP PFN_glClearNamedFramebufferfi) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
    return ((PFN_glClearNamedFramebufferfi)__blue_glCore_glClearNamedFramebufferfi)(framebuffer, buffer, drawbuffer, depth, stencil);
}

extern void* __blue_glCore_glBlitNamedFramebuffer;
void APIENTRY bluegl_glBlitNamedFramebuffer (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    typedef void (APIENTRYP PFN_glBlitNamedFramebuffer) (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    return ((PFN_glBlitNamedFramebuffer)__blue_glCore_glBlitNamedFramebuffer)(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

extern void* __blue_glCore_glCheckNamedFramebufferStatus;
GLenum APIENTRY bluegl_glCheckNamedFramebufferStatus (GLuint framebuffer, GLenum target) {
    typedef GLenum (APIENTRYP PFN_glCheckNamedFramebufferStatus) (GLuint framebuffer, GLenum target);
    return ((PFN_glCheckNamedFramebufferStatus)__blue_glCore_glCheckNamedFramebufferStatus)(framebuffer, target);
}

extern void* __blue_glCore_glGetNamedFramebufferParameteriv;
void APIENTRY bluegl_glGetNamedFramebufferParameteriv (GLuint framebuffer, GLenum pname, GLint *param) {
    typedef void (APIENTRYP PFN_glGetNamedFramebufferParameteriv) (GLuint framebuffer, GLenum pname, GLint *param);
    return ((PFN_glGetNamedFramebufferParameteriv)__blue_glCore_glGetNamedFramebufferParameteriv)(framebuffer, pname, param);
}

extern void* __blue_glCore_glGetNamedFramebufferAttachmentParameteriv;
void APIENTRY bluegl_glGetNamedFramebufferAttachmentParameteriv (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedFramebufferAttachmentParameteriv) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
    return ((PFN_glGetNamedFramebufferAttachmentParameteriv)__blue_glCore_glGetNamedFramebufferAttachmentParameteriv)(framebuffer, attachment, pname, params);
}

extern void* __blue_glCore_glCreateRenderbuffers;
void APIENTRY bluegl_glCreateRenderbuffers (GLsizei n, GLuint *renderbuffers) {
    typedef void (APIENTRYP PFN_glCreateRenderbuffers) (GLsizei n, GLuint *renderbuffers);
    return ((PFN_glCreateRenderbuffers)__blue_glCore_glCreateRenderbuffers)(n, renderbuffers);
}

extern void* __blue_glCore_glNamedRenderbufferStorage;
void APIENTRY bluegl_glNamedRenderbufferStorage (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glNamedRenderbufferStorage) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glNamedRenderbufferStorage)__blue_glCore_glNamedRenderbufferStorage)(renderbuffer, internalformat, width, height);
}

extern void* __blue_glCore_glNamedRenderbufferStorageMultisample;
void APIENTRY bluegl_glNamedRenderbufferStorageMultisample (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glNamedRenderbufferStorageMultisample) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glNamedRenderbufferStorageMultisample)__blue_glCore_glNamedRenderbufferStorageMultisample)(renderbuffer, samples, internalformat, width, height);
}

extern void* __blue_glCore_glGetNamedRenderbufferParameteriv;
void APIENTRY bluegl_glGetNamedRenderbufferParameteriv (GLuint renderbuffer, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedRenderbufferParameteriv) (GLuint renderbuffer, GLenum pname, GLint *params);
    return ((PFN_glGetNamedRenderbufferParameteriv)__blue_glCore_glGetNamedRenderbufferParameteriv)(renderbuffer, pname, params);
}

extern void* __blue_glCore_glCreateTextures;
void APIENTRY bluegl_glCreateTextures (GLenum target, GLsizei n, GLuint *textures) {
    typedef void (APIENTRYP PFN_glCreateTextures) (GLenum target, GLsizei n, GLuint *textures);
    return ((PFN_glCreateTextures)__blue_glCore_glCreateTextures)(target, n, textures);
}

extern void* __blue_glCore_glTextureBuffer;
void APIENTRY bluegl_glTextureBuffer (GLuint texture, GLenum internalformat, GLuint buffer) {
    typedef void (APIENTRYP PFN_glTextureBuffer) (GLuint texture, GLenum internalformat, GLuint buffer);
    return ((PFN_glTextureBuffer)__blue_glCore_glTextureBuffer)(texture, internalformat, buffer);
}

extern void* __blue_glCore_glTextureBufferRange;
void APIENTRY bluegl_glTextureBufferRange (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glTextureBufferRange) (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    return ((PFN_glTextureBufferRange)__blue_glCore_glTextureBufferRange)(texture, internalformat, buffer, offset, size);
}

extern void* __blue_glCore_glTextureStorage1D;
void APIENTRY bluegl_glTextureStorage1D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) {
    typedef void (APIENTRYP PFN_glTextureStorage1D) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
    return ((PFN_glTextureStorage1D)__blue_glCore_glTextureStorage1D)(texture, levels, internalformat, width);
}

extern void* __blue_glCore_glTextureStorage2D;
void APIENTRY bluegl_glTextureStorage2D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glTextureStorage2D) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glTextureStorage2D)__blue_glCore_glTextureStorage2D)(texture, levels, internalformat, width, height);
}

extern void* __blue_glCore_glTextureStorage3D;
void APIENTRY bluegl_glTextureStorage3D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
    typedef void (APIENTRYP PFN_glTextureStorage3D) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    return ((PFN_glTextureStorage3D)__blue_glCore_glTextureStorage3D)(texture, levels, internalformat, width, height, depth);
}

extern void* __blue_glCore_glTextureStorage2DMultisample;
void APIENTRY bluegl_glTextureStorage2DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    typedef void (APIENTRYP PFN_glTextureStorage2DMultisample) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    return ((PFN_glTextureStorage2DMultisample)__blue_glCore_glTextureStorage2DMultisample)(texture, samples, internalformat, width, height, fixedsamplelocations);
}

extern void* __blue_glCore_glTextureStorage3DMultisample;
void APIENTRY bluegl_glTextureStorage3DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    typedef void (APIENTRYP PFN_glTextureStorage3DMultisample) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    return ((PFN_glTextureStorage3DMultisample)__blue_glCore_glTextureStorage3DMultisample)(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}

extern void* __blue_glCore_glTextureSubImage1D;
void APIENTRY bluegl_glTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTextureSubImage1D) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTextureSubImage1D)__blue_glCore_glTextureSubImage1D)(texture, level, xoffset, width, format, type, pixels);
}

extern void* __blue_glCore_glTextureSubImage2D;
void APIENTRY bluegl_glTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTextureSubImage2D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTextureSubImage2D)__blue_glCore_glTextureSubImage2D)(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}

extern void* __blue_glCore_glTextureSubImage3D;
void APIENTRY bluegl_glTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTextureSubImage3D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTextureSubImage3D)__blue_glCore_glTextureSubImage3D)(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

extern void* __blue_glCore_glCompressedTextureSubImage1D;
void APIENTRY bluegl_glCompressedTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTextureSubImage1D) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTextureSubImage1D)__blue_glCore_glCompressedTextureSubImage1D)(texture, level, xoffset, width, format, imageSize, data);
}

extern void* __blue_glCore_glCompressedTextureSubImage2D;
void APIENTRY bluegl_glCompressedTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTextureSubImage2D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTextureSubImage2D)__blue_glCore_glCompressedTextureSubImage2D)(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}

extern void* __blue_glCore_glCompressedTextureSubImage3D;
void APIENTRY bluegl_glCompressedTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTextureSubImage3D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTextureSubImage3D)__blue_glCore_glCompressedTextureSubImage3D)(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

extern void* __blue_glCore_glCopyTextureSubImage1D;
void APIENTRY bluegl_glCopyTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyTextureSubImage1D) (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyTextureSubImage1D)__blue_glCore_glCopyTextureSubImage1D)(texture, level, xoffset, x, y, width);
}

extern void* __blue_glCore_glCopyTextureSubImage2D;
void APIENTRY bluegl_glCopyTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyTextureSubImage2D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyTextureSubImage2D)__blue_glCore_glCopyTextureSubImage2D)(texture, level, xoffset, yoffset, x, y, width, height);
}

extern void* __blue_glCore_glCopyTextureSubImage3D;
void APIENTRY bluegl_glCopyTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyTextureSubImage3D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyTextureSubImage3D)__blue_glCore_glCopyTextureSubImage3D)(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

extern void* __blue_glCore_glTextureParameterf;
void APIENTRY bluegl_glTextureParameterf (GLuint texture, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glTextureParameterf) (GLuint texture, GLenum pname, GLfloat param);
    return ((PFN_glTextureParameterf)__blue_glCore_glTextureParameterf)(texture, pname, param);
}

extern void* __blue_glCore_glTextureParameterfv;
void APIENTRY bluegl_glTextureParameterfv (GLuint texture, GLenum pname, const GLfloat *param) {
    typedef void (APIENTRYP PFN_glTextureParameterfv) (GLuint texture, GLenum pname, const GLfloat *param);
    return ((PFN_glTextureParameterfv)__blue_glCore_glTextureParameterfv)(texture, pname, param);
}

extern void* __blue_glCore_glTextureParameteri;
void APIENTRY bluegl_glTextureParameteri (GLuint texture, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glTextureParameteri) (GLuint texture, GLenum pname, GLint param);
    return ((PFN_glTextureParameteri)__blue_glCore_glTextureParameteri)(texture, pname, param);
}

extern void* __blue_glCore_glTextureParameterIiv;
void APIENTRY bluegl_glTextureParameterIiv (GLuint texture, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glTextureParameterIiv) (GLuint texture, GLenum pname, const GLint *params);
    return ((PFN_glTextureParameterIiv)__blue_glCore_glTextureParameterIiv)(texture, pname, params);
}

extern void* __blue_glCore_glTextureParameterIuiv;
void APIENTRY bluegl_glTextureParameterIuiv (GLuint texture, GLenum pname, const GLuint *params) {
    typedef void (APIENTRYP PFN_glTextureParameterIuiv) (GLuint texture, GLenum pname, const GLuint *params);
    return ((PFN_glTextureParameterIuiv)__blue_glCore_glTextureParameterIuiv)(texture, pname, params);
}

extern void* __blue_glCore_glTextureParameteriv;
void APIENTRY bluegl_glTextureParameteriv (GLuint texture, GLenum pname, const GLint *param) {
    typedef void (APIENTRYP PFN_glTextureParameteriv) (GLuint texture, GLenum pname, const GLint *param);
    return ((PFN_glTextureParameteriv)__blue_glCore_glTextureParameteriv)(texture, pname, param);
}

extern void* __blue_glCore_glGenerateTextureMipmap;
void APIENTRY bluegl_glGenerateTextureMipmap (GLuint texture) {
    typedef void (APIENTRYP PFN_glGenerateTextureMipmap) (GLuint texture);
    return ((PFN_glGenerateTextureMipmap)__blue_glCore_glGenerateTextureMipmap)(texture);
}

extern void* __blue_glCore_glBindTextureUnit;
void APIENTRY bluegl_glBindTextureUnit (GLuint unit, GLuint texture) {
    typedef void (APIENTRYP PFN_glBindTextureUnit) (GLuint unit, GLuint texture);
    return ((PFN_glBindTextureUnit)__blue_glCore_glBindTextureUnit)(unit, texture);
}

extern void* __blue_glCore_glGetTextureImage;
void APIENTRY bluegl_glGetTextureImage (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) {
    typedef void (APIENTRYP PFN_glGetTextureImage) (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
    return ((PFN_glGetTextureImage)__blue_glCore_glGetTextureImage)(texture, level, format, type, bufSize, pixels);
}

extern void* __blue_glCore_glGetCompressedTextureImage;
void APIENTRY bluegl_glGetCompressedTextureImage (GLuint texture, GLint level, GLsizei bufSize, void *pixels) {
    typedef void (APIENTRYP PFN_glGetCompressedTextureImage) (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
    return ((PFN_glGetCompressedTextureImage)__blue_glCore_glGetCompressedTextureImage)(texture, level, bufSize, pixels);
}

extern void* __blue_glCore_glGetTextureLevelParameterfv;
void APIENTRY bluegl_glGetTextureLevelParameterfv (GLuint texture, GLint level, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetTextureLevelParameterfv) (GLuint texture, GLint level, GLenum pname, GLfloat *params);
    return ((PFN_glGetTextureLevelParameterfv)__blue_glCore_glGetTextureLevelParameterfv)(texture, level, pname, params);
}

extern void* __blue_glCore_glGetTextureLevelParameteriv;
void APIENTRY bluegl_glGetTextureLevelParameteriv (GLuint texture, GLint level, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTextureLevelParameteriv) (GLuint texture, GLint level, GLenum pname, GLint *params);
    return ((PFN_glGetTextureLevelParameteriv)__blue_glCore_glGetTextureLevelParameteriv)(texture, level, pname, params);
}

extern void* __blue_glCore_glGetTextureParameterfv;
void APIENTRY bluegl_glGetTextureParameterfv (GLuint texture, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetTextureParameterfv) (GLuint texture, GLenum pname, GLfloat *params);
    return ((PFN_glGetTextureParameterfv)__blue_glCore_glGetTextureParameterfv)(texture, pname, params);
}

extern void* __blue_glCore_glGetTextureParameterIiv;
void APIENTRY bluegl_glGetTextureParameterIiv (GLuint texture, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTextureParameterIiv) (GLuint texture, GLenum pname, GLint *params);
    return ((PFN_glGetTextureParameterIiv)__blue_glCore_glGetTextureParameterIiv)(texture, pname, params);
}

extern void* __blue_glCore_glGetTextureParameterIuiv;
void APIENTRY bluegl_glGetTextureParameterIuiv (GLuint texture, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetTextureParameterIuiv) (GLuint texture, GLenum pname, GLuint *params);
    return ((PFN_glGetTextureParameterIuiv)__blue_glCore_glGetTextureParameterIuiv)(texture, pname, params);
}

extern void* __blue_glCore_glGetTextureParameteriv;
void APIENTRY bluegl_glGetTextureParameteriv (GLuint texture, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTextureParameteriv) (GLuint texture, GLenum pname, GLint *params);
    return ((PFN_glGetTextureParameteriv)__blue_glCore_glGetTextureParameteriv)(texture, pname, params);
}

extern void* __blue_glCore_glCreateVertexArrays;
void APIENTRY bluegl_glCreateVertexArrays (GLsizei n, GLuint *arrays) {
    typedef void (APIENTRYP PFN_glCreateVertexArrays) (GLsizei n, GLuint *arrays);
    return ((PFN_glCreateVertexArrays)__blue_glCore_glCreateVertexArrays)(n, arrays);
}

extern void* __blue_glCore_glDisableVertexArrayAttrib;
void APIENTRY bluegl_glDisableVertexArrayAttrib (GLuint vaobj, GLuint index) {
    typedef void (APIENTRYP PFN_glDisableVertexArrayAttrib) (GLuint vaobj, GLuint index);
    return ((PFN_glDisableVertexArrayAttrib)__blue_glCore_glDisableVertexArrayAttrib)(vaobj, index);
}

extern void* __blue_glCore_glEnableVertexArrayAttrib;
void APIENTRY bluegl_glEnableVertexArrayAttrib (GLuint vaobj, GLuint index) {
    typedef void (APIENTRYP PFN_glEnableVertexArrayAttrib) (GLuint vaobj, GLuint index);
    return ((PFN_glEnableVertexArrayAttrib)__blue_glCore_glEnableVertexArrayAttrib)(vaobj, index);
}

extern void* __blue_glCore_glVertexArrayElementBuffer;
void APIENTRY bluegl_glVertexArrayElementBuffer (GLuint vaobj, GLuint buffer) {
    typedef void (APIENTRYP PFN_glVertexArrayElementBuffer) (GLuint vaobj, GLuint buffer);
    return ((PFN_glVertexArrayElementBuffer)__blue_glCore_glVertexArrayElementBuffer)(vaobj, buffer);
}

extern void* __blue_glCore_glVertexArrayVertexBuffer;
void APIENTRY bluegl_glVertexArrayVertexBuffer (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexBuffer) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    return ((PFN_glVertexArrayVertexBuffer)__blue_glCore_glVertexArrayVertexBuffer)(vaobj, bindingindex, buffer, offset, stride);
}

extern void* __blue_glCore_glVertexArrayVertexBuffers;
void APIENTRY bluegl_glVertexArrayVertexBuffers (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexBuffers) (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
    return ((PFN_glVertexArrayVertexBuffers)__blue_glCore_glVertexArrayVertexBuffers)(vaobj, first, count, buffers, offsets, strides);
}

extern void* __blue_glCore_glVertexArrayAttribBinding;
void APIENTRY bluegl_glVertexArrayAttribBinding (GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
    typedef void (APIENTRYP PFN_glVertexArrayAttribBinding) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
    return ((PFN_glVertexArrayAttribBinding)__blue_glCore_glVertexArrayAttribBinding)(vaobj, attribindex, bindingindex);
}

extern void* __blue_glCore_glVertexArrayAttribFormat;
void APIENTRY bluegl_glVertexArrayAttribFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
    typedef void (APIENTRYP PFN_glVertexArrayAttribFormat) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    return ((PFN_glVertexArrayAttribFormat)__blue_glCore_glVertexArrayAttribFormat)(vaobj, attribindex, size, type, normalized, relativeoffset);
}

extern void* __blue_glCore_glVertexArrayAttribIFormat;
void APIENTRY bluegl_glVertexArrayAttribIFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    typedef void (APIENTRYP PFN_glVertexArrayAttribIFormat) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    return ((PFN_glVertexArrayAttribIFormat)__blue_glCore_glVertexArrayAttribIFormat)(vaobj, attribindex, size, type, relativeoffset);
}

extern void* __blue_glCore_glVertexArrayAttribLFormat;
void APIENTRY bluegl_glVertexArrayAttribLFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    typedef void (APIENTRYP PFN_glVertexArrayAttribLFormat) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    return ((PFN_glVertexArrayAttribLFormat)__blue_glCore_glVertexArrayAttribLFormat)(vaobj, attribindex, size, type, relativeoffset);
}

extern void* __blue_glCore_glVertexArrayBindingDivisor;
void APIENTRY bluegl_glVertexArrayBindingDivisor (GLuint vaobj, GLuint bindingindex, GLuint divisor) {
    typedef void (APIENTRYP PFN_glVertexArrayBindingDivisor) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
    return ((PFN_glVertexArrayBindingDivisor)__blue_glCore_glVertexArrayBindingDivisor)(vaobj, bindingindex, divisor);
}

extern void* __blue_glCore_glGetVertexArrayiv;
void APIENTRY bluegl_glGetVertexArrayiv (GLuint vaobj, GLenum pname, GLint *param) {
    typedef void (APIENTRYP PFN_glGetVertexArrayiv) (GLuint vaobj, GLenum pname, GLint *param);
    return ((PFN_glGetVertexArrayiv)__blue_glCore_glGetVertexArrayiv)(vaobj, pname, param);
}

extern void* __blue_glCore_glGetVertexArrayIndexediv;
void APIENTRY bluegl_glGetVertexArrayIndexediv (GLuint vaobj, GLuint index, GLenum pname, GLint *param) {
    typedef void (APIENTRYP PFN_glGetVertexArrayIndexediv) (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
    return ((PFN_glGetVertexArrayIndexediv)__blue_glCore_glGetVertexArrayIndexediv)(vaobj, index, pname, param);
}

extern void* __blue_glCore_glGetVertexArrayIndexed64iv;
void APIENTRY bluegl_glGetVertexArrayIndexed64iv (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param) {
    typedef void (APIENTRYP PFN_glGetVertexArrayIndexed64iv) (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
    return ((PFN_glGetVertexArrayIndexed64iv)__blue_glCore_glGetVertexArrayIndexed64iv)(vaobj, index, pname, param);
}

extern void* __blue_glCore_glCreateSamplers;
void APIENTRY bluegl_glCreateSamplers (GLsizei n, GLuint *samplers) {
    typedef void (APIENTRYP PFN_glCreateSamplers) (GLsizei n, GLuint *samplers);
    return ((PFN_glCreateSamplers)__blue_glCore_glCreateSamplers)(n, samplers);
}

extern void* __blue_glCore_glCreateProgramPipelines;
void APIENTRY bluegl_glCreateProgramPipelines (GLsizei n, GLuint *pipelines) {
    typedef void (APIENTRYP PFN_glCreateProgramPipelines) (GLsizei n, GLuint *pipelines);
    return ((PFN_glCreateProgramPipelines)__blue_glCore_glCreateProgramPipelines)(n, pipelines);
}

extern void* __blue_glCore_glCreateQueries;
void APIENTRY bluegl_glCreateQueries (GLenum target, GLsizei n, GLuint *ids) {
    typedef void (APIENTRYP PFN_glCreateQueries) (GLenum target, GLsizei n, GLuint *ids);
    return ((PFN_glCreateQueries)__blue_glCore_glCreateQueries)(target, n, ids);
}

extern void* __blue_glCore_glGetQueryBufferObjecti64v;
void APIENTRY bluegl_glGetQueryBufferObjecti64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
    typedef void (APIENTRYP PFN_glGetQueryBufferObjecti64v) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    return ((PFN_glGetQueryBufferObjecti64v)__blue_glCore_glGetQueryBufferObjecti64v)(id, buffer, pname, offset);
}

extern void* __blue_glCore_glGetQueryBufferObjectiv;
void APIENTRY bluegl_glGetQueryBufferObjectiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
    typedef void (APIENTRYP PFN_glGetQueryBufferObjectiv) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    return ((PFN_glGetQueryBufferObjectiv)__blue_glCore_glGetQueryBufferObjectiv)(id, buffer, pname, offset);
}

extern void* __blue_glCore_glGetQueryBufferObjectui64v;
void APIENTRY bluegl_glGetQueryBufferObjectui64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
    typedef void (APIENTRYP PFN_glGetQueryBufferObjectui64v) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    return ((PFN_glGetQueryBufferObjectui64v)__blue_glCore_glGetQueryBufferObjectui64v)(id, buffer, pname, offset);
}

extern void* __blue_glCore_glGetQueryBufferObjectuiv;
void APIENTRY bluegl_glGetQueryBufferObjectuiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
    typedef void (APIENTRYP PFN_glGetQueryBufferObjectuiv) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
    return ((PFN_glGetQueryBufferObjectuiv)__blue_glCore_glGetQueryBufferObjectuiv)(id, buffer, pname, offset);
}

extern void* __blue_glCore_glMemoryBarrierByRegion;
void APIENTRY bluegl_glMemoryBarrierByRegion (GLbitfield barriers) {
    typedef void (APIENTRYP PFN_glMemoryBarrierByRegion) (GLbitfield barriers);
    return ((PFN_glMemoryBarrierByRegion)__blue_glCore_glMemoryBarrierByRegion)(barriers);
}

extern void* __blue_glCore_glGetTextureSubImage;
void APIENTRY bluegl_glGetTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels) {
    typedef void (APIENTRYP PFN_glGetTextureSubImage) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
    return ((PFN_glGetTextureSubImage)__blue_glCore_glGetTextureSubImage)(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}

extern void* __blue_glCore_glGetCompressedTextureSubImage;
void APIENTRY bluegl_glGetCompressedTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels) {
    typedef void (APIENTRYP PFN_glGetCompressedTextureSubImage) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
    return ((PFN_glGetCompressedTextureSubImage)__blue_glCore_glGetCompressedTextureSubImage)(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

extern void* __blue_glCore_glGetGraphicsResetStatus;
GLenum APIENTRY bluegl_glGetGraphicsResetStatus (void) {
    typedef GLenum (APIENTRYP PFN_glGetGraphicsResetStatus) (void);
    return ((PFN_glGetGraphicsResetStatus)__blue_glCore_glGetGraphicsResetStatus)();
}

extern void* __blue_glCore_glGetnCompressedTexImage;
void APIENTRY bluegl_glGetnCompressedTexImage (GLenum target, GLint lod, GLsizei bufSize, void *pixels) {
    typedef void (APIENTRYP PFN_glGetnCompressedTexImage) (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
    return ((PFN_glGetnCompressedTexImage)__blue_glCore_glGetnCompressedTexImage)(target, lod, bufSize, pixels);
}

extern void* __blue_glCore_glGetnTexImage;
void APIENTRY bluegl_glGetnTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) {
    typedef void (APIENTRYP PFN_glGetnTexImage) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
    return ((PFN_glGetnTexImage)__blue_glCore_glGetnTexImage)(target, level, format, type, bufSize, pixels);
}

extern void* __blue_glCore_glGetnUniformdv;
void APIENTRY bluegl_glGetnUniformdv (GLuint program, GLint location, GLsizei bufSize, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetnUniformdv) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
    return ((PFN_glGetnUniformdv)__blue_glCore_glGetnUniformdv)(program, location, bufSize, params);
}

extern void* __blue_glCore_glGetnUniformfv;
void APIENTRY bluegl_glGetnUniformfv (GLuint program, GLint location, GLsizei bufSize, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetnUniformfv) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
    return ((PFN_glGetnUniformfv)__blue_glCore_glGetnUniformfv)(program, location, bufSize, params);
}

extern void* __blue_glCore_glGetnUniformiv;
void APIENTRY bluegl_glGetnUniformiv (GLuint program, GLint location, GLsizei bufSize, GLint *params) {
    typedef void (APIENTRYP PFN_glGetnUniformiv) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
    return ((PFN_glGetnUniformiv)__blue_glCore_glGetnUniformiv)(program, location, bufSize, params);
}

extern void* __blue_glCore_glGetnUniformuiv;
void APIENTRY bluegl_glGetnUniformuiv (GLuint program, GLint location, GLsizei bufSize, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetnUniformuiv) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
    return ((PFN_glGetnUniformuiv)__blue_glCore_glGetnUniformuiv)(program, location, bufSize, params);
}

extern void* __blue_glCore_glReadnPixels;
void APIENTRY bluegl_glReadnPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) {
    typedef void (APIENTRYP PFN_glReadnPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
    return ((PFN_glReadnPixels)__blue_glCore_glReadnPixels)(x, y, width, height, format, type, bufSize, data);
}

extern void* __blue_glCore_glTextureBarrier;
void APIENTRY bluegl_glTextureBarrier (void) {
    typedef void (APIENTRYP PFN_glTextureBarrier) (void);
    return ((PFN_glTextureBarrier)__blue_glCore_glTextureBarrier)();
}

extern void* __blue_glCore_glGetTextureHandleARB;
GLuint64 APIENTRY bluegl_glGetTextureHandleARB (GLuint texture) {
    typedef GLuint64 (APIENTRYP PFN_glGetTextureHandleARB) (GLuint texture);
    return ((PFN_glGetTextureHandleARB)__blue_glCore_glGetTextureHandleARB)(texture);
}

extern void* __blue_glCore_glGetTextureSamplerHandleARB;
GLuint64 APIENTRY bluegl_glGetTextureSamplerHandleARB (GLuint texture, GLuint sampler) {
    typedef GLuint64 (APIENTRYP PFN_glGetTextureSamplerHandleARB) (GLuint texture, GLuint sampler);
    return ((PFN_glGetTextureSamplerHandleARB)__blue_glCore_glGetTextureSamplerHandleARB)(texture, sampler);
}

extern void* __blue_glCore_glMakeTextureHandleResidentARB;
void APIENTRY bluegl_glMakeTextureHandleResidentARB (GLuint64 handle) {
    typedef void (APIENTRYP PFN_glMakeTextureHandleResidentARB) (GLuint64 handle);
    return ((PFN_glMakeTextureHandleResidentARB)__blue_glCore_glMakeTextureHandleResidentARB)(handle);
}

extern void* __blue_glCore_glMakeTextureHandleNonResidentARB;
void APIENTRY bluegl_glMakeTextureHandleNonResidentARB (GLuint64 handle) {
    typedef void (APIENTRYP PFN_glMakeTextureHandleNonResidentARB) (GLuint64 handle);
    return ((PFN_glMakeTextureHandleNonResidentARB)__blue_glCore_glMakeTextureHandleNonResidentARB)(handle);
}

extern void* __blue_glCore_glGetImageHandleARB;
GLuint64 APIENTRY bluegl_glGetImageHandleARB (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) {
    typedef GLuint64 (APIENTRYP PFN_glGetImageHandleARB) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
    return ((PFN_glGetImageHandleARB)__blue_glCore_glGetImageHandleARB)(texture, level, layered, layer, format);
}

extern void* __blue_glCore_glMakeImageHandleResidentARB;
void APIENTRY bluegl_glMakeImageHandleResidentARB (GLuint64 handle, GLenum access) {
    typedef void (APIENTRYP PFN_glMakeImageHandleResidentARB) (GLuint64 handle, GLenum access);
    return ((PFN_glMakeImageHandleResidentARB)__blue_glCore_glMakeImageHandleResidentARB)(handle, access);
}

extern void* __blue_glCore_glMakeImageHandleNonResidentARB;
void APIENTRY bluegl_glMakeImageHandleNonResidentARB (GLuint64 handle) {
    typedef void (APIENTRYP PFN_glMakeImageHandleNonResidentARB) (GLuint64 handle);
    return ((PFN_glMakeImageHandleNonResidentARB)__blue_glCore_glMakeImageHandleNonResidentARB)(handle);
}

extern void* __blue_glCore_glUniformHandleui64ARB;
void APIENTRY bluegl_glUniformHandleui64ARB (GLint location, GLuint64 value) {
    typedef void (APIENTRYP PFN_glUniformHandleui64ARB) (GLint location, GLuint64 value);
    return ((PFN_glUniformHandleui64ARB)__blue_glCore_glUniformHandleui64ARB)(location, value);
}

extern void* __blue_glCore_glUniformHandleui64vARB;
void APIENTRY bluegl_glUniformHandleui64vARB (GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glUniformHandleui64vARB) (GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glUniformHandleui64vARB)__blue_glCore_glUniformHandleui64vARB)(location, count, value);
}

extern void* __blue_glCore_glProgramUniformHandleui64ARB;
void APIENTRY bluegl_glProgramUniformHandleui64ARB (GLuint program, GLint location, GLuint64 value) {
    typedef void (APIENTRYP PFN_glProgramUniformHandleui64ARB) (GLuint program, GLint location, GLuint64 value);
    return ((PFN_glProgramUniformHandleui64ARB)__blue_glCore_glProgramUniformHandleui64ARB)(program, location, value);
}

extern void* __blue_glCore_glProgramUniformHandleui64vARB;
void APIENTRY bluegl_glProgramUniformHandleui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *values) {
    typedef void (APIENTRYP PFN_glProgramUniformHandleui64vARB) (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
    return ((PFN_glProgramUniformHandleui64vARB)__blue_glCore_glProgramUniformHandleui64vARB)(program, location, count, values);
}

extern void* __blue_glCore_glIsTextureHandleResidentARB;
GLboolean APIENTRY bluegl_glIsTextureHandleResidentARB (GLuint64 handle) {
    typedef GLboolean (APIENTRYP PFN_glIsTextureHandleResidentARB) (GLuint64 handle);
    return ((PFN_glIsTextureHandleResidentARB)__blue_glCore_glIsTextureHandleResidentARB)(handle);
}

extern void* __blue_glCore_glIsImageHandleResidentARB;
GLboolean APIENTRY bluegl_glIsImageHandleResidentARB (GLuint64 handle) {
    typedef GLboolean (APIENTRYP PFN_glIsImageHandleResidentARB) (GLuint64 handle);
    return ((PFN_glIsImageHandleResidentARB)__blue_glCore_glIsImageHandleResidentARB)(handle);
}

extern void* __blue_glCore_glVertexAttribL1ui64ARB;
void APIENTRY bluegl_glVertexAttribL1ui64ARB (GLuint index, GLuint64EXT x) {
    typedef void (APIENTRYP PFN_glVertexAttribL1ui64ARB) (GLuint index, GLuint64EXT x);
    return ((PFN_glVertexAttribL1ui64ARB)__blue_glCore_glVertexAttribL1ui64ARB)(index, x);
}

extern void* __blue_glCore_glVertexAttribL1ui64vARB;
void APIENTRY bluegl_glVertexAttribL1ui64vARB (GLuint index, const GLuint64EXT *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL1ui64vARB) (GLuint index, const GLuint64EXT *v);
    return ((PFN_glVertexAttribL1ui64vARB)__blue_glCore_glVertexAttribL1ui64vARB)(index, v);
}

extern void* __blue_glCore_glGetVertexAttribLui64vARB;
void APIENTRY bluegl_glGetVertexAttribLui64vARB (GLuint index, GLenum pname, GLuint64EXT *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribLui64vARB) (GLuint index, GLenum pname, GLuint64EXT *params);
    return ((PFN_glGetVertexAttribLui64vARB)__blue_glCore_glGetVertexAttribLui64vARB)(index, pname, params);
}

extern void* __blue_glCore_glCreateSyncFromCLeventARB;
GLsync APIENTRY bluegl_glCreateSyncFromCLeventARB (struct _cl_context *context, struct _cl_event *event, GLbitfield flags) {
    typedef GLsync (APIENTRYP PFN_glCreateSyncFromCLeventARB) (struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
    return ((PFN_glCreateSyncFromCLeventARB)__blue_glCore_glCreateSyncFromCLeventARB)(context, event, flags);
}

extern void* __blue_glCore_glDispatchComputeGroupSizeARB;
void APIENTRY bluegl_glDispatchComputeGroupSizeARB (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z) {
    typedef void (APIENTRYP PFN_glDispatchComputeGroupSizeARB) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
    return ((PFN_glDispatchComputeGroupSizeARB)__blue_glCore_glDispatchComputeGroupSizeARB)(num_groups_x, num_groups_y, num_groups_z, group_size_x, group_size_y, group_size_z);
}

extern void* __blue_glCore_glDebugMessageControlARB;
void APIENTRY bluegl_glDebugMessageControlARB (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) {
    typedef void (APIENTRYP PFN_glDebugMessageControlARB) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
    return ((PFN_glDebugMessageControlARB)__blue_glCore_glDebugMessageControlARB)(source, type, severity, count, ids, enabled);
}

extern void* __blue_glCore_glDebugMessageInsertARB;
void APIENTRY bluegl_glDebugMessageInsertARB (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) {
    typedef void (APIENTRYP PFN_glDebugMessageInsertARB) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
    return ((PFN_glDebugMessageInsertARB)__blue_glCore_glDebugMessageInsertARB)(source, type, id, severity, length, buf);
}

extern void* __blue_glCore_glDebugMessageCallbackARB;
void APIENTRY bluegl_glDebugMessageCallbackARB (GLDEBUGPROCARB callback, const void *userParam) {
    typedef void (APIENTRYP PFN_glDebugMessageCallbackARB) (GLDEBUGPROCARB callback, const void *userParam);
    return ((PFN_glDebugMessageCallbackARB)__blue_glCore_glDebugMessageCallbackARB)(callback, userParam);
}

extern void* __blue_glCore_glGetDebugMessageLogARB;
GLuint APIENTRY bluegl_glGetDebugMessageLogARB (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) {
    typedef GLuint (APIENTRYP PFN_glGetDebugMessageLogARB) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
    return ((PFN_glGetDebugMessageLogARB)__blue_glCore_glGetDebugMessageLogARB)(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

extern void* __blue_glCore_glBlendEquationiARB;
void APIENTRY bluegl_glBlendEquationiARB (GLuint buf, GLenum mode) {
    typedef void (APIENTRYP PFN_glBlendEquationiARB) (GLuint buf, GLenum mode);
    return ((PFN_glBlendEquationiARB)__blue_glCore_glBlendEquationiARB)(buf, mode);
}

extern void* __blue_glCore_glBlendEquationSeparateiARB;
void APIENTRY bluegl_glBlendEquationSeparateiARB (GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
    typedef void (APIENTRYP PFN_glBlendEquationSeparateiARB) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    return ((PFN_glBlendEquationSeparateiARB)__blue_glCore_glBlendEquationSeparateiARB)(buf, modeRGB, modeAlpha);
}

extern void* __blue_glCore_glBlendFunciARB;
void APIENTRY bluegl_glBlendFunciARB (GLuint buf, GLenum src, GLenum dst) {
    typedef void (APIENTRYP PFN_glBlendFunciARB) (GLuint buf, GLenum src, GLenum dst);
    return ((PFN_glBlendFunciARB)__blue_glCore_glBlendFunciARB)(buf, src, dst);
}

extern void* __blue_glCore_glBlendFuncSeparateiARB;
void APIENTRY bluegl_glBlendFuncSeparateiARB (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    typedef void (APIENTRYP PFN_glBlendFuncSeparateiARB) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    return ((PFN_glBlendFuncSeparateiARB)__blue_glCore_glBlendFuncSeparateiARB)(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

extern void* __blue_glCore_glMultiDrawArraysIndirectCountARB;
void APIENTRY bluegl_glMultiDrawArraysIndirectCountARB (GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
    typedef void (APIENTRYP PFN_glMultiDrawArraysIndirectCountARB) (GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
    return ((PFN_glMultiDrawArraysIndirectCountARB)__blue_glCore_glMultiDrawArraysIndirectCountARB)(mode, indirect, drawcount, maxdrawcount, stride);
}

extern void* __blue_glCore_glMultiDrawElementsIndirectCountARB;
void APIENTRY bluegl_glMultiDrawElementsIndirectCountARB (GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
    typedef void (APIENTRYP PFN_glMultiDrawElementsIndirectCountARB) (GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
    return ((PFN_glMultiDrawElementsIndirectCountARB)__blue_glCore_glMultiDrawElementsIndirectCountARB)(mode, type, indirect, drawcount, maxdrawcount, stride);
}

extern void* __blue_glCore_glGetGraphicsResetStatusARB;
GLenum APIENTRY bluegl_glGetGraphicsResetStatusARB (void) {
    typedef GLenum (APIENTRYP PFN_glGetGraphicsResetStatusARB) (void);
    return ((PFN_glGetGraphicsResetStatusARB)__blue_glCore_glGetGraphicsResetStatusARB)();
}

extern void* __blue_glCore_glGetnTexImageARB;
void APIENTRY bluegl_glGetnTexImageARB (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img) {
    typedef void (APIENTRYP PFN_glGetnTexImageARB) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
    return ((PFN_glGetnTexImageARB)__blue_glCore_glGetnTexImageARB)(target, level, format, type, bufSize, img);
}

extern void* __blue_glCore_glReadnPixelsARB;
void APIENTRY bluegl_glReadnPixelsARB (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) {
    typedef void (APIENTRYP PFN_glReadnPixelsARB) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
    return ((PFN_glReadnPixelsARB)__blue_glCore_glReadnPixelsARB)(x, y, width, height, format, type, bufSize, data);
}

extern void* __blue_glCore_glGetnCompressedTexImageARB;
void APIENTRY bluegl_glGetnCompressedTexImageARB (GLenum target, GLint lod, GLsizei bufSize, void *img) {
    typedef void (APIENTRYP PFN_glGetnCompressedTexImageARB) (GLenum target, GLint lod, GLsizei bufSize, void *img);
    return ((PFN_glGetnCompressedTexImageARB)__blue_glCore_glGetnCompressedTexImageARB)(target, lod, bufSize, img);
}

extern void* __blue_glCore_glGetnUniformfvARB;
void APIENTRY bluegl_glGetnUniformfvARB (GLuint program, GLint location, GLsizei bufSize, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetnUniformfvARB) (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
    return ((PFN_glGetnUniformfvARB)__blue_glCore_glGetnUniformfvARB)(program, location, bufSize, params);
}

extern void* __blue_glCore_glGetnUniformivARB;
void APIENTRY bluegl_glGetnUniformivARB (GLuint program, GLint location, GLsizei bufSize, GLint *params) {
    typedef void (APIENTRYP PFN_glGetnUniformivARB) (GLuint program, GLint location, GLsizei bufSize, GLint *params);
    return ((PFN_glGetnUniformivARB)__blue_glCore_glGetnUniformivARB)(program, location, bufSize, params);
}

extern void* __blue_glCore_glGetnUniformuivARB;
void APIENTRY bluegl_glGetnUniformuivARB (GLuint program, GLint location, GLsizei bufSize, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetnUniformuivARB) (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
    return ((PFN_glGetnUniformuivARB)__blue_glCore_glGetnUniformuivARB)(program, location, bufSize, params);
}

extern void* __blue_glCore_glGetnUniformdvARB;
void APIENTRY bluegl_glGetnUniformdvARB (GLuint program, GLint location, GLsizei bufSize, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetnUniformdvARB) (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
    return ((PFN_glGetnUniformdvARB)__blue_glCore_glGetnUniformdvARB)(program, location, bufSize, params);
}

extern void* __blue_glCore_glMinSampleShadingARB;
void APIENTRY bluegl_glMinSampleShadingARB (GLfloat value) {
    typedef void (APIENTRYP PFN_glMinSampleShadingARB) (GLfloat value);
    return ((PFN_glMinSampleShadingARB)__blue_glCore_glMinSampleShadingARB)(value);
}

extern void* __blue_glCore_glNamedStringARB;
void APIENTRY bluegl_glNamedStringARB (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string) {
    typedef void (APIENTRYP PFN_glNamedStringARB) (GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
    return ((PFN_glNamedStringARB)__blue_glCore_glNamedStringARB)(type, namelen, name, stringlen, string);
}

extern void* __blue_glCore_glDeleteNamedStringARB;
void APIENTRY bluegl_glDeleteNamedStringARB (GLint namelen, const GLchar *name) {
    typedef void (APIENTRYP PFN_glDeleteNamedStringARB) (GLint namelen, const GLchar *name);
    return ((PFN_glDeleteNamedStringARB)__blue_glCore_glDeleteNamedStringARB)(namelen, name);
}

extern void* __blue_glCore_glCompileShaderIncludeARB;
void APIENTRY bluegl_glCompileShaderIncludeARB (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length) {
    typedef void (APIENTRYP PFN_glCompileShaderIncludeARB) (GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
    return ((PFN_glCompileShaderIncludeARB)__blue_glCore_glCompileShaderIncludeARB)(shader, count, path, length);
}

extern void* __blue_glCore_glIsNamedStringARB;
GLboolean APIENTRY bluegl_glIsNamedStringARB (GLint namelen, const GLchar *name) {
    typedef GLboolean (APIENTRYP PFN_glIsNamedStringARB) (GLint namelen, const GLchar *name);
    return ((PFN_glIsNamedStringARB)__blue_glCore_glIsNamedStringARB)(namelen, name);
}

extern void* __blue_glCore_glGetNamedStringARB;
void APIENTRY bluegl_glGetNamedStringARB (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string) {
    typedef void (APIENTRYP PFN_glGetNamedStringARB) (GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
    return ((PFN_glGetNamedStringARB)__blue_glCore_glGetNamedStringARB)(namelen, name, bufSize, stringlen, string);
}

extern void* __blue_glCore_glGetNamedStringivARB;
void APIENTRY bluegl_glGetNamedStringivARB (GLint namelen, const GLchar *name, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedStringivARB) (GLint namelen, const GLchar *name, GLenum pname, GLint *params);
    return ((PFN_glGetNamedStringivARB)__blue_glCore_glGetNamedStringivARB)(namelen, name, pname, params);
}

extern void* __blue_glCore_glBufferPageCommitmentARB;
void APIENTRY bluegl_glBufferPageCommitmentARB (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit) {
    typedef void (APIENTRYP PFN_glBufferPageCommitmentARB) (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
    return ((PFN_glBufferPageCommitmentARB)__blue_glCore_glBufferPageCommitmentARB)(target, offset, size, commit);
}

extern void* __blue_glCore_glNamedBufferPageCommitmentEXT;
void APIENTRY bluegl_glNamedBufferPageCommitmentEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) {
    typedef void (APIENTRYP PFN_glNamedBufferPageCommitmentEXT) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
    return ((PFN_glNamedBufferPageCommitmentEXT)__blue_glCore_glNamedBufferPageCommitmentEXT)(buffer, offset, size, commit);
}

extern void* __blue_glCore_glNamedBufferPageCommitmentARB;
void APIENTRY bluegl_glNamedBufferPageCommitmentARB (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) {
    typedef void (APIENTRYP PFN_glNamedBufferPageCommitmentARB) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
    return ((PFN_glNamedBufferPageCommitmentARB)__blue_glCore_glNamedBufferPageCommitmentARB)(buffer, offset, size, commit);
}

extern void* __blue_glCore_glTexPageCommitmentARB;
void APIENTRY bluegl_glTexPageCommitmentARB (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) {
    typedef void (APIENTRYP PFN_glTexPageCommitmentARB) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
    return ((PFN_glTexPageCommitmentARB)__blue_glCore_glTexPageCommitmentARB)(target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}

extern void* __blue_glCore_glClientActiveTexture;
void APIENTRY bluegl_glClientActiveTexture (GLenum texture) {
    typedef void (APIENTRYP PFN_glClientActiveTexture) (GLenum texture);
    return ((PFN_glClientActiveTexture)__blue_glCore_glClientActiveTexture)(texture);
}

extern void* __blue_glCore_glMultiTexCoord1d;
void APIENTRY bluegl_glMultiTexCoord1d (GLenum target, GLdouble s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1d) (GLenum target, GLdouble s);
    return ((PFN_glMultiTexCoord1d)__blue_glCore_glMultiTexCoord1d)(target, s);
}

extern void* __blue_glCore_glMultiTexCoord1dv;
void APIENTRY bluegl_glMultiTexCoord1dv (GLenum target, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1dv) (GLenum target, const GLdouble *v);
    return ((PFN_glMultiTexCoord1dv)__blue_glCore_glMultiTexCoord1dv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord1f;
void APIENTRY bluegl_glMultiTexCoord1f (GLenum target, GLfloat s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1f) (GLenum target, GLfloat s);
    return ((PFN_glMultiTexCoord1f)__blue_glCore_glMultiTexCoord1f)(target, s);
}

extern void* __blue_glCore_glMultiTexCoord1fv;
void APIENTRY bluegl_glMultiTexCoord1fv (GLenum target, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1fv) (GLenum target, const GLfloat *v);
    return ((PFN_glMultiTexCoord1fv)__blue_glCore_glMultiTexCoord1fv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord1i;
void APIENTRY bluegl_glMultiTexCoord1i (GLenum target, GLint s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1i) (GLenum target, GLint s);
    return ((PFN_glMultiTexCoord1i)__blue_glCore_glMultiTexCoord1i)(target, s);
}

extern void* __blue_glCore_glMultiTexCoord1iv;
void APIENTRY bluegl_glMultiTexCoord1iv (GLenum target, const GLint *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1iv) (GLenum target, const GLint *v);
    return ((PFN_glMultiTexCoord1iv)__blue_glCore_glMultiTexCoord1iv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord1s;
void APIENTRY bluegl_glMultiTexCoord1s (GLenum target, GLshort s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1s) (GLenum target, GLshort s);
    return ((PFN_glMultiTexCoord1s)__blue_glCore_glMultiTexCoord1s)(target, s);
}

extern void* __blue_glCore_glMultiTexCoord1sv;
void APIENTRY bluegl_glMultiTexCoord1sv (GLenum target, const GLshort *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1sv) (GLenum target, const GLshort *v);
    return ((PFN_glMultiTexCoord1sv)__blue_glCore_glMultiTexCoord1sv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord2d;
void APIENTRY bluegl_glMultiTexCoord2d (GLenum target, GLdouble s, GLdouble t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2d) (GLenum target, GLdouble s, GLdouble t);
    return ((PFN_glMultiTexCoord2d)__blue_glCore_glMultiTexCoord2d)(target, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2dv;
void APIENTRY bluegl_glMultiTexCoord2dv (GLenum target, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2dv) (GLenum target, const GLdouble *v);
    return ((PFN_glMultiTexCoord2dv)__blue_glCore_glMultiTexCoord2dv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord2f;
void APIENTRY bluegl_glMultiTexCoord2f (GLenum target, GLfloat s, GLfloat t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2f) (GLenum target, GLfloat s, GLfloat t);
    return ((PFN_glMultiTexCoord2f)__blue_glCore_glMultiTexCoord2f)(target, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2fv;
void APIENTRY bluegl_glMultiTexCoord2fv (GLenum target, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2fv) (GLenum target, const GLfloat *v);
    return ((PFN_glMultiTexCoord2fv)__blue_glCore_glMultiTexCoord2fv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord2i;
void APIENTRY bluegl_glMultiTexCoord2i (GLenum target, GLint s, GLint t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2i) (GLenum target, GLint s, GLint t);
    return ((PFN_glMultiTexCoord2i)__blue_glCore_glMultiTexCoord2i)(target, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2iv;
void APIENTRY bluegl_glMultiTexCoord2iv (GLenum target, const GLint *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2iv) (GLenum target, const GLint *v);
    return ((PFN_glMultiTexCoord2iv)__blue_glCore_glMultiTexCoord2iv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord2s;
void APIENTRY bluegl_glMultiTexCoord2s (GLenum target, GLshort s, GLshort t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2s) (GLenum target, GLshort s, GLshort t);
    return ((PFN_glMultiTexCoord2s)__blue_glCore_glMultiTexCoord2s)(target, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2sv;
void APIENTRY bluegl_glMultiTexCoord2sv (GLenum target, const GLshort *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2sv) (GLenum target, const GLshort *v);
    return ((PFN_glMultiTexCoord2sv)__blue_glCore_glMultiTexCoord2sv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord3d;
void APIENTRY bluegl_glMultiTexCoord3d (GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3d) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
    return ((PFN_glMultiTexCoord3d)__blue_glCore_glMultiTexCoord3d)(target, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3dv;
void APIENTRY bluegl_glMultiTexCoord3dv (GLenum target, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3dv) (GLenum target, const GLdouble *v);
    return ((PFN_glMultiTexCoord3dv)__blue_glCore_glMultiTexCoord3dv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord3f;
void APIENTRY bluegl_glMultiTexCoord3f (GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3f) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
    return ((PFN_glMultiTexCoord3f)__blue_glCore_glMultiTexCoord3f)(target, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3fv;
void APIENTRY bluegl_glMultiTexCoord3fv (GLenum target, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3fv) (GLenum target, const GLfloat *v);
    return ((PFN_glMultiTexCoord3fv)__blue_glCore_glMultiTexCoord3fv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord3i;
void APIENTRY bluegl_glMultiTexCoord3i (GLenum target, GLint s, GLint t, GLint r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3i) (GLenum target, GLint s, GLint t, GLint r);
    return ((PFN_glMultiTexCoord3i)__blue_glCore_glMultiTexCoord3i)(target, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3iv;
void APIENTRY bluegl_glMultiTexCoord3iv (GLenum target, const GLint *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3iv) (GLenum target, const GLint *v);
    return ((PFN_glMultiTexCoord3iv)__blue_glCore_glMultiTexCoord3iv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord3s;
void APIENTRY bluegl_glMultiTexCoord3s (GLenum target, GLshort s, GLshort t, GLshort r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3s) (GLenum target, GLshort s, GLshort t, GLshort r);
    return ((PFN_glMultiTexCoord3s)__blue_glCore_glMultiTexCoord3s)(target, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3sv;
void APIENTRY bluegl_glMultiTexCoord3sv (GLenum target, const GLshort *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3sv) (GLenum target, const GLshort *v);
    return ((PFN_glMultiTexCoord3sv)__blue_glCore_glMultiTexCoord3sv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord4d;
void APIENTRY bluegl_glMultiTexCoord4d (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4d) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
    return ((PFN_glMultiTexCoord4d)__blue_glCore_glMultiTexCoord4d)(target, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4dv;
void APIENTRY bluegl_glMultiTexCoord4dv (GLenum target, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4dv) (GLenum target, const GLdouble *v);
    return ((PFN_glMultiTexCoord4dv)__blue_glCore_glMultiTexCoord4dv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord4f;
void APIENTRY bluegl_glMultiTexCoord4f (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4f) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
    return ((PFN_glMultiTexCoord4f)__blue_glCore_glMultiTexCoord4f)(target, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4fv;
void APIENTRY bluegl_glMultiTexCoord4fv (GLenum target, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4fv) (GLenum target, const GLfloat *v);
    return ((PFN_glMultiTexCoord4fv)__blue_glCore_glMultiTexCoord4fv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord4i;
void APIENTRY bluegl_glMultiTexCoord4i (GLenum target, GLint s, GLint t, GLint r, GLint q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4i) (GLenum target, GLint s, GLint t, GLint r, GLint q);
    return ((PFN_glMultiTexCoord4i)__blue_glCore_glMultiTexCoord4i)(target, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4iv;
void APIENTRY bluegl_glMultiTexCoord4iv (GLenum target, const GLint *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4iv) (GLenum target, const GLint *v);
    return ((PFN_glMultiTexCoord4iv)__blue_glCore_glMultiTexCoord4iv)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord4s;
void APIENTRY bluegl_glMultiTexCoord4s (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4s) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
    return ((PFN_glMultiTexCoord4s)__blue_glCore_glMultiTexCoord4s)(target, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4sv;
void APIENTRY bluegl_glMultiTexCoord4sv (GLenum target, const GLshort *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4sv) (GLenum target, const GLshort *v);
    return ((PFN_glMultiTexCoord4sv)__blue_glCore_glMultiTexCoord4sv)(target, v);
}

extern void* __blue_glCore_glLoadTransposeMatrixf;
void APIENTRY bluegl_glLoadTransposeMatrixf (const GLfloat *m) {
    typedef void (APIENTRYP PFN_glLoadTransposeMatrixf) (const GLfloat *m);
    return ((PFN_glLoadTransposeMatrixf)__blue_glCore_glLoadTransposeMatrixf)(m);
}

extern void* __blue_glCore_glLoadTransposeMatrixd;
void APIENTRY bluegl_glLoadTransposeMatrixd (const GLdouble *m) {
    typedef void (APIENTRYP PFN_glLoadTransposeMatrixd) (const GLdouble *m);
    return ((PFN_glLoadTransposeMatrixd)__blue_glCore_glLoadTransposeMatrixd)(m);
}

extern void* __blue_glCore_glMultTransposeMatrixf;
void APIENTRY bluegl_glMultTransposeMatrixf (const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMultTransposeMatrixf) (const GLfloat *m);
    return ((PFN_glMultTransposeMatrixf)__blue_glCore_glMultTransposeMatrixf)(m);
}

extern void* __blue_glCore_glMultTransposeMatrixd;
void APIENTRY bluegl_glMultTransposeMatrixd (const GLdouble *m) {
    typedef void (APIENTRYP PFN_glMultTransposeMatrixd) (const GLdouble *m);
    return ((PFN_glMultTransposeMatrixd)__blue_glCore_glMultTransposeMatrixd)(m);
}

extern void* __blue_glCore_glFogCoordf;
void APIENTRY bluegl_glFogCoordf (GLfloat coord) {
    typedef void (APIENTRYP PFN_glFogCoordf) (GLfloat coord);
    return ((PFN_glFogCoordf)__blue_glCore_glFogCoordf)(coord);
}

extern void* __blue_glCore_glFogCoordfv;
void APIENTRY bluegl_glFogCoordfv (const GLfloat *coord) {
    typedef void (APIENTRYP PFN_glFogCoordfv) (const GLfloat *coord);
    return ((PFN_glFogCoordfv)__blue_glCore_glFogCoordfv)(coord);
}

extern void* __blue_glCore_glFogCoordd;
void APIENTRY bluegl_glFogCoordd (GLdouble coord) {
    typedef void (APIENTRYP PFN_glFogCoordd) (GLdouble coord);
    return ((PFN_glFogCoordd)__blue_glCore_glFogCoordd)(coord);
}

extern void* __blue_glCore_glFogCoorddv;
void APIENTRY bluegl_glFogCoorddv (const GLdouble *coord) {
    typedef void (APIENTRYP PFN_glFogCoorddv) (const GLdouble *coord);
    return ((PFN_glFogCoorddv)__blue_glCore_glFogCoorddv)(coord);
}

extern void* __blue_glCore_glFogCoordPointer;
void APIENTRY bluegl_glFogCoordPointer (GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glFogCoordPointer) (GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glFogCoordPointer)__blue_glCore_glFogCoordPointer)(type, stride, pointer);
}

extern void* __blue_glCore_glSecondaryColor3b;
void APIENTRY bluegl_glSecondaryColor3b (GLbyte red, GLbyte green, GLbyte blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3b) (GLbyte red, GLbyte green, GLbyte blue);
    return ((PFN_glSecondaryColor3b)__blue_glCore_glSecondaryColor3b)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3bv;
void APIENTRY bluegl_glSecondaryColor3bv (const GLbyte *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3bv) (const GLbyte *v);
    return ((PFN_glSecondaryColor3bv)__blue_glCore_glSecondaryColor3bv)(v);
}

extern void* __blue_glCore_glSecondaryColor3d;
void APIENTRY bluegl_glSecondaryColor3d (GLdouble red, GLdouble green, GLdouble blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3d) (GLdouble red, GLdouble green, GLdouble blue);
    return ((PFN_glSecondaryColor3d)__blue_glCore_glSecondaryColor3d)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3dv;
void APIENTRY bluegl_glSecondaryColor3dv (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3dv) (const GLdouble *v);
    return ((PFN_glSecondaryColor3dv)__blue_glCore_glSecondaryColor3dv)(v);
}

extern void* __blue_glCore_glSecondaryColor3f;
void APIENTRY bluegl_glSecondaryColor3f (GLfloat red, GLfloat green, GLfloat blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3f) (GLfloat red, GLfloat green, GLfloat blue);
    return ((PFN_glSecondaryColor3f)__blue_glCore_glSecondaryColor3f)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3fv;
void APIENTRY bluegl_glSecondaryColor3fv (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3fv) (const GLfloat *v);
    return ((PFN_glSecondaryColor3fv)__blue_glCore_glSecondaryColor3fv)(v);
}

extern void* __blue_glCore_glSecondaryColor3i;
void APIENTRY bluegl_glSecondaryColor3i (GLint red, GLint green, GLint blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3i) (GLint red, GLint green, GLint blue);
    return ((PFN_glSecondaryColor3i)__blue_glCore_glSecondaryColor3i)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3iv;
void APIENTRY bluegl_glSecondaryColor3iv (const GLint *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3iv) (const GLint *v);
    return ((PFN_glSecondaryColor3iv)__blue_glCore_glSecondaryColor3iv)(v);
}

extern void* __blue_glCore_glSecondaryColor3s;
void APIENTRY bluegl_glSecondaryColor3s (GLshort red, GLshort green, GLshort blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3s) (GLshort red, GLshort green, GLshort blue);
    return ((PFN_glSecondaryColor3s)__blue_glCore_glSecondaryColor3s)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3sv;
void APIENTRY bluegl_glSecondaryColor3sv (const GLshort *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3sv) (const GLshort *v);
    return ((PFN_glSecondaryColor3sv)__blue_glCore_glSecondaryColor3sv)(v);
}

extern void* __blue_glCore_glSecondaryColor3ub;
void APIENTRY bluegl_glSecondaryColor3ub (GLubyte red, GLubyte green, GLubyte blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3ub) (GLubyte red, GLubyte green, GLubyte blue);
    return ((PFN_glSecondaryColor3ub)__blue_glCore_glSecondaryColor3ub)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3ubv;
void APIENTRY bluegl_glSecondaryColor3ubv (const GLubyte *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3ubv) (const GLubyte *v);
    return ((PFN_glSecondaryColor3ubv)__blue_glCore_glSecondaryColor3ubv)(v);
}

extern void* __blue_glCore_glSecondaryColor3ui;
void APIENTRY bluegl_glSecondaryColor3ui (GLuint red, GLuint green, GLuint blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3ui) (GLuint red, GLuint green, GLuint blue);
    return ((PFN_glSecondaryColor3ui)__blue_glCore_glSecondaryColor3ui)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3uiv;
void APIENTRY bluegl_glSecondaryColor3uiv (const GLuint *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3uiv) (const GLuint *v);
    return ((PFN_glSecondaryColor3uiv)__blue_glCore_glSecondaryColor3uiv)(v);
}

extern void* __blue_glCore_glSecondaryColor3us;
void APIENTRY bluegl_glSecondaryColor3us (GLushort red, GLushort green, GLushort blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3us) (GLushort red, GLushort green, GLushort blue);
    return ((PFN_glSecondaryColor3us)__blue_glCore_glSecondaryColor3us)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3usv;
void APIENTRY bluegl_glSecondaryColor3usv (const GLushort *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3usv) (const GLushort *v);
    return ((PFN_glSecondaryColor3usv)__blue_glCore_glSecondaryColor3usv)(v);
}

extern void* __blue_glCore_glSecondaryColorPointer;
void APIENTRY bluegl_glSecondaryColorPointer (GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glSecondaryColorPointer) (GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glSecondaryColorPointer)__blue_glCore_glSecondaryColorPointer)(size, type, stride, pointer);
}

extern void* __blue_glCore_glWindowPos2d;
void APIENTRY bluegl_glWindowPos2d (GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glWindowPos2d) (GLdouble x, GLdouble y);
    return ((PFN_glWindowPos2d)__blue_glCore_glWindowPos2d)(x, y);
}

extern void* __blue_glCore_glWindowPos2dv;
void APIENTRY bluegl_glWindowPos2dv (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glWindowPos2dv) (const GLdouble *v);
    return ((PFN_glWindowPos2dv)__blue_glCore_glWindowPos2dv)(v);
}

extern void* __blue_glCore_glWindowPos2f;
void APIENTRY bluegl_glWindowPos2f (GLfloat x, GLfloat y) {
    typedef void (APIENTRYP PFN_glWindowPos2f) (GLfloat x, GLfloat y);
    return ((PFN_glWindowPos2f)__blue_glCore_glWindowPos2f)(x, y);
}

extern void* __blue_glCore_glWindowPos2fv;
void APIENTRY bluegl_glWindowPos2fv (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glWindowPos2fv) (const GLfloat *v);
    return ((PFN_glWindowPos2fv)__blue_glCore_glWindowPos2fv)(v);
}

extern void* __blue_glCore_glWindowPos2i;
void APIENTRY bluegl_glWindowPos2i (GLint x, GLint y) {
    typedef void (APIENTRYP PFN_glWindowPos2i) (GLint x, GLint y);
    return ((PFN_glWindowPos2i)__blue_glCore_glWindowPos2i)(x, y);
}

extern void* __blue_glCore_glWindowPos2iv;
void APIENTRY bluegl_glWindowPos2iv (const GLint *v) {
    typedef void (APIENTRYP PFN_glWindowPos2iv) (const GLint *v);
    return ((PFN_glWindowPos2iv)__blue_glCore_glWindowPos2iv)(v);
}

extern void* __blue_glCore_glWindowPos2s;
void APIENTRY bluegl_glWindowPos2s (GLshort x, GLshort y) {
    typedef void (APIENTRYP PFN_glWindowPos2s) (GLshort x, GLshort y);
    return ((PFN_glWindowPos2s)__blue_glCore_glWindowPos2s)(x, y);
}

extern void* __blue_glCore_glWindowPos2sv;
void APIENTRY bluegl_glWindowPos2sv (const GLshort *v) {
    typedef void (APIENTRYP PFN_glWindowPos2sv) (const GLshort *v);
    return ((PFN_glWindowPos2sv)__blue_glCore_glWindowPos2sv)(v);
}

extern void* __blue_glCore_glWindowPos3d;
void APIENTRY bluegl_glWindowPos3d (GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glWindowPos3d) (GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glWindowPos3d)__blue_glCore_glWindowPos3d)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3dv;
void APIENTRY bluegl_glWindowPos3dv (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glWindowPos3dv) (const GLdouble *v);
    return ((PFN_glWindowPos3dv)__blue_glCore_glWindowPos3dv)(v);
}

extern void* __blue_glCore_glWindowPos3f;
void APIENTRY bluegl_glWindowPos3f (GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glWindowPos3f) (GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glWindowPos3f)__blue_glCore_glWindowPos3f)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3fv;
void APIENTRY bluegl_glWindowPos3fv (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glWindowPos3fv) (const GLfloat *v);
    return ((PFN_glWindowPos3fv)__blue_glCore_glWindowPos3fv)(v);
}

extern void* __blue_glCore_glWindowPos3i;
void APIENTRY bluegl_glWindowPos3i (GLint x, GLint y, GLint z) {
    typedef void (APIENTRYP PFN_glWindowPos3i) (GLint x, GLint y, GLint z);
    return ((PFN_glWindowPos3i)__blue_glCore_glWindowPos3i)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3iv;
void APIENTRY bluegl_glWindowPos3iv (const GLint *v) {
    typedef void (APIENTRYP PFN_glWindowPos3iv) (const GLint *v);
    return ((PFN_glWindowPos3iv)__blue_glCore_glWindowPos3iv)(v);
}

extern void* __blue_glCore_glWindowPos3s;
void APIENTRY bluegl_glWindowPos3s (GLshort x, GLshort y, GLshort z) {
    typedef void (APIENTRYP PFN_glWindowPos3s) (GLshort x, GLshort y, GLshort z);
    return ((PFN_glWindowPos3s)__blue_glCore_glWindowPos3s)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3sv;
void APIENTRY bluegl_glWindowPos3sv (const GLshort *v) {
    typedef void (APIENTRYP PFN_glWindowPos3sv) (const GLshort *v);
    return ((PFN_glWindowPos3sv)__blue_glCore_glWindowPos3sv)(v);
}

extern void* __blue_glCore_glVertexP2ui;
void APIENTRY bluegl_glVertexP2ui (GLenum type, GLuint value) {
    typedef void (APIENTRYP PFN_glVertexP2ui) (GLenum type, GLuint value);
    return ((PFN_glVertexP2ui)__blue_glCore_glVertexP2ui)(type, value);
}

extern void* __blue_glCore_glVertexP2uiv;
void APIENTRY bluegl_glVertexP2uiv (GLenum type, const GLuint *value) {
    typedef void (APIENTRYP PFN_glVertexP2uiv) (GLenum type, const GLuint *value);
    return ((PFN_glVertexP2uiv)__blue_glCore_glVertexP2uiv)(type, value);
}

extern void* __blue_glCore_glVertexP3ui;
void APIENTRY bluegl_glVertexP3ui (GLenum type, GLuint value) {
    typedef void (APIENTRYP PFN_glVertexP3ui) (GLenum type, GLuint value);
    return ((PFN_glVertexP3ui)__blue_glCore_glVertexP3ui)(type, value);
}

extern void* __blue_glCore_glVertexP3uiv;
void APIENTRY bluegl_glVertexP3uiv (GLenum type, const GLuint *value) {
    typedef void (APIENTRYP PFN_glVertexP3uiv) (GLenum type, const GLuint *value);
    return ((PFN_glVertexP3uiv)__blue_glCore_glVertexP3uiv)(type, value);
}

extern void* __blue_glCore_glVertexP4ui;
void APIENTRY bluegl_glVertexP4ui (GLenum type, GLuint value) {
    typedef void (APIENTRYP PFN_glVertexP4ui) (GLenum type, GLuint value);
    return ((PFN_glVertexP4ui)__blue_glCore_glVertexP4ui)(type, value);
}

extern void* __blue_glCore_glVertexP4uiv;
void APIENTRY bluegl_glVertexP4uiv (GLenum type, const GLuint *value) {
    typedef void (APIENTRYP PFN_glVertexP4uiv) (GLenum type, const GLuint *value);
    return ((PFN_glVertexP4uiv)__blue_glCore_glVertexP4uiv)(type, value);
}

extern void* __blue_glCore_glTexCoordP1ui;
void APIENTRY bluegl_glTexCoordP1ui (GLenum type, GLuint coords) {
    typedef void (APIENTRYP PFN_glTexCoordP1ui) (GLenum type, GLuint coords);
    return ((PFN_glTexCoordP1ui)__blue_glCore_glTexCoordP1ui)(type, coords);
}

extern void* __blue_glCore_glTexCoordP1uiv;
void APIENTRY bluegl_glTexCoordP1uiv (GLenum type, const GLuint *coords) {
    typedef void (APIENTRYP PFN_glTexCoordP1uiv) (GLenum type, const GLuint *coords);
    return ((PFN_glTexCoordP1uiv)__blue_glCore_glTexCoordP1uiv)(type, coords);
}

extern void* __blue_glCore_glTexCoordP2ui;
void APIENTRY bluegl_glTexCoordP2ui (GLenum type, GLuint coords) {
    typedef void (APIENTRYP PFN_glTexCoordP2ui) (GLenum type, GLuint coords);
    return ((PFN_glTexCoordP2ui)__blue_glCore_glTexCoordP2ui)(type, coords);
}

extern void* __blue_glCore_glTexCoordP2uiv;
void APIENTRY bluegl_glTexCoordP2uiv (GLenum type, const GLuint *coords) {
    typedef void (APIENTRYP PFN_glTexCoordP2uiv) (GLenum type, const GLuint *coords);
    return ((PFN_glTexCoordP2uiv)__blue_glCore_glTexCoordP2uiv)(type, coords);
}

extern void* __blue_glCore_glTexCoordP3ui;
void APIENTRY bluegl_glTexCoordP3ui (GLenum type, GLuint coords) {
    typedef void (APIENTRYP PFN_glTexCoordP3ui) (GLenum type, GLuint coords);
    return ((PFN_glTexCoordP3ui)__blue_glCore_glTexCoordP3ui)(type, coords);
}

extern void* __blue_glCore_glTexCoordP3uiv;
void APIENTRY bluegl_glTexCoordP3uiv (GLenum type, const GLuint *coords) {
    typedef void (APIENTRYP PFN_glTexCoordP3uiv) (GLenum type, const GLuint *coords);
    return ((PFN_glTexCoordP3uiv)__blue_glCore_glTexCoordP3uiv)(type, coords);
}

extern void* __blue_glCore_glTexCoordP4ui;
void APIENTRY bluegl_glTexCoordP4ui (GLenum type, GLuint coords) {
    typedef void (APIENTRYP PFN_glTexCoordP4ui) (GLenum type, GLuint coords);
    return ((PFN_glTexCoordP4ui)__blue_glCore_glTexCoordP4ui)(type, coords);
}

extern void* __blue_glCore_glTexCoordP4uiv;
void APIENTRY bluegl_glTexCoordP4uiv (GLenum type, const GLuint *coords) {
    typedef void (APIENTRYP PFN_glTexCoordP4uiv) (GLenum type, const GLuint *coords);
    return ((PFN_glTexCoordP4uiv)__blue_glCore_glTexCoordP4uiv)(type, coords);
}

extern void* __blue_glCore_glMultiTexCoordP1ui;
void APIENTRY bluegl_glMultiTexCoordP1ui (GLenum texture, GLenum type, GLuint coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoordP1ui) (GLenum texture, GLenum type, GLuint coords);
    return ((PFN_glMultiTexCoordP1ui)__blue_glCore_glMultiTexCoordP1ui)(texture, type, coords);
}

extern void* __blue_glCore_glMultiTexCoordP1uiv;
void APIENTRY bluegl_glMultiTexCoordP1uiv (GLenum texture, GLenum type, const GLuint *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoordP1uiv) (GLenum texture, GLenum type, const GLuint *coords);
    return ((PFN_glMultiTexCoordP1uiv)__blue_glCore_glMultiTexCoordP1uiv)(texture, type, coords);
}

extern void* __blue_glCore_glMultiTexCoordP2ui;
void APIENTRY bluegl_glMultiTexCoordP2ui (GLenum texture, GLenum type, GLuint coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoordP2ui) (GLenum texture, GLenum type, GLuint coords);
    return ((PFN_glMultiTexCoordP2ui)__blue_glCore_glMultiTexCoordP2ui)(texture, type, coords);
}

extern void* __blue_glCore_glMultiTexCoordP2uiv;
void APIENTRY bluegl_glMultiTexCoordP2uiv (GLenum texture, GLenum type, const GLuint *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoordP2uiv) (GLenum texture, GLenum type, const GLuint *coords);
    return ((PFN_glMultiTexCoordP2uiv)__blue_glCore_glMultiTexCoordP2uiv)(texture, type, coords);
}

extern void* __blue_glCore_glMultiTexCoordP3ui;
void APIENTRY bluegl_glMultiTexCoordP3ui (GLenum texture, GLenum type, GLuint coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoordP3ui) (GLenum texture, GLenum type, GLuint coords);
    return ((PFN_glMultiTexCoordP3ui)__blue_glCore_glMultiTexCoordP3ui)(texture, type, coords);
}

extern void* __blue_glCore_glMultiTexCoordP3uiv;
void APIENTRY bluegl_glMultiTexCoordP3uiv (GLenum texture, GLenum type, const GLuint *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoordP3uiv) (GLenum texture, GLenum type, const GLuint *coords);
    return ((PFN_glMultiTexCoordP3uiv)__blue_glCore_glMultiTexCoordP3uiv)(texture, type, coords);
}

extern void* __blue_glCore_glMultiTexCoordP4ui;
void APIENTRY bluegl_glMultiTexCoordP4ui (GLenum texture, GLenum type, GLuint coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoordP4ui) (GLenum texture, GLenum type, GLuint coords);
    return ((PFN_glMultiTexCoordP4ui)__blue_glCore_glMultiTexCoordP4ui)(texture, type, coords);
}

extern void* __blue_glCore_glMultiTexCoordP4uiv;
void APIENTRY bluegl_glMultiTexCoordP4uiv (GLenum texture, GLenum type, const GLuint *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoordP4uiv) (GLenum texture, GLenum type, const GLuint *coords);
    return ((PFN_glMultiTexCoordP4uiv)__blue_glCore_glMultiTexCoordP4uiv)(texture, type, coords);
}

extern void* __blue_glCore_glNormalP3ui;
void APIENTRY bluegl_glNormalP3ui (GLenum type, GLuint coords) {
    typedef void (APIENTRYP PFN_glNormalP3ui) (GLenum type, GLuint coords);
    return ((PFN_glNormalP3ui)__blue_glCore_glNormalP3ui)(type, coords);
}

extern void* __blue_glCore_glNormalP3uiv;
void APIENTRY bluegl_glNormalP3uiv (GLenum type, const GLuint *coords) {
    typedef void (APIENTRYP PFN_glNormalP3uiv) (GLenum type, const GLuint *coords);
    return ((PFN_glNormalP3uiv)__blue_glCore_glNormalP3uiv)(type, coords);
}

extern void* __blue_glCore_glColorP3ui;
void APIENTRY bluegl_glColorP3ui (GLenum type, GLuint color) {
    typedef void (APIENTRYP PFN_glColorP3ui) (GLenum type, GLuint color);
    return ((PFN_glColorP3ui)__blue_glCore_glColorP3ui)(type, color);
}

extern void* __blue_glCore_glColorP3uiv;
void APIENTRY bluegl_glColorP3uiv (GLenum type, const GLuint *color) {
    typedef void (APIENTRYP PFN_glColorP3uiv) (GLenum type, const GLuint *color);
    return ((PFN_glColorP3uiv)__blue_glCore_glColorP3uiv)(type, color);
}

extern void* __blue_glCore_glColorP4ui;
void APIENTRY bluegl_glColorP4ui (GLenum type, GLuint color) {
    typedef void (APIENTRYP PFN_glColorP4ui) (GLenum type, GLuint color);
    return ((PFN_glColorP4ui)__blue_glCore_glColorP4ui)(type, color);
}

extern void* __blue_glCore_glColorP4uiv;
void APIENTRY bluegl_glColorP4uiv (GLenum type, const GLuint *color) {
    typedef void (APIENTRYP PFN_glColorP4uiv) (GLenum type, const GLuint *color);
    return ((PFN_glColorP4uiv)__blue_glCore_glColorP4uiv)(type, color);
}

extern void* __blue_glCore_glSecondaryColorP3ui;
void APIENTRY bluegl_glSecondaryColorP3ui (GLenum type, GLuint color) {
    typedef void (APIENTRYP PFN_glSecondaryColorP3ui) (GLenum type, GLuint color);
    return ((PFN_glSecondaryColorP3ui)__blue_glCore_glSecondaryColorP3ui)(type, color);
}

extern void* __blue_glCore_glSecondaryColorP3uiv;
void APIENTRY bluegl_glSecondaryColorP3uiv (GLenum type, const GLuint *color) {
    typedef void (APIENTRYP PFN_glSecondaryColorP3uiv) (GLenum type, const GLuint *color);
    return ((PFN_glSecondaryColorP3uiv)__blue_glCore_glSecondaryColorP3uiv)(type, color);
}

extern void* __blue_glCore_glGetnMapdv;
void APIENTRY bluegl_glGetnMapdv (GLenum target, GLenum query, GLsizei bufSize, GLdouble *v) {
    typedef void (APIENTRYP PFN_glGetnMapdv) (GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
    return ((PFN_glGetnMapdv)__blue_glCore_glGetnMapdv)(target, query, bufSize, v);
}

extern void* __blue_glCore_glGetnMapfv;
void APIENTRY bluegl_glGetnMapfv (GLenum target, GLenum query, GLsizei bufSize, GLfloat *v) {
    typedef void (APIENTRYP PFN_glGetnMapfv) (GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
    return ((PFN_glGetnMapfv)__blue_glCore_glGetnMapfv)(target, query, bufSize, v);
}

extern void* __blue_glCore_glGetnMapiv;
void APIENTRY bluegl_glGetnMapiv (GLenum target, GLenum query, GLsizei bufSize, GLint *v) {
    typedef void (APIENTRYP PFN_glGetnMapiv) (GLenum target, GLenum query, GLsizei bufSize, GLint *v);
    return ((PFN_glGetnMapiv)__blue_glCore_glGetnMapiv)(target, query, bufSize, v);
}

extern void* __blue_glCore_glGetnPixelMapfv;
void APIENTRY bluegl_glGetnPixelMapfv (GLenum map, GLsizei bufSize, GLfloat *values) {
    typedef void (APIENTRYP PFN_glGetnPixelMapfv) (GLenum map, GLsizei bufSize, GLfloat *values);
    return ((PFN_glGetnPixelMapfv)__blue_glCore_glGetnPixelMapfv)(map, bufSize, values);
}

extern void* __blue_glCore_glGetnPixelMapuiv;
void APIENTRY bluegl_glGetnPixelMapuiv (GLenum map, GLsizei bufSize, GLuint *values) {
    typedef void (APIENTRYP PFN_glGetnPixelMapuiv) (GLenum map, GLsizei bufSize, GLuint *values);
    return ((PFN_glGetnPixelMapuiv)__blue_glCore_glGetnPixelMapuiv)(map, bufSize, values);
}

extern void* __blue_glCore_glGetnPixelMapusv;
void APIENTRY bluegl_glGetnPixelMapusv (GLenum map, GLsizei bufSize, GLushort *values) {
    typedef void (APIENTRYP PFN_glGetnPixelMapusv) (GLenum map, GLsizei bufSize, GLushort *values);
    return ((PFN_glGetnPixelMapusv)__blue_glCore_glGetnPixelMapusv)(map, bufSize, values);
}

extern void* __blue_glCore_glGetnPolygonStipple;
void APIENTRY bluegl_glGetnPolygonStipple (GLsizei bufSize, GLubyte *pattern) {
    typedef void (APIENTRYP PFN_glGetnPolygonStipple) (GLsizei bufSize, GLubyte *pattern);
    return ((PFN_glGetnPolygonStipple)__blue_glCore_glGetnPolygonStipple)(bufSize, pattern);
}

extern void* __blue_glCore_glGetnColorTable;
void APIENTRY bluegl_glGetnColorTable (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table) {
    typedef void (APIENTRYP PFN_glGetnColorTable) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
    return ((PFN_glGetnColorTable)__blue_glCore_glGetnColorTable)(target, format, type, bufSize, table);
}

extern void* __blue_glCore_glGetnConvolutionFilter;
void APIENTRY bluegl_glGetnConvolutionFilter (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image) {
    typedef void (APIENTRYP PFN_glGetnConvolutionFilter) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
    return ((PFN_glGetnConvolutionFilter)__blue_glCore_glGetnConvolutionFilter)(target, format, type, bufSize, image);
}

extern void* __blue_glCore_glGetnSeparableFilter;
void APIENTRY bluegl_glGetnSeparableFilter (GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span) {
    typedef void (APIENTRYP PFN_glGetnSeparableFilter) (GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
    return ((PFN_glGetnSeparableFilter)__blue_glCore_glGetnSeparableFilter)(target, format, type, rowBufSize, row, columnBufSize, column, span);
}

extern void* __blue_glCore_glGetnHistogram;
void APIENTRY bluegl_glGetnHistogram (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) {
    typedef void (APIENTRYP PFN_glGetnHistogram) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
    return ((PFN_glGetnHistogram)__blue_glCore_glGetnHistogram)(target, reset, format, type, bufSize, values);
}

extern void* __blue_glCore_glGetnMinmax;
void APIENTRY bluegl_glGetnMinmax (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) {
    typedef void (APIENTRYP PFN_glGetnMinmax) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
    return ((PFN_glGetnMinmax)__blue_glCore_glGetnMinmax)(target, reset, format, type, bufSize, values);
}

extern void* __blue_glCore_glPrimitiveBoundingBoxARB;
void APIENTRY bluegl_glPrimitiveBoundingBoxARB (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {
    typedef void (APIENTRYP PFN_glPrimitiveBoundingBoxARB) (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
    return ((PFN_glPrimitiveBoundingBoxARB)__blue_glCore_glPrimitiveBoundingBoxARB)(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}

extern void* __blue_glCore_glClampColorARB;
void APIENTRY bluegl_glClampColorARB (GLenum target, GLenum clamp) {
    typedef void (APIENTRYP PFN_glClampColorARB) (GLenum target, GLenum clamp);
    return ((PFN_glClampColorARB)__blue_glCore_glClampColorARB)(target, clamp);
}

extern void* __blue_glCore_glDrawBuffersARB;
void APIENTRY bluegl_glDrawBuffersARB (GLsizei n, const GLenum *bufs) {
    typedef void (APIENTRYP PFN_glDrawBuffersARB) (GLsizei n, const GLenum *bufs);
    return ((PFN_glDrawBuffersARB)__blue_glCore_glDrawBuffersARB)(n, bufs);
}

extern void* __blue_glCore_glDrawArraysInstancedARB;
void APIENTRY bluegl_glDrawArraysInstancedARB (GLenum mode, GLint first, GLsizei count, GLsizei primcount) {
    typedef void (APIENTRYP PFN_glDrawArraysInstancedARB) (GLenum mode, GLint first, GLsizei count, GLsizei primcount);
    return ((PFN_glDrawArraysInstancedARB)__blue_glCore_glDrawArraysInstancedARB)(mode, first, count, primcount);
}

extern void* __blue_glCore_glDrawElementsInstancedARB;
void APIENTRY bluegl_glDrawElementsInstancedARB (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount) {
    typedef void (APIENTRYP PFN_glDrawElementsInstancedARB) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
    return ((PFN_glDrawElementsInstancedARB)__blue_glCore_glDrawElementsInstancedARB)(mode, count, type, indices, primcount);
}

extern void* __blue_glCore_glProgramStringARB;
void APIENTRY bluegl_glProgramStringARB (GLenum target, GLenum format, GLsizei len, const void *string) {
    typedef void (APIENTRYP PFN_glProgramStringARB) (GLenum target, GLenum format, GLsizei len, const void *string);
    return ((PFN_glProgramStringARB)__blue_glCore_glProgramStringARB)(target, format, len, string);
}

extern void* __blue_glCore_glBindProgramARB;
void APIENTRY bluegl_glBindProgramARB (GLenum target, GLuint program) {
    typedef void (APIENTRYP PFN_glBindProgramARB) (GLenum target, GLuint program);
    return ((PFN_glBindProgramARB)__blue_glCore_glBindProgramARB)(target, program);
}

extern void* __blue_glCore_glDeleteProgramsARB;
void APIENTRY bluegl_glDeleteProgramsARB (GLsizei n, const GLuint *programs) {
    typedef void (APIENTRYP PFN_glDeleteProgramsARB) (GLsizei n, const GLuint *programs);
    return ((PFN_glDeleteProgramsARB)__blue_glCore_glDeleteProgramsARB)(n, programs);
}

extern void* __blue_glCore_glGenProgramsARB;
void APIENTRY bluegl_glGenProgramsARB (GLsizei n, GLuint *programs) {
    typedef void (APIENTRYP PFN_glGenProgramsARB) (GLsizei n, GLuint *programs);
    return ((PFN_glGenProgramsARB)__blue_glCore_glGenProgramsARB)(n, programs);
}

extern void* __blue_glCore_glProgramEnvParameter4dARB;
void APIENTRY bluegl_glProgramEnvParameter4dARB (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glProgramEnvParameter4dARB) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glProgramEnvParameter4dARB)__blue_glCore_glProgramEnvParameter4dARB)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramEnvParameter4dvARB;
void APIENTRY bluegl_glProgramEnvParameter4dvARB (GLenum target, GLuint index, const GLdouble *params) {
    typedef void (APIENTRYP PFN_glProgramEnvParameter4dvARB) (GLenum target, GLuint index, const GLdouble *params);
    return ((PFN_glProgramEnvParameter4dvARB)__blue_glCore_glProgramEnvParameter4dvARB)(target, index, params);
}

extern void* __blue_glCore_glProgramEnvParameter4fARB;
void APIENTRY bluegl_glProgramEnvParameter4fARB (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glProgramEnvParameter4fARB) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glProgramEnvParameter4fARB)__blue_glCore_glProgramEnvParameter4fARB)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramEnvParameter4fvARB;
void APIENTRY bluegl_glProgramEnvParameter4fvARB (GLenum target, GLuint index, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glProgramEnvParameter4fvARB) (GLenum target, GLuint index, const GLfloat *params);
    return ((PFN_glProgramEnvParameter4fvARB)__blue_glCore_glProgramEnvParameter4fvARB)(target, index, params);
}

extern void* __blue_glCore_glProgramLocalParameter4dARB;
void APIENTRY bluegl_glProgramLocalParameter4dARB (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glProgramLocalParameter4dARB) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glProgramLocalParameter4dARB)__blue_glCore_glProgramLocalParameter4dARB)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramLocalParameter4dvARB;
void APIENTRY bluegl_glProgramLocalParameter4dvARB (GLenum target, GLuint index, const GLdouble *params) {
    typedef void (APIENTRYP PFN_glProgramLocalParameter4dvARB) (GLenum target, GLuint index, const GLdouble *params);
    return ((PFN_glProgramLocalParameter4dvARB)__blue_glCore_glProgramLocalParameter4dvARB)(target, index, params);
}

extern void* __blue_glCore_glProgramLocalParameter4fARB;
void APIENTRY bluegl_glProgramLocalParameter4fARB (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glProgramLocalParameter4fARB) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glProgramLocalParameter4fARB)__blue_glCore_glProgramLocalParameter4fARB)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramLocalParameter4fvARB;
void APIENTRY bluegl_glProgramLocalParameter4fvARB (GLenum target, GLuint index, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glProgramLocalParameter4fvARB) (GLenum target, GLuint index, const GLfloat *params);
    return ((PFN_glProgramLocalParameter4fvARB)__blue_glCore_glProgramLocalParameter4fvARB)(target, index, params);
}

extern void* __blue_glCore_glGetProgramEnvParameterdvARB;
void APIENTRY bluegl_glGetProgramEnvParameterdvARB (GLenum target, GLuint index, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetProgramEnvParameterdvARB) (GLenum target, GLuint index, GLdouble *params);
    return ((PFN_glGetProgramEnvParameterdvARB)__blue_glCore_glGetProgramEnvParameterdvARB)(target, index, params);
}

extern void* __blue_glCore_glGetProgramEnvParameterfvARB;
void APIENTRY bluegl_glGetProgramEnvParameterfvARB (GLenum target, GLuint index, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetProgramEnvParameterfvARB) (GLenum target, GLuint index, GLfloat *params);
    return ((PFN_glGetProgramEnvParameterfvARB)__blue_glCore_glGetProgramEnvParameterfvARB)(target, index, params);
}

extern void* __blue_glCore_glGetProgramLocalParameterdvARB;
void APIENTRY bluegl_glGetProgramLocalParameterdvARB (GLenum target, GLuint index, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetProgramLocalParameterdvARB) (GLenum target, GLuint index, GLdouble *params);
    return ((PFN_glGetProgramLocalParameterdvARB)__blue_glCore_glGetProgramLocalParameterdvARB)(target, index, params);
}

extern void* __blue_glCore_glGetProgramLocalParameterfvARB;
void APIENTRY bluegl_glGetProgramLocalParameterfvARB (GLenum target, GLuint index, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetProgramLocalParameterfvARB) (GLenum target, GLuint index, GLfloat *params);
    return ((PFN_glGetProgramLocalParameterfvARB)__blue_glCore_glGetProgramLocalParameterfvARB)(target, index, params);
}

extern void* __blue_glCore_glGetProgramivARB;
void APIENTRY bluegl_glGetProgramivARB (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetProgramivARB) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetProgramivARB)__blue_glCore_glGetProgramivARB)(target, pname, params);
}

extern void* __blue_glCore_glGetProgramStringARB;
void APIENTRY bluegl_glGetProgramStringARB (GLenum target, GLenum pname, void *string) {
    typedef void (APIENTRYP PFN_glGetProgramStringARB) (GLenum target, GLenum pname, void *string);
    return ((PFN_glGetProgramStringARB)__blue_glCore_glGetProgramStringARB)(target, pname, string);
}

extern void* __blue_glCore_glIsProgramARB;
GLboolean APIENTRY bluegl_glIsProgramARB (GLuint program) {
    typedef GLboolean (APIENTRYP PFN_glIsProgramARB) (GLuint program);
    return ((PFN_glIsProgramARB)__blue_glCore_glIsProgramARB)(program);
}

extern void* __blue_glCore_glProgramParameteriARB;
void APIENTRY bluegl_glProgramParameteriARB (GLuint program, GLenum pname, GLint value) {
    typedef void (APIENTRYP PFN_glProgramParameteriARB) (GLuint program, GLenum pname, GLint value);
    return ((PFN_glProgramParameteriARB)__blue_glCore_glProgramParameteriARB)(program, pname, value);
}

extern void* __blue_glCore_glFramebufferTextureARB;
void APIENTRY bluegl_glFramebufferTextureARB (GLenum target, GLenum attachment, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glFramebufferTextureARB) (GLenum target, GLenum attachment, GLuint texture, GLint level);
    return ((PFN_glFramebufferTextureARB)__blue_glCore_glFramebufferTextureARB)(target, attachment, texture, level);
}

extern void* __blue_glCore_glFramebufferTextureLayerARB;
void APIENTRY bluegl_glFramebufferTextureLayerARB (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    typedef void (APIENTRYP PFN_glFramebufferTextureLayerARB) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
    return ((PFN_glFramebufferTextureLayerARB)__blue_glCore_glFramebufferTextureLayerARB)(target, attachment, texture, level, layer);
}

extern void* __blue_glCore_glFramebufferTextureFaceARB;
void APIENTRY bluegl_glFramebufferTextureFaceARB (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) {
    typedef void (APIENTRYP PFN_glFramebufferTextureFaceARB) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
    return ((PFN_glFramebufferTextureFaceARB)__blue_glCore_glFramebufferTextureFaceARB)(target, attachment, texture, level, face);
}

extern void* __blue_glCore_glUniform1i64ARB;
void APIENTRY bluegl_glUniform1i64ARB (GLint location, GLint64 x) {
    typedef void (APIENTRYP PFN_glUniform1i64ARB) (GLint location, GLint64 x);
    return ((PFN_glUniform1i64ARB)__blue_glCore_glUniform1i64ARB)(location, x);
}

extern void* __blue_glCore_glUniform2i64ARB;
void APIENTRY bluegl_glUniform2i64ARB (GLint location, GLint64 x, GLint64 y) {
    typedef void (APIENTRYP PFN_glUniform2i64ARB) (GLint location, GLint64 x, GLint64 y);
    return ((PFN_glUniform2i64ARB)__blue_glCore_glUniform2i64ARB)(location, x, y);
}

extern void* __blue_glCore_glUniform3i64ARB;
void APIENTRY bluegl_glUniform3i64ARB (GLint location, GLint64 x, GLint64 y, GLint64 z) {
    typedef void (APIENTRYP PFN_glUniform3i64ARB) (GLint location, GLint64 x, GLint64 y, GLint64 z);
    return ((PFN_glUniform3i64ARB)__blue_glCore_glUniform3i64ARB)(location, x, y, z);
}

extern void* __blue_glCore_glUniform4i64ARB;
void APIENTRY bluegl_glUniform4i64ARB (GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) {
    typedef void (APIENTRYP PFN_glUniform4i64ARB) (GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
    return ((PFN_glUniform4i64ARB)__blue_glCore_glUniform4i64ARB)(location, x, y, z, w);
}

extern void* __blue_glCore_glUniform1i64vARB;
void APIENTRY bluegl_glUniform1i64vARB (GLint location, GLsizei count, const GLint64 *value) {
    typedef void (APIENTRYP PFN_glUniform1i64vARB) (GLint location, GLsizei count, const GLint64 *value);
    return ((PFN_glUniform1i64vARB)__blue_glCore_glUniform1i64vARB)(location, count, value);
}

extern void* __blue_glCore_glUniform2i64vARB;
void APIENTRY bluegl_glUniform2i64vARB (GLint location, GLsizei count, const GLint64 *value) {
    typedef void (APIENTRYP PFN_glUniform2i64vARB) (GLint location, GLsizei count, const GLint64 *value);
    return ((PFN_glUniform2i64vARB)__blue_glCore_glUniform2i64vARB)(location, count, value);
}

extern void* __blue_glCore_glUniform3i64vARB;
void APIENTRY bluegl_glUniform3i64vARB (GLint location, GLsizei count, const GLint64 *value) {
    typedef void (APIENTRYP PFN_glUniform3i64vARB) (GLint location, GLsizei count, const GLint64 *value);
    return ((PFN_glUniform3i64vARB)__blue_glCore_glUniform3i64vARB)(location, count, value);
}

extern void* __blue_glCore_glUniform4i64vARB;
void APIENTRY bluegl_glUniform4i64vARB (GLint location, GLsizei count, const GLint64 *value) {
    typedef void (APIENTRYP PFN_glUniform4i64vARB) (GLint location, GLsizei count, const GLint64 *value);
    return ((PFN_glUniform4i64vARB)__blue_glCore_glUniform4i64vARB)(location, count, value);
}

extern void* __blue_glCore_glUniform1ui64ARB;
void APIENTRY bluegl_glUniform1ui64ARB (GLint location, GLuint64 x) {
    typedef void (APIENTRYP PFN_glUniform1ui64ARB) (GLint location, GLuint64 x);
    return ((PFN_glUniform1ui64ARB)__blue_glCore_glUniform1ui64ARB)(location, x);
}

extern void* __blue_glCore_glUniform2ui64ARB;
void APIENTRY bluegl_glUniform2ui64ARB (GLint location, GLuint64 x, GLuint64 y) {
    typedef void (APIENTRYP PFN_glUniform2ui64ARB) (GLint location, GLuint64 x, GLuint64 y);
    return ((PFN_glUniform2ui64ARB)__blue_glCore_glUniform2ui64ARB)(location, x, y);
}

extern void* __blue_glCore_glUniform3ui64ARB;
void APIENTRY bluegl_glUniform3ui64ARB (GLint location, GLuint64 x, GLuint64 y, GLuint64 z) {
    typedef void (APIENTRYP PFN_glUniform3ui64ARB) (GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
    return ((PFN_glUniform3ui64ARB)__blue_glCore_glUniform3ui64ARB)(location, x, y, z);
}

extern void* __blue_glCore_glUniform4ui64ARB;
void APIENTRY bluegl_glUniform4ui64ARB (GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) {
    typedef void (APIENTRYP PFN_glUniform4ui64ARB) (GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
    return ((PFN_glUniform4ui64ARB)__blue_glCore_glUniform4ui64ARB)(location, x, y, z, w);
}

extern void* __blue_glCore_glUniform1ui64vARB;
void APIENTRY bluegl_glUniform1ui64vARB (GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glUniform1ui64vARB) (GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glUniform1ui64vARB)__blue_glCore_glUniform1ui64vARB)(location, count, value);
}

extern void* __blue_glCore_glUniform2ui64vARB;
void APIENTRY bluegl_glUniform2ui64vARB (GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glUniform2ui64vARB) (GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glUniform2ui64vARB)__blue_glCore_glUniform2ui64vARB)(location, count, value);
}

extern void* __blue_glCore_glUniform3ui64vARB;
void APIENTRY bluegl_glUniform3ui64vARB (GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glUniform3ui64vARB) (GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glUniform3ui64vARB)__blue_glCore_glUniform3ui64vARB)(location, count, value);
}

extern void* __blue_glCore_glUniform4ui64vARB;
void APIENTRY bluegl_glUniform4ui64vARB (GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glUniform4ui64vARB) (GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glUniform4ui64vARB)__blue_glCore_glUniform4ui64vARB)(location, count, value);
}

extern void* __blue_glCore_glGetUniformi64vARB;
void APIENTRY bluegl_glGetUniformi64vARB (GLuint program, GLint location, GLint64 *params) {
    typedef void (APIENTRYP PFN_glGetUniformi64vARB) (GLuint program, GLint location, GLint64 *params);
    return ((PFN_glGetUniformi64vARB)__blue_glCore_glGetUniformi64vARB)(program, location, params);
}

extern void* __blue_glCore_glGetUniformui64vARB;
void APIENTRY bluegl_glGetUniformui64vARB (GLuint program, GLint location, GLuint64 *params) {
    typedef void (APIENTRYP PFN_glGetUniformui64vARB) (GLuint program, GLint location, GLuint64 *params);
    return ((PFN_glGetUniformui64vARB)__blue_glCore_glGetUniformui64vARB)(program, location, params);
}

extern void* __blue_glCore_glGetnUniformi64vARB;
void APIENTRY bluegl_glGetnUniformi64vARB (GLuint program, GLint location, GLsizei bufSize, GLint64 *params) {
    typedef void (APIENTRYP PFN_glGetnUniformi64vARB) (GLuint program, GLint location, GLsizei bufSize, GLint64 *params);
    return ((PFN_glGetnUniformi64vARB)__blue_glCore_glGetnUniformi64vARB)(program, location, bufSize, params);
}

extern void* __blue_glCore_glGetnUniformui64vARB;
void APIENTRY bluegl_glGetnUniformui64vARB (GLuint program, GLint location, GLsizei bufSize, GLuint64 *params) {
    typedef void (APIENTRYP PFN_glGetnUniformui64vARB) (GLuint program, GLint location, GLsizei bufSize, GLuint64 *params);
    return ((PFN_glGetnUniformui64vARB)__blue_glCore_glGetnUniformui64vARB)(program, location, bufSize, params);
}

extern void* __blue_glCore_glProgramUniform1i64ARB;
void APIENTRY bluegl_glProgramUniform1i64ARB (GLuint program, GLint location, GLint64 x) {
    typedef void (APIENTRYP PFN_glProgramUniform1i64ARB) (GLuint program, GLint location, GLint64 x);
    return ((PFN_glProgramUniform1i64ARB)__blue_glCore_glProgramUniform1i64ARB)(program, location, x);
}

extern void* __blue_glCore_glProgramUniform2i64ARB;
void APIENTRY bluegl_glProgramUniform2i64ARB (GLuint program, GLint location, GLint64 x, GLint64 y) {
    typedef void (APIENTRYP PFN_glProgramUniform2i64ARB) (GLuint program, GLint location, GLint64 x, GLint64 y);
    return ((PFN_glProgramUniform2i64ARB)__blue_glCore_glProgramUniform2i64ARB)(program, location, x, y);
}

extern void* __blue_glCore_glProgramUniform3i64ARB;
void APIENTRY bluegl_glProgramUniform3i64ARB (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z) {
    typedef void (APIENTRYP PFN_glProgramUniform3i64ARB) (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
    return ((PFN_glProgramUniform3i64ARB)__blue_glCore_glProgramUniform3i64ARB)(program, location, x, y, z);
}

extern void* __blue_glCore_glProgramUniform4i64ARB;
void APIENTRY bluegl_glProgramUniform4i64ARB (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) {
    typedef void (APIENTRYP PFN_glProgramUniform4i64ARB) (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
    return ((PFN_glProgramUniform4i64ARB)__blue_glCore_glProgramUniform4i64ARB)(program, location, x, y, z, w);
}

extern void* __blue_glCore_glProgramUniform1i64vARB;
void APIENTRY bluegl_glProgramUniform1i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1i64vARB) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
    return ((PFN_glProgramUniform1i64vARB)__blue_glCore_glProgramUniform1i64vARB)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2i64vARB;
void APIENTRY bluegl_glProgramUniform2i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2i64vARB) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
    return ((PFN_glProgramUniform2i64vARB)__blue_glCore_glProgramUniform2i64vARB)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3i64vARB;
void APIENTRY bluegl_glProgramUniform3i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3i64vARB) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
    return ((PFN_glProgramUniform3i64vARB)__blue_glCore_glProgramUniform3i64vARB)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4i64vARB;
void APIENTRY bluegl_glProgramUniform4i64vARB (GLuint program, GLint location, GLsizei count, const GLint64 *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4i64vARB) (GLuint program, GLint location, GLsizei count, const GLint64 *value);
    return ((PFN_glProgramUniform4i64vARB)__blue_glCore_glProgramUniform4i64vARB)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform1ui64ARB;
void APIENTRY bluegl_glProgramUniform1ui64ARB (GLuint program, GLint location, GLuint64 x) {
    typedef void (APIENTRYP PFN_glProgramUniform1ui64ARB) (GLuint program, GLint location, GLuint64 x);
    return ((PFN_glProgramUniform1ui64ARB)__blue_glCore_glProgramUniform1ui64ARB)(program, location, x);
}

extern void* __blue_glCore_glProgramUniform2ui64ARB;
void APIENTRY bluegl_glProgramUniform2ui64ARB (GLuint program, GLint location, GLuint64 x, GLuint64 y) {
    typedef void (APIENTRYP PFN_glProgramUniform2ui64ARB) (GLuint program, GLint location, GLuint64 x, GLuint64 y);
    return ((PFN_glProgramUniform2ui64ARB)__blue_glCore_glProgramUniform2ui64ARB)(program, location, x, y);
}

extern void* __blue_glCore_glProgramUniform3ui64ARB;
void APIENTRY bluegl_glProgramUniform3ui64ARB (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z) {
    typedef void (APIENTRYP PFN_glProgramUniform3ui64ARB) (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
    return ((PFN_glProgramUniform3ui64ARB)__blue_glCore_glProgramUniform3ui64ARB)(program, location, x, y, z);
}

extern void* __blue_glCore_glProgramUniform4ui64ARB;
void APIENTRY bluegl_glProgramUniform4ui64ARB (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) {
    typedef void (APIENTRYP PFN_glProgramUniform4ui64ARB) (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
    return ((PFN_glProgramUniform4ui64ARB)__blue_glCore_glProgramUniform4ui64ARB)(program, location, x, y, z, w);
}

extern void* __blue_glCore_glProgramUniform1ui64vARB;
void APIENTRY bluegl_glProgramUniform1ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1ui64vARB) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glProgramUniform1ui64vARB)__blue_glCore_glProgramUniform1ui64vARB)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2ui64vARB;
void APIENTRY bluegl_glProgramUniform2ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2ui64vARB) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glProgramUniform2ui64vARB)__blue_glCore_glProgramUniform2ui64vARB)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3ui64vARB;
void APIENTRY bluegl_glProgramUniform3ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3ui64vARB) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glProgramUniform3ui64vARB)__blue_glCore_glProgramUniform3ui64vARB)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4ui64vARB;
void APIENTRY bluegl_glProgramUniform4ui64vARB (GLuint program, GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4ui64vARB) (GLuint program, GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glProgramUniform4ui64vARB)__blue_glCore_glProgramUniform4ui64vARB)(program, location, count, value);
}

extern void* __blue_glCore_glColorTable;
void APIENTRY bluegl_glColorTable (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table) {
    typedef void (APIENTRYP PFN_glColorTable) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
    return ((PFN_glColorTable)__blue_glCore_glColorTable)(target, internalformat, width, format, type, table);
}

extern void* __blue_glCore_glColorTableParameterfv;
void APIENTRY bluegl_glColorTableParameterfv (GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glColorTableParameterfv) (GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glColorTableParameterfv)__blue_glCore_glColorTableParameterfv)(target, pname, params);
}

extern void* __blue_glCore_glColorTableParameteriv;
void APIENTRY bluegl_glColorTableParameteriv (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glColorTableParameteriv) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glColorTableParameteriv)__blue_glCore_glColorTableParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glCopyColorTable;
void APIENTRY bluegl_glCopyColorTable (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyColorTable) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyColorTable)__blue_glCore_glCopyColorTable)(target, internalformat, x, y, width);
}

extern void* __blue_glCore_glGetColorTable;
void APIENTRY bluegl_glGetColorTable (GLenum target, GLenum format, GLenum type, void *table) {
    typedef void (APIENTRYP PFN_glGetColorTable) (GLenum target, GLenum format, GLenum type, void *table);
    return ((PFN_glGetColorTable)__blue_glCore_glGetColorTable)(target, format, type, table);
}

extern void* __blue_glCore_glGetColorTableParameterfv;
void APIENTRY bluegl_glGetColorTableParameterfv (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetColorTableParameterfv) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetColorTableParameterfv)__blue_glCore_glGetColorTableParameterfv)(target, pname, params);
}

extern void* __blue_glCore_glGetColorTableParameteriv;
void APIENTRY bluegl_glGetColorTableParameteriv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetColorTableParameteriv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetColorTableParameteriv)__blue_glCore_glGetColorTableParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glColorSubTable;
void APIENTRY bluegl_glColorSubTable (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glColorSubTable) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
    return ((PFN_glColorSubTable)__blue_glCore_glColorSubTable)(target, start, count, format, type, data);
}

extern void* __blue_glCore_glCopyColorSubTable;
void APIENTRY bluegl_glCopyColorSubTable (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyColorSubTable) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyColorSubTable)__blue_glCore_glCopyColorSubTable)(target, start, x, y, width);
}

extern void* __blue_glCore_glConvolutionFilter1D;
void APIENTRY bluegl_glConvolutionFilter1D (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image) {
    typedef void (APIENTRYP PFN_glConvolutionFilter1D) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
    return ((PFN_glConvolutionFilter1D)__blue_glCore_glConvolutionFilter1D)(target, internalformat, width, format, type, image);
}

extern void* __blue_glCore_glConvolutionFilter2D;
void APIENTRY bluegl_glConvolutionFilter2D (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image) {
    typedef void (APIENTRYP PFN_glConvolutionFilter2D) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
    return ((PFN_glConvolutionFilter2D)__blue_glCore_glConvolutionFilter2D)(target, internalformat, width, height, format, type, image);
}

extern void* __blue_glCore_glConvolutionParameterf;
void APIENTRY bluegl_glConvolutionParameterf (GLenum target, GLenum pname, GLfloat params) {
    typedef void (APIENTRYP PFN_glConvolutionParameterf) (GLenum target, GLenum pname, GLfloat params);
    return ((PFN_glConvolutionParameterf)__blue_glCore_glConvolutionParameterf)(target, pname, params);
}

extern void* __blue_glCore_glConvolutionParameterfv;
void APIENTRY bluegl_glConvolutionParameterfv (GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glConvolutionParameterfv) (GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glConvolutionParameterfv)__blue_glCore_glConvolutionParameterfv)(target, pname, params);
}

extern void* __blue_glCore_glConvolutionParameteri;
void APIENTRY bluegl_glConvolutionParameteri (GLenum target, GLenum pname, GLint params) {
    typedef void (APIENTRYP PFN_glConvolutionParameteri) (GLenum target, GLenum pname, GLint params);
    return ((PFN_glConvolutionParameteri)__blue_glCore_glConvolutionParameteri)(target, pname, params);
}

extern void* __blue_glCore_glConvolutionParameteriv;
void APIENTRY bluegl_glConvolutionParameteriv (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glConvolutionParameteriv) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glConvolutionParameteriv)__blue_glCore_glConvolutionParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glCopyConvolutionFilter1D;
void APIENTRY bluegl_glCopyConvolutionFilter1D (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyConvolutionFilter1D) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyConvolutionFilter1D)__blue_glCore_glCopyConvolutionFilter1D)(target, internalformat, x, y, width);
}

extern void* __blue_glCore_glCopyConvolutionFilter2D;
void APIENTRY bluegl_glCopyConvolutionFilter2D (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyConvolutionFilter2D) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyConvolutionFilter2D)__blue_glCore_glCopyConvolutionFilter2D)(target, internalformat, x, y, width, height);
}

extern void* __blue_glCore_glGetConvolutionFilter;
void APIENTRY bluegl_glGetConvolutionFilter (GLenum target, GLenum format, GLenum type, void *image) {
    typedef void (APIENTRYP PFN_glGetConvolutionFilter) (GLenum target, GLenum format, GLenum type, void *image);
    return ((PFN_glGetConvolutionFilter)__blue_glCore_glGetConvolutionFilter)(target, format, type, image);
}

extern void* __blue_glCore_glGetConvolutionParameterfv;
void APIENTRY bluegl_glGetConvolutionParameterfv (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetConvolutionParameterfv) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetConvolutionParameterfv)__blue_glCore_glGetConvolutionParameterfv)(target, pname, params);
}

extern void* __blue_glCore_glGetConvolutionParameteriv;
void APIENTRY bluegl_glGetConvolutionParameteriv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetConvolutionParameteriv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetConvolutionParameteriv)__blue_glCore_glGetConvolutionParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glGetSeparableFilter;
void APIENTRY bluegl_glGetSeparableFilter (GLenum target, GLenum format, GLenum type, void *row, void *column, void *span) {
    typedef void (APIENTRYP PFN_glGetSeparableFilter) (GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
    return ((PFN_glGetSeparableFilter)__blue_glCore_glGetSeparableFilter)(target, format, type, row, column, span);
}

extern void* __blue_glCore_glSeparableFilter2D;
void APIENTRY bluegl_glSeparableFilter2D (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column) {
    typedef void (APIENTRYP PFN_glSeparableFilter2D) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
    return ((PFN_glSeparableFilter2D)__blue_glCore_glSeparableFilter2D)(target, internalformat, width, height, format, type, row, column);
}

extern void* __blue_glCore_glGetHistogram;
void APIENTRY bluegl_glGetHistogram (GLenum target, GLboolean reset, GLenum format, GLenum type, void *values) {
    typedef void (APIENTRYP PFN_glGetHistogram) (GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
    return ((PFN_glGetHistogram)__blue_glCore_glGetHistogram)(target, reset, format, type, values);
}

extern void* __blue_glCore_glGetHistogramParameterfv;
void APIENTRY bluegl_glGetHistogramParameterfv (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetHistogramParameterfv) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetHistogramParameterfv)__blue_glCore_glGetHistogramParameterfv)(target, pname, params);
}

extern void* __blue_glCore_glGetHistogramParameteriv;
void APIENTRY bluegl_glGetHistogramParameteriv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetHistogramParameteriv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetHistogramParameteriv)__blue_glCore_glGetHistogramParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glGetMinmax;
void APIENTRY bluegl_glGetMinmax (GLenum target, GLboolean reset, GLenum format, GLenum type, void *values) {
    typedef void (APIENTRYP PFN_glGetMinmax) (GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
    return ((PFN_glGetMinmax)__blue_glCore_glGetMinmax)(target, reset, format, type, values);
}

extern void* __blue_glCore_glGetMinmaxParameterfv;
void APIENTRY bluegl_glGetMinmaxParameterfv (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetMinmaxParameterfv) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetMinmaxParameterfv)__blue_glCore_glGetMinmaxParameterfv)(target, pname, params);
}

extern void* __blue_glCore_glGetMinmaxParameteriv;
void APIENTRY bluegl_glGetMinmaxParameteriv (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetMinmaxParameteriv) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetMinmaxParameteriv)__blue_glCore_glGetMinmaxParameteriv)(target, pname, params);
}

extern void* __blue_glCore_glHistogram;
void APIENTRY bluegl_glHistogram (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    typedef void (APIENTRYP PFN_glHistogram) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
    return ((PFN_glHistogram)__blue_glCore_glHistogram)(target, width, internalformat, sink);
}

extern void* __blue_glCore_glMinmax;
void APIENTRY bluegl_glMinmax (GLenum target, GLenum internalformat, GLboolean sink) {
    typedef void (APIENTRYP PFN_glMinmax) (GLenum target, GLenum internalformat, GLboolean sink);
    return ((PFN_glMinmax)__blue_glCore_glMinmax)(target, internalformat, sink);
}

extern void* __blue_glCore_glResetHistogram;
void APIENTRY bluegl_glResetHistogram (GLenum target) {
    typedef void (APIENTRYP PFN_glResetHistogram) (GLenum target);
    return ((PFN_glResetHistogram)__blue_glCore_glResetHistogram)(target);
}

extern void* __blue_glCore_glResetMinmax;
void APIENTRY bluegl_glResetMinmax (GLenum target) {
    typedef void (APIENTRYP PFN_glResetMinmax) (GLenum target);
    return ((PFN_glResetMinmax)__blue_glCore_glResetMinmax)(target);
}

extern void* __blue_glCore_glVertexAttribDivisorARB;
void APIENTRY bluegl_glVertexAttribDivisorARB (GLuint index, GLuint divisor) {
    typedef void (APIENTRYP PFN_glVertexAttribDivisorARB) (GLuint index, GLuint divisor);
    return ((PFN_glVertexAttribDivisorARB)__blue_glCore_glVertexAttribDivisorARB)(index, divisor);
}

extern void* __blue_glCore_glCurrentPaletteMatrixARB;
void APIENTRY bluegl_glCurrentPaletteMatrixARB (GLint index) {
    typedef void (APIENTRYP PFN_glCurrentPaletteMatrixARB) (GLint index);
    return ((PFN_glCurrentPaletteMatrixARB)__blue_glCore_glCurrentPaletteMatrixARB)(index);
}

extern void* __blue_glCore_glMatrixIndexubvARB;
void APIENTRY bluegl_glMatrixIndexubvARB (GLint size, const GLubyte *indices) {
    typedef void (APIENTRYP PFN_glMatrixIndexubvARB) (GLint size, const GLubyte *indices);
    return ((PFN_glMatrixIndexubvARB)__blue_glCore_glMatrixIndexubvARB)(size, indices);
}

extern void* __blue_glCore_glMatrixIndexusvARB;
void APIENTRY bluegl_glMatrixIndexusvARB (GLint size, const GLushort *indices) {
    typedef void (APIENTRYP PFN_glMatrixIndexusvARB) (GLint size, const GLushort *indices);
    return ((PFN_glMatrixIndexusvARB)__blue_glCore_glMatrixIndexusvARB)(size, indices);
}

extern void* __blue_glCore_glMatrixIndexuivARB;
void APIENTRY bluegl_glMatrixIndexuivARB (GLint size, const GLuint *indices) {
    typedef void (APIENTRYP PFN_glMatrixIndexuivARB) (GLint size, const GLuint *indices);
    return ((PFN_glMatrixIndexuivARB)__blue_glCore_glMatrixIndexuivARB)(size, indices);
}

extern void* __blue_glCore_glMatrixIndexPointerARB;
void APIENTRY bluegl_glMatrixIndexPointerARB (GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glMatrixIndexPointerARB) (GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glMatrixIndexPointerARB)__blue_glCore_glMatrixIndexPointerARB)(size, type, stride, pointer);
}

extern void* __blue_glCore_glSampleCoverageARB;
void APIENTRY bluegl_glSampleCoverageARB (GLfloat value, GLboolean invert) {
    typedef void (APIENTRYP PFN_glSampleCoverageARB) (GLfloat value, GLboolean invert);
    return ((PFN_glSampleCoverageARB)__blue_glCore_glSampleCoverageARB)(value, invert);
}

extern void* __blue_glCore_glActiveTextureARB;
void APIENTRY bluegl_glActiveTextureARB (GLenum texture) {
    typedef void (APIENTRYP PFN_glActiveTextureARB) (GLenum texture);
    return ((PFN_glActiveTextureARB)__blue_glCore_glActiveTextureARB)(texture);
}

extern void* __blue_glCore_glClientActiveTextureARB;
void APIENTRY bluegl_glClientActiveTextureARB (GLenum texture) {
    typedef void (APIENTRYP PFN_glClientActiveTextureARB) (GLenum texture);
    return ((PFN_glClientActiveTextureARB)__blue_glCore_glClientActiveTextureARB)(texture);
}

extern void* __blue_glCore_glMultiTexCoord1dARB;
void APIENTRY bluegl_glMultiTexCoord1dARB (GLenum target, GLdouble s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1dARB) (GLenum target, GLdouble s);
    return ((PFN_glMultiTexCoord1dARB)__blue_glCore_glMultiTexCoord1dARB)(target, s);
}

extern void* __blue_glCore_glMultiTexCoord1dvARB;
void APIENTRY bluegl_glMultiTexCoord1dvARB (GLenum target, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1dvARB) (GLenum target, const GLdouble *v);
    return ((PFN_glMultiTexCoord1dvARB)__blue_glCore_glMultiTexCoord1dvARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord1fARB;
void APIENTRY bluegl_glMultiTexCoord1fARB (GLenum target, GLfloat s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1fARB) (GLenum target, GLfloat s);
    return ((PFN_glMultiTexCoord1fARB)__blue_glCore_glMultiTexCoord1fARB)(target, s);
}

extern void* __blue_glCore_glMultiTexCoord1fvARB;
void APIENTRY bluegl_glMultiTexCoord1fvARB (GLenum target, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1fvARB) (GLenum target, const GLfloat *v);
    return ((PFN_glMultiTexCoord1fvARB)__blue_glCore_glMultiTexCoord1fvARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord1iARB;
void APIENTRY bluegl_glMultiTexCoord1iARB (GLenum target, GLint s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1iARB) (GLenum target, GLint s);
    return ((PFN_glMultiTexCoord1iARB)__blue_glCore_glMultiTexCoord1iARB)(target, s);
}

extern void* __blue_glCore_glMultiTexCoord1ivARB;
void APIENTRY bluegl_glMultiTexCoord1ivARB (GLenum target, const GLint *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1ivARB) (GLenum target, const GLint *v);
    return ((PFN_glMultiTexCoord1ivARB)__blue_glCore_glMultiTexCoord1ivARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord1sARB;
void APIENTRY bluegl_glMultiTexCoord1sARB (GLenum target, GLshort s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1sARB) (GLenum target, GLshort s);
    return ((PFN_glMultiTexCoord1sARB)__blue_glCore_glMultiTexCoord1sARB)(target, s);
}

extern void* __blue_glCore_glMultiTexCoord1svARB;
void APIENTRY bluegl_glMultiTexCoord1svARB (GLenum target, const GLshort *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1svARB) (GLenum target, const GLshort *v);
    return ((PFN_glMultiTexCoord1svARB)__blue_glCore_glMultiTexCoord1svARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord2dARB;
void APIENTRY bluegl_glMultiTexCoord2dARB (GLenum target, GLdouble s, GLdouble t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2dARB) (GLenum target, GLdouble s, GLdouble t);
    return ((PFN_glMultiTexCoord2dARB)__blue_glCore_glMultiTexCoord2dARB)(target, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2dvARB;
void APIENTRY bluegl_glMultiTexCoord2dvARB (GLenum target, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2dvARB) (GLenum target, const GLdouble *v);
    return ((PFN_glMultiTexCoord2dvARB)__blue_glCore_glMultiTexCoord2dvARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord2fARB;
void APIENTRY bluegl_glMultiTexCoord2fARB (GLenum target, GLfloat s, GLfloat t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2fARB) (GLenum target, GLfloat s, GLfloat t);
    return ((PFN_glMultiTexCoord2fARB)__blue_glCore_glMultiTexCoord2fARB)(target, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2fvARB;
void APIENTRY bluegl_glMultiTexCoord2fvARB (GLenum target, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2fvARB) (GLenum target, const GLfloat *v);
    return ((PFN_glMultiTexCoord2fvARB)__blue_glCore_glMultiTexCoord2fvARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord2iARB;
void APIENTRY bluegl_glMultiTexCoord2iARB (GLenum target, GLint s, GLint t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2iARB) (GLenum target, GLint s, GLint t);
    return ((PFN_glMultiTexCoord2iARB)__blue_glCore_glMultiTexCoord2iARB)(target, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2ivARB;
void APIENTRY bluegl_glMultiTexCoord2ivARB (GLenum target, const GLint *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2ivARB) (GLenum target, const GLint *v);
    return ((PFN_glMultiTexCoord2ivARB)__blue_glCore_glMultiTexCoord2ivARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord2sARB;
void APIENTRY bluegl_glMultiTexCoord2sARB (GLenum target, GLshort s, GLshort t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2sARB) (GLenum target, GLshort s, GLshort t);
    return ((PFN_glMultiTexCoord2sARB)__blue_glCore_glMultiTexCoord2sARB)(target, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2svARB;
void APIENTRY bluegl_glMultiTexCoord2svARB (GLenum target, const GLshort *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2svARB) (GLenum target, const GLshort *v);
    return ((PFN_glMultiTexCoord2svARB)__blue_glCore_glMultiTexCoord2svARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord3dARB;
void APIENTRY bluegl_glMultiTexCoord3dARB (GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3dARB) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
    return ((PFN_glMultiTexCoord3dARB)__blue_glCore_glMultiTexCoord3dARB)(target, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3dvARB;
void APIENTRY bluegl_glMultiTexCoord3dvARB (GLenum target, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3dvARB) (GLenum target, const GLdouble *v);
    return ((PFN_glMultiTexCoord3dvARB)__blue_glCore_glMultiTexCoord3dvARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord3fARB;
void APIENTRY bluegl_glMultiTexCoord3fARB (GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3fARB) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
    return ((PFN_glMultiTexCoord3fARB)__blue_glCore_glMultiTexCoord3fARB)(target, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3fvARB;
void APIENTRY bluegl_glMultiTexCoord3fvARB (GLenum target, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3fvARB) (GLenum target, const GLfloat *v);
    return ((PFN_glMultiTexCoord3fvARB)__blue_glCore_glMultiTexCoord3fvARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord3iARB;
void APIENTRY bluegl_glMultiTexCoord3iARB (GLenum target, GLint s, GLint t, GLint r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3iARB) (GLenum target, GLint s, GLint t, GLint r);
    return ((PFN_glMultiTexCoord3iARB)__blue_glCore_glMultiTexCoord3iARB)(target, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3ivARB;
void APIENTRY bluegl_glMultiTexCoord3ivARB (GLenum target, const GLint *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3ivARB) (GLenum target, const GLint *v);
    return ((PFN_glMultiTexCoord3ivARB)__blue_glCore_glMultiTexCoord3ivARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord3sARB;
void APIENTRY bluegl_glMultiTexCoord3sARB (GLenum target, GLshort s, GLshort t, GLshort r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3sARB) (GLenum target, GLshort s, GLshort t, GLshort r);
    return ((PFN_glMultiTexCoord3sARB)__blue_glCore_glMultiTexCoord3sARB)(target, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3svARB;
void APIENTRY bluegl_glMultiTexCoord3svARB (GLenum target, const GLshort *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3svARB) (GLenum target, const GLshort *v);
    return ((PFN_glMultiTexCoord3svARB)__blue_glCore_glMultiTexCoord3svARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord4dARB;
void APIENTRY bluegl_glMultiTexCoord4dARB (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4dARB) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
    return ((PFN_glMultiTexCoord4dARB)__blue_glCore_glMultiTexCoord4dARB)(target, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4dvARB;
void APIENTRY bluegl_glMultiTexCoord4dvARB (GLenum target, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4dvARB) (GLenum target, const GLdouble *v);
    return ((PFN_glMultiTexCoord4dvARB)__blue_glCore_glMultiTexCoord4dvARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord4fARB;
void APIENTRY bluegl_glMultiTexCoord4fARB (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4fARB) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
    return ((PFN_glMultiTexCoord4fARB)__blue_glCore_glMultiTexCoord4fARB)(target, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4fvARB;
void APIENTRY bluegl_glMultiTexCoord4fvARB (GLenum target, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4fvARB) (GLenum target, const GLfloat *v);
    return ((PFN_glMultiTexCoord4fvARB)__blue_glCore_glMultiTexCoord4fvARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord4iARB;
void APIENTRY bluegl_glMultiTexCoord4iARB (GLenum target, GLint s, GLint t, GLint r, GLint q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4iARB) (GLenum target, GLint s, GLint t, GLint r, GLint q);
    return ((PFN_glMultiTexCoord4iARB)__blue_glCore_glMultiTexCoord4iARB)(target, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4ivARB;
void APIENTRY bluegl_glMultiTexCoord4ivARB (GLenum target, const GLint *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4ivARB) (GLenum target, const GLint *v);
    return ((PFN_glMultiTexCoord4ivARB)__blue_glCore_glMultiTexCoord4ivARB)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord4sARB;
void APIENTRY bluegl_glMultiTexCoord4sARB (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4sARB) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
    return ((PFN_glMultiTexCoord4sARB)__blue_glCore_glMultiTexCoord4sARB)(target, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4svARB;
void APIENTRY bluegl_glMultiTexCoord4svARB (GLenum target, const GLshort *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4svARB) (GLenum target, const GLshort *v);
    return ((PFN_glMultiTexCoord4svARB)__blue_glCore_glMultiTexCoord4svARB)(target, v);
}

extern void* __blue_glCore_glGenQueriesARB;
void APIENTRY bluegl_glGenQueriesARB (GLsizei n, GLuint *ids) {
    typedef void (APIENTRYP PFN_glGenQueriesARB) (GLsizei n, GLuint *ids);
    return ((PFN_glGenQueriesARB)__blue_glCore_glGenQueriesARB)(n, ids);
}

extern void* __blue_glCore_glDeleteQueriesARB;
void APIENTRY bluegl_glDeleteQueriesARB (GLsizei n, const GLuint *ids) {
    typedef void (APIENTRYP PFN_glDeleteQueriesARB) (GLsizei n, const GLuint *ids);
    return ((PFN_glDeleteQueriesARB)__blue_glCore_glDeleteQueriesARB)(n, ids);
}

extern void* __blue_glCore_glIsQueryARB;
GLboolean APIENTRY bluegl_glIsQueryARB (GLuint id) {
    typedef GLboolean (APIENTRYP PFN_glIsQueryARB) (GLuint id);
    return ((PFN_glIsQueryARB)__blue_glCore_glIsQueryARB)(id);
}

extern void* __blue_glCore_glBeginQueryARB;
void APIENTRY bluegl_glBeginQueryARB (GLenum target, GLuint id) {
    typedef void (APIENTRYP PFN_glBeginQueryARB) (GLenum target, GLuint id);
    return ((PFN_glBeginQueryARB)__blue_glCore_glBeginQueryARB)(target, id);
}

extern void* __blue_glCore_glEndQueryARB;
void APIENTRY bluegl_glEndQueryARB (GLenum target) {
    typedef void (APIENTRYP PFN_glEndQueryARB) (GLenum target);
    return ((PFN_glEndQueryARB)__blue_glCore_glEndQueryARB)(target);
}

extern void* __blue_glCore_glGetQueryivARB;
void APIENTRY bluegl_glGetQueryivARB (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetQueryivARB) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetQueryivARB)__blue_glCore_glGetQueryivARB)(target, pname, params);
}

extern void* __blue_glCore_glGetQueryObjectivARB;
void APIENTRY bluegl_glGetQueryObjectivARB (GLuint id, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetQueryObjectivARB) (GLuint id, GLenum pname, GLint *params);
    return ((PFN_glGetQueryObjectivARB)__blue_glCore_glGetQueryObjectivARB)(id, pname, params);
}

extern void* __blue_glCore_glGetQueryObjectuivARB;
void APIENTRY bluegl_glGetQueryObjectuivARB (GLuint id, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetQueryObjectuivARB) (GLuint id, GLenum pname, GLuint *params);
    return ((PFN_glGetQueryObjectuivARB)__blue_glCore_glGetQueryObjectuivARB)(id, pname, params);
}

extern void* __blue_glCore_glMaxShaderCompilerThreadsARB;
void APIENTRY bluegl_glMaxShaderCompilerThreadsARB (GLuint count) {
    typedef void (APIENTRYP PFN_glMaxShaderCompilerThreadsARB) (GLuint count);
    return ((PFN_glMaxShaderCompilerThreadsARB)__blue_glCore_glMaxShaderCompilerThreadsARB)(count);
}

extern void* __blue_glCore_glPointParameterfARB;
void APIENTRY bluegl_glPointParameterfARB (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glPointParameterfARB) (GLenum pname, GLfloat param);
    return ((PFN_glPointParameterfARB)__blue_glCore_glPointParameterfARB)(pname, param);
}

extern void* __blue_glCore_glPointParameterfvARB;
void APIENTRY bluegl_glPointParameterfvARB (GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glPointParameterfvARB) (GLenum pname, const GLfloat *params);
    return ((PFN_glPointParameterfvARB)__blue_glCore_glPointParameterfvARB)(pname, params);
}

extern void* __blue_glCore_glGetnMapdvARB;
void APIENTRY bluegl_glGetnMapdvARB (GLenum target, GLenum query, GLsizei bufSize, GLdouble *v) {
    typedef void (APIENTRYP PFN_glGetnMapdvARB) (GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
    return ((PFN_glGetnMapdvARB)__blue_glCore_glGetnMapdvARB)(target, query, bufSize, v);
}

extern void* __blue_glCore_glGetnMapfvARB;
void APIENTRY bluegl_glGetnMapfvARB (GLenum target, GLenum query, GLsizei bufSize, GLfloat *v) {
    typedef void (APIENTRYP PFN_glGetnMapfvARB) (GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
    return ((PFN_glGetnMapfvARB)__blue_glCore_glGetnMapfvARB)(target, query, bufSize, v);
}

extern void* __blue_glCore_glGetnMapivARB;
void APIENTRY bluegl_glGetnMapivARB (GLenum target, GLenum query, GLsizei bufSize, GLint *v) {
    typedef void (APIENTRYP PFN_glGetnMapivARB) (GLenum target, GLenum query, GLsizei bufSize, GLint *v);
    return ((PFN_glGetnMapivARB)__blue_glCore_glGetnMapivARB)(target, query, bufSize, v);
}

extern void* __blue_glCore_glGetnPixelMapfvARB;
void APIENTRY bluegl_glGetnPixelMapfvARB (GLenum map, GLsizei bufSize, GLfloat *values) {
    typedef void (APIENTRYP PFN_glGetnPixelMapfvARB) (GLenum map, GLsizei bufSize, GLfloat *values);
    return ((PFN_glGetnPixelMapfvARB)__blue_glCore_glGetnPixelMapfvARB)(map, bufSize, values);
}

extern void* __blue_glCore_glGetnPixelMapuivARB;
void APIENTRY bluegl_glGetnPixelMapuivARB (GLenum map, GLsizei bufSize, GLuint *values) {
    typedef void (APIENTRYP PFN_glGetnPixelMapuivARB) (GLenum map, GLsizei bufSize, GLuint *values);
    return ((PFN_glGetnPixelMapuivARB)__blue_glCore_glGetnPixelMapuivARB)(map, bufSize, values);
}

extern void* __blue_glCore_glGetnPixelMapusvARB;
void APIENTRY bluegl_glGetnPixelMapusvARB (GLenum map, GLsizei bufSize, GLushort *values) {
    typedef void (APIENTRYP PFN_glGetnPixelMapusvARB) (GLenum map, GLsizei bufSize, GLushort *values);
    return ((PFN_glGetnPixelMapusvARB)__blue_glCore_glGetnPixelMapusvARB)(map, bufSize, values);
}

extern void* __blue_glCore_glGetnPolygonStippleARB;
void APIENTRY bluegl_glGetnPolygonStippleARB (GLsizei bufSize, GLubyte *pattern) {
    typedef void (APIENTRYP PFN_glGetnPolygonStippleARB) (GLsizei bufSize, GLubyte *pattern);
    return ((PFN_glGetnPolygonStippleARB)__blue_glCore_glGetnPolygonStippleARB)(bufSize, pattern);
}

extern void* __blue_glCore_glGetnColorTableARB;
void APIENTRY bluegl_glGetnColorTableARB (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table) {
    typedef void (APIENTRYP PFN_glGetnColorTableARB) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
    return ((PFN_glGetnColorTableARB)__blue_glCore_glGetnColorTableARB)(target, format, type, bufSize, table);
}

extern void* __blue_glCore_glGetnConvolutionFilterARB;
void APIENTRY bluegl_glGetnConvolutionFilterARB (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image) {
    typedef void (APIENTRYP PFN_glGetnConvolutionFilterARB) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
    return ((PFN_glGetnConvolutionFilterARB)__blue_glCore_glGetnConvolutionFilterARB)(target, format, type, bufSize, image);
}

extern void* __blue_glCore_glGetnSeparableFilterARB;
void APIENTRY bluegl_glGetnSeparableFilterARB (GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span) {
    typedef void (APIENTRYP PFN_glGetnSeparableFilterARB) (GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
    return ((PFN_glGetnSeparableFilterARB)__blue_glCore_glGetnSeparableFilterARB)(target, format, type, rowBufSize, row, columnBufSize, column, span);
}

extern void* __blue_glCore_glGetnHistogramARB;
void APIENTRY bluegl_glGetnHistogramARB (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) {
    typedef void (APIENTRYP PFN_glGetnHistogramARB) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
    return ((PFN_glGetnHistogramARB)__blue_glCore_glGetnHistogramARB)(target, reset, format, type, bufSize, values);
}

extern void* __blue_glCore_glGetnMinmaxARB;
void APIENTRY bluegl_glGetnMinmaxARB (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) {
    typedef void (APIENTRYP PFN_glGetnMinmaxARB) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
    return ((PFN_glGetnMinmaxARB)__blue_glCore_glGetnMinmaxARB)(target, reset, format, type, bufSize, values);
}

extern void* __blue_glCore_glFramebufferSampleLocationsfvARB;
void APIENTRY bluegl_glFramebufferSampleLocationsfvARB (GLenum target, GLuint start, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glFramebufferSampleLocationsfvARB) (GLenum target, GLuint start, GLsizei count, const GLfloat *v);
    return ((PFN_glFramebufferSampleLocationsfvARB)__blue_glCore_glFramebufferSampleLocationsfvARB)(target, start, count, v);
}

extern void* __blue_glCore_glNamedFramebufferSampleLocationsfvARB;
void APIENTRY bluegl_glNamedFramebufferSampleLocationsfvARB (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glNamedFramebufferSampleLocationsfvARB) (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
    return ((PFN_glNamedFramebufferSampleLocationsfvARB)__blue_glCore_glNamedFramebufferSampleLocationsfvARB)(framebuffer, start, count, v);
}

extern void* __blue_glCore_glEvaluateDepthValuesARB;
void APIENTRY bluegl_glEvaluateDepthValuesARB (void) {
    typedef void (APIENTRYP PFN_glEvaluateDepthValuesARB) (void);
    return ((PFN_glEvaluateDepthValuesARB)__blue_glCore_glEvaluateDepthValuesARB)();
}

extern void* __blue_glCore_glDeleteObjectARB;
void APIENTRY bluegl_glDeleteObjectARB (GLhandleARB obj) {
    typedef void (APIENTRYP PFN_glDeleteObjectARB) (GLhandleARB obj);
    return ((PFN_glDeleteObjectARB)__blue_glCore_glDeleteObjectARB)(obj);
}

extern void* __blue_glCore_glGetHandleARB;
GLhandleARB APIENTRY bluegl_glGetHandleARB (GLenum pname) {
    typedef GLhandleARB (APIENTRYP PFN_glGetHandleARB) (GLenum pname);
    return ((PFN_glGetHandleARB)__blue_glCore_glGetHandleARB)(pname);
}

extern void* __blue_glCore_glDetachObjectARB;
void APIENTRY bluegl_glDetachObjectARB (GLhandleARB containerObj, GLhandleARB attachedObj) {
    typedef void (APIENTRYP PFN_glDetachObjectARB) (GLhandleARB containerObj, GLhandleARB attachedObj);
    return ((PFN_glDetachObjectARB)__blue_glCore_glDetachObjectARB)(containerObj, attachedObj);
}

extern void* __blue_glCore_glCreateShaderObjectARB;
GLhandleARB APIENTRY bluegl_glCreateShaderObjectARB (GLenum shaderType) {
    typedef GLhandleARB (APIENTRYP PFN_glCreateShaderObjectARB) (GLenum shaderType);
    return ((PFN_glCreateShaderObjectARB)__blue_glCore_glCreateShaderObjectARB)(shaderType);
}

extern void* __blue_glCore_glShaderSourceARB;
void APIENTRY bluegl_glShaderSourceARB (GLhandleARB shaderObj, GLsizei count, const GLcharARB **string, const GLint *length) {
    typedef void (APIENTRYP PFN_glShaderSourceARB) (GLhandleARB shaderObj, GLsizei count, const GLcharARB **string, const GLint *length);
    return ((PFN_glShaderSourceARB)__blue_glCore_glShaderSourceARB)(shaderObj, count, string, length);
}

extern void* __blue_glCore_glCompileShaderARB;
void APIENTRY bluegl_glCompileShaderARB (GLhandleARB shaderObj) {
    typedef void (APIENTRYP PFN_glCompileShaderARB) (GLhandleARB shaderObj);
    return ((PFN_glCompileShaderARB)__blue_glCore_glCompileShaderARB)(shaderObj);
}

extern void* __blue_glCore_glCreateProgramObjectARB;
GLhandleARB APIENTRY bluegl_glCreateProgramObjectARB (void) {
    typedef GLhandleARB (APIENTRYP PFN_glCreateProgramObjectARB) (void);
    return ((PFN_glCreateProgramObjectARB)__blue_glCore_glCreateProgramObjectARB)();
}

extern void* __blue_glCore_glAttachObjectARB;
void APIENTRY bluegl_glAttachObjectARB (GLhandleARB containerObj, GLhandleARB obj) {
    typedef void (APIENTRYP PFN_glAttachObjectARB) (GLhandleARB containerObj, GLhandleARB obj);
    return ((PFN_glAttachObjectARB)__blue_glCore_glAttachObjectARB)(containerObj, obj);
}

extern void* __blue_glCore_glLinkProgramARB;
void APIENTRY bluegl_glLinkProgramARB (GLhandleARB programObj) {
    typedef void (APIENTRYP PFN_glLinkProgramARB) (GLhandleARB programObj);
    return ((PFN_glLinkProgramARB)__blue_glCore_glLinkProgramARB)(programObj);
}

extern void* __blue_glCore_glUseProgramObjectARB;
void APIENTRY bluegl_glUseProgramObjectARB (GLhandleARB programObj) {
    typedef void (APIENTRYP PFN_glUseProgramObjectARB) (GLhandleARB programObj);
    return ((PFN_glUseProgramObjectARB)__blue_glCore_glUseProgramObjectARB)(programObj);
}

extern void* __blue_glCore_glValidateProgramARB;
void APIENTRY bluegl_glValidateProgramARB (GLhandleARB programObj) {
    typedef void (APIENTRYP PFN_glValidateProgramARB) (GLhandleARB programObj);
    return ((PFN_glValidateProgramARB)__blue_glCore_glValidateProgramARB)(programObj);
}

extern void* __blue_glCore_glUniform1fARB;
void APIENTRY bluegl_glUniform1fARB (GLint location, GLfloat v0) {
    typedef void (APIENTRYP PFN_glUniform1fARB) (GLint location, GLfloat v0);
    return ((PFN_glUniform1fARB)__blue_glCore_glUniform1fARB)(location, v0);
}

extern void* __blue_glCore_glUniform2fARB;
void APIENTRY bluegl_glUniform2fARB (GLint location, GLfloat v0, GLfloat v1) {
    typedef void (APIENTRYP PFN_glUniform2fARB) (GLint location, GLfloat v0, GLfloat v1);
    return ((PFN_glUniform2fARB)__blue_glCore_glUniform2fARB)(location, v0, v1);
}

extern void* __blue_glCore_glUniform3fARB;
void APIENTRY bluegl_glUniform3fARB (GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    typedef void (APIENTRYP PFN_glUniform3fARB) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    return ((PFN_glUniform3fARB)__blue_glCore_glUniform3fARB)(location, v0, v1, v2);
}

extern void* __blue_glCore_glUniform4fARB;
void APIENTRY bluegl_glUniform4fARB (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    typedef void (APIENTRYP PFN_glUniform4fARB) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    return ((PFN_glUniform4fARB)__blue_glCore_glUniform4fARB)(location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glUniform1iARB;
void APIENTRY bluegl_glUniform1iARB (GLint location, GLint v0) {
    typedef void (APIENTRYP PFN_glUniform1iARB) (GLint location, GLint v0);
    return ((PFN_glUniform1iARB)__blue_glCore_glUniform1iARB)(location, v0);
}

extern void* __blue_glCore_glUniform2iARB;
void APIENTRY bluegl_glUniform2iARB (GLint location, GLint v0, GLint v1) {
    typedef void (APIENTRYP PFN_glUniform2iARB) (GLint location, GLint v0, GLint v1);
    return ((PFN_glUniform2iARB)__blue_glCore_glUniform2iARB)(location, v0, v1);
}

extern void* __blue_glCore_glUniform3iARB;
void APIENTRY bluegl_glUniform3iARB (GLint location, GLint v0, GLint v1, GLint v2) {
    typedef void (APIENTRYP PFN_glUniform3iARB) (GLint location, GLint v0, GLint v1, GLint v2);
    return ((PFN_glUniform3iARB)__blue_glCore_glUniform3iARB)(location, v0, v1, v2);
}

extern void* __blue_glCore_glUniform4iARB;
void APIENTRY bluegl_glUniform4iARB (GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    typedef void (APIENTRYP PFN_glUniform4iARB) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    return ((PFN_glUniform4iARB)__blue_glCore_glUniform4iARB)(location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glUniform1fvARB;
void APIENTRY bluegl_glUniform1fvARB (GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniform1fvARB) (GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glUniform1fvARB)__blue_glCore_glUniform1fvARB)(location, count, value);
}

extern void* __blue_glCore_glUniform2fvARB;
void APIENTRY bluegl_glUniform2fvARB (GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniform2fvARB) (GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glUniform2fvARB)__blue_glCore_glUniform2fvARB)(location, count, value);
}

extern void* __blue_glCore_glUniform3fvARB;
void APIENTRY bluegl_glUniform3fvARB (GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniform3fvARB) (GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glUniform3fvARB)__blue_glCore_glUniform3fvARB)(location, count, value);
}

extern void* __blue_glCore_glUniform4fvARB;
void APIENTRY bluegl_glUniform4fvARB (GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniform4fvARB) (GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glUniform4fvARB)__blue_glCore_glUniform4fvARB)(location, count, value);
}

extern void* __blue_glCore_glUniform1ivARB;
void APIENTRY bluegl_glUniform1ivARB (GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glUniform1ivARB) (GLint location, GLsizei count, const GLint *value);
    return ((PFN_glUniform1ivARB)__blue_glCore_glUniform1ivARB)(location, count, value);
}

extern void* __blue_glCore_glUniform2ivARB;
void APIENTRY bluegl_glUniform2ivARB (GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glUniform2ivARB) (GLint location, GLsizei count, const GLint *value);
    return ((PFN_glUniform2ivARB)__blue_glCore_glUniform2ivARB)(location, count, value);
}

extern void* __blue_glCore_glUniform3ivARB;
void APIENTRY bluegl_glUniform3ivARB (GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glUniform3ivARB) (GLint location, GLsizei count, const GLint *value);
    return ((PFN_glUniform3ivARB)__blue_glCore_glUniform3ivARB)(location, count, value);
}

extern void* __blue_glCore_glUniform4ivARB;
void APIENTRY bluegl_glUniform4ivARB (GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glUniform4ivARB) (GLint location, GLsizei count, const GLint *value);
    return ((PFN_glUniform4ivARB)__blue_glCore_glUniform4ivARB)(location, count, value);
}

extern void* __blue_glCore_glUniformMatrix2fvARB;
void APIENTRY bluegl_glUniformMatrix2fvARB (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix2fvARB) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix2fvARB)__blue_glCore_glUniformMatrix2fvARB)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix3fvARB;
void APIENTRY bluegl_glUniformMatrix3fvARB (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix3fvARB) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix3fvARB)__blue_glCore_glUniformMatrix3fvARB)(location, count, transpose, value);
}

extern void* __blue_glCore_glUniformMatrix4fvARB;
void APIENTRY bluegl_glUniformMatrix4fvARB (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glUniformMatrix4fvARB) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glUniformMatrix4fvARB)__blue_glCore_glUniformMatrix4fvARB)(location, count, transpose, value);
}

extern void* __blue_glCore_glGetObjectParameterfvARB;
void APIENTRY bluegl_glGetObjectParameterfvARB (GLhandleARB obj, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetObjectParameterfvARB) (GLhandleARB obj, GLenum pname, GLfloat *params);
    return ((PFN_glGetObjectParameterfvARB)__blue_glCore_glGetObjectParameterfvARB)(obj, pname, params);
}

extern void* __blue_glCore_glGetObjectParameterivARB;
void APIENTRY bluegl_glGetObjectParameterivARB (GLhandleARB obj, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetObjectParameterivARB) (GLhandleARB obj, GLenum pname, GLint *params);
    return ((PFN_glGetObjectParameterivARB)__blue_glCore_glGetObjectParameterivARB)(obj, pname, params);
}

extern void* __blue_glCore_glGetInfoLogARB;
void APIENTRY bluegl_glGetInfoLogARB (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog) {
    typedef void (APIENTRYP PFN_glGetInfoLogARB) (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
    return ((PFN_glGetInfoLogARB)__blue_glCore_glGetInfoLogARB)(obj, maxLength, length, infoLog);
}

extern void* __blue_glCore_glGetAttachedObjectsARB;
void APIENTRY bluegl_glGetAttachedObjectsARB (GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj) {
    typedef void (APIENTRYP PFN_glGetAttachedObjectsARB) (GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
    return ((PFN_glGetAttachedObjectsARB)__blue_glCore_glGetAttachedObjectsARB)(containerObj, maxCount, count, obj);
}

extern void* __blue_glCore_glGetUniformLocationARB;
GLint APIENTRY bluegl_glGetUniformLocationARB (GLhandleARB programObj, const GLcharARB *name) {
    typedef GLint (APIENTRYP PFN_glGetUniformLocationARB) (GLhandleARB programObj, const GLcharARB *name);
    return ((PFN_glGetUniformLocationARB)__blue_glCore_glGetUniformLocationARB)(programObj, name);
}

extern void* __blue_glCore_glGetActiveUniformARB;
void APIENTRY bluegl_glGetActiveUniformARB (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name) {
    typedef void (APIENTRYP PFN_glGetActiveUniformARB) (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
    return ((PFN_glGetActiveUniformARB)__blue_glCore_glGetActiveUniformARB)(programObj, index, maxLength, length, size, type, name);
}

extern void* __blue_glCore_glGetUniformfvARB;
void APIENTRY bluegl_glGetUniformfvARB (GLhandleARB programObj, GLint location, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetUniformfvARB) (GLhandleARB programObj, GLint location, GLfloat *params);
    return ((PFN_glGetUniformfvARB)__blue_glCore_glGetUniformfvARB)(programObj, location, params);
}

extern void* __blue_glCore_glGetUniformivARB;
void APIENTRY bluegl_glGetUniformivARB (GLhandleARB programObj, GLint location, GLint *params) {
    typedef void (APIENTRYP PFN_glGetUniformivARB) (GLhandleARB programObj, GLint location, GLint *params);
    return ((PFN_glGetUniformivARB)__blue_glCore_glGetUniformivARB)(programObj, location, params);
}

extern void* __blue_glCore_glGetShaderSourceARB;
void APIENTRY bluegl_glGetShaderSourceARB (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source) {
    typedef void (APIENTRYP PFN_glGetShaderSourceARB) (GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
    return ((PFN_glGetShaderSourceARB)__blue_glCore_glGetShaderSourceARB)(obj, maxLength, length, source);
}

extern void* __blue_glCore_glTexBufferARB;
void APIENTRY bluegl_glTexBufferARB (GLenum target, GLenum internalformat, GLuint buffer) {
    typedef void (APIENTRYP PFN_glTexBufferARB) (GLenum target, GLenum internalformat, GLuint buffer);
    return ((PFN_glTexBufferARB)__blue_glCore_glTexBufferARB)(target, internalformat, buffer);
}

extern void* __blue_glCore_glCompressedTexImage3DARB;
void APIENTRY bluegl_glCompressedTexImage3DARB (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexImage3DARB) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexImage3DARB)__blue_glCore_glCompressedTexImage3DARB)(target, level, internalformat, width, height, depth, border, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexImage2DARB;
void APIENTRY bluegl_glCompressedTexImage2DARB (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexImage2DARB) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexImage2DARB)__blue_glCore_glCompressedTexImage2DARB)(target, level, internalformat, width, height, border, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexImage1DARB;
void APIENTRY bluegl_glCompressedTexImage1DARB (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexImage1DARB) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexImage1DARB)__blue_glCore_glCompressedTexImage1DARB)(target, level, internalformat, width, border, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexSubImage3DARB;
void APIENTRY bluegl_glCompressedTexSubImage3DARB (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexSubImage3DARB) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexSubImage3DARB)__blue_glCore_glCompressedTexSubImage3DARB)(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexSubImage2DARB;
void APIENTRY bluegl_glCompressedTexSubImage2DARB (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexSubImage2DARB) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexSubImage2DARB)__blue_glCore_glCompressedTexSubImage2DARB)(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

extern void* __blue_glCore_glCompressedTexSubImage1DARB;
void APIENTRY bluegl_glCompressedTexSubImage1DARB (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) {
    typedef void (APIENTRYP PFN_glCompressedTexSubImage1DARB) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
    return ((PFN_glCompressedTexSubImage1DARB)__blue_glCore_glCompressedTexSubImage1DARB)(target, level, xoffset, width, format, imageSize, data);
}

extern void* __blue_glCore_glGetCompressedTexImageARB;
void APIENTRY bluegl_glGetCompressedTexImageARB (GLenum target, GLint level, void *img) {
    typedef void (APIENTRYP PFN_glGetCompressedTexImageARB) (GLenum target, GLint level, void *img);
    return ((PFN_glGetCompressedTexImageARB)__blue_glCore_glGetCompressedTexImageARB)(target, level, img);
}

extern void* __blue_glCore_glLoadTransposeMatrixfARB;
void APIENTRY bluegl_glLoadTransposeMatrixfARB (const GLfloat *m) {
    typedef void (APIENTRYP PFN_glLoadTransposeMatrixfARB) (const GLfloat *m);
    return ((PFN_glLoadTransposeMatrixfARB)__blue_glCore_glLoadTransposeMatrixfARB)(m);
}

extern void* __blue_glCore_glLoadTransposeMatrixdARB;
void APIENTRY bluegl_glLoadTransposeMatrixdARB (const GLdouble *m) {
    typedef void (APIENTRYP PFN_glLoadTransposeMatrixdARB) (const GLdouble *m);
    return ((PFN_glLoadTransposeMatrixdARB)__blue_glCore_glLoadTransposeMatrixdARB)(m);
}

extern void* __blue_glCore_glMultTransposeMatrixfARB;
void APIENTRY bluegl_glMultTransposeMatrixfARB (const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMultTransposeMatrixfARB) (const GLfloat *m);
    return ((PFN_glMultTransposeMatrixfARB)__blue_glCore_glMultTransposeMatrixfARB)(m);
}

extern void* __blue_glCore_glMultTransposeMatrixdARB;
void APIENTRY bluegl_glMultTransposeMatrixdARB (const GLdouble *m) {
    typedef void (APIENTRYP PFN_glMultTransposeMatrixdARB) (const GLdouble *m);
    return ((PFN_glMultTransposeMatrixdARB)__blue_glCore_glMultTransposeMatrixdARB)(m);
}

extern void* __blue_glCore_glWeightbvARB;
void APIENTRY bluegl_glWeightbvARB (GLint size, const GLbyte *weights) {
    typedef void (APIENTRYP PFN_glWeightbvARB) (GLint size, const GLbyte *weights);
    return ((PFN_glWeightbvARB)__blue_glCore_glWeightbvARB)(size, weights);
}

extern void* __blue_glCore_glWeightsvARB;
void APIENTRY bluegl_glWeightsvARB (GLint size, const GLshort *weights) {
    typedef void (APIENTRYP PFN_glWeightsvARB) (GLint size, const GLshort *weights);
    return ((PFN_glWeightsvARB)__blue_glCore_glWeightsvARB)(size, weights);
}

extern void* __blue_glCore_glWeightivARB;
void APIENTRY bluegl_glWeightivARB (GLint size, const GLint *weights) {
    typedef void (APIENTRYP PFN_glWeightivARB) (GLint size, const GLint *weights);
    return ((PFN_glWeightivARB)__blue_glCore_glWeightivARB)(size, weights);
}

extern void* __blue_glCore_glWeightfvARB;
void APIENTRY bluegl_glWeightfvARB (GLint size, const GLfloat *weights) {
    typedef void (APIENTRYP PFN_glWeightfvARB) (GLint size, const GLfloat *weights);
    return ((PFN_glWeightfvARB)__blue_glCore_glWeightfvARB)(size, weights);
}

extern void* __blue_glCore_glWeightdvARB;
void APIENTRY bluegl_glWeightdvARB (GLint size, const GLdouble *weights) {
    typedef void (APIENTRYP PFN_glWeightdvARB) (GLint size, const GLdouble *weights);
    return ((PFN_glWeightdvARB)__blue_glCore_glWeightdvARB)(size, weights);
}

extern void* __blue_glCore_glWeightubvARB;
void APIENTRY bluegl_glWeightubvARB (GLint size, const GLubyte *weights) {
    typedef void (APIENTRYP PFN_glWeightubvARB) (GLint size, const GLubyte *weights);
    return ((PFN_glWeightubvARB)__blue_glCore_glWeightubvARB)(size, weights);
}

extern void* __blue_glCore_glWeightusvARB;
void APIENTRY bluegl_glWeightusvARB (GLint size, const GLushort *weights) {
    typedef void (APIENTRYP PFN_glWeightusvARB) (GLint size, const GLushort *weights);
    return ((PFN_glWeightusvARB)__blue_glCore_glWeightusvARB)(size, weights);
}

extern void* __blue_glCore_glWeightuivARB;
void APIENTRY bluegl_glWeightuivARB (GLint size, const GLuint *weights) {
    typedef void (APIENTRYP PFN_glWeightuivARB) (GLint size, const GLuint *weights);
    return ((PFN_glWeightuivARB)__blue_glCore_glWeightuivARB)(size, weights);
}

extern void* __blue_glCore_glWeightPointerARB;
void APIENTRY bluegl_glWeightPointerARB (GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glWeightPointerARB) (GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glWeightPointerARB)__blue_glCore_glWeightPointerARB)(size, type, stride, pointer);
}

extern void* __blue_glCore_glVertexBlendARB;
void APIENTRY bluegl_glVertexBlendARB (GLint count) {
    typedef void (APIENTRYP PFN_glVertexBlendARB) (GLint count);
    return ((PFN_glVertexBlendARB)__blue_glCore_glVertexBlendARB)(count);
}

extern void* __blue_glCore_glBindBufferARB;
void APIENTRY bluegl_glBindBufferARB (GLenum target, GLuint buffer) {
    typedef void (APIENTRYP PFN_glBindBufferARB) (GLenum target, GLuint buffer);
    return ((PFN_glBindBufferARB)__blue_glCore_glBindBufferARB)(target, buffer);
}

extern void* __blue_glCore_glDeleteBuffersARB;
void APIENTRY bluegl_glDeleteBuffersARB (GLsizei n, const GLuint *buffers) {
    typedef void (APIENTRYP PFN_glDeleteBuffersARB) (GLsizei n, const GLuint *buffers);
    return ((PFN_glDeleteBuffersARB)__blue_glCore_glDeleteBuffersARB)(n, buffers);
}

extern void* __blue_glCore_glGenBuffersARB;
void APIENTRY bluegl_glGenBuffersARB (GLsizei n, GLuint *buffers) {
    typedef void (APIENTRYP PFN_glGenBuffersARB) (GLsizei n, GLuint *buffers);
    return ((PFN_glGenBuffersARB)__blue_glCore_glGenBuffersARB)(n, buffers);
}

extern void* __blue_glCore_glIsBufferARB;
GLboolean APIENTRY bluegl_glIsBufferARB (GLuint buffer) {
    typedef GLboolean (APIENTRYP PFN_glIsBufferARB) (GLuint buffer);
    return ((PFN_glIsBufferARB)__blue_glCore_glIsBufferARB)(buffer);
}

extern void* __blue_glCore_glBufferDataARB;
void APIENTRY bluegl_glBufferDataARB (GLenum target, GLsizeiptrARB size, const void *data, GLenum usage) {
    typedef void (APIENTRYP PFN_glBufferDataARB) (GLenum target, GLsizeiptrARB size, const void *data, GLenum usage);
    return ((PFN_glBufferDataARB)__blue_glCore_glBufferDataARB)(target, size, data, usage);
}

extern void* __blue_glCore_glBufferSubDataARB;
void APIENTRY bluegl_glBufferSubDataARB (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void *data) {
    typedef void (APIENTRYP PFN_glBufferSubDataARB) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void *data);
    return ((PFN_glBufferSubDataARB)__blue_glCore_glBufferSubDataARB)(target, offset, size, data);
}

extern void* __blue_glCore_glGetBufferSubDataARB;
void APIENTRY bluegl_glGetBufferSubDataARB (GLenum target, GLintptrARB offset, GLsizeiptrARB size, void *data) {
    typedef void (APIENTRYP PFN_glGetBufferSubDataARB) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, void *data);
    return ((PFN_glGetBufferSubDataARB)__blue_glCore_glGetBufferSubDataARB)(target, offset, size, data);
}

extern void* __blue_glCore_glMapBufferARB;
void *APIENTRY bluegl_glMapBufferARB (GLenum target, GLenum access) {
    typedef void *(APIENTRYP PFN_glMapBufferARB) (GLenum target, GLenum access);
    return ((PFN_glMapBufferARB)__blue_glCore_glMapBufferARB)(target, access);
}

extern void* __blue_glCore_glUnmapBufferARB;
GLboolean APIENTRY bluegl_glUnmapBufferARB (GLenum target) {
    typedef GLboolean (APIENTRYP PFN_glUnmapBufferARB) (GLenum target);
    return ((PFN_glUnmapBufferARB)__blue_glCore_glUnmapBufferARB)(target);
}

extern void* __blue_glCore_glGetBufferParameterivARB;
void APIENTRY bluegl_glGetBufferParameterivARB (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetBufferParameterivARB) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetBufferParameterivARB)__blue_glCore_glGetBufferParameterivARB)(target, pname, params);
}

extern void* __blue_glCore_glGetBufferPointervARB;
void APIENTRY bluegl_glGetBufferPointervARB (GLenum target, GLenum pname, void **params) {
    typedef void (APIENTRYP PFN_glGetBufferPointervARB) (GLenum target, GLenum pname, void **params);
    return ((PFN_glGetBufferPointervARB)__blue_glCore_glGetBufferPointervARB)(target, pname, params);
}

extern void* __blue_glCore_glVertexAttrib1dARB;
void APIENTRY bluegl_glVertexAttrib1dARB (GLuint index, GLdouble x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1dARB) (GLuint index, GLdouble x);
    return ((PFN_glVertexAttrib1dARB)__blue_glCore_glVertexAttrib1dARB)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1dvARB;
void APIENTRY bluegl_glVertexAttrib1dvARB (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1dvARB) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib1dvARB)__blue_glCore_glVertexAttrib1dvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib1fARB;
void APIENTRY bluegl_glVertexAttrib1fARB (GLuint index, GLfloat x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1fARB) (GLuint index, GLfloat x);
    return ((PFN_glVertexAttrib1fARB)__blue_glCore_glVertexAttrib1fARB)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1fvARB;
void APIENTRY bluegl_glVertexAttrib1fvARB (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1fvARB) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib1fvARB)__blue_glCore_glVertexAttrib1fvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib1sARB;
void APIENTRY bluegl_glVertexAttrib1sARB (GLuint index, GLshort x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1sARB) (GLuint index, GLshort x);
    return ((PFN_glVertexAttrib1sARB)__blue_glCore_glVertexAttrib1sARB)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1svARB;
void APIENTRY bluegl_glVertexAttrib1svARB (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1svARB) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib1svARB)__blue_glCore_glVertexAttrib1svARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2dARB;
void APIENTRY bluegl_glVertexAttrib2dARB (GLuint index, GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2dARB) (GLuint index, GLdouble x, GLdouble y);
    return ((PFN_glVertexAttrib2dARB)__blue_glCore_glVertexAttrib2dARB)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2dvARB;
void APIENTRY bluegl_glVertexAttrib2dvARB (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2dvARB) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib2dvARB)__blue_glCore_glVertexAttrib2dvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2fARB;
void APIENTRY bluegl_glVertexAttrib2fARB (GLuint index, GLfloat x, GLfloat y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2fARB) (GLuint index, GLfloat x, GLfloat y);
    return ((PFN_glVertexAttrib2fARB)__blue_glCore_glVertexAttrib2fARB)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2fvARB;
void APIENTRY bluegl_glVertexAttrib2fvARB (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2fvARB) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib2fvARB)__blue_glCore_glVertexAttrib2fvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2sARB;
void APIENTRY bluegl_glVertexAttrib2sARB (GLuint index, GLshort x, GLshort y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2sARB) (GLuint index, GLshort x, GLshort y);
    return ((PFN_glVertexAttrib2sARB)__blue_glCore_glVertexAttrib2sARB)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2svARB;
void APIENTRY bluegl_glVertexAttrib2svARB (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2svARB) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib2svARB)__blue_glCore_glVertexAttrib2svARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3dARB;
void APIENTRY bluegl_glVertexAttrib3dARB (GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3dARB) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glVertexAttrib3dARB)__blue_glCore_glVertexAttrib3dARB)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3dvARB;
void APIENTRY bluegl_glVertexAttrib3dvARB (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3dvARB) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib3dvARB)__blue_glCore_glVertexAttrib3dvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3fARB;
void APIENTRY bluegl_glVertexAttrib3fARB (GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3fARB) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glVertexAttrib3fARB)__blue_glCore_glVertexAttrib3fARB)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3fvARB;
void APIENTRY bluegl_glVertexAttrib3fvARB (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3fvARB) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib3fvARB)__blue_glCore_glVertexAttrib3fvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3sARB;
void APIENTRY bluegl_glVertexAttrib3sARB (GLuint index, GLshort x, GLshort y, GLshort z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3sARB) (GLuint index, GLshort x, GLshort y, GLshort z);
    return ((PFN_glVertexAttrib3sARB)__blue_glCore_glVertexAttrib3sARB)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3svARB;
void APIENTRY bluegl_glVertexAttrib3svARB (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3svARB) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib3svARB)__blue_glCore_glVertexAttrib3svARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4NbvARB;
void APIENTRY bluegl_glVertexAttrib4NbvARB (GLuint index, const GLbyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4NbvARB) (GLuint index, const GLbyte *v);
    return ((PFN_glVertexAttrib4NbvARB)__blue_glCore_glVertexAttrib4NbvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4NivARB;
void APIENTRY bluegl_glVertexAttrib4NivARB (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4NivARB) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttrib4NivARB)__blue_glCore_glVertexAttrib4NivARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4NsvARB;
void APIENTRY bluegl_glVertexAttrib4NsvARB (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4NsvARB) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib4NsvARB)__blue_glCore_glVertexAttrib4NsvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4NubARB;
void APIENTRY bluegl_glVertexAttrib4NubARB (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4NubARB) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    return ((PFN_glVertexAttrib4NubARB)__blue_glCore_glVertexAttrib4NubARB)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4NubvARB;
void APIENTRY bluegl_glVertexAttrib4NubvARB (GLuint index, const GLubyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4NubvARB) (GLuint index, const GLubyte *v);
    return ((PFN_glVertexAttrib4NubvARB)__blue_glCore_glVertexAttrib4NubvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4NuivARB;
void APIENTRY bluegl_glVertexAttrib4NuivARB (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4NuivARB) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttrib4NuivARB)__blue_glCore_glVertexAttrib4NuivARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4NusvARB;
void APIENTRY bluegl_glVertexAttrib4NusvARB (GLuint index, const GLushort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4NusvARB) (GLuint index, const GLushort *v);
    return ((PFN_glVertexAttrib4NusvARB)__blue_glCore_glVertexAttrib4NusvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4bvARB;
void APIENTRY bluegl_glVertexAttrib4bvARB (GLuint index, const GLbyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4bvARB) (GLuint index, const GLbyte *v);
    return ((PFN_glVertexAttrib4bvARB)__blue_glCore_glVertexAttrib4bvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4dARB;
void APIENTRY bluegl_glVertexAttrib4dARB (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4dARB) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glVertexAttrib4dARB)__blue_glCore_glVertexAttrib4dARB)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4dvARB;
void APIENTRY bluegl_glVertexAttrib4dvARB (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4dvARB) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib4dvARB)__blue_glCore_glVertexAttrib4dvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4fARB;
void APIENTRY bluegl_glVertexAttrib4fARB (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4fARB) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glVertexAttrib4fARB)__blue_glCore_glVertexAttrib4fARB)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4fvARB;
void APIENTRY bluegl_glVertexAttrib4fvARB (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4fvARB) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib4fvARB)__blue_glCore_glVertexAttrib4fvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4ivARB;
void APIENTRY bluegl_glVertexAttrib4ivARB (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4ivARB) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttrib4ivARB)__blue_glCore_glVertexAttrib4ivARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4sARB;
void APIENTRY bluegl_glVertexAttrib4sARB (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4sARB) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
    return ((PFN_glVertexAttrib4sARB)__blue_glCore_glVertexAttrib4sARB)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4svARB;
void APIENTRY bluegl_glVertexAttrib4svARB (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4svARB) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib4svARB)__blue_glCore_glVertexAttrib4svARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4ubvARB;
void APIENTRY bluegl_glVertexAttrib4ubvARB (GLuint index, const GLubyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4ubvARB) (GLuint index, const GLubyte *v);
    return ((PFN_glVertexAttrib4ubvARB)__blue_glCore_glVertexAttrib4ubvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4uivARB;
void APIENTRY bluegl_glVertexAttrib4uivARB (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4uivARB) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttrib4uivARB)__blue_glCore_glVertexAttrib4uivARB)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4usvARB;
void APIENTRY bluegl_glVertexAttrib4usvARB (GLuint index, const GLushort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4usvARB) (GLuint index, const GLushort *v);
    return ((PFN_glVertexAttrib4usvARB)__blue_glCore_glVertexAttrib4usvARB)(index, v);
}

extern void* __blue_glCore_glVertexAttribPointerARB;
void APIENTRY bluegl_glVertexAttribPointerARB (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexAttribPointerARB) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
    return ((PFN_glVertexAttribPointerARB)__blue_glCore_glVertexAttribPointerARB)(index, size, type, normalized, stride, pointer);
}

extern void* __blue_glCore_glEnableVertexAttribArrayARB;
void APIENTRY bluegl_glEnableVertexAttribArrayARB (GLuint index) {
    typedef void (APIENTRYP PFN_glEnableVertexAttribArrayARB) (GLuint index);
    return ((PFN_glEnableVertexAttribArrayARB)__blue_glCore_glEnableVertexAttribArrayARB)(index);
}

extern void* __blue_glCore_glDisableVertexAttribArrayARB;
void APIENTRY bluegl_glDisableVertexAttribArrayARB (GLuint index) {
    typedef void (APIENTRYP PFN_glDisableVertexAttribArrayARB) (GLuint index);
    return ((PFN_glDisableVertexAttribArrayARB)__blue_glCore_glDisableVertexAttribArrayARB)(index);
}

extern void* __blue_glCore_glGetVertexAttribdvARB;
void APIENTRY bluegl_glGetVertexAttribdvARB (GLuint index, GLenum pname, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribdvARB) (GLuint index, GLenum pname, GLdouble *params);
    return ((PFN_glGetVertexAttribdvARB)__blue_glCore_glGetVertexAttribdvARB)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribfvARB;
void APIENTRY bluegl_glGetVertexAttribfvARB (GLuint index, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribfvARB) (GLuint index, GLenum pname, GLfloat *params);
    return ((PFN_glGetVertexAttribfvARB)__blue_glCore_glGetVertexAttribfvARB)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribivARB;
void APIENTRY bluegl_glGetVertexAttribivARB (GLuint index, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribivARB) (GLuint index, GLenum pname, GLint *params);
    return ((PFN_glGetVertexAttribivARB)__blue_glCore_glGetVertexAttribivARB)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribPointervARB;
void APIENTRY bluegl_glGetVertexAttribPointervARB (GLuint index, GLenum pname, void **pointer) {
    typedef void (APIENTRYP PFN_glGetVertexAttribPointervARB) (GLuint index, GLenum pname, void **pointer);
    return ((PFN_glGetVertexAttribPointervARB)__blue_glCore_glGetVertexAttribPointervARB)(index, pname, pointer);
}

extern void* __blue_glCore_glBindAttribLocationARB;
void APIENTRY bluegl_glBindAttribLocationARB (GLhandleARB programObj, GLuint index, const GLcharARB *name) {
    typedef void (APIENTRYP PFN_glBindAttribLocationARB) (GLhandleARB programObj, GLuint index, const GLcharARB *name);
    return ((PFN_glBindAttribLocationARB)__blue_glCore_glBindAttribLocationARB)(programObj, index, name);
}

extern void* __blue_glCore_glGetActiveAttribARB;
void APIENTRY bluegl_glGetActiveAttribARB (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name) {
    typedef void (APIENTRYP PFN_glGetActiveAttribARB) (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
    return ((PFN_glGetActiveAttribARB)__blue_glCore_glGetActiveAttribARB)(programObj, index, maxLength, length, size, type, name);
}

extern void* __blue_glCore_glGetAttribLocationARB;
GLint APIENTRY bluegl_glGetAttribLocationARB (GLhandleARB programObj, const GLcharARB *name) {
    typedef GLint (APIENTRYP PFN_glGetAttribLocationARB) (GLhandleARB programObj, const GLcharARB *name);
    return ((PFN_glGetAttribLocationARB)__blue_glCore_glGetAttribLocationARB)(programObj, name);
}

extern void* __blue_glCore_glWindowPos2dARB;
void APIENTRY bluegl_glWindowPos2dARB (GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glWindowPos2dARB) (GLdouble x, GLdouble y);
    return ((PFN_glWindowPos2dARB)__blue_glCore_glWindowPos2dARB)(x, y);
}

extern void* __blue_glCore_glWindowPos2dvARB;
void APIENTRY bluegl_glWindowPos2dvARB (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glWindowPos2dvARB) (const GLdouble *v);
    return ((PFN_glWindowPos2dvARB)__blue_glCore_glWindowPos2dvARB)(v);
}

extern void* __blue_glCore_glWindowPos2fARB;
void APIENTRY bluegl_glWindowPos2fARB (GLfloat x, GLfloat y) {
    typedef void (APIENTRYP PFN_glWindowPos2fARB) (GLfloat x, GLfloat y);
    return ((PFN_glWindowPos2fARB)__blue_glCore_glWindowPos2fARB)(x, y);
}

extern void* __blue_glCore_glWindowPos2fvARB;
void APIENTRY bluegl_glWindowPos2fvARB (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glWindowPos2fvARB) (const GLfloat *v);
    return ((PFN_glWindowPos2fvARB)__blue_glCore_glWindowPos2fvARB)(v);
}

extern void* __blue_glCore_glWindowPos2iARB;
void APIENTRY bluegl_glWindowPos2iARB (GLint x, GLint y) {
    typedef void (APIENTRYP PFN_glWindowPos2iARB) (GLint x, GLint y);
    return ((PFN_glWindowPos2iARB)__blue_glCore_glWindowPos2iARB)(x, y);
}

extern void* __blue_glCore_glWindowPos2ivARB;
void APIENTRY bluegl_glWindowPos2ivARB (const GLint *v) {
    typedef void (APIENTRYP PFN_glWindowPos2ivARB) (const GLint *v);
    return ((PFN_glWindowPos2ivARB)__blue_glCore_glWindowPos2ivARB)(v);
}

extern void* __blue_glCore_glWindowPos2sARB;
void APIENTRY bluegl_glWindowPos2sARB (GLshort x, GLshort y) {
    typedef void (APIENTRYP PFN_glWindowPos2sARB) (GLshort x, GLshort y);
    return ((PFN_glWindowPos2sARB)__blue_glCore_glWindowPos2sARB)(x, y);
}

extern void* __blue_glCore_glWindowPos2svARB;
void APIENTRY bluegl_glWindowPos2svARB (const GLshort *v) {
    typedef void (APIENTRYP PFN_glWindowPos2svARB) (const GLshort *v);
    return ((PFN_glWindowPos2svARB)__blue_glCore_glWindowPos2svARB)(v);
}

extern void* __blue_glCore_glWindowPos3dARB;
void APIENTRY bluegl_glWindowPos3dARB (GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glWindowPos3dARB) (GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glWindowPos3dARB)__blue_glCore_glWindowPos3dARB)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3dvARB;
void APIENTRY bluegl_glWindowPos3dvARB (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glWindowPos3dvARB) (const GLdouble *v);
    return ((PFN_glWindowPos3dvARB)__blue_glCore_glWindowPos3dvARB)(v);
}

extern void* __blue_glCore_glWindowPos3fARB;
void APIENTRY bluegl_glWindowPos3fARB (GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glWindowPos3fARB) (GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glWindowPos3fARB)__blue_glCore_glWindowPos3fARB)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3fvARB;
void APIENTRY bluegl_glWindowPos3fvARB (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glWindowPos3fvARB) (const GLfloat *v);
    return ((PFN_glWindowPos3fvARB)__blue_glCore_glWindowPos3fvARB)(v);
}

extern void* __blue_glCore_glWindowPos3iARB;
void APIENTRY bluegl_glWindowPos3iARB (GLint x, GLint y, GLint z) {
    typedef void (APIENTRYP PFN_glWindowPos3iARB) (GLint x, GLint y, GLint z);
    return ((PFN_glWindowPos3iARB)__blue_glCore_glWindowPos3iARB)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3ivARB;
void APIENTRY bluegl_glWindowPos3ivARB (const GLint *v) {
    typedef void (APIENTRYP PFN_glWindowPos3ivARB) (const GLint *v);
    return ((PFN_glWindowPos3ivARB)__blue_glCore_glWindowPos3ivARB)(v);
}

extern void* __blue_glCore_glWindowPos3sARB;
void APIENTRY bluegl_glWindowPos3sARB (GLshort x, GLshort y, GLshort z) {
    typedef void (APIENTRYP PFN_glWindowPos3sARB) (GLshort x, GLshort y, GLshort z);
    return ((PFN_glWindowPos3sARB)__blue_glCore_glWindowPos3sARB)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3svARB;
void APIENTRY bluegl_glWindowPos3svARB (const GLshort *v) {
    typedef void (APIENTRYP PFN_glWindowPos3svARB) (const GLshort *v);
    return ((PFN_glWindowPos3svARB)__blue_glCore_glWindowPos3svARB)(v);
}

extern void* __blue_glCore_glBlendBarrierKHR;
void APIENTRY bluegl_glBlendBarrierKHR (void) {
    typedef void (APIENTRYP PFN_glBlendBarrierKHR) (void);
    return ((PFN_glBlendBarrierKHR)__blue_glCore_glBlendBarrierKHR)();
}

extern void* __blue_glCore_glMultiTexCoord1bOES;
void APIENTRY bluegl_glMultiTexCoord1bOES (GLenum texture, GLbyte s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1bOES) (GLenum texture, GLbyte s);
    return ((PFN_glMultiTexCoord1bOES)__blue_glCore_glMultiTexCoord1bOES)(texture, s);
}

extern void* __blue_glCore_glMultiTexCoord1bvOES;
void APIENTRY bluegl_glMultiTexCoord1bvOES (GLenum texture, const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1bvOES) (GLenum texture, const GLbyte *coords);
    return ((PFN_glMultiTexCoord1bvOES)__blue_glCore_glMultiTexCoord1bvOES)(texture, coords);
}

extern void* __blue_glCore_glMultiTexCoord2bOES;
void APIENTRY bluegl_glMultiTexCoord2bOES (GLenum texture, GLbyte s, GLbyte t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2bOES) (GLenum texture, GLbyte s, GLbyte t);
    return ((PFN_glMultiTexCoord2bOES)__blue_glCore_glMultiTexCoord2bOES)(texture, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2bvOES;
void APIENTRY bluegl_glMultiTexCoord2bvOES (GLenum texture, const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2bvOES) (GLenum texture, const GLbyte *coords);
    return ((PFN_glMultiTexCoord2bvOES)__blue_glCore_glMultiTexCoord2bvOES)(texture, coords);
}

extern void* __blue_glCore_glMultiTexCoord3bOES;
void APIENTRY bluegl_glMultiTexCoord3bOES (GLenum texture, GLbyte s, GLbyte t, GLbyte r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3bOES) (GLenum texture, GLbyte s, GLbyte t, GLbyte r);
    return ((PFN_glMultiTexCoord3bOES)__blue_glCore_glMultiTexCoord3bOES)(texture, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3bvOES;
void APIENTRY bluegl_glMultiTexCoord3bvOES (GLenum texture, const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3bvOES) (GLenum texture, const GLbyte *coords);
    return ((PFN_glMultiTexCoord3bvOES)__blue_glCore_glMultiTexCoord3bvOES)(texture, coords);
}

extern void* __blue_glCore_glMultiTexCoord4bOES;
void APIENTRY bluegl_glMultiTexCoord4bOES (GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4bOES) (GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
    return ((PFN_glMultiTexCoord4bOES)__blue_glCore_glMultiTexCoord4bOES)(texture, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4bvOES;
void APIENTRY bluegl_glMultiTexCoord4bvOES (GLenum texture, const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4bvOES) (GLenum texture, const GLbyte *coords);
    return ((PFN_glMultiTexCoord4bvOES)__blue_glCore_glMultiTexCoord4bvOES)(texture, coords);
}

extern void* __blue_glCore_glTexCoord1bOES;
void APIENTRY bluegl_glTexCoord1bOES (GLbyte s) {
    typedef void (APIENTRYP PFN_glTexCoord1bOES) (GLbyte s);
    return ((PFN_glTexCoord1bOES)__blue_glCore_glTexCoord1bOES)(s);
}

extern void* __blue_glCore_glTexCoord1bvOES;
void APIENTRY bluegl_glTexCoord1bvOES (const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glTexCoord1bvOES) (const GLbyte *coords);
    return ((PFN_glTexCoord1bvOES)__blue_glCore_glTexCoord1bvOES)(coords);
}

extern void* __blue_glCore_glTexCoord2bOES;
void APIENTRY bluegl_glTexCoord2bOES (GLbyte s, GLbyte t) {
    typedef void (APIENTRYP PFN_glTexCoord2bOES) (GLbyte s, GLbyte t);
    return ((PFN_glTexCoord2bOES)__blue_glCore_glTexCoord2bOES)(s, t);
}

extern void* __blue_glCore_glTexCoord2bvOES;
void APIENTRY bluegl_glTexCoord2bvOES (const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glTexCoord2bvOES) (const GLbyte *coords);
    return ((PFN_glTexCoord2bvOES)__blue_glCore_glTexCoord2bvOES)(coords);
}

extern void* __blue_glCore_glTexCoord3bOES;
void APIENTRY bluegl_glTexCoord3bOES (GLbyte s, GLbyte t, GLbyte r) {
    typedef void (APIENTRYP PFN_glTexCoord3bOES) (GLbyte s, GLbyte t, GLbyte r);
    return ((PFN_glTexCoord3bOES)__blue_glCore_glTexCoord3bOES)(s, t, r);
}

extern void* __blue_glCore_glTexCoord3bvOES;
void APIENTRY bluegl_glTexCoord3bvOES (const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glTexCoord3bvOES) (const GLbyte *coords);
    return ((PFN_glTexCoord3bvOES)__blue_glCore_glTexCoord3bvOES)(coords);
}

extern void* __blue_glCore_glTexCoord4bOES;
void APIENTRY bluegl_glTexCoord4bOES (GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
    typedef void (APIENTRYP PFN_glTexCoord4bOES) (GLbyte s, GLbyte t, GLbyte r, GLbyte q);
    return ((PFN_glTexCoord4bOES)__blue_glCore_glTexCoord4bOES)(s, t, r, q);
}

extern void* __blue_glCore_glTexCoord4bvOES;
void APIENTRY bluegl_glTexCoord4bvOES (const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glTexCoord4bvOES) (const GLbyte *coords);
    return ((PFN_glTexCoord4bvOES)__blue_glCore_glTexCoord4bvOES)(coords);
}

extern void* __blue_glCore_glVertex2bOES;
void APIENTRY bluegl_glVertex2bOES (GLbyte x, GLbyte y) {
    typedef void (APIENTRYP PFN_glVertex2bOES) (GLbyte x, GLbyte y);
    return ((PFN_glVertex2bOES)__blue_glCore_glVertex2bOES)(x, y);
}

extern void* __blue_glCore_glVertex2bvOES;
void APIENTRY bluegl_glVertex2bvOES (const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glVertex2bvOES) (const GLbyte *coords);
    return ((PFN_glVertex2bvOES)__blue_glCore_glVertex2bvOES)(coords);
}

extern void* __blue_glCore_glVertex3bOES;
void APIENTRY bluegl_glVertex3bOES (GLbyte x, GLbyte y, GLbyte z) {
    typedef void (APIENTRYP PFN_glVertex3bOES) (GLbyte x, GLbyte y, GLbyte z);
    return ((PFN_glVertex3bOES)__blue_glCore_glVertex3bOES)(x, y, z);
}

extern void* __blue_glCore_glVertex3bvOES;
void APIENTRY bluegl_glVertex3bvOES (const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glVertex3bvOES) (const GLbyte *coords);
    return ((PFN_glVertex3bvOES)__blue_glCore_glVertex3bvOES)(coords);
}

extern void* __blue_glCore_glVertex4bOES;
void APIENTRY bluegl_glVertex4bOES (GLbyte x, GLbyte y, GLbyte z, GLbyte w) {
    typedef void (APIENTRYP PFN_glVertex4bOES) (GLbyte x, GLbyte y, GLbyte z, GLbyte w);
    return ((PFN_glVertex4bOES)__blue_glCore_glVertex4bOES)(x, y, z, w);
}

extern void* __blue_glCore_glVertex4bvOES;
void APIENTRY bluegl_glVertex4bvOES (const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glVertex4bvOES) (const GLbyte *coords);
    return ((PFN_glVertex4bvOES)__blue_glCore_glVertex4bvOES)(coords);
}

extern void* __blue_glCore_glAlphaFuncxOES;
void APIENTRY bluegl_glAlphaFuncxOES (GLenum func, GLfixed ref) {
    typedef void (APIENTRYP PFN_glAlphaFuncxOES) (GLenum func, GLfixed ref);
    return ((PFN_glAlphaFuncxOES)__blue_glCore_glAlphaFuncxOES)(func, ref);
}

extern void* __blue_glCore_glClearColorxOES;
void APIENTRY bluegl_glClearColorxOES (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    typedef void (APIENTRYP PFN_glClearColorxOES) (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
    return ((PFN_glClearColorxOES)__blue_glCore_glClearColorxOES)(red, green, blue, alpha);
}

extern void* __blue_glCore_glClearDepthxOES;
void APIENTRY bluegl_glClearDepthxOES (GLfixed depth) {
    typedef void (APIENTRYP PFN_glClearDepthxOES) (GLfixed depth);
    return ((PFN_glClearDepthxOES)__blue_glCore_glClearDepthxOES)(depth);
}

extern void* __blue_glCore_glClipPlanexOES;
void APIENTRY bluegl_glClipPlanexOES (GLenum plane, const GLfixed *equation) {
    typedef void (APIENTRYP PFN_glClipPlanexOES) (GLenum plane, const GLfixed *equation);
    return ((PFN_glClipPlanexOES)__blue_glCore_glClipPlanexOES)(plane, equation);
}

extern void* __blue_glCore_glColor4xOES;
void APIENTRY bluegl_glColor4xOES (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    typedef void (APIENTRYP PFN_glColor4xOES) (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
    return ((PFN_glColor4xOES)__blue_glCore_glColor4xOES)(red, green, blue, alpha);
}

extern void* __blue_glCore_glDepthRangexOES;
void APIENTRY bluegl_glDepthRangexOES (GLfixed n, GLfixed f) {
    typedef void (APIENTRYP PFN_glDepthRangexOES) (GLfixed n, GLfixed f);
    return ((PFN_glDepthRangexOES)__blue_glCore_glDepthRangexOES)(n, f);
}

extern void* __blue_glCore_glFogxOES;
void APIENTRY bluegl_glFogxOES (GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glFogxOES) (GLenum pname, GLfixed param);
    return ((PFN_glFogxOES)__blue_glCore_glFogxOES)(pname, param);
}

extern void* __blue_glCore_glFogxvOES;
void APIENTRY bluegl_glFogxvOES (GLenum pname, const GLfixed *param) {
    typedef void (APIENTRYP PFN_glFogxvOES) (GLenum pname, const GLfixed *param);
    return ((PFN_glFogxvOES)__blue_glCore_glFogxvOES)(pname, param);
}

extern void* __blue_glCore_glFrustumxOES;
void APIENTRY bluegl_glFrustumxOES (GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
    typedef void (APIENTRYP PFN_glFrustumxOES) (GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
    return ((PFN_glFrustumxOES)__blue_glCore_glFrustumxOES)(l, r, b, t, n, f);
}

extern void* __blue_glCore_glGetClipPlanexOES;
void APIENTRY bluegl_glGetClipPlanexOES (GLenum plane, GLfixed *equation) {
    typedef void (APIENTRYP PFN_glGetClipPlanexOES) (GLenum plane, GLfixed *equation);
    return ((PFN_glGetClipPlanexOES)__blue_glCore_glGetClipPlanexOES)(plane, equation);
}

extern void* __blue_glCore_glGetFixedvOES;
void APIENTRY bluegl_glGetFixedvOES (GLenum pname, GLfixed *params) {
    typedef void (APIENTRYP PFN_glGetFixedvOES) (GLenum pname, GLfixed *params);
    return ((PFN_glGetFixedvOES)__blue_glCore_glGetFixedvOES)(pname, params);
}

extern void* __blue_glCore_glGetTexEnvxvOES;
void APIENTRY bluegl_glGetTexEnvxvOES (GLenum target, GLenum pname, GLfixed *params) {
    typedef void (APIENTRYP PFN_glGetTexEnvxvOES) (GLenum target, GLenum pname, GLfixed *params);
    return ((PFN_glGetTexEnvxvOES)__blue_glCore_glGetTexEnvxvOES)(target, pname, params);
}

extern void* __blue_glCore_glGetTexParameterxvOES;
void APIENTRY bluegl_glGetTexParameterxvOES (GLenum target, GLenum pname, GLfixed *params) {
    typedef void (APIENTRYP PFN_glGetTexParameterxvOES) (GLenum target, GLenum pname, GLfixed *params);
    return ((PFN_glGetTexParameterxvOES)__blue_glCore_glGetTexParameterxvOES)(target, pname, params);
}

extern void* __blue_glCore_glLightModelxOES;
void APIENTRY bluegl_glLightModelxOES (GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glLightModelxOES) (GLenum pname, GLfixed param);
    return ((PFN_glLightModelxOES)__blue_glCore_glLightModelxOES)(pname, param);
}

extern void* __blue_glCore_glLightModelxvOES;
void APIENTRY bluegl_glLightModelxvOES (GLenum pname, const GLfixed *param) {
    typedef void (APIENTRYP PFN_glLightModelxvOES) (GLenum pname, const GLfixed *param);
    return ((PFN_glLightModelxvOES)__blue_glCore_glLightModelxvOES)(pname, param);
}

extern void* __blue_glCore_glLightxOES;
void APIENTRY bluegl_glLightxOES (GLenum light, GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glLightxOES) (GLenum light, GLenum pname, GLfixed param);
    return ((PFN_glLightxOES)__blue_glCore_glLightxOES)(light, pname, param);
}

extern void* __blue_glCore_glLightxvOES;
void APIENTRY bluegl_glLightxvOES (GLenum light, GLenum pname, const GLfixed *params) {
    typedef void (APIENTRYP PFN_glLightxvOES) (GLenum light, GLenum pname, const GLfixed *params);
    return ((PFN_glLightxvOES)__blue_glCore_glLightxvOES)(light, pname, params);
}

extern void* __blue_glCore_glLineWidthxOES;
void APIENTRY bluegl_glLineWidthxOES (GLfixed width) {
    typedef void (APIENTRYP PFN_glLineWidthxOES) (GLfixed width);
    return ((PFN_glLineWidthxOES)__blue_glCore_glLineWidthxOES)(width);
}

extern void* __blue_glCore_glLoadMatrixxOES;
void APIENTRY bluegl_glLoadMatrixxOES (const GLfixed *m) {
    typedef void (APIENTRYP PFN_glLoadMatrixxOES) (const GLfixed *m);
    return ((PFN_glLoadMatrixxOES)__blue_glCore_glLoadMatrixxOES)(m);
}

extern void* __blue_glCore_glMaterialxOES;
void APIENTRY bluegl_glMaterialxOES (GLenum face, GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glMaterialxOES) (GLenum face, GLenum pname, GLfixed param);
    return ((PFN_glMaterialxOES)__blue_glCore_glMaterialxOES)(face, pname, param);
}

extern void* __blue_glCore_glMaterialxvOES;
void APIENTRY bluegl_glMaterialxvOES (GLenum face, GLenum pname, const GLfixed *param) {
    typedef void (APIENTRYP PFN_glMaterialxvOES) (GLenum face, GLenum pname, const GLfixed *param);
    return ((PFN_glMaterialxvOES)__blue_glCore_glMaterialxvOES)(face, pname, param);
}

extern void* __blue_glCore_glMultMatrixxOES;
void APIENTRY bluegl_glMultMatrixxOES (const GLfixed *m) {
    typedef void (APIENTRYP PFN_glMultMatrixxOES) (const GLfixed *m);
    return ((PFN_glMultMatrixxOES)__blue_glCore_glMultMatrixxOES)(m);
}

extern void* __blue_glCore_glMultiTexCoord4xOES;
void APIENTRY bluegl_glMultiTexCoord4xOES (GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4xOES) (GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
    return ((PFN_glMultiTexCoord4xOES)__blue_glCore_glMultiTexCoord4xOES)(texture, s, t, r, q);
}

extern void* __blue_glCore_glNormal3xOES;
void APIENTRY bluegl_glNormal3xOES (GLfixed nx, GLfixed ny, GLfixed nz) {
    typedef void (APIENTRYP PFN_glNormal3xOES) (GLfixed nx, GLfixed ny, GLfixed nz);
    return ((PFN_glNormal3xOES)__blue_glCore_glNormal3xOES)(nx, ny, nz);
}

extern void* __blue_glCore_glOrthoxOES;
void APIENTRY bluegl_glOrthoxOES (GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
    typedef void (APIENTRYP PFN_glOrthoxOES) (GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
    return ((PFN_glOrthoxOES)__blue_glCore_glOrthoxOES)(l, r, b, t, n, f);
}

extern void* __blue_glCore_glPointParameterxvOES;
void APIENTRY bluegl_glPointParameterxvOES (GLenum pname, const GLfixed *params) {
    typedef void (APIENTRYP PFN_glPointParameterxvOES) (GLenum pname, const GLfixed *params);
    return ((PFN_glPointParameterxvOES)__blue_glCore_glPointParameterxvOES)(pname, params);
}

extern void* __blue_glCore_glPointSizexOES;
void APIENTRY bluegl_glPointSizexOES (GLfixed size) {
    typedef void (APIENTRYP PFN_glPointSizexOES) (GLfixed size);
    return ((PFN_glPointSizexOES)__blue_glCore_glPointSizexOES)(size);
}

extern void* __blue_glCore_glPolygonOffsetxOES;
void APIENTRY bluegl_glPolygonOffsetxOES (GLfixed factor, GLfixed units) {
    typedef void (APIENTRYP PFN_glPolygonOffsetxOES) (GLfixed factor, GLfixed units);
    return ((PFN_glPolygonOffsetxOES)__blue_glCore_glPolygonOffsetxOES)(factor, units);
}

extern void* __blue_glCore_glRotatexOES;
void APIENTRY bluegl_glRotatexOES (GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
    typedef void (APIENTRYP PFN_glRotatexOES) (GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
    return ((PFN_glRotatexOES)__blue_glCore_glRotatexOES)(angle, x, y, z);
}

extern void* __blue_glCore_glScalexOES;
void APIENTRY bluegl_glScalexOES (GLfixed x, GLfixed y, GLfixed z) {
    typedef void (APIENTRYP PFN_glScalexOES) (GLfixed x, GLfixed y, GLfixed z);
    return ((PFN_glScalexOES)__blue_glCore_glScalexOES)(x, y, z);
}

extern void* __blue_glCore_glTexEnvxOES;
void APIENTRY bluegl_glTexEnvxOES (GLenum target, GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glTexEnvxOES) (GLenum target, GLenum pname, GLfixed param);
    return ((PFN_glTexEnvxOES)__blue_glCore_glTexEnvxOES)(target, pname, param);
}

extern void* __blue_glCore_glTexEnvxvOES;
void APIENTRY bluegl_glTexEnvxvOES (GLenum target, GLenum pname, const GLfixed *params) {
    typedef void (APIENTRYP PFN_glTexEnvxvOES) (GLenum target, GLenum pname, const GLfixed *params);
    return ((PFN_glTexEnvxvOES)__blue_glCore_glTexEnvxvOES)(target, pname, params);
}

extern void* __blue_glCore_glTexParameterxOES;
void APIENTRY bluegl_glTexParameterxOES (GLenum target, GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glTexParameterxOES) (GLenum target, GLenum pname, GLfixed param);
    return ((PFN_glTexParameterxOES)__blue_glCore_glTexParameterxOES)(target, pname, param);
}

extern void* __blue_glCore_glTexParameterxvOES;
void APIENTRY bluegl_glTexParameterxvOES (GLenum target, GLenum pname, const GLfixed *params) {
    typedef void (APIENTRYP PFN_glTexParameterxvOES) (GLenum target, GLenum pname, const GLfixed *params);
    return ((PFN_glTexParameterxvOES)__blue_glCore_glTexParameterxvOES)(target, pname, params);
}

extern void* __blue_glCore_glTranslatexOES;
void APIENTRY bluegl_glTranslatexOES (GLfixed x, GLfixed y, GLfixed z) {
    typedef void (APIENTRYP PFN_glTranslatexOES) (GLfixed x, GLfixed y, GLfixed z);
    return ((PFN_glTranslatexOES)__blue_glCore_glTranslatexOES)(x, y, z);
}

extern void* __blue_glCore_glAccumxOES;
void APIENTRY bluegl_glAccumxOES (GLenum op, GLfixed value) {
    typedef void (APIENTRYP PFN_glAccumxOES) (GLenum op, GLfixed value);
    return ((PFN_glAccumxOES)__blue_glCore_glAccumxOES)(op, value);
}

extern void* __blue_glCore_glBitmapxOES;
void APIENTRY bluegl_glBitmapxOES (GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte *bitmap) {
    typedef void (APIENTRYP PFN_glBitmapxOES) (GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte *bitmap);
    return ((PFN_glBitmapxOES)__blue_glCore_glBitmapxOES)(width, height, xorig, yorig, xmove, ymove, bitmap);
}

extern void* __blue_glCore_glBlendColorxOES;
void APIENTRY bluegl_glBlendColorxOES (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    typedef void (APIENTRYP PFN_glBlendColorxOES) (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
    return ((PFN_glBlendColorxOES)__blue_glCore_glBlendColorxOES)(red, green, blue, alpha);
}

extern void* __blue_glCore_glClearAccumxOES;
void APIENTRY bluegl_glClearAccumxOES (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    typedef void (APIENTRYP PFN_glClearAccumxOES) (GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
    return ((PFN_glClearAccumxOES)__blue_glCore_glClearAccumxOES)(red, green, blue, alpha);
}

extern void* __blue_glCore_glColor3xOES;
void APIENTRY bluegl_glColor3xOES (GLfixed red, GLfixed green, GLfixed blue) {
    typedef void (APIENTRYP PFN_glColor3xOES) (GLfixed red, GLfixed green, GLfixed blue);
    return ((PFN_glColor3xOES)__blue_glCore_glColor3xOES)(red, green, blue);
}

extern void* __blue_glCore_glColor3xvOES;
void APIENTRY bluegl_glColor3xvOES (const GLfixed *components) {
    typedef void (APIENTRYP PFN_glColor3xvOES) (const GLfixed *components);
    return ((PFN_glColor3xvOES)__blue_glCore_glColor3xvOES)(components);
}

extern void* __blue_glCore_glColor4xvOES;
void APIENTRY bluegl_glColor4xvOES (const GLfixed *components) {
    typedef void (APIENTRYP PFN_glColor4xvOES) (const GLfixed *components);
    return ((PFN_glColor4xvOES)__blue_glCore_glColor4xvOES)(components);
}

extern void* __blue_glCore_glConvolutionParameterxOES;
void APIENTRY bluegl_glConvolutionParameterxOES (GLenum target, GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glConvolutionParameterxOES) (GLenum target, GLenum pname, GLfixed param);
    return ((PFN_glConvolutionParameterxOES)__blue_glCore_glConvolutionParameterxOES)(target, pname, param);
}

extern void* __blue_glCore_glConvolutionParameterxvOES;
void APIENTRY bluegl_glConvolutionParameterxvOES (GLenum target, GLenum pname, const GLfixed *params) {
    typedef void (APIENTRYP PFN_glConvolutionParameterxvOES) (GLenum target, GLenum pname, const GLfixed *params);
    return ((PFN_glConvolutionParameterxvOES)__blue_glCore_glConvolutionParameterxvOES)(target, pname, params);
}

extern void* __blue_glCore_glEvalCoord1xOES;
void APIENTRY bluegl_glEvalCoord1xOES (GLfixed u) {
    typedef void (APIENTRYP PFN_glEvalCoord1xOES) (GLfixed u);
    return ((PFN_glEvalCoord1xOES)__blue_glCore_glEvalCoord1xOES)(u);
}

extern void* __blue_glCore_glEvalCoord1xvOES;
void APIENTRY bluegl_glEvalCoord1xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glEvalCoord1xvOES) (const GLfixed *coords);
    return ((PFN_glEvalCoord1xvOES)__blue_glCore_glEvalCoord1xvOES)(coords);
}

extern void* __blue_glCore_glEvalCoord2xOES;
void APIENTRY bluegl_glEvalCoord2xOES (GLfixed u, GLfixed v) {
    typedef void (APIENTRYP PFN_glEvalCoord2xOES) (GLfixed u, GLfixed v);
    return ((PFN_glEvalCoord2xOES)__blue_glCore_glEvalCoord2xOES)(u, v);
}

extern void* __blue_glCore_glEvalCoord2xvOES;
void APIENTRY bluegl_glEvalCoord2xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glEvalCoord2xvOES) (const GLfixed *coords);
    return ((PFN_glEvalCoord2xvOES)__blue_glCore_glEvalCoord2xvOES)(coords);
}

extern void* __blue_glCore_glFeedbackBufferxOES;
void APIENTRY bluegl_glFeedbackBufferxOES (GLsizei n, GLenum type, const GLfixed *buffer) {
    typedef void (APIENTRYP PFN_glFeedbackBufferxOES) (GLsizei n, GLenum type, const GLfixed *buffer);
    return ((PFN_glFeedbackBufferxOES)__blue_glCore_glFeedbackBufferxOES)(n, type, buffer);
}

extern void* __blue_glCore_glGetConvolutionParameterxvOES;
void APIENTRY bluegl_glGetConvolutionParameterxvOES (GLenum target, GLenum pname, GLfixed *params) {
    typedef void (APIENTRYP PFN_glGetConvolutionParameterxvOES) (GLenum target, GLenum pname, GLfixed *params);
    return ((PFN_glGetConvolutionParameterxvOES)__blue_glCore_glGetConvolutionParameterxvOES)(target, pname, params);
}

extern void* __blue_glCore_glGetHistogramParameterxvOES;
void APIENTRY bluegl_glGetHistogramParameterxvOES (GLenum target, GLenum pname, GLfixed *params) {
    typedef void (APIENTRYP PFN_glGetHistogramParameterxvOES) (GLenum target, GLenum pname, GLfixed *params);
    return ((PFN_glGetHistogramParameterxvOES)__blue_glCore_glGetHistogramParameterxvOES)(target, pname, params);
}

extern void* __blue_glCore_glGetLightxOES;
void APIENTRY bluegl_glGetLightxOES (GLenum light, GLenum pname, GLfixed *params) {
    typedef void (APIENTRYP PFN_glGetLightxOES) (GLenum light, GLenum pname, GLfixed *params);
    return ((PFN_glGetLightxOES)__blue_glCore_glGetLightxOES)(light, pname, params);
}

extern void* __blue_glCore_glGetMapxvOES;
void APIENTRY bluegl_glGetMapxvOES (GLenum target, GLenum query, GLfixed *v) {
    typedef void (APIENTRYP PFN_glGetMapxvOES) (GLenum target, GLenum query, GLfixed *v);
    return ((PFN_glGetMapxvOES)__blue_glCore_glGetMapxvOES)(target, query, v);
}

extern void* __blue_glCore_glGetMaterialxOES;
void APIENTRY bluegl_glGetMaterialxOES (GLenum face, GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glGetMaterialxOES) (GLenum face, GLenum pname, GLfixed param);
    return ((PFN_glGetMaterialxOES)__blue_glCore_glGetMaterialxOES)(face, pname, param);
}

extern void* __blue_glCore_glGetPixelMapxv;
void APIENTRY bluegl_glGetPixelMapxv (GLenum map, GLint size, GLfixed *values) {
    typedef void (APIENTRYP PFN_glGetPixelMapxv) (GLenum map, GLint size, GLfixed *values);
    return ((PFN_glGetPixelMapxv)__blue_glCore_glGetPixelMapxv)(map, size, values);
}

extern void* __blue_glCore_glGetTexGenxvOES;
void APIENTRY bluegl_glGetTexGenxvOES (GLenum coord, GLenum pname, GLfixed *params) {
    typedef void (APIENTRYP PFN_glGetTexGenxvOES) (GLenum coord, GLenum pname, GLfixed *params);
    return ((PFN_glGetTexGenxvOES)__blue_glCore_glGetTexGenxvOES)(coord, pname, params);
}

extern void* __blue_glCore_glGetTexLevelParameterxvOES;
void APIENTRY bluegl_glGetTexLevelParameterxvOES (GLenum target, GLint level, GLenum pname, GLfixed *params) {
    typedef void (APIENTRYP PFN_glGetTexLevelParameterxvOES) (GLenum target, GLint level, GLenum pname, GLfixed *params);
    return ((PFN_glGetTexLevelParameterxvOES)__blue_glCore_glGetTexLevelParameterxvOES)(target, level, pname, params);
}

extern void* __blue_glCore_glIndexxOES;
void APIENTRY bluegl_glIndexxOES (GLfixed component) {
    typedef void (APIENTRYP PFN_glIndexxOES) (GLfixed component);
    return ((PFN_glIndexxOES)__blue_glCore_glIndexxOES)(component);
}

extern void* __blue_glCore_glIndexxvOES;
void APIENTRY bluegl_glIndexxvOES (const GLfixed *component) {
    typedef void (APIENTRYP PFN_glIndexxvOES) (const GLfixed *component);
    return ((PFN_glIndexxvOES)__blue_glCore_glIndexxvOES)(component);
}

extern void* __blue_glCore_glLoadTransposeMatrixxOES;
void APIENTRY bluegl_glLoadTransposeMatrixxOES (const GLfixed *m) {
    typedef void (APIENTRYP PFN_glLoadTransposeMatrixxOES) (const GLfixed *m);
    return ((PFN_glLoadTransposeMatrixxOES)__blue_glCore_glLoadTransposeMatrixxOES)(m);
}

extern void* __blue_glCore_glMap1xOES;
void APIENTRY bluegl_glMap1xOES (GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points) {
    typedef void (APIENTRYP PFN_glMap1xOES) (GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points);
    return ((PFN_glMap1xOES)__blue_glCore_glMap1xOES)(target, u1, u2, stride, order, points);
}

extern void* __blue_glCore_glMap2xOES;
void APIENTRY bluegl_glMap2xOES (GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points) {
    typedef void (APIENTRYP PFN_glMap2xOES) (GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points);
    return ((PFN_glMap2xOES)__blue_glCore_glMap2xOES)(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

extern void* __blue_glCore_glMapGrid1xOES;
void APIENTRY bluegl_glMapGrid1xOES (GLint n, GLfixed u1, GLfixed u2) {
    typedef void (APIENTRYP PFN_glMapGrid1xOES) (GLint n, GLfixed u1, GLfixed u2);
    return ((PFN_glMapGrid1xOES)__blue_glCore_glMapGrid1xOES)(n, u1, u2);
}

extern void* __blue_glCore_glMapGrid2xOES;
void APIENTRY bluegl_glMapGrid2xOES (GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2) {
    typedef void (APIENTRYP PFN_glMapGrid2xOES) (GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2);
    return ((PFN_glMapGrid2xOES)__blue_glCore_glMapGrid2xOES)(n, u1, u2, v1, v2);
}

extern void* __blue_glCore_glMultTransposeMatrixxOES;
void APIENTRY bluegl_glMultTransposeMatrixxOES (const GLfixed *m) {
    typedef void (APIENTRYP PFN_glMultTransposeMatrixxOES) (const GLfixed *m);
    return ((PFN_glMultTransposeMatrixxOES)__blue_glCore_glMultTransposeMatrixxOES)(m);
}

extern void* __blue_glCore_glMultiTexCoord1xOES;
void APIENTRY bluegl_glMultiTexCoord1xOES (GLenum texture, GLfixed s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1xOES) (GLenum texture, GLfixed s);
    return ((PFN_glMultiTexCoord1xOES)__blue_glCore_glMultiTexCoord1xOES)(texture, s);
}

extern void* __blue_glCore_glMultiTexCoord1xvOES;
void APIENTRY bluegl_glMultiTexCoord1xvOES (GLenum texture, const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1xvOES) (GLenum texture, const GLfixed *coords);
    return ((PFN_glMultiTexCoord1xvOES)__blue_glCore_glMultiTexCoord1xvOES)(texture, coords);
}

extern void* __blue_glCore_glMultiTexCoord2xOES;
void APIENTRY bluegl_glMultiTexCoord2xOES (GLenum texture, GLfixed s, GLfixed t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2xOES) (GLenum texture, GLfixed s, GLfixed t);
    return ((PFN_glMultiTexCoord2xOES)__blue_glCore_glMultiTexCoord2xOES)(texture, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2xvOES;
void APIENTRY bluegl_glMultiTexCoord2xvOES (GLenum texture, const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2xvOES) (GLenum texture, const GLfixed *coords);
    return ((PFN_glMultiTexCoord2xvOES)__blue_glCore_glMultiTexCoord2xvOES)(texture, coords);
}

extern void* __blue_glCore_glMultiTexCoord3xOES;
void APIENTRY bluegl_glMultiTexCoord3xOES (GLenum texture, GLfixed s, GLfixed t, GLfixed r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3xOES) (GLenum texture, GLfixed s, GLfixed t, GLfixed r);
    return ((PFN_glMultiTexCoord3xOES)__blue_glCore_glMultiTexCoord3xOES)(texture, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3xvOES;
void APIENTRY bluegl_glMultiTexCoord3xvOES (GLenum texture, const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3xvOES) (GLenum texture, const GLfixed *coords);
    return ((PFN_glMultiTexCoord3xvOES)__blue_glCore_glMultiTexCoord3xvOES)(texture, coords);
}

extern void* __blue_glCore_glMultiTexCoord4xvOES;
void APIENTRY bluegl_glMultiTexCoord4xvOES (GLenum texture, const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4xvOES) (GLenum texture, const GLfixed *coords);
    return ((PFN_glMultiTexCoord4xvOES)__blue_glCore_glMultiTexCoord4xvOES)(texture, coords);
}

extern void* __blue_glCore_glNormal3xvOES;
void APIENTRY bluegl_glNormal3xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glNormal3xvOES) (const GLfixed *coords);
    return ((PFN_glNormal3xvOES)__blue_glCore_glNormal3xvOES)(coords);
}

extern void* __blue_glCore_glPassThroughxOES;
void APIENTRY bluegl_glPassThroughxOES (GLfixed token) {
    typedef void (APIENTRYP PFN_glPassThroughxOES) (GLfixed token);
    return ((PFN_glPassThroughxOES)__blue_glCore_glPassThroughxOES)(token);
}

extern void* __blue_glCore_glPixelMapx;
void APIENTRY bluegl_glPixelMapx (GLenum map, GLint size, const GLfixed *values) {
    typedef void (APIENTRYP PFN_glPixelMapx) (GLenum map, GLint size, const GLfixed *values);
    return ((PFN_glPixelMapx)__blue_glCore_glPixelMapx)(map, size, values);
}

extern void* __blue_glCore_glPixelStorex;
void APIENTRY bluegl_glPixelStorex (GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glPixelStorex) (GLenum pname, GLfixed param);
    return ((PFN_glPixelStorex)__blue_glCore_glPixelStorex)(pname, param);
}

extern void* __blue_glCore_glPixelTransferxOES;
void APIENTRY bluegl_glPixelTransferxOES (GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glPixelTransferxOES) (GLenum pname, GLfixed param);
    return ((PFN_glPixelTransferxOES)__blue_glCore_glPixelTransferxOES)(pname, param);
}

extern void* __blue_glCore_glPixelZoomxOES;
void APIENTRY bluegl_glPixelZoomxOES (GLfixed xfactor, GLfixed yfactor) {
    typedef void (APIENTRYP PFN_glPixelZoomxOES) (GLfixed xfactor, GLfixed yfactor);
    return ((PFN_glPixelZoomxOES)__blue_glCore_glPixelZoomxOES)(xfactor, yfactor);
}

extern void* __blue_glCore_glPrioritizeTexturesxOES;
void APIENTRY bluegl_glPrioritizeTexturesxOES (GLsizei n, const GLuint *textures, const GLfixed *priorities) {
    typedef void (APIENTRYP PFN_glPrioritizeTexturesxOES) (GLsizei n, const GLuint *textures, const GLfixed *priorities);
    return ((PFN_glPrioritizeTexturesxOES)__blue_glCore_glPrioritizeTexturesxOES)(n, textures, priorities);
}

extern void* __blue_glCore_glRasterPos2xOES;
void APIENTRY bluegl_glRasterPos2xOES (GLfixed x, GLfixed y) {
    typedef void (APIENTRYP PFN_glRasterPos2xOES) (GLfixed x, GLfixed y);
    return ((PFN_glRasterPos2xOES)__blue_glCore_glRasterPos2xOES)(x, y);
}

extern void* __blue_glCore_glRasterPos2xvOES;
void APIENTRY bluegl_glRasterPos2xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glRasterPos2xvOES) (const GLfixed *coords);
    return ((PFN_glRasterPos2xvOES)__blue_glCore_glRasterPos2xvOES)(coords);
}

extern void* __blue_glCore_glRasterPos3xOES;
void APIENTRY bluegl_glRasterPos3xOES (GLfixed x, GLfixed y, GLfixed z) {
    typedef void (APIENTRYP PFN_glRasterPos3xOES) (GLfixed x, GLfixed y, GLfixed z);
    return ((PFN_glRasterPos3xOES)__blue_glCore_glRasterPos3xOES)(x, y, z);
}

extern void* __blue_glCore_glRasterPos3xvOES;
void APIENTRY bluegl_glRasterPos3xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glRasterPos3xvOES) (const GLfixed *coords);
    return ((PFN_glRasterPos3xvOES)__blue_glCore_glRasterPos3xvOES)(coords);
}

extern void* __blue_glCore_glRasterPos4xOES;
void APIENTRY bluegl_glRasterPos4xOES (GLfixed x, GLfixed y, GLfixed z, GLfixed w) {
    typedef void (APIENTRYP PFN_glRasterPos4xOES) (GLfixed x, GLfixed y, GLfixed z, GLfixed w);
    return ((PFN_glRasterPos4xOES)__blue_glCore_glRasterPos4xOES)(x, y, z, w);
}

extern void* __blue_glCore_glRasterPos4xvOES;
void APIENTRY bluegl_glRasterPos4xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glRasterPos4xvOES) (const GLfixed *coords);
    return ((PFN_glRasterPos4xvOES)__blue_glCore_glRasterPos4xvOES)(coords);
}

extern void* __blue_glCore_glRectxOES;
void APIENTRY bluegl_glRectxOES (GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2) {
    typedef void (APIENTRYP PFN_glRectxOES) (GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2);
    return ((PFN_glRectxOES)__blue_glCore_glRectxOES)(x1, y1, x2, y2);
}

extern void* __blue_glCore_glRectxvOES;
void APIENTRY bluegl_glRectxvOES (const GLfixed *v1, const GLfixed *v2) {
    typedef void (APIENTRYP PFN_glRectxvOES) (const GLfixed *v1, const GLfixed *v2);
    return ((PFN_glRectxvOES)__blue_glCore_glRectxvOES)(v1, v2);
}

extern void* __blue_glCore_glTexCoord1xOES;
void APIENTRY bluegl_glTexCoord1xOES (GLfixed s) {
    typedef void (APIENTRYP PFN_glTexCoord1xOES) (GLfixed s);
    return ((PFN_glTexCoord1xOES)__blue_glCore_glTexCoord1xOES)(s);
}

extern void* __blue_glCore_glTexCoord1xvOES;
void APIENTRY bluegl_glTexCoord1xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glTexCoord1xvOES) (const GLfixed *coords);
    return ((PFN_glTexCoord1xvOES)__blue_glCore_glTexCoord1xvOES)(coords);
}

extern void* __blue_glCore_glTexCoord2xOES;
void APIENTRY bluegl_glTexCoord2xOES (GLfixed s, GLfixed t) {
    typedef void (APIENTRYP PFN_glTexCoord2xOES) (GLfixed s, GLfixed t);
    return ((PFN_glTexCoord2xOES)__blue_glCore_glTexCoord2xOES)(s, t);
}

extern void* __blue_glCore_glTexCoord2xvOES;
void APIENTRY bluegl_glTexCoord2xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glTexCoord2xvOES) (const GLfixed *coords);
    return ((PFN_glTexCoord2xvOES)__blue_glCore_glTexCoord2xvOES)(coords);
}

extern void* __blue_glCore_glTexCoord3xOES;
void APIENTRY bluegl_glTexCoord3xOES (GLfixed s, GLfixed t, GLfixed r) {
    typedef void (APIENTRYP PFN_glTexCoord3xOES) (GLfixed s, GLfixed t, GLfixed r);
    return ((PFN_glTexCoord3xOES)__blue_glCore_glTexCoord3xOES)(s, t, r);
}

extern void* __blue_glCore_glTexCoord3xvOES;
void APIENTRY bluegl_glTexCoord3xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glTexCoord3xvOES) (const GLfixed *coords);
    return ((PFN_glTexCoord3xvOES)__blue_glCore_glTexCoord3xvOES)(coords);
}

extern void* __blue_glCore_glTexCoord4xOES;
void APIENTRY bluegl_glTexCoord4xOES (GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    typedef void (APIENTRYP PFN_glTexCoord4xOES) (GLfixed s, GLfixed t, GLfixed r, GLfixed q);
    return ((PFN_glTexCoord4xOES)__blue_glCore_glTexCoord4xOES)(s, t, r, q);
}

extern void* __blue_glCore_glTexCoord4xvOES;
void APIENTRY bluegl_glTexCoord4xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glTexCoord4xvOES) (const GLfixed *coords);
    return ((PFN_glTexCoord4xvOES)__blue_glCore_glTexCoord4xvOES)(coords);
}

extern void* __blue_glCore_glTexGenxOES;
void APIENTRY bluegl_glTexGenxOES (GLenum coord, GLenum pname, GLfixed param) {
    typedef void (APIENTRYP PFN_glTexGenxOES) (GLenum coord, GLenum pname, GLfixed param);
    return ((PFN_glTexGenxOES)__blue_glCore_glTexGenxOES)(coord, pname, param);
}

extern void* __blue_glCore_glTexGenxvOES;
void APIENTRY bluegl_glTexGenxvOES (GLenum coord, GLenum pname, const GLfixed *params) {
    typedef void (APIENTRYP PFN_glTexGenxvOES) (GLenum coord, GLenum pname, const GLfixed *params);
    return ((PFN_glTexGenxvOES)__blue_glCore_glTexGenxvOES)(coord, pname, params);
}

extern void* __blue_glCore_glVertex2xOES;
void APIENTRY bluegl_glVertex2xOES (GLfixed x) {
    typedef void (APIENTRYP PFN_glVertex2xOES) (GLfixed x);
    return ((PFN_glVertex2xOES)__blue_glCore_glVertex2xOES)(x);
}

extern void* __blue_glCore_glVertex2xvOES;
void APIENTRY bluegl_glVertex2xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glVertex2xvOES) (const GLfixed *coords);
    return ((PFN_glVertex2xvOES)__blue_glCore_glVertex2xvOES)(coords);
}

extern void* __blue_glCore_glVertex3xOES;
void APIENTRY bluegl_glVertex3xOES (GLfixed x, GLfixed y) {
    typedef void (APIENTRYP PFN_glVertex3xOES) (GLfixed x, GLfixed y);
    return ((PFN_glVertex3xOES)__blue_glCore_glVertex3xOES)(x, y);
}

extern void* __blue_glCore_glVertex3xvOES;
void APIENTRY bluegl_glVertex3xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glVertex3xvOES) (const GLfixed *coords);
    return ((PFN_glVertex3xvOES)__blue_glCore_glVertex3xvOES)(coords);
}

extern void* __blue_glCore_glVertex4xOES;
void APIENTRY bluegl_glVertex4xOES (GLfixed x, GLfixed y, GLfixed z) {
    typedef void (APIENTRYP PFN_glVertex4xOES) (GLfixed x, GLfixed y, GLfixed z);
    return ((PFN_glVertex4xOES)__blue_glCore_glVertex4xOES)(x, y, z);
}

extern void* __blue_glCore_glVertex4xvOES;
void APIENTRY bluegl_glVertex4xvOES (const GLfixed *coords) {
    typedef void (APIENTRYP PFN_glVertex4xvOES) (const GLfixed *coords);
    return ((PFN_glVertex4xvOES)__blue_glCore_glVertex4xvOES)(coords);
}

extern void* __blue_glCore_glQueryMatrixxOES;
GLbitfield APIENTRY bluegl_glQueryMatrixxOES (GLfixed *mantissa, GLint *exponent) {
    typedef GLbitfield (APIENTRYP PFN_glQueryMatrixxOES) (GLfixed *mantissa, GLint *exponent);
    return ((PFN_glQueryMatrixxOES)__blue_glCore_glQueryMatrixxOES)(mantissa, exponent);
}

extern void* __blue_glCore_glClearDepthfOES;
void APIENTRY bluegl_glClearDepthfOES (GLclampf depth) {
    typedef void (APIENTRYP PFN_glClearDepthfOES) (GLclampf depth);
    return ((PFN_glClearDepthfOES)__blue_glCore_glClearDepthfOES)(depth);
}

extern void* __blue_glCore_glClipPlanefOES;
void APIENTRY bluegl_glClipPlanefOES (GLenum plane, const GLfloat *equation) {
    typedef void (APIENTRYP PFN_glClipPlanefOES) (GLenum plane, const GLfloat *equation);
    return ((PFN_glClipPlanefOES)__blue_glCore_glClipPlanefOES)(plane, equation);
}

extern void* __blue_glCore_glDepthRangefOES;
void APIENTRY bluegl_glDepthRangefOES (GLclampf n, GLclampf f) {
    typedef void (APIENTRYP PFN_glDepthRangefOES) (GLclampf n, GLclampf f);
    return ((PFN_glDepthRangefOES)__blue_glCore_glDepthRangefOES)(n, f);
}

extern void* __blue_glCore_glFrustumfOES;
void APIENTRY bluegl_glFrustumfOES (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
    typedef void (APIENTRYP PFN_glFrustumfOES) (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
    return ((PFN_glFrustumfOES)__blue_glCore_glFrustumfOES)(l, r, b, t, n, f);
}

extern void* __blue_glCore_glGetClipPlanefOES;
void APIENTRY bluegl_glGetClipPlanefOES (GLenum plane, GLfloat *equation) {
    typedef void (APIENTRYP PFN_glGetClipPlanefOES) (GLenum plane, GLfloat *equation);
    return ((PFN_glGetClipPlanefOES)__blue_glCore_glGetClipPlanefOES)(plane, equation);
}

extern void* __blue_glCore_glOrthofOES;
void APIENTRY bluegl_glOrthofOES (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
    typedef void (APIENTRYP PFN_glOrthofOES) (GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
    return ((PFN_glOrthofOES)__blue_glCore_glOrthofOES)(l, r, b, t, n, f);
}

extern void* __blue_glCore_glTbufferMask3DFX;
void APIENTRY bluegl_glTbufferMask3DFX (GLuint mask) {
    typedef void (APIENTRYP PFN_glTbufferMask3DFX) (GLuint mask);
    return ((PFN_glTbufferMask3DFX)__blue_glCore_glTbufferMask3DFX)(mask);
}

extern void* __blue_glCore_glDebugMessageEnableAMD;
void APIENTRY bluegl_glDebugMessageEnableAMD (GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) {
    typedef void (APIENTRYP PFN_glDebugMessageEnableAMD) (GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
    return ((PFN_glDebugMessageEnableAMD)__blue_glCore_glDebugMessageEnableAMD)(category, severity, count, ids, enabled);
}

extern void* __blue_glCore_glDebugMessageInsertAMD;
void APIENTRY bluegl_glDebugMessageInsertAMD (GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf) {
    typedef void (APIENTRYP PFN_glDebugMessageInsertAMD) (GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf);
    return ((PFN_glDebugMessageInsertAMD)__blue_glCore_glDebugMessageInsertAMD)(category, severity, id, length, buf);
}

extern void* __blue_glCore_glDebugMessageCallbackAMD;
void APIENTRY bluegl_glDebugMessageCallbackAMD (GLDEBUGPROCAMD callback, void *userParam) {
    typedef void (APIENTRYP PFN_glDebugMessageCallbackAMD) (GLDEBUGPROCAMD callback, void *userParam);
    return ((PFN_glDebugMessageCallbackAMD)__blue_glCore_glDebugMessageCallbackAMD)(callback, userParam);
}

extern void* __blue_glCore_glGetDebugMessageLogAMD;
GLuint APIENTRY bluegl_glGetDebugMessageLogAMD (GLuint count, GLsizei bufsize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message) {
    typedef GLuint (APIENTRYP PFN_glGetDebugMessageLogAMD) (GLuint count, GLsizei bufsize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message);
    return ((PFN_glGetDebugMessageLogAMD)__blue_glCore_glGetDebugMessageLogAMD)(count, bufsize, categories, severities, ids, lengths, message);
}

extern void* __blue_glCore_glBlendFuncIndexedAMD;
void APIENTRY bluegl_glBlendFuncIndexedAMD (GLuint buf, GLenum src, GLenum dst) {
    typedef void (APIENTRYP PFN_glBlendFuncIndexedAMD) (GLuint buf, GLenum src, GLenum dst);
    return ((PFN_glBlendFuncIndexedAMD)__blue_glCore_glBlendFuncIndexedAMD)(buf, src, dst);
}

extern void* __blue_glCore_glBlendFuncSeparateIndexedAMD;
void APIENTRY bluegl_glBlendFuncSeparateIndexedAMD (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    typedef void (APIENTRYP PFN_glBlendFuncSeparateIndexedAMD) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    return ((PFN_glBlendFuncSeparateIndexedAMD)__blue_glCore_glBlendFuncSeparateIndexedAMD)(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

extern void* __blue_glCore_glBlendEquationIndexedAMD;
void APIENTRY bluegl_glBlendEquationIndexedAMD (GLuint buf, GLenum mode) {
    typedef void (APIENTRYP PFN_glBlendEquationIndexedAMD) (GLuint buf, GLenum mode);
    return ((PFN_glBlendEquationIndexedAMD)__blue_glCore_glBlendEquationIndexedAMD)(buf, mode);
}

extern void* __blue_glCore_glBlendEquationSeparateIndexedAMD;
void APIENTRY bluegl_glBlendEquationSeparateIndexedAMD (GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
    typedef void (APIENTRYP PFN_glBlendEquationSeparateIndexedAMD) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    return ((PFN_glBlendEquationSeparateIndexedAMD)__blue_glCore_glBlendEquationSeparateIndexedAMD)(buf, modeRGB, modeAlpha);
}

extern void* __blue_glCore_glUniform1i64NV;
void APIENTRY bluegl_glUniform1i64NV (GLint location, GLint64EXT x) {
    typedef void (APIENTRYP PFN_glUniform1i64NV) (GLint location, GLint64EXT x);
    return ((PFN_glUniform1i64NV)__blue_glCore_glUniform1i64NV)(location, x);
}

extern void* __blue_glCore_glUniform2i64NV;
void APIENTRY bluegl_glUniform2i64NV (GLint location, GLint64EXT x, GLint64EXT y) {
    typedef void (APIENTRYP PFN_glUniform2i64NV) (GLint location, GLint64EXT x, GLint64EXT y);
    return ((PFN_glUniform2i64NV)__blue_glCore_glUniform2i64NV)(location, x, y);
}

extern void* __blue_glCore_glUniform3i64NV;
void APIENTRY bluegl_glUniform3i64NV (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
    typedef void (APIENTRYP PFN_glUniform3i64NV) (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
    return ((PFN_glUniform3i64NV)__blue_glCore_glUniform3i64NV)(location, x, y, z);
}

extern void* __blue_glCore_glUniform4i64NV;
void APIENTRY bluegl_glUniform4i64NV (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
    typedef void (APIENTRYP PFN_glUniform4i64NV) (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
    return ((PFN_glUniform4i64NV)__blue_glCore_glUniform4i64NV)(location, x, y, z, w);
}

extern void* __blue_glCore_glUniform1i64vNV;
void APIENTRY bluegl_glUniform1i64vNV (GLint location, GLsizei count, const GLint64EXT *value) {
    typedef void (APIENTRYP PFN_glUniform1i64vNV) (GLint location, GLsizei count, const GLint64EXT *value);
    return ((PFN_glUniform1i64vNV)__blue_glCore_glUniform1i64vNV)(location, count, value);
}

extern void* __blue_glCore_glUniform2i64vNV;
void APIENTRY bluegl_glUniform2i64vNV (GLint location, GLsizei count, const GLint64EXT *value) {
    typedef void (APIENTRYP PFN_glUniform2i64vNV) (GLint location, GLsizei count, const GLint64EXT *value);
    return ((PFN_glUniform2i64vNV)__blue_glCore_glUniform2i64vNV)(location, count, value);
}

extern void* __blue_glCore_glUniform3i64vNV;
void APIENTRY bluegl_glUniform3i64vNV (GLint location, GLsizei count, const GLint64EXT *value) {
    typedef void (APIENTRYP PFN_glUniform3i64vNV) (GLint location, GLsizei count, const GLint64EXT *value);
    return ((PFN_glUniform3i64vNV)__blue_glCore_glUniform3i64vNV)(location, count, value);
}

extern void* __blue_glCore_glUniform4i64vNV;
void APIENTRY bluegl_glUniform4i64vNV (GLint location, GLsizei count, const GLint64EXT *value) {
    typedef void (APIENTRYP PFN_glUniform4i64vNV) (GLint location, GLsizei count, const GLint64EXT *value);
    return ((PFN_glUniform4i64vNV)__blue_glCore_glUniform4i64vNV)(location, count, value);
}

extern void* __blue_glCore_glUniform1ui64NV;
void APIENTRY bluegl_glUniform1ui64NV (GLint location, GLuint64EXT x) {
    typedef void (APIENTRYP PFN_glUniform1ui64NV) (GLint location, GLuint64EXT x);
    return ((PFN_glUniform1ui64NV)__blue_glCore_glUniform1ui64NV)(location, x);
}

extern void* __blue_glCore_glUniform2ui64NV;
void APIENTRY bluegl_glUniform2ui64NV (GLint location, GLuint64EXT x, GLuint64EXT y) {
    typedef void (APIENTRYP PFN_glUniform2ui64NV) (GLint location, GLuint64EXT x, GLuint64EXT y);
    return ((PFN_glUniform2ui64NV)__blue_glCore_glUniform2ui64NV)(location, x, y);
}

extern void* __blue_glCore_glUniform3ui64NV;
void APIENTRY bluegl_glUniform3ui64NV (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
    typedef void (APIENTRYP PFN_glUniform3ui64NV) (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
    return ((PFN_glUniform3ui64NV)__blue_glCore_glUniform3ui64NV)(location, x, y, z);
}

extern void* __blue_glCore_glUniform4ui64NV;
void APIENTRY bluegl_glUniform4ui64NV (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
    typedef void (APIENTRYP PFN_glUniform4ui64NV) (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
    return ((PFN_glUniform4ui64NV)__blue_glCore_glUniform4ui64NV)(location, x, y, z, w);
}

extern void* __blue_glCore_glUniform1ui64vNV;
void APIENTRY bluegl_glUniform1ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glUniform1ui64vNV) (GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glUniform1ui64vNV)__blue_glCore_glUniform1ui64vNV)(location, count, value);
}

extern void* __blue_glCore_glUniform2ui64vNV;
void APIENTRY bluegl_glUniform2ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glUniform2ui64vNV) (GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glUniform2ui64vNV)__blue_glCore_glUniform2ui64vNV)(location, count, value);
}

extern void* __blue_glCore_glUniform3ui64vNV;
void APIENTRY bluegl_glUniform3ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glUniform3ui64vNV) (GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glUniform3ui64vNV)__blue_glCore_glUniform3ui64vNV)(location, count, value);
}

extern void* __blue_glCore_glUniform4ui64vNV;
void APIENTRY bluegl_glUniform4ui64vNV (GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glUniform4ui64vNV) (GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glUniform4ui64vNV)__blue_glCore_glUniform4ui64vNV)(location, count, value);
}

extern void* __blue_glCore_glGetUniformi64vNV;
void APIENTRY bluegl_glGetUniformi64vNV (GLuint program, GLint location, GLint64EXT *params) {
    typedef void (APIENTRYP PFN_glGetUniformi64vNV) (GLuint program, GLint location, GLint64EXT *params);
    return ((PFN_glGetUniformi64vNV)__blue_glCore_glGetUniformi64vNV)(program, location, params);
}

extern void* __blue_glCore_glGetUniformui64vNV;
void APIENTRY bluegl_glGetUniformui64vNV (GLuint program, GLint location, GLuint64EXT *params) {
    typedef void (APIENTRYP PFN_glGetUniformui64vNV) (GLuint program, GLint location, GLuint64EXT *params);
    return ((PFN_glGetUniformui64vNV)__blue_glCore_glGetUniformui64vNV)(program, location, params);
}

extern void* __blue_glCore_glProgramUniform1i64NV;
void APIENTRY bluegl_glProgramUniform1i64NV (GLuint program, GLint location, GLint64EXT x) {
    typedef void (APIENTRYP PFN_glProgramUniform1i64NV) (GLuint program, GLint location, GLint64EXT x);
    return ((PFN_glProgramUniform1i64NV)__blue_glCore_glProgramUniform1i64NV)(program, location, x);
}

extern void* __blue_glCore_glProgramUniform2i64NV;
void APIENTRY bluegl_glProgramUniform2i64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y) {
    typedef void (APIENTRYP PFN_glProgramUniform2i64NV) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
    return ((PFN_glProgramUniform2i64NV)__blue_glCore_glProgramUniform2i64NV)(program, location, x, y);
}

extern void* __blue_glCore_glProgramUniform3i64NV;
void APIENTRY bluegl_glProgramUniform3i64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
    typedef void (APIENTRYP PFN_glProgramUniform3i64NV) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
    return ((PFN_glProgramUniform3i64NV)__blue_glCore_glProgramUniform3i64NV)(program, location, x, y, z);
}

extern void* __blue_glCore_glProgramUniform4i64NV;
void APIENTRY bluegl_glProgramUniform4i64NV (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
    typedef void (APIENTRYP PFN_glProgramUniform4i64NV) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
    return ((PFN_glProgramUniform4i64NV)__blue_glCore_glProgramUniform4i64NV)(program, location, x, y, z, w);
}

extern void* __blue_glCore_glProgramUniform1i64vNV;
void APIENTRY bluegl_glProgramUniform1i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1i64vNV) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    return ((PFN_glProgramUniform1i64vNV)__blue_glCore_glProgramUniform1i64vNV)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2i64vNV;
void APIENTRY bluegl_glProgramUniform2i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2i64vNV) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    return ((PFN_glProgramUniform2i64vNV)__blue_glCore_glProgramUniform2i64vNV)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3i64vNV;
void APIENTRY bluegl_glProgramUniform3i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3i64vNV) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    return ((PFN_glProgramUniform3i64vNV)__blue_glCore_glProgramUniform3i64vNV)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4i64vNV;
void APIENTRY bluegl_glProgramUniform4i64vNV (GLuint program, GLint location, GLsizei count, const GLint64EXT *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4i64vNV) (GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
    return ((PFN_glProgramUniform4i64vNV)__blue_glCore_glProgramUniform4i64vNV)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform1ui64NV;
void APIENTRY bluegl_glProgramUniform1ui64NV (GLuint program, GLint location, GLuint64EXT x) {
    typedef void (APIENTRYP PFN_glProgramUniform1ui64NV) (GLuint program, GLint location, GLuint64EXT x);
    return ((PFN_glProgramUniform1ui64NV)__blue_glCore_glProgramUniform1ui64NV)(program, location, x);
}

extern void* __blue_glCore_glProgramUniform2ui64NV;
void APIENTRY bluegl_glProgramUniform2ui64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y) {
    typedef void (APIENTRYP PFN_glProgramUniform2ui64NV) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
    return ((PFN_glProgramUniform2ui64NV)__blue_glCore_glProgramUniform2ui64NV)(program, location, x, y);
}

extern void* __blue_glCore_glProgramUniform3ui64NV;
void APIENTRY bluegl_glProgramUniform3ui64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
    typedef void (APIENTRYP PFN_glProgramUniform3ui64NV) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
    return ((PFN_glProgramUniform3ui64NV)__blue_glCore_glProgramUniform3ui64NV)(program, location, x, y, z);
}

extern void* __blue_glCore_glProgramUniform4ui64NV;
void APIENTRY bluegl_glProgramUniform4ui64NV (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
    typedef void (APIENTRYP PFN_glProgramUniform4ui64NV) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
    return ((PFN_glProgramUniform4ui64NV)__blue_glCore_glProgramUniform4ui64NV)(program, location, x, y, z, w);
}

extern void* __blue_glCore_glProgramUniform1ui64vNV;
void APIENTRY bluegl_glProgramUniform1ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1ui64vNV) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glProgramUniform1ui64vNV)__blue_glCore_glProgramUniform1ui64vNV)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2ui64vNV;
void APIENTRY bluegl_glProgramUniform2ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2ui64vNV) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glProgramUniform2ui64vNV)__blue_glCore_glProgramUniform2ui64vNV)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3ui64vNV;
void APIENTRY bluegl_glProgramUniform3ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3ui64vNV) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glProgramUniform3ui64vNV)__blue_glCore_glProgramUniform3ui64vNV)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4ui64vNV;
void APIENTRY bluegl_glProgramUniform4ui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4ui64vNV) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glProgramUniform4ui64vNV)__blue_glCore_glProgramUniform4ui64vNV)(program, location, count, value);
}

extern void* __blue_glCore_glVertexAttribParameteriAMD;
void APIENTRY bluegl_glVertexAttribParameteriAMD (GLuint index, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glVertexAttribParameteriAMD) (GLuint index, GLenum pname, GLint param);
    return ((PFN_glVertexAttribParameteriAMD)__blue_glCore_glVertexAttribParameteriAMD)(index, pname, param);
}

extern void* __blue_glCore_glMultiDrawArraysIndirectAMD;
void APIENTRY bluegl_glMultiDrawArraysIndirectAMD (GLenum mode, const void *indirect, GLsizei primcount, GLsizei stride) {
    typedef void (APIENTRYP PFN_glMultiDrawArraysIndirectAMD) (GLenum mode, const void *indirect, GLsizei primcount, GLsizei stride);
    return ((PFN_glMultiDrawArraysIndirectAMD)__blue_glCore_glMultiDrawArraysIndirectAMD)(mode, indirect, primcount, stride);
}

extern void* __blue_glCore_glMultiDrawElementsIndirectAMD;
void APIENTRY bluegl_glMultiDrawElementsIndirectAMD (GLenum mode, GLenum type, const void *indirect, GLsizei primcount, GLsizei stride) {
    typedef void (APIENTRYP PFN_glMultiDrawElementsIndirectAMD) (GLenum mode, GLenum type, const void *indirect, GLsizei primcount, GLsizei stride);
    return ((PFN_glMultiDrawElementsIndirectAMD)__blue_glCore_glMultiDrawElementsIndirectAMD)(mode, type, indirect, primcount, stride);
}

extern void* __blue_glCore_glGenNamesAMD;
void APIENTRY bluegl_glGenNamesAMD (GLenum identifier, GLuint num, GLuint *names) {
    typedef void (APIENTRYP PFN_glGenNamesAMD) (GLenum identifier, GLuint num, GLuint *names);
    return ((PFN_glGenNamesAMD)__blue_glCore_glGenNamesAMD)(identifier, num, names);
}

extern void* __blue_glCore_glDeleteNamesAMD;
void APIENTRY bluegl_glDeleteNamesAMD (GLenum identifier, GLuint num, const GLuint *names) {
    typedef void (APIENTRYP PFN_glDeleteNamesAMD) (GLenum identifier, GLuint num, const GLuint *names);
    return ((PFN_glDeleteNamesAMD)__blue_glCore_glDeleteNamesAMD)(identifier, num, names);
}

extern void* __blue_glCore_glIsNameAMD;
GLboolean APIENTRY bluegl_glIsNameAMD (GLenum identifier, GLuint name) {
    typedef GLboolean (APIENTRYP PFN_glIsNameAMD) (GLenum identifier, GLuint name);
    return ((PFN_glIsNameAMD)__blue_glCore_glIsNameAMD)(identifier, name);
}

extern void* __blue_glCore_glQueryObjectParameteruiAMD;
void APIENTRY bluegl_glQueryObjectParameteruiAMD (GLenum target, GLuint id, GLenum pname, GLuint param) {
    typedef void (APIENTRYP PFN_glQueryObjectParameteruiAMD) (GLenum target, GLuint id, GLenum pname, GLuint param);
    return ((PFN_glQueryObjectParameteruiAMD)__blue_glCore_glQueryObjectParameteruiAMD)(target, id, pname, param);
}

extern void* __blue_glCore_glGetPerfMonitorGroupsAMD;
void APIENTRY bluegl_glGetPerfMonitorGroupsAMD (GLint *numGroups, GLsizei groupsSize, GLuint *groups) {
    typedef void (APIENTRYP PFN_glGetPerfMonitorGroupsAMD) (GLint *numGroups, GLsizei groupsSize, GLuint *groups);
    return ((PFN_glGetPerfMonitorGroupsAMD)__blue_glCore_glGetPerfMonitorGroupsAMD)(numGroups, groupsSize, groups);
}

extern void* __blue_glCore_glGetPerfMonitorCountersAMD;
void APIENTRY bluegl_glGetPerfMonitorCountersAMD (GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters) {
    typedef void (APIENTRYP PFN_glGetPerfMonitorCountersAMD) (GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
    return ((PFN_glGetPerfMonitorCountersAMD)__blue_glCore_glGetPerfMonitorCountersAMD)(group, numCounters, maxActiveCounters, counterSize, counters);
}

extern void* __blue_glCore_glGetPerfMonitorGroupStringAMD;
void APIENTRY bluegl_glGetPerfMonitorGroupStringAMD (GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString) {
    typedef void (APIENTRYP PFN_glGetPerfMonitorGroupStringAMD) (GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
    return ((PFN_glGetPerfMonitorGroupStringAMD)__blue_glCore_glGetPerfMonitorGroupStringAMD)(group, bufSize, length, groupString);
}

extern void* __blue_glCore_glGetPerfMonitorCounterStringAMD;
void APIENTRY bluegl_glGetPerfMonitorCounterStringAMD (GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString) {
    typedef void (APIENTRYP PFN_glGetPerfMonitorCounterStringAMD) (GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
    return ((PFN_glGetPerfMonitorCounterStringAMD)__blue_glCore_glGetPerfMonitorCounterStringAMD)(group, counter, bufSize, length, counterString);
}

extern void* __blue_glCore_glGetPerfMonitorCounterInfoAMD;
void APIENTRY bluegl_glGetPerfMonitorCounterInfoAMD (GLuint group, GLuint counter, GLenum pname, void *data) {
    typedef void (APIENTRYP PFN_glGetPerfMonitorCounterInfoAMD) (GLuint group, GLuint counter, GLenum pname, void *data);
    return ((PFN_glGetPerfMonitorCounterInfoAMD)__blue_glCore_glGetPerfMonitorCounterInfoAMD)(group, counter, pname, data);
}

extern void* __blue_glCore_glGenPerfMonitorsAMD;
void APIENTRY bluegl_glGenPerfMonitorsAMD (GLsizei n, GLuint *monitors) {
    typedef void (APIENTRYP PFN_glGenPerfMonitorsAMD) (GLsizei n, GLuint *monitors);
    return ((PFN_glGenPerfMonitorsAMD)__blue_glCore_glGenPerfMonitorsAMD)(n, monitors);
}

extern void* __blue_glCore_glDeletePerfMonitorsAMD;
void APIENTRY bluegl_glDeletePerfMonitorsAMD (GLsizei n, GLuint *monitors) {
    typedef void (APIENTRYP PFN_glDeletePerfMonitorsAMD) (GLsizei n, GLuint *monitors);
    return ((PFN_glDeletePerfMonitorsAMD)__blue_glCore_glDeletePerfMonitorsAMD)(n, monitors);
}

extern void* __blue_glCore_glSelectPerfMonitorCountersAMD;
void APIENTRY bluegl_glSelectPerfMonitorCountersAMD (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList) {
    typedef void (APIENTRYP PFN_glSelectPerfMonitorCountersAMD) (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
    return ((PFN_glSelectPerfMonitorCountersAMD)__blue_glCore_glSelectPerfMonitorCountersAMD)(monitor, enable, group, numCounters, counterList);
}

extern void* __blue_glCore_glBeginPerfMonitorAMD;
void APIENTRY bluegl_glBeginPerfMonitorAMD (GLuint monitor) {
    typedef void (APIENTRYP PFN_glBeginPerfMonitorAMD) (GLuint monitor);
    return ((PFN_glBeginPerfMonitorAMD)__blue_glCore_glBeginPerfMonitorAMD)(monitor);
}

extern void* __blue_glCore_glEndPerfMonitorAMD;
void APIENTRY bluegl_glEndPerfMonitorAMD (GLuint monitor) {
    typedef void (APIENTRYP PFN_glEndPerfMonitorAMD) (GLuint monitor);
    return ((PFN_glEndPerfMonitorAMD)__blue_glCore_glEndPerfMonitorAMD)(monitor);
}

extern void* __blue_glCore_glGetPerfMonitorCounterDataAMD;
void APIENTRY bluegl_glGetPerfMonitorCounterDataAMD (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten) {
    typedef void (APIENTRYP PFN_glGetPerfMonitorCounterDataAMD) (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
    return ((PFN_glGetPerfMonitorCounterDataAMD)__blue_glCore_glGetPerfMonitorCounterDataAMD)(monitor, pname, dataSize, data, bytesWritten);
}

extern void* __blue_glCore_glSetMultisamplefvAMD;
void APIENTRY bluegl_glSetMultisamplefvAMD (GLenum pname, GLuint index, const GLfloat *val) {
    typedef void (APIENTRYP PFN_glSetMultisamplefvAMD) (GLenum pname, GLuint index, const GLfloat *val);
    return ((PFN_glSetMultisamplefvAMD)__blue_glCore_glSetMultisamplefvAMD)(pname, index, val);
}

extern void* __blue_glCore_glTexStorageSparseAMD;
void APIENTRY bluegl_glTexStorageSparseAMD (GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) {
    typedef void (APIENTRYP PFN_glTexStorageSparseAMD) (GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
    return ((PFN_glTexStorageSparseAMD)__blue_glCore_glTexStorageSparseAMD)(target, internalFormat, width, height, depth, layers, flags);
}

extern void* __blue_glCore_glTextureStorageSparseAMD;
void APIENTRY bluegl_glTextureStorageSparseAMD (GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) {
    typedef void (APIENTRYP PFN_glTextureStorageSparseAMD) (GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
    return ((PFN_glTextureStorageSparseAMD)__blue_glCore_glTextureStorageSparseAMD)(texture, target, internalFormat, width, height, depth, layers, flags);
}

extern void* __blue_glCore_glStencilOpValueAMD;
void APIENTRY bluegl_glStencilOpValueAMD (GLenum face, GLuint value) {
    typedef void (APIENTRYP PFN_glStencilOpValueAMD) (GLenum face, GLuint value);
    return ((PFN_glStencilOpValueAMD)__blue_glCore_glStencilOpValueAMD)(face, value);
}

extern void* __blue_glCore_glTessellationFactorAMD;
void APIENTRY bluegl_glTessellationFactorAMD (GLfloat factor) {
    typedef void (APIENTRYP PFN_glTessellationFactorAMD) (GLfloat factor);
    return ((PFN_glTessellationFactorAMD)__blue_glCore_glTessellationFactorAMD)(factor);
}

extern void* __blue_glCore_glTessellationModeAMD;
void APIENTRY bluegl_glTessellationModeAMD (GLenum mode) {
    typedef void (APIENTRYP PFN_glTessellationModeAMD) (GLenum mode);
    return ((PFN_glTessellationModeAMD)__blue_glCore_glTessellationModeAMD)(mode);
}

extern void* __blue_glCore_glElementPointerAPPLE;
void APIENTRY bluegl_glElementPointerAPPLE (GLenum type, const void *pointer) {
    typedef void (APIENTRYP PFN_glElementPointerAPPLE) (GLenum type, const void *pointer);
    return ((PFN_glElementPointerAPPLE)__blue_glCore_glElementPointerAPPLE)(type, pointer);
}

extern void* __blue_glCore_glDrawElementArrayAPPLE;
void APIENTRY bluegl_glDrawElementArrayAPPLE (GLenum mode, GLint first, GLsizei count) {
    typedef void (APIENTRYP PFN_glDrawElementArrayAPPLE) (GLenum mode, GLint first, GLsizei count);
    return ((PFN_glDrawElementArrayAPPLE)__blue_glCore_glDrawElementArrayAPPLE)(mode, first, count);
}

extern void* __blue_glCore_glDrawRangeElementArrayAPPLE;
void APIENTRY bluegl_glDrawRangeElementArrayAPPLE (GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count) {
    typedef void (APIENTRYP PFN_glDrawRangeElementArrayAPPLE) (GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
    return ((PFN_glDrawRangeElementArrayAPPLE)__blue_glCore_glDrawRangeElementArrayAPPLE)(mode, start, end, first, count);
}

extern void* __blue_glCore_glMultiDrawElementArrayAPPLE;
void APIENTRY bluegl_glMultiDrawElementArrayAPPLE (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount) {
    typedef void (APIENTRYP PFN_glMultiDrawElementArrayAPPLE) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
    return ((PFN_glMultiDrawElementArrayAPPLE)__blue_glCore_glMultiDrawElementArrayAPPLE)(mode, first, count, primcount);
}

extern void* __blue_glCore_glMultiDrawRangeElementArrayAPPLE;
void APIENTRY bluegl_glMultiDrawRangeElementArrayAPPLE (GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount) {
    typedef void (APIENTRYP PFN_glMultiDrawRangeElementArrayAPPLE) (GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount);
    return ((PFN_glMultiDrawRangeElementArrayAPPLE)__blue_glCore_glMultiDrawRangeElementArrayAPPLE)(mode, start, end, first, count, primcount);
}

extern void* __blue_glCore_glGenFencesAPPLE;
void APIENTRY bluegl_glGenFencesAPPLE (GLsizei n, GLuint *fences) {
    typedef void (APIENTRYP PFN_glGenFencesAPPLE) (GLsizei n, GLuint *fences);
    return ((PFN_glGenFencesAPPLE)__blue_glCore_glGenFencesAPPLE)(n, fences);
}

extern void* __blue_glCore_glDeleteFencesAPPLE;
void APIENTRY bluegl_glDeleteFencesAPPLE (GLsizei n, const GLuint *fences) {
    typedef void (APIENTRYP PFN_glDeleteFencesAPPLE) (GLsizei n, const GLuint *fences);
    return ((PFN_glDeleteFencesAPPLE)__blue_glCore_glDeleteFencesAPPLE)(n, fences);
}

extern void* __blue_glCore_glSetFenceAPPLE;
void APIENTRY bluegl_glSetFenceAPPLE (GLuint fence) {
    typedef void (APIENTRYP PFN_glSetFenceAPPLE) (GLuint fence);
    return ((PFN_glSetFenceAPPLE)__blue_glCore_glSetFenceAPPLE)(fence);
}

extern void* __blue_glCore_glIsFenceAPPLE;
GLboolean APIENTRY bluegl_glIsFenceAPPLE (GLuint fence) {
    typedef GLboolean (APIENTRYP PFN_glIsFenceAPPLE) (GLuint fence);
    return ((PFN_glIsFenceAPPLE)__blue_glCore_glIsFenceAPPLE)(fence);
}

extern void* __blue_glCore_glTestFenceAPPLE;
GLboolean APIENTRY bluegl_glTestFenceAPPLE (GLuint fence) {
    typedef GLboolean (APIENTRYP PFN_glTestFenceAPPLE) (GLuint fence);
    return ((PFN_glTestFenceAPPLE)__blue_glCore_glTestFenceAPPLE)(fence);
}

extern void* __blue_glCore_glFinishFenceAPPLE;
void APIENTRY bluegl_glFinishFenceAPPLE (GLuint fence) {
    typedef void (APIENTRYP PFN_glFinishFenceAPPLE) (GLuint fence);
    return ((PFN_glFinishFenceAPPLE)__blue_glCore_glFinishFenceAPPLE)(fence);
}

extern void* __blue_glCore_glTestObjectAPPLE;
GLboolean APIENTRY bluegl_glTestObjectAPPLE (GLenum object, GLuint name) {
    typedef GLboolean (APIENTRYP PFN_glTestObjectAPPLE) (GLenum object, GLuint name);
    return ((PFN_glTestObjectAPPLE)__blue_glCore_glTestObjectAPPLE)(object, name);
}

extern void* __blue_glCore_glFinishObjectAPPLE;
void APIENTRY bluegl_glFinishObjectAPPLE (GLenum object, GLint name) {
    typedef void (APIENTRYP PFN_glFinishObjectAPPLE) (GLenum object, GLint name);
    return ((PFN_glFinishObjectAPPLE)__blue_glCore_glFinishObjectAPPLE)(object, name);
}

extern void* __blue_glCore_glBufferParameteriAPPLE;
void APIENTRY bluegl_glBufferParameteriAPPLE (GLenum target, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glBufferParameteriAPPLE) (GLenum target, GLenum pname, GLint param);
    return ((PFN_glBufferParameteriAPPLE)__blue_glCore_glBufferParameteriAPPLE)(target, pname, param);
}

extern void* __blue_glCore_glFlushMappedBufferRangeAPPLE;
void APIENTRY bluegl_glFlushMappedBufferRangeAPPLE (GLenum target, GLintptr offset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glFlushMappedBufferRangeAPPLE) (GLenum target, GLintptr offset, GLsizeiptr size);
    return ((PFN_glFlushMappedBufferRangeAPPLE)__blue_glCore_glFlushMappedBufferRangeAPPLE)(target, offset, size);
}

extern void* __blue_glCore_glObjectPurgeableAPPLE;
GLenum APIENTRY bluegl_glObjectPurgeableAPPLE (GLenum objectType, GLuint name, GLenum option) {
    typedef GLenum (APIENTRYP PFN_glObjectPurgeableAPPLE) (GLenum objectType, GLuint name, GLenum option);
    return ((PFN_glObjectPurgeableAPPLE)__blue_glCore_glObjectPurgeableAPPLE)(objectType, name, option);
}

extern void* __blue_glCore_glObjectUnpurgeableAPPLE;
GLenum APIENTRY bluegl_glObjectUnpurgeableAPPLE (GLenum objectType, GLuint name, GLenum option) {
    typedef GLenum (APIENTRYP PFN_glObjectUnpurgeableAPPLE) (GLenum objectType, GLuint name, GLenum option);
    return ((PFN_glObjectUnpurgeableAPPLE)__blue_glCore_glObjectUnpurgeableAPPLE)(objectType, name, option);
}

extern void* __blue_glCore_glGetObjectParameterivAPPLE;
void APIENTRY bluegl_glGetObjectParameterivAPPLE (GLenum objectType, GLuint name, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetObjectParameterivAPPLE) (GLenum objectType, GLuint name, GLenum pname, GLint *params);
    return ((PFN_glGetObjectParameterivAPPLE)__blue_glCore_glGetObjectParameterivAPPLE)(objectType, name, pname, params);
}

extern void* __blue_glCore_glTextureRangeAPPLE;
void APIENTRY bluegl_glTextureRangeAPPLE (GLenum target, GLsizei length, const void *pointer) {
    typedef void (APIENTRYP PFN_glTextureRangeAPPLE) (GLenum target, GLsizei length, const void *pointer);
    return ((PFN_glTextureRangeAPPLE)__blue_glCore_glTextureRangeAPPLE)(target, length, pointer);
}

extern void* __blue_glCore_glGetTexParameterPointervAPPLE;
void APIENTRY bluegl_glGetTexParameterPointervAPPLE (GLenum target, GLenum pname, void **params) {
    typedef void (APIENTRYP PFN_glGetTexParameterPointervAPPLE) (GLenum target, GLenum pname, void **params);
    return ((PFN_glGetTexParameterPointervAPPLE)__blue_glCore_glGetTexParameterPointervAPPLE)(target, pname, params);
}

extern void* __blue_glCore_glBindVertexArrayAPPLE;
void APIENTRY bluegl_glBindVertexArrayAPPLE (GLuint array) {
    typedef void (APIENTRYP PFN_glBindVertexArrayAPPLE) (GLuint array);
    return ((PFN_glBindVertexArrayAPPLE)__blue_glCore_glBindVertexArrayAPPLE)(array);
}

extern void* __blue_glCore_glDeleteVertexArraysAPPLE;
void APIENTRY bluegl_glDeleteVertexArraysAPPLE (GLsizei n, const GLuint *arrays) {
    typedef void (APIENTRYP PFN_glDeleteVertexArraysAPPLE) (GLsizei n, const GLuint *arrays);
    return ((PFN_glDeleteVertexArraysAPPLE)__blue_glCore_glDeleteVertexArraysAPPLE)(n, arrays);
}

extern void* __blue_glCore_glGenVertexArraysAPPLE;
void APIENTRY bluegl_glGenVertexArraysAPPLE (GLsizei n, GLuint *arrays) {
    typedef void (APIENTRYP PFN_glGenVertexArraysAPPLE) (GLsizei n, GLuint *arrays);
    return ((PFN_glGenVertexArraysAPPLE)__blue_glCore_glGenVertexArraysAPPLE)(n, arrays);
}

extern void* __blue_glCore_glIsVertexArrayAPPLE;
GLboolean APIENTRY bluegl_glIsVertexArrayAPPLE (GLuint array) {
    typedef GLboolean (APIENTRYP PFN_glIsVertexArrayAPPLE) (GLuint array);
    return ((PFN_glIsVertexArrayAPPLE)__blue_glCore_glIsVertexArrayAPPLE)(array);
}

extern void* __blue_glCore_glVertexArrayRangeAPPLE;
void APIENTRY bluegl_glVertexArrayRangeAPPLE (GLsizei length, void *pointer) {
    typedef void (APIENTRYP PFN_glVertexArrayRangeAPPLE) (GLsizei length, void *pointer);
    return ((PFN_glVertexArrayRangeAPPLE)__blue_glCore_glVertexArrayRangeAPPLE)(length, pointer);
}

extern void* __blue_glCore_glFlushVertexArrayRangeAPPLE;
void APIENTRY bluegl_glFlushVertexArrayRangeAPPLE (GLsizei length, void *pointer) {
    typedef void (APIENTRYP PFN_glFlushVertexArrayRangeAPPLE) (GLsizei length, void *pointer);
    return ((PFN_glFlushVertexArrayRangeAPPLE)__blue_glCore_glFlushVertexArrayRangeAPPLE)(length, pointer);
}

extern void* __blue_glCore_glVertexArrayParameteriAPPLE;
void APIENTRY bluegl_glVertexArrayParameteriAPPLE (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glVertexArrayParameteriAPPLE) (GLenum pname, GLint param);
    return ((PFN_glVertexArrayParameteriAPPLE)__blue_glCore_glVertexArrayParameteriAPPLE)(pname, param);
}

extern void* __blue_glCore_glEnableVertexAttribAPPLE;
void APIENTRY bluegl_glEnableVertexAttribAPPLE (GLuint index, GLenum pname) {
    typedef void (APIENTRYP PFN_glEnableVertexAttribAPPLE) (GLuint index, GLenum pname);
    return ((PFN_glEnableVertexAttribAPPLE)__blue_glCore_glEnableVertexAttribAPPLE)(index, pname);
}

extern void* __blue_glCore_glDisableVertexAttribAPPLE;
void APIENTRY bluegl_glDisableVertexAttribAPPLE (GLuint index, GLenum pname) {
    typedef void (APIENTRYP PFN_glDisableVertexAttribAPPLE) (GLuint index, GLenum pname);
    return ((PFN_glDisableVertexAttribAPPLE)__blue_glCore_glDisableVertexAttribAPPLE)(index, pname);
}

extern void* __blue_glCore_glIsVertexAttribEnabledAPPLE;
GLboolean APIENTRY bluegl_glIsVertexAttribEnabledAPPLE (GLuint index, GLenum pname) {
    typedef GLboolean (APIENTRYP PFN_glIsVertexAttribEnabledAPPLE) (GLuint index, GLenum pname);
    return ((PFN_glIsVertexAttribEnabledAPPLE)__blue_glCore_glIsVertexAttribEnabledAPPLE)(index, pname);
}

extern void* __blue_glCore_glMapVertexAttrib1dAPPLE;
void APIENTRY bluegl_glMapVertexAttrib1dAPPLE (GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) {
    typedef void (APIENTRYP PFN_glMapVertexAttrib1dAPPLE) (GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
    return ((PFN_glMapVertexAttrib1dAPPLE)__blue_glCore_glMapVertexAttrib1dAPPLE)(index, size, u1, u2, stride, order, points);
}

extern void* __blue_glCore_glMapVertexAttrib1fAPPLE;
void APIENTRY bluegl_glMapVertexAttrib1fAPPLE (GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) {
    typedef void (APIENTRYP PFN_glMapVertexAttrib1fAPPLE) (GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
    return ((PFN_glMapVertexAttrib1fAPPLE)__blue_glCore_glMapVertexAttrib1fAPPLE)(index, size, u1, u2, stride, order, points);
}

extern void* __blue_glCore_glMapVertexAttrib2dAPPLE;
void APIENTRY bluegl_glMapVertexAttrib2dAPPLE (GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) {
    typedef void (APIENTRYP PFN_glMapVertexAttrib2dAPPLE) (GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
    return ((PFN_glMapVertexAttrib2dAPPLE)__blue_glCore_glMapVertexAttrib2dAPPLE)(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

extern void* __blue_glCore_glMapVertexAttrib2fAPPLE;
void APIENTRY bluegl_glMapVertexAttrib2fAPPLE (GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) {
    typedef void (APIENTRYP PFN_glMapVertexAttrib2fAPPLE) (GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
    return ((PFN_glMapVertexAttrib2fAPPLE)__blue_glCore_glMapVertexAttrib2fAPPLE)(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

extern void* __blue_glCore_glDrawBuffersATI;
void APIENTRY bluegl_glDrawBuffersATI (GLsizei n, const GLenum *bufs) {
    typedef void (APIENTRYP PFN_glDrawBuffersATI) (GLsizei n, const GLenum *bufs);
    return ((PFN_glDrawBuffersATI)__blue_glCore_glDrawBuffersATI)(n, bufs);
}

extern void* __blue_glCore_glElementPointerATI;
void APIENTRY bluegl_glElementPointerATI (GLenum type, const void *pointer) {
    typedef void (APIENTRYP PFN_glElementPointerATI) (GLenum type, const void *pointer);
    return ((PFN_glElementPointerATI)__blue_glCore_glElementPointerATI)(type, pointer);
}

extern void* __blue_glCore_glDrawElementArrayATI;
void APIENTRY bluegl_glDrawElementArrayATI (GLenum mode, GLsizei count) {
    typedef void (APIENTRYP PFN_glDrawElementArrayATI) (GLenum mode, GLsizei count);
    return ((PFN_glDrawElementArrayATI)__blue_glCore_glDrawElementArrayATI)(mode, count);
}

extern void* __blue_glCore_glDrawRangeElementArrayATI;
void APIENTRY bluegl_glDrawRangeElementArrayATI (GLenum mode, GLuint start, GLuint end, GLsizei count) {
    typedef void (APIENTRYP PFN_glDrawRangeElementArrayATI) (GLenum mode, GLuint start, GLuint end, GLsizei count);
    return ((PFN_glDrawRangeElementArrayATI)__blue_glCore_glDrawRangeElementArrayATI)(mode, start, end, count);
}

extern void* __blue_glCore_glTexBumpParameterivATI;
void APIENTRY bluegl_glTexBumpParameterivATI (GLenum pname, const GLint *param) {
    typedef void (APIENTRYP PFN_glTexBumpParameterivATI) (GLenum pname, const GLint *param);
    return ((PFN_glTexBumpParameterivATI)__blue_glCore_glTexBumpParameterivATI)(pname, param);
}

extern void* __blue_glCore_glTexBumpParameterfvATI;
void APIENTRY bluegl_glTexBumpParameterfvATI (GLenum pname, const GLfloat *param) {
    typedef void (APIENTRYP PFN_glTexBumpParameterfvATI) (GLenum pname, const GLfloat *param);
    return ((PFN_glTexBumpParameterfvATI)__blue_glCore_glTexBumpParameterfvATI)(pname, param);
}

extern void* __blue_glCore_glGetTexBumpParameterivATI;
void APIENTRY bluegl_glGetTexBumpParameterivATI (GLenum pname, GLint *param) {
    typedef void (APIENTRYP PFN_glGetTexBumpParameterivATI) (GLenum pname, GLint *param);
    return ((PFN_glGetTexBumpParameterivATI)__blue_glCore_glGetTexBumpParameterivATI)(pname, param);
}

extern void* __blue_glCore_glGetTexBumpParameterfvATI;
void APIENTRY bluegl_glGetTexBumpParameterfvATI (GLenum pname, GLfloat *param) {
    typedef void (APIENTRYP PFN_glGetTexBumpParameterfvATI) (GLenum pname, GLfloat *param);
    return ((PFN_glGetTexBumpParameterfvATI)__blue_glCore_glGetTexBumpParameterfvATI)(pname, param);
}

extern void* __blue_glCore_glGenFragmentShadersATI;
GLuint APIENTRY bluegl_glGenFragmentShadersATI (GLuint range) {
    typedef GLuint (APIENTRYP PFN_glGenFragmentShadersATI) (GLuint range);
    return ((PFN_glGenFragmentShadersATI)__blue_glCore_glGenFragmentShadersATI)(range);
}

extern void* __blue_glCore_glBindFragmentShaderATI;
void APIENTRY bluegl_glBindFragmentShaderATI (GLuint id) {
    typedef void (APIENTRYP PFN_glBindFragmentShaderATI) (GLuint id);
    return ((PFN_glBindFragmentShaderATI)__blue_glCore_glBindFragmentShaderATI)(id);
}

extern void* __blue_glCore_glDeleteFragmentShaderATI;
void APIENTRY bluegl_glDeleteFragmentShaderATI (GLuint id) {
    typedef void (APIENTRYP PFN_glDeleteFragmentShaderATI) (GLuint id);
    return ((PFN_glDeleteFragmentShaderATI)__blue_glCore_glDeleteFragmentShaderATI)(id);
}

extern void* __blue_glCore_glBeginFragmentShaderATI;
void APIENTRY bluegl_glBeginFragmentShaderATI (void) {
    typedef void (APIENTRYP PFN_glBeginFragmentShaderATI) (void);
    return ((PFN_glBeginFragmentShaderATI)__blue_glCore_glBeginFragmentShaderATI)();
}

extern void* __blue_glCore_glEndFragmentShaderATI;
void APIENTRY bluegl_glEndFragmentShaderATI (void) {
    typedef void (APIENTRYP PFN_glEndFragmentShaderATI) (void);
    return ((PFN_glEndFragmentShaderATI)__blue_glCore_glEndFragmentShaderATI)();
}

extern void* __blue_glCore_glPassTexCoordATI;
void APIENTRY bluegl_glPassTexCoordATI (GLuint dst, GLuint coord, GLenum swizzle) {
    typedef void (APIENTRYP PFN_glPassTexCoordATI) (GLuint dst, GLuint coord, GLenum swizzle);
    return ((PFN_glPassTexCoordATI)__blue_glCore_glPassTexCoordATI)(dst, coord, swizzle);
}

extern void* __blue_glCore_glSampleMapATI;
void APIENTRY bluegl_glSampleMapATI (GLuint dst, GLuint interp, GLenum swizzle) {
    typedef void (APIENTRYP PFN_glSampleMapATI) (GLuint dst, GLuint interp, GLenum swizzle);
    return ((PFN_glSampleMapATI)__blue_glCore_glSampleMapATI)(dst, interp, swizzle);
}

extern void* __blue_glCore_glColorFragmentOp1ATI;
void APIENTRY bluegl_glColorFragmentOp1ATI (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) {
    typedef void (APIENTRYP PFN_glColorFragmentOp1ATI) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
    return ((PFN_glColorFragmentOp1ATI)__blue_glCore_glColorFragmentOp1ATI)(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod);
}

extern void* __blue_glCore_glColorFragmentOp2ATI;
void APIENTRY bluegl_glColorFragmentOp2ATI (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) {
    typedef void (APIENTRYP PFN_glColorFragmentOp2ATI) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
    return ((PFN_glColorFragmentOp2ATI)__blue_glCore_glColorFragmentOp2ATI)(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod);
}

extern void* __blue_glCore_glColorFragmentOp3ATI;
void APIENTRY bluegl_glColorFragmentOp3ATI (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) {
    typedef void (APIENTRYP PFN_glColorFragmentOp3ATI) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
    return ((PFN_glColorFragmentOp3ATI)__blue_glCore_glColorFragmentOp3ATI)(op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod);
}

extern void* __blue_glCore_glAlphaFragmentOp1ATI;
void APIENTRY bluegl_glAlphaFragmentOp1ATI (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) {
    typedef void (APIENTRYP PFN_glAlphaFragmentOp1ATI) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
    return ((PFN_glAlphaFragmentOp1ATI)__blue_glCore_glAlphaFragmentOp1ATI)(op, dst, dstMod, arg1, arg1Rep, arg1Mod);
}

extern void* __blue_glCore_glAlphaFragmentOp2ATI;
void APIENTRY bluegl_glAlphaFragmentOp2ATI (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) {
    typedef void (APIENTRYP PFN_glAlphaFragmentOp2ATI) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
    return ((PFN_glAlphaFragmentOp2ATI)__blue_glCore_glAlphaFragmentOp2ATI)(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod);
}

extern void* __blue_glCore_glAlphaFragmentOp3ATI;
void APIENTRY bluegl_glAlphaFragmentOp3ATI (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) {
    typedef void (APIENTRYP PFN_glAlphaFragmentOp3ATI) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
    return ((PFN_glAlphaFragmentOp3ATI)__blue_glCore_glAlphaFragmentOp3ATI)(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod);
}

extern void* __blue_glCore_glSetFragmentShaderConstantATI;
void APIENTRY bluegl_glSetFragmentShaderConstantATI (GLuint dst, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glSetFragmentShaderConstantATI) (GLuint dst, const GLfloat *value);
    return ((PFN_glSetFragmentShaderConstantATI)__blue_glCore_glSetFragmentShaderConstantATI)(dst, value);
}

extern void* __blue_glCore_glMapObjectBufferATI;
void *APIENTRY bluegl_glMapObjectBufferATI (GLuint buffer) {
    typedef void *(APIENTRYP PFN_glMapObjectBufferATI) (GLuint buffer);
    return ((PFN_glMapObjectBufferATI)__blue_glCore_glMapObjectBufferATI)(buffer);
}

extern void* __blue_glCore_glUnmapObjectBufferATI;
void APIENTRY bluegl_glUnmapObjectBufferATI (GLuint buffer) {
    typedef void (APIENTRYP PFN_glUnmapObjectBufferATI) (GLuint buffer);
    return ((PFN_glUnmapObjectBufferATI)__blue_glCore_glUnmapObjectBufferATI)(buffer);
}

extern void* __blue_glCore_glPNTrianglesiATI;
void APIENTRY bluegl_glPNTrianglesiATI (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glPNTrianglesiATI) (GLenum pname, GLint param);
    return ((PFN_glPNTrianglesiATI)__blue_glCore_glPNTrianglesiATI)(pname, param);
}

extern void* __blue_glCore_glPNTrianglesfATI;
void APIENTRY bluegl_glPNTrianglesfATI (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glPNTrianglesfATI) (GLenum pname, GLfloat param);
    return ((PFN_glPNTrianglesfATI)__blue_glCore_glPNTrianglesfATI)(pname, param);
}

extern void* __blue_glCore_glStencilOpSeparateATI;
void APIENTRY bluegl_glStencilOpSeparateATI (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    typedef void (APIENTRYP PFN_glStencilOpSeparateATI) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
    return ((PFN_glStencilOpSeparateATI)__blue_glCore_glStencilOpSeparateATI)(face, sfail, dpfail, dppass);
}

extern void* __blue_glCore_glStencilFuncSeparateATI;
void APIENTRY bluegl_glStencilFuncSeparateATI (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask) {
    typedef void (APIENTRYP PFN_glStencilFuncSeparateATI) (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
    return ((PFN_glStencilFuncSeparateATI)__blue_glCore_glStencilFuncSeparateATI)(frontfunc, backfunc, ref, mask);
}

extern void* __blue_glCore_glNewObjectBufferATI;
GLuint APIENTRY bluegl_glNewObjectBufferATI (GLsizei size, const void *pointer, GLenum usage) {
    typedef GLuint (APIENTRYP PFN_glNewObjectBufferATI) (GLsizei size, const void *pointer, GLenum usage);
    return ((PFN_glNewObjectBufferATI)__blue_glCore_glNewObjectBufferATI)(size, pointer, usage);
}

extern void* __blue_glCore_glIsObjectBufferATI;
GLboolean APIENTRY bluegl_glIsObjectBufferATI (GLuint buffer) {
    typedef GLboolean (APIENTRYP PFN_glIsObjectBufferATI) (GLuint buffer);
    return ((PFN_glIsObjectBufferATI)__blue_glCore_glIsObjectBufferATI)(buffer);
}

extern void* __blue_glCore_glUpdateObjectBufferATI;
void APIENTRY bluegl_glUpdateObjectBufferATI (GLuint buffer, GLuint offset, GLsizei size, const void *pointer, GLenum preserve) {
    typedef void (APIENTRYP PFN_glUpdateObjectBufferATI) (GLuint buffer, GLuint offset, GLsizei size, const void *pointer, GLenum preserve);
    return ((PFN_glUpdateObjectBufferATI)__blue_glCore_glUpdateObjectBufferATI)(buffer, offset, size, pointer, preserve);
}

extern void* __blue_glCore_glGetObjectBufferfvATI;
void APIENTRY bluegl_glGetObjectBufferfvATI (GLuint buffer, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetObjectBufferfvATI) (GLuint buffer, GLenum pname, GLfloat *params);
    return ((PFN_glGetObjectBufferfvATI)__blue_glCore_glGetObjectBufferfvATI)(buffer, pname, params);
}

extern void* __blue_glCore_glGetObjectBufferivATI;
void APIENTRY bluegl_glGetObjectBufferivATI (GLuint buffer, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetObjectBufferivATI) (GLuint buffer, GLenum pname, GLint *params);
    return ((PFN_glGetObjectBufferivATI)__blue_glCore_glGetObjectBufferivATI)(buffer, pname, params);
}

extern void* __blue_glCore_glFreeObjectBufferATI;
void APIENTRY bluegl_glFreeObjectBufferATI (GLuint buffer) {
    typedef void (APIENTRYP PFN_glFreeObjectBufferATI) (GLuint buffer);
    return ((PFN_glFreeObjectBufferATI)__blue_glCore_glFreeObjectBufferATI)(buffer);
}

extern void* __blue_glCore_glArrayObjectATI;
void APIENTRY bluegl_glArrayObjectATI (GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) {
    typedef void (APIENTRYP PFN_glArrayObjectATI) (GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
    return ((PFN_glArrayObjectATI)__blue_glCore_glArrayObjectATI)(array, size, type, stride, buffer, offset);
}

extern void* __blue_glCore_glGetArrayObjectfvATI;
void APIENTRY bluegl_glGetArrayObjectfvATI (GLenum array, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetArrayObjectfvATI) (GLenum array, GLenum pname, GLfloat *params);
    return ((PFN_glGetArrayObjectfvATI)__blue_glCore_glGetArrayObjectfvATI)(array, pname, params);
}

extern void* __blue_glCore_glGetArrayObjectivATI;
void APIENTRY bluegl_glGetArrayObjectivATI (GLenum array, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetArrayObjectivATI) (GLenum array, GLenum pname, GLint *params);
    return ((PFN_glGetArrayObjectivATI)__blue_glCore_glGetArrayObjectivATI)(array, pname, params);
}

extern void* __blue_glCore_glVariantArrayObjectATI;
void APIENTRY bluegl_glVariantArrayObjectATI (GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) {
    typedef void (APIENTRYP PFN_glVariantArrayObjectATI) (GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
    return ((PFN_glVariantArrayObjectATI)__blue_glCore_glVariantArrayObjectATI)(id, type, stride, buffer, offset);
}

extern void* __blue_glCore_glGetVariantArrayObjectfvATI;
void APIENTRY bluegl_glGetVariantArrayObjectfvATI (GLuint id, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetVariantArrayObjectfvATI) (GLuint id, GLenum pname, GLfloat *params);
    return ((PFN_glGetVariantArrayObjectfvATI)__blue_glCore_glGetVariantArrayObjectfvATI)(id, pname, params);
}

extern void* __blue_glCore_glGetVariantArrayObjectivATI;
void APIENTRY bluegl_glGetVariantArrayObjectivATI (GLuint id, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVariantArrayObjectivATI) (GLuint id, GLenum pname, GLint *params);
    return ((PFN_glGetVariantArrayObjectivATI)__blue_glCore_glGetVariantArrayObjectivATI)(id, pname, params);
}

extern void* __blue_glCore_glVertexAttribArrayObjectATI;
void APIENTRY bluegl_glVertexAttribArrayObjectATI (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset) {
    typedef void (APIENTRYP PFN_glVertexAttribArrayObjectATI) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
    return ((PFN_glVertexAttribArrayObjectATI)__blue_glCore_glVertexAttribArrayObjectATI)(index, size, type, normalized, stride, buffer, offset);
}

extern void* __blue_glCore_glGetVertexAttribArrayObjectfvATI;
void APIENTRY bluegl_glGetVertexAttribArrayObjectfvATI (GLuint index, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribArrayObjectfvATI) (GLuint index, GLenum pname, GLfloat *params);
    return ((PFN_glGetVertexAttribArrayObjectfvATI)__blue_glCore_glGetVertexAttribArrayObjectfvATI)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribArrayObjectivATI;
void APIENTRY bluegl_glGetVertexAttribArrayObjectivATI (GLuint index, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribArrayObjectivATI) (GLuint index, GLenum pname, GLint *params);
    return ((PFN_glGetVertexAttribArrayObjectivATI)__blue_glCore_glGetVertexAttribArrayObjectivATI)(index, pname, params);
}

extern void* __blue_glCore_glVertexStream1sATI;
void APIENTRY bluegl_glVertexStream1sATI (GLenum stream, GLshort x) {
    typedef void (APIENTRYP PFN_glVertexStream1sATI) (GLenum stream, GLshort x);
    return ((PFN_glVertexStream1sATI)__blue_glCore_glVertexStream1sATI)(stream, x);
}

extern void* __blue_glCore_glVertexStream1svATI;
void APIENTRY bluegl_glVertexStream1svATI (GLenum stream, const GLshort *coords) {
    typedef void (APIENTRYP PFN_glVertexStream1svATI) (GLenum stream, const GLshort *coords);
    return ((PFN_glVertexStream1svATI)__blue_glCore_glVertexStream1svATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream1iATI;
void APIENTRY bluegl_glVertexStream1iATI (GLenum stream, GLint x) {
    typedef void (APIENTRYP PFN_glVertexStream1iATI) (GLenum stream, GLint x);
    return ((PFN_glVertexStream1iATI)__blue_glCore_glVertexStream1iATI)(stream, x);
}

extern void* __blue_glCore_glVertexStream1ivATI;
void APIENTRY bluegl_glVertexStream1ivATI (GLenum stream, const GLint *coords) {
    typedef void (APIENTRYP PFN_glVertexStream1ivATI) (GLenum stream, const GLint *coords);
    return ((PFN_glVertexStream1ivATI)__blue_glCore_glVertexStream1ivATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream1fATI;
void APIENTRY bluegl_glVertexStream1fATI (GLenum stream, GLfloat x) {
    typedef void (APIENTRYP PFN_glVertexStream1fATI) (GLenum stream, GLfloat x);
    return ((PFN_glVertexStream1fATI)__blue_glCore_glVertexStream1fATI)(stream, x);
}

extern void* __blue_glCore_glVertexStream1fvATI;
void APIENTRY bluegl_glVertexStream1fvATI (GLenum stream, const GLfloat *coords) {
    typedef void (APIENTRYP PFN_glVertexStream1fvATI) (GLenum stream, const GLfloat *coords);
    return ((PFN_glVertexStream1fvATI)__blue_glCore_glVertexStream1fvATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream1dATI;
void APIENTRY bluegl_glVertexStream1dATI (GLenum stream, GLdouble x) {
    typedef void (APIENTRYP PFN_glVertexStream1dATI) (GLenum stream, GLdouble x);
    return ((PFN_glVertexStream1dATI)__blue_glCore_glVertexStream1dATI)(stream, x);
}

extern void* __blue_glCore_glVertexStream1dvATI;
void APIENTRY bluegl_glVertexStream1dvATI (GLenum stream, const GLdouble *coords) {
    typedef void (APIENTRYP PFN_glVertexStream1dvATI) (GLenum stream, const GLdouble *coords);
    return ((PFN_glVertexStream1dvATI)__blue_glCore_glVertexStream1dvATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream2sATI;
void APIENTRY bluegl_glVertexStream2sATI (GLenum stream, GLshort x, GLshort y) {
    typedef void (APIENTRYP PFN_glVertexStream2sATI) (GLenum stream, GLshort x, GLshort y);
    return ((PFN_glVertexStream2sATI)__blue_glCore_glVertexStream2sATI)(stream, x, y);
}

extern void* __blue_glCore_glVertexStream2svATI;
void APIENTRY bluegl_glVertexStream2svATI (GLenum stream, const GLshort *coords) {
    typedef void (APIENTRYP PFN_glVertexStream2svATI) (GLenum stream, const GLshort *coords);
    return ((PFN_glVertexStream2svATI)__blue_glCore_glVertexStream2svATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream2iATI;
void APIENTRY bluegl_glVertexStream2iATI (GLenum stream, GLint x, GLint y) {
    typedef void (APIENTRYP PFN_glVertexStream2iATI) (GLenum stream, GLint x, GLint y);
    return ((PFN_glVertexStream2iATI)__blue_glCore_glVertexStream2iATI)(stream, x, y);
}

extern void* __blue_glCore_glVertexStream2ivATI;
void APIENTRY bluegl_glVertexStream2ivATI (GLenum stream, const GLint *coords) {
    typedef void (APIENTRYP PFN_glVertexStream2ivATI) (GLenum stream, const GLint *coords);
    return ((PFN_glVertexStream2ivATI)__blue_glCore_glVertexStream2ivATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream2fATI;
void APIENTRY bluegl_glVertexStream2fATI (GLenum stream, GLfloat x, GLfloat y) {
    typedef void (APIENTRYP PFN_glVertexStream2fATI) (GLenum stream, GLfloat x, GLfloat y);
    return ((PFN_glVertexStream2fATI)__blue_glCore_glVertexStream2fATI)(stream, x, y);
}

extern void* __blue_glCore_glVertexStream2fvATI;
void APIENTRY bluegl_glVertexStream2fvATI (GLenum stream, const GLfloat *coords) {
    typedef void (APIENTRYP PFN_glVertexStream2fvATI) (GLenum stream, const GLfloat *coords);
    return ((PFN_glVertexStream2fvATI)__blue_glCore_glVertexStream2fvATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream2dATI;
void APIENTRY bluegl_glVertexStream2dATI (GLenum stream, GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glVertexStream2dATI) (GLenum stream, GLdouble x, GLdouble y);
    return ((PFN_glVertexStream2dATI)__blue_glCore_glVertexStream2dATI)(stream, x, y);
}

extern void* __blue_glCore_glVertexStream2dvATI;
void APIENTRY bluegl_glVertexStream2dvATI (GLenum stream, const GLdouble *coords) {
    typedef void (APIENTRYP PFN_glVertexStream2dvATI) (GLenum stream, const GLdouble *coords);
    return ((PFN_glVertexStream2dvATI)__blue_glCore_glVertexStream2dvATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream3sATI;
void APIENTRY bluegl_glVertexStream3sATI (GLenum stream, GLshort x, GLshort y, GLshort z) {
    typedef void (APIENTRYP PFN_glVertexStream3sATI) (GLenum stream, GLshort x, GLshort y, GLshort z);
    return ((PFN_glVertexStream3sATI)__blue_glCore_glVertexStream3sATI)(stream, x, y, z);
}

extern void* __blue_glCore_glVertexStream3svATI;
void APIENTRY bluegl_glVertexStream3svATI (GLenum stream, const GLshort *coords) {
    typedef void (APIENTRYP PFN_glVertexStream3svATI) (GLenum stream, const GLshort *coords);
    return ((PFN_glVertexStream3svATI)__blue_glCore_glVertexStream3svATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream3iATI;
void APIENTRY bluegl_glVertexStream3iATI (GLenum stream, GLint x, GLint y, GLint z) {
    typedef void (APIENTRYP PFN_glVertexStream3iATI) (GLenum stream, GLint x, GLint y, GLint z);
    return ((PFN_glVertexStream3iATI)__blue_glCore_glVertexStream3iATI)(stream, x, y, z);
}

extern void* __blue_glCore_glVertexStream3ivATI;
void APIENTRY bluegl_glVertexStream3ivATI (GLenum stream, const GLint *coords) {
    typedef void (APIENTRYP PFN_glVertexStream3ivATI) (GLenum stream, const GLint *coords);
    return ((PFN_glVertexStream3ivATI)__blue_glCore_glVertexStream3ivATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream3fATI;
void APIENTRY bluegl_glVertexStream3fATI (GLenum stream, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glVertexStream3fATI) (GLenum stream, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glVertexStream3fATI)__blue_glCore_glVertexStream3fATI)(stream, x, y, z);
}

extern void* __blue_glCore_glVertexStream3fvATI;
void APIENTRY bluegl_glVertexStream3fvATI (GLenum stream, const GLfloat *coords) {
    typedef void (APIENTRYP PFN_glVertexStream3fvATI) (GLenum stream, const GLfloat *coords);
    return ((PFN_glVertexStream3fvATI)__blue_glCore_glVertexStream3fvATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream3dATI;
void APIENTRY bluegl_glVertexStream3dATI (GLenum stream, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glVertexStream3dATI) (GLenum stream, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glVertexStream3dATI)__blue_glCore_glVertexStream3dATI)(stream, x, y, z);
}

extern void* __blue_glCore_glVertexStream3dvATI;
void APIENTRY bluegl_glVertexStream3dvATI (GLenum stream, const GLdouble *coords) {
    typedef void (APIENTRYP PFN_glVertexStream3dvATI) (GLenum stream, const GLdouble *coords);
    return ((PFN_glVertexStream3dvATI)__blue_glCore_glVertexStream3dvATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream4sATI;
void APIENTRY bluegl_glVertexStream4sATI (GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w) {
    typedef void (APIENTRYP PFN_glVertexStream4sATI) (GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
    return ((PFN_glVertexStream4sATI)__blue_glCore_glVertexStream4sATI)(stream, x, y, z, w);
}

extern void* __blue_glCore_glVertexStream4svATI;
void APIENTRY bluegl_glVertexStream4svATI (GLenum stream, const GLshort *coords) {
    typedef void (APIENTRYP PFN_glVertexStream4svATI) (GLenum stream, const GLshort *coords);
    return ((PFN_glVertexStream4svATI)__blue_glCore_glVertexStream4svATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream4iATI;
void APIENTRY bluegl_glVertexStream4iATI (GLenum stream, GLint x, GLint y, GLint z, GLint w) {
    typedef void (APIENTRYP PFN_glVertexStream4iATI) (GLenum stream, GLint x, GLint y, GLint z, GLint w);
    return ((PFN_glVertexStream4iATI)__blue_glCore_glVertexStream4iATI)(stream, x, y, z, w);
}

extern void* __blue_glCore_glVertexStream4ivATI;
void APIENTRY bluegl_glVertexStream4ivATI (GLenum stream, const GLint *coords) {
    typedef void (APIENTRYP PFN_glVertexStream4ivATI) (GLenum stream, const GLint *coords);
    return ((PFN_glVertexStream4ivATI)__blue_glCore_glVertexStream4ivATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream4fATI;
void APIENTRY bluegl_glVertexStream4fATI (GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glVertexStream4fATI) (GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glVertexStream4fATI)__blue_glCore_glVertexStream4fATI)(stream, x, y, z, w);
}

extern void* __blue_glCore_glVertexStream4fvATI;
void APIENTRY bluegl_glVertexStream4fvATI (GLenum stream, const GLfloat *coords) {
    typedef void (APIENTRYP PFN_glVertexStream4fvATI) (GLenum stream, const GLfloat *coords);
    return ((PFN_glVertexStream4fvATI)__blue_glCore_glVertexStream4fvATI)(stream, coords);
}

extern void* __blue_glCore_glVertexStream4dATI;
void APIENTRY bluegl_glVertexStream4dATI (GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glVertexStream4dATI) (GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glVertexStream4dATI)__blue_glCore_glVertexStream4dATI)(stream, x, y, z, w);
}

extern void* __blue_glCore_glVertexStream4dvATI;
void APIENTRY bluegl_glVertexStream4dvATI (GLenum stream, const GLdouble *coords) {
    typedef void (APIENTRYP PFN_glVertexStream4dvATI) (GLenum stream, const GLdouble *coords);
    return ((PFN_glVertexStream4dvATI)__blue_glCore_glVertexStream4dvATI)(stream, coords);
}

extern void* __blue_glCore_glNormalStream3bATI;
void APIENTRY bluegl_glNormalStream3bATI (GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz) {
    typedef void (APIENTRYP PFN_glNormalStream3bATI) (GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
    return ((PFN_glNormalStream3bATI)__blue_glCore_glNormalStream3bATI)(stream, nx, ny, nz);
}

extern void* __blue_glCore_glNormalStream3bvATI;
void APIENTRY bluegl_glNormalStream3bvATI (GLenum stream, const GLbyte *coords) {
    typedef void (APIENTRYP PFN_glNormalStream3bvATI) (GLenum stream, const GLbyte *coords);
    return ((PFN_glNormalStream3bvATI)__blue_glCore_glNormalStream3bvATI)(stream, coords);
}

extern void* __blue_glCore_glNormalStream3sATI;
void APIENTRY bluegl_glNormalStream3sATI (GLenum stream, GLshort nx, GLshort ny, GLshort nz) {
    typedef void (APIENTRYP PFN_glNormalStream3sATI) (GLenum stream, GLshort nx, GLshort ny, GLshort nz);
    return ((PFN_glNormalStream3sATI)__blue_glCore_glNormalStream3sATI)(stream, nx, ny, nz);
}

extern void* __blue_glCore_glNormalStream3svATI;
void APIENTRY bluegl_glNormalStream3svATI (GLenum stream, const GLshort *coords) {
    typedef void (APIENTRYP PFN_glNormalStream3svATI) (GLenum stream, const GLshort *coords);
    return ((PFN_glNormalStream3svATI)__blue_glCore_glNormalStream3svATI)(stream, coords);
}

extern void* __blue_glCore_glNormalStream3iATI;
void APIENTRY bluegl_glNormalStream3iATI (GLenum stream, GLint nx, GLint ny, GLint nz) {
    typedef void (APIENTRYP PFN_glNormalStream3iATI) (GLenum stream, GLint nx, GLint ny, GLint nz);
    return ((PFN_glNormalStream3iATI)__blue_glCore_glNormalStream3iATI)(stream, nx, ny, nz);
}

extern void* __blue_glCore_glNormalStream3ivATI;
void APIENTRY bluegl_glNormalStream3ivATI (GLenum stream, const GLint *coords) {
    typedef void (APIENTRYP PFN_glNormalStream3ivATI) (GLenum stream, const GLint *coords);
    return ((PFN_glNormalStream3ivATI)__blue_glCore_glNormalStream3ivATI)(stream, coords);
}

extern void* __blue_glCore_glNormalStream3fATI;
void APIENTRY bluegl_glNormalStream3fATI (GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz) {
    typedef void (APIENTRYP PFN_glNormalStream3fATI) (GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
    return ((PFN_glNormalStream3fATI)__blue_glCore_glNormalStream3fATI)(stream, nx, ny, nz);
}

extern void* __blue_glCore_glNormalStream3fvATI;
void APIENTRY bluegl_glNormalStream3fvATI (GLenum stream, const GLfloat *coords) {
    typedef void (APIENTRYP PFN_glNormalStream3fvATI) (GLenum stream, const GLfloat *coords);
    return ((PFN_glNormalStream3fvATI)__blue_glCore_glNormalStream3fvATI)(stream, coords);
}

extern void* __blue_glCore_glNormalStream3dATI;
void APIENTRY bluegl_glNormalStream3dATI (GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz) {
    typedef void (APIENTRYP PFN_glNormalStream3dATI) (GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
    return ((PFN_glNormalStream3dATI)__blue_glCore_glNormalStream3dATI)(stream, nx, ny, nz);
}

extern void* __blue_glCore_glNormalStream3dvATI;
void APIENTRY bluegl_glNormalStream3dvATI (GLenum stream, const GLdouble *coords) {
    typedef void (APIENTRYP PFN_glNormalStream3dvATI) (GLenum stream, const GLdouble *coords);
    return ((PFN_glNormalStream3dvATI)__blue_glCore_glNormalStream3dvATI)(stream, coords);
}

extern void* __blue_glCore_glClientActiveVertexStreamATI;
void APIENTRY bluegl_glClientActiveVertexStreamATI (GLenum stream) {
    typedef void (APIENTRYP PFN_glClientActiveVertexStreamATI) (GLenum stream);
    return ((PFN_glClientActiveVertexStreamATI)__blue_glCore_glClientActiveVertexStreamATI)(stream);
}

extern void* __blue_glCore_glVertexBlendEnviATI;
void APIENTRY bluegl_glVertexBlendEnviATI (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glVertexBlendEnviATI) (GLenum pname, GLint param);
    return ((PFN_glVertexBlendEnviATI)__blue_glCore_glVertexBlendEnviATI)(pname, param);
}

extern void* __blue_glCore_glVertexBlendEnvfATI;
void APIENTRY bluegl_glVertexBlendEnvfATI (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glVertexBlendEnvfATI) (GLenum pname, GLfloat param);
    return ((PFN_glVertexBlendEnvfATI)__blue_glCore_glVertexBlendEnvfATI)(pname, param);
}

extern void* __blue_glCore_glUniformBufferEXT;
void APIENTRY bluegl_glUniformBufferEXT (GLuint program, GLint location, GLuint buffer) {
    typedef void (APIENTRYP PFN_glUniformBufferEXT) (GLuint program, GLint location, GLuint buffer);
    return ((PFN_glUniformBufferEXT)__blue_glCore_glUniformBufferEXT)(program, location, buffer);
}

extern void* __blue_glCore_glGetUniformBufferSizeEXT;
GLint APIENTRY bluegl_glGetUniformBufferSizeEXT (GLuint program, GLint location) {
    typedef GLint (APIENTRYP PFN_glGetUniformBufferSizeEXT) (GLuint program, GLint location);
    return ((PFN_glGetUniformBufferSizeEXT)__blue_glCore_glGetUniformBufferSizeEXT)(program, location);
}

extern void* __blue_glCore_glGetUniformOffsetEXT;
GLintptr APIENTRY bluegl_glGetUniformOffsetEXT (GLuint program, GLint location) {
    typedef GLintptr (APIENTRYP PFN_glGetUniformOffsetEXT) (GLuint program, GLint location);
    return ((PFN_glGetUniformOffsetEXT)__blue_glCore_glGetUniformOffsetEXT)(program, location);
}

extern void* __blue_glCore_glBlendColorEXT;
void APIENTRY bluegl_glBlendColorEXT (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    typedef void (APIENTRYP PFN_glBlendColorEXT) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    return ((PFN_glBlendColorEXT)__blue_glCore_glBlendColorEXT)(red, green, blue, alpha);
}

extern void* __blue_glCore_glBlendEquationSeparateEXT;
void APIENTRY bluegl_glBlendEquationSeparateEXT (GLenum modeRGB, GLenum modeAlpha) {
    typedef void (APIENTRYP PFN_glBlendEquationSeparateEXT) (GLenum modeRGB, GLenum modeAlpha);
    return ((PFN_glBlendEquationSeparateEXT)__blue_glCore_glBlendEquationSeparateEXT)(modeRGB, modeAlpha);
}

extern void* __blue_glCore_glBlendFuncSeparateEXT;
void APIENTRY bluegl_glBlendFuncSeparateEXT (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    typedef void (APIENTRYP PFN_glBlendFuncSeparateEXT) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
    return ((PFN_glBlendFuncSeparateEXT)__blue_glCore_glBlendFuncSeparateEXT)(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

extern void* __blue_glCore_glBlendEquationEXT;
void APIENTRY bluegl_glBlendEquationEXT (GLenum mode) {
    typedef void (APIENTRYP PFN_glBlendEquationEXT) (GLenum mode);
    return ((PFN_glBlendEquationEXT)__blue_glCore_glBlendEquationEXT)(mode);
}

extern void* __blue_glCore_glColorSubTableEXT;
void APIENTRY bluegl_glColorSubTableEXT (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glColorSubTableEXT) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
    return ((PFN_glColorSubTableEXT)__blue_glCore_glColorSubTableEXT)(target, start, count, format, type, data);
}

extern void* __blue_glCore_glCopyColorSubTableEXT;
void APIENTRY bluegl_glCopyColorSubTableEXT (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyColorSubTableEXT) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyColorSubTableEXT)__blue_glCore_glCopyColorSubTableEXT)(target, start, x, y, width);
}

extern void* __blue_glCore_glLockArraysEXT;
void APIENTRY bluegl_glLockArraysEXT (GLint first, GLsizei count) {
    typedef void (APIENTRYP PFN_glLockArraysEXT) (GLint first, GLsizei count);
    return ((PFN_glLockArraysEXT)__blue_glCore_glLockArraysEXT)(first, count);
}

extern void* __blue_glCore_glUnlockArraysEXT;
void APIENTRY bluegl_glUnlockArraysEXT (void) {
    typedef void (APIENTRYP PFN_glUnlockArraysEXT) (void);
    return ((PFN_glUnlockArraysEXT)__blue_glCore_glUnlockArraysEXT)();
}

extern void* __blue_glCore_glConvolutionFilter1DEXT;
void APIENTRY bluegl_glConvolutionFilter1DEXT (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image) {
    typedef void (APIENTRYP PFN_glConvolutionFilter1DEXT) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
    return ((PFN_glConvolutionFilter1DEXT)__blue_glCore_glConvolutionFilter1DEXT)(target, internalformat, width, format, type, image);
}

extern void* __blue_glCore_glConvolutionFilter2DEXT;
void APIENTRY bluegl_glConvolutionFilter2DEXT (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image) {
    typedef void (APIENTRYP PFN_glConvolutionFilter2DEXT) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
    return ((PFN_glConvolutionFilter2DEXT)__blue_glCore_glConvolutionFilter2DEXT)(target, internalformat, width, height, format, type, image);
}

extern void* __blue_glCore_glConvolutionParameterfEXT;
void APIENTRY bluegl_glConvolutionParameterfEXT (GLenum target, GLenum pname, GLfloat params) {
    typedef void (APIENTRYP PFN_glConvolutionParameterfEXT) (GLenum target, GLenum pname, GLfloat params);
    return ((PFN_glConvolutionParameterfEXT)__blue_glCore_glConvolutionParameterfEXT)(target, pname, params);
}

extern void* __blue_glCore_glConvolutionParameterfvEXT;
void APIENTRY bluegl_glConvolutionParameterfvEXT (GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glConvolutionParameterfvEXT) (GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glConvolutionParameterfvEXT)__blue_glCore_glConvolutionParameterfvEXT)(target, pname, params);
}

extern void* __blue_glCore_glConvolutionParameteriEXT;
void APIENTRY bluegl_glConvolutionParameteriEXT (GLenum target, GLenum pname, GLint params) {
    typedef void (APIENTRYP PFN_glConvolutionParameteriEXT) (GLenum target, GLenum pname, GLint params);
    return ((PFN_glConvolutionParameteriEXT)__blue_glCore_glConvolutionParameteriEXT)(target, pname, params);
}

extern void* __blue_glCore_glConvolutionParameterivEXT;
void APIENTRY bluegl_glConvolutionParameterivEXT (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glConvolutionParameterivEXT) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glConvolutionParameterivEXT)__blue_glCore_glConvolutionParameterivEXT)(target, pname, params);
}

extern void* __blue_glCore_glCopyConvolutionFilter1DEXT;
void APIENTRY bluegl_glCopyConvolutionFilter1DEXT (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyConvolutionFilter1DEXT) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyConvolutionFilter1DEXT)__blue_glCore_glCopyConvolutionFilter1DEXT)(target, internalformat, x, y, width);
}

extern void* __blue_glCore_glCopyConvolutionFilter2DEXT;
void APIENTRY bluegl_glCopyConvolutionFilter2DEXT (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyConvolutionFilter2DEXT) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyConvolutionFilter2DEXT)__blue_glCore_glCopyConvolutionFilter2DEXT)(target, internalformat, x, y, width, height);
}

extern void* __blue_glCore_glGetConvolutionFilterEXT;
void APIENTRY bluegl_glGetConvolutionFilterEXT (GLenum target, GLenum format, GLenum type, void *image) {
    typedef void (APIENTRYP PFN_glGetConvolutionFilterEXT) (GLenum target, GLenum format, GLenum type, void *image);
    return ((PFN_glGetConvolutionFilterEXT)__blue_glCore_glGetConvolutionFilterEXT)(target, format, type, image);
}

extern void* __blue_glCore_glGetConvolutionParameterfvEXT;
void APIENTRY bluegl_glGetConvolutionParameterfvEXT (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetConvolutionParameterfvEXT) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetConvolutionParameterfvEXT)__blue_glCore_glGetConvolutionParameterfvEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetConvolutionParameterivEXT;
void APIENTRY bluegl_glGetConvolutionParameterivEXT (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetConvolutionParameterivEXT) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetConvolutionParameterivEXT)__blue_glCore_glGetConvolutionParameterivEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetSeparableFilterEXT;
void APIENTRY bluegl_glGetSeparableFilterEXT (GLenum target, GLenum format, GLenum type, void *row, void *column, void *span) {
    typedef void (APIENTRYP PFN_glGetSeparableFilterEXT) (GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
    return ((PFN_glGetSeparableFilterEXT)__blue_glCore_glGetSeparableFilterEXT)(target, format, type, row, column, span);
}

extern void* __blue_glCore_glSeparableFilter2DEXT;
void APIENTRY bluegl_glSeparableFilter2DEXT (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column) {
    typedef void (APIENTRYP PFN_glSeparableFilter2DEXT) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
    return ((PFN_glSeparableFilter2DEXT)__blue_glCore_glSeparableFilter2DEXT)(target, internalformat, width, height, format, type, row, column);
}

extern void* __blue_glCore_glTangent3bEXT;
void APIENTRY bluegl_glTangent3bEXT (GLbyte tx, GLbyte ty, GLbyte tz) {
    typedef void (APIENTRYP PFN_glTangent3bEXT) (GLbyte tx, GLbyte ty, GLbyte tz);
    return ((PFN_glTangent3bEXT)__blue_glCore_glTangent3bEXT)(tx, ty, tz);
}

extern void* __blue_glCore_glTangent3bvEXT;
void APIENTRY bluegl_glTangent3bvEXT (const GLbyte *v) {
    typedef void (APIENTRYP PFN_glTangent3bvEXT) (const GLbyte *v);
    return ((PFN_glTangent3bvEXT)__blue_glCore_glTangent3bvEXT)(v);
}

extern void* __blue_glCore_glTangent3dEXT;
void APIENTRY bluegl_glTangent3dEXT (GLdouble tx, GLdouble ty, GLdouble tz) {
    typedef void (APIENTRYP PFN_glTangent3dEXT) (GLdouble tx, GLdouble ty, GLdouble tz);
    return ((PFN_glTangent3dEXT)__blue_glCore_glTangent3dEXT)(tx, ty, tz);
}

extern void* __blue_glCore_glTangent3dvEXT;
void APIENTRY bluegl_glTangent3dvEXT (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glTangent3dvEXT) (const GLdouble *v);
    return ((PFN_glTangent3dvEXT)__blue_glCore_glTangent3dvEXT)(v);
}

extern void* __blue_glCore_glTangent3fEXT;
void APIENTRY bluegl_glTangent3fEXT (GLfloat tx, GLfloat ty, GLfloat tz) {
    typedef void (APIENTRYP PFN_glTangent3fEXT) (GLfloat tx, GLfloat ty, GLfloat tz);
    return ((PFN_glTangent3fEXT)__blue_glCore_glTangent3fEXT)(tx, ty, tz);
}

extern void* __blue_glCore_glTangent3fvEXT;
void APIENTRY bluegl_glTangent3fvEXT (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glTangent3fvEXT) (const GLfloat *v);
    return ((PFN_glTangent3fvEXT)__blue_glCore_glTangent3fvEXT)(v);
}

extern void* __blue_glCore_glTangent3iEXT;
void APIENTRY bluegl_glTangent3iEXT (GLint tx, GLint ty, GLint tz) {
    typedef void (APIENTRYP PFN_glTangent3iEXT) (GLint tx, GLint ty, GLint tz);
    return ((PFN_glTangent3iEXT)__blue_glCore_glTangent3iEXT)(tx, ty, tz);
}

extern void* __blue_glCore_glTangent3ivEXT;
void APIENTRY bluegl_glTangent3ivEXT (const GLint *v) {
    typedef void (APIENTRYP PFN_glTangent3ivEXT) (const GLint *v);
    return ((PFN_glTangent3ivEXT)__blue_glCore_glTangent3ivEXT)(v);
}

extern void* __blue_glCore_glTangent3sEXT;
void APIENTRY bluegl_glTangent3sEXT (GLshort tx, GLshort ty, GLshort tz) {
    typedef void (APIENTRYP PFN_glTangent3sEXT) (GLshort tx, GLshort ty, GLshort tz);
    return ((PFN_glTangent3sEXT)__blue_glCore_glTangent3sEXT)(tx, ty, tz);
}

extern void* __blue_glCore_glTangent3svEXT;
void APIENTRY bluegl_glTangent3svEXT (const GLshort *v) {
    typedef void (APIENTRYP PFN_glTangent3svEXT) (const GLshort *v);
    return ((PFN_glTangent3svEXT)__blue_glCore_glTangent3svEXT)(v);
}

extern void* __blue_glCore_glBinormal3bEXT;
void APIENTRY bluegl_glBinormal3bEXT (GLbyte bx, GLbyte by, GLbyte bz) {
    typedef void (APIENTRYP PFN_glBinormal3bEXT) (GLbyte bx, GLbyte by, GLbyte bz);
    return ((PFN_glBinormal3bEXT)__blue_glCore_glBinormal3bEXT)(bx, by, bz);
}

extern void* __blue_glCore_glBinormal3bvEXT;
void APIENTRY bluegl_glBinormal3bvEXT (const GLbyte *v) {
    typedef void (APIENTRYP PFN_glBinormal3bvEXT) (const GLbyte *v);
    return ((PFN_glBinormal3bvEXT)__blue_glCore_glBinormal3bvEXT)(v);
}

extern void* __blue_glCore_glBinormal3dEXT;
void APIENTRY bluegl_glBinormal3dEXT (GLdouble bx, GLdouble by, GLdouble bz) {
    typedef void (APIENTRYP PFN_glBinormal3dEXT) (GLdouble bx, GLdouble by, GLdouble bz);
    return ((PFN_glBinormal3dEXT)__blue_glCore_glBinormal3dEXT)(bx, by, bz);
}

extern void* __blue_glCore_glBinormal3dvEXT;
void APIENTRY bluegl_glBinormal3dvEXT (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glBinormal3dvEXT) (const GLdouble *v);
    return ((PFN_glBinormal3dvEXT)__blue_glCore_glBinormal3dvEXT)(v);
}

extern void* __blue_glCore_glBinormal3fEXT;
void APIENTRY bluegl_glBinormal3fEXT (GLfloat bx, GLfloat by, GLfloat bz) {
    typedef void (APIENTRYP PFN_glBinormal3fEXT) (GLfloat bx, GLfloat by, GLfloat bz);
    return ((PFN_glBinormal3fEXT)__blue_glCore_glBinormal3fEXT)(bx, by, bz);
}

extern void* __blue_glCore_glBinormal3fvEXT;
void APIENTRY bluegl_glBinormal3fvEXT (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glBinormal3fvEXT) (const GLfloat *v);
    return ((PFN_glBinormal3fvEXT)__blue_glCore_glBinormal3fvEXT)(v);
}

extern void* __blue_glCore_glBinormal3iEXT;
void APIENTRY bluegl_glBinormal3iEXT (GLint bx, GLint by, GLint bz) {
    typedef void (APIENTRYP PFN_glBinormal3iEXT) (GLint bx, GLint by, GLint bz);
    return ((PFN_glBinormal3iEXT)__blue_glCore_glBinormal3iEXT)(bx, by, bz);
}

extern void* __blue_glCore_glBinormal3ivEXT;
void APIENTRY bluegl_glBinormal3ivEXT (const GLint *v) {
    typedef void (APIENTRYP PFN_glBinormal3ivEXT) (const GLint *v);
    return ((PFN_glBinormal3ivEXT)__blue_glCore_glBinormal3ivEXT)(v);
}

extern void* __blue_glCore_glBinormal3sEXT;
void APIENTRY bluegl_glBinormal3sEXT (GLshort bx, GLshort by, GLshort bz) {
    typedef void (APIENTRYP PFN_glBinormal3sEXT) (GLshort bx, GLshort by, GLshort bz);
    return ((PFN_glBinormal3sEXT)__blue_glCore_glBinormal3sEXT)(bx, by, bz);
}

extern void* __blue_glCore_glBinormal3svEXT;
void APIENTRY bluegl_glBinormal3svEXT (const GLshort *v) {
    typedef void (APIENTRYP PFN_glBinormal3svEXT) (const GLshort *v);
    return ((PFN_glBinormal3svEXT)__blue_glCore_glBinormal3svEXT)(v);
}

extern void* __blue_glCore_glTangentPointerEXT;
void APIENTRY bluegl_glTangentPointerEXT (GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glTangentPointerEXT) (GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glTangentPointerEXT)__blue_glCore_glTangentPointerEXT)(type, stride, pointer);
}

extern void* __blue_glCore_glBinormalPointerEXT;
void APIENTRY bluegl_glBinormalPointerEXT (GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glBinormalPointerEXT) (GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glBinormalPointerEXT)__blue_glCore_glBinormalPointerEXT)(type, stride, pointer);
}

extern void* __blue_glCore_glCopyTexImage1DEXT;
void APIENTRY bluegl_glCopyTexImage1DEXT (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    typedef void (APIENTRYP PFN_glCopyTexImage1DEXT) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    return ((PFN_glCopyTexImage1DEXT)__blue_glCore_glCopyTexImage1DEXT)(target, level, internalformat, x, y, width, border);
}

extern void* __blue_glCore_glCopyTexImage2DEXT;
void APIENTRY bluegl_glCopyTexImage2DEXT (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    typedef void (APIENTRYP PFN_glCopyTexImage2DEXT) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    return ((PFN_glCopyTexImage2DEXT)__blue_glCore_glCopyTexImage2DEXT)(target, level, internalformat, x, y, width, height, border);
}

extern void* __blue_glCore_glCopyTexSubImage1DEXT;
void APIENTRY bluegl_glCopyTexSubImage1DEXT (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyTexSubImage1DEXT) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyTexSubImage1DEXT)__blue_glCore_glCopyTexSubImage1DEXT)(target, level, xoffset, x, y, width);
}

extern void* __blue_glCore_glCopyTexSubImage2DEXT;
void APIENTRY bluegl_glCopyTexSubImage2DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyTexSubImage2DEXT) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyTexSubImage2DEXT)__blue_glCore_glCopyTexSubImage2DEXT)(target, level, xoffset, yoffset, x, y, width, height);
}

extern void* __blue_glCore_glCopyTexSubImage3DEXT;
void APIENTRY bluegl_glCopyTexSubImage3DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyTexSubImage3DEXT) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyTexSubImage3DEXT)__blue_glCore_glCopyTexSubImage3DEXT)(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

extern void* __blue_glCore_glCullParameterdvEXT;
void APIENTRY bluegl_glCullParameterdvEXT (GLenum pname, GLdouble *params) {
    typedef void (APIENTRYP PFN_glCullParameterdvEXT) (GLenum pname, GLdouble *params);
    return ((PFN_glCullParameterdvEXT)__blue_glCore_glCullParameterdvEXT)(pname, params);
}

extern void* __blue_glCore_glCullParameterfvEXT;
void APIENTRY bluegl_glCullParameterfvEXT (GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glCullParameterfvEXT) (GLenum pname, GLfloat *params);
    return ((PFN_glCullParameterfvEXT)__blue_glCore_glCullParameterfvEXT)(pname, params);
}

extern void* __blue_glCore_glLabelObjectEXT;
void APIENTRY bluegl_glLabelObjectEXT (GLenum type, GLuint object, GLsizei length, const GLchar *label) {
    typedef void (APIENTRYP PFN_glLabelObjectEXT) (GLenum type, GLuint object, GLsizei length, const GLchar *label);
    return ((PFN_glLabelObjectEXT)__blue_glCore_glLabelObjectEXT)(type, object, length, label);
}

extern void* __blue_glCore_glGetObjectLabelEXT;
void APIENTRY bluegl_glGetObjectLabelEXT (GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label) {
    typedef void (APIENTRYP PFN_glGetObjectLabelEXT) (GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
    return ((PFN_glGetObjectLabelEXT)__blue_glCore_glGetObjectLabelEXT)(type, object, bufSize, length, label);
}

extern void* __blue_glCore_glInsertEventMarkerEXT;
void APIENTRY bluegl_glInsertEventMarkerEXT (GLsizei length, const GLchar *marker) {
    typedef void (APIENTRYP PFN_glInsertEventMarkerEXT) (GLsizei length, const GLchar *marker);
    return ((PFN_glInsertEventMarkerEXT)__blue_glCore_glInsertEventMarkerEXT)(length, marker);
}

extern void* __blue_glCore_glPushGroupMarkerEXT;
void APIENTRY bluegl_glPushGroupMarkerEXT (GLsizei length, const GLchar *marker) {
    typedef void (APIENTRYP PFN_glPushGroupMarkerEXT) (GLsizei length, const GLchar *marker);
    return ((PFN_glPushGroupMarkerEXT)__blue_glCore_glPushGroupMarkerEXT)(length, marker);
}

extern void* __blue_glCore_glPopGroupMarkerEXT;
void APIENTRY bluegl_glPopGroupMarkerEXT (void) {
    typedef void (APIENTRYP PFN_glPopGroupMarkerEXT) (void);
    return ((PFN_glPopGroupMarkerEXT)__blue_glCore_glPopGroupMarkerEXT)();
}

extern void* __blue_glCore_glDepthBoundsEXT;
void APIENTRY bluegl_glDepthBoundsEXT (GLclampd zmin, GLclampd zmax) {
    typedef void (APIENTRYP PFN_glDepthBoundsEXT) (GLclampd zmin, GLclampd zmax);
    return ((PFN_glDepthBoundsEXT)__blue_glCore_glDepthBoundsEXT)(zmin, zmax);
}

extern void* __blue_glCore_glMatrixLoadfEXT;
void APIENTRY bluegl_glMatrixLoadfEXT (GLenum mode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixLoadfEXT) (GLenum mode, const GLfloat *m);
    return ((PFN_glMatrixLoadfEXT)__blue_glCore_glMatrixLoadfEXT)(mode, m);
}

extern void* __blue_glCore_glMatrixLoaddEXT;
void APIENTRY bluegl_glMatrixLoaddEXT (GLenum mode, const GLdouble *m) {
    typedef void (APIENTRYP PFN_glMatrixLoaddEXT) (GLenum mode, const GLdouble *m);
    return ((PFN_glMatrixLoaddEXT)__blue_glCore_glMatrixLoaddEXT)(mode, m);
}

extern void* __blue_glCore_glMatrixMultfEXT;
void APIENTRY bluegl_glMatrixMultfEXT (GLenum mode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixMultfEXT) (GLenum mode, const GLfloat *m);
    return ((PFN_glMatrixMultfEXT)__blue_glCore_glMatrixMultfEXT)(mode, m);
}

extern void* __blue_glCore_glMatrixMultdEXT;
void APIENTRY bluegl_glMatrixMultdEXT (GLenum mode, const GLdouble *m) {
    typedef void (APIENTRYP PFN_glMatrixMultdEXT) (GLenum mode, const GLdouble *m);
    return ((PFN_glMatrixMultdEXT)__blue_glCore_glMatrixMultdEXT)(mode, m);
}

extern void* __blue_glCore_glMatrixLoadIdentityEXT;
void APIENTRY bluegl_glMatrixLoadIdentityEXT (GLenum mode) {
    typedef void (APIENTRYP PFN_glMatrixLoadIdentityEXT) (GLenum mode);
    return ((PFN_glMatrixLoadIdentityEXT)__blue_glCore_glMatrixLoadIdentityEXT)(mode);
}

extern void* __blue_glCore_glMatrixRotatefEXT;
void APIENTRY bluegl_glMatrixRotatefEXT (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glMatrixRotatefEXT) (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glMatrixRotatefEXT)__blue_glCore_glMatrixRotatefEXT)(mode, angle, x, y, z);
}

extern void* __blue_glCore_glMatrixRotatedEXT;
void APIENTRY bluegl_glMatrixRotatedEXT (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glMatrixRotatedEXT) (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glMatrixRotatedEXT)__blue_glCore_glMatrixRotatedEXT)(mode, angle, x, y, z);
}

extern void* __blue_glCore_glMatrixScalefEXT;
void APIENTRY bluegl_glMatrixScalefEXT (GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glMatrixScalefEXT) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glMatrixScalefEXT)__blue_glCore_glMatrixScalefEXT)(mode, x, y, z);
}

extern void* __blue_glCore_glMatrixScaledEXT;
void APIENTRY bluegl_glMatrixScaledEXT (GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glMatrixScaledEXT) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glMatrixScaledEXT)__blue_glCore_glMatrixScaledEXT)(mode, x, y, z);
}

extern void* __blue_glCore_glMatrixTranslatefEXT;
void APIENTRY bluegl_glMatrixTranslatefEXT (GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glMatrixTranslatefEXT) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glMatrixTranslatefEXT)__blue_glCore_glMatrixTranslatefEXT)(mode, x, y, z);
}

extern void* __blue_glCore_glMatrixTranslatedEXT;
void APIENTRY bluegl_glMatrixTranslatedEXT (GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glMatrixTranslatedEXT) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glMatrixTranslatedEXT)__blue_glCore_glMatrixTranslatedEXT)(mode, x, y, z);
}

extern void* __blue_glCore_glMatrixFrustumEXT;
void APIENTRY bluegl_glMatrixFrustumEXT (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    typedef void (APIENTRYP PFN_glMatrixFrustumEXT) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    return ((PFN_glMatrixFrustumEXT)__blue_glCore_glMatrixFrustumEXT)(mode, left, right, bottom, top, zNear, zFar);
}

extern void* __blue_glCore_glMatrixOrthoEXT;
void APIENTRY bluegl_glMatrixOrthoEXT (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    typedef void (APIENTRYP PFN_glMatrixOrthoEXT) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
    return ((PFN_glMatrixOrthoEXT)__blue_glCore_glMatrixOrthoEXT)(mode, left, right, bottom, top, zNear, zFar);
}

extern void* __blue_glCore_glMatrixPopEXT;
void APIENTRY bluegl_glMatrixPopEXT (GLenum mode) {
    typedef void (APIENTRYP PFN_glMatrixPopEXT) (GLenum mode);
    return ((PFN_glMatrixPopEXT)__blue_glCore_glMatrixPopEXT)(mode);
}

extern void* __blue_glCore_glMatrixPushEXT;
void APIENTRY bluegl_glMatrixPushEXT (GLenum mode) {
    typedef void (APIENTRYP PFN_glMatrixPushEXT) (GLenum mode);
    return ((PFN_glMatrixPushEXT)__blue_glCore_glMatrixPushEXT)(mode);
}

extern void* __blue_glCore_glClientAttribDefaultEXT;
void APIENTRY bluegl_glClientAttribDefaultEXT (GLbitfield mask) {
    typedef void (APIENTRYP PFN_glClientAttribDefaultEXT) (GLbitfield mask);
    return ((PFN_glClientAttribDefaultEXT)__blue_glCore_glClientAttribDefaultEXT)(mask);
}

extern void* __blue_glCore_glPushClientAttribDefaultEXT;
void APIENTRY bluegl_glPushClientAttribDefaultEXT (GLbitfield mask) {
    typedef void (APIENTRYP PFN_glPushClientAttribDefaultEXT) (GLbitfield mask);
    return ((PFN_glPushClientAttribDefaultEXT)__blue_glCore_glPushClientAttribDefaultEXT)(mask);
}

extern void* __blue_glCore_glTextureParameterfEXT;
void APIENTRY bluegl_glTextureParameterfEXT (GLuint texture, GLenum target, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glTextureParameterfEXT) (GLuint texture, GLenum target, GLenum pname, GLfloat param);
    return ((PFN_glTextureParameterfEXT)__blue_glCore_glTextureParameterfEXT)(texture, target, pname, param);
}

extern void* __blue_glCore_glTextureParameterfvEXT;
void APIENTRY bluegl_glTextureParameterfvEXT (GLuint texture, GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glTextureParameterfvEXT) (GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glTextureParameterfvEXT)__blue_glCore_glTextureParameterfvEXT)(texture, target, pname, params);
}

extern void* __blue_glCore_glTextureParameteriEXT;
void APIENTRY bluegl_glTextureParameteriEXT (GLuint texture, GLenum target, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glTextureParameteriEXT) (GLuint texture, GLenum target, GLenum pname, GLint param);
    return ((PFN_glTextureParameteriEXT)__blue_glCore_glTextureParameteriEXT)(texture, target, pname, param);
}

extern void* __blue_glCore_glTextureParameterivEXT;
void APIENTRY bluegl_glTextureParameterivEXT (GLuint texture, GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glTextureParameterivEXT) (GLuint texture, GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glTextureParameterivEXT)__blue_glCore_glTextureParameterivEXT)(texture, target, pname, params);
}

extern void* __blue_glCore_glTextureImage1DEXT;
void APIENTRY bluegl_glTextureImage1DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTextureImage1DEXT) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTextureImage1DEXT)__blue_glCore_glTextureImage1DEXT)(texture, target, level, internalformat, width, border, format, type, pixels);
}

extern void* __blue_glCore_glTextureImage2DEXT;
void APIENTRY bluegl_glTextureImage2DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTextureImage2DEXT) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTextureImage2DEXT)__blue_glCore_glTextureImage2DEXT)(texture, target, level, internalformat, width, height, border, format, type, pixels);
}

extern void* __blue_glCore_glTextureSubImage1DEXT;
void APIENTRY bluegl_glTextureSubImage1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTextureSubImage1DEXT) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTextureSubImage1DEXT)__blue_glCore_glTextureSubImage1DEXT)(texture, target, level, xoffset, width, format, type, pixels);
}

extern void* __blue_glCore_glTextureSubImage2DEXT;
void APIENTRY bluegl_glTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTextureSubImage2DEXT) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTextureSubImage2DEXT)__blue_glCore_glTextureSubImage2DEXT)(texture, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

extern void* __blue_glCore_glCopyTextureImage1DEXT;
void APIENTRY bluegl_glCopyTextureImage1DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    typedef void (APIENTRYP PFN_glCopyTextureImage1DEXT) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    return ((PFN_glCopyTextureImage1DEXT)__blue_glCore_glCopyTextureImage1DEXT)(texture, target, level, internalformat, x, y, width, border);
}

extern void* __blue_glCore_glCopyTextureImage2DEXT;
void APIENTRY bluegl_glCopyTextureImage2DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    typedef void (APIENTRYP PFN_glCopyTextureImage2DEXT) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    return ((PFN_glCopyTextureImage2DEXT)__blue_glCore_glCopyTextureImage2DEXT)(texture, target, level, internalformat, x, y, width, height, border);
}

extern void* __blue_glCore_glCopyTextureSubImage1DEXT;
void APIENTRY bluegl_glCopyTextureSubImage1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyTextureSubImage1DEXT) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyTextureSubImage1DEXT)__blue_glCore_glCopyTextureSubImage1DEXT)(texture, target, level, xoffset, x, y, width);
}

extern void* __blue_glCore_glCopyTextureSubImage2DEXT;
void APIENTRY bluegl_glCopyTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyTextureSubImage2DEXT) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyTextureSubImage2DEXT)__blue_glCore_glCopyTextureSubImage2DEXT)(texture, target, level, xoffset, yoffset, x, y, width, height);
}

extern void* __blue_glCore_glGetTextureImageEXT;
void APIENTRY bluegl_glGetTextureImageEXT (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels) {
    typedef void (APIENTRYP PFN_glGetTextureImageEXT) (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
    return ((PFN_glGetTextureImageEXT)__blue_glCore_glGetTextureImageEXT)(texture, target, level, format, type, pixels);
}

extern void* __blue_glCore_glGetTextureParameterfvEXT;
void APIENTRY bluegl_glGetTextureParameterfvEXT (GLuint texture, GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetTextureParameterfvEXT) (GLuint texture, GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetTextureParameterfvEXT)__blue_glCore_glGetTextureParameterfvEXT)(texture, target, pname, params);
}

extern void* __blue_glCore_glGetTextureParameterivEXT;
void APIENTRY bluegl_glGetTextureParameterivEXT (GLuint texture, GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTextureParameterivEXT) (GLuint texture, GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetTextureParameterivEXT)__blue_glCore_glGetTextureParameterivEXT)(texture, target, pname, params);
}

extern void* __blue_glCore_glGetTextureLevelParameterfvEXT;
void APIENTRY bluegl_glGetTextureLevelParameterfvEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetTextureLevelParameterfvEXT) (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
    return ((PFN_glGetTextureLevelParameterfvEXT)__blue_glCore_glGetTextureLevelParameterfvEXT)(texture, target, level, pname, params);
}

extern void* __blue_glCore_glGetTextureLevelParameterivEXT;
void APIENTRY bluegl_glGetTextureLevelParameterivEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTextureLevelParameterivEXT) (GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
    return ((PFN_glGetTextureLevelParameterivEXT)__blue_glCore_glGetTextureLevelParameterivEXT)(texture, target, level, pname, params);
}

extern void* __blue_glCore_glTextureImage3DEXT;
void APIENTRY bluegl_glTextureImage3DEXT (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTextureImage3DEXT) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTextureImage3DEXT)__blue_glCore_glTextureImage3DEXT)(texture, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

extern void* __blue_glCore_glTextureSubImage3DEXT;
void APIENTRY bluegl_glTextureSubImage3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTextureSubImage3DEXT) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTextureSubImage3DEXT)__blue_glCore_glTextureSubImage3DEXT)(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

extern void* __blue_glCore_glCopyTextureSubImage3DEXT;
void APIENTRY bluegl_glCopyTextureSubImage3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyTextureSubImage3DEXT) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyTextureSubImage3DEXT)__blue_glCore_glCopyTextureSubImage3DEXT)(texture, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

extern void* __blue_glCore_glBindMultiTextureEXT;
void APIENTRY bluegl_glBindMultiTextureEXT (GLenum texunit, GLenum target, GLuint texture) {
    typedef void (APIENTRYP PFN_glBindMultiTextureEXT) (GLenum texunit, GLenum target, GLuint texture);
    return ((PFN_glBindMultiTextureEXT)__blue_glCore_glBindMultiTextureEXT)(texunit, target, texture);
}

extern void* __blue_glCore_glMultiTexCoordPointerEXT;
void APIENTRY bluegl_glMultiTexCoordPointerEXT (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glMultiTexCoordPointerEXT) (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glMultiTexCoordPointerEXT)__blue_glCore_glMultiTexCoordPointerEXT)(texunit, size, type, stride, pointer);
}

extern void* __blue_glCore_glMultiTexEnvfEXT;
void APIENTRY bluegl_glMultiTexEnvfEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glMultiTexEnvfEXT) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
    return ((PFN_glMultiTexEnvfEXT)__blue_glCore_glMultiTexEnvfEXT)(texunit, target, pname, param);
}

extern void* __blue_glCore_glMultiTexEnvfvEXT;
void APIENTRY bluegl_glMultiTexEnvfvEXT (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glMultiTexEnvfvEXT) (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glMultiTexEnvfvEXT)__blue_glCore_glMultiTexEnvfvEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glMultiTexEnviEXT;
void APIENTRY bluegl_glMultiTexEnviEXT (GLenum texunit, GLenum target, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glMultiTexEnviEXT) (GLenum texunit, GLenum target, GLenum pname, GLint param);
    return ((PFN_glMultiTexEnviEXT)__blue_glCore_glMultiTexEnviEXT)(texunit, target, pname, param);
}

extern void* __blue_glCore_glMultiTexEnvivEXT;
void APIENTRY bluegl_glMultiTexEnvivEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glMultiTexEnvivEXT) (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glMultiTexEnvivEXT)__blue_glCore_glMultiTexEnvivEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glMultiTexGendEXT;
void APIENTRY bluegl_glMultiTexGendEXT (GLenum texunit, GLenum coord, GLenum pname, GLdouble param) {
    typedef void (APIENTRYP PFN_glMultiTexGendEXT) (GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
    return ((PFN_glMultiTexGendEXT)__blue_glCore_glMultiTexGendEXT)(texunit, coord, pname, param);
}

extern void* __blue_glCore_glMultiTexGendvEXT;
void APIENTRY bluegl_glMultiTexGendvEXT (GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params) {
    typedef void (APIENTRYP PFN_glMultiTexGendvEXT) (GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
    return ((PFN_glMultiTexGendvEXT)__blue_glCore_glMultiTexGendvEXT)(texunit, coord, pname, params);
}

extern void* __blue_glCore_glMultiTexGenfEXT;
void APIENTRY bluegl_glMultiTexGenfEXT (GLenum texunit, GLenum coord, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glMultiTexGenfEXT) (GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
    return ((PFN_glMultiTexGenfEXT)__blue_glCore_glMultiTexGenfEXT)(texunit, coord, pname, param);
}

extern void* __blue_glCore_glMultiTexGenfvEXT;
void APIENTRY bluegl_glMultiTexGenfvEXT (GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glMultiTexGenfvEXT) (GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
    return ((PFN_glMultiTexGenfvEXT)__blue_glCore_glMultiTexGenfvEXT)(texunit, coord, pname, params);
}

extern void* __blue_glCore_glMultiTexGeniEXT;
void APIENTRY bluegl_glMultiTexGeniEXT (GLenum texunit, GLenum coord, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glMultiTexGeniEXT) (GLenum texunit, GLenum coord, GLenum pname, GLint param);
    return ((PFN_glMultiTexGeniEXT)__blue_glCore_glMultiTexGeniEXT)(texunit, coord, pname, param);
}

extern void* __blue_glCore_glMultiTexGenivEXT;
void APIENTRY bluegl_glMultiTexGenivEXT (GLenum texunit, GLenum coord, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glMultiTexGenivEXT) (GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
    return ((PFN_glMultiTexGenivEXT)__blue_glCore_glMultiTexGenivEXT)(texunit, coord, pname, params);
}

extern void* __blue_glCore_glGetMultiTexEnvfvEXT;
void APIENTRY bluegl_glGetMultiTexEnvfvEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexEnvfvEXT) (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetMultiTexEnvfvEXT)__blue_glCore_glGetMultiTexEnvfvEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glGetMultiTexEnvivEXT;
void APIENTRY bluegl_glGetMultiTexEnvivEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexEnvivEXT) (GLenum texunit, GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetMultiTexEnvivEXT)__blue_glCore_glGetMultiTexEnvivEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glGetMultiTexGendvEXT;
void APIENTRY bluegl_glGetMultiTexGendvEXT (GLenum texunit, GLenum coord, GLenum pname, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexGendvEXT) (GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
    return ((PFN_glGetMultiTexGendvEXT)__blue_glCore_glGetMultiTexGendvEXT)(texunit, coord, pname, params);
}

extern void* __blue_glCore_glGetMultiTexGenfvEXT;
void APIENTRY bluegl_glGetMultiTexGenfvEXT (GLenum texunit, GLenum coord, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexGenfvEXT) (GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
    return ((PFN_glGetMultiTexGenfvEXT)__blue_glCore_glGetMultiTexGenfvEXT)(texunit, coord, pname, params);
}

extern void* __blue_glCore_glGetMultiTexGenivEXT;
void APIENTRY bluegl_glGetMultiTexGenivEXT (GLenum texunit, GLenum coord, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexGenivEXT) (GLenum texunit, GLenum coord, GLenum pname, GLint *params);
    return ((PFN_glGetMultiTexGenivEXT)__blue_glCore_glGetMultiTexGenivEXT)(texunit, coord, pname, params);
}

extern void* __blue_glCore_glMultiTexParameteriEXT;
void APIENTRY bluegl_glMultiTexParameteriEXT (GLenum texunit, GLenum target, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glMultiTexParameteriEXT) (GLenum texunit, GLenum target, GLenum pname, GLint param);
    return ((PFN_glMultiTexParameteriEXT)__blue_glCore_glMultiTexParameteriEXT)(texunit, target, pname, param);
}

extern void* __blue_glCore_glMultiTexParameterivEXT;
void APIENTRY bluegl_glMultiTexParameterivEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glMultiTexParameterivEXT) (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glMultiTexParameterivEXT)__blue_glCore_glMultiTexParameterivEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glMultiTexParameterfEXT;
void APIENTRY bluegl_glMultiTexParameterfEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glMultiTexParameterfEXT) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
    return ((PFN_glMultiTexParameterfEXT)__blue_glCore_glMultiTexParameterfEXT)(texunit, target, pname, param);
}

extern void* __blue_glCore_glMultiTexParameterfvEXT;
void APIENTRY bluegl_glMultiTexParameterfvEXT (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glMultiTexParameterfvEXT) (GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glMultiTexParameterfvEXT)__blue_glCore_glMultiTexParameterfvEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glMultiTexImage1DEXT;
void APIENTRY bluegl_glMultiTexImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glMultiTexImage1DEXT) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glMultiTexImage1DEXT)__blue_glCore_glMultiTexImage1DEXT)(texunit, target, level, internalformat, width, border, format, type, pixels);
}

extern void* __blue_glCore_glMultiTexImage2DEXT;
void APIENTRY bluegl_glMultiTexImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glMultiTexImage2DEXT) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glMultiTexImage2DEXT)__blue_glCore_glMultiTexImage2DEXT)(texunit, target, level, internalformat, width, height, border, format, type, pixels);
}

extern void* __blue_glCore_glMultiTexSubImage1DEXT;
void APIENTRY bluegl_glMultiTexSubImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glMultiTexSubImage1DEXT) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glMultiTexSubImage1DEXT)__blue_glCore_glMultiTexSubImage1DEXT)(texunit, target, level, xoffset, width, format, type, pixels);
}

extern void* __blue_glCore_glMultiTexSubImage2DEXT;
void APIENTRY bluegl_glMultiTexSubImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glMultiTexSubImage2DEXT) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glMultiTexSubImage2DEXT)__blue_glCore_glMultiTexSubImage2DEXT)(texunit, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

extern void* __blue_glCore_glCopyMultiTexImage1DEXT;
void APIENTRY bluegl_glCopyMultiTexImage1DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    typedef void (APIENTRYP PFN_glCopyMultiTexImage1DEXT) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
    return ((PFN_glCopyMultiTexImage1DEXT)__blue_glCore_glCopyMultiTexImage1DEXT)(texunit, target, level, internalformat, x, y, width, border);
}

extern void* __blue_glCore_glCopyMultiTexImage2DEXT;
void APIENTRY bluegl_glCopyMultiTexImage2DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    typedef void (APIENTRYP PFN_glCopyMultiTexImage2DEXT) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    return ((PFN_glCopyMultiTexImage2DEXT)__blue_glCore_glCopyMultiTexImage2DEXT)(texunit, target, level, internalformat, x, y, width, height, border);
}

extern void* __blue_glCore_glCopyMultiTexSubImage1DEXT;
void APIENTRY bluegl_glCopyMultiTexSubImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyMultiTexSubImage1DEXT) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyMultiTexSubImage1DEXT)__blue_glCore_glCopyMultiTexSubImage1DEXT)(texunit, target, level, xoffset, x, y, width);
}

extern void* __blue_glCore_glCopyMultiTexSubImage2DEXT;
void APIENTRY bluegl_glCopyMultiTexSubImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyMultiTexSubImage2DEXT) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyMultiTexSubImage2DEXT)__blue_glCore_glCopyMultiTexSubImage2DEXT)(texunit, target, level, xoffset, yoffset, x, y, width, height);
}

extern void* __blue_glCore_glGetMultiTexImageEXT;
void APIENTRY bluegl_glGetMultiTexImageEXT (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels) {
    typedef void (APIENTRYP PFN_glGetMultiTexImageEXT) (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
    return ((PFN_glGetMultiTexImageEXT)__blue_glCore_glGetMultiTexImageEXT)(texunit, target, level, format, type, pixels);
}

extern void* __blue_glCore_glGetMultiTexParameterfvEXT;
void APIENTRY bluegl_glGetMultiTexParameterfvEXT (GLenum texunit, GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexParameterfvEXT) (GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetMultiTexParameterfvEXT)__blue_glCore_glGetMultiTexParameterfvEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glGetMultiTexParameterivEXT;
void APIENTRY bluegl_glGetMultiTexParameterivEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexParameterivEXT) (GLenum texunit, GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetMultiTexParameterivEXT)__blue_glCore_glGetMultiTexParameterivEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glGetMultiTexLevelParameterfvEXT;
void APIENTRY bluegl_glGetMultiTexLevelParameterfvEXT (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexLevelParameterfvEXT) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
    return ((PFN_glGetMultiTexLevelParameterfvEXT)__blue_glCore_glGetMultiTexLevelParameterfvEXT)(texunit, target, level, pname, params);
}

extern void* __blue_glCore_glGetMultiTexLevelParameterivEXT;
void APIENTRY bluegl_glGetMultiTexLevelParameterivEXT (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexLevelParameterivEXT) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
    return ((PFN_glGetMultiTexLevelParameterivEXT)__blue_glCore_glGetMultiTexLevelParameterivEXT)(texunit, target, level, pname, params);
}

extern void* __blue_glCore_glMultiTexImage3DEXT;
void APIENTRY bluegl_glMultiTexImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glMultiTexImage3DEXT) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glMultiTexImage3DEXT)__blue_glCore_glMultiTexImage3DEXT)(texunit, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

extern void* __blue_glCore_glMultiTexSubImage3DEXT;
void APIENTRY bluegl_glMultiTexSubImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glMultiTexSubImage3DEXT) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glMultiTexSubImage3DEXT)__blue_glCore_glMultiTexSubImage3DEXT)(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

extern void* __blue_glCore_glCopyMultiTexSubImage3DEXT;
void APIENTRY bluegl_glCopyMultiTexSubImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glCopyMultiTexSubImage3DEXT) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    return ((PFN_glCopyMultiTexSubImage3DEXT)__blue_glCore_glCopyMultiTexSubImage3DEXT)(texunit, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

extern void* __blue_glCore_glEnableClientStateIndexedEXT;
void APIENTRY bluegl_glEnableClientStateIndexedEXT (GLenum array, GLuint index) {
    typedef void (APIENTRYP PFN_glEnableClientStateIndexedEXT) (GLenum array, GLuint index);
    return ((PFN_glEnableClientStateIndexedEXT)__blue_glCore_glEnableClientStateIndexedEXT)(array, index);
}

extern void* __blue_glCore_glDisableClientStateIndexedEXT;
void APIENTRY bluegl_glDisableClientStateIndexedEXT (GLenum array, GLuint index) {
    typedef void (APIENTRYP PFN_glDisableClientStateIndexedEXT) (GLenum array, GLuint index);
    return ((PFN_glDisableClientStateIndexedEXT)__blue_glCore_glDisableClientStateIndexedEXT)(array, index);
}

extern void* __blue_glCore_glGetFloatIndexedvEXT;
void APIENTRY bluegl_glGetFloatIndexedvEXT (GLenum target, GLuint index, GLfloat *data) {
    typedef void (APIENTRYP PFN_glGetFloatIndexedvEXT) (GLenum target, GLuint index, GLfloat *data);
    return ((PFN_glGetFloatIndexedvEXT)__blue_glCore_glGetFloatIndexedvEXT)(target, index, data);
}

extern void* __blue_glCore_glGetDoubleIndexedvEXT;
void APIENTRY bluegl_glGetDoubleIndexedvEXT (GLenum target, GLuint index, GLdouble *data) {
    typedef void (APIENTRYP PFN_glGetDoubleIndexedvEXT) (GLenum target, GLuint index, GLdouble *data);
    return ((PFN_glGetDoubleIndexedvEXT)__blue_glCore_glGetDoubleIndexedvEXT)(target, index, data);
}

extern void* __blue_glCore_glGetPointerIndexedvEXT;
void APIENTRY bluegl_glGetPointerIndexedvEXT (GLenum target, GLuint index, void **data) {
    typedef void (APIENTRYP PFN_glGetPointerIndexedvEXT) (GLenum target, GLuint index, void **data);
    return ((PFN_glGetPointerIndexedvEXT)__blue_glCore_glGetPointerIndexedvEXT)(target, index, data);
}

extern void* __blue_glCore_glEnableIndexedEXT;
void APIENTRY bluegl_glEnableIndexedEXT (GLenum target, GLuint index) {
    typedef void (APIENTRYP PFN_glEnableIndexedEXT) (GLenum target, GLuint index);
    return ((PFN_glEnableIndexedEXT)__blue_glCore_glEnableIndexedEXT)(target, index);
}

extern void* __blue_glCore_glDisableIndexedEXT;
void APIENTRY bluegl_glDisableIndexedEXT (GLenum target, GLuint index) {
    typedef void (APIENTRYP PFN_glDisableIndexedEXT) (GLenum target, GLuint index);
    return ((PFN_glDisableIndexedEXT)__blue_glCore_glDisableIndexedEXT)(target, index);
}

extern void* __blue_glCore_glIsEnabledIndexedEXT;
GLboolean APIENTRY bluegl_glIsEnabledIndexedEXT (GLenum target, GLuint index) {
    typedef GLboolean (APIENTRYP PFN_glIsEnabledIndexedEXT) (GLenum target, GLuint index);
    return ((PFN_glIsEnabledIndexedEXT)__blue_glCore_glIsEnabledIndexedEXT)(target, index);
}

extern void* __blue_glCore_glGetIntegerIndexedvEXT;
void APIENTRY bluegl_glGetIntegerIndexedvEXT (GLenum target, GLuint index, GLint *data) {
    typedef void (APIENTRYP PFN_glGetIntegerIndexedvEXT) (GLenum target, GLuint index, GLint *data);
    return ((PFN_glGetIntegerIndexedvEXT)__blue_glCore_glGetIntegerIndexedvEXT)(target, index, data);
}

extern void* __blue_glCore_glGetBooleanIndexedvEXT;
void APIENTRY bluegl_glGetBooleanIndexedvEXT (GLenum target, GLuint index, GLboolean *data) {
    typedef void (APIENTRYP PFN_glGetBooleanIndexedvEXT) (GLenum target, GLuint index, GLboolean *data);
    return ((PFN_glGetBooleanIndexedvEXT)__blue_glCore_glGetBooleanIndexedvEXT)(target, index, data);
}

extern void* __blue_glCore_glCompressedTextureImage3DEXT;
void APIENTRY bluegl_glCompressedTextureImage3DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedTextureImage3DEXT) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedTextureImage3DEXT)__blue_glCore_glCompressedTextureImage3DEXT)(texture, target, level, internalformat, width, height, depth, border, imageSize, bits);
}

extern void* __blue_glCore_glCompressedTextureImage2DEXT;
void APIENTRY bluegl_glCompressedTextureImage2DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedTextureImage2DEXT) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedTextureImage2DEXT)__blue_glCore_glCompressedTextureImage2DEXT)(texture, target, level, internalformat, width, height, border, imageSize, bits);
}

extern void* __blue_glCore_glCompressedTextureImage1DEXT;
void APIENTRY bluegl_glCompressedTextureImage1DEXT (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedTextureImage1DEXT) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedTextureImage1DEXT)__blue_glCore_glCompressedTextureImage1DEXT)(texture, target, level, internalformat, width, border, imageSize, bits);
}

extern void* __blue_glCore_glCompressedTextureSubImage3DEXT;
void APIENTRY bluegl_glCompressedTextureSubImage3DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedTextureSubImage3DEXT) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedTextureSubImage3DEXT)__blue_glCore_glCompressedTextureSubImage3DEXT)(texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}

extern void* __blue_glCore_glCompressedTextureSubImage2DEXT;
void APIENTRY bluegl_glCompressedTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedTextureSubImage2DEXT) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedTextureSubImage2DEXT)__blue_glCore_glCompressedTextureSubImage2DEXT)(texture, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}

extern void* __blue_glCore_glCompressedTextureSubImage1DEXT;
void APIENTRY bluegl_glCompressedTextureSubImage1DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedTextureSubImage1DEXT) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedTextureSubImage1DEXT)__blue_glCore_glCompressedTextureSubImage1DEXT)(texture, target, level, xoffset, width, format, imageSize, bits);
}

extern void* __blue_glCore_glGetCompressedTextureImageEXT;
void APIENTRY bluegl_glGetCompressedTextureImageEXT (GLuint texture, GLenum target, GLint lod, void *img) {
    typedef void (APIENTRYP PFN_glGetCompressedTextureImageEXT) (GLuint texture, GLenum target, GLint lod, void *img);
    return ((PFN_glGetCompressedTextureImageEXT)__blue_glCore_glGetCompressedTextureImageEXT)(texture, target, lod, img);
}

extern void* __blue_glCore_glCompressedMultiTexImage3DEXT;
void APIENTRY bluegl_glCompressedMultiTexImage3DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedMultiTexImage3DEXT) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedMultiTexImage3DEXT)__blue_glCore_glCompressedMultiTexImage3DEXT)(texunit, target, level, internalformat, width, height, depth, border, imageSize, bits);
}

extern void* __blue_glCore_glCompressedMultiTexImage2DEXT;
void APIENTRY bluegl_glCompressedMultiTexImage2DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedMultiTexImage2DEXT) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedMultiTexImage2DEXT)__blue_glCore_glCompressedMultiTexImage2DEXT)(texunit, target, level, internalformat, width, height, border, imageSize, bits);
}

extern void* __blue_glCore_glCompressedMultiTexImage1DEXT;
void APIENTRY bluegl_glCompressedMultiTexImage1DEXT (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedMultiTexImage1DEXT) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedMultiTexImage1DEXT)__blue_glCore_glCompressedMultiTexImage1DEXT)(texunit, target, level, internalformat, width, border, imageSize, bits);
}

extern void* __blue_glCore_glCompressedMultiTexSubImage3DEXT;
void APIENTRY bluegl_glCompressedMultiTexSubImage3DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedMultiTexSubImage3DEXT) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedMultiTexSubImage3DEXT)__blue_glCore_glCompressedMultiTexSubImage3DEXT)(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits);
}

extern void* __blue_glCore_glCompressedMultiTexSubImage2DEXT;
void APIENTRY bluegl_glCompressedMultiTexSubImage2DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedMultiTexSubImage2DEXT) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedMultiTexSubImage2DEXT)__blue_glCore_glCompressedMultiTexSubImage2DEXT)(texunit, target, level, xoffset, yoffset, width, height, format, imageSize, bits);
}

extern void* __blue_glCore_glCompressedMultiTexSubImage1DEXT;
void APIENTRY bluegl_glCompressedMultiTexSubImage1DEXT (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits) {
    typedef void (APIENTRYP PFN_glCompressedMultiTexSubImage1DEXT) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
    return ((PFN_glCompressedMultiTexSubImage1DEXT)__blue_glCore_glCompressedMultiTexSubImage1DEXT)(texunit, target, level, xoffset, width, format, imageSize, bits);
}

extern void* __blue_glCore_glGetCompressedMultiTexImageEXT;
void APIENTRY bluegl_glGetCompressedMultiTexImageEXT (GLenum texunit, GLenum target, GLint lod, void *img) {
    typedef void (APIENTRYP PFN_glGetCompressedMultiTexImageEXT) (GLenum texunit, GLenum target, GLint lod, void *img);
    return ((PFN_glGetCompressedMultiTexImageEXT)__blue_glCore_glGetCompressedMultiTexImageEXT)(texunit, target, lod, img);
}

extern void* __blue_glCore_glMatrixLoadTransposefEXT;
void APIENTRY bluegl_glMatrixLoadTransposefEXT (GLenum mode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixLoadTransposefEXT) (GLenum mode, const GLfloat *m);
    return ((PFN_glMatrixLoadTransposefEXT)__blue_glCore_glMatrixLoadTransposefEXT)(mode, m);
}

extern void* __blue_glCore_glMatrixLoadTransposedEXT;
void APIENTRY bluegl_glMatrixLoadTransposedEXT (GLenum mode, const GLdouble *m) {
    typedef void (APIENTRYP PFN_glMatrixLoadTransposedEXT) (GLenum mode, const GLdouble *m);
    return ((PFN_glMatrixLoadTransposedEXT)__blue_glCore_glMatrixLoadTransposedEXT)(mode, m);
}

extern void* __blue_glCore_glMatrixMultTransposefEXT;
void APIENTRY bluegl_glMatrixMultTransposefEXT (GLenum mode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixMultTransposefEXT) (GLenum mode, const GLfloat *m);
    return ((PFN_glMatrixMultTransposefEXT)__blue_glCore_glMatrixMultTransposefEXT)(mode, m);
}

extern void* __blue_glCore_glMatrixMultTransposedEXT;
void APIENTRY bluegl_glMatrixMultTransposedEXT (GLenum mode, const GLdouble *m) {
    typedef void (APIENTRYP PFN_glMatrixMultTransposedEXT) (GLenum mode, const GLdouble *m);
    return ((PFN_glMatrixMultTransposedEXT)__blue_glCore_glMatrixMultTransposedEXT)(mode, m);
}

extern void* __blue_glCore_glNamedBufferDataEXT;
void APIENTRY bluegl_glNamedBufferDataEXT (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) {
    typedef void (APIENTRYP PFN_glNamedBufferDataEXT) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
    return ((PFN_glNamedBufferDataEXT)__blue_glCore_glNamedBufferDataEXT)(buffer, size, data, usage);
}

extern void* __blue_glCore_glNamedBufferSubDataEXT;
void APIENTRY bluegl_glNamedBufferSubDataEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) {
    typedef void (APIENTRYP PFN_glNamedBufferSubDataEXT) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
    return ((PFN_glNamedBufferSubDataEXT)__blue_glCore_glNamedBufferSubDataEXT)(buffer, offset, size, data);
}

extern void* __blue_glCore_glMapNamedBufferEXT;
void *APIENTRY bluegl_glMapNamedBufferEXT (GLuint buffer, GLenum access) {
    typedef void *(APIENTRYP PFN_glMapNamedBufferEXT) (GLuint buffer, GLenum access);
    return ((PFN_glMapNamedBufferEXT)__blue_glCore_glMapNamedBufferEXT)(buffer, access);
}

extern void* __blue_glCore_glUnmapNamedBufferEXT;
GLboolean APIENTRY bluegl_glUnmapNamedBufferEXT (GLuint buffer) {
    typedef GLboolean (APIENTRYP PFN_glUnmapNamedBufferEXT) (GLuint buffer);
    return ((PFN_glUnmapNamedBufferEXT)__blue_glCore_glUnmapNamedBufferEXT)(buffer);
}

extern void* __blue_glCore_glGetNamedBufferParameterivEXT;
void APIENTRY bluegl_glGetNamedBufferParameterivEXT (GLuint buffer, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedBufferParameterivEXT) (GLuint buffer, GLenum pname, GLint *params);
    return ((PFN_glGetNamedBufferParameterivEXT)__blue_glCore_glGetNamedBufferParameterivEXT)(buffer, pname, params);
}

extern void* __blue_glCore_glGetNamedBufferPointervEXT;
void APIENTRY bluegl_glGetNamedBufferPointervEXT (GLuint buffer, GLenum pname, void **params) {
    typedef void (APIENTRYP PFN_glGetNamedBufferPointervEXT) (GLuint buffer, GLenum pname, void **params);
    return ((PFN_glGetNamedBufferPointervEXT)__blue_glCore_glGetNamedBufferPointervEXT)(buffer, pname, params);
}

extern void* __blue_glCore_glGetNamedBufferSubDataEXT;
void APIENTRY bluegl_glGetNamedBufferSubDataEXT (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) {
    typedef void (APIENTRYP PFN_glGetNamedBufferSubDataEXT) (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
    return ((PFN_glGetNamedBufferSubDataEXT)__blue_glCore_glGetNamedBufferSubDataEXT)(buffer, offset, size, data);
}

extern void* __blue_glCore_glProgramUniform1fEXT;
void APIENTRY bluegl_glProgramUniform1fEXT (GLuint program, GLint location, GLfloat v0) {
    typedef void (APIENTRYP PFN_glProgramUniform1fEXT) (GLuint program, GLint location, GLfloat v0);
    return ((PFN_glProgramUniform1fEXT)__blue_glCore_glProgramUniform1fEXT)(program, location, v0);
}

extern void* __blue_glCore_glProgramUniform2fEXT;
void APIENTRY bluegl_glProgramUniform2fEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1) {
    typedef void (APIENTRYP PFN_glProgramUniform2fEXT) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
    return ((PFN_glProgramUniform2fEXT)__blue_glCore_glProgramUniform2fEXT)(program, location, v0, v1);
}

extern void* __blue_glCore_glProgramUniform3fEXT;
void APIENTRY bluegl_glProgramUniform3fEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    typedef void (APIENTRYP PFN_glProgramUniform3fEXT) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    return ((PFN_glProgramUniform3fEXT)__blue_glCore_glProgramUniform3fEXT)(program, location, v0, v1, v2);
}

extern void* __blue_glCore_glProgramUniform4fEXT;
void APIENTRY bluegl_glProgramUniform4fEXT (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    typedef void (APIENTRYP PFN_glProgramUniform4fEXT) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    return ((PFN_glProgramUniform4fEXT)__blue_glCore_glProgramUniform4fEXT)(program, location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glProgramUniform1iEXT;
void APIENTRY bluegl_glProgramUniform1iEXT (GLuint program, GLint location, GLint v0) {
    typedef void (APIENTRYP PFN_glProgramUniform1iEXT) (GLuint program, GLint location, GLint v0);
    return ((PFN_glProgramUniform1iEXT)__blue_glCore_glProgramUniform1iEXT)(program, location, v0);
}

extern void* __blue_glCore_glProgramUniform2iEXT;
void APIENTRY bluegl_glProgramUniform2iEXT (GLuint program, GLint location, GLint v0, GLint v1) {
    typedef void (APIENTRYP PFN_glProgramUniform2iEXT) (GLuint program, GLint location, GLint v0, GLint v1);
    return ((PFN_glProgramUniform2iEXT)__blue_glCore_glProgramUniform2iEXT)(program, location, v0, v1);
}

extern void* __blue_glCore_glProgramUniform3iEXT;
void APIENTRY bluegl_glProgramUniform3iEXT (GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
    typedef void (APIENTRYP PFN_glProgramUniform3iEXT) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
    return ((PFN_glProgramUniform3iEXT)__blue_glCore_glProgramUniform3iEXT)(program, location, v0, v1, v2);
}

extern void* __blue_glCore_glProgramUniform4iEXT;
void APIENTRY bluegl_glProgramUniform4iEXT (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    typedef void (APIENTRYP PFN_glProgramUniform4iEXT) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    return ((PFN_glProgramUniform4iEXT)__blue_glCore_glProgramUniform4iEXT)(program, location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glProgramUniform1fvEXT;
void APIENTRY bluegl_glProgramUniform1fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1fvEXT) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glProgramUniform1fvEXT)__blue_glCore_glProgramUniform1fvEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2fvEXT;
void APIENTRY bluegl_glProgramUniform2fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2fvEXT) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glProgramUniform2fvEXT)__blue_glCore_glProgramUniform2fvEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3fvEXT;
void APIENTRY bluegl_glProgramUniform3fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3fvEXT) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glProgramUniform3fvEXT)__blue_glCore_glProgramUniform3fvEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4fvEXT;
void APIENTRY bluegl_glProgramUniform4fvEXT (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4fvEXT) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    return ((PFN_glProgramUniform4fvEXT)__blue_glCore_glProgramUniform4fvEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform1ivEXT;
void APIENTRY bluegl_glProgramUniform1ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1ivEXT) (GLuint program, GLint location, GLsizei count, const GLint *value);
    return ((PFN_glProgramUniform1ivEXT)__blue_glCore_glProgramUniform1ivEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2ivEXT;
void APIENTRY bluegl_glProgramUniform2ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2ivEXT) (GLuint program, GLint location, GLsizei count, const GLint *value);
    return ((PFN_glProgramUniform2ivEXT)__blue_glCore_glProgramUniform2ivEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3ivEXT;
void APIENTRY bluegl_glProgramUniform3ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3ivEXT) (GLuint program, GLint location, GLsizei count, const GLint *value);
    return ((PFN_glProgramUniform3ivEXT)__blue_glCore_glProgramUniform3ivEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4ivEXT;
void APIENTRY bluegl_glProgramUniform4ivEXT (GLuint program, GLint location, GLsizei count, const GLint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4ivEXT) (GLuint program, GLint location, GLsizei count, const GLint *value);
    return ((PFN_glProgramUniform4ivEXT)__blue_glCore_glProgramUniform4ivEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2fvEXT;
void APIENTRY bluegl_glProgramUniformMatrix2fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2fvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix2fvEXT)__blue_glCore_glProgramUniformMatrix2fvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3fvEXT;
void APIENTRY bluegl_glProgramUniformMatrix3fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3fvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix3fvEXT)__blue_glCore_glProgramUniformMatrix3fvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4fvEXT;
void APIENTRY bluegl_glProgramUniformMatrix4fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4fvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix4fvEXT)__blue_glCore_glProgramUniformMatrix4fvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2x3fvEXT;
void APIENTRY bluegl_glProgramUniformMatrix2x3fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2x3fvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix2x3fvEXT)__blue_glCore_glProgramUniformMatrix2x3fvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3x2fvEXT;
void APIENTRY bluegl_glProgramUniformMatrix3x2fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3x2fvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix3x2fvEXT)__blue_glCore_glProgramUniformMatrix3x2fvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2x4fvEXT;
void APIENTRY bluegl_glProgramUniformMatrix2x4fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2x4fvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix2x4fvEXT)__blue_glCore_glProgramUniformMatrix2x4fvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4x2fvEXT;
void APIENTRY bluegl_glProgramUniformMatrix4x2fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4x2fvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix4x2fvEXT)__blue_glCore_glProgramUniformMatrix4x2fvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3x4fvEXT;
void APIENTRY bluegl_glProgramUniformMatrix3x4fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3x4fvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix3x4fvEXT)__blue_glCore_glProgramUniformMatrix3x4fvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4x3fvEXT;
void APIENTRY bluegl_glProgramUniformMatrix4x3fvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4x3fvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    return ((PFN_glProgramUniformMatrix4x3fvEXT)__blue_glCore_glProgramUniformMatrix4x3fvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glTextureBufferEXT;
void APIENTRY bluegl_glTextureBufferEXT (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer) {
    typedef void (APIENTRYP PFN_glTextureBufferEXT) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
    return ((PFN_glTextureBufferEXT)__blue_glCore_glTextureBufferEXT)(texture, target, internalformat, buffer);
}

extern void* __blue_glCore_glMultiTexBufferEXT;
void APIENTRY bluegl_glMultiTexBufferEXT (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer) {
    typedef void (APIENTRYP PFN_glMultiTexBufferEXT) (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
    return ((PFN_glMultiTexBufferEXT)__blue_glCore_glMultiTexBufferEXT)(texunit, target, internalformat, buffer);
}

extern void* __blue_glCore_glTextureParameterIivEXT;
void APIENTRY bluegl_glTextureParameterIivEXT (GLuint texture, GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glTextureParameterIivEXT) (GLuint texture, GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glTextureParameterIivEXT)__blue_glCore_glTextureParameterIivEXT)(texture, target, pname, params);
}

extern void* __blue_glCore_glTextureParameterIuivEXT;
void APIENTRY bluegl_glTextureParameterIuivEXT (GLuint texture, GLenum target, GLenum pname, const GLuint *params) {
    typedef void (APIENTRYP PFN_glTextureParameterIuivEXT) (GLuint texture, GLenum target, GLenum pname, const GLuint *params);
    return ((PFN_glTextureParameterIuivEXT)__blue_glCore_glTextureParameterIuivEXT)(texture, target, pname, params);
}

extern void* __blue_glCore_glGetTextureParameterIivEXT;
void APIENTRY bluegl_glGetTextureParameterIivEXT (GLuint texture, GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTextureParameterIivEXT) (GLuint texture, GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetTextureParameterIivEXT)__blue_glCore_glGetTextureParameterIivEXT)(texture, target, pname, params);
}

extern void* __blue_glCore_glGetTextureParameterIuivEXT;
void APIENTRY bluegl_glGetTextureParameterIuivEXT (GLuint texture, GLenum target, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetTextureParameterIuivEXT) (GLuint texture, GLenum target, GLenum pname, GLuint *params);
    return ((PFN_glGetTextureParameterIuivEXT)__blue_glCore_glGetTextureParameterIuivEXT)(texture, target, pname, params);
}

extern void* __blue_glCore_glMultiTexParameterIivEXT;
void APIENTRY bluegl_glMultiTexParameterIivEXT (GLenum texunit, GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glMultiTexParameterIivEXT) (GLenum texunit, GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glMultiTexParameterIivEXT)__blue_glCore_glMultiTexParameterIivEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glMultiTexParameterIuivEXT;
void APIENTRY bluegl_glMultiTexParameterIuivEXT (GLenum texunit, GLenum target, GLenum pname, const GLuint *params) {
    typedef void (APIENTRYP PFN_glMultiTexParameterIuivEXT) (GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
    return ((PFN_glMultiTexParameterIuivEXT)__blue_glCore_glMultiTexParameterIuivEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glGetMultiTexParameterIivEXT;
void APIENTRY bluegl_glGetMultiTexParameterIivEXT (GLenum texunit, GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexParameterIivEXT) (GLenum texunit, GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetMultiTexParameterIivEXT)__blue_glCore_glGetMultiTexParameterIivEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glGetMultiTexParameterIuivEXT;
void APIENTRY bluegl_glGetMultiTexParameterIuivEXT (GLenum texunit, GLenum target, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetMultiTexParameterIuivEXT) (GLenum texunit, GLenum target, GLenum pname, GLuint *params);
    return ((PFN_glGetMultiTexParameterIuivEXT)__blue_glCore_glGetMultiTexParameterIuivEXT)(texunit, target, pname, params);
}

extern void* __blue_glCore_glProgramUniform1uiEXT;
void APIENTRY bluegl_glProgramUniform1uiEXT (GLuint program, GLint location, GLuint v0) {
    typedef void (APIENTRYP PFN_glProgramUniform1uiEXT) (GLuint program, GLint location, GLuint v0);
    return ((PFN_glProgramUniform1uiEXT)__blue_glCore_glProgramUniform1uiEXT)(program, location, v0);
}

extern void* __blue_glCore_glProgramUniform2uiEXT;
void APIENTRY bluegl_glProgramUniform2uiEXT (GLuint program, GLint location, GLuint v0, GLuint v1) {
    typedef void (APIENTRYP PFN_glProgramUniform2uiEXT) (GLuint program, GLint location, GLuint v0, GLuint v1);
    return ((PFN_glProgramUniform2uiEXT)__blue_glCore_glProgramUniform2uiEXT)(program, location, v0, v1);
}

extern void* __blue_glCore_glProgramUniform3uiEXT;
void APIENTRY bluegl_glProgramUniform3uiEXT (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
    typedef void (APIENTRYP PFN_glProgramUniform3uiEXT) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
    return ((PFN_glProgramUniform3uiEXT)__blue_glCore_glProgramUniform3uiEXT)(program, location, v0, v1, v2);
}

extern void* __blue_glCore_glProgramUniform4uiEXT;
void APIENTRY bluegl_glProgramUniform4uiEXT (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    typedef void (APIENTRYP PFN_glProgramUniform4uiEXT) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    return ((PFN_glProgramUniform4uiEXT)__blue_glCore_glProgramUniform4uiEXT)(program, location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glProgramUniform1uivEXT;
void APIENTRY bluegl_glProgramUniform1uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1uivEXT) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glProgramUniform1uivEXT)__blue_glCore_glProgramUniform1uivEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2uivEXT;
void APIENTRY bluegl_glProgramUniform2uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2uivEXT) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glProgramUniform2uivEXT)__blue_glCore_glProgramUniform2uivEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3uivEXT;
void APIENTRY bluegl_glProgramUniform3uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3uivEXT) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glProgramUniform3uivEXT)__blue_glCore_glProgramUniform3uivEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4uivEXT;
void APIENTRY bluegl_glProgramUniform4uivEXT (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4uivEXT) (GLuint program, GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glProgramUniform4uivEXT)__blue_glCore_glProgramUniform4uivEXT)(program, location, count, value);
}

extern void* __blue_glCore_glNamedProgramLocalParameters4fvEXT;
void APIENTRY bluegl_glNamedProgramLocalParameters4fvEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParameters4fvEXT) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
    return ((PFN_glNamedProgramLocalParameters4fvEXT)__blue_glCore_glNamedProgramLocalParameters4fvEXT)(program, target, index, count, params);
}

extern void* __blue_glCore_glNamedProgramLocalParameterI4iEXT;
void APIENTRY bluegl_glNamedProgramLocalParameterI4iEXT (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParameterI4iEXT) (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
    return ((PFN_glNamedProgramLocalParameterI4iEXT)__blue_glCore_glNamedProgramLocalParameterI4iEXT)(program, target, index, x, y, z, w);
}

extern void* __blue_glCore_glNamedProgramLocalParameterI4ivEXT;
void APIENTRY bluegl_glNamedProgramLocalParameterI4ivEXT (GLuint program, GLenum target, GLuint index, const GLint *params) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParameterI4ivEXT) (GLuint program, GLenum target, GLuint index, const GLint *params);
    return ((PFN_glNamedProgramLocalParameterI4ivEXT)__blue_glCore_glNamedProgramLocalParameterI4ivEXT)(program, target, index, params);
}

extern void* __blue_glCore_glNamedProgramLocalParametersI4ivEXT;
void APIENTRY bluegl_glNamedProgramLocalParametersI4ivEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParametersI4ivEXT) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
    return ((PFN_glNamedProgramLocalParametersI4ivEXT)__blue_glCore_glNamedProgramLocalParametersI4ivEXT)(program, target, index, count, params);
}

extern void* __blue_glCore_glNamedProgramLocalParameterI4uiEXT;
void APIENTRY bluegl_glNamedProgramLocalParameterI4uiEXT (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParameterI4uiEXT) (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    return ((PFN_glNamedProgramLocalParameterI4uiEXT)__blue_glCore_glNamedProgramLocalParameterI4uiEXT)(program, target, index, x, y, z, w);
}

extern void* __blue_glCore_glNamedProgramLocalParameterI4uivEXT;
void APIENTRY bluegl_glNamedProgramLocalParameterI4uivEXT (GLuint program, GLenum target, GLuint index, const GLuint *params) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParameterI4uivEXT) (GLuint program, GLenum target, GLuint index, const GLuint *params);
    return ((PFN_glNamedProgramLocalParameterI4uivEXT)__blue_glCore_glNamedProgramLocalParameterI4uivEXT)(program, target, index, params);
}

extern void* __blue_glCore_glNamedProgramLocalParametersI4uivEXT;
void APIENTRY bluegl_glNamedProgramLocalParametersI4uivEXT (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParametersI4uivEXT) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
    return ((PFN_glNamedProgramLocalParametersI4uivEXT)__blue_glCore_glNamedProgramLocalParametersI4uivEXT)(program, target, index, count, params);
}

extern void* __blue_glCore_glGetNamedProgramLocalParameterIivEXT;
void APIENTRY bluegl_glGetNamedProgramLocalParameterIivEXT (GLuint program, GLenum target, GLuint index, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedProgramLocalParameterIivEXT) (GLuint program, GLenum target, GLuint index, GLint *params);
    return ((PFN_glGetNamedProgramLocalParameterIivEXT)__blue_glCore_glGetNamedProgramLocalParameterIivEXT)(program, target, index, params);
}

extern void* __blue_glCore_glGetNamedProgramLocalParameterIuivEXT;
void APIENTRY bluegl_glGetNamedProgramLocalParameterIuivEXT (GLuint program, GLenum target, GLuint index, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetNamedProgramLocalParameterIuivEXT) (GLuint program, GLenum target, GLuint index, GLuint *params);
    return ((PFN_glGetNamedProgramLocalParameterIuivEXT)__blue_glCore_glGetNamedProgramLocalParameterIuivEXT)(program, target, index, params);
}

extern void* __blue_glCore_glEnableClientStateiEXT;
void APIENTRY bluegl_glEnableClientStateiEXT (GLenum array, GLuint index) {
    typedef void (APIENTRYP PFN_glEnableClientStateiEXT) (GLenum array, GLuint index);
    return ((PFN_glEnableClientStateiEXT)__blue_glCore_glEnableClientStateiEXT)(array, index);
}

extern void* __blue_glCore_glDisableClientStateiEXT;
void APIENTRY bluegl_glDisableClientStateiEXT (GLenum array, GLuint index) {
    typedef void (APIENTRYP PFN_glDisableClientStateiEXT) (GLenum array, GLuint index);
    return ((PFN_glDisableClientStateiEXT)__blue_glCore_glDisableClientStateiEXT)(array, index);
}

extern void* __blue_glCore_glGetFloati_vEXT;
void APIENTRY bluegl_glGetFloati_vEXT (GLenum pname, GLuint index, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetFloati_vEXT) (GLenum pname, GLuint index, GLfloat *params);
    return ((PFN_glGetFloati_vEXT)__blue_glCore_glGetFloati_vEXT)(pname, index, params);
}

extern void* __blue_glCore_glGetDoublei_vEXT;
void APIENTRY bluegl_glGetDoublei_vEXT (GLenum pname, GLuint index, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetDoublei_vEXT) (GLenum pname, GLuint index, GLdouble *params);
    return ((PFN_glGetDoublei_vEXT)__blue_glCore_glGetDoublei_vEXT)(pname, index, params);
}

extern void* __blue_glCore_glGetPointeri_vEXT;
void APIENTRY bluegl_glGetPointeri_vEXT (GLenum pname, GLuint index, void **params) {
    typedef void (APIENTRYP PFN_glGetPointeri_vEXT) (GLenum pname, GLuint index, void **params);
    return ((PFN_glGetPointeri_vEXT)__blue_glCore_glGetPointeri_vEXT)(pname, index, params);
}

extern void* __blue_glCore_glNamedProgramStringEXT;
void APIENTRY bluegl_glNamedProgramStringEXT (GLuint program, GLenum target, GLenum format, GLsizei len, const void *string) {
    typedef void (APIENTRYP PFN_glNamedProgramStringEXT) (GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
    return ((PFN_glNamedProgramStringEXT)__blue_glCore_glNamedProgramStringEXT)(program, target, format, len, string);
}

extern void* __blue_glCore_glNamedProgramLocalParameter4dEXT;
void APIENTRY bluegl_glNamedProgramLocalParameter4dEXT (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParameter4dEXT) (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glNamedProgramLocalParameter4dEXT)__blue_glCore_glNamedProgramLocalParameter4dEXT)(program, target, index, x, y, z, w);
}

extern void* __blue_glCore_glNamedProgramLocalParameter4dvEXT;
void APIENTRY bluegl_glNamedProgramLocalParameter4dvEXT (GLuint program, GLenum target, GLuint index, const GLdouble *params) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParameter4dvEXT) (GLuint program, GLenum target, GLuint index, const GLdouble *params);
    return ((PFN_glNamedProgramLocalParameter4dvEXT)__blue_glCore_glNamedProgramLocalParameter4dvEXT)(program, target, index, params);
}

extern void* __blue_glCore_glNamedProgramLocalParameter4fEXT;
void APIENTRY bluegl_glNamedProgramLocalParameter4fEXT (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParameter4fEXT) (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glNamedProgramLocalParameter4fEXT)__blue_glCore_glNamedProgramLocalParameter4fEXT)(program, target, index, x, y, z, w);
}

extern void* __blue_glCore_glNamedProgramLocalParameter4fvEXT;
void APIENTRY bluegl_glNamedProgramLocalParameter4fvEXT (GLuint program, GLenum target, GLuint index, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glNamedProgramLocalParameter4fvEXT) (GLuint program, GLenum target, GLuint index, const GLfloat *params);
    return ((PFN_glNamedProgramLocalParameter4fvEXT)__blue_glCore_glNamedProgramLocalParameter4fvEXT)(program, target, index, params);
}

extern void* __blue_glCore_glGetNamedProgramLocalParameterdvEXT;
void APIENTRY bluegl_glGetNamedProgramLocalParameterdvEXT (GLuint program, GLenum target, GLuint index, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetNamedProgramLocalParameterdvEXT) (GLuint program, GLenum target, GLuint index, GLdouble *params);
    return ((PFN_glGetNamedProgramLocalParameterdvEXT)__blue_glCore_glGetNamedProgramLocalParameterdvEXT)(program, target, index, params);
}

extern void* __blue_glCore_glGetNamedProgramLocalParameterfvEXT;
void APIENTRY bluegl_glGetNamedProgramLocalParameterfvEXT (GLuint program, GLenum target, GLuint index, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetNamedProgramLocalParameterfvEXT) (GLuint program, GLenum target, GLuint index, GLfloat *params);
    return ((PFN_glGetNamedProgramLocalParameterfvEXT)__blue_glCore_glGetNamedProgramLocalParameterfvEXT)(program, target, index, params);
}

extern void* __blue_glCore_glGetNamedProgramivEXT;
void APIENTRY bluegl_glGetNamedProgramivEXT (GLuint program, GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedProgramivEXT) (GLuint program, GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetNamedProgramivEXT)__blue_glCore_glGetNamedProgramivEXT)(program, target, pname, params);
}

extern void* __blue_glCore_glGetNamedProgramStringEXT;
void APIENTRY bluegl_glGetNamedProgramStringEXT (GLuint program, GLenum target, GLenum pname, void *string) {
    typedef void (APIENTRYP PFN_glGetNamedProgramStringEXT) (GLuint program, GLenum target, GLenum pname, void *string);
    return ((PFN_glGetNamedProgramStringEXT)__blue_glCore_glGetNamedProgramStringEXT)(program, target, pname, string);
}

extern void* __blue_glCore_glNamedRenderbufferStorageEXT;
void APIENTRY bluegl_glNamedRenderbufferStorageEXT (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glNamedRenderbufferStorageEXT) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glNamedRenderbufferStorageEXT)__blue_glCore_glNamedRenderbufferStorageEXT)(renderbuffer, internalformat, width, height);
}

extern void* __blue_glCore_glGetNamedRenderbufferParameterivEXT;
void APIENTRY bluegl_glGetNamedRenderbufferParameterivEXT (GLuint renderbuffer, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedRenderbufferParameterivEXT) (GLuint renderbuffer, GLenum pname, GLint *params);
    return ((PFN_glGetNamedRenderbufferParameterivEXT)__blue_glCore_glGetNamedRenderbufferParameterivEXT)(renderbuffer, pname, params);
}

extern void* __blue_glCore_glNamedRenderbufferStorageMultisampleEXT;
void APIENTRY bluegl_glNamedRenderbufferStorageMultisampleEXT (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glNamedRenderbufferStorageMultisampleEXT) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glNamedRenderbufferStorageMultisampleEXT)__blue_glCore_glNamedRenderbufferStorageMultisampleEXT)(renderbuffer, samples, internalformat, width, height);
}

extern void* __blue_glCore_glNamedRenderbufferStorageMultisampleCoverageEXT;
void APIENTRY bluegl_glNamedRenderbufferStorageMultisampleCoverageEXT (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glNamedRenderbufferStorageMultisampleCoverageEXT) (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glNamedRenderbufferStorageMultisampleCoverageEXT)__blue_glCore_glNamedRenderbufferStorageMultisampleCoverageEXT)(renderbuffer, coverageSamples, colorSamples, internalformat, width, height);
}

extern void* __blue_glCore_glCheckNamedFramebufferStatusEXT;
GLenum APIENTRY bluegl_glCheckNamedFramebufferStatusEXT (GLuint framebuffer, GLenum target) {
    typedef GLenum (APIENTRYP PFN_glCheckNamedFramebufferStatusEXT) (GLuint framebuffer, GLenum target);
    return ((PFN_glCheckNamedFramebufferStatusEXT)__blue_glCore_glCheckNamedFramebufferStatusEXT)(framebuffer, target);
}

extern void* __blue_glCore_glNamedFramebufferTexture1DEXT;
void APIENTRY bluegl_glNamedFramebufferTexture1DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glNamedFramebufferTexture1DEXT) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    return ((PFN_glNamedFramebufferTexture1DEXT)__blue_glCore_glNamedFramebufferTexture1DEXT)(framebuffer, attachment, textarget, texture, level);
}

extern void* __blue_glCore_glNamedFramebufferTexture2DEXT;
void APIENTRY bluegl_glNamedFramebufferTexture2DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glNamedFramebufferTexture2DEXT) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    return ((PFN_glNamedFramebufferTexture2DEXT)__blue_glCore_glNamedFramebufferTexture2DEXT)(framebuffer, attachment, textarget, texture, level);
}

extern void* __blue_glCore_glNamedFramebufferTexture3DEXT;
void APIENTRY bluegl_glNamedFramebufferTexture3DEXT (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
    typedef void (APIENTRYP PFN_glNamedFramebufferTexture3DEXT) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
    return ((PFN_glNamedFramebufferTexture3DEXT)__blue_glCore_glNamedFramebufferTexture3DEXT)(framebuffer, attachment, textarget, texture, level, zoffset);
}

extern void* __blue_glCore_glNamedFramebufferRenderbufferEXT;
void APIENTRY bluegl_glNamedFramebufferRenderbufferEXT (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    typedef void (APIENTRYP PFN_glNamedFramebufferRenderbufferEXT) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    return ((PFN_glNamedFramebufferRenderbufferEXT)__blue_glCore_glNamedFramebufferRenderbufferEXT)(framebuffer, attachment, renderbuffertarget, renderbuffer);
}

extern void* __blue_glCore_glGetNamedFramebufferAttachmentParameterivEXT;
void APIENTRY bluegl_glGetNamedFramebufferAttachmentParameterivEXT (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedFramebufferAttachmentParameterivEXT) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
    return ((PFN_glGetNamedFramebufferAttachmentParameterivEXT)__blue_glCore_glGetNamedFramebufferAttachmentParameterivEXT)(framebuffer, attachment, pname, params);
}

extern void* __blue_glCore_glGenerateTextureMipmapEXT;
void APIENTRY bluegl_glGenerateTextureMipmapEXT (GLuint texture, GLenum target) {
    typedef void (APIENTRYP PFN_glGenerateTextureMipmapEXT) (GLuint texture, GLenum target);
    return ((PFN_glGenerateTextureMipmapEXT)__blue_glCore_glGenerateTextureMipmapEXT)(texture, target);
}

extern void* __blue_glCore_glGenerateMultiTexMipmapEXT;
void APIENTRY bluegl_glGenerateMultiTexMipmapEXT (GLenum texunit, GLenum target) {
    typedef void (APIENTRYP PFN_glGenerateMultiTexMipmapEXT) (GLenum texunit, GLenum target);
    return ((PFN_glGenerateMultiTexMipmapEXT)__blue_glCore_glGenerateMultiTexMipmapEXT)(texunit, target);
}

extern void* __blue_glCore_glFramebufferDrawBufferEXT;
void APIENTRY bluegl_glFramebufferDrawBufferEXT (GLuint framebuffer, GLenum mode) {
    typedef void (APIENTRYP PFN_glFramebufferDrawBufferEXT) (GLuint framebuffer, GLenum mode);
    return ((PFN_glFramebufferDrawBufferEXT)__blue_glCore_glFramebufferDrawBufferEXT)(framebuffer, mode);
}

extern void* __blue_glCore_glFramebufferDrawBuffersEXT;
void APIENTRY bluegl_glFramebufferDrawBuffersEXT (GLuint framebuffer, GLsizei n, const GLenum *bufs) {
    typedef void (APIENTRYP PFN_glFramebufferDrawBuffersEXT) (GLuint framebuffer, GLsizei n, const GLenum *bufs);
    return ((PFN_glFramebufferDrawBuffersEXT)__blue_glCore_glFramebufferDrawBuffersEXT)(framebuffer, n, bufs);
}

extern void* __blue_glCore_glFramebufferReadBufferEXT;
void APIENTRY bluegl_glFramebufferReadBufferEXT (GLuint framebuffer, GLenum mode) {
    typedef void (APIENTRYP PFN_glFramebufferReadBufferEXT) (GLuint framebuffer, GLenum mode);
    return ((PFN_glFramebufferReadBufferEXT)__blue_glCore_glFramebufferReadBufferEXT)(framebuffer, mode);
}

extern void* __blue_glCore_glGetFramebufferParameterivEXT;
void APIENTRY bluegl_glGetFramebufferParameterivEXT (GLuint framebuffer, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetFramebufferParameterivEXT) (GLuint framebuffer, GLenum pname, GLint *params);
    return ((PFN_glGetFramebufferParameterivEXT)__blue_glCore_glGetFramebufferParameterivEXT)(framebuffer, pname, params);
}

extern void* __blue_glCore_glNamedCopyBufferSubDataEXT;
void APIENTRY bluegl_glNamedCopyBufferSubDataEXT (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glNamedCopyBufferSubDataEXT) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    return ((PFN_glNamedCopyBufferSubDataEXT)__blue_glCore_glNamedCopyBufferSubDataEXT)(readBuffer, writeBuffer, readOffset, writeOffset, size);
}

extern void* __blue_glCore_glNamedFramebufferTextureEXT;
void APIENTRY bluegl_glNamedFramebufferTextureEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glNamedFramebufferTextureEXT) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
    return ((PFN_glNamedFramebufferTextureEXT)__blue_glCore_glNamedFramebufferTextureEXT)(framebuffer, attachment, texture, level);
}

extern void* __blue_glCore_glNamedFramebufferTextureLayerEXT;
void APIENTRY bluegl_glNamedFramebufferTextureLayerEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    typedef void (APIENTRYP PFN_glNamedFramebufferTextureLayerEXT) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
    return ((PFN_glNamedFramebufferTextureLayerEXT)__blue_glCore_glNamedFramebufferTextureLayerEXT)(framebuffer, attachment, texture, level, layer);
}

extern void* __blue_glCore_glNamedFramebufferTextureFaceEXT;
void APIENTRY bluegl_glNamedFramebufferTextureFaceEXT (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face) {
    typedef void (APIENTRYP PFN_glNamedFramebufferTextureFaceEXT) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
    return ((PFN_glNamedFramebufferTextureFaceEXT)__blue_glCore_glNamedFramebufferTextureFaceEXT)(framebuffer, attachment, texture, level, face);
}

extern void* __blue_glCore_glTextureRenderbufferEXT;
void APIENTRY bluegl_glTextureRenderbufferEXT (GLuint texture, GLenum target, GLuint renderbuffer) {
    typedef void (APIENTRYP PFN_glTextureRenderbufferEXT) (GLuint texture, GLenum target, GLuint renderbuffer);
    return ((PFN_glTextureRenderbufferEXT)__blue_glCore_glTextureRenderbufferEXT)(texture, target, renderbuffer);
}

extern void* __blue_glCore_glMultiTexRenderbufferEXT;
void APIENTRY bluegl_glMultiTexRenderbufferEXT (GLenum texunit, GLenum target, GLuint renderbuffer) {
    typedef void (APIENTRYP PFN_glMultiTexRenderbufferEXT) (GLenum texunit, GLenum target, GLuint renderbuffer);
    return ((PFN_glMultiTexRenderbufferEXT)__blue_glCore_glMultiTexRenderbufferEXT)(texunit, target, renderbuffer);
}

extern void* __blue_glCore_glVertexArrayVertexOffsetEXT;
void APIENTRY bluegl_glVertexArrayVertexOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexOffsetEXT) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayVertexOffsetEXT)__blue_glCore_glVertexArrayVertexOffsetEXT)(vaobj, buffer, size, type, stride, offset);
}

extern void* __blue_glCore_glVertexArrayColorOffsetEXT;
void APIENTRY bluegl_glVertexArrayColorOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayColorOffsetEXT) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayColorOffsetEXT)__blue_glCore_glVertexArrayColorOffsetEXT)(vaobj, buffer, size, type, stride, offset);
}

extern void* __blue_glCore_glVertexArrayEdgeFlagOffsetEXT;
void APIENTRY bluegl_glVertexArrayEdgeFlagOffsetEXT (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayEdgeFlagOffsetEXT) (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayEdgeFlagOffsetEXT)__blue_glCore_glVertexArrayEdgeFlagOffsetEXT)(vaobj, buffer, stride, offset);
}

extern void* __blue_glCore_glVertexArrayIndexOffsetEXT;
void APIENTRY bluegl_glVertexArrayIndexOffsetEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayIndexOffsetEXT) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayIndexOffsetEXT)__blue_glCore_glVertexArrayIndexOffsetEXT)(vaobj, buffer, type, stride, offset);
}

extern void* __blue_glCore_glVertexArrayNormalOffsetEXT;
void APIENTRY bluegl_glVertexArrayNormalOffsetEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayNormalOffsetEXT) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayNormalOffsetEXT)__blue_glCore_glVertexArrayNormalOffsetEXT)(vaobj, buffer, type, stride, offset);
}

extern void* __blue_glCore_glVertexArrayTexCoordOffsetEXT;
void APIENTRY bluegl_glVertexArrayTexCoordOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayTexCoordOffsetEXT) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayTexCoordOffsetEXT)__blue_glCore_glVertexArrayTexCoordOffsetEXT)(vaobj, buffer, size, type, stride, offset);
}

extern void* __blue_glCore_glVertexArrayMultiTexCoordOffsetEXT;
void APIENTRY bluegl_glVertexArrayMultiTexCoordOffsetEXT (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayMultiTexCoordOffsetEXT) (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayMultiTexCoordOffsetEXT)__blue_glCore_glVertexArrayMultiTexCoordOffsetEXT)(vaobj, buffer, texunit, size, type, stride, offset);
}

extern void* __blue_glCore_glVertexArrayFogCoordOffsetEXT;
void APIENTRY bluegl_glVertexArrayFogCoordOffsetEXT (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayFogCoordOffsetEXT) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayFogCoordOffsetEXT)__blue_glCore_glVertexArrayFogCoordOffsetEXT)(vaobj, buffer, type, stride, offset);
}

extern void* __blue_glCore_glVertexArraySecondaryColorOffsetEXT;
void APIENTRY bluegl_glVertexArraySecondaryColorOffsetEXT (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArraySecondaryColorOffsetEXT) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArraySecondaryColorOffsetEXT)__blue_glCore_glVertexArraySecondaryColorOffsetEXT)(vaobj, buffer, size, type, stride, offset);
}

extern void* __blue_glCore_glVertexArrayVertexAttribOffsetEXT;
void APIENTRY bluegl_glVertexArrayVertexAttribOffsetEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexAttribOffsetEXT) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayVertexAttribOffsetEXT)__blue_glCore_glVertexArrayVertexAttribOffsetEXT)(vaobj, buffer, index, size, type, normalized, stride, offset);
}

extern void* __blue_glCore_glVertexArrayVertexAttribIOffsetEXT;
void APIENTRY bluegl_glVertexArrayVertexAttribIOffsetEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexAttribIOffsetEXT) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayVertexAttribIOffsetEXT)__blue_glCore_glVertexArrayVertexAttribIOffsetEXT)(vaobj, buffer, index, size, type, stride, offset);
}

extern void* __blue_glCore_glEnableVertexArrayEXT;
void APIENTRY bluegl_glEnableVertexArrayEXT (GLuint vaobj, GLenum array) {
    typedef void (APIENTRYP PFN_glEnableVertexArrayEXT) (GLuint vaobj, GLenum array);
    return ((PFN_glEnableVertexArrayEXT)__blue_glCore_glEnableVertexArrayEXT)(vaobj, array);
}

extern void* __blue_glCore_glDisableVertexArrayEXT;
void APIENTRY bluegl_glDisableVertexArrayEXT (GLuint vaobj, GLenum array) {
    typedef void (APIENTRYP PFN_glDisableVertexArrayEXT) (GLuint vaobj, GLenum array);
    return ((PFN_glDisableVertexArrayEXT)__blue_glCore_glDisableVertexArrayEXT)(vaobj, array);
}

extern void* __blue_glCore_glEnableVertexArrayAttribEXT;
void APIENTRY bluegl_glEnableVertexArrayAttribEXT (GLuint vaobj, GLuint index) {
    typedef void (APIENTRYP PFN_glEnableVertexArrayAttribEXT) (GLuint vaobj, GLuint index);
    return ((PFN_glEnableVertexArrayAttribEXT)__blue_glCore_glEnableVertexArrayAttribEXT)(vaobj, index);
}

extern void* __blue_glCore_glDisableVertexArrayAttribEXT;
void APIENTRY bluegl_glDisableVertexArrayAttribEXT (GLuint vaobj, GLuint index) {
    typedef void (APIENTRYP PFN_glDisableVertexArrayAttribEXT) (GLuint vaobj, GLuint index);
    return ((PFN_glDisableVertexArrayAttribEXT)__blue_glCore_glDisableVertexArrayAttribEXT)(vaobj, index);
}

extern void* __blue_glCore_glGetVertexArrayIntegervEXT;
void APIENTRY bluegl_glGetVertexArrayIntegervEXT (GLuint vaobj, GLenum pname, GLint *param) {
    typedef void (APIENTRYP PFN_glGetVertexArrayIntegervEXT) (GLuint vaobj, GLenum pname, GLint *param);
    return ((PFN_glGetVertexArrayIntegervEXT)__blue_glCore_glGetVertexArrayIntegervEXT)(vaobj, pname, param);
}

extern void* __blue_glCore_glGetVertexArrayPointervEXT;
void APIENTRY bluegl_glGetVertexArrayPointervEXT (GLuint vaobj, GLenum pname, void **param) {
    typedef void (APIENTRYP PFN_glGetVertexArrayPointervEXT) (GLuint vaobj, GLenum pname, void **param);
    return ((PFN_glGetVertexArrayPointervEXT)__blue_glCore_glGetVertexArrayPointervEXT)(vaobj, pname, param);
}

extern void* __blue_glCore_glGetVertexArrayIntegeri_vEXT;
void APIENTRY bluegl_glGetVertexArrayIntegeri_vEXT (GLuint vaobj, GLuint index, GLenum pname, GLint *param) {
    typedef void (APIENTRYP PFN_glGetVertexArrayIntegeri_vEXT) (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
    return ((PFN_glGetVertexArrayIntegeri_vEXT)__blue_glCore_glGetVertexArrayIntegeri_vEXT)(vaobj, index, pname, param);
}

extern void* __blue_glCore_glGetVertexArrayPointeri_vEXT;
void APIENTRY bluegl_glGetVertexArrayPointeri_vEXT (GLuint vaobj, GLuint index, GLenum pname, void **param) {
    typedef void (APIENTRYP PFN_glGetVertexArrayPointeri_vEXT) (GLuint vaobj, GLuint index, GLenum pname, void **param);
    return ((PFN_glGetVertexArrayPointeri_vEXT)__blue_glCore_glGetVertexArrayPointeri_vEXT)(vaobj, index, pname, param);
}

extern void* __blue_glCore_glMapNamedBufferRangeEXT;
void *APIENTRY bluegl_glMapNamedBufferRangeEXT (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    typedef void *(APIENTRYP PFN_glMapNamedBufferRangeEXT) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
    return ((PFN_glMapNamedBufferRangeEXT)__blue_glCore_glMapNamedBufferRangeEXT)(buffer, offset, length, access);
}

extern void* __blue_glCore_glFlushMappedNamedBufferRangeEXT;
void APIENTRY bluegl_glFlushMappedNamedBufferRangeEXT (GLuint buffer, GLintptr offset, GLsizeiptr length) {
    typedef void (APIENTRYP PFN_glFlushMappedNamedBufferRangeEXT) (GLuint buffer, GLintptr offset, GLsizeiptr length);
    return ((PFN_glFlushMappedNamedBufferRangeEXT)__blue_glCore_glFlushMappedNamedBufferRangeEXT)(buffer, offset, length);
}

extern void* __blue_glCore_glNamedBufferStorageEXT;
void APIENTRY bluegl_glNamedBufferStorageEXT (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) {
    typedef void (APIENTRYP PFN_glNamedBufferStorageEXT) (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
    return ((PFN_glNamedBufferStorageEXT)__blue_glCore_glNamedBufferStorageEXT)(buffer, size, data, flags);
}

extern void* __blue_glCore_glClearNamedBufferDataEXT;
void APIENTRY bluegl_glClearNamedBufferDataEXT (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glClearNamedBufferDataEXT) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
    return ((PFN_glClearNamedBufferDataEXT)__blue_glCore_glClearNamedBufferDataEXT)(buffer, internalformat, format, type, data);
}

extern void* __blue_glCore_glClearNamedBufferSubDataEXT;
void APIENTRY bluegl_glClearNamedBufferSubDataEXT (GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) {
    typedef void (APIENTRYP PFN_glClearNamedBufferSubDataEXT) (GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
    return ((PFN_glClearNamedBufferSubDataEXT)__blue_glCore_glClearNamedBufferSubDataEXT)(buffer, internalformat, offset, size, format, type, data);
}

extern void* __blue_glCore_glNamedFramebufferParameteriEXT;
void APIENTRY bluegl_glNamedFramebufferParameteriEXT (GLuint framebuffer, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glNamedFramebufferParameteriEXT) (GLuint framebuffer, GLenum pname, GLint param);
    return ((PFN_glNamedFramebufferParameteriEXT)__blue_glCore_glNamedFramebufferParameteriEXT)(framebuffer, pname, param);
}

extern void* __blue_glCore_glGetNamedFramebufferParameterivEXT;
void APIENTRY bluegl_glGetNamedFramebufferParameterivEXT (GLuint framebuffer, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetNamedFramebufferParameterivEXT) (GLuint framebuffer, GLenum pname, GLint *params);
    return ((PFN_glGetNamedFramebufferParameterivEXT)__blue_glCore_glGetNamedFramebufferParameterivEXT)(framebuffer, pname, params);
}

extern void* __blue_glCore_glProgramUniform1dEXT;
void APIENTRY bluegl_glProgramUniform1dEXT (GLuint program, GLint location, GLdouble x) {
    typedef void (APIENTRYP PFN_glProgramUniform1dEXT) (GLuint program, GLint location, GLdouble x);
    return ((PFN_glProgramUniform1dEXT)__blue_glCore_glProgramUniform1dEXT)(program, location, x);
}

extern void* __blue_glCore_glProgramUniform2dEXT;
void APIENTRY bluegl_glProgramUniform2dEXT (GLuint program, GLint location, GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glProgramUniform2dEXT) (GLuint program, GLint location, GLdouble x, GLdouble y);
    return ((PFN_glProgramUniform2dEXT)__blue_glCore_glProgramUniform2dEXT)(program, location, x, y);
}

extern void* __blue_glCore_glProgramUniform3dEXT;
void APIENTRY bluegl_glProgramUniform3dEXT (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glProgramUniform3dEXT) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glProgramUniform3dEXT)__blue_glCore_glProgramUniform3dEXT)(program, location, x, y, z);
}

extern void* __blue_glCore_glProgramUniform4dEXT;
void APIENTRY bluegl_glProgramUniform4dEXT (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glProgramUniform4dEXT) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glProgramUniform4dEXT)__blue_glCore_glProgramUniform4dEXT)(program, location, x, y, z, w);
}

extern void* __blue_glCore_glProgramUniform1dvEXT;
void APIENTRY bluegl_glProgramUniform1dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniform1dvEXT) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glProgramUniform1dvEXT)__blue_glCore_glProgramUniform1dvEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform2dvEXT;
void APIENTRY bluegl_glProgramUniform2dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniform2dvEXT) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glProgramUniform2dvEXT)__blue_glCore_glProgramUniform2dvEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform3dvEXT;
void APIENTRY bluegl_glProgramUniform3dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniform3dvEXT) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glProgramUniform3dvEXT)__blue_glCore_glProgramUniform3dvEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniform4dvEXT;
void APIENTRY bluegl_glProgramUniform4dvEXT (GLuint program, GLint location, GLsizei count, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniform4dvEXT) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
    return ((PFN_glProgramUniform4dvEXT)__blue_glCore_glProgramUniform4dvEXT)(program, location, count, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2dvEXT;
void APIENTRY bluegl_glProgramUniformMatrix2dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2dvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix2dvEXT)__blue_glCore_glProgramUniformMatrix2dvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3dvEXT;
void APIENTRY bluegl_glProgramUniformMatrix3dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3dvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix3dvEXT)__blue_glCore_glProgramUniformMatrix3dvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4dvEXT;
void APIENTRY bluegl_glProgramUniformMatrix4dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4dvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix4dvEXT)__blue_glCore_glProgramUniformMatrix4dvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2x3dvEXT;
void APIENTRY bluegl_glProgramUniformMatrix2x3dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2x3dvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix2x3dvEXT)__blue_glCore_glProgramUniformMatrix2x3dvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix2x4dvEXT;
void APIENTRY bluegl_glProgramUniformMatrix2x4dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix2x4dvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix2x4dvEXT)__blue_glCore_glProgramUniformMatrix2x4dvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3x2dvEXT;
void APIENTRY bluegl_glProgramUniformMatrix3x2dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3x2dvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix3x2dvEXT)__blue_glCore_glProgramUniformMatrix3x2dvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix3x4dvEXT;
void APIENTRY bluegl_glProgramUniformMatrix3x4dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix3x4dvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix3x4dvEXT)__blue_glCore_glProgramUniformMatrix3x4dvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4x2dvEXT;
void APIENTRY bluegl_glProgramUniformMatrix4x2dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4x2dvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix4x2dvEXT)__blue_glCore_glProgramUniformMatrix4x2dvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glProgramUniformMatrix4x3dvEXT;
void APIENTRY bluegl_glProgramUniformMatrix4x3dvEXT (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) {
    typedef void (APIENTRYP PFN_glProgramUniformMatrix4x3dvEXT) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
    return ((PFN_glProgramUniformMatrix4x3dvEXT)__blue_glCore_glProgramUniformMatrix4x3dvEXT)(program, location, count, transpose, value);
}

extern void* __blue_glCore_glTextureBufferRangeEXT;
void APIENTRY bluegl_glTextureBufferRangeEXT (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glTextureBufferRangeEXT) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    return ((PFN_glTextureBufferRangeEXT)__blue_glCore_glTextureBufferRangeEXT)(texture, target, internalformat, buffer, offset, size);
}

extern void* __blue_glCore_glTextureStorage1DEXT;
void APIENTRY bluegl_glTextureStorage1DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
    typedef void (APIENTRYP PFN_glTextureStorage1DEXT) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
    return ((PFN_glTextureStorage1DEXT)__blue_glCore_glTextureStorage1DEXT)(texture, target, levels, internalformat, width);
}

extern void* __blue_glCore_glTextureStorage2DEXT;
void APIENTRY bluegl_glTextureStorage2DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glTextureStorage2DEXT) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glTextureStorage2DEXT)__blue_glCore_glTextureStorage2DEXT)(texture, target, levels, internalformat, width, height);
}

extern void* __blue_glCore_glTextureStorage3DEXT;
void APIENTRY bluegl_glTextureStorage3DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
    typedef void (APIENTRYP PFN_glTextureStorage3DEXT) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    return ((PFN_glTextureStorage3DEXT)__blue_glCore_glTextureStorage3DEXT)(texture, target, levels, internalformat, width, height, depth);
}

extern void* __blue_glCore_glTextureStorage2DMultisampleEXT;
void APIENTRY bluegl_glTextureStorage2DMultisampleEXT (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    typedef void (APIENTRYP PFN_glTextureStorage2DMultisampleEXT) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    return ((PFN_glTextureStorage2DMultisampleEXT)__blue_glCore_glTextureStorage2DMultisampleEXT)(texture, target, samples, internalformat, width, height, fixedsamplelocations);
}

extern void* __blue_glCore_glTextureStorage3DMultisampleEXT;
void APIENTRY bluegl_glTextureStorage3DMultisampleEXT (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    typedef void (APIENTRYP PFN_glTextureStorage3DMultisampleEXT) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    return ((PFN_glTextureStorage3DMultisampleEXT)__blue_glCore_glTextureStorage3DMultisampleEXT)(texture, target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

extern void* __blue_glCore_glVertexArrayBindVertexBufferEXT;
void APIENTRY bluegl_glVertexArrayBindVertexBufferEXT (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
    typedef void (APIENTRYP PFN_glVertexArrayBindVertexBufferEXT) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    return ((PFN_glVertexArrayBindVertexBufferEXT)__blue_glCore_glVertexArrayBindVertexBufferEXT)(vaobj, bindingindex, buffer, offset, stride);
}

extern void* __blue_glCore_glVertexArrayVertexAttribFormatEXT;
void APIENTRY bluegl_glVertexArrayVertexAttribFormatEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexAttribFormatEXT) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    return ((PFN_glVertexArrayVertexAttribFormatEXT)__blue_glCore_glVertexArrayVertexAttribFormatEXT)(vaobj, attribindex, size, type, normalized, relativeoffset);
}

extern void* __blue_glCore_glVertexArrayVertexAttribIFormatEXT;
void APIENTRY bluegl_glVertexArrayVertexAttribIFormatEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexAttribIFormatEXT) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    return ((PFN_glVertexArrayVertexAttribIFormatEXT)__blue_glCore_glVertexArrayVertexAttribIFormatEXT)(vaobj, attribindex, size, type, relativeoffset);
}

extern void* __blue_glCore_glVertexArrayVertexAttribLFormatEXT;
void APIENTRY bluegl_glVertexArrayVertexAttribLFormatEXT (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexAttribLFormatEXT) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    return ((PFN_glVertexArrayVertexAttribLFormatEXT)__blue_glCore_glVertexArrayVertexAttribLFormatEXT)(vaobj, attribindex, size, type, relativeoffset);
}

extern void* __blue_glCore_glVertexArrayVertexAttribBindingEXT;
void APIENTRY bluegl_glVertexArrayVertexAttribBindingEXT (GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexAttribBindingEXT) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
    return ((PFN_glVertexArrayVertexAttribBindingEXT)__blue_glCore_glVertexArrayVertexAttribBindingEXT)(vaobj, attribindex, bindingindex);
}

extern void* __blue_glCore_glVertexArrayVertexBindingDivisorEXT;
void APIENTRY bluegl_glVertexArrayVertexBindingDivisorEXT (GLuint vaobj, GLuint bindingindex, GLuint divisor) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexBindingDivisorEXT) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
    return ((PFN_glVertexArrayVertexBindingDivisorEXT)__blue_glCore_glVertexArrayVertexBindingDivisorEXT)(vaobj, bindingindex, divisor);
}

extern void* __blue_glCore_glVertexArrayVertexAttribLOffsetEXT;
void APIENTRY bluegl_glVertexArrayVertexAttribLOffsetEXT (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexAttribLOffsetEXT) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
    return ((PFN_glVertexArrayVertexAttribLOffsetEXT)__blue_glCore_glVertexArrayVertexAttribLOffsetEXT)(vaobj, buffer, index, size, type, stride, offset);
}

extern void* __blue_glCore_glTexturePageCommitmentEXT;
void APIENTRY bluegl_glTexturePageCommitmentEXT (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) {
    typedef void (APIENTRYP PFN_glTexturePageCommitmentEXT) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
    return ((PFN_glTexturePageCommitmentEXT)__blue_glCore_glTexturePageCommitmentEXT)(texture, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}

extern void* __blue_glCore_glVertexArrayVertexAttribDivisorEXT;
void APIENTRY bluegl_glVertexArrayVertexAttribDivisorEXT (GLuint vaobj, GLuint index, GLuint divisor) {
    typedef void (APIENTRYP PFN_glVertexArrayVertexAttribDivisorEXT) (GLuint vaobj, GLuint index, GLuint divisor);
    return ((PFN_glVertexArrayVertexAttribDivisorEXT)__blue_glCore_glVertexArrayVertexAttribDivisorEXT)(vaobj, index, divisor);
}

extern void* __blue_glCore_glColorMaskIndexedEXT;
void APIENTRY bluegl_glColorMaskIndexedEXT (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
    typedef void (APIENTRYP PFN_glColorMaskIndexedEXT) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
    return ((PFN_glColorMaskIndexedEXT)__blue_glCore_glColorMaskIndexedEXT)(index, r, g, b, a);
}

extern void* __blue_glCore_glDrawArraysInstancedEXT;
void APIENTRY bluegl_glDrawArraysInstancedEXT (GLenum mode, GLint start, GLsizei count, GLsizei primcount) {
    typedef void (APIENTRYP PFN_glDrawArraysInstancedEXT) (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
    return ((PFN_glDrawArraysInstancedEXT)__blue_glCore_glDrawArraysInstancedEXT)(mode, start, count, primcount);
}

extern void* __blue_glCore_glDrawElementsInstancedEXT;
void APIENTRY bluegl_glDrawElementsInstancedEXT (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount) {
    typedef void (APIENTRYP PFN_glDrawElementsInstancedEXT) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
    return ((PFN_glDrawElementsInstancedEXT)__blue_glCore_glDrawElementsInstancedEXT)(mode, count, type, indices, primcount);
}

extern void* __blue_glCore_glDrawRangeElementsEXT;
void APIENTRY bluegl_glDrawRangeElementsEXT (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) {
    typedef void (APIENTRYP PFN_glDrawRangeElementsEXT) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
    return ((PFN_glDrawRangeElementsEXT)__blue_glCore_glDrawRangeElementsEXT)(mode, start, end, count, type, indices);
}

extern void* __blue_glCore_glFogCoordfEXT;
void APIENTRY bluegl_glFogCoordfEXT (GLfloat coord) {
    typedef void (APIENTRYP PFN_glFogCoordfEXT) (GLfloat coord);
    return ((PFN_glFogCoordfEXT)__blue_glCore_glFogCoordfEXT)(coord);
}

extern void* __blue_glCore_glFogCoordfvEXT;
void APIENTRY bluegl_glFogCoordfvEXT (const GLfloat *coord) {
    typedef void (APIENTRYP PFN_glFogCoordfvEXT) (const GLfloat *coord);
    return ((PFN_glFogCoordfvEXT)__blue_glCore_glFogCoordfvEXT)(coord);
}

extern void* __blue_glCore_glFogCoorddEXT;
void APIENTRY bluegl_glFogCoorddEXT (GLdouble coord) {
    typedef void (APIENTRYP PFN_glFogCoorddEXT) (GLdouble coord);
    return ((PFN_glFogCoorddEXT)__blue_glCore_glFogCoorddEXT)(coord);
}

extern void* __blue_glCore_glFogCoorddvEXT;
void APIENTRY bluegl_glFogCoorddvEXT (const GLdouble *coord) {
    typedef void (APIENTRYP PFN_glFogCoorddvEXT) (const GLdouble *coord);
    return ((PFN_glFogCoorddvEXT)__blue_glCore_glFogCoorddvEXT)(coord);
}

extern void* __blue_glCore_glFogCoordPointerEXT;
void APIENTRY bluegl_glFogCoordPointerEXT (GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glFogCoordPointerEXT) (GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glFogCoordPointerEXT)__blue_glCore_glFogCoordPointerEXT)(type, stride, pointer);
}

extern void* __blue_glCore_glBlitFramebufferEXT;
void APIENTRY bluegl_glBlitFramebufferEXT (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    typedef void (APIENTRYP PFN_glBlitFramebufferEXT) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    return ((PFN_glBlitFramebufferEXT)__blue_glCore_glBlitFramebufferEXT)(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

extern void* __blue_glCore_glRenderbufferStorageMultisampleEXT;
void APIENTRY bluegl_glRenderbufferStorageMultisampleEXT (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glRenderbufferStorageMultisampleEXT) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glRenderbufferStorageMultisampleEXT)__blue_glCore_glRenderbufferStorageMultisampleEXT)(target, samples, internalformat, width, height);
}

extern void* __blue_glCore_glIsRenderbufferEXT;
GLboolean APIENTRY bluegl_glIsRenderbufferEXT (GLuint renderbuffer) {
    typedef GLboolean (APIENTRYP PFN_glIsRenderbufferEXT) (GLuint renderbuffer);
    return ((PFN_glIsRenderbufferEXT)__blue_glCore_glIsRenderbufferEXT)(renderbuffer);
}

extern void* __blue_glCore_glBindRenderbufferEXT;
void APIENTRY bluegl_glBindRenderbufferEXT (GLenum target, GLuint renderbuffer) {
    typedef void (APIENTRYP PFN_glBindRenderbufferEXT) (GLenum target, GLuint renderbuffer);
    return ((PFN_glBindRenderbufferEXT)__blue_glCore_glBindRenderbufferEXT)(target, renderbuffer);
}

extern void* __blue_glCore_glDeleteRenderbuffersEXT;
void APIENTRY bluegl_glDeleteRenderbuffersEXT (GLsizei n, const GLuint *renderbuffers) {
    typedef void (APIENTRYP PFN_glDeleteRenderbuffersEXT) (GLsizei n, const GLuint *renderbuffers);
    return ((PFN_glDeleteRenderbuffersEXT)__blue_glCore_glDeleteRenderbuffersEXT)(n, renderbuffers);
}

extern void* __blue_glCore_glGenRenderbuffersEXT;
void APIENTRY bluegl_glGenRenderbuffersEXT (GLsizei n, GLuint *renderbuffers) {
    typedef void (APIENTRYP PFN_glGenRenderbuffersEXT) (GLsizei n, GLuint *renderbuffers);
    return ((PFN_glGenRenderbuffersEXT)__blue_glCore_glGenRenderbuffersEXT)(n, renderbuffers);
}

extern void* __blue_glCore_glRenderbufferStorageEXT;
void APIENTRY bluegl_glRenderbufferStorageEXT (GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glRenderbufferStorageEXT) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glRenderbufferStorageEXT)__blue_glCore_glRenderbufferStorageEXT)(target, internalformat, width, height);
}

extern void* __blue_glCore_glGetRenderbufferParameterivEXT;
void APIENTRY bluegl_glGetRenderbufferParameterivEXT (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetRenderbufferParameterivEXT) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetRenderbufferParameterivEXT)__blue_glCore_glGetRenderbufferParameterivEXT)(target, pname, params);
}

extern void* __blue_glCore_glIsFramebufferEXT;
GLboolean APIENTRY bluegl_glIsFramebufferEXT (GLuint framebuffer) {
    typedef GLboolean (APIENTRYP PFN_glIsFramebufferEXT) (GLuint framebuffer);
    return ((PFN_glIsFramebufferEXT)__blue_glCore_glIsFramebufferEXT)(framebuffer);
}

extern void* __blue_glCore_glBindFramebufferEXT;
void APIENTRY bluegl_glBindFramebufferEXT (GLenum target, GLuint framebuffer) {
    typedef void (APIENTRYP PFN_glBindFramebufferEXT) (GLenum target, GLuint framebuffer);
    return ((PFN_glBindFramebufferEXT)__blue_glCore_glBindFramebufferEXT)(target, framebuffer);
}

extern void* __blue_glCore_glDeleteFramebuffersEXT;
void APIENTRY bluegl_glDeleteFramebuffersEXT (GLsizei n, const GLuint *framebuffers) {
    typedef void (APIENTRYP PFN_glDeleteFramebuffersEXT) (GLsizei n, const GLuint *framebuffers);
    return ((PFN_glDeleteFramebuffersEXT)__blue_glCore_glDeleteFramebuffersEXT)(n, framebuffers);
}

extern void* __blue_glCore_glGenFramebuffersEXT;
void APIENTRY bluegl_glGenFramebuffersEXT (GLsizei n, GLuint *framebuffers) {
    typedef void (APIENTRYP PFN_glGenFramebuffersEXT) (GLsizei n, GLuint *framebuffers);
    return ((PFN_glGenFramebuffersEXT)__blue_glCore_glGenFramebuffersEXT)(n, framebuffers);
}

extern void* __blue_glCore_glCheckFramebufferStatusEXT;
GLenum APIENTRY bluegl_glCheckFramebufferStatusEXT (GLenum target) {
    typedef GLenum (APIENTRYP PFN_glCheckFramebufferStatusEXT) (GLenum target);
    return ((PFN_glCheckFramebufferStatusEXT)__blue_glCore_glCheckFramebufferStatusEXT)(target);
}

extern void* __blue_glCore_glFramebufferTexture1DEXT;
void APIENTRY bluegl_glFramebufferTexture1DEXT (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glFramebufferTexture1DEXT) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    return ((PFN_glFramebufferTexture1DEXT)__blue_glCore_glFramebufferTexture1DEXT)(target, attachment, textarget, texture, level);
}

extern void* __blue_glCore_glFramebufferTexture2DEXT;
void APIENTRY bluegl_glFramebufferTexture2DEXT (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glFramebufferTexture2DEXT) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    return ((PFN_glFramebufferTexture2DEXT)__blue_glCore_glFramebufferTexture2DEXT)(target, attachment, textarget, texture, level);
}

extern void* __blue_glCore_glFramebufferTexture3DEXT;
void APIENTRY bluegl_glFramebufferTexture3DEXT (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
    typedef void (APIENTRYP PFN_glFramebufferTexture3DEXT) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
    return ((PFN_glFramebufferTexture3DEXT)__blue_glCore_glFramebufferTexture3DEXT)(target, attachment, textarget, texture, level, zoffset);
}

extern void* __blue_glCore_glFramebufferRenderbufferEXT;
void APIENTRY bluegl_glFramebufferRenderbufferEXT (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    typedef void (APIENTRYP PFN_glFramebufferRenderbufferEXT) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    return ((PFN_glFramebufferRenderbufferEXT)__blue_glCore_glFramebufferRenderbufferEXT)(target, attachment, renderbuffertarget, renderbuffer);
}

extern void* __blue_glCore_glGetFramebufferAttachmentParameterivEXT;
void APIENTRY bluegl_glGetFramebufferAttachmentParameterivEXT (GLenum target, GLenum attachment, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetFramebufferAttachmentParameterivEXT) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
    return ((PFN_glGetFramebufferAttachmentParameterivEXT)__blue_glCore_glGetFramebufferAttachmentParameterivEXT)(target, attachment, pname, params);
}

extern void* __blue_glCore_glGenerateMipmapEXT;
void APIENTRY bluegl_glGenerateMipmapEXT (GLenum target) {
    typedef void (APIENTRYP PFN_glGenerateMipmapEXT) (GLenum target);
    return ((PFN_glGenerateMipmapEXT)__blue_glCore_glGenerateMipmapEXT)(target);
}

extern void* __blue_glCore_glProgramParameteriEXT;
void APIENTRY bluegl_glProgramParameteriEXT (GLuint program, GLenum pname, GLint value) {
    typedef void (APIENTRYP PFN_glProgramParameteriEXT) (GLuint program, GLenum pname, GLint value);
    return ((PFN_glProgramParameteriEXT)__blue_glCore_glProgramParameteriEXT)(program, pname, value);
}

extern void* __blue_glCore_glProgramEnvParameters4fvEXT;
void APIENTRY bluegl_glProgramEnvParameters4fvEXT (GLenum target, GLuint index, GLsizei count, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glProgramEnvParameters4fvEXT) (GLenum target, GLuint index, GLsizei count, const GLfloat *params);
    return ((PFN_glProgramEnvParameters4fvEXT)__blue_glCore_glProgramEnvParameters4fvEXT)(target, index, count, params);
}

extern void* __blue_glCore_glProgramLocalParameters4fvEXT;
void APIENTRY bluegl_glProgramLocalParameters4fvEXT (GLenum target, GLuint index, GLsizei count, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glProgramLocalParameters4fvEXT) (GLenum target, GLuint index, GLsizei count, const GLfloat *params);
    return ((PFN_glProgramLocalParameters4fvEXT)__blue_glCore_glProgramLocalParameters4fvEXT)(target, index, count, params);
}

extern void* __blue_glCore_glGetUniformuivEXT;
void APIENTRY bluegl_glGetUniformuivEXT (GLuint program, GLint location, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetUniformuivEXT) (GLuint program, GLint location, GLuint *params);
    return ((PFN_glGetUniformuivEXT)__blue_glCore_glGetUniformuivEXT)(program, location, params);
}

extern void* __blue_glCore_glBindFragDataLocationEXT;
void APIENTRY bluegl_glBindFragDataLocationEXT (GLuint program, GLuint color, const GLchar *name) {
    typedef void (APIENTRYP PFN_glBindFragDataLocationEXT) (GLuint program, GLuint color, const GLchar *name);
    return ((PFN_glBindFragDataLocationEXT)__blue_glCore_glBindFragDataLocationEXT)(program, color, name);
}

extern void* __blue_glCore_glGetFragDataLocationEXT;
GLint APIENTRY bluegl_glGetFragDataLocationEXT (GLuint program, const GLchar *name) {
    typedef GLint (APIENTRYP PFN_glGetFragDataLocationEXT) (GLuint program, const GLchar *name);
    return ((PFN_glGetFragDataLocationEXT)__blue_glCore_glGetFragDataLocationEXT)(program, name);
}

extern void* __blue_glCore_glUniform1uiEXT;
void APIENTRY bluegl_glUniform1uiEXT (GLint location, GLuint v0) {
    typedef void (APIENTRYP PFN_glUniform1uiEXT) (GLint location, GLuint v0);
    return ((PFN_glUniform1uiEXT)__blue_glCore_glUniform1uiEXT)(location, v0);
}

extern void* __blue_glCore_glUniform2uiEXT;
void APIENTRY bluegl_glUniform2uiEXT (GLint location, GLuint v0, GLuint v1) {
    typedef void (APIENTRYP PFN_glUniform2uiEXT) (GLint location, GLuint v0, GLuint v1);
    return ((PFN_glUniform2uiEXT)__blue_glCore_glUniform2uiEXT)(location, v0, v1);
}

extern void* __blue_glCore_glUniform3uiEXT;
void APIENTRY bluegl_glUniform3uiEXT (GLint location, GLuint v0, GLuint v1, GLuint v2) {
    typedef void (APIENTRYP PFN_glUniform3uiEXT) (GLint location, GLuint v0, GLuint v1, GLuint v2);
    return ((PFN_glUniform3uiEXT)__blue_glCore_glUniform3uiEXT)(location, v0, v1, v2);
}

extern void* __blue_glCore_glUniform4uiEXT;
void APIENTRY bluegl_glUniform4uiEXT (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    typedef void (APIENTRYP PFN_glUniform4uiEXT) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    return ((PFN_glUniform4uiEXT)__blue_glCore_glUniform4uiEXT)(location, v0, v1, v2, v3);
}

extern void* __blue_glCore_glUniform1uivEXT;
void APIENTRY bluegl_glUniform1uivEXT (GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glUniform1uivEXT) (GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glUniform1uivEXT)__blue_glCore_glUniform1uivEXT)(location, count, value);
}

extern void* __blue_glCore_glUniform2uivEXT;
void APIENTRY bluegl_glUniform2uivEXT (GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glUniform2uivEXT) (GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glUniform2uivEXT)__blue_glCore_glUniform2uivEXT)(location, count, value);
}

extern void* __blue_glCore_glUniform3uivEXT;
void APIENTRY bluegl_glUniform3uivEXT (GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glUniform3uivEXT) (GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glUniform3uivEXT)__blue_glCore_glUniform3uivEXT)(location, count, value);
}

extern void* __blue_glCore_glUniform4uivEXT;
void APIENTRY bluegl_glUniform4uivEXT (GLint location, GLsizei count, const GLuint *value) {
    typedef void (APIENTRYP PFN_glUniform4uivEXT) (GLint location, GLsizei count, const GLuint *value);
    return ((PFN_glUniform4uivEXT)__blue_glCore_glUniform4uivEXT)(location, count, value);
}

extern void* __blue_glCore_glGetHistogramEXT;
void APIENTRY bluegl_glGetHistogramEXT (GLenum target, GLboolean reset, GLenum format, GLenum type, void *values) {
    typedef void (APIENTRYP PFN_glGetHistogramEXT) (GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
    return ((PFN_glGetHistogramEXT)__blue_glCore_glGetHistogramEXT)(target, reset, format, type, values);
}

extern void* __blue_glCore_glGetHistogramParameterfvEXT;
void APIENTRY bluegl_glGetHistogramParameterfvEXT (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetHistogramParameterfvEXT) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetHistogramParameterfvEXT)__blue_glCore_glGetHistogramParameterfvEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetHistogramParameterivEXT;
void APIENTRY bluegl_glGetHistogramParameterivEXT (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetHistogramParameterivEXT) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetHistogramParameterivEXT)__blue_glCore_glGetHistogramParameterivEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetMinmaxEXT;
void APIENTRY bluegl_glGetMinmaxEXT (GLenum target, GLboolean reset, GLenum format, GLenum type, void *values) {
    typedef void (APIENTRYP PFN_glGetMinmaxEXT) (GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
    return ((PFN_glGetMinmaxEXT)__blue_glCore_glGetMinmaxEXT)(target, reset, format, type, values);
}

extern void* __blue_glCore_glGetMinmaxParameterfvEXT;
void APIENTRY bluegl_glGetMinmaxParameterfvEXT (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetMinmaxParameterfvEXT) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetMinmaxParameterfvEXT)__blue_glCore_glGetMinmaxParameterfvEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetMinmaxParameterivEXT;
void APIENTRY bluegl_glGetMinmaxParameterivEXT (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetMinmaxParameterivEXT) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetMinmaxParameterivEXT)__blue_glCore_glGetMinmaxParameterivEXT)(target, pname, params);
}

extern void* __blue_glCore_glHistogramEXT;
void APIENTRY bluegl_glHistogramEXT (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    typedef void (APIENTRYP PFN_glHistogramEXT) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
    return ((PFN_glHistogramEXT)__blue_glCore_glHistogramEXT)(target, width, internalformat, sink);
}

extern void* __blue_glCore_glMinmaxEXT;
void APIENTRY bluegl_glMinmaxEXT (GLenum target, GLenum internalformat, GLboolean sink) {
    typedef void (APIENTRYP PFN_glMinmaxEXT) (GLenum target, GLenum internalformat, GLboolean sink);
    return ((PFN_glMinmaxEXT)__blue_glCore_glMinmaxEXT)(target, internalformat, sink);
}

extern void* __blue_glCore_glResetHistogramEXT;
void APIENTRY bluegl_glResetHistogramEXT (GLenum target) {
    typedef void (APIENTRYP PFN_glResetHistogramEXT) (GLenum target);
    return ((PFN_glResetHistogramEXT)__blue_glCore_glResetHistogramEXT)(target);
}

extern void* __blue_glCore_glResetMinmaxEXT;
void APIENTRY bluegl_glResetMinmaxEXT (GLenum target) {
    typedef void (APIENTRYP PFN_glResetMinmaxEXT) (GLenum target);
    return ((PFN_glResetMinmaxEXT)__blue_glCore_glResetMinmaxEXT)(target);
}

extern void* __blue_glCore_glIndexFuncEXT;
void APIENTRY bluegl_glIndexFuncEXT (GLenum func, GLclampf ref) {
    typedef void (APIENTRYP PFN_glIndexFuncEXT) (GLenum func, GLclampf ref);
    return ((PFN_glIndexFuncEXT)__blue_glCore_glIndexFuncEXT)(func, ref);
}

extern void* __blue_glCore_glIndexMaterialEXT;
void APIENTRY bluegl_glIndexMaterialEXT (GLenum face, GLenum mode) {
    typedef void (APIENTRYP PFN_glIndexMaterialEXT) (GLenum face, GLenum mode);
    return ((PFN_glIndexMaterialEXT)__blue_glCore_glIndexMaterialEXT)(face, mode);
}

extern void* __blue_glCore_glApplyTextureEXT;
void APIENTRY bluegl_glApplyTextureEXT (GLenum mode) {
    typedef void (APIENTRYP PFN_glApplyTextureEXT) (GLenum mode);
    return ((PFN_glApplyTextureEXT)__blue_glCore_glApplyTextureEXT)(mode);
}

extern void* __blue_glCore_glTextureLightEXT;
void APIENTRY bluegl_glTextureLightEXT (GLenum pname) {
    typedef void (APIENTRYP PFN_glTextureLightEXT) (GLenum pname);
    return ((PFN_glTextureLightEXT)__blue_glCore_glTextureLightEXT)(pname);
}

extern void* __blue_glCore_glTextureMaterialEXT;
void APIENTRY bluegl_glTextureMaterialEXT (GLenum face, GLenum mode) {
    typedef void (APIENTRYP PFN_glTextureMaterialEXT) (GLenum face, GLenum mode);
    return ((PFN_glTextureMaterialEXT)__blue_glCore_glTextureMaterialEXT)(face, mode);
}

extern void* __blue_glCore_glMultiDrawArraysEXT;
void APIENTRY bluegl_glMultiDrawArraysEXT (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount) {
    typedef void (APIENTRYP PFN_glMultiDrawArraysEXT) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
    return ((PFN_glMultiDrawArraysEXT)__blue_glCore_glMultiDrawArraysEXT)(mode, first, count, primcount);
}

extern void* __blue_glCore_glMultiDrawElementsEXT;
void APIENTRY bluegl_glMultiDrawElementsEXT (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount) {
    typedef void (APIENTRYP PFN_glMultiDrawElementsEXT) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount);
    return ((PFN_glMultiDrawElementsEXT)__blue_glCore_glMultiDrawElementsEXT)(mode, count, type, indices, primcount);
}

extern void* __blue_glCore_glSampleMaskEXT;
void APIENTRY bluegl_glSampleMaskEXT (GLclampf value, GLboolean invert) {
    typedef void (APIENTRYP PFN_glSampleMaskEXT) (GLclampf value, GLboolean invert);
    return ((PFN_glSampleMaskEXT)__blue_glCore_glSampleMaskEXT)(value, invert);
}

extern void* __blue_glCore_glSamplePatternEXT;
void APIENTRY bluegl_glSamplePatternEXT (GLenum pattern) {
    typedef void (APIENTRYP PFN_glSamplePatternEXT) (GLenum pattern);
    return ((PFN_glSamplePatternEXT)__blue_glCore_glSamplePatternEXT)(pattern);
}

extern void* __blue_glCore_glColorTableEXT;
void APIENTRY bluegl_glColorTableEXT (GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void *table) {
    typedef void (APIENTRYP PFN_glColorTableEXT) (GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void *table);
    return ((PFN_glColorTableEXT)__blue_glCore_glColorTableEXT)(target, internalFormat, width, format, type, table);
}

extern void* __blue_glCore_glGetColorTableEXT;
void APIENTRY bluegl_glGetColorTableEXT (GLenum target, GLenum format, GLenum type, void *data) {
    typedef void (APIENTRYP PFN_glGetColorTableEXT) (GLenum target, GLenum format, GLenum type, void *data);
    return ((PFN_glGetColorTableEXT)__blue_glCore_glGetColorTableEXT)(target, format, type, data);
}

extern void* __blue_glCore_glGetColorTableParameterivEXT;
void APIENTRY bluegl_glGetColorTableParameterivEXT (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetColorTableParameterivEXT) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetColorTableParameterivEXT)__blue_glCore_glGetColorTableParameterivEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetColorTableParameterfvEXT;
void APIENTRY bluegl_glGetColorTableParameterfvEXT (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetColorTableParameterfvEXT) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetColorTableParameterfvEXT)__blue_glCore_glGetColorTableParameterfvEXT)(target, pname, params);
}

extern void* __blue_glCore_glPixelTransformParameteriEXT;
void APIENTRY bluegl_glPixelTransformParameteriEXT (GLenum target, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glPixelTransformParameteriEXT) (GLenum target, GLenum pname, GLint param);
    return ((PFN_glPixelTransformParameteriEXT)__blue_glCore_glPixelTransformParameteriEXT)(target, pname, param);
}

extern void* __blue_glCore_glPixelTransformParameterfEXT;
void APIENTRY bluegl_glPixelTransformParameterfEXT (GLenum target, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glPixelTransformParameterfEXT) (GLenum target, GLenum pname, GLfloat param);
    return ((PFN_glPixelTransformParameterfEXT)__blue_glCore_glPixelTransformParameterfEXT)(target, pname, param);
}

extern void* __blue_glCore_glPixelTransformParameterivEXT;
void APIENTRY bluegl_glPixelTransformParameterivEXT (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glPixelTransformParameterivEXT) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glPixelTransformParameterivEXT)__blue_glCore_glPixelTransformParameterivEXT)(target, pname, params);
}

extern void* __blue_glCore_glPixelTransformParameterfvEXT;
void APIENTRY bluegl_glPixelTransformParameterfvEXT (GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glPixelTransformParameterfvEXT) (GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glPixelTransformParameterfvEXT)__blue_glCore_glPixelTransformParameterfvEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetPixelTransformParameterivEXT;
void APIENTRY bluegl_glGetPixelTransformParameterivEXT (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetPixelTransformParameterivEXT) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetPixelTransformParameterivEXT)__blue_glCore_glGetPixelTransformParameterivEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetPixelTransformParameterfvEXT;
void APIENTRY bluegl_glGetPixelTransformParameterfvEXT (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetPixelTransformParameterfvEXT) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetPixelTransformParameterfvEXT)__blue_glCore_glGetPixelTransformParameterfvEXT)(target, pname, params);
}

extern void* __blue_glCore_glPointParameterfEXT;
void APIENTRY bluegl_glPointParameterfEXT (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glPointParameterfEXT) (GLenum pname, GLfloat param);
    return ((PFN_glPointParameterfEXT)__blue_glCore_glPointParameterfEXT)(pname, param);
}

extern void* __blue_glCore_glPointParameterfvEXT;
void APIENTRY bluegl_glPointParameterfvEXT (GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glPointParameterfvEXT) (GLenum pname, const GLfloat *params);
    return ((PFN_glPointParameterfvEXT)__blue_glCore_glPointParameterfvEXT)(pname, params);
}

extern void* __blue_glCore_glPolygonOffsetEXT;
void APIENTRY bluegl_glPolygonOffsetEXT (GLfloat factor, GLfloat bias) {
    typedef void (APIENTRYP PFN_glPolygonOffsetEXT) (GLfloat factor, GLfloat bias);
    return ((PFN_glPolygonOffsetEXT)__blue_glCore_glPolygonOffsetEXT)(factor, bias);
}

extern void* __blue_glCore_glPolygonOffsetClampEXT;
void APIENTRY bluegl_glPolygonOffsetClampEXT (GLfloat factor, GLfloat units, GLfloat clamp) {
    typedef void (APIENTRYP PFN_glPolygonOffsetClampEXT) (GLfloat factor, GLfloat units, GLfloat clamp);
    return ((PFN_glPolygonOffsetClampEXT)__blue_glCore_glPolygonOffsetClampEXT)(factor, units, clamp);
}

extern void* __blue_glCore_glProvokingVertexEXT;
void APIENTRY bluegl_glProvokingVertexEXT (GLenum mode) {
    typedef void (APIENTRYP PFN_glProvokingVertexEXT) (GLenum mode);
    return ((PFN_glProvokingVertexEXT)__blue_glCore_glProvokingVertexEXT)(mode);
}

extern void* __blue_glCore_glRasterSamplesEXT;
void APIENTRY bluegl_glRasterSamplesEXT (GLuint samples, GLboolean fixedsamplelocations) {
    typedef void (APIENTRYP PFN_glRasterSamplesEXT) (GLuint samples, GLboolean fixedsamplelocations);
    return ((PFN_glRasterSamplesEXT)__blue_glCore_glRasterSamplesEXT)(samples, fixedsamplelocations);
}

extern void* __blue_glCore_glSecondaryColor3bEXT;
void APIENTRY bluegl_glSecondaryColor3bEXT (GLbyte red, GLbyte green, GLbyte blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3bEXT) (GLbyte red, GLbyte green, GLbyte blue);
    return ((PFN_glSecondaryColor3bEXT)__blue_glCore_glSecondaryColor3bEXT)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3bvEXT;
void APIENTRY bluegl_glSecondaryColor3bvEXT (const GLbyte *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3bvEXT) (const GLbyte *v);
    return ((PFN_glSecondaryColor3bvEXT)__blue_glCore_glSecondaryColor3bvEXT)(v);
}

extern void* __blue_glCore_glSecondaryColor3dEXT;
void APIENTRY bluegl_glSecondaryColor3dEXT (GLdouble red, GLdouble green, GLdouble blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3dEXT) (GLdouble red, GLdouble green, GLdouble blue);
    return ((PFN_glSecondaryColor3dEXT)__blue_glCore_glSecondaryColor3dEXT)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3dvEXT;
void APIENTRY bluegl_glSecondaryColor3dvEXT (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3dvEXT) (const GLdouble *v);
    return ((PFN_glSecondaryColor3dvEXT)__blue_glCore_glSecondaryColor3dvEXT)(v);
}

extern void* __blue_glCore_glSecondaryColor3fEXT;
void APIENTRY bluegl_glSecondaryColor3fEXT (GLfloat red, GLfloat green, GLfloat blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3fEXT) (GLfloat red, GLfloat green, GLfloat blue);
    return ((PFN_glSecondaryColor3fEXT)__blue_glCore_glSecondaryColor3fEXT)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3fvEXT;
void APIENTRY bluegl_glSecondaryColor3fvEXT (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3fvEXT) (const GLfloat *v);
    return ((PFN_glSecondaryColor3fvEXT)__blue_glCore_glSecondaryColor3fvEXT)(v);
}

extern void* __blue_glCore_glSecondaryColor3iEXT;
void APIENTRY bluegl_glSecondaryColor3iEXT (GLint red, GLint green, GLint blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3iEXT) (GLint red, GLint green, GLint blue);
    return ((PFN_glSecondaryColor3iEXT)__blue_glCore_glSecondaryColor3iEXT)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3ivEXT;
void APIENTRY bluegl_glSecondaryColor3ivEXT (const GLint *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3ivEXT) (const GLint *v);
    return ((PFN_glSecondaryColor3ivEXT)__blue_glCore_glSecondaryColor3ivEXT)(v);
}

extern void* __blue_glCore_glSecondaryColor3sEXT;
void APIENTRY bluegl_glSecondaryColor3sEXT (GLshort red, GLshort green, GLshort blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3sEXT) (GLshort red, GLshort green, GLshort blue);
    return ((PFN_glSecondaryColor3sEXT)__blue_glCore_glSecondaryColor3sEXT)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3svEXT;
void APIENTRY bluegl_glSecondaryColor3svEXT (const GLshort *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3svEXT) (const GLshort *v);
    return ((PFN_glSecondaryColor3svEXT)__blue_glCore_glSecondaryColor3svEXT)(v);
}

extern void* __blue_glCore_glSecondaryColor3ubEXT;
void APIENTRY bluegl_glSecondaryColor3ubEXT (GLubyte red, GLubyte green, GLubyte blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3ubEXT) (GLubyte red, GLubyte green, GLubyte blue);
    return ((PFN_glSecondaryColor3ubEXT)__blue_glCore_glSecondaryColor3ubEXT)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3ubvEXT;
void APIENTRY bluegl_glSecondaryColor3ubvEXT (const GLubyte *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3ubvEXT) (const GLubyte *v);
    return ((PFN_glSecondaryColor3ubvEXT)__blue_glCore_glSecondaryColor3ubvEXT)(v);
}

extern void* __blue_glCore_glSecondaryColor3uiEXT;
void APIENTRY bluegl_glSecondaryColor3uiEXT (GLuint red, GLuint green, GLuint blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3uiEXT) (GLuint red, GLuint green, GLuint blue);
    return ((PFN_glSecondaryColor3uiEXT)__blue_glCore_glSecondaryColor3uiEXT)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3uivEXT;
void APIENTRY bluegl_glSecondaryColor3uivEXT (const GLuint *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3uivEXT) (const GLuint *v);
    return ((PFN_glSecondaryColor3uivEXT)__blue_glCore_glSecondaryColor3uivEXT)(v);
}

extern void* __blue_glCore_glSecondaryColor3usEXT;
void APIENTRY bluegl_glSecondaryColor3usEXT (GLushort red, GLushort green, GLushort blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3usEXT) (GLushort red, GLushort green, GLushort blue);
    return ((PFN_glSecondaryColor3usEXT)__blue_glCore_glSecondaryColor3usEXT)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3usvEXT;
void APIENTRY bluegl_glSecondaryColor3usvEXT (const GLushort *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3usvEXT) (const GLushort *v);
    return ((PFN_glSecondaryColor3usvEXT)__blue_glCore_glSecondaryColor3usvEXT)(v);
}

extern void* __blue_glCore_glSecondaryColorPointerEXT;
void APIENTRY bluegl_glSecondaryColorPointerEXT (GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glSecondaryColorPointerEXT) (GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glSecondaryColorPointerEXT)__blue_glCore_glSecondaryColorPointerEXT)(size, type, stride, pointer);
}

extern void* __blue_glCore_glUseShaderProgramEXT;
void APIENTRY bluegl_glUseShaderProgramEXT (GLenum type, GLuint program) {
    typedef void (APIENTRYP PFN_glUseShaderProgramEXT) (GLenum type, GLuint program);
    return ((PFN_glUseShaderProgramEXT)__blue_glCore_glUseShaderProgramEXT)(type, program);
}

extern void* __blue_glCore_glActiveProgramEXT;
void APIENTRY bluegl_glActiveProgramEXT (GLuint program) {
    typedef void (APIENTRYP PFN_glActiveProgramEXT) (GLuint program);
    return ((PFN_glActiveProgramEXT)__blue_glCore_glActiveProgramEXT)(program);
}

extern void* __blue_glCore_glCreateShaderProgramEXT;
GLuint APIENTRY bluegl_glCreateShaderProgramEXT (GLenum type, const GLchar *string) {
    typedef GLuint (APIENTRYP PFN_glCreateShaderProgramEXT) (GLenum type, const GLchar *string);
    return ((PFN_glCreateShaderProgramEXT)__blue_glCore_glCreateShaderProgramEXT)(type, string);
}

extern void* __blue_glCore_glBindImageTextureEXT;
void APIENTRY bluegl_glBindImageTextureEXT (GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format) {
    typedef void (APIENTRYP PFN_glBindImageTextureEXT) (GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
    return ((PFN_glBindImageTextureEXT)__blue_glCore_glBindImageTextureEXT)(index, texture, level, layered, layer, access, format);
}

extern void* __blue_glCore_glMemoryBarrierEXT;
void APIENTRY bluegl_glMemoryBarrierEXT (GLbitfield barriers) {
    typedef void (APIENTRYP PFN_glMemoryBarrierEXT) (GLbitfield barriers);
    return ((PFN_glMemoryBarrierEXT)__blue_glCore_glMemoryBarrierEXT)(barriers);
}

extern void* __blue_glCore_glStencilClearTagEXT;
void APIENTRY bluegl_glStencilClearTagEXT (GLsizei stencilTagBits, GLuint stencilClearTag) {
    typedef void (APIENTRYP PFN_glStencilClearTagEXT) (GLsizei stencilTagBits, GLuint stencilClearTag);
    return ((PFN_glStencilClearTagEXT)__blue_glCore_glStencilClearTagEXT)(stencilTagBits, stencilClearTag);
}

extern void* __blue_glCore_glActiveStencilFaceEXT;
void APIENTRY bluegl_glActiveStencilFaceEXT (GLenum face) {
    typedef void (APIENTRYP PFN_glActiveStencilFaceEXT) (GLenum face);
    return ((PFN_glActiveStencilFaceEXT)__blue_glCore_glActiveStencilFaceEXT)(face);
}

extern void* __blue_glCore_glTexSubImage1DEXT;
void APIENTRY bluegl_glTexSubImage1DEXT (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexSubImage1DEXT) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexSubImage1DEXT)__blue_glCore_glTexSubImage1DEXT)(target, level, xoffset, width, format, type, pixels);
}

extern void* __blue_glCore_glTexSubImage2DEXT;
void APIENTRY bluegl_glTexSubImage2DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexSubImage2DEXT) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexSubImage2DEXT)__blue_glCore_glTexSubImage2DEXT)(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

extern void* __blue_glCore_glTexImage3DEXT;
void APIENTRY bluegl_glTexImage3DEXT (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexImage3DEXT) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexImage3DEXT)__blue_glCore_glTexImage3DEXT)(target, level, internalformat, width, height, depth, border, format, type, pixels);
}

extern void* __blue_glCore_glTexSubImage3DEXT;
void APIENTRY bluegl_glTexSubImage3DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexSubImage3DEXT) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexSubImage3DEXT)__blue_glCore_glTexSubImage3DEXT)(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

extern void* __blue_glCore_glFramebufferTextureLayerEXT;
void APIENTRY bluegl_glFramebufferTextureLayerEXT (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    typedef void (APIENTRYP PFN_glFramebufferTextureLayerEXT) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
    return ((PFN_glFramebufferTextureLayerEXT)__blue_glCore_glFramebufferTextureLayerEXT)(target, attachment, texture, level, layer);
}

extern void* __blue_glCore_glTexBufferEXT;
void APIENTRY bluegl_glTexBufferEXT (GLenum target, GLenum internalformat, GLuint buffer) {
    typedef void (APIENTRYP PFN_glTexBufferEXT) (GLenum target, GLenum internalformat, GLuint buffer);
    return ((PFN_glTexBufferEXT)__blue_glCore_glTexBufferEXT)(target, internalformat, buffer);
}

extern void* __blue_glCore_glTexParameterIivEXT;
void APIENTRY bluegl_glTexParameterIivEXT (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glTexParameterIivEXT) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glTexParameterIivEXT)__blue_glCore_glTexParameterIivEXT)(target, pname, params);
}

extern void* __blue_glCore_glTexParameterIuivEXT;
void APIENTRY bluegl_glTexParameterIuivEXT (GLenum target, GLenum pname, const GLuint *params) {
    typedef void (APIENTRYP PFN_glTexParameterIuivEXT) (GLenum target, GLenum pname, const GLuint *params);
    return ((PFN_glTexParameterIuivEXT)__blue_glCore_glTexParameterIuivEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetTexParameterIivEXT;
void APIENTRY bluegl_glGetTexParameterIivEXT (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTexParameterIivEXT) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetTexParameterIivEXT)__blue_glCore_glGetTexParameterIivEXT)(target, pname, params);
}

extern void* __blue_glCore_glGetTexParameterIuivEXT;
void APIENTRY bluegl_glGetTexParameterIuivEXT (GLenum target, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetTexParameterIuivEXT) (GLenum target, GLenum pname, GLuint *params);
    return ((PFN_glGetTexParameterIuivEXT)__blue_glCore_glGetTexParameterIuivEXT)(target, pname, params);
}

extern void* __blue_glCore_glClearColorIiEXT;
void APIENTRY bluegl_glClearColorIiEXT (GLint red, GLint green, GLint blue, GLint alpha) {
    typedef void (APIENTRYP PFN_glClearColorIiEXT) (GLint red, GLint green, GLint blue, GLint alpha);
    return ((PFN_glClearColorIiEXT)__blue_glCore_glClearColorIiEXT)(red, green, blue, alpha);
}

extern void* __blue_glCore_glClearColorIuiEXT;
void APIENTRY bluegl_glClearColorIuiEXT (GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    typedef void (APIENTRYP PFN_glClearColorIuiEXT) (GLuint red, GLuint green, GLuint blue, GLuint alpha);
    return ((PFN_glClearColorIuiEXT)__blue_glCore_glClearColorIuiEXT)(red, green, blue, alpha);
}

extern void* __blue_glCore_glAreTexturesResidentEXT;
GLboolean APIENTRY bluegl_glAreTexturesResidentEXT (GLsizei n, const GLuint *textures, GLboolean *residences) {
    typedef GLboolean (APIENTRYP PFN_glAreTexturesResidentEXT) (GLsizei n, const GLuint *textures, GLboolean *residences);
    return ((PFN_glAreTexturesResidentEXT)__blue_glCore_glAreTexturesResidentEXT)(n, textures, residences);
}

extern void* __blue_glCore_glBindTextureEXT;
void APIENTRY bluegl_glBindTextureEXT (GLenum target, GLuint texture) {
    typedef void (APIENTRYP PFN_glBindTextureEXT) (GLenum target, GLuint texture);
    return ((PFN_glBindTextureEXT)__blue_glCore_glBindTextureEXT)(target, texture);
}

extern void* __blue_glCore_glDeleteTexturesEXT;
void APIENTRY bluegl_glDeleteTexturesEXT (GLsizei n, const GLuint *textures) {
    typedef void (APIENTRYP PFN_glDeleteTexturesEXT) (GLsizei n, const GLuint *textures);
    return ((PFN_glDeleteTexturesEXT)__blue_glCore_glDeleteTexturesEXT)(n, textures);
}

extern void* __blue_glCore_glGenTexturesEXT;
void APIENTRY bluegl_glGenTexturesEXT (GLsizei n, GLuint *textures) {
    typedef void (APIENTRYP PFN_glGenTexturesEXT) (GLsizei n, GLuint *textures);
    return ((PFN_glGenTexturesEXT)__blue_glCore_glGenTexturesEXT)(n, textures);
}

extern void* __blue_glCore_glIsTextureEXT;
GLboolean APIENTRY bluegl_glIsTextureEXT (GLuint texture) {
    typedef GLboolean (APIENTRYP PFN_glIsTextureEXT) (GLuint texture);
    return ((PFN_glIsTextureEXT)__blue_glCore_glIsTextureEXT)(texture);
}

extern void* __blue_glCore_glPrioritizeTexturesEXT;
void APIENTRY bluegl_glPrioritizeTexturesEXT (GLsizei n, const GLuint *textures, const GLclampf *priorities) {
    typedef void (APIENTRYP PFN_glPrioritizeTexturesEXT) (GLsizei n, const GLuint *textures, const GLclampf *priorities);
    return ((PFN_glPrioritizeTexturesEXT)__blue_glCore_glPrioritizeTexturesEXT)(n, textures, priorities);
}

extern void* __blue_glCore_glTextureNormalEXT;
void APIENTRY bluegl_glTextureNormalEXT (GLenum mode) {
    typedef void (APIENTRYP PFN_glTextureNormalEXT) (GLenum mode);
    return ((PFN_glTextureNormalEXT)__blue_glCore_glTextureNormalEXT)(mode);
}

extern void* __blue_glCore_glGetQueryObjecti64vEXT;
void APIENTRY bluegl_glGetQueryObjecti64vEXT (GLuint id, GLenum pname, GLint64 *params) {
    typedef void (APIENTRYP PFN_glGetQueryObjecti64vEXT) (GLuint id, GLenum pname, GLint64 *params);
    return ((PFN_glGetQueryObjecti64vEXT)__blue_glCore_glGetQueryObjecti64vEXT)(id, pname, params);
}

extern void* __blue_glCore_glGetQueryObjectui64vEXT;
void APIENTRY bluegl_glGetQueryObjectui64vEXT (GLuint id, GLenum pname, GLuint64 *params) {
    typedef void (APIENTRYP PFN_glGetQueryObjectui64vEXT) (GLuint id, GLenum pname, GLuint64 *params);
    return ((PFN_glGetQueryObjectui64vEXT)__blue_glCore_glGetQueryObjectui64vEXT)(id, pname, params);
}

extern void* __blue_glCore_glBeginTransformFeedbackEXT;
void APIENTRY bluegl_glBeginTransformFeedbackEXT (GLenum primitiveMode) {
    typedef void (APIENTRYP PFN_glBeginTransformFeedbackEXT) (GLenum primitiveMode);
    return ((PFN_glBeginTransformFeedbackEXT)__blue_glCore_glBeginTransformFeedbackEXT)(primitiveMode);
}

extern void* __blue_glCore_glEndTransformFeedbackEXT;
void APIENTRY bluegl_glEndTransformFeedbackEXT (void) {
    typedef void (APIENTRYP PFN_glEndTransformFeedbackEXT) (void);
    return ((PFN_glEndTransformFeedbackEXT)__blue_glCore_glEndTransformFeedbackEXT)();
}

extern void* __blue_glCore_glBindBufferRangeEXT;
void APIENTRY bluegl_glBindBufferRangeEXT (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glBindBufferRangeEXT) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    return ((PFN_glBindBufferRangeEXT)__blue_glCore_glBindBufferRangeEXT)(target, index, buffer, offset, size);
}

extern void* __blue_glCore_glBindBufferOffsetEXT;
void APIENTRY bluegl_glBindBufferOffsetEXT (GLenum target, GLuint index, GLuint buffer, GLintptr offset) {
    typedef void (APIENTRYP PFN_glBindBufferOffsetEXT) (GLenum target, GLuint index, GLuint buffer, GLintptr offset);
    return ((PFN_glBindBufferOffsetEXT)__blue_glCore_glBindBufferOffsetEXT)(target, index, buffer, offset);
}

extern void* __blue_glCore_glBindBufferBaseEXT;
void APIENTRY bluegl_glBindBufferBaseEXT (GLenum target, GLuint index, GLuint buffer) {
    typedef void (APIENTRYP PFN_glBindBufferBaseEXT) (GLenum target, GLuint index, GLuint buffer);
    return ((PFN_glBindBufferBaseEXT)__blue_glCore_glBindBufferBaseEXT)(target, index, buffer);
}

extern void* __blue_glCore_glTransformFeedbackVaryingsEXT;
void APIENTRY bluegl_glTransformFeedbackVaryingsEXT (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) {
    typedef void (APIENTRYP PFN_glTransformFeedbackVaryingsEXT) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
    return ((PFN_glTransformFeedbackVaryingsEXT)__blue_glCore_glTransformFeedbackVaryingsEXT)(program, count, varyings, bufferMode);
}

extern void* __blue_glCore_glGetTransformFeedbackVaryingEXT;
void APIENTRY bluegl_glGetTransformFeedbackVaryingEXT (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) {
    typedef void (APIENTRYP PFN_glGetTransformFeedbackVaryingEXT) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
    return ((PFN_glGetTransformFeedbackVaryingEXT)__blue_glCore_glGetTransformFeedbackVaryingEXT)(program, index, bufSize, length, size, type, name);
}

extern void* __blue_glCore_glArrayElementEXT;
void APIENTRY bluegl_glArrayElementEXT (GLint i) {
    typedef void (APIENTRYP PFN_glArrayElementEXT) (GLint i);
    return ((PFN_glArrayElementEXT)__blue_glCore_glArrayElementEXT)(i);
}

extern void* __blue_glCore_glColorPointerEXT;
void APIENTRY bluegl_glColorPointerEXT (GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer) {
    typedef void (APIENTRYP PFN_glColorPointerEXT) (GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
    return ((PFN_glColorPointerEXT)__blue_glCore_glColorPointerEXT)(size, type, stride, count, pointer);
}

extern void* __blue_glCore_glDrawArraysEXT;
void APIENTRY bluegl_glDrawArraysEXT (GLenum mode, GLint first, GLsizei count) {
    typedef void (APIENTRYP PFN_glDrawArraysEXT) (GLenum mode, GLint first, GLsizei count);
    return ((PFN_glDrawArraysEXT)__blue_glCore_glDrawArraysEXT)(mode, first, count);
}

extern void* __blue_glCore_glEdgeFlagPointerEXT;
void APIENTRY bluegl_glEdgeFlagPointerEXT (GLsizei stride, GLsizei count, const GLboolean *pointer) {
    typedef void (APIENTRYP PFN_glEdgeFlagPointerEXT) (GLsizei stride, GLsizei count, const GLboolean *pointer);
    return ((PFN_glEdgeFlagPointerEXT)__blue_glCore_glEdgeFlagPointerEXT)(stride, count, pointer);
}

extern void* __blue_glCore_glGetPointervEXT;
void APIENTRY bluegl_glGetPointervEXT (GLenum pname, void **params) {
    typedef void (APIENTRYP PFN_glGetPointervEXT) (GLenum pname, void **params);
    return ((PFN_glGetPointervEXT)__blue_glCore_glGetPointervEXT)(pname, params);
}

extern void* __blue_glCore_glIndexPointerEXT;
void APIENTRY bluegl_glIndexPointerEXT (GLenum type, GLsizei stride, GLsizei count, const void *pointer) {
    typedef void (APIENTRYP PFN_glIndexPointerEXT) (GLenum type, GLsizei stride, GLsizei count, const void *pointer);
    return ((PFN_glIndexPointerEXT)__blue_glCore_glIndexPointerEXT)(type, stride, count, pointer);
}

extern void* __blue_glCore_glNormalPointerEXT;
void APIENTRY bluegl_glNormalPointerEXT (GLenum type, GLsizei stride, GLsizei count, const void *pointer) {
    typedef void (APIENTRYP PFN_glNormalPointerEXT) (GLenum type, GLsizei stride, GLsizei count, const void *pointer);
    return ((PFN_glNormalPointerEXT)__blue_glCore_glNormalPointerEXT)(type, stride, count, pointer);
}

extern void* __blue_glCore_glTexCoordPointerEXT;
void APIENTRY bluegl_glTexCoordPointerEXT (GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer) {
    typedef void (APIENTRYP PFN_glTexCoordPointerEXT) (GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
    return ((PFN_glTexCoordPointerEXT)__blue_glCore_glTexCoordPointerEXT)(size, type, stride, count, pointer);
}

extern void* __blue_glCore_glVertexPointerEXT;
void APIENTRY bluegl_glVertexPointerEXT (GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexPointerEXT) (GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
    return ((PFN_glVertexPointerEXT)__blue_glCore_glVertexPointerEXT)(size, type, stride, count, pointer);
}

extern void* __blue_glCore_glVertexAttribL1dEXT;
void APIENTRY bluegl_glVertexAttribL1dEXT (GLuint index, GLdouble x) {
    typedef void (APIENTRYP PFN_glVertexAttribL1dEXT) (GLuint index, GLdouble x);
    return ((PFN_glVertexAttribL1dEXT)__blue_glCore_glVertexAttribL1dEXT)(index, x);
}

extern void* __blue_glCore_glVertexAttribL2dEXT;
void APIENTRY bluegl_glVertexAttribL2dEXT (GLuint index, GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glVertexAttribL2dEXT) (GLuint index, GLdouble x, GLdouble y);
    return ((PFN_glVertexAttribL2dEXT)__blue_glCore_glVertexAttribL2dEXT)(index, x, y);
}

extern void* __blue_glCore_glVertexAttribL3dEXT;
void APIENTRY bluegl_glVertexAttribL3dEXT (GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glVertexAttribL3dEXT) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glVertexAttribL3dEXT)__blue_glCore_glVertexAttribL3dEXT)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttribL4dEXT;
void APIENTRY bluegl_glVertexAttribL4dEXT (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glVertexAttribL4dEXT) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glVertexAttribL4dEXT)__blue_glCore_glVertexAttribL4dEXT)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttribL1dvEXT;
void APIENTRY bluegl_glVertexAttribL1dvEXT (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL1dvEXT) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttribL1dvEXT)__blue_glCore_glVertexAttribL1dvEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribL2dvEXT;
void APIENTRY bluegl_glVertexAttribL2dvEXT (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL2dvEXT) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttribL2dvEXT)__blue_glCore_glVertexAttribL2dvEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribL3dvEXT;
void APIENTRY bluegl_glVertexAttribL3dvEXT (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL3dvEXT) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttribL3dvEXT)__blue_glCore_glVertexAttribL3dvEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribL4dvEXT;
void APIENTRY bluegl_glVertexAttribL4dvEXT (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL4dvEXT) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttribL4dvEXT)__blue_glCore_glVertexAttribL4dvEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribLPointerEXT;
void APIENTRY bluegl_glVertexAttribLPointerEXT (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexAttribLPointerEXT) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glVertexAttribLPointerEXT)__blue_glCore_glVertexAttribLPointerEXT)(index, size, type, stride, pointer);
}

extern void* __blue_glCore_glGetVertexAttribLdvEXT;
void APIENTRY bluegl_glGetVertexAttribLdvEXT (GLuint index, GLenum pname, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribLdvEXT) (GLuint index, GLenum pname, GLdouble *params);
    return ((PFN_glGetVertexAttribLdvEXT)__blue_glCore_glGetVertexAttribLdvEXT)(index, pname, params);
}

extern void* __blue_glCore_glBeginVertexShaderEXT;
void APIENTRY bluegl_glBeginVertexShaderEXT (void) {
    typedef void (APIENTRYP PFN_glBeginVertexShaderEXT) (void);
    return ((PFN_glBeginVertexShaderEXT)__blue_glCore_glBeginVertexShaderEXT)();
}

extern void* __blue_glCore_glEndVertexShaderEXT;
void APIENTRY bluegl_glEndVertexShaderEXT (void) {
    typedef void (APIENTRYP PFN_glEndVertexShaderEXT) (void);
    return ((PFN_glEndVertexShaderEXT)__blue_glCore_glEndVertexShaderEXT)();
}

extern void* __blue_glCore_glBindVertexShaderEXT;
void APIENTRY bluegl_glBindVertexShaderEXT (GLuint id) {
    typedef void (APIENTRYP PFN_glBindVertexShaderEXT) (GLuint id);
    return ((PFN_glBindVertexShaderEXT)__blue_glCore_glBindVertexShaderEXT)(id);
}

extern void* __blue_glCore_glGenVertexShadersEXT;
GLuint APIENTRY bluegl_glGenVertexShadersEXT (GLuint range) {
    typedef GLuint (APIENTRYP PFN_glGenVertexShadersEXT) (GLuint range);
    return ((PFN_glGenVertexShadersEXT)__blue_glCore_glGenVertexShadersEXT)(range);
}

extern void* __blue_glCore_glDeleteVertexShaderEXT;
void APIENTRY bluegl_glDeleteVertexShaderEXT (GLuint id) {
    typedef void (APIENTRYP PFN_glDeleteVertexShaderEXT) (GLuint id);
    return ((PFN_glDeleteVertexShaderEXT)__blue_glCore_glDeleteVertexShaderEXT)(id);
}

extern void* __blue_glCore_glShaderOp1EXT;
void APIENTRY bluegl_glShaderOp1EXT (GLenum op, GLuint res, GLuint arg1) {
    typedef void (APIENTRYP PFN_glShaderOp1EXT) (GLenum op, GLuint res, GLuint arg1);
    return ((PFN_glShaderOp1EXT)__blue_glCore_glShaderOp1EXT)(op, res, arg1);
}

extern void* __blue_glCore_glShaderOp2EXT;
void APIENTRY bluegl_glShaderOp2EXT (GLenum op, GLuint res, GLuint arg1, GLuint arg2) {
    typedef void (APIENTRYP PFN_glShaderOp2EXT) (GLenum op, GLuint res, GLuint arg1, GLuint arg2);
    return ((PFN_glShaderOp2EXT)__blue_glCore_glShaderOp2EXT)(op, res, arg1, arg2);
}

extern void* __blue_glCore_glShaderOp3EXT;
void APIENTRY bluegl_glShaderOp3EXT (GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3) {
    typedef void (APIENTRYP PFN_glShaderOp3EXT) (GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
    return ((PFN_glShaderOp3EXT)__blue_glCore_glShaderOp3EXT)(op, res, arg1, arg2, arg3);
}

extern void* __blue_glCore_glSwizzleEXT;
void APIENTRY bluegl_glSwizzleEXT (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
    typedef void (APIENTRYP PFN_glSwizzleEXT) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
    return ((PFN_glSwizzleEXT)__blue_glCore_glSwizzleEXT)(res, in, outX, outY, outZ, outW);
}

extern void* __blue_glCore_glWriteMaskEXT;
void APIENTRY bluegl_glWriteMaskEXT (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
    typedef void (APIENTRYP PFN_glWriteMaskEXT) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
    return ((PFN_glWriteMaskEXT)__blue_glCore_glWriteMaskEXT)(res, in, outX, outY, outZ, outW);
}

extern void* __blue_glCore_glInsertComponentEXT;
void APIENTRY bluegl_glInsertComponentEXT (GLuint res, GLuint src, GLuint num) {
    typedef void (APIENTRYP PFN_glInsertComponentEXT) (GLuint res, GLuint src, GLuint num);
    return ((PFN_glInsertComponentEXT)__blue_glCore_glInsertComponentEXT)(res, src, num);
}

extern void* __blue_glCore_glExtractComponentEXT;
void APIENTRY bluegl_glExtractComponentEXT (GLuint res, GLuint src, GLuint num) {
    typedef void (APIENTRYP PFN_glExtractComponentEXT) (GLuint res, GLuint src, GLuint num);
    return ((PFN_glExtractComponentEXT)__blue_glCore_glExtractComponentEXT)(res, src, num);
}

extern void* __blue_glCore_glGenSymbolsEXT;
GLuint APIENTRY bluegl_glGenSymbolsEXT (GLenum datatype, GLenum storagetype, GLenum range, GLuint components) {
    typedef GLuint (APIENTRYP PFN_glGenSymbolsEXT) (GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
    return ((PFN_glGenSymbolsEXT)__blue_glCore_glGenSymbolsEXT)(datatype, storagetype, range, components);
}

extern void* __blue_glCore_glSetInvariantEXT;
void APIENTRY bluegl_glSetInvariantEXT (GLuint id, GLenum type, const void *addr) {
    typedef void (APIENTRYP PFN_glSetInvariantEXT) (GLuint id, GLenum type, const void *addr);
    return ((PFN_glSetInvariantEXT)__blue_glCore_glSetInvariantEXT)(id, type, addr);
}

extern void* __blue_glCore_glSetLocalConstantEXT;
void APIENTRY bluegl_glSetLocalConstantEXT (GLuint id, GLenum type, const void *addr) {
    typedef void (APIENTRYP PFN_glSetLocalConstantEXT) (GLuint id, GLenum type, const void *addr);
    return ((PFN_glSetLocalConstantEXT)__blue_glCore_glSetLocalConstantEXT)(id, type, addr);
}

extern void* __blue_glCore_glVariantbvEXT;
void APIENTRY bluegl_glVariantbvEXT (GLuint id, const GLbyte *addr) {
    typedef void (APIENTRYP PFN_glVariantbvEXT) (GLuint id, const GLbyte *addr);
    return ((PFN_glVariantbvEXT)__blue_glCore_glVariantbvEXT)(id, addr);
}

extern void* __blue_glCore_glVariantsvEXT;
void APIENTRY bluegl_glVariantsvEXT (GLuint id, const GLshort *addr) {
    typedef void (APIENTRYP PFN_glVariantsvEXT) (GLuint id, const GLshort *addr);
    return ((PFN_glVariantsvEXT)__blue_glCore_glVariantsvEXT)(id, addr);
}

extern void* __blue_glCore_glVariantivEXT;
void APIENTRY bluegl_glVariantivEXT (GLuint id, const GLint *addr) {
    typedef void (APIENTRYP PFN_glVariantivEXT) (GLuint id, const GLint *addr);
    return ((PFN_glVariantivEXT)__blue_glCore_glVariantivEXT)(id, addr);
}

extern void* __blue_glCore_glVariantfvEXT;
void APIENTRY bluegl_glVariantfvEXT (GLuint id, const GLfloat *addr) {
    typedef void (APIENTRYP PFN_glVariantfvEXT) (GLuint id, const GLfloat *addr);
    return ((PFN_glVariantfvEXT)__blue_glCore_glVariantfvEXT)(id, addr);
}

extern void* __blue_glCore_glVariantdvEXT;
void APIENTRY bluegl_glVariantdvEXT (GLuint id, const GLdouble *addr) {
    typedef void (APIENTRYP PFN_glVariantdvEXT) (GLuint id, const GLdouble *addr);
    return ((PFN_glVariantdvEXT)__blue_glCore_glVariantdvEXT)(id, addr);
}

extern void* __blue_glCore_glVariantubvEXT;
void APIENTRY bluegl_glVariantubvEXT (GLuint id, const GLubyte *addr) {
    typedef void (APIENTRYP PFN_glVariantubvEXT) (GLuint id, const GLubyte *addr);
    return ((PFN_glVariantubvEXT)__blue_glCore_glVariantubvEXT)(id, addr);
}

extern void* __blue_glCore_glVariantusvEXT;
void APIENTRY bluegl_glVariantusvEXT (GLuint id, const GLushort *addr) {
    typedef void (APIENTRYP PFN_glVariantusvEXT) (GLuint id, const GLushort *addr);
    return ((PFN_glVariantusvEXT)__blue_glCore_glVariantusvEXT)(id, addr);
}

extern void* __blue_glCore_glVariantuivEXT;
void APIENTRY bluegl_glVariantuivEXT (GLuint id, const GLuint *addr) {
    typedef void (APIENTRYP PFN_glVariantuivEXT) (GLuint id, const GLuint *addr);
    return ((PFN_glVariantuivEXT)__blue_glCore_glVariantuivEXT)(id, addr);
}

extern void* __blue_glCore_glVariantPointerEXT;
void APIENTRY bluegl_glVariantPointerEXT (GLuint id, GLenum type, GLuint stride, const void *addr) {
    typedef void (APIENTRYP PFN_glVariantPointerEXT) (GLuint id, GLenum type, GLuint stride, const void *addr);
    return ((PFN_glVariantPointerEXT)__blue_glCore_glVariantPointerEXT)(id, type, stride, addr);
}

extern void* __blue_glCore_glEnableVariantClientStateEXT;
void APIENTRY bluegl_glEnableVariantClientStateEXT (GLuint id) {
    typedef void (APIENTRYP PFN_glEnableVariantClientStateEXT) (GLuint id);
    return ((PFN_glEnableVariantClientStateEXT)__blue_glCore_glEnableVariantClientStateEXT)(id);
}

extern void* __blue_glCore_glDisableVariantClientStateEXT;
void APIENTRY bluegl_glDisableVariantClientStateEXT (GLuint id) {
    typedef void (APIENTRYP PFN_glDisableVariantClientStateEXT) (GLuint id);
    return ((PFN_glDisableVariantClientStateEXT)__blue_glCore_glDisableVariantClientStateEXT)(id);
}

extern void* __blue_glCore_glBindLightParameterEXT;
GLuint APIENTRY bluegl_glBindLightParameterEXT (GLenum light, GLenum value) {
    typedef GLuint (APIENTRYP PFN_glBindLightParameterEXT) (GLenum light, GLenum value);
    return ((PFN_glBindLightParameterEXT)__blue_glCore_glBindLightParameterEXT)(light, value);
}

extern void* __blue_glCore_glBindMaterialParameterEXT;
GLuint APIENTRY bluegl_glBindMaterialParameterEXT (GLenum face, GLenum value) {
    typedef GLuint (APIENTRYP PFN_glBindMaterialParameterEXT) (GLenum face, GLenum value);
    return ((PFN_glBindMaterialParameterEXT)__blue_glCore_glBindMaterialParameterEXT)(face, value);
}

extern void* __blue_glCore_glBindTexGenParameterEXT;
GLuint APIENTRY bluegl_glBindTexGenParameterEXT (GLenum unit, GLenum coord, GLenum value) {
    typedef GLuint (APIENTRYP PFN_glBindTexGenParameterEXT) (GLenum unit, GLenum coord, GLenum value);
    return ((PFN_glBindTexGenParameterEXT)__blue_glCore_glBindTexGenParameterEXT)(unit, coord, value);
}

extern void* __blue_glCore_glBindTextureUnitParameterEXT;
GLuint APIENTRY bluegl_glBindTextureUnitParameterEXT (GLenum unit, GLenum value) {
    typedef GLuint (APIENTRYP PFN_glBindTextureUnitParameterEXT) (GLenum unit, GLenum value);
    return ((PFN_glBindTextureUnitParameterEXT)__blue_glCore_glBindTextureUnitParameterEXT)(unit, value);
}

extern void* __blue_glCore_glBindParameterEXT;
GLuint APIENTRY bluegl_glBindParameterEXT (GLenum value) {
    typedef GLuint (APIENTRYP PFN_glBindParameterEXT) (GLenum value);
    return ((PFN_glBindParameterEXT)__blue_glCore_glBindParameterEXT)(value);
}

extern void* __blue_glCore_glIsVariantEnabledEXT;
GLboolean APIENTRY bluegl_glIsVariantEnabledEXT (GLuint id, GLenum cap) {
    typedef GLboolean (APIENTRYP PFN_glIsVariantEnabledEXT) (GLuint id, GLenum cap);
    return ((PFN_glIsVariantEnabledEXT)__blue_glCore_glIsVariantEnabledEXT)(id, cap);
}

extern void* __blue_glCore_glGetVariantBooleanvEXT;
void APIENTRY bluegl_glGetVariantBooleanvEXT (GLuint id, GLenum value, GLboolean *data) {
    typedef void (APIENTRYP PFN_glGetVariantBooleanvEXT) (GLuint id, GLenum value, GLboolean *data);
    return ((PFN_glGetVariantBooleanvEXT)__blue_glCore_glGetVariantBooleanvEXT)(id, value, data);
}

extern void* __blue_glCore_glGetVariantIntegervEXT;
void APIENTRY bluegl_glGetVariantIntegervEXT (GLuint id, GLenum value, GLint *data) {
    typedef void (APIENTRYP PFN_glGetVariantIntegervEXT) (GLuint id, GLenum value, GLint *data);
    return ((PFN_glGetVariantIntegervEXT)__blue_glCore_glGetVariantIntegervEXT)(id, value, data);
}

extern void* __blue_glCore_glGetVariantFloatvEXT;
void APIENTRY bluegl_glGetVariantFloatvEXT (GLuint id, GLenum value, GLfloat *data) {
    typedef void (APIENTRYP PFN_glGetVariantFloatvEXT) (GLuint id, GLenum value, GLfloat *data);
    return ((PFN_glGetVariantFloatvEXT)__blue_glCore_glGetVariantFloatvEXT)(id, value, data);
}

extern void* __blue_glCore_glGetVariantPointervEXT;
void APIENTRY bluegl_glGetVariantPointervEXT (GLuint id, GLenum value, void **data) {
    typedef void (APIENTRYP PFN_glGetVariantPointervEXT) (GLuint id, GLenum value, void **data);
    return ((PFN_glGetVariantPointervEXT)__blue_glCore_glGetVariantPointervEXT)(id, value, data);
}

extern void* __blue_glCore_glGetInvariantBooleanvEXT;
void APIENTRY bluegl_glGetInvariantBooleanvEXT (GLuint id, GLenum value, GLboolean *data) {
    typedef void (APIENTRYP PFN_glGetInvariantBooleanvEXT) (GLuint id, GLenum value, GLboolean *data);
    return ((PFN_glGetInvariantBooleanvEXT)__blue_glCore_glGetInvariantBooleanvEXT)(id, value, data);
}

extern void* __blue_glCore_glGetInvariantIntegervEXT;
void APIENTRY bluegl_glGetInvariantIntegervEXT (GLuint id, GLenum value, GLint *data) {
    typedef void (APIENTRYP PFN_glGetInvariantIntegervEXT) (GLuint id, GLenum value, GLint *data);
    return ((PFN_glGetInvariantIntegervEXT)__blue_glCore_glGetInvariantIntegervEXT)(id, value, data);
}

extern void* __blue_glCore_glGetInvariantFloatvEXT;
void APIENTRY bluegl_glGetInvariantFloatvEXT (GLuint id, GLenum value, GLfloat *data) {
    typedef void (APIENTRYP PFN_glGetInvariantFloatvEXT) (GLuint id, GLenum value, GLfloat *data);
    return ((PFN_glGetInvariantFloatvEXT)__blue_glCore_glGetInvariantFloatvEXT)(id, value, data);
}

extern void* __blue_glCore_glGetLocalConstantBooleanvEXT;
void APIENTRY bluegl_glGetLocalConstantBooleanvEXT (GLuint id, GLenum value, GLboolean *data) {
    typedef void (APIENTRYP PFN_glGetLocalConstantBooleanvEXT) (GLuint id, GLenum value, GLboolean *data);
    return ((PFN_glGetLocalConstantBooleanvEXT)__blue_glCore_glGetLocalConstantBooleanvEXT)(id, value, data);
}

extern void* __blue_glCore_glGetLocalConstantIntegervEXT;
void APIENTRY bluegl_glGetLocalConstantIntegervEXT (GLuint id, GLenum value, GLint *data) {
    typedef void (APIENTRYP PFN_glGetLocalConstantIntegervEXT) (GLuint id, GLenum value, GLint *data);
    return ((PFN_glGetLocalConstantIntegervEXT)__blue_glCore_glGetLocalConstantIntegervEXT)(id, value, data);
}

extern void* __blue_glCore_glGetLocalConstantFloatvEXT;
void APIENTRY bluegl_glGetLocalConstantFloatvEXT (GLuint id, GLenum value, GLfloat *data) {
    typedef void (APIENTRYP PFN_glGetLocalConstantFloatvEXT) (GLuint id, GLenum value, GLfloat *data);
    return ((PFN_glGetLocalConstantFloatvEXT)__blue_glCore_glGetLocalConstantFloatvEXT)(id, value, data);
}

extern void* __blue_glCore_glVertexWeightfEXT;
void APIENTRY bluegl_glVertexWeightfEXT (GLfloat weight) {
    typedef void (APIENTRYP PFN_glVertexWeightfEXT) (GLfloat weight);
    return ((PFN_glVertexWeightfEXT)__blue_glCore_glVertexWeightfEXT)(weight);
}

extern void* __blue_glCore_glVertexWeightfvEXT;
void APIENTRY bluegl_glVertexWeightfvEXT (const GLfloat *weight) {
    typedef void (APIENTRYP PFN_glVertexWeightfvEXT) (const GLfloat *weight);
    return ((PFN_glVertexWeightfvEXT)__blue_glCore_glVertexWeightfvEXT)(weight);
}

extern void* __blue_glCore_glVertexWeightPointerEXT;
void APIENTRY bluegl_glVertexWeightPointerEXT (GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexWeightPointerEXT) (GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glVertexWeightPointerEXT)__blue_glCore_glVertexWeightPointerEXT)(size, type, stride, pointer);
}

extern void* __blue_glCore_glImportSyncEXT;
GLsync APIENTRY bluegl_glImportSyncEXT (GLenum external_sync_type, GLintptr external_sync, GLbitfield flags) {
    typedef GLsync (APIENTRYP PFN_glImportSyncEXT) (GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
    return ((PFN_glImportSyncEXT)__blue_glCore_glImportSyncEXT)(external_sync_type, external_sync, flags);
}

extern void* __blue_glCore_glFrameTerminatorGREMEDY;
void APIENTRY bluegl_glFrameTerminatorGREMEDY (void) {
    typedef void (APIENTRYP PFN_glFrameTerminatorGREMEDY) (void);
    return ((PFN_glFrameTerminatorGREMEDY)__blue_glCore_glFrameTerminatorGREMEDY)();
}

extern void* __blue_glCore_glStringMarkerGREMEDY;
void APIENTRY bluegl_glStringMarkerGREMEDY (GLsizei len, const void *string) {
    typedef void (APIENTRYP PFN_glStringMarkerGREMEDY) (GLsizei len, const void *string);
    return ((PFN_glStringMarkerGREMEDY)__blue_glCore_glStringMarkerGREMEDY)(len, string);
}

extern void* __blue_glCore_glImageTransformParameteriHP;
void APIENTRY bluegl_glImageTransformParameteriHP (GLenum target, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glImageTransformParameteriHP) (GLenum target, GLenum pname, GLint param);
    return ((PFN_glImageTransformParameteriHP)__blue_glCore_glImageTransformParameteriHP)(target, pname, param);
}

extern void* __blue_glCore_glImageTransformParameterfHP;
void APIENTRY bluegl_glImageTransformParameterfHP (GLenum target, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glImageTransformParameterfHP) (GLenum target, GLenum pname, GLfloat param);
    return ((PFN_glImageTransformParameterfHP)__blue_glCore_glImageTransformParameterfHP)(target, pname, param);
}

extern void* __blue_glCore_glImageTransformParameterivHP;
void APIENTRY bluegl_glImageTransformParameterivHP (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glImageTransformParameterivHP) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glImageTransformParameterivHP)__blue_glCore_glImageTransformParameterivHP)(target, pname, params);
}

extern void* __blue_glCore_glImageTransformParameterfvHP;
void APIENTRY bluegl_glImageTransformParameterfvHP (GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glImageTransformParameterfvHP) (GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glImageTransformParameterfvHP)__blue_glCore_glImageTransformParameterfvHP)(target, pname, params);
}

extern void* __blue_glCore_glGetImageTransformParameterivHP;
void APIENTRY bluegl_glGetImageTransformParameterivHP (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetImageTransformParameterivHP) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetImageTransformParameterivHP)__blue_glCore_glGetImageTransformParameterivHP)(target, pname, params);
}

extern void* __blue_glCore_glGetImageTransformParameterfvHP;
void APIENTRY bluegl_glGetImageTransformParameterfvHP (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetImageTransformParameterfvHP) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetImageTransformParameterfvHP)__blue_glCore_glGetImageTransformParameterfvHP)(target, pname, params);
}

extern void* __blue_glCore_glMultiModeDrawArraysIBM;
void APIENTRY bluegl_glMultiModeDrawArraysIBM (const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride) {
    typedef void (APIENTRYP PFN_glMultiModeDrawArraysIBM) (const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride);
    return ((PFN_glMultiModeDrawArraysIBM)__blue_glCore_glMultiModeDrawArraysIBM)(mode, first, count, primcount, modestride);
}

extern void* __blue_glCore_glMultiModeDrawElementsIBM;
void APIENTRY bluegl_glMultiModeDrawElementsIBM (const GLenum *mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, GLint modestride) {
    typedef void (APIENTRYP PFN_glMultiModeDrawElementsIBM) (const GLenum *mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, GLint modestride);
    return ((PFN_glMultiModeDrawElementsIBM)__blue_glCore_glMultiModeDrawElementsIBM)(mode, count, type, indices, primcount, modestride);
}

extern void* __blue_glCore_glFlushStaticDataIBM;
void APIENTRY bluegl_glFlushStaticDataIBM (GLenum target) {
    typedef void (APIENTRYP PFN_glFlushStaticDataIBM) (GLenum target);
    return ((PFN_glFlushStaticDataIBM)__blue_glCore_glFlushStaticDataIBM)(target);
}

extern void* __blue_glCore_glColorPointerListIBM;
void APIENTRY bluegl_glColorPointerListIBM (GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride) {
    typedef void (APIENTRYP PFN_glColorPointerListIBM) (GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
    return ((PFN_glColorPointerListIBM)__blue_glCore_glColorPointerListIBM)(size, type, stride, pointer, ptrstride);
}

extern void* __blue_glCore_glSecondaryColorPointerListIBM;
void APIENTRY bluegl_glSecondaryColorPointerListIBM (GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride) {
    typedef void (APIENTRYP PFN_glSecondaryColorPointerListIBM) (GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
    return ((PFN_glSecondaryColorPointerListIBM)__blue_glCore_glSecondaryColorPointerListIBM)(size, type, stride, pointer, ptrstride);
}

extern void* __blue_glCore_glEdgeFlagPointerListIBM;
void APIENTRY bluegl_glEdgeFlagPointerListIBM (GLint stride, const GLboolean **pointer, GLint ptrstride) {
    typedef void (APIENTRYP PFN_glEdgeFlagPointerListIBM) (GLint stride, const GLboolean **pointer, GLint ptrstride);
    return ((PFN_glEdgeFlagPointerListIBM)__blue_glCore_glEdgeFlagPointerListIBM)(stride, pointer, ptrstride);
}

extern void* __blue_glCore_glFogCoordPointerListIBM;
void APIENTRY bluegl_glFogCoordPointerListIBM (GLenum type, GLint stride, const void **pointer, GLint ptrstride) {
    typedef void (APIENTRYP PFN_glFogCoordPointerListIBM) (GLenum type, GLint stride, const void **pointer, GLint ptrstride);
    return ((PFN_glFogCoordPointerListIBM)__blue_glCore_glFogCoordPointerListIBM)(type, stride, pointer, ptrstride);
}

extern void* __blue_glCore_glIndexPointerListIBM;
void APIENTRY bluegl_glIndexPointerListIBM (GLenum type, GLint stride, const void **pointer, GLint ptrstride) {
    typedef void (APIENTRYP PFN_glIndexPointerListIBM) (GLenum type, GLint stride, const void **pointer, GLint ptrstride);
    return ((PFN_glIndexPointerListIBM)__blue_glCore_glIndexPointerListIBM)(type, stride, pointer, ptrstride);
}

extern void* __blue_glCore_glNormalPointerListIBM;
void APIENTRY bluegl_glNormalPointerListIBM (GLenum type, GLint stride, const void **pointer, GLint ptrstride) {
    typedef void (APIENTRYP PFN_glNormalPointerListIBM) (GLenum type, GLint stride, const void **pointer, GLint ptrstride);
    return ((PFN_glNormalPointerListIBM)__blue_glCore_glNormalPointerListIBM)(type, stride, pointer, ptrstride);
}

extern void* __blue_glCore_glTexCoordPointerListIBM;
void APIENTRY bluegl_glTexCoordPointerListIBM (GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride) {
    typedef void (APIENTRYP PFN_glTexCoordPointerListIBM) (GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
    return ((PFN_glTexCoordPointerListIBM)__blue_glCore_glTexCoordPointerListIBM)(size, type, stride, pointer, ptrstride);
}

extern void* __blue_glCore_glVertexPointerListIBM;
void APIENTRY bluegl_glVertexPointerListIBM (GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride) {
    typedef void (APIENTRYP PFN_glVertexPointerListIBM) (GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
    return ((PFN_glVertexPointerListIBM)__blue_glCore_glVertexPointerListIBM)(size, type, stride, pointer, ptrstride);
}

extern void* __blue_glCore_glBlendFuncSeparateINGR;
void APIENTRY bluegl_glBlendFuncSeparateINGR (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    typedef void (APIENTRYP PFN_glBlendFuncSeparateINGR) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
    return ((PFN_glBlendFuncSeparateINGR)__blue_glCore_glBlendFuncSeparateINGR)(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

extern void* __blue_glCore_glApplyFramebufferAttachmentCMAAINTEL;
void APIENTRY bluegl_glApplyFramebufferAttachmentCMAAINTEL (void) {
    typedef void (APIENTRYP PFN_glApplyFramebufferAttachmentCMAAINTEL) (void);
    return ((PFN_glApplyFramebufferAttachmentCMAAINTEL)__blue_glCore_glApplyFramebufferAttachmentCMAAINTEL)();
}

extern void* __blue_glCore_glSyncTextureINTEL;
void APIENTRY bluegl_glSyncTextureINTEL (GLuint texture) {
    typedef void (APIENTRYP PFN_glSyncTextureINTEL) (GLuint texture);
    return ((PFN_glSyncTextureINTEL)__blue_glCore_glSyncTextureINTEL)(texture);
}

extern void* __blue_glCore_glUnmapTexture2DINTEL;
void APIENTRY bluegl_glUnmapTexture2DINTEL (GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glUnmapTexture2DINTEL) (GLuint texture, GLint level);
    return ((PFN_glUnmapTexture2DINTEL)__blue_glCore_glUnmapTexture2DINTEL)(texture, level);
}

extern void* __blue_glCore_glMapTexture2DINTEL;
void *APIENTRY bluegl_glMapTexture2DINTEL (GLuint texture, GLint level, GLbitfield access, GLint *stride, GLenum *layout) {
    typedef void *(APIENTRYP PFN_glMapTexture2DINTEL) (GLuint texture, GLint level, GLbitfield access, GLint *stride, GLenum *layout);
    return ((PFN_glMapTexture2DINTEL)__blue_glCore_glMapTexture2DINTEL)(texture, level, access, stride, layout);
}

extern void* __blue_glCore_glVertexPointervINTEL;
void APIENTRY bluegl_glVertexPointervINTEL (GLint size, GLenum type, const void **pointer) {
    typedef void (APIENTRYP PFN_glVertexPointervINTEL) (GLint size, GLenum type, const void **pointer);
    return ((PFN_glVertexPointervINTEL)__blue_glCore_glVertexPointervINTEL)(size, type, pointer);
}

extern void* __blue_glCore_glNormalPointervINTEL;
void APIENTRY bluegl_glNormalPointervINTEL (GLenum type, const void **pointer) {
    typedef void (APIENTRYP PFN_glNormalPointervINTEL) (GLenum type, const void **pointer);
    return ((PFN_glNormalPointervINTEL)__blue_glCore_glNormalPointervINTEL)(type, pointer);
}

extern void* __blue_glCore_glColorPointervINTEL;
void APIENTRY bluegl_glColorPointervINTEL (GLint size, GLenum type, const void **pointer) {
    typedef void (APIENTRYP PFN_glColorPointervINTEL) (GLint size, GLenum type, const void **pointer);
    return ((PFN_glColorPointervINTEL)__blue_glCore_glColorPointervINTEL)(size, type, pointer);
}

extern void* __blue_glCore_glTexCoordPointervINTEL;
void APIENTRY bluegl_glTexCoordPointervINTEL (GLint size, GLenum type, const void **pointer) {
    typedef void (APIENTRYP PFN_glTexCoordPointervINTEL) (GLint size, GLenum type, const void **pointer);
    return ((PFN_glTexCoordPointervINTEL)__blue_glCore_glTexCoordPointervINTEL)(size, type, pointer);
}

extern void* __blue_glCore_glBeginPerfQueryINTEL;
void APIENTRY bluegl_glBeginPerfQueryINTEL (GLuint queryHandle) {
    typedef void (APIENTRYP PFN_glBeginPerfQueryINTEL) (GLuint queryHandle);
    return ((PFN_glBeginPerfQueryINTEL)__blue_glCore_glBeginPerfQueryINTEL)(queryHandle);
}

extern void* __blue_glCore_glCreatePerfQueryINTEL;
void APIENTRY bluegl_glCreatePerfQueryINTEL (GLuint queryId, GLuint *queryHandle) {
    typedef void (APIENTRYP PFN_glCreatePerfQueryINTEL) (GLuint queryId, GLuint *queryHandle);
    return ((PFN_glCreatePerfQueryINTEL)__blue_glCore_glCreatePerfQueryINTEL)(queryId, queryHandle);
}

extern void* __blue_glCore_glDeletePerfQueryINTEL;
void APIENTRY bluegl_glDeletePerfQueryINTEL (GLuint queryHandle) {
    typedef void (APIENTRYP PFN_glDeletePerfQueryINTEL) (GLuint queryHandle);
    return ((PFN_glDeletePerfQueryINTEL)__blue_glCore_glDeletePerfQueryINTEL)(queryHandle);
}

extern void* __blue_glCore_glEndPerfQueryINTEL;
void APIENTRY bluegl_glEndPerfQueryINTEL (GLuint queryHandle) {
    typedef void (APIENTRYP PFN_glEndPerfQueryINTEL) (GLuint queryHandle);
    return ((PFN_glEndPerfQueryINTEL)__blue_glCore_glEndPerfQueryINTEL)(queryHandle);
}

extern void* __blue_glCore_glGetFirstPerfQueryIdINTEL;
void APIENTRY bluegl_glGetFirstPerfQueryIdINTEL (GLuint *queryId) {
    typedef void (APIENTRYP PFN_glGetFirstPerfQueryIdINTEL) (GLuint *queryId);
    return ((PFN_glGetFirstPerfQueryIdINTEL)__blue_glCore_glGetFirstPerfQueryIdINTEL)(queryId);
}

extern void* __blue_glCore_glGetNextPerfQueryIdINTEL;
void APIENTRY bluegl_glGetNextPerfQueryIdINTEL (GLuint queryId, GLuint *nextQueryId) {
    typedef void (APIENTRYP PFN_glGetNextPerfQueryIdINTEL) (GLuint queryId, GLuint *nextQueryId);
    return ((PFN_glGetNextPerfQueryIdINTEL)__blue_glCore_glGetNextPerfQueryIdINTEL)(queryId, nextQueryId);
}

extern void* __blue_glCore_glGetPerfCounterInfoINTEL;
void APIENTRY bluegl_glGetPerfCounterInfoINTEL (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue) {
    typedef void (APIENTRYP PFN_glGetPerfCounterInfoINTEL) (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
    return ((PFN_glGetPerfCounterInfoINTEL)__blue_glCore_glGetPerfCounterInfoINTEL)(queryId, counterId, counterNameLength, counterName, counterDescLength, counterDesc, counterOffset, counterDataSize, counterTypeEnum, counterDataTypeEnum, rawCounterMaxValue);
}

extern void* __blue_glCore_glGetPerfQueryDataINTEL;
void APIENTRY bluegl_glGetPerfQueryDataINTEL (GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid *data, GLuint *bytesWritten) {
    typedef void (APIENTRYP PFN_glGetPerfQueryDataINTEL) (GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid *data, GLuint *bytesWritten);
    return ((PFN_glGetPerfQueryDataINTEL)__blue_glCore_glGetPerfQueryDataINTEL)(queryHandle, flags, dataSize, data, bytesWritten);
}

extern void* __blue_glCore_glGetPerfQueryIdByNameINTEL;
void APIENTRY bluegl_glGetPerfQueryIdByNameINTEL (GLchar *queryName, GLuint *queryId) {
    typedef void (APIENTRYP PFN_glGetPerfQueryIdByNameINTEL) (GLchar *queryName, GLuint *queryId);
    return ((PFN_glGetPerfQueryIdByNameINTEL)__blue_glCore_glGetPerfQueryIdByNameINTEL)(queryName, queryId);
}

extern void* __blue_glCore_glGetPerfQueryInfoINTEL;
void APIENTRY bluegl_glGetPerfQueryInfoINTEL (GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask) {
    typedef void (APIENTRYP PFN_glGetPerfQueryInfoINTEL) (GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);
    return ((PFN_glGetPerfQueryInfoINTEL)__blue_glCore_glGetPerfQueryInfoINTEL)(queryId, queryNameLength, queryName, dataSize, noCounters, noInstances, capsMask);
}

extern void* __blue_glCore_glResizeBuffersMESA;
void APIENTRY bluegl_glResizeBuffersMESA (void) {
    typedef void (APIENTRYP PFN_glResizeBuffersMESA) (void);
    return ((PFN_glResizeBuffersMESA)__blue_glCore_glResizeBuffersMESA)();
}

extern void* __blue_glCore_glWindowPos2dMESA;
void APIENTRY bluegl_glWindowPos2dMESA (GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glWindowPos2dMESA) (GLdouble x, GLdouble y);
    return ((PFN_glWindowPos2dMESA)__blue_glCore_glWindowPos2dMESA)(x, y);
}

extern void* __blue_glCore_glWindowPos2dvMESA;
void APIENTRY bluegl_glWindowPos2dvMESA (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glWindowPos2dvMESA) (const GLdouble *v);
    return ((PFN_glWindowPos2dvMESA)__blue_glCore_glWindowPos2dvMESA)(v);
}

extern void* __blue_glCore_glWindowPos2fMESA;
void APIENTRY bluegl_glWindowPos2fMESA (GLfloat x, GLfloat y) {
    typedef void (APIENTRYP PFN_glWindowPos2fMESA) (GLfloat x, GLfloat y);
    return ((PFN_glWindowPos2fMESA)__blue_glCore_glWindowPos2fMESA)(x, y);
}

extern void* __blue_glCore_glWindowPos2fvMESA;
void APIENTRY bluegl_glWindowPos2fvMESA (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glWindowPos2fvMESA) (const GLfloat *v);
    return ((PFN_glWindowPos2fvMESA)__blue_glCore_glWindowPos2fvMESA)(v);
}

extern void* __blue_glCore_glWindowPos2iMESA;
void APIENTRY bluegl_glWindowPos2iMESA (GLint x, GLint y) {
    typedef void (APIENTRYP PFN_glWindowPos2iMESA) (GLint x, GLint y);
    return ((PFN_glWindowPos2iMESA)__blue_glCore_glWindowPos2iMESA)(x, y);
}

extern void* __blue_glCore_glWindowPos2ivMESA;
void APIENTRY bluegl_glWindowPos2ivMESA (const GLint *v) {
    typedef void (APIENTRYP PFN_glWindowPos2ivMESA) (const GLint *v);
    return ((PFN_glWindowPos2ivMESA)__blue_glCore_glWindowPos2ivMESA)(v);
}

extern void* __blue_glCore_glWindowPos2sMESA;
void APIENTRY bluegl_glWindowPos2sMESA (GLshort x, GLshort y) {
    typedef void (APIENTRYP PFN_glWindowPos2sMESA) (GLshort x, GLshort y);
    return ((PFN_glWindowPos2sMESA)__blue_glCore_glWindowPos2sMESA)(x, y);
}

extern void* __blue_glCore_glWindowPos2svMESA;
void APIENTRY bluegl_glWindowPos2svMESA (const GLshort *v) {
    typedef void (APIENTRYP PFN_glWindowPos2svMESA) (const GLshort *v);
    return ((PFN_glWindowPos2svMESA)__blue_glCore_glWindowPos2svMESA)(v);
}

extern void* __blue_glCore_glWindowPos3dMESA;
void APIENTRY bluegl_glWindowPos3dMESA (GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glWindowPos3dMESA) (GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glWindowPos3dMESA)__blue_glCore_glWindowPos3dMESA)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3dvMESA;
void APIENTRY bluegl_glWindowPos3dvMESA (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glWindowPos3dvMESA) (const GLdouble *v);
    return ((PFN_glWindowPos3dvMESA)__blue_glCore_glWindowPos3dvMESA)(v);
}

extern void* __blue_glCore_glWindowPos3fMESA;
void APIENTRY bluegl_glWindowPos3fMESA (GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glWindowPos3fMESA) (GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glWindowPos3fMESA)__blue_glCore_glWindowPos3fMESA)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3fvMESA;
void APIENTRY bluegl_glWindowPos3fvMESA (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glWindowPos3fvMESA) (const GLfloat *v);
    return ((PFN_glWindowPos3fvMESA)__blue_glCore_glWindowPos3fvMESA)(v);
}

extern void* __blue_glCore_glWindowPos3iMESA;
void APIENTRY bluegl_glWindowPos3iMESA (GLint x, GLint y, GLint z) {
    typedef void (APIENTRYP PFN_glWindowPos3iMESA) (GLint x, GLint y, GLint z);
    return ((PFN_glWindowPos3iMESA)__blue_glCore_glWindowPos3iMESA)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3ivMESA;
void APIENTRY bluegl_glWindowPos3ivMESA (const GLint *v) {
    typedef void (APIENTRYP PFN_glWindowPos3ivMESA) (const GLint *v);
    return ((PFN_glWindowPos3ivMESA)__blue_glCore_glWindowPos3ivMESA)(v);
}

extern void* __blue_glCore_glWindowPos3sMESA;
void APIENTRY bluegl_glWindowPos3sMESA (GLshort x, GLshort y, GLshort z) {
    typedef void (APIENTRYP PFN_glWindowPos3sMESA) (GLshort x, GLshort y, GLshort z);
    return ((PFN_glWindowPos3sMESA)__blue_glCore_glWindowPos3sMESA)(x, y, z);
}

extern void* __blue_glCore_glWindowPos3svMESA;
void APIENTRY bluegl_glWindowPos3svMESA (const GLshort *v) {
    typedef void (APIENTRYP PFN_glWindowPos3svMESA) (const GLshort *v);
    return ((PFN_glWindowPos3svMESA)__blue_glCore_glWindowPos3svMESA)(v);
}

extern void* __blue_glCore_glWindowPos4dMESA;
void APIENTRY bluegl_glWindowPos4dMESA (GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glWindowPos4dMESA) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glWindowPos4dMESA)__blue_glCore_glWindowPos4dMESA)(x, y, z, w);
}

extern void* __blue_glCore_glWindowPos4dvMESA;
void APIENTRY bluegl_glWindowPos4dvMESA (const GLdouble *v) {
    typedef void (APIENTRYP PFN_glWindowPos4dvMESA) (const GLdouble *v);
    return ((PFN_glWindowPos4dvMESA)__blue_glCore_glWindowPos4dvMESA)(v);
}

extern void* __blue_glCore_glWindowPos4fMESA;
void APIENTRY bluegl_glWindowPos4fMESA (GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glWindowPos4fMESA) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glWindowPos4fMESA)__blue_glCore_glWindowPos4fMESA)(x, y, z, w);
}

extern void* __blue_glCore_glWindowPos4fvMESA;
void APIENTRY bluegl_glWindowPos4fvMESA (const GLfloat *v) {
    typedef void (APIENTRYP PFN_glWindowPos4fvMESA) (const GLfloat *v);
    return ((PFN_glWindowPos4fvMESA)__blue_glCore_glWindowPos4fvMESA)(v);
}

extern void* __blue_glCore_glWindowPos4iMESA;
void APIENTRY bluegl_glWindowPos4iMESA (GLint x, GLint y, GLint z, GLint w) {
    typedef void (APIENTRYP PFN_glWindowPos4iMESA) (GLint x, GLint y, GLint z, GLint w);
    return ((PFN_glWindowPos4iMESA)__blue_glCore_glWindowPos4iMESA)(x, y, z, w);
}

extern void* __blue_glCore_glWindowPos4ivMESA;
void APIENTRY bluegl_glWindowPos4ivMESA (const GLint *v) {
    typedef void (APIENTRYP PFN_glWindowPos4ivMESA) (const GLint *v);
    return ((PFN_glWindowPos4ivMESA)__blue_glCore_glWindowPos4ivMESA)(v);
}

extern void* __blue_glCore_glWindowPos4sMESA;
void APIENTRY bluegl_glWindowPos4sMESA (GLshort x, GLshort y, GLshort z, GLshort w) {
    typedef void (APIENTRYP PFN_glWindowPos4sMESA) (GLshort x, GLshort y, GLshort z, GLshort w);
    return ((PFN_glWindowPos4sMESA)__blue_glCore_glWindowPos4sMESA)(x, y, z, w);
}

extern void* __blue_glCore_glWindowPos4svMESA;
void APIENTRY bluegl_glWindowPos4svMESA (const GLshort *v) {
    typedef void (APIENTRYP PFN_glWindowPos4svMESA) (const GLshort *v);
    return ((PFN_glWindowPos4svMESA)__blue_glCore_glWindowPos4svMESA)(v);
}

extern void* __blue_glCore_glBeginConditionalRenderNVX;
void APIENTRY bluegl_glBeginConditionalRenderNVX (GLuint id) {
    typedef void (APIENTRYP PFN_glBeginConditionalRenderNVX) (GLuint id);
    return ((PFN_glBeginConditionalRenderNVX)__blue_glCore_glBeginConditionalRenderNVX)(id);
}

extern void* __blue_glCore_glEndConditionalRenderNVX;
void APIENTRY bluegl_glEndConditionalRenderNVX (void) {
    typedef void (APIENTRYP PFN_glEndConditionalRenderNVX) (void);
    return ((PFN_glEndConditionalRenderNVX)__blue_glCore_glEndConditionalRenderNVX)();
}

extern void* __blue_glCore_glMultiDrawArraysIndirectBindlessNV;
void APIENTRY bluegl_glMultiDrawArraysIndirectBindlessNV (GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount) {
    typedef void (APIENTRYP PFN_glMultiDrawArraysIndirectBindlessNV) (GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
    return ((PFN_glMultiDrawArraysIndirectBindlessNV)__blue_glCore_glMultiDrawArraysIndirectBindlessNV)(mode, indirect, drawCount, stride, vertexBufferCount);
}

extern void* __blue_glCore_glMultiDrawElementsIndirectBindlessNV;
void APIENTRY bluegl_glMultiDrawElementsIndirectBindlessNV (GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount) {
    typedef void (APIENTRYP PFN_glMultiDrawElementsIndirectBindlessNV) (GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
    return ((PFN_glMultiDrawElementsIndirectBindlessNV)__blue_glCore_glMultiDrawElementsIndirectBindlessNV)(mode, type, indirect, drawCount, stride, vertexBufferCount);
}

extern void* __blue_glCore_glMultiDrawArraysIndirectBindlessCountNV;
void APIENTRY bluegl_glMultiDrawArraysIndirectBindlessCountNV (GLenum mode, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount) {
    typedef void (APIENTRYP PFN_glMultiDrawArraysIndirectBindlessCountNV) (GLenum mode, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
    return ((PFN_glMultiDrawArraysIndirectBindlessCountNV)__blue_glCore_glMultiDrawArraysIndirectBindlessCountNV)(mode, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}

extern void* __blue_glCore_glMultiDrawElementsIndirectBindlessCountNV;
void APIENTRY bluegl_glMultiDrawElementsIndirectBindlessCountNV (GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount) {
    typedef void (APIENTRYP PFN_glMultiDrawElementsIndirectBindlessCountNV) (GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
    return ((PFN_glMultiDrawElementsIndirectBindlessCountNV)__blue_glCore_glMultiDrawElementsIndirectBindlessCountNV)(mode, type, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}

extern void* __blue_glCore_glGetTextureHandleNV;
GLuint64 APIENTRY bluegl_glGetTextureHandleNV (GLuint texture) {
    typedef GLuint64 (APIENTRYP PFN_glGetTextureHandleNV) (GLuint texture);
    return ((PFN_glGetTextureHandleNV)__blue_glCore_glGetTextureHandleNV)(texture);
}

extern void* __blue_glCore_glGetTextureSamplerHandleNV;
GLuint64 APIENTRY bluegl_glGetTextureSamplerHandleNV (GLuint texture, GLuint sampler) {
    typedef GLuint64 (APIENTRYP PFN_glGetTextureSamplerHandleNV) (GLuint texture, GLuint sampler);
    return ((PFN_glGetTextureSamplerHandleNV)__blue_glCore_glGetTextureSamplerHandleNV)(texture, sampler);
}

extern void* __blue_glCore_glMakeTextureHandleResidentNV;
void APIENTRY bluegl_glMakeTextureHandleResidentNV (GLuint64 handle) {
    typedef void (APIENTRYP PFN_glMakeTextureHandleResidentNV) (GLuint64 handle);
    return ((PFN_glMakeTextureHandleResidentNV)__blue_glCore_glMakeTextureHandleResidentNV)(handle);
}

extern void* __blue_glCore_glMakeTextureHandleNonResidentNV;
void APIENTRY bluegl_glMakeTextureHandleNonResidentNV (GLuint64 handle) {
    typedef void (APIENTRYP PFN_glMakeTextureHandleNonResidentNV) (GLuint64 handle);
    return ((PFN_glMakeTextureHandleNonResidentNV)__blue_glCore_glMakeTextureHandleNonResidentNV)(handle);
}

extern void* __blue_glCore_glGetImageHandleNV;
GLuint64 APIENTRY bluegl_glGetImageHandleNV (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) {
    typedef GLuint64 (APIENTRYP PFN_glGetImageHandleNV) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
    return ((PFN_glGetImageHandleNV)__blue_glCore_glGetImageHandleNV)(texture, level, layered, layer, format);
}

extern void* __blue_glCore_glMakeImageHandleResidentNV;
void APIENTRY bluegl_glMakeImageHandleResidentNV (GLuint64 handle, GLenum access) {
    typedef void (APIENTRYP PFN_glMakeImageHandleResidentNV) (GLuint64 handle, GLenum access);
    return ((PFN_glMakeImageHandleResidentNV)__blue_glCore_glMakeImageHandleResidentNV)(handle, access);
}

extern void* __blue_glCore_glMakeImageHandleNonResidentNV;
void APIENTRY bluegl_glMakeImageHandleNonResidentNV (GLuint64 handle) {
    typedef void (APIENTRYP PFN_glMakeImageHandleNonResidentNV) (GLuint64 handle);
    return ((PFN_glMakeImageHandleNonResidentNV)__blue_glCore_glMakeImageHandleNonResidentNV)(handle);
}

extern void* __blue_glCore_glUniformHandleui64NV;
void APIENTRY bluegl_glUniformHandleui64NV (GLint location, GLuint64 value) {
    typedef void (APIENTRYP PFN_glUniformHandleui64NV) (GLint location, GLuint64 value);
    return ((PFN_glUniformHandleui64NV)__blue_glCore_glUniformHandleui64NV)(location, value);
}

extern void* __blue_glCore_glUniformHandleui64vNV;
void APIENTRY bluegl_glUniformHandleui64vNV (GLint location, GLsizei count, const GLuint64 *value) {
    typedef void (APIENTRYP PFN_glUniformHandleui64vNV) (GLint location, GLsizei count, const GLuint64 *value);
    return ((PFN_glUniformHandleui64vNV)__blue_glCore_glUniformHandleui64vNV)(location, count, value);
}

extern void* __blue_glCore_glProgramUniformHandleui64NV;
void APIENTRY bluegl_glProgramUniformHandleui64NV (GLuint program, GLint location, GLuint64 value) {
    typedef void (APIENTRYP PFN_glProgramUniformHandleui64NV) (GLuint program, GLint location, GLuint64 value);
    return ((PFN_glProgramUniformHandleui64NV)__blue_glCore_glProgramUniformHandleui64NV)(program, location, value);
}

extern void* __blue_glCore_glProgramUniformHandleui64vNV;
void APIENTRY bluegl_glProgramUniformHandleui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64 *values) {
    typedef void (APIENTRYP PFN_glProgramUniformHandleui64vNV) (GLuint program, GLint location, GLsizei count, const GLuint64 *values);
    return ((PFN_glProgramUniformHandleui64vNV)__blue_glCore_glProgramUniformHandleui64vNV)(program, location, count, values);
}

extern void* __blue_glCore_glIsTextureHandleResidentNV;
GLboolean APIENTRY bluegl_glIsTextureHandleResidentNV (GLuint64 handle) {
    typedef GLboolean (APIENTRYP PFN_glIsTextureHandleResidentNV) (GLuint64 handle);
    return ((PFN_glIsTextureHandleResidentNV)__blue_glCore_glIsTextureHandleResidentNV)(handle);
}

extern void* __blue_glCore_glIsImageHandleResidentNV;
GLboolean APIENTRY bluegl_glIsImageHandleResidentNV (GLuint64 handle) {
    typedef GLboolean (APIENTRYP PFN_glIsImageHandleResidentNV) (GLuint64 handle);
    return ((PFN_glIsImageHandleResidentNV)__blue_glCore_glIsImageHandleResidentNV)(handle);
}

extern void* __blue_glCore_glBlendParameteriNV;
void APIENTRY bluegl_glBlendParameteriNV (GLenum pname, GLint value) {
    typedef void (APIENTRYP PFN_glBlendParameteriNV) (GLenum pname, GLint value);
    return ((PFN_glBlendParameteriNV)__blue_glCore_glBlendParameteriNV)(pname, value);
}

extern void* __blue_glCore_glBlendBarrierNV;
void APIENTRY bluegl_glBlendBarrierNV (void) {
    typedef void (APIENTRYP PFN_glBlendBarrierNV) (void);
    return ((PFN_glBlendBarrierNV)__blue_glCore_glBlendBarrierNV)();
}

extern void* __blue_glCore_glCreateStatesNV;
void APIENTRY bluegl_glCreateStatesNV (GLsizei n, GLuint *states) {
    typedef void (APIENTRYP PFN_glCreateStatesNV) (GLsizei n, GLuint *states);
    return ((PFN_glCreateStatesNV)__blue_glCore_glCreateStatesNV)(n, states);
}

extern void* __blue_glCore_glDeleteStatesNV;
void APIENTRY bluegl_glDeleteStatesNV (GLsizei n, const GLuint *states) {
    typedef void (APIENTRYP PFN_glDeleteStatesNV) (GLsizei n, const GLuint *states);
    return ((PFN_glDeleteStatesNV)__blue_glCore_glDeleteStatesNV)(n, states);
}

extern void* __blue_glCore_glIsStateNV;
GLboolean APIENTRY bluegl_glIsStateNV (GLuint state) {
    typedef GLboolean (APIENTRYP PFN_glIsStateNV) (GLuint state);
    return ((PFN_glIsStateNV)__blue_glCore_glIsStateNV)(state);
}

extern void* __blue_glCore_glStateCaptureNV;
void APIENTRY bluegl_glStateCaptureNV (GLuint state, GLenum mode) {
    typedef void (APIENTRYP PFN_glStateCaptureNV) (GLuint state, GLenum mode);
    return ((PFN_glStateCaptureNV)__blue_glCore_glStateCaptureNV)(state, mode);
}

extern void* __blue_glCore_glGetCommandHeaderNV;
GLuint APIENTRY bluegl_glGetCommandHeaderNV (GLenum tokenID, GLuint size) {
    typedef GLuint (APIENTRYP PFN_glGetCommandHeaderNV) (GLenum tokenID, GLuint size);
    return ((PFN_glGetCommandHeaderNV)__blue_glCore_glGetCommandHeaderNV)(tokenID, size);
}

extern void* __blue_glCore_glGetStageIndexNV;
GLushort APIENTRY bluegl_glGetStageIndexNV (GLenum shadertype) {
    typedef GLushort (APIENTRYP PFN_glGetStageIndexNV) (GLenum shadertype);
    return ((PFN_glGetStageIndexNV)__blue_glCore_glGetStageIndexNV)(shadertype);
}

extern void* __blue_glCore_glDrawCommandsNV;
void APIENTRY bluegl_glDrawCommandsNV (GLenum primitiveMode, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, GLuint count) {
    typedef void (APIENTRYP PFN_glDrawCommandsNV) (GLenum primitiveMode, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, GLuint count);
    return ((PFN_glDrawCommandsNV)__blue_glCore_glDrawCommandsNV)(primitiveMode, buffer, indirects, sizes, count);
}

extern void* __blue_glCore_glDrawCommandsAddressNV;
void APIENTRY bluegl_glDrawCommandsAddressNV (GLenum primitiveMode, const GLuint64 *indirects, const GLsizei *sizes, GLuint count) {
    typedef void (APIENTRYP PFN_glDrawCommandsAddressNV) (GLenum primitiveMode, const GLuint64 *indirects, const GLsizei *sizes, GLuint count);
    return ((PFN_glDrawCommandsAddressNV)__blue_glCore_glDrawCommandsAddressNV)(primitiveMode, indirects, sizes, count);
}

extern void* __blue_glCore_glDrawCommandsStatesNV;
void APIENTRY bluegl_glDrawCommandsStatesNV (GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count) {
    typedef void (APIENTRYP PFN_glDrawCommandsStatesNV) (GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
    return ((PFN_glDrawCommandsStatesNV)__blue_glCore_glDrawCommandsStatesNV)(buffer, indirects, sizes, states, fbos, count);
}

extern void* __blue_glCore_glDrawCommandsStatesAddressNV;
void APIENTRY bluegl_glDrawCommandsStatesAddressNV (const GLuint64 *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count) {
    typedef void (APIENTRYP PFN_glDrawCommandsStatesAddressNV) (const GLuint64 *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
    return ((PFN_glDrawCommandsStatesAddressNV)__blue_glCore_glDrawCommandsStatesAddressNV)(indirects, sizes, states, fbos, count);
}

extern void* __blue_glCore_glCreateCommandListsNV;
void APIENTRY bluegl_glCreateCommandListsNV (GLsizei n, GLuint *lists) {
    typedef void (APIENTRYP PFN_glCreateCommandListsNV) (GLsizei n, GLuint *lists);
    return ((PFN_glCreateCommandListsNV)__blue_glCore_glCreateCommandListsNV)(n, lists);
}

extern void* __blue_glCore_glDeleteCommandListsNV;
void APIENTRY bluegl_glDeleteCommandListsNV (GLsizei n, const GLuint *lists) {
    typedef void (APIENTRYP PFN_glDeleteCommandListsNV) (GLsizei n, const GLuint *lists);
    return ((PFN_glDeleteCommandListsNV)__blue_glCore_glDeleteCommandListsNV)(n, lists);
}

extern void* __blue_glCore_glIsCommandListNV;
GLboolean APIENTRY bluegl_glIsCommandListNV (GLuint list) {
    typedef GLboolean (APIENTRYP PFN_glIsCommandListNV) (GLuint list);
    return ((PFN_glIsCommandListNV)__blue_glCore_glIsCommandListNV)(list);
}

extern void* __blue_glCore_glListDrawCommandsStatesClientNV;
void APIENTRY bluegl_glListDrawCommandsStatesClientNV (GLuint list, GLuint segment, const void **indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count) {
    typedef void (APIENTRYP PFN_glListDrawCommandsStatesClientNV) (GLuint list, GLuint segment, const void **indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
    return ((PFN_glListDrawCommandsStatesClientNV)__blue_glCore_glListDrawCommandsStatesClientNV)(list, segment, indirects, sizes, states, fbos, count);
}

extern void* __blue_glCore_glCommandListSegmentsNV;
void APIENTRY bluegl_glCommandListSegmentsNV (GLuint list, GLuint segments) {
    typedef void (APIENTRYP PFN_glCommandListSegmentsNV) (GLuint list, GLuint segments);
    return ((PFN_glCommandListSegmentsNV)__blue_glCore_glCommandListSegmentsNV)(list, segments);
}

extern void* __blue_glCore_glCompileCommandListNV;
void APIENTRY bluegl_glCompileCommandListNV (GLuint list) {
    typedef void (APIENTRYP PFN_glCompileCommandListNV) (GLuint list);
    return ((PFN_glCompileCommandListNV)__blue_glCore_glCompileCommandListNV)(list);
}

extern void* __blue_glCore_glCallCommandListNV;
void APIENTRY bluegl_glCallCommandListNV (GLuint list) {
    typedef void (APIENTRYP PFN_glCallCommandListNV) (GLuint list);
    return ((PFN_glCallCommandListNV)__blue_glCore_glCallCommandListNV)(list);
}

extern void* __blue_glCore_glBeginConditionalRenderNV;
void APIENTRY bluegl_glBeginConditionalRenderNV (GLuint id, GLenum mode) {
    typedef void (APIENTRYP PFN_glBeginConditionalRenderNV) (GLuint id, GLenum mode);
    return ((PFN_glBeginConditionalRenderNV)__blue_glCore_glBeginConditionalRenderNV)(id, mode);
}

extern void* __blue_glCore_glEndConditionalRenderNV;
void APIENTRY bluegl_glEndConditionalRenderNV (void) {
    typedef void (APIENTRYP PFN_glEndConditionalRenderNV) (void);
    return ((PFN_glEndConditionalRenderNV)__blue_glCore_glEndConditionalRenderNV)();
}

extern void* __blue_glCore_glSubpixelPrecisionBiasNV;
void APIENTRY bluegl_glSubpixelPrecisionBiasNV (GLuint xbits, GLuint ybits) {
    typedef void (APIENTRYP PFN_glSubpixelPrecisionBiasNV) (GLuint xbits, GLuint ybits);
    return ((PFN_glSubpixelPrecisionBiasNV)__blue_glCore_glSubpixelPrecisionBiasNV)(xbits, ybits);
}

extern void* __blue_glCore_glConservativeRasterParameterfNV;
void APIENTRY bluegl_glConservativeRasterParameterfNV (GLenum pname, GLfloat value) {
    typedef void (APIENTRYP PFN_glConservativeRasterParameterfNV) (GLenum pname, GLfloat value);
    return ((PFN_glConservativeRasterParameterfNV)__blue_glCore_glConservativeRasterParameterfNV)(pname, value);
}

extern void* __blue_glCore_glCopyImageSubDataNV;
void APIENTRY bluegl_glCopyImageSubDataNV (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
    typedef void (APIENTRYP PFN_glCopyImageSubDataNV) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
    return ((PFN_glCopyImageSubDataNV)__blue_glCore_glCopyImageSubDataNV)(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
}

extern void* __blue_glCore_glDepthRangedNV;
void APIENTRY bluegl_glDepthRangedNV (GLdouble zNear, GLdouble zFar) {
    typedef void (APIENTRYP PFN_glDepthRangedNV) (GLdouble zNear, GLdouble zFar);
    return ((PFN_glDepthRangedNV)__blue_glCore_glDepthRangedNV)(zNear, zFar);
}

extern void* __blue_glCore_glClearDepthdNV;
void APIENTRY bluegl_glClearDepthdNV (GLdouble depth) {
    typedef void (APIENTRYP PFN_glClearDepthdNV) (GLdouble depth);
    return ((PFN_glClearDepthdNV)__blue_glCore_glClearDepthdNV)(depth);
}

extern void* __blue_glCore_glDepthBoundsdNV;
void APIENTRY bluegl_glDepthBoundsdNV (GLdouble zmin, GLdouble zmax) {
    typedef void (APIENTRYP PFN_glDepthBoundsdNV) (GLdouble zmin, GLdouble zmax);
    return ((PFN_glDepthBoundsdNV)__blue_glCore_glDepthBoundsdNV)(zmin, zmax);
}

extern void* __blue_glCore_glDrawTextureNV;
void APIENTRY bluegl_glDrawTextureNV (GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1) {
    typedef void (APIENTRYP PFN_glDrawTextureNV) (GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
    return ((PFN_glDrawTextureNV)__blue_glCore_glDrawTextureNV)(texture, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
}

extern void* __blue_glCore_glMapControlPointsNV;
void APIENTRY bluegl_glMapControlPointsNV (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void *points) {
    typedef void (APIENTRYP PFN_glMapControlPointsNV) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void *points);
    return ((PFN_glMapControlPointsNV)__blue_glCore_glMapControlPointsNV)(target, index, type, ustride, vstride, uorder, vorder, packed, points);
}

extern void* __blue_glCore_glMapParameterivNV;
void APIENTRY bluegl_glMapParameterivNV (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glMapParameterivNV) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glMapParameterivNV)__blue_glCore_glMapParameterivNV)(target, pname, params);
}

extern void* __blue_glCore_glMapParameterfvNV;
void APIENTRY bluegl_glMapParameterfvNV (GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glMapParameterfvNV) (GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glMapParameterfvNV)__blue_glCore_glMapParameterfvNV)(target, pname, params);
}

extern void* __blue_glCore_glGetMapControlPointsNV;
void APIENTRY bluegl_glGetMapControlPointsNV (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void *points) {
    typedef void (APIENTRYP PFN_glGetMapControlPointsNV) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void *points);
    return ((PFN_glGetMapControlPointsNV)__blue_glCore_glGetMapControlPointsNV)(target, index, type, ustride, vstride, packed, points);
}

extern void* __blue_glCore_glGetMapParameterivNV;
void APIENTRY bluegl_glGetMapParameterivNV (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetMapParameterivNV) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetMapParameterivNV)__blue_glCore_glGetMapParameterivNV)(target, pname, params);
}

extern void* __blue_glCore_glGetMapParameterfvNV;
void APIENTRY bluegl_glGetMapParameterfvNV (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetMapParameterfvNV) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetMapParameterfvNV)__blue_glCore_glGetMapParameterfvNV)(target, pname, params);
}

extern void* __blue_glCore_glGetMapAttribParameterivNV;
void APIENTRY bluegl_glGetMapAttribParameterivNV (GLenum target, GLuint index, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetMapAttribParameterivNV) (GLenum target, GLuint index, GLenum pname, GLint *params);
    return ((PFN_glGetMapAttribParameterivNV)__blue_glCore_glGetMapAttribParameterivNV)(target, index, pname, params);
}

extern void* __blue_glCore_glGetMapAttribParameterfvNV;
void APIENTRY bluegl_glGetMapAttribParameterfvNV (GLenum target, GLuint index, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetMapAttribParameterfvNV) (GLenum target, GLuint index, GLenum pname, GLfloat *params);
    return ((PFN_glGetMapAttribParameterfvNV)__blue_glCore_glGetMapAttribParameterfvNV)(target, index, pname, params);
}

extern void* __blue_glCore_glEvalMapsNV;
void APIENTRY bluegl_glEvalMapsNV (GLenum target, GLenum mode) {
    typedef void (APIENTRYP PFN_glEvalMapsNV) (GLenum target, GLenum mode);
    return ((PFN_glEvalMapsNV)__blue_glCore_glEvalMapsNV)(target, mode);
}

extern void* __blue_glCore_glGetMultisamplefvNV;
void APIENTRY bluegl_glGetMultisamplefvNV (GLenum pname, GLuint index, GLfloat *val) {
    typedef void (APIENTRYP PFN_glGetMultisamplefvNV) (GLenum pname, GLuint index, GLfloat *val);
    return ((PFN_glGetMultisamplefvNV)__blue_glCore_glGetMultisamplefvNV)(pname, index, val);
}

extern void* __blue_glCore_glSampleMaskIndexedNV;
void APIENTRY bluegl_glSampleMaskIndexedNV (GLuint index, GLbitfield mask) {
    typedef void (APIENTRYP PFN_glSampleMaskIndexedNV) (GLuint index, GLbitfield mask);
    return ((PFN_glSampleMaskIndexedNV)__blue_glCore_glSampleMaskIndexedNV)(index, mask);
}

extern void* __blue_glCore_glTexRenderbufferNV;
void APIENTRY bluegl_glTexRenderbufferNV (GLenum target, GLuint renderbuffer) {
    typedef void (APIENTRYP PFN_glTexRenderbufferNV) (GLenum target, GLuint renderbuffer);
    return ((PFN_glTexRenderbufferNV)__blue_glCore_glTexRenderbufferNV)(target, renderbuffer);
}

extern void* __blue_glCore_glDeleteFencesNV;
void APIENTRY bluegl_glDeleteFencesNV (GLsizei n, const GLuint *fences) {
    typedef void (APIENTRYP PFN_glDeleteFencesNV) (GLsizei n, const GLuint *fences);
    return ((PFN_glDeleteFencesNV)__blue_glCore_glDeleteFencesNV)(n, fences);
}

extern void* __blue_glCore_glGenFencesNV;
void APIENTRY bluegl_glGenFencesNV (GLsizei n, GLuint *fences) {
    typedef void (APIENTRYP PFN_glGenFencesNV) (GLsizei n, GLuint *fences);
    return ((PFN_glGenFencesNV)__blue_glCore_glGenFencesNV)(n, fences);
}

extern void* __blue_glCore_glIsFenceNV;
GLboolean APIENTRY bluegl_glIsFenceNV (GLuint fence) {
    typedef GLboolean (APIENTRYP PFN_glIsFenceNV) (GLuint fence);
    return ((PFN_glIsFenceNV)__blue_glCore_glIsFenceNV)(fence);
}

extern void* __blue_glCore_glTestFenceNV;
GLboolean APIENTRY bluegl_glTestFenceNV (GLuint fence) {
    typedef GLboolean (APIENTRYP PFN_glTestFenceNV) (GLuint fence);
    return ((PFN_glTestFenceNV)__blue_glCore_glTestFenceNV)(fence);
}

extern void* __blue_glCore_glGetFenceivNV;
void APIENTRY bluegl_glGetFenceivNV (GLuint fence, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetFenceivNV) (GLuint fence, GLenum pname, GLint *params);
    return ((PFN_glGetFenceivNV)__blue_glCore_glGetFenceivNV)(fence, pname, params);
}

extern void* __blue_glCore_glFinishFenceNV;
void APIENTRY bluegl_glFinishFenceNV (GLuint fence) {
    typedef void (APIENTRYP PFN_glFinishFenceNV) (GLuint fence);
    return ((PFN_glFinishFenceNV)__blue_glCore_glFinishFenceNV)(fence);
}

extern void* __blue_glCore_glSetFenceNV;
void APIENTRY bluegl_glSetFenceNV (GLuint fence, GLenum condition) {
    typedef void (APIENTRYP PFN_glSetFenceNV) (GLuint fence, GLenum condition);
    return ((PFN_glSetFenceNV)__blue_glCore_glSetFenceNV)(fence, condition);
}

extern void* __blue_glCore_glFragmentCoverageColorNV;
void APIENTRY bluegl_glFragmentCoverageColorNV (GLuint color) {
    typedef void (APIENTRYP PFN_glFragmentCoverageColorNV) (GLuint color);
    return ((PFN_glFragmentCoverageColorNV)__blue_glCore_glFragmentCoverageColorNV)(color);
}

extern void* __blue_glCore_glProgramNamedParameter4fNV;
void APIENTRY bluegl_glProgramNamedParameter4fNV (GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glProgramNamedParameter4fNV) (GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glProgramNamedParameter4fNV)__blue_glCore_glProgramNamedParameter4fNV)(id, len, name, x, y, z, w);
}

extern void* __blue_glCore_glProgramNamedParameter4fvNV;
void APIENTRY bluegl_glProgramNamedParameter4fvNV (GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glProgramNamedParameter4fvNV) (GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v);
    return ((PFN_glProgramNamedParameter4fvNV)__blue_glCore_glProgramNamedParameter4fvNV)(id, len, name, v);
}

extern void* __blue_glCore_glProgramNamedParameter4dNV;
void APIENTRY bluegl_glProgramNamedParameter4dNV (GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glProgramNamedParameter4dNV) (GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glProgramNamedParameter4dNV)__blue_glCore_glProgramNamedParameter4dNV)(id, len, name, x, y, z, w);
}

extern void* __blue_glCore_glProgramNamedParameter4dvNV;
void APIENTRY bluegl_glProgramNamedParameter4dvNV (GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glProgramNamedParameter4dvNV) (GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v);
    return ((PFN_glProgramNamedParameter4dvNV)__blue_glCore_glProgramNamedParameter4dvNV)(id, len, name, v);
}

extern void* __blue_glCore_glGetProgramNamedParameterfvNV;
void APIENTRY bluegl_glGetProgramNamedParameterfvNV (GLuint id, GLsizei len, const GLubyte *name, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetProgramNamedParameterfvNV) (GLuint id, GLsizei len, const GLubyte *name, GLfloat *params);
    return ((PFN_glGetProgramNamedParameterfvNV)__blue_glCore_glGetProgramNamedParameterfvNV)(id, len, name, params);
}

extern void* __blue_glCore_glGetProgramNamedParameterdvNV;
void APIENTRY bluegl_glGetProgramNamedParameterdvNV (GLuint id, GLsizei len, const GLubyte *name, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetProgramNamedParameterdvNV) (GLuint id, GLsizei len, const GLubyte *name, GLdouble *params);
    return ((PFN_glGetProgramNamedParameterdvNV)__blue_glCore_glGetProgramNamedParameterdvNV)(id, len, name, params);
}

extern void* __blue_glCore_glCoverageModulationTableNV;
void APIENTRY bluegl_glCoverageModulationTableNV (GLsizei n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glCoverageModulationTableNV) (GLsizei n, const GLfloat *v);
    return ((PFN_glCoverageModulationTableNV)__blue_glCore_glCoverageModulationTableNV)(n, v);
}

extern void* __blue_glCore_glGetCoverageModulationTableNV;
void APIENTRY bluegl_glGetCoverageModulationTableNV (GLsizei bufsize, GLfloat *v) {
    typedef void (APIENTRYP PFN_glGetCoverageModulationTableNV) (GLsizei bufsize, GLfloat *v);
    return ((PFN_glGetCoverageModulationTableNV)__blue_glCore_glGetCoverageModulationTableNV)(bufsize, v);
}

extern void* __blue_glCore_glCoverageModulationNV;
void APIENTRY bluegl_glCoverageModulationNV (GLenum components) {
    typedef void (APIENTRYP PFN_glCoverageModulationNV) (GLenum components);
    return ((PFN_glCoverageModulationNV)__blue_glCore_glCoverageModulationNV)(components);
}

extern void* __blue_glCore_glRenderbufferStorageMultisampleCoverageNV;
void APIENTRY bluegl_glRenderbufferStorageMultisampleCoverageNV (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) {
    typedef void (APIENTRYP PFN_glRenderbufferStorageMultisampleCoverageNV) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
    return ((PFN_glRenderbufferStorageMultisampleCoverageNV)__blue_glCore_glRenderbufferStorageMultisampleCoverageNV)(target, coverageSamples, colorSamples, internalformat, width, height);
}

extern void* __blue_glCore_glProgramVertexLimitNV;
void APIENTRY bluegl_glProgramVertexLimitNV (GLenum target, GLint limit) {
    typedef void (APIENTRYP PFN_glProgramVertexLimitNV) (GLenum target, GLint limit);
    return ((PFN_glProgramVertexLimitNV)__blue_glCore_glProgramVertexLimitNV)(target, limit);
}

extern void* __blue_glCore_glFramebufferTextureEXT;
void APIENTRY bluegl_glFramebufferTextureEXT (GLenum target, GLenum attachment, GLuint texture, GLint level) {
    typedef void (APIENTRYP PFN_glFramebufferTextureEXT) (GLenum target, GLenum attachment, GLuint texture, GLint level);
    return ((PFN_glFramebufferTextureEXT)__blue_glCore_glFramebufferTextureEXT)(target, attachment, texture, level);
}

extern void* __blue_glCore_glFramebufferTextureFaceEXT;
void APIENTRY bluegl_glFramebufferTextureFaceEXT (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) {
    typedef void (APIENTRYP PFN_glFramebufferTextureFaceEXT) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
    return ((PFN_glFramebufferTextureFaceEXT)__blue_glCore_glFramebufferTextureFaceEXT)(target, attachment, texture, level, face);
}

extern void* __blue_glCore_glProgramLocalParameterI4iNV;
void APIENTRY bluegl_glProgramLocalParameterI4iNV (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
    typedef void (APIENTRYP PFN_glProgramLocalParameterI4iNV) (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
    return ((PFN_glProgramLocalParameterI4iNV)__blue_glCore_glProgramLocalParameterI4iNV)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramLocalParameterI4ivNV;
void APIENTRY bluegl_glProgramLocalParameterI4ivNV (GLenum target, GLuint index, const GLint *params) {
    typedef void (APIENTRYP PFN_glProgramLocalParameterI4ivNV) (GLenum target, GLuint index, const GLint *params);
    return ((PFN_glProgramLocalParameterI4ivNV)__blue_glCore_glProgramLocalParameterI4ivNV)(target, index, params);
}

extern void* __blue_glCore_glProgramLocalParametersI4ivNV;
void APIENTRY bluegl_glProgramLocalParametersI4ivNV (GLenum target, GLuint index, GLsizei count, const GLint *params) {
    typedef void (APIENTRYP PFN_glProgramLocalParametersI4ivNV) (GLenum target, GLuint index, GLsizei count, const GLint *params);
    return ((PFN_glProgramLocalParametersI4ivNV)__blue_glCore_glProgramLocalParametersI4ivNV)(target, index, count, params);
}

extern void* __blue_glCore_glProgramLocalParameterI4uiNV;
void APIENTRY bluegl_glProgramLocalParameterI4uiNV (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    typedef void (APIENTRYP PFN_glProgramLocalParameterI4uiNV) (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    return ((PFN_glProgramLocalParameterI4uiNV)__blue_glCore_glProgramLocalParameterI4uiNV)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramLocalParameterI4uivNV;
void APIENTRY bluegl_glProgramLocalParameterI4uivNV (GLenum target, GLuint index, const GLuint *params) {
    typedef void (APIENTRYP PFN_glProgramLocalParameterI4uivNV) (GLenum target, GLuint index, const GLuint *params);
    return ((PFN_glProgramLocalParameterI4uivNV)__blue_glCore_glProgramLocalParameterI4uivNV)(target, index, params);
}

extern void* __blue_glCore_glProgramLocalParametersI4uivNV;
void APIENTRY bluegl_glProgramLocalParametersI4uivNV (GLenum target, GLuint index, GLsizei count, const GLuint *params) {
    typedef void (APIENTRYP PFN_glProgramLocalParametersI4uivNV) (GLenum target, GLuint index, GLsizei count, const GLuint *params);
    return ((PFN_glProgramLocalParametersI4uivNV)__blue_glCore_glProgramLocalParametersI4uivNV)(target, index, count, params);
}

extern void* __blue_glCore_glProgramEnvParameterI4iNV;
void APIENTRY bluegl_glProgramEnvParameterI4iNV (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
    typedef void (APIENTRYP PFN_glProgramEnvParameterI4iNV) (GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
    return ((PFN_glProgramEnvParameterI4iNV)__blue_glCore_glProgramEnvParameterI4iNV)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramEnvParameterI4ivNV;
void APIENTRY bluegl_glProgramEnvParameterI4ivNV (GLenum target, GLuint index, const GLint *params) {
    typedef void (APIENTRYP PFN_glProgramEnvParameterI4ivNV) (GLenum target, GLuint index, const GLint *params);
    return ((PFN_glProgramEnvParameterI4ivNV)__blue_glCore_glProgramEnvParameterI4ivNV)(target, index, params);
}

extern void* __blue_glCore_glProgramEnvParametersI4ivNV;
void APIENTRY bluegl_glProgramEnvParametersI4ivNV (GLenum target, GLuint index, GLsizei count, const GLint *params) {
    typedef void (APIENTRYP PFN_glProgramEnvParametersI4ivNV) (GLenum target, GLuint index, GLsizei count, const GLint *params);
    return ((PFN_glProgramEnvParametersI4ivNV)__blue_glCore_glProgramEnvParametersI4ivNV)(target, index, count, params);
}

extern void* __blue_glCore_glProgramEnvParameterI4uiNV;
void APIENTRY bluegl_glProgramEnvParameterI4uiNV (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    typedef void (APIENTRYP PFN_glProgramEnvParameterI4uiNV) (GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    return ((PFN_glProgramEnvParameterI4uiNV)__blue_glCore_glProgramEnvParameterI4uiNV)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramEnvParameterI4uivNV;
void APIENTRY bluegl_glProgramEnvParameterI4uivNV (GLenum target, GLuint index, const GLuint *params) {
    typedef void (APIENTRYP PFN_glProgramEnvParameterI4uivNV) (GLenum target, GLuint index, const GLuint *params);
    return ((PFN_glProgramEnvParameterI4uivNV)__blue_glCore_glProgramEnvParameterI4uivNV)(target, index, params);
}

extern void* __blue_glCore_glProgramEnvParametersI4uivNV;
void APIENTRY bluegl_glProgramEnvParametersI4uivNV (GLenum target, GLuint index, GLsizei count, const GLuint *params) {
    typedef void (APIENTRYP PFN_glProgramEnvParametersI4uivNV) (GLenum target, GLuint index, GLsizei count, const GLuint *params);
    return ((PFN_glProgramEnvParametersI4uivNV)__blue_glCore_glProgramEnvParametersI4uivNV)(target, index, count, params);
}

extern void* __blue_glCore_glGetProgramLocalParameterIivNV;
void APIENTRY bluegl_glGetProgramLocalParameterIivNV (GLenum target, GLuint index, GLint *params) {
    typedef void (APIENTRYP PFN_glGetProgramLocalParameterIivNV) (GLenum target, GLuint index, GLint *params);
    return ((PFN_glGetProgramLocalParameterIivNV)__blue_glCore_glGetProgramLocalParameterIivNV)(target, index, params);
}

extern void* __blue_glCore_glGetProgramLocalParameterIuivNV;
void APIENTRY bluegl_glGetProgramLocalParameterIuivNV (GLenum target, GLuint index, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetProgramLocalParameterIuivNV) (GLenum target, GLuint index, GLuint *params);
    return ((PFN_glGetProgramLocalParameterIuivNV)__blue_glCore_glGetProgramLocalParameterIuivNV)(target, index, params);
}

extern void* __blue_glCore_glGetProgramEnvParameterIivNV;
void APIENTRY bluegl_glGetProgramEnvParameterIivNV (GLenum target, GLuint index, GLint *params) {
    typedef void (APIENTRYP PFN_glGetProgramEnvParameterIivNV) (GLenum target, GLuint index, GLint *params);
    return ((PFN_glGetProgramEnvParameterIivNV)__blue_glCore_glGetProgramEnvParameterIivNV)(target, index, params);
}

extern void* __blue_glCore_glGetProgramEnvParameterIuivNV;
void APIENTRY bluegl_glGetProgramEnvParameterIuivNV (GLenum target, GLuint index, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetProgramEnvParameterIuivNV) (GLenum target, GLuint index, GLuint *params);
    return ((PFN_glGetProgramEnvParameterIuivNV)__blue_glCore_glGetProgramEnvParameterIuivNV)(target, index, params);
}

extern void* __blue_glCore_glProgramSubroutineParametersuivNV;
void APIENTRY bluegl_glProgramSubroutineParametersuivNV (GLenum target, GLsizei count, const GLuint *params) {
    typedef void (APIENTRYP PFN_glProgramSubroutineParametersuivNV) (GLenum target, GLsizei count, const GLuint *params);
    return ((PFN_glProgramSubroutineParametersuivNV)__blue_glCore_glProgramSubroutineParametersuivNV)(target, count, params);
}

extern void* __blue_glCore_glGetProgramSubroutineParameteruivNV;
void APIENTRY bluegl_glGetProgramSubroutineParameteruivNV (GLenum target, GLuint index, GLuint *param) {
    typedef void (APIENTRYP PFN_glGetProgramSubroutineParameteruivNV) (GLenum target, GLuint index, GLuint *param);
    return ((PFN_glGetProgramSubroutineParameteruivNV)__blue_glCore_glGetProgramSubroutineParameteruivNV)(target, index, param);
}

extern void* __blue_glCore_glVertex2hNV;
void APIENTRY bluegl_glVertex2hNV (GLhalfNV x, GLhalfNV y) {
    typedef void (APIENTRYP PFN_glVertex2hNV) (GLhalfNV x, GLhalfNV y);
    return ((PFN_glVertex2hNV)__blue_glCore_glVertex2hNV)(x, y);
}

extern void* __blue_glCore_glVertex2hvNV;
void APIENTRY bluegl_glVertex2hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertex2hvNV) (const GLhalfNV *v);
    return ((PFN_glVertex2hvNV)__blue_glCore_glVertex2hvNV)(v);
}

extern void* __blue_glCore_glVertex3hNV;
void APIENTRY bluegl_glVertex3hNV (GLhalfNV x, GLhalfNV y, GLhalfNV z) {
    typedef void (APIENTRYP PFN_glVertex3hNV) (GLhalfNV x, GLhalfNV y, GLhalfNV z);
    return ((PFN_glVertex3hNV)__blue_glCore_glVertex3hNV)(x, y, z);
}

extern void* __blue_glCore_glVertex3hvNV;
void APIENTRY bluegl_glVertex3hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertex3hvNV) (const GLhalfNV *v);
    return ((PFN_glVertex3hvNV)__blue_glCore_glVertex3hvNV)(v);
}

extern void* __blue_glCore_glVertex4hNV;
void APIENTRY bluegl_glVertex4hNV (GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) {
    typedef void (APIENTRYP PFN_glVertex4hNV) (GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
    return ((PFN_glVertex4hNV)__blue_glCore_glVertex4hNV)(x, y, z, w);
}

extern void* __blue_glCore_glVertex4hvNV;
void APIENTRY bluegl_glVertex4hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertex4hvNV) (const GLhalfNV *v);
    return ((PFN_glVertex4hvNV)__blue_glCore_glVertex4hvNV)(v);
}

extern void* __blue_glCore_glNormal3hNV;
void APIENTRY bluegl_glNormal3hNV (GLhalfNV nx, GLhalfNV ny, GLhalfNV nz) {
    typedef void (APIENTRYP PFN_glNormal3hNV) (GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
    return ((PFN_glNormal3hNV)__blue_glCore_glNormal3hNV)(nx, ny, nz);
}

extern void* __blue_glCore_glNormal3hvNV;
void APIENTRY bluegl_glNormal3hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glNormal3hvNV) (const GLhalfNV *v);
    return ((PFN_glNormal3hvNV)__blue_glCore_glNormal3hvNV)(v);
}

extern void* __blue_glCore_glColor3hNV;
void APIENTRY bluegl_glColor3hNV (GLhalfNV red, GLhalfNV green, GLhalfNV blue) {
    typedef void (APIENTRYP PFN_glColor3hNV) (GLhalfNV red, GLhalfNV green, GLhalfNV blue);
    return ((PFN_glColor3hNV)__blue_glCore_glColor3hNV)(red, green, blue);
}

extern void* __blue_glCore_glColor3hvNV;
void APIENTRY bluegl_glColor3hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glColor3hvNV) (const GLhalfNV *v);
    return ((PFN_glColor3hvNV)__blue_glCore_glColor3hvNV)(v);
}

extern void* __blue_glCore_glColor4hNV;
void APIENTRY bluegl_glColor4hNV (GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha) {
    typedef void (APIENTRYP PFN_glColor4hNV) (GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
    return ((PFN_glColor4hNV)__blue_glCore_glColor4hNV)(red, green, blue, alpha);
}

extern void* __blue_glCore_glColor4hvNV;
void APIENTRY bluegl_glColor4hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glColor4hvNV) (const GLhalfNV *v);
    return ((PFN_glColor4hvNV)__blue_glCore_glColor4hvNV)(v);
}

extern void* __blue_glCore_glTexCoord1hNV;
void APIENTRY bluegl_glTexCoord1hNV (GLhalfNV s) {
    typedef void (APIENTRYP PFN_glTexCoord1hNV) (GLhalfNV s);
    return ((PFN_glTexCoord1hNV)__blue_glCore_glTexCoord1hNV)(s);
}

extern void* __blue_glCore_glTexCoord1hvNV;
void APIENTRY bluegl_glTexCoord1hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glTexCoord1hvNV) (const GLhalfNV *v);
    return ((PFN_glTexCoord1hvNV)__blue_glCore_glTexCoord1hvNV)(v);
}

extern void* __blue_glCore_glTexCoord2hNV;
void APIENTRY bluegl_glTexCoord2hNV (GLhalfNV s, GLhalfNV t) {
    typedef void (APIENTRYP PFN_glTexCoord2hNV) (GLhalfNV s, GLhalfNV t);
    return ((PFN_glTexCoord2hNV)__blue_glCore_glTexCoord2hNV)(s, t);
}

extern void* __blue_glCore_glTexCoord2hvNV;
void APIENTRY bluegl_glTexCoord2hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glTexCoord2hvNV) (const GLhalfNV *v);
    return ((PFN_glTexCoord2hvNV)__blue_glCore_glTexCoord2hvNV)(v);
}

extern void* __blue_glCore_glTexCoord3hNV;
void APIENTRY bluegl_glTexCoord3hNV (GLhalfNV s, GLhalfNV t, GLhalfNV r) {
    typedef void (APIENTRYP PFN_glTexCoord3hNV) (GLhalfNV s, GLhalfNV t, GLhalfNV r);
    return ((PFN_glTexCoord3hNV)__blue_glCore_glTexCoord3hNV)(s, t, r);
}

extern void* __blue_glCore_glTexCoord3hvNV;
void APIENTRY bluegl_glTexCoord3hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glTexCoord3hvNV) (const GLhalfNV *v);
    return ((PFN_glTexCoord3hvNV)__blue_glCore_glTexCoord3hvNV)(v);
}

extern void* __blue_glCore_glTexCoord4hNV;
void APIENTRY bluegl_glTexCoord4hNV (GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) {
    typedef void (APIENTRYP PFN_glTexCoord4hNV) (GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
    return ((PFN_glTexCoord4hNV)__blue_glCore_glTexCoord4hNV)(s, t, r, q);
}

extern void* __blue_glCore_glTexCoord4hvNV;
void APIENTRY bluegl_glTexCoord4hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glTexCoord4hvNV) (const GLhalfNV *v);
    return ((PFN_glTexCoord4hvNV)__blue_glCore_glTexCoord4hvNV)(v);
}

extern void* __blue_glCore_glMultiTexCoord1hNV;
void APIENTRY bluegl_glMultiTexCoord1hNV (GLenum target, GLhalfNV s) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1hNV) (GLenum target, GLhalfNV s);
    return ((PFN_glMultiTexCoord1hNV)__blue_glCore_glMultiTexCoord1hNV)(target, s);
}

extern void* __blue_glCore_glMultiTexCoord1hvNV;
void APIENTRY bluegl_glMultiTexCoord1hvNV (GLenum target, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord1hvNV) (GLenum target, const GLhalfNV *v);
    return ((PFN_glMultiTexCoord1hvNV)__blue_glCore_glMultiTexCoord1hvNV)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord2hNV;
void APIENTRY bluegl_glMultiTexCoord2hNV (GLenum target, GLhalfNV s, GLhalfNV t) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2hNV) (GLenum target, GLhalfNV s, GLhalfNV t);
    return ((PFN_glMultiTexCoord2hNV)__blue_glCore_glMultiTexCoord2hNV)(target, s, t);
}

extern void* __blue_glCore_glMultiTexCoord2hvNV;
void APIENTRY bluegl_glMultiTexCoord2hvNV (GLenum target, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord2hvNV) (GLenum target, const GLhalfNV *v);
    return ((PFN_glMultiTexCoord2hvNV)__blue_glCore_glMultiTexCoord2hvNV)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord3hNV;
void APIENTRY bluegl_glMultiTexCoord3hNV (GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3hNV) (GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
    return ((PFN_glMultiTexCoord3hNV)__blue_glCore_glMultiTexCoord3hNV)(target, s, t, r);
}

extern void* __blue_glCore_glMultiTexCoord3hvNV;
void APIENTRY bluegl_glMultiTexCoord3hvNV (GLenum target, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord3hvNV) (GLenum target, const GLhalfNV *v);
    return ((PFN_glMultiTexCoord3hvNV)__blue_glCore_glMultiTexCoord3hvNV)(target, v);
}

extern void* __blue_glCore_glMultiTexCoord4hNV;
void APIENTRY bluegl_glMultiTexCoord4hNV (GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4hNV) (GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
    return ((PFN_glMultiTexCoord4hNV)__blue_glCore_glMultiTexCoord4hNV)(target, s, t, r, q);
}

extern void* __blue_glCore_glMultiTexCoord4hvNV;
void APIENTRY bluegl_glMultiTexCoord4hvNV (GLenum target, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glMultiTexCoord4hvNV) (GLenum target, const GLhalfNV *v);
    return ((PFN_glMultiTexCoord4hvNV)__blue_glCore_glMultiTexCoord4hvNV)(target, v);
}

extern void* __blue_glCore_glFogCoordhNV;
void APIENTRY bluegl_glFogCoordhNV (GLhalfNV fog) {
    typedef void (APIENTRYP PFN_glFogCoordhNV) (GLhalfNV fog);
    return ((PFN_glFogCoordhNV)__blue_glCore_glFogCoordhNV)(fog);
}

extern void* __blue_glCore_glFogCoordhvNV;
void APIENTRY bluegl_glFogCoordhvNV (const GLhalfNV *fog) {
    typedef void (APIENTRYP PFN_glFogCoordhvNV) (const GLhalfNV *fog);
    return ((PFN_glFogCoordhvNV)__blue_glCore_glFogCoordhvNV)(fog);
}

extern void* __blue_glCore_glSecondaryColor3hNV;
void APIENTRY bluegl_glSecondaryColor3hNV (GLhalfNV red, GLhalfNV green, GLhalfNV blue) {
    typedef void (APIENTRYP PFN_glSecondaryColor3hNV) (GLhalfNV red, GLhalfNV green, GLhalfNV blue);
    return ((PFN_glSecondaryColor3hNV)__blue_glCore_glSecondaryColor3hNV)(red, green, blue);
}

extern void* __blue_glCore_glSecondaryColor3hvNV;
void APIENTRY bluegl_glSecondaryColor3hvNV (const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glSecondaryColor3hvNV) (const GLhalfNV *v);
    return ((PFN_glSecondaryColor3hvNV)__blue_glCore_glSecondaryColor3hvNV)(v);
}

extern void* __blue_glCore_glVertexWeighthNV;
void APIENTRY bluegl_glVertexWeighthNV (GLhalfNV weight) {
    typedef void (APIENTRYP PFN_glVertexWeighthNV) (GLhalfNV weight);
    return ((PFN_glVertexWeighthNV)__blue_glCore_glVertexWeighthNV)(weight);
}

extern void* __blue_glCore_glVertexWeighthvNV;
void APIENTRY bluegl_glVertexWeighthvNV (const GLhalfNV *weight) {
    typedef void (APIENTRYP PFN_glVertexWeighthvNV) (const GLhalfNV *weight);
    return ((PFN_glVertexWeighthvNV)__blue_glCore_glVertexWeighthvNV)(weight);
}

extern void* __blue_glCore_glVertexAttrib1hNV;
void APIENTRY bluegl_glVertexAttrib1hNV (GLuint index, GLhalfNV x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1hNV) (GLuint index, GLhalfNV x);
    return ((PFN_glVertexAttrib1hNV)__blue_glCore_glVertexAttrib1hNV)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1hvNV;
void APIENTRY bluegl_glVertexAttrib1hvNV (GLuint index, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1hvNV) (GLuint index, const GLhalfNV *v);
    return ((PFN_glVertexAttrib1hvNV)__blue_glCore_glVertexAttrib1hvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2hNV;
void APIENTRY bluegl_glVertexAttrib2hNV (GLuint index, GLhalfNV x, GLhalfNV y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2hNV) (GLuint index, GLhalfNV x, GLhalfNV y);
    return ((PFN_glVertexAttrib2hNV)__blue_glCore_glVertexAttrib2hNV)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2hvNV;
void APIENTRY bluegl_glVertexAttrib2hvNV (GLuint index, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2hvNV) (GLuint index, const GLhalfNV *v);
    return ((PFN_glVertexAttrib2hvNV)__blue_glCore_glVertexAttrib2hvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3hNV;
void APIENTRY bluegl_glVertexAttrib3hNV (GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3hNV) (GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
    return ((PFN_glVertexAttrib3hNV)__blue_glCore_glVertexAttrib3hNV)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3hvNV;
void APIENTRY bluegl_glVertexAttrib3hvNV (GLuint index, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3hvNV) (GLuint index, const GLhalfNV *v);
    return ((PFN_glVertexAttrib3hvNV)__blue_glCore_glVertexAttrib3hvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4hNV;
void APIENTRY bluegl_glVertexAttrib4hNV (GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4hNV) (GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
    return ((PFN_glVertexAttrib4hNV)__blue_glCore_glVertexAttrib4hNV)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4hvNV;
void APIENTRY bluegl_glVertexAttrib4hvNV (GLuint index, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4hvNV) (GLuint index, const GLhalfNV *v);
    return ((PFN_glVertexAttrib4hvNV)__blue_glCore_glVertexAttrib4hvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttribs1hvNV;
void APIENTRY bluegl_glVertexAttribs1hvNV (GLuint index, GLsizei n, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs1hvNV) (GLuint index, GLsizei n, const GLhalfNV *v);
    return ((PFN_glVertexAttribs1hvNV)__blue_glCore_glVertexAttribs1hvNV)(index, n, v);
}

extern void* __blue_glCore_glVertexAttribs2hvNV;
void APIENTRY bluegl_glVertexAttribs2hvNV (GLuint index, GLsizei n, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs2hvNV) (GLuint index, GLsizei n, const GLhalfNV *v);
    return ((PFN_glVertexAttribs2hvNV)__blue_glCore_glVertexAttribs2hvNV)(index, n, v);
}

extern void* __blue_glCore_glVertexAttribs3hvNV;
void APIENTRY bluegl_glVertexAttribs3hvNV (GLuint index, GLsizei n, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs3hvNV) (GLuint index, GLsizei n, const GLhalfNV *v);
    return ((PFN_glVertexAttribs3hvNV)__blue_glCore_glVertexAttribs3hvNV)(index, n, v);
}

extern void* __blue_glCore_glVertexAttribs4hvNV;
void APIENTRY bluegl_glVertexAttribs4hvNV (GLuint index, GLsizei n, const GLhalfNV *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs4hvNV) (GLuint index, GLsizei n, const GLhalfNV *v);
    return ((PFN_glVertexAttribs4hvNV)__blue_glCore_glVertexAttribs4hvNV)(index, n, v);
}

extern void* __blue_glCore_glGetInternalformatSampleivNV;
void APIENTRY bluegl_glGetInternalformatSampleivNV (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params) {
    typedef void (APIENTRYP PFN_glGetInternalformatSampleivNV) (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params);
    return ((PFN_glGetInternalformatSampleivNV)__blue_glCore_glGetInternalformatSampleivNV)(target, internalformat, samples, pname, bufSize, params);
}

extern void* __blue_glCore_glGenOcclusionQueriesNV;
void APIENTRY bluegl_glGenOcclusionQueriesNV (GLsizei n, GLuint *ids) {
    typedef void (APIENTRYP PFN_glGenOcclusionQueriesNV) (GLsizei n, GLuint *ids);
    return ((PFN_glGenOcclusionQueriesNV)__blue_glCore_glGenOcclusionQueriesNV)(n, ids);
}

extern void* __blue_glCore_glDeleteOcclusionQueriesNV;
void APIENTRY bluegl_glDeleteOcclusionQueriesNV (GLsizei n, const GLuint *ids) {
    typedef void (APIENTRYP PFN_glDeleteOcclusionQueriesNV) (GLsizei n, const GLuint *ids);
    return ((PFN_glDeleteOcclusionQueriesNV)__blue_glCore_glDeleteOcclusionQueriesNV)(n, ids);
}

extern void* __blue_glCore_glIsOcclusionQueryNV;
GLboolean APIENTRY bluegl_glIsOcclusionQueryNV (GLuint id) {
    typedef GLboolean (APIENTRYP PFN_glIsOcclusionQueryNV) (GLuint id);
    return ((PFN_glIsOcclusionQueryNV)__blue_glCore_glIsOcclusionQueryNV)(id);
}

extern void* __blue_glCore_glBeginOcclusionQueryNV;
void APIENTRY bluegl_glBeginOcclusionQueryNV (GLuint id) {
    typedef void (APIENTRYP PFN_glBeginOcclusionQueryNV) (GLuint id);
    return ((PFN_glBeginOcclusionQueryNV)__blue_glCore_glBeginOcclusionQueryNV)(id);
}

extern void* __blue_glCore_glEndOcclusionQueryNV;
void APIENTRY bluegl_glEndOcclusionQueryNV (void) {
    typedef void (APIENTRYP PFN_glEndOcclusionQueryNV) (void);
    return ((PFN_glEndOcclusionQueryNV)__blue_glCore_glEndOcclusionQueryNV)();
}

extern void* __blue_glCore_glGetOcclusionQueryivNV;
void APIENTRY bluegl_glGetOcclusionQueryivNV (GLuint id, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetOcclusionQueryivNV) (GLuint id, GLenum pname, GLint *params);
    return ((PFN_glGetOcclusionQueryivNV)__blue_glCore_glGetOcclusionQueryivNV)(id, pname, params);
}

extern void* __blue_glCore_glGetOcclusionQueryuivNV;
void APIENTRY bluegl_glGetOcclusionQueryuivNV (GLuint id, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetOcclusionQueryuivNV) (GLuint id, GLenum pname, GLuint *params);
    return ((PFN_glGetOcclusionQueryuivNV)__blue_glCore_glGetOcclusionQueryuivNV)(id, pname, params);
}

extern void* __blue_glCore_glProgramBufferParametersfvNV;
void APIENTRY bluegl_glProgramBufferParametersfvNV (GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glProgramBufferParametersfvNV) (GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat *params);
    return ((PFN_glProgramBufferParametersfvNV)__blue_glCore_glProgramBufferParametersfvNV)(target, bindingIndex, wordIndex, count, params);
}

extern void* __blue_glCore_glProgramBufferParametersIivNV;
void APIENTRY bluegl_glProgramBufferParametersIivNV (GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint *params) {
    typedef void (APIENTRYP PFN_glProgramBufferParametersIivNV) (GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint *params);
    return ((PFN_glProgramBufferParametersIivNV)__blue_glCore_glProgramBufferParametersIivNV)(target, bindingIndex, wordIndex, count, params);
}

extern void* __blue_glCore_glProgramBufferParametersIuivNV;
void APIENTRY bluegl_glProgramBufferParametersIuivNV (GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint *params) {
    typedef void (APIENTRYP PFN_glProgramBufferParametersIuivNV) (GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint *params);
    return ((PFN_glProgramBufferParametersIuivNV)__blue_glCore_glProgramBufferParametersIuivNV)(target, bindingIndex, wordIndex, count, params);
}

extern void* __blue_glCore_glGenPathsNV;
GLuint APIENTRY bluegl_glGenPathsNV (GLsizei range) {
    typedef GLuint (APIENTRYP PFN_glGenPathsNV) (GLsizei range);
    return ((PFN_glGenPathsNV)__blue_glCore_glGenPathsNV)(range);
}

extern void* __blue_glCore_glDeletePathsNV;
void APIENTRY bluegl_glDeletePathsNV (GLuint path, GLsizei range) {
    typedef void (APIENTRYP PFN_glDeletePathsNV) (GLuint path, GLsizei range);
    return ((PFN_glDeletePathsNV)__blue_glCore_glDeletePathsNV)(path, range);
}

extern void* __blue_glCore_glIsPathNV;
GLboolean APIENTRY bluegl_glIsPathNV (GLuint path) {
    typedef GLboolean (APIENTRYP PFN_glIsPathNV) (GLuint path);
    return ((PFN_glIsPathNV)__blue_glCore_glIsPathNV)(path);
}

extern void* __blue_glCore_glPathCommandsNV;
void APIENTRY bluegl_glPathCommandsNV (GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords) {
    typedef void (APIENTRYP PFN_glPathCommandsNV) (GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
    return ((PFN_glPathCommandsNV)__blue_glCore_glPathCommandsNV)(path, numCommands, commands, numCoords, coordType, coords);
}

extern void* __blue_glCore_glPathCoordsNV;
void APIENTRY bluegl_glPathCoordsNV (GLuint path, GLsizei numCoords, GLenum coordType, const void *coords) {
    typedef void (APIENTRYP PFN_glPathCoordsNV) (GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
    return ((PFN_glPathCoordsNV)__blue_glCore_glPathCoordsNV)(path, numCoords, coordType, coords);
}

extern void* __blue_glCore_glPathSubCommandsNV;
void APIENTRY bluegl_glPathSubCommandsNV (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords) {
    typedef void (APIENTRYP PFN_glPathSubCommandsNV) (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
    return ((PFN_glPathSubCommandsNV)__blue_glCore_glPathSubCommandsNV)(path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords);
}

extern void* __blue_glCore_glPathSubCoordsNV;
void APIENTRY bluegl_glPathSubCoordsNV (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords) {
    typedef void (APIENTRYP PFN_glPathSubCoordsNV) (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
    return ((PFN_glPathSubCoordsNV)__blue_glCore_glPathSubCoordsNV)(path, coordStart, numCoords, coordType, coords);
}

extern void* __blue_glCore_glPathStringNV;
void APIENTRY bluegl_glPathStringNV (GLuint path, GLenum format, GLsizei length, const void *pathString) {
    typedef void (APIENTRYP PFN_glPathStringNV) (GLuint path, GLenum format, GLsizei length, const void *pathString);
    return ((PFN_glPathStringNV)__blue_glCore_glPathStringNV)(path, format, length, pathString);
}

extern void* __blue_glCore_glPathGlyphsNV;
void APIENTRY bluegl_glPathGlyphsNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
    typedef void (APIENTRYP PFN_glPathGlyphsNV) (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    return ((PFN_glPathGlyphsNV)__blue_glCore_glPathGlyphsNV)(firstPathName, fontTarget, fontName, fontStyle, numGlyphs, type, charcodes, handleMissingGlyphs, pathParameterTemplate, emScale);
}

extern void* __blue_glCore_glPathGlyphRangeNV;
void APIENTRY bluegl_glPathGlyphRangeNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
    typedef void (APIENTRYP PFN_glPathGlyphRangeNV) (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    return ((PFN_glPathGlyphRangeNV)__blue_glCore_glPathGlyphRangeNV)(firstPathName, fontTarget, fontName, fontStyle, firstGlyph, numGlyphs, handleMissingGlyphs, pathParameterTemplate, emScale);
}

extern void* __blue_glCore_glWeightPathsNV;
void APIENTRY bluegl_glWeightPathsNV (GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights) {
    typedef void (APIENTRYP PFN_glWeightPathsNV) (GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
    return ((PFN_glWeightPathsNV)__blue_glCore_glWeightPathsNV)(resultPath, numPaths, paths, weights);
}

extern void* __blue_glCore_glCopyPathNV;
void APIENTRY bluegl_glCopyPathNV (GLuint resultPath, GLuint srcPath) {
    typedef void (APIENTRYP PFN_glCopyPathNV) (GLuint resultPath, GLuint srcPath);
    return ((PFN_glCopyPathNV)__blue_glCore_glCopyPathNV)(resultPath, srcPath);
}

extern void* __blue_glCore_glInterpolatePathsNV;
void APIENTRY bluegl_glInterpolatePathsNV (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight) {
    typedef void (APIENTRYP PFN_glInterpolatePathsNV) (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
    return ((PFN_glInterpolatePathsNV)__blue_glCore_glInterpolatePathsNV)(resultPath, pathA, pathB, weight);
}

extern void* __blue_glCore_glTransformPathNV;
void APIENTRY bluegl_glTransformPathNV (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues) {
    typedef void (APIENTRYP PFN_glTransformPathNV) (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
    return ((PFN_glTransformPathNV)__blue_glCore_glTransformPathNV)(resultPath, srcPath, transformType, transformValues);
}

extern void* __blue_glCore_glPathParameterivNV;
void APIENTRY bluegl_glPathParameterivNV (GLuint path, GLenum pname, const GLint *value) {
    typedef void (APIENTRYP PFN_glPathParameterivNV) (GLuint path, GLenum pname, const GLint *value);
    return ((PFN_glPathParameterivNV)__blue_glCore_glPathParameterivNV)(path, pname, value);
}

extern void* __blue_glCore_glPathParameteriNV;
void APIENTRY bluegl_glPathParameteriNV (GLuint path, GLenum pname, GLint value) {
    typedef void (APIENTRYP PFN_glPathParameteriNV) (GLuint path, GLenum pname, GLint value);
    return ((PFN_glPathParameteriNV)__blue_glCore_glPathParameteriNV)(path, pname, value);
}

extern void* __blue_glCore_glPathParameterfvNV;
void APIENTRY bluegl_glPathParameterfvNV (GLuint path, GLenum pname, const GLfloat *value) {
    typedef void (APIENTRYP PFN_glPathParameterfvNV) (GLuint path, GLenum pname, const GLfloat *value);
    return ((PFN_glPathParameterfvNV)__blue_glCore_glPathParameterfvNV)(path, pname, value);
}

extern void* __blue_glCore_glPathParameterfNV;
void APIENTRY bluegl_glPathParameterfNV (GLuint path, GLenum pname, GLfloat value) {
    typedef void (APIENTRYP PFN_glPathParameterfNV) (GLuint path, GLenum pname, GLfloat value);
    return ((PFN_glPathParameterfNV)__blue_glCore_glPathParameterfNV)(path, pname, value);
}

extern void* __blue_glCore_glPathDashArrayNV;
void APIENTRY bluegl_glPathDashArrayNV (GLuint path, GLsizei dashCount, const GLfloat *dashArray) {
    typedef void (APIENTRYP PFN_glPathDashArrayNV) (GLuint path, GLsizei dashCount, const GLfloat *dashArray);
    return ((PFN_glPathDashArrayNV)__blue_glCore_glPathDashArrayNV)(path, dashCount, dashArray);
}

extern void* __blue_glCore_glPathStencilFuncNV;
void APIENTRY bluegl_glPathStencilFuncNV (GLenum func, GLint ref, GLuint mask) {
    typedef void (APIENTRYP PFN_glPathStencilFuncNV) (GLenum func, GLint ref, GLuint mask);
    return ((PFN_glPathStencilFuncNV)__blue_glCore_glPathStencilFuncNV)(func, ref, mask);
}

extern void* __blue_glCore_glPathStencilDepthOffsetNV;
void APIENTRY bluegl_glPathStencilDepthOffsetNV (GLfloat factor, GLfloat units) {
    typedef void (APIENTRYP PFN_glPathStencilDepthOffsetNV) (GLfloat factor, GLfloat units);
    return ((PFN_glPathStencilDepthOffsetNV)__blue_glCore_glPathStencilDepthOffsetNV)(factor, units);
}

extern void* __blue_glCore_glStencilFillPathNV;
void APIENTRY bluegl_glStencilFillPathNV (GLuint path, GLenum fillMode, GLuint mask) {
    typedef void (APIENTRYP PFN_glStencilFillPathNV) (GLuint path, GLenum fillMode, GLuint mask);
    return ((PFN_glStencilFillPathNV)__blue_glCore_glStencilFillPathNV)(path, fillMode, mask);
}

extern void* __blue_glCore_glStencilStrokePathNV;
void APIENTRY bluegl_glStencilStrokePathNV (GLuint path, GLint reference, GLuint mask) {
    typedef void (APIENTRYP PFN_glStencilStrokePathNV) (GLuint path, GLint reference, GLuint mask);
    return ((PFN_glStencilStrokePathNV)__blue_glCore_glStencilStrokePathNV)(path, reference, mask);
}

extern void* __blue_glCore_glStencilFillPathInstancedNV;
void APIENTRY bluegl_glStencilFillPathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues) {
    typedef void (APIENTRYP PFN_glStencilFillPathInstancedNV) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
    return ((PFN_glStencilFillPathInstancedNV)__blue_glCore_glStencilFillPathInstancedNV)(numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues);
}

extern void* __blue_glCore_glStencilStrokePathInstancedNV;
void APIENTRY bluegl_glStencilStrokePathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues) {
    typedef void (APIENTRYP PFN_glStencilStrokePathInstancedNV) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
    return ((PFN_glStencilStrokePathInstancedNV)__blue_glCore_glStencilStrokePathInstancedNV)(numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues);
}

extern void* __blue_glCore_glPathCoverDepthFuncNV;
void APIENTRY bluegl_glPathCoverDepthFuncNV (GLenum func) {
    typedef void (APIENTRYP PFN_glPathCoverDepthFuncNV) (GLenum func);
    return ((PFN_glPathCoverDepthFuncNV)__blue_glCore_glPathCoverDepthFuncNV)(func);
}

extern void* __blue_glCore_glCoverFillPathNV;
void APIENTRY bluegl_glCoverFillPathNV (GLuint path, GLenum coverMode) {
    typedef void (APIENTRYP PFN_glCoverFillPathNV) (GLuint path, GLenum coverMode);
    return ((PFN_glCoverFillPathNV)__blue_glCore_glCoverFillPathNV)(path, coverMode);
}

extern void* __blue_glCore_glCoverStrokePathNV;
void APIENTRY bluegl_glCoverStrokePathNV (GLuint path, GLenum coverMode) {
    typedef void (APIENTRYP PFN_glCoverStrokePathNV) (GLuint path, GLenum coverMode);
    return ((PFN_glCoverStrokePathNV)__blue_glCore_glCoverStrokePathNV)(path, coverMode);
}

extern void* __blue_glCore_glCoverFillPathInstancedNV;
void APIENTRY bluegl_glCoverFillPathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues) {
    typedef void (APIENTRYP PFN_glCoverFillPathInstancedNV) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    return ((PFN_glCoverFillPathInstancedNV)__blue_glCore_glCoverFillPathInstancedNV)(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}

extern void* __blue_glCore_glCoverStrokePathInstancedNV;
void APIENTRY bluegl_glCoverStrokePathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues) {
    typedef void (APIENTRYP PFN_glCoverStrokePathInstancedNV) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    return ((PFN_glCoverStrokePathInstancedNV)__blue_glCore_glCoverStrokePathInstancedNV)(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
}

extern void* __blue_glCore_glGetPathParameterivNV;
void APIENTRY bluegl_glGetPathParameterivNV (GLuint path, GLenum pname, GLint *value) {
    typedef void (APIENTRYP PFN_glGetPathParameterivNV) (GLuint path, GLenum pname, GLint *value);
    return ((PFN_glGetPathParameterivNV)__blue_glCore_glGetPathParameterivNV)(path, pname, value);
}

extern void* __blue_glCore_glGetPathParameterfvNV;
void APIENTRY bluegl_glGetPathParameterfvNV (GLuint path, GLenum pname, GLfloat *value) {
    typedef void (APIENTRYP PFN_glGetPathParameterfvNV) (GLuint path, GLenum pname, GLfloat *value);
    return ((PFN_glGetPathParameterfvNV)__blue_glCore_glGetPathParameterfvNV)(path, pname, value);
}

extern void* __blue_glCore_glGetPathCommandsNV;
void APIENTRY bluegl_glGetPathCommandsNV (GLuint path, GLubyte *commands) {
    typedef void (APIENTRYP PFN_glGetPathCommandsNV) (GLuint path, GLubyte *commands);
    return ((PFN_glGetPathCommandsNV)__blue_glCore_glGetPathCommandsNV)(path, commands);
}

extern void* __blue_glCore_glGetPathCoordsNV;
void APIENTRY bluegl_glGetPathCoordsNV (GLuint path, GLfloat *coords) {
    typedef void (APIENTRYP PFN_glGetPathCoordsNV) (GLuint path, GLfloat *coords);
    return ((PFN_glGetPathCoordsNV)__blue_glCore_glGetPathCoordsNV)(path, coords);
}

extern void* __blue_glCore_glGetPathDashArrayNV;
void APIENTRY bluegl_glGetPathDashArrayNV (GLuint path, GLfloat *dashArray) {
    typedef void (APIENTRYP PFN_glGetPathDashArrayNV) (GLuint path, GLfloat *dashArray);
    return ((PFN_glGetPathDashArrayNV)__blue_glCore_glGetPathDashArrayNV)(path, dashArray);
}

extern void* __blue_glCore_glGetPathMetricsNV;
void APIENTRY bluegl_glGetPathMetricsNV (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics) {
    typedef void (APIENTRYP PFN_glGetPathMetricsNV) (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
    return ((PFN_glGetPathMetricsNV)__blue_glCore_glGetPathMetricsNV)(metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics);
}

extern void* __blue_glCore_glGetPathMetricRangeNV;
void APIENTRY bluegl_glGetPathMetricRangeNV (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics) {
    typedef void (APIENTRYP PFN_glGetPathMetricRangeNV) (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
    return ((PFN_glGetPathMetricRangeNV)__blue_glCore_glGetPathMetricRangeNV)(metricQueryMask, firstPathName, numPaths, stride, metrics);
}

extern void* __blue_glCore_glGetPathSpacingNV;
void APIENTRY bluegl_glGetPathSpacingNV (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing) {
    typedef void (APIENTRYP PFN_glGetPathSpacingNV) (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
    return ((PFN_glGetPathSpacingNV)__blue_glCore_glGetPathSpacingNV)(pathListMode, numPaths, pathNameType, paths, pathBase, advanceScale, kerningScale, transformType, returnedSpacing);
}

extern void* __blue_glCore_glIsPointInFillPathNV;
GLboolean APIENTRY bluegl_glIsPointInFillPathNV (GLuint path, GLuint mask, GLfloat x, GLfloat y) {
    typedef GLboolean (APIENTRYP PFN_glIsPointInFillPathNV) (GLuint path, GLuint mask, GLfloat x, GLfloat y);
    return ((PFN_glIsPointInFillPathNV)__blue_glCore_glIsPointInFillPathNV)(path, mask, x, y);
}

extern void* __blue_glCore_glIsPointInStrokePathNV;
GLboolean APIENTRY bluegl_glIsPointInStrokePathNV (GLuint path, GLfloat x, GLfloat y) {
    typedef GLboolean (APIENTRYP PFN_glIsPointInStrokePathNV) (GLuint path, GLfloat x, GLfloat y);
    return ((PFN_glIsPointInStrokePathNV)__blue_glCore_glIsPointInStrokePathNV)(path, x, y);
}

extern void* __blue_glCore_glGetPathLengthNV;
GLfloat APIENTRY bluegl_glGetPathLengthNV (GLuint path, GLsizei startSegment, GLsizei numSegments) {
    typedef GLfloat (APIENTRYP PFN_glGetPathLengthNV) (GLuint path, GLsizei startSegment, GLsizei numSegments);
    return ((PFN_glGetPathLengthNV)__blue_glCore_glGetPathLengthNV)(path, startSegment, numSegments);
}

extern void* __blue_glCore_glPointAlongPathNV;
GLboolean APIENTRY bluegl_glPointAlongPathNV (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY) {
    typedef GLboolean (APIENTRYP PFN_glPointAlongPathNV) (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
    return ((PFN_glPointAlongPathNV)__blue_glCore_glPointAlongPathNV)(path, startSegment, numSegments, distance, x, y, tangentX, tangentY);
}

extern void* __blue_glCore_glMatrixLoad3x2fNV;
void APIENTRY bluegl_glMatrixLoad3x2fNV (GLenum matrixMode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixLoad3x2fNV) (GLenum matrixMode, const GLfloat *m);
    return ((PFN_glMatrixLoad3x2fNV)__blue_glCore_glMatrixLoad3x2fNV)(matrixMode, m);
}

extern void* __blue_glCore_glMatrixLoad3x3fNV;
void APIENTRY bluegl_glMatrixLoad3x3fNV (GLenum matrixMode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixLoad3x3fNV) (GLenum matrixMode, const GLfloat *m);
    return ((PFN_glMatrixLoad3x3fNV)__blue_glCore_glMatrixLoad3x3fNV)(matrixMode, m);
}

extern void* __blue_glCore_glMatrixLoadTranspose3x3fNV;
void APIENTRY bluegl_glMatrixLoadTranspose3x3fNV (GLenum matrixMode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixLoadTranspose3x3fNV) (GLenum matrixMode, const GLfloat *m);
    return ((PFN_glMatrixLoadTranspose3x3fNV)__blue_glCore_glMatrixLoadTranspose3x3fNV)(matrixMode, m);
}

extern void* __blue_glCore_glMatrixMult3x2fNV;
void APIENTRY bluegl_glMatrixMult3x2fNV (GLenum matrixMode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixMult3x2fNV) (GLenum matrixMode, const GLfloat *m);
    return ((PFN_glMatrixMult3x2fNV)__blue_glCore_glMatrixMult3x2fNV)(matrixMode, m);
}

extern void* __blue_glCore_glMatrixMult3x3fNV;
void APIENTRY bluegl_glMatrixMult3x3fNV (GLenum matrixMode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixMult3x3fNV) (GLenum matrixMode, const GLfloat *m);
    return ((PFN_glMatrixMult3x3fNV)__blue_glCore_glMatrixMult3x3fNV)(matrixMode, m);
}

extern void* __blue_glCore_glMatrixMultTranspose3x3fNV;
void APIENTRY bluegl_glMatrixMultTranspose3x3fNV (GLenum matrixMode, const GLfloat *m) {
    typedef void (APIENTRYP PFN_glMatrixMultTranspose3x3fNV) (GLenum matrixMode, const GLfloat *m);
    return ((PFN_glMatrixMultTranspose3x3fNV)__blue_glCore_glMatrixMultTranspose3x3fNV)(matrixMode, m);
}

extern void* __blue_glCore_glStencilThenCoverFillPathNV;
void APIENTRY bluegl_glStencilThenCoverFillPathNV (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode) {
    typedef void (APIENTRYP PFN_glStencilThenCoverFillPathNV) (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
    return ((PFN_glStencilThenCoverFillPathNV)__blue_glCore_glStencilThenCoverFillPathNV)(path, fillMode, mask, coverMode);
}

extern void* __blue_glCore_glStencilThenCoverStrokePathNV;
void APIENTRY bluegl_glStencilThenCoverStrokePathNV (GLuint path, GLint reference, GLuint mask, GLenum coverMode) {
    typedef void (APIENTRYP PFN_glStencilThenCoverStrokePathNV) (GLuint path, GLint reference, GLuint mask, GLenum coverMode);
    return ((PFN_glStencilThenCoverStrokePathNV)__blue_glCore_glStencilThenCoverStrokePathNV)(path, reference, mask, coverMode);
}

extern void* __blue_glCore_glStencilThenCoverFillPathInstancedNV;
void APIENTRY bluegl_glStencilThenCoverFillPathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues) {
    typedef void (APIENTRYP PFN_glStencilThenCoverFillPathInstancedNV) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    return ((PFN_glStencilThenCoverFillPathInstancedNV)__blue_glCore_glStencilThenCoverFillPathInstancedNV)(numPaths, pathNameType, paths, pathBase, fillMode, mask, coverMode, transformType, transformValues);
}

extern void* __blue_glCore_glStencilThenCoverStrokePathInstancedNV;
void APIENTRY bluegl_glStencilThenCoverStrokePathInstancedNV (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues) {
    typedef void (APIENTRYP PFN_glStencilThenCoverStrokePathInstancedNV) (GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
    return ((PFN_glStencilThenCoverStrokePathInstancedNV)__blue_glCore_glStencilThenCoverStrokePathInstancedNV)(numPaths, pathNameType, paths, pathBase, reference, mask, coverMode, transformType, transformValues);
}

extern void* __blue_glCore_glPathGlyphIndexRangeNV;
GLenum APIENTRY bluegl_glPathGlyphIndexRangeNV (GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2]) {
    typedef GLenum (APIENTRYP PFN_glPathGlyphIndexRangeNV) (GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2]);
    return ((PFN_glPathGlyphIndexRangeNV)__blue_glCore_glPathGlyphIndexRangeNV)(fontTarget, fontName, fontStyle, pathParameterTemplate, emScale, baseAndCount);
}

extern void* __blue_glCore_glPathGlyphIndexArrayNV;
GLenum APIENTRY bluegl_glPathGlyphIndexArrayNV (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
    typedef GLenum (APIENTRYP PFN_glPathGlyphIndexArrayNV) (GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    return ((PFN_glPathGlyphIndexArrayNV)__blue_glCore_glPathGlyphIndexArrayNV)(firstPathName, fontTarget, fontName, fontStyle, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
}

extern void* __blue_glCore_glPathMemoryGlyphIndexArrayNV;
GLenum APIENTRY bluegl_glPathMemoryGlyphIndexArrayNV (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
    typedef GLenum (APIENTRYP PFN_glPathMemoryGlyphIndexArrayNV) (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
    return ((PFN_glPathMemoryGlyphIndexArrayNV)__blue_glCore_glPathMemoryGlyphIndexArrayNV)(firstPathName, fontTarget, fontSize, fontData, faceIndex, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
}

extern void* __blue_glCore_glProgramPathFragmentInputGenNV;
void APIENTRY bluegl_glProgramPathFragmentInputGenNV (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs) {
    typedef void (APIENTRYP PFN_glProgramPathFragmentInputGenNV) (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
    return ((PFN_glProgramPathFragmentInputGenNV)__blue_glCore_glProgramPathFragmentInputGenNV)(program, location, genMode, components, coeffs);
}

extern void* __blue_glCore_glGetProgramResourcefvNV;
void APIENTRY bluegl_glGetProgramResourcefvNV (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetProgramResourcefvNV) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params);
    return ((PFN_glGetProgramResourcefvNV)__blue_glCore_glGetProgramResourcefvNV)(program, programInterface, index, propCount, props, bufSize, length, params);
}

extern void* __blue_glCore_glPathColorGenNV;
void APIENTRY bluegl_glPathColorGenNV (GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat *coeffs) {
    typedef void (APIENTRYP PFN_glPathColorGenNV) (GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat *coeffs);
    return ((PFN_glPathColorGenNV)__blue_glCore_glPathColorGenNV)(color, genMode, colorFormat, coeffs);
}

extern void* __blue_glCore_glPathTexGenNV;
void APIENTRY bluegl_glPathTexGenNV (GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat *coeffs) {
    typedef void (APIENTRYP PFN_glPathTexGenNV) (GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat *coeffs);
    return ((PFN_glPathTexGenNV)__blue_glCore_glPathTexGenNV)(texCoordSet, genMode, components, coeffs);
}

extern void* __blue_glCore_glPathFogGenNV;
void APIENTRY bluegl_glPathFogGenNV (GLenum genMode) {
    typedef void (APIENTRYP PFN_glPathFogGenNV) (GLenum genMode);
    return ((PFN_glPathFogGenNV)__blue_glCore_glPathFogGenNV)(genMode);
}

extern void* __blue_glCore_glGetPathColorGenivNV;
void APIENTRY bluegl_glGetPathColorGenivNV (GLenum color, GLenum pname, GLint *value) {
    typedef void (APIENTRYP PFN_glGetPathColorGenivNV) (GLenum color, GLenum pname, GLint *value);
    return ((PFN_glGetPathColorGenivNV)__blue_glCore_glGetPathColorGenivNV)(color, pname, value);
}

extern void* __blue_glCore_glGetPathColorGenfvNV;
void APIENTRY bluegl_glGetPathColorGenfvNV (GLenum color, GLenum pname, GLfloat *value) {
    typedef void (APIENTRYP PFN_glGetPathColorGenfvNV) (GLenum color, GLenum pname, GLfloat *value);
    return ((PFN_glGetPathColorGenfvNV)__blue_glCore_glGetPathColorGenfvNV)(color, pname, value);
}

extern void* __blue_glCore_glGetPathTexGenivNV;
void APIENTRY bluegl_glGetPathTexGenivNV (GLenum texCoordSet, GLenum pname, GLint *value) {
    typedef void (APIENTRYP PFN_glGetPathTexGenivNV) (GLenum texCoordSet, GLenum pname, GLint *value);
    return ((PFN_glGetPathTexGenivNV)__blue_glCore_glGetPathTexGenivNV)(texCoordSet, pname, value);
}

extern void* __blue_glCore_glGetPathTexGenfvNV;
void APIENTRY bluegl_glGetPathTexGenfvNV (GLenum texCoordSet, GLenum pname, GLfloat *value) {
    typedef void (APIENTRYP PFN_glGetPathTexGenfvNV) (GLenum texCoordSet, GLenum pname, GLfloat *value);
    return ((PFN_glGetPathTexGenfvNV)__blue_glCore_glGetPathTexGenfvNV)(texCoordSet, pname, value);
}

extern void* __blue_glCore_glPixelDataRangeNV;
void APIENTRY bluegl_glPixelDataRangeNV (GLenum target, GLsizei length, const void *pointer) {
    typedef void (APIENTRYP PFN_glPixelDataRangeNV) (GLenum target, GLsizei length, const void *pointer);
    return ((PFN_glPixelDataRangeNV)__blue_glCore_glPixelDataRangeNV)(target, length, pointer);
}

extern void* __blue_glCore_glFlushPixelDataRangeNV;
void APIENTRY bluegl_glFlushPixelDataRangeNV (GLenum target) {
    typedef void (APIENTRYP PFN_glFlushPixelDataRangeNV) (GLenum target);
    return ((PFN_glFlushPixelDataRangeNV)__blue_glCore_glFlushPixelDataRangeNV)(target);
}

extern void* __blue_glCore_glPointParameteriNV;
void APIENTRY bluegl_glPointParameteriNV (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glPointParameteriNV) (GLenum pname, GLint param);
    return ((PFN_glPointParameteriNV)__blue_glCore_glPointParameteriNV)(pname, param);
}

extern void* __blue_glCore_glPointParameterivNV;
void APIENTRY bluegl_glPointParameterivNV (GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glPointParameterivNV) (GLenum pname, const GLint *params);
    return ((PFN_glPointParameterivNV)__blue_glCore_glPointParameterivNV)(pname, params);
}

extern void* __blue_glCore_glPresentFrameKeyedNV;
void APIENTRY bluegl_glPresentFrameKeyedNV (GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1) {
    typedef void (APIENTRYP PFN_glPresentFrameKeyedNV) (GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
    return ((PFN_glPresentFrameKeyedNV)__blue_glCore_glPresentFrameKeyedNV)(video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, key0, target1, fill1, key1);
}

extern void* __blue_glCore_glPresentFrameDualFillNV;
void APIENTRY bluegl_glPresentFrameDualFillNV (GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3) {
    typedef void (APIENTRYP PFN_glPresentFrameDualFillNV) (GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
    return ((PFN_glPresentFrameDualFillNV)__blue_glCore_glPresentFrameDualFillNV)(video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, target1, fill1, target2, fill2, target3, fill3);
}

extern void* __blue_glCore_glGetVideoivNV;
void APIENTRY bluegl_glGetVideoivNV (GLuint video_slot, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVideoivNV) (GLuint video_slot, GLenum pname, GLint *params);
    return ((PFN_glGetVideoivNV)__blue_glCore_glGetVideoivNV)(video_slot, pname, params);
}

extern void* __blue_glCore_glGetVideouivNV;
void APIENTRY bluegl_glGetVideouivNV (GLuint video_slot, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetVideouivNV) (GLuint video_slot, GLenum pname, GLuint *params);
    return ((PFN_glGetVideouivNV)__blue_glCore_glGetVideouivNV)(video_slot, pname, params);
}

extern void* __blue_glCore_glGetVideoi64vNV;
void APIENTRY bluegl_glGetVideoi64vNV (GLuint video_slot, GLenum pname, GLint64EXT *params) {
    typedef void (APIENTRYP PFN_glGetVideoi64vNV) (GLuint video_slot, GLenum pname, GLint64EXT *params);
    return ((PFN_glGetVideoi64vNV)__blue_glCore_glGetVideoi64vNV)(video_slot, pname, params);
}

extern void* __blue_glCore_glGetVideoui64vNV;
void APIENTRY bluegl_glGetVideoui64vNV (GLuint video_slot, GLenum pname, GLuint64EXT *params) {
    typedef void (APIENTRYP PFN_glGetVideoui64vNV) (GLuint video_slot, GLenum pname, GLuint64EXT *params);
    return ((PFN_glGetVideoui64vNV)__blue_glCore_glGetVideoui64vNV)(video_slot, pname, params);
}

extern void* __blue_glCore_glPrimitiveRestartNV;
void APIENTRY bluegl_glPrimitiveRestartNV (void) {
    typedef void (APIENTRYP PFN_glPrimitiveRestartNV) (void);
    return ((PFN_glPrimitiveRestartNV)__blue_glCore_glPrimitiveRestartNV)();
}

extern void* __blue_glCore_glPrimitiveRestartIndexNV;
void APIENTRY bluegl_glPrimitiveRestartIndexNV (GLuint index) {
    typedef void (APIENTRYP PFN_glPrimitiveRestartIndexNV) (GLuint index);
    return ((PFN_glPrimitiveRestartIndexNV)__blue_glCore_glPrimitiveRestartIndexNV)(index);
}

extern void* __blue_glCore_glCombinerParameterfvNV;
void APIENTRY bluegl_glCombinerParameterfvNV (GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glCombinerParameterfvNV) (GLenum pname, const GLfloat *params);
    return ((PFN_glCombinerParameterfvNV)__blue_glCore_glCombinerParameterfvNV)(pname, params);
}

extern void* __blue_glCore_glCombinerParameterfNV;
void APIENTRY bluegl_glCombinerParameterfNV (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glCombinerParameterfNV) (GLenum pname, GLfloat param);
    return ((PFN_glCombinerParameterfNV)__blue_glCore_glCombinerParameterfNV)(pname, param);
}

extern void* __blue_glCore_glCombinerParameterivNV;
void APIENTRY bluegl_glCombinerParameterivNV (GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glCombinerParameterivNV) (GLenum pname, const GLint *params);
    return ((PFN_glCombinerParameterivNV)__blue_glCore_glCombinerParameterivNV)(pname, params);
}

extern void* __blue_glCore_glCombinerParameteriNV;
void APIENTRY bluegl_glCombinerParameteriNV (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glCombinerParameteriNV) (GLenum pname, GLint param);
    return ((PFN_glCombinerParameteriNV)__blue_glCore_glCombinerParameteriNV)(pname, param);
}

extern void* __blue_glCore_glCombinerInputNV;
void APIENTRY bluegl_glCombinerInputNV (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) {
    typedef void (APIENTRYP PFN_glCombinerInputNV) (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
    return ((PFN_glCombinerInputNV)__blue_glCore_glCombinerInputNV)(stage, portion, variable, input, mapping, componentUsage);
}

extern void* __blue_glCore_glCombinerOutputNV;
void APIENTRY bluegl_glCombinerOutputNV (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum) {
    typedef void (APIENTRYP PFN_glCombinerOutputNV) (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
    return ((PFN_glCombinerOutputNV)__blue_glCore_glCombinerOutputNV)(stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum);
}

extern void* __blue_glCore_glFinalCombinerInputNV;
void APIENTRY bluegl_glFinalCombinerInputNV (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) {
    typedef void (APIENTRYP PFN_glFinalCombinerInputNV) (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
    return ((PFN_glFinalCombinerInputNV)__blue_glCore_glFinalCombinerInputNV)(variable, input, mapping, componentUsage);
}

extern void* __blue_glCore_glGetCombinerInputParameterfvNV;
void APIENTRY bluegl_glGetCombinerInputParameterfvNV (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetCombinerInputParameterfvNV) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
    return ((PFN_glGetCombinerInputParameterfvNV)__blue_glCore_glGetCombinerInputParameterfvNV)(stage, portion, variable, pname, params);
}

extern void* __blue_glCore_glGetCombinerInputParameterivNV;
void APIENTRY bluegl_glGetCombinerInputParameterivNV (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetCombinerInputParameterivNV) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
    return ((PFN_glGetCombinerInputParameterivNV)__blue_glCore_glGetCombinerInputParameterivNV)(stage, portion, variable, pname, params);
}

extern void* __blue_glCore_glGetCombinerOutputParameterfvNV;
void APIENTRY bluegl_glGetCombinerOutputParameterfvNV (GLenum stage, GLenum portion, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetCombinerOutputParameterfvNV) (GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
    return ((PFN_glGetCombinerOutputParameterfvNV)__blue_glCore_glGetCombinerOutputParameterfvNV)(stage, portion, pname, params);
}

extern void* __blue_glCore_glGetCombinerOutputParameterivNV;
void APIENTRY bluegl_glGetCombinerOutputParameterivNV (GLenum stage, GLenum portion, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetCombinerOutputParameterivNV) (GLenum stage, GLenum portion, GLenum pname, GLint *params);
    return ((PFN_glGetCombinerOutputParameterivNV)__blue_glCore_glGetCombinerOutputParameterivNV)(stage, portion, pname, params);
}

extern void* __blue_glCore_glGetFinalCombinerInputParameterfvNV;
void APIENTRY bluegl_glGetFinalCombinerInputParameterfvNV (GLenum variable, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetFinalCombinerInputParameterfvNV) (GLenum variable, GLenum pname, GLfloat *params);
    return ((PFN_glGetFinalCombinerInputParameterfvNV)__blue_glCore_glGetFinalCombinerInputParameterfvNV)(variable, pname, params);
}

extern void* __blue_glCore_glGetFinalCombinerInputParameterivNV;
void APIENTRY bluegl_glGetFinalCombinerInputParameterivNV (GLenum variable, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetFinalCombinerInputParameterivNV) (GLenum variable, GLenum pname, GLint *params);
    return ((PFN_glGetFinalCombinerInputParameterivNV)__blue_glCore_glGetFinalCombinerInputParameterivNV)(variable, pname, params);
}

extern void* __blue_glCore_glCombinerStageParameterfvNV;
void APIENTRY bluegl_glCombinerStageParameterfvNV (GLenum stage, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glCombinerStageParameterfvNV) (GLenum stage, GLenum pname, const GLfloat *params);
    return ((PFN_glCombinerStageParameterfvNV)__blue_glCore_glCombinerStageParameterfvNV)(stage, pname, params);
}

extern void* __blue_glCore_glGetCombinerStageParameterfvNV;
void APIENTRY bluegl_glGetCombinerStageParameterfvNV (GLenum stage, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetCombinerStageParameterfvNV) (GLenum stage, GLenum pname, GLfloat *params);
    return ((PFN_glGetCombinerStageParameterfvNV)__blue_glCore_glGetCombinerStageParameterfvNV)(stage, pname, params);
}

extern void* __blue_glCore_glFramebufferSampleLocationsfvNV;
void APIENTRY bluegl_glFramebufferSampleLocationsfvNV (GLenum target, GLuint start, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glFramebufferSampleLocationsfvNV) (GLenum target, GLuint start, GLsizei count, const GLfloat *v);
    return ((PFN_glFramebufferSampleLocationsfvNV)__blue_glCore_glFramebufferSampleLocationsfvNV)(target, start, count, v);
}

extern void* __blue_glCore_glNamedFramebufferSampleLocationsfvNV;
void APIENTRY bluegl_glNamedFramebufferSampleLocationsfvNV (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glNamedFramebufferSampleLocationsfvNV) (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
    return ((PFN_glNamedFramebufferSampleLocationsfvNV)__blue_glCore_glNamedFramebufferSampleLocationsfvNV)(framebuffer, start, count, v);
}

extern void* __blue_glCore_glResolveDepthValuesNV;
void APIENTRY bluegl_glResolveDepthValuesNV (void) {
    typedef void (APIENTRYP PFN_glResolveDepthValuesNV) (void);
    return ((PFN_glResolveDepthValuesNV)__blue_glCore_glResolveDepthValuesNV)();
}

extern void* __blue_glCore_glMakeBufferResidentNV;
void APIENTRY bluegl_glMakeBufferResidentNV (GLenum target, GLenum access) {
    typedef void (APIENTRYP PFN_glMakeBufferResidentNV) (GLenum target, GLenum access);
    return ((PFN_glMakeBufferResidentNV)__blue_glCore_glMakeBufferResidentNV)(target, access);
}

extern void* __blue_glCore_glMakeBufferNonResidentNV;
void APIENTRY bluegl_glMakeBufferNonResidentNV (GLenum target) {
    typedef void (APIENTRYP PFN_glMakeBufferNonResidentNV) (GLenum target);
    return ((PFN_glMakeBufferNonResidentNV)__blue_glCore_glMakeBufferNonResidentNV)(target);
}

extern void* __blue_glCore_glIsBufferResidentNV;
GLboolean APIENTRY bluegl_glIsBufferResidentNV (GLenum target) {
    typedef GLboolean (APIENTRYP PFN_glIsBufferResidentNV) (GLenum target);
    return ((PFN_glIsBufferResidentNV)__blue_glCore_glIsBufferResidentNV)(target);
}

extern void* __blue_glCore_glMakeNamedBufferResidentNV;
void APIENTRY bluegl_glMakeNamedBufferResidentNV (GLuint buffer, GLenum access) {
    typedef void (APIENTRYP PFN_glMakeNamedBufferResidentNV) (GLuint buffer, GLenum access);
    return ((PFN_glMakeNamedBufferResidentNV)__blue_glCore_glMakeNamedBufferResidentNV)(buffer, access);
}

extern void* __blue_glCore_glMakeNamedBufferNonResidentNV;
void APIENTRY bluegl_glMakeNamedBufferNonResidentNV (GLuint buffer) {
    typedef void (APIENTRYP PFN_glMakeNamedBufferNonResidentNV) (GLuint buffer);
    return ((PFN_glMakeNamedBufferNonResidentNV)__blue_glCore_glMakeNamedBufferNonResidentNV)(buffer);
}

extern void* __blue_glCore_glIsNamedBufferResidentNV;
GLboolean APIENTRY bluegl_glIsNamedBufferResidentNV (GLuint buffer) {
    typedef GLboolean (APIENTRYP PFN_glIsNamedBufferResidentNV) (GLuint buffer);
    return ((PFN_glIsNamedBufferResidentNV)__blue_glCore_glIsNamedBufferResidentNV)(buffer);
}

extern void* __blue_glCore_glGetBufferParameterui64vNV;
void APIENTRY bluegl_glGetBufferParameterui64vNV (GLenum target, GLenum pname, GLuint64EXT *params) {
    typedef void (APIENTRYP PFN_glGetBufferParameterui64vNV) (GLenum target, GLenum pname, GLuint64EXT *params);
    return ((PFN_glGetBufferParameterui64vNV)__blue_glCore_glGetBufferParameterui64vNV)(target, pname, params);
}

extern void* __blue_glCore_glGetNamedBufferParameterui64vNV;
void APIENTRY bluegl_glGetNamedBufferParameterui64vNV (GLuint buffer, GLenum pname, GLuint64EXT *params) {
    typedef void (APIENTRYP PFN_glGetNamedBufferParameterui64vNV) (GLuint buffer, GLenum pname, GLuint64EXT *params);
    return ((PFN_glGetNamedBufferParameterui64vNV)__blue_glCore_glGetNamedBufferParameterui64vNV)(buffer, pname, params);
}

extern void* __blue_glCore_glGetIntegerui64vNV;
void APIENTRY bluegl_glGetIntegerui64vNV (GLenum value, GLuint64EXT *result) {
    typedef void (APIENTRYP PFN_glGetIntegerui64vNV) (GLenum value, GLuint64EXT *result);
    return ((PFN_glGetIntegerui64vNV)__blue_glCore_glGetIntegerui64vNV)(value, result);
}

extern void* __blue_glCore_glUniformui64NV;
void APIENTRY bluegl_glUniformui64NV (GLint location, GLuint64EXT value) {
    typedef void (APIENTRYP PFN_glUniformui64NV) (GLint location, GLuint64EXT value);
    return ((PFN_glUniformui64NV)__blue_glCore_glUniformui64NV)(location, value);
}

extern void* __blue_glCore_glUniformui64vNV;
void APIENTRY bluegl_glUniformui64vNV (GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glUniformui64vNV) (GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glUniformui64vNV)__blue_glCore_glUniformui64vNV)(location, count, value);
}

extern void* __blue_glCore_glProgramUniformui64NV;
void APIENTRY bluegl_glProgramUniformui64NV (GLuint program, GLint location, GLuint64EXT value) {
    typedef void (APIENTRYP PFN_glProgramUniformui64NV) (GLuint program, GLint location, GLuint64EXT value);
    return ((PFN_glProgramUniformui64NV)__blue_glCore_glProgramUniformui64NV)(program, location, value);
}

extern void* __blue_glCore_glProgramUniformui64vNV;
void APIENTRY bluegl_glProgramUniformui64vNV (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) {
    typedef void (APIENTRYP PFN_glProgramUniformui64vNV) (GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
    return ((PFN_glProgramUniformui64vNV)__blue_glCore_glProgramUniformui64vNV)(program, location, count, value);
}

extern void* __blue_glCore_glTextureBarrierNV;
void APIENTRY bluegl_glTextureBarrierNV (void) {
    typedef void (APIENTRYP PFN_glTextureBarrierNV) (void);
    return ((PFN_glTextureBarrierNV)__blue_glCore_glTextureBarrierNV)();
}

extern void* __blue_glCore_glTexImage2DMultisampleCoverageNV;
void APIENTRY bluegl_glTexImage2DMultisampleCoverageNV (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
    typedef void (APIENTRYP PFN_glTexImage2DMultisampleCoverageNV) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
    return ((PFN_glTexImage2DMultisampleCoverageNV)__blue_glCore_glTexImage2DMultisampleCoverageNV)(target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations);
}

extern void* __blue_glCore_glTexImage3DMultisampleCoverageNV;
void APIENTRY bluegl_glTexImage3DMultisampleCoverageNV (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
    typedef void (APIENTRYP PFN_glTexImage3DMultisampleCoverageNV) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
    return ((PFN_glTexImage3DMultisampleCoverageNV)__blue_glCore_glTexImage3DMultisampleCoverageNV)(target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations);
}

extern void* __blue_glCore_glTextureImage2DMultisampleNV;
void APIENTRY bluegl_glTextureImage2DMultisampleNV (GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
    typedef void (APIENTRYP PFN_glTextureImage2DMultisampleNV) (GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
    return ((PFN_glTextureImage2DMultisampleNV)__blue_glCore_glTextureImage2DMultisampleNV)(texture, target, samples, internalFormat, width, height, fixedSampleLocations);
}

extern void* __blue_glCore_glTextureImage3DMultisampleNV;
void APIENTRY bluegl_glTextureImage3DMultisampleNV (GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
    typedef void (APIENTRYP PFN_glTextureImage3DMultisampleNV) (GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
    return ((PFN_glTextureImage3DMultisampleNV)__blue_glCore_glTextureImage3DMultisampleNV)(texture, target, samples, internalFormat, width, height, depth, fixedSampleLocations);
}

extern void* __blue_glCore_glTextureImage2DMultisampleCoverageNV;
void APIENTRY bluegl_glTextureImage2DMultisampleCoverageNV (GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
    typedef void (APIENTRYP PFN_glTextureImage2DMultisampleCoverageNV) (GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
    return ((PFN_glTextureImage2DMultisampleCoverageNV)__blue_glCore_glTextureImage2DMultisampleCoverageNV)(texture, target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations);
}

extern void* __blue_glCore_glTextureImage3DMultisampleCoverageNV;
void APIENTRY bluegl_glTextureImage3DMultisampleCoverageNV (GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
    typedef void (APIENTRYP PFN_glTextureImage3DMultisampleCoverageNV) (GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
    return ((PFN_glTextureImage3DMultisampleCoverageNV)__blue_glCore_glTextureImage3DMultisampleCoverageNV)(texture, target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations);
}

extern void* __blue_glCore_glBeginTransformFeedbackNV;
void APIENTRY bluegl_glBeginTransformFeedbackNV (GLenum primitiveMode) {
    typedef void (APIENTRYP PFN_glBeginTransformFeedbackNV) (GLenum primitiveMode);
    return ((PFN_glBeginTransformFeedbackNV)__blue_glCore_glBeginTransformFeedbackNV)(primitiveMode);
}

extern void* __blue_glCore_glEndTransformFeedbackNV;
void APIENTRY bluegl_glEndTransformFeedbackNV (void) {
    typedef void (APIENTRYP PFN_glEndTransformFeedbackNV) (void);
    return ((PFN_glEndTransformFeedbackNV)__blue_glCore_glEndTransformFeedbackNV)();
}

extern void* __blue_glCore_glTransformFeedbackAttribsNV;
void APIENTRY bluegl_glTransformFeedbackAttribsNV (GLsizei count, const GLint *attribs, GLenum bufferMode) {
    typedef void (APIENTRYP PFN_glTransformFeedbackAttribsNV) (GLsizei count, const GLint *attribs, GLenum bufferMode);
    return ((PFN_glTransformFeedbackAttribsNV)__blue_glCore_glTransformFeedbackAttribsNV)(count, attribs, bufferMode);
}

extern void* __blue_glCore_glBindBufferRangeNV;
void APIENTRY bluegl_glBindBufferRangeNV (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    typedef void (APIENTRYP PFN_glBindBufferRangeNV) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    return ((PFN_glBindBufferRangeNV)__blue_glCore_glBindBufferRangeNV)(target, index, buffer, offset, size);
}

extern void* __blue_glCore_glBindBufferOffsetNV;
void APIENTRY bluegl_glBindBufferOffsetNV (GLenum target, GLuint index, GLuint buffer, GLintptr offset) {
    typedef void (APIENTRYP PFN_glBindBufferOffsetNV) (GLenum target, GLuint index, GLuint buffer, GLintptr offset);
    return ((PFN_glBindBufferOffsetNV)__blue_glCore_glBindBufferOffsetNV)(target, index, buffer, offset);
}

extern void* __blue_glCore_glBindBufferBaseNV;
void APIENTRY bluegl_glBindBufferBaseNV (GLenum target, GLuint index, GLuint buffer) {
    typedef void (APIENTRYP PFN_glBindBufferBaseNV) (GLenum target, GLuint index, GLuint buffer);
    return ((PFN_glBindBufferBaseNV)__blue_glCore_glBindBufferBaseNV)(target, index, buffer);
}

extern void* __blue_glCore_glTransformFeedbackVaryingsNV;
void APIENTRY bluegl_glTransformFeedbackVaryingsNV (GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode) {
    typedef void (APIENTRYP PFN_glTransformFeedbackVaryingsNV) (GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode);
    return ((PFN_glTransformFeedbackVaryingsNV)__blue_glCore_glTransformFeedbackVaryingsNV)(program, count, locations, bufferMode);
}

extern void* __blue_glCore_glActiveVaryingNV;
void APIENTRY bluegl_glActiveVaryingNV (GLuint program, const GLchar *name) {
    typedef void (APIENTRYP PFN_glActiveVaryingNV) (GLuint program, const GLchar *name);
    return ((PFN_glActiveVaryingNV)__blue_glCore_glActiveVaryingNV)(program, name);
}

extern void* __blue_glCore_glGetVaryingLocationNV;
GLint APIENTRY bluegl_glGetVaryingLocationNV (GLuint program, const GLchar *name) {
    typedef GLint (APIENTRYP PFN_glGetVaryingLocationNV) (GLuint program, const GLchar *name);
    return ((PFN_glGetVaryingLocationNV)__blue_glCore_glGetVaryingLocationNV)(program, name);
}

extern void* __blue_glCore_glGetActiveVaryingNV;
void APIENTRY bluegl_glGetActiveVaryingNV (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) {
    typedef void (APIENTRYP PFN_glGetActiveVaryingNV) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
    return ((PFN_glGetActiveVaryingNV)__blue_glCore_glGetActiveVaryingNV)(program, index, bufSize, length, size, type, name);
}

extern void* __blue_glCore_glGetTransformFeedbackVaryingNV;
void APIENTRY bluegl_glGetTransformFeedbackVaryingNV (GLuint program, GLuint index, GLint *location) {
    typedef void (APIENTRYP PFN_glGetTransformFeedbackVaryingNV) (GLuint program, GLuint index, GLint *location);
    return ((PFN_glGetTransformFeedbackVaryingNV)__blue_glCore_glGetTransformFeedbackVaryingNV)(program, index, location);
}

extern void* __blue_glCore_glTransformFeedbackStreamAttribsNV;
void APIENTRY bluegl_glTransformFeedbackStreamAttribsNV (GLsizei count, const GLint *attribs, GLsizei nbuffers, const GLint *bufstreams, GLenum bufferMode) {
    typedef void (APIENTRYP PFN_glTransformFeedbackStreamAttribsNV) (GLsizei count, const GLint *attribs, GLsizei nbuffers, const GLint *bufstreams, GLenum bufferMode);
    return ((PFN_glTransformFeedbackStreamAttribsNV)__blue_glCore_glTransformFeedbackStreamAttribsNV)(count, attribs, nbuffers, bufstreams, bufferMode);
}

extern void* __blue_glCore_glBindTransformFeedbackNV;
void APIENTRY bluegl_glBindTransformFeedbackNV (GLenum target, GLuint id) {
    typedef void (APIENTRYP PFN_glBindTransformFeedbackNV) (GLenum target, GLuint id);
    return ((PFN_glBindTransformFeedbackNV)__blue_glCore_glBindTransformFeedbackNV)(target, id);
}

extern void* __blue_glCore_glDeleteTransformFeedbacksNV;
void APIENTRY bluegl_glDeleteTransformFeedbacksNV (GLsizei n, const GLuint *ids) {
    typedef void (APIENTRYP PFN_glDeleteTransformFeedbacksNV) (GLsizei n, const GLuint *ids);
    return ((PFN_glDeleteTransformFeedbacksNV)__blue_glCore_glDeleteTransformFeedbacksNV)(n, ids);
}

extern void* __blue_glCore_glGenTransformFeedbacksNV;
void APIENTRY bluegl_glGenTransformFeedbacksNV (GLsizei n, GLuint *ids) {
    typedef void (APIENTRYP PFN_glGenTransformFeedbacksNV) (GLsizei n, GLuint *ids);
    return ((PFN_glGenTransformFeedbacksNV)__blue_glCore_glGenTransformFeedbacksNV)(n, ids);
}

extern void* __blue_glCore_glIsTransformFeedbackNV;
GLboolean APIENTRY bluegl_glIsTransformFeedbackNV (GLuint id) {
    typedef GLboolean (APIENTRYP PFN_glIsTransformFeedbackNV) (GLuint id);
    return ((PFN_glIsTransformFeedbackNV)__blue_glCore_glIsTransformFeedbackNV)(id);
}

extern void* __blue_glCore_glPauseTransformFeedbackNV;
void APIENTRY bluegl_glPauseTransformFeedbackNV (void) {
    typedef void (APIENTRYP PFN_glPauseTransformFeedbackNV) (void);
    return ((PFN_glPauseTransformFeedbackNV)__blue_glCore_glPauseTransformFeedbackNV)();
}

extern void* __blue_glCore_glResumeTransformFeedbackNV;
void APIENTRY bluegl_glResumeTransformFeedbackNV (void) {
    typedef void (APIENTRYP PFN_glResumeTransformFeedbackNV) (void);
    return ((PFN_glResumeTransformFeedbackNV)__blue_glCore_glResumeTransformFeedbackNV)();
}

extern void* __blue_glCore_glDrawTransformFeedbackNV;
void APIENTRY bluegl_glDrawTransformFeedbackNV (GLenum mode, GLuint id) {
    typedef void (APIENTRYP PFN_glDrawTransformFeedbackNV) (GLenum mode, GLuint id);
    return ((PFN_glDrawTransformFeedbackNV)__blue_glCore_glDrawTransformFeedbackNV)(mode, id);
}

extern void* __blue_glCore_glVDPAUInitNV;
void APIENTRY bluegl_glVDPAUInitNV (const void *vdpDevice, const void *getProcAddress) {
    typedef void (APIENTRYP PFN_glVDPAUInitNV) (const void *vdpDevice, const void *getProcAddress);
    return ((PFN_glVDPAUInitNV)__blue_glCore_glVDPAUInitNV)(vdpDevice, getProcAddress);
}

extern void* __blue_glCore_glVDPAUFiniNV;
void APIENTRY bluegl_glVDPAUFiniNV (void) {
    typedef void (APIENTRYP PFN_glVDPAUFiniNV) (void);
    return ((PFN_glVDPAUFiniNV)__blue_glCore_glVDPAUFiniNV)();
}

extern void* __blue_glCore_glVDPAURegisterVideoSurfaceNV;
GLvdpauSurfaceNV APIENTRY bluegl_glVDPAURegisterVideoSurfaceNV (const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames) {
    typedef GLvdpauSurfaceNV (APIENTRYP PFN_glVDPAURegisterVideoSurfaceNV) (const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
    return ((PFN_glVDPAURegisterVideoSurfaceNV)__blue_glCore_glVDPAURegisterVideoSurfaceNV)(vdpSurface, target, numTextureNames, textureNames);
}

extern void* __blue_glCore_glVDPAURegisterOutputSurfaceNV;
GLvdpauSurfaceNV APIENTRY bluegl_glVDPAURegisterOutputSurfaceNV (const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames) {
    typedef GLvdpauSurfaceNV (APIENTRYP PFN_glVDPAURegisterOutputSurfaceNV) (const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
    return ((PFN_glVDPAURegisterOutputSurfaceNV)__blue_glCore_glVDPAURegisterOutputSurfaceNV)(vdpSurface, target, numTextureNames, textureNames);
}

extern void* __blue_glCore_glVDPAUIsSurfaceNV;
GLboolean APIENTRY bluegl_glVDPAUIsSurfaceNV (GLvdpauSurfaceNV surface) {
    typedef GLboolean (APIENTRYP PFN_glVDPAUIsSurfaceNV) (GLvdpauSurfaceNV surface);
    return ((PFN_glVDPAUIsSurfaceNV)__blue_glCore_glVDPAUIsSurfaceNV)(surface);
}

extern void* __blue_glCore_glVDPAUUnregisterSurfaceNV;
void APIENTRY bluegl_glVDPAUUnregisterSurfaceNV (GLvdpauSurfaceNV surface) {
    typedef void (APIENTRYP PFN_glVDPAUUnregisterSurfaceNV) (GLvdpauSurfaceNV surface);
    return ((PFN_glVDPAUUnregisterSurfaceNV)__blue_glCore_glVDPAUUnregisterSurfaceNV)(surface);
}

extern void* __blue_glCore_glVDPAUGetSurfaceivNV;
void APIENTRY bluegl_glVDPAUGetSurfaceivNV (GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) {
    typedef void (APIENTRYP PFN_glVDPAUGetSurfaceivNV) (GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
    return ((PFN_glVDPAUGetSurfaceivNV)__blue_glCore_glVDPAUGetSurfaceivNV)(surface, pname, bufSize, length, values);
}

extern void* __blue_glCore_glVDPAUSurfaceAccessNV;
void APIENTRY bluegl_glVDPAUSurfaceAccessNV (GLvdpauSurfaceNV surface, GLenum access) {
    typedef void (APIENTRYP PFN_glVDPAUSurfaceAccessNV) (GLvdpauSurfaceNV surface, GLenum access);
    return ((PFN_glVDPAUSurfaceAccessNV)__blue_glCore_glVDPAUSurfaceAccessNV)(surface, access);
}

extern void* __blue_glCore_glVDPAUMapSurfacesNV;
void APIENTRY bluegl_glVDPAUMapSurfacesNV (GLsizei numSurfaces, const GLvdpauSurfaceNV *surfaces) {
    typedef void (APIENTRYP PFN_glVDPAUMapSurfacesNV) (GLsizei numSurfaces, const GLvdpauSurfaceNV *surfaces);
    return ((PFN_glVDPAUMapSurfacesNV)__blue_glCore_glVDPAUMapSurfacesNV)(numSurfaces, surfaces);
}

extern void* __blue_glCore_glVDPAUUnmapSurfacesNV;
void APIENTRY bluegl_glVDPAUUnmapSurfacesNV (GLsizei numSurface, const GLvdpauSurfaceNV *surfaces) {
    typedef void (APIENTRYP PFN_glVDPAUUnmapSurfacesNV) (GLsizei numSurface, const GLvdpauSurfaceNV *surfaces);
    return ((PFN_glVDPAUUnmapSurfacesNV)__blue_glCore_glVDPAUUnmapSurfacesNV)(numSurface, surfaces);
}

extern void* __blue_glCore_glFlushVertexArrayRangeNV;
void APIENTRY bluegl_glFlushVertexArrayRangeNV (void) {
    typedef void (APIENTRYP PFN_glFlushVertexArrayRangeNV) (void);
    return ((PFN_glFlushVertexArrayRangeNV)__blue_glCore_glFlushVertexArrayRangeNV)();
}

extern void* __blue_glCore_glVertexArrayRangeNV;
void APIENTRY bluegl_glVertexArrayRangeNV (GLsizei length, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexArrayRangeNV) (GLsizei length, const void *pointer);
    return ((PFN_glVertexArrayRangeNV)__blue_glCore_glVertexArrayRangeNV)(length, pointer);
}

extern void* __blue_glCore_glVertexAttribL1i64NV;
void APIENTRY bluegl_glVertexAttribL1i64NV (GLuint index, GLint64EXT x) {
    typedef void (APIENTRYP PFN_glVertexAttribL1i64NV) (GLuint index, GLint64EXT x);
    return ((PFN_glVertexAttribL1i64NV)__blue_glCore_glVertexAttribL1i64NV)(index, x);
}

extern void* __blue_glCore_glVertexAttribL2i64NV;
void APIENTRY bluegl_glVertexAttribL2i64NV (GLuint index, GLint64EXT x, GLint64EXT y) {
    typedef void (APIENTRYP PFN_glVertexAttribL2i64NV) (GLuint index, GLint64EXT x, GLint64EXT y);
    return ((PFN_glVertexAttribL2i64NV)__blue_glCore_glVertexAttribL2i64NV)(index, x, y);
}

extern void* __blue_glCore_glVertexAttribL3i64NV;
void APIENTRY bluegl_glVertexAttribL3i64NV (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
    typedef void (APIENTRYP PFN_glVertexAttribL3i64NV) (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
    return ((PFN_glVertexAttribL3i64NV)__blue_glCore_glVertexAttribL3i64NV)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttribL4i64NV;
void APIENTRY bluegl_glVertexAttribL4i64NV (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
    typedef void (APIENTRYP PFN_glVertexAttribL4i64NV) (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
    return ((PFN_glVertexAttribL4i64NV)__blue_glCore_glVertexAttribL4i64NV)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttribL1i64vNV;
void APIENTRY bluegl_glVertexAttribL1i64vNV (GLuint index, const GLint64EXT *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL1i64vNV) (GLuint index, const GLint64EXT *v);
    return ((PFN_glVertexAttribL1i64vNV)__blue_glCore_glVertexAttribL1i64vNV)(index, v);
}

extern void* __blue_glCore_glVertexAttribL2i64vNV;
void APIENTRY bluegl_glVertexAttribL2i64vNV (GLuint index, const GLint64EXT *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL2i64vNV) (GLuint index, const GLint64EXT *v);
    return ((PFN_glVertexAttribL2i64vNV)__blue_glCore_glVertexAttribL2i64vNV)(index, v);
}

extern void* __blue_glCore_glVertexAttribL3i64vNV;
void APIENTRY bluegl_glVertexAttribL3i64vNV (GLuint index, const GLint64EXT *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL3i64vNV) (GLuint index, const GLint64EXT *v);
    return ((PFN_glVertexAttribL3i64vNV)__blue_glCore_glVertexAttribL3i64vNV)(index, v);
}

extern void* __blue_glCore_glVertexAttribL4i64vNV;
void APIENTRY bluegl_glVertexAttribL4i64vNV (GLuint index, const GLint64EXT *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL4i64vNV) (GLuint index, const GLint64EXT *v);
    return ((PFN_glVertexAttribL4i64vNV)__blue_glCore_glVertexAttribL4i64vNV)(index, v);
}

extern void* __blue_glCore_glVertexAttribL1ui64NV;
void APIENTRY bluegl_glVertexAttribL1ui64NV (GLuint index, GLuint64EXT x) {
    typedef void (APIENTRYP PFN_glVertexAttribL1ui64NV) (GLuint index, GLuint64EXT x);
    return ((PFN_glVertexAttribL1ui64NV)__blue_glCore_glVertexAttribL1ui64NV)(index, x);
}

extern void* __blue_glCore_glVertexAttribL2ui64NV;
void APIENTRY bluegl_glVertexAttribL2ui64NV (GLuint index, GLuint64EXT x, GLuint64EXT y) {
    typedef void (APIENTRYP PFN_glVertexAttribL2ui64NV) (GLuint index, GLuint64EXT x, GLuint64EXT y);
    return ((PFN_glVertexAttribL2ui64NV)__blue_glCore_glVertexAttribL2ui64NV)(index, x, y);
}

extern void* __blue_glCore_glVertexAttribL3ui64NV;
void APIENTRY bluegl_glVertexAttribL3ui64NV (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
    typedef void (APIENTRYP PFN_glVertexAttribL3ui64NV) (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
    return ((PFN_glVertexAttribL3ui64NV)__blue_glCore_glVertexAttribL3ui64NV)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttribL4ui64NV;
void APIENTRY bluegl_glVertexAttribL4ui64NV (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
    typedef void (APIENTRYP PFN_glVertexAttribL4ui64NV) (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
    return ((PFN_glVertexAttribL4ui64NV)__blue_glCore_glVertexAttribL4ui64NV)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttribL1ui64vNV;
void APIENTRY bluegl_glVertexAttribL1ui64vNV (GLuint index, const GLuint64EXT *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL1ui64vNV) (GLuint index, const GLuint64EXT *v);
    return ((PFN_glVertexAttribL1ui64vNV)__blue_glCore_glVertexAttribL1ui64vNV)(index, v);
}

extern void* __blue_glCore_glVertexAttribL2ui64vNV;
void APIENTRY bluegl_glVertexAttribL2ui64vNV (GLuint index, const GLuint64EXT *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL2ui64vNV) (GLuint index, const GLuint64EXT *v);
    return ((PFN_glVertexAttribL2ui64vNV)__blue_glCore_glVertexAttribL2ui64vNV)(index, v);
}

extern void* __blue_glCore_glVertexAttribL3ui64vNV;
void APIENTRY bluegl_glVertexAttribL3ui64vNV (GLuint index, const GLuint64EXT *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL3ui64vNV) (GLuint index, const GLuint64EXT *v);
    return ((PFN_glVertexAttribL3ui64vNV)__blue_glCore_glVertexAttribL3ui64vNV)(index, v);
}

extern void* __blue_glCore_glVertexAttribL4ui64vNV;
void APIENTRY bluegl_glVertexAttribL4ui64vNV (GLuint index, const GLuint64EXT *v) {
    typedef void (APIENTRYP PFN_glVertexAttribL4ui64vNV) (GLuint index, const GLuint64EXT *v);
    return ((PFN_glVertexAttribL4ui64vNV)__blue_glCore_glVertexAttribL4ui64vNV)(index, v);
}

extern void* __blue_glCore_glGetVertexAttribLi64vNV;
void APIENTRY bluegl_glGetVertexAttribLi64vNV (GLuint index, GLenum pname, GLint64EXT *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribLi64vNV) (GLuint index, GLenum pname, GLint64EXT *params);
    return ((PFN_glGetVertexAttribLi64vNV)__blue_glCore_glGetVertexAttribLi64vNV)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribLui64vNV;
void APIENTRY bluegl_glGetVertexAttribLui64vNV (GLuint index, GLenum pname, GLuint64EXT *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribLui64vNV) (GLuint index, GLenum pname, GLuint64EXT *params);
    return ((PFN_glGetVertexAttribLui64vNV)__blue_glCore_glGetVertexAttribLui64vNV)(index, pname, params);
}

extern void* __blue_glCore_glVertexAttribLFormatNV;
void APIENTRY bluegl_glVertexAttribLFormatNV (GLuint index, GLint size, GLenum type, GLsizei stride) {
    typedef void (APIENTRYP PFN_glVertexAttribLFormatNV) (GLuint index, GLint size, GLenum type, GLsizei stride);
    return ((PFN_glVertexAttribLFormatNV)__blue_glCore_glVertexAttribLFormatNV)(index, size, type, stride);
}

extern void* __blue_glCore_glBufferAddressRangeNV;
void APIENTRY bluegl_glBufferAddressRangeNV (GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length) {
    typedef void (APIENTRYP PFN_glBufferAddressRangeNV) (GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
    return ((PFN_glBufferAddressRangeNV)__blue_glCore_glBufferAddressRangeNV)(pname, index, address, length);
}

extern void* __blue_glCore_glVertexFormatNV;
void APIENTRY bluegl_glVertexFormatNV (GLint size, GLenum type, GLsizei stride) {
    typedef void (APIENTRYP PFN_glVertexFormatNV) (GLint size, GLenum type, GLsizei stride);
    return ((PFN_glVertexFormatNV)__blue_glCore_glVertexFormatNV)(size, type, stride);
}

extern void* __blue_glCore_glNormalFormatNV;
void APIENTRY bluegl_glNormalFormatNV (GLenum type, GLsizei stride) {
    typedef void (APIENTRYP PFN_glNormalFormatNV) (GLenum type, GLsizei stride);
    return ((PFN_glNormalFormatNV)__blue_glCore_glNormalFormatNV)(type, stride);
}

extern void* __blue_glCore_glColorFormatNV;
void APIENTRY bluegl_glColorFormatNV (GLint size, GLenum type, GLsizei stride) {
    typedef void (APIENTRYP PFN_glColorFormatNV) (GLint size, GLenum type, GLsizei stride);
    return ((PFN_glColorFormatNV)__blue_glCore_glColorFormatNV)(size, type, stride);
}

extern void* __blue_glCore_glIndexFormatNV;
void APIENTRY bluegl_glIndexFormatNV (GLenum type, GLsizei stride) {
    typedef void (APIENTRYP PFN_glIndexFormatNV) (GLenum type, GLsizei stride);
    return ((PFN_glIndexFormatNV)__blue_glCore_glIndexFormatNV)(type, stride);
}

extern void* __blue_glCore_glTexCoordFormatNV;
void APIENTRY bluegl_glTexCoordFormatNV (GLint size, GLenum type, GLsizei stride) {
    typedef void (APIENTRYP PFN_glTexCoordFormatNV) (GLint size, GLenum type, GLsizei stride);
    return ((PFN_glTexCoordFormatNV)__blue_glCore_glTexCoordFormatNV)(size, type, stride);
}

extern void* __blue_glCore_glEdgeFlagFormatNV;
void APIENTRY bluegl_glEdgeFlagFormatNV (GLsizei stride) {
    typedef void (APIENTRYP PFN_glEdgeFlagFormatNV) (GLsizei stride);
    return ((PFN_glEdgeFlagFormatNV)__blue_glCore_glEdgeFlagFormatNV)(stride);
}

extern void* __blue_glCore_glSecondaryColorFormatNV;
void APIENTRY bluegl_glSecondaryColorFormatNV (GLint size, GLenum type, GLsizei stride) {
    typedef void (APIENTRYP PFN_glSecondaryColorFormatNV) (GLint size, GLenum type, GLsizei stride);
    return ((PFN_glSecondaryColorFormatNV)__blue_glCore_glSecondaryColorFormatNV)(size, type, stride);
}

extern void* __blue_glCore_glFogCoordFormatNV;
void APIENTRY bluegl_glFogCoordFormatNV (GLenum type, GLsizei stride) {
    typedef void (APIENTRYP PFN_glFogCoordFormatNV) (GLenum type, GLsizei stride);
    return ((PFN_glFogCoordFormatNV)__blue_glCore_glFogCoordFormatNV)(type, stride);
}

extern void* __blue_glCore_glVertexAttribFormatNV;
void APIENTRY bluegl_glVertexAttribFormatNV (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride) {
    typedef void (APIENTRYP PFN_glVertexAttribFormatNV) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
    return ((PFN_glVertexAttribFormatNV)__blue_glCore_glVertexAttribFormatNV)(index, size, type, normalized, stride);
}

extern void* __blue_glCore_glVertexAttribIFormatNV;
void APIENTRY bluegl_glVertexAttribIFormatNV (GLuint index, GLint size, GLenum type, GLsizei stride) {
    typedef void (APIENTRYP PFN_glVertexAttribIFormatNV) (GLuint index, GLint size, GLenum type, GLsizei stride);
    return ((PFN_glVertexAttribIFormatNV)__blue_glCore_glVertexAttribIFormatNV)(index, size, type, stride);
}

extern void* __blue_glCore_glGetIntegerui64i_vNV;
void APIENTRY bluegl_glGetIntegerui64i_vNV (GLenum value, GLuint index, GLuint64EXT *result) {
    typedef void (APIENTRYP PFN_glGetIntegerui64i_vNV) (GLenum value, GLuint index, GLuint64EXT *result);
    return ((PFN_glGetIntegerui64i_vNV)__blue_glCore_glGetIntegerui64i_vNV)(value, index, result);
}

extern void* __blue_glCore_glAreProgramsResidentNV;
GLboolean APIENTRY bluegl_glAreProgramsResidentNV (GLsizei n, const GLuint *programs, GLboolean *residences) {
    typedef GLboolean (APIENTRYP PFN_glAreProgramsResidentNV) (GLsizei n, const GLuint *programs, GLboolean *residences);
    return ((PFN_glAreProgramsResidentNV)__blue_glCore_glAreProgramsResidentNV)(n, programs, residences);
}

extern void* __blue_glCore_glBindProgramNV;
void APIENTRY bluegl_glBindProgramNV (GLenum target, GLuint id) {
    typedef void (APIENTRYP PFN_glBindProgramNV) (GLenum target, GLuint id);
    return ((PFN_glBindProgramNV)__blue_glCore_glBindProgramNV)(target, id);
}

extern void* __blue_glCore_glDeleteProgramsNV;
void APIENTRY bluegl_glDeleteProgramsNV (GLsizei n, const GLuint *programs) {
    typedef void (APIENTRYP PFN_glDeleteProgramsNV) (GLsizei n, const GLuint *programs);
    return ((PFN_glDeleteProgramsNV)__blue_glCore_glDeleteProgramsNV)(n, programs);
}

extern void* __blue_glCore_glExecuteProgramNV;
void APIENTRY bluegl_glExecuteProgramNV (GLenum target, GLuint id, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glExecuteProgramNV) (GLenum target, GLuint id, const GLfloat *params);
    return ((PFN_glExecuteProgramNV)__blue_glCore_glExecuteProgramNV)(target, id, params);
}

extern void* __blue_glCore_glGenProgramsNV;
void APIENTRY bluegl_glGenProgramsNV (GLsizei n, GLuint *programs) {
    typedef void (APIENTRYP PFN_glGenProgramsNV) (GLsizei n, GLuint *programs);
    return ((PFN_glGenProgramsNV)__blue_glCore_glGenProgramsNV)(n, programs);
}

extern void* __blue_glCore_glGetProgramParameterdvNV;
void APIENTRY bluegl_glGetProgramParameterdvNV (GLenum target, GLuint index, GLenum pname, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetProgramParameterdvNV) (GLenum target, GLuint index, GLenum pname, GLdouble *params);
    return ((PFN_glGetProgramParameterdvNV)__blue_glCore_glGetProgramParameterdvNV)(target, index, pname, params);
}

extern void* __blue_glCore_glGetProgramParameterfvNV;
void APIENTRY bluegl_glGetProgramParameterfvNV (GLenum target, GLuint index, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetProgramParameterfvNV) (GLenum target, GLuint index, GLenum pname, GLfloat *params);
    return ((PFN_glGetProgramParameterfvNV)__blue_glCore_glGetProgramParameterfvNV)(target, index, pname, params);
}

extern void* __blue_glCore_glGetProgramivNV;
void APIENTRY bluegl_glGetProgramivNV (GLuint id, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetProgramivNV) (GLuint id, GLenum pname, GLint *params);
    return ((PFN_glGetProgramivNV)__blue_glCore_glGetProgramivNV)(id, pname, params);
}

extern void* __blue_glCore_glGetProgramStringNV;
void APIENTRY bluegl_glGetProgramStringNV (GLuint id, GLenum pname, GLubyte *program) {
    typedef void (APIENTRYP PFN_glGetProgramStringNV) (GLuint id, GLenum pname, GLubyte *program);
    return ((PFN_glGetProgramStringNV)__blue_glCore_glGetProgramStringNV)(id, pname, program);
}

extern void* __blue_glCore_glGetTrackMatrixivNV;
void APIENTRY bluegl_glGetTrackMatrixivNV (GLenum target, GLuint address, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetTrackMatrixivNV) (GLenum target, GLuint address, GLenum pname, GLint *params);
    return ((PFN_glGetTrackMatrixivNV)__blue_glCore_glGetTrackMatrixivNV)(target, address, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribdvNV;
void APIENTRY bluegl_glGetVertexAttribdvNV (GLuint index, GLenum pname, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribdvNV) (GLuint index, GLenum pname, GLdouble *params);
    return ((PFN_glGetVertexAttribdvNV)__blue_glCore_glGetVertexAttribdvNV)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribfvNV;
void APIENTRY bluegl_glGetVertexAttribfvNV (GLuint index, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribfvNV) (GLuint index, GLenum pname, GLfloat *params);
    return ((PFN_glGetVertexAttribfvNV)__blue_glCore_glGetVertexAttribfvNV)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribivNV;
void APIENTRY bluegl_glGetVertexAttribivNV (GLuint index, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribivNV) (GLuint index, GLenum pname, GLint *params);
    return ((PFN_glGetVertexAttribivNV)__blue_glCore_glGetVertexAttribivNV)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribPointervNV;
void APIENTRY bluegl_glGetVertexAttribPointervNV (GLuint index, GLenum pname, void **pointer) {
    typedef void (APIENTRYP PFN_glGetVertexAttribPointervNV) (GLuint index, GLenum pname, void **pointer);
    return ((PFN_glGetVertexAttribPointervNV)__blue_glCore_glGetVertexAttribPointervNV)(index, pname, pointer);
}

extern void* __blue_glCore_glIsProgramNV;
GLboolean APIENTRY bluegl_glIsProgramNV (GLuint id) {
    typedef GLboolean (APIENTRYP PFN_glIsProgramNV) (GLuint id);
    return ((PFN_glIsProgramNV)__blue_glCore_glIsProgramNV)(id);
}

extern void* __blue_glCore_glLoadProgramNV;
void APIENTRY bluegl_glLoadProgramNV (GLenum target, GLuint id, GLsizei len, const GLubyte *program) {
    typedef void (APIENTRYP PFN_glLoadProgramNV) (GLenum target, GLuint id, GLsizei len, const GLubyte *program);
    return ((PFN_glLoadProgramNV)__blue_glCore_glLoadProgramNV)(target, id, len, program);
}

extern void* __blue_glCore_glProgramParameter4dNV;
void APIENTRY bluegl_glProgramParameter4dNV (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glProgramParameter4dNV) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glProgramParameter4dNV)__blue_glCore_glProgramParameter4dNV)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramParameter4dvNV;
void APIENTRY bluegl_glProgramParameter4dvNV (GLenum target, GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glProgramParameter4dvNV) (GLenum target, GLuint index, const GLdouble *v);
    return ((PFN_glProgramParameter4dvNV)__blue_glCore_glProgramParameter4dvNV)(target, index, v);
}

extern void* __blue_glCore_glProgramParameter4fNV;
void APIENTRY bluegl_glProgramParameter4fNV (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glProgramParameter4fNV) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glProgramParameter4fNV)__blue_glCore_glProgramParameter4fNV)(target, index, x, y, z, w);
}

extern void* __blue_glCore_glProgramParameter4fvNV;
void APIENTRY bluegl_glProgramParameter4fvNV (GLenum target, GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glProgramParameter4fvNV) (GLenum target, GLuint index, const GLfloat *v);
    return ((PFN_glProgramParameter4fvNV)__blue_glCore_glProgramParameter4fvNV)(target, index, v);
}

extern void* __blue_glCore_glProgramParameters4dvNV;
void APIENTRY bluegl_glProgramParameters4dvNV (GLenum target, GLuint index, GLsizei count, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glProgramParameters4dvNV) (GLenum target, GLuint index, GLsizei count, const GLdouble *v);
    return ((PFN_glProgramParameters4dvNV)__blue_glCore_glProgramParameters4dvNV)(target, index, count, v);
}

extern void* __blue_glCore_glProgramParameters4fvNV;
void APIENTRY bluegl_glProgramParameters4fvNV (GLenum target, GLuint index, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glProgramParameters4fvNV) (GLenum target, GLuint index, GLsizei count, const GLfloat *v);
    return ((PFN_glProgramParameters4fvNV)__blue_glCore_glProgramParameters4fvNV)(target, index, count, v);
}

extern void* __blue_glCore_glRequestResidentProgramsNV;
void APIENTRY bluegl_glRequestResidentProgramsNV (GLsizei n, const GLuint *programs) {
    typedef void (APIENTRYP PFN_glRequestResidentProgramsNV) (GLsizei n, const GLuint *programs);
    return ((PFN_glRequestResidentProgramsNV)__blue_glCore_glRequestResidentProgramsNV)(n, programs);
}

extern void* __blue_glCore_glTrackMatrixNV;
void APIENTRY bluegl_glTrackMatrixNV (GLenum target, GLuint address, GLenum matrix, GLenum transform) {
    typedef void (APIENTRYP PFN_glTrackMatrixNV) (GLenum target, GLuint address, GLenum matrix, GLenum transform);
    return ((PFN_glTrackMatrixNV)__blue_glCore_glTrackMatrixNV)(target, address, matrix, transform);
}

extern void* __blue_glCore_glVertexAttribPointerNV;
void APIENTRY bluegl_glVertexAttribPointerNV (GLuint index, GLint fsize, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexAttribPointerNV) (GLuint index, GLint fsize, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glVertexAttribPointerNV)__blue_glCore_glVertexAttribPointerNV)(index, fsize, type, stride, pointer);
}

extern void* __blue_glCore_glVertexAttrib1dNV;
void APIENTRY bluegl_glVertexAttrib1dNV (GLuint index, GLdouble x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1dNV) (GLuint index, GLdouble x);
    return ((PFN_glVertexAttrib1dNV)__blue_glCore_glVertexAttrib1dNV)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1dvNV;
void APIENTRY bluegl_glVertexAttrib1dvNV (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1dvNV) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib1dvNV)__blue_glCore_glVertexAttrib1dvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib1fNV;
void APIENTRY bluegl_glVertexAttrib1fNV (GLuint index, GLfloat x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1fNV) (GLuint index, GLfloat x);
    return ((PFN_glVertexAttrib1fNV)__blue_glCore_glVertexAttrib1fNV)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1fvNV;
void APIENTRY bluegl_glVertexAttrib1fvNV (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1fvNV) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib1fvNV)__blue_glCore_glVertexAttrib1fvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib1sNV;
void APIENTRY bluegl_glVertexAttrib1sNV (GLuint index, GLshort x) {
    typedef void (APIENTRYP PFN_glVertexAttrib1sNV) (GLuint index, GLshort x);
    return ((PFN_glVertexAttrib1sNV)__blue_glCore_glVertexAttrib1sNV)(index, x);
}

extern void* __blue_glCore_glVertexAttrib1svNV;
void APIENTRY bluegl_glVertexAttrib1svNV (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib1svNV) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib1svNV)__blue_glCore_glVertexAttrib1svNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2dNV;
void APIENTRY bluegl_glVertexAttrib2dNV (GLuint index, GLdouble x, GLdouble y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2dNV) (GLuint index, GLdouble x, GLdouble y);
    return ((PFN_glVertexAttrib2dNV)__blue_glCore_glVertexAttrib2dNV)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2dvNV;
void APIENTRY bluegl_glVertexAttrib2dvNV (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2dvNV) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib2dvNV)__blue_glCore_glVertexAttrib2dvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2fNV;
void APIENTRY bluegl_glVertexAttrib2fNV (GLuint index, GLfloat x, GLfloat y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2fNV) (GLuint index, GLfloat x, GLfloat y);
    return ((PFN_glVertexAttrib2fNV)__blue_glCore_glVertexAttrib2fNV)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2fvNV;
void APIENTRY bluegl_glVertexAttrib2fvNV (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2fvNV) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib2fvNV)__blue_glCore_glVertexAttrib2fvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib2sNV;
void APIENTRY bluegl_glVertexAttrib2sNV (GLuint index, GLshort x, GLshort y) {
    typedef void (APIENTRYP PFN_glVertexAttrib2sNV) (GLuint index, GLshort x, GLshort y);
    return ((PFN_glVertexAttrib2sNV)__blue_glCore_glVertexAttrib2sNV)(index, x, y);
}

extern void* __blue_glCore_glVertexAttrib2svNV;
void APIENTRY bluegl_glVertexAttrib2svNV (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib2svNV) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib2svNV)__blue_glCore_glVertexAttrib2svNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3dNV;
void APIENTRY bluegl_glVertexAttrib3dNV (GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3dNV) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
    return ((PFN_glVertexAttrib3dNV)__blue_glCore_glVertexAttrib3dNV)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3dvNV;
void APIENTRY bluegl_glVertexAttrib3dvNV (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3dvNV) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib3dvNV)__blue_glCore_glVertexAttrib3dvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3fNV;
void APIENTRY bluegl_glVertexAttrib3fNV (GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3fNV) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glVertexAttrib3fNV)__blue_glCore_glVertexAttrib3fNV)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3fvNV;
void APIENTRY bluegl_glVertexAttrib3fvNV (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3fvNV) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib3fvNV)__blue_glCore_glVertexAttrib3fvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib3sNV;
void APIENTRY bluegl_glVertexAttrib3sNV (GLuint index, GLshort x, GLshort y, GLshort z) {
    typedef void (APIENTRYP PFN_glVertexAttrib3sNV) (GLuint index, GLshort x, GLshort y, GLshort z);
    return ((PFN_glVertexAttrib3sNV)__blue_glCore_glVertexAttrib3sNV)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttrib3svNV;
void APIENTRY bluegl_glVertexAttrib3svNV (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib3svNV) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib3svNV)__blue_glCore_glVertexAttrib3svNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4dNV;
void APIENTRY bluegl_glVertexAttrib4dNV (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4dNV) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    return ((PFN_glVertexAttrib4dNV)__blue_glCore_glVertexAttrib4dNV)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4dvNV;
void APIENTRY bluegl_glVertexAttrib4dvNV (GLuint index, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4dvNV) (GLuint index, const GLdouble *v);
    return ((PFN_glVertexAttrib4dvNV)__blue_glCore_glVertexAttrib4dvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4fNV;
void APIENTRY bluegl_glVertexAttrib4fNV (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4fNV) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glVertexAttrib4fNV)__blue_glCore_glVertexAttrib4fNV)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4fvNV;
void APIENTRY bluegl_glVertexAttrib4fvNV (GLuint index, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4fvNV) (GLuint index, const GLfloat *v);
    return ((PFN_glVertexAttrib4fvNV)__blue_glCore_glVertexAttrib4fvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4sNV;
void APIENTRY bluegl_glVertexAttrib4sNV (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4sNV) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
    return ((PFN_glVertexAttrib4sNV)__blue_glCore_glVertexAttrib4sNV)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4svNV;
void APIENTRY bluegl_glVertexAttrib4svNV (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4svNV) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttrib4svNV)__blue_glCore_glVertexAttrib4svNV)(index, v);
}

extern void* __blue_glCore_glVertexAttrib4ubNV;
void APIENTRY bluegl_glVertexAttrib4ubNV (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    typedef void (APIENTRYP PFN_glVertexAttrib4ubNV) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
    return ((PFN_glVertexAttrib4ubNV)__blue_glCore_glVertexAttrib4ubNV)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttrib4ubvNV;
void APIENTRY bluegl_glVertexAttrib4ubvNV (GLuint index, const GLubyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttrib4ubvNV) (GLuint index, const GLubyte *v);
    return ((PFN_glVertexAttrib4ubvNV)__blue_glCore_glVertexAttrib4ubvNV)(index, v);
}

extern void* __blue_glCore_glVertexAttribs1dvNV;
void APIENTRY bluegl_glVertexAttribs1dvNV (GLuint index, GLsizei count, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs1dvNV) (GLuint index, GLsizei count, const GLdouble *v);
    return ((PFN_glVertexAttribs1dvNV)__blue_glCore_glVertexAttribs1dvNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs1fvNV;
void APIENTRY bluegl_glVertexAttribs1fvNV (GLuint index, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs1fvNV) (GLuint index, GLsizei count, const GLfloat *v);
    return ((PFN_glVertexAttribs1fvNV)__blue_glCore_glVertexAttribs1fvNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs1svNV;
void APIENTRY bluegl_glVertexAttribs1svNV (GLuint index, GLsizei count, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs1svNV) (GLuint index, GLsizei count, const GLshort *v);
    return ((PFN_glVertexAttribs1svNV)__blue_glCore_glVertexAttribs1svNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs2dvNV;
void APIENTRY bluegl_glVertexAttribs2dvNV (GLuint index, GLsizei count, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs2dvNV) (GLuint index, GLsizei count, const GLdouble *v);
    return ((PFN_glVertexAttribs2dvNV)__blue_glCore_glVertexAttribs2dvNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs2fvNV;
void APIENTRY bluegl_glVertexAttribs2fvNV (GLuint index, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs2fvNV) (GLuint index, GLsizei count, const GLfloat *v);
    return ((PFN_glVertexAttribs2fvNV)__blue_glCore_glVertexAttribs2fvNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs2svNV;
void APIENTRY bluegl_glVertexAttribs2svNV (GLuint index, GLsizei count, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs2svNV) (GLuint index, GLsizei count, const GLshort *v);
    return ((PFN_glVertexAttribs2svNV)__blue_glCore_glVertexAttribs2svNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs3dvNV;
void APIENTRY bluegl_glVertexAttribs3dvNV (GLuint index, GLsizei count, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs3dvNV) (GLuint index, GLsizei count, const GLdouble *v);
    return ((PFN_glVertexAttribs3dvNV)__blue_glCore_glVertexAttribs3dvNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs3fvNV;
void APIENTRY bluegl_glVertexAttribs3fvNV (GLuint index, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs3fvNV) (GLuint index, GLsizei count, const GLfloat *v);
    return ((PFN_glVertexAttribs3fvNV)__blue_glCore_glVertexAttribs3fvNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs3svNV;
void APIENTRY bluegl_glVertexAttribs3svNV (GLuint index, GLsizei count, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs3svNV) (GLuint index, GLsizei count, const GLshort *v);
    return ((PFN_glVertexAttribs3svNV)__blue_glCore_glVertexAttribs3svNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs4dvNV;
void APIENTRY bluegl_glVertexAttribs4dvNV (GLuint index, GLsizei count, const GLdouble *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs4dvNV) (GLuint index, GLsizei count, const GLdouble *v);
    return ((PFN_glVertexAttribs4dvNV)__blue_glCore_glVertexAttribs4dvNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs4fvNV;
void APIENTRY bluegl_glVertexAttribs4fvNV (GLuint index, GLsizei count, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs4fvNV) (GLuint index, GLsizei count, const GLfloat *v);
    return ((PFN_glVertexAttribs4fvNV)__blue_glCore_glVertexAttribs4fvNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs4svNV;
void APIENTRY bluegl_glVertexAttribs4svNV (GLuint index, GLsizei count, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs4svNV) (GLuint index, GLsizei count, const GLshort *v);
    return ((PFN_glVertexAttribs4svNV)__blue_glCore_glVertexAttribs4svNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribs4ubvNV;
void APIENTRY bluegl_glVertexAttribs4ubvNV (GLuint index, GLsizei count, const GLubyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttribs4ubvNV) (GLuint index, GLsizei count, const GLubyte *v);
    return ((PFN_glVertexAttribs4ubvNV)__blue_glCore_glVertexAttribs4ubvNV)(index, count, v);
}

extern void* __blue_glCore_glVertexAttribI1iEXT;
void APIENTRY bluegl_glVertexAttribI1iEXT (GLuint index, GLint x) {
    typedef void (APIENTRYP PFN_glVertexAttribI1iEXT) (GLuint index, GLint x);
    return ((PFN_glVertexAttribI1iEXT)__blue_glCore_glVertexAttribI1iEXT)(index, x);
}

extern void* __blue_glCore_glVertexAttribI2iEXT;
void APIENTRY bluegl_glVertexAttribI2iEXT (GLuint index, GLint x, GLint y) {
    typedef void (APIENTRYP PFN_glVertexAttribI2iEXT) (GLuint index, GLint x, GLint y);
    return ((PFN_glVertexAttribI2iEXT)__blue_glCore_glVertexAttribI2iEXT)(index, x, y);
}

extern void* __blue_glCore_glVertexAttribI3iEXT;
void APIENTRY bluegl_glVertexAttribI3iEXT (GLuint index, GLint x, GLint y, GLint z) {
    typedef void (APIENTRYP PFN_glVertexAttribI3iEXT) (GLuint index, GLint x, GLint y, GLint z);
    return ((PFN_glVertexAttribI3iEXT)__blue_glCore_glVertexAttribI3iEXT)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttribI4iEXT;
void APIENTRY bluegl_glVertexAttribI4iEXT (GLuint index, GLint x, GLint y, GLint z, GLint w) {
    typedef void (APIENTRYP PFN_glVertexAttribI4iEXT) (GLuint index, GLint x, GLint y, GLint z, GLint w);
    return ((PFN_glVertexAttribI4iEXT)__blue_glCore_glVertexAttribI4iEXT)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttribI1uiEXT;
void APIENTRY bluegl_glVertexAttribI1uiEXT (GLuint index, GLuint x) {
    typedef void (APIENTRYP PFN_glVertexAttribI1uiEXT) (GLuint index, GLuint x);
    return ((PFN_glVertexAttribI1uiEXT)__blue_glCore_glVertexAttribI1uiEXT)(index, x);
}

extern void* __blue_glCore_glVertexAttribI2uiEXT;
void APIENTRY bluegl_glVertexAttribI2uiEXT (GLuint index, GLuint x, GLuint y) {
    typedef void (APIENTRYP PFN_glVertexAttribI2uiEXT) (GLuint index, GLuint x, GLuint y);
    return ((PFN_glVertexAttribI2uiEXT)__blue_glCore_glVertexAttribI2uiEXT)(index, x, y);
}

extern void* __blue_glCore_glVertexAttribI3uiEXT;
void APIENTRY bluegl_glVertexAttribI3uiEXT (GLuint index, GLuint x, GLuint y, GLuint z) {
    typedef void (APIENTRYP PFN_glVertexAttribI3uiEXT) (GLuint index, GLuint x, GLuint y, GLuint z);
    return ((PFN_glVertexAttribI3uiEXT)__blue_glCore_glVertexAttribI3uiEXT)(index, x, y, z);
}

extern void* __blue_glCore_glVertexAttribI4uiEXT;
void APIENTRY bluegl_glVertexAttribI4uiEXT (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    typedef void (APIENTRYP PFN_glVertexAttribI4uiEXT) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    return ((PFN_glVertexAttribI4uiEXT)__blue_glCore_glVertexAttribI4uiEXT)(index, x, y, z, w);
}

extern void* __blue_glCore_glVertexAttribI1ivEXT;
void APIENTRY bluegl_glVertexAttribI1ivEXT (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI1ivEXT) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttribI1ivEXT)__blue_glCore_glVertexAttribI1ivEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI2ivEXT;
void APIENTRY bluegl_glVertexAttribI2ivEXT (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI2ivEXT) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttribI2ivEXT)__blue_glCore_glVertexAttribI2ivEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI3ivEXT;
void APIENTRY bluegl_glVertexAttribI3ivEXT (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI3ivEXT) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttribI3ivEXT)__blue_glCore_glVertexAttribI3ivEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4ivEXT;
void APIENTRY bluegl_glVertexAttribI4ivEXT (GLuint index, const GLint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4ivEXT) (GLuint index, const GLint *v);
    return ((PFN_glVertexAttribI4ivEXT)__blue_glCore_glVertexAttribI4ivEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI1uivEXT;
void APIENTRY bluegl_glVertexAttribI1uivEXT (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI1uivEXT) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttribI1uivEXT)__blue_glCore_glVertexAttribI1uivEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI2uivEXT;
void APIENTRY bluegl_glVertexAttribI2uivEXT (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI2uivEXT) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttribI2uivEXT)__blue_glCore_glVertexAttribI2uivEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI3uivEXT;
void APIENTRY bluegl_glVertexAttribI3uivEXT (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI3uivEXT) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttribI3uivEXT)__blue_glCore_glVertexAttribI3uivEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4uivEXT;
void APIENTRY bluegl_glVertexAttribI4uivEXT (GLuint index, const GLuint *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4uivEXT) (GLuint index, const GLuint *v);
    return ((PFN_glVertexAttribI4uivEXT)__blue_glCore_glVertexAttribI4uivEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4bvEXT;
void APIENTRY bluegl_glVertexAttribI4bvEXT (GLuint index, const GLbyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4bvEXT) (GLuint index, const GLbyte *v);
    return ((PFN_glVertexAttribI4bvEXT)__blue_glCore_glVertexAttribI4bvEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4svEXT;
void APIENTRY bluegl_glVertexAttribI4svEXT (GLuint index, const GLshort *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4svEXT) (GLuint index, const GLshort *v);
    return ((PFN_glVertexAttribI4svEXT)__blue_glCore_glVertexAttribI4svEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4ubvEXT;
void APIENTRY bluegl_glVertexAttribI4ubvEXT (GLuint index, const GLubyte *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4ubvEXT) (GLuint index, const GLubyte *v);
    return ((PFN_glVertexAttribI4ubvEXT)__blue_glCore_glVertexAttribI4ubvEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribI4usvEXT;
void APIENTRY bluegl_glVertexAttribI4usvEXT (GLuint index, const GLushort *v) {
    typedef void (APIENTRYP PFN_glVertexAttribI4usvEXT) (GLuint index, const GLushort *v);
    return ((PFN_glVertexAttribI4usvEXT)__blue_glCore_glVertexAttribI4usvEXT)(index, v);
}

extern void* __blue_glCore_glVertexAttribIPointerEXT;
void APIENTRY bluegl_glVertexAttribIPointerEXT (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) {
    typedef void (APIENTRYP PFN_glVertexAttribIPointerEXT) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
    return ((PFN_glVertexAttribIPointerEXT)__blue_glCore_glVertexAttribIPointerEXT)(index, size, type, stride, pointer);
}

extern void* __blue_glCore_glGetVertexAttribIivEXT;
void APIENTRY bluegl_glGetVertexAttribIivEXT (GLuint index, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribIivEXT) (GLuint index, GLenum pname, GLint *params);
    return ((PFN_glGetVertexAttribIivEXT)__blue_glCore_glGetVertexAttribIivEXT)(index, pname, params);
}

extern void* __blue_glCore_glGetVertexAttribIuivEXT;
void APIENTRY bluegl_glGetVertexAttribIuivEXT (GLuint index, GLenum pname, GLuint *params) {
    typedef void (APIENTRYP PFN_glGetVertexAttribIuivEXT) (GLuint index, GLenum pname, GLuint *params);
    return ((PFN_glGetVertexAttribIuivEXT)__blue_glCore_glGetVertexAttribIuivEXT)(index, pname, params);
}

extern void* __blue_glCore_glBeginVideoCaptureNV;
void APIENTRY bluegl_glBeginVideoCaptureNV (GLuint video_capture_slot) {
    typedef void (APIENTRYP PFN_glBeginVideoCaptureNV) (GLuint video_capture_slot);
    return ((PFN_glBeginVideoCaptureNV)__blue_glCore_glBeginVideoCaptureNV)(video_capture_slot);
}

extern void* __blue_glCore_glBindVideoCaptureStreamBufferNV;
void APIENTRY bluegl_glBindVideoCaptureStreamBufferNV (GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset) {
    typedef void (APIENTRYP PFN_glBindVideoCaptureStreamBufferNV) (GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
    return ((PFN_glBindVideoCaptureStreamBufferNV)__blue_glCore_glBindVideoCaptureStreamBufferNV)(video_capture_slot, stream, frame_region, offset);
}

extern void* __blue_glCore_glBindVideoCaptureStreamTextureNV;
void APIENTRY bluegl_glBindVideoCaptureStreamTextureNV (GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture) {
    typedef void (APIENTRYP PFN_glBindVideoCaptureStreamTextureNV) (GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
    return ((PFN_glBindVideoCaptureStreamTextureNV)__blue_glCore_glBindVideoCaptureStreamTextureNV)(video_capture_slot, stream, frame_region, target, texture);
}

extern void* __blue_glCore_glEndVideoCaptureNV;
void APIENTRY bluegl_glEndVideoCaptureNV (GLuint video_capture_slot) {
    typedef void (APIENTRYP PFN_glEndVideoCaptureNV) (GLuint video_capture_slot);
    return ((PFN_glEndVideoCaptureNV)__blue_glCore_glEndVideoCaptureNV)(video_capture_slot);
}

extern void* __blue_glCore_glGetVideoCaptureivNV;
void APIENTRY bluegl_glGetVideoCaptureivNV (GLuint video_capture_slot, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVideoCaptureivNV) (GLuint video_capture_slot, GLenum pname, GLint *params);
    return ((PFN_glGetVideoCaptureivNV)__blue_glCore_glGetVideoCaptureivNV)(video_capture_slot, pname, params);
}

extern void* __blue_glCore_glGetVideoCaptureStreamivNV;
void APIENTRY bluegl_glGetVideoCaptureStreamivNV (GLuint video_capture_slot, GLuint stream, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetVideoCaptureStreamivNV) (GLuint video_capture_slot, GLuint stream, GLenum pname, GLint *params);
    return ((PFN_glGetVideoCaptureStreamivNV)__blue_glCore_glGetVideoCaptureStreamivNV)(video_capture_slot, stream, pname, params);
}

extern void* __blue_glCore_glGetVideoCaptureStreamfvNV;
void APIENTRY bluegl_glGetVideoCaptureStreamfvNV (GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetVideoCaptureStreamfvNV) (GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat *params);
    return ((PFN_glGetVideoCaptureStreamfvNV)__blue_glCore_glGetVideoCaptureStreamfvNV)(video_capture_slot, stream, pname, params);
}

extern void* __blue_glCore_glGetVideoCaptureStreamdvNV;
void APIENTRY bluegl_glGetVideoCaptureStreamdvNV (GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble *params) {
    typedef void (APIENTRYP PFN_glGetVideoCaptureStreamdvNV) (GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble *params);
    return ((PFN_glGetVideoCaptureStreamdvNV)__blue_glCore_glGetVideoCaptureStreamdvNV)(video_capture_slot, stream, pname, params);
}

extern void* __blue_glCore_glVideoCaptureNV;
GLenum APIENTRY bluegl_glVideoCaptureNV (GLuint video_capture_slot, GLuint *sequence_num, GLuint64EXT *capture_time) {
    typedef GLenum (APIENTRYP PFN_glVideoCaptureNV) (GLuint video_capture_slot, GLuint *sequence_num, GLuint64EXT *capture_time);
    return ((PFN_glVideoCaptureNV)__blue_glCore_glVideoCaptureNV)(video_capture_slot, sequence_num, capture_time);
}

extern void* __blue_glCore_glVideoCaptureStreamParameterivNV;
void APIENTRY bluegl_glVideoCaptureStreamParameterivNV (GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glVideoCaptureStreamParameterivNV) (GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint *params);
    return ((PFN_glVideoCaptureStreamParameterivNV)__blue_glCore_glVideoCaptureStreamParameterivNV)(video_capture_slot, stream, pname, params);
}

extern void* __blue_glCore_glVideoCaptureStreamParameterfvNV;
void APIENTRY bluegl_glVideoCaptureStreamParameterfvNV (GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glVideoCaptureStreamParameterfvNV) (GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat *params);
    return ((PFN_glVideoCaptureStreamParameterfvNV)__blue_glCore_glVideoCaptureStreamParameterfvNV)(video_capture_slot, stream, pname, params);
}

extern void* __blue_glCore_glVideoCaptureStreamParameterdvNV;
void APIENTRY bluegl_glVideoCaptureStreamParameterdvNV (GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble *params) {
    typedef void (APIENTRYP PFN_glVideoCaptureStreamParameterdvNV) (GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble *params);
    return ((PFN_glVideoCaptureStreamParameterdvNV)__blue_glCore_glVideoCaptureStreamParameterdvNV)(video_capture_slot, stream, pname, params);
}

extern void* __blue_glCore_glFramebufferTextureMultiviewOVR;
void APIENTRY bluegl_glFramebufferTextureMultiviewOVR (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews) {
    typedef void (APIENTRYP PFN_glFramebufferTextureMultiviewOVR) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
    return ((PFN_glFramebufferTextureMultiviewOVR)__blue_glCore_glFramebufferTextureMultiviewOVR)(target, attachment, texture, level, baseViewIndex, numViews);
}

extern void* __blue_glCore_glHintPGI;
void APIENTRY bluegl_glHintPGI (GLenum target, GLint mode) {
    typedef void (APIENTRYP PFN_glHintPGI) (GLenum target, GLint mode);
    return ((PFN_glHintPGI)__blue_glCore_glHintPGI)(target, mode);
}

extern void* __blue_glCore_glDetailTexFuncSGIS;
void APIENTRY bluegl_glDetailTexFuncSGIS (GLenum target, GLsizei n, const GLfloat *points) {
    typedef void (APIENTRYP PFN_glDetailTexFuncSGIS) (GLenum target, GLsizei n, const GLfloat *points);
    return ((PFN_glDetailTexFuncSGIS)__blue_glCore_glDetailTexFuncSGIS)(target, n, points);
}

extern void* __blue_glCore_glGetDetailTexFuncSGIS;
void APIENTRY bluegl_glGetDetailTexFuncSGIS (GLenum target, GLfloat *points) {
    typedef void (APIENTRYP PFN_glGetDetailTexFuncSGIS) (GLenum target, GLfloat *points);
    return ((PFN_glGetDetailTexFuncSGIS)__blue_glCore_glGetDetailTexFuncSGIS)(target, points);
}

extern void* __blue_glCore_glFogFuncSGIS;
void APIENTRY bluegl_glFogFuncSGIS (GLsizei n, const GLfloat *points) {
    typedef void (APIENTRYP PFN_glFogFuncSGIS) (GLsizei n, const GLfloat *points);
    return ((PFN_glFogFuncSGIS)__blue_glCore_glFogFuncSGIS)(n, points);
}

extern void* __blue_glCore_glGetFogFuncSGIS;
void APIENTRY bluegl_glGetFogFuncSGIS (GLfloat *points) {
    typedef void (APIENTRYP PFN_glGetFogFuncSGIS) (GLfloat *points);
    return ((PFN_glGetFogFuncSGIS)__blue_glCore_glGetFogFuncSGIS)(points);
}

extern void* __blue_glCore_glSampleMaskSGIS;
void APIENTRY bluegl_glSampleMaskSGIS (GLclampf value, GLboolean invert) {
    typedef void (APIENTRYP PFN_glSampleMaskSGIS) (GLclampf value, GLboolean invert);
    return ((PFN_glSampleMaskSGIS)__blue_glCore_glSampleMaskSGIS)(value, invert);
}

extern void* __blue_glCore_glSamplePatternSGIS;
void APIENTRY bluegl_glSamplePatternSGIS (GLenum pattern) {
    typedef void (APIENTRYP PFN_glSamplePatternSGIS) (GLenum pattern);
    return ((PFN_glSamplePatternSGIS)__blue_glCore_glSamplePatternSGIS)(pattern);
}

extern void* __blue_glCore_glPixelTexGenParameteriSGIS;
void APIENTRY bluegl_glPixelTexGenParameteriSGIS (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glPixelTexGenParameteriSGIS) (GLenum pname, GLint param);
    return ((PFN_glPixelTexGenParameteriSGIS)__blue_glCore_glPixelTexGenParameteriSGIS)(pname, param);
}

extern void* __blue_glCore_glPixelTexGenParameterivSGIS;
void APIENTRY bluegl_glPixelTexGenParameterivSGIS (GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glPixelTexGenParameterivSGIS) (GLenum pname, const GLint *params);
    return ((PFN_glPixelTexGenParameterivSGIS)__blue_glCore_glPixelTexGenParameterivSGIS)(pname, params);
}

extern void* __blue_glCore_glPixelTexGenParameterfSGIS;
void APIENTRY bluegl_glPixelTexGenParameterfSGIS (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glPixelTexGenParameterfSGIS) (GLenum pname, GLfloat param);
    return ((PFN_glPixelTexGenParameterfSGIS)__blue_glCore_glPixelTexGenParameterfSGIS)(pname, param);
}

extern void* __blue_glCore_glPixelTexGenParameterfvSGIS;
void APIENTRY bluegl_glPixelTexGenParameterfvSGIS (GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glPixelTexGenParameterfvSGIS) (GLenum pname, const GLfloat *params);
    return ((PFN_glPixelTexGenParameterfvSGIS)__blue_glCore_glPixelTexGenParameterfvSGIS)(pname, params);
}

extern void* __blue_glCore_glGetPixelTexGenParameterivSGIS;
void APIENTRY bluegl_glGetPixelTexGenParameterivSGIS (GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetPixelTexGenParameterivSGIS) (GLenum pname, GLint *params);
    return ((PFN_glGetPixelTexGenParameterivSGIS)__blue_glCore_glGetPixelTexGenParameterivSGIS)(pname, params);
}

extern void* __blue_glCore_glGetPixelTexGenParameterfvSGIS;
void APIENTRY bluegl_glGetPixelTexGenParameterfvSGIS (GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetPixelTexGenParameterfvSGIS) (GLenum pname, GLfloat *params);
    return ((PFN_glGetPixelTexGenParameterfvSGIS)__blue_glCore_glGetPixelTexGenParameterfvSGIS)(pname, params);
}

extern void* __blue_glCore_glPointParameterfSGIS;
void APIENTRY bluegl_glPointParameterfSGIS (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glPointParameterfSGIS) (GLenum pname, GLfloat param);
    return ((PFN_glPointParameterfSGIS)__blue_glCore_glPointParameterfSGIS)(pname, param);
}

extern void* __blue_glCore_glPointParameterfvSGIS;
void APIENTRY bluegl_glPointParameterfvSGIS (GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glPointParameterfvSGIS) (GLenum pname, const GLfloat *params);
    return ((PFN_glPointParameterfvSGIS)__blue_glCore_glPointParameterfvSGIS)(pname, params);
}

extern void* __blue_glCore_glSharpenTexFuncSGIS;
void APIENTRY bluegl_glSharpenTexFuncSGIS (GLenum target, GLsizei n, const GLfloat *points) {
    typedef void (APIENTRYP PFN_glSharpenTexFuncSGIS) (GLenum target, GLsizei n, const GLfloat *points);
    return ((PFN_glSharpenTexFuncSGIS)__blue_glCore_glSharpenTexFuncSGIS)(target, n, points);
}

extern void* __blue_glCore_glGetSharpenTexFuncSGIS;
void APIENTRY bluegl_glGetSharpenTexFuncSGIS (GLenum target, GLfloat *points) {
    typedef void (APIENTRYP PFN_glGetSharpenTexFuncSGIS) (GLenum target, GLfloat *points);
    return ((PFN_glGetSharpenTexFuncSGIS)__blue_glCore_glGetSharpenTexFuncSGIS)(target, points);
}

extern void* __blue_glCore_glTexImage4DSGIS;
void APIENTRY bluegl_glTexImage4DSGIS (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexImage4DSGIS) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexImage4DSGIS)__blue_glCore_glTexImage4DSGIS)(target, level, internalformat, width, height, depth, size4d, border, format, type, pixels);
}

extern void* __blue_glCore_glTexSubImage4DSGIS;
void APIENTRY bluegl_glTexSubImage4DSGIS (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const void *pixels) {
    typedef void (APIENTRYP PFN_glTexSubImage4DSGIS) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const void *pixels);
    return ((PFN_glTexSubImage4DSGIS)__blue_glCore_glTexSubImage4DSGIS)(target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels);
}

extern void* __blue_glCore_glTextureColorMaskSGIS;
void APIENTRY bluegl_glTextureColorMaskSGIS (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    typedef void (APIENTRYP PFN_glTextureColorMaskSGIS) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    return ((PFN_glTextureColorMaskSGIS)__blue_glCore_glTextureColorMaskSGIS)(red, green, blue, alpha);
}

extern void* __blue_glCore_glGetTexFilterFuncSGIS;
void APIENTRY bluegl_glGetTexFilterFuncSGIS (GLenum target, GLenum filter, GLfloat *weights) {
    typedef void (APIENTRYP PFN_glGetTexFilterFuncSGIS) (GLenum target, GLenum filter, GLfloat *weights);
    return ((PFN_glGetTexFilterFuncSGIS)__blue_glCore_glGetTexFilterFuncSGIS)(target, filter, weights);
}

extern void* __blue_glCore_glTexFilterFuncSGIS;
void APIENTRY bluegl_glTexFilterFuncSGIS (GLenum target, GLenum filter, GLsizei n, const GLfloat *weights) {
    typedef void (APIENTRYP PFN_glTexFilterFuncSGIS) (GLenum target, GLenum filter, GLsizei n, const GLfloat *weights);
    return ((PFN_glTexFilterFuncSGIS)__blue_glCore_glTexFilterFuncSGIS)(target, filter, n, weights);
}

extern void* __blue_glCore_glAsyncMarkerSGIX;
void APIENTRY bluegl_glAsyncMarkerSGIX (GLuint marker) {
    typedef void (APIENTRYP PFN_glAsyncMarkerSGIX) (GLuint marker);
    return ((PFN_glAsyncMarkerSGIX)__blue_glCore_glAsyncMarkerSGIX)(marker);
}

extern void* __blue_glCore_glFinishAsyncSGIX;
GLint APIENTRY bluegl_glFinishAsyncSGIX (GLuint *markerp) {
    typedef GLint (APIENTRYP PFN_glFinishAsyncSGIX) (GLuint *markerp);
    return ((PFN_glFinishAsyncSGIX)__blue_glCore_glFinishAsyncSGIX)(markerp);
}

extern void* __blue_glCore_glPollAsyncSGIX;
GLint APIENTRY bluegl_glPollAsyncSGIX (GLuint *markerp) {
    typedef GLint (APIENTRYP PFN_glPollAsyncSGIX) (GLuint *markerp);
    return ((PFN_glPollAsyncSGIX)__blue_glCore_glPollAsyncSGIX)(markerp);
}

extern void* __blue_glCore_glGenAsyncMarkersSGIX;
GLuint APIENTRY bluegl_glGenAsyncMarkersSGIX (GLsizei range) {
    typedef GLuint (APIENTRYP PFN_glGenAsyncMarkersSGIX) (GLsizei range);
    return ((PFN_glGenAsyncMarkersSGIX)__blue_glCore_glGenAsyncMarkersSGIX)(range);
}

extern void* __blue_glCore_glDeleteAsyncMarkersSGIX;
void APIENTRY bluegl_glDeleteAsyncMarkersSGIX (GLuint marker, GLsizei range) {
    typedef void (APIENTRYP PFN_glDeleteAsyncMarkersSGIX) (GLuint marker, GLsizei range);
    return ((PFN_glDeleteAsyncMarkersSGIX)__blue_glCore_glDeleteAsyncMarkersSGIX)(marker, range);
}

extern void* __blue_glCore_glIsAsyncMarkerSGIX;
GLboolean APIENTRY bluegl_glIsAsyncMarkerSGIX (GLuint marker) {
    typedef GLboolean (APIENTRYP PFN_glIsAsyncMarkerSGIX) (GLuint marker);
    return ((PFN_glIsAsyncMarkerSGIX)__blue_glCore_glIsAsyncMarkerSGIX)(marker);
}

extern void* __blue_glCore_glFlushRasterSGIX;
void APIENTRY bluegl_glFlushRasterSGIX (void) {
    typedef void (APIENTRYP PFN_glFlushRasterSGIX) (void);
    return ((PFN_glFlushRasterSGIX)__blue_glCore_glFlushRasterSGIX)();
}

extern void* __blue_glCore_glFragmentColorMaterialSGIX;
void APIENTRY bluegl_glFragmentColorMaterialSGIX (GLenum face, GLenum mode) {
    typedef void (APIENTRYP PFN_glFragmentColorMaterialSGIX) (GLenum face, GLenum mode);
    return ((PFN_glFragmentColorMaterialSGIX)__blue_glCore_glFragmentColorMaterialSGIX)(face, mode);
}

extern void* __blue_glCore_glFragmentLightfSGIX;
void APIENTRY bluegl_glFragmentLightfSGIX (GLenum light, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glFragmentLightfSGIX) (GLenum light, GLenum pname, GLfloat param);
    return ((PFN_glFragmentLightfSGIX)__blue_glCore_glFragmentLightfSGIX)(light, pname, param);
}

extern void* __blue_glCore_glFragmentLightfvSGIX;
void APIENTRY bluegl_glFragmentLightfvSGIX (GLenum light, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glFragmentLightfvSGIX) (GLenum light, GLenum pname, const GLfloat *params);
    return ((PFN_glFragmentLightfvSGIX)__blue_glCore_glFragmentLightfvSGIX)(light, pname, params);
}

extern void* __blue_glCore_glFragmentLightiSGIX;
void APIENTRY bluegl_glFragmentLightiSGIX (GLenum light, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glFragmentLightiSGIX) (GLenum light, GLenum pname, GLint param);
    return ((PFN_glFragmentLightiSGIX)__blue_glCore_glFragmentLightiSGIX)(light, pname, param);
}

extern void* __blue_glCore_glFragmentLightivSGIX;
void APIENTRY bluegl_glFragmentLightivSGIX (GLenum light, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glFragmentLightivSGIX) (GLenum light, GLenum pname, const GLint *params);
    return ((PFN_glFragmentLightivSGIX)__blue_glCore_glFragmentLightivSGIX)(light, pname, params);
}

extern void* __blue_glCore_glFragmentLightModelfSGIX;
void APIENTRY bluegl_glFragmentLightModelfSGIX (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glFragmentLightModelfSGIX) (GLenum pname, GLfloat param);
    return ((PFN_glFragmentLightModelfSGIX)__blue_glCore_glFragmentLightModelfSGIX)(pname, param);
}

extern void* __blue_glCore_glFragmentLightModelfvSGIX;
void APIENTRY bluegl_glFragmentLightModelfvSGIX (GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glFragmentLightModelfvSGIX) (GLenum pname, const GLfloat *params);
    return ((PFN_glFragmentLightModelfvSGIX)__blue_glCore_glFragmentLightModelfvSGIX)(pname, params);
}

extern void* __blue_glCore_glFragmentLightModeliSGIX;
void APIENTRY bluegl_glFragmentLightModeliSGIX (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glFragmentLightModeliSGIX) (GLenum pname, GLint param);
    return ((PFN_glFragmentLightModeliSGIX)__blue_glCore_glFragmentLightModeliSGIX)(pname, param);
}

extern void* __blue_glCore_glFragmentLightModelivSGIX;
void APIENTRY bluegl_glFragmentLightModelivSGIX (GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glFragmentLightModelivSGIX) (GLenum pname, const GLint *params);
    return ((PFN_glFragmentLightModelivSGIX)__blue_glCore_glFragmentLightModelivSGIX)(pname, params);
}

extern void* __blue_glCore_glFragmentMaterialfSGIX;
void APIENTRY bluegl_glFragmentMaterialfSGIX (GLenum face, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glFragmentMaterialfSGIX) (GLenum face, GLenum pname, GLfloat param);
    return ((PFN_glFragmentMaterialfSGIX)__blue_glCore_glFragmentMaterialfSGIX)(face, pname, param);
}

extern void* __blue_glCore_glFragmentMaterialfvSGIX;
void APIENTRY bluegl_glFragmentMaterialfvSGIX (GLenum face, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glFragmentMaterialfvSGIX) (GLenum face, GLenum pname, const GLfloat *params);
    return ((PFN_glFragmentMaterialfvSGIX)__blue_glCore_glFragmentMaterialfvSGIX)(face, pname, params);
}

extern void* __blue_glCore_glFragmentMaterialiSGIX;
void APIENTRY bluegl_glFragmentMaterialiSGIX (GLenum face, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glFragmentMaterialiSGIX) (GLenum face, GLenum pname, GLint param);
    return ((PFN_glFragmentMaterialiSGIX)__blue_glCore_glFragmentMaterialiSGIX)(face, pname, param);
}

extern void* __blue_glCore_glFragmentMaterialivSGIX;
void APIENTRY bluegl_glFragmentMaterialivSGIX (GLenum face, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glFragmentMaterialivSGIX) (GLenum face, GLenum pname, const GLint *params);
    return ((PFN_glFragmentMaterialivSGIX)__blue_glCore_glFragmentMaterialivSGIX)(face, pname, params);
}

extern void* __blue_glCore_glGetFragmentLightfvSGIX;
void APIENTRY bluegl_glGetFragmentLightfvSGIX (GLenum light, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetFragmentLightfvSGIX) (GLenum light, GLenum pname, GLfloat *params);
    return ((PFN_glGetFragmentLightfvSGIX)__blue_glCore_glGetFragmentLightfvSGIX)(light, pname, params);
}

extern void* __blue_glCore_glGetFragmentLightivSGIX;
void APIENTRY bluegl_glGetFragmentLightivSGIX (GLenum light, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetFragmentLightivSGIX) (GLenum light, GLenum pname, GLint *params);
    return ((PFN_glGetFragmentLightivSGIX)__blue_glCore_glGetFragmentLightivSGIX)(light, pname, params);
}

extern void* __blue_glCore_glGetFragmentMaterialfvSGIX;
void APIENTRY bluegl_glGetFragmentMaterialfvSGIX (GLenum face, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetFragmentMaterialfvSGIX) (GLenum face, GLenum pname, GLfloat *params);
    return ((PFN_glGetFragmentMaterialfvSGIX)__blue_glCore_glGetFragmentMaterialfvSGIX)(face, pname, params);
}

extern void* __blue_glCore_glGetFragmentMaterialivSGIX;
void APIENTRY bluegl_glGetFragmentMaterialivSGIX (GLenum face, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetFragmentMaterialivSGIX) (GLenum face, GLenum pname, GLint *params);
    return ((PFN_glGetFragmentMaterialivSGIX)__blue_glCore_glGetFragmentMaterialivSGIX)(face, pname, params);
}

extern void* __blue_glCore_glLightEnviSGIX;
void APIENTRY bluegl_glLightEnviSGIX (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glLightEnviSGIX) (GLenum pname, GLint param);
    return ((PFN_glLightEnviSGIX)__blue_glCore_glLightEnviSGIX)(pname, param);
}

extern void* __blue_glCore_glFrameZoomSGIX;
void APIENTRY bluegl_glFrameZoomSGIX (GLint factor) {
    typedef void (APIENTRYP PFN_glFrameZoomSGIX) (GLint factor);
    return ((PFN_glFrameZoomSGIX)__blue_glCore_glFrameZoomSGIX)(factor);
}

extern void* __blue_glCore_glIglooInterfaceSGIX;
void APIENTRY bluegl_glIglooInterfaceSGIX (GLenum pname, const void *params) {
    typedef void (APIENTRYP PFN_glIglooInterfaceSGIX) (GLenum pname, const void *params);
    return ((PFN_glIglooInterfaceSGIX)__blue_glCore_glIglooInterfaceSGIX)(pname, params);
}

extern void* __blue_glCore_glGetInstrumentsSGIX;
GLint APIENTRY bluegl_glGetInstrumentsSGIX (void) {
    typedef GLint (APIENTRYP PFN_glGetInstrumentsSGIX) (void);
    return ((PFN_glGetInstrumentsSGIX)__blue_glCore_glGetInstrumentsSGIX)();
}

extern void* __blue_glCore_glInstrumentsBufferSGIX;
void APIENTRY bluegl_glInstrumentsBufferSGIX (GLsizei size, GLint *buffer) {
    typedef void (APIENTRYP PFN_glInstrumentsBufferSGIX) (GLsizei size, GLint *buffer);
    return ((PFN_glInstrumentsBufferSGIX)__blue_glCore_glInstrumentsBufferSGIX)(size, buffer);
}

extern void* __blue_glCore_glPollInstrumentsSGIX;
GLint APIENTRY bluegl_glPollInstrumentsSGIX (GLint *marker_p) {
    typedef GLint (APIENTRYP PFN_glPollInstrumentsSGIX) (GLint *marker_p);
    return ((PFN_glPollInstrumentsSGIX)__blue_glCore_glPollInstrumentsSGIX)(marker_p);
}

extern void* __blue_glCore_glReadInstrumentsSGIX;
void APIENTRY bluegl_glReadInstrumentsSGIX (GLint marker) {
    typedef void (APIENTRYP PFN_glReadInstrumentsSGIX) (GLint marker);
    return ((PFN_glReadInstrumentsSGIX)__blue_glCore_glReadInstrumentsSGIX)(marker);
}

extern void* __blue_glCore_glStartInstrumentsSGIX;
void APIENTRY bluegl_glStartInstrumentsSGIX (void) {
    typedef void (APIENTRYP PFN_glStartInstrumentsSGIX) (void);
    return ((PFN_glStartInstrumentsSGIX)__blue_glCore_glStartInstrumentsSGIX)();
}

extern void* __blue_glCore_glStopInstrumentsSGIX;
void APIENTRY bluegl_glStopInstrumentsSGIX (GLint marker) {
    typedef void (APIENTRYP PFN_glStopInstrumentsSGIX) (GLint marker);
    return ((PFN_glStopInstrumentsSGIX)__blue_glCore_glStopInstrumentsSGIX)(marker);
}

extern void* __blue_glCore_glGetListParameterfvSGIX;
void APIENTRY bluegl_glGetListParameterfvSGIX (GLuint list, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetListParameterfvSGIX) (GLuint list, GLenum pname, GLfloat *params);
    return ((PFN_glGetListParameterfvSGIX)__blue_glCore_glGetListParameterfvSGIX)(list, pname, params);
}

extern void* __blue_glCore_glGetListParameterivSGIX;
void APIENTRY bluegl_glGetListParameterivSGIX (GLuint list, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetListParameterivSGIX) (GLuint list, GLenum pname, GLint *params);
    return ((PFN_glGetListParameterivSGIX)__blue_glCore_glGetListParameterivSGIX)(list, pname, params);
}

extern void* __blue_glCore_glListParameterfSGIX;
void APIENTRY bluegl_glListParameterfSGIX (GLuint list, GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glListParameterfSGIX) (GLuint list, GLenum pname, GLfloat param);
    return ((PFN_glListParameterfSGIX)__blue_glCore_glListParameterfSGIX)(list, pname, param);
}

extern void* __blue_glCore_glListParameterfvSGIX;
void APIENTRY bluegl_glListParameterfvSGIX (GLuint list, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glListParameterfvSGIX) (GLuint list, GLenum pname, const GLfloat *params);
    return ((PFN_glListParameterfvSGIX)__blue_glCore_glListParameterfvSGIX)(list, pname, params);
}

extern void* __blue_glCore_glListParameteriSGIX;
void APIENTRY bluegl_glListParameteriSGIX (GLuint list, GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glListParameteriSGIX) (GLuint list, GLenum pname, GLint param);
    return ((PFN_glListParameteriSGIX)__blue_glCore_glListParameteriSGIX)(list, pname, param);
}

extern void* __blue_glCore_glListParameterivSGIX;
void APIENTRY bluegl_glListParameterivSGIX (GLuint list, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glListParameterivSGIX) (GLuint list, GLenum pname, const GLint *params);
    return ((PFN_glListParameterivSGIX)__blue_glCore_glListParameterivSGIX)(list, pname, params);
}

extern void* __blue_glCore_glPixelTexGenSGIX;
void APIENTRY bluegl_glPixelTexGenSGIX (GLenum mode) {
    typedef void (APIENTRYP PFN_glPixelTexGenSGIX) (GLenum mode);
    return ((PFN_glPixelTexGenSGIX)__blue_glCore_glPixelTexGenSGIX)(mode);
}

extern void* __blue_glCore_glDeformationMap3dSGIX;
void APIENTRY bluegl_glDeformationMap3dSGIX (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points) {
    typedef void (APIENTRYP PFN_glDeformationMap3dSGIX) (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points);
    return ((PFN_glDeformationMap3dSGIX)__blue_glCore_glDeformationMap3dSGIX)(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);
}

extern void* __blue_glCore_glDeformationMap3fSGIX;
void APIENTRY bluegl_glDeformationMap3fSGIX (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points) {
    typedef void (APIENTRYP PFN_glDeformationMap3fSGIX) (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points);
    return ((PFN_glDeformationMap3fSGIX)__blue_glCore_glDeformationMap3fSGIX)(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);
}

extern void* __blue_glCore_glDeformSGIX;
void APIENTRY bluegl_glDeformSGIX (GLbitfield mask) {
    typedef void (APIENTRYP PFN_glDeformSGIX) (GLbitfield mask);
    return ((PFN_glDeformSGIX)__blue_glCore_glDeformSGIX)(mask);
}

extern void* __blue_glCore_glLoadIdentityDeformationMapSGIX;
void APIENTRY bluegl_glLoadIdentityDeformationMapSGIX (GLbitfield mask) {
    typedef void (APIENTRYP PFN_glLoadIdentityDeformationMapSGIX) (GLbitfield mask);
    return ((PFN_glLoadIdentityDeformationMapSGIX)__blue_glCore_glLoadIdentityDeformationMapSGIX)(mask);
}

extern void* __blue_glCore_glReferencePlaneSGIX;
void APIENTRY bluegl_glReferencePlaneSGIX (const GLdouble *equation) {
    typedef void (APIENTRYP PFN_glReferencePlaneSGIX) (const GLdouble *equation);
    return ((PFN_glReferencePlaneSGIX)__blue_glCore_glReferencePlaneSGIX)(equation);
}

extern void* __blue_glCore_glSpriteParameterfSGIX;
void APIENTRY bluegl_glSpriteParameterfSGIX (GLenum pname, GLfloat param) {
    typedef void (APIENTRYP PFN_glSpriteParameterfSGIX) (GLenum pname, GLfloat param);
    return ((PFN_glSpriteParameterfSGIX)__blue_glCore_glSpriteParameterfSGIX)(pname, param);
}

extern void* __blue_glCore_glSpriteParameterfvSGIX;
void APIENTRY bluegl_glSpriteParameterfvSGIX (GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glSpriteParameterfvSGIX) (GLenum pname, const GLfloat *params);
    return ((PFN_glSpriteParameterfvSGIX)__blue_glCore_glSpriteParameterfvSGIX)(pname, params);
}

extern void* __blue_glCore_glSpriteParameteriSGIX;
void APIENTRY bluegl_glSpriteParameteriSGIX (GLenum pname, GLint param) {
    typedef void (APIENTRYP PFN_glSpriteParameteriSGIX) (GLenum pname, GLint param);
    return ((PFN_glSpriteParameteriSGIX)__blue_glCore_glSpriteParameteriSGIX)(pname, param);
}

extern void* __blue_glCore_glSpriteParameterivSGIX;
void APIENTRY bluegl_glSpriteParameterivSGIX (GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glSpriteParameterivSGIX) (GLenum pname, const GLint *params);
    return ((PFN_glSpriteParameterivSGIX)__blue_glCore_glSpriteParameterivSGIX)(pname, params);
}

extern void* __blue_glCore_glTagSampleBufferSGIX;
void APIENTRY bluegl_glTagSampleBufferSGIX (void) {
    typedef void (APIENTRYP PFN_glTagSampleBufferSGIX) (void);
    return ((PFN_glTagSampleBufferSGIX)__blue_glCore_glTagSampleBufferSGIX)();
}

extern void* __blue_glCore_glColorTableSGI;
void APIENTRY bluegl_glColorTableSGI (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table) {
    typedef void (APIENTRYP PFN_glColorTableSGI) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
    return ((PFN_glColorTableSGI)__blue_glCore_glColorTableSGI)(target, internalformat, width, format, type, table);
}

extern void* __blue_glCore_glColorTableParameterfvSGI;
void APIENTRY bluegl_glColorTableParameterfvSGI (GLenum target, GLenum pname, const GLfloat *params) {
    typedef void (APIENTRYP PFN_glColorTableParameterfvSGI) (GLenum target, GLenum pname, const GLfloat *params);
    return ((PFN_glColorTableParameterfvSGI)__blue_glCore_glColorTableParameterfvSGI)(target, pname, params);
}

extern void* __blue_glCore_glColorTableParameterivSGI;
void APIENTRY bluegl_glColorTableParameterivSGI (GLenum target, GLenum pname, const GLint *params) {
    typedef void (APIENTRYP PFN_glColorTableParameterivSGI) (GLenum target, GLenum pname, const GLint *params);
    return ((PFN_glColorTableParameterivSGI)__blue_glCore_glColorTableParameterivSGI)(target, pname, params);
}

extern void* __blue_glCore_glCopyColorTableSGI;
void APIENTRY bluegl_glCopyColorTableSGI (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    typedef void (APIENTRYP PFN_glCopyColorTableSGI) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
    return ((PFN_glCopyColorTableSGI)__blue_glCore_glCopyColorTableSGI)(target, internalformat, x, y, width);
}

extern void* __blue_glCore_glGetColorTableSGI;
void APIENTRY bluegl_glGetColorTableSGI (GLenum target, GLenum format, GLenum type, void *table) {
    typedef void (APIENTRYP PFN_glGetColorTableSGI) (GLenum target, GLenum format, GLenum type, void *table);
    return ((PFN_glGetColorTableSGI)__blue_glCore_glGetColorTableSGI)(target, format, type, table);
}

extern void* __blue_glCore_glGetColorTableParameterfvSGI;
void APIENTRY bluegl_glGetColorTableParameterfvSGI (GLenum target, GLenum pname, GLfloat *params) {
    typedef void (APIENTRYP PFN_glGetColorTableParameterfvSGI) (GLenum target, GLenum pname, GLfloat *params);
    return ((PFN_glGetColorTableParameterfvSGI)__blue_glCore_glGetColorTableParameterfvSGI)(target, pname, params);
}

extern void* __blue_glCore_glGetColorTableParameterivSGI;
void APIENTRY bluegl_glGetColorTableParameterivSGI (GLenum target, GLenum pname, GLint *params) {
    typedef void (APIENTRYP PFN_glGetColorTableParameterivSGI) (GLenum target, GLenum pname, GLint *params);
    return ((PFN_glGetColorTableParameterivSGI)__blue_glCore_glGetColorTableParameterivSGI)(target, pname, params);
}

extern void* __blue_glCore_glFinishTextureSUNX;
void APIENTRY bluegl_glFinishTextureSUNX (void) {
    typedef void (APIENTRYP PFN_glFinishTextureSUNX) (void);
    return ((PFN_glFinishTextureSUNX)__blue_glCore_glFinishTextureSUNX)();
}

extern void* __blue_glCore_glGlobalAlphaFactorbSUN;
void APIENTRY bluegl_glGlobalAlphaFactorbSUN (GLbyte factor) {
    typedef void (APIENTRYP PFN_glGlobalAlphaFactorbSUN) (GLbyte factor);
    return ((PFN_glGlobalAlphaFactorbSUN)__blue_glCore_glGlobalAlphaFactorbSUN)(factor);
}

extern void* __blue_glCore_glGlobalAlphaFactorsSUN;
void APIENTRY bluegl_glGlobalAlphaFactorsSUN (GLshort factor) {
    typedef void (APIENTRYP PFN_glGlobalAlphaFactorsSUN) (GLshort factor);
    return ((PFN_glGlobalAlphaFactorsSUN)__blue_glCore_glGlobalAlphaFactorsSUN)(factor);
}

extern void* __blue_glCore_glGlobalAlphaFactoriSUN;
void APIENTRY bluegl_glGlobalAlphaFactoriSUN (GLint factor) {
    typedef void (APIENTRYP PFN_glGlobalAlphaFactoriSUN) (GLint factor);
    return ((PFN_glGlobalAlphaFactoriSUN)__blue_glCore_glGlobalAlphaFactoriSUN)(factor);
}

extern void* __blue_glCore_glGlobalAlphaFactorfSUN;
void APIENTRY bluegl_glGlobalAlphaFactorfSUN (GLfloat factor) {
    typedef void (APIENTRYP PFN_glGlobalAlphaFactorfSUN) (GLfloat factor);
    return ((PFN_glGlobalAlphaFactorfSUN)__blue_glCore_glGlobalAlphaFactorfSUN)(factor);
}

extern void* __blue_glCore_glGlobalAlphaFactordSUN;
void APIENTRY bluegl_glGlobalAlphaFactordSUN (GLdouble factor) {
    typedef void (APIENTRYP PFN_glGlobalAlphaFactordSUN) (GLdouble factor);
    return ((PFN_glGlobalAlphaFactordSUN)__blue_glCore_glGlobalAlphaFactordSUN)(factor);
}

extern void* __blue_glCore_glGlobalAlphaFactorubSUN;
void APIENTRY bluegl_glGlobalAlphaFactorubSUN (GLubyte factor) {
    typedef void (APIENTRYP PFN_glGlobalAlphaFactorubSUN) (GLubyte factor);
    return ((PFN_glGlobalAlphaFactorubSUN)__blue_glCore_glGlobalAlphaFactorubSUN)(factor);
}

extern void* __blue_glCore_glGlobalAlphaFactorusSUN;
void APIENTRY bluegl_glGlobalAlphaFactorusSUN (GLushort factor) {
    typedef void (APIENTRYP PFN_glGlobalAlphaFactorusSUN) (GLushort factor);
    return ((PFN_glGlobalAlphaFactorusSUN)__blue_glCore_glGlobalAlphaFactorusSUN)(factor);
}

extern void* __blue_glCore_glGlobalAlphaFactoruiSUN;
void APIENTRY bluegl_glGlobalAlphaFactoruiSUN (GLuint factor) {
    typedef void (APIENTRYP PFN_glGlobalAlphaFactoruiSUN) (GLuint factor);
    return ((PFN_glGlobalAlphaFactoruiSUN)__blue_glCore_glGlobalAlphaFactoruiSUN)(factor);
}

extern void* __blue_glCore_glDrawMeshArraysSUN;
void APIENTRY bluegl_glDrawMeshArraysSUN (GLenum mode, GLint first, GLsizei count, GLsizei width) {
    typedef void (APIENTRYP PFN_glDrawMeshArraysSUN) (GLenum mode, GLint first, GLsizei count, GLsizei width);
    return ((PFN_glDrawMeshArraysSUN)__blue_glCore_glDrawMeshArraysSUN)(mode, first, count, width);
}

extern void* __blue_glCore_glReplacementCodeuiSUN;
void APIENTRY bluegl_glReplacementCodeuiSUN (GLuint code) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiSUN) (GLuint code);
    return ((PFN_glReplacementCodeuiSUN)__blue_glCore_glReplacementCodeuiSUN)(code);
}

extern void* __blue_glCore_glReplacementCodeusSUN;
void APIENTRY bluegl_glReplacementCodeusSUN (GLushort code) {
    typedef void (APIENTRYP PFN_glReplacementCodeusSUN) (GLushort code);
    return ((PFN_glReplacementCodeusSUN)__blue_glCore_glReplacementCodeusSUN)(code);
}

extern void* __blue_glCore_glReplacementCodeubSUN;
void APIENTRY bluegl_glReplacementCodeubSUN (GLubyte code) {
    typedef void (APIENTRYP PFN_glReplacementCodeubSUN) (GLubyte code);
    return ((PFN_glReplacementCodeubSUN)__blue_glCore_glReplacementCodeubSUN)(code);
}

extern void* __blue_glCore_glReplacementCodeuivSUN;
void APIENTRY bluegl_glReplacementCodeuivSUN (const GLuint *code) {
    typedef void (APIENTRYP PFN_glReplacementCodeuivSUN) (const GLuint *code);
    return ((PFN_glReplacementCodeuivSUN)__blue_glCore_glReplacementCodeuivSUN)(code);
}

extern void* __blue_glCore_glReplacementCodeusvSUN;
void APIENTRY bluegl_glReplacementCodeusvSUN (const GLushort *code) {
    typedef void (APIENTRYP PFN_glReplacementCodeusvSUN) (const GLushort *code);
    return ((PFN_glReplacementCodeusvSUN)__blue_glCore_glReplacementCodeusvSUN)(code);
}

extern void* __blue_glCore_glReplacementCodeubvSUN;
void APIENTRY bluegl_glReplacementCodeubvSUN (const GLubyte *code) {
    typedef void (APIENTRYP PFN_glReplacementCodeubvSUN) (const GLubyte *code);
    return ((PFN_glReplacementCodeubvSUN)__blue_glCore_glReplacementCodeubvSUN)(code);
}

extern void* __blue_glCore_glReplacementCodePointerSUN;
void APIENTRY bluegl_glReplacementCodePointerSUN (GLenum type, GLsizei stride, const void **pointer) {
    typedef void (APIENTRYP PFN_glReplacementCodePointerSUN) (GLenum type, GLsizei stride, const void **pointer);
    return ((PFN_glReplacementCodePointerSUN)__blue_glCore_glReplacementCodePointerSUN)(type, stride, pointer);
}

extern void* __blue_glCore_glColor4ubVertex2fSUN;
void APIENTRY bluegl_glColor4ubVertex2fSUN (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y) {
    typedef void (APIENTRYP PFN_glColor4ubVertex2fSUN) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
    return ((PFN_glColor4ubVertex2fSUN)__blue_glCore_glColor4ubVertex2fSUN)(r, g, b, a, x, y);
}

extern void* __blue_glCore_glColor4ubVertex2fvSUN;
void APIENTRY bluegl_glColor4ubVertex2fvSUN (const GLubyte *c, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glColor4ubVertex2fvSUN) (const GLubyte *c, const GLfloat *v);
    return ((PFN_glColor4ubVertex2fvSUN)__blue_glCore_glColor4ubVertex2fvSUN)(c, v);
}

extern void* __blue_glCore_glColor4ubVertex3fSUN;
void APIENTRY bluegl_glColor4ubVertex3fSUN (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glColor4ubVertex3fSUN) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glColor4ubVertex3fSUN)__blue_glCore_glColor4ubVertex3fSUN)(r, g, b, a, x, y, z);
}

extern void* __blue_glCore_glColor4ubVertex3fvSUN;
void APIENTRY bluegl_glColor4ubVertex3fvSUN (const GLubyte *c, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glColor4ubVertex3fvSUN) (const GLubyte *c, const GLfloat *v);
    return ((PFN_glColor4ubVertex3fvSUN)__blue_glCore_glColor4ubVertex3fvSUN)(c, v);
}

extern void* __blue_glCore_glColor3fVertex3fSUN;
void APIENTRY bluegl_glColor3fVertex3fSUN (GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glColor3fVertex3fSUN) (GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glColor3fVertex3fSUN)__blue_glCore_glColor3fVertex3fSUN)(r, g, b, x, y, z);
}

extern void* __blue_glCore_glColor3fVertex3fvSUN;
void APIENTRY bluegl_glColor3fVertex3fvSUN (const GLfloat *c, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glColor3fVertex3fvSUN) (const GLfloat *c, const GLfloat *v);
    return ((PFN_glColor3fVertex3fvSUN)__blue_glCore_glColor3fVertex3fvSUN)(c, v);
}

extern void* __blue_glCore_glNormal3fVertex3fSUN;
void APIENTRY bluegl_glNormal3fVertex3fSUN (GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glNormal3fVertex3fSUN) (GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glNormal3fVertex3fSUN)__blue_glCore_glNormal3fVertex3fSUN)(nx, ny, nz, x, y, z);
}

extern void* __blue_glCore_glNormal3fVertex3fvSUN;
void APIENTRY bluegl_glNormal3fVertex3fvSUN (const GLfloat *n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glNormal3fVertex3fvSUN) (const GLfloat *n, const GLfloat *v);
    return ((PFN_glNormal3fVertex3fvSUN)__blue_glCore_glNormal3fVertex3fvSUN)(n, v);
}

extern void* __blue_glCore_glColor4fNormal3fVertex3fSUN;
void APIENTRY bluegl_glColor4fNormal3fVertex3fSUN (GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glColor4fNormal3fVertex3fSUN) (GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glColor4fNormal3fVertex3fSUN)__blue_glCore_glColor4fNormal3fVertex3fSUN)(r, g, b, a, nx, ny, nz, x, y, z);
}

extern void* __blue_glCore_glColor4fNormal3fVertex3fvSUN;
void APIENTRY bluegl_glColor4fNormal3fVertex3fvSUN (const GLfloat *c, const GLfloat *n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glColor4fNormal3fVertex3fvSUN) (const GLfloat *c, const GLfloat *n, const GLfloat *v);
    return ((PFN_glColor4fNormal3fVertex3fvSUN)__blue_glCore_glColor4fNormal3fVertex3fvSUN)(c, n, v);
}

extern void* __blue_glCore_glTexCoord2fVertex3fSUN;
void APIENTRY bluegl_glTexCoord2fVertex3fSUN (GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glTexCoord2fVertex3fSUN) (GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glTexCoord2fVertex3fSUN)__blue_glCore_glTexCoord2fVertex3fSUN)(s, t, x, y, z);
}

extern void* __blue_glCore_glTexCoord2fVertex3fvSUN;
void APIENTRY bluegl_glTexCoord2fVertex3fvSUN (const GLfloat *tc, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glTexCoord2fVertex3fvSUN) (const GLfloat *tc, const GLfloat *v);
    return ((PFN_glTexCoord2fVertex3fvSUN)__blue_glCore_glTexCoord2fVertex3fvSUN)(tc, v);
}

extern void* __blue_glCore_glTexCoord4fVertex4fSUN;
void APIENTRY bluegl_glTexCoord4fVertex4fSUN (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glTexCoord4fVertex4fSUN) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glTexCoord4fVertex4fSUN)__blue_glCore_glTexCoord4fVertex4fSUN)(s, t, p, q, x, y, z, w);
}

extern void* __blue_glCore_glTexCoord4fVertex4fvSUN;
void APIENTRY bluegl_glTexCoord4fVertex4fvSUN (const GLfloat *tc, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glTexCoord4fVertex4fvSUN) (const GLfloat *tc, const GLfloat *v);
    return ((PFN_glTexCoord4fVertex4fvSUN)__blue_glCore_glTexCoord4fVertex4fvSUN)(tc, v);
}

extern void* __blue_glCore_glTexCoord2fColor4ubVertex3fSUN;
void APIENTRY bluegl_glTexCoord2fColor4ubVertex3fSUN (GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glTexCoord2fColor4ubVertex3fSUN) (GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glTexCoord2fColor4ubVertex3fSUN)__blue_glCore_glTexCoord2fColor4ubVertex3fSUN)(s, t, r, g, b, a, x, y, z);
}

extern void* __blue_glCore_glTexCoord2fColor4ubVertex3fvSUN;
void APIENTRY bluegl_glTexCoord2fColor4ubVertex3fvSUN (const GLfloat *tc, const GLubyte *c, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glTexCoord2fColor4ubVertex3fvSUN) (const GLfloat *tc, const GLubyte *c, const GLfloat *v);
    return ((PFN_glTexCoord2fColor4ubVertex3fvSUN)__blue_glCore_glTexCoord2fColor4ubVertex3fvSUN)(tc, c, v);
}

extern void* __blue_glCore_glTexCoord2fColor3fVertex3fSUN;
void APIENTRY bluegl_glTexCoord2fColor3fVertex3fSUN (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glTexCoord2fColor3fVertex3fSUN) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glTexCoord2fColor3fVertex3fSUN)__blue_glCore_glTexCoord2fColor3fVertex3fSUN)(s, t, r, g, b, x, y, z);
}

extern void* __blue_glCore_glTexCoord2fColor3fVertex3fvSUN;
void APIENTRY bluegl_glTexCoord2fColor3fVertex3fvSUN (const GLfloat *tc, const GLfloat *c, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glTexCoord2fColor3fVertex3fvSUN) (const GLfloat *tc, const GLfloat *c, const GLfloat *v);
    return ((PFN_glTexCoord2fColor3fVertex3fvSUN)__blue_glCore_glTexCoord2fColor3fVertex3fvSUN)(tc, c, v);
}

extern void* __blue_glCore_glTexCoord2fNormal3fVertex3fSUN;
void APIENTRY bluegl_glTexCoord2fNormal3fVertex3fSUN (GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glTexCoord2fNormal3fVertex3fSUN) (GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glTexCoord2fNormal3fVertex3fSUN)__blue_glCore_glTexCoord2fNormal3fVertex3fSUN)(s, t, nx, ny, nz, x, y, z);
}

extern void* __blue_glCore_glTexCoord2fNormal3fVertex3fvSUN;
void APIENTRY bluegl_glTexCoord2fNormal3fVertex3fvSUN (const GLfloat *tc, const GLfloat *n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glTexCoord2fNormal3fVertex3fvSUN) (const GLfloat *tc, const GLfloat *n, const GLfloat *v);
    return ((PFN_glTexCoord2fNormal3fVertex3fvSUN)__blue_glCore_glTexCoord2fNormal3fVertex3fvSUN)(tc, n, v);
}

extern void* __blue_glCore_glTexCoord2fColor4fNormal3fVertex3fSUN;
void APIENTRY bluegl_glTexCoord2fColor4fNormal3fVertex3fSUN (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glTexCoord2fColor4fNormal3fVertex3fSUN) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glTexCoord2fColor4fNormal3fVertex3fSUN)__blue_glCore_glTexCoord2fColor4fNormal3fVertex3fSUN)(s, t, r, g, b, a, nx, ny, nz, x, y, z);
}

extern void* __blue_glCore_glTexCoord2fColor4fNormal3fVertex3fvSUN;
void APIENTRY bluegl_glTexCoord2fColor4fNormal3fVertex3fvSUN (const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glTexCoord2fColor4fNormal3fVertex3fvSUN) (const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
    return ((PFN_glTexCoord2fColor4fNormal3fVertex3fvSUN)__blue_glCore_glTexCoord2fColor4fNormal3fVertex3fvSUN)(tc, c, n, v);
}

extern void* __blue_glCore_glTexCoord4fColor4fNormal3fVertex4fSUN;
void APIENTRY bluegl_glTexCoord4fColor4fNormal3fVertex4fSUN (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    typedef void (APIENTRYP PFN_glTexCoord4fColor4fNormal3fVertex4fSUN) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    return ((PFN_glTexCoord4fColor4fNormal3fVertex4fSUN)__blue_glCore_glTexCoord4fColor4fNormal3fVertex4fSUN)(s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w);
}

extern void* __blue_glCore_glTexCoord4fColor4fNormal3fVertex4fvSUN;
void APIENTRY bluegl_glTexCoord4fColor4fNormal3fVertex4fvSUN (const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glTexCoord4fColor4fNormal3fVertex4fvSUN) (const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
    return ((PFN_glTexCoord4fColor4fNormal3fVertex4fvSUN)__blue_glCore_glTexCoord4fColor4fNormal3fVertex4fvSUN)(tc, c, n, v);
}

extern void* __blue_glCore_glReplacementCodeuiVertex3fSUN;
void APIENTRY bluegl_glReplacementCodeuiVertex3fSUN (GLuint rc, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiVertex3fSUN) (GLuint rc, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glReplacementCodeuiVertex3fSUN)__blue_glCore_glReplacementCodeuiVertex3fSUN)(rc, x, y, z);
}

extern void* __blue_glCore_glReplacementCodeuiVertex3fvSUN;
void APIENTRY bluegl_glReplacementCodeuiVertex3fvSUN (const GLuint *rc, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiVertex3fvSUN) (const GLuint *rc, const GLfloat *v);
    return ((PFN_glReplacementCodeuiVertex3fvSUN)__blue_glCore_glReplacementCodeuiVertex3fvSUN)(rc, v);
}

extern void* __blue_glCore_glReplacementCodeuiColor4ubVertex3fSUN;
void APIENTRY bluegl_glReplacementCodeuiColor4ubVertex3fSUN (GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiColor4ubVertex3fSUN) (GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glReplacementCodeuiColor4ubVertex3fSUN)__blue_glCore_glReplacementCodeuiColor4ubVertex3fSUN)(rc, r, g, b, a, x, y, z);
}

extern void* __blue_glCore_glReplacementCodeuiColor4ubVertex3fvSUN;
void APIENTRY bluegl_glReplacementCodeuiColor4ubVertex3fvSUN (const GLuint *rc, const GLubyte *c, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiColor4ubVertex3fvSUN) (const GLuint *rc, const GLubyte *c, const GLfloat *v);
    return ((PFN_glReplacementCodeuiColor4ubVertex3fvSUN)__blue_glCore_glReplacementCodeuiColor4ubVertex3fvSUN)(rc, c, v);
}

extern void* __blue_glCore_glReplacementCodeuiColor3fVertex3fSUN;
void APIENTRY bluegl_glReplacementCodeuiColor3fVertex3fSUN (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiColor3fVertex3fSUN) (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glReplacementCodeuiColor3fVertex3fSUN)__blue_glCore_glReplacementCodeuiColor3fVertex3fSUN)(rc, r, g, b, x, y, z);
}

extern void* __blue_glCore_glReplacementCodeuiColor3fVertex3fvSUN;
void APIENTRY bluegl_glReplacementCodeuiColor3fVertex3fvSUN (const GLuint *rc, const GLfloat *c, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiColor3fVertex3fvSUN) (const GLuint *rc, const GLfloat *c, const GLfloat *v);
    return ((PFN_glReplacementCodeuiColor3fVertex3fvSUN)__blue_glCore_glReplacementCodeuiColor3fVertex3fvSUN)(rc, c, v);
}

extern void* __blue_glCore_glReplacementCodeuiNormal3fVertex3fSUN;
void APIENTRY bluegl_glReplacementCodeuiNormal3fVertex3fSUN (GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiNormal3fVertex3fSUN) (GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glReplacementCodeuiNormal3fVertex3fSUN)__blue_glCore_glReplacementCodeuiNormal3fVertex3fSUN)(rc, nx, ny, nz, x, y, z);
}

extern void* __blue_glCore_glReplacementCodeuiNormal3fVertex3fvSUN;
void APIENTRY bluegl_glReplacementCodeuiNormal3fVertex3fvSUN (const GLuint *rc, const GLfloat *n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiNormal3fVertex3fvSUN) (const GLuint *rc, const GLfloat *n, const GLfloat *v);
    return ((PFN_glReplacementCodeuiNormal3fVertex3fvSUN)__blue_glCore_glReplacementCodeuiNormal3fVertex3fvSUN)(rc, n, v);
}

extern void* __blue_glCore_glReplacementCodeuiColor4fNormal3fVertex3fSUN;
void APIENTRY bluegl_glReplacementCodeuiColor4fNormal3fVertex3fSUN (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiColor4fNormal3fVertex3fSUN) (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glReplacementCodeuiColor4fNormal3fVertex3fSUN)__blue_glCore_glReplacementCodeuiColor4fNormal3fVertex3fSUN)(rc, r, g, b, a, nx, ny, nz, x, y, z);
}

extern void* __blue_glCore_glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
void APIENTRY bluegl_glReplacementCodeuiColor4fNormal3fVertex3fvSUN (const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiColor4fNormal3fVertex3fvSUN) (const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
    return ((PFN_glReplacementCodeuiColor4fNormal3fVertex3fvSUN)__blue_glCore_glReplacementCodeuiColor4fNormal3fVertex3fvSUN)(rc, c, n, v);
}

extern void* __blue_glCore_glReplacementCodeuiTexCoord2fVertex3fSUN;
void APIENTRY bluegl_glReplacementCodeuiTexCoord2fVertex3fSUN (GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiTexCoord2fVertex3fSUN) (GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glReplacementCodeuiTexCoord2fVertex3fSUN)__blue_glCore_glReplacementCodeuiTexCoord2fVertex3fSUN)(rc, s, t, x, y, z);
}

extern void* __blue_glCore_glReplacementCodeuiTexCoord2fVertex3fvSUN;
void APIENTRY bluegl_glReplacementCodeuiTexCoord2fVertex3fvSUN (const GLuint *rc, const GLfloat *tc, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiTexCoord2fVertex3fvSUN) (const GLuint *rc, const GLfloat *tc, const GLfloat *v);
    return ((PFN_glReplacementCodeuiTexCoord2fVertex3fvSUN)__blue_glCore_glReplacementCodeuiTexCoord2fVertex3fvSUN)(rc, tc, v);
}

extern void* __blue_glCore_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
void APIENTRY bluegl_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN (GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN) (GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)__blue_glCore_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)(rc, s, t, nx, ny, nz, x, y, z);
}

extern void* __blue_glCore_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
void APIENTRY bluegl_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN (const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN) (const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v);
    return ((PFN_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)__blue_glCore_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)(rc, tc, n, v);
}

extern void* __blue_glCore_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
void APIENTRY bluegl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN (GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN) (GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
    return ((PFN_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)__blue_glCore_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)(rc, s, t, r, g, b, a, nx, ny, nz, x, y, z);
}

extern void* __blue_glCore_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
void APIENTRY bluegl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN (const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v) {
    typedef void (APIENTRYP PFN_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN) (const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
    return ((PFN_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)__blue_glCore_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)(rc, tc, c, n, v);
}

#ifdef __cplusplus
}
#endif

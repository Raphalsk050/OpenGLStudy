
#ifndef TNT_FILAMENT_BACKEND_OPENGLBLOBCACHE_H
#define TNT_FILAMENT_BACKEND_OPENGLBLOBCACHE_H

#include "gl_headers.h"

#include "BlobCacheKey.h"

namespace filament::backend {

class Platform;
class Program;
class OpenGLContext;

class OpenGLBlobCache {
public:
    explicit OpenGLBlobCache(OpenGLContext& gl) noexcept;

    GLuint retrieve(BlobCacheKey* key, Platform& platform,
            Program const& program) const noexcept;

    void insert(Platform& platform,
            BlobCacheKey const& key, GLuint program) noexcept;

private:
    struct Blob;
    bool mCachingSupported = false;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_OPENGLBLOBCACHE_H

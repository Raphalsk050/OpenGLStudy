
#ifndef TNT_FILAMENT_DRIVER_METALUTILS_H
#define TNT_FILAMENT_DRIVER_METALUTILS_H

#include <Metal/Metal.h>

namespace filament::backend {

API_AVAILABLE(ios(13.0))
id<MTLTexture> createTextureViewWithSwizzle(id<MTLTexture> texture,
        MTLTextureSwizzleChannels swizzle);

id<MTLTexture> createTextureViewWithLodRange(id<MTLTexture> texture, NSUInteger lodMin,
        NSUInteger lodMax);

id<MTLTexture> createTextureViewWithSingleSlice(id<MTLTexture> texture, NSUInteger slice);

} // namespace filament::backend

#endif //TNT_FILAMENT_DRIVER_METALUTILS_H


#ifndef TNT_FILAMENT_FG_FRAMEGRAPHTEXTURE_H
#define TNT_FILAMENT_FG_FRAMEGRAPHTEXTURE_H

#include "fg/FrameGraphId.h"

#include <backend/DriverEnums.h>
#include <backend/Handle.h>

namespace filament {
class ResourceAllocatorInterface;
} // namespace::filament

namespace filament {

struct FrameGraphTexture {
    backend::Handle<backend::HwTexture> handle;

    struct SubResourceDescriptor {
        uint8_t level = 0;      // resource's mip level
        uint8_t layer = 0;      // resource's layer or face
    };

    void create(ResourceAllocatorInterface& resourceAllocator, const char* name,
            Descriptor const& descriptor, Usage usage, bool useProtectedMemory) noexcept;

    void destroy(ResourceAllocatorInterface& resourceAllocator) noexcept;

    static Descriptor generateSubResourceDescriptor(Descriptor descriptor,
            SubResourceDescriptor const& srd) noexcept;
};

} // namespace filament

#endif // TNT_FILAMENT_FG_FRAMEGRAPHTEXTURE_H

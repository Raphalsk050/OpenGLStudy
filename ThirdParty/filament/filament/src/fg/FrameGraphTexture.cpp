
#include "fg/FrameGraphTexture.h"

#include "ResourceAllocator.h"

#include <algorithm>

namespace filament {

void FrameGraphTexture::create(ResourceAllocatorInterface& resourceAllocator, const char* name,
        FrameGraphTexture::Descriptor const& descriptor, FrameGraphTexture::Usage usage,
        bool useProtectedMemory) noexcept {
    if (useProtectedMemory) {
        // FIXME: I think we should restrict this to attachments and blit destinations only
        usage |= FrameGraphTexture::Usage::PROTECTED;
    }
    std::array<backend::TextureSwizzle, 4> swizzle = {
            descriptor.swizzle.r,
            descriptor.swizzle.g,
            descriptor.swizzle.b,
            descriptor.swizzle.a };
    handle = resourceAllocator.createTexture(name,
            descriptor.type, descriptor.levels, descriptor.format, descriptor.samples,
            descriptor.width, descriptor.height, descriptor.depth,
            swizzle, usage);
}

void FrameGraphTexture::destroy(ResourceAllocatorInterface& resourceAllocator) noexcept {
    if (handle) {
        resourceAllocator.destroyTexture(handle);
        handle.clear();
    }
}

FrameGraphTexture::Descriptor FrameGraphTexture::generateSubResourceDescriptor(
        Descriptor descriptor,
        SubResourceDescriptor const& srd) noexcept {
    descriptor.levels = 1;
    descriptor.width  = std::max(1u, descriptor.width >> srd.level);
    descriptor.height = std::max(1u, descriptor.height >> srd.level);
    return descriptor;
}

} // namespace filament

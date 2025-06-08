
#ifndef TNT_METALBLITTER_H
#define TNT_METALBLITTER_H

#include <Metal/Metal.h>

#include <backend/DriverEnums.h>

#include "robin_map/include/tsl/robin_map.h"
#include "third_party/filament/libs/utils/include/utils/Hash.h"

namespace filament::backend {

struct MetalContext;

class MetalBlitter {

public:

    explicit MetalBlitter(MetalContext& context) noexcept;

    struct BlitArgs {
        struct Attachment {
            id<MTLTexture> texture = nil;
            MTLRegion region = {};
            uint8_t level = 0;
            uint32_t slice = 0;      // must be 0 on source attachment
        };

        // Valid source formats:       2D, 2DArray, 2DMultisample, 3D
        // Valid destination formats:  2D, 2DArray, 3D, Cube
        Attachment source;
        Attachment destination;
        SamplerMagFilter filter;

        bool destinationIsFullAttachment() const {
            return destination.texture.width == destination.region.size.width &&
                   destination.texture.height == destination.region.size.height;
        }
    };

    void blit(id<MTLCommandBuffer> cmdBuffer, const BlitArgs& args, const char* label);

    void shutdown() noexcept;

private:

    static void setupAttachment(MTLRenderPassAttachmentDescriptor* descriptor,
            const BlitArgs& args, uint32_t depthPlane);

    struct BlitFunctionKey {
        bool msaaColorSource{};
        bool sources3D{};
        char padding[2]{};

        bool isValid() const noexcept {
            // MSAA 3D textures do not exist.
            bool const hasMsaa = msaaColorSource;
            return !(hasMsaa && sources3D);
        }

        bool operator==(const BlitFunctionKey& rhs) const noexcept {
            return msaaColorSource == rhs.msaaColorSource &&
                   sources3D == rhs.sources3D;
        }
    };

    static bool blitFastPath(id<MTLCommandBuffer> cmdBuffer,
            const BlitArgs& args, const char* label);

    void blitSlowPath(id<MTLCommandBuffer> cmdBuffer,
            const BlitArgs& args, const char* label);

    void blitDepthPlane(id <MTLCommandBuffer> cmdBuffer, const BlitArgs& args,
            uint32_t depthPlaneSource, uint32_t depthPlaneDest, const char* label);

    id<MTLFunction> compileFragmentFunction(BlitFunctionKey key) const;
    id<MTLFunction> getBlitVertexFunction();
    id<MTLFunction> getBlitFragmentFunction(BlitFunctionKey key);

    MetalContext& mContext;

    using HashFn = utils::hash::MurmurHashFn<BlitFunctionKey>;
    using Function = id<MTLFunction>;
    tsl::robin_map<BlitFunctionKey, Function, HashFn> mBlitFunctions;

    id<MTLFunction> mVertexFunction = nil;
};

} // namespace filament::backend


#endif //TNT_METALBLITTER_H

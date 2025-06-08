
#ifndef TNT_FILAMENT_FG_FRAMEGRAPHRENDERPASS_H
#define TNT_FILAMENT_FG_FRAMEGRAPHRENDERPASS_H

#include "fg/FrameGraphTexture.h"

#include <backend/DriverEnums.h>
#include <backend/TargetBufferInfo.h>

#include <filament/Viewport.h>

namespace filament {

struct FrameGraphRenderPass {
    static constexpr size_t ATTACHMENT_COUNT = backend::MRT::MAX_SUPPORTED_RENDER_TARGET_COUNT + 2;
    struct Attachments {
        union {
            FrameGraphId<FrameGraphTexture> array[ATTACHMENT_COUNT] = {};
            struct {
                FrameGraphId<FrameGraphTexture> color[backend::MRT::MAX_SUPPORTED_RENDER_TARGET_COUNT];
                FrameGraphId<FrameGraphTexture> depth;
                FrameGraphId<FrameGraphTexture> stencil;
            };
        };
    };

    struct Descriptor {
        Attachments attachments{};
        Viewport viewport{};
        math::float4 clearColor{};
        uint8_t samples = 0;    // # of samples (0 = unset, default)
        uint8_t layerCount = 0; // # of layer (# > 1 = multiview)
        backend::TargetBufferFlags clearFlags{};
        backend::TargetBufferFlags discardStart{};
    };

    struct ImportDescriptor {
        backend::TargetBufferFlags attachments = backend::TargetBufferFlags::COLOR0;
        Viewport viewport{};
        math::float4 clearColor{};  // this overrides Descriptor::clearColor
        uint8_t samples = 0;        // # of samples (0 = unset, default)
        backend::TargetBufferFlags clearFlags{}; // this overrides Descriptor::clearFlags
        backend::TargetBufferFlags keepOverrideStart{};
        backend::TargetBufferFlags keepOverrideEnd{};
    };

    uint32_t id = 0;
};

} // namespace filament

#endif // TNT_FILAMENT_FG_FRAMEGRAPHRENDERPASS_H

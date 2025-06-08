
#ifndef TNT_FILAMENT_PERSHADOWMAPUNIFORMS_H
#define TNT_FILAMENT_PERSHADOWMAPUNIFORMS_H

#include <private/filament/UibStructs.h>

#include <backend/DriverApiForward.h>
#include <backend/DriverEnums.h>
#include <backend/Handle.h>

#include "third_party/filament/libs/math/include/math/vec4.h"

namespace filament {

struct CameraInfo;

class FEngine;
class LightManager;

class PerShadowMapUniforms {

public:
    class Transaction {
        friend PerShadowMapUniforms;
        PerViewUib* uniforms = nullptr;
        Transaction() = default; // disallow creation by the caller
    };

    explicit PerShadowMapUniforms(FEngine& engine) noexcept;

    void terminate(backend::DriverApi& driver);

    static void prepareCamera(Transaction const& transaction,
            FEngine& engine, const CameraInfo& camera) noexcept;

    static void prepareLodBias(Transaction const& transaction,
            float bias) noexcept;

    static void prepareViewport(Transaction const& transaction,
            backend::Viewport const& viewport) noexcept;

    static void prepareTime(Transaction const& transaction,
            FEngine& engine, math::float4 const& userTime) noexcept;

    static void prepareShadowMapping(Transaction const& transaction,
            bool highPrecision) noexcept;

    static Transaction open(backend::DriverApi& driver) noexcept;

    // update local data into GPU UBO
    void commit(Transaction& transaction, backend::DriverApi& driver) noexcept;

    // bind this UBO
    void bind(backend::DriverApi& driver) noexcept;

private:
    static PerViewUib& edit(Transaction const& transaction) noexcept;
    backend::Handle<backend::HwBufferObject> mUniformBufferHandle;
};

} // namespace filament

#endif //TNT_FILAMENT_PERSHADOWMAPUNIFORMS_H

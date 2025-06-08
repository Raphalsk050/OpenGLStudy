
#ifndef TNT_IBL_PREFILTER_IBLPREFILTER_H
#define TNT_IBL_PREFILTER_IBLPREFILTER_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Entity.h"

#include <filament/Texture.h>

namespace filament {
class Engine;
class View;
class Scene;
class Renderer;
class Material;
class MaterialInstance;
class VertexBuffer;
class IndexBuffer;
class Camera;
class Texture;
} // namespace filament

class UTILS_PUBLIC IBLPrefilterContext {
public:

    enum class Kernel : uint8_t {
        D_GGX,        // Trowbridge-reitz distribution
    };

    explicit IBLPrefilterContext(filament::Engine& engine);

    ~IBLPrefilterContext() noexcept;

    // not copyable
    IBLPrefilterContext(IBLPrefilterContext const&) = delete;
    IBLPrefilterContext& operator=(IBLPrefilterContext const&) = delete;

    // movable
    IBLPrefilterContext(IBLPrefilterContext&& rhs) noexcept;
    IBLPrefilterContext& operator=(IBLPrefilterContext&& rhs) noexcept;

    // -------------------------------------------------------------------------------------------

    class EquirectangularToCubemap {
    public:

        struct Config {
            bool mirror = true;  //!< mirror the source horizontally
        };

        explicit EquirectangularToCubemap(IBLPrefilterContext& context);

       EquirectangularToCubemap(IBLPrefilterContext& context, Config const& config);

        ~EquirectangularToCubemap() noexcept;

        EquirectangularToCubemap(EquirectangularToCubemap const&) = delete;
        EquirectangularToCubemap& operator=(EquirectangularToCubemap const&) = delete;
        EquirectangularToCubemap(EquirectangularToCubemap&& rhs) noexcept;
        EquirectangularToCubemap& operator=(EquirectangularToCubemap&& rhs) noexcept;

        filament::Texture* operator()(
                filament::Texture const* equirectangular,
                filament::Texture* outCubemap = nullptr);

    private:
        IBLPrefilterContext& mContext;
        filament::Material* mEquirectMaterial = nullptr;
        Config mConfig{};
    };

    class IrradianceFilter {
    public:
        using Kernel = Kernel;

        struct Config {
            uint16_t sampleCount = 1024u;   //!< filter sample count (max 2048)
            Kernel kernel = Kernel::D_GGX;  //!< filter kernel
        };

        struct Options {
            float hdrLinear = 1024.0f;   //!< no HDR compression up to this value
            float hdrMax = 16384.0f;     //!< HDR compression between hdrLinear and hdrMax
            float lodOffset = 2.0f;      //!< Good values are 2.0 or 3.0. Higher values help with heavily HDR inputs.
            bool generateMipmap = true;  //!< set to false if the input environment map already has mipmaps
        };

        IrradianceFilter(IBLPrefilterContext& context, Config config);

        explicit IrradianceFilter(IBLPrefilterContext& context);

        ~IrradianceFilter() noexcept;

        IrradianceFilter(IrradianceFilter const&) = delete;
        IrradianceFilter& operator=(IrradianceFilter const&) = delete;
        IrradianceFilter(IrradianceFilter&& rhs) noexcept;
        IrradianceFilter& operator=(IrradianceFilter&& rhs) noexcept;

        filament::Texture* operator()(Options options,
                filament::Texture const* environmentCubemap,
                filament::Texture* outIrradianceTexture = nullptr);

        filament::Texture* operator()(
                filament::Texture const* environmentCubemap,
                filament::Texture* outIrradianceTexture = nullptr);

    private:
        filament::Texture* createIrradianceTexture();
        IBLPrefilterContext& mContext;
        filament::Material* mKernelMaterial = nullptr;
        filament::Texture* mKernelTexture = nullptr;
        uint32_t mSampleCount = 0u;
    };

    class SpecularFilter {
    public:
        using Kernel = Kernel;

        struct Config {
            uint16_t sampleCount = 1024u;   //!< filter sample count (max 2048)
            uint8_t levelCount = 5u;        //!< number of roughness levels
            Kernel kernel = Kernel::D_GGX;  //!< filter kernel
        };

        struct Options {
            float hdrLinear = 1024.0f;   //!< no HDR compression up to this value
            float hdrMax = 16384.0f;     //!< HDR compression between hdrLinear and hdrMax
            float lodOffset = 1.0f;      //!< Good values are 1.0 or 2.0. Higher values help with heavily HDR inputs.
            bool generateMipmap = true;  //!< set to false if the input environment map already has mipmaps
        };

        SpecularFilter(IBLPrefilterContext& context, Config config);

        explicit SpecularFilter(IBLPrefilterContext& context);

        ~SpecularFilter() noexcept;

        SpecularFilter(SpecularFilter const&) = delete;
        SpecularFilter& operator=(SpecularFilter const&) = delete;
        SpecularFilter(SpecularFilter&& rhs) noexcept;
        SpecularFilter& operator=(SpecularFilter&& rhs) noexcept;

        filament::Texture* operator()(Options options,
                filament::Texture const* environmentCubemap,
                filament::Texture* outReflectionsTexture = nullptr);

        filament::Texture* operator()(
                filament::Texture const* environmentCubemap,
                filament::Texture* outReflectionsTexture = nullptr);

        // TODO: option for progressive filtering

        // TODO: add a callback for when the processing is done?

    private:
        filament::Texture* createReflectionsTexture();
        IBLPrefilterContext& mContext;
        filament::Material* mKernelMaterial = nullptr;
        filament::Texture* mKernelTexture = nullptr;
        uint32_t mSampleCount = 0u;
        uint8_t mLevelCount = 1u;
    };

private:
    friend class Filter;
    filament::Engine& mEngine;
    filament::Renderer* mRenderer{};
    filament::Scene* mScene{};
    filament::VertexBuffer* mVertexBuffer{};
    filament::IndexBuffer* mIndexBuffer{};
    filament::Camera* mCamera{};
    utils::Entity mFullScreenQuadEntity{};
    utils::Entity mCameraEntity{};
    filament::View* mView{};
    filament::Material* mIntegrationMaterial{};
    filament::Material* mIrradianceIntegrationMaterial{};
};

#endif //TNT_IBL_PREFILTER_IBLPREFILTER_H

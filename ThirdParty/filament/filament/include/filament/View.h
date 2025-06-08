
//! \file

#ifndef TNT_FILAMENT_VIEW_H
#define TNT_FILAMENT_VIEW_H

#include <filament/FilamentAPI.h>
#include <filament/Options.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Entity.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <utility>

#include <stddef.h>
#include <stdint.h>

namespace filament {

namespace backend {
class CallbackHandler;
} // namespace backend

class Camera;
class ColorGrading;
class MaterialInstance;
class RenderTarget;
class Scene;
class Viewport;

class UTILS_PUBLIC View : public FilamentAPI {
public:
    using QualityLevel = filament::QualityLevel;
    using BlendMode = filament::BlendMode;
    using AntiAliasing = filament::AntiAliasing;
    using Dithering = filament::Dithering;
    using ShadowType = filament::ShadowType;

    using DynamicResolutionOptions = filament::DynamicResolutionOptions;
    using BloomOptions = filament::BloomOptions;
    using FogOptions = filament::FogOptions;
    using DepthOfFieldOptions = filament::DepthOfFieldOptions;
    using VignetteOptions = filament::VignetteOptions;
    using RenderQuality = filament::RenderQuality;
    using AmbientOcclusionOptions = filament::AmbientOcclusionOptions;
    using TemporalAntiAliasingOptions = filament::TemporalAntiAliasingOptions;
    using MultiSampleAntiAliasingOptions = filament::MultiSampleAntiAliasingOptions;
    using VsmShadowOptions = filament::VsmShadowOptions;
    using SoftShadowOptions = filament::SoftShadowOptions;
    using ScreenSpaceReflectionsOptions = filament::ScreenSpaceReflectionsOptions;
    using GuardBandOptions = filament::GuardBandOptions;
    using StereoscopicOptions = filament::StereoscopicOptions;

    void setName(const char* UTILS_NONNULL name) noexcept;

    const char* UTILS_NULLABLE getName() const noexcept;

    void setScene(Scene* UTILS_NULLABLE scene);

    Scene* UTILS_NULLABLE getScene() noexcept;

    Scene const* UTILS_NULLABLE getScene() const noexcept {
        return const_cast<View*>(this)->getScene();
    }

    void setRenderTarget(RenderTarget* UTILS_NULLABLE renderTarget) noexcept;

    RenderTarget* UTILS_NULLABLE getRenderTarget() const noexcept;

    void setViewport(Viewport const& viewport) noexcept;

    Viewport const& getViewport() const noexcept;

    void setCamera(Camera* UTILS_NONNULL camera) noexcept;

    bool hasCamera() const noexcept;

    Camera& getCamera() noexcept;

    Camera const& getCamera() const noexcept {
        return const_cast<View*>(this)->getCamera();
    }

    void setBlendMode(BlendMode blendMode) noexcept;

    BlendMode getBlendMode() const noexcept;

    void setVisibleLayers(uint8_t select, uint8_t values) noexcept;

    inline void setLayerEnabled(size_t layer, bool enabled) noexcept {
        const uint8_t mask = 1u << layer;
        setVisibleLayers(mask, enabled ? mask : 0);
    }

    uint8_t getVisibleLayers() const noexcept;

    void setShadowingEnabled(bool enabled) noexcept;

    bool isShadowingEnabled() const noexcept;

    void setScreenSpaceRefractionEnabled(bool enabled) noexcept;

    bool isScreenSpaceRefractionEnabled() const noexcept;

    UTILS_DEPRECATED
    void setSampleCount(uint8_t count = 1) noexcept;

    UTILS_DEPRECATED
    uint8_t getSampleCount() const noexcept;

    void setAntiAliasing(AntiAliasing type) noexcept;

    AntiAliasing getAntiAliasing() const noexcept;

    void setTemporalAntiAliasingOptions(TemporalAntiAliasingOptions options) noexcept;

    TemporalAntiAliasingOptions const& getTemporalAntiAliasingOptions() const noexcept;

    void setScreenSpaceReflectionsOptions(ScreenSpaceReflectionsOptions options) noexcept;

    ScreenSpaceReflectionsOptions const& getScreenSpaceReflectionsOptions() const noexcept;

    void setGuardBandOptions(GuardBandOptions options) noexcept;

    GuardBandOptions const& getGuardBandOptions() const noexcept;

    void setMultiSampleAntiAliasingOptions(MultiSampleAntiAliasingOptions options) noexcept;

    MultiSampleAntiAliasingOptions const& getMultiSampleAntiAliasingOptions() const noexcept;

    void setColorGrading(ColorGrading* UTILS_NULLABLE colorGrading) noexcept;

    const ColorGrading* UTILS_NULLABLE getColorGrading() const noexcept;

    void setAmbientOcclusionOptions(AmbientOcclusionOptions const& options) noexcept;

    AmbientOcclusionOptions const& getAmbientOcclusionOptions() const noexcept;

    void setBloomOptions(BloomOptions options) noexcept;

    BloomOptions getBloomOptions() const noexcept;

    void setFogOptions(FogOptions options) noexcept;

    FogOptions getFogOptions() const noexcept;

    void setDepthOfFieldOptions(DepthOfFieldOptions options) noexcept;

    DepthOfFieldOptions getDepthOfFieldOptions() const noexcept;

    void setVignetteOptions(VignetteOptions options) noexcept;

    VignetteOptions getVignetteOptions() const noexcept;

    void setDithering(Dithering dithering) noexcept;

    Dithering getDithering() const noexcept;

    void setDynamicResolutionOptions(DynamicResolutionOptions const& options) noexcept;

    DynamicResolutionOptions getDynamicResolutionOptions() const noexcept;

    void setRenderQuality(RenderQuality const& renderQuality) noexcept;

    RenderQuality getRenderQuality() const noexcept;

    void setDynamicLightingOptions(float zLightNear, float zLightFar) noexcept;

    void setShadowType(ShadowType shadow) noexcept;

    void setVsmShadowOptions(VsmShadowOptions const& options) noexcept;

    VsmShadowOptions getVsmShadowOptions() const noexcept;

    void setSoftShadowOptions(SoftShadowOptions const& options) noexcept;

    SoftShadowOptions getSoftShadowOptions() const noexcept;

    void setPostProcessingEnabled(bool enabled) noexcept;

    //! Returns true if post-processing is enabled. See setPostProcessingEnabled() for more info.
    bool isPostProcessingEnabled() const noexcept;

    void setFrontFaceWindingInverted(bool inverted) noexcept;

    bool isFrontFaceWindingInverted() const noexcept;

    void setStencilBufferEnabled(bool enabled) noexcept;

    bool isStencilBufferEnabled() const noexcept;

    void setStereoscopicOptions(StereoscopicOptions const& options) noexcept;

    StereoscopicOptions const& getStereoscopicOptions() const noexcept;

    // for debugging...

    //! debugging: allows to entirely disable frustum culling. (culling enabled by default).
    void setFrustumCullingEnabled(bool culling) noexcept;

    //! debugging: returns whether frustum culling is enabled.
    bool isFrustumCullingEnabled() const noexcept;

    //! debugging: sets the Camera used for rendering. It may be different from the culling camera.
    void setDebugCamera(Camera* UTILS_NULLABLE camera) noexcept;

    //! debugging: returns a Camera from the point of view of *the* dominant directional light used for shadowing.
    Camera const* UTILS_NULLABLE getDirectionalShadowCamera() const noexcept;


        math::float3 fragCoords;        //! screen space coordinates in GL convention
    };

    using PickingQueryResultCallback =
            void(*)(PickingQueryResult const& result, PickingQuery* UTILS_NONNULL pq);

    template<typename T, void(T::*method)(PickingQueryResult const&)>
    void pick(uint32_t x, uint32_t y, T* UTILS_NONNULL instance,
            backend::CallbackHandler* UTILS_NULLABLE handler = nullptr) noexcept {
        PickingQuery& query = pick(x, y, [](PickingQueryResult const& result, PickingQuery* pq) {
            (static_cast<T*>(pq->storage[0])->*method)(result);
        }, handler);
        query.storage[0] = instance;
    }

    template<typename T, void(T::*method)(PickingQueryResult const&)>
    void pick(uint32_t x, uint32_t y, T instance,
            backend::CallbackHandler* UTILS_NULLABLE handler = nullptr) noexcept {
        static_assert(sizeof(instance) <= sizeof(PickingQuery::storage), "user data too large");
        PickingQuery& query = pick(x, y, [](PickingQueryResult const& result, PickingQuery* pq) {
            T* const that = static_cast<T*>(reinterpret_cast<void*>(pq->storage));
            (that->*method)(result);
            that->~T();
        }, handler);
        new(query.storage) T(std::move(instance));
    }

    template<typename T>
    void pick(uint32_t x, uint32_t y, T functor,
            backend::CallbackHandler* UTILS_NULLABLE handler = nullptr) noexcept {
        static_assert(sizeof(functor) <= sizeof(PickingQuery::storage), "functor too large");
        PickingQuery& query = pick(x, y, handler,
                (PickingQueryResultCallback)[](PickingQueryResult const& result, PickingQuery* pq) {
                    T* const that = static_cast<T*>(reinterpret_cast<void*>(pq->storage));
                    that->operator()(result);
                    that->~T();
                });
        new(query.storage) T(std::move(functor));
    }

    PickingQuery& pick(uint32_t x, uint32_t y,
            backend::CallbackHandler* UTILS_NULLABLE handler,
            PickingQueryResultCallback UTILS_NONNULL callback) noexcept;

    void setMaterialGlobal(uint32_t index, math::float4 const& value);

    math::float4 getMaterialGlobal(uint32_t index) const;

    utils::Entity getFogEntity() const noexcept;

    enum class UTILS_DEPRECATED AmbientOcclusion : uint8_t {
        NONE = 0,       //!< No Ambient Occlusion
        SSAO = 1        //!< Basic, sampling SSAO
    };

    UTILS_DEPRECATED
    void setAmbientOcclusion(AmbientOcclusion ambientOcclusion) noexcept;

    UTILS_DEPRECATED
    AmbientOcclusion getAmbientOcclusion() const noexcept;

protected:
    // prevent heap allocation
    ~View() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_VIEW_H

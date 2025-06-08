
#ifndef TNT_FILAMENT_LIGHTMANAGER_H
#define TNT_FILAMENT_LIGHTMANAGER_H

#include <filament/FilamentAPI.h>
#include <filament/Color.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Entity.h"
#include "third_party/filament/libs/utils/include/utils/EntityInstance.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"
#include "third_party/filament/libs/math/include/math/quat.h"

#include <stdint.h>
#include <stddef.h>

namespace utils {
    class Entity;
} // namespace utils

namespace filament {

class Engine;
class FEngine;
class FLightManager;

class UTILS_PUBLIC LightManager : public FilamentAPI {
    struct BuilderDetails;

public:
    using Instance = utils::EntityInstance<LightManager>;

    size_t getComponentCount() const noexcept;

    bool hasComponent(utils::Entity e) const noexcept;

    bool empty() const noexcept;

    utils::Entity getEntity(Instance i) const noexcept;

    utils::Entity const* UTILS_NONNULL getEntities() const noexcept;

    Instance getInstance(utils::Entity e) const noexcept;

    // destroys this component from the given entity
    void destroy(utils::Entity e) noexcept;


    //! Denotes the type of the light being created.
    enum class Type : uint8_t {
        SUN,            //!< Directional light that also draws a sun's disk in the sky.
        DIRECTIONAL,    //!< Directional light, emits light in a given direction.
        POINT,          //!< Point light, emits light from a position, in all directions.
        FOCUSED_SPOT,   //!< Physically correct spot light.
        SPOT,           //!< Spot light with coupling of outer cone and illumination disabled.
    };

    struct ShadowOptions {
        uint8_t shadowCascades = 1;

        float cascadeSplitPositions[3] = { 0.125f, 0.25f, 0.50f };

        float constantBias = 0.001f;

        float normalBias = 1.0f;

        float shadowFar = 0.0f;

        float shadowNearHint = 1.0f;

        float shadowFarHint = 100.0f;

        bool stable = false;

        bool lispsm = true;

        float polygonOffsetConstant = 0.5f;

        float polygonOffsetSlope = 2.0f;

        bool screenSpaceContactShadows = false;

        uint8_t stepCount = 8;

        float maxShadowDistance = 0.3f;

        struct Vsm {
            bool elvsm = false;

            float blurWidth = 0.0f;
        } vsm;

        float shadowBulbRadius = 0.02f;

        math::quatf transform{ 1.0f };
    };

    struct ShadowCascades {
        static void computeUniformSplits(float* UTILS_NONNULL splitPositions, uint8_t cascades);

        static void computeLogSplits(float* UTILS_NONNULL splitPositions, uint8_t cascades,
                float near, float far);

        static void computePracticalSplits(float* UTILS_NONNULL splitPositions, uint8_t cascades,
                float near, float far, float lambda);
    };

    //! Use Builder to construct a Light object instance
    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        explicit Builder(Type type) noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& lightChannel(unsigned int channel, bool enable = true) noexcept;

        Builder& castShadows(bool enable) noexcept;

        Builder& shadowOptions(const ShadowOptions& options) noexcept;

        Builder& castLight(bool enable) noexcept;

        Builder& position(const math::float3& position) noexcept;

        Builder& direction(const math::float3& direction) noexcept;

        Builder& color(const LinearColor& color) noexcept;

        Builder& intensity(float intensity) noexcept;

        Builder& intensityCandela(float intensity) noexcept;

        Builder& intensity(float watts, float efficiency) noexcept;

        Builder& falloff(float radius) noexcept;

        Builder& spotLightCone(float inner, float outer) noexcept;

        Builder& sunAngularRadius(float angularRadius) noexcept;

        Builder& sunHaloSize(float haloSize) noexcept;

        Builder& sunHaloFalloff(float haloFalloff) noexcept;

        enum Result { Error = -1, Success = 0  };

        Result build(Engine& engine, utils::Entity entity);

    private:
        friend class FEngine;
        friend class FLightManager;
    };

    static constexpr float EFFICIENCY_INCANDESCENT = 0.0220f;   //!< Typical efficiency of an incandescent light bulb (2.2%)
    static constexpr float EFFICIENCY_HALOGEN      = 0.0707f;   //!< Typical efficiency of an halogen light bulb (7.0%)
    static constexpr float EFFICIENCY_FLUORESCENT  = 0.0878f;   //!< Typical efficiency of a fluorescent light bulb (8.7%)
    static constexpr float EFFICIENCY_LED          = 0.1171f;   //!< Typical efficiency of a LED light bulb (11.7%)

    Type getType(Instance i) const noexcept;

    inline bool isDirectional(Instance i) const noexcept {
        Type const type = getType(i);
        return type == Type::DIRECTIONAL || type == Type::SUN;
    }

    inline bool isPointLight(Instance i) const noexcept {
        return getType(i) == Type::POINT;
    }

    inline bool isSpotLight(Instance i) const noexcept {
        Type const type = getType(i);
        return type == Type::SPOT || type == Type::FOCUSED_SPOT;
    }

    void setLightChannel(Instance i, unsigned int channel, bool enable = true) noexcept;

    bool getLightChannel(Instance i, unsigned int channel) const noexcept;

    void setPosition(Instance i, const math::float3& position) noexcept;

    //! returns the light's position in world space
    const math::float3& getPosition(Instance i) const noexcept;

    void setDirection(Instance i, const math::float3& direction) noexcept;

    //! returns the light's direction in world space
    const math::float3& getDirection(Instance i) const noexcept;

    void setColor(Instance i, const LinearColor& color) noexcept;

    const math::float3& getColor(Instance i) const noexcept;

    void setIntensity(Instance i, float intensity) noexcept;

    void setIntensity(Instance i, float watts, float efficiency) noexcept {
        setIntensity(i, watts * 683.0f * efficiency);
    }

    void setIntensityCandela(Instance i, float intensity) noexcept;

    float getIntensity(Instance i) const noexcept;

    void setFalloff(Instance i, float radius) noexcept;

    float getFalloff(Instance i) const noexcept;

    void setSpotLightCone(Instance i, float inner, float outer) noexcept;

    float getSpotLightOuterCone(Instance i) const noexcept;

    float getSpotLightInnerCone(Instance i) const noexcept;

    void setSunAngularRadius(Instance i, float angularRadius) noexcept;

    float getSunAngularRadius(Instance i) const noexcept;

    void setSunHaloSize(Instance i, float haloSize) noexcept;

    float getSunHaloSize(Instance i) const noexcept;

    void setSunHaloFalloff(Instance i, float haloFalloff) noexcept;

    float getSunHaloFalloff(Instance i) const noexcept;

    ShadowOptions const& getShadowOptions(Instance i) const noexcept;

    void setShadowOptions(Instance i, ShadowOptions const& options) noexcept;

    void setShadowCaster(Instance i, bool shadowCaster) noexcept;

    bool isShadowCaster(Instance i) const noexcept;

protected:
    // prevent heap allocation
    ~LightManager() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_LIGHTMANAGER_H

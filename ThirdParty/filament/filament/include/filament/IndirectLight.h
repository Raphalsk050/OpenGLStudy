
//! \file

#ifndef TNT_FILAMENT_INDIRECTLIGHT_H
#define TNT_FILAMENT_INDIRECTLIGHT_H

#include <filament/FilamentAPI.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <stdint.h>

namespace filament {

class Engine;
class Texture;

class FIndirectLight;

class UTILS_PUBLIC IndirectLight : public FilamentAPI {
    struct BuilderDetails;

public:

    //! Use Builder to construct an IndirectLight object instance
    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& reflections(Texture const* UTILS_NULLABLE cubemap) noexcept;

        Builder& irradiance(uint8_t bands, math::float3 const* UTILS_NONNULL sh) noexcept;

        Builder& radiance(uint8_t bands, math::float3 const* UTILS_NONNULL sh) noexcept;

        Builder& irradiance(Texture const* UTILS_NULLABLE cubemap) noexcept;

        Builder& intensity(float envIntensity) noexcept;

        Builder& rotation(math::mat3f const& rotation) noexcept;

        IndirectLight* UTILS_NONNULL build(Engine& engine);

    private:
        friend class FIndirectLight;
    };

    void setIntensity(float intensity) noexcept;

    float getIntensity() const noexcept;

    void setRotation(math::mat3f const& rotation) noexcept;

    const math::mat3f& getRotation() const noexcept;

    Texture const* UTILS_NULLABLE getReflectionsTexture() const noexcept;

    Texture const* UTILS_NULLABLE getIrradianceTexture() const noexcept;

    static math::float3 getDirectionEstimate(const math::float3 sh[UTILS_NONNULL 9]) noexcept;

    static math::float4 getColorEstimate(const math::float3 sh[UTILS_NONNULL 9],
            math::float3 direction) noexcept;


    UTILS_DEPRECATED
    math::float4 getColorEstimate(math::float3 direction) const noexcept;

protected:
    // prevent heap allocation
    ~IndirectLight() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_INDIRECTLIGHT_H

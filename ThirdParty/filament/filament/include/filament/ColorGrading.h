
//! \file

#ifndef TNT_FILAMENT_COLORGRADING_H
#define TNT_FILAMENT_COLORGRADING_H

#include <filament/FilamentAPI.h>
#include <filament/ToneMapper.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <stdint.h>
#include <stddef.h>

namespace filament {

class Engine;
class FColorGrading;

namespace color {
class ColorSpace;
}

class UTILS_PUBLIC ColorGrading : public FilamentAPI {
    struct BuilderDetails;
public:

    enum class QualityLevel : uint8_t {
        LOW,
        MEDIUM,
        HIGH,
        ULTRA
    };

    enum class LutFormat : uint8_t {
        INTEGER,    //!< 10 bits per component
        FLOAT,      //!< 16 bits per component (10 bits mantissa precision)
    };


    enum class UTILS_DEPRECATED ToneMapping : uint8_t {
        LINEAR        = 0,     //!< Linear tone mapping (i.e. no tone mapping)
        ACES_LEGACY   = 1,     //!< ACES tone mapping, with a brightness modifier to match Filament's legacy tone mapper
        ACES          = 2,     //!< ACES tone mapping
        FILMIC        = 3,     //!< Filmic tone mapping, modelled after ACES but applied in sRGB space
        DISPLAY_RANGE = 4,     //!< Tone mapping used to validate/debug scene exposure
    };

    //! Use Builder to construct a ColorGrading object instance
    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& quality(QualityLevel qualityLevel) noexcept;

        Builder& format(LutFormat format) noexcept;

        Builder& dimensions(uint8_t dim) noexcept;

        Builder& toneMapper(ToneMapper const* UTILS_NULLABLE toneMapper) noexcept;

        UTILS_DEPRECATED
        Builder& toneMapping(ToneMapping toneMapping) noexcept;

        Builder& luminanceScaling(bool luminanceScaling) noexcept;

        Builder& gamutMapping(bool gamutMapping) noexcept;

        Builder& exposure(float exposure) noexcept;

        Builder& nightAdaptation(float adaptation) noexcept;

        Builder& whiteBalance(float temperature, float tint) noexcept;

        Builder& channelMixer(
                math::float3 outRed, math::float3 outGreen, math::float3 outBlue) noexcept;

        Builder& shadowsMidtonesHighlights(
                math::float4 shadows, math::float4 midtones, math::float4 highlights,
                math::float4 ranges) noexcept;

        Builder& slopeOffsetPower(math::float3 slope, math::float3 offset, math::float3 power) noexcept;

        Builder& contrast(float contrast) noexcept;

        Builder& vibrance(float vibrance) noexcept;

        Builder& saturation(float saturation) noexcept;

        Builder& curves(math::float3 shadowGamma, math::float3 midPoint, math::float3 highlightScale) noexcept;

        Builder& outputColorSpace(const color::ColorSpace& colorSpace) noexcept;

        ColorGrading* UTILS_NONNULL build(Engine& engine);

    private:
        friend class FColorGrading;
    };

protected:
    // prevent heap allocation
    ~ColorGrading() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_COLORGRADING_H

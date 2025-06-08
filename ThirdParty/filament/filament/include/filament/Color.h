
//! \file

#ifndef TNT_FILAMENT_COLOR_H
#define TNT_FILAMENT_COLOR_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include <stdint.h>
#include <stddef.h>

namespace filament {

//! RGB color in linear space
using LinearColor = math::float3;

//! RGB color in sRGB space
using sRGBColor  = math::float3;

//! RGBA color in linear space, with alpha
using LinearColorA = math::float4;

//! RGBA color in sRGB space, with alpha
using sRGBColorA  = math::float4;

//! types of RGB colors
enum class RgbType : uint8_t {
    sRGB,   //!< the color is defined in Rec.709-sRGB-D65 (sRGB) space
    LINEAR, //!< the color is defined in Rec.709-Linear-D65 ("linear sRGB") space
};

//! types of RGBA colors
enum class RgbaType : uint8_t {
    sRGB,
    LINEAR,
    PREMULTIPLIED_sRGB,
    PREMULTIPLIED_LINEAR
};

//! type of color conversion to use when converting to/from sRGB and linear spaces
enum ColorConversion {
    ACCURATE,   //!< accurate conversion using the sRGB standard
    FAST        //!< fast conversion using a simple gamma 2.2 curve
};

class UTILS_PUBLIC Color {
public:
    //! converts an RGB color to linear space, the conversion depends on the specified type
    static LinearColor toLinear(RgbType type, math::float3 color);

    //! converts an RGBA color to linear space, the conversion depends on the specified type
    static LinearColorA toLinear(RgbaType type, math::float4 color);

    //! converts an RGB color in sRGB space to an RGB color in linear space
    template<ColorConversion = ACCURATE>
    static LinearColor toLinear(sRGBColor const& color);

    template<ColorConversion = ACCURATE>
    static sRGBColor toSRGB(LinearColor const& color);

    template<ColorConversion = ACCURATE>
    static LinearColorA toLinear(sRGBColorA const& color);

    template<ColorConversion = ACCURATE>
    static sRGBColorA toSRGB(LinearColorA const& color);

    static LinearColor cct(float K);

    static LinearColor illuminantD(float K);

    static math::float3 absorptionAtDistance(LinearColor const& color, float distance);

private:
    static math::float3 sRGBToLinear(math::float3 color) noexcept;
    static math::float3 linearToSRGB(math::float3 color) noexcept;
};

// Use the default implementation from the header
template<>
inline LinearColor Color::toLinear<FAST>(sRGBColor const& color) {
    return pow(color, 2.2f);
}

template<>
inline LinearColorA Color::toLinear<FAST>(sRGBColorA const& color) {
    return LinearColorA{pow(color.rgb, 2.2f), color.a};
}

template<>
inline LinearColor Color::toLinear<ACCURATE>(sRGBColor const& color) {
    return sRGBToLinear(color);
}

template<>
inline LinearColorA Color::toLinear<ACCURATE>(sRGBColorA const& color) {
    return LinearColorA{sRGBToLinear(color.rgb), color.a};
}

// Use the default implementation from the header
template<>
inline sRGBColor Color::toSRGB<FAST>(LinearColor const& color) {
    return pow(color, 1.0f / 2.2f);
}

template<>
inline sRGBColorA Color::toSRGB<FAST>(LinearColorA const& color) {
    return sRGBColorA{pow(color.rgb, 1.0f / 2.2f), color.a};
}

template<>
inline sRGBColor Color::toSRGB<ACCURATE>(LinearColor const& color) {
    return linearToSRGB(color);
}

template<>
inline sRGBColorA Color::toSRGB<ACCURATE>(LinearColorA const& color) {
    return sRGBColorA{linearToSRGB(color.rgb), color.a};
}

inline LinearColor Color::toLinear(RgbType type, math::float3 color) {
    return (type == RgbType::LINEAR) ? color : Color::toLinear<ACCURATE>(color);
}

// converts an RGBA color to linear space
// the conversion depends on the specified type
inline LinearColorA Color::toLinear(RgbaType type, math::float4 color) {
    switch (type) {
        case RgbaType::sRGB:
            return Color::toLinear<ACCURATE>(color) * math::float4{color.a, color.a, color.a, 1.0f};
        case RgbaType::LINEAR:
            return color * math::float4{color.a, color.a, color.a, 1.0f};
        case RgbaType::PREMULTIPLIED_sRGB:
            return Color::toLinear<ACCURATE>(color);
        case RgbaType::PREMULTIPLIED_LINEAR:
            return color;
    }
}

} // namespace filament

#endif // TNT_FILAMENT_COLOR_H

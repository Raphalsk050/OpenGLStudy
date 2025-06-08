
#ifndef TNT_FILAMENT_COLOR_SPACE_H
#define TNT_FILAMENT_COLOR_SPACE_H

#include "third_party/filament/libs/math/include/math/vec2.h"

namespace filament::color {

using namespace math;

struct Primaries {
    float2 r;
    float2 g;
    float2 b;

    bool operator==(const Primaries& rhs) const noexcept {
        return r == rhs.r && b == rhs.b && g == rhs.g;
    }
};

//! Reference white for a color space, defined as the xy coordinates in the xyY space.
using WhitePoint = float2;

struct TransferFunction {
    constexpr TransferFunction(
            double a,
            double b,
            double c,
            double d,
            double e,
            double f,
            double g
    ) : a(a),
        b(b),
        c(c),
        d(d),
        e(e),
        f(f),
        g(g) {
    }

    constexpr TransferFunction(
            double a,
            double b,
            double c,
            double d,
            double g
    ) : TransferFunction(a, b, c, d, 0.0, 0.0, g) {
    }

    bool operator==(const TransferFunction& rhs) const noexcept {
        return
                a == rhs.a &&
                b == rhs.b &&
                c == rhs.c &&
                d == rhs.d &&
                e == rhs.e &&
                f == rhs.f &&
                g == rhs.g;
    }

    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    double g;
};

class ColorSpace {
public:
    constexpr ColorSpace(
            const Primaries primaries,
            const TransferFunction transferFunction,
            const WhitePoint whitePoint
    ) : mPrimaries(primaries),
        mTransferFunction(transferFunction),
        mWhitePoint(whitePoint) {
    }

    bool operator==(const ColorSpace& rhs) const noexcept {
        return mPrimaries == rhs.mPrimaries &&
                mTransferFunction == rhs.mTransferFunction &&
                mWhitePoint == rhs.mWhitePoint;
    }

    constexpr const Primaries& getPrimaries() const { return mPrimaries; }
    constexpr const TransferFunction& getTransferFunction() const { return mTransferFunction; }
    constexpr const WhitePoint& getWhitePoint() const { return mWhitePoint; }

private:
    Primaries mPrimaries;
    TransferFunction mTransferFunction;
    WhitePoint mWhitePoint;
};

class PartialColorSpace {
public:
    constexpr ColorSpace operator-(const WhitePoint& whitePoint) const {
        return { mPrimaries, mTransferFunction, whitePoint };
    }

private:
    constexpr PartialColorSpace(
            const Primaries primaries,
            const TransferFunction transferFunction
    ) : mPrimaries(primaries),
        mTransferFunction(transferFunction) {
    }

    Primaries mPrimaries;
    TransferFunction mTransferFunction;

    friend class Gamut;
};

class Gamut {
public:
    constexpr explicit Gamut(const Primaries primaries) : mPrimaries(primaries) {
    }

    constexpr Gamut(float2 r, float2 g, float2 b) : Gamut(Primaries{ r, g, b }) {
    }

    constexpr PartialColorSpace operator-(const TransferFunction& transferFunction) const {
        return { mPrimaries, transferFunction };
    }

    constexpr const Primaries& getPrimaries() const { return mPrimaries; }

private:
    Primaries mPrimaries;
};

//! Rec.709 color gamut, used in the sRGB and DisplayP3 color spaces.
constexpr Gamut Rec709 = {{ 0.640f, 0.330f },
                          { 0.300f, 0.600f },
                          { 0.150f, 0.060f }};

//! Linear transfer function.
constexpr TransferFunction Linear = { 1.0, 0.0, 0.0, 0.0, 1.0 };

//! sRGB transfer function.
constexpr TransferFunction sRGB = { 1.0 / 1.055, 0.055 / 1.055, 1.0 / 12.92, 0.04045, 2.4 };

//! Standard CIE 1931 2° illuminant D65. This illuminant has a color temperature of 6504K.
constexpr WhitePoint D65 = { 0.31271f, 0.32902f };

} // namespace filament::color

#endif // TNT_FILAMENT_COLOR_SPACE_H

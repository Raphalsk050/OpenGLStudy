
//! \file

#ifndef TNT_FILAMENT_TEXTURESAMPLER_H
#define TNT_FILAMENT_TEXTURESAMPLER_H

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <math.h>

#include <stdint.h>

namespace filament {

class UTILS_PUBLIC TextureSampler {
public:
    using WrapMode = backend::SamplerWrapMode;
    using MinFilter = backend::SamplerMinFilter;
    using MagFilter = backend::SamplerMagFilter;
    using CompareMode = backend::SamplerCompareMode;
    using CompareFunc = backend::SamplerCompareFunc;

    TextureSampler() noexcept = default;

    explicit TextureSampler(backend::SamplerParams params) noexcept : mSamplerParams(params) { }

    TextureSampler(const TextureSampler& rhs) noexcept = default;
    TextureSampler& operator=(const TextureSampler& rhs) noexcept = default;

    explicit TextureSampler(MagFilter minMag, WrapMode str = WrapMode::CLAMP_TO_EDGE) noexcept  {
        mSamplerParams.filterMin = MinFilter(minMag);
        mSamplerParams.filterMag = minMag;
        mSamplerParams.wrapS = str;
        mSamplerParams.wrapT = str;
        mSamplerParams.wrapR = str;
    }

    TextureSampler(MinFilter min, MagFilter mag, WrapMode str = WrapMode::CLAMP_TO_EDGE) noexcept  {
        mSamplerParams.filterMin = min;
        mSamplerParams.filterMag = mag;
        mSamplerParams.wrapS = str;
        mSamplerParams.wrapT = str;
        mSamplerParams.wrapR = str;
    }

    TextureSampler(MinFilter min, MagFilter mag, WrapMode s, WrapMode t, WrapMode r) noexcept  {
        mSamplerParams.filterMin = min;
        mSamplerParams.filterMag = mag;
        mSamplerParams.wrapS = s;
        mSamplerParams.wrapT = t;
        mSamplerParams.wrapR = r;
    }

    explicit TextureSampler(CompareMode mode, CompareFunc func = CompareFunc::LE) noexcept  {
        mSamplerParams.compareMode = mode;
        mSamplerParams.compareFunc = func;
    }

    void setMinFilter(MinFilter v) noexcept {
        mSamplerParams.filterMin = v;
    }

    void setMagFilter(MagFilter v) noexcept {
        mSamplerParams.filterMag = v;
    }

    void setWrapModeS(WrapMode v) noexcept {
        mSamplerParams.wrapS = v;
    }

    void setWrapModeT(WrapMode v) noexcept {
        mSamplerParams.wrapT = v;
    }

    void setWrapModeR(WrapMode v) noexcept {
        mSamplerParams.wrapR = v;
    }

    void setAnisotropy(float anisotropy) noexcept {
        const int log2 = ilogbf(anisotropy > 0 ? anisotropy : -anisotropy);
        mSamplerParams.anisotropyLog2 = uint8_t(log2 < 7 ? log2 : 7);
    }

    void setCompareMode(CompareMode mode, CompareFunc func = CompareFunc::LE) noexcept {
        mSamplerParams.compareMode = mode;
        mSamplerParams.compareFunc = func;
    }

    //! returns the minification filter value
    MinFilter getMinFilter() const noexcept { return mSamplerParams.filterMin; }

    //! returns the magnification filter value
    MagFilter getMagFilter() const noexcept { return mSamplerParams.filterMag; }

    //! returns the s-coordinate wrap mode (horizontal)
    WrapMode getWrapModeS() const noexcept  { return mSamplerParams.wrapS; }

    //! returns the t-coordinate wrap mode (vertical)
    WrapMode getWrapModeT() const noexcept  { return mSamplerParams.wrapT; }

    //! returns the r-coordinate wrap mode (depth)
    WrapMode getWrapModeR() const noexcept  { return mSamplerParams.wrapR; }

    //! returns the anisotropy value
    float getAnisotropy() const noexcept { return float(1u << mSamplerParams.anisotropyLog2); }

    //! returns the compare mode
    CompareMode getCompareMode() const noexcept { return mSamplerParams.compareMode; }

    //! returns the compare function
    CompareFunc getCompareFunc() const noexcept { return mSamplerParams.compareFunc; }


    // no user-serviceable parts below...
    backend::SamplerParams getSamplerParams() const noexcept  { return mSamplerParams; }

private:
    backend::SamplerParams mSamplerParams{};
};

} // namespace filament

#endif // TNT_FILAMENT_TEXTURESAMPLER_H

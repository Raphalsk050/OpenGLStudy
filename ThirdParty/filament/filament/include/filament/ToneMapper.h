
#ifndef TNT_FILAMENT_TONEMAPPER_H
#define TNT_FILAMENT_TONEMAPPER_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <cstdint>

namespace filament {

struct UTILS_PUBLIC ToneMapper {
    ToneMapper() noexcept;
    virtual ~ToneMapper() noexcept;

    virtual math::float3 operator()(math::float3 c) const noexcept = 0;
};

struct UTILS_PUBLIC LinearToneMapper final : public ToneMapper {
    LinearToneMapper() noexcept;
    ~LinearToneMapper() noexcept final;

    math::float3 operator()(math::float3 c) const noexcept override;
};

struct UTILS_PUBLIC ACESToneMapper final : public ToneMapper {
    ACESToneMapper() noexcept;
    ~ACESToneMapper() noexcept final;

    math::float3 operator()(math::float3 c) const noexcept override;
};

struct UTILS_PUBLIC ACESLegacyToneMapper final : public ToneMapper {
    ACESLegacyToneMapper() noexcept;
    ~ACESLegacyToneMapper() noexcept final;

    math::float3 operator()(math::float3 c) const noexcept override;
};

struct UTILS_PUBLIC FilmicToneMapper final : public ToneMapper {
    FilmicToneMapper() noexcept;
    ~FilmicToneMapper() noexcept final;

    math::float3 operator()(math::float3 x) const noexcept override;
};

struct UTILS_PUBLIC PBRNeutralToneMapper final : public ToneMapper {
    PBRNeutralToneMapper() noexcept;
    ~PBRNeutralToneMapper() noexcept final;

    math::float3 operator()(math::float3 x) const noexcept override;
};

struct UTILS_PUBLIC AgxToneMapper final : public ToneMapper {
    enum class AgxLook : uint8_t {
        NONE = 0,   //!< Base contrast with no look applied
        PUNCHY,     //!< A punchy and more chroma laden look for sRGB displays
        GOLDEN      //!< A golden tinted, slightly washed look for BT.1886 displays
    };

    explicit AgxToneMapper(AgxLook look = AgxLook::NONE) noexcept;
    ~AgxToneMapper() noexcept final;

    math::float3 operator()(math::float3 x) const noexcept override;

    AgxLook look;
};

struct UTILS_PUBLIC GenericToneMapper final : public ToneMapper {
    explicit GenericToneMapper(
            float contrast = 1.55f,
            float midGrayIn = 0.18f,
            float midGrayOut = 0.215f,
            float hdrMax = 10.0f
    ) noexcept;
    ~GenericToneMapper() noexcept final;

    GenericToneMapper(GenericToneMapper const&) = delete;
    GenericToneMapper& operator=(GenericToneMapper const&) = delete;
    GenericToneMapper(GenericToneMapper&& rhs)  noexcept;
    GenericToneMapper& operator=(GenericToneMapper&& rhs) noexcept;

    math::float3 operator()(math::float3 x) const noexcept override;

    float getMidGrayIn() const noexcept;

    float getHdrMax() const noexcept;

    void setMidGrayIn(float midGrayIn) noexcept;

    void setHdrMax(float hdrMax) noexcept;

private:
    struct Options;
    Options* mOptions;
};

struct UTILS_PUBLIC DisplayRangeToneMapper final : public ToneMapper {
    DisplayRangeToneMapper() noexcept;
    ~DisplayRangeToneMapper() noexcept override;

    math::float3 operator()(math::float3 c) const noexcept override;
};

} // namespace filament

#endif // TNT_FILAMENT_TONEMAPPER_H

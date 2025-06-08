
#ifndef TNT_FILAMENT_DRIVER_SAMPLERBINDINGMAP_H
#define TNT_FILAMENT_DRIVER_SAMPLERBINDINGMAP_H

#include <private/filament/SamplerBindingsInfo.h>

#include <filament/MaterialEnums.h>

namespace filament {

class SamplerInterfaceBlock;

class SamplerBindingMap {
public:

    using SamplerGroupBindingInfo = SamplerGroupBindingInfo;

    // Initializes the SamplerBindingMap.
    // Assigns a range of finalized binding points to each sampler block.
    // If a per-material SIB is provided, then material samplers are also inserted (always at the
    // end).
    void init(MaterialDomain materialDomain,
            SamplerInterfaceBlock const& perMaterialSib);

    SamplerGroupBindingInfo const& getSamplerGroupBindingInfo(
            SamplerBindingPoints bindingPoint) const noexcept {
        return mSamplerBlockOffsets[+bindingPoint];
    }

    // Gets the global offset of the first sampler in the given sampler block.
    inline uint8_t getBlockOffset(SamplerBindingPoints bindingPoint) const noexcept {
        assert_invariant(mSamplerBlockOffsets[+bindingPoint].bindingOffset != UNKNOWN_OFFSET);
        return getSamplerGroupBindingInfo(bindingPoint).bindingOffset;
    }

    size_t getActiveSamplerCount() const noexcept {
        return mActiveSamplerCount;
    }

    utils::CString const& getSamplerName(size_t binding) const noexcept {
        return mSamplerNamesBindingMap[binding];
    }

private:
    constexpr static uint8_t UNKNOWN_OFFSET = SamplerGroupBindingInfo::UNKNOWN_OFFSET;
    SamplerGroupBindingInfoList mSamplerBlockOffsets{};
    SamplerBindingToNameMap mSamplerNamesBindingMap{};
    uint8_t mActiveSamplerCount = 0;
};

} // namespace filament

#endif // TNT_FILAMENT_DRIVER_SAMPLERBINDINGMAP_H

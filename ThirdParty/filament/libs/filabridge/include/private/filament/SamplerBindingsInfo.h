
#ifndef TNT_FILABRIDGE_SAMPLERBINDINGS_INFO_H
#define TNT_FILABRIDGE_SAMPLERBINDINGS_INFO_H

#include <backend/DriverEnums.h>

#include <private/filament/EngineEnums.h>

#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

#include <array>

namespace filament {

// binding information about a sampler group
struct SamplerGroupBindingInfo {
    constexpr static uint8_t UNKNOWN_OFFSET = 0xff;
    // global binding of this block, or UNKNOWN_OFFSET if not used.
    uint8_t bindingOffset = UNKNOWN_OFFSET;
    // shader stage flags for samplers in this block
    backend::ShaderStageFlags shaderStageFlags = backend::ShaderStageFlags::NONE;
    // number of samplers in this block. Can be zero.
    uint8_t count = 0;
};

// list of binding information for all known binding points
using SamplerGroupBindingInfoList =
        std::array<SamplerGroupBindingInfo, utils::Enum::count<SamplerBindingPoints>()>;

// map of sampler shader binding to sampler shader name
using SamplerBindingToNameMap =
        utils::FixedCapacityVector<utils::CString>;

} // namespace filament

#endif //TNT_FILABRIDGE_SAMPLERBINDINGS_INFO_H

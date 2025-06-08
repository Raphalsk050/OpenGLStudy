
#ifndef TNT_GEOMETRY_TRANSCODER_H
#define TNT_GEOMETRY_TRANSCODER_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <stddef.h>
#include <stdint.h>

namespace filament {
namespace geometry {

enum class ComponentType {
    BYTE,   //!< If normalization is enabled, this maps from [-127,127] to [-1,+1]
    UBYTE,  //!< If normalization is enabled, this maps from [0,255] to [0, +1]
    SHORT,  //!< If normalization is enabled, this maps from [-32767,32767] to [-1,+1]
    USHORT, //!< If normalization is enabled, this maps from [0,65535] to [0, +1]
    HALF,   //!< 1 sign bit, 5 exponent bits, and 5 mantissa bits.
    FLOAT,  //!< Standard 32-bit float
};

class UTILS_PUBLIC Transcoder {
public:
    struct Config {
        ComponentType componentType;
        bool normalized;
        uint32_t componentCount;
        uint32_t inputStrideBytes = 0; //!< If stride is 0, the transcoder assumes tight packing.
    };

    Transcoder(Config config) noexcept : mConfig(config) {}

    size_t operator()(float* UTILS_RESTRICT target, void const* UTILS_RESTRICT source,
            size_t count) const noexcept;

private:
    const Config mConfig;
};

} // namespace geometry
} // namespace filament

#endif // TNT_GEOMETRY_TRANSCODER_H

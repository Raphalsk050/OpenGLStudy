
#ifndef TNT_FILAMENT_DRIVER_DATARESHAPER_H
#define TNT_FILAMENT_DRIVER_DATARESHAPER_H

#include <backend/PixelBufferDescriptor.h>

#include <cstring>
#include <stddef.h>
#include <stdint.h>
#include <cstring>

#include "third_party/filament/libs/math/include/math/scalar.h"

#include "third_party/filament/libs/utils/include/utils/debug.h"

namespace filament {
namespace backend {

// Provides an alpha value when expanding 3-channel images to 4-channel.
// Also used as a normalization scale when converting between numeric types.
template<typename componentType> inline componentType getMaxValue();

class DataReshaper {
public:

    // Adds padding to multi-channel interleaved data by inserting dummy values, or discards
    // trailing channels. This is useful for platforms that only accept 4-component data, since
    // users often wish to submit (or receive) 3-component data.
    template<typename componentType, size_t srcChannelCount, size_t dstChannelCount>
    static void reshape(void* UTILS_RESTRICT dest, const void* UTILS_RESTRICT src,
            size_t numSrcBytes) {
        const componentType maxValue = getMaxValue<componentType>();
        const componentType* in = (const componentType*) src;
        componentType* out = (componentType*) dest;
        const size_t width = (numSrcBytes / sizeof(componentType)) / srcChannelCount;
        constexpr size_t minChannelCount = math::min(srcChannelCount, dstChannelCount);
        for (size_t column = 0; column < width; ++column) {
            for (size_t channel = 0; channel < minChannelCount; ++channel) {
                out[channel] = in[channel];
            }
            for (size_t channel = srcChannelCount; channel < dstChannelCount; ++channel) {
                out[channel] = maxValue;
            }
            in += srcChannelCount;
            out += dstChannelCount;
        }
    }

    static void copyImage(uint8_t* UTILS_RESTRICT dest,
                          const uint8_t* UTILS_RESTRICT src,

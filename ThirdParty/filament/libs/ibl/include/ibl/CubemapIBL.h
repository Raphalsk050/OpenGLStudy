
#ifndef IBL_CUBEMAPIBL_H
#define IBL_CUBEMAPIBL_H

#include "third_party/filament/libs/math/include/math/vec3.h"

#include "third_party/filament/libs/utils/include/utils/Slice.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <vector>

#include <stdint.h>
#include <stddef.h>

namespace utils {
class JobSystem;
} // namespace utils

namespace filament {
namespace ibl {

class Cubemap;
class Image;

class UTILS_PUBLIC CubemapIBL {
public:
    typedef void (*Progress)(size_t, float, void*);

    static void roughnessFilter(
            utils::JobSystem& js, Cubemap& dst, const utils::Slice<Cubemap>& levels,
            float linearRoughness, size_t maxNumSamples, math::float3 mirror, bool prefilter,
            Progress updater = nullptr, void* userdata = nullptr);

    static void roughnessFilter(
            utils::JobSystem& js, Cubemap& dst, const std::vector<Cubemap>& levels,
            float linearRoughness, size_t maxNumSamples, math::float3 mirror, bool prefilter,
            Progress updater = nullptr, void* userdata = nullptr);

    //! Computes the "DFG" term of the "split-sum" approximation and stores it in a 2D image
    static void DFG(utils::JobSystem& js, Image& dst, bool multiscatter, bool cloth);

    static void diffuseIrradiance(utils::JobSystem& js, Cubemap& dst, const std::vector<Cubemap>& levels,
            size_t maxNumSamples = 1024, Progress updater = nullptr, void* userdata = nullptr);

    // for debugging. ignore.
    static void brdf(utils::JobSystem& js, Cubemap& dst, float linearRoughness);
};

} // namespace ibl
} // namespace filament


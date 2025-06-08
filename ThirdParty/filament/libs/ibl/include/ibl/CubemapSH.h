
#ifndef IBL_CUBEMAPSH_H
#define IBL_CUBEMAPSH_H


#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mat3.h"
#include "third_party/filament/libs/math/include/math/vec3.h"

#include <memory>
#include <vector>

namespace utils {
class JobSystem;
} // namespace utils

namespace filament {
namespace ibl {

class Cubemap;

class UTILS_PUBLIC CubemapSH {
public:
    static std::unique_ptr<math::float3[]> computeSH(
            utils::JobSystem& js, const Cubemap& cm, size_t numBands, bool irradiance);

    static void renderSH(utils::JobSystem& js, Cubemap& cm,
            const std::unique_ptr<math::float3[]>& sh, size_t numBands);

    static void windowSH(std::unique_ptr<math::float3[]>& sh, size_t numBands, float cutoff);

    static void preprocessSHForShader(std::unique_ptr<math::float3[]>& sh);

    static void renderPreScaledSH3Bands(utils::JobSystem& js, Cubemap& cm,
            const std::unique_ptr<math::float3[]>& sh);

    static constexpr size_t getShIndex(ssize_t m, size_t l) {
        return SHindex(m, l);
    }

private:
    class float5 {
        float v[5];
    public:
        float5() = default;
        constexpr float5(float a, float b, float c, float d, float e) : v{ a, b, c, d, e } {}
        constexpr float operator[](size_t i) const { return v[i]; }
        float& operator[](size_t i) { return v[i]; }
    };

    static inline const float5 multiply(const float5 M[5], float5 x) noexcept {
        return float5{
                M[0][0] * x[0] + M[1][0] * x[1] + M[2][0] * x[2] + M[3][0] * x[3] + M[4][0] * x[4],
                M[0][1] * x[0] + M[1][1] * x[1] + M[2][1] * x[2] + M[3][1] * x[3] + M[4][1] * x[4],
                M[0][2] * x[0] + M[1][2] * x[1] + M[2][2] * x[2] + M[3][2] * x[3] + M[4][2] * x[4],
                M[0][3] * x[0] + M[1][3] * x[1] + M[2][3] * x[2] + M[3][3] * x[3] + M[4][3] * x[4],
                M[0][4] * x[0] + M[1][4] * x[1] + M[2][4] * x[2] + M[3][4] * x[3] + M[4][4] * x[4]
        };
    };


    static inline constexpr size_t SHindex(ssize_t m, size_t l) {
        return l * (l + 1) + m;
    }

    static void computeShBasis(float* SHb, size_t numBands, const math::float3& s);

    static float Kml(ssize_t m, size_t l);

    static std::vector<float> Ki(size_t numBands);

    static constexpr float computeTruncatedCosSh(size_t l);

    static float sincWindow(size_t l, float w);

    static math::float3 rotateShericalHarmonicBand1(math::float3 band1, math::mat3f const& M);

    static float5 rotateShericalHarmonicBand2(float5 const& band2, math::mat3f const& M);

        // debugging only...
    static float Legendre(ssize_t l, ssize_t m, float x);
    static float TSH(int l, int m, const math::float3& d);
    static void printShBase(std::ostream& out, int l, int m);
};

} // namespace ibl
} // namespace filament


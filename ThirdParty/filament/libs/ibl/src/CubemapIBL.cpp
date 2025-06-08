

#include <ibl/CubemapIBL.h>

#include <ibl/Cubemap.h>
#include <ibl/CubemapUtils.h>
#include <ibl/utilities.h>

#include "CubemapUtilsImpl.h"

#include "third_party/filament/libs/utils/include/utils/JobSystem.h"

#include "third_party/filament/libs/math/include/math/mat3.h"
#include "third_party/filament/libs/math/include/math/scalar.h"

#include <random>
#include <vector>

using namespace filament::math;
using namespace utils;

namespace filament {
namespace ibl {

static float pow5(float x) {
    const float x2 = x * x;
    return x2 * x2 * x;
}

static float pow6(float x) {
    const float x2 = x * x;
    return x2 * x2 * x2;
}

static float3 hemisphereImportanceSampleDggx(float2 u, float a) { // pdf = D(a) * cosTheta
    const float phi = 2.0f * (float) F_PI * u.x;
    // NOTE: (aa-1) == (a-1)(a+1) produces better fp accuracy
    const float cosTheta2 = (1 - u.y) / (1 + (a + 1) * ((a - 1) * u.y));
    const float cosTheta = std::sqrt(cosTheta2);
    const float sinTheta = std::sqrt(1 - cosTheta2);
    return { sinTheta * std::cos(phi), sinTheta * std::sin(phi), cosTheta };
}

static float3 UTILS_UNUSED hemisphereCosSample(float2 u) {  // pdf = cosTheta / F_PI;
    const float phi = 2.0f * (float) F_PI * u.x;
    const float cosTheta2 = 1 - u.y;
    const float cosTheta = std::sqrt(cosTheta2);
    const float sinTheta = std::sqrt(1 - cosTheta2);
    return { sinTheta * std::cos(phi), sinTheta * std::sin(phi), cosTheta };
}

static float3 UTILS_UNUSED hemisphereUniformSample(float2 u) { // pdf = 1.0 / (2.0 * F_PI);
    const float phi = 2.0f * (float) F_PI * u.x;
    const float cosTheta = 1 - u.y;
    const float sinTheta = std::sqrt(1 - cosTheta * cosTheta);
    return { sinTheta * std::cos(phi), sinTheta * std::sin(phi), cosTheta };
}

static float3 UTILS_UNUSED hemisphereImportanceSampleDCharlie(float2 u, float a) { // pdf = DistributionCharlie() * cosTheta
    const float phi = 2.0f * (float) F_PI * u.x;

    const float sinTheta = std::pow(u.y, a / (2 * a + 1));
    const float cosTheta = std::sqrt(1 - sinTheta * sinTheta);

    return { sinTheta * std::cos(phi), sinTheta * std::sin(phi), cosTheta };
}

static float DistributionGGX(float NoH, float linearRoughness) {
    // NOTE: (aa-1) == (a-1)(a+1) produces better fp accuracy
    float a = linearRoughness;
    float f = (a - 1) * ((a + 1) * (NoH * NoH)) + 1;
    return (a * a) / ((float) F_PI * f * f);
}

static float UTILS_UNUSED DistributionAshikhmin(float NoH, float linearRoughness) {
    float a = linearRoughness;
    float a2 = a * a;
    float cos2h = NoH * NoH;
    float sin2h = 1 - cos2h;
    float sin4h = sin2h * sin2h;
    return 1.0f / ((float) F_PI * (1 + 4 * a2)) * (sin4h + 4 * std::exp(-cos2h / (a2 * sin2h)));
}

static float UTILS_UNUSED DistributionCharlie(float NoH, float linearRoughness) {
    // Estevez and Kulla 2017, "Production Friendly Microfacet Sheen BRDF"
    float a = linearRoughness;
    float invAlpha = 1 / a;
    float cos2h = NoH * NoH;
    float sin2h = 1 - cos2h;
    return (2.0f + invAlpha) * std::pow(sin2h, invAlpha * 0.5f) / (2.0f * (float) F_PI);
}

static float Fresnel(float f0, float f90, float LoH) {
    const float Fc = pow5(1 - LoH);
    return f0 * (1 - Fc) + f90 * Fc;
}

static float Visibility(float NoV, float NoL, float a) {
    // Heitz 2014, "Understanding the Masking-Shadowing Function in Microfacet-Based BRDFs"
    // Height-correlated GGX
    const float a2 = a * a;
    const float GGXL = NoV * std::sqrt((NoL - NoL * a2) * NoL + a2);
    const float GGXV = NoL * std::sqrt((NoV - NoV * a2) * NoV + a2);
    return 0.5f / (GGXV + GGXL);
}


UTILS_ALWAYS_INLINE
void CubemapIBL::roughnessFilter(
        utils::JobSystem& js, Cubemap& dst, const std::vector<Cubemap>& levels,
        float linearRoughness, size_t maxNumSamples, math::float3 mirror, bool prefilter,
        Progress updater, void* userdata) {
    roughnessFilter(js, dst, { levels.data(), uint32_t(levels.size()) },
            linearRoughness, maxNumSamples, mirror, prefilter, updater, userdata);
}

void CubemapIBL::roughnessFilter(
        utils::JobSystem& js, Cubemap& dst, const utils::Slice<Cubemap>& levels,
        float linearRoughness, size_t maxNumSamples, math::float3 mirror, bool prefilter,
        Progress updater, void* userdata)
{
    const float numSamples = maxNumSamples;
    const float inumSamples = 1.0f / numSamples;
    const size_t maxLevel = levels.size()-1;
    const float maxLevelf = maxLevel;
    const Cubemap& base(levels[0]);
    const size_t dim0 = base.getDimensions();
    const float omegaP = (4.0f * (float) F_PI) / float(6 * dim0 * dim0);
    std::atomic_uint progress = {0};

    if (linearRoughness == 0) {
        auto scanline = [&]
                (CubemapUtils::EmptyState&, size_t y, Cubemap::Face f, Cubemap::Texel* data, size_t dim) {
                    if (UTILS_UNLIKELY(updater)) {
                        size_t p = progress.fetch_add(1, std::memory_order_relaxed) + 1;
                        updater(0, (float)p / ((float) dim * 6.0f), userdata);
                    }
                    const Cubemap& cm = levels[0];
                    for (size_t x = 0; x < dim; ++x, ++data) {
                        const float2 p(Cubemap::center(x, y));
                        const float3 N(dst.getDirectionFor(f, p.x, p.y) * mirror);
                        // FIXME: we should pick the proper LOD here and do trilinear filtering
                        Cubemap::writeAt(data, cm.sampleAt(N));
                    }
        };
        // at least 256 pixel cubemap before we use multithreading -- the overhead of launching
        // jobs is too large compared to the work above.
        if (dst.getDimensions() <= 256) {
            CubemapUtils::processSingleThreaded<CubemapUtils::EmptyState>(
                    dst, js, std::ref(scanline));
        } else {
            CubemapUtils::process<CubemapUtils::EmptyState>(dst, js, std::ref(scanline));
        }
        return;
    }

    // be careful w/ the size of this structure, the smaller the better
    struct CacheEntry {
        float3 L;
        float brdf_NoL;
        float lerp;
        uint8_t l0;
        uint8_t l1;
    };

    std::vector<CacheEntry> cache;
    cache.reserve(maxNumSamples);

    // precompute everything that only depends on the sample #
    float weight = 0;
    // index of the sample to use
    // our goal is to use maxNumSamples for which NoL is > 0
    // to achieve this, we might have to try more samples than
    // maxNumSamples
    for (size_t sampleIndex = 0 ; sampleIndex < maxNumSamples; sampleIndex++) {

        // get Hammersley distribution for the half-sphere
        const float2 u = hammersley(uint32_t(sampleIndex), inumSamples);

        // Importance sampling GGX - Trowbridge-Reitz
        const float3 H = hemisphereImportanceSampleDggx(u, linearRoughness);

#if 0
        // This produces the same result that the code below using the the non-simplified
        // equation. This let's us see that N == V and that L = -reflect(V, H)
        // Keep this for reference.
        const float3 N = {0, 0, 1};
        const float3 V = N;
        const float3 L = 2 * dot(H, V) * H - V;
        const float NoL = dot(N, L);
        const float NoH = dot(N, H);
        const float NoH2 = NoH * NoH;
        const float NoV = dot(N, V);
#else
        const float NoH = H.z;
        const float NoH2 = H.z * H.z;
        const float NoL = 2 * NoH2 - 1;
        const float3 L(2 * NoH * H.x, 2 * NoH * H.y, NoL);
#endif

        if (NoL > 0) {
            const float pdf = DistributionGGX(NoH, linearRoughness) / 4;

            // K is a LOD bias that allows a bit of overlapping between samples
            constexpr float K = 4;
            const float omegaS = 1 / (numSamples * pdf);
            const float l = float(log4(omegaS) - log4(omegaP) + log4(K));
            const float mipLevel = prefilter ? clamp(float(l), 0.0f, maxLevelf) : 0.0f;

            const float brdf_NoL = float(NoL);

            weight += brdf_NoL;

            uint8_t l0 = uint8_t(mipLevel);
            uint8_t l1 = uint8_t(std::min(maxLevel, size_t(l0 + 1)));
            float lerp = mipLevel - (float) l0;

            cache.push_back({ L, brdf_NoL, lerp, l0, l1 });
        }
    }

    for (auto& entry : cache) {
        entry.brdf_NoL *= 1.0f / weight;
    }

    // we can sample the cubemap in any order, sort by the weight, it could improve fp precision
    std::sort(cache.begin(), cache.end(), [](CacheEntry const& lhs, CacheEntry const& rhs) {
        return lhs.brdf_NoL < rhs.brdf_NoL;
    });


    struct State {
        // maybe blue-noise instead would look even better
        std::default_random_engine gen;
        std::uniform_real_distribution<float> distribution{ -F_PI, F_PI };
    };

    auto scanline = [&](State& state, size_t y,
            Cubemap::Face f, Cubemap::Texel* data, size_t dim) {
        if (UTILS_UNLIKELY(updater)) {
            size_t p = progress.fetch_add(1, std::memory_order_relaxed) + 1;
            updater(0, (float) p / ((float) dim * 6.0f), userdata);
        }
        mat3 R;
        const size_t numSamples = cache.size();
        for (size_t x = 0; x < dim; ++x, ++data) {
            const float2 p(Cubemap::center(x, y));
            const float3 N(dst.getDirectionFor(f, p.x, p.y) * mirror);

            // center the cone around the normal (handle case of normal close to up)
            const float3 up = std::abs(N.z) < 0.999 ? float3(0, 0, 1) : float3(1, 0, 0);
            R[0] = normalize(cross(up, N));
            R[1] = cross(N, R[0]);
            R[2] = N;

            R *= mat3f::rotation(state.distribution(state.gen), float3{0,0,1});

            float3 Li = 0;
            for (size_t sample = 0; sample < numSamples; sample++) {
                const CacheEntry& e = cache[sample];
                const float3 L(R * e.L);
                const Cubemap& cmBase = levels[e.l0];
                const Cubemap& next = levels[e.l1];
                const float3 c0 = Cubemap::trilinearFilterAt(cmBase, next, e.lerp, L);
                Li += c0 * e.brdf_NoL;
            }
            Cubemap::writeAt(data, Cubemap::Texel(Li));
        }
    };

    // don't use the jobsystem unless we have enough work per scanline -- or the overhead of
    // launching jobs will prevail.
    if (dst.getDimensions() * maxNumSamples <= 256) {
        CubemapUtils::processSingleThreaded<State>(dst, js, std::ref(scanline));
    } else {
        CubemapUtils::process<State>(dst, js, std::ref(scanline));
    }
}


void CubemapIBL::diffuseIrradiance(JobSystem& js, Cubemap& dst, const std::vector<Cubemap>& levels,
        size_t maxNumSamples, CubemapIBL::Progress updater, void* userdata)
{
    const float numSamples = maxNumSamples;
    const float inumSamples = 1.0f / numSamples;
    const size_t maxLevel = levels.size()-1;
    const float maxLevelf = maxLevel;
    const Cubemap& base(levels[0]);
    const size_t dim0 = base.getDimensions();
    const float omegaP = (4.0f * (float) F_PI) / float(6 * dim0 * dim0);

    std::atomic_uint progress = {0};

    struct CacheEntry {
        float3 L;
        float lerp;
        uint8_t l0;
        uint8_t l1;
    };

    std::vector<CacheEntry> cache;
    cache.reserve(maxNumSamples);

    // precompute everything that only depends on the sample #
    for (size_t sampleIndex = 0; sampleIndex < maxNumSamples; sampleIndex++) {
        // get Hammersley distribution for the half-sphere
        const float2 u = hammersley(uint32_t(sampleIndex), inumSamples);
        const float3 L = hemisphereCosSample(u);
        const float3 N = { 0, 0, 1 };
        const float NoL = dot(N, L);

        if (NoL > 0) {
            float pdf = NoL * (float) F_1_PI;

            constexpr float K = 4;
            const float omegaS = 1.0f / (numSamples * pdf);
            const float l = float(log4(omegaS) - log4(omegaP) + log4(K));
            const float mipLevel = clamp(float(l), 0.0f, maxLevelf);

            uint8_t l0 = uint8_t(mipLevel);
            uint8_t l1 = uint8_t(std::min(maxLevel, size_t(l0 + 1)));
            float lerp = mipLevel - (float) l0;

            cache.push_back({ L, lerp, l0, l1 });
        }
    }

    CubemapUtils::process<CubemapUtils::EmptyState>(dst, js,
            [&](CubemapUtils::EmptyState&, size_t y,
                    Cubemap::Face f, Cubemap::Texel* data, size_t dim) {

        if (updater) {
            size_t p = progress.fetch_add(1, std::memory_order_relaxed) + 1;
            updater(0, (float)p / ((float) dim * 6.0f), userdata);
        }

        mat3 R;
        const size_t numSamples = cache.size();
        for (size_t x = 0; x < dim; ++x, ++data) {
            const float2 p(Cubemap::center(x, y));
            const float3 N(dst.getDirectionFor(f, p.x, p.y));

            // center the cone around the normal (handle case of normal close to up)
            const float3 up = std::abs(N.z) < 0.999 ? float3(0, 0, 1) : float3(1, 0, 0);
            R[0] = normalize(cross(up, N));
            R[1] = cross(N, R[0]);
            R[2] = N;

            float3 Li = 0;
            for (size_t sample = 0; sample < numSamples; sample++) {
                const CacheEntry& e = cache[sample];
                const float3 L(R * e.L);
                const Cubemap& cmBase = levels[e.l0];
                const Cubemap& next = levels[e.l1];
                const float3 c0 = Cubemap::trilinearFilterAt(cmBase, next, e.lerp, L);
                Li += c0;
            }
            Cubemap::writeAt(data, Cubemap::Texel(Li * inumSamples));
        }
    });
}

// Not importance-sampled
static float2 UTILS_UNUSED DFV_NoIS(float NoV, float roughness, size_t numSamples) {
    float2 r = 0;
    const float linearRoughness = roughness * roughness;
    const float3 V(std::sqrt(1 - NoV * NoV), 0, NoV);
    for (size_t i = 0; i < numSamples; i++) {
        const float2 u = hammersley(uint32_t(i), 1.0f / numSamples);
        const float3 H = hemisphereCosSample(u);
        const float3 L = 2 * dot(V, H) * H - V;
        const float VoH = saturate(dot(V, H));
        const float NoL = saturate(L.z);
        const float NoH = saturate(H.z);
        if (NoL > 0) {
            // Note: remember VoH == LoH  (H is half vector)
            const float J = 1.0f / (4.0f * VoH);
            const float pdf = NoH / (float) F_PI;
            const float d = DistributionGGX(NoH, linearRoughness) * NoL / (pdf * J);
            const float Fc = pow5(1 - VoH);
            const float v = Visibility(NoV, NoL, linearRoughness);
            r.x += d * v * (1.0f - Fc);
            r.y += d * v * Fc;
        }
    }
    return r / numSamples;
}


static float2 DFV(float NoV, float linearRoughness, size_t numSamples) {
    float2 r = 0;
    const float3 V(std::sqrt(1 - NoV * NoV), 0, NoV);
    for (size_t i = 0; i < numSamples; i++) {
        const float2 u = hammersley(uint32_t(i), 1.0f / numSamples);
        const float3 H = hemisphereImportanceSampleDggx(u, linearRoughness);
        const float3 L = 2 * dot(V, H) * H - V;
        const float VoH = saturate(dot(V, H));
        const float NoL = saturate(L.z);
        const float NoH = saturate(H.z);
        if (NoL > 0) {
            const float v = Visibility(NoV, NoL, linearRoughness) * NoL * (VoH / NoH);
            const float Fc = pow5(1 - VoH);
            r.x += v * (1.0f - Fc);
            r.y += v * Fc;
        }
    }
    return r * (4.0f / numSamples);
}

static float2 DFV_Multiscatter(float NoV, float linearRoughness, size_t numSamples) {
    float2 r = 0;
    const float3 V(std::sqrt(1 - NoV * NoV), 0, NoV);
    for (size_t i = 0; i < numSamples; i++) {
        const float2 u = hammersley(uint32_t(i), 1.0f / numSamples);
        const float3 H = hemisphereImportanceSampleDggx(u, linearRoughness);
        const float3 L = 2 * dot(V, H) * H - V;
        const float VoH = saturate(dot(V, H));
        const float NoL = saturate(L.z);
        const float NoH = saturate(H.z);
        if (NoL > 0) {
            const float v = Visibility(NoV, NoL, linearRoughness) * NoL * (VoH / NoH);
            const float Fc = pow5(1 - VoH);
            r.x += v * Fc;
            r.y += v;
        }
    }
    return r * (4.0f / numSamples);
}

static float UTILS_UNUSED DFV_LazanyiTerm(float NoV, float linearRoughness, size_t numSamples) {
    float r = 0;
    const float cosThetaMax = (float) std::cos(81.7 * F_PI / 180.0);
    const float q = 1.0f / (cosThetaMax * pow6(1.0f - cosThetaMax));
    const float3 V(std::sqrt(1 - NoV * NoV), 0, NoV);
    for (size_t i = 0; i < numSamples; i++) {
        const float2 u = hammersley(uint32_t(i), 1.0f / numSamples);
        const float3 H = hemisphereImportanceSampleDggx(u, linearRoughness);
        const float3 L = 2 * dot(V, H) * H - V;
        const float VoH = saturate(dot(V, H));
        const float NoL = saturate(L.z);
        const float NoH = saturate(H.z);
        if (NoL > 0) {
            const float v = Visibility(NoV, NoL, linearRoughness) * NoL * (VoH / NoH);
            const float Fc = pow6(1 - VoH);
            r += v * Fc * VoH * q;
        }
    }
    return r * (4.0f / numSamples);
}

static float DFV_Charlie_Uniform(float NoV, float linearRoughness, size_t numSamples) {
    float r = 0.0;
    const float3 V(std::sqrt(1 - NoV * NoV), 0, NoV);
    for (size_t i = 0; i < numSamples; i++) {
        const float2 u = hammersley(uint32_t(i), 1.0f / numSamples);
        const float3 H = hemisphereUniformSample(u);
        const float3 L = 2 * dot(V, H) * H - V;
        const float VoH = saturate(dot(V, H));
        const float NoL = saturate(L.z);
        const float NoH = saturate(H.z);
        if (NoL > 0) {
            const float v = VisibilityAshikhmin(NoV, NoL, linearRoughness);
            const float d = DistributionCharlie(NoH, linearRoughness);
            r += v * d * NoL * VoH; // VoH comes from the Jacobian, 1/(4*VoH)
        }
    }
    // uniform sampling, the PDF is 1/2pi, 4 comes from the Jacobian
    return r * (4.0f * 2.0f * (float) F_PI / numSamples);
}

static float UTILS_UNUSED DFV_Charlie_IS(float NoV, float linearRoughness, size_t numSamples) {
    float r = 0.0;
    const float3 V(std::sqrt(1 - NoV * NoV), 0, NoV);
    for (size_t i = 0; i < numSamples; i++) {
        const float2 u = hammersley(uint32_t(i), 1.0f / numSamples);
        const float3 H = hemisphereImportanceSampleDCharlie(u, linearRoughness);
        const float3 L = 2 * dot(V, H) * H - V;
        const float VoH = saturate(dot(V, H));
        const float NoL = saturate(L.z);
        const float NoH = saturate(H.z);
        if (NoL > 0) {
            const float J = 1.0f / (4.0f * VoH);
            const float pdf = NoH; // D has been removed as it cancels out in the previous equation
            const float v = VisibilityAshikhmin(NoV, NoL, linearRoughness);

            r += v * NoL / (pdf * J);
        }
    }
    return r / numSamples;
}

void CubemapIBL::brdf(utils::JobSystem& js, Cubemap& dst, float linearRoughness) {
    CubemapUtils::process<CubemapUtils::EmptyState>(dst, js,
            [ & ](CubemapUtils::EmptyState&, size_t y,
                    Cubemap::Face f, Cubemap::Texel* data, size_t dim) {
                for (size_t x=0 ; x<dim ; ++x, ++data) {
                    const float2 p(Cubemap::center(x, y));
                    const float3 H(dst.getDirectionFor(f, p.x, p.y));
                    const float3 N = { 0, 0, 1 };
                    const float3 V = N;
                    const float3 L = 2 * dot(H, V) * H - V;
                    const float NoL = dot(N, L);
                    const float NoH = dot(N, H);
                    const float NoV = dot(N, V);
                    const float LoH = dot(L, H);
                    float brdf_NoL = 0;
                    if (NoL > 0 && LoH > 0) {
                        const float D = DistributionGGX(NoH, linearRoughness);
                        const float F = Fresnel(0.04f, 1.0f, LoH);
                        const float V = Visibility(NoV, NoL, linearRoughness);
                        brdf_NoL = float(D * F * V * NoL);
                    }
                    Cubemap::writeAt(data, Cubemap::Texel{ brdf_NoL });
                }
            });
}

void CubemapIBL::DFG(JobSystem& js, Image& dst, bool multiscatter, bool cloth) {
    auto dfvFunction = multiscatter ? DFV_Multiscatter : DFV;
    auto job = jobs::parallel_for<char>(js, nullptr, nullptr, uint32_t(dst.getHeight()),
            [&dst, dfvFunction, cloth](char const* d, size_t c) {
                const size_t width = dst.getWidth();
                const size_t height = dst.getHeight();
                size_t y0 = size_t(d);
                for (size_t y = y0; y < y0 + c; y++) {
                    Cubemap::Texel* UTILS_RESTRICT data =
                            static_cast<Cubemap::Texel*>(dst.getPixelRef(0, y));

                    const float h = (float) height;
                    const float coord = saturate((h - y + 0.5f) / h);
                    // map the coordinate in the texture to a linear_roughness,
                    // here we're using ^2, but other mappings are possible.
                    // ==> coord = sqrt(linear_roughness)
                    const float linear_roughness = coord * coord;
                    for (size_t x = 0; x < width; x++, data++) {
                        // const float NoV = float(x) / (width-1);
                        const float NoV = saturate((x + 0.5f) / width);
                        float3 r = { dfvFunction(NoV, linear_roughness, 1024), 0 };
                        if (cloth) {
                            r.b = float(DFV_Charlie_Uniform(NoV, linear_roughness, 4096));
                        }
                        *data = r;
                    }
                }
            }, jobs::CountSplitter<1, 8>());
    js.runAndWait(job);
}

} // namespace ibl
} // namespace filament


#ifndef TNT_FILAMENT_MATERIALINSTANCE_H
#define TNT_FILAMENT_MATERIALINSTANCE_H

#include <filament/FilamentAPI.h>
#include <filament/Color.h>

#include <filament/MaterialEnums.h>

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"
#include <string.h>

#include <type_traits>

#include <stddef.h>
#include <stdint.h>
#include <string.h>

namespace filament {

class Material;
class Texture;
class TextureSampler;
class UniformBuffer;
class BufferInterfaceBlock;

class UTILS_PUBLIC MaterialInstance : public FilamentAPI {
    template<size_t N>
    using StringLiteralHelper = const char[N];

    struct StringLiteral {
        const char* UTILS_NONNULL data;
        size_t size;
        template<size_t N>
        StringLiteral(StringLiteralHelper<N> const& s) noexcept // NOLINT(google-explicit-constructor)
                : data(s), size(N - 1) {
        }
    };

public:
    using CullingMode = filament::backend::CullingMode;
    using TransparencyMode = filament::TransparencyMode;
    using DepthFunc = filament::backend::SamplerCompareFunc;
    using StencilCompareFunc = filament::backend::SamplerCompareFunc;
    using StencilOperation = filament::backend::StencilOperation;
    using StencilFace = filament::backend::StencilFace;

    template<typename T>
    using is_supported_parameter_t = typename std::enable_if<
            std::is_same<float, T>::value ||
            std::is_same<int32_t, T>::value ||
            std::is_same<uint32_t, T>::value ||
            std::is_same<math::int2, T>::value ||
            std::is_same<math::int3, T>::value ||
            std::is_same<math::int4, T>::value ||
            std::is_same<math::uint2, T>::value ||
            std::is_same<math::uint3, T>::value ||
            std::is_same<math::uint4, T>::value ||
            std::is_same<math::float2, T>::value ||
            std::is_same<math::float3, T>::value ||
            std::is_same<math::float4, T>::value ||
            std::is_same<math::mat4f, T>::value ||
            // these types are slower as they need a layout conversion
            std::is_same<bool, T>::value ||
            std::is_same<math::bool2, T>::value ||
            std::is_same<math::bool3, T>::value ||
            std::is_same<math::bool4, T>::value ||
            std::is_same<math::mat3f, T>::value
    >::type;

    static MaterialInstance* UTILS_NONNULL duplicate(MaterialInstance const* UTILS_NONNULL other,
            const char* UTILS_NULLABLE name = nullptr) noexcept;

    Material const* UTILS_NONNULL getMaterial() const noexcept;

    const char* UTILS_NONNULL getName() const noexcept;

    template<typename T, typename = is_supported_parameter_t<T>>
    void setParameter(const char* UTILS_NONNULL name, size_t nameLength, T const& value);

    template<typename T, typename = is_supported_parameter_t<T>>
    inline void setParameter(const char* UTILS_NONNULL name, T const& value) {
        setParameter<T>(name, strlen(name), value);
    }


    template<typename T, typename = is_supported_parameter_t<T>>
    void setParameter(const char* UTILS_NONNULL name, size_t nameLength,
            const T* UTILS_NONNULL values, size_t count);

    template<typename T, typename = is_supported_parameter_t<T>>
    inline void setParameter(const char* UTILS_NONNULL name,
            const T* UTILS_NONNULL values, size_t count) {
        setParameter<T>(name, strlen(name), values, count);
    }


    void setParameter(const char* UTILS_NONNULL name, size_t nameLength,
            Texture const* UTILS_NULLABLE texture, TextureSampler const& sampler);

    inline void setParameter(const char* UTILS_NONNULL name,
            Texture const* UTILS_NULLABLE texture, TextureSampler const& sampler) {
        setParameter(name, strlen(name), texture, sampler);
    }


    void setParameter(const char* UTILS_NONNULL name, size_t nameLength,
            RgbType type, math::float3 color);

    inline void setParameter(const char* UTILS_NONNULL name, RgbType type, math::float3 color) {
        setParameter(name, strlen(name), type, color);
    }


    void setParameter(const char* UTILS_NONNULL name, size_t nameLength,
            RgbaType type, math::float4 color);

    inline void setParameter(const char* UTILS_NONNULL name, RgbaType type, math::float4 color) {
        setParameter(name, strlen(name), type, color);
    }

    template<typename T>
    T getParameter(const char* UTILS_NONNULL name, size_t nameLength) const;

    template<typename T, typename = is_supported_parameter_t<T>>
    inline T getParameter(const char* UTILS_NONNULL name) const {
        return getParameter<T>(name, strlen(name));
    }

    void setScissor(uint32_t left, uint32_t bottom, uint32_t width, uint32_t height) noexcept;

    void unsetScissor() noexcept;

    void setPolygonOffset(float scale, float constant) noexcept;

    void setMaskThreshold(float threshold) noexcept;

    float getMaskThreshold() const noexcept;

    void setSpecularAntiAliasingVariance(float variance) noexcept;

    float getSpecularAntiAliasingVariance() const noexcept;

    void setSpecularAntiAliasingThreshold(float threshold) noexcept;

    float getSpecularAntiAliasingThreshold() const noexcept;

    void setDoubleSided(bool doubleSided) noexcept;

    bool isDoubleSided() const noexcept;

    void setTransparencyMode(TransparencyMode mode) noexcept;

    TransparencyMode getTransparencyMode() const noexcept;

    void setCullingMode(CullingMode culling) noexcept;

    CullingMode getCullingMode() const noexcept;

    void setColorWrite(bool enable) noexcept;

    bool isColorWriteEnabled() const noexcept;

    void setDepthWrite(bool enable) noexcept;

    bool isDepthWriteEnabled() const noexcept;

    void setDepthCulling(bool enable) noexcept;

    void setDepthFunc(DepthFunc depthFunc) noexcept;

    DepthFunc getDepthFunc() const noexcept;

    bool isDepthCullingEnabled() const noexcept;

    void setStencilWrite(bool enable) noexcept;

    bool isStencilWriteEnabled() const noexcept;

    void setStencilCompareFunction(StencilCompareFunc func,
            StencilFace face = StencilFace::FRONT_AND_BACK) noexcept;

    void setStencilOpStencilFail(StencilOperation op,
            StencilFace face = StencilFace::FRONT_AND_BACK) noexcept;

    void setStencilOpDepthFail(StencilOperation op,
            StencilFace face = StencilFace::FRONT_AND_BACK) noexcept;

    void setStencilOpDepthStencilPass(StencilOperation op,
            StencilFace face = StencilFace::FRONT_AND_BACK) noexcept;

    void setStencilReferenceValue(uint8_t value,
            StencilFace face = StencilFace::FRONT_AND_BACK) noexcept;

    void setStencilReadMask(uint8_t readMask,
            StencilFace face = StencilFace::FRONT_AND_BACK) noexcept;

    void setStencilWriteMask(uint8_t writeMask,
            StencilFace face = StencilFace::FRONT_AND_BACK) noexcept;

protected:
    // prevent heap allocation
    ~MaterialInstance() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_MATERIALINSTANCE_H

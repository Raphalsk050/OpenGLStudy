
#ifndef TNT_FILAMENT_MATERIAL_H
#define TNT_FILAMENT_MATERIAL_H

#include <filament/Color.h>
#include <filament/FilamentAPI.h>
#include <filament/MaterialEnums.h>
#include <filament/MaterialInstance.h>

#include <backend/CallbackHandler.h>
#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Invocable.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <type_traits>
#include <utility>

#include <stddef.h>
#include <stdint.h>
#include <string.h>

namespace utils {
    class CString;
} // namespace utils

namespace filament {

class Texture;
class TextureSampler;

class FEngine;
class FMaterial;

class Engine;

class UTILS_PUBLIC Material : public FilamentAPI {
    struct BuilderDetails;

public:
    using BlendingMode = filament::BlendingMode;
    using Shading = filament::Shading;
    using Interpolation = filament::Interpolation;
    using VertexDomain = filament::VertexDomain;
    using TransparencyMode = filament::TransparencyMode;

    using ParameterType = backend::UniformType;
    using Precision = backend::Precision;
    using SamplerType = backend::SamplerType;
    using SamplerFormat = backend::SamplerFormat;
    using CullingMode = backend::CullingMode;
    using ShaderModel = backend::ShaderModel;
    using SubpassType = backend::SubpassType;

    struct ParameterInfo {
        //! Name of the parameter.
        const char* UTILS_NONNULL name;
        //! Whether the parameter is a sampler (texture).
        bool isSampler;
        //! Whether the parameter is a subpass type.
        bool isSubpass;
        union {
            //! Type of the parameter if the parameter is not a sampler.
            ParameterType type;
            //! Type of the parameter if the parameter is a sampler.
            SamplerType samplerType;
            //! Type of the parameter if the parameter is a subpass.
            SubpassType subpassType;
        };
        //! Size of the parameter when the parameter is an array.
        uint32_t count;
        //! Requested precision of the parameter.
        Precision precision;
    };

    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& package(const void* UTILS_NONNULL payload, size_t size);

        template<typename T>
        using is_supported_constant_parameter_t = typename std::enable_if<
                std::is_same<int32_t, T>::value ||
                std::is_same<float, T>::value ||
                std::is_same<bool, T>::value>::type;

        template<typename T, typename = is_supported_constant_parameter_t<T>>
        Builder& constant(const char* UTILS_NONNULL name, size_t nameLength, T value);

        Builder& sphericalHarmonicsBandCount(size_t shBandCount) noexcept;

        Material* UTILS_NULLABLE build(Engine& engine);
    private:
        friend class FMaterial;
    };

    using CompilerPriorityQueue = backend:: CompilerPriorityQueue;

    void compile(CompilerPriorityQueue priority,
            UserVariantFilterMask variants,
            backend::CallbackHandler* UTILS_NULLABLE handler = nullptr,
            utils::Invocable<void(Material* UTILS_NONNULL)>&& callback = {}) noexcept;

    inline void compile(CompilerPriorityQueue priority,
            UserVariantFilterBit variants,
            backend::CallbackHandler* UTILS_NULLABLE handler = nullptr,
            utils::Invocable<void(Material* UTILS_NONNULL)>&& callback = {}) noexcept {
        compile(priority, UserVariantFilterMask(variants), handler,
                std::forward<utils::Invocable<void(Material* UTILS_NONNULL)>>(callback));
    }

    inline void compile(CompilerPriorityQueue priority,
            backend::CallbackHandler* UTILS_NULLABLE handler = nullptr,
            utils::Invocable<void(Material* UTILS_NONNULL)>&& callback = {}) noexcept {
        compile(priority, UserVariantFilterBit::ALL, handler,
                std::forward<utils::Invocable<void(Material* UTILS_NONNULL)>>(callback));
    }

    MaterialInstance* UTILS_NONNULL createInstance(const char* UTILS_NULLABLE name = nullptr) const noexcept;

    //! Returns the name of this material as a null-terminated string.
    const char* UTILS_NONNULL getName() const noexcept;

    //! Returns the shading model of this material.
    Shading getShading() const noexcept;

    //! Returns the interpolation mode of this material. This affects how variables are interpolated.
    Interpolation getInterpolation() const noexcept;

    //! Returns the blending mode of this material.
    BlendingMode getBlendingMode() const noexcept;

    //! Returns the vertex domain of this material.
    VertexDomain getVertexDomain() const noexcept;

    //! Returns the material's supported variants
    UserVariantFilterMask getSupportedVariants() const noexcept;

    //! Returns the material domain of this material.
    //! The material domain determines how the material is used.
    MaterialDomain getMaterialDomain() const noexcept;

    //! Returns the default culling mode of this material.
    CullingMode getCullingMode() const noexcept;

    //! Returns the transparency mode of this material.
    //! This value only makes sense when the blending mode is transparent or fade.
    TransparencyMode getTransparencyMode() const noexcept;

    //! Indicates whether instances of this material will, by default, write to the color buffer.
    bool isColorWriteEnabled() const noexcept;

    //! Indicates whether instances of this material will, by default, write to the depth buffer.
    bool isDepthWriteEnabled() const noexcept;

    //! Indicates whether instances of this material will, by default, use depth testing.
    bool isDepthCullingEnabled() const noexcept;

    //! Indicates whether this material is double-sided.
    bool isDoubleSided() const noexcept;

    //! Indicates whether this material uses alpha to coverage.
    bool isAlphaToCoverageEnabled() const noexcept;

    //! Returns the alpha mask threshold used when the blending mode is set to masked.
    float getMaskThreshold() const noexcept;

    //! Indicates whether this material uses the shadowing factor as a color multiplier.
    //! This values only makes sense when the shading mode is unlit.
    bool hasShadowMultiplier() const noexcept;

    //! Indicates whether this material has specular anti-aliasing enabled
    bool hasSpecularAntiAliasing() const noexcept;

    //! Returns the screen-space variance for specular-antialiasing, this value is between 0 and 1.
    float getSpecularAntiAliasingVariance() const noexcept;

    //! Returns the clamping threshold for specular-antialiasing, this value is between 0 and 1.
    float getSpecularAntiAliasingThreshold() const noexcept;

    //! Returns the list of vertex attributes required by this material.
    AttributeBitset getRequiredAttributes() const noexcept;

    //! Returns the refraction mode used by this material.
    RefractionMode getRefractionMode() const noexcept;

    //! Return the refraction type used by this material.
    RefractionType getRefractionType() const noexcept;

    //! Returns the reflection mode used by this material.
    ReflectionMode getReflectionMode() const noexcept;

    //! Returns the minimum required feature level for this material.
    backend::FeatureLevel getFeatureLevel() const noexcept;

    size_t getParameterCount() const noexcept;

    size_t getParameters(ParameterInfo* UTILS_NONNULL parameters, size_t count) const noexcept;

    //! Indicates whether a parameter of the given name exists on this material.
    bool hasParameter(const char* UTILS_NONNULL name) const noexcept;

    //! Indicates whether an existing parameter is a sampler or not.
    bool isSampler(const char* UTILS_NONNULL name) const noexcept;

    template <typename T>
    void setDefaultParameter(const char* UTILS_NONNULL name, T value) noexcept {
        getDefaultInstance()->setParameter(name, value);
    }

    void setDefaultParameter(const char* UTILS_NONNULL name,
            Texture const* UTILS_NULLABLE texture, TextureSampler const& sampler) noexcept {
        getDefaultInstance()->setParameter(name, texture, sampler);
    }

    void setDefaultParameter(const char* UTILS_NONNULL name, RgbType type, math::float3 color) noexcept {
        getDefaultInstance()->setParameter(name, type, color);
    }

    void setDefaultParameter(const char* UTILS_NONNULL name, RgbaType type, math::float4 color) noexcept {
        getDefaultInstance()->setParameter(name, type, color);
    }

    //! Returns this material's default instance.
    MaterialInstance* UTILS_NONNULL getDefaultInstance() noexcept;

    //! Returns this material's default instance.
    MaterialInstance const* UTILS_NONNULL getDefaultInstance() const noexcept;

protected:
    // prevent heap allocation
    ~Material() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_MATERIAL_H

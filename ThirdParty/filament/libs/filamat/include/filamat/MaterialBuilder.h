
//! \file

#ifndef TNT_FILAMAT_MATERIAL_PACKAGE_BUILDER_H
#define TNT_FILAMAT_MATERIAL_PACKAGE_BUILDER_H

#include <filament/MaterialEnums.h>

#include <filamat/IncludeCallback.h>
#include <filamat/Package.h>

#include <backend/DriverEnums.h>
#include <backend/TargetBufferInfo.h>

#include "third_party/filament/libs/utils/include/utils/BitmaskEnum.h"
#include "third_party/filament/libs/utils/include/utils/bitset.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/CString.h"

#include "third_party/filament/libs/math/include/math/vec3.h"

#include <atomic>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <variant>

#include <stddef.h>
#include <stdint.h>

namespace utils {
class JobSystem;
}

namespace filament {
class BufferInterfaceBlock;
}

namespace filamat {

struct MaterialInfo;
struct Variant;
class ChunkContainer;

class UTILS_PUBLIC MaterialBuilderBase {
public:
    enum class Platform {
        DESKTOP,
        MOBILE,
        ALL
    };

    enum class TargetApi : uint8_t {
        OPENGL      = 0x01u,
        VULKAN      = 0x02u,
        METAL       = 0x04u,
        ALL         = OPENGL | VULKAN | METAL
    };

    enum class TargetLanguage {
        GLSL,           // GLSL with OpenGL 4.1 / OpenGL ES 3.0 semantics
        SPIRV           // GLSL with Vulkan semantics
    };

    enum class Optimization {
        NONE,
        PREPROCESSOR,
        SIZE,
        PERFORMANCE
    };

    static void init();

    static void shutdown();

protected:
    // Looks at platform and target API, then decides on shader models and output formats.
    void prepare(bool vulkanSemantics, filament::backend::FeatureLevel featureLevel);

    using ShaderModel = filament::backend::ShaderModel;
    Platform mPlatform = Platform::DESKTOP;
    TargetApi mTargetApi = (TargetApi) 0;
    Optimization mOptimization = Optimization::PERFORMANCE;
    bool mPrintShaders = false;
    bool mGenerateDebugInfo = false;
    bool mIncludeEssl1 = true;
    utils::bitset32 mShaderModels;
    struct CodeGenParams {
        ShaderModel shaderModel;
        TargetApi targetApi;
        TargetLanguage targetLanguage;
        filament::backend::FeatureLevel featureLevel;
    };
    std::vector<CodeGenParams> mCodeGenPermutations;

    // Keeps track of how many times MaterialBuilder::init() has been called without a call to
    // MaterialBuilder::shutdown(). Internally, glslang does something similar. We keep track for
    // ourselves, so we can inform the user if MaterialBuilder::init() hasn't been called before
    // attempting to build a material.
    static std::atomic<int> materialBuilderClients;
};

// Utility function that looks at an Engine backend to determine TargetApi
inline constexpr MaterialBuilderBase::TargetApi targetApiFromBackend(
        filament::backend::Backend backend) noexcept {
    using filament::backend::Backend;
    using TargetApi = MaterialBuilderBase::TargetApi;
    switch (backend) {
        case Backend::DEFAULT: return TargetApi::ALL;
        case Backend::OPENGL:  return TargetApi::OPENGL;
        case Backend::VULKAN:  return TargetApi::VULKAN;
        case Backend::METAL:   return TargetApi::METAL;
        case Backend::NOOP:    return TargetApi::OPENGL;
    }
}

class UTILS_PUBLIC MaterialBuilder : public MaterialBuilderBase {
public:
    MaterialBuilder();
    ~MaterialBuilder();

    MaterialBuilder(const MaterialBuilder& rhs) = delete;
    MaterialBuilder& operator=(const MaterialBuilder& rhs) = delete;

    MaterialBuilder(MaterialBuilder&& rhs) noexcept = default;
    MaterialBuilder& operator=(MaterialBuilder&& rhs) noexcept = default;

    static constexpr size_t MATERIAL_VARIABLES_COUNT = 4;
    enum class Variable : uint8_t {
        CUSTOM0,
        CUSTOM1,
        CUSTOM2,
        CUSTOM3
        // when adding more variables, make sure to update MATERIAL_VARIABLES_COUNT
    };

    using MaterialDomain = filament::MaterialDomain;
    using RefractionMode = filament::RefractionMode;
    using RefractionType = filament::RefractionType;
    using ReflectionMode = filament::ReflectionMode;
    using VertexAttribute = filament::VertexAttribute;

    using ShaderQuality = filament::ShaderQuality;
    using BlendingMode = filament::BlendingMode;
    using BlendFunction = filament::backend::BlendFunction;
    using Shading = filament::Shading;
    using Interpolation = filament::Interpolation;
    using VertexDomain = filament::VertexDomain;
    using TransparencyMode = filament::TransparencyMode;
    using SpecularAmbientOcclusion = filament::SpecularAmbientOcclusion;

    using AttributeType = filament::backend::UniformType;
    using UniformType = filament::backend::UniformType;
    using ConstantType = filament::backend::ConstantType;
    using SamplerType = filament::backend::SamplerType;
    using SubpassType = filament::backend::SubpassType;
    using SamplerFormat = filament::backend::SamplerFormat;
    using ParameterPrecision = filament::backend::Precision;
    using Precision = filament::backend::Precision;
    using CullingMode = filament::backend::CullingMode;
    using FeatureLevel = filament::backend::FeatureLevel;
    using StereoscopicType = filament::backend::StereoscopicType;
    using ShaderStage = filament::backend::ShaderStage;

    enum class VariableQualifier : uint8_t {
        OUT
    };

    enum class OutputTarget : uint8_t {
        COLOR,
        DEPTH
    };

    enum class OutputType : uint8_t {
        FLOAT,
        FLOAT2,
        FLOAT3,
        FLOAT4
    };

    struct PreprocessorDefine {
        std::string name;
        std::string value;

        PreprocessorDefine(std::string  name, std::string  value) :
                name(std::move(name)), value(std::move(value)) {}
    };
    using PreprocessorDefineList = std::vector<PreprocessorDefine>;


    MaterialBuilder& noSamplerValidation(bool enabled) noexcept;

    //! Enable generation of ESSL 1.0 code in FL0 materials.
    MaterialBuilder& includeEssl1(bool enabled) noexcept;

    //! Set the name of this material.
    MaterialBuilder& name(const char* name) noexcept;

    //! Set the file name of this material file. Used in error reporting.
    MaterialBuilder& fileName(const char* name) noexcept;

    //! Set the shading model.
    MaterialBuilder& shading(Shading shading) noexcept;

    //! Set the interpolation mode.
    MaterialBuilder& interpolation(Interpolation interpolation) noexcept;

    //! Add a parameter (i.e., a uniform) to this material.
    MaterialBuilder& parameter(const char* name, UniformType type,
            ParameterPrecision precision = ParameterPrecision::DEFAULT) noexcept;

    //! Add a parameter array to this material.
    MaterialBuilder& parameter(const char* name, size_t size, UniformType type,
            ParameterPrecision precision = ParameterPrecision::DEFAULT) noexcept;

    //! Add a constant parameter to this material.
    template<typename T>
    using is_supported_constant_parameter_t = typename std::enable_if<
            std::is_same<int32_t, T>::value ||
            std::is_same<float, T>::value ||
            std::is_same<bool, T>::value>::type;
    template<typename T, typename = is_supported_constant_parameter_t<T>>
    MaterialBuilder& constant(const char *name, ConstantType type, T defaultValue = 0);

    MaterialBuilder& parameter(const char* name, SamplerType samplerType,
            SamplerFormat format = SamplerFormat::FLOAT,
            ParameterPrecision precision = ParameterPrecision::DEFAULT,
            bool multisample = false) noexcept;

    MaterialBuilder& buffer(filament::BufferInterfaceBlock bib) noexcept;

    //! Custom variables (all float4).
    MaterialBuilder& variable(Variable v, const char* name) noexcept;

    MaterialBuilder& require(VertexAttribute attribute) noexcept;

    //! Specify the domain that this material will operate in.
    MaterialBuilder& materialDomain(MaterialBuilder::MaterialDomain materialDomain) noexcept;

    MaterialBuilder& material(const char* code, size_t line = 0) noexcept;

    MaterialBuilder& includeCallback(IncludeCallback callback) noexcept;

    MaterialBuilder& materialVertex(const char* code, size_t line = 0) noexcept;


    MaterialBuilder& quality(ShaderQuality quality) noexcept;

    MaterialBuilder& featureLevel(FeatureLevel featureLevel) noexcept;

    MaterialBuilder& blending(BlendingMode blending) noexcept;

    MaterialBuilder& customBlendFunctions(
            BlendFunction srcRGB,
            BlendFunction srcA,
            BlendFunction dstRGB,
            BlendFunction dstA) noexcept;

    MaterialBuilder& postLightingBlending(BlendingMode blending) noexcept;

    //! Set the vertex domain for this material.
    MaterialBuilder& vertexDomain(VertexDomain domain) noexcept;

    MaterialBuilder& culling(CullingMode culling) noexcept;

    //! Enable / disable color-buffer write (enabled by default, material instances can override).
    MaterialBuilder& colorWrite(bool enable) noexcept;

    //! Enable / disable depth-buffer write (enabled by default for opaque, disabled for others, material instances can override).
    MaterialBuilder& depthWrite(bool enable) noexcept;

    //! Enable / disable depth based culling (enabled by default, material instances can override).
    MaterialBuilder& depthCulling(bool enable) noexcept;

    //! Enable / disable instanced primitives (disabled by default).
    MaterialBuilder& instanced(bool enable) noexcept;

    MaterialBuilder& doubleSided(bool doubleSided) noexcept;

    MaterialBuilder& maskThreshold(float threshold) noexcept;

    MaterialBuilder& alphaToCoverage(bool enable) noexcept;

    //! The material output is multiplied by the shadowing factor (UNLIT model only).
    MaterialBuilder& shadowMultiplier(bool shadowMultiplier) noexcept;

    //! This material casts transparent shadows. The blending mode must be TRANSPARENT or FADE.
    MaterialBuilder& transparentShadow(bool transparentShadow) noexcept;

    MaterialBuilder& specularAntiAliasing(bool specularAntiAliasing) noexcept;

    MaterialBuilder& specularAntiAliasingVariance(float screenSpaceVariance) noexcept;

    MaterialBuilder& specularAntiAliasingThreshold(float threshold) noexcept;

    MaterialBuilder& clearCoatIorChange(bool clearCoatIorChange) noexcept;

    //! Enable / disable flipping of the Y coordinate of UV attributes, enabled by default.
    MaterialBuilder& flipUV(bool flipUV) noexcept;

    //! Enable / disable multi-bounce ambient occlusion, disabled by default on mobile.
    MaterialBuilder& multiBounceAmbientOcclusion(bool multiBounceAO) noexcept;

    //! Set the specular ambient occlusion technique. Disabled by default on mobile.
    MaterialBuilder& specularAmbientOcclusion(SpecularAmbientOcclusion specularAO) noexcept;

    //! Specify the refraction
    MaterialBuilder& refractionMode(RefractionMode refraction) noexcept;

    //! Specify the refraction type
    MaterialBuilder& refractionType(RefractionType refractionType) noexcept;

    //! Specifies how reflections should be rendered (default is DEFAULT).
    MaterialBuilder& reflectionMode(ReflectionMode mode) noexcept;

    //! Specifies how transparent objects should be rendered (default is DEFAULT).
    MaterialBuilder& transparencyMode(TransparencyMode mode) noexcept;

    //! Specify the stereoscopic type (default is INSTANCED)
    MaterialBuilder& stereoscopicType(StereoscopicType stereoscopicType) noexcept;

    //! Specify the number of eyes for stereoscopic rendering
    MaterialBuilder& stereoscopicEyeCount(uint8_t eyeCount) noexcept;

    MaterialBuilder& customSurfaceShading(bool customSurfaceShading) noexcept;

    MaterialBuilder& platform(Platform platform) noexcept;

    MaterialBuilder& targetApi(TargetApi targetApi) noexcept;

    MaterialBuilder& optimization(Optimization optimization) noexcept;

    // TODO: this is present here for matc's "--print" flag, but ideally does not belong inside
    // MaterialBuilder.
    //! If true, will output the generated GLSL shader code to stdout.
    MaterialBuilder& printShaders(bool printShaders) noexcept;

    //! If true, will include debugging information in generated SPIRV.
    MaterialBuilder& generateDebugInfo(bool generateDebugInfo) noexcept;

    //! Specifies a list of variants that should be filtered out during code generation.
    MaterialBuilder& variantFilter(filament::UserVariantFilterMask variantFilter) noexcept;

    //! Adds a new preprocessor macro definition to the shader code. Can be called repeatedly.
    MaterialBuilder& shaderDefine(const char* name, const char* value) noexcept;

    //! Add a new fragment shader output variable. Only valid for materials in the POST_PROCESS domain.
    MaterialBuilder& output(VariableQualifier qualifier, OutputTarget target, Precision precision,
            OutputType type, const char* name, int location = -1) noexcept;

    MaterialBuilder& enableFramebufferFetch() noexcept;

    MaterialBuilder& vertexDomainDeviceJittered(bool enabled) noexcept;

    MaterialBuilder& useLegacyMorphing() noexcept;

    //! specify compute kernel group size
    MaterialBuilder& groupSize(filament::math::uint3 groupSize) noexcept;

    Package build(utils::JobSystem& jobSystem) noexcept;

public:
    // The methods and types below are for internal use
    /// @cond never

    MaterialBuilder& subpass(SubpassType subpassType,
            SamplerFormat format, ParameterPrecision precision, const char* name) noexcept;
    MaterialBuilder& subpass(SubpassType subpassType,
            SamplerFormat format, const char* name) noexcept;
    MaterialBuilder& subpass(SubpassType subpassType,
            ParameterPrecision precision, const char* name) noexcept;
    MaterialBuilder& subpass(SubpassType subpassType, const char* name) noexcept;

    struct Parameter {
        Parameter() noexcept: parameterType(INVALID) {}

        // Sampler
        Parameter(const char* paramName, SamplerType t, SamplerFormat f, ParameterPrecision p, bool ms)
                : name(paramName), size(1), precision(p), samplerType(t), format(f), parameterType(SAMPLER), multisample(ms) { }

        // Uniform
        Parameter(const char* paramName, UniformType t, size_t typeSize, ParameterPrecision p)
                : name(paramName), size(typeSize), uniformType(t), precision(p), parameterType(UNIFORM) { }

        // Subpass
        Parameter(const char* paramName, SubpassType t, SamplerFormat f, ParameterPrecision p)
                : name(paramName), size(1), precision(p), subpassType(t), format(f), parameterType(SUBPASS) { }

        utils::CString name;
        size_t size;
        UniformType uniformType;
        ParameterPrecision precision;
        SamplerType samplerType;
        SubpassType subpassType;
        SamplerFormat format;
        bool multisample;
        enum {
            INVALID,
            UNIFORM,
            SAMPLER,
            SUBPASS
        } parameterType;

        bool isSampler() const { return parameterType == SAMPLER; }
        bool isUniform() const { return parameterType == UNIFORM; }
        bool isSubpass() const { return parameterType == SUBPASS; }
    };

    struct Output {
        Output() noexcept = default;
        Output(const char* outputName, VariableQualifier qualifier, OutputTarget target,
                Precision precision, OutputType type, int location) noexcept
                : name(outputName), qualifier(qualifier), target(target), precision(precision),
                  type(type), location(location) { }

        utils::CString name;
        VariableQualifier qualifier;
        OutputTarget target;
        Precision precision;
        OutputType type;
        int location;
    };

    struct Constant {
        utils::CString name;
        ConstantType type;
        union {
            int32_t i;
            float f;
            bool b;
        } defaultValue;
    };

    struct PushConstant {
        utils::CString name;
        ConstantType type;
        ShaderStage stage;
    };

    static constexpr size_t MATERIAL_PROPERTIES_COUNT = filament::MATERIAL_PROPERTIES_COUNT;
    using Property = filament::Property;

    using PropertyList = bool[MATERIAL_PROPERTIES_COUNT];
    using VariableList = utils::CString[MATERIAL_VARIABLES_COUNT];
    using OutputList = std::vector<Output>;

    static constexpr size_t MAX_COLOR_OUTPUT = filament::backend::MRT::MAX_SUPPORTED_RENDER_TARGET_COUNT;
    static constexpr size_t MAX_DEPTH_OUTPUT = 1;
    static_assert(MAX_COLOR_OUTPUT == 8,
            "When updating MRT::MAX_SUPPORTED_RENDER_TARGET_COUNT, manually update post_process_inputs.fs"
            " and post_process.fs");

    // Preview the first shader generated by the given CodeGenParams.
    // This is used to run Static Code Analysis before generating a package.
    std::string peek(filament::backend::ShaderStage type,
            const CodeGenParams& params, const PropertyList& properties) noexcept;

    // Returns true if any of the parameter samplers matches the specified type.
    bool hasSamplerType(SamplerType samplerType) const noexcept;

    static constexpr size_t MAX_PARAMETERS_COUNT = 48;
    static constexpr size_t MAX_SUBPASS_COUNT = 1;
    static constexpr size_t MAX_BUFFERS_COUNT = 4;
    using ParameterList = Parameter[MAX_PARAMETERS_COUNT];
    using SubpassList = Parameter[MAX_SUBPASS_COUNT];
    using BufferList = std::vector<std::unique_ptr<filament::BufferInterfaceBlock>>;
    using ConstantList = std::vector<Constant>;
    using PushConstantList = std::vector<PushConstant>;

    // returns the number of parameters declared in this material
    uint8_t getParameterCount() const noexcept { return mParameterCount; }

    // returns a list of at least getParameterCount() parameters
    const ParameterList& getParameters() const noexcept { return mParameters; }

    // returns the number of parameters declared in this material
    uint8_t getSubpassCount() const noexcept { return mSubpassCount; }

    // returns a list of at least getParameterCount() parameters
    const SubpassList& getSubPasses() const noexcept { return mSubpasses; }

    filament::UserVariantFilterMask getVariantFilter() const { return mVariantFilter; }

    FeatureLevel getFeatureLevel() const noexcept { return mFeatureLevel; }
    /// @endcond

    struct Attribute {
        std::string_view name;
        AttributeType type;
        MaterialBuilder::VertexAttribute location;
        std::string getAttributeName() const noexcept {
            return "mesh_" + std::string{ name };
        }
        std::string getDefineName() const noexcept {
            std::string uppercase{ name };
            transform(uppercase.cbegin(), uppercase.cend(), uppercase.begin(), ::toupper);
            return "HAS_ATTRIBUTE_" + uppercase;
        }
    };

    using AttributeDatabase = std::array<Attribute, filament::backend::MAX_VERTEX_ATTRIBUTE_COUNT>;

    static inline AttributeDatabase const& getAttributeDatabase() noexcept {
        return sAttributeDatabase;
    }

private:
    static const AttributeDatabase sAttributeDatabase;

    void prepareToBuild(MaterialInfo& info) noexcept;

    // Initialize internal push constants that will both be written to the shaders and material
    // chunks (like user-defined spec constants).
    void initPushConstants() noexcept;

    // Return true if the shader is syntactically and semantically valid.
    // This method finds all the properties defined in the fragment and
    // vertex shaders of the material.
    bool findAllProperties(CodeGenParams const& semanticCodeGenParams) noexcept;

    // Multiple calls to findProperties accumulate the property sets across fragment
    // and vertex shaders in mProperties.
    bool findProperties(filament::backend::ShaderStage type,
            MaterialBuilder::PropertyList& allProperties,
            CodeGenParams const& semanticCodeGenParams) noexcept;

    bool runSemanticAnalysis(MaterialInfo* inOutInfo,
            CodeGenParams const& semanticCodeGenParams) noexcept;

    bool checkLiteRequirements() noexcept;

    bool checkMaterialLevelFeatures(MaterialInfo const& info) const noexcept;

    void writeCommonChunks(ChunkContainer& container, MaterialInfo& info) const noexcept;
    void writeSurfaceChunks(ChunkContainer& container) const noexcept;

    bool generateShaders(
            utils::JobSystem& jobSystem,
            const std::vector<filamat::Variant>& variants, ChunkContainer& container,
            const MaterialInfo& info) const noexcept;

    bool hasCustomVaryings() const noexcept;
    bool needsStandardDepthProgram() const noexcept;

    bool isLit() const noexcept { return mShading != filament::Shading::UNLIT; }

    utils::CString mMaterialName;
    utils::CString mFileName;

    class ShaderCode {
    public:
        void setLineOffset(size_t offset) noexcept { mLineOffset = offset; }
        void setUnresolved(const utils::CString& code) noexcept {
            mIncludesResolved = false;
            mCode = code;
        }

        // Resolve all the #include directives, returns true if successful.
        bool resolveIncludes(IncludeCallback callback, const utils::CString& fileName) noexcept;

        const utils::CString& getResolved() const noexcept {
            assert(mIncludesResolved);
            return mCode;
        }

        size_t getLineOffset() const noexcept { return mLineOffset; }

    private:
        utils::CString mCode;
        size_t mLineOffset = 0;
        bool mIncludesResolved = false;
    };

    ShaderCode mMaterialFragmentCode;
    ShaderCode mMaterialVertexCode;

    IncludeCallback mIncludeCallback = nullptr;

    PropertyList mProperties;
    ParameterList mParameters;
    ConstantList mConstants;
    PushConstantList mPushConstants;
    SubpassList mSubpasses;
    VariableList mVariables;
    OutputList mOutputs;
    BufferList mBuffers;

    ShaderQuality mShaderQuality = ShaderQuality::DEFAULT;
    FeatureLevel mFeatureLevel = FeatureLevel::FEATURE_LEVEL_1;
    BlendingMode mBlendingMode = BlendingMode::OPAQUE;
    BlendingMode mPostLightingBlendingMode = BlendingMode::TRANSPARENT;
    std::array<BlendFunction, 4> mCustomBlendFunctions = {};
    CullingMode mCullingMode = CullingMode::BACK;
    Shading mShading = Shading::LIT;
    MaterialDomain mMaterialDomain = MaterialDomain::SURFACE;
    RefractionMode mRefractionMode = RefractionMode::NONE;
    RefractionType mRefractionType = RefractionType::SOLID;
    ReflectionMode mReflectionMode = ReflectionMode::DEFAULT;
    Interpolation mInterpolation = Interpolation::SMOOTH;
    VertexDomain mVertexDomain = VertexDomain::OBJECT;
    TransparencyMode mTransparencyMode = TransparencyMode::DEFAULT;
    StereoscopicType mStereoscopicType = StereoscopicType::INSTANCED;
    uint8_t mStereoscopicEyeCount = 2;

    filament::AttributeBitset mRequiredAttributes;

    float mMaskThreshold = 0.4f;
    float mSpecularAntiAliasingVariance = 0.15f;
    float mSpecularAntiAliasingThreshold = 0.2f;

    filament::math::uint3 mGroupSize = { 1, 1, 1 };

    bool mShadowMultiplier = false;
    bool mTransparentShadow = false;

    uint8_t mParameterCount = 0;
    uint8_t mSubpassCount = 0;

    bool mDoubleSided = false;
    bool mDoubleSidedCapability = false;
    bool mColorWrite = true;
    bool mDepthTest = true;
    bool mInstanced = false;
    bool mDepthWrite = true;
    bool mDepthWriteSet = false;
    bool mAlphaToCoverage = false;
    bool mAlphaToCoverageSet = false;

    bool mSpecularAntiAliasing = false;
    bool mClearCoatIorChange = true;

    bool mFlipUV = true;

    bool mMultiBounceAO = false;
    bool mMultiBounceAOSet = false;

    SpecularAmbientOcclusion mSpecularAO = SpecularAmbientOcclusion::NONE;
    bool mSpecularAOSet = false;

    bool mCustomSurfaceShading = false;

    bool mEnableFramebufferFetch = false;

    bool mVertexDomainDeviceJittered = false;

    bool mUseLegacyMorphing = false;

    PreprocessorDefineList mDefines;

    filament::UserVariantFilterMask mVariantFilter = {};

    bool mNoSamplerValidation = false;
};

} // namespace filamat

template<> struct utils::EnableBitMaskOperators<filamat::MaterialBuilder::TargetApi>
        : public std::true_type {};

#endif

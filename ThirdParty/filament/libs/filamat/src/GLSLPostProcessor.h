
#ifndef TNT_GLSLPOSTPROCESSOR_H
#define TNT_GLSLPOSTPROCESSOR_H

#include <filamat/MaterialBuilder.h>    // for MaterialBuilder:: enums

#include <private/filament/Variant.h>

#include "ShaderMinifier.h"

#include <spirv-tools/optimizer.hpp>

#include "glslang/Public/ShaderLang.h"

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

#include <memory>
#include <string>
#include <vector>

namespace filament {
class SamplerInterfaceBlock;
};

namespace filamat {

using SpirvBlob = std::vector<uint32_t>;
using BindingPointAndSib = std::pair<uint8_t, const filament::SamplerInterfaceBlock*>;
using SibVector = utils::FixedCapacityVector<BindingPointAndSib>;

class GLSLPostProcessor {
public:
    enum Flags : uint32_t {
        PRINT_SHADERS = 1 << 0,
        GENERATE_DEBUG_INFO = 1 << 1,
    };

    GLSLPostProcessor(MaterialBuilder::Optimization optimization, uint32_t flags);

    ~GLSLPostProcessor();

    struct Config {
        filament::Variant variant;
        MaterialBuilder::TargetApi targetApi;
        MaterialBuilder::TargetLanguage targetLanguage;
        filament::backend::ShaderStage shaderType;
        filament::backend::ShaderModel shaderModel;
        filament::backend::FeatureLevel featureLevel;
        filament::MaterialDomain domain;
        const filamat::MaterialInfo* materialInfo;
        bool hasFramebufferFetch;
        bool usesClipDistance;
        struct {
            std::vector<std::pair<uint32_t, uint32_t>> subpassInputToColorLocation;
        } glsl;
    };

    bool process(const std::string& inputShader, Config const& config,
            std::string* outputGlsl,
            SpirvBlob* outputSpirv,
            std::string* outputMsl);

    // public so backend_test can also use it
    static void spirvToMsl(const SpirvBlob* spirv, std::string* outMsl,
            filament::backend::ShaderModel shaderModel, bool useFramebufferFetch,
            const SibVector& sibs, const ShaderMinifier* minifier);

private:
    struct InternalConfig {
        std::string* glslOutput = nullptr;
        SpirvBlob* spirvOutput = nullptr;
        std::string* mslOutput = nullptr;
        EShLanguage shLang = EShLangFragment;
        // use 100 for ES environment, 110 for desktop
         int langVersion = 0;
        ShaderMinifier minifier;
    };

    bool fullOptimization(const glslang::TShader& tShader,
            GLSLPostProcessor::Config const& config, InternalConfig& internalConfig) const;

    void preprocessOptimization(glslang::TShader& tShader,
            GLSLPostProcessor::Config const& config, InternalConfig& internalConfig) const;

    using OptimizerPtr = std::shared_ptr<spvtools::Optimizer>;
    static OptimizerPtr createOptimizer(
            MaterialBuilder::Optimization optimization,
            Config const& config);

    static void registerSizePasses(spvtools::Optimizer& optimizer, Config const& config);
    static void registerPerformancePasses(spvtools::Optimizer& optimizer, Config const& config);

    void optimizeSpirv(OptimizerPtr optimizer, SpirvBlob& spirv) const;

    void fixupClipDistance(SpirvBlob& spirv, GLSLPostProcessor::Config const& config) const;

    const MaterialBuilder::Optimization mOptimization;
    const bool mPrintShaders;
    const bool mGenerateDebugInfo;
};

} // namespace filamat

#endif //TNT_GLSLPOSTPROCESSOR_H

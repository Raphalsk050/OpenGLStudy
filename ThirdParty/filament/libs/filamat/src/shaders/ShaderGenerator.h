
#ifndef TNT_FILAMENT_DETAILS_SHADERGENERATOR_H
#define TNT_FILAMENT_DETAILS_SHADERGENERATOR_H


#include "MaterialInfo.h"

#include <filament/MaterialEnums.h>

#include <filamat/MaterialBuilder.h>

#include <private/filament/Variant.h>

#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/sstream.h"

#include <algorithm>

namespace filamat {

class CodeGenerator;

class ShaderGenerator {
public:
    ShaderGenerator(
            MaterialBuilder::PropertyList const& properties,
            MaterialBuilder::VariableList const& variables,
            MaterialBuilder::OutputList const& outputs,
            MaterialBuilder::PreprocessorDefineList const& defines,
            MaterialBuilder::ConstantList const& constants,
            MaterialBuilder::PushConstantList const& pushConstants,
            utils::CString const& materialCode,
            size_t lineOffset,
            utils::CString const& materialVertexCode,
            size_t vertexLineOffset,
            MaterialBuilder::MaterialDomain materialDomain) noexcept;

    std::string createVertexProgram(filament::backend::ShaderModel shaderModel,
            MaterialBuilder::TargetApi targetApi, MaterialBuilder::TargetLanguage targetLanguage,
            MaterialBuilder::FeatureLevel featureLevel,
            MaterialInfo const& material, filament::Variant variant,
            filament::Interpolation interpolation,
            filament::VertexDomain vertexDomain) const noexcept;

    std::string createFragmentProgram(filament::backend::ShaderModel shaderModel,
            MaterialBuilder::TargetApi targetApi, MaterialBuilder::TargetLanguage targetLanguage,
            MaterialBuilder::FeatureLevel featureLevel,
            MaterialInfo const& material, filament::Variant variant,
            filament::Interpolation interpolation) const noexcept;

    std::string createComputeProgram(filament::backend::ShaderModel shaderModel,
            MaterialBuilder::TargetApi targetApi, MaterialBuilder::TargetLanguage targetLanguage,
            MaterialBuilder::FeatureLevel featureLevel,
            MaterialInfo const& material) const noexcept;

    static void fixupExternalSamplers(filament::backend::ShaderModel sm, std::string& shader,
            MaterialBuilder::FeatureLevel featureLevel,
            MaterialInfo const& material) noexcept;

private:
    static void generateVertexDomainDefines(utils::io::sstream& out,
            filament::VertexDomain domain) noexcept;

    static void generateSurfaceMaterialVariantProperties(utils::io::sstream& out,
            MaterialBuilder::PropertyList const properties,
            const MaterialBuilder::PreprocessorDefineList& defines) noexcept;

    static void generateSurfaceMaterialVariantDefines(utils::io::sstream& out,
            filament::backend::ShaderStage stage,
            MaterialBuilder::FeatureLevel featureLevel,
            MaterialInfo const& material, filament::Variant variant) noexcept;

    static void generatePostProcessMaterialVariantDefines(utils::io::sstream& out,
            filament::PostProcessVariant variant) noexcept;

    static void generateUserSpecConstants(
            const CodeGenerator& cg, utils::io::sstream& fs,
            MaterialBuilder::ConstantList const& constants);

    std::string createPostProcessVertexProgram(filament::backend::ShaderModel sm,
            MaterialBuilder::TargetApi targetApi, MaterialBuilder::TargetLanguage targetLanguage,
            MaterialBuilder::FeatureLevel featureLevel,
            MaterialInfo const& material, filament::Variant::type_t variantKey) const noexcept;

    std::string createPostProcessFragmentProgram(filament::backend::ShaderModel sm,
            MaterialBuilder::TargetApi targetApi, MaterialBuilder::TargetLanguage targetLanguage,
            MaterialBuilder::FeatureLevel featureLevel,
            MaterialInfo const& material, uint8_t variant) const noexcept;

    static void appendShader(utils::io::sstream& ss,
            const utils::CString& shader, size_t lineOffset) noexcept;

    static bool hasSkinningOrMorphing(
            filament::Variant variant,
            MaterialBuilder::FeatureLevel featureLevel) noexcept;

    static bool hasStereo(
            filament::Variant variant,
            MaterialBuilder::FeatureLevel featureLevel) noexcept;

    MaterialBuilder::PropertyList mProperties;
    MaterialBuilder::VariableList mVariables;
    MaterialBuilder::OutputList mOutputs;
    MaterialBuilder::MaterialDomain mMaterialDomain;
    MaterialBuilder::PreprocessorDefineList mDefines;
    MaterialBuilder::ConstantList mConstants;
    MaterialBuilder::PushConstantList mPushConstants;
    utils::CString mMaterialFragmentCode;   // fragment or compute code
    utils::CString mMaterialVertexCode;
    size_t mMaterialLineOffset;
    size_t mMaterialVertexLineOffset;
    bool mIsMaterialVertexShaderEmpty;
};

} // namespace filament

#endif // TNT_FILAMENT_DETAILS_SHADERGENERATOR_H

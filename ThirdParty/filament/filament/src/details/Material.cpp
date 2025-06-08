
#include "details/Material.h"
#include "details/Engine.h"

#include "Froxelizer.h"
#include "MaterialParser.h"

#include "FilamentAPI-impl.h"

#include <private/filament/EngineEnums.h>
#include <private/filament/SamplerInterfaceBlock.h>
#include <private/filament/BufferInterfaceBlock.h>
#include <private/filament/PushConstantInfo.h>
#include <private/filament/Variant.h>

#include <filament/Material.h>
#include <filament/MaterialEnums.h>

#if FILAMENT_ENABLE_MATDBG
#include <matdbg/DebugServer.h>
#endif

#include <filaflat/ChunkContainer.h>
#include <filaflat/MaterialChunk.h>

#include <backend/DriverEnums.h>
#include <backend/CallbackHandler.h>
#include <backend/Program.h>

#include "third_party/filament/libs/utils/include/utils/BitmaskEnum.h"
#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/Hash.h"
#include "third_party/filament/libs/utils/include/utils/Invocable.h"
#include "third_party/filament/libs/utils/include/utils/Log.h"
#include "third_party/filament/libs/utils/include/utils/Panic.h"
#include "third_party/filament/libs/utils/include/utils/bitset.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include <algorithm>
#include <array>
#include <iterator>
#include <memory>
#include <new>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <variant>

#include <stddef.h>
#include <stdint.h>

namespace filament {

using namespace backend;
using namespace filaflat;
using namespace utils;

static std::unique_ptr<MaterialParser> createParser(Backend backend,
        utils::FixedCapacityVector<ShaderLanguage> languages, const void* data, size_t size) {
    // unique_ptr so we don't leak MaterialParser on failures below
    auto materialParser = std::make_unique<MaterialParser>(languages, data, size);

    MaterialParser::ParseResult const materialResult = materialParser->parse();

    if (UTILS_UNLIKELY(materialResult == MaterialParser::ParseResult::ERROR_MISSING_BACKEND)) {
        std::string languageNames;
        for (auto it = languages.begin(); it != languages.end(); ++it) {
            languageNames.append(shaderLanguageToString(*it));
            if (std::next(it) != languages.end()) {
                languageNames.append(", ");
            }
        }

        FILAMENT_CHECK_PRECONDITION(
                materialResult != MaterialParser::ParseResult::ERROR_MISSING_BACKEND)
                << "the material was not built for any of the " << backendToString(backend)
                << " backend's supported shader languages (" << languageNames.c_str() << ")\n";
    }

    if (backend == Backend::NOOP) {
        return materialParser;
    }

    FILAMENT_CHECK_PRECONDITION(materialResult == MaterialParser::ParseResult::SUCCESS)
            << "could not parse the material package";

    uint32_t version = 0;
    materialParser->getMaterialVersion(&version);
    FILAMENT_CHECK_PRECONDITION(version == MATERIAL_VERSION)
            << "Material version mismatch. Expected " << MATERIAL_VERSION << " but received "
            << version << ".";

    assert_invariant(backend != Backend::DEFAULT && "Default backend has not been resolved.");

    return materialParser;
}

struct Material::BuilderDetails {
    const void* mPayload = nullptr;
    size_t mSize = 0;
    bool mDefaultMaterial = false;
    int32_t mShBandsCount = 3;
    std::unordered_map<
        utils::CString,
        std::variant<int32_t, float, bool>,
        CString::Hasher> mConstantSpecializations;
};

FMaterial::DefaultMaterialBuilder::DefaultMaterialBuilder() : Material::Builder() {
    mImpl->mDefaultMaterial = true;
}

using BuilderType = Material;
BuilderType::Builder::Builder() noexcept = default;
BuilderType::Builder::~Builder() noexcept = default;
BuilderType::Builder::Builder(BuilderType::Builder const& rhs) noexcept = default;
BuilderType::Builder::Builder(BuilderType::Builder&& rhs) noexcept = default;
BuilderType::Builder& BuilderType::Builder::operator=(BuilderType::Builder const& rhs) noexcept = default;
BuilderType::Builder& BuilderType::Builder::operator=(BuilderType::Builder&& rhs) noexcept = default;

Material::Builder& Material::Builder::package(const void* payload, size_t size) {
    mImpl->mPayload = payload;
    mImpl->mSize = size;
    return *this;
}

Material::Builder& Material::Builder::sphericalHarmonicsBandCount(size_t shBandCount) noexcept {
    mImpl->mShBandsCount = math::clamp(shBandCount, size_t(1), size_t(3));
    return *this;
}

template<typename T, typename>
Material::Builder& Material::Builder::constant(const char* name, size_t nameLength, T value) {
    FILAMENT_CHECK_PRECONDITION(name != nullptr) << "name cannot be null";
    mImpl->mConstantSpecializations[{name, nameLength}] = value;
    return *this;
}

template Material::Builder& Material::Builder::constant<int32_t>(const char*, size_t, int32_t);
template Material::Builder& Material::Builder::constant<float>(const char*, size_t, float);
template Material::Builder& Material::Builder::constant<bool>(const char*, size_t, bool);

Material* Material::Builder::build(Engine& engine) {
    std::unique_ptr<MaterialParser> materialParser = createParser(
        downcast(engine).getBackend(), downcast(engine).getShaderLanguage(),
        mImpl->mPayload, mImpl->mSize);

    if (!materialParser) {
        return nullptr;
    }

    uint32_t v = 0;
    materialParser->getShaderModels(&v);
    utils::bitset32 shaderModels;
    shaderModels.setValue(v);

    ShaderModel const shaderModel = downcast(engine).getShaderModel();
    if (!shaderModels.test(static_cast<uint32_t>(shaderModel))) {
        CString name;
        materialParser->getName(&name);
        slog.e << "The material '" << name.c_str_safe() << "' was not built for ";
        switch (shaderModel) {
            case ShaderModel::MOBILE:
                slog.e << "mobile.\n";
                break;
            case ShaderModel::DESKTOP:
                slog.e << "desktop.\n";
                break;
        }
        slog.e << "Compiled material contains shader models 0x"
                << io::hex << shaderModels.getValue() << io::dec << "." << io::endl;
        return nullptr;
    }

    return downcast(engine).createMaterial(*this, std::move(materialParser));
}

FMaterial::FMaterial(FEngine& engine, const Material::Builder& builder,
        std::unique_ptr<MaterialParser> materialParser)
        : mIsDefaultMaterial(builder->mDefaultMaterial),
          mEngine(engine),
          mMaterialId(engine.getMaterialId()),
          mMaterialParser(std::move(materialParser))
{
    MaterialParser* const parser = mMaterialParser.get();

    UTILS_UNUSED_IN_RELEASE bool const nameOk = parser->getName(&mName);
    assert_invariant(nameOk);

    mFeatureLevel = [parser]() -> FeatureLevel {
        // code written this way so the IDE will complain when/if we add a FeatureLevel
        uint8_t level = 1;
        parser->getFeatureLevel(&level);
        assert_invariant(level <= 3);
        FeatureLevel featureLevel = FeatureLevel::FEATURE_LEVEL_1;
        switch (FeatureLevel(level)) {
            case FeatureLevel::FEATURE_LEVEL_0:
            case FeatureLevel::FEATURE_LEVEL_1:
            case FeatureLevel::FEATURE_LEVEL_2:
            case FeatureLevel::FEATURE_LEVEL_3:
                featureLevel = FeatureLevel(level);
                break;
        }
        return featureLevel;
    }();

    UTILS_UNUSED_IN_RELEASE bool success;

    success = parser->getCacheId(&mCacheId);
    assert_invariant(success);

    success = parser->getSIB(&mSamplerInterfaceBlock);
    assert_invariant(success);

    success = parser->getUIB(&mUniformInterfaceBlock);
    assert_invariant(success);

    if (UTILS_UNLIKELY(parser->getShaderLanguage() == ShaderLanguage::ESSL1)) {
        success = parser->getBindingUniformInfo(&mBindingUniformInfo);
        assert_invariant(success);

        success = parser->getAttributeInfo(&mAttributeInfo);
        assert_invariant(success);
    } else if (mFeatureLevel <= FeatureLevel::FEATURE_LEVEL_1) {
        // this chunk is not needed for materials at feature level 2 and above
        success = parser->getUniformBlockBindings(&mUniformBlockBindings);
        assert_invariant(success);
    }

    success = parser->getSamplerBlockBindings(
            &mSamplerGroupBindingInfoList, &mSamplerBindingToNameMap);
    assert_invariant(success);

    // Older materials will not have a subpass chunk; this should not be an error.
    if (!parser->getSubpasses(&mSubpassInfo)) {
        mSubpassInfo.isValid = false;
    }

    parser->getShading(&mShading);
    parser->getMaterialProperties(&mMaterialProperties);
    parser->getInterpolation(&mInterpolation);
    parser->getVertexDomain(&mVertexDomain);
    parser->getMaterialDomain(&mMaterialDomain);
    parser->getMaterialVariantFilterMask(&mVariantFilterMask);
    parser->getRequiredAttributes(&mRequiredAttributes);
    parser->getRefractionMode(&mRefractionMode);
    parser->getRefractionType(&mRefractionType);
    parser->getReflectionMode(&mReflectionMode);
    parser->getTransparencyMode(&mTransparencyMode);
    parser->getDoubleSided(&mDoubleSided);
    parser->getCullingMode(&mCullingMode);

    if (mShading == Shading::UNLIT) {
        parser->hasShadowMultiplier(&mHasShadowMultiplier);
    }

    mIsVariantLit = mShading != Shading::UNLIT || mHasShadowMultiplier;

    // color write
    bool colorWrite = false;
    parser->getColorWrite(&colorWrite);
    mRasterState.colorWrite = colorWrite;

    // depth test
    bool depthTest = false;
    parser->getDepthTest(&depthTest);
    mRasterState.depthFunc = depthTest ? RasterState::DepthFunc::GE : RasterState::DepthFunc::A;

    // if doubleSided() was called we override culling()
    bool doubleSideSet = false;
    parser->getDoubleSidedSet(&doubleSideSet);
    if (doubleSideSet) {
        mDoubleSidedCapability = true;
        mRasterState.culling = mDoubleSided ? CullingMode::NONE : mCullingMode;
    } else {
        mRasterState.culling = mCullingMode;
    }

    // specular anti-aliasing
    parser->hasSpecularAntiAliasing(&mSpecularAntiAliasing);
    if (mSpecularAntiAliasing) {
        parser->getSpecularAntiAliasingVariance(&mSpecularAntiAliasingVariance);
        parser->getSpecularAntiAliasingThreshold(&mSpecularAntiAliasingThreshold);
    }

    processBlendingMode(parser);
    processSpecializationConstants(engine, builder, parser);
    processPushConstants(engine, parser);
    processDepthVariants(engine, parser);

    // we can only initialize the default instance once we're initialized ourselves
    new(&mDefaultInstanceStorage) FMaterialInstance(engine, this);


#if FILAMENT_ENABLE_MATDBG
    // Register the material with matdbg.
    matdbg::DebugServer* server = downcast(engine).debug.server;
    if (UTILS_UNLIKELY(server)) {
        auto details = builder.mImpl;
        mDebuggerId = server->addMaterial(mName, details->mPayload, details->mSize, this);
    }
#endif
}

FMaterial::~FMaterial() noexcept {
    std::destroy_at(getDefaultInstance());
}

void FMaterial::invalidate(Variant::type_t variantMask, Variant::type_t variantValue) noexcept {
    if (mMaterialDomain == MaterialDomain::SURFACE) {
        DriverApi& driverApi = mEngine.getDriverApi();
        auto& cachedPrograms = mCachedPrograms;
        for (size_t k = 0, n = VARIANT_COUNT; k < n; ++k) {
            Variant const variant(k);
            if ((k & variantMask) == variantValue) {
                if (UTILS_LIKELY(!mIsDefaultMaterial)) {
                    // The depth variants may be shared with the default material, in which case
                    // we should not free it now.
                    bool const isSharedVariant =
                            Variant::isValidDepthVariant(variant) && !mHasCustomDepthShader;
                    if (isSharedVariant) {
                        // we don't own this variant, skip.
                        continue;
                    }
                }
                driverApi.destroyProgram(cachedPrograms[k]);
                cachedPrograms[k].clear();
            }
        }

         if (UTILS_UNLIKELY(!mIsDefaultMaterial && !mHasCustomDepthShader)) {
            FMaterial const* const pDefaultMaterial = mEngine.getDefaultMaterial();
            for (Variant const variant: pDefaultMaterial->mDepthVariants) {
                pDefaultMaterial->prepareProgram(variant);
                if (!cachedPrograms[variant.key]) {
                    cachedPrograms[variant.key] = pDefaultMaterial->getProgram(variant);
                }
            }
        }
    } else if (mMaterialDomain == MaterialDomain::POST_PROCESS) {
        DriverApi& driverApi = mEngine.getDriverApi();
        auto& cachedPrograms = mCachedPrograms;
        for (size_t k = 0, n = POST_PROCESS_VARIANT_COUNT; k < n; ++k) {
            if ((k & variantMask) == variantValue) {
                driverApi.destroyProgram(cachedPrograms[k]);
                cachedPrograms[k].clear();
            }
        }
    } else if (mMaterialDomain == MaterialDomain::COMPUTE) {
        // TODO: handle compute variants if any
    }
}

void FMaterial::terminate(FEngine& engine) {

#if FILAMENT_ENABLE_MATDBG
    // Unregister the material with matdbg.
    matdbg::DebugServer* server = engine.debug.server;
    if (UTILS_UNLIKELY(server)) {
        server->removeMaterial(mDebuggerId);
    }
#endif

    destroyPrograms(engine);

    getDefaultInstance()->terminate(engine);
}

void FMaterial::compile(CompilerPriorityQueue priority,
        UserVariantFilterMask variantSpec,
        backend::CallbackHandler* handler,
        utils::Invocable<void(Material*)>&& callback) noexcept {

    // Turn off the STE variant if stereo is not supported.
    if (!mEngine.getDriverApi().isStereoSupported()) {
        variantSpec &= ~UserVariantFilterMask(UserVariantFilterBit::STE);
    }

    UserVariantFilterMask const variantFilter =
            ~variantSpec & UserVariantFilterMask(UserVariantFilterBit::ALL);

    if (UTILS_LIKELY(mEngine.getDriverApi().isParallelShaderCompileSupported())) {
        auto const& variants = isVariantLit() ?
                VariantUtils::getLitVariants() : VariantUtils::getUnlitVariants();
        for (auto const variant: variants) {
            if (!variantFilter || variant == Variant::filterUserVariant(variant, variantFilter)) {
                if (hasVariant(variant)) {
                    prepareProgram(variant, priority);
                }
            }
        }
    }

    if (callback) {
        struct Callback {
            Invocable<void(Material*)> f;
            Material* m;
            static void func(void* user) {
                auto* const c = reinterpret_cast<Callback*>(user);
                c->f(c->m);
                delete c;
            }
        };
        auto* const user = new(std::nothrow) Callback{ std::move(callback), this };
        mEngine.getDriverApi().compilePrograms(priority, handler, &Callback::func, static_cast<void*>(user));
    } else {
        mEngine.getDriverApi().compilePrograms(priority, nullptr, nullptr, nullptr);
    }
}

FMaterialInstance* FMaterial::createInstance(const char* name) const noexcept {
    return FMaterialInstance::duplicate(getDefaultInstance(), name);
}

bool FMaterial::hasParameter(const char* name) const noexcept {
    return mUniformInterfaceBlock.hasField(name) ||
           mSamplerInterfaceBlock.hasSampler(name) ||
            mSubpassInfo.name == utils::CString(name);
}

bool FMaterial::isSampler(const char* name) const noexcept {
    return mSamplerInterfaceBlock.hasSampler(name);
}

BufferInterfaceBlock::FieldInfo const* FMaterial::reflect(
        std::string_view name) const noexcept {
    return mUniformInterfaceBlock.getFieldInfo(name);
}

bool FMaterial::hasVariant(Variant variant) const noexcept {
    Variant vertexVariant, fragmentVariant;
    switch (getMaterialDomain()) {
        case MaterialDomain::SURFACE:
            vertexVariant = Variant::filterVariantVertex(variant);
            fragmentVariant = Variant::filterVariantFragment(variant);
            break;
        case MaterialDomain::POST_PROCESS:
            vertexVariant = fragmentVariant = variant;
            break;
        case MaterialDomain::COMPUTE:
            // TODO: implement MaterialDomain::COMPUTE
            return false;
    }
    const ShaderModel sm = mEngine.getShaderModel();
    if (!mMaterialParser->hasShader(sm, vertexVariant, ShaderStage::VERTEX)) {
        return false;
    }
    if (!mMaterialParser->hasShader(sm, fragmentVariant, ShaderStage::FRAGMENT)) {
        return false;
    }
    return true;
}

void FMaterial::prepareProgramSlow(Variant variant,
        backend::CompilerPriorityQueue priorityQueue) const noexcept {
    assert_invariant(mEngine.hasFeatureLevel(mFeatureLevel));
    switch (getMaterialDomain()) {
        case MaterialDomain::SURFACE:
            getSurfaceProgramSlow(variant, priorityQueue);
            break;
        case MaterialDomain::POST_PROCESS:
            getPostProcessProgramSlow(variant, priorityQueue);
            break;
        case MaterialDomain::COMPUTE:
            // TODO: implement MaterialDomain::COMPUTE
            break;
    }
}

void FMaterial::getSurfaceProgramSlow(Variant variant,
        CompilerPriorityQueue priorityQueue) const noexcept {
    // filterVariant() has already been applied in generateCommands(), shouldn't be needed here
    // if we're unlit, we don't have any bits that correspond to lit materials
    assert_invariant(variant == Variant::filterVariant(variant, isVariantLit()) );

    assert_invariant(!Variant::isReserved(variant));

    Variant const vertexVariant   = Variant::filterVariantVertex(variant);
    Variant const fragmentVariant = Variant::filterVariantFragment(variant);

    Program pb{ getProgramWithVariants(variant, vertexVariant, fragmentVariant) };
    pb.priorityQueue(priorityQueue);
    pb.multiview(
            mEngine.getConfig().stereoscopicType == StereoscopicType::MULTIVIEW &&
            Variant::isStereoVariant(variant));
    createAndCacheProgram(std::move(pb), variant);
}

void FMaterial::getPostProcessProgramSlow(Variant variant,
        CompilerPriorityQueue priorityQueue) const noexcept {
    Program pb{ getProgramWithVariants(variant, variant, variant) };
    pb.priorityQueue(priorityQueue);
    createAndCacheProgram(std::move(pb), variant);
}

Program FMaterial::getProgramWithVariants(
        Variant variant,
        Variant vertexVariant,
        Variant fragmentVariant) const noexcept {
    FEngine const& engine = mEngine;
    const ShaderModel sm = engine.getShaderModel();
    const bool isNoop = engine.getBackend() == Backend::NOOP;

    ShaderContent& vsBuilder = engine.getVertexShaderContent();

    UTILS_UNUSED_IN_RELEASE bool const vsOK = mMaterialParser->getShader(vsBuilder, sm,
            vertexVariant, ShaderStage::VERTEX);

    FILAMENT_CHECK_POSTCONDITION(isNoop || (vsOK && !vsBuilder.empty()))
            << "The material '" << mName.c_str()
            << "' has not been compiled to include the required GLSL or SPIR-V chunks for the "
               "vertex shader (variant="
            << variant.key << ", filtered=" << vertexVariant.key << ").";


    ShaderContent& fsBuilder = engine.getFragmentShaderContent();

    UTILS_UNUSED_IN_RELEASE bool const fsOK = mMaterialParser->getShader(fsBuilder, sm,
            fragmentVariant, ShaderStage::FRAGMENT);

    FILAMENT_CHECK_POSTCONDITION(isNoop || (fsOK && !fsBuilder.empty()))
            << "The material '" << mName.c_str()
            << "' has not been compiled to include the required GLSL or SPIR-V chunks for the "
               "fragment shader (variant="
            << variant.key << ", filtered=" << ").";

    Program program;
    program.shader(ShaderStage::VERTEX, vsBuilder.data(), vsBuilder.size())
           .shader(ShaderStage::FRAGMENT, fsBuilder.data(), fsBuilder.size())
           .shaderLanguage(mMaterialParser->getShaderLanguage())
           .uniformBlockBindings(mUniformBlockBindings)
           .diagnostics(mName,
                    [this, variant](io::ostream& out) -> io::ostream& {
                        return out << mName.c_str_safe()
                                   << ", variant=(" << io::hex << variant.key << io::dec << ")";
                    });

    UTILS_NOUNROLL
    for (size_t i = 0; i < Enum::count<SamplerBindingPoints>(); i++) {
        SamplerBindingPoints const bindingPoint = (SamplerBindingPoints)i;
        auto const& info = mSamplerGroupBindingInfoList[i];
        if (info.count) {
            std::array<Program::Sampler, backend::MAX_SAMPLER_COUNT> samplers{};
            for (size_t j = 0, c = info.count; j < c; ++j) {
                uint8_t const binding = info.bindingOffset + j;
                samplers[j] = { mSamplerBindingToNameMap[binding], binding };
            }
            program.setSamplerGroup(+bindingPoint, info.shaderStageFlags,
                    samplers.data(), info.count);
        }
    }
    if (UTILS_UNLIKELY(mMaterialParser->getShaderLanguage() == ShaderLanguage::ESSL1)) {
        assert_invariant(!mBindingUniformInfo.empty());
        for (auto const& [index, uniforms] : mBindingUniformInfo) {
            program.uniforms(uint32_t(index), uniforms);
        }
        program.attributes(mAttributeInfo);
    }

    program.specializationConstants(mSpecializationConstants);

    program.pushConstants(ShaderStage::VERTEX, mPushConstants[(uint8_t) ShaderStage::VERTEX]);
    program.pushConstants(ShaderStage::FRAGMENT, mPushConstants[(uint8_t) ShaderStage::FRAGMENT]);

    program.cacheId(utils::hash::combine(size_t(mCacheId), variant.key));

    return program;
}

void FMaterial::createAndCacheProgram(Program&& p, Variant variant) const noexcept {
    auto program = mEngine.getDriverApi().createProgram(std::move(p));
    assert_invariant(program);
    mCachedPrograms[variant.key] = program;
}

size_t FMaterial::getParameters(ParameterInfo* parameters, size_t count) const noexcept {
    count = std::min(count, getParameterCount());

    const auto& uniforms = mUniformInterfaceBlock.getFieldInfoList();
    size_t i = 0;
    size_t const uniformCount = std::min(count, size_t(uniforms.size()));
    for ( ; i < uniformCount; i++) {
        ParameterInfo& info = parameters[i];
        const auto& uniformInfo = uniforms[i];
        info.name = uniformInfo.name.c_str();
        info.isSampler = false;
        info.isSubpass = false;
        info.type = uniformInfo.type;
        info.count = std::max(1u, uniformInfo.size);
        info.precision = uniformInfo.precision;
    }

    const auto& samplers = mSamplerInterfaceBlock.getSamplerInfoList();
    size_t const samplerCount = samplers.size();
    for (size_t j = 0; i < count && j < samplerCount; i++, j++) {
        ParameterInfo& info = parameters[i];
        const auto& samplerInfo = samplers[j];
        info.name = samplerInfo.name.c_str();
        info.isSampler = true;
        info.isSubpass = false;
        info.samplerType = samplerInfo.type;
        info.count = 1;
        info.precision = samplerInfo.precision;
    }

    if (mSubpassInfo.isValid && i < count) {
        ParameterInfo& info = parameters[i];
        info.name = mSubpassInfo.name.c_str();
        info.isSampler = false;
        info.isSubpass = true;
        info.subpassType = mSubpassInfo.type;
        info.count = 1;
        info.precision = mSubpassInfo.precision;
    }

    return count;
}

#if FILAMENT_ENABLE_MATDBG

// Swaps in an edited version of the original package that was used to create the material. The
// edited package was stashed in response to a debugger event. This is invoked only when the
// Material Debugger is attached. The only editable features of a material package are the shader
// source strings, so here we trigger a rebuild of the HwProgram objects.
void FMaterial::applyPendingEdits() noexcept {
    const char* name = mName.c_str();
    slog.d << "Applying edits to " << (name ? name : "(untitled)") << io::endl;
    destroyPrograms(mEngine); // FIXME: this will not destroy the shared variants
    latchPendingEdits();
}

void FMaterial::setPendingEdits(std::unique_ptr<MaterialParser> pendingEdits) noexcept {
    std::lock_guard const lock(mPendingEditsLock);
    std::swap(pendingEdits, mPendingEdits);
}

bool FMaterial::hasPendingEdits() noexcept {
    std::lock_guard const lock(mPendingEditsLock);
    return (bool)mPendingEdits;
}

void FMaterial::latchPendingEdits() noexcept {
    std::lock_guard const lock(mPendingEditsLock);
    mMaterialParser.reset(mPendingEdits.release());
}


void FMaterial::onEditCallback(void* userdata, const utils::CString&, const void* packageData,
        size_t packageSize) {
    FMaterial* material = downcast((Material*) userdata);
    FEngine const& engine = material->mEngine;

    // This is called on a web server thread, so we defer clearing the program cache
    // and swapping out the MaterialParser until the next getProgram call.
    std::unique_ptr<MaterialParser> pending = createParser(
            engine.getBackend(), engine.getShaderLanguage(), packageData, packageSize);
    material->setPendingEdits(std::move(pending));
}

void FMaterial::onQueryCallback(void* userdata, VariantList* pVariants) {
    FMaterial* material = downcast((Material*) userdata);
    std::lock_guard<utils::Mutex> const lock(material->mActiveProgramsLock);
    *pVariants = material->mActivePrograms;
    material->mActivePrograms.reset();
}


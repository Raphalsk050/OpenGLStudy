
#ifdef FILAMENT_TARGET_MOBILE
#   define DOF_DEFAULT_RING_COUNT 3
#   define DOF_DEFAULT_MAX_COC    24
#else
#   define DOF_DEFAULT_RING_COUNT 5
#   define DOF_DEFAULT_MAX_COC    32
#endif

#include "PostProcessManager.h"

#include "details/Engine.h"

#include "fg/FrameGraph.h"
#include "fg/FrameGraphId.h"
#include "fg/FrameGraphResources.h"
#include "fg/FrameGraphTexture.h"

#include "fsr.h"
#include "FrameHistory.h"
#include "PerViewUniforms.h"
#include "RenderPass.h"

#include "details/Camera.h"
#include "details/ColorGrading.h"
#include "details/Material.h"
#include "details/MaterialInstance.h"
#include "details/Texture.h"
#include "details/VertexBuffer.h"

#include "generated/resources/materials.h"

#include <filament/Material.h>
#include <filament/MaterialEnums.h>
#include <filament/Options.h>
#include <filament/Viewport.h>

#include <private/filament/EngineEnums.h>

#include <backend/DriverEnums.h>
#include <backend/DriverApiForward.h>
#include <backend/Handle.h>
#include <backend/PipelineState.h>
#include <backend/PixelBufferDescriptor.h>

#include <private/backend/BackendUtils.h>

#include "third_party/filament/libs/math/include/math/half.h"
#include "third_party/filament/libs/math/include/math/mat2.h"
#include "third_party/filament/libs/math/include/math/mat3.h"
#include "third_party/filament/libs/math/include/math/mat4.h"
#include "third_party/filament/libs/math/include/math/scalar.h"
#include "third_party/filament/libs/math/include/math/vec2.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include "third_party/filament/libs/utils/include/utils/algorithm.h"
#include "third_party/filament/libs/utils/include/utils/BitmaskEnum.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <string_view>
#include <variant>
#include <utility>

#include <stddef.h>
#include <stdint.h>

namespace filament {

using namespace utils;
using namespace math;
using namespace backend;

static constexpr uint8_t kMaxBloomLevels = 12u;
static_assert(kMaxBloomLevels >= 3, "We require at least 3 bloom levels");

constexpr static float halton(unsigned int i, unsigned int b) noexcept {
    // skipping a bunch of entries makes the average of the sequence closer to 0.5
    i += 409;
    float f = 1.0f;
    float r = 0.0f;
    while (i > 0u) {
        f /= float(b);
        r += f * float(i % b);
        i /= b;
    }
    return r;
}

// ------------------------------------------------------------------------------------------------

PostProcessManager::PostProcessMaterial::PostProcessMaterial() noexcept {
    mMaterial = nullptr; // aliased to mData
    mData = nullptr;
}

PostProcessManager::PostProcessMaterial::PostProcessMaterial(MaterialInfo const& info) noexcept
        : PostProcessMaterial() {
    mData = info.data; // aliased to mMaterial
    mSize = info.size;
    mConstants = info.constants;
}

PostProcessManager::PostProcessMaterial::PostProcessMaterial(
        PostProcessManager::PostProcessMaterial&& rhs) noexcept
        : PostProcessMaterial() {
    using namespace std;
    swap(mData, rhs.mData); // aliased to mMaterial
    swap(mSize, rhs.mSize);
    swap(mHasMaterial, rhs.mHasMaterial);
    swap(mConstants, rhs.mConstants);
}

PostProcessManager::PostProcessMaterial& PostProcessManager::PostProcessMaterial::operator=(
        PostProcessManager::PostProcessMaterial&& rhs) noexcept {
    if (this != &rhs) {
        using namespace std;
        swap(mData, rhs.mData); // aliased to mMaterial
        swap(mSize, rhs.mSize);
        swap(mHasMaterial, rhs.mHasMaterial);
        swap(mConstants, rhs.mConstants);
    }
    return *this;
}

PostProcessManager::PostProcessMaterial::~PostProcessMaterial() {
    assert_invariant(!mHasMaterial || mMaterial == nullptr);
}

void PostProcessManager::PostProcessMaterial::terminate(FEngine& engine) noexcept {
    if (mHasMaterial) {
        engine.destroy(mMaterial);
// this is only needed for validation in the dtor in debug builds
#ifndef NDEBUG
        mMaterial = nullptr;
        mHasMaterial = false;
    } else {
        mData = nullptr;
#endif
    }
}

UTILS_NOINLINE
void PostProcessManager::PostProcessMaterial::loadMaterial(FEngine& engine) const noexcept {
    // TODO: After all materials using this class have been converted to the post-process material
    //       domain, load both OPAQUE and TRANSPARENT variants here.
    mHasMaterial = true;
    auto builder = Material::Builder();
    builder.package(mData, mSize);
    for (auto const& constant: mConstants) {
        std::visit([&](auto&& arg) {
            builder.constant(constant.name.data(), constant.name.size(), arg);
        }, constant.value);
    }
    mMaterial = downcast(builder.build(engine));
}

UTILS_NOINLINE
FMaterial* PostProcessManager::PostProcessMaterial::getMaterial(FEngine& engine) const noexcept {
    if (UTILS_UNLIKELY(!mHasMaterial)) {
        loadMaterial(engine);
    }
    return mMaterial;
}

UTILS_NOINLINE
std::pair<backend::PipelineState, backend::Viewport>
        PostProcessManager::PostProcessMaterial::getPipelineState(
        FEngine& engine, Variant::type_t variantKey) const noexcept {
    FMaterial* const material = getMaterial(engine);
    material->prepareProgram(Variant{ variantKey });
    return {{
            .program = material->getProgram(Variant{ variantKey }),
            .vertexBufferInfo = engine.getFullScreenVertexBuffer()->getVertexBufferInfoHandle(),
            .rasterState = material->getRasterState() },
            material->getDefaultInstance()->getScissor() };
}

UTILS_NOINLINE
FMaterialInstance* PostProcessManager::PostProcessMaterial::getMaterialInstance(
        FEngine& engine) const noexcept {
    FMaterial* const material = getMaterial(engine);
    return material->getDefaultInstance();
}

// ------------------------------------------------------------------------------------------------

const PostProcessManager::JitterSequence<4> PostProcessManager::sRGSS4 = {{{
        { 0.625f, 0.125f },
        { 0.125f, 0.375f },
        { 0.875f, 0.625f },
        { 0.375f, 0.875f }
}}};

const PostProcessManager::JitterSequence<4> PostProcessManager::sUniformHelix4 = {{{
        { 0.25f, 0.25f },
        { 0.75f, 0.75f },
        { 0.25f, 0.75f },
        { 0.75f, 0.25f },
}}};

template<size_t COUNT>
constexpr auto halton() {
    std::array<float2, COUNT> h;
    for (size_t i = 0; i < COUNT; i++) {
        h[i] = {
                filament::halton(i, 2),
                filament::halton(i, 3) };
    }
    return h;
}

const PostProcessManager::JitterSequence<32>
        PostProcessManager::sHaltonSamples = { halton<32>() };

PostProcessManager::PostProcessManager(FEngine& engine) noexcept
        : mEngine(engine),
          mWorkaroundSplitEasu(false),
          mWorkaroundAllowReadOnlyAncillaryFeedbackLoop(false) {
}

PostProcessManager::~PostProcessManager() noexcept = default;

UTILS_NOINLINE
void PostProcessManager::registerPostProcessMaterial(std::string_view name,
        MaterialInfo const& info) {
    mMaterialRegistry.try_emplace(name, info);
}

UTILS_NOINLINE
PostProcessManager::PostProcessMaterial& PostProcessManager::getPostProcessMaterial(
        std::string_view name) noexcept {
    assert_invariant(mMaterialRegistry.find(name) != mMaterialRegistry.end());
    return mMaterialRegistry[name];
}

#define MATERIAL(n) MATERIALS_ ## n ## _DATA, MATERIALS_ ## n ## _SIZE

static const PostProcessManager::MaterialInfo sMaterialListFeatureLevel0[] = {
        { "blitLow",                    MATERIAL(BLITLOW) },
};

static const PostProcessManager::MaterialInfo sMaterialList[] = {
        { "bilateralBlur",              MATERIAL(BILATERALBLUR) },
        { "bilateralBlurBentNormals",   MATERIAL(BILATERALBLURBENTNORMALS) },
        { "blitArray",                  MATERIAL(BLITARRAY) },
        { "blitDepth",                  MATERIAL(BLITDEPTH) },
        { "bloomDownsample",            MATERIAL(BLOOMDOWNSAMPLE) },
        { "bloomDownsample2x",          MATERIAL(BLOOMDOWNSAMPLE2X) },
        { "bloomDownsample9",           MATERIAL(BLOOMDOWNSAMPLE9) },
        { "bloomUpsample",              MATERIAL(BLOOMUPSAMPLE) },
        { "colorGrading",               MATERIAL(COLORGRADING) },
        { "colorGradingAsSubpass",      MATERIAL(COLORGRADINGASSUBPASS) },
        { "customResolveAsSubpass",     MATERIAL(CUSTOMRESOLVEASSUBPASS) },
        { "dof",                        MATERIAL(DOF) },
        { "dofCoc",                     MATERIAL(DOFCOC) },
        { "dofCombine",                 MATERIAL(DOFCOMBINE) },
        { "dofDilate",                  MATERIAL(DOFDILATE) },
        { "dofDownsample",              MATERIAL(DOFDOWNSAMPLE) },
        { "dofMedian",                  MATERIAL(DOFMEDIAN) },
        { "dofMipmap",                  MATERIAL(DOFMIPMAP) },
        { "dofTiles",                   MATERIAL(DOFTILES) },
        { "dofTilesSwizzle",            MATERIAL(DOFTILESSWIZZLE) },
        { "flare",                      MATERIAL(FLARE) },
        { "fxaa",                       MATERIAL(FXAA) },
        { "mipmapDepth",                MATERIAL(MIPMAPDEPTH) },
        { "sao",                        MATERIAL(SAO) },
        { "saoBentNormals",             MATERIAL(SAOBENTNORMALS) },
        { "separableGaussianBlur1",     MATERIAL(SEPARABLEGAUSSIANBLUR),
                { {"arraySampler", false}, {"componentCount", 1} } },
        { "separableGaussianBlur1L",    MATERIAL(SEPARABLEGAUSSIANBLUR),
                { {"arraySampler", true }, {"componentCount", 1} } },
        { "separableGaussianBlur2",     MATERIAL(SEPARABLEGAUSSIANBLUR),
                { {"arraySampler", false}, {"componentCount", 2} } },
        { "separableGaussianBlur2L",    MATERIAL(SEPARABLEGAUSSIANBLUR),
                { {"arraySampler", true }, {"componentCount", 2} } },
        { "separableGaussianBlur3",     MATERIAL(SEPARABLEGAUSSIANBLUR),
                { {"arraySampler", false}, {"componentCount", 3} } },
        { "separableGaussianBlur3L",    MATERIAL(SEPARABLEGAUSSIANBLUR),
                { {"arraySampler", true }, {"componentCount", 3} } },
        { "separableGaussianBlur4",     MATERIAL(SEPARABLEGAUSSIANBLUR),
                { {"arraySampler", false}, {"componentCount", 4} } },
        { "separableGaussianBlur4L",    MATERIAL(SEPARABLEGAUSSIANBLUR),
                { {"arraySampler", true }, {"componentCount", 4} } },
        { "taa",                        MATERIAL(TAA) },
        { "vsmMipmap",                  MATERIAL(VSMMIPMAP) },
        { "fsr_easu",                   MATERIAL(FSR_EASU) },
        { "fsr_easu_mobile",            MATERIAL(FSR_EASU_MOBILE) },
        { "fsr_easu_mobileF",           MATERIAL(FSR_EASU_MOBILEF) },
        { "fsr_rcas",                   MATERIAL(FSR_RCAS) },
        { "debugShadowCascades",        MATERIAL(DEBUGSHADOWCASCADES) },
        { "resolveDepth",               MATERIAL(RESOLVEDEPTH) },
        { "shadowmap",                  MATERIAL(SHADOWMAP) },
};

void PostProcessManager::init() noexcept {
    auto& engine = mEngine;
    DriverApi& driver = engine.getDriverApi();

    //FDebugRegistry& debugRegistry = engine.getDebugRegistry();
    //debugRegistry.registerProperty("d.ssao.sampleCount", &engine.debug.ssao.sampleCount);
    //debugRegistry.registerProperty("d.ssao.spiralTurns", &engine.debug.ssao.spiralTurns);
    //debugRegistry.registerProperty("d.ssao.kernelSize", &engine.debug.ssao.kernelSize);
    //debugRegistry.registerProperty("d.ssao.stddev", &engine.debug.ssao.stddev);

    mWorkaroundSplitEasu =
            driver.isWorkaroundNeeded(Workaround::SPLIT_EASU);
    mWorkaroundAllowReadOnlyAncillaryFeedbackLoop =
            driver.isWorkaroundNeeded(Workaround::ALLOW_READ_ONLY_ANCILLARY_FEEDBACK_LOOP);

    #pragma nounroll
    for (auto const& info: sMaterialListFeatureLevel0) {
        registerPostProcessMaterial(info.name, info);
    }

    if (mEngine.getActiveFeatureLevel() >= FeatureLevel::FEATURE_LEVEL_1) {
        #pragma nounroll
        for (auto const& info: sMaterialList) {
            registerPostProcessMaterial(info.name, info);
        }
    }

    if (engine.hasFeatureLevel(FeatureLevel::FEATURE_LEVEL_1)) {
        mStarburstTexture = driver.createTexture(SamplerType::SAMPLER_2D, 1,
                TextureFormat::R8, 1, 256, 1, 1, TextureUsage::DEFAULT);

        PixelBufferDescriptor dataStarburst(driver.allocate(256), 256,
                PixelDataFormat::R, PixelDataType::UBYTE);
        std::generate_n((uint8_t*)dataStarburst.buffer, 256,
                [&dist = mUniformDistribution, &gen = mEngine.getRandomEngine()]() {
                    float const r = 0.5f + 0.5f * dist(gen);
                    return uint8_t(r * 255.0f);
                });

        driver.update3DImage(mStarburstTexture,
                0, 0, 0, 0, 256, 1, 1,
                std::move(dataStarburst));
    }
}

void PostProcessManager::terminate(DriverApi& driver) noexcept {
    FEngine& engine = mEngine;
    driver.destroyTexture(mStarburstTexture);
    auto first = mMaterialRegistry.begin();
    auto last = mMaterialRegistry.end();
    while (first != last) {
        first.value().terminate(engine);
        ++first;
    }
}

backend::Handle<backend::HwTexture> PostProcessManager::getOneTexture() const {
    return mEngine.getOneTexture();
}

backend::Handle<backend::HwTexture> PostProcessManager::getZeroTexture() const {
    return mEngine.getZeroTexture();
}

backend::Handle<backend::HwTexture> PostProcessManager::getOneTextureArray() const {
    return mEngine.getOneTextureArray();
}

backend::Handle<backend::HwTexture> PostProcessManager::getZeroTextureArray() const {
    return mEngine.getZeroTextureArray();
}

UTILS_NOINLINE
void PostProcessManager::render(FrameGraphResources::RenderPassInfo const& out,
        backend::PipelineState const& pipeline, backend::Viewport const& scissor,
        DriverApi& driver) const noexcept {

    assert_invariant(
            ((out.params.readOnlyDepthStencil & RenderPassParams::READONLY_DEPTH)
             && !pipeline.rasterState.depthWrite)
            || !(out.params.readOnlyDepthStencil & RenderPassParams::READONLY_DEPTH));

    FEngine const& engine = mEngine;
    Handle<HwRenderPrimitive> const fullScreenQuad = engine.getFullScreenRenderPrimitive();
    driver.beginRenderPass(out.target, out.params);
    driver.scissor(scissor);
    driver.draw(pipeline, fullScreenQuad, 0, 3, 1);
    driver.endRenderPass();
}

UTILS_NOINLINE
void PostProcessManager::commitAndRender(FrameGraphResources::RenderPassInfo const& out,
        PostProcessMaterial const& material, uint8_t variant, DriverApi& driver) const noexcept {
    FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
    mi->commit(driver);
    mi->use(driver);
    render(out, material.getPipelineState(mEngine, variant), driver);
}

UTILS_ALWAYS_INLINE
void PostProcessManager::commitAndRender(FrameGraphResources::RenderPassInfo const& out,
        PostProcessMaterial const& material, DriverApi& driver) const noexcept {
    commitAndRender(out, material, 0, driver);
}

// ------------------------------------------------------------------------------------------------

PostProcessManager::StructurePassOutput PostProcessManager::structure(FrameGraph& fg,
        RenderPassBuilder const& passBuilder, uint8_t structureRenderFlags,
        uint32_t width, uint32_t height,
        StructurePassConfig const& config) noexcept {

    const float scale = config.scale;

    // structure pass -- automatically culled if not used, currently used by:
    //    - ssao
    //    - contact shadows
    // It consists of a mipmapped depth pass, tuned for SSAO
    struct StructurePassData {
        FrameGraphId<FrameGraphTexture> depth;
        FrameGraphId<FrameGraphTexture> picking;
    };

    // sanitize a bit the user provided scaling factor
    width  = std::max(32u, (uint32_t)std::ceil(float(width) * scale));
    height = std::max(32u, (uint32_t)std::ceil(float(height) * scale));

    // We limit the lowest lod size to 32 pixels (which is where the -5 comes from)
    const size_t levelCount = std::min(8, FTexture::maxLevelCount(width, height) - 5);
    assert_invariant(levelCount >= 1);

    // generate depth pass at the requested resolution
    auto& structurePass = fg.addPass<StructurePassData>("Structure Pass",
            [&](FrameGraph::Builder& builder, auto& data) {
                bool const isES2 = mEngine.getDriverApi().getFeatureLevel() == FeatureLevel::FEATURE_LEVEL_0;
                data.depth = builder.createTexture("Structure Buffer", {
                        .width = width, .height = height,
                        .levels = uint8_t(levelCount),
                        .format = isES2 ? TextureFormat::DEPTH24 : TextureFormat::DEPTH32F });

                data.depth = builder.write(data.depth,
                        FrameGraphTexture::Usage::DEPTH_ATTACHMENT);

                if (config.picking) {
                    data.picking = builder.createTexture("Picking Buffer", {
                            .width = width, .height = height,
                            .format = isES2 ? TextureFormat::RGBA8 : TextureFormat::RG32F });

                    data.picking = builder.write(data.picking,
                            FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                }

                builder.declareRenderPass("Structure Target", {
                        .attachments = { .color = { data.picking }, .depth = data.depth },
                        .clearFlags = TargetBufferFlags::COLOR0 | TargetBufferFlags::DEPTH
                });
            },
            [=, passBuilder = passBuilder](FrameGraphResources const& resources,
                    auto const&, DriverApi&) mutable {
                Variant structureVariant(Variant::DEPTH_VARIANT);
                structureVariant.setPicking(config.picking);

                auto out = resources.getRenderPassInfo();

                passBuilder.renderFlags(structureRenderFlags);
                passBuilder.variant(structureVariant);
                passBuilder.commandTypeFlags(RenderPass::CommandTypeFlags::SSAO);

                RenderPass const pass{ passBuilder.build(mEngine) };
                RenderPass::execute(pass, mEngine, resources.getPassName(), out.target, out.params);
            });

    auto depth = structurePass->depth;


    struct StructureMipmapData {
        FrameGraphId<FrameGraphTexture> depth;
        uint32_t rt[8];
    };

    fg.addPass<StructureMipmapData>("StructureMipmap",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.depth = builder.sample(depth);
                for (size_t i = 1; i < levelCount; i++) {
                    auto out = builder.createSubresource(data.depth, "Structure mip", {
                            .level = uint8_t(i)
                    });
                    out = builder.write(out, FrameGraphTexture::Usage::DEPTH_ATTACHMENT);
                    data.rt[i - 1] = builder.declareRenderPass("Structure mip target", {
                            .attachments = { .depth = out }
                    });
                }
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto in = resources.getTexture(data.depth);
                auto& material = getPostProcessMaterial("mipmapDepth");
                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                mi->setParameter("depth", in, { .filterMin = SamplerMinFilter::NEAREST_MIPMAP_NEAREST });
                // The first mip already exists, so we process n-1 lods
                for (size_t level = 0; level < levelCount - 1; level++) {
                    auto out = resources.getRenderPassInfo(level);
                    driver.setMinMaxLevels(in, level, level);
                    commitAndRender(out, material, driver);
                }
                driver.setMinMaxLevels(in, 0, levelCount - 1);
            });

    return { depth, structurePass->picking };
}

// ------------------------------------------------------------------------------------------------

FrameGraphId<FrameGraphTexture> PostProcessManager::ssr(FrameGraph& fg,
        RenderPassBuilder const& passBuilder,
        FrameHistory const& frameHistory,
        CameraInfo const& cameraInfo,
        PerViewUniforms& uniforms,
        FrameGraphId<FrameGraphTexture> structure,
        ScreenSpaceReflectionsOptions const& options,
        FrameGraphTexture::Descriptor const& desc) noexcept {

    struct SSRPassData {
        // our output, the reflection map
        FrameGraphId<FrameGraphTexture> reflections;
        // we need a depth buffer for culling
        FrameGraphId<FrameGraphTexture> depth;
        // we also need the structure buffer for ray-marching
        FrameGraphId<FrameGraphTexture> structure;
        // and the history buffer for fetching the reflections
        FrameGraphId<FrameGraphTexture> history;
    };

    auto const& previous = frameHistory.getPrevious().ssr;
    if (!previous.color.handle) {
        return {};
    }

    FrameGraphId<FrameGraphTexture> history = fg.import("SSR history", previous.desc,
            FrameGraphTexture::Usage::SAMPLEABLE, previous.color);
    mat4 const& historyProjection = previous.projection;
    auto const& uvFromClipMatrix = mEngine.getUvFromClipMatrix();

    auto& ssrPass = fg.addPass<SSRPassData>("SSR Pass",
            [&](FrameGraph::Builder& builder, auto& data) {

                // Create our reflection buffer. We need an alpha channel, so we have to use RGBA16F
                data.reflections = builder.createTexture("Reflections Texture", {
                        .width = desc.width, .height = desc.height,
                        .format = TextureFormat::RGBA16F });

                // create our depth buffer, the depth buffer is never written to memory
                data.depth = builder.createTexture("Reflections Texture Depth", {
                        .width = desc.width, .height = desc.height,
                        .format = TextureFormat::DEPTH32F });

                // we're writing to both these buffers
                data.reflections = builder.write(data.reflections,
                        FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                data.depth = builder.write(data.depth,
                        FrameGraphTexture::Usage::DEPTH_ATTACHMENT);

                // finally declare our render target
                builder.declareRenderPass("Reflections Target", {
                        .attachments = { .color = { data.reflections }, .depth = data.depth },
                        .clearFlags = TargetBufferFlags::COLOR0 | TargetBufferFlags::DEPTH });

                // get the structure buffer
                assert_invariant(structure);
                data.structure = builder.sample(structure);

                if (history) {
                    data.history = builder.sample(history);
                }
            },
            [this, projection = cameraInfo.projection,
                    userViewMatrix = cameraInfo.getUserViewMatrix(), uvFromClipMatrix, historyProjection,
                    options, &uniforms, passBuilder = passBuilder]
            (FrameGraphResources const& resources, auto const& data, DriverApi& driver) mutable {
                // set structure sampler
                uniforms.prepareStructure(data.structure ?
                        resources.getTexture(data.structure) : getOneTexture());

                // set screen-space reflections and screen-space refractions
                mat4f const uvFromViewMatrix = uvFromClipMatrix * projection;
                mat4f const reprojection = uvFromClipMatrix *
                        mat4f{ historyProjection * inverse(userViewMatrix) };

                // the history sampler is a regular texture2D
                TextureHandle const history = data.history ?
                        resources.getTexture(data.history) : getZeroTexture();
                uniforms.prepareHistorySSR(history, reprojection, uvFromViewMatrix, options);

                uniforms.commit(driver);

                auto out = resources.getRenderPassInfo();

                // Remove the HAS_SHADOWING RenderFlags, since it's irrelevant when rendering reflections
                passBuilder.renderFlags(~RenderPass::HAS_SHADOWING, 0);

                // use our special SSR variant, it can only be applied to object that have
                // the SCREEN_SPACE ReflectionMode.
                passBuilder.variant(Variant{ Variant::SPECIAL_SSR });

                // generate all our drawing commands, except blended objects.
                passBuilder.commandTypeFlags(RenderPass::CommandTypeFlags::SCREEN_SPACE_REFLECTIONS);

                RenderPass const pass{ passBuilder.build(mEngine) };
                RenderPass::execute(pass, mEngine, resources.getPassName(), out.target, out.params);
            });

    return ssrPass->reflections;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::screenSpaceAmbientOcclusion(FrameGraph& fg,
        filament::Viewport const&, const CameraInfo& cameraInfo,
        FrameGraphId<FrameGraphTexture> depth,
        AmbientOcclusionOptions const& options) noexcept {
    assert_invariant(depth);

    const size_t levelCount = fg.getDescriptor(depth).levels;

    // With q the standard deviation,
    // A gaussian filter requires 6q-1 values to keep its gaussian nature
    // (see en.wikipedia.org/wiki/Gaussian_filter)
    // More intuitively, 2q is the width of the filter in pixels.
    BilateralPassConfig config = {
            .bentNormals = options.bentNormals,
            .bilateralThreshold = options.bilateralThreshold,
    };

    float sampleCount{};
    float spiralTurns{};
    float standardDeviation{};
    switch (options.quality) {
        default:
        case QualityLevel::LOW:
            sampleCount = 7.0f;
            spiralTurns = 3.0f;
            standardDeviation = 8.0;
            break;
        case QualityLevel::MEDIUM:
            sampleCount = 11.0f;
            spiralTurns = 6.0f;
            standardDeviation = 8.0;
            break;
        case QualityLevel::HIGH:
            sampleCount = 16.0f;
            spiralTurns = 7.0f;
            standardDeviation = 6.0;
            break;
        case QualityLevel::ULTRA:
            sampleCount = 32.0f;
            spiralTurns = 14.0f;
            standardDeviation = 4.0;
            break;
    }

    switch (options.lowPassFilter) {
        default:
        case QualityLevel::LOW:
            // no filtering, values don't matter
            config.kernelSize = 1;
            config.standardDeviation = 1.0f;
            config.scale = 1.0f;
            break;
        case QualityLevel::MEDIUM:
            config.kernelSize = 11;
            config.standardDeviation = standardDeviation * 0.5f;
            config.scale = 2.0f;
            break;
        case QualityLevel::HIGH:
        case QualityLevel::ULTRA:
            config.kernelSize = 23;
            config.standardDeviation = standardDeviation;
            config.scale = 1.0f;
            break;
    }

    // for debugging
    //config.kernelSize = engine.debug.ssao.kernelSize;
    //config.standardDeviation = engine.debug.ssao.stddev;
    //sampleCount = engine.debug.ssao.sampleCount;
    //spiralTurns = engine.debug.ssao.spiralTurns;


    struct SSAOPassData {
        FrameGraphId<FrameGraphTexture> depth;
        FrameGraphId<FrameGraphTexture> ssao;
        FrameGraphId<FrameGraphTexture> ao;
        FrameGraphId<FrameGraphTexture> bn;
    };

    const bool computeBentNormals = options.bentNormals;

    const bool highQualityUpsampling =
            options.upsampling >= QualityLevel::HIGH && options.resolution < 1.0f;

    const bool lowPassFilterEnabled = options.lowPassFilter != QualityLevel::LOW;

    FrameGraphId<FrameGraphTexture> duplicateDepthOutput = {};
    if (!mWorkaroundAllowReadOnlyAncillaryFeedbackLoop) {
        duplicateDepthOutput = blitDepth(fg, depth);
    }

    auto& SSAOPass = fg.addPass<SSAOPassData>(
            "SSAO Pass",
            [&](FrameGraph::Builder& builder, auto& data) {
                auto const& desc = builder.getDescriptor(depth);

                data.depth = builder.sample(depth);
                data.ssao = builder.createTexture("SSAO Buffer", {
                        .width = desc.width,
                        .height = desc.height,
                        .depth = computeBentNormals ? 2u : 1u,
                        .type = Texture::Sampler::SAMPLER_2D_ARRAY,
                        .format = (lowPassFilterEnabled || highQualityUpsampling || computeBentNormals) ?
                                TextureFormat::RGB8 : TextureFormat::R8
                });

                if (computeBentNormals) {
                    data.ao = builder.createSubresource(data.ssao, "SSAO attachment", { .layer = 0 });
                    data.bn = builder.createSubresource(data.ssao, "Bent Normals attachment", { .layer = 1 });
                    data.ao = builder.write(data.ao, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                    data.bn = builder.write(data.bn, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                } else {
                    data.ao = data.ssao;
                    data.ao = builder.write(data.ao, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                }

                // Here we use the depth test to skip pixels at infinity (i.e. the skybox)
                // Note that we have to clear the SAO buffer because blended objects will end-up
                // reading into it even though they were not written in the depth buffer.
                // The bilateral filter in the blur pass will ignore pixels at infinity.

                auto depthAttachment = duplicateDepthOutput ? duplicateDepthOutput : data.depth;

                depthAttachment = builder.read(depthAttachment,
                        FrameGraphTexture::Usage::DEPTH_ATTACHMENT);
                builder.declareRenderPass("SSAO Target", {
                        .attachments = { .color = { data.ao, data.bn }, .depth = depthAttachment },
                        .clearColor = { 1.0f },
                        .clearFlags = TargetBufferFlags::COLOR0 | TargetBufferFlags::COLOR1
                });
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto depth = resources.getTexture(data.depth);
                auto ssao = resources.getRenderPassInfo();
                auto const& desc = resources.getDescriptor(data.depth);

                // Estimate of the size in pixel units of a 1m tall/wide object viewed from 1m away (i.e. at z=-1)
                const float projectionScale = std::min(
                        0.5f * cameraInfo.projection[0].x * desc.width,
                        0.5f * cameraInfo.projection[1].y * desc.height);

                // Where the falloff function peaks
                const float peak = 0.1f * options.radius;
                const float intensity = (f::TAU * peak) * options.intensity;
                // always square AO result, as it looks much better
                const float power = options.power * 2.0f;

                const auto invProjection = inverse(cameraInfo.projection);
                const float inc = (1.0f / (sampleCount - 0.5f)) * spiralTurns * f::TAU;

                const mat4 screenFromClipMatrix{ mat4::row_major_init{
                        0.5 * desc.width, 0.0, 0.0, 0.5 * desc.width,
                        0.0, 0.5 * desc.height, 0.0, 0.5 * desc.height,
                        0.0, 0.0, 0.5, 0.5,
                        0.0, 0.0, 0.0, 1.0
                }};

                auto& material = computeBentNormals ?
                            getPostProcessMaterial("saoBentNormals") :
                            getPostProcessMaterial("sao");

                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                mi->setParameter("depth", depth, {
                        .filterMin = SamplerMinFilter::NEAREST_MIPMAP_NEAREST });
                mi->setParameter("screenFromViewMatrix",
                        mat4f(screenFromClipMatrix * cameraInfo.projection));
                mi->setParameter("resolution",
                        float4{ desc.width, desc.height, 1.0f / desc.width, 1.0f / desc.height });
                mi->setParameter("invRadiusSquared",
                        1.0f / (options.radius * options.radius));
                mi->setParameter("minHorizonAngleSineSquared",
                        std::pow(std::sin(options.minHorizonAngleRad), 2.0f));
                mi->setParameter("projectionScale",
                        projectionScale);
                mi->setParameter("projectionScaleRadius",
                        projectionScale * options.radius);
                mi->setParameter("positionParams", float2{
                        invProjection[0][0], invProjection[1][1] } * 2.0f);
                mi->setParameter("peak2", peak * peak);
                mi->setParameter("bias", options.bias);
                mi->setParameter("power", power);
                mi->setParameter("intensity", intensity / sampleCount);
                mi->setParameter("maxLevel", uint32_t(levelCount - 1));
                mi->setParameter("sampleCount", float2{ sampleCount, 1.0f / (sampleCount - 0.5f) });
                mi->setParameter("spiralTurns", spiralTurns);
                mi->setParameter("angleIncCosSin", float2{ std::cos(inc), std::sin(inc) });
                mi->setParameter("invFarPlane", 1.0f / -cameraInfo.zf);

                mi->setParameter("ssctShadowDistance", options.ssct.shadowDistance);
                mi->setParameter("ssctConeAngleTangeant", std::tan(options.ssct.lightConeRad * 0.5f));
                mi->setParameter("ssctContactDistanceMaxInv", 1.0f / options.ssct.contactDistanceMax);
                // light direction in view space
                const mat4f view{ cameraInfo.getUserViewMatrix() };
                const float3 l = normalize(
                        mat3f::getTransformForNormals(view.upperLeft())
                                * options.ssct.lightDirection);
                mi->setParameter("ssctIntensity",
                        options.ssct.enabled ? options.ssct.intensity : 0.0f);
                mi->setParameter("ssctVsLightDirection", -l);
                mi->setParameter("ssctDepthBias",
                        float2{ options.ssct.depthBias, options.ssct.depthSlopeBias });
                mi->setParameter("ssctSampleCount", uint32_t(options.ssct.sampleCount));
                mi->setParameter("ssctRayCount",
                        float2{ options.ssct.rayCount, 1.0f / float(options.ssct.rayCount) });

                mi->commit(driver);
                mi->use(driver);

                auto pipeline = material.getPipelineState(mEngine);
                pipeline.first.rasterState.depthFunc = RasterState::DepthFunc::L;
                assert_invariant(ssao.params.readOnlyDepthStencil & RenderPassParams::READONLY_DEPTH);
                render(ssao, pipeline, driver);
            });

    FrameGraphId<FrameGraphTexture> ssao = SSAOPass->ssao;


    if (lowPassFilterEnabled) {
        ssao = bilateralBlurPass(fg, ssao, depth, { config.scale, 0 },
                cameraInfo.zf,
                TextureFormat::RGB8,
                config);

        ssao = bilateralBlurPass(fg, ssao, depth, { 0, config.scale },
                cameraInfo.zf,
                (highQualityUpsampling || computeBentNormals) ? TextureFormat::RGB8
                                                              : TextureFormat::R8,
                config);
    }

    return ssao;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::bilateralBlurPass(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input,
        FrameGraphId<FrameGraphTexture> depth,
        math::int2 axis, float zf, TextureFormat format,
        BilateralPassConfig const& config) noexcept {
    assert_invariant(depth);

    struct BlurPassData {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> blurred;
        FrameGraphId<FrameGraphTexture> ao;
        FrameGraphId<FrameGraphTexture> bn;
    };

    auto& blurPass = fg.addPass<BlurPassData>("Separable Blur Pass",
            [&](FrameGraph::Builder& builder, auto& data) {

                auto const& desc = builder.getDescriptor(input);

                data.input = builder.sample(input);

                data.blurred = builder.createTexture("Blurred output", {
                        .width = desc.width,
                        .height = desc.height,
                        .depth = desc.depth,
                        .type = desc.type,
                        .format = format });

                depth = builder.read(depth, FrameGraphTexture::Usage::DEPTH_ATTACHMENT);

                if (config.bentNormals) {
                    data.ao = builder.createSubresource(data.blurred, "SSAO attachment", { .layer = 0 });
                    data.bn = builder.createSubresource(data.blurred, "Bent Normals attachment", { .layer = 1 });
                    data.ao = builder.write(data.ao, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                    data.bn = builder.write(data.bn, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                } else {
                    data.ao = data.blurred;
                    data.ao = builder.write(data.ao, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                }

                // Here we use the depth test to skip pixels at infinity (i.e. the skybox)
                // We need to clear the buffers because we are skipping pixels at infinity (skybox)
                data.blurred = builder.write(data.blurred, FrameGraphTexture::Usage::COLOR_ATTACHMENT);

                builder.declareRenderPass("Blurred target", {
                        .attachments = { .color = { data.ao, data.bn }, .depth = depth },
                        .clearColor = { 1.0f },
                        .clearFlags = TargetBufferFlags::COLOR0 | TargetBufferFlags::COLOR1
                });
            },
            [=](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {
                auto ssao = resources.getTexture(data.input);
                auto blurred = resources.getRenderPassInfo();
                auto const& desc = resources.getDescriptor(data.blurred);

                // unnormalized gaussian half-kernel of a given standard deviation
                // returns number of samples stored in the array (max 16)
                constexpr size_t kernelArraySize = 16; // limited by bilateralBlur.mat
                auto gaussianKernel =
                        [kernelArraySize](float* outKernel, size_t gaussianWidth, float stdDev) -> uint32_t {
                    const size_t gaussianSampleCount = std::min(kernelArraySize, (gaussianWidth + 1u) / 2u);
                    for (size_t i = 0; i < gaussianSampleCount; i++) {
                        float const x = float(i);
                        float const g = std::exp(-(x * x) / (2.0f * stdDev * stdDev));
                        outKernel[i] = g;
                    }
                    return uint32_t(gaussianSampleCount);
                };

                float kGaussianSamples[kernelArraySize];
                uint32_t const kGaussianCount = gaussianKernel(kGaussianSamples,
                        config.kernelSize, config.standardDeviation);

                auto& material = config.bentNormals ?
                        getPostProcessMaterial("bilateralBlurBentNormals") :
                        getPostProcessMaterial("bilateralBlur");
                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                });
                mi->setParameter("level", 0.0f);
                mi->setParameter("layer", 0.0f);
                mi->setParameter("axis", float2{ 0, 1.0f / tempDesc.height });
                mi->commit(driver);
                // we don't need to call use() here, since it's the same material

                render(hwOutRT, separableGaussianBlur.getPipelineState(mEngine), driver);
            });

    return blurPass->out;
}

PostProcessManager::ScreenSpaceRefConfig PostProcessManager::prepareMipmapSSR(FrameGraph& fg,
        uint32_t width, uint32_t height, backend::TextureFormat format,
        float verticalFieldOfView, float2 scale) noexcept {

    // The kernel-size was determined empirically so that we don't get too many artifacts
    // due to the down-sampling with a box filter (which happens implicitly).
    // Requires only 6 stored coefficients and 11 tap/pass
    // e.g.: size of 13 (4 stored coefficients)
    //      +-------+-------+-------*===*-------+-------+-------+
    //  ... | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | ...
    //      +-------+-------+-------*===*-------+-------+-------+
    constexpr size_t kernelSize = 21u;

    // The relation between the kernel size N and sigma (standard deviation) is 6*sigma - 1 = N
    // and is designed so the filter keeps its "gaussian-ness".
    // The standard deviation sigma0 is expressed in texels.
    constexpr float sigma0 = (kernelSize + 1u) / 6.0f;

    static_assert(kernelSize & 1u,
            "kernel size must be odd");

    static_assert((((kernelSize - 1u) / 2u) & 1u) == 0,
            "kernel positive side size must be even");

    // texel size of the reflection buffer in world units at 1 meter
    constexpr float d = 1.0f; // 1m
    const float texelSizeAtOneMeter = d * std::tan(verticalFieldOfView) / float(height);


    const float refractionLodOffset =
            -std::log2(f::SQRT2 * sigma0 * texelSizeAtOneMeter);

    // LOD count, we don't go lower than 16 texel in one dimension
    uint8_t roughnessLodCount = FTexture::maxLevelCount(width, height);
    roughnessLodCount = std::max(std::min(4, +roughnessLodCount), +roughnessLodCount - 4);

    // Make sure we keep the original buffer aspect ratio (this is because dynamic-resolution is
    // not necessarily homogenous).
    uint32_t w = width;
    uint32_t h = height;
    if (scale.x != scale.y) {
        // dynamic resolution wasn't homogenous, which would affect the blur, so make sure to
        // keep an intermediary buffer that has the same aspect-ratio as the original.
        const float homogenousScale = std::sqrt(scale.x * scale.y);
        w = uint32_t((homogenousScale / scale.x) * float(width));
        h = uint32_t((homogenousScale / scale.y) * float(height));
    }

    const FrameGraphTexture::Descriptor outDesc{
            .width = w, .height = h, .depth = 2,
            .levels = roughnessLodCount,
            .type = SamplerType::SAMPLER_2D_ARRAY,
            .format = format,
    };

    struct PrepareMipmapSSRPassData {
        FrameGraphId<FrameGraphTexture> ssr;
        FrameGraphId<FrameGraphTexture> refraction;
        FrameGraphId<FrameGraphTexture> reflection;
    };
    auto& pass = fg.addPass<PrepareMipmapSSRPassData>("Prepare MipmapSSR Pass",
            [&](FrameGraph::Builder& builder, auto& data){
                // create the SSR 2D array
                data.ssr = builder.createTexture("ssr", outDesc);
                // create the refraction subresource at layer 0
                data.refraction = builder.createSubresource(data.ssr, "refraction", {.layer = 0 });
                // create the reflection subresource at layer 1
                data.reflection = builder.createSubresource(data.ssr, "reflection", {.layer = 1 });
            });

    return {
            .ssr = pass->ssr,
            .refraction = pass->refraction,
            .reflection = pass->reflection,
            .lodOffset = refractionLodOffset,
            .roughnessLodCount = roughnessLodCount,
            .kernelSize = kernelSize,
            .sigma0 = sigma0
    };
}

FrameGraphId<FrameGraphTexture> PostProcessManager::generateMipmapSSR(
        PostProcessManager& ppm, FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input,
        FrameGraphId<FrameGraphTexture> output,
        bool needInputDuplication, ScreenSpaceRefConfig const& config) noexcept {

    // Descriptor of our actual input image (e.g. reflection buffer or refraction framebuffer)
    auto const& desc = fg.getDescriptor(input);

    // Descriptor of the destination. `output` is a subresource (i.e. a layer of a 2D array)
    auto const& outDesc = fg.getDescriptor(output);


    // needInputDuplication:
    // In some situations it's not possible to use the FrameGraph's forwardResource(),
    // as an optimization because the SSR buffer must be distinct from the color buffer
    // (input here), because we can't read and write into the same buffer (e.g. for refraction).

    if (needInputDuplication || outDesc.width != desc.width || outDesc.height != desc.height) {
        if (desc.samples > 1 &&
                outDesc.width == desc.width && outDesc.height == desc.height &&
                desc.format == outDesc.format) {
            // Resolve directly into the destination. This guarantees a blit/resolve will be
            // performed (i.e.: the source is copied) and we also guarantee that format/scaling
            // is the same after the forwardResource call below.
            input = ppm.resolve(fg, "ssr", input, outDesc);
        } else {
            // First resolve (if needed), may be a no-op. Guarantees that format/size is unchanged
            // by construction.
            input = ppm.resolve(fg, "ssr", input, { .levels = 1 });
            // Then blit into an appropriate texture, this handles scaling and format conversion.
            // The input/output sizes may differ when non-homogenous DSR is enabled.
            input = ppm.blit(fg, false, input, { 0, 0, desc.width, desc.height }, outDesc,
                    SamplerMagFilter::LINEAR, SamplerMinFilter::LINEAR);
        }
    }

    // A lot of magic happens right here. This forward call replaces 'input' (which is either
    // the actual input we received when entering this function, or, a resolved version of it) by
    // our output. Effectively, forcing the methods *above* to render into our output.
    output = fg.forwardResource(output, input);


    return ppm.generateGaussianMipmap(fg, output, config.roughnessLodCount,
            true, config.kernelSize, config.sigma0);
}

FrameGraphId<FrameGraphTexture> PostProcessManager::dof(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input,
        FrameGraphId<FrameGraphTexture> depth,
        const CameraInfo& cameraInfo,
        bool translucent,
        float2 bokehScale,
        const DepthOfFieldOptions& dofOptions) noexcept {

    assert_invariant(depth);

    const uint8_t variant = uint8_t(
            translucent ? PostProcessVariant::TRANSLUCENT : PostProcessVariant::OPAQUE);

    const TextureFormat format = translucent ? TextureFormat::RGBA16F
                                             : TextureFormat::R11F_G11F_B10F;

    // Rotate the bokeh based on the aperture diameter (i.e. angle of the blades)
    float bokehAngle = f::PI / 6.0f;
    if (dofOptions.maxApertureDiameter > 0.0f) {
        bokehAngle += f::PI_2 * saturate(cameraInfo.A / dofOptions.maxApertureDiameter);
    }

    const float focusDistance = cameraInfo.d;
    auto const& desc = fg.getDescriptor<FrameGraphTexture>(input);
    const float Kc = (cameraInfo.A * cameraInfo.f) / (focusDistance - cameraInfo.f);
    const float Ks = ((float)desc.height) / FCamera::SENSOR_SIZE;
    const float K  = dofOptions.cocScale * Ks * Kc;

    auto const& p = cameraInfo.projection;
    const float2 cocParams = {
              K * focusDistance * p[2][3] / p[3][2],
              K * (1.0 + focusDistance * p[2][2] / p[3][2])
    };

    const uint32_t dofResolution = dofOptions.nativeResolution ? 1u : 2u;

    auto const& colorDesc = fg.getDescriptor(input);
    const uint32_t width  = colorDesc.width  / dofResolution;
    const uint32_t height = colorDesc.height / dofResolution;

    // at full resolution, 4 "safe" levels are guaranteed
    constexpr const uint32_t maxMipLevels = 4u;

    // compute numbers of "safe" levels (should be 4, but can be 3 at half res)
    const uint8_t mipmapCount = std::min(maxMipLevels, ctz(width | height));
    assert_invariant(mipmapCount == maxMipLevels || mipmapCount == maxMipLevels-1);


    struct PostProcessDofDownsample {
        FrameGraphId<FrameGraphTexture> color;
        FrameGraphId<FrameGraphTexture> depth;
        FrameGraphId<FrameGraphTexture> outColor;
        FrameGraphId<FrameGraphTexture> outCoc;
    };

    auto& ppDoFDownsample = fg.addPass<PostProcessDofDownsample>("DoF Downsample",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.color = builder.sample(input);
                data.depth = builder.sample(depth);

                data.outColor = builder.createTexture("dof downsample output", {
                        .width  = width, .height = height, .levels = mipmapCount, .format = format
                });
                data.outCoc = builder.createTexture("dof CoC output", {
                        .width  = width, .height = height, .levels = mipmapCount,
                        .format = TextureFormat::R16F,
                        .swizzle = {
                                // the next stage expects min/max CoC in the red/green channel
                                .r = backend::TextureSwizzle::CHANNEL_0,
                                .g = backend::TextureSwizzle::CHANNEL_0 },
                });
                data.outColor = builder.write(data.outColor, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                data.outCoc   = builder.write(data.outCoc,   FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                builder.declareRenderPass("DoF Target", { .attachments = {
                                .color = { data.outColor, data.outCoc }
                        }
                });
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto const& out = resources.getRenderPassInfo();
                auto color = resources.getTexture(data.color);
                auto depth = resources.getTexture(data.depth);
                auto const& material = (dofResolution == 1) ?
                        getPostProcessMaterial("dofCoc") :
                        getPostProcessMaterial("dofDownsample");
                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                mi->setParameter("color", color, { .filterMin = SamplerMinFilter::NEAREST });
                mi->setParameter("depth", depth, { .filterMin = SamplerMinFilter::NEAREST });
                mi->setParameter("cocParams", cocParams);
                mi->setParameter("cocClamp", float2{
                    -(dofOptions.maxForegroundCOC ? dofOptions.maxForegroundCOC : DOF_DEFAULT_MAX_COC),
                      dofOptions.maxBackgroundCOC ? dofOptions.maxBackgroundCOC : DOF_DEFAULT_MAX_COC});
                mi->setParameter("texelSize", float2{
                        1.0f / float(colorDesc.width),
                        1.0f / float(colorDesc.height) });
                commitAndRender(out, material, driver);
            });


    struct PostProcessDofMipmap {
        FrameGraphId<FrameGraphTexture> inOutColor;
        FrameGraphId<FrameGraphTexture> inOutCoc;
        uint32_t rp[maxMipLevels];
    };

    assert_invariant(mipmapCount - 1 <= sizeof(PostProcessDofMipmap::rp) / sizeof(uint32_t));

    auto& ppDoFMipmap = fg.addPass<PostProcessDofMipmap>("DoF Mipmap",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.inOutColor = builder.sample(ppDoFDownsample->outColor);
                data.inOutCoc   = builder.sample(ppDoFDownsample->outCoc);
                for (size_t i = 0; i < mipmapCount - 1u; i++) {
                    // make sure inputs are always multiple of two (should be true by construction)
                    // (this is so that we can compute clean mip levels)
                    assert_invariant((FTexture::valueForLevel(uint8_t(i), fg.getDescriptor(data.inOutColor).width ) & 0x1u) == 0);
                    assert_invariant((FTexture::valueForLevel(uint8_t(i), fg.getDescriptor(data.inOutColor).height) & 0x1u) == 0);

                    auto inOutColor = builder.createSubresource(data.inOutColor, "Color mip", { .level = uint8_t(i + 1) });
                    auto inOutCoc   = builder.createSubresource(data.inOutCoc, "Coc mip", { .level = uint8_t(i + 1) });

                    inOutColor = builder.write(inOutColor, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                    inOutCoc   = builder.write(inOutCoc,   FrameGraphTexture::Usage::COLOR_ATTACHMENT);

                    data.rp[i] = builder.declareRenderPass("DoF Target", { .attachments = {
                                .color = { inOutColor, inOutCoc  }
                        }
                    });
                }
            },
            [=](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {

                auto desc       = resources.getDescriptor(data.inOutColor);
                auto inOutColor = resources.getTexture(data.inOutColor);
                auto inOutCoc   = resources.getTexture(data.inOutCoc);

                auto const& material = getPostProcessMaterial("dofMipmap");
                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                mi->setParameter("color", inOutColor, { .filterMin = SamplerMinFilter::NEAREST_MIPMAP_NEAREST });
                mi->setParameter("coc",   inOutCoc,   { .filterMin = SamplerMinFilter::NEAREST_MIPMAP_NEAREST });
                mi->use(driver);

                auto const pipeline = material.getPipelineState(mEngine, variant);

                for (size_t level = 0 ; level < mipmapCount - 1u ; level++) {
                    const float w = FTexture::valueForLevel(level, desc.width);
                    const float h = FTexture::valueForLevel(level, desc.height);

                    auto const& out = resources.getRenderPassInfo(data.rp[level]);
                    driver.setMinMaxLevels(inOutColor, level, level);
                    driver.setMinMaxLevels(inOutCoc, level, level);
                    mi->setParameter("weightScale", 0.5f / float(1u << level));   // FIXME: halfres?
                    mi->setParameter("texelSize", float2{ 1.0f / w, 1.0f / h });
                    mi->commit(driver);
                    render(out, pipeline, driver);
                }
                driver.setMinMaxLevels(inOutColor, 0, mipmapCount - 1u);
                driver.setMinMaxLevels(inOutCoc, 0, mipmapCount - 1u);
            });


    auto inTilesCocMinMax = ppDoFDownsample->outCoc;

    // TODO: Should the tile size be in real pixels? i.e. always 16px instead of being dependant on
    //       the DoF effect resolution?
    // Size of a tile in full-resolution pixels -- must match TILE_SIZE in dofDilate.mat
    const size_t tileSize = 16;

    // we assume the width/height is already multiple of 16
    assert_invariant(!(colorDesc.width  & 0xF) && !(colorDesc.height & 0xF));
    const uint32_t tileBufferWidth  = width;
    const uint32_t tileBufferHeight = height;
    const size_t tileReductionCount = ctz(tileSize / dofResolution);

    struct PostProcessDofTiling1 {
        FrameGraphId<FrameGraphTexture> inCocMinMax;
        FrameGraphId<FrameGraphTexture> outTilesCocMinMax;
    };

    const bool textureSwizzleSupported = Texture::isTextureSwizzleSupported(mEngine);
    for (size_t i = 0; i < tileReductionCount; i++) {
        auto& ppDoFTiling = fg.addPass<PostProcessDofTiling1>("DoF Tiling",
                [&](FrameGraph::Builder& builder, auto& data) {

                    // this must be true by construction
                    assert_invariant(((tileBufferWidth  >> i) & 1u) == 0);
                    assert_invariant(((tileBufferHeight >> i) & 1u) == 0);

                    data.inCocMinMax = builder.sample(inTilesCocMinMax);
                    data.outTilesCocMinMax = builder.createTexture("dof tiles output", {
                            .width  = tileBufferWidth  >> (i + 1u),
                            .height = tileBufferHeight >> (i + 1u),
                            .format = TextureFormat::RG16F
                    });
                    data.outTilesCocMinMax = builder.declareRenderPass(data.outTilesCocMinMax);
                },
                [=](FrameGraphResources const& resources,
                        auto const& data, DriverApi& driver) {
                    auto const& inputDesc = resources.getDescriptor(data.inCocMinMax);
                    auto const& out = resources.getRenderPassInfo();
                    auto inCocMinMax = resources.getTexture(data.inCocMinMax);
                    auto const& material = (!textureSwizzleSupported && (i == 0)) ?
                            getPostProcessMaterial("dofTilesSwizzle") :
                            getPostProcessMaterial("dofTiles");
                    FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                    mi->setParameter("cocMinMax", inCocMinMax, { .filterMin = SamplerMinFilter::NEAREST });
                    mi->setParameter("texelSize", float2{ 1.0f / inputDesc.width, 1.0f / inputDesc.height });
                    commitAndRender(out, material, driver);
                });
        inTilesCocMinMax = ppDoFTiling->outTilesCocMinMax;
    }


    // This is a small helper that does one round of dilate
    auto dilate = [&](FrameGraphId<FrameGraphTexture> input) -> FrameGraphId<FrameGraphTexture> {

        struct PostProcessDofDilate {
            FrameGraphId<FrameGraphTexture> inTilesCocMinMax;
            FrameGraphId<FrameGraphTexture> outTilesCocMinMax;
        };

        auto& ppDoFDilate = fg.addPass<PostProcessDofDilate>("DoF Dilate",
                [&](FrameGraph::Builder& builder, auto& data) {
                    auto const& inputDesc = fg.getDescriptor(input);
                    data.inTilesCocMinMax = builder.sample(input);
                    data.outTilesCocMinMax = builder.createTexture("dof dilated tiles output", inputDesc);
                    data.outTilesCocMinMax = builder.declareRenderPass(data.outTilesCocMinMax );
                },
                [=](FrameGraphResources const& resources,
                        auto const& data, DriverApi& driver) {
                    auto const& out = resources.getRenderPassInfo();
                    auto inTilesCocMinMax = resources.getTexture(data.inTilesCocMinMax);
                    auto const& material = getPostProcessMaterial("dofDilate");
                    FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                    mi->setParameter("tiles", inTilesCocMinMax, { .filterMin = SamplerMinFilter::NEAREST });
                    commitAndRender(out, material, driver);
                });
        return ppDoFDilate->outTilesCocMinMax;
    };

    // Tiles of 16 full-resolution pixels requires two dilate rounds to accommodate our max Coc of 32 pixels
    // (note: when running at half-res, the tiles are 8 half-resolution pixels, and still need two
    //  dilate rounds to accommodate the mac CoC pf 16 half-resolution pixels)
    auto dilated = dilate(inTilesCocMinMax);
    dilated = dilate(dilated);


    struct PostProcessDof {
        FrameGraphId<FrameGraphTexture> color;
        FrameGraphId<FrameGraphTexture> coc;
        FrameGraphId<FrameGraphTexture> tilesCocMinMax;
        FrameGraphId<FrameGraphTexture> outColor;
        FrameGraphId<FrameGraphTexture> outAlpha;
    };

    auto& ppDoF = fg.addPass<PostProcessDof>("DoF",
            [&](FrameGraph::Builder& builder, auto& data) {

                data.color          = builder.sample(ppDoFMipmap->inOutColor);
                data.coc            = builder.sample(ppDoFMipmap->inOutCoc);
                data.tilesCocMinMax = builder.sample(dilated);

                data.outColor = builder.createTexture("dof color output", {
                        .width  = colorDesc.width  / dofResolution,
                        .height = colorDesc.height / dofResolution,
                        .format = fg.getDescriptor(data.color).format
                });
                data.outAlpha = builder.createTexture("dof alpha output", {
                        .width  = colorDesc.width  / dofResolution,
                        .height = colorDesc.height / dofResolution,
                        .format = TextureFormat::R8
                });
                data.outColor  = builder.write(data.outColor, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                data.outAlpha  = builder.write(data.outAlpha, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                builder.declareRenderPass("DoF Target", {
                        .attachments = { .color = { data.outColor, data.outAlpha }}
                });
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto const& out = resources.getRenderPassInfo();

                auto color          = resources.getTexture(data.color);
                auto coc            = resources.getTexture(data.coc);
                auto tilesCocMinMax = resources.getTexture(data.tilesCocMinMax);

                auto const& inputDesc = resources.getDescriptor(data.coc);

                auto const& material = getPostProcessMaterial("dof");
                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                // it's not safe to use bilinear filtering in the general case (causes artifacts around edges)
                mi->setParameter("color", color,
                        { .filterMin = SamplerMinFilter::NEAREST_MIPMAP_NEAREST });
                mi->setParameter("colorLinear", color,
                        { .filterMin = SamplerMinFilter::LINEAR_MIPMAP_NEAREST });
                mi->setParameter("coc", coc,
                        { .filterMin = SamplerMinFilter::NEAREST_MIPMAP_NEAREST });
                mi->setParameter("tiles", tilesCocMinMax,
                        { .filterMin = SamplerMinFilter::NEAREST });
                mi->setParameter("cocToTexelScale", float2{
                        bokehScale.x / (inputDesc.width * dofResolution),
                        bokehScale.y / (inputDesc.height * dofResolution)
                });
                mi->setParameter("cocToPixelScale", (1.0f / float(dofResolution)));
                mi->setParameter("ringCounts", float4{
                    dofOptions.foregroundRingCount ? dofOptions.foregroundRingCount : DOF_DEFAULT_RING_COUNT,
                    dofOptions.backgroundRingCount ? dofOptions.backgroundRingCount : DOF_DEFAULT_RING_COUNT,
                    dofOptions.fastGatherRingCount ? dofOptions.fastGatherRingCount : DOF_DEFAULT_RING_COUNT,
                    0.0 // unused for now
                });
                mi->setParameter("bokehAngle",  bokehAngle);
                commitAndRender(out, material, driver);
            });


    struct PostProcessDofMedian {
        FrameGraphId<FrameGraphTexture> inColor;
        FrameGraphId<FrameGraphTexture> inAlpha;
        FrameGraphId<FrameGraphTexture> tilesCocMinMax;
        FrameGraphId<FrameGraphTexture> outColor;
        FrameGraphId<FrameGraphTexture> outAlpha;
    };

    auto& ppDoFMedian = fg.addPass<PostProcessDofMedian>("DoF Median",
            [&](FrameGraph::Builder& builder, auto& data) {

                data.inColor        = builder.sample(ppDoF->outColor);
                data.inAlpha        = builder.sample(ppDoF->outAlpha);
                data.tilesCocMinMax = builder.sample(dilated);

                data.outColor = builder.createTexture("dof color output", fg.getDescriptor(data.inColor));
                data.outAlpha = builder.createTexture("dof alpha output", fg.getDescriptor(data.inAlpha));
                data.outColor = builder.write(data.outColor, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                data.outAlpha = builder.write(data.outAlpha, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                builder.declareRenderPass("DoF Target", {
                        .attachments = { .color = { data.outColor, data.outAlpha }}
                });
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto const& out = resources.getRenderPassInfo();

                auto inColor        = resources.getTexture(data.inColor);
                auto inAlpha        = resources.getTexture(data.inAlpha);
                auto tilesCocMinMax = resources.getTexture(data.tilesCocMinMax);

                auto const& material = getPostProcessMaterial("dofMedian");
                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                mi->setParameter("dof",   inColor,        { .filterMin = SamplerMinFilter::NEAREST_MIPMAP_NEAREST });
                mi->setParameter("alpha", inAlpha,        { .filterMin = SamplerMinFilter::NEAREST_MIPMAP_NEAREST });
                mi->setParameter("tiles", tilesCocMinMax, { .filterMin = SamplerMinFilter::NEAREST });
                commitAndRender(out, material, driver);
            });



    auto outColor = ppDoFMedian->outColor;
    auto outAlpha = ppDoFMedian->outAlpha;
    if (dofOptions.filter == DepthOfFieldOptions::Filter::NONE) {
        outColor = ppDoF->outColor;
        outAlpha = ppDoF->outAlpha;
    }

    struct PostProcessDofCombine {
        FrameGraphId<FrameGraphTexture> color;
        FrameGraphId<FrameGraphTexture> dof;
        FrameGraphId<FrameGraphTexture> alpha;
        FrameGraphId<FrameGraphTexture> tilesCocMinMax;
        FrameGraphId<FrameGraphTexture> output;
    };

    auto& ppDoFCombine = fg.addPass<PostProcessDofCombine>("DoF combine",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.color      = builder.sample(input);
                data.dof        = builder.sample(outColor);
                data.alpha      = builder.sample(outAlpha);
                data.tilesCocMinMax = builder.sample(dilated);
                auto const& inputDesc = fg.getDescriptor(data.color);
                data.output = builder.createTexture("DoF output", inputDesc);
                data.output = builder.declareRenderPass(data.output);
            },
            [=](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {
                auto const& out = resources.getRenderPassInfo();

                auto color      = resources.getTexture(data.color);
                auto dof        = resources.getTexture(data.dof);
                auto alpha      = resources.getTexture(data.alpha);
                auto tilesCocMinMax = resources.getTexture(data.tilesCocMinMax);

                auto const& material = getPostProcessMaterial("dofCombine");
                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                mi->setParameter("color", color, { .filterMin = SamplerMinFilter::NEAREST });
                mi->setParameter("dof",   dof,   { .filterMag = SamplerMagFilter::NEAREST });
                mi->setParameter("alpha", alpha, { .filterMag = SamplerMagFilter::NEAREST });
                mi->setParameter("tiles", tilesCocMinMax, { .filterMin = SamplerMinFilter::NEAREST });
                commitAndRender(out, material, driver);
            });

    return ppDoFCombine->output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::downscalePass(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input,
        FrameGraphTexture::Descriptor const& outDesc,
        bool threshold, float highlight, bool fireflies) noexcept {
    struct DownsampleData {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
    };
    auto& downsamplePass = fg.addPass<DownsampleData>("Downsample",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.input = builder.sample(input);
                data.output = builder.createTexture("Downsample-output", outDesc);
                builder.declareRenderPass(data.output);
            },
            [=](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {
                auto const& material = getPostProcessMaterial("bloomDownsample2x");
                auto* mi = material.getMaterialInstance(mEngine);
                mi->setParameter("source", resources.getTexture(data.input), {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR
                });
                mi->setParameter("level", 0);
                mi->setParameter("threshold", threshold ? 1.0f : 0.0f);
                mi->setParameter("fireflies", fireflies ? 1.0f : 0.0f);
                mi->setParameter("invHighlight", std::isinf(highlight) ? 0.0f : 1.0f / highlight);
                commitAndRender(resources.getRenderPassInfo(), material, driver);
            });
    return downsamplePass->output;
}

PostProcessManager::BloomPassOutput PostProcessManager::bloom(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input, TextureFormat outFormat,
        BloomOptions& inoutBloomOptions,
        TemporalAntiAliasingOptions const& taaOptions,
        float2 scale) noexcept {

    // Figure out a good size for the bloom buffer. We must use a fixed bloom buffer size so
    // that the size/strength of the bloom doesn't vary much with the resolution, otherwise
    // dynamic resolution would affect the bloom effect too much.
    auto desc = fg.getDescriptor(input);

    // width and height after dynamic resolution upscaling
    const float aspect = (float(desc.width) * scale.y) / (float(desc.height) * scale.x);

    // FIXME: don't allow inoutBloomOptions.resolution to be larger than input's resolution
    //        (avoid upscale) but how does this affect dynamic resolution
    // FIXME: check what happens on WebGL and intel's processors

    // compute the desired bloom buffer size
    float bloomHeight = float(inoutBloomOptions.resolution);
    float bloomWidth  = bloomHeight * aspect;

    // we might need to adjust the max # of levels
    const uint32_t major = uint32_t(std::max(bloomWidth,  bloomHeight));
    const uint8_t maxLevels = FTexture::maxLevelCount(major);
    inoutBloomOptions.levels = std::min(inoutBloomOptions.levels, maxLevels);
    inoutBloomOptions.levels = std::min(inoutBloomOptions.levels, kMaxBloomLevels);

    if (inoutBloomOptions.quality == QualityLevel::LOW) {
        // In low quality mode, we adjust the bloom buffer size so that both dimensions
        // have enough exact mip levels. This can slightly affect the aspect ratio causing
        // some artifacts:
        // - add some anamorphism (experimentally not visible)
        // - visible bloom size changes with dynamic resolution in non-homogenous mode
        // This allows us to use the 9 sample downsampling filter (instead of 13)
        // for at least 4 levels.
        uint32_t width  = std::max(1u, uint32_t(std::floor(bloomWidth)));
        uint32_t height = std::max(1u, uint32_t(std::floor(bloomHeight)));
        width  &= ~((1 << 4) - 1);  // at least 4 levels
        height &= ~((1 << 4) - 1);
        bloomWidth  = float(width);
        bloomHeight = float(height);
    }

    bool threshold = inoutBloomOptions.threshold;

    // we don't need to do the fireflies reduction if we have TAA (it already does it)
    bool fireflies = threshold && !taaOptions.enabled;

    while (2 * bloomWidth < float(desc.width) || 2 * bloomHeight < float(desc.height)) {
        if (inoutBloomOptions.quality == QualityLevel::LOW ||
            inoutBloomOptions.quality == QualityLevel::MEDIUM) {
            input = downscalePass(fg, input, {
                            .width  = (desc.width  = std::max(1u, desc.width  / 2)),
                            .height = (desc.height = std::max(1u, desc.height / 2)),
                            .format = outFormat
                    },
                    threshold, inoutBloomOptions.highlight, fireflies);
            threshold = false; // we do the thresholding only once during down sampling
            fireflies = false; // we do the fireflies reduction only once during down sampling
        } else if (inoutBloomOptions.quality == QualityLevel::HIGH ||
                   inoutBloomOptions.quality == QualityLevel::ULTRA) {
            // In high quality mode, we increase the size of the bloom buffer such that the
            // first scaling is less than 2x, and we increase the number of levels accordingly.
            if (bloomWidth * 2.0f > 2048.0f || bloomHeight * 2.0f > 2048.0f) {
                // but we can't scale above the h/w guaranteed minspec
                break;
            }
            bloomWidth  *= 2.0f;
            bloomHeight *= 2.0f;
            inoutBloomOptions.levels++;
        }
    }

    // convert back to integer width/height
    uint32_t const width  = std::max(1u, uint32_t(std::floor(bloomWidth)));
    uint32_t const height = std::max(1u, uint32_t(std::floor(bloomHeight)));

    input = downscalePass(fg, input,
            { .width = width, .height = height, .format = outFormat },
            threshold, inoutBloomOptions.highlight, fireflies);

    struct BloomPassData {
        FrameGraphId<FrameGraphTexture> out;
        uint32_t outRT[kMaxBloomLevels];
    };

    // Creating a mip-chain poses a "feedback" loop problem on some GPU. We will disable
    // Bloom on these.
    // See: https://github.com/google/filament/issues/2338

    auto& bloomDownsamplePass = fg.addPass<BloomPassData>("Bloom Downsample",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.out = builder.createTexture("Bloom Out Texture", {
                        .width = width,
                        .height = height,
                        .levels = inoutBloomOptions.levels,
                        .format = outFormat
                });
                data.out = builder.sample(data.out);

                for (size_t i = 0; i < inoutBloomOptions.levels; i++) {
                    auto out = builder.createSubresource(data.out, "Bloom Out Texture mip",
                            { .level = uint8_t(i) });
                    if (i == 0) {
                        // this causes the last blit above to render into this mip
                       fg.forwardResource(out, input);
                    }
                    builder.declareRenderPass(out, &data.outRT[i]);
                }
            },
            [=](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {

                // TODO: if downsampling is not exactly a multiple of two, use the 13 samples
                //       filter. This is generally the accepted solution, however, the 13 samples
                //       filter is not correct either when we don't sample at integer coordinates,
                //       but it seems ot create less artifacts.
                //       A better solution might be to use the filter described in
                //       Castaño, 2013, "Shadow Mapping Summary Part 1", which is 5x5 filter with
                //       9 samples, but works at all coordinates.

                auto hwOut = resources.getTexture(data.out);

                auto const& material9 = getPostProcessMaterial("bloomDownsample9");
                auto const& material13 = getPostProcessMaterial("bloomDownsample");

                auto* mi9 = material9.getMaterialInstance(mEngine);
                auto* mi13 = material13.getMaterialInstance(mEngine);

                mi9->setParameter("source", hwOut, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR_MIPMAP_NEAREST });

                mi13->setParameter("source", hwOut, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR_MIPMAP_NEAREST });

                mi9->commit(driver);
                mi13->commit(driver);

                // PipelineState for both materials should be the same
                auto const pipeline = material9.getPipelineState(mEngine);

                for (size_t i = 1; i < inoutBloomOptions.levels; i++) {
                    auto hwDstRT = resources.getRenderPassInfo(data.outRT[i]);
                    hwDstRT.params.flags.discardStart = TargetBufferFlags::COLOR;
                    hwDstRT.params.flags.discardEnd = TargetBufferFlags::NONE;

                    // if downsampling is a multiple of 2 in each dimension we can use the
                    // 9 samples filter.
                    auto vp = resources.getRenderPassInfo(data.outRT[i-1]).params.viewport;
                    auto* const mi = (vp.width & 1 || vp.height & 1) ? mi13 : mi9;
                    mi->use(driver);
                    driver.setMinMaxLevels(hwOut, i - 1, i - 1); // this offsets baseLevel to i-1
                    render(hwDstRT, pipeline, driver);
                }
                driver.setMinMaxLevels(hwOut, 0, inoutBloomOptions.levels - 1);
            });

    // output of bloom downsample pass becomes input of next (flare) pass
    input = bloomDownsamplePass->out;

    // flare pass
    auto flare = flarePass(fg, input, width, height, outFormat, inoutBloomOptions);

    auto& bloomUpsamplePass = fg.addPass<BloomPassData>("Bloom Upsample",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.out = builder.sample(input);
                for (size_t i = 0; i < inoutBloomOptions.levels; i++) {
                    auto out = builder.createSubresource(data.out, "Bloom Out Texture mip",
                            { .level = uint8_t(i) });
                    builder.declareRenderPass(out, &data.outRT[i]);
                }
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto hwOut = resources.getTexture(data.out);
                auto const& outDesc = resources.getDescriptor(data.out);

                auto const& material = getPostProcessMaterial("bloomUpsample");
                auto* mi = material.getMaterialInstance(mEngine);
                mi->setParameter("source", hwOut, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR_MIPMAP_NEAREST});
                mi->commit(driver);
                mi->use(driver);

                auto pipeline = material.getPipelineState(mEngine);
                pipeline.first.rasterState.blendFunctionSrcRGB = BlendFunction::ONE;
                pipeline.first.rasterState.blendFunctionDstRGB = BlendFunction::ONE;

                for (size_t j = inoutBloomOptions.levels, i = j - 1; i >= 1; i--, j++) {
                    auto hwDstRT = resources.getRenderPassInfo(data.outRT[i - 1]);
                    hwDstRT.params.flags.discardStart = TargetBufferFlags::NONE; // b/c we'll blend
                    hwDstRT.params.flags.discardEnd = TargetBufferFlags::NONE;
                    auto w = FTexture::valueForLevel(i - 1, outDesc.width);
                    auto h = FTexture::valueForLevel(i - 1, outDesc.height);
                    mi->setParameter("resolution", float4{ w, h, 1.0f / w, 1.0f / h });
                    mi->commit(driver);
                    driver.setMinMaxLevels(hwOut, i, i); // this offsets baseLevel to i
                    render(hwDstRT, pipeline, driver);
                }
                driver.setMinMaxLevels(hwOut, 0, inoutBloomOptions.levels - 1);
            });

    return { bloomUpsamplePass->out, flare };
}

UTILS_NOINLINE
FrameGraphId<FrameGraphTexture> PostProcessManager::flarePass(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input,
        uint32_t width, uint32_t height,
        backend::TextureFormat outFormat,
        BloomOptions const& bloomOptions) noexcept {

    struct FlarePassData {
        FrameGraphId<FrameGraphTexture> in;
        FrameGraphId<FrameGraphTexture> out;
    };
    auto& flarePass = fg.addPass<FlarePassData>("Flare",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.in = builder.sample(input);
                data.out = builder.createTexture("Flare Texture", {
                        .width  = std::max(1u, width  / 2),
                        .height = std::max(1u, height / 2),
                        .format = outFormat
                });
                data.out = builder.declareRenderPass(data.out);
            },
            [=](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {
                auto in = resources.getTexture(data.in);
                auto out = resources.getRenderPassInfo(0);
                const float aspectRatio = float(width) / float(height);

                auto const& material = getPostProcessMaterial("flare");
                FMaterialInstance* mi = material.getMaterialInstance(mEngine);

                mi->setParameter("color", in, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR_MIPMAP_NEAREST
                });

                mi->setParameter("level", 0.0f);    // adjust with resolution
                mi->setParameter("aspectRatio", float2{ aspectRatio, 1.0f / aspectRatio });
                mi->setParameter("threshold",
                        float2{ bloomOptions.ghostThreshold, bloomOptions.haloThreshold });
                mi->setParameter("chromaticAberration", bloomOptions.chromaticAberration);
                mi->setParameter("ghostCount", (float)bloomOptions.ghostCount);
                mi->setParameter("ghostSpacing", bloomOptions.ghostSpacing);
                mi->setParameter("haloRadius", bloomOptions.haloRadius);
                mi->setParameter("haloThickness", bloomOptions.haloThickness);

                commitAndRender(out, material, driver);
            });

    constexpr float kernelWidth = 9;
    constexpr float sigma = (kernelWidth + 1.0f) / 6.0f;
    auto flare = gaussianBlurPass(fg, flarePass->out, {}, false, kernelWidth, sigma);
    return flare;
}

UTILS_NOINLINE
static float4 getVignetteParameters(VignetteOptions const& options,
        uint32_t width, uint32_t height) noexcept {
    if (options.enabled) {
        // Vignette params
        // From 0.0 to 0.5 the vignette is a rounded rect that turns into an oval
        // From 0.5 to 1.0 the vignette turns from oval to circle
        float const oval = min(options.roundness, 0.5f) * 2.0f;
        float const circle = (max(options.roundness, 0.5f) - 0.5f) * 2.0f;
        float const roundness = (1.0f - oval) * 6.0f + oval;

        // Mid point varies during the oval/rounded section of roundness
        // We also modify it to emphasize feathering
        float const midPoint = (1.0f - options.midPoint) * mix(2.2f, 3.0f, oval)
                         * (1.0f - 0.1f * options.feather);

        // Radius of the rounded corners as a param to pow()
        float const radius = roundness *
                mix(1.0f + 4.0f * (1.0f - options.feather), 1.0f, std::sqrt(oval));

        // Factor to transform oval into circle
        float const aspect = mix(1.0f, float(width) / float(height), circle);

        return float4{ midPoint, radius, aspect, options.feather };
    }

    // Set half-max to show disabled
    return float4{ std::numeric_limits<half>::max() };
}

void PostProcessManager::colorGradingPrepareSubpass(DriverApi& driver,
        const FColorGrading* colorGrading, ColorGradingConfig const& colorGradingConfig,
        VignetteOptions const& vignetteOptions, uint32_t width, uint32_t height) noexcept {

    float4 const vignetteParameters = getVignetteParameters(vignetteOptions, width, height);

    auto const& material = getPostProcessMaterial("colorGradingAsSubpass");
    FMaterialInstance* mi = material.getMaterialInstance(mEngine);

    mi->setParameter("lut", colorGrading->getHwHandle(), {
            .filterMag = SamplerMagFilter::LINEAR,
            .filterMin = SamplerMinFilter::LINEAR,
            .wrapS = SamplerWrapMode::CLAMP_TO_EDGE,
            .wrapT = SamplerWrapMode::CLAMP_TO_EDGE,
            .wrapR = SamplerWrapMode::CLAMP_TO_EDGE,
            .anisotropyLog2 = 0
    });
    const float lutDimension = float(colorGrading->getDimension());
    mi->setParameter("lutSize", float2{
        0.5f / lutDimension, (lutDimension - 1.0f) / lutDimension,
    });

    const float temporalNoise = mUniformDistribution(mEngine.getRandomEngine());

    mi->setParameter("vignette", vignetteParameters);
    mi->setParameter("vignetteColor", vignetteOptions.color);
    mi->setParameter("dithering", colorGradingConfig.dithering);
    mi->setParameter("fxaa", colorGradingConfig.fxaa);
    mi->setParameter("temporalNoise", temporalNoise);
    mi->commit(driver);

    // load both variants
    material.getMaterial(mEngine)->prepareProgram(
            Variant{ Variant::type_t(PostProcessVariant::TRANSLUCENT) });
    material.getMaterial(mEngine)->prepareProgram(
            Variant{ Variant::type_t(PostProcessVariant::OPAQUE) });
}

void PostProcessManager::colorGradingSubpass(DriverApi& driver,
        ColorGradingConfig const& colorGradingConfig) noexcept {
    FEngine const& engine = mEngine;
    Handle<HwRenderPrimitive> const& fullScreenRenderPrimitive = engine.getFullScreenRenderPrimitive();

    auto const& material = getPostProcessMaterial("colorGradingAsSubpass");
    // the UBO has been set and committed in colorGradingPrepareSubpass()
    FMaterialInstance* mi = material.getMaterialInstance(mEngine);
    mi->use(driver);
    const Variant::type_t variant = Variant::type_t(colorGradingConfig.translucent ?
            PostProcessVariant::TRANSLUCENT : PostProcessVariant::OPAQUE);

    auto const pipeline = material.getPipelineState(mEngine, variant);

    driver.nextSubpass();
    driver.scissor(pipeline.second);
    driver.draw(pipeline.first, fullScreenRenderPrimitive, 0, 3, 1);
}

void PostProcessManager::customResolvePrepareSubpass(DriverApi& driver, CustomResolveOp op) noexcept {
    auto const& material = getPostProcessMaterial("customResolveAsSubpass");
    FMaterialInstance* mi = material.getMaterialInstance(mEngine);
    mi->setParameter("direction", op == CustomResolveOp::COMPRESS ? 1.0f : -1.0f),
    mi->commit(driver);
    material.getMaterial(mEngine)->prepareProgram(Variant{});
}

void PostProcessManager::customResolveSubpass(DriverApi& driver) noexcept {
    FEngine const& engine = mEngine;
    Handle<HwRenderPrimitive> const& fullScreenRenderPrimitive = engine.getFullScreenRenderPrimitive();
    auto const& material = getPostProcessMaterial("customResolveAsSubpass");
    // the UBO has been set and committed in colorGradingPrepareSubpass()
    auto const pipeline = material.getPipelineState(mEngine);
    FMaterialInstance* mi = material.getMaterialInstance(mEngine);
    mi->use(driver);
    driver.nextSubpass();
    driver.scissor(pipeline.second);
    driver.draw(pipeline.first, fullScreenRenderPrimitive, 0, 3, 1);
}

FrameGraphId<FrameGraphTexture> PostProcessManager::customResolveUncompressPass(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> inout) noexcept {
    struct UncompressData {
        FrameGraphId<FrameGraphTexture> inout;
    };
    auto& detonemapPass = fg.addPass<UncompressData>("Uncompress Pass",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.inout = builder.read(inout, FrameGraphTexture::Usage::SUBPASS_INPUT);
                data.inout = builder.write(data.inout, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                builder.declareRenderPass("Uncompress target", {
                        .attachments = { .color = { data.inout }}
                });
            },
            [=](FrameGraphResources const& resources, auto const&, DriverApi& driver) {
                customResolvePrepareSubpass(driver, CustomResolveOp::UNCOMPRESS);
                auto out = resources.getRenderPassInfo();
                out.params.subpassMask = 1;
                driver.beginRenderPass(out.target, out.params);
                customResolveSubpass(driver);
                driver.endRenderPass();
            });
    return detonemapPass->inout;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::colorGrading(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input, filament::Viewport const& vp,
        FrameGraphId<FrameGraphTexture> bloom,
        FrameGraphId<FrameGraphTexture> flare,
        FColorGrading const* colorGrading,
        ColorGradingConfig const& colorGradingConfig,
        BloomOptions const& bloomOptions,
        VignetteOptions const& vignetteOptions) noexcept
{
    FrameGraphId<FrameGraphTexture> bloomDirt;
    FrameGraphId<FrameGraphTexture> starburst;

    float bloomStrength = 0.0f;
    if (bloomOptions.enabled) {
        bloomStrength = clamp(bloomOptions.strength, 0.0f, 1.0f);
        if (bloomOptions.dirt) {
            FTexture* fdirt = downcast(bloomOptions.dirt);
            FrameGraphTexture const frameGraphTexture{ .handle = fdirt->getHwHandle() };
            bloomDirt = fg.import("dirt", {
                    .width = (uint32_t)fdirt->getWidth(0u),
                    .height = (uint32_t)fdirt->getHeight(0u),
                    .format = fdirt->getFormat()
            }, FrameGraphTexture::Usage::SAMPLEABLE, frameGraphTexture);
        }

        if (bloomOptions.lensFlare && bloomOptions.starburst) {
            starburst = fg.import("starburst", {
                    .width = 256, .height = 1, .format = TextureFormat::R8
            }, FrameGraphTexture::Usage::SAMPLEABLE,
                    FrameGraphTexture{ .handle = mStarburstTexture });
        }
    }

    struct PostProcessColorGrading {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
        FrameGraphId<FrameGraphTexture> bloom;
        FrameGraphId<FrameGraphTexture> flare;
        FrameGraphId<FrameGraphTexture> dirt;
        FrameGraphId<FrameGraphTexture> starburst;
    };

    auto& ppColorGrading = fg.addPass<PostProcessColorGrading>("colorGrading",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.input = builder.sample(input);
                data.output = builder.createTexture("colorGrading output", {
                        .width = vp.width,
                        .height = vp.height,
                        .format = colorGradingConfig.ldrFormat
                });
                data.output = builder.declareRenderPass(data.output);

                if (bloom) {
                    data.bloom = builder.sample(bloom);
                }
                if (bloomDirt) {
                    data.dirt = builder.sample(bloomDirt);
                }
                if (bloomOptions.lensFlare && flare) {
                    data.flare = builder.sample(flare);
                    if (starburst) {
                        data.starburst = builder.sample(starburst);
                    }
                }
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto colorTexture = resources.getTexture(data.input);

                auto bloomTexture =
                        data.bloom ? resources.getTexture(data.bloom) : getZeroTexture();

                auto flareTexture =
                        data.flare ? resources.getTexture(data.flare) : getZeroTexture();

                auto dirtTexture =
                        data.dirt ? resources.getTexture(data.dirt) : getOneTexture();

                auto starburstTexture =
                        data.starburst ? resources.getTexture(data.starburst) : getOneTexture();

                auto const& out = resources.getRenderPassInfo();

                auto const& material = getPostProcessMaterial("colorGrading");
                FMaterialInstance* mi = material.getMaterialInstance(mEngine);

                mi->setParameter("lut", colorGrading->getHwHandle(), {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR
                });
                const float lutDimension = float(colorGrading->getDimension());
                mi->setParameter("lutSize", float2{
                        0.5f / lutDimension, (lutDimension - 1.0f) / lutDimension,
                });
                });
                mi->setParameter("flareBuffer", flareTexture, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR
                });
                mi->setParameter("dirtBuffer", dirtTexture, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR
                });
                mi->setParameter("starburstBuffer", starburstTexture, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR,
                        .wrapS = SamplerWrapMode::REPEAT,
                        .wrapT = SamplerWrapMode::REPEAT
                });

                // Bloom params
                float4 bloomParameters{
                    bloomStrength / float(bloomOptions.levels),
                    1.0f,
                    (bloomOptions.enabled && bloomOptions.dirt) ? bloomOptions.dirtStrength : 0.0f,
                    bloomOptions.lensFlare ? bloomStrength : 0.0f
                };
                if (bloomOptions.blendMode == BloomOptions::BlendMode::INTERPOLATE) {
                    bloomParameters.y = 1.0f - bloomParameters.x;
                }

                auto const& input = resources.getDescriptor(data.input);
                auto const& output = resources.getDescriptor(data.output);
                float4 const vignetteParameters = getVignetteParameters(
                        vignetteOptions, output.width, output.height);

                const float temporalNoise = mUniformDistribution(mEngine.getRandomEngine());

                mi->setParameter("dithering", colorGradingConfig.dithering);
                mi->setParameter("bloom", bloomParameters);
                mi->setParameter("vignette", vignetteParameters);
                mi->setParameter("vignetteColor", vignetteOptions.color);
                mi->setParameter("fxaa", colorGradingConfig.fxaa);
                mi->setParameter("temporalNoise", temporalNoise);
                mi->setParameter("viewport", float4{
                        (float)vp.left   / input.width,
                        (float)vp.bottom / input.height,
                        (float)vp.width  / input.width,
                        (float)vp.height / input.height
                });

                const uint8_t variant = uint8_t(colorGradingConfig.translucent ?
                            PostProcessVariant::TRANSLUCENT : PostProcessVariant::OPAQUE);

                commitAndRender(out, material, variant, driver);
            }
    );

    return ppColorGrading->output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::fxaa(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input, filament::Viewport const& vp,
        TextureFormat outFormat, bool translucent) noexcept {

    struct PostProcessFXAA {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
    };

    auto& ppFXAA = fg.addPass<PostProcessFXAA>("fxaa",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.input = builder.sample(input);
                data.output = builder.createTexture("fxaa output", {
                        .width = vp.width,
                        .height = vp.height,
                        .format = outFormat
                });
                data.output = builder.declareRenderPass(data.output);
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto const& inDesc = resources.getDescriptor(data.input);
                auto const& texture = resources.getTexture(data.input);
                auto const& out = resources.getRenderPassInfo();

                auto const& material = getPostProcessMaterial("fxaa");
                FMaterialInstance* mi = material.getMaterialInstance(mEngine);
                mi->setParameter("colorBuffer", texture, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR
                });
                mi->setParameter("viewport", float4{
                        (float)vp.left   / inDesc.width,
                        (float)vp.bottom / inDesc.height,
                        (float)vp.width  / inDesc.width,
                        (float)vp.height / inDesc.height
                });
                mi->setParameter("texelSize", 1.0f / float2{ inDesc.width, inDesc.height });

                const uint8_t variant = uint8_t(translucent ?
                    PostProcessVariant::TRANSLUCENT : PostProcessVariant::OPAQUE);

                commitAndRender(out, material, variant, driver);
            });

    return ppFXAA->output;
}

void PostProcessManager::prepareTaa(FrameGraph& fg,
        filament::Viewport const& svp,
        TemporalAntiAliasingOptions const& taaOptions,
        FrameHistory& frameHistory,
        FrameHistoryEntry::TemporalAA FrameHistoryEntry::*pTaa,
        CameraInfo* inoutCameraInfo,
        PerViewUniforms& uniforms) const noexcept {
    auto const& previous = frameHistory.getPrevious().*pTaa;
    auto& current = frameHistory.getCurrent().*pTaa;

    // compute projection
    current.projection = inoutCameraInfo->projection * inoutCameraInfo->getUserViewMatrix();
    current.frameId = previous.frameId + 1;

    auto jitterPosition = [pattern = taaOptions.jitterPattern](size_t frameIndex){
        using JitterPattern = TemporalAntiAliasingOptions::JitterPattern;
        switch (pattern) {
            case JitterPattern::RGSS_X4:
                return sRGSS4(frameIndex);
            case JitterPattern::UNIFORM_HELIX_X4:
                return sUniformHelix4(frameIndex);
            case JitterPattern::HALTON_23_X8:
                return sHaltonSamples(frameIndex % 8);
            case JitterPattern::HALTON_23_X16:
                return sHaltonSamples(frameIndex % 16);
            case JitterPattern::HALTON_23_X32:
                return sHaltonSamples(frameIndex);
        }
    };

    // sample position within a pixel [-0.5, 0.5]
    // for metal/vulkan we need to reverse the y-offset
    current.jitter = jitterPosition(previous.frameId);
    float2 jitter = current.jitter;
    switch (mEngine.getBackend()) {
        case Backend::VULKAN:
        case Backend::METAL:
            jitter.y = -jitter.y;
            UTILS_FALLTHROUGH;
        case Backend::OPENGL:
        default:
            break;
    }

    float2 const jitterInClipSpace = jitter * (2.0f / float2{ svp.width, svp.height });

    // update projection matrix
    inoutCameraInfo->projection[2].xy -= jitterInClipSpace;
    // VERTEX_DOMAIN_DEVICE doesn't apply the projection, but it still needs this
    // clip transform, so we apply it separately (see main.vs)
    inoutCameraInfo->clipTransform.zw -= jitterInClipSpace;

    fg.addTrivialSideEffectPass("Jitter Camera",
            [=, &uniforms] (DriverApi& driver) {
        uniforms.prepareCamera(mEngine, *inoutCameraInfo);
        uniforms.commit(driver);
    });
}

void PostProcessManager::configureTemporalAntiAliasingMaterial(
        TemporalAntiAliasingOptions const& taaOptions) noexcept {

    FMaterial* const ma = getPostProcessMaterial("taa").getMaterial(mEngine);
    bool dirty = false;

    auto setConstantParameter =
            [&dirty](FMaterial* const ma, std::string_view name, auto value) noexcept {
        auto id = ma->getSpecializationConstantId(name);
        if (id.has_value()) {
            if (ma->setConstant(id.value(), value)) {
                dirty = true;
            }
        }
    };

    setConstantParameter(ma, "upscaling", taaOptions.upscaling);
    setConstantParameter(ma, "historyReprojection", taaOptions.historyReprojection);
    setConstantParameter(ma, "filterHistory", taaOptions.filterHistory);
    setConstantParameter(ma, "filterInput", taaOptions.filterInput);
    setConstantParameter(ma, "useYCoCg", taaOptions.useYCoCg);
    setConstantParameter(ma, "preventFlickering", taaOptions.preventFlickering);
    setConstantParameter(ma, "boxType", (int32_t)taaOptions.boxType);
    setConstantParameter(ma, "boxClipping", (int32_t)taaOptions.boxClipping);
    setConstantParameter(ma, "varianceGamma", taaOptions.varianceGamma);
    if (dirty) {
        ma->invalidate();
        // TODO: call Material::compile(), we can't si that now because it works only
        //       with surface materials
    }
}

FrameGraphId<FrameGraphTexture> PostProcessManager::taa(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input,
        FrameGraphId<FrameGraphTexture> depth,
        FrameHistory& frameHistory,
        FrameHistoryEntry::TemporalAA FrameHistoryEntry::*pTaa,
        TemporalAntiAliasingOptions const& taaOptions,
        ColorGradingConfig const& colorGradingConfig) noexcept {
    assert_invariant(depth);

    auto const& previous = frameHistory.getPrevious().*pTaa;
    auto& current = frameHistory.getCurrent().*pTaa;

    // if we don't have a history yet, just use the current color buffer as history
    FrameGraphId<FrameGraphTexture> colorHistory = input;
    if (UTILS_LIKELY(previous.color.handle)) {
        colorHistory = fg.import("TAA history", previous.desc,
                FrameGraphTexture::Usage::SAMPLEABLE, previous.color);
    }

    mat4 const& historyProjection = previous.color.handle ?
            previous.projection : current.projection;

    struct TAAData {
        FrameGraphId<FrameGraphTexture> color;
        FrameGraphId<FrameGraphTexture> depth;
        FrameGraphId<FrameGraphTexture> history;
        FrameGraphId<FrameGraphTexture> output;
        FrameGraphId<FrameGraphTexture> tonemappedOutput;
    };
    auto& taaPass = fg.addPass<TAAData>("TAA",
            [&](FrameGraph::Builder& builder, auto& data) {
                auto desc = fg.getDescriptor(input);
                if (taaOptions.upscaling) {
                    desc.width *= 2;
                    desc.height *= 2;
                }
                data.color = builder.sample(input);
                data.depth = builder.sample(depth);
                data.history = builder.sample(colorHistory);
                data.output = builder.createTexture("TAA output", desc);
                data.output = builder.write(data.output);
                if (colorGradingConfig.asSubpass) {
                    data.tonemappedOutput = builder.createTexture("Tonemapped Buffer", {
                            .width = desc.width,
                            .height = desc.height,
                            .format = colorGradingConfig.ldrFormat
                    });
                    data.tonemappedOutput = builder.write(data.tonemappedOutput, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                    data.output = builder.read(data.output, FrameGraphTexture::Usage::SUBPASS_INPUT);
                }
                data.output = builder.write(data.output, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                builder.declareRenderPass("TAA target", {
                        .attachments = { .color = { data.output, data.tonemappedOutput }}
                });
            },
            [=, &current](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {

                constexpr mat4f normalizedToClip{mat4f::row_major_init{
                        2, 0, 0, -1,
                        0, 2, 0, -1,
                        0, 0, 1,  0,
                        0, 0, 0,  1
                }};

                constexpr float2 sampleOffsets[9] = {
                        { -1.0f, -1.0f }, {  0.0f, -1.0f }, {  1.0f, -1.0f },
                        { -1.0f,  0.0f }, {  0.0f,  0.0f }, {  1.0f,  0.0f },
                        { -1.0f,  1.0f }, {  0.0f,  1.0f }, {  1.0f,  1.0f },
                };

                constexpr float2 subSampleOffsets[4] = {
                        { -0.25f, 0.25f }, {  0.25f, 0.25f }, { 0.25f, -0.25f }, { -0.25f, -0.25f }
                };

                float4 sum = 0.0;
                float4 weights[9];

                // this doesn't get vectorized (probably because of exp()), so don't bother
                // unrolling it.
                #pragma nounroll
                for (size_t i = 0; i < 9; i++) {
                    float2 const o = sampleOffsets[i];
                    for (size_t j = 0; j < 4; j++) {
                        float2 const s = taaOptions.upscaling ? subSampleOffsets[j] : float2{ 0 };
                        float2 const d = (o - current.jitter - s) / taaOptions.filterWidth;
                        // This is a gaussian fit of a 3.3-wide Blackman-Harris window
                        // see: "High Quality Temporal Supersampling" by Brian Karis
                        weights[i][j] = std::exp(-2.29f * (d.x * d.x + d.y * d.y));
                    }
                    sum += weights[i];
                }
                for (auto& w : weights) {
                    w /= sum;
                }

                auto out = resources.getRenderPassInfo();
                auto color = resources.getTexture(data.color);
                auto depth = resources.getTexture(data.depth);
                auto history = resources.getTexture(data.history);
                auto const& material = getPostProcessMaterial("taa");

                FMaterialInstance* mi = material.getMaterialInstance(mEngine);
                mi->setParameter("color",  color, {});  // nearest
                mi->setParameter("depth",  depth, {});  // nearest
                mi->setParameter("alpha", taaOptions.feedback);
                mi->setParameter("history", history, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR
                });
                mi->setParameter("filterWeights",  weights, 9);
                mi->setParameter("jitter",  current.jitter);
                mi->setParameter("reprojection",
                        mat4f{ historyProjection * inverse(current.projection) } *
                        normalizedToClip);

                mi->commit(driver);
                mi->use(driver);

                const uint8_t variant = uint8_t(colorGradingConfig.translucent ?
                        PostProcessVariant::TRANSLUCENT : PostProcessVariant::OPAQUE);

                if (colorGradingConfig.asSubpass) {
                    out.params.subpassMask = 1;
                }
                auto const pipeline = material.getPipelineState(mEngine, variant);
                driver.beginRenderPass(out.target, out.params);
                driver.scissor(pipeline.second);
                driver.draw(pipeline.first, mEngine.getFullScreenRenderPrimitive(), 0, 3, 1);
                if (colorGradingConfig.asSubpass) {
                    colorGradingSubpass(driver, colorGradingConfig);
                }
                driver.endRenderPass();
            });

    input = colorGradingConfig.asSubpass ? taaPass->tonemappedOutput : taaPass->output;
    auto history = input;

    // optional sharpen pass from FSR1
    if (taaOptions.sharpness > 0.0f) {
        input = rcas(fg, taaOptions.sharpness,
                input, fg.getDescriptor(input), colorGradingConfig.translucent);
    }

    struct ExportColorHistoryData {
        FrameGraphId<FrameGraphTexture> color;
    };
    fg.addPass<ExportColorHistoryData>("Export TAA history",
            [&](FrameGraph::Builder& builder, auto& data) {
                // We need to use sideEffect here to ensure this pass won't be culled.
                // The "output" of this pass is going to be used during the next frame as
                // an "import".
                builder.sideEffect();
                data.color = builder.sample(history); // FIXME: an access must be declared for detach(), why?
            }, [&current](FrameGraphResources const& resources, auto const& data, auto&) {
                resources.detach(data.color, &current.color, &current.desc);
            });

    return input;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::rcas(
        FrameGraph& fg,
        float sharpness,
        FrameGraphId<FrameGraphTexture> input,
        FrameGraphTexture::Descriptor const& outDesc,
        bool translucent) {

    struct QuadBlitData {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
    };

    auto& ppFsrRcas = fg.addPass<QuadBlitData>("FidelityFX FSR1 Rcas",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.input = builder.sample(input);
                data.output = builder.createTexture("FFX FSR1 Rcas output", outDesc);
                data.output = builder.declareRenderPass(data.output);
            },
            [=](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {

                auto input = resources.getTexture(data.input);
                auto out = resources.getRenderPassInfo();
                auto const& outputDesc = resources.getDescriptor(data.input);

                auto& material = getPostProcessMaterial("fsr_rcas");
                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);

                FSRUniforms uniforms;
                FSR_SharpeningSetup(&uniforms, { .sharpness = 2.0f - 2.0f * sharpness });
                mi->setParameter("RcasCon", uniforms.RcasCon);
                mi->setParameter("color", input, {}); // uses texelFetch
                mi->setParameter("resolution", float4{
                        outputDesc.width, outputDesc.height,
                        1.0f / outputDesc.width, 1.0f / outputDesc.height });
                mi->commit(driver);
                mi->use(driver);

                const uint8_t variant = uint8_t(
                        translucent ? PostProcessVariant::TRANSLUCENT : PostProcessVariant::OPAQUE);

                auto const pipeline = material.getPipelineState(mEngine, variant);
                render(out, pipeline, driver);
            });

    return ppFsrRcas->output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::upscale(FrameGraph& fg, bool translucent,
        DynamicResolutionOptions dsrOptions, FrameGraphId<FrameGraphTexture> input,
        filament::Viewport const& vp, FrameGraphTexture::Descriptor const& outDesc,
        backend::SamplerMagFilter filter) noexcept {

    // The code below cannot handle sub-resources
    assert_invariant(fg.getSubResourceDescriptor(input).layer == 0);
    assert_invariant(fg.getSubResourceDescriptor(input).level == 0);

    const bool lowQualityFallback = translucent && dsrOptions.quality != QualityLevel::LOW;
    if (lowQualityFallback) {
        // FidelityFX-FSR doesn't support the alpha channel currently
        dsrOptions.quality = QualityLevel::LOW;
    }

    const bool twoPassesEASU = mWorkaroundSplitEasu &&
            (dsrOptions.quality == QualityLevel::MEDIUM
                || dsrOptions.quality == QualityLevel::HIGH);

    struct QuadBlitData {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
        FrameGraphId<FrameGraphTexture> depth;
    };

    auto& ppQuadBlit = fg.addPass<QuadBlitData>(dsrOptions.enabled ? "upscaling" : "compositing",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.input = builder.sample(input);
                data.output = builder.createTexture("upscaled output", outDesc);

                if (twoPassesEASU) {
                    // FIXME: it would be better to use the stencil buffer in this case (less bandwidth)
                    data.depth = builder.createTexture("upscaled output depth", {
                        .width = outDesc.width,
                        .height = outDesc.height,
                        .format = TextureFormat::DEPTH16
                    });
                    data.depth = builder.write(data.depth, FrameGraphTexture::Usage::DEPTH_ATTACHMENT);
                }

                data.output = builder.write(data.output, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                builder.declareRenderPass(builder.getName(data.output), {
                        .attachments = { .color = { data.output }, .depth = { data.depth }},
                        .clearFlags = TargetBufferFlags::DEPTH });
            },
            [this, twoPassesEASU, dsrOptions, vp, translucent, filter](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {

                // helper to set the EASU uniforms
                auto setEasuUniforms = [vp, backend = mEngine.getBackend()](FMaterialInstance* mi,
                        FrameGraphTexture::Descriptor const& inputDesc,
                        FrameGraphTexture::Descriptor const& outputDesc) {
                    FSRUniforms uniforms{};
                    FSR_ScalingSetup(&uniforms, {
                            .backend = backend,
                            .input = vp,
                            .inputWidth = inputDesc.width,
                            .inputHeight = inputDesc.height,
                            .outputWidth = outputDesc.width,
                            .outputHeight = outputDesc.height,
                    });
                    mi->setParameter("EasuCon0", uniforms.EasuCon0);
                    mi->setParameter("EasuCon1", uniforms.EasuCon1);
                    mi->setParameter("EasuCon2", uniforms.EasuCon2);
                    mi->setParameter("EasuCon3", uniforms.EasuCon3);
                    mi->setParameter("textureSize",
                            float2{ inputDesc.width, inputDesc.height });
                };

                // helper to enable blending
                auto enableTranslucentBlending = [](PipelineState& pipeline) {
                    pipeline.rasterState.blendFunctionSrcRGB = BlendFunction::ONE;
                    pipeline.rasterState.blendFunctionSrcAlpha = BlendFunction::ONE;
                    pipeline.rasterState.blendFunctionDstRGB = BlendFunction::ONE_MINUS_SRC_ALPHA;
                    pipeline.rasterState.blendFunctionDstAlpha = BlendFunction::ONE_MINUS_SRC_ALPHA;
                };

                auto color = resources.getTexture(data.input);
                auto const& inputDesc = resources.getDescriptor(data.input);
                auto const& outputDesc = resources.getDescriptor(data.output);

                // --------------------------------------------------------------------------------
                // set uniforms

                PostProcessMaterial* splitEasuMaterial = nullptr;
                PostProcessMaterial* easuMaterial = nullptr;

                if (twoPassesEASU) {
                    splitEasuMaterial = &getPostProcessMaterial("fsr_easu_mobileF");
                    auto* mi = splitEasuMaterial->getMaterialInstance(mEngine);
                    setEasuUniforms(mi, inputDesc, outputDesc);
                    mi->setParameter("color", color, {
                        .filterMag = SamplerMagFilter::LINEAR
                    });
                    mi->setParameter("resolution",
                            float4{ outputDesc.width, outputDesc.height,
                                    1.0f / outputDesc.width, 1.0f / outputDesc.height });
                    mi->commit(driver);
                    mi->use(driver);
                }

                { // just a scope to not leak local variables
                    const std::string_view blitterNames[4] = {
                            "blitLow", "fsr_easu_mobile", "fsr_easu_mobile", "fsr_easu" };
                    unsigned const index = std::min(3u, (unsigned)dsrOptions.quality);
                    easuMaterial = &getPostProcessMaterial(blitterNames[index]);
                    auto* mi = easuMaterial->getMaterialInstance(mEngine);
                    if (dsrOptions.quality != QualityLevel::LOW) {
                        setEasuUniforms(mi, inputDesc, outputDesc);
                    }
                    mi->setParameter("color", color, {
                        .filterMag = (dsrOptions.quality == QualityLevel::LOW) ?
                                filter : SamplerMagFilter::LINEAR
                    });

                    if (blitterNames[index] != "blitLow") {
                        mi->setParameter("resolution",
                                float4{outputDesc.width, outputDesc.height, 1.0f / outputDesc.width,
                                    1.0f / outputDesc.height});
                    }

                    mi->setParameter("viewport", float4{
                            (float)vp.left   / inputDesc.width,
                            (float)vp.bottom / inputDesc.height,
                            (float)vp.width  / inputDesc.width,
                            (float)vp.height / inputDesc.height
                    });
                    mi->commit(driver);
                    mi->use(driver);
                }

                // --------------------------------------------------------------------------------
                // render pass with draw calls

                auto fullScreenRenderPrimitive = mEngine.getFullScreenRenderPrimitive();

                auto out = resources.getRenderPassInfo();

                if (UTILS_UNLIKELY(twoPassesEASU)) {
                    auto pipeline0 = splitEasuMaterial->getPipelineState(mEngine);
                    auto pipeline1 = easuMaterial->getPipelineState(mEngine);
                    pipeline1.first.rasterState.depthFunc = backend::SamplerCompareFunc::NE;
                    if (translucent) {
                        enableTranslucentBlending(pipeline0.first);
                        enableTranslucentBlending(pipeline1.first);
                    }
                    driver.beginRenderPass(out.target, out.params);
                    driver.scissor(pipeline0.second);
                    driver.draw(pipeline0.first, fullScreenRenderPrimitive, 0, 3, 1);
                    driver.scissor(pipeline1.second);
                    driver.draw(pipeline1.first, fullScreenRenderPrimitive, 0, 3, 1);
                    driver.endRenderPass();
                } else {
                    auto pipeline = easuMaterial->getPipelineState(mEngine);
                    if (translucent) {
                        enableTranslucentBlending(pipeline.first);
                    }
                    render(out, pipeline, driver);
                }
            });

    auto output = ppQuadBlit->output;

    // if we had to take the low quality fallback, we still do the "sharpen pass"
    if (dsrOptions.sharpness > 0.0f &&
            (dsrOptions.quality != QualityLevel::LOW || lowQualityFallback)) {
        output = rcas(fg, dsrOptions.sharpness, output, outDesc, translucent);
    }

    // we rely on automatic culling of unused render passes
    return output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::blit(FrameGraph& fg, bool translucent,
        FrameGraphId<FrameGraphTexture> input,
        filament::Viewport const& vp, FrameGraphTexture::Descriptor const& outDesc,
        SamplerMagFilter filterMag,
        SamplerMinFilter filterMin) noexcept {

    // TODO: add support for sub-resources
    assert_invariant(fg.getSubResourceDescriptor(input).layer == 0);
    assert_invariant(fg.getSubResourceDescriptor(input).level == 0);

    struct QuadBlitData {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
    };

    auto& ppQuadBlit = fg.addPass<QuadBlitData>("blitting",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.input = builder.sample(input);
                data.output = builder.createTexture("blit output", outDesc);
                data.output = builder.write(data.output,
                        FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                builder.declareRenderPass(builder.getName(data.output), {
                        .attachments = { .color = { data.output }},
                        .clearFlags = TargetBufferFlags::DEPTH });
            },
            [=](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {
                auto color = resources.getTexture(data.input);
                auto const& inputDesc = resources.getDescriptor(data.input);
                auto out = resources.getRenderPassInfo();

                // --------------------------------------------------------------------------------
                // set uniforms

                PostProcessMaterial const& material = getPostProcessMaterial("blitLow");
                auto* mi = material.getMaterialInstance(mEngine);
                mi->setParameter("color", color, {
                        .filterMag = filterMag,
                        .filterMin = filterMin
                });
                mi->setParameter("viewport", float4{
                        float(vp.left)   / inputDesc.width,
                        float(vp.bottom) / inputDesc.height,
                        float(vp.width)  / inputDesc.width,
                        float(vp.height) / inputDesc.height
                });
                mi->commit(driver);
                mi->use(driver);

                auto pipeline = material.getPipelineState(mEngine);
                if (translucent) {
                    pipeline.first.rasterState.blendFunctionSrcRGB = BlendFunction::ONE;
                    pipeline.first.rasterState.blendFunctionSrcAlpha = BlendFunction::ONE;
                    pipeline.first.rasterState.blendFunctionDstRGB = BlendFunction::ONE_MINUS_SRC_ALPHA;
                    pipeline.first.rasterState.blendFunctionDstAlpha = BlendFunction::ONE_MINUS_SRC_ALPHA;
                }
                render(out, pipeline, driver);
            });

    return ppQuadBlit->output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::blitDepth(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input) noexcept {
    auto const& inputDesc = fg.getDescriptor(input);
    filament::Viewport const vp = {0, 0, inputDesc.width, inputDesc.height};
    bool const hardwareBlitSupported =
            mEngine.getDriverApi().isDepthStencilBlitSupported(inputDesc.format);

    struct BlitData {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
    };

    if (hardwareBlitSupported) {
        auto& depthPass = fg.addPass<BlitData>(
                "Depth Blit",
                [&](FrameGraph::Builder& builder, auto& data) {
                    data.input = builder.read(input, FrameGraphTexture::Usage::BLIT_SRC);

                    auto desc = builder.getDescriptor(data.input);
                    desc.levels = 1;// only copy the base level

                    // create a new buffer for the copy
                    data.output = builder.createTexture("depth blit output", desc);

                    // output is an attachment
                    data.output = builder.write(data.output, FrameGraphTexture::Usage::BLIT_DST);
                },
                [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                    auto const& src = resources.getTexture(data.input);
                    auto const& dst = resources.getTexture(data.output);
                    auto const& srcSubDesc = resources.getSubResourceDescriptor(data.input);
                    auto const& dstSubDesc = resources.getSubResourceDescriptor(data.output);
                    auto const& desc = resources.getDescriptor(data.output);
                    assert_invariant(desc.samples == resources.getDescriptor(data.input).samples);
                    // here we can guarantee that src and dst format and size match, by
                    // construction.
                    driver.blit(
                            dst, dstSubDesc.level, dstSubDesc.layer, { 0, 0 },
                            src, srcSubDesc.level, srcSubDesc.layer, { 0, 0 },
                            { desc.width, desc.height });
                });
        return depthPass->output;
    }
    // Otherwise, we would do a shader-based blit.

    auto& ppQuadBlit = fg.addPass<BlitData>(
            "Depth Blit (Shader)",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.input = builder.sample(input);
                // Note that this is a same size/format blit.
                auto const& outputDesc = inputDesc;
                data.output = builder.createTexture("depth blit output", outputDesc);
                data.output =
                        builder.write(data.output, FrameGraphTexture::Usage::DEPTH_ATTACHMENT);
                builder.declareRenderPass(builder.getName(data.output),
                        {.attachments = {.depth = {data.output}}});
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto depth = resources.getTexture(data.input);
                auto const& inputDesc = resources.getDescriptor(data.input);
                auto out = resources.getRenderPassInfo();

                // --------------------------------------------------------------------------------
                // set uniforms
                PostProcessMaterial const& material = getPostProcessMaterial("blitDepth");
                auto* mi = material.getMaterialInstance(mEngine);
                mi->setParameter("depth", depth,
                        {
                            .filterMag = SamplerMagFilter::NEAREST,
                            .filterMin = SamplerMinFilter::NEAREST,
                        });
                mi->setParameter("viewport",
                        float4{float(vp.left) / inputDesc.width,
                            float(vp.bottom) / inputDesc.height, float(vp.width) / inputDesc.width,
                            float(vp.height) / inputDesc.height});
                commitAndRender(out, material, driver);
            });

    return ppQuadBlit->output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::resolve(FrameGraph& fg,
        const char* outputBufferName, FrameGraphId<FrameGraphTexture> input,
        FrameGraphTexture::Descriptor outDesc) noexcept {

    // Don't do anything if we're not a MSAA buffer
    auto const& inDesc = fg.getDescriptor(input);
    if (inDesc.samples <= 1) {
        return input;
    }

    // we currently don't support stencil resolve
    assert_invariant(!isStencilFormat(inDesc.format));

    // The Metal / Vulkan backends currently don't support depth/stencil resolve.
    if (isDepthFormat(inDesc.format) && (!mEngine.getDriverApi().isDepthStencilResolveSupported())) {
        return resolveDepth(fg, outputBufferName, input, outDesc);
    }

    outDesc.width = inDesc.width;
    outDesc.height = inDesc.height;
    outDesc.format = inDesc.format;
    outDesc.samples = 0;

    struct ResolveData {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
    };

    auto& ppResolve = fg.addPass<ResolveData>("resolve",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.input = builder.read(input, FrameGraphTexture::Usage::BLIT_SRC);
                data.output = builder.createTexture(outputBufferName, outDesc);
                data.output = builder.write(data.output, FrameGraphTexture::Usage::BLIT_DST);
            },
            [](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto const& src = resources.getTexture(data.input);
                auto const& dst = resources.getTexture(data.output);
                auto const& srcSubDesc = resources.getSubResourceDescriptor(data.input);
                auto const& dstSubDesc = resources.getSubResourceDescriptor(data.output);
                UTILS_UNUSED_IN_RELEASE auto const& srcDesc = resources.getDescriptor(data.input);
                UTILS_UNUSED_IN_RELEASE auto const& dstDesc = resources.getDescriptor(data.output);
                assert_invariant(src);
                assert_invariant(dst);
                assert_invariant(srcDesc.format == dstDesc.format);
                assert_invariant(srcDesc.width == dstDesc.width && srcDesc.height == dstDesc.height);
                driver.resolve(
                        dst, dstSubDesc.level, dstSubDesc.layer,
                        src, srcSubDesc.level, srcSubDesc.layer);
            });

    return ppResolve->output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::resolveDepth(FrameGraph& fg,
        const char* outputBufferName, FrameGraphId<FrameGraphTexture> input,
        FrameGraphTexture::Descriptor outDesc) noexcept {

    // Don't do anything if we're not a MSAA buffer
    auto const& inDesc = fg.getDescriptor(input);
    if (inDesc.samples <= 1) {
        return input;
    }

    UTILS_UNUSED_IN_RELEASE auto const& inSubDesc = fg.getSubResourceDescriptor(input);
    assert_invariant(isDepthFormat(inDesc.format));
    assert_invariant(inSubDesc.layer == 0);
    assert_invariant(inSubDesc.level == 0);

    outDesc.width = inDesc.width;
    outDesc.height = inDesc.height;
    outDesc.format = inDesc.format;
    outDesc.samples = 0;

    struct ResolveData {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
    };

    auto& ppResolve = fg.addPass<ResolveData>("resolveDepth",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.input = builder.sample(input);
                data.output = builder.createTexture(outputBufferName, outDesc);
                data.output = builder.write(data.output, FrameGraphTexture::Usage::DEPTH_ATTACHMENT);
                builder.declareRenderPass(builder.getName(data.output), {
                        .attachments = { .depth = { data.output }},
                        .clearFlags = TargetBufferFlags::DEPTH });
            },
            [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                auto const& input = resources.getTexture(data.input);
                auto const& material = getPostProcessMaterial("resolveDepth");
                auto* mi = material.getMaterialInstance(mEngine);
                mi->setParameter("depth", input, {}); // NEAREST
                commitAndRender(resources.getRenderPassInfo(), material, driver);
            });

    return ppResolve->output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::vsmMipmapPass(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input, uint8_t layer, size_t level,
        math::float4 clearColor, bool finalize) noexcept {

    struct VsmMipData {
        FrameGraphId<FrameGraphTexture> in;
    };

    auto& depthMipmapPass = fg.addPass<VsmMipData>("VSM Generate Mipmap Pass",
            [&](FrameGraph::Builder& builder, auto& data) {
                const char* name = builder.getName(input);
                data.in = builder.sample(input);

                auto out = builder.createSubresource(data.in, "Mip level", {
                        .level = uint8_t(level + 1), .layer = layer });

                out = builder.write(out, FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                builder.declareRenderPass(name, {
                    .attachments = { .color = { out }},
                    .clearColor = clearColor,
                    .clearFlags = TargetBufferFlags::COLOR
                });
            },
            [=](FrameGraphResources const& resources,
                    auto const& data, DriverApi& driver) {

                auto in = resources.getTexture(data.in);
                auto out = resources.getRenderPassInfo();

                auto const& inDesc = resources.getDescriptor(data.in);
                auto width = inDesc.width;
                assert_invariant(width == inDesc.height);
                int const dim = width >> (level + 1);

                driver.setMinMaxLevels(in, level, level);

                auto& material = getPostProcessMaterial("vsmMipmap");

                // When generating shadow map mip levels, we want to preserve the 1 texel border.
                // (note clearing never respects the scissor in Filament)
                auto const [pipeline, _] = material.getPipelineState(mEngine);
                backend::Viewport const scissor = { 1u, 1u, dim - 2u, dim - 2u };

                FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                mi->setParameter("color", in, {
                        .filterMag = SamplerMagFilter::LINEAR,
                        .filterMin = SamplerMinFilter::LINEAR_MIPMAP_NEAREST
                });
                mi->setParameter("layer", uint32_t(layer));
                mi->setParameter("uvscale", 1.0f / float(dim));
                mi->commit(driver);
                mi->use(driver);
                render(out, pipeline, scissor, driver);

                if (finalize) {
                   driver.setMinMaxLevels(in, 0, level);
                }
            });

    return depthMipmapPass->in;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::debugShadowCascades(FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input,
        FrameGraphId<FrameGraphTexture> depth) noexcept {

    // new pass for showing the cascades
    struct DebugShadowCascadesData {
        FrameGraphId<FrameGraphTexture> color;
        FrameGraphId<FrameGraphTexture> depth;
        FrameGraphId<FrameGraphTexture> output;
    };
    auto& debugShadowCascadePass = fg.addPass<DebugShadowCascadesData>("ShadowCascades",
            [&](FrameGraph::Builder& builder, auto& data) {
                auto desc = builder.getDescriptor(input);
                data.color = builder.sample(input);
                data.depth = builder.sample(depth);
                data.output = builder.createTexture("Shadow Cascade Debug", desc);
                builder.declareRenderPass(data.output);
            },
            [=](FrameGraphResources const& resources, auto const& data, backend::DriverApi& driver) {
                auto color = resources.getTexture(data.color);
                auto depth = resources.getTexture(data.depth);
                auto out = resources.getRenderPassInfo();
                auto& material = getPostProcessMaterial("debugShadowCascades");
                auto const pipeline = material.getPipelineState(mEngine);
                FMaterialInstance* mi = material.getMaterialInstance(mEngine);
                mi->setParameter("color",  color, {});  // nearest
                mi->setParameter("depth",  depth, {});  // nearest
                mi->commit(driver);
                mi->use(driver);

                render(out, pipeline, driver);
            });

    return debugShadowCascadePass->output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::debugCombineArrayTexture(FrameGraph& fg,
    bool translucent, FrameGraphId<FrameGraphTexture> input,
    filament::Viewport const& vp, FrameGraphTexture::Descriptor const& outDesc,
    SamplerMagFilter filterMag,
    SamplerMinFilter filterMin) noexcept {

    auto& inputTextureDesc = fg.getDescriptor(input);
    assert_invariant(inputTextureDesc.depth > 1);
    assert_invariant(inputTextureDesc.type == SamplerType::SAMPLER_2D_ARRAY);

    // TODO: add support for sub-resources
    assert_invariant(fg.getSubResourceDescriptor(input).layer == 0);
    assert_invariant(fg.getSubResourceDescriptor(input).level == 0);

    struct QuadBlitData {
        FrameGraphId<FrameGraphTexture> input;
        FrameGraphId<FrameGraphTexture> output;
    };

    auto& ppQuadBlit = fg.addPass<QuadBlitData>("combining array tex",
        [&](FrameGraph::Builder& builder, auto& data) {
            data.input = builder.sample(input);
            data.output = builder.createTexture("upscaled output", outDesc);
            data.output = builder.write(data.output,
                FrameGraphTexture::Usage::COLOR_ATTACHMENT);
            builder.declareRenderPass(builder.getName(data.output), {
                    .attachments = {.color = { data.output }},
                    .clearFlags = TargetBufferFlags::DEPTH });
        },
        [=](FrameGraphResources const& resources,
            auto const& data, DriverApi& driver) {
                auto color = resources.getTexture(data.input);
                auto const& inputDesc = resources.getDescriptor(data.input);
                auto out = resources.getRenderPassInfo();

                // --------------------------------------------------------------------------------
                // set uniforms

                PostProcessMaterial const& material = getPostProcessMaterial("blitArray");
                auto* mi = material.getMaterialInstance(mEngine);
                mi->setParameter("color", color, {
                        .filterMag = filterMag,
                        .filterMin = filterMin
                    });
                mi->setParameter("viewport", float4{
                        float(vp.left) / inputDesc.width,
                        float(vp.bottom) / inputDesc.height,
                        float(vp.width) / inputDesc.width,
                        float(vp.height) / inputDesc.height
                    });
                mi->use(driver);

                auto pipeline = material.getPipelineState(mEngine);
                if (translucent) {
                    pipeline.first.rasterState.blendFunctionSrcRGB = BlendFunction::ONE;
                    pipeline.first.rasterState.blendFunctionSrcAlpha = BlendFunction::ONE;
                    pipeline.first.rasterState.blendFunctionDstRGB = BlendFunction::ONE_MINUS_SRC_ALPHA;
                    pipeline.first.rasterState.blendFunctionDstAlpha = BlendFunction::ONE_MINUS_SRC_ALPHA;
                }

                // The width of each view takes up 1/depth of the screen width.
                out.params.viewport.width /= inputTextureDesc.depth;

                // Render all layers of the texture to the screen side-by-side.
                for (uint32_t i = 0; i < inputTextureDesc.depth; ++i) {
                    mi->setParameter("layerIndex", i);
                    mi->commit(driver);
                    render(out, pipeline, driver);
                    // From the second draw, don't clear the targetbuffer.
                    out.params.flags.clear = filament::backend::TargetBufferFlags::NONE;
                    out.params.flags.discardStart = filament::backend::TargetBufferFlags::NONE;
                    out.params.viewport.left += out.params.viewport.width;
                }
        });

    return ppQuadBlit->output;
}

FrameGraphId<FrameGraphTexture> PostProcessManager::debugDisplayShadowTexture(
        FrameGraph& fg,
        FrameGraphId<FrameGraphTexture> input,
        FrameGraphId<FrameGraphTexture> shadowmap, float scale,
        uint8_t layer, uint8_t level, uint8_t channel, float power) noexcept {
    if (shadowmap) {
        struct ShadowMapData {
            FrameGraphId<FrameGraphTexture> color;
            FrameGraphId<FrameGraphTexture> depth;
        };

        auto const& desc = fg.getDescriptor(input);
        float const ratio = float(desc.height) / float(desc.width);
        float const screenScale = float(fg.getDescriptor(shadowmap).height) / float(desc.height);
        float2 const s = { screenScale * scale * ratio, screenScale * scale };

        auto& shadomapDebugPass = fg.addPass<ShadowMapData>("shadowmap debug pass",
                [&](FrameGraph::Builder& builder, auto& data) {
                    data.color = builder.read(input,
                            FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                    data.color = builder.write(data.color,
                            FrameGraphTexture::Usage::COLOR_ATTACHMENT);
                    data.depth = builder.sample(shadowmap);
                    builder.declareRenderPass("color target", {
                            .attachments = { .color = { data.color }}
                    });
                },
                [=](FrameGraphResources const& resources, auto const& data, DriverApi& driver) {
                    auto out = resources.getRenderPassInfo();
                    auto in = resources.getTexture(data.depth);
                    auto const& material = getPostProcessMaterial("shadowmap");
                    FMaterialInstance* const mi = material.getMaterialInstance(mEngine);
                    mi->setParameter("shadowmap", in, {
                        .filterMin = SamplerMinFilter::NEAREST_MIPMAP_NEAREST });
                    mi->setParameter("scale", s);
                    mi->setParameter("layer", (uint32_t)layer);
                    mi->setParameter("level", (uint32_t)level);
                    mi->setParameter("channel", (uint32_t)channel);
                    mi->setParameter("power", power);
                    commitAndRender(out, material, driver);
                });
        input = shadomapDebugPass->color;
    }
    return input;
}


} // namespace filament

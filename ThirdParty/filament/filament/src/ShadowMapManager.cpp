
#include "ShadowMapManager.h"
#include "RenderPass.h"
#include "ShadowMap.h"

#include <filament/Frustum.h>
#include <filament/LightManager.h>
#include <filament/Options.h>

#include <private/filament/EngineEnums.h>

#include "components/RenderableManager.h"

#include "details/Camera.h"
#include "details/DebugRegistry.h"
#include "details/Texture.h"
#include "details/View.h"

#include "fg/FrameGraph.h"
#include "fg/FrameGraphId.h"
#include "fg/FrameGraphRenderPass.h"
#include "fg/FrameGraphTexture.h"

#include <backend/DriverApiForward.h>
#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/Range.h"
#include "third_party/filament/libs/utils/include/utils/Slice.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"

#include "third_party/filament/libs/math/include/math/half.h"
#include "third_party/filament/libs/math/include/math/mat4.h"
#include "third_party/filament/libs/math/include/math/vec4.h"
#include "third_party/filament/libs/math/include/math/scalar.h"

#include <cmath>
#include <limits>
#include <new>
#include <memory>

#include <stdint.h>
#include <stddef.h>

namespace filament {

using namespace backend;
using namespace math;

ShadowMapManager::ShadowMapManager(FEngine& engine) {
    FDebugRegistry& debugRegistry = engine.getDebugRegistry();
    debugRegistry.registerProperty("d.shadowmap.visualize_cascades",
            &engine.debug.shadowmap.visualize_cascades);
    debugRegistry.registerProperty("d.shadowmap.tightly_bound_scene",
            &engine.debug.shadowmap.tightly_bound_scene);
}

ShadowMapManager::~ShadowMapManager() {
    // destroy the ShadowMap array in-place
    if (UTILS_UNLIKELY(mInitialized)) {
        UTILS_NOUNROLL
        for (auto& entry: mShadowMapCache) {
            std::destroy_at(std::launder(reinterpret_cast<ShadowMap*>(&entry)));
        }
    }
}

void ShadowMapManager::createIfNeeded(FEngine& engine,
        std::unique_ptr<ShadowMapManager>& inOutShadowMapManager) {
    if (UTILS_UNLIKELY(!inOutShadowMapManager)) {
        inOutShadowMapManager.reset(new ShadowMapManager(engine));
    }
}

void ShadowMapManager::terminate(FEngine& engine,
        std::unique_ptr<ShadowMapManager>& shadowMapManager) {
    if (shadowMapManager) {
        shadowMapManager->terminate(engine);
    }
}

void ShadowMapManager::terminate(FEngine& engine) {
    if (UTILS_UNLIKELY(mInitialized)) {
        DriverApi& driver = engine.getDriverApi();
        driver.destroyBufferObject(mShadowUbh);
        UTILS_NOUNROLL
        for (auto& entry: mShadowMapCache) {
            std::launder(reinterpret_cast<ShadowMap*>(&entry))->terminate(engine);
        }
    }
}

ShadowMapManager::ShadowTechnique ShadowMapManager::update(
        Builder const& builder,
        FEngine& engine, FView& view,
        CameraInfo const& cameraInfo,
        FScene::RenderableSoa& renderableData, FScene::LightSoa const& lightData) noexcept {

    if (!builder.mDirectionalShadowMapCount && !builder.mSpotShadowMapCount) {
        // no shadows were recorder
        return ShadowTechnique::NONE;
    }

    // initialize the shadowmap array the first time
    if (UTILS_UNLIKELY(!mInitialized)) {
        mInitialized = true;
        // initialize our ShadowMap array in-place
        mShadowUbh = engine.getDriverApi().createBufferObject(mShadowUb.getSize(),
                BufferObjectBinding::UNIFORM, BufferUsage::DYNAMIC);
        UTILS_NOUNROLL
        for (auto& entry: mShadowMapCache) {
            new(&entry) ShadowMap(engine);
        }
    }

    mDirectionalShadowMapCount = builder.mDirectionalShadowMapCount;
    mSpotShadowMapCount = builder.mSpotShadowMapCount;

    for (auto const& entry : builder.mShadowMaps) {
        auto& shadowMap = getShadowMap(entry.shadowIndex);
        shadowMap.initialize(
                entry.lightIndex,
                entry.shadowType,
                entry.shadowIndex,
                entry.face,
                entry.options);
    }

    ShadowTechnique shadowTechnique = {};

    calculateTextureRequirements(engine, view, lightData);

    // Compute scene-dependent values shared across all shadow maps
    ShadowMap::SceneInfo const info{ *view.getScene(), view.getVisibleLayers(), cameraInfo.view };

    shadowTechnique |= updateCascadeShadowMaps(
            engine, view, cameraInfo, renderableData, lightData, info);

    shadowTechnique |= updateSpotShadowMaps(
            engine, lightData);

    mSceneInfo = info;

    return shadowTechnique;
}

ShadowMapManager::Builder& ShadowMapManager::Builder::directionalShadowMap(size_t lightIndex,
        LightManager::ShadowOptions const* options) noexcept {
    assert_invariant(options->shadowCascades <= CONFIG_MAX_SHADOW_CASCADES);
    // this updates getCascadedShadowMap()
    mDirectionalShadowMapCount = options->shadowCascades;
    for (size_t c = 0; c < options->shadowCascades; c++) {
        mShadowMaps.push_back({
                .lightIndex = lightIndex,
                .shadowType = ShadowType::DIRECTIONAL,
                .shadowIndex = uint8_t(c),
                .face = 0,
                .options = options });
    }
    return *this;
}

ShadowMapManager::Builder& ShadowMapManager::Builder::shadowMap(size_t lightIndex, bool spotlight,
        LightManager::ShadowOptions const* options) noexcept {
    if (spotlight) {
        const size_t c = mSpotShadowMapCount++;
        const size_t i = c + CONFIG_MAX_SHADOW_CASCADES;
        assert_invariant(i < CONFIG_MAX_SHADOWMAPS);
        mShadowMaps.push_back({
                .lightIndex = lightIndex,
                .shadowType = ShadowType::SPOT,
                .shadowIndex = uint8_t(i),
                .face = 0,
                .options = options });
    } else {
        // point-light, generate 6 independent shadowmaps
        for (size_t face = 0; face < 6; face++) {
            const size_t c = mSpotShadowMapCount++;
            const size_t i = c + CONFIG_MAX_SHADOW_CASCADES;
            assert_invariant(i < CONFIG_MAX_SHADOWMAPS);
            mShadowMaps.push_back({
                    .lightIndex = lightIndex,
                    .shadowType = ShadowType::POINT,
                    .shadowIndex = uint8_t(i),
                    .face = uint8_t(face),
                    .options = options });
        }
    }
    return *this;
}

FrameGraphId<FrameGraphTexture> ShadowMapManager::render(FEngine& engine, FrameGraph& fg,
        RenderPassBuilder const& passBuilder,
        FView& view, CameraInfo const& mainCameraInfo,
        float4 const& userTime) noexcept {

    const float moment2 = std::numeric_limits<half>::max();
    const float moment1 = std::sqrt(moment2);
    const float4 vsmClearColor{ moment1, moment2, -moment1, moment2 };

    FScene* scene = view.getScene();
    assert_invariant(scene);

    // make a copy here, because it's a very small structure
    const TextureAtlasRequirements textureRequirements = mTextureAtlasRequirements;
    assert_invariant(textureRequirements.layers <= CONFIG_MAX_SHADOW_LAYERS);

    // -------------------------------------------------------------------------------------------
    // Prepare Shadow Pass
    // -------------------------------------------------------------------------------------------

    struct PrepareShadowPassData {
        struct ShadowPass {
            mutable RenderPass::Executor executor;
            ShadowMap* shadowMap;
            utils::Range<uint32_t> range;
            FScene::VisibleMaskType visibilityMask;
        };
        // the actual shadow map atlas (currently a 2D texture array)
        FrameGraphId<FrameGraphTexture> shadows;
        // a RenderPass per shadow map
        utils::FixedCapacityVector<ShadowPass> passList;
    };

    VsmShadowOptions const& vsmShadowOptions = view.getVsmShadowOptions();

    auto& prepareShadowPass = fg.addPass<PrepareShadowPassData>("Prepare Shadow Pass",
            [&](FrameGraph::Builder& builder, auto& data) {
                data.passList.reserve(CONFIG_MAX_SHADOWMAPS);
                data.shadows = builder.createTexture("Shadowmap", {
                        .width = textureRequirements.size, .height = textureRequirements.size,
                        .depth = textureRequirements.layers,
                        .levels = textureRequirements.levels,
                        .type = SamplerType::SAMPLER_2D_ARRAY,
                        .format = textureRequirements.format
                });

                // these loops create a list of the shadow maps that might need to be rendered
                auto& passList = data.passList;

                // Directional, cascaded shadow maps
                auto const directionalShadowCastersRange = view.getVisibleDirectionalShadowCasters();
                if (!directionalShadowCastersRange.empty()) {
                    for (auto& shadowMap : getCascadedShadowMap()) {
                        // for the directional light, we already know if it has visible shadows.
                        if (shadowMap.hasVisibleShadows()) {
                            passList.push_back({
                                    {}, &shadowMap, directionalShadowCastersRange,
                                    VISIBLE_DIR_SHADOW_RENDERABLE });
                        }
                    }
                }

                // Point lights and Spotlight shadow maps
                auto const spotShadowCastersRange = view.getVisibleSpotShadowCasters();
                if (!spotShadowCastersRange.empty()) {
                    for (auto& shadowMap : getSpotShadowMaps()) {
                        assert_invariant(!shadowMap.isDirectionalShadow());

                        switch (shadowMap.getShadowType()) {
                            case ShadowType::DIRECTIONAL:
                                // we should never be here
                                break;
                            case ShadowType::SPOT:
                                prepareSpotShadowMap(shadowMap, engine, view, mainCameraInfo,
                                        scene->getLightData(), mSceneInfo);
                                break;
                            case ShadowType::POINT:
                                preparePointShadowMap(shadowMap, engine, view, mainCameraInfo,
                                        scene->getLightData());
                                break;
                        }

                        if (shadowMap.hasVisibleShadows()) {
                            passList.push_back({
                                    {}, &shadowMap, spotShadowCastersRange,
                                    VISIBLE_DYN_SHADOW_RENDERABLE });
                        }
                    }
                }

                assert_invariant(passList.size() <= textureRequirements.layers);

                // This pass must be declared as having a side effect because it never gets a
                // "read" from one of its resource (only writes), so the FrameGraph culls it.
                builder.sideEffect();
            },
            [this, &engine, &view, vsmShadowOptions,
                scene, mainCameraInfo, userTime, passBuilder = passBuilder](
                    FrameGraphResources const&, auto const& data, DriverApi& driver) mutable {


                // Note: we could almost parallel_for the loop below, the problem currently is
                // that updatePrimitivesLod() updates temporary global state.
                // prepareSpotShadowMap() also update the visibility of renderable. These two
                // pieces of state are needed only until shadowMap.render() returns.
                // Conceptually, we could store this out-of-band.

                // Generate a RenderPass for each shadow map
                for (auto const& entry : data.passList) {
                    ShadowMap const& shadowMap = *entry.shadowMap;
                    assert_invariant(shadowMap.hasVisibleShadows());

                    // Note: this loop can generate a lot of commands that come out of the
                    //       "per frame command arena". The allocation persists until the
                    //       end of the frame.
                    //       One way to possibly mitigate this, would be to always use the
                    //       same command buffer for all shadow map, but then we'd generate
                    //       a lot of unneeded draw calls.
                    //       To do this efficiently, we'd need a way to cull draw calls already
                    //       recorded in the command buffer, per shadow map.

                    // Note: the output of culling below is stored in scene->getRenderableData()

                    switch (shadowMap.getShadowType()) {
                        case ShadowType::DIRECTIONAL:
                            // we should never be here
                            break;
                        case ShadowType::SPOT:
                            ShadowMapManager::cullSpotShadowMap(shadowMap, engine, view,
                                    scene->getRenderableData(), entry.range,
                                    scene->getLightData());
                            break;
                        case ShadowType::POINT:
                            ShadowMapManager::cullPointShadowMap(shadowMap, view,
                                    scene->getRenderableData(), entry.range,
                                    scene->getLightData());
                            break;
                    }

                    // cameraInfo only valid after calling update
                    const CameraInfo cameraInfo{ shadowMap.getCamera(), mainCameraInfo };

                    auto transaction = ShadowMap::open(driver);
                    ShadowMap::prepareCamera(transaction, engine, cameraInfo);
                    ShadowMap::prepareViewport(transaction, shadowMap.getViewport());
                    ShadowMap::prepareTime(transaction, engine, userTime);
                    ShadowMap::prepareShadowMapping(transaction,
                            vsmShadowOptions.highPrecision);
                    shadowMap.commit(transaction, driver);

                    // updatePrimitivesLod must be run before RenderPass::appendCommands.
                    view.updatePrimitivesLod(engine,
                            cameraInfo, scene->getRenderableData(), entry.range);

                    // generate and sort the commands for rendering the shadow map

                    RenderPass const pass = passBuilder
                            .camera(cameraInfo)
                            .visibilityMask(entry.visibilityMask)
                            .geometry(scene->getRenderableData(),
                                    entry.range,
                                    view.getRenderableUBO())
                            .commandTypeFlags(RenderPass::CommandTypeFlags::SHADOW)
                            .build(engine);

                    entry.executor = pass.getExecutor();

                    if (!view.hasVSM()) {
                        auto const* options = shadowMap.getShadowOptions();
                        PolygonOffset const polygonOffset = { // handle reversed Z
                                .slope    = -options->polygonOffsetSlope,
                                .constant = -options->polygonOffsetConstant
                        };
                        entry.executor.overridePolygonOffset(&polygonOffset);
                    }
                }

                // Finally update our UBO in one batch
                if (mShadowUb.isDirty()) {
                    driver.updateBufferObject(mShadowUbh,
                            mShadowUb.toBufferDescriptor(driver), 0);
                }
            });

    // -------------------------------------------------------------------------------------------
    // Shadow Passes
    // -------------------------------------------------------------------------------------------

    fg.getBlackboard()["shadowmap"] = prepareShadowPass->shadows;

    struct ShadowPassData {
        FrameGraphId<FrameGraphTexture> tempBlurSrc{};  // temporary shadowmap when blurring
        FrameGraphId<FrameGraphTexture> output;
        uint32_t rt{};
    };

    auto const& passList = prepareShadowPass.getData().passList;
    for (auto const& entry: passList) {
        assert_invariant(entry.shadowMap->hasVisibleShadows());

        const uint8_t layer = entry.shadowMap->getLayer();
        const auto* options = entry.shadowMap->getShadowOptions();
        const auto msaaSamples = textureRequirements.msaaSamples;

        auto& shadowPass = fg.addPass<ShadowPassData>("Shadow Pass",
                [&](FrameGraph::Builder& builder, auto& data) {
                    const bool blur = view.hasVSM() && options->vsm.blurWidth > 0.0f;

                    FrameGraphRenderPass::Descriptor renderTargetDesc{};

                    data.output = builder.createSubresource(prepareShadowPass->shadows,
                            "Shadowmap Layer", { .layer = layer });

                    if (view.hasVSM()) {
                        // Each shadow pass has its own sample count, but textures are created with
                        // a default count of 1 because we're using "magic resolve" (sample count is
                        // set on the render target).
                        // When rendering VSM shadow maps, we still need a depth texture for sorting.
                        // We specify the sample count here because we don't need automatic resolve.
                        auto depth = builder.createTexture("Temporary VSM Depth Texture", {
                                .width = textureRequirements.size, .height = textureRequirements.size,
                                .samples = msaaSamples,
                                .format = TextureFormat::DEPTH16,
                        });

                        // Temporary (resolved) texture used to render the shadowmap when blurring
                        // is needed -- it'll be used as the source of the blur.
                        data.tempBlurSrc = builder.createTexture("Temporary Shadowmap", {
                                .width = textureRequirements.size, .height = textureRequirements.size,
                                .format = textureRequirements.format
                        });

                        depth = builder.write(depth,
                                FrameGraphTexture::Usage::DEPTH_ATTACHMENT);

                        data.output = builder.write(data.output,
                                FrameGraphTexture::Usage::COLOR_ATTACHMENT);

                        renderTargetDesc.attachments.color[0] = data.output;
                        renderTargetDesc.attachments.depth = depth;
                        renderTargetDesc.clearFlags =
                                TargetBufferFlags::COLOR | TargetBufferFlags::DEPTH;
                        // we need to clear the shadow map with the max EVSM moments
                        renderTargetDesc.clearColor = vsmClearColor;
                        renderTargetDesc.samples = msaaSamples;

                        if (blur) {
                            data.tempBlurSrc = builder.write(data.tempBlurSrc,
                                    FrameGraphTexture::Usage::COLOR_ATTACHMENT);

                            data.rt = builder.declareRenderPass("Temp Shadow RT", {
                                    .attachments = {
                                            .color = { data.tempBlurSrc },
                                            .depth = depth },
                                    .clearColor = vsmClearColor,
                                    .samples = msaaSamples,
                                    .clearFlags = TargetBufferFlags::COLOR
                                            | TargetBufferFlags::DEPTH
                            });
                        }
                    } else {
                        // the shadowmap layer
                        data.output = builder.write(data.output,
                                FrameGraphTexture::Usage::DEPTH_ATTACHMENT);
                        renderTargetDesc.attachments.depth = data.output;
                        renderTargetDesc.clearFlags = TargetBufferFlags::DEPTH;
                    }

                    // finally, create the shadowmap render target -- one per layer.
                    auto rt = builder.declareRenderPass("Shadow RT", renderTargetDesc);

                    // render either directly into the shadowmap, or to the temporary texture for
                    // blurring.
                    data.rt = blur ? data.rt : rt;
                },
                [=, &engine, &entry](FrameGraphResources const& resources,
                        auto const& data, DriverApi& driver) {

                    // Note: we capture entry by reference here. That's actually okay because
                    // `entry` lives in `PrepareShadowPassData` which is guaranteed to still
                    // be alive when we execute here (all passes stay alive until the FrameGraph
                    // is destroyed).
                    // It wouldn't work to capture by copy because entry.executor wouldn't be
                    // initialized, as this happens in an `execute` block.

                    auto rt = resources.getRenderPassInfo(data.rt);

                    driver.beginRenderPass(rt.target, rt.params);
                    entry.shadowMap->bind(driver);
                    entry.executor.overrideScissor(entry.shadowMap->getScissor());
                    entry.executor.execute(engine, "Shadow Pass");
                    driver.endRenderPass();
                });


        // now emit the blurring passes if needed
        if (view.hasVSM()) {
            auto& ppm = engine.getPostProcessManager();

            const float blurWidth = options->vsm.blurWidth;
            if (blurWidth > 0.0f) {
                const float sigma = (blurWidth + 1.0f) / 6.0f;
                size_t kernelWidth = std::ceil((blurWidth - 5.0f) / 4.0f);
                kernelWidth = kernelWidth * 4 + 5;
                ppm.gaussianBlurPass(fg,
                        shadowPass->tempBlurSrc,
                        shadowPass->output,
                        false, kernelWidth, sigma);
            }

            // If the shadow texture has more than one level, mipmapping was requested, either directly
            // or indirectly via anisotropic filtering.
            // So generate the mipmaps for each layer
            if (textureRequirements.levels > 1) {
                for (size_t level = 0; level < textureRequirements.levels - 1; level++) {
                    const bool finalize = level == textureRequirements.levels - 2;
                    ppm.vsmMipmapPass(fg, prepareShadowPass->shadows, layer, level,
                            vsmClearColor, finalize);
                }
            }
        }
    }

    return prepareShadowPass->shadows;
}

ShadowMapManager::ShadowTechnique ShadowMapManager::updateCascadeShadowMaps(FEngine& engine,
        FView& view, CameraInfo cameraInfo, FScene::RenderableSoa& renderableData,
        FScene::LightSoa const& lightData, ShadowMap::SceneInfo sceneInfo) noexcept {

    FScene* scene = view.getScene();
    auto& lcm = engine.getLightManager();

    FLightManager::Instance const directionalLight = lightData.elementAt<FScene::LIGHT_INSTANCE>(0);
    FLightManager::ShadowOptions const& options = lcm.getShadowOptions(directionalLight);
    FLightManager::ShadowParams const& params = lcm.getShadowParams(directionalLight);

    // Adjust the camera's projection for the light's shadowFar
    cameraInfo.zf = params.options.shadowFar > 0.0f ? params.options.shadowFar : cameraInfo.zf;
    if (UTILS_UNLIKELY(params.options.shadowFar > 0.0f)) {
        cameraInfo.zf = params.options.shadowFar;
        float const n = cameraInfo.zn;
        float const f = cameraInfo.zf;

        auto& p = cameraInfo.cullingProjection;
        float4 const N = { 0, 0,  1,  n };  // near plane equation
        float4 const F = { 0, 0, -1, -f };  // far plane equation
        // near plane equation scale factor
        float const sn = -2.0f * (p[2].w * F.w - p[3].w * F.z) / (N.z * F.w - N.w * F.z);
        // far plane equation scale factor
        float const sf = -2.0f * (p[2].w * N.w - p[3].w * N.z) / (F.z * N.w - F.w * N.z);
        // New values for the projection
        p[2].z = (sf * F.z - sn * N.z) * 0.5f;
        p[3].z = (sf * F.w - sn * N.w) * 0.5f;
    }

    const ShadowMap::ShadowMapInfo shadowMapInfo{
            .atlasDimension      = mTextureAtlasRequirements.size,
            .textureDimension    = uint16_t(options.mapSize),
            .shadowDimension     = uint16_t(options.mapSize - 2u),
            .textureSpaceFlipped = engine.getBackend() == Backend::METAL ||
                                   engine.getBackend() == Backend::VULKAN,
            .vsm                 = view.hasVSM()
    };

    bool hasVisibleShadows = false;
    utils::Slice<ShadowMap> cascadedShadowMaps = getCascadedShadowMap();
    if (!cascadedShadowMaps.empty()) {
        // Even if we have more than one cascade, we cull directional shadow casters against the
        // entire camera frustum, as if we only had a single cascade.
        ShadowMap& shadowMap = cascadedShadowMaps[0];

        const auto direction = lightData.elementAt<FScene::SHADOW_DIRECTION>(0);

        // We compute the directional light's model matrix using the origin's as the light position.
        // The choice of the light's origin initially doesn't matter for a directional light.
        // This will be adjusted later because of how we compute the depth metric for VSM.
        const mat4f MvAtOrigin = ShadowMap::getDirectionalLightViewMatrix(direction,
                normalize(cameraInfo.worldTransform[0].xyz));

        // Compute scene-dependent values shared across all cascades
        ShadowMap::updateSceneInfoDirectional(MvAtOrigin, *scene, sceneInfo);

        shadowMap.updateDirectional(engine,
                lightData, 0, cameraInfo, shadowMapInfo, sceneInfo);

        hasVisibleShadows = shadowMap.hasVisibleShadows();

        if (hasVisibleShadows) {
            Frustum const& frustum = shadowMap.getCamera().getCullingFrustum();
            FView::cullRenderables(engine.getJobSystem(), renderableData, frustum,
                    VISIBLE_DIR_SHADOW_RENDERABLE_BIT);
        }
    }

    ShadowTechnique shadowTechnique{};
    uint32_t directionalShadowsMask = 0;
    uint32_t cascadeHasVisibleShadows = 0;

    if (hasVisibleShadows) {
        // Adjust the near and far planes to tightly bound the scene.
        float vsNear = -cameraInfo.zn;
        float vsFar = -cameraInfo.zf;
        if (engine.debug.shadowmap.tightly_bound_scene && !params.options.stable) {
            vsNear = std::min(vsNear, sceneInfo.vsNearFar.x);
            vsFar = std::max(vsFar, sceneInfo.vsNearFar.y);
        }

        const size_t cascadeCount = cascadedShadowMaps.size();

        // We divide the camera frustum into N cascades. This gives us N + 1 split positions.
        // The first split position is the near plane; the last split position is the far plane.
        std::array<float, CascadeSplits::SPLIT_COUNT> splitPercentages{};
        splitPercentages[cascadeCount] = 1.0f;
        for (size_t i = 1; i < cascadeCount; i++) {
            splitPercentages[i] = options.cascadeSplitPositions[i - 1];
        }

        const CascadeSplits splits({
                .proj = cameraInfo.cullingProjection,
                .near = vsNear,
                .far = vsFar,
                .cascadeCount = cascadeCount,
                .splitPositions = splitPercentages
        });

        // The split positions uniform is a float4. To save space, we chop off the first split position
        // (which is the near plane, and doesn't need to be communicated to the shaders).
        static_assert(CONFIG_MAX_SHADOW_CASCADES <= 5,
                "At most, a float4 can fit 4 split positions for 5 shadow cascades");
        float4 wsSplitPositionUniform{ -std::numeric_limits<float>::infinity() };
        std::copy(splits.beginWs() + 1, splits.endWs(), &wsSplitPositionUniform[0]);

        float csSplitPosition[CONFIG_MAX_SHADOW_CASCADES + 1];
        std::copy(splits.beginCs(), splits.endCs(), csSplitPosition);

        mShadowMappingUniforms.cascadeSplits = wsSplitPositionUniform;

        // When computing the required bias we need a half-texel size, so we multiply by 0.5 here.
        // note: normalBias is set to zero for VSM
        const float normalBias = shadowMapInfo.vsm ? 0.0f : 0.5f * lcm.getShadowNormalBias(0);

        for (size_t i = 0, c = cascadedShadowMaps.size(); i < c; i++) {
            // Compute the frustum for the directional light.
            ShadowMap& shadowMap = cascadedShadowMaps[i];
            assert_invariant(shadowMap.getLightIndex() == 0);

            sceneInfo.csNearFar = { csSplitPosition[i], csSplitPosition[i + 1] };

            auto shaderParameters = shadowMap.updateDirectional(engine,
                    lightData, 0, cameraInfo, shadowMapInfo, sceneInfo);

            if (shadowMap.hasVisibleShadows()) {
                const size_t shadowIndex = shadowMap.getShadowIndex();
                assert_invariant(shadowIndex == i);

                // Texel size is constant for directional light (although that's not true when LISPSM
                // is used, but in that case we're pretending it is).
                const float wsTexelSize = shaderParameters.texelSizeAtOneMeterWs;

                auto& s = mShadowUb.edit();
                s.shadows[shadowIndex].layer = shadowMap.getLayer();
                s.shadows[shadowIndex].lightFromWorldMatrix = shaderParameters.lightSpace;
                s.shadows[shadowIndex].scissorNormalized = shaderParameters.scissorNormalized;
                s.shadows[shadowIndex].normalBias = normalBias * wsTexelSize;
                s.shadows[shadowIndex].texelSizeAtOneMeter = wsTexelSize;
                s.shadows[shadowIndex].elvsm = options.vsm.elvsm;
                s.shadows[shadowIndex].bulbRadiusLs =
                        mSoftShadowOptions.penumbraScale * options.shadowBulbRadius / wsTexelSize;

                shadowTechnique |= ShadowTechnique::SHADOW_MAP;
                cascadeHasVisibleShadows |= 0x1u << i;
            }
        }
    }

    // screen-space contact shadows for the directional light
    float const screenSpaceShadowDistance = options.maxShadowDistance;
    if (options.screenSpaceContactShadows) {
        shadowTechnique |= ShadowTechnique::SCREEN_SPACE;
    }
    directionalShadowsMask |= std::min(uint8_t(255u), options.stepCount) << 8u;

    if (any(shadowTechnique & ShadowTechnique::SHADOW_MAP)) {
        directionalShadowsMask |= 0x1u;
    }
    if (any(shadowTechnique & ShadowTechnique::SCREEN_SPACE)) {
        directionalShadowsMask |= 0x2u;
    }

    uint32_t cascades = 0;
    cascades |= uint32_t(cascadedShadowMaps.size());
    cascades |= cascadeHasVisibleShadows << 8u;

    mShadowMappingUniforms.directionalShadows = directionalShadowsMask;
    mShadowMappingUniforms.ssContactShadowDistance = screenSpaceShadowDistance;
    mShadowMappingUniforms.cascades = cascades;

    return shadowTechnique;
}

void ShadowMapManager::updateSpotVisibilityMasks(
        uint8_t visibleLayers,
        uint8_t const* UTILS_RESTRICT layers,
        FRenderableManager::Visibility const* UTILS_RESTRICT visibility,
        Culler::result_type* UTILS_RESTRICT visibleMask, size_t count) {
    // __restrict__ seems to only be taken into account as function parameters. This is very
    // important here, otherwise, this loop doesn't get vectorized.
    // This is vectorized 16x.
    count = (count + 0xFu) & ~0xFu; // capacity guaranteed to be multiple of 16
    for (size_t i = 0; i < count; ++i) {
        const Culler::result_type mask = visibleMask[i];
        const FRenderableManager::Visibility v = visibility[i];
        const bool inVisibleLayer = layers[i] & visibleLayers;

        const bool visSpotShadowRenderable = v.castShadows && inVisibleLayer &&
                (!v.culling || (mask & VISIBLE_DYN_SHADOW_RENDERABLE));

        using Type = Culler::result_type;

        visibleMask[i] &= ~Type(VISIBLE_DYN_SHADOW_RENDERABLE);
        visibleMask[i] |= Type(visSpotShadowRenderable << VISIBLE_DYN_SHADOW_RENDERABLE_BIT);
    }
}

void ShadowMapManager::prepareSpotShadowMap(ShadowMap& shadowMap, FEngine& engine, FView& view,
        CameraInfo const& mainCameraInfo,
        FScene::LightSoa& lightData, ShadowMap::SceneInfo const& sceneInfo) noexcept {

    const size_t lightIndex = shadowMap.getLightIndex();
    FLightManager::ShadowOptions const* const options = shadowMap.getShadowOptions();

    // update the shadow map frustum/camera
    const ShadowMap::ShadowMapInfo shadowMapInfo{
            .atlasDimension      = mTextureAtlasRequirements.size,
            .textureDimension    = uint16_t(options->mapSize),
            .shadowDimension     = uint16_t(options->mapSize - 2u),
            .textureSpaceFlipped = engine.getBackend() == Backend::METAL ||
                                   engine.getBackend() == Backend::VULKAN,
            .vsm                 = view.hasVSM()
    };

    auto shaderParameters = shadowMap.updateSpot(engine,
            lightData, lightIndex, mainCameraInfo, shadowMapInfo, *view.getScene(), sceneInfo);

    // and if we need to generate it, update all the UBO data
    if (shadowMap.hasVisibleShadows()) {
        const size_t shadowIndex = shadowMap.getShadowIndex();
        const float wsTexelSizeAtOneMeter = shaderParameters.texelSizeAtOneMeterWs;
        // note: normalBias is set to zero for VSM
        const float normalBias = shadowMapInfo.vsm ? 0.0f : options->normalBias;

        auto& s = mShadowUb.edit();
        const double n = shadowMap.getCamera().getNear();
        const double f = shadowMap.getCamera().getCullingFar();
        s.shadows[shadowIndex].layer = shadowMap.getLayer();
        s.shadows[shadowIndex].lightFromWorldMatrix = shaderParameters.lightSpace;
        s.shadows[shadowIndex].scissorNormalized = shaderParameters.scissorNormalized;
        s.shadows[shadowIndex].normalBias = normalBias * wsTexelSizeAtOneMeter;
        s.shadows[shadowIndex].lightFromWorldZ = shaderParameters.lightFromWorldZ;
        s.shadows[shadowIndex].texelSizeAtOneMeter = wsTexelSizeAtOneMeter;
        s.shadows[shadowIndex].nearOverFarMinusNear = float(n / (f - n));
        s.shadows[shadowIndex].elvsm = options->vsm.elvsm;
        s.shadows[shadowIndex].bulbRadiusLs =
                mSoftShadowOptions.penumbraScale * options->shadowBulbRadius
                        / wsTexelSizeAtOneMeter;

    }
}

void ShadowMapManager::cullSpotShadowMap(ShadowMap const& shadowMap, FEngine& engine, FView& view,
        FScene::RenderableSoa& renderableData, utils::Range<uint32_t> range,
        FScene::LightSoa& lightData) noexcept {
    auto& lcm = engine.getLightManager();

    const size_t lightIndex = shadowMap.getLightIndex();
    const FLightManager::Instance li = lightData.elementAt<FScene::LIGHT_INSTANCE>(lightIndex);

    // compute the frustum for this light
    // for spotlights, we cull shadow casters first because we already know the frustum,
    // this will help us find better near/far plane later
    const auto position = lightData.elementAt<FScene::POSITION_RADIUS>(lightIndex).xyz;
    const auto direction = lightData.elementAt<FScene::DIRECTION>(lightIndex);
    const auto radius = lightData.elementAt<FScene::POSITION_RADIUS>(lightIndex).w;
    const auto outerConeAngle = lcm.getSpotLightOuterCone(li);

    // compute shadow map frustum for culling
    const mat4f Mv = ShadowMap::getDirectionalLightViewMatrix(direction, { 0, 1, 0 }, position);
    const mat4f Mp = mat4f::perspective(outerConeAngle * f::RAD_TO_DEG * 2.0f, 1.0f, 0.01f, radius);
    const mat4f MpMv = math::highPrecisionMultiply(Mp, Mv);
    const Frustum frustum(MpMv);

    // Cull shadow casters
    float3 const* worldAABBCenter = renderableData.data<FScene::WORLD_AABB_CENTER>();
    float3 const* worldAABBExtent = renderableData.data<FScene::WORLD_AABB_EXTENT>();
    FScene::VisibleMaskType* visibleArray = renderableData.data<FScene::VISIBLE_MASK>();
    Culler::intersects(
            visibleArray + range.first,
            frustum,
            worldAABBCenter + range.first,
            worldAABBExtent + range.first,
            range.size(),
            VISIBLE_DYN_SHADOW_RENDERABLE_BIT);

    // update their visibility mask
    uint8_t const* layers = renderableData.data<FScene::LAYERS>();
    auto const* visibility = renderableData.data<FScene::VISIBILITY_STATE>();
    updateSpotVisibilityMasks(
            view.getVisibleLayers(),
            layers + range.first,
            visibility + range.first,
            visibleArray + range.first,
            range.size());
}

void ShadowMapManager::preparePointShadowMap(ShadowMap& shadowMap,
        FEngine& engine, FView& view, CameraInfo const& mainCameraInfo,
        FScene::LightSoa& lightData) noexcept {

    const uint8_t face = shadowMap.getFace();
    const size_t lightIndex = shadowMap.getLightIndex();
    FLightManager::ShadowOptions const* const options = shadowMap.getShadowOptions();

    // update the shadow map frustum/camera
    const ShadowMap::ShadowMapInfo shadowMapInfo{
            .atlasDimension      = mTextureAtlasRequirements.size,
            .textureDimension    = uint16_t(options->mapSize),
            .shadowDimension     = uint16_t(options->mapSize), // point-lights don't have a border
            .textureSpaceFlipped = engine.getBackend() == Backend::METAL ||
                                   engine.getBackend() == Backend::VULKAN,
            .vsm                 = view.hasVSM()
    };

    auto shaderParameters = shadowMap.updatePoint(engine, lightData, lightIndex,
            mainCameraInfo, shadowMapInfo, *view.getScene(), face);

    // and if we need to generate it, update all the UBO data
    if (shadowMap.hasVisibleShadows()) {
        const size_t shadowIndex = shadowMap.getShadowIndex();
        const float wsTexelSizeAtOneMeter = shaderParameters.texelSizeAtOneMeterWs;
        // note: normalBias is set to zero for VSM
        const float normalBias = shadowMapInfo.vsm ? 0.0f : options->normalBias;

        auto& s = mShadowUb.edit();
        const double n = shadowMap.getCamera().getNear();
        const double f = shadowMap.getCamera().getCullingFar();
        s.shadows[shadowIndex].layer = shadowMap.getLayer();
        s.shadows[shadowIndex].lightFromWorldMatrix = shaderParameters.lightSpace;
        s.shadows[shadowIndex].scissorNormalized = shaderParameters.scissorNormalized;
        s.shadows[shadowIndex].normalBias = normalBias * wsTexelSizeAtOneMeter;
        s.shadows[shadowIndex].lightFromWorldZ = shaderParameters.lightFromWorldZ;
        s.shadows[shadowIndex].texelSizeAtOneMeter = wsTexelSizeAtOneMeter;
        s.shadows[shadowIndex].nearOverFarMinusNear = float(n / (f - n));
        s.shadows[shadowIndex].elvsm = options->vsm.elvsm;
        s.shadows[shadowIndex].bulbRadiusLs =
                mSoftShadowOptions.penumbraScale * options->shadowBulbRadius
                        / wsTexelSizeAtOneMeter;
    }
}

void ShadowMapManager::cullPointShadowMap(ShadowMap const& shadowMap, FView& view,
        FScene::RenderableSoa& renderableData, utils::Range<uint32_t> range,
        FScene::LightSoa& lightData) noexcept {

    const uint8_t face = shadowMap.getFace();
    const size_t lightIndex = shadowMap.getLightIndex();

    // compute the frustum for this light
    // for spotlights, we cull shadow casters first because we already know the frustum,
    // this will help us find better near/far plane later
    const auto position = lightData.elementAt<FScene::POSITION_RADIUS>(lightIndex).xyz;
    const auto radius = lightData.elementAt<FScene::POSITION_RADIUS>(lightIndex).w;

    // compute shadow map frustum for culling
    const mat4f Mv = ShadowMap::getPointLightViewMatrix(TextureCubemapFace(face), position);
    const mat4f Mp = mat4f::perspective(90.0f, 1.0f, 0.01f, radius);
    const Frustum frustum{ math::highPrecisionMultiply(Mp, Mv) };

    // Cull shadow casters
    float3 const* worldAABBCenter = renderableData.data<FScene::WORLD_AABB_CENTER>();
    float3 const* worldAABBExtent = renderableData.data<FScene::WORLD_AABB_EXTENT>();
    FScene::VisibleMaskType* visibleArray = renderableData.data<FScene::VISIBLE_MASK>();
    Culler::intersects(
            visibleArray + range.first,
            frustum,
            worldAABBCenter + range.first,
            worldAABBExtent + range.first,
            range.size(),
            VISIBLE_DYN_SHADOW_RENDERABLE_BIT);

    // update their visibility mask
    uint8_t const* layers = renderableData.data<FScene::LAYERS>();
    auto const* visibility = renderableData.data<FScene::VISIBILITY_STATE>();
    updateSpotVisibilityMasks(
            view.getVisibleLayers(),
            layers + range.first,
            visibility + range.first,
            visibleArray + range.first,
            range.size());
}

ShadowMapManager::ShadowTechnique ShadowMapManager::updateSpotShadowMaps(FEngine& engine,
        FScene::LightSoa const& lightData) noexcept {

    // The const_cast here is a little ugly, but conceptually lightData should be const,
    // it's just that we're using it to store some temporary data. With SoA we can't have
    // a `mutable` element, so that's a workaround.
    FScene::ShadowInfo* const shadowInfo = const_cast<FScene::ShadowInfo*>(
            lightData.data<FScene::SHADOW_INFO>());

    ShadowTechnique shadowTechnique{};
    utils::Slice<ShadowMap> const spotShadowMaps = getSpotShadowMaps();
    if (!spotShadowMaps.empty()) {
        shadowTechnique |= ShadowTechnique::SHADOW_MAP;
        for (ShadowMap const& shadowMap : spotShadowMaps) {
            const size_t lightIndex = shadowMap.getLightIndex();
            // Gather the per-light (not per shadow map) information. For point lights we will
            // "see" 6 shadowmaps (one per face), we must use the first face one, the shader
            // knows how to find the entry for other faces (they're guaranteed to be sequential).
            if (shadowMap.getFace() == 0) {
                shadowInfo[lightIndex].castsShadows = true;     // FIXME: is that set correctly?
                shadowInfo[lightIndex].index = shadowMap.getShadowIndex();
            }
        }
    }

    // screen-space contact shadows for point/spotlights
    auto& lcm = engine.getLightManager();
    auto *pLightInstances = lightData.data<FScene::LIGHT_INSTANCE>();
    for (size_t i = 0, c = lightData.size(); i < c; i++) {
        // screen-space contact shadows
        LightManager::ShadowOptions const& shadowOptions = lcm.getShadowOptions(pLightInstances[i]);
        if (shadowOptions.screenSpaceContactShadows) {
            shadowTechnique |= ShadowTechnique::SCREEN_SPACE;
            shadowInfo[i].contactShadows = true;
            // TODO: distance/steps are always taken from the directional light currently
        }
    }

    return shadowTechnique;
}

void ShadowMapManager::calculateTextureRequirements(FEngine& engine, FView& view,
        FScene::LightSoa const&) noexcept {

    // Lay out the shadow maps. For now, we take the largest requested dimension and allocate a
    // texture of that size. Each cascade / shadow map gets its own layer in the array texture.
    // The directional shadow cascades start on layer 0, followed by spotlights.
    uint8_t layer = 0;
    uint32_t maxDimension = 0;
    bool elvsm = false;
    for (ShadowMap& shadowMap : getCascadedShadowMap()) {
        // Shadow map size should be the same for all cascades.
        auto const& options = shadowMap.getShadowOptions();
        maxDimension = std::max(maxDimension, options->mapSize);
        elvsm = elvsm || options->vsm.elvsm;
        shadowMap.setLayer(layer++);
    }
    for (ShadowMap& shadowMap : getSpotShadowMaps()) {
        auto const& options = shadowMap.getShadowOptions();
        maxDimension = std::max(maxDimension, options->mapSize);
        elvsm = elvsm || options->vsm.elvsm;
        shadowMap.setLayer(layer++);
    }

    const uint8_t layersNeeded = layer;

    // Generate mipmaps for VSM when anisotropy is enabled or when requested
    auto const& vsmShadowOptions = view.getVsmShadowOptions();
    const bool useMipmapping = view.hasVSM() &&
                               ((vsmShadowOptions.anisotropy > 0) || vsmShadowOptions.mipmapping);

    uint8_t msaaSamples = vsmShadowOptions.msaaSamples;
    if (engine.getDriverApi().isWorkaroundNeeded(Workaround::DISABLE_BLIT_INTO_TEXTURE_ARRAY)) {
        msaaSamples = 1;
    }

    TextureFormat format = TextureFormat::DEPTH16;
    if (view.hasVSM()) {
        if (vsmShadowOptions.highPrecision) {
            if (elvsm) {
                format = TextureFormat::RGBA32F;
            } else {
                format = TextureFormat::RG32F;
            }
        } else {
            if (elvsm) {
                format = TextureFormat::RGBA16F;
            } else {
                format = TextureFormat::RG16F;
            }
        }
    }

    mSoftShadowOptions = view.getSoftShadowOptions();

    uint8_t mipLevels = 1u;
    if (useMipmapping) {
        // Limit the lowest mipmap level to 256x256.
        // This avoids artifacts on high derivative tangent surfaces.
        int const lowMipmapLevel = 7;    // log2(256) - 1
        mipLevels = std::max(1, FTexture::maxLevelCount(maxDimension) - lowMipmapLevel);
    }

    // publish the debugging data
    engine.debug.shadowmap.display_shadow_texture_layer_count = layersNeeded;
    engine.debug.shadowmap.display_shadow_texture_level_count = mipLevels;

    mTextureAtlasRequirements = {
            (uint16_t)maxDimension,
            layersNeeded,
            mipLevels,
            msaaSamples,
            format
    };
}

ShadowMapManager::CascadeSplits::CascadeSplits(Params const& params) noexcept
        : mSplitCount(params.cascadeCount + 1) {
    for (size_t s = 0; s < mSplitCount; s++) {
        mSplitsWs[s] = params.near + (params.far - params.near) * params.splitPositions[s];
        mSplitsCs[s] = mat4f::project(params.proj, float3(0.0f, 0.0f, mSplitsWs[s])).z;
    }
}

} // namespace filament

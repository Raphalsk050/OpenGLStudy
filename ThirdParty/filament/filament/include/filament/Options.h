
#ifndef TNT_FILAMENT_OPTIONS_H
#define TNT_FILAMENT_OPTIONS_H

#include <filament/Color.h>

#include "third_party/filament/libs/math/include/math/vec2.h"
#include "third_party/filament/libs/math/include/math/vec3.h"

#include <math.h>

#include <stdint.h>

namespace filament {

class Texture;

enum class QualityLevel : uint8_t {
    LOW,
    MEDIUM,
    HIGH,
    ULTRA
};

enum class BlendMode : uint8_t {
    OPAQUE,
    TRANSLUCENT
};

struct DynamicResolutionOptions {
    math::float2 minScale = {0.5f, 0.5f};           //!< minimum scale factors in x and y %codegen_java_float%
    math::float2 maxScale = {1.0f, 1.0f};           //!< maximum scale factors in x and y %codegen_java_float%
    float sharpness = 0.9f;                         //!< sharpness when QualityLevel::MEDIUM or higher is used [0 (disabled), 1 (sharpest)]
    bool enabled = false;                           //!< enable or disable dynamic resolution
    bool homogeneousScaling = false;                //!< set to true to force homogeneous scaling

    QualityLevel quality = QualityLevel::LOW;
};

struct BloomOptions {
    enum class BlendMode : uint8_t {
        ADD,           //!< Bloom is modulated by the strength parameter and added to the scene
        INTERPOLATE    //!< Bloom is interpolated with the scene using the strength parameter
    };
    Texture* dirt = nullptr;                //!< user provided dirt texture %codegen_skip_json% %codegen_skip_javascript%
    float dirtStrength = 0.2f;              //!< strength of the dirt texture %codegen_skip_json% %codegen_skip_javascript%
    float strength = 0.10f;                 //!< bloom's strength between 0.0 and 1.0
    uint32_t resolution = 384;              //!< resolution of vertical axis (2^levels to 2048)
    uint8_t levels = 6;                     //!< number of blur levels (1 to 11)
    BlendMode blendMode = BlendMode::ADD;   //!< how the bloom effect is applied
    bool threshold = true;                  //!< whether to threshold the source
    bool enabled = false;                   //!< enable or disable bloom
    float highlight = 1000.0f;              //!< limit highlights to this value before bloom [10, +inf]

    QualityLevel quality = QualityLevel::LOW;

    bool lensFlare = false;                 //!< enable screen-space lens flare
    bool starburst = true;                  //!< enable starburst effect on lens flare
    float chromaticAberration = 0.005f;     //!< amount of chromatic aberration
    uint8_t ghostCount = 4;                 //!< number of flare "ghosts"
    float ghostSpacing = 0.6f;              //!< spacing of the ghost in screen units [0, 1[
    float ghostThreshold = 10.0f;           //!< hdr threshold for the ghosts
    float haloThickness = 0.1f;             //!< thickness of halo in vertical screen units, 0 to disable
    float haloRadius = 0.4f;                //!< radius of halo in vertical screen units [0, 0.5]
    float haloThreshold = 10.0f;            //!< hdr threshold for the halo
};

struct FogOptions {
    float distance = 0.0f;

    float cutOffDistance = INFINITY;

    float maximumOpacity = 1.0f;

    float height = 0.0f;

    float heightFalloff = 1.0f;

    LinearColor color = { 1.0f, 1.0f, 1.0f };

    float density = 0.1f;

    float inScatteringStart = 0.0f;

    float inScatteringSize = -1.0f;

    bool fogColorFromIbl = false;

    Texture* skyColor = nullptr;    //!< %codegen_skip_json% %codegen_skip_javascript%

    bool enabled = false;
};

struct DepthOfFieldOptions {
    enum class Filter : uint8_t {
        NONE,
        UNUSED,
        MEDIAN
    };
    float cocScale = 1.0f;              //!< circle of confusion scale factor (amount of blur)
    float cocAspectRatio = 1.0f;        //!< width/height aspect ratio of the circle of confusion (simulate anamorphic lenses)
    float maxApertureDiameter = 0.01f;  //!< maximum aperture diameter in meters (zero to disable rotation)
    bool enabled = false;               //!< enable or disable depth of field effect
    Filter filter = Filter::MEDIAN;     //!< filter to use for filling gaps in the kernel
    bool nativeResolution = false;      //!< perform DoF processing at native resolution
    uint8_t foregroundRingCount = 0; //!< number of kernel rings for foreground tiles
    uint8_t backgroundRingCount = 0; //!< number of kernel rings for background tiles
    uint8_t fastGatherRingCount = 0; //!< number of kernel rings for fast tiles
    uint16_t maxForegroundCOC = 0;

    uint16_t maxBackgroundCOC = 0;
};

struct VignetteOptions {
    float midPoint = 0.5f;                      //!< high values restrict the vignette closer to the corners, between 0 and 1
    float roundness = 0.5f;                     //!< controls the shape of the vignette, from a rounded rectangle (0.0), to an oval (0.5), to a circle (1.0)
    float feather = 0.5f;                       //!< softening amount of the vignette effect, between 0 and 1
    LinearColorA color = {0.0f, 0.0f, 0.0f, 1.0f}; //!< color of the vignette effect, alpha is currently ignored
    bool enabled = false;                       //!< enables or disables the vignette effect
};

struct RenderQuality {
    QualityLevel hdrColorBuffer = QualityLevel::HIGH;
};

struct AmbientOcclusionOptions {
    float radius = 0.3f;    //!< Ambient Occlusion radius in meters, between 0 and ~10.
    float power = 1.0f;     //!< Controls ambient occlusion's contrast. Must be positive.
    float bias = 0.0005f;   //!< Self-occlusion bias in meters. Use to avoid self-occlusion. Between 0 and a few mm.
    float resolution = 0.5f;//!< How each dimension of the AO buffer is scaled. Must be either 0.5 or 1.0.
    float intensity = 1.0f; //!< Strength of the Ambient Occlusion effect.
    float bilateralThreshold = 0.05f; //!< depth distance that constitute an edge for filtering
    QualityLevel quality = QualityLevel::LOW; //!< affects # of samples used for AO.
    QualityLevel lowPassFilter = QualityLevel::MEDIUM; //!< affects AO smoothness
    QualityLevel upsampling = QualityLevel::LOW; //!< affects AO buffer upsampling quality
    bool enabled = false;    //!< enables or disables screen-space ambient occlusion
    bool bentNormals = false; //!< enables bent normals computation from AO, and specular AO
    float minHorizonAngleRad = 0.0f;  //!< min angle in radian to consider
    struct Ssct {
        float lightConeRad = 1.0f;       //!< full cone angle in radian, between 0 and pi/2
        float shadowDistance = 0.3f;     //!< how far shadows can be cast
        float contactDistanceMax = 1.0f; //!< max distance for contact
        float intensity = 0.8f;          //!< intensity
        math::float3 lightDirection = { 0, -1, 0 };    //!< light direction
        float depthBias = 0.01f;         //!< depth bias in world units (mitigate self shadowing)
        float depthSlopeBias = 0.01f;    //!< depth slope bias (mitigate self shadowing)
        uint8_t sampleCount = 4;         //!< tracing sample count, between 1 and 255
        uint8_t rayCount = 1;            //!< # of rays to trace, between 1 and 255
        bool enabled = false;            //!< enables or disables SSCT
    };
    Ssct ssct;                           // %codegen_skip_javascript% %codegen_java_flatten%
};

struct MultiSampleAntiAliasingOptions {
    bool enabled = false;           //!< enables or disables msaa

    uint8_t sampleCount = 4;

    bool customResolve = false;
};

struct TemporalAntiAliasingOptions {
    float filterWidth = 1.0f;   //!< reconstruction filter width typically between 0.2 (sharper, aliased) and 1.5 (smoother)
    float feedback = 0.12f;     //!< history feedback, between 0 (maximum temporal AA) and 1 (no temporal AA).
    float lodBias = -1.0f;      //!< texturing lod bias (typically -1 or -2)
    float sharpness = 0.0f;     //!< post-TAA sharpen, especially useful when upscaling is true.
    bool enabled = false;       //!< enables or disables temporal anti-aliasing
    bool upscaling = false;     //!< 4x TAA upscaling. Disables Dynamic Resolution. [BETA]

    enum class BoxType : uint8_t {
        AABB,           //!< use an AABB neighborhood
        VARIANCE,       //!< use the variance of the neighborhood (not recommended)
        AABB_VARIANCE   //!< use both AABB and variance
    };

    enum class BoxClipping : uint8_t {
        ACCURATE,       //!< Accurate box clipping
        CLAMP,          //!< clamping
        NONE            //!< no rejections (use for debugging)
    };

    enum class JitterPattern : uint8_t {
        RGSS_X4,             //!  4-samples, rotated grid sampling
        UNIFORM_HELIX_X4,    //!  4-samples, uniform grid in helix sequence
        HALTON_23_X8,        //!  8-samples of halton 2,3
        HALTON_23_X16,       //! 16-samples of halton 2,3
        HALTON_23_X32        //! 32-samples of halton 2,3
    };

    bool filterHistory = true;      //!< whether to filter the history buffer
    bool filterInput = true;        //!< whether to apply the reconstruction filter to the input
    bool useYCoCg = false;          //!< whether to use the YcoCg color-space for history rejection
    BoxType boxType = BoxType::AABB;            //!< type of color gamut box
    BoxClipping boxClipping = BoxClipping::ACCURATE;     //!< clipping algorithm
    JitterPattern jitterPattern = JitterPattern::HALTON_23_X16; //! Jitter Pattern
    float varianceGamma = 1.0f; //! High values increases ghosting artefact, lower values increases jittering, range [0.75, 1.25]

    bool preventFlickering = false;     //!< adjust the feedback dynamically to reduce flickering
    bool historyReprojection = true;    //!< whether to apply history reprojection (debug option)
};

struct ScreenSpaceReflectionsOptions {
    float thickness = 0.1f;     //!< ray thickness, in world units
    float bias = 0.01f;         //!< bias, in world units, to prevent self-intersections
    float maxDistance = 3.0f;   //!< maximum distance, in world units, to raycast
    float stride = 2.0f;        //!< stride, in texels, for samples along the ray.
    bool enabled = false;
};

struct GuardBandOptions {
    bool enabled = false;
};

enum class AntiAliasing : uint8_t {
    NONE,   //!< no anti aliasing performed as part of post-processing
    FXAA    //!< FXAA is a low-quality but very efficient type of anti-aliasing. (default).
};

enum class Dithering : uint8_t {
    NONE,       //!< No dithering
    TEMPORAL    //!< Temporal dithering (default)
};

enum class ShadowType : uint8_t {
    PCF,        //!< percentage-closer filtered shadows (default)
    VSM,        //!< variance shadows
    DPCF,       //!< PCF with contact hardening simulation
    PCSS,       //!< PCF with soft shadows and contact hardening
    PCFd,       // for debugging only, don't use.
};

struct VsmShadowOptions {
    uint8_t anisotropy = 0;

    bool mipmapping = false;

    uint8_t msaaSamples = 1;

    bool highPrecision = false;

    float minVarianceScale = 0.5f;

    float lightBleedReduction = 0.15f;
};

struct SoftShadowOptions {
    float penumbraScale = 1.0f;

    float penumbraRatioScale = 1.0f;
};

struct StereoscopicOptions {
    bool enabled = false;
};

} // namespace filament

#endif //TNT_FILAMENT_OPTIONS_H

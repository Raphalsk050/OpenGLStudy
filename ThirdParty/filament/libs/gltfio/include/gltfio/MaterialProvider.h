
#ifndef GLTFIO_MATERIALPROVIDER_H
#define GLTFIO_MATERIALPROVIDER_H

#include <filament/Engine.h>
#include <filament/Material.h>
#include <filament/MaterialInstance.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <array>
#include <string>

namespace filament::gltfio {

enum class AlphaMode : uint8_t {
    OPAQUE,
    MASK,
    BLEND
};

// The following struct gets hashed so all padding bits should be explicit.
// Tell the compiler to emit a warning if it adds any padding.
UTILS_WARNING_PUSH
UTILS_WARNING_ENABLE_PADDED

struct alignas(4) MaterialKey {
    // -- 32 bit boundary --
    bool doubleSided : 1;
    bool unlit : 1;
    bool hasVertexColors : 1;
    bool hasBaseColorTexture : 1;
    bool hasNormalTexture : 1;
    bool hasOcclusionTexture : 1;
    bool hasEmissiveTexture : 1;
    bool useSpecularGlossiness : 1;
    AlphaMode alphaMode : 4;
    bool enableDiagnostics : 4;
    union {
        struct {
            bool hasMetallicRoughnessTexture : 1;
            uint8_t metallicRoughnessUV : 7;
        };
        struct {
            bool hasSpecularGlossinessTexture : 1;
            uint8_t specularGlossinessUV : 7;
        };
    };
    uint8_t baseColorUV;
    // -- 32 bit boundary --
    bool hasClearCoatTexture : 1;
    uint8_t clearCoatUV : 7;
    bool hasClearCoatRoughnessTexture : 1;
    uint8_t clearCoatRoughnessUV : 7;
    bool hasClearCoatNormalTexture : 1;
    uint8_t clearCoatNormalUV : 7;
    bool hasClearCoat : 1;
    bool hasTransmission : 1;
    bool hasTextureTransforms : 6;
    // -- 32 bit boundary --
    uint8_t emissiveUV;
    uint8_t aoUV;
    uint8_t normalUV;
    bool hasTransmissionTexture : 1;
    uint8_t transmissionUV : 7;
    // -- 32 bit boundary --
    bool hasSheenColorTexture : 1;
    uint8_t sheenColorUV : 7;
    bool hasSheenRoughnessTexture : 1;
    uint8_t sheenRoughnessUV : 7;
    bool hasVolumeThicknessTexture : 1;
    uint8_t volumeThicknessUV : 7;
    bool hasSheen : 1;
    bool hasIOR : 1;
    bool hasVolume : 1;
    bool hasSpecular : 1;
    bool hasSpecularTexture : 1;
    bool hasSpecularColorTexture : 1;
    bool padding : 2;
    // -- 32 bit boundary --
    uint8_t specularTextureUV;
    uint8_t specularColorTextureUV;
    uint16_t padding2;
};

static_assert(sizeof(MaterialKey) == 20, "MaterialKey has unexpected size.");

UTILS_WARNING_POP

bool operator==(const MaterialKey& k1, const MaterialKey& k2);

// Define a mapping from a uv set index in the source asset to one of Filament's uv sets.
enum UvSet : uint8_t { UNUSED, UV0, UV1 };
constexpr int UvMapSize = 8;
using UvMap = std::array<UvSet, UvMapSize>;

inline uint8_t getNumUvSets(const UvMap& uvmap) {
    return std::max({
        uvmap[0], uvmap[1], uvmap[2], uvmap[3],
        uvmap[4], uvmap[5], uvmap[6], uvmap[7],
    });
};

class UTILS_PUBLIC MaterialProvider {
public:
    virtual ~MaterialProvider() {}

    virtual MaterialInstance* createMaterialInstance(MaterialKey* config, UvMap* uvmap,
            const char* label = "material", const char* extras = nullptr) = 0;

    virtual Material* getMaterial(MaterialKey* config, UvMap* uvmap,
            const char* label = "material") { return nullptr; }

    virtual const Material* const* getMaterials() const noexcept = 0;

    virtual size_t getMaterialsCount() const noexcept = 0;

    virtual void destroyMaterials() = 0;

    virtual bool needsDummyData(VertexAttribute attrib) const noexcept = 0;
};

void constrainMaterial(MaterialKey* key, UvMap* uvmap);

void processShaderString(std::string* shader, const UvMap& uvmap,
        const MaterialKey& config);

UTILS_PUBLIC
MaterialProvider* createJitShaderProvider(Engine* engine, bool optimizeShaders = false);

UTILS_PUBLIC
MaterialProvider* createUbershaderProvider(Engine* engine, const void* archive,
        size_t archiveByteCount);

} // namespace filament::gltfio

#endif // GLTFIO_MATERIALPROVIDER_H

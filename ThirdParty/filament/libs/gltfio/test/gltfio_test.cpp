
#include <gtest/gtest.h>

#include <backend/PixelBufferDescriptor.h>

#include <filament/Engine.h>
#include <filament/MaterialEnums.h>
#include <filament/RenderableManager.h>
#include <filament/TransformManager.h>

#include <gltfio/AssetLoader.h>
#include <gltfio/FilamentAsset.h>
#include <gltfio/ResourceLoader.h>
#include <gltfio/TextureProvider.h>
#include <gltfio/math.h>
#include "third_party/filament/libs/math/include/math/mathfwd.h"
#include "third_party/filament/libs/utils/include/utils/EntityManager.h"
#include "third_party/filament/libs/utils/include/utils/NameComponentManager.h"
#include "third_party/filament/libs/utils/include/utils/Path.h"

#include "materials/uberarchive.h"

#include <fstream>
#include <unordered_map>

using namespace filament;
using namespace backend;
using namespace gltfio;
using namespace utils;

char const* ANIMATED_MORPH_CUBE_GLB = "AnimatedMorphCube.glb";

static std::ifstream::pos_type getFileSize(const char* filename) {
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

class glTFData {
public:
    glTFData(Path filename, Engine* engine, MaterialProvider* materialProvider,
            NameComponentManager* nameManager)
        : mAssetLoader(AssetLoader::create({engine, materialProvider, nameManager})),
          mResourceLoader(new ResourceLoader({


#ifndef GLTFIO_UTILITY_H
#define GLTFIO_UTILITY_H

#include <backend/BufferDescriptor.h>

#include "robin_map/include/tsl/robin_map.h"

#include <stdint.h>
#include <stddef.h>

struct FFilamentAsset;
struct cgltf_primitive;
struct cgltf_data;
class DracoCache;

struct cgltf_accessor;

namespace filament::gltfio {

// Referenced in ResourceLoader and AssetLoaderExtended
using BufferDescriptor = filament::backend::BufferDescriptor;
using UriDataCache = tsl::robin_map<std::string, BufferDescriptor>;
using UriDataCacheHandle = std::shared_ptr<UriDataCache>;

} // namespace filament::gltfio::utility

namespace filament::gltfio::utility {

// Functions that are shared between the original implementation and the extended implementation.
void decodeDracoMeshes(cgltf_data const* gltf, cgltf_primitive const* prim, DracoCache* dracoCache);
void decodeMeshoptCompression(cgltf_data* data);
bool primitiveHasVertexColor(cgltf_primitive* inPrim);
uint32_t computeBindingSize(cgltf_accessor const* accessor);
void convertBytesToShorts(uint16_t* dst, uint8_t const* src, size_t count);
uint32_t computeBindingOffset(cgltf_accessor const* accessor);
bool requiresConversion(cgltf_accessor const* accessor);
bool requiresPacking(cgltf_accessor const* accessor);
bool loadCgltfBuffers(cgltf_data const* gltf, char const* gltfPath,
        UriDataCacheHandle uriDataCacheHandle);

} // namespace filament::gltfio::utility

#endif

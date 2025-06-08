
#ifndef MATDBG_SHADERINFO_H
#define MATDBG_SHADERINFO_H

#include <backend/DriverEnums.h>

#include <filaflat/ChunkContainer.h>
#include <filaflat/MaterialChunk.h>

#include <private/filament/Variant.h>

namespace filament {
namespace matdbg {

struct ShaderInfo {
    backend::ShaderModel shaderModel;
    Variant variant;
    backend::ShaderStage pipelineStage;
    uint32_t offset;
};

size_t getShaderCount(const filaflat::ChunkContainer& container, filamat::ChunkType type);
bool getShaderInfo(const filaflat::ChunkContainer& container, ShaderInfo* info, filamat::ChunkType chunkType);

} // namespace matdbg
} // namespace filament

#endif  // MATDBG_SHADERINFO_H

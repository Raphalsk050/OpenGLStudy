
#include <matdbg/ShaderInfo.h>

#include <filaflat/ChunkContainer.h>
#include <filaflat/DictionaryReader.h>
#include <filaflat/MaterialChunk.h>
#include <filaflat/Unflattener.h>

#include <filament/MaterialChunkType.h>
#include <filament/MaterialEnums.h>

#include <backend/DriverEnums.h>

namespace filament::matdbg {

using namespace backend;
using namespace filaflat;
using namespace filamat;
using namespace utils;

size_t getShaderCount(const ChunkContainer& container, ChunkType type) {
    if (!container.hasChunk(type)) {
        return 0;
    }

    auto [start, end] = container.getChunkRange(type);
    Unflattener unflattener(start, end);

    uint64_t shaderCount = 0;
    if (!unflattener.read(&shaderCount) || shaderCount == 0) {
        return 0;
    }
    return shaderCount;
}


bool getShaderInfo(const ChunkContainer& container, ShaderInfo* info, ChunkType chunkType) {
    if (!container.hasChunk(chunkType)) {
        return true;
    }

    auto [start, end] = container.getChunkRange(chunkType);
    Unflattener unflattener(start, end);

    uint64_t shaderCount = 0;
    if (!unflattener.read(&shaderCount) || shaderCount == 0) {
        return false;
    }

    for (uint64_t i = 0; i < shaderCount; i++) {
        uint8_t shaderModelValue;
        Variant variant;
        uint8_t pipelineStageValue;
        uint32_t offsetValue;

        if (!unflattener.read(&shaderModelValue)) {
            return false;
        }

        if (!unflattener.read(&variant)) {
            return false;
        }

        if (!unflattener.read(&pipelineStageValue)) {
            return false;
        }

        if (!unflattener.read(&offsetValue)) {
            return false;
        }

        *info++ = {
            .shaderModel = ShaderModel(shaderModelValue),
            .variant = variant,
            .pipelineStage = ShaderStage(pipelineStageValue),
            .offset = offsetValue
        };
    }
    return true;
}

} // namespace filament

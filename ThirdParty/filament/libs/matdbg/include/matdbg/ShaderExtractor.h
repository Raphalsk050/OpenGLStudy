
#ifndef MATDBG_SHADEREXTRACTOR_H
#define MATDBG_SHADEREXTRACTOR_H

#include <filaflat/ChunkContainer.h>
#include <filaflat/MaterialChunk.h>

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/CString.h"

namespace filament {
namespace matdbg {

// ShaderExtractor is a utility class for extracting shader source from a material package. It works
// in a manner similar to ShaderReplacer.
class ShaderExtractor {
public:
    ShaderExtractor(backend::ShaderLanguage target, const void* data, size_t size);
    bool parse() noexcept;
    bool getShader(backend::ShaderModel shaderModel,
            Variant variant, backend::ShaderStage stage, filaflat::ShaderContent& shader) noexcept;
    bool getDictionary(filaflat::BlobDictionary& dictionary) noexcept;

    static utils::CString spirvToGLSL(backend::ShaderModel shaderModel, const uint32_t* data,
            size_t wordCount);
    static utils::CString spirvToText(const uint32_t* data, size_t wordCount);

private:
    filaflat::ChunkContainer mChunkContainer;
    filaflat::MaterialChunk mMaterialChunk;
    filamat::ChunkType mMaterialTag = filamat::ChunkType::Unknown;
    filamat::ChunkType mDictionaryTag = filamat::ChunkType::Unknown;
};

} // namespace matdbg
} // namespace filament

#endif  // MATDBG_SHADEREXTRACTOR_H

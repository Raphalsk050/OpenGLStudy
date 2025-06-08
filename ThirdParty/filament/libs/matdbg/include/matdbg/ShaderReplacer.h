
#ifndef MATDBG_SHADERREPLACER_H
#define MATDBG_SHADERREPLACER_H

#include <filaflat/ChunkContainer.h>

#include <backend/DriverEnums.h>
#include "private/filament/Variant.h"

namespace filament {
namespace matdbg {

// ShaderReplacer is a utility class for replacing shader source within a material package. It works
// in a manner similar to ShaderExtractor.
class ShaderReplacer {
public:
    ShaderReplacer(backend::Backend backend, const void* data, size_t size);
    ~ShaderReplacer();
    bool replaceShaderSource(backend::ShaderModel shaderModel, Variant variant,
            backend::ShaderStage stage, const char* sourceString, size_t stringLength);
    const uint8_t* getEditedPackage() const;
    size_t getEditedSize() const;
private:
    bool replaceSpirv(backend::ShaderModel shaderModel, Variant variant,
            backend::ShaderStage stage, const char* source, size_t sourceLength);
    const backend::Backend mBackend;
    filaflat::ChunkContainer mOriginalPackage;
    filaflat::ChunkContainer* mEditedPackage = nullptr;
    filamat::ChunkType mMaterialTag = filamat::ChunkType::Unknown;
    filamat::ChunkType mDictionaryTag = filamat::ChunkType::Unknown;
};

} // namespace matdbg
} // namespace filament

#endif  // MATDBG_SHADERREPLACER_H

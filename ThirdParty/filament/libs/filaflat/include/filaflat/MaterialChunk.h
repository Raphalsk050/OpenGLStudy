
#ifndef TNT_FILAMAT_MATERIAL_CHUNK_H
#define TNT_FILAMAT_MATERIAL_CHUNK_H

#include <filament/MaterialChunkType.h>

#include <filaflat/ChunkContainer.h>
#include <filaflat/Unflattener.h>

#include <private/filament/Variant.h>

#include "robin_map/include/tsl/robin_map.h"

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/Invocable.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

namespace filaflat {

class MaterialChunk {
public:
    using ShaderModel = filament::backend::ShaderModel;
    using ShaderStage = filament::backend::ShaderStage;
    using Variant = filament::Variant;

    explicit MaterialChunk(ChunkContainer const& container);
    ~MaterialChunk() noexcept;

    // call this once after container.parse() has been called
    bool initialize(filamat::ChunkType materialTag);

    // call this as many times as needed
    // populates "shaderContent" with the requested shader, or returns false on failure.
    bool getShader(ShaderContent& shaderContent, BlobDictionary const& dictionary,
            ShaderModel shaderModel, filament::Variant variant, ShaderStage stage);

    uint32_t getShaderCount() const noexcept;

    void visitShaders(utils::Invocable<void(ShaderModel, Variant, ShaderStage)>&& visitor) const;

    bool hasShader(ShaderModel model, Variant variant, ShaderStage stage) const noexcept;

    // These methods are for debugging purposes only (matdbg)
    // @{
    static void decodeKey(uint32_t key,
            ShaderModel* outModel, Variant* outVariant, ShaderStage* outStage);
    const tsl::robin_map<uint32_t, uint32_t>& getOffsets() const { return mOffsets; }
    // @}

private:
    ChunkContainer const& mContainer;
    filamat::ChunkType mMaterialTag = filamat::ChunkType::Unknown;
    Unflattener mUnflattener;
    const uint8_t* mBase = nullptr;
    tsl::robin_map<uint32_t, uint32_t> mOffsets;

    bool getTextShader(Unflattener unflattener,
            BlobDictionary const& dictionary, ShaderContent& shaderContent,
            ShaderModel shaderModel, filament::Variant variant, ShaderStage shaderStage);

    bool getBinaryShader(
            BlobDictionary const& dictionary, ShaderContent& shaderContent,
            ShaderModel shaderModel, filament::Variant variant, ShaderStage shaderStage);
};

} // namespace filamat

#endif // TNT_FILAMAT_MATERIAL_CHUNK_H

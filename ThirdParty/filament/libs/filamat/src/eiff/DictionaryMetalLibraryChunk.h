
#ifndef TNT_FILAMAT_DIC_METAL_LIBRARY_CHUNK_H
#define TNT_FILAMAT_DIC_METAL_LIBRARY_CHUNK_H

#include <stdint.h>
#include <vector>

#include "Chunk.h"
#include "Flattener.h"
#include "BlobDictionary.h"

namespace filamat {

class DictionaryMetalLibraryChunk final : public Chunk {
public:
    explicit DictionaryMetalLibraryChunk(BlobDictionary&& dictionary);
    ~DictionaryMetalLibraryChunk() = default;

private:
    void flatten(Flattener& f) override;

    BlobDictionary mDictionary;
    bool mStripDebugInfo;
};

} // namespace filamat

#endif // TNT_FILAMAT_DIC_METAL_LIBRARY_CHUNK_H


#include "DictionaryTextChunk.h"

namespace filamat {

DictionaryTextChunk::DictionaryTextChunk(LineDictionary&& dictionary, ChunkType chunkType) :
        Chunk(chunkType), mDictionary(std::move(dictionary)) {
}

void DictionaryTextChunk::flatten(Flattener& f) {
    // NumStrings
    f.writeUint32(mDictionary.getLineCount());

    // Strings
    for (size_t i = 0 ; i < mDictionary.getLineCount() ; i++) {
        f.writeString(mDictionary.getString(i).data());
    }
}

} // namespace filamat

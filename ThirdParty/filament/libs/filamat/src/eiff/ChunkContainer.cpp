
#include "ChunkContainer.h"
#include "Flattener.h"

namespace filamat {

// This call is relatively expensive since it performs a dry run of the flattering process,
// using a flattener that will calculate offets but will not write. It should be used only once
// when the container is about to be flattened.

size_t ChunkContainer::getSize() const {
    return flatten(Flattener::getDryRunner());
}

size_t ChunkContainer::flatten(Flattener& f) const {
    for (const auto& chunk: mChildren) {
        f.writeUint64(static_cast<uint64_t>(chunk->getType()));
        f.writeSizePlaceholder();
        chunk->flatten(f);
        f.writeSize();
    }
    return f.getBytesWritten();
}

}

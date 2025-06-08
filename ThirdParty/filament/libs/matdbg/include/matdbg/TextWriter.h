
#ifndef MATDBG_TEXTWRITER_H
#define MATDBG_TEXTWRITER_H

#include <filaflat/ChunkContainer.h>

#include "third_party/filament/libs/utils/include/utils/CString.h"

namespace filament {
namespace matdbg {

class TextWriter {
public:
    bool writeMaterialInfo(const filaflat::ChunkContainer& package);
    const char* getString() const;
    size_t getSize() const;
private:
    utils::CString mTextString;
};

} // namespace matdbg
} // namespace filament

#endif  // MATDBG_TEXTWRITER_H

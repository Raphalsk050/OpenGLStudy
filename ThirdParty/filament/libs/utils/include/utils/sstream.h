
#ifndef TNT_UTILS_SSTREAM_H
#define TNT_UTILS_SSTREAM_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include <stddef.h>

namespace utils::io {

class UTILS_PUBLIC sstream : public ostream {
public:
    ostream& flush() noexcept override;
    const char* c_str() const noexcept;
    size_t length() const noexcept;
};

} // namespace utils::io

#endif // TNT_UTILS_SSTREAM_H

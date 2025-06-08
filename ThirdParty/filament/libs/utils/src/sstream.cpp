
#include "third_party/filament/libs/utils/include/utils/sstream.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include "ostream_.h"

namespace utils::io {

utils::io::ostream& sstream::flush() noexcept {
    // no-op.
    return *this;
}

const char* sstream::c_str() const noexcept {
    char const* buffer = getBuffer().get();
    return buffer ? buffer : "";
}

size_t sstream::length() const noexcept {
    return getBuffer().length();
}

} // namespace utils::io

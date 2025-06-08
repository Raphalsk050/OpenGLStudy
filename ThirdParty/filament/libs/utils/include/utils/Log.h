
#ifndef TNT_UTILS_LOG_H
#define TNT_UTILS_LOG_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

namespace utils {

struct UTILS_PUBLIC Loggers {
    // FIL_DEBUG level logging stream
    io::ostream& d;

    // ERROR level logging stream
    io::ostream& e;

    // WARNING level logging stream
    io::ostream& w;

    // INFORMATION level logging stream
    io::ostream& i;

    // VERBOSE level logging stream
    io::ostream& v;
};

extern UTILS_PUBLIC Loggers const slog;

} // namespace utils

#endif // TNT_UTILS_LOG_H

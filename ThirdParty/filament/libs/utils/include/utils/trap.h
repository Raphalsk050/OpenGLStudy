
#ifndef TNT_UTILS_TRAP_H
#define TNT_UTILS_TRAP_H

#include <csignal>

#if defined(WIN32)
#include <Windows.h>
#include "third_party/filament/libs/utils/include/utils/unwindows.h"
#endif

namespace utils {

// This can be used as a programmatic breakpoint.
inline void debug_trap() noexcept {
#if defined(WIN32)
    DebugBreak();
#else
    std::raise(SIGINT);
#endif
}

} // namespace utils

#endif // TNT_UTILS_TRAP_H

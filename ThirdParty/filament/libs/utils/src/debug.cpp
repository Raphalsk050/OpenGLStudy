
#include "third_party/filament/libs/utils/include/utils/debug.h"

#include "third_party/filament/libs/utils/include/utils/Panic.h"

#include <cstdlib>

namespace utils {

// we use a non-inlined, not marked as "no return" function for aborting so that we can set
// a breakpoint on the call to abort() in panic() below and skip over it in the debugger if
// needed.
UTILS_NOINLINE
void abort() noexcept {
    std::abort();
}

void panic(const char *func, const char * file, int line, const char *assertion) noexcept {
    PANIC_LOG("%s:%d: failed assertion '%s'\n", file, line, assertion);
    abort(); // set a breakpoint here
    return;  // this line is needed to be able to move the cursor here in the debugger
}

} // namespace filament

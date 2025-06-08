
#ifndef TNT_UTILS_DEBUG_H
#define TNT_UTILS_DEBUG_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace utils {
UTILS_PUBLIC
void panic(const char *func, const char * file, int line, const char *assertion) noexcept;
} // namespace filament

#ifdef NDEBUG
#   define	assert_invariant(e)	((void)0)
#else
#   define	assert_invariant(e) \
            (UTILS_LIKELY(e) ? ((void)0) : utils::panic(__func__, __FILE__, __LINE__, #e))
#endif // NDEBUG

#endif // TNT_UTILS_DEBUG_H


#ifndef TNT_FILAMAT_INCLUDES_H
#define TNT_FILAMAT_INCLUDES_H

#include "third_party/filament/libs/utils/include/utils/CString.h"

#include <filamat/IncludeCallback.h>

#include <vector>

namespace filamat {

struct ResolveOptions {
    // If true, insert #line directives before / after each include.
    bool insertLineDirectives = false;

    // Surrounds line directives with #if defined(GL_GOOGLE_cpp_style_line_directive)
    // Some drivers may complain about the use of cpp style #line directives if they don't support
    // it.
    bool insertLineDirectiveCheck = false;

    // If true, process #include directives.
    bool resolveIncludes = true;
};

// Recursively handle all the includes inside of root.
// Returns true if all includes were handled successfully, false otherwise.
// callback may be null, in which case any #include directives found will result in a failure.
bool resolveIncludes(IncludeResult& root, IncludeCallback callback,
        const ResolveOptions& options, size_t depth = 0);

struct FoundInclude {
    utils::CString name;
    size_t startPosition;
    size_t length;
    size_t line;        // the line number the include was found on (first line is 1)
};

std::vector<FoundInclude> parseForIncludes(const utils::CString& source);

} // namespace filamat

#endif

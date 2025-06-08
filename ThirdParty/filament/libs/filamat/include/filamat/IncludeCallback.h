
#ifndef TNT_FILAMAT_INCLUDER_H
#define TNT_FILAMAT_INCLUDER_H

#include "third_party/filament/libs/utils/include/utils/CString.h"

#include <functional>

namespace filamat {

struct IncludeResult {
    // The include name of the root file, as if it were being included.
    // I.e., 'foobar.h' in the case of #include "foobar.h"
    const utils::CString includeName;

    // The following fields should be filled out by the IncludeCallback when processing an include,
    // or when calling resolveIncludes for the root file.

    // The full contents of the include file. This may contain additional, recursive include
    // directives.
    utils::CString text;

    // The line number for the first line of text (first line is 0).
    size_t lineNumberOffset = 0;

    // The name of the include file. This gets passed as "includerName" for any includes inside of
    // source. This field isn't used by the include system; it's up to the callback to give meaning
    // to this value and interpret it accordingly.  In the case of DirIncluder, this is an empty
    // string to represent the root include file, and a canonical path for subsequent included
    // files.
    utils::CString name;
};

using IncludeCallback = std::function<bool(
        const utils::CString& includedBy,
        IncludeResult& result)>;

} // namespace filamat

#endif


#ifndef TNT_DIRINCLUDER_H_
#define TNT_DIRINCLUDER_H_

#include <filamat/IncludeCallback.h>

#include "third_party/filament/libs/utils/include/utils/Path.h"

namespace matc {

// Functor callback handler used to resolve includes relative to a root include directory.
class DirIncluder {
public:
    void setIncludeDirectory(utils::Path dir) noexcept {
        assert(dir.isDirectory());
        mIncludeDirectory = dir;
    }

    bool operator()(const utils::CString& includedBy, filamat::IncludeResult& result);

private:
    utils::Path mIncludeDirectory;

};

} // namespace matc

#endif

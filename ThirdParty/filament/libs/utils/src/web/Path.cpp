
#include "third_party/filament/libs/utils/include/utils/Path.h"

namespace utils {

bool Path::mkdir() const {
    return true;
}

Path Path::getCurrentExecutable() {
    return Path("filament-wasm");
}

Path Path::getUserSettingsDirectory() {
    return Path(".");
}

} // namespace utils

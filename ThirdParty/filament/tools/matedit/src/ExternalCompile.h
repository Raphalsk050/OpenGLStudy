
#ifndef TNT_MATEDIT_EXTERNALCOMPILE_H
#define TNT_MATEDIT_EXTERNALCOMPILE_H

#include "third_party/filament/libs/utils/include/utils/Path.h"

#include <string>
#include <vector>

namespace matedit {

int externalCompile(utils::Path input, utils::Path output, bool preserveTextShaders,
        std::vector<std::string> args);

} // namespace matedit

#endif

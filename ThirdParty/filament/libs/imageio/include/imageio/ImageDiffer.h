
#include <image/LinearImage.h>

#include "third_party/filament/libs/utils/include/utils/Path.h"

namespace image {

enum class ComparisonMode {
    SKIP,
    COMPARE,
    UPDATE,
};

// Saves an image to disk or does a load-and-compare, depending on comparison mode.
// This makes it easy for unit tests to have compare / update commands.
// The passed-in image is the "result image" and the expected image is the "golden image".
void updateOrCompare(LinearImage result, const utils::Path& golden, ComparisonMode, float epsilon);

}  // namespace image

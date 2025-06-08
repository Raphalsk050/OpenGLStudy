
#include "details/Fence.h"

namespace filament {

using namespace backend;

FenceStatus Fence::waitAndDestroy(Fence* fence, Mode mode) {
    return FFence::waitAndDestroy(downcast(fence), mode);
}

FenceStatus Fence::wait(Mode mode, uint64_t timeout) {
    return downcast(this)->wait(mode, timeout);
}

} // namespace filament

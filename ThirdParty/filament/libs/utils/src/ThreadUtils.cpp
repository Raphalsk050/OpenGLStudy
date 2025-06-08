
#include "third_party/filament/libs/utils/include/utils/ThreadUtils.h"

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace utils {

UTILS_NOINLINE
std::thread::id ThreadUtils::getThreadId() noexcept {
    return std::this_thread::get_id();
}

bool ThreadUtils::isThisThread(std::thread::id id) noexcept {
    return getThreadId() == id;
}

} // namespace utils

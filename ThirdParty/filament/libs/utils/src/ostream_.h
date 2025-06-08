
#ifndef TNT_UTILS_OSTREAM__H
#define TNT_UTILS_OSTREAM__H

#include "third_party/filament/libs/utils/include/utils/ostream.h"
#include <mutex>

namespace utils::io {

struct ostream_ {
    std::mutex mLock;
    ostream::Buffer mData;
    std::pair<ostream::ConsumerCallback, void*> mConsumer{};
    bool mShowHex = false;
};

} // utils::io

#endif // TNT_UTILS_OSTREAM__H

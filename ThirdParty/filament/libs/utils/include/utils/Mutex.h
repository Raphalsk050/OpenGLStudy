
#ifndef TNT_UTILS_MUTEX_H
#define TNT_UTILS_MUTEX_H

#if defined(__ANDROID__)
#include "third_party/filament/libs/utils/include/utils/linux/Mutex.h"
#else
#include "third_party/filament/libs/utils/include/utils/generic/Mutex.h"
#endif

#endif // TNT_UTILS_MUTEX_H


#ifndef TNT_UTILS_CONDITION_H
#define TNT_UTILS_CONDITION_H

#if defined(__ANDROID__)
#include "third_party/filament/libs/utils/include/utils/linux/Condition.h"
#else
#include "third_party/filament/libs/utils/include/utils/generic/Condition.h"
#endif

#endif // TNT_UTILS_CONDITION_H


#ifndef TNT_UTILS_SYSTRACE_H
#define TNT_UTILS_SYSTRACE_H


#define SYSTRACE_TAG_NEVER          (0)
#define SYSTRACE_TAG_ALWAYS         (1<<0)
#define SYSTRACE_TAG_FILAMENT       (1<<1)  // don't change, used in makefiles
#define SYSTRACE_TAG_JOBSYSTEM      (1<<2)


#ifndef SYSTRACE_TAG
#define SYSTRACE_TAG (SYSTRACE_TAG_ALWAYS)
#endif

// Systrace on Apple platforms is fragile and adds overhead, should only be enabled in dev builds.
#ifndef FILAMENT_APPLE_SYSTRACE
#define FILAMENT_APPLE_SYSTRACE 0
#endif

#if defined(__ANDROID__)
#include "third_party/filament/libs/utils/include/utils/android/Systrace.h"
#elif defined(__APPLE__) && FILAMENT_APPLE_SYSTRACE
#include "third_party/filament/libs/utils/include/utils/darwin/Systrace.h"
#else

#define SYSTRACE_ENABLE()
#define SYSTRACE_DISABLE()
#define SYSTRACE_CONTEXT()
#define SYSTRACE_NAME(name)
#define SYSTRACE_FRAME_ID(frame)
#define SYSTRACE_NAME_BEGIN(name)
#define SYSTRACE_NAME_END()
#define SYSTRACE_CALL()
#define SYSTRACE_ASYNC_BEGIN(name, cookie)
#define SYSTRACE_ASYNC_END(name, cookie)
#define SYSTRACE_VALUE32(name, val)
#define SYSTRACE_VALUE64(name, val)

#endif // ANDROID

#endif // TNT_UTILS_SYSTRACE_H

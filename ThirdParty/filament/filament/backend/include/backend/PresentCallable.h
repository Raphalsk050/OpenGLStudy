
//! \file

#ifndef TNT_FILAMENT_BACKEND_PRESENTCALLABLE
#define TNT_FILAMENT_BACKEND_PRESENTCALLABLE

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament::backend {

class UTILS_PUBLIC PresentCallable {
public:

    using PresentFn = void(*)(bool presentFrame, void* user);

    PresentCallable(PresentFn fn, void* user) noexcept;
    ~PresentCallable() noexcept = default;
    PresentCallable(const PresentCallable& rhs) = default;
    PresentCallable& operator=(const PresentCallable& rhs) = default;

    void operator()(bool presentFrame = true) noexcept;

private:

    PresentFn mPresentFn;
    void* mUser = nullptr;

};

using FrameFinishedCallback UTILS_DEPRECATED = void(*)(PresentCallable callable, void* user);

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_PRESENTCALLABLE


#ifndef TNT_FILAMENT_DETAILS_FENCE_H
#define TNT_FILAMENT_DETAILS_FENCE_H

#include "downcast.h"

#include <filament/Fence.h>

#include <backend/Handle.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Condition.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"

namespace filament {

class FEngine;

class FFence : public Fence {
public:
    FFence(FEngine& engine);

    void terminate(FEngine& engine) noexcept;

    FenceStatus wait(Mode mode, uint64_t timeout) noexcept;

    static FenceStatus waitAndDestroy(FFence* fence, Mode mode) noexcept;

private:
    // We assume we don't have a lot of contention of fence and have all of them
    // share a single lock/condition
    static utils::Mutex sLock;
    static utils::Condition sCondition;

    struct FenceSignal {
        explicit FenceSignal() noexcept = default;
        enum State : uint8_t { UNSIGNALED, SIGNALED, DESTROYED };
        State mState = UNSIGNALED;
        void signal(State s = SIGNALED) noexcept;
        FenceStatus wait(uint64_t timeout) noexcept;
    };

    FEngine& mEngine;
    // TODO: use custom allocator for these small objects
    std::shared_ptr<FenceSignal> mFenceSignal;
};

FILAMENT_DOWNCAST(Fence)

} // namespace filament

#endif // TNT_FILAMENT_DETAILS_FENCE_H

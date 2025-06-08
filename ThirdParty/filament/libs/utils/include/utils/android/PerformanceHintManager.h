
#ifndef TNT_UTILS_ANDROID_PERFORMANCEHINTMANAGER_H
#define TNT_UTILS_ANDROID_PERFORMANCEHINTMANAGER_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/PrivateImplementation.h"

#include <stddef.h>
#include <stdint.h>

namespace utils {

namespace details {
struct PerformanceHintManager;
} // namespace details

class UTILS_PUBLIC PerformanceHintManager :
        private PrivateImplementation<details::PerformanceHintManager> {
    friend struct details::PerformanceHintManager;
    struct SessionDetails;

public:
    class UTILS_PUBLIC Session : PrivateImplementation<SessionDetails> {
        friend class PerformanceHintManager;
        friend struct PerformanceHintManager::SessionDetails;
    public:
        Session() noexcept;
        Session(PerformanceHintManager& manager,
                int32_t const* threadIds, size_t size,
                int64_t initialTargetWorkDurationNanos) noexcept;
        ~Session() noexcept;

        Session(Session&& rhs) noexcept;
        Session& operator=(Session&& rhs) noexcept;
        Session(Session const& rhs) = delete;
        Session& operator=(Session const& rhs) = delete;

        bool isValid() const;
        int updateTargetWorkDuration(int64_t targetDurationNanos) noexcept;
        int reportActualWorkDuration(int64_t actualDurationNanos) noexcept;
    };

    // caveat: This must be called on a Java thread
    PerformanceHintManager() noexcept;
    ~PerformanceHintManager() noexcept;

    // Whether PerformanceHintManager APIs are supported (which doesn't mean PerformanceHintManager
    // itself is, use isValid()).
    static bool isSupported() noexcept;

    // Whether PerformanceHintManager can be used.
    bool isValid() const;

    int64_t getPreferredUpdateRateNanos() const noexcept;
};

} // namespace utils

#endif //TNT_UTILS_ANDROID_PERFORMANCEHINTMANAGER_H

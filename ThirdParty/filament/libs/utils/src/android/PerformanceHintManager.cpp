
#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/android/PerformanceHintManager.h"

#include <android/performance_hint.h>
#include <android/api-level.h>

#include <stddef.h>
#include <stdint.h>

#define UTILS_PRIVATE_IMPLEMENTATION_NON_COPYABLE
#include "third_party/filament/libs/utils/include/utils/PrivateImplementation-impl.h"

namespace utils {

namespace details {
struct PerformanceHintManager {
    APerformanceHintManager* mManager = nullptr;
};
} // namespace details


struct PerformanceHintManager::SessionDetails {
    APerformanceHintSession* mSession = nullptr;
};

PerformanceHintManager::PerformanceHintManager() noexcept {
    if (__builtin_available(android __ANDROID_API_T__, *)) {
        mImpl->mManager = APerformanceHint_getManager();
    }
}

PerformanceHintManager::~PerformanceHintManager() noexcept = default;

bool PerformanceHintManager::isSupported() noexcept {
    if (__builtin_available(android __ANDROID_API_T__, *)) {
        return true;
    }
    return false;
}

bool PerformanceHintManager::isValid() const {
    return mImpl->mManager != nullptr;
}

int64_t PerformanceHintManager::getPreferredUpdateRateNanos() const noexcept {
    if (__builtin_available(android __ANDROID_API_T__, *)) {
        if (UTILS_LIKELY(mImpl->mManager)) {
            return APerformanceHint_getPreferredUpdateRateNanos(mImpl->mManager);
        }
    }
    return -1;
}

// ------------------------------------------------------------------------------------------------

PerformanceHintManager::Session::Session() noexcept = default;

PerformanceHintManager::Session::Session(PerformanceHintManager& manager, int32_t const* threadIds,
        size_t size, int64_t initialTargetWorkDurationNanos) noexcept {
    if (__builtin_available(android __ANDROID_API_T__, *)) {
        if (UTILS_LIKELY(manager.isValid())) {
            mImpl->mSession = APerformanceHint_createSession(
                   manager->mManager, threadIds, size, initialTargetWorkDurationNanos);
        }
    }
}

PerformanceHintManager::Session::Session(Session&& rhs) noexcept = default;

PerformanceHintManager::Session& PerformanceHintManager::Session::operator=(Session&& rhs) noexcept  = default;

PerformanceHintManager::Session::~Session() noexcept {
    if (__builtin_available(android __ANDROID_API_T__, *)) {
        if (UTILS_LIKELY(mImpl->mSession)) {
            APerformanceHint_closeSession(mImpl->mSession);
        }
    }
}

bool PerformanceHintManager::Session::isValid() const {
    return mImpl->mSession != nullptr;
}

int PerformanceHintManager::Session::updateTargetWorkDuration(
        int64_t targetDurationNanos) noexcept {
    if (__builtin_available(android __ANDROID_API_T__, *)) {
        if (UTILS_LIKELY(mImpl->mSession)) {
            return APerformanceHint_updateTargetWorkDuration(mImpl->mSession, targetDurationNanos);
        }
    }
    return -1;
}

int PerformanceHintManager::Session::reportActualWorkDuration(
        int64_t actualDurationNanos) noexcept {
    if (__builtin_available(android __ANDROID_API_T__, *)) {
        if (UTILS_LIKELY(mImpl->mSession)) {
            return APerformanceHint_updateTargetWorkDuration(mImpl->mSession, actualDurationNanos);
        }
    }
    return -1;
}

} // namespace utils


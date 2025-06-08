
#include "third_party/filament/libs/utils/include/utils/android/ThermalManager.h"

#include <android/thermal.h>

#include <utility>

namespace utils {

ThermalManager::ThermalManager() {
    if (__builtin_available(android 30, *)) {
        mThermalManager = AThermal_acquireManager();
    }
}

ThermalManager::~ThermalManager() {
    if (__builtin_available(android 30, *)) {
        AThermal_releaseManager(mThermalManager);
    }
}

ThermalManager::ThermalManager(ThermalManager&& rhs) noexcept
        : mThermalManager(rhs.mThermalManager) {
    rhs.mThermalManager = nullptr;
}

ThermalManager& ThermalManager::operator=(ThermalManager&& rhs) noexcept {
    std::swap(mThermalManager, rhs.mThermalManager);
    return *this;
}

ThermalManager::ThermalStatus ThermalManager::getCurrentThermalStatus() const noexcept {
    if (__builtin_available(android 30, *)) {
        return (ThermalManager::ThermalStatus)AThermal_getCurrentThermalStatus(mThermalManager);
    } else {
        return ThermalStatus::NONE;
    }
}

} // namespace utils

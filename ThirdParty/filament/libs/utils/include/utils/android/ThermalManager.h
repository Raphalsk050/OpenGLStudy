
#ifndef TNT_UTILS_ANDROID_THERMALMANAGER_H
#define TNT_UTILS_ANDROID_THERMALMANAGER_H

#include <stdint.h>

struct AThermalManager;

namespace utils {

class ThermalManager {
public:
    enum class ThermalStatus : int8_t {
        ERROR = -1,
        NONE,
        LIGHT,
        MODERATE,
        SEVERE,
        CRITICAL,
        EMERGENCY,
        SHUTDOWN
    };

    ThermalManager();
    ~ThermalManager();

    // Movable
    ThermalManager(ThermalManager&& rhs) noexcept;
    ThermalManager& operator=(ThermalManager&& rhs) noexcept;

    // not copiable
    ThermalManager(ThermalManager const& rhs) = delete;
    ThermalManager& operator=(ThermalManager const& rhs) = delete;

    ThermalStatus getCurrentThermalStatus() const noexcept;

private:
    AThermalManager* mThermalManager = nullptr;
};

} // namespace utils

#endif // TNT_UTILS_ANDROID_THERMALMANAGER_H

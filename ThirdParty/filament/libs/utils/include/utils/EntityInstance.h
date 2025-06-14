
#ifndef TNT_UTILS_ENTITYINSTANCE_H
#define TNT_UTILS_ENTITYINSTANCE_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <type_traits>

#include <stdint.h>

namespace utils {

class UTILS_PUBLIC EntityInstanceBase {
public:
    using Type = uint32_t;
protected:
    Type mInstance = 0;
};

template <typename T, bool EDIT = false>
class UTILS_PUBLIC EntityInstance : public EntityInstanceBase {
public:
    // default Instance is invalid
    constexpr EntityInstance() noexcept = default;

    // check if this Instance is valid
    constexpr bool isValid() const noexcept { return mInstance != 0; }

    // Instances of same type can be copied/assigned
    constexpr EntityInstance(EntityInstance const& other) noexcept = default;
    constexpr EntityInstance& operator=(EntityInstance const& other) noexcept = default;

    // EDIT instances can be converted to "read" Instances of same type
    template <typename = std::enable_if<!EDIT>>
    constexpr explicit EntityInstance(EntityInstance<T, true> const& other) noexcept {
        mInstance = other.asValue();
    }
    template <typename = std::enable_if<!EDIT>>
    EntityInstance& operator=(EntityInstance<T, true> const& other) noexcept {
        mInstance = other.asValue();
        return *this;
    }

    // Instances can be compared
    constexpr bool operator!=(EntityInstance e) const { return mInstance != e.mInstance; }
    constexpr bool operator==(EntityInstance e) const { return mInstance == e.mInstance; }

    // Instances can be sorted
    constexpr bool operator<(EntityInstance e) const { return mInstance < e.mInstance; }
    constexpr bool operator<=(EntityInstance e) const { return mInstance <= e.mInstance; }
    constexpr bool operator>(EntityInstance e) const { return mInstance > e.mInstance; }
    constexpr bool operator>=(EntityInstance e) const { return mInstance >= e.mInstance; }

    // and we can iterate
    constexpr EntityInstance& operator++() noexcept { ++mInstance; return *this; }
    constexpr EntityInstance& operator--() noexcept { --mInstance; return *this; }
    constexpr const EntityInstance operator++(int) const noexcept { return EntityInstance{ mInstance + 1 }; }
    constexpr const EntityInstance operator--(int) const noexcept { return EntityInstance{ mInstance - 1 }; }


    // return a value for this Instance (mostly needed for debugging
    constexpr uint32_t asValue() const noexcept { return mInstance; }

    // auto convert to Type, so it can be used as an index
    constexpr operator Type() const noexcept { return mInstance; } // NOLINT(google-explicit-constructor)

    // conversion from Type so we can initialize from an index
    constexpr EntityInstance(Type value) noexcept { mInstance = value; } // NOLINT(google-explicit-constructor)
};

} // namespace utils

#endif // TNT_UTILS_ENTITYINSTANCE_H

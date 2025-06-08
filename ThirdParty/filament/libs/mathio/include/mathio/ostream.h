
#include <iosfwd>
#include "third_party/filament/libs/math/include/math/mathfwd.h"

#if __has_attribute(visibility)
#    define MATHIO_PUBLIC __attribute__((visibility("default")))
#else
#    define MATHIO_PUBLIC
#endif

namespace filament::math::details {

template<typename T> class TQuaternion;

template<typename T>
MATHIO_PUBLIC
std::ostream& operator<<(std::ostream& out, const TVec2<T>& v) noexcept;

template<typename T>
MATHIO_PUBLIC
std::ostream& operator<<(std::ostream& out, const TVec3<T>& v) noexcept;

template<typename T>
MATHIO_PUBLIC
std::ostream& operator<<(std::ostream& out, const TVec4<T>& v) noexcept;

template<typename T>
MATHIO_PUBLIC
std::ostream& operator<<(std::ostream& out, const TMat22<T>& v) noexcept;

template<typename T>
MATHIO_PUBLIC
std::ostream& operator<<(std::ostream& out, const TMat33<T>& v) noexcept;

template<typename T>
MATHIO_PUBLIC
std::ostream& operator<<(std::ostream& out, const TMat44<T>& v) noexcept;

template<typename T>
MATHIO_PUBLIC
std::ostream& operator<<(std::ostream& out, const TQuaternion<T>& v) noexcept;

}  // namespace filament::math::details

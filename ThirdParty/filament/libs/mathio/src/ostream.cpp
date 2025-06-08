
#include <mathio/ostream.h>

#include "third_party/filament/libs/math/include/math/mat2.h"
#include "third_party/filament/libs/math/include/math/mat3.h"
#include "third_party/filament/libs/math/include/math/mat4.h"

#include "third_party/filament/libs/math/include/math/vec2.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include "third_party/filament/libs/math/include/math/quat.h"
#include "third_party/filament/libs/math/include/math/half.h"

#include <iomanip>
#include <ostream>
#include <string>

namespace filament::math::details {

template<typename T>
std::ostream& printVector(std::ostream& stream, const T* data, size_t count) {
    stream << "< ";
    for (size_t i = 0; i < count - 1; i++) {
        stream << data[i] << ", ";
    }
    stream << data[count - 1] << " >";
    return stream;
}

template<typename T>
std::ostream& printMatrix(std::ostream& stream, const T* m, size_t rows, size_t cols) {
    for (size_t row = 0; row < rows; ++row) {
        if (row != 0) {
            stream << std::endl;
        }
        if (row == 0) {
            stream << "/ ";
        } else if (row == rows - 1) {
            stream << "\\ ";
        } else {
            stream << "| ";
        }
        for (size_t col = 0; col < cols; ++col) {
            stream << std::setw(10) << std::to_string(m[row + col * rows]);
        }
        if (row == 0) {
            stream << " \\";
        } else if (row == rows - 1) {
            stream << " /";
        } else {
            stream << " |";
        }
    }
    return stream;
}

template<template<typename T> class BASE, typename T>
std::ostream& printQuat(std::ostream& stream, const BASE<T>& q) {
    return stream << "< " << q.w << " + " << q.x << "i + " << q.y << "j + " << q.z << "k >";
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TVec2<T>& v) noexcept {
    return printVector(out, v.v, 2);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TVec3<T>& v) noexcept {
    return printVector(out, v.v, 3);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TVec4<T>& v) noexcept {
    return printVector(out, v.v, 4);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TMat22<T>& v) noexcept {
    return printMatrix(out, v.asArray(), 2, 2);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TMat33<T>& v) noexcept {
    return printMatrix(out, v.asArray(), 3, 3);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TMat44<T>& v) noexcept {
    return printMatrix(out, v.asArray(), 4, 4);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const TQuaternion<T>& v) noexcept {
    return printQuat(out, v);
}

template std::ostream& operator<<(std::ostream& out, const TVec2<double>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec2<float>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec2<half>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec2<uint32_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec2<int32_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec2<uint16_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec2<int16_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec2<uint8_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec2<int8_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec2<bool>& v) noexcept;

template std::ostream& operator<<(std::ostream& out, const TVec3<double>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec3<float>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec3<half>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec3<uint32_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec3<int32_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec3<uint16_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec3<int16_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec3<uint8_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec3<int8_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec3<bool>& v) noexcept;

template std::ostream& operator<<(std::ostream& out, const TVec4<double>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec4<float>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec4<half>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec4<uint32_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec4<int32_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec4<uint16_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec4<int16_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec4<uint8_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec4<int8_t>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TVec4<bool>& v) noexcept;

template std::ostream& operator<<(std::ostream& out, const TMat22<double>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TMat22<float>& v) noexcept;

template std::ostream& operator<<(std::ostream& out, const TMat33<double>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TMat33<float>& v) noexcept;

template std::ostream& operator<<(std::ostream& out, const TMat44<double>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TMat44<float>& v) noexcept;

template std::ostream& operator<<(std::ostream& out, const TQuaternion<double>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TQuaternion<float>& v) noexcept;
template std::ostream& operator<<(std::ostream& out, const TQuaternion<half>& v) noexcept;

}  // namespace filament::math::details

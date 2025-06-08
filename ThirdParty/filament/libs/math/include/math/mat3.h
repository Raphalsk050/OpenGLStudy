
#ifndef TNT_MATH_MAT3_H
#define TNT_MATH_MAT3_H

#include "third_party/filament/libs/math/include/math/compiler.h"
#include "third_party/filament/libs/math/include/math/quat.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/TMatHelpers.h"
#include "third_party/filament/libs/math/include/math/TVecHelpers.h"

#include <limits.h>
#include <stdint.h>
#include <sys/types.h>

#include <cmath>

#include <assert.h>
#include <stddef.h>

namespace filament {
namespace math {
// -------------------------------------------------------------------------------------
namespace details {

template<typename T>
class MATH_EMPTY_BASES TMat33 :
        public TVecUnaryOperators<TMat33, T>,
        public TVecComparisonOperators<TMat33, T>,
        public TVecAddOperators<TMat33, T>,
        public TMatProductOperators<TMat33, T, TVec3>,
        public TMatSquareFunctions<TMat33, T>,
        public TMatTransform<TMat33, T>,
        public TMatHelpers<TMat33, T> {
public:
    enum no_init {
        NO_INIT
    };
    typedef T value_type;
    typedef T& reference;
    typedef T const& const_reference;
    typedef size_t size_type;
    typedef TVec3<T> col_type;
    typedef TVec3<T> row_type;

    static constexpr size_t COL_SIZE = col_type::SIZE;  // size of a column (i.e.: number of rows)
    static constexpr size_t ROW_SIZE = row_type::SIZE;  // size of a row (i.e.: number of columns)
    static constexpr size_t NUM_ROWS = COL_SIZE;
    static constexpr size_t NUM_COLS = ROW_SIZE;

private:

    col_type m_value[NUM_COLS];

public:
    // array access
    inline constexpr col_type const& operator[](size_t column) const noexcept {
        assert(column < NUM_COLS);
        return m_value[column];
    }

    inline constexpr col_type& operator[](size_t column) noexcept {
        assert(column < NUM_COLS);
        return m_value[column];
    }


    constexpr explicit TMat33(no_init) noexcept {}


    constexpr TMat33() noexcept;

    template<typename U>
    constexpr explicit TMat33(U v) noexcept;

    template<typename U>
    constexpr explicit TMat33(const TVec3<U>& v) noexcept;

    template<typename U>
    constexpr explicit TMat33(const TMat33<U>& rhs) noexcept;

    template<typename A, typename B, typename C>
    constexpr TMat33(const TVec3<A>& v0, const TVec3<B>& v1, const TVec3<C>& v2) noexcept;

    template<
            typename A, typename B, typename C,
            typename D, typename E, typename F,
            typename G, typename H, typename I>
    constexpr explicit TMat33(A m00, B m01, C m02,
            D m10, E m11, F m12,
            G m20, H m21, I m22) noexcept;


    struct row_major_init {
        template<
                typename A, typename B, typename C,
                typename D, typename E, typename F,
                typename G, typename H, typename I>
        constexpr explicit row_major_init(A m00, B m01, C m02,
                D m10, E m11, F m12,
                G m20, H m21, I m22) noexcept
                : m(m00, m10, m20,
                m01, m11, m21,
                m02, m12, m22) {}

    private:
        friend TMat33;
        TMat33 m;
    };

    constexpr explicit TMat33(row_major_init c) noexcept : TMat33(std::move(c.m)) {}

    template<typename U>
    constexpr explicit TMat33(const TQuaternion<U>& q) noexcept;

    friend inline
    constexpr TMat33 orthogonalize(const TMat33& m) noexcept {
        TMat33 ret(TMat33::NO_INIT);
        ret[0] = normalize(m[0]);
        ret[2] = normalize(cross(ret[0], m[1]));
        ret[1] = normalize(cross(ret[2], ret[0]));
        return ret;
    }

    static constexpr TMat33 getTransformForNormals(const TMat33& m) noexcept {
        return matrix::cof(m);
    }

    template<typename A, typename B>
    static TMat33 lookTo(const TVec3<A>& direction, const TVec3<B>& up) noexcept;

    static constexpr TQuaternion<T> packTangentFrame(
            const TMat33& m, size_t storageSize = sizeof(int16_t)) noexcept;

    template<typename A>
    static constexpr TMat33 translation(const TVec3<A>& t) noexcept {
        TMat33 r;
        r[2] = t;
        return r;
    }

    template<typename A>
    static constexpr TMat33 scaling(const TVec3<A>& s) noexcept {
        return TMat33{ s };
    }

    template<typename A>
    static constexpr TMat33 scaling(A s) noexcept {
        return TMat33{ TVec3<T>{ s }};
    }
};

// ----------------------------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------------------------

// Since the matrix code could become pretty big quickly, we don't inline most
// operations.

template<typename T>
constexpr TMat33<T>::TMat33() noexcept
        : m_value{
        col_type(1, 0, 0),
        col_type(0, 1, 0),
        col_type(0, 0, 1) } {
}

template<typename T>
template<typename U>
constexpr TMat33<T>::TMat33(U v) noexcept
        : m_value{
        col_type(v, 0, 0),
        col_type(0, v, 0),
        col_type(0, 0, v) } {
}

template<typename T>
template<typename U>
constexpr TMat33<T>::TMat33(const TVec3<U>& v) noexcept
        : m_value{
        col_type(v[0], 0, 0),
        col_type(0, v[1], 0),
        col_type(0, 0, v[2]) } {
}

// construct from 16 scalars. Note that the arrangement
// of values in the constructor is the transpose of the matrix
// notation.
template<typename T>
template<
        typename A, typename B, typename C,
        typename D, typename E, typename F,
        typename G, typename H, typename I>
constexpr TMat33<T>::TMat33(A m00, B m01, C m02,
        D m10, E m11, F m12,
        G m20, H m21, I m22) noexcept
        : m_value{
        col_type(m00, m01, m02),
        col_type(m10, m11, m12),
        col_type(m20, m21, m22) } {
}

template<typename T>
template<typename U>
constexpr TMat33<T>::TMat33(const TMat33<U>& rhs) noexcept {
    for (size_t col = 0; col < NUM_COLS; ++col) {
        m_value[col] = col_type(rhs[col]);
    }
}

// Construct from 3 column vectors.
template<typename T>
template<typename A, typename B, typename C>
constexpr TMat33<T>::TMat33(const TVec3<A>& v0, const TVec3<B>& v1, const TVec3<C>& v2) noexcept
        : m_value{ v0, v1, v2 } {
}

template<typename T>
template<typename U>
constexpr TMat33<T>::TMat33(const TQuaternion<U>& q) noexcept : m_value{} {
    const U n = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
    const U s = n > 0 ? 2 / n : 0;
    const U x = s * q.x;
    const U y = s * q.y;
    const U z = s * q.z;
    const U xx = x * q.x;
    const U xy = x * q.y;
    const U xz = x * q.z;
    const U xw = x * q.w;
    const U yy = y * q.y;
    const U yz = y * q.z;
    const U yw = y * q.w;
    const U zz = z * q.z;
    const U zw = z * q.w;
    m_value[0] = col_type(1 - yy - zz, xy + zw, xz - yw);  // NOLINT
    m_value[1] = col_type(xy - zw, 1 - xx - zz, yz + xw);  // NOLINT
    m_value[2] = col_type(xz + yw, yz - xw, 1 - xx - yy);  // NOLINT
}

template<typename T>
constexpr T dot_tolerance() noexcept;

template<>
constexpr float dot_tolerance<float>() noexcept { return 0.999f; }

template<>
constexpr double dot_tolerance<double>() noexcept { return 0.9999; }

template<typename T>
template<typename A, typename B>
TMat33<T> TMat33<T>::lookTo(const TVec3<A>& direction, const TVec3<B>& up) noexcept {
    auto const z_axis = direction;
    auto norm_up = up;
    if (std::abs(dot(z_axis, norm_up)) > dot_tolerance< arithmetic_result_t<A, B> >()) {
        // Fix up vector if we're degenerate (looking straight up, basically)
        norm_up = { norm_up.z, norm_up.x, norm_up.y };
    }
    auto const x_axis = normalize(cross(z_axis, norm_up));
    auto const y_axis = cross(x_axis, z_axis);
    return { x_axis, y_axis, -z_axis };
}

//------------------------------------------------------------------------------
template<typename T>
constexpr TQuaternion<T> TMat33<T>::packTangentFrame(const TMat33<T>& m, size_t storageSize) noexcept {
    TQuaternion<T> q = TMat33<T>{ m[0], cross(m[2], m[0]), m[2] }.toQuaternion();
    q = positive(normalize(q));

    // Ensure w is never 0.0
    // Bias is 2^(nb_bits - 1) - 1
    const T bias = T(1.0) / T((1 << (storageSize * CHAR_BIT - 1)) - 1);
    if (q.w < bias) {
        q.w = bias;

        const T factor = (T)(std::sqrt(1.0 - (double)bias * (double)bias));
        q.xyz *= factor;
    }

    // If there's a reflection ((n x t) . b <= 0), make sure w is negative
    if (dot(cross(m[0], m[2]), m[1]) < T(0)) {
        q = -q;
    }

    return q;
}


}  // namespace details

template<typename T>
constexpr details::TMat33<T> prescaleForNormals(const details::TMat33<T>& m) noexcept {
    return m * details::TMat33<T>(
                    1.0 / std::sqrt(max(float3{length2(m[0]), length2(m[1]), length2(m[2])})));
}

// ----------------------------------------------------------------------------------------

typedef details::TMat33<double> mat3;
typedef details::TMat33<float> mat3f;

// ----------------------------------------------------------------------------------------
}  // namespace math
}  // namespace filament

namespace std {
template<typename T>
constexpr void swap(filament::math::details::TMat33<T>& lhs,
        filament::math::details::TMat33<T>& rhs) noexcept {
    // This generates much better code than the default implementation
    // It's unclear why, I believe this is due to an optimization bug in the clang.
    //
    //     filament::math::details::TMat33<T> t(lhs);
    //    lhs = rhs;
    //    rhs = t;
    //
    // clang always copy lhs on the stack, even if it's never using it (it's using the
    // copy it has in registers).

    const T t00 = lhs[0][0];
    const T t01 = lhs[0][1];
    const T t02 = lhs[0][2];
    const T t10 = lhs[1][0];
    const T t11 = lhs[1][1];
    const T t12 = lhs[1][2];
    const T t20 = lhs[2][0];
    const T t21 = lhs[2][1];
    const T t22 = lhs[2][2];

    lhs[0][0] = rhs[0][0];
    lhs[0][1] = rhs[0][1];
    lhs[0][2] = rhs[0][2];
    lhs[1][0] = rhs[1][0];
    lhs[1][1] = rhs[1][1];
    lhs[1][2] = rhs[1][2];
    lhs[2][0] = rhs[2][0];
    lhs[2][1] = rhs[2][1];
    lhs[2][2] = rhs[2][2];

    rhs[0][0] = t00;
    rhs[0][1] = t01;
    rhs[0][2] = t02;
    rhs[1][0] = t10;
    rhs[1][1] = t11;
    rhs[1][2] = t12;
    rhs[2][0] = t20;
    rhs[2][1] = t21;
    rhs[2][2] = t22;
}
}

#endif  // TNT_MATH_MAT3_H

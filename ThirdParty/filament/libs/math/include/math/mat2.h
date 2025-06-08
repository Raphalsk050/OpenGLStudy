
#ifndef TNT_MATH_MAT2_H
#define TNT_MATH_MAT2_H

#include "third_party/filament/libs/math/include/math/TMatHelpers.h"
#include "third_party/filament/libs/math/include/math/compiler.h"
#include "third_party/filament/libs/math/include/math/vec2.h"

#include <stdint.h>
#include <sys/types.h>

namespace filament {
namespace math {
// -------------------------------------------------------------------------------------
namespace details {

template<typename T>
class MATH_EMPTY_BASES TMat22 :
        public TVecUnaryOperators<TMat22, T>,
        public TVecComparisonOperators<TMat22, T>,
        public TVecAddOperators<TMat22, T>,
        public TMatProductOperators<TMat22, T, TVec2>,
        public TMatSquareFunctions<TMat22, T>,
        public TMatHelpers<TMat22, T> {
public:
    enum no_init {
        NO_INIT
    };
    typedef T value_type;
    typedef T& reference;
    typedef T const& const_reference;
    typedef size_t size_type;
    typedef TVec2<T> col_type;
    typedef TVec2<T> row_type;

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


    constexpr explicit TMat22(no_init) noexcept {}


    constexpr TMat22() noexcept ;

    template<typename U>
    constexpr explicit TMat22(U v) noexcept;

    template<typename U>
    constexpr explicit TMat22(const TVec2<U>& v) noexcept;

    template<typename U>
    constexpr explicit TMat22(const TMat22<U>& rhs) noexcept;

    template<typename A, typename B>
    constexpr TMat22(const TVec2<A>& v0, const TVec2<B>& v1) noexcept;

    template<
            typename A, typename B,
            typename C, typename D>
    constexpr explicit TMat22(A m00, B m01, C m10, D m11) noexcept ;


    struct row_major_init {
        template<typename A, typename B,
                typename C, typename D>
        constexpr explicit row_major_init(A m00, B m01, C m10, D m11) noexcept
                : m(m00, m10, m01, m11) {}

    private:
        friend TMat22;
        TMat22 m;
    };

    constexpr explicit TMat22(row_major_init c) noexcept : TMat22(std::move(c.m)) {}

    static TMat22<T> rotate(T radian) noexcept {
        TMat22<T> r(TMat22<T>::NO_INIT);
        T c = std::cos(radian);
        T s = std::sin(radian);
        r[0][0] = c;
        r[1][1] = c;
        r[0][1] = s;
        r[1][0] = -s;
        return r;
    }

    template<typename A>
    static constexpr TMat22 translation(const TVec2<A>& t) noexcept {
        TMat22 r;
        r[2] = t;
        return r;
    }

    template<typename A>
    static constexpr TMat22 scaling(const TVec2<A>& s) noexcept {
        return TMat22{ s };
    }

    template<typename A>
    static constexpr TMat22 scaling(A s) noexcept {
        return TMat22{ TVec2<T>{ s, s }};
    }
};

// ----------------------------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------------------------

// Since the matrix code could become pretty big quickly, we don't inline most
// operations.

template<typename T>
constexpr TMat22<T>::TMat22() noexcept
        : m_value{ col_type(1, 0), col_type(0, 1) } {
}

template<typename T>
template<typename U>
constexpr TMat22<T>::TMat22(U v) noexcept
        : m_value{ col_type(v, 0), col_type(0, v) } {
}

template<typename T>
template<typename U>
constexpr TMat22<T>::TMat22(const TVec2<U>& v) noexcept
        : m_value{ col_type(v[0], 0), col_type(0, v[1]) } {
}

// construct from 4 scalars. Note that the arrangement
// of values in the constructor is the transpose of the matrix
// notation.
template<typename T>
template<typename A, typename B,
        typename C, typename D>
constexpr TMat22<T>::TMat22(A m00, B m01, C m10, D m11) noexcept
        : m_value{ col_type(m00, m01), col_type(m10, m11) } {
}

template<typename T>
template<typename U>
constexpr TMat22<T>::TMat22(const TMat22<U>& rhs) noexcept {
    for (size_t col = 0; col < NUM_COLS; ++col) {
        m_value[col] = col_type(rhs[col]);
    }
}

// Construct from 2 column vectors.
template<typename T>
template<typename A, typename B>
constexpr TMat22<T>::TMat22(const TVec2<A>& v0, const TVec2<B>& v1) noexcept
        : m_value{ v0, v1 } {
}

}  // namespace details

// ----------------------------------------------------------------------------------------

typedef details::TMat22<double> mat2;
typedef details::TMat22<float> mat2f;

// ----------------------------------------------------------------------------------------
}  // namespace math
}  // namespace filament

namespace std {
template<typename T>
constexpr void swap(filament::math::details::TMat22<T>& lhs,
        filament::math::details::TMat22<T>& rhs) noexcept {
    // This generates much better code than the default implementation
    // It's unclear why, I believe this is due to an optimization bug in the clang.
    //
    //     filament::math::details::TMat22<T> t(lhs);
    //    lhs = rhs;
    //    rhs = t;
    //
    // clang always copy lhs on the stack, even if it's never using it (it's using the
    // copy it has in registers).

    const T t00 = lhs[0][0];
    const T t01 = lhs[0][1];
    const T t10 = lhs[1][0];
    const T t11 = lhs[1][1];

    lhs[0][0] = rhs[0][0];
    lhs[0][1] = rhs[0][1];
    lhs[1][0] = rhs[1][0];
    lhs[1][1] = rhs[1][1];

    rhs[0][0] = t00;
    rhs[0][1] = t01;
    rhs[1][0] = t10;
    rhs[1][1] = t11;
}
}

#endif  // TNT_MATH_MAT2_H

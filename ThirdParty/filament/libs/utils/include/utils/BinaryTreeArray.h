
#ifndef TNT_UTILS_BINARYTREEARRAY_H
#define TNT_UTILS_BINARYTREEARRAY_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <type_traits>

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

namespace utils {

class BinaryTreeArray {

    // Simple fixed capacity stack
    template<typename TYPE, size_t CAPACITY,
            typename = typename std::enable_if<std::is_trivial<TYPE>::value>::type>
    class stack {
        TYPE mElements[CAPACITY];
        size_t mSize = 0;
    public:
        bool empty() const noexcept { return mSize == 0; }
        void push(TYPE const& v) noexcept {
            assert(mSize < CAPACITY);
            mElements[mSize++] = v;
        }
        void pop() noexcept {
            assert(mSize > 0);
            --mSize;
        }
        const TYPE& back() const noexcept {
            return mElements[mSize - 1];
        }
    };

public:
    static size_t count(size_t height) noexcept { return  (1u << height) - 1; }


#ifndef TNT_UTILS_FIXEDCIRCULARBUFFER_H
#define TNT_UTILS_FIXEDCIRCULARBUFFER_H

#include "third_party/filament/libs/utils/include/utils/debug.h"

#include <memory>
#include <optional>
#include <type_traits>

#include <stddef.h>

namespace utils {

template<typename T>
class FixedCircularBuffer {
public:
    explicit FixedCircularBuffer(size_t capacity)
        : mData(std::make_unique<T[]>(capacity)), mCapacity(capacity) {}

    size_t size() const noexcept { return mSize; }
    size_t capacity() const noexcept { return mCapacity; }
    bool full() const noexcept { return mCapacity > 0 && mSize == mCapacity; }
    bool empty() const noexcept { return mSize == 0; }

    std::optional<T> push(T v) noexcept {
        if (mCapacity == 0) {
            return v;
        }
        std::optional<T> displaced = full() ? pop() : std::optional<T>{};
        mData[mEnd] = v;
        mEnd = (mEnd + 1) % mCapacity;
        mSize++;
        return displaced;
    }

    T pop() noexcept {
        assert_invariant(mSize > 0);
        T result = mData[mBegin];
        mBegin = (mBegin + 1) % mCapacity;
        mSize--;
        return result;
    }

private:
    std::unique_ptr<T[]> mData;

    size_t mBegin = 0;
    size_t mEnd = 0;
    size_t mSize = 0;
    size_t mCapacity;
};

} // namespace utils

#endif  // TNT_UTILS_FIXEDCIRCULARBUFFER_H

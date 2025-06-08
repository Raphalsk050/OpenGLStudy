
#ifndef TNT_FILAFLAT_UNFLATTENER_H
#define TNT_FILAFLAT_UNFLATTENER_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/CString.h"

#include <private/filament/Variant.h>

#include <type_traits>

#include <stdint.h>

namespace filaflat {

// Allow read operation from an Unflattenable. All READ operation MUST go through the Unflattener
// since it checks boundaries before readind. All read operations return values MUST be verified,
// never assume a read will succeed.
class UTILS_PUBLIC Unflattener {
public:
    Unflattener() noexcept = default;

    Unflattener(const uint8_t* src, const uint8_t* end)
            : mSrc(src), mCursor(src), mEnd(end) {
        assert_invariant(src && end);
    }

    Unflattener(Unflattener const& rhs) = default;

    ~Unflattener() noexcept = default;

    bool hasData() const noexcept {
        return mCursor < mEnd;
    }

    bool willOverflow(size_t size) const noexcept {
        return (mCursor + size) > mEnd;
    }

    void skipAlignmentPadding() {
        const uint8_t padSize = (8 - (intptr_t(mCursor) % 8)) % 8;
        mCursor += padSize;
        assert_invariant(0 == (intptr_t(mCursor) % 8));
    }

    template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    bool read(T* const out) noexcept {
        if (UTILS_UNLIKELY(willOverflow(sizeof(T)))) {
            return false;
        }
        auto const* const cursor = mCursor;
        mCursor += sizeof(T);
        T v = 0;
        for (size_t i = 0; i < sizeof(T); i++) {
            v |= T(cursor[i]) << (8 * i);
        }
        *out = v;
        return true;
    }

    bool read(float* f) noexcept {
        return read(reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(f)));
    }

    bool read(filament::Variant* v) noexcept {
        return read(&v->key);
    }

    bool read(utils::CString* s) noexcept;

    bool read(const char** blob, size_t* size) noexcept;

    bool read(const char** s) noexcept;

    const uint8_t* getCursor() const noexcept {
        return mCursor;
    }

    void setCursor(const uint8_t* cursor) noexcept {
        mCursor = (cursor >= mSrc && cursor < mEnd) ? cursor : mEnd;
    }

private:
    const uint8_t* mSrc = nullptr;
    const uint8_t* mCursor = nullptr;
    const uint8_t* mEnd = nullptr;
};

} //namespace filaflat

#endif // TNT_FILAFLAT_UNFLATTENER_H

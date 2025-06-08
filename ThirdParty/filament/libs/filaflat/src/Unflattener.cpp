
#include <filaflat/Unflattener.h>

namespace filaflat {

bool Unflattener::read(const char** blob, size_t* size) noexcept {
    uint64_t nbytes;
    if (!read(&nbytes)) {
        return false;
    }
    const uint8_t* start = mCursor;
    mCursor += nbytes;
    bool const overflowed = mCursor > mEnd;
    if (!overflowed) {
        *blob = (const char*)start;
        *size = nbytes;
    }
    return !overflowed;
}

bool Unflattener::read(utils::CString* const s) noexcept {
    const uint8_t* const start = mCursor;
    const uint8_t* const last = mEnd;
    const uint8_t* curr = start;
    while (curr < last && *curr != '\0') {
        curr++;
    }
    bool const overflowed = start >= last;
    if (UTILS_LIKELY(!overflowed)) {
        *s = utils::CString{ (const char*)start, utils::CString::size_type(curr - start) };
        curr++;
    }
    mCursor = curr;
    return !overflowed;
}

bool Unflattener::read(const char** const s) noexcept {
    const uint8_t* const start = mCursor;
    const uint8_t* const last = mEnd;
    const uint8_t* curr = start;
    while (curr < last && *curr != '\0') {
        curr++;
    }
    bool const overflowed = start >= last;
    if (UTILS_LIKELY(!overflowed)) {
        *s = (char const*)start;
        curr++;
    }
    mCursor = curr;
    return !overflowed;
}

}

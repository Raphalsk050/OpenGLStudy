
#ifndef UTILS_CALLSTACK_H
#define UTILS_CALLSTACK_H

#include <stddef.h>
#include <stdint.h>
#include <typeinfo>

#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

namespace utils {

class CallStack {
public:
    CallStack() = default;
    CallStack(const CallStack&) = default;
    ~CallStack() = default;

    static CallStack unwind(size_t ignore = 0) noexcept;

    void update(size_t ignore = 0) noexcept;

    size_t getFrameCount() const noexcept;

    intptr_t operator [](size_t index) const;

    friend utils::io::ostream& operator <<(utils::io::ostream& stream, const CallStack& callstack);

    bool operator <(const CallStack& rhs) const;

    inline bool operator >(const CallStack& rhs) const {
        return rhs < *this;
    }

    inline bool operator !=(const CallStack& rhs) const {
        return *this < rhs || rhs < *this;
    }

    inline bool operator >=(const CallStack& rhs) const {
        return !operator <(rhs);
    }

    inline bool operator <=(const CallStack& rhs) const {
        return !operator >(rhs);
    }

    inline bool operator ==(const CallStack& rhs) const {
        return !operator !=(rhs);
    }

private:
    void update_gcc(size_t ignore) noexcept;

    static utils::CString demangle(const char* mangled);

    static constexpr size_t NUM_FRAMES = 20;

    struct StackFrameInfo {
        intptr_t pc;
    };

    size_t m_frame_count = 0;
    StackFrameInfo m_stack[NUM_FRAMES];
};

} // namespace utils

#endif // UTILS_CALLSTACK_H

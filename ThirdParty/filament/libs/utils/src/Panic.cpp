
#include "third_party/filament/libs/utils/include/utils/Panic.h"

#include "ostream_.h"

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Log.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cstdlib>
#include <cstring>
#include <mutex>
#include <new>
#include <string>
#include <string_view>
#include <utility>

namespace utils {

// ------------------------------------------------------------------------------------------------

class UserPanicHandler {
    struct CallBack {
        Panic::PanicHandlerCallback handler = nullptr;
        void* user = nullptr;
        void call(Panic const& panic) const noexcept {
            if (UTILS_UNLIKELY(handler)) {
                handler(user, panic);
            }
        }
    };

    mutable std::mutex mLock{};
    CallBack mCallBack{};

    CallBack getCallback() const noexcept {
        std::lock_guard const lock(mLock);
        return mCallBack;
    }

public:
    static UserPanicHandler& get() noexcept {
        static UserPanicHandler data;
        return data;
    }

    void call(Panic const& panic) const noexcept {
        getCallback().call(panic);
    }

    void set(Panic::PanicHandlerCallback handler, void* user) noexcept {
        std::lock_guard const lock(mLock);
        mCallBack = { handler, user };
    }
};

// ------------------------------------------------------------------------------------------------

UTILS_NOINLINE
static std::string sprintfToString(const char* format, va_list args) noexcept {
    std::string s;
    va_list tmp;
    va_copy(tmp, args);
    int n = vsnprintf(nullptr, 0, format, tmp);
    va_end(tmp);

    if (n >= 0) {
        ++n; // for the nul-terminating char
        char* const buf = new(std::nothrow) char[n];
        if (buf) {
            vsnprintf(buf, size_t(n), format, args);
            s.assign(buf);
            delete [] buf;
        }
    }
    return s;
}

static inline std::string sprintfToString(const char* format, ...) noexcept {
    va_list args;
    va_start(args, format);
    std::string const s{ sprintfToString(format, args) };
    va_end(args);
    return s;
}

static std::string buildPanicString(
        std::string_view const& msg, const char* function, int line,
        const char* file, const char* reason) {
#ifndef NDEBUG
    return sprintfToString("%.*s\nin %s:%d\nin file %s\nreason: %s",
            msg.size(), msg.data(), function, line, file, reason);
#else
    return sprintfToString("%.*s\nin %s:%d\nreason: %s",
            msg.size(), msg.data(), function, line, reason);
#endif
}

// ------------------------------------------------------------------------------------------------

Panic::~Panic() noexcept = default;

void Panic::setPanicHandler(PanicHandlerCallback handler, void* user) noexcept {
    UserPanicHandler::get().set(handler, user);
}

// ------------------------------------------------------------------------------------------------

template<typename T>
TPanic<T>::TPanic(const char* function, const char* file, int line, char const* literal,
        std::string reason)
        : mFile(file),
          mFunction(function),
          mLine(line),
          mLiteral(literal),
          mReason(std::move(reason)) {
    mCallstack.update(1);
    mWhat = buildPanicString(T::type, mFunction, mLine, mFile, mReason.c_str());
}

template<typename T>
TPanic<T>::~TPanic() = default;

template<typename T>
const char* TPanic<T>::what() const noexcept {
    return mWhat.c_str();
}

template<typename T>
const char* TPanic<T>::getType() const noexcept {
    return T::type;
}

template<typename T>
const char* TPanic<T>::getReason() const noexcept {
    return mReason.c_str();
}

template<typename T>
const char* TPanic<T>::getReasonLiteral() const noexcept {
    return mLiteral.c_str();
}

template<typename T>
const char* TPanic<T>::getFunction() const noexcept {
    return mFunction;
}

template<typename T>
const char* TPanic<T>::getFile() const noexcept {
    return mFile;
}

template<typename T>
int TPanic<T>::getLine() const noexcept {
    return mLine;
}

template<typename T>
const CallStack& TPanic<T>::getCallStack() const noexcept {
    return mCallstack;
}

template<typename T>
void TPanic<T>::log() const noexcept {
    slog.e << what() << io::endl;
    slog.e << mCallstack << io::endl;
}

UTILS_ALWAYS_INLINE
inline static const char* formatFile(char const* file) noexcept {
    const char * p = std::strstr(file, "filament/");
    return p ? p : file;
}

template<typename T>
void TPanic<T>::panic(char const* function, char const* file, int line, char const* literal,
        const char* format, ...) {
    va_list args;
    va_start(args, format);
    std::string reason{ sprintfToString(format, args) };
    va_end(args);

    panic(function, file, line, literal, std::move(reason));
}

template<typename T>
void TPanic<T>::panic(char const* function, char const* file, int line, char const* literal,
        std::string reason) {

    if (reason.empty()) {
        reason = literal;
    }

    T e(function, formatFile(file), line, literal, std::move(reason));

    // always log the Panic at the point it is detected
    e.log();

    // Call the user provided handler
    UserPanicHandler::get().call(e);

    // if exceptions are enabled, throw now.
#ifdef __EXCEPTIONS
    throw e;
#endif

    // and finally abort if we somehow get here
    std::abort();
}

// -----------------------------------------------------------------------------------------------

namespace details {

void panicLog(char const* function, char const* file, int line, const char* format, ...) noexcept {
    va_list args;
    va_start(args, format);
    std::string const reason{ sprintfToString(format, args) };
    va_end(args);

    std::string const msg = buildPanicString("PanicLog",
            function, line, file, reason.c_str());

    slog.e << msg << io::endl;
    slog.e << CallStack::unwind(1) << io::endl;
}

PanicStream::PanicStream(
        char const* function,
        char const* file,
        int line,
        char const* condition) noexcept
        : mFunction(function), mFile(file), mLine(line), mLiteral(condition) {
}

PanicStream::~PanicStream() = default;

PanicStream& PanicStream::operator<<(short value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(unsigned short value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(char value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(unsigned char value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(int value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(unsigned int value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(long value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(unsigned long value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(long long int value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(unsigned long long int value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(float value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(double value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(long double value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(bool value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(void const* value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(char const* value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(unsigned char const* value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(std::string const& value) noexcept {
    mStream << value;
    return *this;
}

PanicStream& PanicStream::operator<<(std::string_view const& value) noexcept {
    mStream << value;
    return *this;
}

} // namespace details

// -----------------------------------------------------------------------------------------------

template class UTILS_PUBLIC TPanic<PreconditionPanic>;
template class UTILS_PUBLIC TPanic<PostconditionPanic>;
template class UTILS_PUBLIC TPanic<ArithmeticPanic>;

} // namespace utils

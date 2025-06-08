
#ifndef TNT_UTILS_PANIC_H
#define TNT_UTILS_PANIC_H

#ifdef FILAMENT_PANIC_USES_ABSL
#   if FILAMENT_PANIC_USES_ABSL
#       include "absl/log/log.h"
#       define  FILAMENT_CHECK_PRECONDITION      CHECK
#       define  FILAMENT_CHECK_POSTCONDITION     CHECK
#       define  FILAMENT_CHECK_ARITHMETIC        CHECK
#   endif
#endif

#include "third_party/filament/libs/utils/include/utils/CallStack.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/sstream.h"

#include <string>
#include <string_view>

#ifdef __EXCEPTIONS
#   define UTILS_EXCEPTIONS 1
#else
#   ifdef UTILS_EXCEPTIONS
#       error  UTILS_EXCEPTIONS is already defined!
#   endif
#endif


namespace utils {

// -----------------------------------------------------------------------------------------------

class UTILS_PUBLIC Panic {
public:

    using PanicHandlerCallback = void(*)(void* user, Panic const& panic);

    static void setPanicHandler(PanicHandlerCallback handler, void* user) noexcept;


    virtual ~Panic() noexcept;

    virtual const char* what() const noexcept = 0;

    virtual const char* getType() const noexcept = 0;

    virtual const char* getReason() const noexcept = 0;

    virtual const char* getReasonLiteral() const noexcept = 0;

    virtual const char* getFunction() const noexcept = 0;

    virtual const char* getFile() const noexcept = 0;

    virtual int getLine() const noexcept = 0;

    virtual const CallStack& getCallStack() const noexcept = 0;

    virtual void log() const noexcept = 0;
};

// -----------------------------------------------------------------------------------------------

template <typename T>
class UTILS_PUBLIC TPanic : public Panic {
public:
    // std::exception protocol
    const char* what() const noexcept override;

    // Panic interface
    const char* getType() const noexcept override;
    const char* getReason() const noexcept override;
    const char* getReasonLiteral() const noexcept override;
    const char* getFunction() const noexcept override;
    const char* getFile() const noexcept override;
    int getLine() const noexcept override;
    const CallStack& getCallStack() const noexcept override;
    void log() const noexcept override;

    static void panic(char const* function, char const* file, int line, char const* literal,
            const char* format, ...) UTILS_NORETURN;

    static inline void panic(
            char const* function, char const* file, int line, char const* literal,
            std::string reason) UTILS_NORETURN;

protected:

    TPanic(char const* function, char const* file, int line, char const* literal,
            std::string reason);

    ~TPanic() override;

private:
    void buildMessage();

    char const* const mFile = nullptr;      // file where the panic happened
    char const* const mFunction = nullptr;  // function where the panic happened
    int const mLine = -1;                   // line where the panic happened
    std::string mLiteral;                   // reason for the panic, built only from literals
    std::string mReason;                    // reason for the panic
    mutable std::string mWhat;              // fully formatted reason
    CallStack mCallstack;
};

namespace details {
// these are private, don't use
void panicLog(
        char const* function, char const* file, int line, const char* format, ...) noexcept;
}  // namespace details

// -----------------------------------------------------------------------------------------------

class UTILS_PUBLIC PreconditionPanic : public TPanic<PreconditionPanic> {
    // Programming error, can be avoided
    // e.g.: invalid arguments
    using TPanic<PreconditionPanic>::TPanic;
    friend class TPanic<PreconditionPanic>;
    constexpr static auto type = "Precondition";
};

class UTILS_PUBLIC PostconditionPanic : public TPanic<PostconditionPanic> {
    // Usually only detectable at runtime
    // e.g.: dead-lock would occur, arithmetic errors
    using TPanic<PostconditionPanic>::TPanic;
    friend class TPanic<PostconditionPanic>;
    constexpr static auto type = "Postcondition";
};

class UTILS_PUBLIC ArithmeticPanic : public TPanic<ArithmeticPanic> {
    // A common case of post-condition error
    // e.g.: underflow, overflow, internal computations errors
    using TPanic<ArithmeticPanic>::TPanic;
    friend class TPanic<ArithmeticPanic>;
    constexpr static auto type = "Arithmetic";
};

namespace details {

struct Voidify final {
    template<typename T>
    void operator&&(const T&) const&& {}
};

class UTILS_PUBLIC PanicStream {
public:
    PanicStream(
            char const* function,
            char const* file,
            int line,
            char const* message) noexcept;

    ~PanicStream();

    PanicStream& operator<<(short value) noexcept;
    PanicStream& operator<<(unsigned short value) noexcept;

    PanicStream& operator<<(char value) noexcept;
    PanicStream& operator<<(unsigned char value) noexcept;

    PanicStream& operator<<(int value) noexcept;
    PanicStream& operator<<(unsigned int value) noexcept;

    PanicStream& operator<<(long value) noexcept;
    PanicStream& operator<<(unsigned long value) noexcept;

    PanicStream& operator<<(long long value) noexcept;
    PanicStream& operator<<(unsigned long long value) noexcept;

    PanicStream& operator<<(float value) noexcept;
    PanicStream& operator<<(double value) noexcept;
    PanicStream& operator<<(long double value) noexcept;

    PanicStream& operator<<(bool value) noexcept;

    PanicStream& operator<<(const void* value) noexcept;

    PanicStream& operator<<(const char* string) noexcept;
    PanicStream& operator<<(const unsigned char* string) noexcept;

    PanicStream& operator<<(std::string const& s) noexcept;
    PanicStream& operator<<(std::string_view const& s) noexcept;

protected:
    io::sstream mStream;
    char const* mFunction;
    char const* mFile;
    int mLine;
    char const* mLiteral;
};

template<typename T>
class TPanicStream : public PanicStream {
public:
    using PanicStream::PanicStream;
    ~TPanicStream() noexcept(false) UTILS_NORETURN {
        T::panic(mFunction, mFile, mLine, mLiteral, mStream.c_str());
    }
};

} // namespace details

// -----------------------------------------------------------------------------------------------
}  // namespace utils

#ifndef NDEBUG
#   define PANIC_FILE(F) (F)
#   define PANIC_FUNCTION __PRETTY_FUNCTION__
#else
#   define PANIC_FILE(F) ""
#   define PANIC_FUNCTION __func__
#endif


#define FILAMENT_CHECK_CONDITION_IMPL(cond)                                                        \
    switch (0)                                                                                     \
    case 0:                                                                                        \
    default:                                                                                       \
        UTILS_LIKELY(cond) ? (void)0 : ::utils::details::Voidify()&&

#define FILAMENT_PANIC_IMPL(message, TYPE)                                                         \
        ::utils::details::TPanicStream<::utils::TYPE>(PANIC_FUNCTION, PANIC_FILE(__FILE__), __LINE__, message)

#ifndef FILAMENT_CHECK_PRECONDITION
#define FILAMENT_CHECK_PRECONDITION(condition)                                                     \
    FILAMENT_CHECK_CONDITION_IMPL(condition)  FILAMENT_PANIC_IMPL(#condition, PreconditionPanic)
#endif

#ifndef FILAMENT_CHECK_POSTCONDITION
#define FILAMENT_CHECK_POSTCONDITION(condition)                                                    \
    FILAMENT_CHECK_CONDITION_IMPL(condition)  FILAMENT_PANIC_IMPL(#condition, PostconditionPanic)
#endif

#ifndef FILAMENT_CHECK_ARITHMETIC
#define FILAMENT_CHECK_ARITHMETIC(condition)                                                       \
    FILAMENT_CHECK_CONDITION_IMPL(condition)  FILAMENT_PANIC_IMPL(#condition, ArithmeticPanic)
#endif

#define PANIC_PRECONDITION_IMPL(cond, format, ...)                                                 \
    ::utils::PreconditionPanic::panic(PANIC_FUNCTION,                                              \
            PANIC_FILE(__FILE__), __LINE__, #cond, format, ##__VA_ARGS__)

#define PANIC_POSTCONDITION_IMPL(cond, format, ...)                                                \
    ::utils::PostconditionPanic::panic(PANIC_FUNCTION,                                             \
            PANIC_FILE(__FILE__), __LINE__, #cond, format, ##__VA_ARGS__)

#define PANIC_ARITHMETIC_IMPL(cond, format, ...)                                                   \
    ::utils::ArithmeticPanic::panic(PANIC_FUNCTION,                                                \
            PANIC_FILE(__FILE__), __LINE__, #cond, format, ##__VA_ARGS__)

#define PANIC_LOG_IMPL(cond, format, ...)                                                          \
    ::utils::details::panicLog(PANIC_FUNCTION,                                                     \
            PANIC_FILE(__FILE__), __LINE__, format, ##__VA_ARGS__)

#define PANIC_PRECONDITION(format, ...)     PANIC_PRECONDITION_IMPL(format, format, ##__VA_ARGS__)

#define PANIC_POSTCONDITION(format, ...)    PANIC_POSTCONDITION_IMPL(format, format, ##__VA_ARGS__)

#define PANIC_ARITHMETIC(format, ...)       PANIC_ARITHMETIC_IMPL(format, format, ##__VA_ARGS__)

#define PANIC_LOG(format, ...)              PANIC_LOG_IMPL(format, format, ##__VA_ARGS__)

#define ASSERT_PRECONDITION(cond, format, ...)                                                     \
    (!UTILS_LIKELY(cond) ? PANIC_PRECONDITION_IMPL(cond, format, ##__VA_ARGS__) : (void)0)

#if defined(UTILS_EXCEPTIONS) || !defined(NDEBUG)
#define ASSERT_PRECONDITION_NON_FATAL(cond, format, ...)                                           \
    (!UTILS_LIKELY(cond) ? PANIC_PRECONDITION_IMPL(cond, format, ##__VA_ARGS__), false : true)
#else
#define ASSERT_PRECONDITION_NON_FATAL(cond, format, ...)                                           \
    (!UTILS_LIKELY(cond) ? PANIC_LOG_IMPL(cond, format, ##__VA_ARGS__), false : true)
#endif


#define ASSERT_POSTCONDITION(cond, format, ...)                                                    \
    (!UTILS_LIKELY(cond) ? PANIC_POSTCONDITION_IMPL(cond, format, ##__VA_ARGS__) : (void)0)

#if defined(UTILS_EXCEPTIONS) || !defined(NDEBUG)
#define ASSERT_POSTCONDITION_NON_FATAL(cond, format, ...)                                          \
    (!UTILS_LIKELY(cond) ? PANIC_POSTCONDITION_IMPL(cond, format, ##__VA_ARGS__), false : true)
#else
#define ASSERT_POSTCONDITION_NON_FATAL(cond, format, ...)                                          \
    (!UTILS_LIKELY(cond) ? PANIC_LOG_IMPL(cond, format, ##__VA_ARGS__), false : true)
#endif

#define ASSERT_ARITHMETIC(cond, format, ...)                                                       \
    (!(cond) ? PANIC_ARITHMETIC_IMPL(cond, format, ##__VA_ARGS__) : (void)0)

#if defined(UTILS_EXCEPTIONS) || !defined(NDEBUG)
#define ASSERT_ARITHMETIC_NON_FATAL(cond, format, ...)                                             \
    (!UTILS_LIKELY(cond) ? PANIC_ARITHMETIC_IMPL(cond, format, ##__VA_ARGS__), false : true)
#else
#define ASSERT_ARITHMETIC_NON_FATAL(cond, format, ...)                                             \
    (!UTILS_LIKELY(cond) ? PANIC_LOG_IMPL(cond, format, ##__VA_ARGS__), false : true)
#endif

#define ASSERT_DESTRUCTOR(cond, format, ...)                                                       \
    (!UTILS_LIKELY(cond) ? PANIC_LOG_IMPL(cond, format, ##__VA_ARGS__) : (void)0)

#endif  // TNT_UTILS_PANIC_H

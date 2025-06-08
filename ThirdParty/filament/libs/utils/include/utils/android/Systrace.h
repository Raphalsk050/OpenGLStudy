
#ifndef TNT_UTILS_ANDROID_SYSTRACE_H
#define TNT_UTILS_ANDROID_SYSTRACE_H

#include <atomic>

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

// enable tracing
#define SYSTRACE_ENABLE() ::utils::details::Systrace::enable(SYSTRACE_TAG)

// disable tracing
#define SYSTRACE_DISABLE() ::utils::details::Systrace::disable(SYSTRACE_TAG)


#define SYSTRACE_CONTEXT() ::utils::details::Systrace ___trctx(SYSTRACE_TAG)


// SYSTRACE_NAME traces the beginning and end of the current scope.  To trace
// the correct start and end times this macro should be declared first in the
// scope body.
// It also automatically creates a Systrace context
#define SYSTRACE_NAME(name) ::utils::details::ScopedTrace ___tracer(SYSTRACE_TAG, name)

// Denotes that a new frame has started processing.
#define SYSTRACE_FRAME_ID(frame) \
#define SYSTRACE_ASYNC_BEGIN(name, cookie) \
        ___trctx.asyncBegin(SYSTRACE_TAG, name, cookie)

#define SYSTRACE_ASYNC_END(name, cookie) \
        ___trctx.asyncEnd(SYSTRACE_TAG, name, cookie)

#define SYSTRACE_VALUE32(name, val) \
        ___trctx.value(SYSTRACE_TAG, name, int32_t(val))

#define SYSTRACE_VALUE64(name, val) \
        ___trctx.value(SYSTRACE_TAG, name, int64_t(val))

// ------------------------------------------------------------------------------------------------
// No user serviceable code below...
// ------------------------------------------------------------------------------------------------

namespace utils {
namespace details {

class UTILS_PUBLIC Systrace {
   public:

    enum tags {
        NEVER       = SYSTRACE_TAG_NEVER,
        ALWAYS      = SYSTRACE_TAG_ALWAYS,
        FILAMENT    = SYSTRACE_TAG_FILAMENT,
        JOBSYSTEM   = SYSTRACE_TAG_JOBSYSTEM
        // we could define more TAGS here, as we need them.
    };

    explicit Systrace(uint32_t tag) noexcept {
        if (tag) init(tag);
    }

    static void enable(uint32_t tags) noexcept;
    static void disable(uint32_t tags) noexcept;


    inline void traceBegin(uint32_t tag, const char* name) noexcept {
        if (tag && UTILS_UNLIKELY(mIsTracingEnabled)) {
            beginSection(this, name);
        }
    }

    inline void traceEnd(uint32_t tag) noexcept {
        if (tag && UTILS_UNLIKELY(mIsTracingEnabled)) {
            endSection(this);
        }
    }

    inline void asyncBegin(uint32_t tag, const char* name, int32_t cookie) noexcept {
        if (tag && UTILS_UNLIKELY(mIsTracingEnabled)) {
            beginAsyncSection(this, name, cookie);
        }
    }

    inline void asyncEnd(uint32_t tag, const char* name, int32_t cookie) noexcept {
        if (tag && UTILS_UNLIKELY(mIsTracingEnabled)) {
            endAsyncSection(this, name, cookie);
        }
    }

    inline void value(uint32_t tag, const char* name, int32_t value) noexcept {
        if (tag && UTILS_UNLIKELY(mIsTracingEnabled)) {
            setCounter(this, name, value);
        }
    }

    inline void value(uint32_t tag, const char* name, int64_t value) noexcept {
        if (tag && UTILS_UNLIKELY(mIsTracingEnabled)) {
            setCounter(this, name, value);
        }
    }

   private:
    friend class ScopedTrace;

    // whether tracing is supported at all by the platform

    using ATrace_isEnabled_t          = bool (*)();
    using ATrace_beginSection_t       = void (*)(const char* sectionName);
    using ATrace_endSection_t         = void (*)();
    using ATrace_beginAsyncSection_t  = void (*)(const char* sectionName, int32_t cookie);
    using ATrace_endAsyncSection_t    = void (*)(const char* sectionName, int32_t cookie);
    using ATrace_setCounter_t         = void (*)(const char* counterName, int64_t counterValue);

    struct GlobalState {
        bool isTracingAvailable;
        std::atomic<uint32_t> isTracingEnabled;
        int markerFd;

        ATrace_isEnabled_t ATrace_isEnabled;
        ATrace_beginSection_t ATrace_beginSection;
        ATrace_endSection_t ATrace_endSection;
        ATrace_beginAsyncSection_t ATrace_beginAsyncSection;
        ATrace_endAsyncSection_t ATrace_endAsyncSection;
        ATrace_setCounter_t ATrace_setCounter;

        void (*beginSection)(Systrace* that, const char* name);
        void (*endSection)(Systrace* that);
        void (*beginAsyncSection)(Systrace* that, const char* name, int32_t cookie);
        void (*endAsyncSection)(Systrace* that, const char* name, int32_t cookie);
        void (*setCounter)(Systrace* that, const char* name, int64_t value);
    };

    static GlobalState sGlobalState;


    // per-instance versions for better performance
    ATrace_isEnabled_t ATrace_isEnabled;
    ATrace_beginSection_t ATrace_beginSection;
    ATrace_endSection_t ATrace_endSection;
    ATrace_beginAsyncSection_t ATrace_beginAsyncSection;
    ATrace_endAsyncSection_t ATrace_endAsyncSection;
    ATrace_setCounter_t ATrace_setCounter;

    void (*beginSection)(Systrace* that, const char* name);
    void (*endSection)(Systrace* that);
    void (*beginAsyncSection)(Systrace* that, const char* name, int32_t cookie);
    void (*endAsyncSection)(Systrace* that, const char* name, int32_t cookie);
    void (*setCounter)(Systrace* that, const char* name, int64_t value);

    void init(uint32_t tag) noexcept;

    // cached values for faster access, no need to be initialized
    bool mIsTracingEnabled;
    int mMarkerFd = -1;
    pid_t mPid;

    static void setup() noexcept;
    static void init_once() noexcept;
    static bool isTracingEnabled(uint32_t tag) noexcept;

    static void begin_body(int fd, int pid, const char* name) noexcept;
    static void end_body(int fd, int pid) noexcept;
    static void async_begin_body(int fd, int pid, const char* name, int32_t cookie) noexcept;
    static void async_end_body(int fd, int pid, const char* name, int32_t cookie) noexcept;
    static void int64_body(int fd, int pid, const char* name, int64_t value) noexcept;
};

// ------------------------------------------------------------------------------------------------

class UTILS_PUBLIC ScopedTrace {
public:
    // we don't inline this because it's relatively heavy due to a global check
    ScopedTrace(uint32_t tag, const char* name) noexcept: mTrace(tag), mTag(tag) {
        mTrace.traceBegin(tag, name);
    }

    inline ~ScopedTrace() noexcept {
        mTrace.traceEnd(mTag);
    }

private:
    Systrace mTrace;
    const uint32_t mTag;
};

} // namespace details
} // namespace utils

#endif // TNT_UTILS_ANDROID_SYSTRACE_H

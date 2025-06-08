
#include "third_party/filament/libs/utils/include/utils/Log.h"

#include "ostream_.h"

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#ifdef __ANDROID__
#   include <android/log.h>
#   ifndef UTILS_LOG_TAG
#       define UTILS_LOG_TAG "Filament"
#   endif
#endif

#if defined(__EMSCRIPTEN__)
#include <emscripten/console.h>
#endif

#include <mutex>

namespace utils {
namespace io {

class LogStream : public ostream {
public:

    enum Priority {
        LOG_DEBUG, LOG_ERROR, LOG_WARNING, LOG_INFO, LOG_VERBOSE
    };

    explicit LogStream(Priority p) noexcept : mPriority(p) {}

    ostream& flush() noexcept override;

private:
    const Priority mPriority;
};

ostream& LogStream::flush() noexcept {
    std::lock_guard const lock(mImpl->mLock);
    Buffer& buf = getBuffer();
    char const* const str = buf.get();
    if (UTILS_UNLIKELY(!str)) {
        // this can happen if the log hasn't been written ever
        return *this;
    }

#ifdef __ANDROID__
    int prio = ANDROID_LOG_UNKNOWN;
    switch (mPriority) {
        case LOG_DEBUG:     prio = ANDROID_LOG_DEBUG;   break;
        case LOG_ERROR:     prio = ANDROID_LOG_ERROR;   break;
        case LOG_WARNING:   prio = ANDROID_LOG_WARN;    break;
        case LOG_INFO:      prio = ANDROID_LOG_INFO;    break;
        case LOG_VERBOSE:   prio = ANDROID_LOG_VERBOSE; break;
    }
    __android_log_write(prio, UTILS_LOG_TAG, str);
#elif defined(__EMSCRIPTEN__)
    switch (mPriority) {
        case LOG_DEBUG:
        case LOG_WARNING:
        case LOG_INFO:
            _emscripten_out(str);
            break;
        case LOG_ERROR:
            _emscripten_err(str);
            break;
        case LOG_VERBOSE:
#ifndef NFIL_DEBUG
            _emscripten_out(str);
#endif
            break;
    }
#else  // not ANDROID or EMSCRIPTEN
    switch (mPriority) {
        case LOG_DEBUG:
        case LOG_WARNING:
        case LOG_INFO:
            fprintf(stdout, "%s", str);
            break;
        case LOG_ERROR:
            fprintf(stderr, "%s", str);
            break;
        case LOG_VERBOSE:
#ifndef NFIL_DEBUG
            fprintf(stdout, "%s", str);
#endif
            break;
    }
#endif  // __ANDROID__ or __EMSCRIPTEN__
    buf.reset();
    return *this;
}



static LogStream cout(LogStream::Priority::LOG_DEBUG);
static LogStream cerr(LogStream::Priority::LOG_ERROR);
static LogStream cwarn(LogStream::Priority::LOG_WARNING);
static LogStream cinfo(LogStream::Priority::LOG_INFO);
static LogStream cverbose(LogStream::Priority::LOG_VERBOSE);

} // namespace io


Loggers const slog = {
        io::cout,       // debug
        io::cerr,       // error
        io::cwarn,      // warning
        io::cinfo,      // info
        io::cverbose    // verbose
};

} // namespace utils

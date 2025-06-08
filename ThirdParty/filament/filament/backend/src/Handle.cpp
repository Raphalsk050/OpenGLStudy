
#include <backend/Handle.h>

#ifndef NDEBUG
#   include <string>
#endif

#include "third_party/filament/libs/utils/include/utils/CallStack.h"

using namespace utils;

namespace filament::backend {

#ifndef NDEBUG

static char const * const kOurNamespace = "filament::backend";

// removes all occurrences of "what" from "str"
UTILS_NOINLINE
static std::string& removeAll(std::string& str, const std::string& what) noexcept {
    if (!what.empty()) {
        const std::string empty;
        size_t pos = 0;
        while ((pos = str.find(what, pos)) != std::string::npos) {
            str.replace(pos, what.length(), empty);
        }
    }
    return str;
}

template <typename T>
UTILS_NOINLINE
static io::ostream& logHandle(io::ostream& out, std::string& typeName, T id) noexcept {
    return out << removeAll(typeName, kOurNamespace) << " @ " << id;
}

template <typename T>
io::ostream& operator<<(io::ostream& out, const Handle<T>& h) noexcept {
    std::string s(CallStack::typeName<Handle<T>>().c_str());
    return logHandle(out, s, h.getId());
}

// Explicit Instantiation of the streaming operators (so they're not inlined)
template io::ostream& operator<<(io::ostream& out, const Handle<HwVertexBuffer>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwIndexBuffer>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwRenderPrimitive>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwProgram>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwSamplerGroup>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwTexture>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwRenderTarget>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwFence>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwSwapChain>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwStream>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwTimerQuery>& h) noexcept;
template io::ostream& operator<<(io::ostream& out, const Handle<HwBufferObject>& h) noexcept;

#endif

} // namespace filament::backend

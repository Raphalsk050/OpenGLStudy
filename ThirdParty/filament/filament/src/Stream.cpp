
#include "details/Stream.h"

namespace filament {

using namespace backend;

StreamType Stream::getStreamType() const noexcept {
    return downcast(this)->getStreamType();
}

void Stream::setAcquiredImage(void* image, Callback callback, void* userdata) noexcept {
    downcast(this)->setAcquiredImage(image, callback, userdata);
}

void Stream::setAcquiredImage(void* image,
        backend::CallbackHandler* handler, Callback callback, void* userdata) noexcept {
    downcast(this)->setAcquiredImage(image, handler, callback, userdata);
}

void Stream::setDimensions(uint32_t width, uint32_t height) noexcept {
    downcast(this)->setDimensions(width, height);
}

int64_t Stream::getTimestamp() const noexcept {
    return downcast(this)->getTimestamp();
}

} // namespace filament

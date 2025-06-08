
//! \file

#ifndef TNT_FILAMENT_BACKEND_BUFFERDESCRIPTOR_H
#define TNT_FILAMENT_BACKEND_BUFFERDESCRIPTOR_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include <stddef.h>

namespace filament::backend {

class CallbackHandler;

class UTILS_PUBLIC BufferDescriptor {
public:
    using Callback = void(*)(void* buffer, size_t size, void* user);

    //! creates an empty descriptor
    BufferDescriptor() noexcept = default;

    //! calls the callback to advertise BufferDescriptor no-longer owns the buffer
    ~BufferDescriptor() noexcept {
        if (mCallback) {
            mCallback(buffer, size, mUser);
        }
    }

    BufferDescriptor(const BufferDescriptor& rhs) = delete;
    BufferDescriptor& operator=(const BufferDescriptor& rhs) = delete;

    BufferDescriptor(BufferDescriptor&& rhs) noexcept
        : buffer(rhs.buffer), size(rhs.size),
          mCallback(rhs.mCallback), mUser(rhs.mUser), mHandler(rhs.mHandler) {
            rhs.buffer = nullptr;
            rhs.mCallback = nullptr;
    }

    BufferDescriptor& operator=(BufferDescriptor&& rhs) noexcept {
        if (this != &rhs) {
            buffer = rhs.buffer;
            size = rhs.size;
            mCallback = rhs.mCallback;
            mUser = rhs.mUser;
            mHandler = rhs.mHandler;
            rhs.buffer = nullptr;
            rhs.mCallback = nullptr;
        }
        return *this;
    }

    BufferDescriptor(void const* buffer, size_t size,
            Callback callback = nullptr, void* user = nullptr) noexcept
                : buffer(const_cast<void*>(buffer)), size(size), mCallback(callback), mUser(user) {
    }

    BufferDescriptor(void const* buffer, size_t size,
            CallbackHandler* handler, Callback callback, void* user = nullptr) noexcept
                : buffer(const_cast<void*>(buffer)), size(size),
                mCallback(callback), mUser(user), mHandler(handler) {
    }

    // --------------------------------------------------------------------------------------------

    template<typename T, void(T::*method)(void const*, size_t)>
    static BufferDescriptor make(void const* buffer, size_t size, T* data,
            CallbackHandler* handler = nullptr) noexcept {
        return {
                buffer, size,
                handler, [](void* b, size_t s, void* u) {
                    (static_cast<T*>(u)->*method)(b, s);
                }, data
        };
    }

    template<typename T>
    static BufferDescriptor make(void const* buffer, size_t size, T&& functor,
            CallbackHandler* handler = nullptr) noexcept {
        return {
                buffer, size,
                handler, [](void* b, size_t s, void* u) {
                    T* const that = static_cast<T*>(u);
                    that->operator()(b, s);
                    delete that;
                },
                new T(std::forward<T>(functor))
        };
    }

    // --------------------------------------------------------------------------------------------

    void setCallback(Callback callback, void* user = nullptr) noexcept {
        this->mCallback = callback;
        this->mUser = user;
        this->mHandler = nullptr;
    }

    void setCallback(CallbackHandler* handler, Callback callback, void* user = nullptr) noexcept {
        mCallback = callback;
        mUser = user;
        mHandler = handler;
    }

    //! Returns whether a release callback is set
    bool hasCallback() const noexcept { return mCallback != nullptr; }

    //! Returns the currently set release callback function
    Callback getCallback() const noexcept {
        return mCallback;
    }

    //! Returns the handler for this callback or nullptr if the default handler is to be used.
    CallbackHandler* getHandler() const noexcept {
        return mHandler;
    }

    //! Returns the user opaque pointer associated to this BufferDescriptor
    void* getUser() const noexcept {
        return mUser;
    }

    //! CPU memory-buffer virtual address
    void* buffer = nullptr;

    //! CPU memory-buffer size in bytes
    size_t size = 0;

private:
    // callback when the buffer is consumed.
    Callback mCallback = nullptr;
    void* mUser = nullptr;
    CallbackHandler* mHandler = nullptr;
};

} // namespace filament::backend

#if !defined(NDEBUG)
utils::io::ostream& operator<<(utils::io::ostream& out, const filament::backend::BufferDescriptor& b);
#endif

#endif // TNT_FILAMENT_BACKEND_BUFFERDESCRIPTOR_H

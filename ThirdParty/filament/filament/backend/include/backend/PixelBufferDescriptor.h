
//! \file

#ifndef TNT_FILAMENT_BACKEND_PIXELBUFFERDESCRIPTOR_H
#define TNT_FILAMENT_BACKEND_PIXELBUFFERDESCRIPTOR_H

#include <backend/BufferDescriptor.h>
#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include <stddef.h>
#include <stdint.h>

namespace filament::backend {

class UTILS_PUBLIC PixelBufferDescriptor : public BufferDescriptor {
public:
    using PixelDataFormat = backend::PixelDataFormat;
    using PixelDataType = backend::PixelDataType;

    PixelBufferDescriptor() = default;

    PixelBufferDescriptor(void const* buffer, size_t size,
            PixelDataFormat format, PixelDataType type, uint8_t alignment,
            uint32_t left, uint32_t top, uint32_t stride,
            CallbackHandler* handler, Callback callback, void* user = nullptr) noexcept
            : BufferDescriptor(buffer, size, handler, callback, user),
              left(left), top(top), stride(stride),
              format(format), type(type), alignment(alignment) {
    }

    PixelBufferDescriptor(void const* buffer, size_t size,
            PixelDataFormat format, PixelDataType type, uint8_t alignment = 1,
            uint32_t left = 0, uint32_t top = 0, uint32_t stride = 0,
            Callback callback = nullptr, void* user = nullptr) noexcept
            : BufferDescriptor(buffer, size, callback, user),
              left(left), top(top), stride(stride),
              format(format), type(type), alignment(alignment) {
    }

    PixelBufferDescriptor(void const* buffer, size_t size,
            PixelDataFormat format, PixelDataType type,
            CallbackHandler* handler, Callback callback, void* user = nullptr) noexcept
            : BufferDescriptor(buffer, size, handler, callback, user),
              stride(0), format(format), type(type), alignment(1) {
    }

    PixelBufferDescriptor(void const* buffer, size_t size,
            PixelDataFormat format, PixelDataType type,
            Callback callback, void* user = nullptr) noexcept
            : BufferDescriptor(buffer, size, callback, user),
              stride(0), format(format), type(type), alignment(1) {
    }


    PixelBufferDescriptor(void const* buffer, size_t size,
            backend::CompressedPixelDataType format, uint32_t imageSize,
            CallbackHandler* handler, Callback callback, void* user = nullptr) noexcept
            : BufferDescriptor(buffer, size, handler, callback, user),
              imageSize(imageSize), compressedFormat(format), type(PixelDataType::COMPRESSED),
              alignment(1) {
    }

    PixelBufferDescriptor(void const* buffer, size_t size,
            backend::CompressedPixelDataType format, uint32_t imageSize,
            Callback callback, void* user = nullptr) noexcept
            : BufferDescriptor(buffer, size, callback, user),
              imageSize(imageSize), compressedFormat(format), type(PixelDataType::COMPRESSED),
              alignment(1) {
    }

    // --------------------------------------------------------------------------------------------

    template<typename T, void(T::*method)(void const*, size_t)>
    static PixelBufferDescriptor make(void const* buffer, size_t size,
            PixelDataFormat format, PixelDataType type, uint8_t alignment,
            uint32_t left, uint32_t top, uint32_t stride, T* data,
            CallbackHandler* handler = nullptr) noexcept {
        return { buffer, size, format, type, alignment, left, top, stride,
                handler, [](void* b, size_t s, void* u) {
                    (static_cast<T*>(u)->*method)(b, s); }, data };
    }

    template<typename T, void(T::*method)(void const*, size_t)>
    static PixelBufferDescriptor make(void const* buffer, size_t size,
            PixelDataFormat format, PixelDataType type, T* data,
            CallbackHandler* handler = nullptr) noexcept {
        return { buffer, size, format, type, handler, [](void* b, size_t s, void* u) {
                    (static_cast<T*>(u)->*method)(b, s); }, data };
    }

    template<typename T, void(T::*method)(void const*, size_t)>
    static PixelBufferDescriptor make(void const* buffer, size_t size,
            backend::CompressedPixelDataType format, uint32_t imageSize, T* data,
            CallbackHandler* handler = nullptr) noexcept {
        return { buffer, size, format, imageSize, handler, [](void* b, size_t s, void* u) {
                    (static_cast<T*>(u)->*method)(b, s); }, data
        };
    }

    template<typename T>
    static PixelBufferDescriptor make(void const* buffer, size_t size,
            PixelDataFormat format, PixelDataType type, uint8_t alignment,
            uint32_t left, uint32_t top, uint32_t stride, T&& functor,
            CallbackHandler* handler = nullptr) noexcept {
        return { buffer, size, format, type, alignment, left, top, stride,
                handler, [](void* b, size_t s, void* u) {
                    T* const that = static_cast<T*>(u);
                    that->operator()(b, s);
                    delete that;
                }, new T(std::forward<T>(functor))
        };
    }

    template<typename T>
    static PixelBufferDescriptor make(void const* buffer, size_t size,
            PixelDataFormat format, PixelDataType type, T&& functor,
            CallbackHandler* handler = nullptr) noexcept {
        return { buffer, size, format, type,
                 handler, [](void* b, size_t s, void* u) {
                    T* const that = static_cast<T*>(u);
                    that->operator()(b, s);
                    delete that;
                }, new T(std::forward<T>(functor))
        };
    }

    template<typename T>
    static PixelBufferDescriptor make(void const* buffer, size_t size,
            backend::CompressedPixelDataType format, uint32_t imageSize, T&& functor,
            CallbackHandler* handler = nullptr) noexcept {
        return { buffer, size, format, imageSize,
                 handler, [](void* b, size_t s, void* u) {
                    T* const that = static_cast<T*>(u);
                    that->operator()(b, s);
                    delete that;
                }, new T(std::forward<T>(functor))
        };
    }

    // --------------------------------------------------------------------------------------------

    static constexpr size_t computeDataSize(PixelDataFormat format, PixelDataType type,
            size_t stride, size_t height, size_t alignment) noexcept {
        assert_invariant(alignment);

        if (type == PixelDataType::COMPRESSED) {
            return 0;
        }

        size_t n = 0;
        switch (format) {
            case PixelDataFormat::R:
            case PixelDataFormat::R_INTEGER:
            case PixelDataFormat::DEPTH_COMPONENT:
            case PixelDataFormat::ALPHA:
                n = 1;
                break;
            case PixelDataFormat::RG:
            case PixelDataFormat::RG_INTEGER:
            case PixelDataFormat::DEPTH_STENCIL:
                n = 2;
                break;
            case PixelDataFormat::RGB:
            case PixelDataFormat::RGB_INTEGER:
                n = 3;
                break;
            case PixelDataFormat::UNUSED: // shouldn't happen (used to be rgbm)
            case PixelDataFormat::RGBA:
            case PixelDataFormat::RGBA_INTEGER:
                n = 4;
                break;
        }

        size_t bpp = n;
        switch (type) {
            case PixelDataType::COMPRESSED: // Impossible -- to squash the IDE warnings
            case PixelDataType::UBYTE:
            case PixelDataType::BYTE:
                // nothing to do
                break;
            case PixelDataType::USHORT:
            case PixelDataType::SHORT:
            case PixelDataType::HALF:
                bpp *= 2;
                break;
            case PixelDataType::UINT:
            case PixelDataType::INT:
            case PixelDataType::FLOAT:
                bpp *= 4;
                break;
            case PixelDataType::UINT_10F_11F_11F_REV:
                // Special case, format must be RGB and uses 4 bytes
                assert_invariant(format == PixelDataFormat::RGB);
                bpp = 4;
                break;
            case PixelDataType::UINT_2_10_10_10_REV:
                // Special case, format must be RGBA and uses 4 bytes
                assert_invariant(format == PixelDataFormat::RGBA);
                bpp = 4;
                break;
            case PixelDataType::USHORT_565:
                // Special case, format must be RGB and uses 2 bytes
                assert_invariant(format == PixelDataFormat::RGB);
                bpp = 2;
                break;
        }

        size_t const bpr = bpp * stride;
        size_t const bprAligned = (bpr + (alignment - 1)) & (~alignment + 1);
        return bprAligned * height;
    }

    //! left coordinate in pixels
    uint32_t left   = 0;
    //! top coordinate in pixels
    uint32_t top    = 0;
    union {
        struct {
            //! stride in pixels
            uint32_t stride;
            //! Pixel data format
            PixelDataFormat format;
        };
        struct {
            //! compressed image size
            uint32_t imageSize;
            //! compressed image format
            backend::CompressedPixelDataType compressedFormat;
        };
    };
    //! pixel data type
    PixelDataType type : 4;
    //! row alignment in bytes
    uint8_t alignment  : 4;
};

} // namespace backend::filament

#if !defined(NDEBUG)
utils::io::ostream& operator<<(utils::io::ostream& out, const filament::backend::PixelBufferDescriptor& b);
#endif

#endif // TNT_FILAMENT_BACKEND_PIXELBUFFERDESCRIPTOR_H


#ifndef TNT_BACKENDTESTUTILS_H
#define TNT_BACKENDTESTUTILS_H

#include <cstddef>

#include <backend/PixelBufferDescriptor.h>

using namespace filament;
using namespace filament::backend;

inline void getPixelInfo(PixelDataFormat format, PixelDataType type, size_t& outComponents, int& outBpp) {
    assert_invariant(type != PixelDataType::COMPRESSED);
    switch (format) {
        case PixelDataFormat::UNUSED:
        case PixelDataFormat::R:
        case PixelDataFormat::R_INTEGER:
        case PixelDataFormat::DEPTH_COMPONENT:
        case PixelDataFormat::ALPHA:
            outComponents = 1;
            break;
        case PixelDataFormat::RG:
        case PixelDataFormat::RG_INTEGER:
        case PixelDataFormat::DEPTH_STENCIL:
            outComponents = 2;
            break;
        case PixelDataFormat::RGB:
        case PixelDataFormat::RGB_INTEGER:
            outComponents = 3;
            break;
        case PixelDataFormat::RGBA:
        case PixelDataFormat::RGBA_INTEGER:
            outComponents = 4;
            break;
    }

    outBpp = outComponents;
    switch (type) {
        case PixelDataType::COMPRESSED: // Impossible -- to squash the IDE warnings
        case PixelDataType::UBYTE:
        case PixelDataType::BYTE:
            // nothing to do
            break;
        case PixelDataType::USHORT:
        case PixelDataType::SHORT:
        case PixelDataType::HALF:
            outBpp *= 2;
            break;
        case PixelDataType::UINT:
        case PixelDataType::INT:
        case PixelDataType::FLOAT:
            outBpp *= 4;
            break;
        case PixelDataType::UINT_10F_11F_11F_REV:
            // Special case, format must be RGB and uses 4 bytes
            assert_invariant(format == PixelDataFormat::RGB);
            outBpp = 4;
            break;
        case PixelDataType::UINT_2_10_10_10_REV:
            // Special case, format must be RGBA and uses 4 bytes
            assert_invariant(format == PixelDataFormat::RGBA);
            outBpp = 4;
            break;
        case PixelDataType::USHORT_565:
            // Special case, format must be RGB and uses 2 bytes
            assert_invariant(format == PixelDataFormat::RGB);
            outBpp = 2;
            break;
    }
}

template<typename ComponentType>
static void fillCheckerboard(void* buffer, size_t size, size_t stride, size_t components,
        ComponentType value) {
    ComponentType* row = (ComponentType*)buffer;
    int p = 0;
    for (int r = 0; r < size; r++) {
        ComponentType* pixel = row;
        for (int col = 0; col < size; col++) {
            // Generate a checkerboard pattern.
            if ((p & 0x0010) ^ ((p / size) & 0x0010)) {
                // Turn on the first component (red).
                pixel[0] = value;
            }
            pixel += components;
            p++;
        }
        row += stride * components;
    }
}

static PixelBufferDescriptor checkerboardPixelBuffer(PixelDataFormat format, PixelDataType type,
        size_t size, size_t bufferPadding = 0) {
    size_t components; int bpp;
    getPixelInfo(format, type, components, bpp);

    size_t bufferSize = size + bufferPadding * 2;
    uint8_t* buffer = (uint8_t*) calloc(1, bufferSize * bufferSize * bpp);

    uint8_t* ptr = buffer + (bufferSize * bufferPadding * bpp) + (bufferPadding * bpp);

    switch (type) {
        case PixelDataType::BYTE:
            fillCheckerboard<int8_t>(ptr, size, bufferSize, components, 1);
            break;

        case PixelDataType::UBYTE:
            fillCheckerboard<uint8_t>(ptr, size, bufferSize, components, 0xFF);
            break;

        case PixelDataType::SHORT:
            fillCheckerboard<int16_t>(ptr, size, bufferSize, components, 1);
            break;

        case PixelDataType::USHORT:
            fillCheckerboard<uint16_t>(ptr, size, bufferSize, components, 1u);
            break;

        case PixelDataType::UINT:
            fillCheckerboard<uint32_t>(ptr, size, bufferSize, components, 1u);
            break;

        case PixelDataType::INT:
            fillCheckerboard<int32_t>(ptr, size, bufferSize, components, 1);
            break;

        case PixelDataType::FLOAT:
            fillCheckerboard<float>(ptr, size, bufferSize, components, 1.0f);
            break;

        case PixelDataType::HALF:
            fillCheckerboard<math::half>(ptr, size, bufferSize, components, math::half(1.0f));
            break;

        case PixelDataType::UINT_2_10_10_10_REV:
            break;

        case PixelDataType::UINT_10F_11F_11F_REV:

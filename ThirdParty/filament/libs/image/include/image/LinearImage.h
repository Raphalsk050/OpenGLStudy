
#ifndef IMAGE_LINEARIMAGE_H
#define IMAGE_LINEARIMAGE_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <cstdint>

namespace image {

class UTILS_PUBLIC LinearImage {
public:

    ~LinearImage();

    LinearImage(uint32_t width, uint32_t height, uint32_t channels);

    LinearImage(const LinearImage& that);
    LinearImage& operator=(const LinearImage& that);

    LinearImage() : mDataRef(nullptr), mData(nullptr), mWidth(0), mHeight(0), mChannels(0) {}
    operator bool() const { return mData != nullptr; } 

    float* getPixelRef() { return mData; }
    template<typename T> T* get() { return reinterpret_cast<T*>(mData); }

    float const* getPixelRef() const { return mData; }
    template<typename T> T const* get() const { return reinterpret_cast<T const*>(mData); }

    float* getPixelRef(uint32_t column, uint32_t row) {
        return mData + (column + row * mWidth) * mChannels;
    }

    template<typename T>
    T* get(uint32_t column, uint32_t row) {
        return reinterpret_cast<T*>(getPixelRef(column, row));
    }

    float const* getPixelRef(uint32_t column, uint32_t row) const {
        return mData + (column + row * mWidth) * mChannels;
    }

    template<typename T>
    T const* get(uint32_t column, uint32_t row) const {
        return reinterpret_cast<T const*>(getPixelRef(column, row));
    }

    uint32_t getWidth() const { return mWidth; }
    uint32_t getHeight() const { return mHeight; }
    uint32_t getChannels() const { return mChannels; }
    void reset() { *this = LinearImage(); }
    bool isValid() const { return mData; }

private:

    struct SharedReference;
    SharedReference* mDataRef = nullptr;

    float* mData;
    uint32_t mWidth;
    uint32_t mHeight;
    uint32_t mChannels;
};

} // namespace image


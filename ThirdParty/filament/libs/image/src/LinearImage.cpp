
#include <image/LinearImage.h>

#include <cstring> // for memset
#include <memory>

namespace image  {

struct LinearImage::SharedReference {
    SharedReference(uint32_t width, uint32_t height, uint32_t channels) {
        const uint32_t nfloats = width * height * channels;
        float* floats = new float[nfloats];
        memset(floats, 0, sizeof(float) * nfloats);
        pixels = std::shared_ptr<float>(floats, std::default_delete<float[]>());
    }
    std::shared_ptr<float> pixels;
};

LinearImage::~LinearImage() {
    delete mDataRef;
}

LinearImage::LinearImage(uint32_t width, uint32_t height, uint32_t channels) :
    mDataRef(new SharedReference(width, height, channels)),
    mData(mDataRef->pixels.get()),
    mWidth(width), mHeight(height), mChannels(channels) {}

LinearImage::LinearImage(const LinearImage& that) {
    *this = that;
}

LinearImage& LinearImage::operator=(const LinearImage& that) {
    auto newDataRef = that.mDataRef
        ? new SharedReference(*that.mDataRef)
        : nullptr;
    delete mDataRef;
    mDataRef = newDataRef;
    
    mData = that.mData;
    mWidth = that.mWidth;
    mHeight = that.mHeight;
    mChannels = that.mChannels;
    return *this;
}

}  // namespace image

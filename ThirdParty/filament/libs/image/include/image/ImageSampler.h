
#ifndef IMAGE_IMAGESAMPLER_H
#define IMAGE_IMAGESAMPLER_H

#include <image/LinearImage.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace image {

struct UTILS_PUBLIC SingleSample {
    float& operator[](int index) { return *(data + index); }
    float* data = nullptr;
    ~SingleSample();
};

enum class Filter {
    DEFAULT,          // Selects MITCHELL or LANCZOS dynamically.
    BOX,              // Computes the un-weighted average over the filter radius.
    NEAREST,          // Copies the source sample nearest to the center of the filter.
    HERMITE,          // Also known as "smoothstep", has some nice properties.
    GAUSSIAN_SCALARS, // Standard Gaussian filter with sigma = 0.5
    GAUSSIAN_NORMALS, // Same as GAUSSIAN_SCALARS, but interpolates unitized vectors.
    MITCHELL,         // Cubic resampling per Mitchell-Netravali, default for magnification.
    LANCZOS,          // Popular sinc-based filter, default for minification.
    MINIMUM           // Takes a min val rather than avg, perhaps useful for depth maps and SDF's.
};

struct Region {
    float left;
    float top;
    float right;
    float bottom;
};

enum class Orientation {
    STANDARD = 0,
    FLIP_X = 1 << 0,
    FLIP_Y = 1 << 1,
    FLIP_XY = FLIP_X | FLIP_Y
};

struct Boundary {
    enum {
        EXCLUDE, // Ignore the samples and renormalize the filter. This is probably what you want.
        REGION,  // Keep samples that are outside sourceRegion if they are still within the image.
        CLAMP,   // Pretend the edge pixel is repeated forever. Gives edge pixels more weight.
        REPEAT,  // Resample from the region, wrapping back to the front of the row or column.
        MIRROR,  // Resample from the region but assume that it has been flipped.
        COLOR,   // Use the specified constant color.
        NEIGHBOR // Sample from an adjacent image.
    } mode = EXCLUDE;
    SingleSample color;              // Used only if mode = COLOR
    LinearImage* neighbor = nullptr; // Used only if mode = NEIGHBOR
    Orientation orientation;         // Used only if mode = NEIGHBOR
};

struct ImageSampler {
    Filter horizontalFilter = Filter::DEFAULT;
    Filter verticalFilter = Filter::DEFAULT;
    Region sourceRegion = {0, 0, 1, 1};
    float filterRadiusMultiplier = 1;
    Boundary east;
    Boundary north;
    Boundary west;
    Boundary south;
};

UTILS_PUBLIC
LinearImage resampleImage(const LinearImage& source, uint32_t width, uint32_t height,
        const ImageSampler& sampler);

UTILS_PUBLIC
LinearImage resampleImage(const LinearImage& source, uint32_t width, uint32_t height,
        Filter filter = Filter::DEFAULT);

UTILS_PUBLIC
void computeSingleSample(const LinearImage& source, float x, float y, SingleSample* result,
        Filter filter = Filter::BOX);

UTILS_PUBLIC
void generateMipmaps(const LinearImage& source, Filter, LinearImage* result, uint32_t mipCount);

UTILS_PUBLIC
uint32_t getMipmapCount(const LinearImage& source);

UTILS_PUBLIC
Filter filterFromString(const char* name);

} // namespace image


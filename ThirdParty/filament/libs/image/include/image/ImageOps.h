
#ifndef IMAGE_IMAGEOPS_H
#define IMAGE_IMAGEOPS_H

#include <image/LinearImage.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <cstddef>
#include <initializer_list>

namespace image {

// Concatenates images horizontally to create a filmstrip atlas, similar to numpy's hstack.
UTILS_PUBLIC LinearImage horizontalStack(std::initializer_list<LinearImage> images);
UTILS_PUBLIC LinearImage horizontalStack(LinearImage const* img, size_t count);

// Concatenates images vertically to create a filmstrip atlas, similar to numpy's vstack.
UTILS_PUBLIC LinearImage verticalStack(std::initializer_list<LinearImage> images);
UTILS_PUBLIC LinearImage verticalStack(LinearImage const* img, size_t count);

// Horizontally or vertically mirror the given image.
UTILS_PUBLIC LinearImage horizontalFlip(const LinearImage& image);
UTILS_PUBLIC LinearImage verticalFlip(const LinearImage& image);

// Transforms normals (components live in [-1,+1]) into colors (components live in [0,+1]).
UTILS_PUBLIC LinearImage vectorsToColors(const LinearImage& image);
UTILS_PUBLIC LinearImage colorsToVectors(const LinearImage& image);

// Creates a single-channel image by extracting the selected channel.
UTILS_PUBLIC LinearImage extractChannel(const LinearImage& image, uint32_t channel);

// Constructs a multi-channel image by copying data from a sequence of single-channel images.
UTILS_PUBLIC LinearImage combineChannels(std::initializer_list<LinearImage> images);
UTILS_PUBLIC LinearImage combineChannels(LinearImage const* img, size_t count);

// Generates a new image with rows & columns swapped.
UTILS_PUBLIC LinearImage transpose(const LinearImage& image);

// Extracts pixels by specifying a crop window where (0,0) is the top-left corner of the image.
// The boundary is specified as Left Top Right Bottom.
UTILS_PUBLIC
LinearImage cropRegion(const LinearImage& image, uint32_t l, uint32_t t, uint32_t r, uint32_t b);

// Lexicographically compares two images, similar to memcmp.
UTILS_PUBLIC int compare(const LinearImage& a, const LinearImage& b, float epsilon = 0.0f);

// Sets all pixels in all channels to the given value.
UTILS_PUBLIC void clearToValue(LinearImage& img, float value);

// Called by the coordinate field generator to query if a pixel is within the region of interest.
using PresenceCallback = bool(*)(const LinearImage& img, uint32_t col, uint32_t row, void* user);

// Generates a two-channel field of non-normalized coordinates that indicate the nearest pixel
// whose presence function returns true. This is the first step before generating a distance
// field or generalized Voronoi map.
UTILS_PUBLIC
LinearImage computeCoordField(const LinearImage& src, PresenceCallback presence, void* user);

// Generates a single-channel Euclidean distance field with positive values outside the region
// of interest in the source image, and zero values inside. If sqrt is false, the computed
// distances are squared. If signed distance (SDF) is desired, this function can be called a second
// time using an inverted source field.
UTILS_PUBLIC LinearImage edtFromCoordField(const LinearImage& coordField, bool sqrt);

// Dereferences the given coordinate field. Useful for creating Voronoi diagrams or dilated images.
UTILS_PUBLIC
LinearImage voronoiFromCoordField(const LinearImage& coordField, const LinearImage& src);

// Copies content of a source image into a target image. Requires width/height/channels to match.
UTILS_PUBLIC void blitImage(LinearImage& target, const LinearImage& source);

} // namespace image



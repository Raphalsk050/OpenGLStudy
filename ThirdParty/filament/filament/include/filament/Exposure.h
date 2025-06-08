
//! \file

#ifndef TNT_FILAMENT_EXPOSURE_H
#define TNT_FILAMENT_EXPOSURE_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament {

class Camera;

namespace Exposure {

UTILS_PUBLIC
float ev100(const Camera& camera) noexcept;

UTILS_PUBLIC
float ev100(float aperture, float shutterSpeed, float sensitivity) noexcept;

UTILS_PUBLIC
float ev100FromLuminance(float luminance) noexcept;

UTILS_PUBLIC
float ev100FromIlluminance(float illuminance) noexcept;

UTILS_PUBLIC
float exposure(const Camera& camera) noexcept;

UTILS_PUBLIC
float exposure(float aperture, float shutterSpeed, float sensitivity) noexcept;

UTILS_PUBLIC
float exposure(float ev100) noexcept;

UTILS_PUBLIC
float luminance(const Camera& camera) noexcept;

UTILS_PUBLIC
float luminance(float aperture, float shutterSpeed, float sensitivity) noexcept;

UTILS_PUBLIC
float luminance(float ev100) noexcept;

UTILS_PUBLIC
float illuminance(const Camera& camera) noexcept;

UTILS_PUBLIC
float illuminance(float aperture, float shutterSpeed, float sensitivity) noexcept;

UTILS_PUBLIC
float illuminance(float ev100) noexcept;

} // namespace exposure
} // namespace filament

#endif // TNT_FILAMENT_EXPOSURE_H

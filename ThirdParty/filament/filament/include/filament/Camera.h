
//! \file

#ifndef TNT_FILAMENT_CAMERA_H
#define TNT_FILAMENT_CAMERA_H

#include <filament/FilamentAPI.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"
#include "third_party/filament/libs/math/include/math/vec2.h"
#include "third_party/filament/libs/math/include/math/vec4.h"
#include "third_party/filament/libs/math/include/math/mat4.h"

#include <math.h>

#include <stdint.h>
#include <stddef.h>

namespace utils {
class Entity;
} // namespace utils

namespace filament {

class UTILS_PUBLIC Camera : public FilamentAPI {
public:
    //! Denotes the projection type used by this camera. \see setProjection
    enum class Projection : int {
        PERSPECTIVE,    //!< perspective projection, objects get smaller as they are farther
        ORTHO           //!< orthonormal projection, preserves distances
    };

    //! Denotes a field-of-view direction. \see setProjection
    enum class Fov : int {
        VERTICAL,       //!< the field-of-view angle is defined on the vertical axis
        HORIZONTAL      //!< the field-of-view angle is defined on the horizontal axis
    };

    static math::mat4 projection(Fov direction, double fovInDegrees,
            double aspect, double near, double far = INFINITY);

    static math::mat4 projection(double focalLengthInMillimeters,
            double aspect, double near, double far = INFINITY);


    void setProjection(Projection projection,
            double left, double right,
            double bottom, double top,
            double near, double far);


    void setProjection(double fovInDegrees, double aspect, double near, double far,
                       Fov direction = Fov::VERTICAL);

    void setLensProjection(double focalLengthInMillimeters,
            double aspect, double near, double far);


    void setCustomProjection(math::mat4 const& projection, double near, double far) noexcept;

    void setCustomProjection(math::mat4 const& projection, math::mat4 const& projectionForCulling,
            double near, double far) noexcept;

    void setCustomEyeProjection(math::mat4 const* UTILS_NONNULL projection, size_t count,
            math::mat4 const& projectionForCulling, double near, double far);

    void setScaling(math::double2 scaling) noexcept;

    void setShift(math::double2 shift) noexcept;

    math::double4 getScaling() const noexcept;

    math::double2 getShift() const noexcept;

    math::mat4 getProjectionMatrix(uint8_t eyeId = 0) const;


    math::mat4 getCullingProjectionMatrix() const noexcept;


    //! Returns the frustum's near plane
    double getNear() const noexcept;

    //! Returns the frustum's far plane used for culling
    double getCullingFar() const noexcept;

    void setModelMatrix(const math::mat4& model) noexcept;
    void setModelMatrix(const math::mat4f& model) noexcept; //!< @overload

    void setEyeModelMatrix(uint8_t eyeId, math::mat4 const& model);

    void lookAt(math::double3 const& eye,
                math::double3 const& center,
                math::double3 const& up = math::double3{0, 1, 0}) noexcept;

    math::mat4 getModelMatrix() const noexcept;

    //! Returns the camera's view matrix (inverse of the model matrix)
    math::mat4 getViewMatrix() const noexcept;

    //! Returns the camera's position in world space
    math::double3 getPosition() const noexcept;

    //! Returns the camera's normalized left vector
    math::float3 getLeftVector() const noexcept;

    //! Returns the camera's normalized up vector
    math::float3 getUpVector() const noexcept;

    //! Returns the camera's forward vector
    math::float3 getForwardVector() const noexcept;

    //! Returns the camera's field of view in degrees
    float getFieldOfViewInDegrees(Fov direction) const noexcept;

    //! Returns the camera's culling Frustum in world space
    class Frustum getFrustum() const noexcept;

    //! Returns the entity representing this camera
    utils::Entity getEntity() const noexcept;

    void setExposure(float aperture, float shutterSpeed, float sensitivity) noexcept;

    void setExposure(float exposure) noexcept {
        setExposure(1.0f, 1.2f, 100.0f * (1.0f / exposure));
    }

    //! returns this camera's aperture in f-stops
    float getAperture() const noexcept;

    //! returns this camera's shutter speed in seconds
    float getShutterSpeed() const noexcept;

    //! returns this camera's sensitivity in ISO
    float getSensitivity() const noexcept;

    double getFocalLength() const noexcept;

    void setFocusDistance(float distance) noexcept;

    //! Returns the focus distance in world units
    float getFocusDistance() const noexcept;

    static math::mat4 inverseProjection(const math::mat4& p) noexcept;

    static math::mat4f inverseProjection(const math::mat4f& p) noexcept;

    static double computeEffectiveFocalLength(double focalLength, double focusDistance) noexcept;

    static double computeEffectiveFov(double fovInDegrees, double focusDistance) noexcept;

protected:
    // prevent heap allocation
    ~Camera() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_CAMERA_H

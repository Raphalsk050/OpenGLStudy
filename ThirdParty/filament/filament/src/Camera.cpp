
#include "details/Camera.h"

#include "third_party/filament/libs/math/include/math/mat4.h"

namespace filament {

using namespace math;

void Camera::setProjection(double fovInDegrees, double aspect, double near, double far,
        Camera::Fov direction) {
    setCustomProjection(
            projection(direction, fovInDegrees, aspect, near),
            projection(direction, fovInDegrees, aspect, near, far),
            near, far);
}

void Camera::setLensProjection(double focalLengthInMillimeters,
        double aspect, double near, double far) {
    setCustomProjection(
            projection(focalLengthInMillimeters, aspect, near),
            projection(focalLengthInMillimeters, aspect, near, far),
            near, far);
}

mat4f Camera::inverseProjection(const mat4f& p) noexcept {
    return inverse(p);
}

mat4 Camera::inverseProjection(const mat4& p) noexcept {
    return inverse(p);
}

void Camera::setEyeModelMatrix(uint8_t eyeId, math::mat4 const& model) {
    downcast(this)->setEyeModelMatrix(eyeId, model);
}

void Camera::setCustomEyeProjection(math::mat4 const* projection, size_t count,
        math::mat4 const& projectionForCulling, double near, double far) {
    downcast(this)->setCustomEyeProjection(projection, count, projectionForCulling, near, far);
}

void Camera::setProjection(Camera::Projection projection, double left, double right, double bottom,
        double top, double near, double far) {
    downcast(this)->setProjection(projection, left, right, bottom, top, near, far);
}

void Camera::setCustomProjection(mat4 const& projection, double near, double far) noexcept {
    downcast(this)->setCustomProjection(projection, near, far);
}

void Camera::setCustomProjection(mat4 const& projection, mat4 const& projectionForCulling,
        double near, double far) noexcept {
    downcast(this)->setCustomProjection(projection, projectionForCulling, near, far);
}

void Camera::setScaling(double2 scaling) noexcept {
    downcast(this)->setScaling(scaling);
}

void Camera::setShift(double2 shift) noexcept {
    downcast(this)->setShift(shift);
}

mat4 Camera::getProjectionMatrix(uint8_t eyeId) const {
    return downcast(this)->getUserProjectionMatrix(eyeId);
}

mat4 Camera::getCullingProjectionMatrix() const noexcept {
    return downcast(this)->getUserCullingProjectionMatrix();
}

double4 Camera::getScaling() const noexcept {
    return downcast(this)->getScaling();
}

double2 Camera::getShift() const noexcept {
    return downcast(this)->getShift();
}

double Camera::getNear() const noexcept {
    return downcast(this)->getNear();
}

double Camera::getCullingFar() const noexcept {
    return downcast(this)->getCullingFar();
}

void Camera::setModelMatrix(const mat4& modelMatrix) noexcept {
    downcast(this)->setModelMatrix(modelMatrix);
}

void Camera::setModelMatrix(const mat4f& modelMatrix) noexcept {
    downcast(this)->setModelMatrix(modelMatrix);
}

void Camera::lookAt(double3 const& eye, double3 const& center, double3 const& up) noexcept {
    downcast(this)->lookAt(eye, center, up);
}

mat4 Camera::getModelMatrix() const noexcept {
    return downcast(this)->getModelMatrix();
}

mat4 Camera::getViewMatrix() const noexcept {
    return downcast(this)->getViewMatrix();
}

double3 Camera::getPosition() const noexcept {
    return downcast(this)->getPosition();
}

float3 Camera::getLeftVector() const noexcept {
    return downcast(this)->getLeftVector();
}

float3 Camera::getUpVector() const noexcept {
    return downcast(this)->getUpVector();
}

float3 Camera::getForwardVector() const noexcept {
    return downcast(this)->getForwardVector();
}

float Camera::getFieldOfViewInDegrees(Camera::Fov direction) const noexcept {
    return downcast(this)->getFieldOfViewInDegrees(direction);
}

Frustum Camera::getFrustum() const noexcept {
    return downcast(this)->getCullingFrustum();
}

utils::Entity Camera::getEntity() const noexcept {
    return downcast(this)->getEntity();
}

void Camera::setExposure(float aperture, float shutterSpeed, float ISO) noexcept {
    downcast(this)->setExposure(aperture, shutterSpeed, ISO);
}

float Camera::getAperture() const noexcept {
    return downcast(this)->getAperture();
}

float Camera::getShutterSpeed() const noexcept {
    return downcast(this)->getShutterSpeed();
}

float Camera::getSensitivity() const noexcept {
    return downcast(this)->getSensitivity();
}

void Camera::setFocusDistance(float distance) noexcept {
    downcast(this)->setFocusDistance(distance);
}

float Camera::getFocusDistance() const noexcept {
    return downcast(this)->getFocusDistance();
}

double Camera::getFocalLength() const noexcept {
    return downcast(this)->getFocalLength();
}

double Camera::computeEffectiveFocalLength(double focalLength, double focusDistance) noexcept {
    return FCamera::computeEffectiveFocalLength(focalLength, focusDistance);
}

double Camera::computeEffectiveFov(double fovInDegrees, double focusDistance) noexcept {
    return FCamera::computeEffectiveFov(fovInDegrees, focusDistance);
}

math::mat4 Camera::projection(Fov direction, double fovInDegrees,
        double aspect, double near, double far) {
    return FCamera::projection(direction, fovInDegrees, aspect, near, far);
}

math::mat4 Camera::projection(double focalLengthInMillimeters,
        double aspect, double near, double far) {
    return FCamera::projection(focalLengthInMillimeters, aspect, near, far);
}

} // namespace filament

#include "SceneCamera.h"

namespace GLStudy {

SceneCamera::SceneCamera() {
    RecalculateProjection();
}

SceneCamera::~SceneCamera() {
    if (engine_ && filament_camera_) {
        engine_->destroyCameraComponent(entity_);
        utils::EntityManager::get().destroy(entity_);
    }
}

void SceneCamera::CreateFilamentCamera(filament::Engine* engine) {
    if (filament_camera_)
        return;
    engine_ = engine;
    entity_ = utils::EntityManager::get().create();
    filament_camera_ = engine_->createCamera(entity_);
    RecalculateProjection();
}

void SceneCamera::SetPerspective(float fov, float near_clip, float far_clip) {
    projection_type_ = ProjectionType::Perspective;
    fov_ = fov;
    near_clip_ = near_clip;
    far_clip_ = far_clip;
    RecalculateProjection();
}

void SceneCamera::SetOrthographic(float size, float near_clip, float far_clip) {
    projection_type_ = ProjectionType::Orthographic;
    orthographic_size_ = size;
    near_clip_ = near_clip;
    far_clip_ = far_clip;
    RecalculateProjection();
}

void SceneCamera::SetViewportSize(float width, float height) {
    aspect_ratio_ = width / height;
    RecalculateProjection();
}

void SceneCamera::RecalculateProjection() {
    if (projection_type_ == ProjectionType::Perspective) {
        projection_matrix_ = glm::perspective(glm::radians(fov_), aspect_ratio_, near_clip_, far_clip_);
        if (filament_camera_)
            filament_camera_->setProjection(fov_, aspect_ratio_, near_clip_, far_clip_);
    } else {
        float orthoLeft = -orthographic_size_ * aspect_ratio_ * 0.5f;
        float orthoRight = orthographic_size_ * aspect_ratio_ * 0.5f;
        float orthoBottom = -orthographic_size_ * 0.5f;
        float orthoTop = orthographic_size_ * 0.5f;
        projection_matrix_ = glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop, near_clip_, far_clip_);
        if (filament_camera_)
            filament_camera_->setProjection(filament::Camera::Projection::ORTHO,
                    orthoLeft, orthoRight, orthoBottom, orthoTop, near_clip_, far_clip_);
    }
}

} // namespace GLStudy

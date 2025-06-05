#include "SceneCamera.h"
#include <gtc/matrix_transform.hpp>

namespace GLStudy {

SceneCamera::SceneCamera(ProjectionType type, float fov, float near_clip, float far_clip)
    : projection_type_(type), fov_(fov), near_clip_(near_clip), far_clip_(far_clip)
{
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
    } else {
        float orthoLeft = -orthographic_size_ * aspect_ratio_ * 0.5f;
        float orthoRight = orthographic_size_ * aspect_ratio_ * 0.5f;
        float orthoBottom = -orthographic_size_ * 0.5f;
        float orthoTop = orthographic_size_ * 0.5f;
        projection_matrix_ = glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop, near_clip_, far_clip_);
    }
}

}

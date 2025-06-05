#pragma once
#include "Camera.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace GLStudy {
    enum class ProjectionType {
        Perspective = 0,
        Orthographic = 1
    };

    class SceneCamera : public Camera {
    public:
        SceneCamera();

        void SetPerspective(float fov, float near_clip, float far_clip);
        void SetOrthographic(float size, float near_clip, float far_clip);
        void SetViewportSize(float width, float height);

        float GetFOV() const { return fov_; }
        float GetNearClip() const { return near_clip_; }
        float GetFarClip() const { return far_clip_; }
        ProjectionType GetProjectionType() const { return projection_type_; }

    private:
        ProjectionType projection_type_ = ProjectionType::Perspective;
        float aspect_ratio_ = 1.0f;
        float fov_ = 60.0f;
        float orthographic_size_ = 10.0f;
        float near_clip_ = 0.03f;
        float far_clip_ = 1000.0f;

        void RecalculateProjection();
    };
}

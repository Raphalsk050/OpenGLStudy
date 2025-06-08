#pragma once
#include "Camera.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <filament/Camera.h>
#include <utils/Entity.h>
#include <utils/EntityManager.h>

namespace GLStudy {
    enum class ProjectionType {
        Perspective = 0,
        Orthographic = 1
    };

    // Camera component using Filament camera internally
    class SceneCamera : public Camera {
    public:
        SceneCamera();
        ~SceneCamera();

        void CreateFilamentCamera(filament::Engine* engine);
        filament::Camera* GetFilamentCamera() const { return filament_camera_; }

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

        filament::Engine* engine_ = nullptr;
        utils::Entity entity_{};
        filament::Camera* filament_camera_ = nullptr;

        void RecalculateProjection();
    };
}

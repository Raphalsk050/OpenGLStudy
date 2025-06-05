#pragma once
#include "Camera.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace GLStudy {
    class EditorCamera : public Camera {
    public:
        EditorCamera() = default;

        void SetPosition(const glm::vec3& position) { position_ = position; RecalculateView(); }
        void SetRotation(const glm::vec3& rotation) { rotation_ = rotation; RecalculateView(); }

        const glm::vec3& GetPosition() const { return position_; }
        const glm::vec3& GetRotation() const { return rotation_; }

    private:
        glm::vec3 position_{0.0f};
        glm::vec3 rotation_{0.0f};

        void RecalculateView();
    };
}

#pragma once
#include <glm.hpp>

namespace GLStudy {
    class Camera {
    public:
        virtual ~Camera() = default;

        const glm::mat4& GetProjection() const { return projection_matrix_; }
        const glm::mat4& GetView() const { return view_matrix_; }
        glm::mat4 GetViewProjection() const { return projection_matrix_ * view_matrix_; }

    protected:
        glm::mat4 projection_matrix_{1.0f};
        glm::mat4 view_matrix_{1.0f};
    };
}

#include "EditorCamera.h"

namespace GLStudy {

void EditorCamera::RecalculateView() {
    glm::mat4 transform(1.0f);
    transform = glm::translate(transform, position_);
    transform = glm::rotate(transform, rotation_.x, glm::vec3(1.0f, 0.0f, 0.0f));
    transform = glm::rotate(transform, rotation_.y, glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, rotation_.z, glm::vec3(0.0f, 0.0f, 1.0f));
    view_matrix_ = glm::inverse(transform);
}

}

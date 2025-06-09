#pragma once
#include "gtc/quaternion.hpp"
#include "LinearMath/btTransform.h"

static btTransform ConvertMat4ToBtTransform(const glm::mat4& mat)
{
    glm::vec3 position{ mat[3].x, mat[3].y, mat[3].z };

    glm::quat   rotQuat = glm::quat_cast(mat);
    btQuaternion btQuat(rotQuat.x, rotQuat.y, rotQuat.z, rotQuat.w);

    btTransform transform;
    transform.setOrigin(btVector3(position.x, position.y, position.z));
    transform.setRotation(btQuat);

    return transform;
}

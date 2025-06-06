#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 4) in mat4 aModelTransform;

uniform mat4 u_LightSpaceMatrix;

void main()
{
    gl_Position = u_LightSpaceMatrix * aModelTransform * vec4(aPos, 1.0);
}

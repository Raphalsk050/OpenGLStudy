#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in mat4 aModel;
layout(location = 5) in vec4 aColor;

uniform mat4 u_ViewProjection;

out vec4 vColor;

void main()
{
    gl_Position = u_ViewProjection * aModel * vec4(aPos, 1.0);
    vColor = aColor;
}
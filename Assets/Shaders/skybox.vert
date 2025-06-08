#version 330 core
layout(location = 0) in vec3 aPos;

out vec3 vPos;

uniform mat4 u_ViewProjection;

void main()
{
    vPos = aPos;
    gl_Position = u_ViewProjection * vec4(aPos, 1.0);
}

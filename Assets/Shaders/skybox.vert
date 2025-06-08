#version 330 core
layout(location = 0) in vec3 aPos;
uniform mat4 u_View;
uniform mat4 u_Projection;
out vec3 vTexCoord;
void main() {
    vTexCoord = aPos;
    vec4 pos = u_Projection * u_View * vec4(aPos, 1.0);
    gl_Position = pos.xyww;
}

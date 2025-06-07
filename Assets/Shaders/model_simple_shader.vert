#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec3 aTangent;
layout(location = 3) in vec2 aTexCoord;

uniform mat4 u_ViewProjection;
uniform mat4 u_Model;

out vec4 vColor;
out vec3 vNormal;
out vec3 vPos;
out vec2 vTexCoord;

void main()
{
    vec4 worldPos = u_Model * vec4(aPos, 1.0);
    vNormal = mat3(transpose(inverse(u_Model))) * aNormal;
    gl_Position = u_ViewProjection * worldPos;
    vPos = worldPos.xyz;
    vColor = vec4(1.0);
    vTexCoord = aTexCoord;
}

#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec3 aTangent;
layout(location = 3) in vec2 aTexCoord;
layout(location = 4) in mat4 aModelTransform;
layout(location = 8) in vec4 aColor;

uniform mat4 u_ViewProjection;
uniform mat4 u_Model;

out vec3 vPos;
out vec3 vNormal;
out vec3 vTangent;
out vec4 vColor;
out vec2 vTexCoord;

void main()
{
    vec4 worldPos = u_Model * aModelTransform * vec4(aPos, 1.0);
    mat3 normalMatrix = mat3(transpose(inverse(u_Model * aModelTransform)));
    vPos = worldPos.xyz;
    vNormal = normalMatrix * aNormal;
    vTangent = normalMatrix * aTangent;
    vColor = aColor;
    vTexCoord = aTexCoord;
    gl_Position = u_ViewProjection * worldPos;
}

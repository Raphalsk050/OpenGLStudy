#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec3 aTangent;
layout(location = 3) in vec2 aTexCoord;
layout(location = 4) in mat4 aModelTransform;
layout(location = 8) in vec4 aColor;

uniform mat4 u_ViewProjection;
uniform mat4 u_LightSpaceMatrix;

out vec3 vPos;
out vec3 vNormal;
out vec4 vColor;
out vec4 vFragPosLightSpace;

void main()
{
    vec4 worldPos = aModelTransform * vec4(aPos, 1.0);
    vPos = worldPos.xyz;
    vNormal = mat3(transpose(inverse(aModelTransform))) * aNormal;
    vColor = aColor;
    vFragPosLightSpace = u_LightSpaceMatrix * worldPos;
    gl_Position = u_ViewProjection * worldPos;
}

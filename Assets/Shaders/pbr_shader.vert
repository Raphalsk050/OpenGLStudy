#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec3 aTangent;
layout(location = 3) in vec2 aTexCoord;
layout(location = 4) in mat4 aModelTransform;
layout(location = 8) in vec4 aColor;
uniform vec4 u_Color;

uniform mat4 u_ViewProjection;
uniform mat4 u_Model;
uniform bool u_UseInstance;

out vec3 vPos;
out vec3 vNormal;
out vec4 vColor;

void main()
{
    mat4 model = u_UseInstance ? aModelTransform : u_Model;
    vec4 worldPos = model * vec4(aPos, 1.0);
    vPos = worldPos.xyz;
    vNormal = mat3(transpose(inverse(model))) * aNormal;
    vColor = u_UseInstance ? aColor : u_Color;
    gl_Position = u_ViewProjection * worldPos;
}

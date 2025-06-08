#version 330 core
out vec4 FragColor;

in vec3 vPos;

uniform sampler2D u_Skybox;

const vec2 invAtan = vec2(0.1591, 0.3183);
vec2 sampleSphericalMap(vec3 v)
{
    vec2 uv = vec2(atan(v.z, v.x), asin(v.y));
    uv *= invAtan;
    uv += 0.5;
    return uv;
}

void main()
{
    vec2 uv = sampleSphericalMap(normalize(vPos));
    vec3 color = texture(u_Skybox, uv).rgb;
    FragColor = vec4(color, 1.0);
}

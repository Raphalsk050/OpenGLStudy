#version 330 core
in vec4 vColor;
in vec3 vNormal;
in vec3 vPos;

out vec4 FragColor;

vec3 vAmbientLightColor = vec3(1.0f,1.0f,1.0f);
float ambientLightIntensity = 0.2f;
vec3 vLightPosition = vec3(0.0f,1.0f,0.0f);
float pointLightIntensity = 1.0f;

void main()
{
    // Normalize the normal
    vec3 normal = normalize(vNormal);
    vec3 lightDir = normalize(vLightPosition - vPos);
    float NdotL = max(dot(lightDir, normal),0.0f);

    vec3 ambientLight = vAmbientLightColor * ambientLightIntensity;
    vec3 diffuse = vec3(NdotL) * vec3(pointLightIntensity);
    vec3 lighting = ambientLight + diffuse;

    FragColor.xyz = vColor.xyz * lighting;
    FragColor.a = 1.0f;
}
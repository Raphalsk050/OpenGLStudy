#version 330 core
in vec3 vPos;
in vec3 vNormal;
in vec4 vColor;

out vec4 FragColor;

struct Light {
    int type;
    vec3 position;
    vec3 direction;
    vec3 color;
    float intensity;
    float range;
    float innerCutoff;
    float outerCutoff;
};

#define MAX_LIGHTS 4
uniform int u_NumLights;
uniform Light u_Lights[MAX_LIGHTS];
uniform vec3 u_CamPos;

const float PI = 3.14159265359;

float DistributionGGX(vec3 N, vec3 H, float roughness)
{
    float a = roughness*roughness;
    float a2 = a*a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH*NdotH;

    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    return a2 / (PI * denom * denom);
}

float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float denom = NdotV * (1.0 - k) + k;
    return NdotV / denom;
}

float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);
    return ggx1 * ggx2;
}

vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(1.0 - cosTheta, 5.0);
}

void main()
{
    vec3 albedo = vColor.rgb;
    float metallic = 0.8;
    float roughness = 0.3;
    vec3 N = normalize(vNormal);
    vec3 V = normalize(u_CamPos - vPos);
    vec3 F0 = mix(vec3(0.04), albedo, metallic);

    vec3 Lo = vec3(0.0);
    for(int i = 0; i < u_NumLights; ++i)
    {
        vec3 L;
        float attenuation = 1.0;
        if(u_Lights[i].type == 0)
        {
            L = normalize(-u_Lights[i].direction);
        }
        else
        {
            vec3 toLight = u_Lights[i].position - vPos;
            L = normalize(toLight);
            float dist = length(toLight);
            attenuation = 1.0 / (dist * dist);
            if(u_Lights[i].type == 2)
            {
                float theta = dot(L, normalize(-u_Lights[i].direction));
                float epsilon = u_Lights[i].innerCutoff - u_Lights[i].outerCutoff;
                float intensity = clamp((theta - u_Lights[i].outerCutoff) / epsilon, 0.0, 1.0);
                attenuation *= intensity;
            }
        }
        vec3 H = normalize(V + L);
        vec3 radiance = u_Lights[i].color * u_Lights[i].intensity * attenuation;

        float NDF = DistributionGGX(N, H, roughness);
        float G = GeometrySmith(N, V, L, roughness);
        vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

        vec3 nominator = NDF * G * F;
        float denom = 4.0 * max(dot(N,V), 0.0) * max(dot(N,L), 0.0) + 0.001;
        vec3 specular = nominator / denom;

        vec3 kS = F;
        vec3 kD = vec3(1.0) - kS;
        kD *= 1.0 - metallic;

        float NdotL = max(dot(N, L), 0.0);
        Lo += (kD * albedo / PI + specular) * radiance * NdotL;
    }
    vec3 ambient = vec3(0.03) * albedo;
    vec3 color = ambient + Lo;
    color = pow(color, vec3(1.0/2.2));
    FragColor = vec4(color, 1.0);
}

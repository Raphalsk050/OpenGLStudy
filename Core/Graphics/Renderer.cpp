#include "Renderer.h"
#include <gtc/type_ptr.hpp>
#include <cmath>

namespace GLStudy {

static void SetupVertexAttributes()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, position));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, normal));
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, tangent));
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, texcoord));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
}

Renderer::MeshRenderData& Renderer::GetOrCreateMeshData(const std::string& key,
                                              const std::vector<VertexData>& vertices,
                                              const std::vector<unsigned int>& indices)
{
    auto it = meshes_.find(key);
    if(it != meshes_.end())
        return it->second;

    MeshRenderData data{};
    data.vao = std::make_unique<VertexArray>();
    data.vao->Bind();
    if(!vertices.empty())
    {
        data.vbo = std::make_unique<VertexBuffer>(vertices.data(), vertices.size()*sizeof(VertexData));
        data.ibo = std::make_unique<IndexBuffer>(indices.data(), indices.size());
        SetupVertexAttributes();
    }
    data.instance_vbo = std::make_unique<VertexBuffer>(nullptr, sizeof(InstanceData)*1000, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(4,4,GL_FLOAT,GL_FALSE,sizeof(InstanceData),(void*)offsetof(InstanceData,model));
    glVertexAttribPointer(5,4,GL_FLOAT,GL_FALSE,sizeof(InstanceData),(void*)(offsetof(InstanceData,model)+sizeof(glm::vec4)));
    glVertexAttribPointer(6,4,GL_FLOAT,GL_FALSE,sizeof(InstanceData),(void*)(offsetof(InstanceData,model)+sizeof(glm::vec4)*2));
    glVertexAttribPointer(7,4,GL_FLOAT,GL_FALSE,sizeof(InstanceData),(void*)(offsetof(InstanceData,model)+sizeof(glm::vec4)*3));
    glVertexAttribPointer(8,4,GL_FLOAT,GL_FALSE,sizeof(InstanceData),(void*)offsetof(InstanceData,color));
    glEnableVertexAttribArray(4);
    glEnableVertexAttribArray(5);
    glEnableVertexAttribArray(6);
    glEnableVertexAttribArray(7);
    glEnableVertexAttribArray(8);
    glVertexAttribDivisor(4,1);
    glVertexAttribDivisor(5,1);
    glVertexAttribDivisor(6,1);
    glVertexAttribDivisor(7,1);
    glVertexAttribDivisor(8,1);
    data.vao->Unbind();
    data.index_count = indices.size();
    auto [iter,_] = meshes_.emplace(key, std::move(data));
    return iter->second;
}

static void GeneratePlane(std::vector<VertexData>& verts, std::vector<unsigned int>& idx)
{
    verts.resize(4);
    verts[0].position = {-0.5f,0.0f, 0.5f};
    verts[1].position = { 0.5f,0.0f, 0.5f};
    verts[2].position = { 0.5f,0.0f,-0.5f};
    verts[3].position = {-0.5f,0.0f,-0.5f};
    for(int i=0;i<4;i++)
    {
        verts[i].normal = {0,1,0};
        verts[i].tangent = {1,0,0};
        verts[i].texcoord = {(i==1||i==2)?1.0f:0.0f, (i>=2)?0.0f:1.0f};
    }
    idx = {0,1,2,2,3,0};
}

static void GenerateSphere(std::vector<VertexData>& verts, std::vector<unsigned int>& idx, int lat=16, int lon=16)
{
    for(int y=0;y<=lat;y++)
    {
        for(int x=0;x<=lon;x++)
        {
            float xSeg = (float)x/(float)lon;
            float ySeg = (float)y/(float)lat;
            float xPos = std::cos(xSeg*2*M_PI)*std::sin(ySeg*M_PI);
            float yPos = std::cos(ySeg*M_PI);
            float zPos = std::sin(xSeg*2*M_PI)*std::sin(ySeg*M_PI);
            VertexData v{};
            v.position = {xPos,yPos,zPos};
            v.normal = glm::normalize(v.position);
            glm::vec3 t = glm::cross(glm::vec3(0,1,0), v.normal);
            if(glm::length(t)<0.001f) t = glm::cross(glm::vec3(1,0,0),v.normal);
            v.tangent = glm::normalize(t);
            v.texcoord = {xSeg,ySeg};
            verts.push_back(v);
        }
    }
    for(int y=0;y<lat;y++)
    {
        for(int x=0;x<lon;x++)
        {
            int i0 = y*(lon+1)+x;
            int i1 = i0 + lon +1;
            idx.push_back(i0);
            idx.push_back(i1);
            idx.push_back(i0+1);
            idx.push_back(i1);
            idx.push_back(i1+1);
            idx.push_back(i0+1);
        }
    }
}

static void GenerateCapsule(std::vector<VertexData>& verts, std::vector<unsigned int>& idx)
{
    int lat=8, lon=16; float halfH=0.5f;
    // upper hemisphere
    for(int y=0;y<=lat;y++)
    {
        float v = (float)y/(float)lat;
        float phi = v*M_PI/2.0f;
        for(int x=0;x<=lon;x++)
        {
            float u = (float)x/(float)lon;
            float theta = u*2*M_PI;
            float xPos = std::cos(theta)*std::sin(phi);
            float yPos = std::cos(phi)+halfH;
            float zPos = std::sin(theta)*std::sin(phi);
            VertexData vert{};
            vert.position={xPos,yPos,zPos};
            vert.normal=glm::normalize(glm::vec3(xPos, std::cos(phi), zPos));
            glm::vec3 t = glm::cross(glm::vec3(0,1,0), vert.normal);
            if(glm::length(t)<0.001f) t = glm::cross(glm::vec3(1,0,0),vert.normal);
            vert.tangent = glm::normalize(t);
            vert.texcoord={u,v/2};
            verts.push_back(vert);
        }
    }
    int baseOffset = (lat+1)*(lon+1);
    // lower hemisphere
    for(int y=0;y<=lat;y++)
    {
        float v = (float)y/(float)lat;
        float phi = v*M_PI/2.0f;
        for(int x=0;x<=lon;x++)
        {
            float u = (float)x/(float)lon;
            float theta = u*2*M_PI;
            float xPos = std::cos(theta)*std::sin(phi);
            float yPos = -std::cos(phi)-halfH;
            float zPos = std::sin(theta)*std::sin(phi);
            VertexData vert{};
            vert.position={xPos,yPos,zPos};
            vert.normal=glm::normalize(glm::vec3(xPos,-std::cos(phi),zPos));
            glm::vec3 t = glm::cross(glm::vec3(0,1,0), vert.normal);
            if(glm::length(t)<0.001f) t = glm::cross(glm::vec3(1,0,0),vert.normal);
            vert.tangent = glm::normalize(t);
            vert.texcoord={u,1.0f - v/2};
            verts.push_back(vert);
        }
    }

    // indices for hemisphere and cylinder
    for(int y=0;y<lat;y++)
    {
        for(int x=0;x<lon;x++)
        {
            int i0 = y*(lon+1)+x;
            int i1 = i0 + lon +1;
            idx.push_back(i0);
            idx.push_back(i1);
            idx.push_back(i0+1);
            idx.push_back(i1);
            idx.push_back(i1+1);
            idx.push_back(i0+1);

            int j0 = baseOffset + y*(lon+1)+x;
            int j1 = j0 + lon +1;
            idx.push_back(j0);
            idx.push_back(j0+1);
            idx.push_back(j1);
            idx.push_back(j1);
            idx.push_back(j0+1);
            idx.push_back(j1+1);
        }
    }

    // cylinder between hemispheres
    int startA = lat*(lon+1)+lon+1; // top ring start index (latth row? Wait illusions). but to keep simple we use bridging.
    for(int x=0;x<lon;x++)
    {
        int top0 = lat*(lon+1)+x;
        int top1 = top0+1;
        int bottom0 = baseOffset + x;
        int bottom1 = bottom0+1;
        idx.push_back(top0);
        idx.push_back(bottom0);
        idx.push_back(top1);
        idx.push_back(top1);
        idx.push_back(bottom0);
        idx.push_back(bottom1);
    }
}

void Renderer::InitDefaultMeshes()
{
    // Triangle
    std::vector<VertexData> v; std::vector<unsigned int> i;
    v = {
        {{-0.5f,-0.5f,0.0f},{0,0,1},{1,0,0},{0,0}},
        {{ 0.5f,-0.5f,0.0f},{0,0,1},{1,0,0},{1,0}},
        {{ 0.0f, 0.5f,0.0f},{0,0,1},{1,0,0},{0.5f,1}}
    };
    i = {0,1,2};
    GetOrCreateMeshData("Triangle",v,i);

    // Cube (existing data from old implementation)
    std::vector<VertexData> cube_v={
        {{-0.5f,-0.5f,0.5f},{0,0,1},{1,0,0},{0,0}},
        {{0.5f,-0.5f,0.5f},{0,0,1},{1,0,0},{1,0}},
        {{0.5f,0.5f,0.5f},{0,0,1},{1,0,0},{1,1}},
        {{-0.5f,0.5f,0.5f},{0,0,1},{1,0,0},{0,1}},
        {{-0.5f,-0.5f,-0.5f},{0,0,-1},{-1,0,0},{1,0}},
        {{-0.5f,0.5f,-0.5f},{0,0,-1},{-1,0,0},{1,1}},
        {{0.5f,0.5f,-0.5f},{0,0,-1},{-1,0,0},{0,1}},
        {{0.5f,-0.5f,-0.5f},{0,0,-1},{-1,0,0},{0,0}},
        {{-0.5f,-0.5f,-0.5f},{-1,0,0},{0,0,-1},{0,0}},
        {{-0.5f,-0.5f,0.5f},{-1,0,0},{0,0,-1},{1,0}},
        {{-0.5f,0.5f,0.5f},{-1,0,0},{0,0,-1},{1,1}},
        {{-0.5f,0.5f,-0.5f},{-1,0,0},{0,0,-1},{0,1}},
        {{0.5f,-0.5f,0.5f},{1,0,0},{0,0,1},{0,0}},
        {{0.5f,-0.5f,-0.5f},{1,0,0},{0,0,1},{1,0}},
        {{0.5f,0.5f,-0.5f},{1,0,0},{0,0,1},{1,1}},
        {{0.5f,0.5f,0.5f},{1,0,0},{0,0,1},{0,1}},
        {{-0.5f,-0.5f,-0.5f},{0,-1,0},{1,0,0},{0,0}},
        {{0.5f,-0.5f,-0.5f},{0,-1,0},{1,0,0},{1,0}},
        {{0.5f,-0.5f,0.5f},{0,-1,0},{1,0,0},{1,1}},
        {{-0.5f,-0.5f,0.5f},{0,-1,0},{1,0,0},{0,1}},
        {{-0.5f,0.5f,0.5f},{0,1,0},{1,0,0},{0,0}},
        {{0.5f,0.5f,0.5f},{0,1,0},{1,0,0},{1,0}},
        {{0.5f,0.5f,-0.5f},{0,1,0},{1,0,0},{1,1}},
        {{-0.5f,0.5f,-0.5f},{0,1,0},{1,0,0},{0,1}}
    };
    std::vector<unsigned int> cube_i={
        0,1,2,2,3,0,
        4,5,6,6,7,4,
        8,9,10,10,11,8,
        12,13,14,14,15,12,
        16,17,18,18,19,16,
        20,21,22,22,23,20
    };
    GetOrCreateMeshData("Cube",cube_v,cube_i);

    // Plane
    std::vector<VertexData> p_v; std::vector<unsigned int> p_i; GeneratePlane(p_v,p_i); GetOrCreateMeshData("Plane",p_v,p_i);

    // Sphere
    std::vector<VertexData> s_v; std::vector<unsigned int> s_i; GenerateSphere(s_v,s_i); GetOrCreateMeshData("Sphere",s_v,s_i);

    // Capsule
    std::vector<VertexData> c_v; std::vector<unsigned int> c_i; GenerateCapsule(c_v,c_i); GetOrCreateMeshData("Capsule",c_v,c_i);
}

void Renderer::Init()
{
    shader_prog_ = Shader::CreateShaderProgram("Assets/Shaders/pbr_shader.vert", "Assets/Shaders/pbr_shader.frag");
    glUseProgram(shader_prog_);
    view_proj_location_ = glGetUniformLocation(shader_prog_, "u_ViewProjection");
    cam_pos_location_ = glGetUniformLocation(shader_prog_, "u_CamPos");
    num_lights_location_ = glGetUniformLocation(shader_prog_, "u_NumLights");
    InitDefaultMeshes();
}

void Renderer::DrawMesh(MeshType type, const glm::mat4& model, const glm::vec4& color, const std::string& path)
{
    std::string key;
    if(type == MeshType::Model)
    {
        key = path;
        if(meshes_.find(key) == meshes_.end())
        {
            std::vector<VertexData> verts; std::vector<unsigned int> inds;
            if(ModelLoader::LoadOBJ(path, verts, inds))
                GetOrCreateMeshData(key, verts, inds);
            else
                return;
        }
    }
    else
    {
        switch(type)
        {
            case MeshType::Triangle: key="Triangle"; break;
            case MeshType::Cube: key="Cube"; break;
            case MeshType::Sphere: key="Sphere"; break;
            case MeshType::Capsule: key="Capsule"; break;
            case MeshType::Plane: key="Plane"; break;
            default: key="Triangle"; break;
        }
    }
    auto& data = meshes_[key];
    data.instances.push_back({model,color});
}

void Renderer::BeginScene(const glm::mat4& view_projection,const glm::vec3& cam_pos,const std::vector<LightData>& lights)
{
    view_projection_ = view_projection;
    camera_pos_ = cam_pos;
    lights_ = lights;
}

void Renderer::Flush()
{
    glUseProgram(shader_prog_);
    glUniformMatrix4fv(view_proj_location_,1,GL_FALSE,glm::value_ptr(view_projection_));
    glUniform3fv(cam_pos_location_,1,glm::value_ptr(camera_pos_));
    glUniform1i(num_lights_location_, static_cast<int>(lights_.size()));
    for(size_t i=0;i<lights_.size() && i<4;++i)
    {
        std::string base = "u_Lights["+std::to_string(i)+"]";
        glUniform1i(glGetUniformLocation(shader_prog_,(base+".type").c_str()),static_cast<int>(lights_[i].type));
        glUniform3fv(glGetUniformLocation(shader_prog_,(base+".position").c_str()),1,glm::value_ptr(lights_[i].position));
        glUniform3fv(glGetUniformLocation(shader_prog_,(base+".direction").c_str()),1,glm::value_ptr(lights_[i].direction));
        glUniform3fv(glGetUniformLocation(shader_prog_,(base+".color").c_str()),1,glm::value_ptr(lights_[i].color));
        glUniform1f(glGetUniformLocation(shader_prog_,(base+".intensity").c_str()),lights_[i].intensity);
        glUniform1f(glGetUniformLocation(shader_prog_,(base+".range").c_str()),lights_[i].range);
        glUniform1f(glGetUniformLocation(shader_prog_,(base+".innerCutoff").c_str()),lights_[i].inner_cutoff);
        glUniform1f(glGetUniformLocation(shader_prog_,(base+".outerCutoff").c_str()),lights_[i].outer_cutoff);
    }

    for(auto& [key,data] : meshes_)
    {
        if(data.instances.empty()) continue;
        data.vao->Bind();
        data.instance_vbo->SetData(data.instances.data(), data.instances.size()*sizeof(InstanceData));
        glDrawElementsInstanced(GL_TRIANGLES, data.index_count, GL_UNSIGNED_INT, nullptr, data.instances.size());
        data.instances.clear();
    }
}

} // namespace GLStudy

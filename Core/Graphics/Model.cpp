#include "Model.h"
#include "Texture.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace GLStudy {

static GLuint LoadMatTex(aiMaterial* mat, aiTextureType type, const std::string& dir) {
    if(mat->GetTextureCount(type) > 0) {
        aiString str;
        mat->GetTexture(type, 0, &str);
        std::string path = dir + "/" + std::string(str.C_Str());
        return Texture::LoadTexture2D(path);
    }
    return 0;
}

Model::Model(const std::string& path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path,
        aiProcess_Triangulate | aiProcess_GenNormals |
        aiProcess_CalcTangentSpace | aiProcess_FlipUVs);
    if(!scene || !scene->mRootNode) return;
    directory_ = path.substr(0, path.find_last_of('/'));
    materials_.reserve(scene->mNumMaterials);
    for(unsigned int i=0;i<scene->mNumMaterials;++i) {
        aiMaterial* aiMat = scene->mMaterials[i];
        Material mat;
        int shading;
        if(aiMat->Get(AI_MATKEY_SHADING_MODEL, shading) == AI_SUCCESS && shading == aiShadingMode_Unlit)
            mat.shading = MaterialShading::Unlit;
        float opacity = 1.0f;
        aiMat->Get(AI_MATKEY_OPACITY, opacity);
        mat.opaque = opacity >= 1.0f;
        mat.transparent = opacity < 1.0f;
        mat.albedo_texture = LoadMatTex(aiMat, aiTextureType_BASE_COLOR, directory_);
        if(!mat.albedo_texture) mat.albedo_texture = LoadMatTex(aiMat, aiTextureType_DIFFUSE, directory_);
        mat.has_albedo = mat.albedo_texture != 0;
        mat.normal_texture = LoadMatTex(aiMat, aiTextureType_NORMALS, directory_);
        mat.has_normal = mat.normal_texture != 0;
        mat.specular_texture = LoadMatTex(aiMat, aiTextureType_SPECULAR, directory_);
        mat.has_specular = mat.specular_texture != 0;
        mat.ao_texture = LoadMatTex(aiMat, aiTextureType_AMBIENT_OCCLUSION, directory_);
        mat.has_ao = mat.ao_texture != 0;
        mat.roughness_texture = LoadMatTex(aiMat, aiTextureType_DIFFUSE_ROUGHNESS, directory_);
        mat.has_roughness = mat.roughness_texture != 0;
        mat.emissive_texture = LoadMatTex(aiMat, aiTextureType_EMISSIVE, directory_);
        mat.has_emissive = mat.emissive_texture != 0;
        materials_.push_back(mat);
    }
    ProcessNode(scene->mRootNode, scene);
}

void Model::ProcessNode(aiNode* node, const aiScene* scene) {
    for(unsigned int i=0;i<node->mNumMeshes;++i) {
        meshes_.push_back(ProcessMesh(scene->mMeshes[node->mMeshes[i]], scene));
    }
    for(unsigned int i=0;i<node->mNumChildren;++i) {
        ProcessNode(node->mChildren[i], scene);
    }
}

Mesh Model::ProcessMesh(aiMesh* mesh, const aiScene* scene) {
    struct Vertex { glm::vec3 pos; glm::vec3 normal; glm::vec3 tangent; glm::vec2 tex; };
    std::vector<Vertex> vertices(mesh->mNumVertices);
    for(unsigned int i=0;i<mesh->mNumVertices;i++) {
        vertices[i].pos = {mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z};
        vertices[i].normal = mesh->HasNormals() ? glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z) : glm::vec3(0.0f);
        vertices[i].tangent = mesh->HasTangentsAndBitangents() ? glm::vec3(mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z) : glm::vec3(0.0f);
        if(mesh->HasTextureCoords(0))
            vertices[i].tex = {mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y};
        else
            vertices[i].tex = glm::vec2(0.0f);
    }
    std::vector<unsigned int> indices;
    for(unsigned int i=0;i<mesh->mNumFaces;i++) {
        const aiFace& face = mesh->mFaces[i];
        for(unsigned int j=0;j<face.mNumIndices;j++)
            indices.push_back(face.mIndices[j]);
    }
    Mesh m;
    m.vao = std::make_unique<VertexArray>();
    m.vao->Bind();
    m.vbo = std::make_unique<VertexBuffer>(vertices.data(), vertices.size() * sizeof(Vertex));
    m.ibo = std::make_unique<IndexBuffer>(indices.data(), indices.size());
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,pos));
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,normal));
    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,tangent));
    glVertexAttribPointer(3,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,tex));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    m.vao->Unbind();
    m.index_count = indices.size();
    m.material_index = mesh->mMaterialIndex;
    return m;
}

}

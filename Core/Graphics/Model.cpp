#include "Model.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace GLStudy {
Model::Model(const std::string& path) {
    LoadModel(path);
}

void Model::LoadModel(const std::string& path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path,
        aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_CalcTangentSpace | aiProcess_FlipUVs);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        return;
    directory_ = path.substr(0, path.find_last_of('/'));
    ProcessNode(scene->mRootNode, scene);
}

void Model::ProcessNode(aiNode* node, const aiScene* scene) {
    for(unsigned int i=0;i<node->mNumMeshes;i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes_.push_back(ProcessMesh(mesh, scene));
    }
    for(unsigned int i=0;i<node->mNumChildren;i++)
        ProcessNode(node->mChildren[i], scene);
}

Mesh Model::ProcessMesh(aiMesh* mesh, const aiScene* scene) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    vertices.reserve(mesh->mNumVertices);
    for(unsigned int i=0;i<mesh->mNumVertices;i++) {
        Vertex v{};
        v.position = {mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z};
        if(mesh->HasNormals())
            v.normal = {mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z};
        if(mesh->HasTangentsAndBitangents())
            v.tangent = {mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z};
        if(mesh->mTextureCoords[0])
            v.texcoord = {mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y};
        vertices.push_back(v);
    }
    for(unsigned int i=0;i<mesh->mNumFaces;i++) {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j=0;j<face.mNumIndices;j++)
            indices.push_back(face.mIndices[j]);
    }
    Mesh m;
    m.index_count = indices.size();
    m.vao = std::make_unique<VertexArray>();
    m.vao->Bind();
    m.vbo = std::make_unique<VertexBuffer>(vertices.data(), vertices.size()*sizeof(Vertex));
    m.ibo = std::make_unique<IndexBuffer>(indices.data(), indices.size());
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,position));
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,normal));
    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,tangent));
    glVertexAttribPointer(3,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,texcoord));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    m.vao->Unbind();
    if(mesh->mMaterialIndex >= 0)
        m.material = LoadMaterial(scene->mMaterials[mesh->mMaterialIndex]);
    return m;
}

Material Model::LoadMaterial(aiMaterial* mat) {
    Material material;
    aiString str;
    if(mat->GetTexture(aiTextureType_DIFFUSE,0,&str) == AI_SUCCESS){
        std::string path = directory_ + "/" + std::string(str.C_Str());
        material.albedo = std::make_shared<Texture2D>(path);
    }
    if(mat->GetTexture(aiTextureType_NORMALS,0,&str) == AI_SUCCESS){
        std::string path = directory_ + "/" + std::string(str.C_Str());
        material.normal = std::make_shared<Texture2D>(path);
    }
    if(mat->GetTexture(aiTextureType_SPECULAR,0,&str) == AI_SUCCESS){
        std::string path = directory_ + "/" + std::string(str.C_Str());
        material.specular = std::make_shared<Texture2D>(path);
    }
    if(mat->GetTexture(aiTextureType_AMBIENT_OCCLUSION,0,&str) == AI_SUCCESS){
        std::string path = directory_ + "/" + std::string(str.C_Str());
        material.ao = std::make_shared<Texture2D>(path);
    }
    if(mat->GetTexture(aiTextureType_DIFFUSE_ROUGHNESS,0,&str) == AI_SUCCESS){
        std::string path = directory_ + "/" + std::string(str.C_Str());
        material.roughness = std::make_shared<Texture2D>(path);
    }
    if(mat->GetTexture(aiTextureType_EMISSIVE,0,&str) == AI_SUCCESS){
        std::string path = directory_ + "/" + std::string(str.C_Str());
        material.emissive_map = std::make_shared<Texture2D>(path);
    }
    return material;
}
}

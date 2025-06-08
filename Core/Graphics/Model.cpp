#include "Model.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <filesystem>
#include <iostream>
#include <cstdlib>

namespace GLStudy {

bool Model::LoadModel(const std::string& path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(
        path,
        aiProcess_Triangulate |
        aiProcess_GenSmoothNormals |
        aiProcess_CalcTangentSpace |
        aiProcess_PreTransformVertices);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "Assimp error: " << importer.GetErrorString() << std::endl;
        return false;
    }
    directory_ = path.substr(0, path.find_last_of('/'));
    meshes_.clear();
    ProcessNode(scene->mRootNode, scene);
    return true;
}

void Model::ProcessNode(aiNode* node, const aiScene* scene) {
    for(unsigned int i=0;i<node->mNumMeshes;i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes_.push_back(ProcessMesh(mesh, scene));
    }
    for(unsigned int i=0;i<node->mNumChildren;i++) {
        ProcessNode(node->mChildren[i], scene);
    }
}

Mesh Model::ProcessMesh(aiMesh* mesh, const aiScene* scene) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    for(unsigned int i=0;i<mesh->mNumVertices;i++) {
        Vertex vertex{};
        vertex.position = {mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z};
        vertex.normal = mesh->HasNormals() ?
            glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z) :
            glm::vec3(0.0f);
        if(mesh->HasTangentsAndBitangents())
            vertex.tangent = {mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z};
        if(mesh->mTextureCoords[0])
            vertex.texcoord = {mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y};
        vertices.push_back(vertex);
    }
    for(unsigned int i=0;i<mesh->mNumFaces;i++) {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j=0;j<face.mNumIndices;j++)
            indices.push_back(face.mIndices[j]);
    }

    if(!mesh->HasNormals()) {
        std::vector<glm::vec3> temp_normals(vertices.size(), glm::vec3(0.0f));
        for(unsigned int i = 0; i < mesh->mNumFaces; ++i) {
            const aiFace& face = mesh->mFaces[i];
            if(face.mNumIndices < 3) continue;
            unsigned int i0 = face.mIndices[0];
            unsigned int i1 = face.mIndices[1];
            unsigned int i2 = face.mIndices[2];
            glm::vec3 v0 = vertices[i0].position;
            glm::vec3 v1 = vertices[i1].position;
            glm::vec3 v2 = vertices[i2].position;
            glm::vec3 normal = glm::normalize(glm::cross(v1 - v0, v2 - v0));
            temp_normals[i0] += normal;
            temp_normals[i1] += normal;
            temp_normals[i2] += normal;
        }
        for(size_t i = 0; i < vertices.size(); ++i)
            vertices[i].normal = glm::normalize(temp_normals[i]);
    }
    std::shared_ptr<Texture2D> albedoTex = nullptr;
    std::shared_ptr<Texture2D> normalTex = nullptr;
    if(mesh->mMaterialIndex >=0) {
        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
        auto LoadTextureOfType = [&](aiTextureType type) -> std::shared_ptr<Texture2D> {
            if(material->GetTextureCount(type) == 0)
                return nullptr;
            aiString str; material->GetTexture(type, 0, &str);
            std::string filename = str.C_Str();
            if(filename.empty())
                return nullptr;
            const aiTexture* texData = scene->GetEmbeddedTexture(filename.c_str());
            if(!texData && filename[0] == '*') {
                int idx = std::atoi(filename.c_str() + 1);
                if(idx >= 0 && idx < static_cast<int>(scene->mNumTextures))
                    texData = scene->mTextures[idx];
            }
            if(texData) {
                if(texData->mHeight == 0)
                    return std::make_shared<Texture2D>(reinterpret_cast<const unsigned char*>(texData->pcData), texData->mWidth);
                auto tex = std::make_shared<Texture2D>();
                tex->LoadFromRawData(reinterpret_cast<const unsigned char*>(texData->pcData), texData->mWidth, texData->mHeight, 4);
                return tex;
            } else {
                std::filesystem::path filePath = filename;
                if (!filePath.is_absolute())
                    filePath = std::filesystem::path(directory_) / filePath;
                if (!std::filesystem::exists(filePath))
                    filePath = std::filesystem::path(directory_) / filePath.filename();
                return std::make_shared<Texture2D>(filePath.string());
            }
        };

        albedoTex = LoadTextureOfType(aiTextureType_DIFFUSE);
        normalTex = LoadTextureOfType(aiTextureType_NORMALS);
        if(!normalTex)
            normalTex = LoadTextureOfType(aiTextureType_HEIGHT);
    }
    return Mesh(vertices, indices, albedoTex, normalTex);
}

void Model::Draw(unsigned int shader, const glm::mat4& transform) const {
    glUniformMatrix4fv(glGetUniformLocation(shader, "u_Model"), 1, GL_FALSE, glm::value_ptr(transform));
    // set instance transform to identity
    glm::mat4 identity(1.0f);
    glVertexAttrib4fv(4, glm::value_ptr(identity[0]));
    glVertexAttrib4fv(5, glm::value_ptr(identity[1]));
    glVertexAttrib4fv(6, glm::value_ptr(identity[2]));
    glVertexAttrib4fv(7, glm::value_ptr(identity[3]));
    glVertexAttrib4f(8,1.0f,1.0f,1.0f,1.0f);
    for(const auto& mesh : meshes_)
        mesh.Draw(shader);
}

}

#include "Model.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>

namespace GLStudy {

bool Model::LoadModel(const std::string& path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
                                             aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
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
        vertex.normal = mesh->HasNormals() ? glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z) : glm::vec3(0.0f);
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
    std::shared_ptr<Texture2D> tex = nullptr;
    if(mesh->mMaterialIndex >=0) {
        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
        if(material->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
            aiString str; material->GetTexture(aiTextureType_DIFFUSE,0,&str);
            std::string filename = str.C_Str();
            std::string filepath = directory_ + "/" + filename;
            tex = std::make_shared<Texture2D>(filepath);
        }
    }
    return Mesh(vertices, indices, tex);
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

#include "Model.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Texture2D.h"

namespace GLStudy {
    namespace {
        struct Vertex {
            glm::vec3 position;
            glm::vec3 normal;
            glm::vec3 tangent;
            glm::vec2 texcoord;
        };
    }

    bool Model::LoadFromFile(const std::string& path) {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_CalcTangentSpace | aiProcess_FlipUVs);
        if (!scene || !scene->HasMeshes())
            return false;
        meshes_.clear();
        meshes_.reserve(scene->mNumMeshes);
        for (unsigned int i = 0; i < scene->mNumMeshes; ++i) {
            aiMesh* mesh = scene->mMeshes[i];
            std::vector<Vertex> vertices;
            std::vector<unsigned int> indices;
            vertices.reserve(mesh->mNumVertices);
            for (unsigned int v = 0; v < mesh->mNumVertices; ++v) {
                Vertex vert{};
                vert.position = {mesh->mVertices[v].x, mesh->mVertices[v].y, mesh->mVertices[v].z};
                if (mesh->HasNormals())
                    vert.normal = {mesh->mNormals[v].x, mesh->mNormals[v].y, mesh->mNormals[v].z};
                if (mesh->HasTangentsAndBitangents())
                    vert.tangent = {mesh->mTangents[v].x, mesh->mTangents[v].y, mesh->mTangents[v].z};
                if (mesh->HasTextureCoords(0))
                    vert.texcoord = {mesh->mTextureCoords[0][v].x, mesh->mTextureCoords[0][v].y};
                vertices.push_back(vert);
            }
            for (unsigned int f = 0; f < mesh->mNumFaces; ++f) {
                const aiFace& face = mesh->mFaces[f];
                for (unsigned int j = 0; j < face.mNumIndices; ++j)
                    indices.push_back(face.mIndices[j]);
            }
            Mesh new_mesh;
            new_mesh.vao = std::make_unique<VertexArray>();
            new_mesh.vbo = std::make_unique<VertexBuffer>(vertices.data(), vertices.size() * sizeof(Vertex));
            new_mesh.ibo = std::make_unique<IndexBuffer>(indices.data(), indices.size());
            new_mesh.vao->Bind();
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
            glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));
            glEnableVertexAttribArray(0);
            glEnableVertexAttribArray(1);
            glEnableVertexAttribArray(2);
            glEnableVertexAttribArray(3);
            new_mesh.index_count = indices.size();
            new_mesh.vao->Unbind();
            aiMaterial* mat = scene->mMaterials[mesh->mMaterialIndex];
            aiColor3D color(1.0f,1.0f,1.0f);
            mat->Get(AI_MATKEY_COLOR_DIFFUSE, color);
            new_mesh.material.albedo = {color.r, color.g, color.b};
            // TODO load textures if present
            meshes_.push_back(std::move(new_mesh));
        }
        return true;
    }
}

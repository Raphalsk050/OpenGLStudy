#include "ModelLoader.h"
#include <filesystem>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace GLStudy {

bool ModelLoader::LoadModel(const std::string& path, ModelData& out_model)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path.c_str(), aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_CalcTangentSpace | aiProcess_FlipUVs);
    if(!scene || !scene->mNumMeshes)
        return false;
    std::filesystem::path base = std::filesystem::path(path).parent_path();

    out_model.materials.resize(scene->mNumMaterials);
    for(unsigned int i=0;i<scene->mNumMaterials;i++) {
        Material mat{};
        const aiMaterial* aimat = scene->mMaterials[i];
        aiString tex;
        if(AI_SUCCESS == aimat->GetTexture(aiTextureType_DIFFUSE,0,&tex)) {
            mat.albedo_path = (base / tex.C_Str()).string();
            mat.has_albedo = true;
        }
        if(AI_SUCCESS == aimat->GetTexture(aiTextureType_NORMALS,0,&tex)) {
            mat.normal_path = (base / tex.C_Str()).string();
            mat.has_normal = true;
        }
        if(AI_SUCCESS == aimat->GetTexture(aiTextureType_SPECULAR,0,&tex)) {
            mat.specular_path = (base / tex.C_Str()).string();
            mat.has_specular = true;
        }
        if(AI_SUCCESS == aimat->GetTexture(aiTextureType_HEIGHT,0,&tex)) {
            mat.roughness_path = (base / tex.C_Str()).string();
            mat.has_roughness = true;
        }
        if(AI_SUCCESS == aimat->GetTexture(aiTextureType_LIGHTMAP,0,&tex)) {
            mat.ao_path = (base / tex.C_Str()).string();
            mat.has_ao = true;
        }
        if(AI_SUCCESS == aimat->GetTexture(aiTextureType_EMISSIVE,0,&tex)) {
            mat.emissive_path = (base / tex.C_Str()).string();
            mat.has_emissive = true;
        }
        out_model.materials[i] = mat;
    }

    out_model.meshes.resize(scene->mNumMeshes);
    for(unsigned int m=0;m<scene->mNumMeshes;m++) {
        const aiMesh* mesh = scene->mMeshes[m];
        MeshData md{};
        md.material_index = mesh->mMaterialIndex;
        md.vertices.resize(mesh->mNumVertices);
        for(unsigned int v=0; v<mesh->mNumVertices; ++v) {
            VertexData vd{};
            vd.position = {mesh->mVertices[v].x, mesh->mVertices[v].y, mesh->mVertices[v].z};
            if(mesh->HasNormals())
                vd.normal = {mesh->mNormals[v].x, mesh->mNormals[v].y, mesh->mNormals[v].z};
            if(mesh->HasTangentsAndBitangents())
                vd.tangent = {mesh->mTangents[v].x, mesh->mTangents[v].y, mesh->mTangents[v].z};
            if(mesh->HasTextureCoords(0))
                vd.texcoord = {mesh->mTextureCoords[0][v].x, mesh->mTextureCoords[0][v].y};
            md.vertices[v] = vd;
        }
        for(unsigned int f=0; f<mesh->mNumFaces; ++f) {
            const aiFace& face = mesh->mFaces[f];
            for(unsigned int j=0;j<face.mNumIndices;j++)
                md.indices.push_back(face.mIndices[j]);
        }
        out_model.meshes[m] = std::move(md);
    }
    return true;
}

}

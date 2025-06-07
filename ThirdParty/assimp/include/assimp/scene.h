#pragma once
#define AI_SUCCESS 1

struct aiNode;
struct aiMesh;
struct aiMaterial;
struct aiScene {
    unsigned int mNumMeshes;
    aiMesh** mMeshes;
    unsigned int mNumMaterials;
    aiMaterial** mMaterials;
};

struct aiVector3D { float x,y,z; };
struct aiFace { unsigned int mNumIndices; unsigned int* mIndices; };

struct aiMesh {
    unsigned int mNumVertices;
    aiVector3D* mVertices;
    aiVector3D* mNormals;
    aiVector3D* mTangents;
    aiVector3D** mTextureCoords;
    unsigned int mNumFaces;
    aiFace* mFaces;
    unsigned int mMaterialIndex;
    bool HasNormals() const { return mNormals != nullptr; }
    bool HasTangentsAndBitangents() const { return mTangents != nullptr; }
    bool HasTextureCoords(unsigned int) const { return mTextureCoords != nullptr; }
};

struct aiString { const char* C_Str() const { return data; } char data[1024]; };

enum aiTextureType {
    aiTextureType_DIFFUSE,
    aiTextureType_SPECULAR,
    aiTextureType_AMBIENT,
    aiTextureType_EMISSIVE,
    aiTextureType_HEIGHT,
    aiTextureType_NORMALS,
    aiTextureType_LIGHTMAP
};


struct aiMaterial {
    int GetTexture(aiTextureType, unsigned int, aiString* out) const { return 1; }
};


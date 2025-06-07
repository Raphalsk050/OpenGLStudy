#include "ModelLoader.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

namespace GLStudy {
namespace {
struct IndexKey {
    int v;
    int vt;
    int vn;
    bool operator==(const IndexKey& other) const {
        return v==other.v && vt==other.vt && vn==other.vn;
    }
};
struct KeyHash {
    std::size_t operator()(const IndexKey& k) const noexcept {
        return ((std::hash<int>()(k.v) ^ (std::hash<int>()(k.vt) << 1)) >> 1) ^ (std::hash<int>()(k.vn) << 1);
    }
};
}

bool ModelLoader::LoadOBJ(const std::string& path,
                          std::vector<VertexData>& out_vertices,
                          std::vector<unsigned int>& out_indices)
{
    std::ifstream file(path);
    if(!file.is_open())
        return false;

    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> texcoords;

    std::unordered_map<IndexKey, unsigned int, KeyHash> uniqueIndex;
    std::string line;
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string prefix;
        ss >> prefix;
        if(prefix == "v") {
            glm::vec3 pos;
            ss >> pos.x >> pos.y >> pos.z;
            positions.push_back(pos);
        } else if(prefix == "vn") {
            glm::vec3 n;
            ss >> n.x >> n.y >> n.z;
            normals.push_back(n);
        } else if(prefix == "vt") {
            glm::vec2 uv;
            ss >> uv.x >> uv.y;
            texcoords.push_back(uv);
        } else if(prefix == "f") {
            for(int i=0;i<3;i++) {
                std::string vert;
                ss >> vert;
                std::replace(vert.begin(), vert.end(), '/', ' ');
                std::stringstream vs(vert);
                IndexKey key{0,0,0};
                vs >> key.v >> key.vt >> key.vn;
                key.v--; key.vt--; key.vn--;
                auto it = uniqueIndex.find(key);
                if(it == uniqueIndex.end()) {
                    VertexData v{};
                    v.position = positions[key.v];
                    if(key.vn >=0 && key.vn < (int)normals.size())
                        v.normal = normals[key.vn];
                    else
                        v.normal = glm::vec3(0,1,0);
                    if(key.vt >=0 && key.vt < (int)texcoords.size())
                        v.texcoord = texcoords[key.vt];
                    else
                        v.texcoord = glm::vec2(0.0f);
                    // simple tangent computation
                    glm::vec3 up(0.0f,1.0f,0.0f);
                    glm::vec3 t = glm::cross(up, v.normal);
                    if(glm::length(t) < 0.001f)
                        t = glm::cross(glm::vec3(1,0,0), v.normal);
                    v.tangent = glm::normalize(t);

                    unsigned int index = static_cast<unsigned int>(out_vertices.size());
                    out_vertices.push_back(v);
                    uniqueIndex[key] = index;
                    out_indices.push_back(index);
                } else {
                    out_indices.push_back(it->second);
                }
            }
        }
    }

    return true;
}

} // namespace GLStudy

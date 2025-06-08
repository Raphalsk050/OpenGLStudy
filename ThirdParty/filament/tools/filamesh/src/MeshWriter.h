
#include <filameshio/filamesh.h>

#include "third_party/filament/libs/math/include/math/half.h"
#include "third_party/filament/libs/math/include/math/mat3.h"
#include "third_party/filament/libs/math/include/math/norm.h"
#include "third_party/filament/libs/math/include/math/quat.h"
#include "third_party/filament/libs/math/include/math/vec3.h"

#include <iostream>
#include <string>
#include <vector>

namespace filamesh {

using half4 = filament::math::half4;
using short4 = filament::math::short4;
using ubyte4 = filament::math::ubyte4;
using ushort2 = filament::math::ushort2;

struct Vertex {
    half4  position;
    short4 tangents;
    ubyte4 color;
    ushort2 uv0;
};

struct Mesh {
    std::vector<Part> parts;
    std::vector<std::string> materials;
    uint32_t vertexCount = 0;
    std::vector<uint32_t> indices;
    // interleaved:
    std::vector<Vertex> vertices;
    // de-interleaved:
    std::vector<decltype(Vertex::position)>  positions;
    std::vector<decltype(Vertex::tangents)>  tangents;
    std::vector<decltype(Vertex::color)>     colors;
    std::vector<decltype(Vertex::uv0)>       uv0;
    std::vector<decltype(Vertex::uv0)>       uv1;
};

class MeshWriter {
    uint32_t mFlags;
    void optimize(Mesh& mesh);
public:
    MeshWriter(uint32_t flags) : mFlags(flags) {}
    bool serialize(std::ostream&, Mesh& mesh);
};

}

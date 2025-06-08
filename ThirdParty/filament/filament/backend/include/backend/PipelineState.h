
#ifndef TNT_FILAMENT_BACKEND_PIPELINESTATE_H
#define TNT_FILAMENT_BACKEND_PIPELINESTATE_H

#include <backend/DriverEnums.h>
#include <backend/Handle.h>

#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include <stdint.h>

namespace filament::backend {

//! \privatesection

struct PipelineState {
    Handle<HwProgram> program;                                              //  4
    Handle<HwVertexBufferInfo> vertexBufferInfo;                            //  4
    RasterState rasterState;                                                //  4
    StencilState stencilState;                                              // 12
    PolygonOffset polygonOffset;                                            //  8
    PrimitiveType primitiveType = PrimitiveType::TRIANGLES;                 //  1
    uint8_t padding[3] = {};                                                //  3
};

} // namespace filament::backend

#if !defined(NDEBUG)
utils::io::ostream& operator<<(utils::io::ostream& out, const filament::backend::PipelineState& ps);
#endif

#endif //TNT_FILAMENT_BACKEND_PIPELINESTATE_H

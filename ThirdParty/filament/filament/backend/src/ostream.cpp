
#include <backend/BufferDescriptor.h>
#include <backend/DriverEnums.h>
#include <backend/PipelineState.h>
#include <backend/PixelBufferDescriptor.h>
#include <backend/TargetBufferInfo.h>

#include "third_party/filament/libs/utils/include/utils/ostream.h"

using namespace filament;
using namespace backend;
using namespace utils;

// ------------------------------------------------------------------------------------------------
// Stream operators for all types in DriverEnums.h
// (These must live outside the filament namespace)
// ------------------------------------------------------------------------------------------------

#if !defined(NDEBUG)

#define CASE(ENUM, VALUE)    \
    case ENUM::VALUE: {      \
        out << #VALUE;       \
        break;               \
}

io::ostream& operator<<(io::ostream& out, ShaderModel model) {
    switch (model) {
        CASE(ShaderModel, MOBILE)
        CASE(ShaderModel, DESKTOP)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, PrimitiveType type) {
    switch (type) {
        CASE(PrimitiveType, TRIANGLES)
        CASE(PrimitiveType, TRIANGLE_STRIP)
        CASE(PrimitiveType, LINES)
        CASE(PrimitiveType, LINE_STRIP)
        CASE(PrimitiveType, POINTS)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, ElementType type) {
    switch (type) {
        CASE(ElementType, BYTE)
        CASE(ElementType, BYTE2)
        CASE(ElementType, BYTE3)
        CASE(ElementType, BYTE4)
        CASE(ElementType, UBYTE)
        CASE(ElementType, UBYTE2)
        CASE(ElementType, UBYTE3)
        CASE(ElementType, UBYTE4)
        CASE(ElementType, SHORT)
        CASE(ElementType, SHORT2)
        CASE(ElementType, SHORT3)
        CASE(ElementType, SHORT4)
        CASE(ElementType, USHORT)
        CASE(ElementType, USHORT2)
        CASE(ElementType, USHORT3)
        CASE(ElementType, USHORT4)
        CASE(ElementType, INT)
        CASE(ElementType, UINT)
        CASE(ElementType, FLOAT)
        CASE(ElementType, FLOAT2)
        CASE(ElementType, FLOAT3)
        CASE(ElementType, FLOAT4)
        CASE(ElementType, HALF)
        CASE(ElementType, HALF2)
        CASE(ElementType, HALF3)
        CASE(ElementType, HALF4)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, BufferUsage usage) {
    switch (usage) {
        CASE(BufferUsage, STATIC)
        CASE(BufferUsage, DYNAMIC)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, CullingMode mode) {
    switch (mode) {
        CASE(CullingMode, NONE)
        CASE(CullingMode, FRONT)
        CASE(CullingMode, BACK)
        CASE(CullingMode, FRONT_AND_BACK)
    }
    return out;
}


io::ostream& operator<<(io::ostream& out, SamplerType type) {
    switch (type) {
        CASE(SamplerType, SAMPLER_2D)
        CASE(SamplerType, SAMPLER_2D_ARRAY)
        CASE(SamplerType, SAMPLER_3D)
        CASE(SamplerType, SAMPLER_CUBEMAP)
        CASE(SamplerType, SAMPLER_CUBEMAP_ARRAY)
        CASE(SamplerType, SAMPLER_EXTERNAL)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, SamplerFormat type) {
    switch (type) {
        CASE(SamplerFormat, INT)
        CASE(SamplerFormat, UINT)
        CASE(SamplerFormat, FLOAT)
        CASE(SamplerFormat, SHADOW)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, Precision precision) {
    switch (precision) {
        CASE(Precision, LOW)
        CASE(Precision, MEDIUM)
        CASE(Precision, HIGH)
        CASE(Precision, DEFAULT)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, PixelDataFormat format) {
    switch (format) {
        CASE(PixelDataFormat, R)
        CASE(PixelDataFormat, R_INTEGER)
        CASE(PixelDataFormat, RG)
        CASE(PixelDataFormat, RG_INTEGER)
        CASE(PixelDataFormat, RGB)
        CASE(PixelDataFormat, RGB_INTEGER)
        CASE(PixelDataFormat, RGBA)
        CASE(PixelDataFormat, RGBA_INTEGER)
        CASE(PixelDataFormat, DEPTH_COMPONENT)
        CASE(PixelDataFormat, DEPTH_STENCIL)
        CASE(PixelDataFormat, ALPHA)
        CASE(PixelDataFormat, UNUSED)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, PixelDataType format) {
    switch (format) {
        CASE(PixelDataType, UBYTE)
        CASE(PixelDataType, BYTE)
        CASE(PixelDataType, USHORT)
        CASE(PixelDataType, SHORT)
        CASE(PixelDataType, UINT)
        CASE(PixelDataType, INT)
        CASE(PixelDataType, HALF)
        CASE(PixelDataType, FLOAT)
        CASE(PixelDataType, COMPRESSED)
        CASE(PixelDataType, UINT_10F_11F_11F_REV)
        CASE(PixelDataType, USHORT_565)
        CASE(PixelDataType, UINT_2_10_10_10_REV)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, TextureFormat format) {
    switch (format) {
        CASE(TextureFormat, R8)
        CASE(TextureFormat, R8_SNORM)
        CASE(TextureFormat, R16F)
        CASE(TextureFormat, R32F)
        CASE(TextureFormat, R8UI)
        CASE(TextureFormat, R8I)
        CASE(TextureFormat, STENCIL8)
        CASE(TextureFormat, R16UI)
        CASE(TextureFormat, R16I)
        CASE(TextureFormat, R32UI)
        CASE(TextureFormat, R32I)
        CASE(TextureFormat, RG8)
        CASE(TextureFormat, RG8_SNORM)
        CASE(TextureFormat, RG16F)
        CASE(TextureFormat, RG32F)
        CASE(TextureFormat, RG8UI)
        CASE(TextureFormat, RG8I)
        CASE(TextureFormat, RG16UI)
        CASE(TextureFormat, RG16I)
        CASE(TextureFormat, RG32UI)
        CASE(TextureFormat, RG32I)
        CASE(TextureFormat, RGB8)
        CASE(TextureFormat, SRGB8)
        CASE(TextureFormat, RGB565)
        CASE(TextureFormat, RGB8_SNORM)
        CASE(TextureFormat, R11F_G11F_B10F)
        CASE(TextureFormat, RGB9_E5)
        CASE(TextureFormat, RGB16F)
        CASE(TextureFormat, RGB32F)
        CASE(TextureFormat, RGB8UI)
        CASE(TextureFormat, RGB8I)
        CASE(TextureFormat, RGB16UI)
        CASE(TextureFormat, RGB16I)
        CASE(TextureFormat, RGB32UI)
        CASE(TextureFormat, RGB32I)
        CASE(TextureFormat, RGBA8)
        CASE(TextureFormat, SRGB8_A8)
        CASE(TextureFormat, RGBA8_SNORM)
        CASE(TextureFormat, RGB5_A1)
        CASE(TextureFormat, RGBA4)
        CASE(TextureFormat, RGB10_A2)
        CASE(TextureFormat, RGBA16F)
        CASE(TextureFormat, RGBA32F)
        CASE(TextureFormat, RGBA8UI)
        CASE(TextureFormat, RGBA8I)
        CASE(TextureFormat, RGBA16UI)
        CASE(TextureFormat, RGBA16I)
        CASE(TextureFormat, RGBA32UI)
        CASE(TextureFormat, RGBA32I)
        CASE(TextureFormat, DEPTH16)
        CASE(TextureFormat, DEPTH24)
        CASE(TextureFormat, DEPTH32F)
        CASE(TextureFormat, DEPTH24_STENCIL8)
        CASE(TextureFormat, DEPTH32F_STENCIL8)
        // compressed formats...
        CASE(TextureFormat, EAC_R11)
        CASE(TextureFormat, EAC_R11_SIGNED)
        CASE(TextureFormat, EAC_RG11)
        CASE(TextureFormat, EAC_RG11_SIGNED)
        CASE(TextureFormat, ETC2_RGB8)
        CASE(TextureFormat, ETC2_SRGB8)
        CASE(TextureFormat, ETC2_RGB8_A1)
        CASE(TextureFormat, ETC2_SRGB8_A1)
        CASE(TextureFormat, ETC2_EAC_RGBA8)
        CASE(TextureFormat, ETC2_EAC_SRGBA8)
        CASE(TextureFormat, DXT1_RGB)
        CASE(TextureFormat, DXT1_SRGB)
        CASE(TextureFormat, DXT1_RGBA)
        CASE(TextureFormat, DXT1_SRGBA)
        CASE(TextureFormat, DXT3_RGBA)
        CASE(TextureFormat, DXT3_SRGBA)
        CASE(TextureFormat, DXT5_RGBA)
        CASE(TextureFormat, DXT5_SRGBA)
        CASE(TextureFormat, RED_RGTC1)
        CASE(TextureFormat, SIGNED_RED_RGTC1)
        CASE(TextureFormat, RED_GREEN_RGTC2)
        CASE(TextureFormat, SIGNED_RED_GREEN_RGTC2)
        CASE(TextureFormat, RGB_BPTC_SIGNED_FLOAT)
        CASE(TextureFormat, RGB_BPTC_UNSIGNED_FLOAT)
        CASE(TextureFormat, RGBA_BPTC_UNORM)
        CASE(TextureFormat, SRGB_ALPHA_BPTC_UNORM)
        CASE(TextureFormat, RGBA_ASTC_4x4)
        CASE(TextureFormat, RGBA_ASTC_5x4)
        CASE(TextureFormat, RGBA_ASTC_5x5)
        CASE(TextureFormat, RGBA_ASTC_6x5)
        CASE(TextureFormat, RGBA_ASTC_6x6)
        CASE(TextureFormat, RGBA_ASTC_8x5)
        CASE(TextureFormat, RGBA_ASTC_8x6)
        CASE(TextureFormat, RGBA_ASTC_8x8)
        CASE(TextureFormat, RGBA_ASTC_10x5)
        CASE(TextureFormat, RGBA_ASTC_10x6)
        CASE(TextureFormat, RGBA_ASTC_10x8)
        CASE(TextureFormat, RGBA_ASTC_10x10)
        CASE(TextureFormat, RGBA_ASTC_12x10)
        CASE(TextureFormat, RGBA_ASTC_12x12)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_4x4)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_5x4)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_5x5)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_6x5)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_6x6)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_8x5)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_8x6)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_8x8)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_10x5)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_10x6)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_10x8)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_10x10)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_12x10)
        CASE(TextureFormat, SRGB8_ALPHA8_ASTC_12x12)
        CASE(TextureFormat, UNUSED)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, TextureCubemapFace face) {
    switch (face) {
        CASE(TextureCubemapFace, NEGATIVE_X)
        CASE(TextureCubemapFace, POSITIVE_X)
        CASE(TextureCubemapFace, NEGATIVE_Y)
        CASE(TextureCubemapFace, POSITIVE_Y)
        CASE(TextureCubemapFace, NEGATIVE_Z)
        CASE(TextureCubemapFace, POSITIVE_Z)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, SamplerWrapMode wrap) {
    switch (wrap) {
        CASE(SamplerWrapMode, REPEAT)
        CASE(SamplerWrapMode, CLAMP_TO_EDGE)
        CASE(SamplerWrapMode, MIRRORED_REPEAT)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, SamplerMinFilter filter) {
    switch (filter) {
        CASE(SamplerMinFilter, NEAREST)
        CASE(SamplerMinFilter, LINEAR)
        CASE(SamplerMinFilter, NEAREST_MIPMAP_NEAREST)
        CASE(SamplerMinFilter, LINEAR_MIPMAP_NEAREST)
        CASE(SamplerMinFilter, NEAREST_MIPMAP_LINEAR)
        CASE(SamplerMinFilter, LINEAR_MIPMAP_LINEAR)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, SamplerMagFilter filter) {
    switch (filter) {
        CASE(SamplerMagFilter, NEAREST)
        CASE(SamplerMagFilter, LINEAR)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, SamplerCompareMode mode) {
    switch (mode) {
        CASE(SamplerCompareMode, NONE)
        CASE(SamplerCompareMode, COMPARE_TO_TEXTURE)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, SamplerCompareFunc func) {
    switch (func) {
        CASE(SamplerCompareFunc, LE)
        CASE(SamplerCompareFunc, GE)
        CASE(SamplerCompareFunc, L)
        CASE(SamplerCompareFunc, G)
        CASE(SamplerCompareFunc, E)
        CASE(SamplerCompareFunc, NE)
        CASE(SamplerCompareFunc, A)
        CASE(SamplerCompareFunc, N)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, BufferObjectBinding binding) {
    switch (binding) {
        CASE(BufferObjectBinding, VERTEX)
        CASE(BufferObjectBinding, UNIFORM)
        CASE(BufferObjectBinding, SHADER_STORAGE)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, TextureSwizzle swizzle) {
    switch (swizzle) {
        CASE(TextureSwizzle, SUBSTITUTE_ZERO)
        CASE(TextureSwizzle, SUBSTITUTE_ONE)
        CASE(TextureSwizzle, CHANNEL_0)
        CASE(TextureSwizzle, CHANNEL_1)
        CASE(TextureSwizzle, CHANNEL_2)
        CASE(TextureSwizzle, CHANNEL_3)
    }
    return out;
}

io::ostream& operator<<(io::ostream& out, SamplerParams params) {
    out << "SamplerParams{ "
    << params.filterMin << ", "
    << params.filterMag << ", "
    << params.wrapS << ", "
    << params.wrapT << ", "
    << params.wrapR << ", "
    << (1u << params.anisotropyLog2) << ", "
    << params.compareMode << ", "
    << params.compareFunc
    << " }";
    return out;
}

io::ostream& operator<<(io::ostream& out, const AttributeArray& type) {
    return out << "AttributeArray[" << type.max_size() << "]{}";
}

io::ostream& operator<<(io::ostream& out, const RasterState& rs) {
    // TODO: implement decoding of enums
    return out << "RasterState{"
    << rs.culling << ", "
    << uint8_t(rs.blendEquationRGB) << ", "
    << uint8_t(rs.blendEquationAlpha) << ", "
    << uint8_t(rs.blendFunctionSrcRGB) << ", "
    << uint8_t(rs.blendFunctionSrcAlpha) << ", "
    << uint8_t(rs.blendFunctionDstRGB) << ", "
    << uint8_t(rs.blendFunctionDstAlpha) << "}";
}

io::ostream& operator<<(io::ostream& out, const TargetBufferInfo& tbi) {
    return out << "TargetBufferInfo{"
    << "handle=" << tbi.handle
    << ", baseViewIndex=" << tbi.baseViewIndex
    << ", level=" << tbi.level
    << ", layer=" << tbi.layer << "}";
}

io::ostream& operator<<(io::ostream& out, const PolygonOffset& po) {
    return out << "PolygonOffset{"
    << "slope=" << po.slope
    << ", constant=" << po.constant << "}";
}

io::ostream& operator<<(io::ostream& out, const PipelineState& ps) {
    return out << "PipelineState{"
    << "program=" << ps.program
    << ", rasterState=" << ps.rasterState
    << ", polygonOffset=" << ps.polygonOffset << "}";
}

io::ostream& operator<<(io::ostream& out, BufferDescriptor const& b) {
    return out << "BufferDescriptor{ buffer=" << b.buffer
    << ", size=" << b.size
    << ", callback=" << b.getCallback()
    << ", user=" << b.getUser() << " }";
}

io::ostream& operator<<(io::ostream& out, PixelBufferDescriptor const& b) {
    BufferDescriptor const& base = static_cast<BufferDescriptor const&>(b);
    return out << "PixelBufferDescriptor{ " << base
    <<   "left=" << b.left
    << ", top=" << b.top
    << ", stride=" << b.stride
    << ", format=" << b.format
    << ", type=" << b.type
    << ", alignment=" << b.alignment << " }";
}

io::ostream& operator<<(io::ostream& out, filament::backend::Viewport const& viewport) {
    return out << "Viewport{"
    <<   "left=" << viewport.left
    << ", bottom=" << viewport.bottom
    << ", width=" << viewport.width
    << ", height=" << viewport.height << "}";
}

io::ostream& operator<<(io::ostream& out, TargetBufferFlags flags) {
    // TODO: implement decoding of enum
    out << uint32_t(flags);
    return out;
}

io::ostream& operator<<(io::ostream& out, RenderPassParams const& params) {
    out << "RenderPassParams{"
    <<   "clear=" << params.flags.clear
    << ", discardStart=" << params.flags.discardStart
    << ", discardEnd=" << params.flags.discardEnd
    << ", left=" << params.viewport.left
    << ", bottom=" << params.viewport.bottom
    << ", width=" << params.viewport.width
    << ", height=" << params.viewport.height
    << ", clearColor=" << params.clearColor
    << ", clearDepth=" << params.clearDepth
    << ", clearStencil=" << params.clearStencil << "}";
    return out;
}

io::ostream& operator<<(io::ostream& out, MRT const& mrt) {
    // TODO: implement decoding of enum
    out << "MRT{...}";
    return out;
}

io::ostream& operator<<(io::ostream& stream, ShaderStageFlags stageFlags) {
    const char* str = nullptr;
    switch (stageFlags) {
        case ShaderStageFlags::NONE:
            str = "{ }";
            break;
        case ShaderStageFlags::VERTEX:
            str = "{ vertex }";
            break;
        case ShaderStageFlags::FRAGMENT:
            str = "{ fragment }";
            break;
        case ShaderStageFlags::COMPUTE:
            str = "{ compute }";
            break;
        case ShaderStageFlags::ALL_SHADER_STAGE_FLAGS:
            str = "{ vertex | fragment | compute }";
            break;
    }
    return stream << str;
}

#undef CASE

#endif // !NDEBUG

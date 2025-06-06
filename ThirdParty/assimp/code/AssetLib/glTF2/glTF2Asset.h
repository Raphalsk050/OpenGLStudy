/*
Open Asset Import Library (assimp)
----------------------------------------------------------------------

Copyright (c) 2006-2025, assimp team

All rights reserved.

Redistribution and use of this software in source and binary forms,
with or without modification, are permitted provided that the
following conditions are met:

* Redistributions of source code must retain the above
copyright notice, this list of conditions and the
following disclaimer.

* Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the
following disclaimer in the documentation and/or other
materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
contributors may be used to endorse or promote products
derived from this software without specific prior
written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/

/** @file glTFAsset.h
 * Declares a glTF class to handle gltf/glb files
 *
 * glTF Extensions Support:
 *   KHR_materials_pbrSpecularGlossiness full
 *   KHR_materials_specular full
 *   KHR_materials_unlit full
 *   KHR_lights_punctual full
 *   KHR_materials_sheen full
 *   KHR_materials_clearcoat full
 *   KHR_materials_transmission full
 *   KHR_materials_volume full
 *   KHR_materials_ior full
 *   KHR_materials_emissive_strength full
 *   KHR_materials_anisotropy full
 */
#ifndef GLTF2ASSET_H_INC
#define GLTF2ASSET_H_INC

#if !defined(ASSIMP_BUILD_NO_GLTF_IMPORTER) && !defined(ASSIMP_BUILD_NO_GLTF2_IMPORTER)

#include <assimp/Exceptional.h>

#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

// clang-format off
#if (__GNUC__ == 8 && __GNUC_MINOR__ >= 0)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wclass-memaccess"
#endif

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/schema.h>

#if (__GNUC__ == 8 && __GNUC_MINOR__ >= 0)
#   pragma GCC diagnostic pop
#endif

#ifdef ASSIMP_API
#   include <assimp/ByteSwapper.h>
#   include <assimp/DefaultIOSystem.h>
#   include <memory>
#else
#   include <memory>
#   define AI_SWAP4(p)
#   define ai_assert
#endif

#if _MSC_VER > 1500 || (defined __GNUC___)
#   define ASSIMP_GLTF_USE_UNORDERED_MULTIMAP
#else
#   define gltf_unordered_map map
#   define gltf_unordered_set set
#endif

#ifdef ASSIMP_GLTF_USE_UNORDERED_MULTIMAP
#   include <unordered_map>
#   include <unordered_set>
#   if defined(_MSC_VER) && _MSC_VER <= 1600
#       define gltf_unordered_map tr1::unordered_map
#       define gltf_unordered_set tr1::unordered_set
#   else
#       define gltf_unordered_map unordered_map
#       define gltf_unordered_set unordered_set
#   endif
#endif
// clang-format on

#include <assimp/StringUtils.h>
#include <assimp/material.h>
#include <assimp/GltfMaterial.h>

#include "AssetLib/glTFCommon/glTFCommon.h"

namespace glTF2 {

using glTFCommon::Nullable;
using glTFCommon::Ref;
using glTFCommon::IOStream;
using glTFCommon::IOSystem;
using glTFCommon::shared_ptr;

using rapidjson::Document;
using rapidjson::Value;

class Asset;
class AssetWriter;

struct BufferView; // here due to cross-reference
struct Texture;
struct Skin;

using glTFCommon::mat4;
using glTFCommon::vec3;
using glTFCommon::vec4;

//! Magic number for GLB files
#define AI_GLB_MAGIC_NUMBER "glTF"

#ifdef ASSIMP_API
#include <assimp/Compiler/pushpack1.h>
#endif

//! For binary .glb files
//! 12-byte header (+ the JSON + a "body" data section)
struct GLB_Header {
    uint8_t magic[4]; //!< Magic number: "glTF"
    uint32_t version; //!< Version number (always 2 as of the last update)
    uint32_t length; //!< Total length of the Binary glTF, including header, scene, and body, in bytes
} PACK_STRUCT;

struct GLB_Chunk {
    uint32_t chunkLength;
    uint32_t chunkType;
} PACK_STRUCT;

#ifdef ASSIMP_API
#include <assimp/Compiler/poppack1.h>
#endif

//! Values for the GLB_Chunk::chunkType field
enum ChunkType {
    ChunkType_JSON = 0x4E4F534A,
    ChunkType_BIN = 0x004E4942
};

//! Values for the mesh primitive modes
enum PrimitiveMode {
    PrimitiveMode_POINTS = 0,
    PrimitiveMode_LINES = 1,
    PrimitiveMode_LINE_LOOP = 2,
    PrimitiveMode_LINE_STRIP = 3,
    PrimitiveMode_TRIANGLES = 4,
    PrimitiveMode_TRIANGLE_STRIP = 5,
    PrimitiveMode_TRIANGLE_FAN = 6
};

//! Values for the Accessor::componentType field
enum ComponentType {
    ComponentType_BYTE = 5120,
    ComponentType_UNSIGNED_BYTE = 5121,
    ComponentType_SHORT = 5122,
    ComponentType_UNSIGNED_SHORT = 5123,
    ComponentType_UNSIGNED_INT = 5125,
    ComponentType_FLOAT = 5126
};

inline unsigned int ComponentTypeSize(ComponentType t) {
    switch (t) {
    case ComponentType_SHORT:
    case ComponentType_UNSIGNED_SHORT:
        return 2;

    case ComponentType_UNSIGNED_INT:
    case ComponentType_FLOAT:
        return 4;

    case ComponentType_BYTE:
    case ComponentType_UNSIGNED_BYTE:
        return 1;
    default:
        throw DeadlyImportError("GLTF: Unsupported Component Type ", ai_to_string(t));
    }
}

//! Values for the BufferView::target field
enum BufferViewTarget {
    BufferViewTarget_NONE = 0,
    BufferViewTarget_ARRAY_BUFFER = 34962,
    BufferViewTarget_ELEMENT_ARRAY_BUFFER = 34963
};

//! Values for the Sampler::magFilter field
enum class SamplerMagFilter : unsigned int {
    UNSET = 0,
    SamplerMagFilter_Nearest = 9728,
    SamplerMagFilter_Linear = 9729
};

//! Values for the Sampler::minFilter field
enum class SamplerMinFilter : unsigned int {
    UNSET = 0,
    SamplerMinFilter_Nearest = 9728,
    SamplerMinFilter_Linear = 9729,
    SamplerMinFilter_Nearest_Mipmap_Nearest = 9984,
    SamplerMinFilter_Linear_Mipmap_Nearest = 9985,
    SamplerMinFilter_Nearest_Mipmap_Linear = 9986,
    SamplerMinFilter_Linear_Mipmap_Linear = 9987
};

//! Values for the Sampler::wrapS and Sampler::wrapT field
enum class SamplerWrap : unsigned int {
    UNSET = 0,
    Clamp_To_Edge = 33071,
    Mirrored_Repeat = 33648,
    Repeat = 10497
};

//! Values for the Texture::format and Texture::internalFormat fields
enum TextureFormat {
    TextureFormat_ALPHA = 6406,
    TextureFormat_RGB = 6407,
    TextureFormat_RGBA = 6408,
    TextureFormat_LUMINANCE = 6409,
    TextureFormat_LUMINANCE_ALPHA = 6410
};

//! Values for the Texture::target field
enum TextureTarget {
    TextureTarget_TEXTURE_2D = 3553
};

//! Values for the Texture::type field
enum TextureType {
    TextureType_UNSIGNED_BYTE = 5121,
    TextureType_UNSIGNED_SHORT_5_6_5 = 33635,
    TextureType_UNSIGNED_SHORT_4_4_4_4 = 32819,
    TextureType_UNSIGNED_SHORT_5_5_5_1 = 32820
};

//! Values for the Animation::Target::path field
enum AnimationPath {
    AnimationPath_TRANSLATION,
    AnimationPath_ROTATION,
    AnimationPath_SCALE,
    AnimationPath_WEIGHTS,
};

//! Values for the Animation::Sampler::interpolation field
enum Interpolation {
    Interpolation_LINEAR,
    Interpolation_STEP,
    Interpolation_CUBICSPLINE,
};

//! Values for the Accessor::type field (helper class)
class AttribType {
public:
    enum Value { SCALAR,
        VEC2,
        VEC3,
        VEC4,
        MAT2,
        MAT3,
        MAT4 };

private:
    static const size_t NUM_VALUES = static_cast<size_t>(MAT4) + 1;

    struct Info {
        const char *name;
        unsigned int numComponents;
    };

    template <int N>
    struct data { static const Info infos[NUM_VALUES]; };

public:
    inline static Value FromString(const char *str) {
        for (size_t i = 0; i < NUM_VALUES; ++i) {
            if (strcmp(data<0>::infos[i].name, str) == 0) {
                return static_cast<Value>(i);
            }
        }
        return SCALAR;
    }

    inline static const char *ToString(Value type) {
        return data<0>::infos[static_cast<size_t>(type)].name;
    }

    inline static unsigned int GetNumComponents(Value type) {
        return data<0>::infos[static_cast<size_t>(type)].numComponents;
    }
};

// must match the order of the AttribTypeTraits::Value enum!
template <int N>
const AttribType::Info
        AttribType::data<N>::infos[AttribType::NUM_VALUES] = {
            { "SCALAR", 1 }, { "VEC2", 2 }, { "VEC3", 3 }, { "VEC4", 4 }, { "MAT2", 4 }, { "MAT3", 9 }, { "MAT4", 16 }
        };


struct CustomExtension {

    //
    // A struct containing custom extension data added to a glTF2 file
    // Has to contain Object, Array, String, Double, Uint64, and Int64 at a minimum
    // String, Double, Uint64, and Int64 are stored in the Nullables
    // Object and Array are stored in the std::vector
    //
    std::string name;

    Nullable<std::string> mStringValue;
    Nullable<double> mDoubleValue;
    Nullable<uint64_t> mUint64Value;
    Nullable<int64_t> mInt64Value;
    Nullable<bool> mBoolValue;

    // std::vector<CustomExtension> handles both Object and Array
    Nullable<std::vector<CustomExtension>> mValues;

    operator bool() const {
        return Size() != 0;
    }

    size_t Size() const {
        if (mValues.isPresent) {
            return mValues.value.size();
        } else if (mStringValue.isPresent || mDoubleValue.isPresent || mUint64Value.isPresent || mInt64Value.isPresent || mBoolValue.isPresent) {
            return 1;
        }
        return 0;
    }

    CustomExtension() = default;

    ~CustomExtension() = default;

    CustomExtension(const CustomExtension &other) = default;

    CustomExtension& operator=(const CustomExtension&) = default;
};

//! Represents metadata in an glTF2 object
struct Extras {
    std::vector<CustomExtension> mValues;

    inline bool HasExtras() const {
        return !mValues.empty();
    }
};

//! Base class for all glTF top-level objects
struct Object {
    int index; //!< The index of this object within its property container
    int oIndex; //!< The original index of this object defined in the JSON
    std::string id; //!< The globally unique ID used to reference this object
    std::string name; //!< The user-defined name of this object

    CustomExtension customExtensions;
    Extras extras;

    //! Objects marked as special are not exported (used to emulate the binary body buffer)
    virtual bool IsSpecial() const { return false; }

    virtual ~Object() = default;

    //! Maps special IDs to another ID, where needed. Subclasses may override it (statically)
    static const char *TranslateId(Asset & /*r*/, const char *id) { return id; }

    inline Value *FindString(Value &val, const char *id);
    inline Value *FindNumber(Value &val, const char *id);
    inline Value *FindUInt(Value &val, const char *id);
    inline Value *FindArray(Value &val, const char *id);
    inline Value *FindObject(Value &val, const char *id);
    inline Value *FindExtension(Value &val, const char *extensionId);

    inline void ReadExtensions(Value &val);
    inline void ReadExtras(Value &val);
};

//
// Classes for each glTF top-level object type
//

//! A buffer points to binary geometry, animation, or skins.
struct Buffer : public Object {
    /********************* Types *********************/
public:
    enum Type {
        Type_arraybuffer,
        Type_text
    };

    /// \struct SEncodedRegion
    /// Descriptor of encoded region in "bufferView".
    struct SEncodedRegion {
        const size_t Offset; ///< Offset from begin of "bufferView" to encoded region, in bytes.
        const size_t EncodedData_Length; ///< Size of encoded region, in bytes.
        uint8_t *const DecodedData; ///< Cached encoded data.
        const size_t DecodedData_Length; ///< Size of decoded region, in bytes.
        const std::string ID; ///< ID of the region.

        /// \fn SEncodedRegion(const size_t pOffset, const size_t pEncodedData_Length, uint8_t* pDecodedData, const size_t pDecodedData_Length, const std::string pID)
        /// Constructor.
        /// \param [in] pOffset - offset from begin of "bufferView" to encoded region, in bytes.
        /// \param [in] pEncodedData_Length - size of encoded region, in bytes.
        /// \param [in] pDecodedData - pointer to decoded data array.
        /// \param [in] pDecodedData_Length - size of encoded region, in bytes.
        /// \param [in] pID - ID of the region.
        SEncodedRegion(const size_t pOffset, const size_t pEncodedData_Length, uint8_t *pDecodedData, const size_t pDecodedData_Length, const std::string &pID) :
                Offset(pOffset),
                EncodedData_Length(pEncodedData_Length),
                DecodedData(pDecodedData),
                DecodedData_Length(pDecodedData_Length),
                ID(pID) {}

        /// \fn ~SEncodedRegion()
        /// Destructor.
        ~SEncodedRegion() { delete[] DecodedData; }
    };

    /******************* Variables *******************/

    //std::string uri; //!< The uri of the buffer. Can be a filepath, a data uri, etc. (required)
    size_t byteLength; //!< The length of the buffer in bytes. (default: 0)
    //std::string type; //!< XMLHttpRequest responseType (default: "arraybuffer")
    size_t capacity = 0; //!< The capacity of the buffer in bytes. (default: 0)

    Type type;

    /// \var EncodedRegion_Current
    /// Pointer to currently active encoded region.
    /// Why not decoding all regions at once and not to set one buffer with decoded data?
    /// Yes, why not? Even "accessor" point to decoded data. I mean that fields "byteOffset", "byteStride" and "count" has values which describes decoded
    /// data array. But only in range of mesh while is active parameters from "compressedData". For another mesh accessors point to decoded data too. But
    /// offset is counted for another regions is encoded.
    /// Example. You have two meshes. For every of it you have 4 bytes of data. That data compressed to 2 bytes. So, you have buffer with encoded data:
    /// M1_E0, M1_E1, M2_E0, M2_E1.
    /// After decoding you'll get:
    /// M1_D0, M1_D1, M1_D2, M1_D3, M2_D0, M2_D1, M2_D2, M2_D3.
    /// "accessors" must to use values that point to decoded data - obviously. So, you'll expect "accessors" like
    /// "accessor_0" : { byteOffset: 0, byteLength: 4}, "accessor_1" : { byteOffset: 4, byteLength: 4}
    /// but in real life you'll get:
    /// "accessor_0" : { byteOffset: 0, byteLength: 4}, "accessor_1" : { byteOffset: 2, byteLength: 4}
    /// Yes, accessor of next mesh has offset and length which mean: current mesh data is decoded, all other data is encoded.
    /// And when before you start to read data of current mesh (with encoded data of course) you must decode region of "bufferView", after read finished
    /// delete encoding mark. And after that you can repeat process: decode data of mesh, read, delete decoded data.
    ///
    /// Remark. Encoding all data at once is good in world with computers which do not has RAM limitation. So, you must use step by step encoding in
    /// exporter and importer. And, thanks to such way, there is no need to load whole file into memory.
    SEncodedRegion *EncodedRegion_Current;

private:
    shared_ptr<uint8_t> mData; //!< Pointer to the data
    bool mIsSpecial; //!< Set to true for special cases (e.g. the body buffer)

    /// \var EncodedRegion_List
    /// List of encoded regions.
    std::list<SEncodedRegion *> EncodedRegion_List;

    /******************* Functions *******************/

public:
    Buffer();
    ~Buffer() override;

    void Read(Value &obj, Asset &r);

    bool LoadFromStream(IOStream &stream, size_t length = 0, size_t baseOffset = 0);

    /// \fn void EncodedRegion_Mark(const size_t pOffset, const size_t pEncodedData_Length, uint8_t* pDecodedData, const size_t pDecodedData_Length, const std::string& pID)
    /// Mark region of "bufferView" as encoded. When data is request from such region then "bufferView" use decoded data.
    /// \param [in] pOffset - offset from begin of "bufferView" to encoded region, in bytes.
    /// \param [in] pEncodedData_Length - size of encoded region, in bytes.
    /// \param [in] pDecodedData - pointer to decoded data array.
    /// \param [in] pDecodedData_Length - size of encoded region, in bytes.
    /// \param [in] pID - ID of the region.
    void EncodedRegion_Mark(const size_t pOffset, const size_t pEncodedData_Length, uint8_t *pDecodedData, const size_t pDecodedData_Length, const std::string &pID);

    /// \fn void EncodedRegion_SetCurrent(const std::string& pID)
    /// Select current encoded region by ID. \sa EncodedRegion_Current.
    /// \param [in] pID - ID of the region.
    void EncodedRegion_SetCurrent(const std::string &pID);

    /// \fn bool ReplaceData(const size_t pBufferData_Offset, const size_t pBufferData_Count, const uint8_t* pReplace_Data, const size_t pReplace_Count)
    /// Replace part of buffer data. Pay attention that function work with original array of data (\ref mData) not with encoded regions.
    /// \param [in] pBufferData_Offset - index of first element in buffer from which new data will be placed.
    /// \param [in] pBufferData_Count - count of bytes in buffer which will be replaced.
    /// \param [in] pReplace_Data - pointer to array with new data for buffer.
    /// \param [in] pReplace_Count - count of bytes in new data.
    /// \return true - if successfully replaced, false if input arguments is out of range.
    bool ReplaceData(const size_t pBufferData_Offset, const size_t pBufferData_Count, const uint8_t *pReplace_Data, const size_t pReplace_Count);
    bool ReplaceData_joint(const size_t pBufferData_Offset, const size_t pBufferData_Count, const uint8_t *pReplace_Data, const size_t pReplace_Count);

    size_t AppendData(uint8_t *data, size_t length);
    void Grow(size_t amount);

    uint8_t *GetPointer() { return mData.get(); }

    void MarkAsSpecial() { mIsSpecial = true; }

    bool IsSpecial() const override { return mIsSpecial; }

    std::string GetURI() { return std::string(this->id) + ".bin"; }

    static const char *TranslateId(Asset &r, const char *id);
};

//! A view into a buffer generally representing a subset of the buffer.
struct BufferView : public Object {
    Ref<Buffer> buffer; //! The ID of the buffer. (required)
    size_t byteOffset; //! The offset into the buffer in bytes. (required)
    size_t byteLength; //! The length of the bufferView in bytes. (default: 0)
    unsigned int byteStride; //!< The stride, in bytes, between attributes referenced by this accessor. (default: 0)

    BufferViewTarget target; //! The target that the WebGL buffer should be bound to.

    void Read(Value &obj, Asset &r);
    uint8_t *GetPointerAndTailSize(size_t accOffset, size_t& outTailSize);
};

//! A typed view into a BufferView. A BufferView contains raw binary data.
//! An accessor provides a typed view into a BufferView or a subset of a BufferView
//! similar to how WebGL's vertexAttribPointer() defines an attribute in a buffer.
struct Accessor : public Object {
    struct Sparse;

    Ref<BufferView> bufferView; //!< The ID of the bufferView. (required)
    size_t byteOffset; //!< The offset relative to the start of the bufferView in bytes. (required)
    ComponentType componentType; //!< The datatype of components in the attribute. (required)
    size_t count; //!< The number of attributes referenced by this accessor. (required)
    AttribType::Value type; //!< Specifies if the attribute is a scalar, vector, or matrix. (required)
    std::vector<double> max; //!< Maximum value of each component in this attribute.
    std::vector<double> min; //!< Minimum value of each component in this attribute.
    std::unique_ptr<Sparse> sparse;
    std::unique_ptr<Buffer> decodedBuffer; // Packed decoded data, returned instead of original bufferView if present

    unsigned int GetNumComponents();
    unsigned int GetBytesPerComponent();
    unsigned int GetElementSize();

    inline uint8_t *GetPointer();
    inline size_t GetStride();
    inline size_t GetMaxByteSize();

    template <class T>
    size_t ExtractData(T *&outData, const std::vector<unsigned int> *remappingIndices = nullptr);

    void WriteData(size_t count, const void *src_buffer, size_t src_stride);
    void WriteSparseValues(size_t count, const void *src_data, size_t src_dataStride);
    void WriteSparseIndices(size_t count, const void *src_idx, size_t src_idxStride);

    //! Helper class to iterate the data
    class Indexer {
        friend struct Accessor;

        // This field is reported as not used, making it protectd is the easiest way to work around it without going to the bottom of what the problem is:
        // ../code/glTF2/glTF2Asset.h:392:19: error: private field 'accessor' is not used [-Werror,-Wunused-private-field]
    protected:
        Accessor &accessor;

    private:
        uint8_t *data;
        size_t elemSize, stride;

        Indexer(Accessor &acc);

    public:
        //! Accesses the i-th value as defined by the accessor
        template <class T>
        T GetValue(int i);

        //! Accesses the i-th value as defined by the accessor
        inline unsigned int GetUInt(int i) {
            return GetValue<unsigned int>(i);
        }

        inline bool IsValid() const {
            return data != nullptr;
        }
    };

    inline Indexer GetIndexer() {
        return Indexer(*this);
    }

    Accessor() = default;
    void Read(Value &obj, Asset &r);

    //sparse
    struct Sparse {
        size_t count;
        ComponentType indicesType;
        Ref<BufferView> indices;
        size_t indicesByteOffset;
        Ref<BufferView> values;
        size_t valuesByteOffset;

        std::vector<uint8_t> data; //!< Actual data, which may be defaulted to an array of zeros or the original data, with the sparse buffer view applied on top of it.

        void PopulateData(size_t numBytes, const uint8_t *bytes);
        void PatchData(unsigned int elementSize);
    };
};

struct Camera : public Object {
    enum Type {
        Perspective,
        Orthographic
    };

    Type type;

    union {
        struct {
            float aspectRatio; //!<The floating - point aspect ratio of the field of view. (0 = undefined = use the canvas one)
            float yfov; //!<The floating - point vertical field of view in radians. (required)
            float zfar; //!<The floating - point distance to the far clipping plane. (required)
            float znear; //!< The floating - point distance to the near clipping plane. (required)
        } perspective;

        struct {
            float xmag; //! The floating-point horizontal magnification of the view. (required)
            float ymag; //! The floating-point vertical magnification of the view. (required)
            float zfar; //! The floating-point distance to the far clipping plane. (required)
            float znear; //! The floating-point distance to the near clipping plane. (required)
        } ortographic;
    } cameraProperties;

    Camera() :
            type(Perspective),
            cameraProperties() {
        // empty
    }
    void Read(Value &obj, Asset &r);
};

//! A light (from KHR_lights_punctual extension)
struct Light : public Object {
    enum Type {
        Directional,
        Point,
        Spot
    };

    Type type;

    vec3 color;
    float intensity;
    Nullable<float> range;

    float innerConeAngle;
    float outerConeAngle;

    Light() = default;
    void Read(Value &obj, Asset &r);
};

//! Image data used to create a texture.
struct Image : public Object {
    std::string uri; //! The uri of the image, that can be a file path, a data URI, etc.. (required)

    Ref<BufferView> bufferView;

    std::string mimeType;

    int width, height;

private:
    std::unique_ptr<uint8_t[]> mData;
    size_t mDataLength;

public:
    Image();
    void Read(Value &obj, Asset &r);

    inline bool HasData() const { return mDataLength > 0; }

    inline size_t GetDataLength() const { return mDataLength; }

    inline const uint8_t *GetData() const { return mData.get(); }

    inline uint8_t *StealData();

    inline void SetData(uint8_t *data, size_t length, Asset &r);
};

const vec4 defaultBaseColor = { 1, 1, 1, 1 };
const vec3 defaultEmissiveFactor = { 0, 0, 0 };
const vec4 defaultDiffuseFactor = { 1, 1, 1, 1 };
const vec3 defaultSpecularFactor = { 1, 1, 1 };
const vec3 defaultSpecularColorFactor = { 1, 1, 1 };
const vec3 defaultSheenFactor = { 0, 0, 0 };
const vec3 defaultAttenuationColor = { 1, 1, 1 };

struct TextureInfo {
    Ref<Texture> texture;
    unsigned int index;
    unsigned int texCoord = 0;

    bool textureTransformSupported = false;
    struct TextureTransformExt {
        float offset[2];
        float rotation;
        float scale[2];
    } TextureTransformExt_t;
};

struct NormalTextureInfo : TextureInfo {
    float scale = 1;
};

struct OcclusionTextureInfo : TextureInfo {
    float strength = 1;
};

struct PbrMetallicRoughness {
    vec4 baseColorFactor;
    TextureInfo baseColorTexture;
    TextureInfo metallicRoughnessTexture;
    float metallicFactor;
    float roughnessFactor;
};

struct PbrSpecularGlossiness {
    vec4 diffuseFactor;
    vec3 specularFactor;
    float glossinessFactor;
    TextureInfo diffuseTexture;
    TextureInfo specularGlossinessTexture;

    PbrSpecularGlossiness() { SetDefaults(); }
    void SetDefaults();
};

struct MaterialSpecular {
    float specularFactor;
    vec3 specularColorFactor;
    TextureInfo specularTexture;
    TextureInfo specularColorTexture;

    MaterialSpecular() { SetDefaults(); }
    void SetDefaults();
};

struct MaterialSheen {
    vec3 sheenColorFactor;
    float sheenRoughnessFactor;
    TextureInfo sheenColorTexture;
    TextureInfo sheenRoughnessTexture;

    MaterialSheen() { SetDefaults(); }
    void SetDefaults();
};

struct MaterialClearcoat {
    float clearcoatFactor = 0.f;
    float clearcoatRoughnessFactor = 0.f;
    TextureInfo clearcoatTexture;
    TextureInfo clearcoatRoughnessTexture;
    NormalTextureInfo clearcoatNormalTexture;
};

struct MaterialTransmission {
    TextureInfo transmissionTexture;
    float transmissionFactor = 0.f;
};

struct MaterialVolume {
    float thicknessFactor = 0.f;
    TextureInfo thicknessTexture;
    float attenuationDistance = 0.f;
    vec3 attenuationColor;

    MaterialVolume() { SetDefaults(); }
    void SetDefaults();
};

struct MaterialIOR {
    float ior = 0.f;

    MaterialIOR() { SetDefaults(); }
    void SetDefaults();
};

struct MaterialEmissiveStrength {
    float emissiveStrength = 0.f;

    MaterialEmissiveStrength() { SetDefaults(); }
    void SetDefaults();
};

struct MaterialAnisotropy {
    float anisotropyStrength = 0.f;
    float anisotropyRotation = 0.f;
    TextureInfo anisotropyTexture;

    MaterialAnisotropy() { SetDefaults(); }
    void SetDefaults();
};

//! The material appearance of a primitive.
struct Material : public Object {
    //PBR metallic roughness properties
    PbrMetallicRoughness pbrMetallicRoughness;

    //other basic material properties
    NormalTextureInfo normalTexture;
    OcclusionTextureInfo occlusionTexture;
    TextureInfo emissiveTexture;
    vec3 emissiveFactor;
    std::string alphaMode;
    float alphaCutoff;
    bool doubleSided;

    //extension: KHR_materials_pbrSpecularGlossiness
    Nullable<PbrSpecularGlossiness> pbrSpecularGlossiness;

    //extension: KHR_materials_specular
    Nullable<MaterialSpecular> materialSpecular;

    //extension: KHR_materials_sheen
    Nullable<MaterialSheen> materialSheen;

    //extension: KHR_materials_clearcoat
    Nullable<MaterialClearcoat> materialClearcoat;

    //extension: KHR_materials_transmission
    Nullable<MaterialTransmission> materialTransmission;

    //extension: KHR_materials_volume
    Nullable<MaterialVolume> materialVolume;

    //extension: KHR_materials_ior
    Nullable<MaterialIOR> materialIOR;

    //extension: KHR_materials_emissive_strength
    Nullable<MaterialEmissiveStrength> materialEmissiveStrength;

    //extension: KHR_materials_anisotropy
    Nullable<MaterialAnisotropy> materialAnisotropy;

    //extension: KHR_materials_unlit
    bool unlit;

    Material() { SetDefaults(); }
    void Read(Value &obj, Asset &r);
    void SetDefaults();

    inline void SetTextureProperties(Asset &r, Value *prop, TextureInfo &out);
    inline void ReadTextureProperty(Asset &r, Value &vals, const char *propName, TextureInfo &out);
    inline void ReadTextureProperty(Asset &r, Value &vals, const char *propName, NormalTextureInfo &out);
    inline void ReadTextureProperty(Asset &r, Value &vals, const char *propName, OcclusionTextureInfo &out);
};

//! A set of primitives to be rendered. A node can contain one or more meshes. A node's transform places the mesh in the scene.
struct Mesh : public Object {
    using AccessorList = std::vector<Ref<Accessor>>;

    struct Primitive {
        PrimitiveMode mode;

        struct Attributes {
            AccessorList position, normal, tangent, texcoord, color, joint, jointmatrix, weight;
        } attributes;

        Ref<Accessor> indices;

        Ref<Material> material;

        struct Target {
            AccessorList position, normal, tangent;
        };
        std::vector<Target> targets;

        // extension: FB_ngon_encoding
        bool ngonEncoded;

        Primitive(): ngonEncoded(false) {}
    };

    std::vector<Primitive> primitives;

    std::vector<float> weights;
    std::vector<std::string> targetNames;

    Mesh() = default;

    /// Get mesh data from JSON-object and place them to root asset.
    /// \param [in] pJSON_Object - reference to pJSON-object from which data are read.
    /// \param [out] pAsset_Root - reference to root asset where data will be stored.
    void Read(Value &pJSON_Object, Asset &pAsset_Root);
};

struct Node : public Object {
    std::vector<Ref<Node>> children;
    std::vector<Ref<Mesh>> meshes;

    Nullable<mat4> matrix;
    Nullable<vec3> translation;
    Nullable<vec4> rotation;
    Nullable<vec3> scale;

    Ref<Camera> camera;
    Ref<Light> light;

    std::vector<Ref<Node>> skeletons; //!< The ID of skeleton nodes. Each of which is the root of a node hierarchy.
    Ref<Skin> skin; //!< The ID of the skin referenced by this node.
    std::string jointName; //!< Name used when this node is a joint in a skin.

    Ref<Node> parent; //!< This is not part of the glTF specification. Used as a helper.

    Node() = default;
    void Read(Value &obj, Asset &r);
};

struct Program : public Object {
    Program() = default;
    void Read(Value &obj, Asset &r);
};

struct Sampler : public Object {
    SamplerMagFilter magFilter; //!< The texture magnification filter.
    SamplerMinFilter minFilter; //!< The texture minification filter.
    SamplerWrap wrapS; //!< The texture wrapping in the S direction.
    SamplerWrap wrapT; //!< The texture wrapping in the T direction.

    Sampler() { SetDefaults(); }
    void Read(Value &obj, Asset &r);
    void SetDefaults();
};

struct Scene : public Object {
    std::string name;
    std::vector<Ref<Node>> nodes;

    Scene() = default;
    void Read(Value &obj, Asset &r);
};

struct Shader : public Object {
    Shader() = default;
    void Read(Value &obj, Asset &r);
};

struct Skin : public Object {
    Nullable<mat4> bindShapeMatrix; //!< Floating-point 4x4 transformation matrix stored in column-major order.
    Ref<Accessor> inverseBindMatrices; //!< The ID of the accessor containing the floating-point 4x4 inverse-bind matrices.
    std::vector<Ref<Node>> jointNames; //!< Joint names of the joints (nodes with a jointName property) in this skin.
    std::string name; //!< The user-defined name of this object.

    Skin() = default;
    void Read(Value &obj, Asset &r);
};

//! A texture and its sampler.
struct Texture : public Object {
    Ref<Sampler> sampler; //!< The ID of the sampler used by this texture. (required)
    Ref<Image> source; //!< The ID of the image used by this texture. (required)

    //TextureFormat format; //!< The texture's format. (default: TextureFormat_RGBA)
    //TextureFormat internalFormat; //!< The texture's internal format. (default: TextureFormat_RGBA)

    //TextureTarget target; //!< The target that the WebGL texture should be bound to. (default: TextureTarget_TEXTURE_2D)
    //TextureType type; //!< Texel datatype. (default: TextureType_UNSIGNED_BYTE)

    Texture() = default;
    void Read(Value &obj, Asset &r);
};

struct Animation : public Object {
    struct Sampler {
        Sampler() :
                interpolation(Interpolation_LINEAR) {}

        Ref<Accessor> input; //!< Accessor reference to the buffer storing the key-frame times.
        Ref<Accessor> output; //!< Accessor reference to the buffer storing the key-frame values.
        Interpolation interpolation; //!< Type of interpolation algorithm to use between key-frames.
    };

    struct Target {
        Target() :
                path(AnimationPath_TRANSLATION) {}

        Ref<Node> node; //!< The node to animate.
        AnimationPath path; //!< The property of the node to animate.
    };

    struct Channel {
        Channel() :
                sampler(-1) {}

        int sampler; //!< The sampler index containing the animation data.
        Target target; //!< The node and property to animate.
    };

    std::vector<Sampler> samplers; //!< All the key-frame data for this animation.
    std::vector<Channel> channels; //!< Data to connect nodes to key-frames.

    Animation() = default;
    void Read(Value &obj, Asset &r);
};

//! Base class for LazyDict that acts as an interface
class LazyDictBase {
public:
    virtual ~LazyDictBase() = default;

    virtual void AttachToDocument(Document &doc) = 0;
    virtual void DetachFromDocument() = 0;

#if !defined(ASSIMP_BUILD_NO_EXPORT)
    virtual void WriteObjects(AssetWriter &writer) = 0;
#endif
};

template <class T>
class LazyDict;

//! (Implemented in glTFAssetWriter.h)
template <class T>
void WriteLazyDict(LazyDict<T> &d, AssetWriter &w);

//! Manages lazy loading of the glTF top-level objects, and keeps a reference to them by ID
//! It is the owner the loaded objects, so when it is destroyed it also deletes them
template <class T>
class LazyDict : public LazyDictBase {
    friend class Asset;
    friend class AssetWriter;

    using Dict = typename std::gltf_unordered_map<unsigned int, unsigned int>;
    using IdDict = typename std::gltf_unordered_map<std::string, unsigned int>;

    std::vector<T *> mObjs; //! The read objects
    Dict mObjsByOIndex; //! The read objects accessible by original index
    IdDict mObjsById; //! The read objects accessible by id
    const char *mDictId; //! ID of the dictionary object
    const char *mExtId; //! ID of the extension defining the dictionary
    Value *mDict; //! JSON dictionary object
    Asset &mAsset; //! The asset instance

    std::gltf_unordered_set<unsigned int> mRecursiveReferenceCheck; //! Used by Retrieve to prevent recursive lookups

    void AttachToDocument(Document &doc);
    void DetachFromDocument();

#if !defined(ASSIMP_BUILD_NO_EXPORT)
    void WriteObjects(AssetWriter &writer) { WriteLazyDict<T>(*this, writer); }
#endif

    Ref<T> Add(T *obj);

public:
    LazyDict(Asset &asset, const char *dictId, const char *extId = nullptr);
    ~LazyDict();

    Ref<T> Retrieve(unsigned int i);

    Ref<T> Get(unsigned int i);
    Ref<T> Get(const char *id);

    Ref<T> Create(const char *id);
    Ref<T> Create(const std::string &id) { return Create(id.c_str()); }

    unsigned int Remove(const char *id);

    inline unsigned int Size() const { return unsigned(mObjs.size()); }

    inline T &operator[](size_t i) { return *mObjs[i]; }
};

struct AssetMetadata {
    std::string copyright; //!< A copyright message suitable for display to credit the content creator.
    std::string generator; //!< Tool that generated this glTF model.Useful for debugging.

    struct {
        std::string api; //!< Specifies the target rendering API (default: "WebGL")
        std::string version; //!< Specifies the target rendering API (default: "1.0.3")
    } profile; //!< Specifies the target rendering API and version, e.g., WebGL 1.0.3. (default: {})

    std::string version; //!< The glTF format version

    void Read(Document &doc);

    AssetMetadata() = default;
};

//
// glTF Asset class
//

//! Root object for a glTF asset
class Asset {
    using IdMap = std::gltf_unordered_map<std::string, int>;

    template <class T>
    friend class LazyDict;
    friend struct Buffer; // To access OpenFile
    friend class AssetWriter;

    std::vector<LazyDictBase *> mDicts;

public:
    //! Keeps info about the enabled extensions
    struct Extensions {
        bool KHR_materials_pbrSpecularGlossiness;
        bool KHR_materials_specular;
        bool KHR_materials_unlit;
        bool KHR_lights_punctual;
        bool KHR_texture_transform;
        bool KHR_materials_sheen;
        bool KHR_materials_clearcoat;
        bool KHR_materials_transmission;
        bool KHR_materials_volume;
        bool KHR_materials_ior;
        bool KHR_materials_emissive_strength;
        bool KHR_materials_anisotropy;
        bool KHR_draco_mesh_compression;
        bool FB_ngon_encoding;
        bool KHR_texture_basisu;

        Extensions() :
                KHR_materials_pbrSpecularGlossiness(false),
                KHR_materials_specular(false),
                KHR_materials_unlit(false),
                KHR_lights_punctual(false),
                KHR_texture_transform(false),
                KHR_materials_sheen(false),
                KHR_materials_clearcoat(false),
                KHR_materials_transmission(false),
                KHR_materials_volume(false),
                KHR_materials_ior(false),
                KHR_materials_emissive_strength(false),
                KHR_materials_anisotropy(false),
                KHR_draco_mesh_compression(false),
                FB_ngon_encoding(false),
                KHR_texture_basisu(false) {
            // empty
        }
    } extensionsUsed;

    //! Keeps info about the required extensions
    struct RequiredExtensions {
        bool KHR_draco_mesh_compression;
        bool KHR_texture_basisu;

        RequiredExtensions() : KHR_draco_mesh_compression(false), KHR_texture_basisu(false) {
            // empty
        }
    } extensionsRequired;

    AssetMetadata asset;
    Value *extras;

    // Dictionaries for each type of object

    LazyDict<Accessor> accessors;
    LazyDict<Animation> animations;
    LazyDict<Buffer> buffers;
    LazyDict<BufferView> bufferViews;
    LazyDict<Camera> cameras;
    LazyDict<Light> lights;
    LazyDict<Image> images;
    LazyDict<Material> materials;
    LazyDict<Mesh> meshes;
    LazyDict<Node> nodes;
    LazyDict<Sampler> samplers;
    LazyDict<Scene> scenes;
    LazyDict<Skin> skins;
    LazyDict<Texture> textures;

    Ref<Scene> scene;

public:
    Asset(IOSystem *io = nullptr, rapidjson::IRemoteSchemaDocumentProvider *schemaDocumentProvider = nullptr) :
            mDicts(),
            extensionsUsed(),
            extensionsRequired(),
            asset(),
            extras(nullptr),
            accessors(*this, "accessors"),
            animations(*this, "animations"),
            buffers(*this, "buffers"),
            bufferViews(*this, "bufferViews"),
            cameras(*this, "cameras"),
            lights(*this, "lights", "KHR_lights_punctual"),
            images(*this, "images"),
            materials(*this, "materials"),
            meshes(*this, "meshes"),
            nodes(*this, "nodes"),
            samplers(*this, "samplers"),
            scenes(*this, "scenes"),
            skins(*this, "skins"),
            textures(*this, "textures") ,
            mIOSystem(io),
            mSchemaDocumentProvider(schemaDocumentProvider) {
        // empty
    }

    //! Main function
    void Load(const std::string &file, bool isBinary = false);

    //! Parse the AssetMetadata and check that the version is 2.
    bool CanRead(const std::string &pFile, bool isBinary = false);

    //! Enables binary encoding on the asset
    void SetAsBinary();

    //! Search for an available name, starting from the given strings
    std::string FindUniqueID(const std::string &str, const char *suffix);

    Ref<Buffer> GetBodyBuffer() { return mBodyBuffer; }

    Asset(Asset &) = delete;
    Asset &operator=(const Asset &) = delete;

private:
    void ReadBinaryHeader(IOStream &stream, std::vector<char> &sceneData);

    /// Obtain a JSON document from the stream.
    /// \param second argument is a buffer used by the document. It must be kept
    /// alive while the document is in use.
    Document ReadDocument(IOStream& stream, bool isBinary, std::vector<char>& sceneData);

    void ReadExtensionsUsed(Document &doc);
    void ReadExtensionsRequired(Document &doc);

    IOStream *OpenFile(const std::string &path, const char *mode, bool absolute = false);

private:
    IOSystem *mIOSystem;
    rapidjson::IRemoteSchemaDocumentProvider *mSchemaDocumentProvider;
    std::string mCurrentAssetDir;
    size_t mSceneLength;
    size_t mBodyOffset;
    size_t mBodyLength;
    IdMap mUsedIds;
    std::map<std::string, int, std::less<>> mUsedNamesMap;
    Ref<Buffer> mBodyBuffer;
};

inline std::string getContextForErrorMessages(const std::string &id, const std::string &name) {
    std::string context = id;
    if (!name.empty()) {
        context += " (\"" + name + "\")";
    }
    return context;
}

} // namespace glTF2

// Include the implementation of the methods
#include "glTF2Asset.inl"

#endif // ASSIMP_BUILD_NO_GLTF_IMPORTER

#endif // GLTF2ASSET_H_INC

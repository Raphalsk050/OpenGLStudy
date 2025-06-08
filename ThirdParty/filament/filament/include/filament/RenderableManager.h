
#ifndef TNT_FILAMENT_RENDERABLEMANAGER_H
#define TNT_FILAMENT_RENDERABLEMANAGER_H

#include <filament/Box.h>
#include <filament/FilamentAPI.h>
#include <filament/MaterialEnums.h>
#include <filament/MorphTargetBuffer.h>

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/EntityInstance.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include <type_traits>

#include <float.h>
#include <stddef.h>
#include <stdint.h>

namespace utils {
    class Entity;
} // namespace utils

namespace filament {

class BufferObject;
class Engine;
class IndexBuffer;
class MaterialInstance;
class Renderer;
class SkinningBuffer;
class VertexBuffer;
class Texture;
class InstanceBuffer;

class FEngine;
class FRenderPrimitive;
class FRenderableManager;

class UTILS_PUBLIC RenderableManager : public FilamentAPI {
    struct BuilderDetails;

public:
    using Instance = utils::EntityInstance<RenderableManager>;
    using PrimitiveType = backend::PrimitiveType;

    bool hasComponent(utils::Entity e) const noexcept;

    Instance getInstance(utils::Entity e) const noexcept;

    size_t getComponentCount() const noexcept;

    bool empty() const noexcept;

    utils::Entity getEntity(Instance i) const noexcept;

    utils::Entity const* UTILS_NONNULL getEntities() const noexcept;

    struct Bone {
        math::quatf unitQuaternion = { 1.f, 0.f, 0.f, 0.f };
        math::float3 translation = { 0.f, 0.f, 0.f };
        float reserved = 0;
    };

    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        enum Result { Error = -1, Success = 0  };

        static constexpr uint8_t DEFAULT_CHANNEL = 2u;

        enum class GeometryType : uint8_t {
            DYNAMIC,        //!< dynamic gemoetry has no restriction
            STATIC_BOUNDS,  //!< bounds and world space transform are immutable
            STATIC          //!< skinning/morphing not allowed and Vertex/IndexBuffer immutables
        };

        explicit Builder(size_t count) noexcept;


        Builder& geometry(size_t index, PrimitiveType type,
                VertexBuffer* UTILS_NONNULL vertices,
                IndexBuffer* UTILS_NONNULL indices,
                size_t offset, size_t minIndex, size_t maxIndex, size_t count) noexcept;

        Builder& geometry(size_t index, PrimitiveType type,
                VertexBuffer* UTILS_NONNULL vertices,
                IndexBuffer* UTILS_NONNULL indices,
                size_t offset, size_t count) noexcept; //!< \overload

        Builder& geometry(size_t index, PrimitiveType type,
                VertexBuffer* UTILS_NONNULL vertices,
                IndexBuffer* UTILS_NONNULL indices) noexcept; //!< \overload


        Builder& geometryType(GeometryType type) noexcept;

        Builder& material(size_t index,
                MaterialInstance const* UTILS_NONNULL materialInstance) noexcept;

        Builder& boundingBox(const Box& axisAlignedBoundingBox) noexcept;

        Builder& layerMask(uint8_t select, uint8_t values) noexcept;

        Builder& priority(uint8_t priority) noexcept;

        Builder& channel(uint8_t channel) noexcept;

        Builder& culling(bool enable) noexcept;

        Builder& lightChannel(unsigned int channel, bool enable = true) noexcept;

        Builder& castShadows(bool enable) noexcept;

        Builder& receiveShadows(bool enable) noexcept;

        Builder& screenSpaceContactShadows(bool enable) noexcept;

        Builder& enableSkinningBuffers(bool enabled = true) noexcept;

        Builder& fog(bool enabled = true) noexcept;

        Builder& skinning(SkinningBuffer* UTILS_NONNULL skinningBuffer,
                size_t count, size_t offset) noexcept;


        Builder& skinning(size_t boneCount, math::mat4f const* UTILS_NONNULL transforms) noexcept;
        Builder& skinning(size_t boneCount, Bone const* UTILS_NONNULL bones) noexcept; //!< \overload
        Builder& skinning(size_t boneCount) noexcept; //!< \overload

        Builder& boneIndicesAndWeights(size_t primitiveIndex,
                math::float2 const* UTILS_NONNULL indicesAndWeights,
                size_t count, size_t bonesPerVertex) noexcept;

        Builder& boneIndicesAndWeights(size_t primitiveIndex,
                utils::FixedCapacityVector<
                    utils::FixedCapacityVector<math::float2>> indicesAndWeightsVector) noexcept;

        Builder& morphing(size_t targetCount) noexcept;

        Builder& morphing(MorphTargetBuffer* UTILS_NONNULL morphTargetBuffer) noexcept;

        RenderableManager::Builder& morphing(uint8_t level,
                size_t primitiveIndex, size_t offset) noexcept;


        Builder& blendOrder(size_t primitiveIndex, uint16_t order) noexcept;

        Builder& globalBlendOrderEnabled(size_t primitiveIndex, bool enabled) noexcept;

        Builder& instances(size_t instanceCount) noexcept;

        Builder& instances(size_t instanceCount,
                InstanceBuffer* UTILS_NONNULL instanceBuffer) noexcept;

        Result build(Engine& engine, utils::Entity entity);

    private:
        friend class FEngine;
        friend class FRenderPrimitive;
        friend class FRenderableManager;
        struct Entry {
            VertexBuffer* UTILS_NULLABLE vertices = nullptr;
            IndexBuffer* UTILS_NULLABLE indices = nullptr;
            size_t offset = 0;
            size_t count = 0;
            MaterialInstance const* UTILS_NULLABLE materialInstance = nullptr;
            PrimitiveType type = PrimitiveType::TRIANGLES;
            uint16_t blendOrder = 0;
            bool globalBlendOrderEnabled = false;
            struct {
                MorphTargetBuffer* UTILS_NULLABLE buffer = nullptr;
                size_t offset = 0;
                size_t count = 0;
            } morphing;
        };
    };

    void destroy(utils::Entity e) noexcept;

    void setAxisAlignedBoundingBox(Instance instance, const Box& aabb);

    void setLayerMask(Instance instance, uint8_t select, uint8_t values) noexcept;

    void setPriority(Instance instance, uint8_t priority) noexcept;

    void setChannel(Instance instance, uint8_t channel) noexcept;

    void setCulling(Instance instance, bool enable) noexcept;

    void setFogEnabled(Instance instance, bool enable) noexcept;

    bool getFogEnabled(Instance instance) const noexcept;

    void setLightChannel(Instance instance, unsigned int channel, bool enable) noexcept;

    bool getLightChannel(Instance instance, unsigned int channel) const noexcept;

    void setCastShadows(Instance instance, bool enable) noexcept;

    void setReceiveShadows(Instance instance, bool enable) noexcept;

    void setScreenSpaceContactShadows(Instance instance, bool enable) noexcept;

    bool isShadowCaster(Instance instance) const noexcept;

    bool isShadowReceiver(Instance instance) const noexcept;

    void setBones(Instance instance, Bone const* UTILS_NONNULL transforms,
            size_t boneCount = 1, size_t offset = 0);

    void setBones(Instance instance, math::mat4f const* UTILS_NONNULL transforms,
            size_t boneCount = 1, size_t offset = 0); //!< \overload

    void setSkinningBuffer(Instance instance, SkinningBuffer* UTILS_NONNULL skinningBuffer,
            size_t count, size_t offset);

    void setMorphWeights(Instance instance,
            float const* UTILS_NONNULL weights, size_t count, size_t offset = 0);

    void setMorphTargetBufferOffsetAt(Instance instance, uint8_t level, size_t primitiveIndex,
            size_t offset);

    MorphTargetBuffer* UTILS_NULLABLE getMorphTargetBuffer(Instance instance) const noexcept;

    size_t getMorphTargetCount(Instance instance) const noexcept;

    const Box& getAxisAlignedBoundingBox(Instance instance) const noexcept;

    uint8_t getLayerMask(Instance instance) const noexcept;

    size_t getPrimitiveCount(Instance instance) const noexcept;

    void setMaterialInstanceAt(Instance instance,
            size_t primitiveIndex, MaterialInstance const* UTILS_NONNULL materialInstance);

    MaterialInstance* UTILS_NULLABLE getMaterialInstanceAt(
            Instance instance, size_t primitiveIndex) const noexcept;

    void setGeometryAt(Instance instance, size_t primitiveIndex, PrimitiveType type,
            VertexBuffer* UTILS_NONNULL vertices,
            IndexBuffer* UTILS_NONNULL indices,
            size_t offset, size_t count) noexcept;

    void setBlendOrderAt(Instance instance, size_t primitiveIndex, uint16_t order) noexcept;

    void setGlobalBlendOrderEnabledAt(Instance instance, size_t primitiveIndex, bool enabled) noexcept;

    AttributeBitset getEnabledAttributesAt(Instance instance, size_t primitiveIndex) const noexcept;


    template<typename VECTOR, typename INDEX,
            typename = typename is_supported_vector_type<VECTOR>::type,
            typename = typename is_supported_index_type<INDEX>::type>
    static Box computeAABB(
            VECTOR const* UTILS_NONNULL vertices,
            INDEX const* UTILS_NONNULL indices, size_t count,
            size_t stride = sizeof(VECTOR)) noexcept;

protected:
    // prevent heap allocation
    ~RenderableManager() = default;
};

template<typename VECTOR, typename INDEX, typename, typename>
Box RenderableManager::computeAABB(
        VECTOR const* UTILS_NONNULL vertices,
        INDEX const* UTILS_NONNULL indices,
        size_t count, size_t stride) noexcept {
    math::float3 bmin(FLT_MAX);
    math::float3 bmax(-FLT_MAX);
    for (size_t i = 0; i < count; ++i) {
        VECTOR const* p = reinterpret_cast<VECTOR const*>(
                (char const*)vertices + indices[i] * stride);
        const math::float3 v(p->x, p->y, p->z);
        bmin = min(bmin, v);
        bmax = max(bmax, v);
    }
    return Box().set(bmin, bmax);
}

} // namespace filament

#endif // TNT_FILAMENT_RENDERABLEMANAGER_H

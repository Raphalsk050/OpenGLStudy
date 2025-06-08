
#ifndef TNT_FILAMENT_MORPHTARGETBUFFER_H
#define TNT_FILAMENT_MORPHTARGETBUFFER_H

#include <filament/FilamentAPI.h>

#include <filament/Engine.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <stddef.h>

namespace filament {

class UTILS_PUBLIC MorphTargetBuffer : public FilamentAPI {
    struct BuilderDetails;

public:
    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& vertexCount(size_t vertexCount) noexcept;

        Builder& count(size_t count) noexcept;

        MorphTargetBuffer* UTILS_NONNULL build(Engine& engine);
    private:
        friend class FMorphTargetBuffer;
    };

    void setPositionsAt(Engine& engine, size_t targetIndex,
            math::float3 const* UTILS_NONNULL positions, size_t count, size_t offset = 0);

    void setPositionsAt(Engine& engine, size_t targetIndex,
            math::float4 const* UTILS_NONNULL positions, size_t count, size_t offset = 0);

    void setTangentsAt(Engine& engine, size_t targetIndex,
            math::short4 const* UTILS_NONNULL tangents, size_t count, size_t offset = 0);

    size_t getVertexCount() const noexcept;

    size_t getCount() const noexcept;

protected:
    // prevent heap allocation
    ~MorphTargetBuffer() = default;
};

} // namespace filament

#endif //TNT_FILAMENT_MORPHTARGETBUFFER_H

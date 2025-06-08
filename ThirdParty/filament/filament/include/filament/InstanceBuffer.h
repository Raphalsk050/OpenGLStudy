
#ifndef TNT_FILAMENT_INSTANCEBUFFER_H
#define TNT_FILAMENT_INSTANCEBUFFER_H

#include <filament/FilamentAPI.h>
#include <filament/Engine.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <stddef.h>

namespace filament {

class UTILS_PUBLIC InstanceBuffer : public FilamentAPI {
    struct BuilderDetails;

public:
    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;

    public:

        explicit Builder(size_t instanceCount) noexcept;

        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& localTransforms(math::mat4f const* UTILS_NULLABLE localTransforms) noexcept;

        InstanceBuffer* UTILS_NONNULL build(Engine& engine);

    private:
        friend class FInstanceBuffer;
    };

    size_t getInstanceCount() const noexcept;

    void setLocalTransforms(math::mat4f const* UTILS_NONNULL localTransforms,
            size_t count, size_t offset = 0);

protected:
    // prevent heap allocation
    ~InstanceBuffer() = default;
};

} // namespace filament

#endif //TNT_FILAMENT_INSTANCEBUFFER_H

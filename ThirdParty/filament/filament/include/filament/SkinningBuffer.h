
#ifndef TNT_FILAMENT_SKINNINGBUFFER_H
#define TNT_FILAMENT_SKINNINGBUFFER_H

#include <filament/FilamentAPI.h>

#include <filament/RenderableManager.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <stddef.h>
#include <stdint.h>

namespace filament {

class UTILS_PUBLIC SkinningBuffer : public FilamentAPI {
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

        Builder& boneCount(uint32_t boneCount) noexcept;

        Builder& initialize(bool initialize = true) noexcept;

        SkinningBuffer* UTILS_NONNULL build(Engine& engine);
    private:
        friend class FSkinningBuffer;
    };

    void setBones(Engine& engine, RenderableManager::Bone const* UTILS_NONNULL transforms,
            size_t count, size_t offset = 0);

    void setBones(Engine& engine, math::mat4f const* UTILS_NONNULL transforms,
            size_t count, size_t offset = 0);

    size_t getBoneCount() const noexcept;

protected:
    // prevent heap allocation
    ~SkinningBuffer() = default;
};

} // namespace filament

#endif //TNT_FILAMENT_SKINNINGBUFFER_H

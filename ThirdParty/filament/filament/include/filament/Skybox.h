
//! \file

#ifndef TNT_FILAMENT_SKYBOX_H
#define TNT_FILAMENT_SKYBOX_H

#include <filament/FilamentAPI.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <stdint.h>

namespace filament {

class FSkybox;

class Engine;
class Texture;

class UTILS_PUBLIC Skybox : public FilamentAPI {
    struct BuilderDetails;

public:
    //! Use Builder to construct an Skybox object instance
    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& environment(Texture* UTILS_NONNULL cubemap) noexcept;

        Builder& showSun(bool show) noexcept;

        Builder& intensity(float envIntensity) noexcept;

        Builder& color(math::float4 color) noexcept;

        Skybox* UTILS_NONNULL build(Engine& engine);

    private:
        friend class FSkybox;
    };

    void setColor(math::float4 color) noexcept;

    void setLayerMask(uint8_t select, uint8_t values) noexcept;

    uint8_t getLayerMask() const noexcept;

    float getIntensity() const noexcept;

    Texture const* UTILS_NONNULL getTexture() const noexcept;

protected:
    // prevent heap allocation
    ~Skybox() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_SKYBOX_H

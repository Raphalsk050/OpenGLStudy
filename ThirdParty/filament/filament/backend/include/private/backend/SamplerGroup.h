
#ifndef TNT_FILAMENT_BACKEND_PRIVATE_SAMPLERGROUP_H
#define TNT_FILAMENT_BACKEND_PRIVATE_SAMPLERGROUP_H

#include <backend/DriverApiForward.h>
#include <backend/DriverEnums.h>
#include <backend/SamplerDescriptor.h>

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"

#include <stddef.h>

namespace filament::backend {

class BufferDescriptor;


class SamplerGroup {
public:

    using SamplerParams = backend::SamplerParams;

    SamplerGroup() noexcept {} // NOLINT

    // create a sampler group
    explicit SamplerGroup(size_t count) noexcept;

    // can be copied. Sets dirty flag.
    SamplerGroup(const SamplerGroup& rhs) noexcept;
    SamplerGroup& operator=(const SamplerGroup& rhs) noexcept;

    // and moved. Leaves rhs empty, keep diry flag on new SamplerGroup.
    SamplerGroup(SamplerGroup&& rhs) noexcept = default;
    SamplerGroup& operator=(SamplerGroup&& rhs) = default;

    ~SamplerGroup() noexcept = default;

    BufferDescriptor toBufferDescriptor(DriverApi& driver) const noexcept;

    // sampler count
    size_t getSize() const noexcept { return mBuffer.size(); }

    // return if any samplers has been changed
    bool isDirty() const noexcept {
        return mDirty;
    }

    // mark the whole group as clean (no modified uniforms)
    void clean() const noexcept { mDirty = false; }

    // set sampler at given index
    void setSampler(size_t index, backend::SamplerDescriptor sampler) noexcept;

    inline void clearSampler(size_t index) {
        setSampler(index, {});
    }


    // FIXME: This is now [[deprecated]]. Currently it is only used by the Vulkan/Metal backends.
    backend::SamplerDescriptor* data() noexcept { return mBuffer.data(); }

private:
#if !defined(NDEBUG)
    friend utils::io::ostream& operator<<(utils::io::ostream& out, const SamplerGroup& rhs);
#endif

    utils::FixedCapacityVector<backend::SamplerDescriptor> mBuffer;
    mutable bool mDirty = false;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_PRIVATE_SAMPLERGROUP_H

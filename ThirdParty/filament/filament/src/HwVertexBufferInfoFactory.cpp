
#include "HwVertexBufferInfoFactory.h"

#include <backend/DriverApiForward.h>
#include <backend/DriverEnums.h>
#include <backend/Handle.h>

#include <private/backend/DriverApi.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"
#include "third_party/filament/libs/utils/include/utils/Hash.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

namespace filament {

using namespace utils;
using namespace backend;

size_t HwVertexBufferInfoFactory::Parameters::hash() const noexcept {
    static_assert((sizeof(*this) % sizeof(uint32_t)) == 0);
    return utils::hash::murmur3(
            reinterpret_cast<uint32_t const*>(this), sizeof(Parameters) / sizeof(uint32_t), 0);
}

bool operator==(HwVertexBufferInfoFactory::Parameters const& lhs,
        HwVertexBufferInfoFactory::Parameters const& rhs) noexcept {
    return !memcmp(&lhs, &rhs, sizeof(HwVertexBufferInfoFactory::Parameters));
}

// ------------------------------------------------------------------------------------------------

HwVertexBufferInfoFactory::HwVertexBufferInfoFactory()
        : mArena("HwVertexBufferInfoFactory::mArena", SET_ARENA_SIZE),
          mBimap(mArena) {
    mBimap.reserve(256);
}

HwVertexBufferInfoFactory::~HwVertexBufferInfoFactory() noexcept = default;

void HwVertexBufferInfoFactory::terminate(DriverApi&) noexcept {
    assert_invariant(mBimap.empty());
}

auto HwVertexBufferInfoFactory::create(DriverApi& driver,
        uint8_t bufferCount,
        uint8_t attributeCount,
        backend::AttributeArray attributes) noexcept -> Handle {

    Key const key({ bufferCount, attributeCount, {}, attributes });
    auto pos = mBimap.find(key);

    // the common case is that we've never seen it (i.e.: no reuse)
    if (UTILS_LIKELY(pos == mBimap.end())) {
        auto handle = driver.createVertexBufferInfo(
                bufferCount, attributeCount,
                attributes);
        mBimap.insert(key, { handle });
        return handle;
    }

    ++(pos->first.pKey->refs);
    return pos->second.handle;
}

void HwVertexBufferInfoFactory::destroy(DriverApi& driver, Handle handle) noexcept {
    // look for this handle in our map
    auto pos = mBimap.find(Value{ handle });
    if (--(pos->second.pKey->refs) == 0) {
        mBimap.erase(pos);
        driver.destroyVertexBufferInfo(handle);
    }
}

} // namespace filament

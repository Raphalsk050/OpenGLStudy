
#include "fg/Blackboard.h"

#include <string_view>

namespace filament {

Blackboard::Blackboard() noexcept = default;

Blackboard::~Blackboard() noexcept = default;

FrameGraphHandle Blackboard::getHandle(std::string_view name) const noexcept {
    auto it = mMap.find(name);
    if (it != mMap.end()) {
        return it->second;
    }
    return {};
}

FrameGraphHandle& Blackboard::operator [](std::string_view name) noexcept {
    auto[pos, _] = mMap.insert_or_assign(name, FrameGraphHandle{});
    return pos->second;
}

void Blackboard::put(std::string_view name, FrameGraphHandle handle) noexcept {
    operator[](name) = handle;
}


void Blackboard::remove(std::string_view name) noexcept {
    mMap.erase(name);
}

} // namespace filament

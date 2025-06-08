
#ifndef TNT_FILAMENT_FG_FRAMEGRAPHID_H
#define TNT_FILAMENT_FG_FRAMEGRAPHID_H

#include <stdint.h>
#include <limits>
#include <utility>

namespace filament {

template<typename T>
class FrameGraphId;

class Blackboard;
class FrameGraph;
class FrameGraphResources;
class PassNode;
class ResourceNode;

template<typename RESOURCE>
class FrameGraphId : public FrameGraphHandle {
public:
    using FrameGraphHandle::FrameGraphHandle;
    FrameGraphId() noexcept = default;
    explicit FrameGraphId(FrameGraphHandle r) : FrameGraphHandle(r) { }
};

} // namespace filament

#endif //TNT_FILAMENT_FG_FRAMEGRAPHID_H

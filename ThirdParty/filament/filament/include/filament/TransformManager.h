
#ifndef TNT_FILAMENT_TRANSFORMMANAGER_H
#define TNT_FILAMENT_TRANSFORMMANAGER_H

#include <filament/FilamentAPI.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/EntityInstance.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <iterator>

#include <stddef.h>

namespace utils {
class Entity;
} // namespace utils

namespace filament {

class FTransformManager;

class UTILS_PUBLIC TransformManager : public FilamentAPI {
public:
    using Instance = utils::EntityInstance<TransformManager>;

    class children_iterator {
        friend class FTransformManager;
        TransformManager const& mManager;
        Instance mInstance;
        children_iterator(TransformManager const& mgr, Instance instance) noexcept
                : mManager(mgr), mInstance(instance) { }
    public:
        using value_type = Instance;
        using difference_type = ptrdiff_t;
        using pointer = Instance*;
        using reference = Instance&;
        using iterator_category = std::forward_iterator_tag;

        children_iterator& operator++();

        children_iterator operator++(int) { // NOLINT
            children_iterator ret(*this);
            ++(*this);
            return ret;
        }

        bool operator == (const children_iterator& other) const noexcept {
            return mInstance == other.mInstance;
        }

        bool operator != (const children_iterator& other) const noexcept {
            return mInstance != other.mInstance;
        }

        value_type operator*() const { return mInstance; }
    };

    bool hasComponent(utils::Entity e) const noexcept;

    Instance getInstance(utils::Entity e) const noexcept;

    size_t getComponentCount() const noexcept;

    bool empty() const noexcept;

    utils::Entity getEntity(Instance i) const noexcept;

    utils::Entity const* UTILS_NONNULL getEntities() const noexcept;

    void setAccurateTranslationsEnabled(bool enable) noexcept;

    bool isAccurateTranslationsEnabled() const noexcept;

    void create(utils::Entity entity, Instance parent, const math::mat4f& localTransform);
    void create(utils::Entity entity, Instance parent, const math::mat4& localTransform); //!< \overload
    void create(utils::Entity entity, Instance parent = {}); //!< \overload

    void destroy(utils::Entity e) noexcept;

    void setParent(Instance i, Instance newParent) noexcept;

    utils::Entity getParent(Instance i) const noexcept;

    size_t getChildCount(Instance i) const noexcept;

    size_t getChildren(Instance i, utils::Entity* UTILS_NONNULL children, size_t count) const noexcept;

    children_iterator getChildrenBegin(Instance parent) const noexcept;

    children_iterator getChildrenEnd(Instance parent) const noexcept;

    void setTransform(Instance ci, const math::mat4f& localTransform) noexcept;

    void setTransform(Instance ci, const math::mat4& localTransform) noexcept;

    const math::mat4f& getTransform(Instance ci) const noexcept;

    math::mat4 getTransformAccurate(Instance ci) const noexcept;

    const math::mat4f& getWorldTransform(Instance ci) const noexcept;

    math::mat4 getWorldTransformAccurate(Instance ci) const noexcept;

    void openLocalTransformTransaction() noexcept;

    void commitLocalTransformTransaction() noexcept;

protected:
    // prevent heap allocation
    ~TransformManager() = default;
};

} // namespace filament


#endif // TNT_TRANSFORMMANAGER_H

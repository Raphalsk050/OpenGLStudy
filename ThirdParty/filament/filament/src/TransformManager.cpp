
#include "components/TransformManager.h"

using namespace utils;

namespace filament {

using namespace math;

bool TransformManager::hasComponent(Entity e) const noexcept {
    return downcast(this)->hasComponent(e);
}

size_t TransformManager::getComponentCount() const noexcept {
    return downcast(this)->getComponentCount();
}

bool TransformManager::empty() const noexcept {
    return downcast(this)->empty();
}

utils::Entity TransformManager::getEntity(TransformManager::Instance i) const noexcept {
    return downcast(this)->getEntity(i);
}

utils::Entity const* TransformManager::getEntities() const noexcept {
    return downcast(this)->getEntities();
}

TransformManager::Instance TransformManager::getInstance(Entity e) const noexcept {
    return downcast(this)->getInstance(e);
}

void TransformManager::create(Entity entity, Instance parent, const mat4f& worldTransform) {
    downcast(this)->create(entity, parent, worldTransform);
}

void TransformManager::create(Entity entity, Instance parent, const mat4& worldTransform) {
    downcast(this)->create(entity, parent, worldTransform);
}

void TransformManager::create(Entity entity, Instance parent) {
    downcast(this)->create(entity, parent, mat4f{});
}

void TransformManager::destroy(Entity e) noexcept {
    downcast(this)->destroy(e);
}

void TransformManager::setTransform(Instance ci, const mat4f& model) noexcept {
    downcast(this)->setTransform(ci, model);
}

void TransformManager::setTransform(Instance ci, const mat4& model) noexcept {
    downcast(this)->setTransform(ci, model);
}

const mat4f& TransformManager::getTransform(Instance ci) const noexcept {
    return downcast(this)->getTransform(ci);
}

mat4 TransformManager::getTransformAccurate(Instance ci) const noexcept {
    return downcast(this)->getTransformAccurate(ci);
}

const mat4f& TransformManager::getWorldTransform(Instance ci) const noexcept {
    return downcast(this)->getWorldTransform(ci);
}

mat4 TransformManager::getWorldTransformAccurate(Instance ci) const noexcept {
    return downcast(this)->getWorldTransformAccurate(ci);
}

void TransformManager::setParent(Instance i, Instance newParent) noexcept {
    downcast(this)->setParent(i, newParent);
}

utils::Entity TransformManager::getParent(Instance i) const noexcept {
    return downcast(this)->getParent(i);
}

size_t TransformManager::getChildCount(Instance i) const noexcept {
    return downcast(this)->getChildCount(i);
}

size_t TransformManager::getChildren(Instance i, utils::Entity* children,
        size_t count) const noexcept {
    return downcast(this)->getChildren(i, children, count);
}

void TransformManager::openLocalTransformTransaction() noexcept {
    downcast(this)->openLocalTransformTransaction();
}

void TransformManager::commitLocalTransformTransaction() noexcept {
    downcast(this)->commitLocalTransformTransaction();
}

TransformManager::children_iterator TransformManager::getChildrenBegin(
        TransformManager::Instance parent) const noexcept {
    return downcast(this)->getChildrenBegin(parent);
}

TransformManager::children_iterator TransformManager::getChildrenEnd(
        TransformManager::Instance parent) const noexcept {
    return downcast(this)->getChildrenEnd(parent);
}

void TransformManager::setAccurateTranslationsEnabled(bool enable) noexcept {
    downcast(this)->setAccurateTranslationsEnabled(enable);
}

bool TransformManager::isAccurateTranslationsEnabled() const noexcept {
    return downcast(this)->isAccurateTranslationsEnabled();
}

} // namespace filament

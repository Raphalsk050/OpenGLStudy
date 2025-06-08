
#include "details/Scene.h"

#include "details/IndirectLight.h"
#include "details/Skybox.h"

using namespace utils;

namespace filament {

void Scene::setSkybox(Skybox* skybox) noexcept {
    downcast(this)->setSkybox(downcast(skybox));
}

Skybox* Scene::getSkybox() const noexcept {
    return downcast(this)->getSkybox();
}

void Scene::setIndirectLight(IndirectLight* ibl) noexcept {
    downcast(this)->setIndirectLight(downcast(ibl));
}

IndirectLight* Scene::getIndirectLight() const noexcept {
    return downcast(this)->getIndirectLight();
}

void Scene::addEntity(Entity entity) {
    downcast(this)->addEntity(entity);
}

void Scene::addEntities(const Entity* entities, size_t count) {
    downcast(this)->addEntities(entities, count);
}

void Scene::remove(Entity entity) {
    downcast(this)->remove(entity);
}

void Scene::removeEntities(const Entity* entities, size_t count) {
    downcast(this)->removeEntities(entities, count);
}

size_t Scene::getEntityCount() const noexcept {
    return downcast(this)->getEntityCount();
}

size_t Scene::getRenderableCount() const noexcept {
    return downcast(this)->getRenderableCount();
}

size_t Scene::getLightCount() const noexcept {
    return downcast(this)->getLightCount();
}

bool Scene::hasEntity(Entity entity) const noexcept {
    return downcast(this)->hasEntity(entity);
}

void Scene::forEach(Invocable<void(utils::Entity)>&& functor) const noexcept {
    downcast(this)->forEach(std::move(functor));
}

} // namespace filament

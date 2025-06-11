#include "PhysicsWorld.h"

#include "CollisionShape.h"
#include "RigidBody.h"
#include "Core/engine.h"
#include "Core/Scene/Components.h"
#include "Core/Scene/Scene.h"
#include <future>
#include <memory>
#include "Core/Utils.h"
#include <glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <thread>
#include <gtx/quaternion.hpp>

namespace GLStudy
{
    PhysicsWorld::PhysicsWorld()
    {
        collisionConfiguration_ = std::make_unique<btDefaultCollisionConfiguration>();
        dispatcher_ = std::make_unique<btCollisionDispatcher>(collisionConfiguration_.get());
        overlapping_pair_cache_ = std::make_unique<btDbvtBroadphase>();
        solver_ = std::make_unique<btSequentialImpulseConstraintSolver>();
        dynamics_world_ = std::make_unique<btDiscreteDynamicsWorld>(dispatcher_.get(), overlapping_pair_cache_.get(), solver_.get(), collisionConfiguration_.get());
        dynamics_world_->setGravity(gravity_);

        // Setup all the rigidBody components in the scene

        auto body_view = Engine::Get().GetScene()->registry_.view<RigidBodyComponent>();
        for (auto entity : body_view)
        {
            auto& rb = body_view.get<RigidBodyComponent>(entity);
            // TODO(rafael): implement other mesh types
            switch (rb.mesh_type)
            {
            case MeshType::Sphere:
                {
                    auto transform = Engine::Get().GetScene()->GetWorldMatrix(entity);
                    auto rb_transform = ConvertMat4ToBtTransform(transform);

                    rb.body = CreateRigidBody(rb.mass, rb_transform, CollisionShape::createSphereShape(rb.size.getX()));
                    rb.body->get()->setAngularFactor(rb.angular_factor);
                    if (rb.disable_sleep)
                        rb.body->get()->setActivationState(DISABLE_DEACTIVATION);
                    break;
                }


            case MeshType::Cube:
                {
                    auto transform = Engine::Get().GetScene()->GetWorldMatrix(entity);
                    auto rb_transform = ConvertMat4ToBtTransform(transform);

                    rb.body = CreateRigidBody(rb.mass, rb_transform, CollisionShape::createBoxShape(rb.size / 2.0f));
                    rb.body->get()->setAngularFactor(rb.angular_factor);
                    if (rb.disable_sleep)
                        rb.body->get()->setActivationState(DISABLE_DEACTIVATION);
                    break;
                }
            }
        }
    }

    PhysicsWorld::~PhysicsWorld()
    {
        if (dynamics_world_)
        {
            std::scoped_lock lock(world_mutex_);
            for (int i = dynamics_world_->getNumCollisionObjects() - 1; i >= 0; --i)
            {
                btCollisionObject* obj = dynamics_world_->getCollisionObjectArray()[i];
                dynamics_world_->removeCollisionObject(obj);
                delete obj;
            }
            dynamics_world_.reset();
        }
    }

    void PhysicsWorld::Update(Timestep ts)
    {
        StepSimulation(ts);

        Engine& engine = Engine::Get();
        std::scoped_lock lock(engine.GetSceneMutex(), world_mutex_);
        Scene* scene = engine.GetScene();

        // synchronize entity transforms with Bullet rigid bodies
        auto view = scene->registry_.view<TransformComponent, RigidBodyComponent>();
        for (auto entity : view)
        {
            auto& tr = view.get<TransformComponent>(entity);
            auto& rb = view.get<RigidBodyComponent>(entity);
            if (rb.body && rb.body->body_)
            {
                btTransform trans;
                rb.body->body_->getMotionState()->getWorldTransform(trans);
                btVector3 pos = trans.getOrigin();
                tr.position = glm::vec3(pos.getX(), pos.getY(), pos.getZ());
                btQuaternion rot = trans.getRotation();
                glm::quat q(rot.getW(), rot.getX(), rot.getY(), rot.getZ());
                tr.rotation = glm::eulerAngles(q);
            }
        }

        scene->LateUpdate(ts);
    }

    void PhysicsWorld::SetGravity(const btVector3& gravity)
    {
        gravity_ = gravity;
        dynamics_world_->setGravity(gravity_);
    }

    void PhysicsWorld::SetTimeStep(float timeStep)
    {
        time_steps_ = timeStep;
    }

    void PhysicsWorld::AddConstraint(btTypedConstraint* constraint, bool disableCollisionsBetweenLinkedBodies)
    {
        std::scoped_lock lock(world_mutex_);
        dynamics_world_->addConstraint(constraint, disableCollisionsBetweenLinkedBodies);
    }

    void PhysicsWorld::StepSimulation(float deltaTime) const
    {
        if (dynamics_world_)
        {
            std::scoped_lock lock(world_mutex_);
            dynamics_world_->stepSimulation(deltaTime);
        }
    }

    // TODO(rafael): make a complete wrapper around btCollisionShape. Now we only have a class that creates directly and returns a btCollsionShape pointer
RigidBody* PhysicsWorld::CreateRigidBody(float mass, const btTransform& startTransform, btCollisionShape* shape)
{
    std::scoped_lock lock(world_mutex_);
    auto body = new RigidBody(shape, mass, startTransform);
    dynamics_world_->addRigidBody(body->body_);
    return body;
}

std::future<RigidBodyComponent> PhysicsWorld::AddRigidbodyAsync(EntityHandle entity, const RigidBodyComponent& spec)
{
    // First add a placeholder component to the entity
    entity.AddComponent<RigidBodyComponent>(spec);

    auto task = [=, this]() mutable -> RigidBodyComponent {
        RigidBodyComponent rb = spec;
        if (!dynamics_world_)
            return rb;

        auto transform = Engine::Get().GetScene()->GetWorldMatrix(entity.Raw());
        auto rb_transform = ConvertMat4ToBtTransform(transform);

        btCollisionShape* shape = nullptr;
        switch (rb.mesh_type)
        {
            case MeshType::Sphere:
                shape = CollisionShape::createSphereShape(rb.size.getX());
                break;
            case MeshType::Cube:
            default:
                shape = CollisionShape::createBoxShape(rb.size / 2.0f);
                break;
        }

        rb.body = CreateRigidBody(rb.mass, rb_transform, shape);
        rb.body->get()->setUserIndex(static_cast<int>(entity.Raw()));
        rb.body->get()->setAngularFactor(rb.angular_factor);
        if (rb.disable_sleep)
            rb.body->get()->setActivationState(DISABLE_DEACTIVATION);

        auto& registry = Engine::Get().GetScene()->registry_;
        registry.patch<RigidBodyComponent>(entity.Raw(), [&](auto& comp){ comp.body = rb.body; });
        return rb;
    };

    return std::async(std::launch::async, std::move(task));
}

bool PhysicsWorld::Raycast(const glm::vec3& from, const glm::vec3& to, RaycastHit& outHit) const
{
    if (!dynamics_world_)
        return false;

    btVector3 start(from.x, from.y, from.z);
    btVector3 end(to.x, to.y, to.z);

    btCollisionWorld::ClosestRayResultCallback cb(start, end);

    {
        std::scoped_lock lock(world_mutex_);
        dynamics_world_->rayTest(start, end, cb);
    }

    if (cb.hasHit())
    {
        outHit.hitPoint = glm::vec3(cb.m_hitPointWorld.x(), cb.m_hitPointWorld.y(), cb.m_hitPointWorld.z());
        outHit.hitNormal = glm::vec3(cb.m_hitNormalWorld.x(), cb.m_hitNormalWorld.y(), cb.m_hitNormalWorld.z());
        outHit.distance = cb.m_closestHitFraction;

        entt::entity e = entt::null;
        if (cb.m_collisionObject)
            e = static_cast<entt::entity>(cb.m_collisionObject->getUserIndex());
        outHit.entity = EntityHandle(e, Engine::Get().GetScene());
        return true;
    }

    return false;
}
} // GLStudy

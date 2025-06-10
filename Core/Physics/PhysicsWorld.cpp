#include "PhysicsWorld.h"

#include "CollisionShape.h"
#include "RigidBody.h"
#include "Core/engine.h"
#include "Core/Scene/Components.h"
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
        // Bullet objects are owned by unique_ptr, but ensure world is cleared first
        if (dynamics_world_)
        {
            // Remove all rigid bodies to avoid dangling pointers
            for (int i = dynamics_world_->getNumCollisionObjects() - 1; i >= 0; --i)
            {
                btCollisionObject* obj = dynamics_world_->getCollisionObjectArray()[i];
                dynamics_world_->removeCollisionObject(obj);
                delete obj;
            }
        }
    }

    void PhysicsWorld::Update(Timestep ts)
    {
        StepSimulation(ts);

        // synchronize entity transforms with Bullet rigid bodies
        auto view = Engine::Get().GetScene()->registry_.view<TransformComponent, RigidBodyComponent>();
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
        dynamics_world_->addConstraint(constraint, disableCollisionsBetweenLinkedBodies);
    }

    void PhysicsWorld::StepSimulation(float deltaTime) const
    {
        if (dynamics_world_)
        {
            dynamics_world_->stepSimulation(deltaTime);
        }
    }

    // TODO(rafael): make a complete wrapper around btCollisionShape. Now we only have a class that creates directly and returns a btCollsionShape pointer
RigidBody* PhysicsWorld::CreateRigidBody(float mass, const btTransform& startTransform, btCollisionShape* shape)
{
    auto body = new RigidBody(shape, mass, startTransform);
    dynamics_world_->addRigidBody(body->body_);
    return body;
}

std::future<RigidBodyComponent> PhysicsWorld::AddRigidbodyAsync(EntityHandle entity, const RigidBodyComponent& spec)
{
    // First add a placeholder component to the entity
    entity.AddComponent<RigidBodyComponent>(spec);

    std::packaged_task<RigidBodyComponent()> task([=, this]() mutable -> RigidBodyComponent {
        RigidBodyComponent rb = spec;

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
        rb.body->get()->setAngularFactor(rb.angular_factor);
        if (rb.disable_sleep)
            rb.body->get()->setActivationState(DISABLE_DEACTIVATION);

        // Update the component in the registry
        auto& registry = Engine::Get().GetScene()->registry_;
        registry.patch<RigidBodyComponent>(entity.Raw(), [&](auto& comp){ comp.body = rb.body; });
        return rb;
    });

    std::future<RigidBodyComponent> future = task.get_future();
    std::thread(std::move(task)).detach();
    return future;
}
} // GLStudy

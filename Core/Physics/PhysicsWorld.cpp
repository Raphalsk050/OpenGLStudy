#include "PhysicsWorld.h"

#include "CollisionShape.h"
#include "RigidBody.h"
#include "Core/engine.h"
#include "Core/Scene/Components.h"
#include "Core/Utils.h"
#include "ThirdParty/bullet/examples/TinyRenderer/our_gl.h"
#include <glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/quaternion.hpp>

namespace GLStudy
{
    PhysicsWorld::PhysicsWorld()
    {
        collisionConfiguration_ = new btDefaultCollisionConfiguration();
        dispatcher_ = new btCollisionDispatcher(collisionConfiguration_);
        overlapping_pair_cache_ = new btDbvtBroadphase();
        solver_ = new btSequentialImpulseConstraintSolver();
        dynamics_world_ = new btDiscreteDynamicsWorld(dispatcher_, overlapping_pair_cache_, solver_, collisionConfiguration_);
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
                    break;
                }


            case MeshType::Cube:
                {
                    auto transform = Engine::Get().GetScene()->GetWorldMatrix(entity);
                    auto rb_transform = ConvertMat4ToBtTransform(transform);

                    rb.body = CreateRigidBody(rb.mass, rb_transform, CollisionShape::createBoxShape(rb.size / 2.0f));
                    break;
                }
            }
        }
    }

    void PhysicsWorld::Update()
    {
        StepSimulation(time_steps_);

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
} // GLStudy

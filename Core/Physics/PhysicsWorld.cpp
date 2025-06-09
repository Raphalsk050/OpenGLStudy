#include "PhysicsWorld.h"

#include "CollisionShape.h"
#include "RigidBody.h"
#include "Core/engine.h"
#include "Core/Scene/Components.h"
#include "Core/Utils.h"
#include "ThirdParty/bullet/examples/TinyRenderer/our_gl.h"

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
        auto transform_view = Engine::Get().GetScene()->registry_.view<TransformComponent>();

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

                    CreateRigidBody(rb.mass, rb_transform, CollisionShape::createSphereShape(rb.size));
                    break;
                }


            case MeshType::Cube:
                {
                    auto transform = Engine::Get().GetScene()->GetWorldMatrix(entity);
                    auto rb_transform = ConvertMat4ToBtTransform(transform);

                    CreateRigidBody(rb.mass, rb_transform, CollisionShape::createBoxShape(btVector3(rb.size / 2.0f, rb.size / 2.0f, rb.size / 2.0f)));
                    break;
                }
            }
        }
    }

    void PhysicsWorld::Update()
    {
        StepSimulation(time_steps_);
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
    }
} // GLStudy

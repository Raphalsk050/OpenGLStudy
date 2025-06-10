#pragma once
#include <btBulletDynamicsCommon.h>

#include "Core/TimeStep.h"
#include <future>
#include <memory>
#include "Core/Scene/EntityHandle.h"
#include "Core/Scene/Components.h"

namespace GLStudy
{
    class RigidBody;

    class PhysicsWorld
    {
    public:
        PhysicsWorld();
        ~PhysicsWorld();
        void SetGravity(const btVector3& gravity);
        void SetTimeStep(float timeStep);


        void AddConstraint(btTypedConstraint* constraint, bool disableCollisionsBetweenLinkedBodies);

        // Expose rigid body creation so external systems can asynchronously
        // create bodies when components are added at runtime
        RigidBody* CreateRigidBody(float mass, const btTransform& startTransform, btCollisionShape* shape);

        // Create a RigidBodyComponent asynchronously for an entity using std futures
        std::future<RigidBodyComponent> AddRigidbodyAsync(EntityHandle entity, const RigidBodyComponent& spec);

        // Convenience wrapper matching typical AddComponent semantics
        std::future<RigidBodyComponent> AddRigidbody(EntityHandle entity, const RigidBodyComponent& spec)
        {
            return AddRigidbodyAsync(entity, spec);
        }


    private:
        btScalar time_steps_ = 1.0f / 60.0f;
        btVector3 gravity_ = btVector3(0.0f, -9.807f, 0.0f);
        std::unique_ptr<btCollisionDispatcher> dispatcher_;
        std::unique_ptr<btBroadphaseInterface> overlapping_pair_cache_;
        std::unique_ptr<btSequentialImpulseConstraintSolver> solver_;
        std::unique_ptr<btDefaultCollisionConfiguration> collisionConfiguration_;
        std::unique_ptr<btDiscreteDynamicsWorld> dynamics_world_;

    private:
        void Update(Timestep ts);

        void StepSimulation(float deltaTime) const;

        friend class Engine;
    };
} // GLStudy

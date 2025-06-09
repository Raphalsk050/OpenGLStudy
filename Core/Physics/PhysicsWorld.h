#pragma once
#include <btBulletDynamicsCommon.h>

#include "Core/TimeStep.h"
#include <boost/thread/future.hpp>
#include "Core/Scene/EntityHandle.h"
#include "Core/Scene/Components.h"

namespace GLStudy
{
    class RigidBody;

    class PhysicsWorld
    {
    public:
        PhysicsWorld();
        void SetGravity(const btVector3& gravity);
        void SetTimeStep(float timeStep);


        void AddConstraint(btTypedConstraint* constraint, bool disableCollisionsBetweenLinkedBodies);

        // Expose rigid body creation so external systems can asynchronously
        // create bodies when components are added at runtime
        RigidBody* CreateRigidBody(float mass, const btTransform& startTransform, btCollisionShape* shape);

        // Create a RigidBodyComponent asynchronously for an entity using Boost futures
        boost::future<RigidBodyComponent> AddRigidbodyAsync(EntityHandle entity, const RigidBodyComponent& spec);


    private:
        btScalar time_steps_ = 1.0f / 60.0f;
        btVector3 gravity_ = btVector3(0.0f, -9.807f, 0.0f);
        btCollisionDispatcher* dispatcher_;
        btBroadphaseInterface* overlapping_pair_cache_;
        btSequentialImpulseConstraintSolver* solver_;
        btDefaultCollisionConfiguration* collisionConfiguration_;
        btDiscreteDynamicsWorld* dynamics_world_;

    private:
        void Update(Timestep ts);

        void StepSimulation(float deltaTime) const;

        void physicsDebugDraw(int debugFlags)
        {
            if (dynamics_world_ && dynamics_world_->getDebugDrawer())
            {
                dynamics_world_->getDebugDrawer()->setDebugMode(debugFlags);
                dynamics_world_->debugDrawWorld();
            }
        }

        friend class Engine;
    };
} // GLStudy

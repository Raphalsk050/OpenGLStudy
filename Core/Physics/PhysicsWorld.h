#pragma once
#include <btBulletDynamicsCommon.h>

namespace GLStudy
{
    class RigidBody;

    class PhysicsWorld
    {
    public:
        PhysicsWorld();
        void SetGravity(const btVector3& gravity);
        void SetTimeStep(float timeStep);

    private:
        btScalar time_steps_ = 1.0f / 60.0f;
        btVector3 gravity_ = btVector3(0.0f, -9.807f, 0.0f);
        btCollisionDispatcher* dispatcher_;
        btBroadphaseInterface* overlapping_pair_cache_;
        btSequentialImpulseConstraintSolver* solver_;
        btDefaultCollisionConfiguration* collisionConfiguration_;
        btDiscreteDynamicsWorld* dynamics_world_;

    private:
        void Update();

        RigidBody* CreateRigidBody(float mass, const btTransform& startTransform, btCollisionShape* shape);

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

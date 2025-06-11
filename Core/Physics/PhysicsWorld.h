#pragma once
#include <btBulletDynamicsCommon.h>

#include "Core/TimeStep.h"
#include <future>
#include <memory>
#include <mutex>
#include <glm.hpp>
#include "Core/Scene/EntityHandle.h"
#include "Core/Scene/Components.h"

namespace GLStudy
{
    class RigidBody;

    struct RaycastHit
    {
        EntityHandle entity;
        glm::vec3 hitPoint{0.0f};
        glm::vec3 hitNormal{0.0f};
        float distance{0.0f};
    };

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

        bool Raycast(const glm::vec3& from, const glm::vec3& to, RaycastHit& outHit) const;


    private:
        btScalar time_steps_ = 1.0f / 60.0f;
        btVector3 gravity_ = btVector3(0.0f, -9.807f, 0.0f);
        std::unique_ptr<btCollisionDispatcher> dispatcher_;
        std::unique_ptr<btBroadphaseInterface> overlapping_pair_cache_;
        std::unique_ptr<btSequentialImpulseConstraintSolver> solver_;
        std::unique_ptr<btDefaultCollisionConfiguration> collisionConfiguration_;
        std::unique_ptr<btDiscreteDynamicsWorld> dynamics_world_;

        mutable std::mutex world_mutex_;

    public:
        /**
         * Execute a callable while holding the internal world mutex. This
         * allows game code to safely interact with Bullet objects without
         * exposing the mutex itself.
         */
        template <typename Fn>
        auto RunLocked(Fn&& fn) const -> decltype(fn())
        {
            std::scoped_lock lock(world_mutex_);
            return fn();
        }

    private:
        void Update(Timestep ts);

        void StepSimulation(float deltaTime) const;

        friend class Engine;
    };
} // GLStudy

#pragma once
#include "BulletDynamics/Dynamics/btRigidBody.h"

namespace GLStudy
{
    // This class is a wrapper around btRigidBody from bullet physics
    class RigidBody
    {
    public:
        RigidBody(btCollisionShape* shape, btScalar mass, const btTransform& startTransform);

        btRigidBody* operator->() { return body_; }
        const btRigidBody* operator->() const { return body_; }

        // deleted operators
        RigidBody& operator=(const RigidBody&) = delete;
        RigidBody(const RigidBody&) = delete;

    private:
        btRigidBody* body_;
        friend class PhysicsWorld;
    };
} // GLStudy

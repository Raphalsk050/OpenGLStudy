#include "RigidBody.h"

#include "BulletCollision/CollisionShapes/btCollisionShape.h"
#include "LinearMath/btDefaultMotionState.h"

namespace GLStudy
{
    RigidBody::RigidBody(btCollisionShape* shape, btScalar mass, const btTransform& startTransform)
    {
        btAssert((!shape || shape->getShapeType() != INVALID_SHAPE_PROXYTYPE));

        //rigidbody is dynamic if and only if mass is non zero, otherwise static
        bool isDynamic = (mass != 0.f);

        btVector3 localInertia(0, 0, 0);
        if (isDynamic)
            shape->calculateLocalInertia(mass, localInertia);

        //using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects

#define USE_MOTIONSTATE 1
#ifdef USE_MOTIONSTATE
        btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);

        btRigidBody::btRigidBodyConstructionInfo cInfo(mass, myMotionState, shape, localInertia);

        btRigidBody* body = new btRigidBody(cInfo);
        //body->setContactProcessingThreshold(m_defaultContactProcessingThreshold);

#else
        btRigidBody* body = new btRigidBody(mass, 0, shape, localInertia);
        body->setWorldTransform(startTransform);
#endif  //

        body->setUserIndex(-1);
    }
} // GLStudy

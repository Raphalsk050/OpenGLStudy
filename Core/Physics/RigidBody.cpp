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

        body_ = new btRigidBody(cInfo);
        //body_->setContactProcessingThreshold(m_defaultContactProcessingThreshold);

#else
        body_ = new btRigidBody(mass, 0, shape, localInertia);
        body_->setWorldTransform(startTransform);
#endif  //

        body_->setUserIndex(-1);
    }

    RigidBody::~RigidBody()
    {
        delete body_->getMotionState();
        delete body_;
    }
} // GLStudy

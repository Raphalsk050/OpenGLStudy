#include "CollisionShape.h"

namespace GLStudy {
    btCollisionShape* CollisionShape::createBoxShape(const btVector3& halfExtents)
    {
        return new btBoxShape(halfExtents);
    }

    btCollisionShape* CollisionShape::createSphereShape(const btScalar radius)
    {
        return new btSphereShape(radius);
    }

    btCollisionShape* CollisionShape::createCylinderShape(const btScalar halfHeight)
    {
        return new btCylinderShape(btVector3(halfHeight, halfHeight, halfHeight));
    }

    btCollisionShape* CollisionShape::createConeShape(const btScalar radius, const btScalar height)
    {
        return new btConeShape(radius, height);
    }

    btCollisionShape* CollisionShape::createCapsuleShape(const btScalar radius, const btScalar height)
    {
        return new btCapsuleShape(radius, height);
    }
} // GLStudy
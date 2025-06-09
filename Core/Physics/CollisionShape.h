#pragma once
#include <btBulletCollisionCommon.h>


namespace GLStudy
{
    // this class is a wrapper around btCollsionShape from bullet physics
    class CollisionShape
    {
    public:
        CollisionShape() = default;
        static btCollisionShape* createBoxShape(const btVector3& halfExtents);
        static btCollisionShape* createSphereShape(const btScalar radius);
        static btCollisionShape* createCylinderShape(const btScalar halfHeight);
        static btCollisionShape* createConeShape(const btScalar radius, const btScalar height);
        static btCollisionShape* createCapsuleShape(const btScalar radius, const btScalar height);
    };
} // GLStudy

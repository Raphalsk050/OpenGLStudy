# OpenGLStudy

This project integrates the Bullet Physics engine through CMake. Only the core
libraries (`BulletDynamics`, `BulletCollision` and `LinearMath`) are used. If
the machine has no network access you can provide a pre-downloaded Bullet source
by passing `-DBULLET_ROOT=/path/to/bullet3` when running CMake.

The renderer now supports physically based rendering (PBR) with simple point
lights. Lights are represented by a `LightComponent` with different types
(directional, point and spot) and are uploaded to the shaders every frame.



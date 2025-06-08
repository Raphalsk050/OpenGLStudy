# OpenGLStudy

This project integrates the Bullet Physics engine through CMake. Only the core
libraries (`BulletDynamics`, `BulletCollision` and `LinearMath`) are used. If
the machine has no network access you can provide a pre-downloaded Bullet source
by passing `-DBULLET_ROOT=/path/to/bullet3` when running CMake.

The repository also includes bgfx as a submodule. Pass `-DUSE_BGFX=ON` to CMake
to build the experimental bgfx renderer.

The renderer now supports physically based rendering (PBR) with directional,
point and spot lights. Lights are represented by a `LightComponent` and are
uploaded to the shaders every frame.



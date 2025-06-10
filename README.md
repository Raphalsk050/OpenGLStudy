# OpenGLStudy

This project integrates the Bullet Physics engine through CMake. Only the core
libraries (`BulletDynamics`, `BulletCollision` and `LinearMath`) are used. If
the machine has no network access you can provide a pre-downloaded Bullet source
by passing `-DBULLET_ROOT=/path/to/bullet3` when running CMake.

## Prebuilt dependencies

The repository used to contain the full sources of Bullet, Assimp and Boost.
These have been replaced by the precompiled packages available on the system.
Before configuring the project make sure the following packages are installed:

```
sudo apt install libbullet-dev libassimp-dev libboost-thread-dev libboost-system-dev
```

The `setup.sh` script now installs these packages automatically.

The renderer now supports physically based rendering (PBR) with directional,
point and spot lights. Lights are represented by a `LightComponent` and are
uploaded to the shaders every frame.



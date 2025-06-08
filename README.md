# OpenGLStudy

This project integrates the Bullet Physics engine through CMake. Only the core
libraries (`BulletDynamics`, `BulletCollision` and `LinearMath`) are used. If
the machine has no network access you can provide a pre-downloaded Bullet source
by passing `-DBULLET_ROOT=/path/to/bullet3` when running CMake.

The renderer now supports physically based rendering (PBR) with directional,
point and spot lights. Lights are represented by a `LightComponent` and are
uploaded to the shaders every frame.

## Generating IBL textures

Use `Scripts/generate_ibl.sh` to create irradiance and prefiltered cubemaps from
an HDR environment map using Filament's `cmgen` tool:

```bash
./Scripts/generate_ibl.sh Assets/Textures/Skybox/sky.hdr Assets/Textures/Skybox/ColorfulAlley
```

The generated `irradiance.ktx` and `prefilter.ktx` files can then be loaded by
the engine.



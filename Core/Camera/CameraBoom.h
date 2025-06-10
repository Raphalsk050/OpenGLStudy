#pragma once
#include "Core/TimeStep.h"
#include "Core/Scene/Scene.h"

namespace GLStudy {
    class CameraBoomSystem {
    public:
        static void OnUpdate(Scene& scene, Timestep ts);
    };
}

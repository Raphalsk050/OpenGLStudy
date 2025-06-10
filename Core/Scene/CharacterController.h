#pragma once
#include "Core/TimeStep.h"
#include "Scene.h"

namespace GLStudy {
    class CharacterControllerSystem {
    public:
        static void OnUpdate(Scene& scene, Timestep ts);
    };
}

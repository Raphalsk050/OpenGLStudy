#pragma once
#include <iostream>
#include <glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Time.h"
#include "Core/Layer/LayerStack.h"


namespace GLStudy
{
    enum class EngineInitializationStates : uint8_t
    {
        INITIALIZING = 0,
        INITIALIZED = 1,
        SHUTTINGDOWN = 2,
    };

    enum class EngineStates : uint8_t
    {
        RUNNING = 0,
        PAUSED = 1,
        STOPPED = 2
    };

    class Engine
    {
    public:
        Engine();

        void Setup();

        void Pause();

        void Resume();

        void Shutdown();

        void PushLayer(Layer* layer);

    private:
        GLFWwindow* window_;
        int width_ = 800, height_ = 600;
        LayerStack layer_stack_;
        Timestep timestep_;
        Time time_;
        float last_frame_time_ = 0.0f;

        void InitGLFW();

        void InitGLAD();

        GLFWwindow* CreateWindow(int width = 800, int height = 600, const char* title = "Sample");

        void Update(Timestep ts);

        EngineStates state_ = EngineStates::PAUSED;
        EngineInitializationStates initialization_state_ = EngineInitializationStates::INITIALIZING;

        void UpdateLayers(Timestep ts);
    };
}

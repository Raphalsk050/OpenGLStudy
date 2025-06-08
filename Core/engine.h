#pragma once
#include <iostream>
#include <memory>
#include <glm.hpp>
#ifndef USE_BGFX
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

#include "Time.h"
#include "Core/Layer/LayerStack.h"
#ifdef USE_BGFX
#include "Core/Graphics/BGFXRenderer.h"
#else
#include "Core/Graphics/Renderer.h"
#endif
#include "Scene/Scene.h"
#include "Core/Input/Input.h"
#include "Core/Events/Event.h"


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

        void OnEvent(Event& event);

        void Pause();

        void Resume();

        void Shutdown();

        void PushLayer(Layer* layer);

        using RendererType =
#ifdef USE_BGFX
            BGFXRenderer;
#else
            Renderer;
#endif

        RendererType* GetRenderer() const { return renderer_.get(); }

        Scene* GetScene() const { return scene_; }

        GLFWwindow* GetWindow() const { return window_; }

    private:
        GLFWwindow* window_;
        int width_ = 800, height_ = 600;
        LayerStack layer_stack_;
        Timestep timestep_;
        Time time_;
        float last_frame_time_ = 0.0f;
        std::unique_ptr<RendererType> renderer_;

        // currently, the engine will have only one scene
        // TODO(rafael): in the future, the idea is to hold multiple scenes and the user can decide
        // to switch to a new scene or to add multiple scene layers, like unity does.
        Scene* scene_;

        void InitGLFW();

        void InitGLAD();

        GLFWwindow* CreateWindow(int width = 800, int height = 600, const char* title = "Sample");

        void Update(Timestep ts);

        EngineStates state_ = EngineStates::PAUSED;
        EngineInitializationStates initialization_state_ = EngineInitializationStates::INITIALIZING;

        void UpdateLayers(Timestep ts);
        void InitCallbacks();
    };
}

#pragma once
#include <iostream>
#include <memory>
#include <glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <atomic>
#include <mutex>

#include "Time.h"
#include "Core/Layer/LayerStack.h"
#include "Core/Graphics/Renderer.h"
#include "Scene/Scene.h"
#include "Core/Input/Input.h"
#include "Core/Events/Event.h"
#include "Physics/PhysicsWorld.h"


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
        static Engine& Get()
        {
            static Engine instance;
            return instance;
        }


        void Setup();

        void OnEvent(Event& event);

        void Pause();

        void Resume();

        void Shutdown();

        void PushLayer(Layer* layer);

        Renderer* GetRenderer() const { return renderer_.get(); }

        Scene* GetScene() const { return scene_; }

        /** Current interpolation factor used for render smoothing */
        float GetInterpolationFactor() const { return interpolation_factor_.load(); }

        GLFWwindow* GetWindow() const { return window_.get(); }

        PhysicsWorld* GetPhysicsWorld() const { return physic_world_.get(); }

        std::mutex& GetSceneMutex() { return scene_mutex_; }

    private:
        Engine(const Engine&)            = delete;
        Engine& operator=(const Engine&) = delete;
        Engine(Engine&&)                 = delete;
        Engine& operator=(Engine&&)      = delete;

        struct GLFWDeleter
        {
            void operator()(GLFWwindow* w) const { if (w) glfwDestroyWindow(w); }
        };
        std::unique_ptr<GLFWwindow, GLFWDeleter> window_;
        int width_ = 800, height_ = 600;
        LayerStack layer_stack_;
        Timestep timestep_;
        Time time_;
        float last_frame_time_ = 0.0f;
        std::unique_ptr<Renderer> renderer_;
        std::unique_ptr<PhysicsWorld> physic_world_;

        std::thread render_thread_;
        std::atomic<bool> render_running_{false};

        double physics_accumulator_{0.0};
        double physics_fixed_dt_{1.0 / 60.0};
        std::atomic<float> interpolation_factor_{0.0f};

        std::mutex scene_mutex_;

        // currently, the engine will have only one scene
        // TODO(rafael): in the future, the idea is to hold multiple scenes and the user can decide
        // to switch to a new scene or to add multiple scene layers, like unity does.
        Scene* scene_;

    private:
        Engine();
        ~Engine();

        void InitGLFW();

        bool InitGLAD();

        GLFWwindow* CreateWindow(int width = 800, int height = 600, const char* title = "Sample");

        void Update(Timestep ts);

        EngineStates state_ = EngineStates::PAUSED;
        EngineInitializationStates initialization_state_ = EngineInitializationStates::INITIALIZING;

        void UpdateLayers(Timestep ts);
        void InitCallbacks();
    };
}

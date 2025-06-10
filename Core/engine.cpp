#include "engine.h"
#include "Core/Events/WindowApplicationEvent.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Events/MouseEvent.h"

namespace GLStudy
{
    static void SizeCallback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    Engine::Engine()
    {
        renderer_ = std::make_unique<Renderer>();
        scene_ = new Scene();
    }

    Engine::~Engine()
    {
        render_running_ = false;
        physics_running_ = false;
        if (render_thread_.joinable())
            render_thread_.join();
        if (physics_thread_.joinable())
            physics_thread_.join();
        delete scene_;
    }

    void Engine::Setup()
    {
        InitGLFW();
        CreateWindow(width_, height_, "OpenGL Study");
        if (!window_)
        {
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window_.get());
        if (!InitGLAD())
        {
            glfwDestroyWindow(window_.get());
            glfwTerminate();
            return;
        }

        const GLubyte* renderer = glGetString(GL_RENDERER);
        const GLubyte* vendor   = glGetString(GL_VENDOR);
        const GLubyte* version  = glGetString(GL_VERSION);

        std::cout << "Vendor:   " << vendor   << std::endl;
        std::cout << "Renderer: " << renderer << std::endl;
        std::cout << "Version:  " << version  << std::endl;

        Input::Init(window_.get());
        InitCallbacks();

        renderer_->Init();
        scene_->OnViewportResize(width_, height_);

        // Physics world must exist before layers attach so asynchronous
        // component creation can safely reference it
        physic_world_ = std::make_unique<PhysicsWorld>();
        physics_running_ = true;
        physics_thread_ = std::thread([this]() {
            float last = Time::GetTime();
            while (physics_running_)
            {
                float now = Time::GetTime();
                float dt = now - last;
                last = now;
                physic_world_->Update(dt);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });

        initialization_state_ = EngineInitializationStates::INITIALIZED;

        // Attach layers that were pushed before setup
        for (Layer* layer : layer_stack_)
        {
            layer->OnAttach();
        }

        // Release the context from the main thread and start the render thread
        glfwMakeContextCurrent(nullptr);

        render_running_ = true;
        render_thread_ = std::thread([this]() {
            glfwMakeContextCurrent(window_.get());

            while (render_running_ && !glfwWindowShouldClose(window_.get()))
            {
                {
                    std::scoped_lock lock(scene_mutex_);
                    scene_->Render(GetRenderer());
                }
                glfwSwapBuffers(window_.get());
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });

        // TODO(rafael): Just to debug the engine for now. Take this off in the future
        Resume();

        while (render_running_ && !glfwWindowShouldClose(window_.get()))
        {
            float time = Time::GetTime();
            timestep_ = time - last_frame_time_;
            last_frame_time_ = time;

            glfwPollEvents();
            Update(timestep_);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        render_running_ = false;
        physics_running_ = false;
        if (render_thread_.joinable())
            render_thread_.join();
        if (physics_thread_.joinable())
            physics_thread_.join();

        window_.reset();
        glfwTerminate();
    }

    void Engine::Pause()
    {
        if (state_ == EngineStates::RUNNING)
            state_ = EngineStates::PAUSED;
    }

    void Engine::Resume()
    {
        if (state_ != EngineStates::RUNNING)
            state_ = EngineStates::RUNNING;
    }

    void Engine::Shutdown()
    {
    }

    void Engine::PushLayer(Layer* layer)
    {
        layer_stack_.PushLayer(layer);
        // If the engine is already initialized, immediately attach the layer
        if (initialization_state_ == EngineInitializationStates::INITIALIZED)
        {
            layer->OnAttach();

        }
    }

    void Engine::InitGLFW()
    {
        if (!glfwInit())
        {
            std::cout << "Failed to initialize GLFW" << std::endl;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    bool Engine::InitGLAD()
    {
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return false;
        }

        glViewport(0, 0, width_, height_);
        return true;
    }

    GLFWwindow* Engine::CreateWindow(int width, int height, const char* title)
    {
        GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!window)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            return nullptr;
        }
        window_.reset(window);

        return window_.get();
    }

    void Engine::Update(Timestep ts)
    {
        if (state_ != EngineStates::RUNNING)
            return;

        {
            std::scoped_lock lock(scene_mutex_);
            scene_->OnUpdate(ts);
            UpdateLayers(ts);
        }
    }

    void Engine::UpdateLayers(Timestep ts)
    {
        for (Layer* layer : layer_stack_)
        {
            layer->OnUpdate(ts);
        }
    }

    void Engine::OnEvent(Event& event)
    {
        std::scoped_lock lock(scene_mutex_);
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& e) {
            width_ = e.GetWidth();
            height_ = e.GetHeight();
            glViewport(0, 0, width_, height_);
            scene_->OnViewportResize(width_, height_);
            return false;
        });

        scene_->OnEvent(event);

        for (auto it = layer_stack_.rbegin(); it != layer_stack_.rend(); ++it)
        {
            (*it)->OnEvent(event);
            if (event.Handled)
                break;
        }
    }

    void Engine::InitCallbacks()
    {
        glfwSetWindowUserPointer(window_.get(), this);

        glfwSetFramebufferSizeCallback(window_.get(), [](GLFWwindow* win, int w, int h) {
            Engine* eng = static_cast<Engine*>(glfwGetWindowUserPointer(win));
            WindowResizeEvent ev(w, h);
            eng->OnEvent(ev);
        });

        glfwSetKeyCallback(window_.get(), [](GLFWwindow* win, int key, int scancode, int action, int mods) {
            Engine* eng = static_cast<Engine*>(glfwGetWindowUserPointer(win));
            switch (action) {
            case GLFW_PRESS:
            {
                KeyPressedEvent e(key, false);
                eng->OnEvent(e);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent e(key);
                eng->OnEvent(e);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent e(key, true);
                eng->OnEvent(e);
                break;
            }
            }
        });

        glfwSetMouseButtonCallback(window_.get(), [](GLFWwindow* win, int button, int action, int mods) {
            Engine* eng = static_cast<Engine*>(glfwGetWindowUserPointer(win));
            if (action == GLFW_PRESS) {
                MouseButtonPressedEvent e(button);
                eng->OnEvent(e);
            } else if (action == GLFW_RELEASE) {
                MouseButtonReleasedEvent e(button);
                eng->OnEvent(e);
            }
        });

        glfwSetCursorPosCallback(window_.get(), [](GLFWwindow* win, double xpos, double ypos) {
            Engine* eng = static_cast<Engine*>(glfwGetWindowUserPointer(win));
            MouseMovedEvent e(static_cast<float>(xpos), static_cast<float>(ypos));
            eng->OnEvent(e);
        });

        glfwSetScrollCallback(window_.get(), [](GLFWwindow* win, double xoff, double yoff) {
            Engine* eng = static_cast<Engine*>(glfwGetWindowUserPointer(win));
            MouseScrolledEvent e(static_cast<float>(xoff), static_cast<float>(yoff));
            eng->OnEvent(e);
        });
    }
}

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

    Engine::Engine(): window_(nullptr)
    {
        renderer_ = std::make_unique<Renderer>();
        scene_ = new Scene();
    }

    void Engine::Setup()
    {
        InitGLFW();
        CreateWindow(width_, height_, "OpenGL Study");
        Input::Init(window_);
        InitGLAD();
        renderer_->Init();

        InitCallbacks();

        initialization_state_ = EngineInitializationStates::INITIALIZED;

        // Attach layers that were pushed before setup
        for (Layer* layer : layer_stack_)
        {
            layer->OnAttach();
        }

        // TODO(rafael): Just to debug the engine for now. Take this off in the future
        Resume();

        while (!glfwWindowShouldClose(window_))
        {
            float time = Time::GetTime();
            timestep_ = time - last_frame_time_;
            last_frame_time_ = time;

            Update(timestep_);
            scene_->Render(GetRenderer());
        }
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
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void Engine::InitGLAD()
    {
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }

        glViewport(0, 0, width_, height_);
    }

    GLFWwindow* Engine::CreateWindow(int width, int height, const char* title)
    {
        GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!window)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
        }
        glfwMakeContextCurrent(window);
        window_ = window;
        return window;
    }

    void Engine::Update(Timestep ts)
    {
        glfwPollEvents();
        glfwSwapBuffers(window_);

        if (state_ != EngineStates::RUNNING)
            return;

        UpdateLayers(ts);
    }

    void Engine::UpdateLayers(Timestep ts)
    {
        for (Layer* layer : layer_stack_)
        {
            layer->OnUpdate(ts);
            std::cout << ts << std::endl;
        }
    }

    void Engine::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& e) {
            width_ = e.GetWidth();
            height_ = e.GetHeight();
            glViewport(0, 0, width_, height_);
            return false;
        });

        for (auto it = layer_stack_.rbegin(); it != layer_stack_.rend(); ++it)
        {
            (*it)->OnEvent(event);
            if (event.Handled)
                break;
        }
    }

    void Engine::InitCallbacks()
    {
        glfwSetWindowUserPointer(window_, this);

        glfwSetFramebufferSizeCallback(window_, [](GLFWwindow* win, int w, int h) {
            Engine* eng = static_cast<Engine*>(glfwGetWindowUserPointer(win));
            WindowResizeEvent ev(w, h);
            eng->OnEvent(ev);
        });

        glfwSetKeyCallback(window_, [](GLFWwindow* win, int key, int scancode, int action, int mods) {
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

        glfwSetMouseButtonCallback(window_, [](GLFWwindow* win, int button, int action, int mods) {
            Engine* eng = static_cast<Engine*>(glfwGetWindowUserPointer(win));
            if (action == GLFW_PRESS) {
                MouseButtonPressedEvent e(button);
                eng->OnEvent(e);
            } else if (action == GLFW_RELEASE) {
                MouseButtonReleasedEvent e(button);
                eng->OnEvent(e);
            }
        });

        glfwSetCursorPosCallback(window_, [](GLFWwindow* win, double xpos, double ypos) {
            Engine* eng = static_cast<Engine*>(glfwGetWindowUserPointer(win));
            MouseMovedEvent e(static_cast<float>(xpos), static_cast<float>(ypos));
            eng->OnEvent(e);
        });

        glfwSetScrollCallback(window_, [](GLFWwindow* win, double xoff, double yoff) {
            Engine* eng = static_cast<Engine*>(glfwGetWindowUserPointer(win));
            MouseScrolledEvent e(static_cast<float>(xoff), static_cast<float>(yoff));
            eng->OnEvent(e);
        });
    }
}

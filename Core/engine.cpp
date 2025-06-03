#include "engine.h"

namespace GLStudy {
  void SizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
  }

  Engine::Engine(): window_(nullptr) {
  }

  void Engine::Setup() {
    InitGLFW();
    CreateWindow(width_, height_, "OpenGL Study");
    InitGLAD();

    // updates the current screen size based on the callback
    glfwSetFramebufferSizeCallback(window_, SizeCallback);

    // Attach layers that were pushed before setup
    for (Layer *layer : layer_stack_) {
      layer->OnAttach();
    }

    while (!glfwWindowShouldClose(window_)) {
      Update();
    }
  }

  void Engine::Pause() {
    if (state_ == EngineStates::RUNNING)
      state_ = EngineStates::PAUSED;
  }

  void Engine::Resume() {
    if (state_ != EngineStates::RUNNING)
      state_ = EngineStates::RUNNING;
  }

  void Engine::Shutdown() {
  }

  void Engine::PushLayer(Layer *layer)
  {
    layer_stack_.PushLayer(layer);
    // If the engine is already initialized, immediately attach the layer
    if (window_ != nullptr) {
      layer->OnAttach();
    }
  }

  void Engine::InitGLFW() {
    if (!glfwInit()) {
      std::cout << "Failed to initialize GLFW" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }

  void Engine::InitGLAD() {
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
      std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glViewport(0, 0, width_, height_);
  }

  GLFWwindow *Engine::CreateWindow(int width, int height, const char *title) {
    GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
      std::cout << "Failed to create GLFW window" << std::endl;
    }
    glfwMakeContextCurrent(window);
    window_ = window;
    return window;
  }

  void Engine::Update() {
    glfwPollEvents();
    glfwSwapBuffers(window_);

    if (state_ != EngineStates::RUNNING)
      return;

  }
}

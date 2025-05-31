#pragma once
#include <iostream>
#include <glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace GLStudy {
  enum class EngineStates : uint8_t {
    RUNNING = 0,
    PAUSED = 1,
    STOPPED = 2
  };

  class Engine {
  public:

    Engine();

    void Setup();

    void Pause();

    void Resume();

    void Shutdown();

  private:
    GLFWwindow *window_;
    int width_ = 800, height_ = 600;

    void InitGLFW();

    void InitGLAD();

    GLFWwindow *CreateWindow(int width = 800, int height = 600, const char *title = "Sample");

    void Update();

    EngineStates state_ = EngineStates::PAUSED;
  };
}

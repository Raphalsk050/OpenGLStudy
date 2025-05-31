cmake_minimum_required(VERSION 3.31)
project(openglStudy)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(ThirdParty/glfw)
add_subdirectory(ThirdParty/glad)
add_subdirectory(ThirdParty/glm)

add_executable(openglStudy
        main.cpp
        Core/engine.cpp
        Core/engine.h
)

target_include_directories(openglStudy PUBLIC
        ThirdParty/glfw/include
        ThirdParty/glad/include
        ThirdParty/glm
)

target_link_libraries(openglStudy PUBLIC
        glm
        glad
        glfw
)

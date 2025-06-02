cmake_minimum_required(VERSION 3.31)
project(openglStudy)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(ThirdParty/glfw)
add_subdirectory(ThirdParty/glad)
add_subdirectory(ThirdParty/glm)

add_executable(openglStudy
        Program/main.cpp
        Program/Layers/ProgramLayer.h
        Program/Layers/ProgramLayer.cpp
        Core/engine.cpp
        Core/engine.h
        Core/TimeStep.h
        Core/Time.h
        Core/Layer/Layer.h
        Core/Layer/Layer.cpp
        Core/Layer/LayerStack.h
        Core/Layer/LayerStack.cpp
        Core/Shader/Shader.h
        Core/Shader/Shader.cpp
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

add_custom_command(
        TARGET openglStudy POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets
        $<TARGET_FILE_DIR:openglStudy>/Assets
)

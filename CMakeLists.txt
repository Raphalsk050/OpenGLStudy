cmake_minimum_required(VERSION 3.31)
project(openglStudy)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(ThirdParty/glfw)
add_subdirectory(ThirdParty/glad)
add_subdirectory(ThirdParty/glm)
add_subdirectory(ThirdParty/entt)

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
        Core/Scene/Components.h
        Core/Scene/EntityHandle.h
        Core/Scene/EntityHandle.cpp
        Core/Scene/Scene.h
        Core/Scene/Scene.cpp
        Core/Graphics/VertexBuffer.h
        Core/Graphics/VertexBuffer.cpp
        Core/Graphics/VertexArray.h
        Core/Graphics/VertexArray.cpp
        Core/Graphics/IndexBuffer.h
        Core/Graphics/IndexBuffer.cpp
        Core/Graphics/Renderer.h
        Core/Graphics/Renderer.cpp
        Core/Camera/Camera.h
        Core/Camera/SceneCamera.h
        Core/Camera/SceneCamera.cpp
        Core/Camera/EditorCamera.h
        Core/Camera/EditorCamera.cpp
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
        Entt
)

add_custom_command(
        TARGET openglStudy POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets
        $<TARGET_FILE_DIR:openglStudy>/Assets
)

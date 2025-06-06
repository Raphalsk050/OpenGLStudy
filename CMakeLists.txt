cmake_minimum_required(VERSION 3.11)
project(openglStudy)

set(CMAKE_CXX_STANDARD 20)

set(USE_BULLET OFF)



add_subdirectory(ThirdParty/glfw)
add_subdirectory(ThirdParty/glad)
add_subdirectory(ThirdParty/glm)
add_subdirectory(ThirdParty/entt)

if(USE_BULLET)
    # bullet properties
    set(BUILD_BULLET2_DEMOS OFF CACHE BOOL "" FORCE)
    set(BUILD_CPU_DEMOS OFF CACHE BOOL "" FORCE)
    set(BUILD_OPENGL3_DEMOS OFF CACHE BOOL "" FORCE)
    set(BUILD_EXTRAS OFF CACHE BOOL "" FORCE)
    set(INSTALL_LIBS OFF CACHE BOOL "" FORCE)
    add_subdirectory(ThirdParty/bullet)
endif ()

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
        Core/Camera/CameraController.h
        Core/Camera/CameraController.cpp
        Core/Camera/EditorCamera.h
        Core/Camera/EditorCamera.cpp
        Core/Config.h
        Core/Input/Input.h
        Core/Input/Input.cpp
        Core/Input/KeyCodes.h
        Core/Input/MouseCodes.h
        Core/Events/Event.h
        Core/Events/Event.cpp
        Core/Events/KeyEvent.h
        Core/Events/MouseEvent.h
        Core/Events/WindowApplicationEvent.h
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

if(USE_BULLET)
    target_link_libraries(openglStudy PUBLIC
            BulletDynamics
            BulletCollision
            LinearMath
    )
endif ()

set(CMAKE_CXX_FLAGS_PROFILE "${CMAKE_CXX_FLAGS_DEBUG} -pg")
set(CMAKE_EXE_LINKER_FLAGS_PROFILE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -pg")

# this is to copy the windows dlls to make the program work
if (WIN32 AND MINGW)
    get_filename_component(MINGW_BIN_DIR "${CMAKE_CXX_COMPILER}" PATH)

    set(RUNTIME_DLLS
            libwinpthread-1.dll
            libstdc++-6.dll
            libgcc_s_seh-1.dll
    )

    foreach(_dll ${RUNTIME_DLLS})
        if (EXISTS "${MINGW_BIN_DIR}/${_dll}")
            add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${MINGW_BIN_DIR}/${_dll}"
                    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${_dll}"
                    COMMENT "Copiando ${_dll} para a pasta do executável"
            )
        else()
            message(WARNING "Não encontrou ${_dll} em ${MINGW_BIN_DIR}; verifique o caminho ou copie-a manualmente")
        endif()
    endforeach()
endif()

add_custom_command(
        TARGET openglStudy POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets
        $<TARGET_FILE_DIR:openglStudy>/Assets
)

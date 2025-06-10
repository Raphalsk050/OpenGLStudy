cmake_minimum_required(VERSION 3.11)
project(openglStudy)

set(CMAKE_CXX_STANDARD 20)
set(USE_BULLET ON)

if(WIN32)
    # — Windows: use vcpkg toolchain if available
    if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        if(DEFINED ENV{VCPKG_ROOT})
            set(CMAKE_TOOLCHAIN_FILE
                    "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
                    CACHE STRING "Vcpkg toolchain" FORCE)
            message(STATUS "Using vcpkg toolchain: ${CMAKE_TOOLCHAIN_FILE}")
        else()
            message(STATUS "VCPKG_ROOT not set, falling back to system install.")
        endif()
    endif()

    # Find Windows (vcpkg‐provided) packages
    find_package(OpenGL REQUIRED)
    find_package(assimp CONFIG REQUIRED)
    find_package(Boost REQUIRED COMPONENTS thread system)
    find_package(ZLIB REQUIRED)
    if(USE_BULLET)
        find_package(Bullet CONFIG REQUIRED)
    endif()

    # Third-party submodules
    add_subdirectory(ThirdParty/glfw)
    add_subdirectory(ThirdParty/glad)
    add_subdirectory(ThirdParty/glm)
    add_subdirectory(ThirdParty/entt)

    # Gather sources
    file(GLOB_RECURSE SRC_FILES
            Program/*.cpp Program/*.h
            Core/*.cpp Core/*.h
    )

    add_executable(openglStudy ${SRC_FILES})

    target_include_directories(openglStudy PUBLIC
            ThirdParty/glfw/include
            ThirdParty/glad/include
            ThirdParty/glm
            ThirdParty/stb
            ThirdParty/tinyexr
            ThirdParty/tinyexr/deps/miniz
            ${CMAKE_SOURCE_DIR}/ThirdParty/boost_patch
    )

    target_link_libraries(openglStudy PUBLIC
            glfw
            glad
            glm
            Entt
            OpenGL::GL
            assimp::assimp
            Boost::thread
            Boost::system
            ZLIB::ZLIB
    )

    if(USE_BULLET)
        target_include_directories(openglStudy PUBLIC ${BULLET_INCLUDE_DIRS})
        target_link_libraries(openglStudy PUBLIC ${BULLET_LIBRARIES})
    endif()

else()
    add_subdirectory(ThirdParty/glfw)
    add_subdirectory(ThirdParty/glad)
    add_subdirectory(ThirdParty/glm)
    add_subdirectory(ThirdParty/entt)

    # Use prebuilt versions of Assimp, Boost and Bullet from the system
    find_package(assimp REQUIRED)
    find_package(ZLIB REQUIRED)

    if(USE_BULLET)
        find_package(Bullet REQUIRED)
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
            Core/Graphics/Texture.h
            Core/Graphics/Texture.cpp
            Core/Graphics/Mesh.h
            Core/Graphics/Mesh.cpp
            Core/Graphics/Primitives.h
            Core/Graphics/Primitives.cpp
            Core/Graphics/Model.h
            Core/Graphics/Model.cpp
            Core/Graphics/CubemapTexture.h
            Core/Graphics/CubemapTexture.cpp
            Core/Graphics/Skybox.h
            Core/Graphics/Skybox.cpp
            Core/Camera/Camera.h
            Core/Camera/SceneCamera.h
            Core/Camera/SceneCamera.cpp
            Core/Camera/CameraController.h
            Core/Camera/CameraController.cpp
            Core/Camera/EditorCamera.h
            Core/Camera/EditorCamera.cpp
            Core/Camera/CameraBoom.h
            Core/Camera/CameraBoom.cpp
            Core/Scene/CharacterController.h
            Core/Scene/CharacterController.cpp
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
            Core/Physics/PhysicsWorld.cpp
            Core/Physics/PhysicsWorld.h
            Core/Physics/CollisionShape.cpp
            Core/Physics/CollisionShape.h
            Core/Physics/RigidBody.cpp
            Core/Physics/RigidBody.h
            Core/Utils.h
    )

    target_include_directories(openglStudy PUBLIC
            ThirdParty/glfw/include
            ThirdParty/glad/include
            ThirdParty/glm
            ThirdParty/stb
            ThirdParty/tinyexr
            ThirdParty/tinyexr/deps/miniz
    )

    target_link_libraries(openglStudy PUBLIC
            glm
            glad
            glfw
            Entt
            assimp
            ZLIB::ZLIB
    )

    # Enable tinyexr
    target_compile_definitions(openglStudy PRIVATE
            TINYEXR_USE_MINIZ=0)

    if(USE_BULLET)
        target_link_libraries(openglStudy PUBLIC ${BULLET_LIBRARIES})

        target_include_directories(openglStudy PUBLIC ${BULLET_INCLUDE_DIRS})
    endif ()

    set(CMAKE_CXX_FLAGS_PROFILE "${CMAKE_CXX_FLAGS_DEBUG} -pg")
    set(CMAKE_EXE_LINKER_FLAGS_PROFILE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -pg")
endif()

# Common compile definitions and post-build copy
target_compile_definitions(openglStudy PRIVATE
        BOOST_THREAD_PROVIDES_FUTURE
        BOOST_THREAD_VERSION=5
        TINYEXR_USE_MINIZ=0
)

add_custom_command(
        TARGET openglStudy POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets
        $<TARGET_FILE_DIR:openglStudy>/Assets
)

cmake_minimum_required(VERSION 3.19)
project(FilamentMinimal)

# Root directory of Filament sources
set(FILAMENT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# Only include the core engine and essential libraries to keep the footprint minimal
# The build output folders are separated to avoid conflicts
add_subdirectory(${FILAMENT_ROOT}/filament          ${CMAKE_BINARY_DIR}/filament-core)
add_subdirectory(${FILAMENT_ROOT}/libs/filabridge    ${CMAKE_BINARY_DIR}/filabridge)
add_subdirectory(${FILAMENT_ROOT}/libs/geometry      ${CMAKE_BINARY_DIR}/geometry)
add_subdirectory(${FILAMENT_ROOT}/libs/image         ${CMAKE_BINARY_DIR}/image)
add_subdirectory(${FILAMENT_ROOT}/libs/math          ${CMAKE_BINARY_DIR}/math)
add_subdirectory(${FILAMENT_ROOT}/libs/utils         ${CMAKE_BINARY_DIR}/utils)
# Optional: enable glTF model loading
add_subdirectory(${FILAMENT_ROOT}/libs/gltfio      ${CMAKE_BINARY_DIR}/gltfio)

# Expose imported targets for use by the parent project
# filament::filament, filament::filabridge, geometry::geometry, image::image, math::math, utils::utils

message(STATUS "Configured minimal Filament build: core + filabridge + geometry + image + math + utils")

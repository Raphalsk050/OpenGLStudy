add_library(assimp STATIC src/Importer.cpp)
target_include_directories(assimp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

cmake_minimum_required(VERSION 3.11)

# Use the Boost sources already present in this directory. The Boost project
# provides its own CMake build scripts, so simply include them here.
set(BOOST_ENABLE_CMAKE ON)
set(BOOST_INCLUDE_LIBRARIES thread system)

# Build Boost from the local sources instead of downloading from the system
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/boost)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/boost ${CMAKE_CURRENT_BINARY_DIR}/boost-build)
else()
    message(FATAL_ERROR "Boost sources not found in ${CMAKE_CURRENT_SOURCE_DIR}/boost")
endif()

# Alias libraries to match expected target names
if(TARGET boost_thread)
    add_library(Boost::thread ALIAS boost_thread)
endif()
if(TARGET boost_system)
    add_library(Boost::system ALIAS boost_system)
endif()

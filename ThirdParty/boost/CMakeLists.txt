cmake_minimum_required(VERSION 3.11)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_LIST_DIR})
set(BOOST_ENABLE_CMAKE ON)
set(BOOST_INCLUDE_LIBRARIES thread system)

FetchContent_Declare(
    boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG boost-1.84.0
)

FetchContent_MakeAvailable(boost)

if(TARGET boost_thread)
    add_library(Boost::thread ALIAS boost_thread)
endif()
if(TARGET boost_system)
    add_library(Boost::system ALIAS boost_system)
endif()

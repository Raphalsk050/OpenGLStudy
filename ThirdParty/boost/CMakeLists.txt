cmake_minimum_required(VERSION 3.11)

include(FetchContent)

set(BOOST_ENABLE_CMAKE ON)
set(BOOST_INCLUDE_LIBRARIES thread system)

FetchContent_Declare(
    boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.83.0/boost-1.83.0.tar.gz
)
FetchContent_MakeAvailable(boost)

# alias targets for convenience
if(TARGET boost_thread)
    add_library(Boost::thread ALIAS boost_thread)
endif()
if(TARGET boost_system)
    add_library(Boost::system ALIAS boost_system)
endif()

cmake_minimum_required(VERSION 3.23)
project(physics_sim)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(physics_sim
        object_state.cpp
        object_state.hpp)

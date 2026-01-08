cmake_minimum_required(VERSION 4.0)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled3 main.cpp
        Vivant.cpp
        Vivant.hpp
        Animal.cpp
        Animal.hpp
        cmake-build-debug/Chevre.cpp
        cmake-build-debug/Chevre.hpp)

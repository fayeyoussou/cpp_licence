cmake_minimum_required(VERSION 4.0)
project(surcharge)

set(CMAKE_CXX_STANDARD 20)

add_executable(surcharge main.cpp
        Etudiant.cpp
        Etudiant.hpp
        Classe.cpp
        Classe.hpp)

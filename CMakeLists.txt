    cmake_minimum_required(VERSION 3.21)
    project(untitled8 )

    set(CMAKE_CXX_STANDARD 14 sources/Fraction.hpp doctest.h)

    add_executable(untitled8 main.cpp sources/Fraction.cpp)

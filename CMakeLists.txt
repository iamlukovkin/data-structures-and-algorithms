cmake_minimum_required(VERSION 4.0)
project(data_structures_and_algorithms)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(data_structures_and_algorithms
        main.cpp
        Tree.h
)

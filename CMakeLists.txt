cmake_minimum_required(VERSION 4.0)
project(data_structures_and_algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(data_structures_and_algorithms main.cpp
        src/AbstractGraph.cpp
        src/AdjacencyListGraph.cpp
        src/AdjacencyVectorGraph.cpp
        src/GraphIterator.cpp
        src/ListIterator.cpp
        src/ListRange.cpp
        src/VectorIterator.cpp
        src/VectorRange.cpp
)

target_include_directories(data_structures_and_algorithms PRIVATE include/)

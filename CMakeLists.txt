cmake_minimum_required(VERSION 3.10)
project(data_structures_and_algorithms C)

set(CMAKE_C_STANDART 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(data_structures_and_algorithms 
  src/main.c
  src/graph/graph.c
)

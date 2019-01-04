cmake_minimum_required(VERSION 3.10)
project(graph_bridges)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Relase)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(graph src/main.cpp src/Graph.cpp include/Graph.h src/Algorithm.cpp include/Algorithm.h)
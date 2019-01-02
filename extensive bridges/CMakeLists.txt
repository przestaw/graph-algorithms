cmake_minimum_required(VERSION 3.5)
project(graph_extensive_bridges)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE relase)

add_executable(graph src/main.cpp src/Graph.cpp include/Graph.h src/Algorithm.cpp include/Algorithm.h)

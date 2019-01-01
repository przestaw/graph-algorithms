cmake_minimum_required(VERSION 3.10)
project(graph_bridges)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph src/main.cpp src/Graph.cpp include/Graph.h src/Algorithm.cpp include/Algorithm.h)
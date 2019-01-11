cmake_minimum_required(VERSION 3.5)
project(graph_extensive_bridges)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Relase)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}" -O3 -Wall -pedantic -Wunused-functions)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(graph src/main.cpp src/Graph.cpp include/Graph.h)

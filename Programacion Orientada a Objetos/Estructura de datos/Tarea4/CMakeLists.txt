cmake_minimum_required(VERSION 3.5)
project(Tarea4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Matrices.h Matrices.cpp)
add_executable(Tarea4 ${SOURCE_FILES})
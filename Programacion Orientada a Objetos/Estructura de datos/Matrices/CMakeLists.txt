cmake_minimum_required(VERSION 3.3)
project(Matrices)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Main.cpp
    Matrices.cpp
    Matrices.h)

add_executable(Matrices ${SOURCE_FILES})
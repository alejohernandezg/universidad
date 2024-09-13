cmake_minimum_required(VERSION 3.3)
project(EJEMPLOS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ciclo.cpp
    EstructurasControl.cpp)

add_executable(EJEMPLOS ${SOURCE_FILES})
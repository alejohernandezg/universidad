cmake_minimum_required(VERSION 3.3)
project(MultiplicacionPolinomios)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Taller3.cpp Taller3.h)
add_executable(MultiplicacionPolinomios ${SOURCE_FILES})
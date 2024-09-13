cmake_minimum_required(VERSION 3.3)
project(Pilas)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Stack.cpp Stack.h ListaSencilla.cpp ListaSencilla.h)
add_executable(Pilas ${SOURCE_FILES})
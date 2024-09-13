cmake_minimum_required(VERSION 3.3)
project(Taller2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Taller2.cpp Taller2.h)
add_executable(Taller2 ${SOURCE_FILES})
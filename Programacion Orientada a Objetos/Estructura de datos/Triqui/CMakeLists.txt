cmake_minimum_required(VERSION 3.5)
project(Triqui)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Main.c TableroArreglo.c TableroArreglo.h)
add_executable(Triqui ${SOURCE_FILES})
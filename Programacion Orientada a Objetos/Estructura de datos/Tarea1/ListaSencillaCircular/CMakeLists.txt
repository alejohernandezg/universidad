cmake_minimum_required(VERSION 3.5)
project(Nueva_carpeta)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ListaSencillaCircular.cpp ListaSencillaCircular.h)
add_executable(Nueva_carpeta ${SOURCE_FILES})
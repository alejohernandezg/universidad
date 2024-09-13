cmake_minimum_required(VERSION 3.3)
project(ListaDoble)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ListaDobe.cpp ListaDobe.h)
add_executable(ListaDoble ${SOURCE_FILES})
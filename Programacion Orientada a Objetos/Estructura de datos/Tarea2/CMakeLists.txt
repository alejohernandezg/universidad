cmake_minimum_required(VERSION 3.5)
project(Tarea2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp  tarea2.cpp tarea2.h  ListaDoble.h structs.cpp structs.h)
add_executable(Tarea2 ${SOURCE_FILES})
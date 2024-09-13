cmake_minimum_required(VERSION 3.3)
project(Archivos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Main.cpp Archivos.h Archivos.cpp)
add_executable(Archivos ${SOURCE_FILES} Archivos.h Archivos.cpp)
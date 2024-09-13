cmake_minimum_required(VERSION 3.3)
project(ArchivosBinarios)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ArchivosBinarios.cpp ArchivosBinarios.h)
add_executable(ArchivosBinarios ${SOURCE_FILES} )
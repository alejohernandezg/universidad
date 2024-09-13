cmake_minimum_required(VERSION 3.3)
project(ListaSencilla)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ListaSencilla.cpp
    ListaSencilla.h
    Main.cpp)

add_executable(ListaSencilla ${SOURCE_FILES})
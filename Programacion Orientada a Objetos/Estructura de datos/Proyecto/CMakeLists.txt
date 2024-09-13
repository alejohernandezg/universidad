cmake_minimum_required(VERSION 3.5)
project(Proyecto)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp taller4.h taller4.cpp cola.h cola.cpp pilas.h pilas.cpp listasDobles2.h listasDobles2.cpp)
add_executable(Proyecto ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.4)
project(TallerGrafos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vertice.h Arista.h Grafo.h GrafoUtils.h)
add_executable(TallerGrafos ${SOURCE_FILES})
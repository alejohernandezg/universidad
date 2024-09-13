cmake_minimum_required(VERSION 3.5)
project(calculadora2_0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Calculadora.cpp Calculadora.h NoDivisible.cpp NoDivisible.h mainCalculadora.cpp mainCalculadora.h)
add_executable(calculadora2_0 ${SOURCE_FILES})
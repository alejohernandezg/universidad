cmake_minimum_required(VERSION 3.3)
project(ArbolesNArios_Estudiantes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ArbolNArio.cpp
    ArbolNArio.h
    ListaDoble.cpp
    ListaDoble.h
    main.cpp)

add_executable(ArbolesNArios_Estudiantes ${SOURCE_FILES})
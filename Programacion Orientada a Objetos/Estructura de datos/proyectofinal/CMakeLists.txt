cmake_minimum_required(VERSION 3.5)
project(proyectofinal)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    cola.cpp
    cola.h
    listasDobles2.cpp
    listasDobles2.h
    main.cpp
    pilas.cpp
    pilas.h
    taller4.cpp
    taller4.h)

add_executable(proyectofinal ${SOURCE_FILES})
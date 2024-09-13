all: programa
programa:OperacionesFish Main
		g++ -o Structs OperacionesFish.o Main.o

OperacionesFish:OperacionesFish.cpp Structs.h
		g++ -c OperacionesFish.cpp

Main:Main.cpp Structs.h
		g++ -c Main.cpp


all: programa
programa: matrices main
	g++ -o matrices Matrices.o Main.o
#Primer objetivo
matrices: Matrices.cpp Matrices.h
	g++ -c Matrices.cpp
main: Main.cpp Matrices.h
	g++ -c Main.cpp
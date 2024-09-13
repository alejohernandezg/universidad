all: programa
programa: Archivos Main
	g++ -o Archivos Archivos.o Main.o
Archivos: Archivos.cpp Archivos.h
	g++ -c Archivos.cpp
Main: Main.cpp Archivos.h
	g++ -c Main.cpp
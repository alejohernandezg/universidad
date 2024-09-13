all: programa
programa: Archivos Main
	g++ -o Archivos ArchivosBinarios.o Main.o
Archivos: ArchivosBinarios.cpp ArchivosBinarios.h
	g++ -c ArchivosBinarios.cpp
Main: Main.cpp ArchivosBinarios.h
	g++ -c main.cpp
all: programa
programa: arreglos main
	g++ -o arreglos Arreglos.o Main.o
#Primer objetivo
arreglos: Arreglos.cpp Arreglos.h
	g++ -c Arreglos.cpp
main: Main.cpp Arreglos.h
	g++ -c Main.cpp
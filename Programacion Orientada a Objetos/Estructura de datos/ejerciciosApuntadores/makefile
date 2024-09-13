all: programa
programa: apuntadores main
	g++ -o progrApuntadores Apuntadores.o Main.o
#Primer objetivo
apuntadores: Apuntadores.cpp Apuntadores.h
	g++ -c Apuntadores.cpp
main: Main.cpp Apuntadores.h
	g++ -c Main.cpp
all: programa
programa: Colegio Main
				g++ -o Colegio.exe Colegio.o Main.o
Colegio:Colegio.cpp Colegio.h
				g++ -c Colegio.cpp
Main: Main.cpp Colegio.h
				g++ -c Main.cpp
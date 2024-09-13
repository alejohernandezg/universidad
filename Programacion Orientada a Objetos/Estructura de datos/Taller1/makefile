all: programa
programa: Taller1 Main
				g++ -o Taller1.exe Taller1.o Main.o
Taller1:Taller1.cpp Taller1.h
				g++ -c Taller1.cpp
Main: Main.cpp Taller1.h
				g++ -c Main.cpp
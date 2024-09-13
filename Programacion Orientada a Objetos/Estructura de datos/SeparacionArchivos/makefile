all: programa
programa: OperacionesFinanzas Main
				g++ -o Finanzas.exe Finanzas.o Main.o
OperacionesFinanzas:Finanzas.cpp Finanzas.h
				g++ -c Finanzas.cpp
Main: Main.cpp Finanzas.h
				g++ -c Main.cpp
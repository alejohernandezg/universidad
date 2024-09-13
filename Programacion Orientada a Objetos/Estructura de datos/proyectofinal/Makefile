all: programa
programa: listasDobles2.o main.o pilas.o cola.o taller4.o
	g++ -o ld listasDobles2.o main.o pilas.o cola.o taller4.o

listaDobles2.o: listasDobles2.cpp listasDobles2.h
	g++ -c listasDobles2.cpp
main.o: main.cpp listasDobles2.h pilas.h cola.h taller4.o
	g++ -c main.cpp
pilas.o: pilas.cpp pilas.h
	g++ -c pilas.cpp
cola.o: cola.cpp cola.h
	g++ -c cola.cpp
taller4.o: taller4.cpp taller4.h
	g++ -c taller4.cpp
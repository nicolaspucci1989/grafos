CC = gcc
CFLAGS = -Wall

grafo: main.o grafos.o
	$(CC) $(CFLAGS) -o grafo main.o grafos.o

main.o: main.c grafos.h
	$(CC) $(CFLAGS) -c main.c

grafos.o: grafos.c grafos.h
	$(CC) $(CFLAGS) -c grafos.c


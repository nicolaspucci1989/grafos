CC = gcc
CFLAGS = -Wall

grafos: main.o grafos.o
	$(CC) $(CFLAGS) -o grafos main.o grafos.o


bfs: grafos.o bfs_ady.o
	$(CC) $(CFLAGS) -o bfs grafos.o bfs_ady.o

bfs_ady.o: bfs_ady.c grafos.h
	$(CC) $(CFLAGS) -c bfs_ady.c

main.o: main.c grafos.h
	$(CC) $(CFLAGS) -c main.c

grafos.o: grafos.c grafos.h
	$(CC) $(CFLAGS) -c grafos.c

clean:
	rm *.o *.exe

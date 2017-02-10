CC = gcc
CFLAGS = -Wall

grafos: main.o grafos.o
	$(CC) $(CFLAGS) -o grafos main.o grafos.o

main.o: main.c grafos.h
	$(CC) $(CFLAGS) -c main.c

grafos.o: grafos.c grafos.h
	$(CC) $(CFLAGS) -c grafos.c

clean:
	rm *.o *.exe

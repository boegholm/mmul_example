
CC=gcc
CFLAGS=-O1 -I.

all: dynmmul statmmul

dynmmul: dynmmul.o dynmmul.c
	$(CC) $(CFLAGS) dynmmul.o mmul.o nanos.o -o dynmmul

statmmul: statmmul.o dynmmul.c
	$(CC) $(CFLAGS) statmmul.o mmul.o nanos.o -o statmmul

dynmmul.o: dynmmul.c mmul.o nanos.o
	$(CC) $(CFLAGS) -c -o dynmmul.o dynmmul.c

statmmul.o: statmmul.c mmul.o nanos.o
	$(CC) $(CFLAGS) -c -o statmmul.o statmmul.c

mmul.o: mmul.h mmul.c
	$(CC) -c $(CFLAGS) mmul.c -o mmul.o

nanos.o: nanos.h nanos.c
	$(CC) -c $(CFLAGS) nanos.c -o nanos.o

clean:
	rm nanos.o mmul.o statmmul.o dynmmul.o dynmmul statmmul

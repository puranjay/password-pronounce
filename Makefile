CC = gcc
CFLAGS = -c -Wall

all: main

main: main.o randrange.o
	$(CC) main.o randrange.o -o password-pronounce

main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c

randrange.o: src/randrange.c
	$(CC) $(CFLAGS) src/randrange.c

clean:
	rm -rf *o password-pronounce

install:
	cp password-pronounce /usr/bin/

uninstall:
	rm /usr/bin/password-pronounce

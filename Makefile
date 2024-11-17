CC = gcc
CFLAGS = -c -Wall
CFL = -lreadline

all: example

example: lab4b.o mystring.o
	$(CC) lab4b.o mystring.o -o example -lreadline
lab4b.o: lab4b.c
	$(CC) $(CFLAGS) lab4b.c 
mystring.o: mystring.c
	$(CC) $(CFLAGS) mystring.c 

clean:
	rm -f *.o example

.PHONY: all clean


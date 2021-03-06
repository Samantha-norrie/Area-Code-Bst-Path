
CC=gcc

CFLAGS=-c -Wall -g -std=c99

all: areaCode

areaCode: areaCode.o bst.o
        $(CC) areaCode.o bst.o -o areaCode

areaCode.o: areaCode.c bst.h
        $(CC) $(CFLAGS) areaCode.c

bst.o: bst.c bst.h
        $(CC) $(CFLAGS) bst.c

clean:
        rm -rf *.o areaCode

CC=gcc
CFLAGS=-DDEBUG
all: bfi

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c
mem.o: mem.c

	$(CC) $(CFLAGS) -c mem.c
bfi: stack.h stack.o mem.h mem.o
	$(CC) $(CFLAGS) bfi.c mem.o stack.o -o bfi	

clean:

	rm -fr main stack.o
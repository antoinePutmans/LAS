CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

ex1: ex1.o
	cc $(CFLAGS) -o ex1 ex1.o

ex1.o: ex1.c
	cc $(CFLAGS) -c ex1.c


clean:
	rm -f *.o 
	rm -f ex1
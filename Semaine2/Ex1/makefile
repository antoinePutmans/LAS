CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

al: ex1 ex2 ex3 ex4

ex1: ex1.o
	cc $(CFLAGS) -o ex1 ex1.o

ex1.o: ex1.c
	cc $(CFLAGS) -c ex1.c

ex2: ex2.o
	cc $(CFLAGS) -o ex2 ex2.o

ex2.o: ex2.c
	cc $(CFLAGS) -c ex2.c


ex3: ex3.o
	cc $(CFLAGS) -o ex3 ex3.o

ex3.o: ex3.c
	cc $(CFLAGS) -c ex3.c

ex4: ex4.o
	cc $(CFLAGS) -o ex4 ex4.o

ex4.o: ex4.c
	cc $(CFLAGS) -c ex4.c

clean:
	rm -f *.o 
	rm -f ex1 ex2 ex3 ex4
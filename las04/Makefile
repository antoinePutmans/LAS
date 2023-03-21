CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

ALL= ex1 ex2 ex3 ex4

all: $(ALL)

ex1: ex1.o utils_v2.o
	gcc $(CFLAGS) -o ex1 ex1.o utils_v2.o

ex1.o: ex1.c utils_v2.h
	gcc $(CFLAGS) -c ex1.c

ex2: ex2.o utils_v2.o
	gcc $(CFLAGS) -o ex2 ex2.o utils_v2.o

ex2.o: ex2.c utils_v2.h
	gcc $(CFLAGS) -c ex2.c

ex3: ex3.o utils_v2.o
	gcc $(CFLAGS) -o ex3 ex3.o utils_v2.o

ex3.o: ex3.c utils_v2.h
	gcc $(CFLAGS) -c ex3.c

ex4: ex4.o utils_v2.o
	gcc $(CFLAGS) -o ex4 ex4.o utils_v2.o

ex4.o: ex4.c utils_v2.h
	gcc $(CFLAGS) -c ex4.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f $(ALL)
CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

all : testWrite testFWrite

testFWrite: testFWrite.o utils_v2.o
	cc $(CFLAGS) -o testFWrite testFWrite.o utils_v2.o

testWrite: testWrite.o utils_v2.o
	cc $(CFLAGS) -o testWrite testWrite.o utils_v2.o

testFWrite.o: testFWrite.c utils_v2.h
	cc $(CFLAGS) -c testFWrite.c

testWrite.o: testWrite.c utils_v2.h
	cc $(CFLAGS) -c testWrite.c

utils_v2.o: utils_v2.c utils_v2.h
	cc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f testWrite test testFWrite testF
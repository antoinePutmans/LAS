CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

all: admin1 distributeur ecran

admin1: utils_v2.o admin1.o
	cc $(CFLAGS) -o admin1 admin1.o utils_v2.o  

distributeur: utils_v2.o distributeur.o
	cc $(CFLAGS) -o distributeur distributeur.o utils_v2.o  

ecran: utils_v2.o ecran.o
	cc $(CFLAGS) -o ecran ecran.o utils_v2.o  

admin1.o: utils_v2.h admin1.c
	cc $(CFLAGS) -c admin1.c  

distributeur.o: utils_v2.h distributeur.c
	cc $(CFLAGS) -c distributeur.c  

ecran.o: utils_v2.h ecran.c
	cc $(CFLAGS) -c ecran.c  

utils_v2.o: utils_v2.h utils_v2.c 
	cc $(CFLAGS) -c utils_v2.c 

# for dev purpose
clear:
	clear
	
clean:
	rm -f *.o
	rm -f dashboard
	rm -f radar
	rm -f admin1
	rm -f ecran
	ipcrm -a

dev1: all
	./radar
	ipcs
	
dev2: all
	./dashboard
	ipcs
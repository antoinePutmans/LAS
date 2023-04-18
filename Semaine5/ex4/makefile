CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

all: admin1 client serveur

client: utils_v2.o client.o
	cc $(CFLAGS) -o client client.o utils_v2.o  

serveur: utils_v2.o serveur.o
	cc $(CFLAGS) -o serveur serveur.o utils_v2.o  

admin1: utils_v2.o admin1.o
	cc $(CFLAGS) -o admin1 admin1.o utils_v2.o  

client.o: utils_v2.h client.c
	cc $(CFLAGS) -c client.c  

serveur.o: utils_v2.h serveur.c
	cc $(CFLAGS) -c serveur.c  

admin1.o: utils_v2.h admin1.c
	cc $(CFLAGS) -c admin1.c  

utils_v2.o: utils_v2.h utils_v2.c 
	cc $(CFLAGS) -c utils_v2.c 

# for dev purpose
clear:
	clear
	
clean:
	rm -f *.o
	rm -f client
	rm -f serveur
	rm -f admin1
	ipcrm -a

dev1: all
	./serveur
	ipcs
	
dev2: all
	./client
	ipcs
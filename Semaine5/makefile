CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

all: radar dashboard

radar: utils_v2.o radar.o
	cc $(CFLAGS) -o radar radar.o utils_v2.o  

dashboard: utils_v2.o dashboard.o
	cc $(CFLAGS) -o dashboard dashboard.o utils_v2.o  

radar.o: utils_v2.h radar.c
	cc $(CFLAGS) -c radar.c  

dashboard.o: utils_v2.h dashboard.c
	cc $(CFLAGS) -c dashboard.c  

utils_v2.o: utils_v2.h utils_v2.c 
	cc $(CFLAGS) -c utils_v2.c 

# for dev purpose
clear:
	clear
	
clean:
	rm -f *.o
	rm -f dashboard
	rm -f radar
	ipcrm -a

dev1: all
	./radar
	ipcs
	
dev2: all
	./dashboard
	ipcs
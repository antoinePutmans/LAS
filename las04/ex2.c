#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v2.h"
#define NB_SIGNAUX 32

volatile sig_atomic_t end = 0;
volatile sig_atomic_t cnt = 0;


void sig_handler(int sig) {
    char* message = "Signal '";
    char* signal = strsignal(sig);
    char* message2 = "' reçu ";
    write(0, message, strlen(message));
    write(0, signal, strlen(signal));
    write(0, message2, strlen(message2));
}

int main(){

    printf("[%d] Hello, I am TIMER! ;)\n", getpid());
    struct sigaction action = {0};
    action.sa_handler = sig_handler;
    ssigfillset(&action.sa_mask);
    action.sa_flags = 0;
    for (int i = 1; i<=NB_SIGNAUX; i++){ 
        if (sigaction(i,&action, NULL) != 0){
            printf("Signal %d (%s) non capture\n", i, strsignal(i));
        }
    }
    
    while (true){
        char* point = ". ";
        write(0,point, strlen(point));
        sleep(1);
    }
    
}
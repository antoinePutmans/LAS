#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v2.h"

volatile sig_atomic_t end = 0;
volatile sig_atomic_t end2 = 0;
volatile sig_atomic_t cnt = 0;

void sigusr1_handler(int sig) {
    char* msg = "Signal SIGUSR1 reçu !\n";
    write(0,msg,strlen(msg));
    cnt++;
    if (cnt >= 7){
        end = 1;
    } 
}

void sigchld_handler(int sig) {
    char* msg = "Fin du père\n";
    write(0,msg,strlen(msg));
    end2 = 1;
}

void child_handler(){
    while(end == 0){
        sleep(1);
    }
}

int main(){
    ssigaction(SIGUSR1, sigusr1_handler);
    ssigaction(SIGCHLD, sigchld_handler);
    pid_t childId = fork_and_run0(child_handler);
    while (end2 == 0){
        skill(childId, SIGUSR1);
        sleep(1);
    }
    
}
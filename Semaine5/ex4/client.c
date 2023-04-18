#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "utils_v2.h"

#define SHM_KEY 244
#define SEM_KEY 360
#define PERM 0666

int main(int argc, char* argv[]){
    if (argc != 2 || !islower(argv[1]) || strlen(argv[1]) != 10){
        printf("No\n");
        exit(1);
    }
    int sem_id = sem_get(SEM_KEY, 2);
    sem_down(sem_id,0); 
    int shm_id = sshmget(SHM_KEY, sizeof(char)*11, 0);
    char* t = sshmat(shm_id);
    strcpy(argv[1],t);
    sem_up(sem_id,1);
    printf("%s",t);
    sem_up(sem_id,1);
}
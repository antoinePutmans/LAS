#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "utils_v2.h"

#define SHM_KEY 244
#define SEM_KEY 360
#define PERM 0666

int main(int argc, char* argv[]){
    bool isCOptionPresent = false;
    bool isDOptionPresent = false;

    for(int i = 1 ; i < argc ; i++){
        if (strcmp(argv[i],"-c") == 0){
            printf("c present\n");
            isCOptionPresent = true;
        } 
        if (strcmp(argv[i],"-d") == 0) {
            printf("d present\n");
            isDOptionPresent = true;
        }
    }

    if (isCOptionPresent == true){
        sem_create(SEM_KEY, 2, PERM, 1);
        int shm_id = sshmget(SHM_KEY, sizeof(char)*11, IPC_EXCL | IPC_CREAT | PERM);
        int sem_id = sem_get(SEM_KEY, 2);
        // Initialisation du deuxieme semaphore a 0 (ferme)
        sem_down(sem_id,1);
    }

    if (isDOptionPresent == true){
        int sem_id = sem_get(SEM_KEY, 2);
        int shm_id = sshmget(SHM_KEY, sizeof(int)*2, 0);
        sshmdelete(shm_id);
        sem_delete(sem_id); 
    }
}
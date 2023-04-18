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

int main(){
    int sem_id = sem_get(SEM_KEY,2);
    sem_down(sem_id,1);
    int shm_id = sshmget(SHM_KEY, sizeof(char)*10, 0);
    char* t = sshmat(shm_id);
    for (int i = 0; t[i]!='\0'; i++) {
        if(t[i] >= 'a' && t[i] <= 'z') {
            t[i] = t[i] -32;
        }
    }
    sem_up(sem_id,0);
}
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "utils_v2.h"

#define SHM_KEY 248
#define SEM_KEY 369
#define PERM 0666

#define DISTRIBUTEUR 0
#define ECRAN 1


int main(){
    int shm_id = sshmget(SHM_KEY, sizeof(int)*2, 0);
    int* t = sshmat(shm_id);
    int sem_id = sem_get(SEM_KEY, 1);
    sem_down0(sem_id);
    if (t[ECRAN] == t[DISTRIBUTEUR]) {
        printf("Il y a personne");
    } else{
        t[ECRAN]++;
        printf("%d",t[ECRAN]);
    }
    sem_up0(sem_id);
}
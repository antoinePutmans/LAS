#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "utils_v2.h"

#define SHM_KEY 248
#define SEM_KEY 369
#define PERM 0666

#define DISTRIBUTEUR 0
#define ECRAN 1

//******************************************************************************
//MAIN FUNCTION
//******************************************************************************
int main (int argc, char *argv[]) {
    int shm_id = sshmget(SHM_KEY, sizeof(int)*2, 0);
    int* t = sshmat(shm_id);
    int sem_id = sem_get(SEM_KEY, 1);
    sem_down0(sem_id);
    (t[0])++;
    printf("%d",t[0]);
    sem_up0(sem_id);
}
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "utils_v2.h"

#define SHM_KEY 248
#define SEM_KEY 369
#define PERM 0666

//******************************************************************************
//MAIN FUNCTION
//******************************************************************************
int main (int argc, char *argv[]) {
    int shm_id = sshmget(SHM_KEY, sizeof(int)*2, 0);
    int* distributeur = sshmat(shm_id);
    (*distributeur++);
    printf("%d",*distributeur);
}
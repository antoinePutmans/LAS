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

int main(){
    int shm_id = sshmget(SHM_KEY, sizeof(int)*2, 0);
    int* distributeur = sshmat(shm_id);
    int* ecran = distributeur++;
    if (*ecran == *distributeur) {
        printf("Il y a personne");
        exit(0);
    }
    (*ecran)++;
    printf("%d",*ecran);
}
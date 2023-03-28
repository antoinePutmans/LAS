#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#include "utils_v2.h"

#define KEY 202020
//******************************************************************************
//MAIN FUNCTION
//******************************************************************************
int main (int argc, char *argv[]) {
  
  alarm(60);
  // GET SHARED MEMORY 
  int shm_id = sshmget(KEY, sizeof(int), 0);
  int* z = sshmat(shm_id);
  while(true){
    printf("shared mem value: *z = %d\n", *z);
    sleep(5);
  }
}
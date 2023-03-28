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
  // GET SHARED MEMORY 
  int shm_id = sshmget(KEY, sizeof(int), 0);
  alarm(60);
  int* z = sshmat(shm_id);
  while(true){
    *z = randomIntBetween(1,25);
    sleep(3);
  }  

  //COMMENT OR UNCOMMENT
  sshmdelete(shm_id);
}
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv) {

    printf("trois .. deux .. un ..");
    //fflush(stdout);
    int childPid = fork();
    if(childPid == -1){
        perror("Error fork");
        exit(1);
    }
    
    if(childPid != 0){
    }
    else{
        printf("partez");
    }
}

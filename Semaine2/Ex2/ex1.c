#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char ** argv) {
    int childPid = fork();
    if(childPid != 0){
        int status = 0;
        pid_t wait = waitpid(childPid,&status,0);
        if(wait == -1){
            perror("Erreur wait");
            exit(1);
        }
        printf("1 2 3\n",);
    }
    else {
        printf("4 5 6\n");
    }
}

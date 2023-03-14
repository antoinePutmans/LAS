#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "utils_v2.h"
#define TAILLEBUFFER 20


int main(){
    int fd[2];
    int ret = pipe(fd);
    int childId = sfork();

    if(childId!=0){
        ret = sclose(pipefd[0]); // pas lire
        checkNeg(ret, "close error");
        char buffer[TAILLEBUFFER];
        while(read(0,buffer,sizeof(char)*TAILLEBUFFER) != EOF){
            int len = strlen(buffer);
            swrite(pipefd[1],buffer,len*sizeof(char));
        };
        ret = sclose(pipefd[1]);
    }
    else {
        
    }
}
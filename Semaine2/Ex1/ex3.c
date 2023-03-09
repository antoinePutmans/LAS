#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv) {
    
    char * buffer = "trois .. deux .. un ..\n";
    int buffer_size = strlen(buffer);
    write(1,buffer,buffer_size);
    

    int childPid = fork();
    if(childPid == -1){
        perror("Error fork");
        exit(1);
    }
    
    if(childPid != 0){
    }
    else{
        char * bufferChild = "partez\n";
        int buffer_sizeChild = strlen(bufferChild);
        write(1,bufferChild,buffer_sizeChild);
    }
}

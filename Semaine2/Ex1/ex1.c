#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv) {
    int a = 5;
    int childPid = fork();
    if(childPid == -1){
        perror("Error");
        exit(1);
    }
    
    printf("%d\n",childPid);

    if(childPid!=0){
        int b = a*5; 
        printf("parent : a = %d, b = %d\n",a,b);
    }
    else{
        int b = a*2;
        printf("child : a = %d, b = %d\n",a,b);
    }
}

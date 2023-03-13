#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


#define MAXCHAR 20
int main(int argc, char ** argv) {

    printf("Veuillez entrer le nom du fichier script\n");
    char buffer[MAXCHAR+1];
    int readSize = read(0,&buffer,(MAXCHAR+1)*sizeof(char));
    checkNeg(readSize,"Erreur read");
    

    int openIndex = open(buffer, O_WRONLY | O_TRUNC | O_CREAT, 0700);
    checkNeg(openIndex,"Erreur d'ouverture");

    char* sheBang = "#!/bin/bash\nls -l\n"; 
    int sheBangSize = strlen(sheBang)+1;
    checkNeg(write(openIndex,sheBang,sizeof(char)*sheBangSize),"Erreur write");
    
    int childPid = fork();
    checkNeg(childPid,"Erreur fork")


    if(childPid != 0){
    
    }
    else {
        // execl("/bin/ls","ls","-l","monscript.sh", NULL);
    }
}

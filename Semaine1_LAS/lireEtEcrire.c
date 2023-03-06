#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "utils_v2.h"

#define MAXCHAR 80

int main(int argc, char ** argv) {

    if(!argv[2]){
        perror("Manque d'arguments");
        exit(1);
    }

    int openIndex1 = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
    checkNeg(openIndex,"Erreur d'ouverture");

    int openIndex2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
    checkNeg(openIndex2,"Erreur d'ouverture");

    char *msg = malloc(sizeof(char) * MAXCHAR+1);

    int readLine = readLimitedLine(msg,MAXCHAR)
    while(readLine>0 && readLine != EOF){
        
    }

    for(int i = 0 ; i < 10000000 ; i++){
        int nbrWr = write(openIndex,&i,sizeof(int));
        checkCond(nbrWr != sizeof(int),"Erreur d'écriture");
    }
    int res = close(openIndex);
    checkNeg(res,"Error closing file");

}


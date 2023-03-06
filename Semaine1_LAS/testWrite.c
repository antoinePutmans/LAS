#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "utils_v2.h"

#define FILENAME "test" 

int main(int argc, char ** argv) {
    int openIndex = open(FILENAME, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    checkNeg(openIndex,"Erreur d'ouverture");
    for(int i = 0 ; i < 10000000 ; i++){
        int nbrWr = write(openIndex,&i,sizeof(int));
        checkCond(nbrWr != sizeof(int),"Erreur d'écriture");
    }
    int res = close(openIndex);
    checkNeg(res,"Error closing file");

}


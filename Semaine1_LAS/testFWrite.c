#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "utils_v2.h"

#define FILENAME "testF" 
#define BUFFERSIZE 80

int main(int argc, char ** argv) {
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Problème"); // message lié à errno
        exit(1);
    }

    for(int i = 0 ; i < 10000000 ; i++){
        if(fwrite(&i,sizeof(int),1,file) != 1){
            perror("Erreur d'écriture");
            exit(1);
        }
    }
    int res = fclose(file);
    checkNeg(res,"Error closing file");

}


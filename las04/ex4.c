#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#include "utils_v2.h"

void nohup_handler(int sig) {
    
}

int main(){
    ssigaction(SIGHUP, nohup_handler);
    int cnt = 0;
    char* insultes[20] = {"prof de DO", "bélître", "puterelle", "butor", "cuistre", "faquin", "orchidoclaste", "faraud", "fesse-mathieu",
     "nodocéphale", "alburostre", "forban", "foutriquet", "fripon", "ganache", "fot-en-cul", "gaupe", "godiche", "gougnafier", "houlier"};
    printf("Tu es un...\n");
    while(1){
        if (cnt == 20) cnt = 0;
        printf("%s", insultes[cnt++]);
        sleep(3);
    }
    exit(0);
}
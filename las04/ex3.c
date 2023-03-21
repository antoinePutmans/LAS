#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#include "utils_v2.h"


#define BUFFERSIZE 80


volatile sig_atomic_t end = 0;

void upper (char *str)
{
   int i = 0;
   while (str[i] != '\0') {
      str[i] = toupper(str[i]);
      i++;
   }
}


void sigpipe_handler(int sig) {
    char* message = "Signal '";
    char* signal = strsignal(sig);
    char* message2 = "' reçu ";
    write(0, message, strlen(message));
    write(0, signal, strlen(signal));
    write(0, message2, strlen(message2));
    end = 1;
}

void run_child(void *argv)
{
   // PROCESSUS FILS
   int *pipefd = argv;
   //char line[BUFFERSIZE + 1];

   // Cloture du descripteur d'écriture
   sclose(pipefd[0]); // on a recu le pipe mais osef
   sclose(pipefd[1]);

    return;
    /* dead code 
       // Boucle de lecture sur le pipe, transformation en uppercase
   // et écriture à l'écran
   int nbChar;
   while ((nbChar = sread(pipefd[0], line, BUFFERSIZE)) != 0) {
      upper(line);
      write(1, line, nbChar);
   }
   */
}

int main(int argc, char **argv)
{
   char line[BUFFERSIZE + 1];

   // Création du pipe
   int pipefd[2];
   spipe(pipefd);
   struct sigaction action = {0};
   action.sa_handler = sigpipe_handler;
   ssigfillset(&action.sa_mask);
   action.sa_flags = 0;
   ssigaction(SIGPIPE, sigpipe_handler);
   // Création de l'enfant
   fork_and_run1(run_child, pipefd);

   // PROCESSUS PARENT
   // Cloture du descripteur pour la lecture
   sclose(pipefd[0]);

   // Boucle de lecture au clavier et écriture dans le pipe 
   int nbChar;
   while ( end == 0) {
      nbChar = read(0, line, BUFFERSIZE);
      write(1, line, nbChar);
      write(pipefd[1], line, nbChar);
   }

   // Cloture du descripteur pour l'écriture
   sclose(pipefd[1]);
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


// PROTOTYPES
void    send_msg(int pid, char *msg);


// CODE
int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        int pid = atoi(argv[1]);
        char *msg = argv[2];
        send_msg(pid,msg);
    }
    else
    {
        printf("Veillez mettre en paramettre le pid du serveur et le message !!");
        return 1;
    }
}

void send_msg(int pid, char *msg)
{
    while (*msg != '\0') {
        // Traitement de chaque caractère
        for (int i = 7; i >= 0; i--) {
            // Bits 1
            if(*msg & (1 << i))
            {
                kill(pid, SIGUSR2)
            }
            else
            {
                kill(pid, SIGUSR1)
            }
            usleep(100000);
        }
        putchar(' '); // Espace entre les caractères pour la lisibilité
        msg++;
    }
    putchar('\n');
}
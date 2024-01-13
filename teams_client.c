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
        printf("Veillez mettre en paramettre le pid du serveur et le message !!\n");
        return 1;
    }
}

void send_msg(int pid, char *msg)
{
    while (*msg != '\0') {
        // Traitement de chaque caractère
        for (int i = 7; i >= 0; i--) {
            printf("%X\n", *msg);
            // Bits 1
            int bit = (*msg >> i) & 1;
            if (bit == 0)
            {
                kill(pid, SIGUSR2);
            }
            else
            {
                kill(pid, SIGUSR1);
            }
            usleep(100000);
        }
        putchar(' '); // Espace entre les caractères pour la lisibilité
        msg++;
    }
    putchar('\n');
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>


// PROTOTYPES
void    print_pid(void);
void    print_msg(int signum);

int binaire = 0;

// CODE
int main()
{
    print_pid();
    printf("En attente de nouveaux messages\n");

    signal(SIGUSR1, print_msg);
    signal(SIGUSR2, print_msg);
    while (1)
    {
        sleep(1);
    }
    
    return 0;
}

// AFFICHER LE CODE
void    print_msg(int signum)
{
    static int bits = 0;

    if (signum == SIGUSR1)
    {
        binaire = (binaire << 1) | 0;
        printf("0\n");
    }   
    else if (signum == SIGUSR2)
    {
        binaire = (binaire << 1) | 1;
        printf("1\n");
    }
    bits++;

    if (bits == 8)
    {
        printf("Caractère reçu : %c\n", (char)binaire);
        bits = 0;
        binaire = 0;
    }
}


// Affichage du pid du serveu
void    print_pid(void)
{
    int pid;
    
    pid = getpid();
    printf("LE PID DU SERVEUR : %i\n", pid);
}
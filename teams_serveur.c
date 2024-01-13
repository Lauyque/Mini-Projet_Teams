#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>


// PROTOTYPES
void    print_pid(void);
void    print_msg(int signum);

int binaire;

// CODE
int main()
{
    print_pid();
    printf("En attente de nouveaux messages");

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
        if (signum = SIGUSR1)
        {
            printf("coucou : %i\n", signum);
        }   
        else if (signum = SIGUSR2)
        {
            printf("pas coucou : %i\n", signum);
        }
}


// Affichage du pid du serveu
void    print_pid(void)
{
    int pid;
    
    pid = getpid();
    printf("LE PID DU SERVEUR : %i\n", pid);
}
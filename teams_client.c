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
    int value;
    int count = 0;
    while (msg[count] != '\0')
    {
        value = msg[count];
        count++;
        printf("%i", value);
    }
    putchar('\n');
}
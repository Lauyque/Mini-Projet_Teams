#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


// PROTOTYPES
void    send_msg(int pid, char msg);


// CODE
int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        int pid = atoi(argv[1]);
        char msg = atoi(argv[2]);
        send_msg(int pid,char msg);
    }
}

void send_msg(int pid, char msg)
{
    printf("%d", *msg)
}
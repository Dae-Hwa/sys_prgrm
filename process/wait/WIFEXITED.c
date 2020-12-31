#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int pid,
        child_pid,
        status;

    pid = fork();

    switch (pid)
    {
    case -1:
        perror("fork is failed\n");
        break;
    case 0:
        execl("/bin/ls", "ls", "-al", NULL);
        perror("execl is failed\n");
        break;
    default:
        child_pid = wait(&status);

        if (WIFEXITED(status) != 0)
        {
            printf("Child Process Normally Terminated\n");
        }
        else
        {
            printf("somthings wrong");
        }
        break;
    }
}
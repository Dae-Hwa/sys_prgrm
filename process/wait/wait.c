#include <unistd.h>
#include <stdio.h>

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
        child_pid = wait(NULL);
        printf("ls is complete\n");
        printf("parent : %d\n", getpid());
        printf("cilhd : %d\n", child_pid);
        break;
    }
}
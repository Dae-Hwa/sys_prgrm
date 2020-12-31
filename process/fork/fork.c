#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    printf("Before fork\n");

    pid = fork();

    if (pid == 0)
    {
        printf("Child : %d\n", pid);
        printf("pid=%d\n", getpid());
        printf("ppid=%d\n", getppid());
    }
    else if (0 < pid)
    {
        printf("Parent : %d\n", pid);
        printf("pid=%d\n", getpid());
        printf("ppid=%d\n", getppid());
    }
    else
    {
        printf("fork failed");
    }

    return 0;
}
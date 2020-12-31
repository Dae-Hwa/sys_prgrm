#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *envp[] = {"USER=DAE", NULL};
    char *arg[] = {"ls", "-al", NULL};

    printf("execute(execve) ls\n");

    execve("/bin/ls", arg, envp);

    perror("execve is failed\n");
    exit(1);
}
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *arg[] = {"ls", "-al", NULL};

    printf("execute(execve) ls\n");

    execvp("ls", arg);

    perror("execve is failed\n");
    exit(1);
}
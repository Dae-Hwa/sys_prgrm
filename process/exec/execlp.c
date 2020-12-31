#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("execute ls\n");

    char *args[] = {"ls", "-l", NULL};

    execvp("ls", args);

    perror("execl is failed\n");
    exit(1);
}
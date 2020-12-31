#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#define MAXLINE 64

int main(int argc, char **argv)
{
    char buf[MAXLINE];
    pid_t pid;
    printf("My Shell Executed\n");

    while (1)
    {
        printf("> ");
        memset(buf, 0x00, MAXLINE);
        fgets(buf, MAXLINE - 1, stdin);

        if (strncmp(buf, "exit\n", 5) == 0)
        {
            break;
        }

        // 마지막 개행문자 제거
        buf[strlen(buf) - 1] = 0x00;

        pid = fork();
        if (pid == 0)
        {
            // 문자열 스플릿
            char *spilited[strlen(buf)];
            char *command = strtok(buf, " ");
            int last = 0;
            for (int i = 0; command != NULL; i++)
            {
                spilited[i] = command;
                command = strtok(NULL, " ");
                last = i;
            }
            spilited[last + 1] = NULL;

            if (execvp(buf, spilited) == -1)
            {
                printf("execution failed, input command : %s\n", buf);
                exit(0);
            }
        }
        if (0 < pid)
        {
            wait(NULL);
        }
    }
    return 0;
}
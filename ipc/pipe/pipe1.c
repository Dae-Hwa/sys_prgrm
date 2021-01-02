#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 255

char *msg = "Hello Child Process";

int main()
{
    char buf[255];
    int fd[2], pid, nbytes;

    // 파이프 생성
    if (pipe(fd) < 0)
        exit(1);

    pid = fork();

    if (0 < pid)
    {
        printf("this is parent\n");
        printf("pid : %d, cpid : %d\na", getpid(), pid);
        // 파이프에 전달
        write(fd[1], msg, MSGSIZE);
        exit(0);
    }
    else
    {
        printf("this is child\n");
        printf("pid : %d\n", getpid());
        // 파이프에서 꺼냄
        nbytes = read(fd[0], buf, MSGSIZE);
        printf("%d %s\n", nbytes, buf);
        exit(0);
    }

    return 0;
}
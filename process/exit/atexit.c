#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    void exitHandling(void);
    void goodbyeMessage(void);

    int ret;

    ret = atexit(exitHandling);
    if (ret != 0)
    {
        perror("Error in atexit\n");
    }
    ret = atexit(goodbyeMessage);
    if (ret != 0)
    {
        perror("Error in atexit\n");
    }
    exit(EXIT_SUCCESS);
}

void exitHandling(void)
{
    printf("exit handling\n");
}

void goodbyeMessage(void)
{
    printf("goodbye\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int value = 100;

    printf("Before fork(): value = %d\n", value);

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child: value before modification = %d\n", value);

        value = 200;

        printf("Child: value after modification = %d\n", value);
    }
    else
    {
        wait(NULL);

        printf("Parent: value after child modification = %d\n", value);
    }

    return 0;
}

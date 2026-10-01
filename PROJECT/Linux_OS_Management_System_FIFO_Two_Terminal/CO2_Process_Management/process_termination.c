#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child process started.\n");
        printf("Child PID: %d\n", getpid());

        printf("Child process is terminating...\n");
        exit(0);
    }
    else
    {
        printf("Parent process waiting for child...\n");

        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Child terminated normally.\n");
            printf("Exit status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t pid;

    char message[100];
    char received[100];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    printf("=====================================\n");
    printf("       IPC USING PIPE\n");
    printf("=====================================\n");

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        // Parent process
        close(fd[0]);

        printf("Parent: Enter a message: ");
        fgets(message, sizeof(message), stdin);

        message[strcspn(message, "\n")] = '\0';

        write(fd[1], message, strlen(message) + 1);

        printf("Parent: Message sent through pipe.\n");

        close(fd[1]);

        wait(NULL);

        printf("Parent: Child process completed.\n");
    }
    else
    {
        // Child process
        close(fd[1]);

        read(fd[0], received, sizeof(received));

        printf("Child : Message received: %s\n", received);

        close(fd[0]);
    }

    return 0;
}

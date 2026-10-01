#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    int pipefd[2];
    pid_t pid;
    char message[256];
    char buffer[256] = {0};

    printf("\n=== PIPE COMMUNICATION DEMO ===\n");
    printf("Enter message to send from parent to child: ");
    if (!fgets(message, sizeof(message), stdin)) return 1;
    message[strcspn(message, "\n")] = '\0';

    if (pipe(pipefd) == -1) { perror("pipe failed"); return 1; }

    pid = fork();
    if (pid < 0) { perror("fork failed"); return 1; }

    if (pid == 0) {
        close(pipefd[1]);
        ssize_t n = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (n < 0) { perror("read failed"); close(pipefd[0]); return 1; }
        buffer[n] = '\0';
        printf("\nChild received: %s\n", buffer);
        close(pipefd[0]);
    } else {
        close(pipefd[0]);
        write(pipefd[1], message, strlen(message));
        close(pipefd[1]);
        waitpid(pid, NULL, 0);
        printf("Parent: Message sent successfully through pipe.\n");
    }
    return 0;
}

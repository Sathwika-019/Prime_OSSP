#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig)
{
    printf("\n\nSignal received: SIGINT (%d)\n", sig);
    printf("Process is terminating safely.\n");
    exit(0);
}

int main(void)
{
    signal(SIGINT, handle_signal);

    printf("\n=== SIGNAL COMMUNICATION DEMO ===\n");
    printf("Process ID: %d\n", getpid());
    printf("The process is waiting for SIGINT.\n");
    printf("Press Ctrl+C when you want to send SIGINT.\n\n");

    while (1) {
        printf("Process is running... (PID: %d)\n", getpid());
        sleep(2);
    }
    return 0;
}

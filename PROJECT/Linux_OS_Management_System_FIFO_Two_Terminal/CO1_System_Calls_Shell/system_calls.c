#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("Linux System Calls Demonstration\n\n");

    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());

    printf("\nSystem call demonstration completed.\n");

    return 0;
}

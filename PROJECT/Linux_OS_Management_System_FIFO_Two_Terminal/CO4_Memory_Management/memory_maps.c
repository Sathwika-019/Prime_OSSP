#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process ID: %d\n\n", getpid());

    printf("Process memory map:\n");
    printf("-------------------\n");

    FILE *file = fopen("/proc/self/maps", "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}

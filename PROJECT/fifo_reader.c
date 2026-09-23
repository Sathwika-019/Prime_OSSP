#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/sathwika_fifo"

int main()
{
    int fd;
    char received[100];

    printf("=====================================\n");
    printf("          FIFO READER\n");
    printf("=====================================\n");

    printf("Reader: Waiting for message...\n");

    fd = open(FIFO_NAME, O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    read(fd, received, sizeof(received));

    printf("Reader: Message received: %s\n", received);

    close(fd);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_NAME "/tmp/sathwika_fifo"

int main()
{
    int fd;
    char message[100];

    printf("=====================================\n");
    printf("          FIFO WRITER\n");
    printf("=====================================\n");

    mkfifo(FIFO_NAME, 0666);

    printf("Writer: Enter a message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("Writer: Waiting for reader...\n");

    fd = open(FIFO_NAME, O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, message, strlen(message) + 1);

    printf("Writer: Message sent successfully.\n");

    close(fd);

    return 0;
}

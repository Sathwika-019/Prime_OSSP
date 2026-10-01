#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char message[] = "Hello from Linux File I/O!";
    char buffer[100];

    fd = open("sample.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, message, strlen(message));
    close(fd);

    fd = open("sample.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    int bytes = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';

    printf("Data read from file: %s\n", buffer);

    close(fd);

    return 0;
}

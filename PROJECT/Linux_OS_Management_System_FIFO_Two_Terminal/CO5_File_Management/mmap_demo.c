#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
    const char *filename = "mapped.txt";
    const char *message = "Hello from memory mapped file!";
    int fd;
    size_t length = strlen(message) + 1;

    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    if (ftruncate(fd, length) == -1)
    {
        perror("ftruncate");
        close(fd);
        return 1;
    }

    char *mapped = mmap(NULL, length,
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED, fd, 0);

    if (mapped == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    strcpy(mapped, message);

    printf("Data written using mmap(): %s\n", mapped);

    munmap(mapped, length);
    close(fd);

    return 0;
}

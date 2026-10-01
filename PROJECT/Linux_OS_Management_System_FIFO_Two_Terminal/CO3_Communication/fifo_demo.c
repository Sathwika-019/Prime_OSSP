#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define FIFO_PATH "/tmp/linux_os_management_fifo"
#define BUF_SIZE 256

static void create_fifo(void) {
    if (mkfifo(FIFO_PATH, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo failed");
        exit(EXIT_FAILURE);
    }
}

static void reader(void) {
    char buffer[BUF_SIZE];
    int fd;

    create_fifo();
    printf("\n=== FIFO READER ===\n");
    printf("FIFO: %s\n", FIFO_PATH);
    printf("Waiting for a message from the writer...\n");
    fflush(stdout);

    fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) { perror("open reader"); exit(EXIT_FAILURE); }

    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
    if (n > 0) {
        buffer[n] = '\0';
        printf("\nReader received: %s\n", buffer);
    }
    close(fd);
}

static void writer(void) {
    char buffer[BUF_SIZE];
    int fd;

    create_fifo();
    printf("\n=== FIFO WRITER ===\n");
    printf("FIFO: %s\n", FIFO_PATH);
    printf("Enter message to send: ");
    fflush(stdout);

    if (!fgets(buffer, sizeof(buffer), stdin)) return;
    buffer[strcspn(buffer, "\n")] = '\0';

    fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) { perror("open writer"); exit(EXIT_FAILURE); }

    write(fd, buffer, strlen(buffer) + 1);
    printf("Message sent successfully through FIFO.\n");
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2 || (strcmp(argv[1], "reader") != 0 && strcmp(argv[1], "writer") != 0)) {
        printf("Usage:\n");
        printf("  %s reader   # run in Terminal 1\n", argv[0]);
        printf("  %s writer   # run in Terminal 2\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "reader") == 0) reader();
    else writer();

    return 0;
}

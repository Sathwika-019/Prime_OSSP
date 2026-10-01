#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    const char *dirname = "test_directory";

    if (mkdir(dirname, 0755) == -1)
    {
        printf("Directory may already exist.\n");
    }
    else
    {
        printf("Directory created successfully.\n");
    }

    DIR *dir = opendir(".");

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;

    printf("\nFiles and directories:\n");

    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("========================================\n");
        printf("     LINUX INTER-PROCESS COMMUNICATION\n");
        printf("========================================\n");
        printf("1. IPC using Pipe\n");
        printf("2. IPC using FIFO\n");
        printf("3. Compare Pipe and FIFO\n");
        printf("4. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nStarting Pipe IPC...\n");
                system("./pipe_ipc");
                break;

            case 2:
                printf("\nFIFO IPC requires two terminals.\n");
                printf("Terminal 1: ./fifo_reader\n");
                printf("Terminal 2: ./fifo_writer\n");
                break;

            case 3:
                printf("\n");
                printf("========== PIPE vs FIFO ==========\n");
                printf("Pipe : Usually used between related processes.\n");
                printf("FIFO : Can be used between independent processes.\n");
                printf("Pipe : Created using pipe().\n");
                printf("FIFO : Created using mkfifo().\n");
                printf("Pipe : Unnamed communication channel.\n");
                printf("FIFO : Named communication channel.\n");
                printf("==================================\n");
                break;

            case 4:
                printf("\nExiting project...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

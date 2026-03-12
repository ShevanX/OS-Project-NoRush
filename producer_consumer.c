#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    int choice;

    while (1)
    {
        printf("\n===== PRODUCER-CONSUMER MENU =====\n\n");
        printf("1. Producer\n");
        printf("2. Consumer\n");
        printf("0. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("\nExiting Producer-Consumer Menu.\n\n");
            break;
        }

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            // Child process
            if (choice == 1)
            {
                execl("./producer", "producer", NULL);
            }
            else if (choice == 2)
            {
                execl("./consumer", "consumer", NULL);
            }
            else
            {
                printf("Invalid choice!\n");
            }
            // If exec fails
            perror("Exec failed");
            exit(1);
        }
        else
        {
            // Parent process waits
            wait(NULL);
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int choice;

    while(1){
        //Menu display
        printf("\n===== MAIN MENU =====\n\n");
        printf("1. Fork based Task executor system\n");
        printf("2. Producer–Consumer Simulation System\n");
        printf("0. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //quit if the choice is 0
        if (choice == 0){
            printf("\nExiting Program. Goodbye!!!\n\n");
            break;
        }

        //creating a fork
        pid_t pid = fork();

        if(pid < 0){
            perror("fork failed");
            exit(1);
        } else if (pid == 0){
            // Child process
            if (choice == 1){
                execl("./fork_tasks", "fork_task", NULL);
            }
            else if (choice == 2){
                execl("./producer_consumer", "producer_consumer", NULL); 
            }
            else{
                printf("Invalid choice!\n");
            }
            //If execl fails
            perror("Exec failed.");
            exit(1);
        } else {
            // Parent process waits for child
            wait(NULL);
        }
    }

    return 0;
}
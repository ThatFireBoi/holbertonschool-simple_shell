#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
void print_prompt() {
    printf("$ ");
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        print_prompt();

        if (fgets(command, sizeof(command), stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            printf("\n");
            break;
        }

        // Remove the newline character
        size_t command_length = strlen(command);
        if (command_length > 0 && command[command_length - 1] == '\n') {
            command[command_length - 1] = '\0';
        }

	//Handles exit command
	if (strcmp(command, "exit") == 0) {
            printf("Logging off\n");
            break;
        }

        // Fork the child
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child
            execlp(command, command, (char *)NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            // Parent
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                if (exit_status != 0) {
                    printf("Command returned with non-zero exit status: %d\n", exit_status);
                }
            } else if (WIFSIGNALED(status)) {
                printf("Command terminated by signal\n");
            }
        }
    }

    return 0;
}


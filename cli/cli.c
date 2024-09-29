/*
################################################################################
################################################################################
### Nain Project Programming Language CLI                                    ###
################################################################################
################################################################################
Copyright 2024 Mario Rosell <mar1luski@proton.me>
All rights reserved

This file is part of the Nain project programming language CLI.
The Nain project is free software, meant to be usefull and to help you develop faster
The projet is released uncer the OCL license 1.4, meaning you can re-distribute it, edit it,
contribute to it, but always with the same license, giving credits to the original author and
comercial use is not allowed unless permission is given by the author or project administrator.

Everything on the Nain project has no warranty. In case of bugs, you can ask on the forums.
/I hope you enjoy using it as much as I enjoyed making it :)
Now with everything said, let's get to it!
*/

#include <stdio.h>      // For printf and fgets
#include <stdlib.h>     // For exit and system
#include <string.h>     // For strtok and strcmp
#include <unistd.h>     // For fork, execvp, and chdir
#include <sys/types.h>  // For data types
#include <sys/wait.h>   // For waitpid

#define MAX_INPUT_SIZE 1024  // Maximum size for input buffer
#define MAX_ARG_SIZE 100     // Maximum number of arguments

int main() {
    char input[MAX_INPUT_SIZE];        // Buffer for storing user input
    char *args[MAX_ARG_SIZE];          // Array for storing command arguments
    pid_t pid;                         // Process ID for child processes
    int status;                        // Variable to store exit status of child

    while (1) {
        printf("mycli> ");             // Display the CLI prompt
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) { // Read user input
            perror("fgets");           // Handle input error
            continue;                  // Continue to the next iteration
        }

        // Remove trailing newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for the exit command
        if (strcmp(input, "exit") == 0) {
            system("clear");           // Clear the screen before exiting
            break;                     // Exit the loop and terminate
        }

        // Tokenize the input into arguments
        int i = 0;
        args[i] = strtok(input, " ");  // Get the first token (command)
        while (args[i] != NULL) {      // Loop to get remaining tokens
            i++;
            args[i] = strtok(NULL, " "); // Get next token
        }

        // Check for built-in command 'cd'
        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "cd: missing argument\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("cd");      // Handle chdir error
                }
            }
            continue;  // Skip forking and executing if it's a built-in command
        }

        // Fork a child process
        pid = fork();
        if (pid < 0) {                 // Fork failed
            perror("fork");            // Handle fork error
            continue;                  // Continue to the next iteration
        }

        if (pid == 0) {                // Child process
            // Execute the command using execvp
            if (execvp(args[0], args) == -1) {
                perror("execvp");      // Handle exec failure
            }
            exit(EXIT_FAILURE);         // Exit if exec fails
        } else {                        // Parent process
            // Wait for the child process to finish
            do {
                waitpid(pid, &status, WUNTRACED); // Wait for child to finish
            } while (!WIFEXITED(status) && !WIFSIGNALED(status)); // Check if child exited normally
        }
    }

    return 0; // Exit the program
}

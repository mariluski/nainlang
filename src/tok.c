/*
################################################################################
###### Nain Project Programming Language Token list                       ######
################################################################################
Copyright 2024 Mario Rosell <mar1luski@proton.me>
All rights reserved

This file is part of the Nain project programming language.
The Nain project is free software, meant to be useful and to help you develop faster.
The project is released under the OCL license 1.4, meaning you can re-distribute it, edit it,
contribute to it, but always with the same license, giving credits to the original author and
commercial use is not allowed unless permission is given by the author or project administrator.

Everything on the Nain project has no warranty. In case of bugs, you can ask on the forums.
I hope you enjoy using it as much as I enjoyed making it :)
Now with everything said, let's get to it!
*/

#include <stdio.h>   // For printf and fgets
#include <stdlib.h> // For exit and system calls
#include <string.h>  // For strtok and strcmp
#include <unistd.h>  // For fork, execvp, and chdir

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_SIZE];

    while (1) {
        // Display the CLI prompt
        char *user = getenv("USER");
        printf("nain@cli in %s > ", user);

        // Read user input
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            perror("fgets");
            continue; // Read next input if there was an error
        }

        // Exit condition for the shell
        if (strcmp(input, "exit\n") == 0) {
            break; // Exit the loop if user types "exit"
        }

        // Tokenizing the input
        input[strcspn(input, "\n")] = 0; // Remove the newline character
        char *token = strtok(input, " ");
        int i = 0;

        // Storing tokens in arguments array (if needed)
        while (token != NULL && i < MAX_ARG_SIZE - 1) {
            args[i++] = token; // Add token to arguments
            token = strtok(NULL, " "); // Get next token
        }
        args[i] = NULL; // Terminate the array with NULL

    }
    
    return 0; // Exit the main function
}

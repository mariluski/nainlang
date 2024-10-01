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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1000 // Reasonable size for input buffer
#define MAX_USER_SIZE 100   // Reasonable size for username

void display_help() {
    printf("Available commands:\n");
    printf("cli.help - Show this help message\n");
    printf("cli.exit - Exit the program\n");
}

int main() {
    char banner[] = " \n \
███╗   ██╗ █████╗ ██╗███╗   ██╗ \n\
 ████╗  ██║██╔══██╗██║████╗  ██║ \n\
 ██╔██╗ ██║███████║██║██╔██╗ ██║ \n \
██║╚██╗██║██╔══██║██║██║╚██╗██║ \n \
██║ ╚████║██║  ██║██║██║ ╚████║ \n \
╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝ \n \
";
    
    printf("%s", banner);
    printf("Nain Project Programming Language CLI\n");
    printf("Copyright 2024 Mario Rosell\n");
    printf("====================================\n");
    printf("Use cli.help to get help and cli.exit to exit, or press CTRL+D\n\n");
    
    char input[MAX_INPUT_SIZE];

    while (1) {
        char *user = getlogin(); // Get user name
        if (user == NULL) {
            strncpy(user, "Unknown", MAX_USER_SIZE);
        }
        printf("Nain CLI at %s > ", user); // Prompt for user input
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on EOF (CTRL+D)
        }

        // Remove newline character if it exists
        input[strcspn(input, "\n")] = 0;

        // Check for commands
        if (strcmp(input, "cli.help") == 0) {
            display_help(); // Invoke help function
        } else if (strcmp(input, "cli.exit") == 0) {
            printf("\nExiting Nain...\n");
            system("clear");
            break;
        } else {
            printf("Unknown command: %s\n", input);
        }
    }

    return 0;
}

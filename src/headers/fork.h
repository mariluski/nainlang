#ifndef fork_h
#define fork_h

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#endif // fork_h

pid_t fork() {
    pid_t pidErrorCode = fork();
    if (pidErrorCode < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return pidErrorCode;
}

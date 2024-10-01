#ifndef addToPipe_h
#define addToPipe_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif // addToPipe_h

char *addToPipe(char *input) {
    char *result = (char *)malloc(strlen(input) + 1);
    if (result == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(result, input);
    return result;
}
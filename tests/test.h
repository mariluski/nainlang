/*
##################################
### Nain test utils header file ##
##################################
Copyright 2024 Mario Rosell <mar1luski@proton.me>
All rights reserved

This file is part of the Nain project testing framework.
The Nain project is free software, meant to be usefull and to help you develop faster
The projet is released uncer the OCL license 1.4, meaning you can re-distribute it, edit it,
contribute to it, but always with the same license, giving credits to the original author and
comercial use is not allowed unless permission is given by the author or project administrator.

Everything on the Nain project has no warranty. In case of bugs, you can ask on the forums.
I hope you enjoy using it as much as I enjoyed making it :)
Now with everything said, let's get to it!
*/

// Define the Nain test utils header file
#ifndef TEST_UTILS_H
#define TEST_UTILS_H

// imports neccesary headers for better portability
#include <stdio.h>
#include <stdlib.h>

// Macro for comparing two values, if the arguments are not euqual, it returns an error
#define assertEquals(expected, actual)                      \
    do {                                                             \
        if ((expected) != (actual)) {                                \
            fprintf(stderr, "Assertion failed: [%s:%d] "           \
                    "Expected: %d, Actual: %d\n",                  \
                    __FILE__, __LINE__, (expected), (actual));     \
            exit(EXIT_FAILURE);                                      \
        }                                                            \
    } while(0)

// Macro for checking if a pointer is NULL
#define assertNotNull(ptr)                                    \
    do {                                                             \
        if ((ptr) == NULL) {                                         \
            fprintf(stderr, "Assertion failed: [%s:%d] "           \
                    "Expected non-null pointer\n",                 \
                    __FILE__, __LINE__);                           \
            exit(EXIT_FAILURE);                                      \
        }                                                            \
    } while(0)
#define assertNotErrors(ptr)                                    \
    do {                                                             \
        if ((ptr) == NULL) {                                         \
            fprintf(stderr, "Assertion failed: [%s:%d] "           \
                    "Expected non-null pointer\n",                 \
                    __FILE__, __LINE__);                           \
            exit(EXIT_FAILURE);                                      \
        }                                                            \
    } while(0)

// Function to print a test start message
void start_test(const char* test_name) {
    printf("Running test: %s\n", test_name);
}

// Function to print a test end message
void end_test() {
    printf("Test completed successfully.\n");
}

#endif // TEST_UTILS_H
#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdio.h>
#include <stdlib.h>

// Macro for comparing two values
#define TEST_ASSERT_EQUAL(expected, actual)                          \
    do {                                                             \
        if ((expected) != (actual)) {                                \
            fprintf(stderr, "Assertion failed: [%s:%d] "           \
                    "Expected: %d, Actual: %d\n",                  \
                    __FILE__, __LINE__, (expected), (actual));     \
            exit(EXIT_FAILURE);                                      \
        }                                                            \
    } while(0)

// Macro for checking if a pointer is NULL
#define TEST_ASSERT_NOT_NULL(ptr)                                    \
    do {                                                             \
        if ((ptr) == NULL) {                                         \
            fprintf(stderr, "Assertion failed: [%s:%d] "           \
                    "Expected non-null pointer\n",                 \
                    __FILE__, __LINE__);                           \
            exit(EXIT_FAILURE);                                      \
        }                                                            \
    } while(0)

// Function to print a test start message
void start_test(const char* test_name) {
    printf("Running test: %s\n", test_name);
}

// Function to print a test end message
void end_test() {
    printf("Test completed successfully.\n");
}

#endif // TEST_UTILS_H
//TODO add more functions
// TODO add comments on \ lines
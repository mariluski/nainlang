/**
 * @file tokmrg.h
 * @author Mario (marilusk1@proton.me)
 * @brief Header file to tokenize inputs.
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef tokmrg_h
#define tokmrg_h
#include <stdio.h>  // for printing
#include <unistd.h> // for pipes
#include <stdlib.h> // for allocation
#include <string.h> // for string management
#endif

enum TOKS {
    // Mathematical Operators
    PLUS, 
    MINUS, 
    MULTIPLY, 
    DIVIDE, 
    ELEVATE, 
    POW, 
    MOD, 
    FACTORIAL, 
    ABS, 
    SQRT,

    // Trigonometric Functions
    SIN, 
    COS, 
    TAN, 
    ASIN, 
    ACOS, 
    ATAN, 
    SINH, 
    COSH, 
    TANH, 
    ASINH, 
    ACOSH, 
    ATANH,

    // Logarithmic and Exponential Functions
    LOG, 
    LN, 
    LOG10, 
    EXP,

    // Constants
    PI, 
    E,

    // Boolean Constants
    TRUE, 
    FALSE,

    // Parentheses and Brackets
    L_PAREN, 
    R_PAREN, 
    L_BRACKET, 
    R_BRACKET, 
    L_BRACE, 
    R_BRACE,

    // Punctuation
    COMMA, 
    SEMICOLON, 
    COLON,
    
    // Assignment and Equality
    ASSIGN, 
    EQUAL, 
    NOT_EQUAL,
    
    // Comparison Operators
    LESS, 
    LESS_EQUAL, 
    GREATER, 
    GREATER_EQUAL,

    // Logical Operators
    AND, 
    OR, 
    NOT,

    // Control Structures
    IF, 
    ELSE, 
    WHILE, 
    DO, 
    FOR, 
    TO, 
    STEP, 
    BREAK, 
    CONTINUE, 
    RETURN,
    
    // Variable Declarations
    LET, 
    IN,

    // Asynchronous Functions
    ASYNC, 
    AWAIT,
    
    // Functions and Imports/Exports
    FUNC,
    WITH, 
    AKA, 
    EXPORT,
};

// Tokenizer function
void tokenize(char input[]) {
    int i = 0;
    char currentChar;
    
    while ((currentChar = input[i]) != '\0') {
        switch (currentChar) {
            case '+': 
                printf("PLUS token found\n");
                break;
            case '-': 
                printf("MINUS token found\n");
                break;
            case '*': 
                printf("MULTIPLY token found\n");
                break;
            case '/': 
                printf("DIVIDE token found\n");
                break;
            // Handle other characters/symbols as needed.
            default:
                printf("Unknown token: %c\n", currentChar);
        }
        i++;
    }
}

// Advance function: move through the input
void advance(char input[], int *pos, char *currentChar) {
    if (input[*pos] != '\0') {
        *currentChar = input[*pos];
        (*pos)++;
    } else {
        *currentChar = '\0';
    }
}

// Example token break function
void breakTokens(char input[]) {
    int pos = 0;
    char currentChar = input[pos];
    while (currentChar != '\0') {
        tokenize(&currentChar); // Tokenize each character (simplified)
        advance(input, &pos, &currentChar); // Move to the next character
    }
}
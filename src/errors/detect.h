/*
##########################################
#### Nain error detection header file ####
##########################################

Nain is a small, fast and safe programming lenguage.
*/

#ifndef detect_h // Creates a header
#define detect_h//  Defines a macro

#include <stdio.h> // For printing
#include <stdlib.h>  // For memory management
#include <string.h> // For string manipulation

int main(char input[]) {
    // Code for error detection
    /*
        EXPLANATION OF HOW ERRORS ARE DETECTED.
        
        Errors are detected by the order of the tokens, cheking types, arguments, unfinished statements, etc.

        Example:
        
        fn addTwoNumbers(a: int b: int) {
            return a + // missing operhand
        }

        This, will return the following error:

        fatal:
        =================================================
        | error type: unfinished statement.             |
        | location: line 2, column 9.                   |
        | description: The statement is unfinished.     |
        | see: `nine explain E1` for more information.  |
        | ==============================================|
        |   return a + => error: operhand not found.    |
        |   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ |
        |   HINT:                                       |
        |   Remove the + sign.                          |
        =================================================
        thats how errors look like.
        and warnings look like this:

        fn addTwoNumbers(a: int b: int) {
            return a + point(b)
        }
        
        warning at line 2, column 16: using pointers to arguments is not recommended.
        return a + point(b)
        ^^^^^^^^^^^^^^^^^^^
    */
}
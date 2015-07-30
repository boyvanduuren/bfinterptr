//
// Created by boy on 7/28/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

int main()
{
    // our program will be in this piece of memory
    char* ribbon = malloc(sizeof(char) * STACK_SIZE);
    // this piece of memory is for the program to use
    char* stackptr = malloc(sizeof(char) * STACK_SIZE);
    // keep a pointer to the beginning of that memory for free()
    char* beginningofstack = stackptr;

    // read our program from STDIN
    read(STDIN_FILENO, ribbon, RIBBON_SIZE-1);

    // our main loop
    for (int i = 0; i < strlen(ribbon); i++) {
        char operand = ribbon[i];
        op(ribbon, i, &stackptr);
        // If we had to start a new loop, skip to end of loop
        if (operand == '[') {
            i = findclosingbracket(ribbon, i);
        }
    }

    // free allocated memory
    free(ribbon);
    free(beginningofstack);
}

// find the matching closing bracket for a loop
int findclosingbracket(const char* ribbon, int pos)
{
    int count = 0;
    int closingbracket = 0;

    while (closingbracket == 0) {
        char symbol = ribbon[++pos];
        if (symbol == ']') {
            if (count == 0) {
                closingbracket = pos;
            }
            else {
                count--;
            }
        }
        else if (symbol == '[') {
            count++;
        }
        if (pos > strlen(ribbon)) {
            return -1;
        }
    }

    return closingbracket;
}

void newloop(const char* ribbon, int start, int end, char** stackptr)
{
    // the end of a loop should never be less than 1
    if (end < 1) {
        exit(EXIT_FAILURE);
    }
    // loop while value at the stack isn't 0
    while (**stackptr) {
        for (int i = start+1; i < end; i++) {
            char symbol = ribbon[i];
            op(ribbon, i, stackptr);
            if (symbol == '[') {
                // if we started a subloop jump to the end of that
                i = findclosingbracket(ribbon, i);
            }
        }
    }
}

void op(const char* ribbon, int pos, char** stackptr)
{
    char symbol = ribbon[pos];
    switch (symbol) {
        case '[':
            newloop(ribbon, pos, findclosingbracket(ribbon, pos), stackptr);
            break;
        case ']':
            // We don't need to do anything for ]
            break;
        case '<':
            (*stackptr)--;
            break;
        case '>':
            (*stackptr)++;
            break;
        case '-':
            (**stackptr)--;
            break;
        case '+':
            (**stackptr)++;
            break;
        case ',':
            **stackptr = getchar();
            break;
        case '.':
            putchar(**stackptr);
            break;
    }
}

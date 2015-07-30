//
// Created by boy on 7/28/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
//    const char* ribbon = "+++++[->+<]>.";
    const char* ribbon = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
    char* stackptr = malloc(sizeof(char) * STACK_SIZE);

    for (int i = 0; i < strlen(ribbon); i++) {
        char operand = ribbon[i];
        op(ribbon, i, &stackptr);
        // If we had to start a new loop, skip to end of loop
        if (operand == '[') {
            i = findclosingbracket(ribbon, i);
        }
    }
    printf("%d", stackptr[0]);
}

int findclosingbracket(const char *ribbon, int pos)
{
    int count = 0;
    int closingbracket = -1;

    while (closingbracket == -1) {
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
            return -2;
        }
    }

    return closingbracket;
}

void newloop(const char* ribbon, int start, int end, char** stackptr)
{
    while (**stackptr) {
        printf("iter: ");
        for (int i = start+1; i < end; i++) {
            printf("%c", ribbon[i]);
            op(ribbon, i, stackptr);
        }
        printf(" (ptr: %d, ptr+1: %d)\n", **stackptr, *(*stackptr+1));
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
            // don't know if we need to do something here
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

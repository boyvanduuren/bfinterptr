//
// Created by boy on 7/28/15.
//

#ifndef BFINTRPTR_MAIN_H
#define BFINTRPTR_MAIN_H

#define RIBBON_SIZE 100000
#define STACK_SIZE 100000

int findclosingbracket(const char* ribbon, int pos);
void newloop(const char* ribbon, int start, int end, char** stackptr);
void op(const char* ribbon, int pos, char** stackptr);

#endif //BFINTRPTR_MAIN_H

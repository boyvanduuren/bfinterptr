//
// Created by boy on 7/28/15.
//

#ifndef BFINTRPTR_MAIN_H
#define BFINTRPTR_MAIN_H

#define STACK_SIZE 256

int findclosingbracket(const char *ribbon, int pos);
void newloop(const char *ribbon, int start, int end, char **stackptr);
void op(const char* ribbon, int pos, char** stackptr);

#endif //BFINTRPTR_MAIN_H

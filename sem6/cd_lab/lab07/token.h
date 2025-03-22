#ifndef TOKEN_H
#define TOKEN_H

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "findkeywords.h"

typedef struct token{
   char token_name[50];
   int row;
   int col;
   char type[20];
   int index;
} token;

void add_token(token *tt, int *tp, char *word, char *type, int r, int c);
int getnexttoken1(FILE *fp, token *tt, int *tp);


#endif

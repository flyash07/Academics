#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include <string.h>
#include <stdio.h>
#include "token.h"


#define TABLE_SIZE 100

typedef struct Symbol {
    int serial_number;
    char lex_name[50]; 
    char type[20];     
    int size;          
    int is_occupied;   
} Symbol;

typedef struct {
    char rettype[100];
    char name[100];
    Symbol table[TABLE_SIZE];
} SymbolTable;

extern SymbolTable main_symbol_table;
extern SymbolTable code[100];
extern int codecounter;

int search_symbol(SymbolTable *st, const char *lex_name);
int insert_symbol(SymbolTable *st, const char *lex_name, const char *type, int size);
int get_type_size(const char *type);
void symbol_table(token tt[], int tp);
void synctables(SymbolTable * st);

#endif

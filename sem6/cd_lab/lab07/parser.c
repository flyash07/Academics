#include <stdio.h>
#include "symbol_table.h"
#include "token.h"
#include "la.h"


SymbolTable * st;

void program();
void declarations();
void data_type();
void identifier_list();
void A();
void assign_stat();
void B();

void invalid(char * s) {
    printf("Error: %s\n",s);
    exit(0);
}

void valid() {
    printf("\n----------------SUCCESS!---------------\n");
    exit(0);
}

void program() {
    token tt;
    printf("Checking for 'main'\n");
    getnexttoken(&tt);
    if (strcmp(tt.token_name, "main") == 0) {
        printf("Matched 'main'\n");
        getnexttoken(&tt);
        if (tt.token_name[0] == '(') {
            printf("Matched '('\n");
            getnexttoken(&tt);
            if (tt.token_name[0]== ')') {
                printf("Matched ')'\n");
                getnexttoken(&tt);
                if (tt.token_name[0] == '{') {
                    printf("Matched '{'\n");
                    // declarations();
                    // printf("Returned\n");
                    // assign_stat();
                    getnexttoken(&tt);
                    if (tt.token_name[0] == '}') {
                        printf("Matched '}'\n");
                        return;
                    } else invalid("Expected }\n");
                }
                else invalid("Expected {\n");
            }
            else invalid("Expected )\n");
        }
        else invalid("Expected (\n");
    } else invalid("No main found");
}
void declarations() {
    token tt;
    getnexttoken(&tt);
    if (strcmp(tt.token_name, "int") == 0 || strcmp(tt.token_name,"char") == 0) {
        // data_type();
        // identifier_list();
        getnexttoken(&tt);
        if (tt.token_name[0] == ';') {
            printf("Matched ';' (End of declaration)\n");
            declarations();
        } else {
            invalid("Expected ;\n");
        }
    } else {
        printf("No more declarations (epsilon transition)\n");
    }
}

// void data_type() {
//     token tt;
//     getnexttoken(&tt);
//     if (strncmp(&str[cur], "int", 3) == 0 && !isalnum(str[cur + 3])) {
//         printf("Matched 'int'\n");
//     } else if (strncmp(&str[cur], "char", 4) == 0 && !isalnum(str[cur + 4])) {
//         printf("Matched 'char'\n");
//     } else {
//         invalid("Expected data-type\n");
//     }
// }

int main() {
    la();
    synctables(st);
    program();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int cur = 0;
// char str[100] = "main(){int a, b; char c; a=2;}$";
char str[100] = "main(){int a, b; char c; a=2;}$";


void program();
void declarations();
void data_type();
void identifier_list();
void A();
void assign_stat();
void B();




void data_type() {
    while(str[cur]== ' ') cur++;
    if (strncmp(&str[cur], "int", 3) == 0 && !isalnum(str[cur + 3])) {
        printf("Matched 'int'\n");
        cur += 3;
    } else if (strncmp(&str[cur], "char", 4) == 0 && !isalnum(str[cur + 4])) {
        printf("Matched 'char'\n");
        cur += 4;
    } else {
        invalid("Expected data-type\n");
    }
}

void identifier_list() {
    while(str[cur]== ' ') cur++;
    if (isalpha(str[cur])) {
        printf("Matched identifier: %c\n", str[cur]);
        while (isalnum(str[cur])) cur++;
        A();
    } else {
        invalid("Identifier should begin with lettter \n");
    }
}

void A() {
    while(str[cur]== ' ') cur++;
    if (str[cur] == ',') {
        printf("Matched ',' (More identifiers)\n");
        cur+=2;
        identifier_list();
    } else {
        printf("No more identifiers (epsilon transition)\n");
    }
}

void assign_stat() {
    while(str[cur]== ' ') cur++;
    if (isalpha(str[cur])) {
        printf("Matched identifier: %c\n", str[cur]);
        while (isalnum(str[cur])) cur++;  // Allow multi-character identifiers
        if (str[cur] == '=') {
            printf("Matched '=' (Assignment)\n");
            cur++;
            B();
        } else {
            invalid("Expected = before \n");
        }
    } else {
        invalid("Identifier should begin with lettter \n");
    }
}

void B() {
    while(str[cur]== ' ') cur++;
    if (isalpha(str[cur]) || isdigit(str[cur])) {
        printf("Matched value: %c\n", str[cur]);
        while (isalnum(str[cur])) cur++;  
        if (str[cur]==';') {
            cur++;
            return;
        } else
            invalid("Expected ;\n");
    } else {
        invalid("Invalid assignment, expected number/identifier on RHS\n");
    }
}

int main() {
    printf("Enter program\n");
    program();
    if (str[cur] == '$') {
        valid();
    } else {
        invalid("Parsing failed\n");
    }
}

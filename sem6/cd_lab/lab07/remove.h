#ifndef REMOVE_H
#define REMOVE_H


#include <stdio.h>


// Function to remove preprocessor directives
void removepdirective(FILE *fr, FILE *fw);


// Function to remove extra whitespaces and tabs, replacing them with a single space
void removewhitespaces(FILE *fr, FILE *fw);


// Function to remove comments from the file (supports single-line comments)
void removecomments(FILE *fr, FILE *fw);


#endif

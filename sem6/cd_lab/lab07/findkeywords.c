#include "findkeywords.h"
#include <string.h>


static const char *keywords[] = {
   "auto", "break", "case", "char", "continue", "do", "default", "const",
   "double", "else", "enum", "extern", "for", "if", "goto", "float", "int",
   "long", "register", "return", "signed", "static", "sizeof", "short",
   "struct", "switch", "typedef", "union", "void", "while", "volatile",
   "unsigned", "echo"
};


int isakeyword(const char *word) {
   for (int i = 0; i < 33; i++) {
       if (strcmp(word, keywords[i]) == 0) {
           return 1;
       }
   }
   return 0;
}

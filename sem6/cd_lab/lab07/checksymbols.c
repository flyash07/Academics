#include "checksymbols.h"

int checkspecialsymbols(char n, char next, token *t, int rn, int cn) {
   t->row = rn;
   t->col = cn;
   t->index = 0;

   // Multi-character operators
   if (n == '+' && next == '+') {
       strcpy(t->type, "increment_operator");
       strcpy(t->token_name, "++");
       return 2;
   }
   if (n == '-' && next == '-') {
       strcpy(t->type, "decrement_operator");
       strcpy(t->token_name, "--");
       return 2;
   }
   if (n == '=' && next == '=') {
       strcpy(t->type, "comparison_operator");
       strcpy(t->token_name, "==");
       return 2;
   }
   if (n == '!' && next == '=') {
       strcpy(t->type, "comparison_operator");
       strcpy(t->token_name, "!=");
       return 2;
   }
   if (n == '>' && next == '=') {
       strcpy(t->type, "comparison_operator");
       strcpy(t->token_name, ">=");
       return 2;
   }
   if (n == '<' && next == '=') {
       strcpy(t->type, "comparison_operator");
       strcpy(t->token_name, "<=");
       return 2;
   }
   if (n == '&' && next == '&') {
       strcpy(t->type, "logical_operator");
       strcpy(t->token_name, "&&");
       return 2;
   }
   if (n == '|' && next == '|') {
       strcpy(t->type, "logical_operator");
       strcpy(t->token_name, "||");
       return 2;
   }

   // Single-character operators
   if (n == '+' || n == '-' || n == '*' || n == '/' || n == '%') {
       strcpy(t->type, "math_operator");
       t->token_name[0] = n;
       t->token_name[1] = '\0';
       return 1;
   }
   if (n == '&' || n == '|' || n == '^' || n == '~') {
       strcpy(t->type, "bitwise_operator");
       t->token_name[0] = n;
       t->token_name[1] = '\0';
       return 1;
   }
   if (n == '=') {
       strcpy(t->type, "assignment_operator");
       t->token_name[0] = n;
       t->token_name[1] = '\0';
       return 1;
   }
   if (n == '?') {
       strcpy(t->type, "ternary_operator");
       t->token_name[0] = n;
       t->token_name[1] = '\0';
       return 1;
   }
   if (n == ':') {
       strcpy(t->type, "ternary_operator");
       t->token_name[0] = n;
       t->token_name[1] = '\0';
       return 1;
   }
   if (n == ',' || n == ';') {
       strcpy(t->type, "punctuation");
       t->token_name[0] = n;
       t->token_name[1] = '\0';
       return 1;
   }
   if (n == '{' || n == '}' || n == '(' || n == ')' || n == '[' || n == ']') {
       strcpy(t->type, "bracket");
       t->token_name[0] = n;
       t->token_name[1] = '\0';
       return 1;
   }
   if (n == '>' || n == '<') {
       strcpy(t->type, "comparison_operator");
       t->token_name[0] = n;
       t->token_name[1] = '\0';
       return 1;
   }

   // Not a special symbol
   return 0;
}


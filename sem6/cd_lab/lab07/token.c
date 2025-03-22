#include "token.h"

int rn = 0, cn = 0;

void add_token(token *tt, int *tp, char *word, char *type, int r, int c) {
   strcpy(tt[*tp].token_name,word);
   strcpy(tt[*tp].type,type);
   tt[*tp].row = r;
   tt[*tp].col = c;
   tt[*tp].index = *tp;
   (*tp)++;
}


int getnexttoken1(FILE *fp, token *tt, int *tp) {
   char word[50];
   int k = 0;
   char n, next;

   if (fread(&n, 1, 1, fp)) {
       if (n == '\n') {
            rn++;
            cn = 0;
            return 1;
       }


        if (isalpha(n)) {
            word[k++]=n;
            while (fread(&n, 1, 1, fp) && ((isalnum(n) || n=='_'))) {
                word[k++] = n;
            }

            fseek(fp, -1, SEEK_CUR);
            cn=cn+k;
            word[k] = '\0';
            if (isakeyword(word)) {
                add_token(tt, tp, word, "keyword", rn, cn - k);
                return 1;
            } else {
                add_token(tt, tp, word, "identifier", rn, cn - k);
                return 1;
            }

        }


       if (n == '"') {
           word[k++] = n;
           while (fread(&n, 1, 1, fp) && n != '"') {
               word[k++] = n;
           }
           word[k++] = '"';
           cn=cn+k;
           word[k] = '\0';
           add_token(tt, tp, word, "literal string", rn, cn - k);
           k = 0;
           return 1;
       } 
       if (n == '\'') {
            word[k++] = n;
            while (fread(&n, 1, 1, fp) && n != '\'') {
                word[k++] = n;
            }
            word[k++] = '\'';
            cn=cn+k;
            word[k] = '\0';
            add_token(tt, tp, word, "literal string", rn, cn - k);
            k = 0;
            return 1;
        }

        if(isdigit(n) ) {
            word[k++] = n;
            while (fread(&n, 1, 1, fp) && isdigit(n)) {
                word[k++] = n;
            }
            fseek(fp, -1, SEEK_CUR);
            cn=cn+k;
            word[k] = '\0';
            add_token(tt, tp, word, "number", rn, cn - k);
            return 1;
        }
        token t;

        if (fread(&next, 1, 1, fp)) {
            int result = checkspecialsymbols(n, next, &t, rn, cn);
            if (result == 2) { 
                add_token(tt, tp, t.token_name, t.type, rn, cn);
                printf("tw%s", t.token_name);
                cn+=2;
                return 1;
            } else if (result == 1) {
                add_token(tt, tp, t.token_name, t.type, rn, cn);
                cn++;
                fseek(fp, -1, SEEK_CUR);
                return 1;
            } else {
                cn++;
                fseek(fp, -1, SEEK_CUR);
                return 1;
            }
        } else {
            //if no next is there
            if (checkspecialsymbols(n, '\0', &t, rn, cn)) {
                add_token(tt, tp, t.token_name, t.type, rn, cn);
                return -1;
            }
        }
       
   }

   return -1;
}



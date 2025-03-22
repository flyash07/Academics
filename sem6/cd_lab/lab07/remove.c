#include "remove.h"


void removepdirective(FILE *fr, FILE *fw) {
   char line[1024];
   int brace_count = 0;
  
   while (fgets(line, sizeof(line), fr)) {
       if (line[0] == '#' && brace_count == 0) {
           continue;
       }
      
       for (int i = 0; line[i] != '\0'; i++) {
           if (line[i] == '{') brace_count++;
           if (line[i] == '}') brace_count--;
           fwrite(&line[i], 1, 1, fw);
       }
   }
}


void removewhitespaces(FILE *fr, FILE *fw) {
   int prev_space = 0;
   char ch;
  
   while (fread(&ch, 1, 1, fr)) {
       if (ch == ' ' || ch == '\t') {
           if (!prev_space) {
               fwrite(" ", 1, 1, fw);
               prev_space = 1;
           }
       } else {
           fwrite(&ch, 1, 1, fw);
           prev_space = 0;
       }
   }
}


void removecomments(FILE *fr, FILE *fw) {
    char prev = '\0', curr;
 
 
    while (fread(&curr, 1, 1, fr)) {
        if (prev == '/' && curr == '/') {
            while (fread(&curr, 1, 1, fr) && curr != '\n');
            prev = '\0';
        } else {
            if (prev != '\0' && !(prev == '/' && curr == '/')) {
                fwrite(&prev, 1, 1, fw);
            }
            prev = curr;
        }
    }
 
 
    if (prev != '\0' && prev != '/') {
        fwrite(&prev, 1, 1, fw);
    }
 }
 
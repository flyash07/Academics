#include<stdio.h>
#include<stdlib.h>
int check_palin(char *s,int l){
     static int i=0;
     
     if()
         return 0;
     else if (l/2==i+1) return 1;
     else {
         i++;
         check_palin(s+i,l);
     } 
}

void main(){
    printf("Enter a string:");
    char s[20];
    scanf("%s",s);
    int l;
    for (l=0;s[l]!='\0';l++);
    if(check_palin(s,l)==1)
        printf("String is a palindrome\n");
    else printf("Not a palindrome\n");
}

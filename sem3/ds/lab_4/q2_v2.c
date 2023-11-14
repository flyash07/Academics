#include<stdio.h>
void copystr(char *s1,char *s2)
{
    if(*s1=='\0')
    {
      *s2='\0';
      return;
      }
      
      *s2=*s1;
      s2++;
      s1++;
      copystr(s1,s2);
      
}
void main(){
    printf("Enter a string:");
    char s1[10],s2[10];
    scanf("%s",s1);
    printf("%s",s1);
    copystr(s1,s2);
    printf("Copied string is:");
    printf("%s",s2);
    printf("\n");
}

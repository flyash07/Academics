#include<stdio.h>
void copystr(char *s1,char *s2)
{
    static int i=0;
    if(*(s1+i)=='\0'){
	   *(s2+i)='\0';
	    return;
}
    else {
	    *(s2+i)=*(s1+i);
	    i=i+1;
	    printf("%d\n",i);
	    printf("%c ",*(s1+i));
	    copystr((s1+i),(s2+i));
	  }
}
void main(){
    printf("Enter a string:");
    char s1[10],s2[10];
    scanf("%s",s1);
    copystr(s1,s2);
    printf("Copied string is:");
    printf("%s\n",s2);
}

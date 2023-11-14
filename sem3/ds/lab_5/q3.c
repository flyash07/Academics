#include<stdio.h>
#include<stdlib.h>
int tos=-1;
void push(char t,char *s){
                // tos++;
                *(s+(++tos))=t;
		// printf("Pushed\n");
		return;
}
char pop(char *s){
	        // tos--;
	        return *(s+(--tos)+1);
}
int check_palin(char *a,int l,char *s){
    int i;
    for(i=0;i!=l/2;i++){
        push(*a,s);
        a++;
    }
    // printf("%d\n",i);
    if(l%2==1)
        a++;
    for(i=l/2+1;i<l;i++)
        if(pop(s)!=*(a++)) return 0;
    return 1;
}

int main(){
    char *s;
    s=(char *)malloc(20*sizeof(char));
    printf("Enter a string:");
    char a[20];
    scanf("%s",a);
    int l;
    for (l=0;a[l]!='\0';l++);
    // printf("%d",l);
    if(check_palin(a,l,s)==1)
        printf("String is a palindrome\n");
    else printf("Not a palindrome\n");
    free(s);
    return 0;
}

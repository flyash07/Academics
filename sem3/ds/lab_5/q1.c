#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int tos;
	char c[20];
}STACK;
int isEmpty(STACK *s){
	if (s->tos==-1)
		return 1;
	else return 0;
}
int isFull(STACK *s){
	if (s->tos==20-1)
		return 1;
        else return 0;
}
void push(STACK *s,char t){
	if(isFull(s)){
		printf("stack overflow\n");
		return;
	}
	else{
		(s->tos)++;
		s->c[s->tos]=t;
		printf("Pushed\n");
		return;
        }
}
char pop(STACK *s){
	if(isEmpty(s)){
		printf("stack underflow\n");
		return '\0';
	}
	else {
	        (s->tos)--;
	        return s->c[s->tos+1];
	}
}
void display(STACK *s){
        for(int i=0;i<=(s->tos);i++)
             printf("%c\t",*((s->c)+i));
        printf("\n");
}
int main(){
	STACK *s;
	s=(STACK *)malloc(sizeof(STACK));
	s->tos=-1;
	int a;
	char t,dummy;
	while(1){
		printf("1.Push   2.Pop  3.Display  4.Exit\n");
		printf("Enter choice:");
		scanf("%d",&a);
		scanf("%c",&dummy);
		
		if(a==1){
			printf("Enter character:");
			scanf("%c",&t);
			push(s,t);
		}
		else if(a==2){
		        t=pop(s);
		        if (t!='\0')
		  	     printf("Popped character is %c\n",t);
		}
		else if(a==3)  display(s);
		else exit(0);
	}
	return 0;
}

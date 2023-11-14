//program to convert infix to prefix
#include <stdio.h>
#include <stdlib.h>

char stack[100];
int top = -1;

int precedence(char operator)
{
    switch (operator) {
    case '+': 
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}


void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char * convert(char * in,int l ){
   //1.reverse

   char *pre=(char *)malloc(30*sizeof(char));
   char temp;int i,j;
   for(i=0;i<l/2;i++){
      temp=*(in+i);
      *(in+i)=*(in+l-i-1);
      *(in+l-i-1)=temp;  
   }
   
   //2.interchange ( and )
   for(i=0;i<l;i++){
      if(*(in+i)=='(')  *(in+i)=')';
      else if(*(in+i)==')')  *(in+i)='(';
   }

   //3.covert to postfix

   for(i=0,j=0;i<l;i++){
    if((*(in+i)-'0'>=0)&&(*(in+i)-'0'<=9)){
        *(pre+j)=*(in+i);
        j++;
    }
    else if (in[i] == '(') {
            push(*(in+i));
    }
    else if (in[i] == ')') {
            while (top > -1 && stack[top] != '(')
                pre[j++] = pop();
    }
    else {
            while (top > -1 && precedence(stack[top])>= precedence(in[i]))
                pre[j++] = pop();
            push(*(in+i));
    }

   }
   while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        pre[j++] = pop();
    }
   *(pre+j+1)='\0';
   
   //4.reverse
   for(i=0;i<(j+1)/2;i++){ 
       temp=*(pre+i);
      *(pre+i)=*(pre+j-i-1);
      *(pre+j-i-1)=temp;  
   }
   return pre;

}

int main()
{
   printf("Enter a infix exp:");
   char in[30];
   int result = 0;
   scanf("%s", in);
   char *pre=(char *)malloc(30*sizeof(char)); //char arr to store prefix
   int l;
   for (l = 0; in[l] != '\0'; l++); //length of exp
   pre= convert(in,l);
   printf("Postfix expression is:%s\n",pre);
   free(pre);
   return 0;
}

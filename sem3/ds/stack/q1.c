//program to evaluate prefix exp
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   int data[30];
   int top;
} stack;

int evaluate(char x, int op1, int op2)
{
   if (x == '+')
      return (op1 + op2);
   if (x == '-')
      return (op1 - op2);
   if (x == '*')
      return (op1 * op2);
   if (x == '/')
      return (op1 / op2);
   if (x == '%')
      return (op1 % op2);
}

void init(stack *s)
{
   s->top = -1;
}

int empty(stack *s)
{
   if (s->top == -1)
      return (1);
   return 0;
}

int full(stack *s)
{
   if (s->top == 29)
      return (1);
   return (0);
}

void push(stack *s, int x)
{
   s->top = s->top + 1;
   s->data[s->top] = x;
}

int pop(stack *s)
{
   int x;
   x = s->data[s->top];
   s->top = s->top - 1;
   return (x);
}

int main()
{
   printf("Enter a prefix exp:");
   char e[30];
   int result = 0;
   scanf("%s", e);
   stack *s = (stack *)malloc(sizeof(stack));
   init(s);
   int l, x, y;
   for (l = 0; e[l] != '\0'; l++)
      ;
   for (int i = l - 1; i >= 0; i--)
   {
      if ((e[i] - '0' >= 0) && (e[i] - '0' <= 9))

         push(s, e[i] - '0');
      else
      {
         x = pop(s);
         y = pop(s);
         push(s, evaluate(e[i], x, y));
      }
   }
   printf("Answer is:%d\n", pop(s));
   free(s);
   return 0;
}

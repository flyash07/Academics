#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int tos;
    int *a;
} stack;
int len;
int isEmpty(stack *s)
{
    if (s->tos == -1)
        return 1;
    else
        return 0;
}
int isFull(stack *s)
{
    if (s->tos == len - 1)
        return 1;
    else
        return 0;
}
void push(stack *s, int t)
{
    if (isFull(s))
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        s->a[++(s->tos)] = t;
        return;
    }
}
char pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("stack underflow\n");
        return '\0';
    }
    else
    {
        return s->a[s->tos--];
    }
}
void enqueue(stack *si, stack *so)
{
    int t;
    printf("Enter element to enqueue:");
    scanf("%d", &t);
    push(si, t);
}
int dequeue(stack *si, stack *so)
{
    for (; (si->tos) != 0;)
    {
        push(so, pop(si));
    }
    int t = pop(si);
    for (; (so->tos) != -1;)
    {
        push(si, pop(so));
    }
    return t;
}
void display(stack *si)
{
    for (int i = 0; i <= si->tos; i++)
    {
        printf("%d  ", si->a[i]);
    }
    printf("\n");
}
int main()
{
    stack si, so;
    si.tos = so.tos = -1;
    printf("Enter length of queue:");
    scanf("%d", &len);
    si.a = (int *)malloc(len * sizeof(int));
    so.a = (int *)malloc(len * sizeof(int));
    while (1)
    {
        int a;
        printf("1.Enqueue  2.Dequeue  3.Display  4.Exit  :");
        scanf("%d", &a);
        if (a == 1)
            enqueue(&si, &so);
        else if (a == 2)
            printf("Dequeued elemnt:%d\n", dequeue(&si, &so));
        else if (a == 3)
            display(&si);
        else
        {
            free(si.a);
            free(so.a);
            exit(0);
        }
    }
}
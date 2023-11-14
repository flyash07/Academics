#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int f;
    int r;
    int size;
    int arr[50];
} Cqueue;
Cqueue q;
int isEmpty()
{
    if (q.f == q.r)
        return 1;
    else
        return 0;
}
int isFull()
{
    if ((q.r + 1) % q.size == q.f)
        return 1;
    else
        return 0;
}

void enqueue(int x)
{
    if (isFull())
        printf("Queue is full\n");
    else
    {
        q.r = (q.r + 1) % q.size;
        q.arr[q.r] = x;
    }
}

int dequeue()
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -999;
    }
    else
    {
        q.f = (q.f + 1) % q.size;
        return q.arr[q.f];
    }
}

void displaycq()
{
    printf("Displaying queue\n");
    int i = q.f;
    while (i != q.r)
    {
        i = (i + 1) % q.size;
        printf("%d  ", q.arr[i]);
    }
    printf("\n");
}

void reverse()
{
    if (isEmpty())
    {
        return;
    }
    int t = dequeue();
    reverse();
    enqueue(t);
}

int main()
{
    int i, c;
    q.f = q.r = 0;
    printf("Enter the size of queue:");
    scanf("%d", &q.size);
    (q.size)++;
    for (i = 0; i < q.size - 1; i++)
    {
        printf("Enter element:");
        scanf("%d", &c);
        enqueue(c);
    }
    printf("Queue before reversing:\n");
    displaycq();
    reverse();
    printf("Queue after reversing:\n");
    displaycq();
}

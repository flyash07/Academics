#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int f;
    int r;
    int size;
} Cqueue;

int *arr;
int N;

int isEmpty(Cqueue *q)
{
    if (q->f == q->r)
        return 1;
    else
        return 0;
}

int isFull(Cqueue *q)
{
    if (((q->r + 1) % q->size == q->f)||((q->r + 1) % q->size+N/2+1 == q->f))
        return 1;
    else
        return 0;
}

void insertcq(Cqueue *q1, Cqueue *q2)
{
    printf("Choose q1 or q2:");
    int t;
    scanf("%d", &t);
    if (t == 1)
    {
        if (isFull(q1))
            printf("Queue is full\n");
        else
        {
            q1->r = (q1->r + 1) % q1->size;
            printf("Enter element to enqueue:");
            scanf("%d", arr + q1->r);
            printf("Enqueued\n");
        }
    }
    else
    {
        if (isFull(q2))
            printf("Queue is full\n");
        else
        {
            q2->r = (q2->r + 1) % q2->size + N / 2+1;
            printf("Enter element to enqueue:");
            scanf("%d", arr + q2->r);
            printf("Enqueued\n");
        }
    }
    
}

int deletecq(Cqueue *q1,Cqueue *q2)
{
    printf("Choose q1 or q2:");
    int t;
    scanf("%d", &t);
    if(t==1){
        if (isEmpty(q1))
        printf("Queue is empty\n");
        else
        {
        q1->f = (q1->f + 1) % q1->size;
        return arr[q1->f];
        }
    
    }
    else{
        if (isEmpty(q2))
        printf("Queue is empty\n");
        else
        {
        q2->f = (q2->f + 1) % q2->size+N/2+1;
        return arr[q2->f];
        }
    
    }
    
}

void displaycq(Cqueue *q1, Cqueue *q2)
{
    printf("Displaying q1\n");
    int i = q1->f;
    while (i != q1->r)
    {
        i = (i + 1) % q1->size;
        printf("%d  ", arr[i]);
    }
    printf("\nDisplaying q2\n");
    i=q2->f;
    while (i != q2->r)
    {
        i = (i + 1) % q2->size+N/2+1;
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main()
{
    Cqueue q1, q2;
    printf("Enter the size of array:");
    scanf("%d", &N);
    q1.size = N / 2 + 1;
    q2.size = N - N / 2 + 1;
    q1.f = q1.r = 0; 
    q2.f = q2.r = N / 2 + 2;
    arr = (int *)malloc(N * sizeof(int));
    while (1)
    {
        int c;
        printf("1.Enqueue    2.Dequeue   3.Display    4.Exit  :");
        scanf("%d", &c);
        if (c == 1)
            insertcq(&q1, &q2);
        else if (c == 2)
            printf("Dequeued element is :%d\n", deletecq(&q1,&q2));
        else if (c == 3)
            displaycq(&q1, &q2);
        else
            exit(0);
    }
}

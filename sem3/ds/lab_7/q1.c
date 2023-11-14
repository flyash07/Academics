#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int f;
    int r;
    int size;
    char **arr;
} Cqueue;

int isEmpty(Cqueue *q)
{
    if (q->f == q->r)
        return 1;
    else
        return 0;
}

int isFull(Cqueue *q)
{
    if ((q->r + 1) % q->size == q->f)
        return 1;
    else
        return 0;
}

void insertcq(Cqueue *q)
{
    if (isFull(q))
        printf("Queue is full\n");
    else
    {
        q->r = (q->r + 1) % q->size;
        printf("Enter a string to enqueue:");
        scanf("%s", q->arr[q->r]);
        printf("Enqueued %s\n", (q->arr[q->r]));
    }
}

char *deletecq(Cqueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        return q->arr[q->f];
    }
}

void displaycq(Cqueue *q)
{
    printf("Displaying queue\n");
    int i = q->f;
    while (i != q->r)
    {
        i = (i + 1) % q->size;
        printf("%s  ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    Cqueue *q = (Cqueue *)malloc(sizeof(Cqueue));
    q->f = q->r = 0;
    printf("Enter the size of queue:");
    scanf("%d", &q->size);
    (q->size)++;
    q->arr = (char **)malloc(q->size * sizeof(char *));
    for (int i = 0; i < q->size; i++)
    {
        *(q->arr + i) = (char *)malloc(30 * sizeof(char));
    }
    while (1)
    {
        int c;
        printf("1.Enqueue    2.Dequeue   3.Display    4.Exit  :");
        scanf("%d", &c);
        if (c == 1)
            insertcq(q);
        else if (c == 2)
        {
            printf("Dequeued element is :%s\n", deletecq(q));
        }
        else if (c == 3)
            displaycq(q);
        else
        {
            for (int i = 0; i < q->size; i++)
            {
                free(q->arr[i]);
            }
            free(q->arr);
            free(q);
            exit(0);
        }
    }
}

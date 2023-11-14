#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *reverse(struct node *head)
{
    struct node *p, *q;
    p = NULL;
    while (head)
    {
        q = p;
        p = head;
        head = head->link;
        p->link = q;
    }
    return p;
}
int main()
{
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    first->data = 7;
    second->data = 20;
    third->data = 37;
    fourth->data = 50;
    first->link = second;
    second->link = third;
    third->link = fourth;
    fourth->link = NULL;
    first = reverse(first);
    struct node *ptr = first;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }
}
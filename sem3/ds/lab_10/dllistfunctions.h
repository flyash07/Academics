#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;

} node;

void display(node *ptr) {
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void insertnode(int x,node * head) {
  node * ptr=head;
  while(ptr->next!=head)  ptr=ptr->next;
  node *t = (node *)malloc(sizeof(node));
  t->data = x;
  t->next = head;
  t->prev = ptr;
  ptr->next = t;
}
/*
void deletenode(node *ptr) {

  ptr->prev->next = ptr->next;
  ptr->next->prev = ptr->prev;
  free(ptr);
}
*/
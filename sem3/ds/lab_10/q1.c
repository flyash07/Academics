#include "dllistfunctions.h"

node *init(node *ptr, int t) {
  printf("Inside init\n");
  //node *ptr1 = malloc(sizeof(node));
  ptr->data = t;
  ptr->next = NULL;
  ptr->prev = NULL;
  return ptr;
}

void insertRight(node *ptr, int t) {
  if (ptr->data == -999) {
    ptr = init(ptr, t);
    return;
  }
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  node *newnode = (node *)malloc(sizeof(node));
  newnode->data = t;
  newnode->next = NULL;
  newnode->prev = ptr;
  ptr->next = newnode;
}
node *insertLeft(node *ptr, int t) {
  if (ptr->data == -999) {
    return init(ptr, t);
  }
  node *newnode = malloc(sizeof(node));
  newnode->data = t;
  printf("data inserted\n");
  newnode->prev = NULL;
  newnode->next = ptr;
  ptr->prev = newnode;
  return newnode;
}
node *deleteLeft(node *ptr) {
  node *temp = ptr->next;
  ptr->next->prev = NULL;
  printf("Deleted element is %d\n",ptr->data);
  free(ptr);
  return temp;
}

void deleteRight(node *ptr) {
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->prev->next = NULL;
  printf("Deleted element is %d\n",ptr->data);
  free(ptr);
}

int main() {
  int n, inp;
  node *dlist = (node *)malloc(sizeof(node));
  dlist->data=-999;
  printf("Enter length of list:");
  scanf("%d", &n);
  printf("1. insert left  2.insert right  3.delete left  4.delete right  "
         "5.display  6.exit");
  while (1) {
    printf("Choice:");
    scanf("%d", &inp);
    if (inp == 1) {
      printf("Enter value:");
      scanf("%d", &inp);
      dlist = insertLeft(dlist, inp);
      printf("inserted %d\n",dlist->data);

    } else if (inp == 2) {
      printf("Enter value:");
      scanf("%d", &inp);
      insertRight(dlist, inp);

    } else if (inp == 3) {
      dlist = deleteLeft(dlist);
    } else if (inp == 4) {
      deleteRight(dlist);
    } else if (inp == 5) {
      display(dlist);
    } else
      exit(0);
  }
}


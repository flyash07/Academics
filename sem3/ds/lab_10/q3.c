#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char * data;
  struct node *prev;
  struct node *next;

} node;
char dummy;

void insertnode( node * head){

    while(head->next!=NULL) head=head->next;
    node * newnode=(node *)malloc(sizeof(node));
    (newnode->data)=(char *)malloc(30*sizeof(char));
    printf("Enter a word:");
    //scanf("%c",&dummy);
    scanf("%s",(newnode->data));
    newnode->next=NULL;
    newnode->prev=head;
    head->next=newnode;
}

node * reverse(node * head){

    node * temp,*temp1;
    while(head->next!=NULL){
        temp=head->next;
        head->next=head->prev;
        head->prev=temp;
        head=head->prev;
    }
    temp1=head;
    temp=head->next;
    head->next=head->prev;
    head->prev=temp;
    return temp1;    
}

void display(node * head){
    while(head!=NULL){
        printf("%s  ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    node * head = (node *) malloc(sizeof(node));
    head->data = (char *) malloc(30*sizeof(char));
    printf("Enter a word:");
    scanf("%s",head->data);
    insertnode(head);
    insertnode(head);
    insertnode(head);
    insertnode(head);
    display(head);
    head=reverse(head);
    display(head);
}
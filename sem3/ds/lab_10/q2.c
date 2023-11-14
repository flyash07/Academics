#include "dllistfunctions.h"
node * create_node(){
    node *n=(node *)malloc(sizeof(node));
    n->prev=n->next=NULL;
    return n;
}

node * add(node * a , node * b){
    node * h1=a;
    node * h2=b;
    a=a->next;b=b->next;
    node * s=(node *)malloc(sizeof(node));
    node * s1=create_node();
    //node *s2 =s1;
    int t,c=0;
    t=a->data+b->data;
    c=t/10;
    s->data=t%10;
    s->next=s->prev=s1;
    s1->prev=s1->next=s; 
    while(a!=h1 && b!=h2){
        t=a->data+b->data+c;
        c=t/10;
        insertnode(t%10,s1);
        a=a->next;
        b=b->next;
    }
    while(a!=h1){
        insertnode(a->data+c,s1);
        c=0;
        a=a->next;
    }
    while(b!=h2){
        insertnode(b->data+c,s1);
        c=0;
        b=b->next;
    }
    if (c){
        insertnode(c,s1);
    }
    return s1;
}




node * create_dll(long int x){
    node * n=create_node();
    node * i1=(node *)malloc(sizeof(node));
    i1->data=x%10;
    x=x/10;
    i1->prev=i1->next=n;
    n->next=n->prev=i1;   
    while(x!=0){
        insertnode(x%10,n);
        x/=10;
    }
    return n;
}

void display_rec(node * s,node * head){
    if(s==head)  return;
    else{
        int t=s->data;
        display_rec(s->next,head);
        printf("%d ",t);
    }
}

int main(){
    long int a,b;
    printf("Enter the first long int:");
    scanf("%ld",&a);
    node * al =create_dll(a);
    printf("Enter the second long int:");
    scanf("%ld",&b);
    node * bl= create_dll(b);
    printf("Accepted\n");
    display_rec(al->next,al);
    printf("\n");
    display_rec(bl->next,bl);
    printf("\n");
    node *sum=add(al,bl);
    printf("\n");
    display_rec(sum->next->next,sum);
    printf("\n");
}
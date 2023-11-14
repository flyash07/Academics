#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node * lchild;
    int data;
    struct node * rchild;
}node;

int count=0;

void inorder(node * root){
    if(root){
        inorder(root->lchild);
        count++;
        if(root->data==s){
            return;
        }
        inorder(root->rchild);
        count++;
    }
}

inorderprint(node * root){
    inorderprint(root->lchild);
    count--;
    if (count==0){
        printf("Successor is:%d",root->data);
        return;
    }
    inorderprint(root->rchild);
    count--;


}

node * in_successorfin(node * root,int s){
    inorder(root);
    if(root->lchild){
        inorderprint(root->lchild);
    }
    else
        inorderprint(root->rchild);

}




int main(){
    return 0;
}
#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node * getnode(){
	return (node*)malloc(sizeof(node));
}

void createbst(int n,node *root){
	node * prev=root;
	while(root){
		if(n>root->data){
			prev=root;
			root=root->right;
		}
		else if(n<root->data){
			prev=root;
			root=root->left;
		}
		else{
			printf("Cant add\n");
			return ;
		}
	}
	node * n1=getnode();
	n1->data=n;
	n1->right=n1->left=NULL;
	if(prev->data>n)
		prev->left=n1;
	else
		prev->right=n1;

}

void inorder(node * root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void find_ances(int n,int * arr,int *k,node *root){
	while(root){
		if(n>root->data){
			arr[(*k)++]=root->data;
			root=root->right;
		}
		else if(n<root->data){
			arr[(*k)++]=root->data;
			root=root->left;
		}
		else{
			arr[(*k)++]=root->data;
			return ;
		}
	}
}

int find_common(int *a, int *b, int *p,int *q){
	for(int i=*p-1;i>=0;i--){
		for(int j=*p-1;j>=0;j--){
			if(a[i]==b[j])
				return a[i];
		}
	}
	return -1;
}

int main(){	

	int n,x,y,p=0,q=0;
	int arr1[50];
	int arr2[50];
	node * root=getnode();
	printf("Enter no.of nodes:");
	scanf("%d",&n);
	printf("Enter root node:");
	scanf("%d",&(root->data));
	for(int i=1;i<n;i++){
		printf("Enter:");
		scanf("%d",&x);
		createbst(x,root);
	}
	inorder(root);
	printf("\n");
	printf("Enter node 1 val:");
	scanf("%d",&x);
	printf("Enter node 2 val:");
	scanf("%d",&y);
	find_ances(x,arr1,&p,root);
	find_ances(y,arr2,&q,root);
	printf("Ancestors node 1:\n");
    for(int i=0;i<p;i++)
    	printf("%d ",arr1[i]);
    printf("\n");
	printf("Ancestors node 2:\n");
    for(int i=0;i<q;i++)
    	printf("%d ",arr2[i]);
    printf("\n");

    printf("Common ancestor is:%d\n",find_common(arr1,arr2,&p,&q));


}
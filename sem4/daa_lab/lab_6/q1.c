#include<stdio.h>
#include<stdlib.h>
int opcount=0;
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

// createbt(node * root,)
int counter(node * root){
	int x;
	opcount++;
	static int ct=0;
	if(root){
		x=counter(root->left);
		ct++;
		x=counter(root->right);
	}
	return ct;
}

void inorder(node * root){
	
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int main(){	

	int x;
	node * root=getnode();

	// createbt(root);
	printf("Enter root node:");
	scanf("%d",&(root->data));
	while(1){
		printf("Enter:");
		scanf("%d",&x);
		if(x==-1) break;
		createbst(x,root);
	}
	printf("Number of nodes: %d\n", counter(root));
	printf("inorder taversal -> ");
	inorder(root);
	printf("\n");
	printf("Opcount is- %d\n",opcount);
}
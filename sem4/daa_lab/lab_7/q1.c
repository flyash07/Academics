#include<stdio.h>
#include<stdlib.h>


int a[100];
typedef struct node{
	int data;
	int bf;
	struct node *left;
	struct node *right;
}node;

int max(int a, int b){
	return (a>b?a:b);
}

int height(node * root){
	if(!root){
		return 0;
	}
	else{
		return 1+max(height(root->left),height(root->right));
	}
}

void calc_bal (node * root){
	int lefthgt=height(root->left);
	int righthgt=height(root->right);
    int bf = lefthgt-righthgt;
    root->bf=bf;
}

node* rightRotate(node* y){  
    node * x = y->left;  
    node * T2 = x->right;  
   
    x->right = y;  
    y->left = T2;  
   
    return x;  
}  
   
node* leftRotate(node* x){  
    node* y = x->right;  
    node* T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
      
    return y;  
}

node * getnode(){
	return (node*)malloc(sizeof(node));
}

node * createbst_avl(node *root,int n){

    if (root == NULL){
    	node * n1=getnode();
		n1->data=n;
		n1->right=n1->left=NULL;
		return n1;
    }
   
    if (n < root->data)  
        root->left  = createbst_avl(root->left, n);  
    else if (n > root->data)  
        root->right = createbst_avl(root->right,n);  
	

	calc_bal(root);
	  
   
	if(root->bf> 1 && n < root->left->data){  
            return rightRotate(root);  
        }  
    if(root->bf<-1 && n > root->right->data){  
            return leftRotate(root);  
        }   
    if(root->bf> 1 && n > root->left->data){  
            root->left = leftRotate(root->left);  
            return rightRotate(root);  
        }  
    if(root->bf< -1 && n < root->right->data){  
            root->right = rightRotate(root->right);  
            return leftRotate(root);  
        }  
    return root;
}  


void preorder(node * root){
	if(root){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node * root){
	
	if(root){
		inorder(root->left);
		a[count++]=root->data;
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int main(){
	int n,x;
	node * root=getnode();
	printf("Enter no.of nodes:");
	scanf("%d",&n);
	printf("Enter root node:");
	scanf("%d",&(root->data));
	for(int i=1;i<n;i++){
		printf("Enter:");
		scanf("%d",&x);
		root=createbst_avl(root,x);
	}
	printf("Tree\n");
	preorder(root);
}
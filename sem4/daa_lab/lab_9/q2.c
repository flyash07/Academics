#include<stdio.h>
#include<stdlib.h>
int success=0;
int notsuccess=0;
typedef struct node{
	int data;
	struct node * next;
}node;

node * getnode(){
	return (node *)malloc(sizeof(node));
}
void add(node ** arr,int m,node * val){
	if(arr[m]==NULL){
		arr[m]=val;
		return;
	}
	node * root=arr[m];
	while(root->next)
		root=root->next;
	root->next=val;
}

void displayhash(node ** arr,int m){
	for(int i=0;i<m;i++){
		node * root=arr[i];
		while(root){
			printf("%d->",root->data);
			root=root->next;
		}
		printf("NULL\n");
	}
}

void search(int x,node ** arr,int m){
	if(arr[x%m]){
		node * root=arr[x%m];
		while(root){
			if(root->data==x){
				success++;
				return;
			}
			root=root->next;
			notsuccess++;
		}
	}
	notsuccess++;

}

int main(){
	int n,m,x;
	printf("Enter size:");
	scanf("%d",&n);
	printf("Enter m value:");
	scanf("%d",&m);
	node ** a=(node **)malloc(m*sizeof(node *));
	for(int i=0;i<n;i++){
		node * n1=getnode();
		scanf("%d",&(n1->data));
		add(a,(n1->data)%m,n1);
	}
	printf("Hash created-\n");
	displayhash(a,m);
	printf("Enter element to search:");
	scanf("%d",&x);
	search(x,a,m);
	printf("Successful search :%d\n",success);
	printf("Unsuccessful search :%d\n",notsuccess);
}


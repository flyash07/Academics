#include<stdio.h>
#include<stdlib.h>
void display(int **,int, int);
void product(int **,int **, int , int, int, int);
int main(){
	int m,n,p,q,i,j,**a,**b;
	printf("Enter the dimensions of matrix A:");
	scanf("%d%d",&m,&n);
	printf("Enter the dimensions of matrix B:");
	scanf("%d%d",&p,&q);
	
	a=(int **)calloc(m,sizeof(int*));
	if(a==NULL) exit(0);
	for(i=0;i<m;i++){
	    *(a+i)=(int *) calloc(n,sizeof(int));
	    if (*(a+i)==NULL) exit(0);
	}
	printf("Enter the elements of the matrix A:");
	for(i=0;i<m;i++){
	    for(j=0;j<n;j++)
	        scanf("%d",(*(a+i)+j));
	}
	
	
	b=(int **)calloc(p,sizeof(int*));
	if(b==NULL) exit(0);
	for(i=0;i<p;i++){
	    *(b+i)=(int *) calloc(q,sizeof(int));
	    if (*(b+i)==NULL) exit(0);
	}
	printf("Enter the elements of the matrix B:");
	for(i=0;i<p;i++){
	    for(j=0;j<q;j++)
	        scanf("%d",(*(b+i)+j));
	}
	printf("Matrix A:\n");
	display(a,m,n);
	printf("Matrix B:\n");
	display(b,p,q);
	if (n!=p){
	   printf("Matrix multiplication not possible\n");
	   return 0;
	}
	product(a,b,m,n,p,q);
	free(a);
	free(b);
	return 0;

}
void display( int **a,int m, int n){
	int i,j;
        for (int i=0;i<m;i++){
             for (int j=0;j<n;j++)
                  printf("%d\t",*(*(a+i)+j));
             printf("\n");
             }
}

void product(int **a,int **b, int m, int n, int p, int q){
	int i,j,k,**c;
	c=(int **)calloc(m,sizeof(int*));
	if(c==NULL) exit(0);
	for(i=0;i<m;i++){
	    *(c+i)=(int *) calloc(q,sizeof(int));
	    if (*(c+i)==NULL) exit(0);
	}
	for(i=0;i<m;i++){
		for(j=0;j<q;j++)
			for (k=0;k<n;k++)
			*(*(c+i)+j)+=(*(*(a+i)+k))*(*(*(b+k)+j));
		    
	}
	printf("Product matrix:\n");
	display(c,m,q);
	free(c);
}

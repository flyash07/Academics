#include<stdio.h>
void display(int [][50],int, int);
void product(int [][50],int [][50], int , int, int, int);
int main(){
	int m,n,p,q,i,j,a[50][50],b[50][50];
	printf("Enter the dimensions of matrix A:");
	scanf("%d%d",&m,&n);
	printf("Enter the dimensions of matrix B:");
	scanf("%d%d",&p,&q);
	if (n!=p){
	   printf("Matrix multiplication not possible\n");
	   return 0;
	}
	printf("Enter the elements of the matrix A:");
	for(i=0;i<m;i++){
	    for(j=0;j<n;j++)
	        scanf("%d",&a[i][j]);
	}
	printf("Enter the elements of the matrix B:");
	for(i=0;i<p;i++){
	    for(j=0;j<q;j++)
	        scanf("%d",&b[i][j]);
	}
	printf("Matrix A:\n");
	display(a,m,n);
	printf("Matrix B:\n");
	display(b,p,q);
	product(a,b,m,n,p,q);
	return 0;

}
void display( int a[][50],int m, int n){
	int i,j;
     for (int i=0;i<m;i++){
         for (int j=0;j<n;j++)
             printf("%d\t",a[i][j]);
         printf("\n");
     }
}

void product(int a[][50],int b[][50], int m, int n, int p, int q){
	int i,j,k;
	int c[50][50];
	for(i=0;i<m;i++){
		for(j=0;j<q;j++)
			for (k=0;k<n;k++)
			c[i][j]+=a[i][k]*b[k][j];
		    
	}
	printf("Product matrix:\n");
	display(c,m,q);
}

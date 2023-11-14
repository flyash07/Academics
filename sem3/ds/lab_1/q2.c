#include<stdio.h>
int check_sparce(int [50][50], int,int);
int main(){
	int a[50][50],m,n,i,j;
	printf("Enter number of rows and columns in the matrix:");
	scanf("%d%d",&m,&n);
	// scanf("%d",&n);
	printf("Enter the elements of matrix:");
	for(i=0;i<m;i++){
	    for (j=0;j<n;j++){
	        scanf("%d",&a[m][n]);
	    }
	}
	if (check_sparce(a,m,n)==1)
	    printf("Given matrix is a sparse matrix\n");
	else 
	    printf("Given matrix is not a sparce matrix\n");
	return 0;
}
int check_sparce(int a[][50],int m,int n){
    int i,j,count=0;
	for(i=0;i<m;i++){
	    for (j=0;j<n;j++){
	        if (a[m][n]==0)
	            count++;
	    }
	}
	if (count>m*n/2)   return 1;
	else return 0;

}
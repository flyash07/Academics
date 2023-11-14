#include<stdio.h>
int Lsearch(int [50], int, int);
int main(){
	int a[50],i,t,m,index;
	printf("Enter number of elements in array:");
	scanf("%d",&m);
	printf("Enter the elements of the array:");
	for(i=0;i<m;i++)
	   scanf("%d",&a[i]);
	printf("Enter the element that you want to search:");
	scanf("%d",&t);
	index=Lsearch(a,m,t);
	if (index==-1) 
	    printf("Element not found \n");
	else 
	    printf("Element found at index %d\n",index);
	return 0;
}
int Lsearch(int a[50],int m,int t){
	int i;
	for (i=0;i<m;i++){
	    if (a[i]==t) return i;
	}
	return -1;
}
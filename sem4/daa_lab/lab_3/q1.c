#include<stdio.h>

int main(){
	int n=8;
	int opcount=0,t;
	int a[]={5,8,3,6,4,1,1,2};
	
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			opcount++;
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nopcount is %d\n",opcount);
}
			

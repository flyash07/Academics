#include<stdio.h>
#include<stdlib.h>
int opcount=0;

void heapify(int h[],int n){
	int i,k,v,heap,j;
	for(i=(n/2);i>=1;i--){
		k=i;
		opcount++;
		v=h[k];
		heap=0;
		while(heap==0 && 2*k<=n){
			j=2*k;
					opcount++;

			if(j<n)
				if(h[j]<h[j+1])
					j=j+1;
			if(v>=h[j])
				heap=1;
			else{
				h[k]=h[j];
				k=j;
			}
		}
		h[k]=v;
	}
return;
}

int main(){
	int i,n;
	printf("\nEnter the number of Elements:");
	scanf("%d",&n);
	int h[n];
	printf("\nEnter the Elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&h[i]);
	printf("\ndisplay the array:");
	for(i=1;i<=n;i++)
		printf("%d ",h[i]);
	heapify(h,n);
	printf("\nThe heap created:");
	for(i=1;i<=n;i++)
		printf("%d ",h[i]);
	printf("\n");
	printf("Opcount is : %d\n",opcount);
}
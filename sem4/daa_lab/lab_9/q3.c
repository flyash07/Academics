#include<stdio.h>
#include<stdlib.h>
int success=0;
int notsuccess=0;
void hash(int *a, int n, int *chash, int m){
	for(int i=0;i<n;i++){
		if(chash[a[i]%m]==0){
			chash[a[i]%m]=a[i];
		}
		else{
			int j=i+1;
			while(chash[j]!=0){
				j++;
				if (j==m) j=0;
			}
			chash[j]=a[i];
		}
	}
}
	
void search(int x,int *a, int m){
	int t=x%m;
	if(a[t]==x){
		success++;
		return;
	}
	int count=0;t++;notsuccess++;
	while(count<m){
		if(a[t]==x){
			success++;
			return;
		}
		notsuccess++;
		t++;
		count++;
	}
}

int main(){
	int n,m,x;
	printf("Enter size:");
	scanf("%d",&n);
	printf("Enter m value:");
	scanf("%d",&m);
	if(n>m){
		printf("closed hashing not possible\n");
		exit(0);
	}
	int a[n];
	printf("Enter array:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int chash[m];
	for(int i=0;i<m;i++)
		chash[i]=0;
	hash(a,n,chash,m);
	printf("Hash created-\n");
	for(int i=0;i<m;i++)
		printf("%d  ",chash[i]);
	printf("\nEnter element to search:");
	scanf("%d",&x);
	search(x,chash,m);
	printf("Successful search :%d\n",success);
	printf("unsuccessful search :%d\n",notsuccess);
}

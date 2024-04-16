#include<stdio.h>
#include<stdlib.h>

int opcount=0;


int main(){
	int n;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	int path[n][n];
	printf("Enter path lengths:");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&path[i][j]);
			if(path[i][j]==-1)
				path[i][j]=10000;         
		}


	for(int k=0;k<n;k++)
                for(int i=0;i<n;i++)
                        for(int j=0;j<n;j++){
                        	opcount++;
				if(path[i][j]>path[i][k]+path[k][j])
					path[i][j]=path[i][k]+path[k][j];
                        }
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(path[i][j]==10000)
				path[i][j]=-1;         
		

	printf("Shortest path matrix :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",path[i][j]);
		printf("\n");
	}
	printf("Opcount is %d\n",opcount);
}
//topological sort using source removal

#include <stdio.h>
#include <stdlib.h>
int count,n;
int adj[50][50];
int topo_sort[50];

int check_incoming(int v){
	for(int i=0;i<n;i++)
		if(adj[i][v])	
			return 1;
	return 0;
}

int exists(int v){
	for(int i=0;i<count;i++)
		if(topo_sort[i]==v)
			return 1;
	return 0;
}

void reset_row(int v){
	for(int i=0;i<n;i++)
		adj[v][i]=0;
}
void source_removal(){
	while(count<n){
		for(int i=0;i<n;i++){
			if(!check_incoming(i) && !exists(i)){
					topo_sort[count++]=i;
					reset_row(i);
			}
		}
	}
}

int main()
{
    int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        topo_sort[i]=-1;
    }
    printf("Enter enter adjancency matrix:\n");
    for (i = 0; i <n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    count=0;
    source_removal();
    printf("Topological sort is:\n");
    for(int i=0;i<n;i++)
    	printf("%d ",topo_sort[i]);
    printf("\n");

}

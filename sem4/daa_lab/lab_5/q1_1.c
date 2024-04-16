//topological sort using dfs

#include <stdio.h>
int k,n;
int adj[50][50];
int visited[50];
int topo_sort[50];


void dfs_topo_sort(int start)
{
    visited[start] = 1;
    for (int i = 0; i < n; i++) 
        if (adj[start][i] == 1)
            if(!visited[i])
            dfs_topo_sort(i);
  	topo_sort[--k]=start;
}

int main()
{
    int v,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        topo_sort[i]=-1;
        visited[i] = 0;
    }
    printf("Enter enter adjancency matrix:\n");
    for (i = 0; i <n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    k=n;
    for(int i=0;i<n;i++){
    	if(!visited[i])
    		dfs_topo_sort(i);
    }
    
    printf("Topological sort is:\n");
    for(int i=0;i<n;i++)
    	printf("%d ",topo_sort[i]);
    printf("\n");

}
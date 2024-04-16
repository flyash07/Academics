#include <stdio.h>
#include <stdlib.h>
int opcount=0;
int main()
{
    int n;
    printf("Enter No. of nodes: \t");
    scanf("%d",&n);
    int** adj=(int **)calloc(n,sizeof(int *));
    printf("\nEnter Adjacency Matrix : \n");
    for(int i=0;i<n;i++)    {
        adj[i]=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                opcount++;
               adj[i][j] = adj[i][j] | (adj[i][k] & adj[k][j]);
            }
            
   
    printf("Transitive enclosure : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
    printf("Opcount is %d\n",opcount);
}




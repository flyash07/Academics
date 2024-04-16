#include <stdio.h>
 
int visited[50], queue[50], f=-1,r= -1;
int adj[50][50];

void bfs(int v,int n)
{
     queue[++r]=v;
    visited[v]=1;
    int vis;
    while (f!=r) {
        vis = queue[++f];
        printf("%d ", vis);
        for (int i = 0; i<n; i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {
                queue[++r]=i;
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int v,n,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        queue[i] = 0;
        visited[i] = 0;
    }
    printf("Enter enter adjancency matrix:\n");
    for (i = 0; i <n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("start vertex: ");
    scanf("%d", &v);
    bfs(v,n);
}
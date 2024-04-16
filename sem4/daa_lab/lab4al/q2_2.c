

#include<stdio.h>

int visited[50];
int n;
int adj[50][50];
int push_order[50];  int m=0;
int pop_order[50]; int k=0;

void dfs(int start)
{
    int flag=0;
    printf("%d  ", start);
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1){
            if(!visited[i]) {
            push_order[m++]=i;
            dfs(i);
            }
    }
      

    }
  pop_order[k++]=start;
}
int main()
{
    int v,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter enter adjancency matrix:\n");
    for (i = 0; i <n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("start vertex: ");
    scanf("%d", &v);
    dfs(v);
    printf("\n");

    for(i=0;i<m;i++)
        printf("%d ",push_order[i]);
    printf("\n");
    for(i=0;i<k;i++)
        printf("%d ",pop_order[i]);
    printf("\n");

}
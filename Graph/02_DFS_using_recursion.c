#include <stdio.h>
#define MAX 10
void DFS(int node,int n,int adj[MAX][MAX],int visited[MAX])
{
    printf("%d ",node);
    visited[node]=1;

    for(int i=0;i<n;i++)
    {
        if(adj[node][i]==1 && visited[i]==0)
        {
            DFS(i,n,adj,visited);
        }
    }
}
void main(){
    int n,edge,src,des,start;
    
    printf("Enter the number of vertices : ");
    scanf("%d",&n);

//Declaring and initializing the adjacency matrix 
    int adj[MAX][MAX];
    int visited[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            adj[i][j]=0;
        visited[i]=0;
    }  

    printf("Enter the number of edges : ");
    scanf("%d",&edge);
    printf("Enter the edges (src des) :\n");
    for(int i=0;i<edge;i++)
    {
        scanf("%d %d",&src,&des);
        adj[src][des]=1;
        adj[des][src]=1;
    }
    
    printf("Enter the starting vertex : ");
    scanf("%d",&start);

    DFS(start,n,adj,visited);

}
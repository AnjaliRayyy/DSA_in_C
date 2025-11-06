#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
struct stack{
    int *arr;
    int size;
    int top;
};
bool isEmpty(struct stack* s)
{
    return s->top==-1;
}
void push(struct stack* s,int data)
{
    s->top++;
    s->arr[s->top]=data;
}
int pop(struct stack* s)
{
    return s->arr[s->top--];
}
void DFS(int node,int n,int adj[MAX][MAX],int visited[MAX],struct stack* s)
{
    push(s,node);
    while(!isEmpty(s))
    {
        int v=pop(s);
        if(visited[v]==0)
        {
            printf("%d ",v);
            visited[v]=1;
        }

        for(int i=0;i<n;i++)
        {
            if(adj[v][i]==1 && visited[i]==0)
            {
                push(s,i);
            }
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

    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=n;
    s->arr=(int*)malloc(n*sizeof(int));

    DFS(start,n,adj,visited,s);

}
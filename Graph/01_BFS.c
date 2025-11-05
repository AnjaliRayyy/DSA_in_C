#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct queue{
    int *arr;
    int capacity;
    int front;
    int rear;
};
bool isEmpty(struct queue* q)
{
    return (q->front ==- 1);
}
void enqueue(struct queue* q,int data){
    if(q->front == -1)  q->front++;
    q->rear++;
    q->arr[q->rear]=data;
}
int dequeue(struct queue* q){
    if(isEmpty(q))  return -1;
    int item=q->arr[q->front];
    if(q->front==q->rear)   q->front=q->rear=-1;
    else    q->front++;
    return item;
}
void main()
{
    int n,e,src,des,start;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    int adj[n][n];
    int visited[n];

    //Initializing the adjacency matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        adj[i][j]=0;
        visited[i]=0;
    }

    printf("Enter the number of edges : ");
    scanf("%d",&e);

    printf("Enter edges (src des) :\n");
    for(int i=0;i<e;i++)
    {
        scanf("%d %d",&src,&des);
        adj[src][des]=1;
        adj[des][src]=1;
    }

    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=-1;
    q->capacity=n;
    q->arr=(int*)malloc(n*sizeof(int));

    printf("Enter the starting vertex : ");
    scanf("%d",&start);
    printf("%d ",start);
    visited[start]=1;
    enqueue(q,start);

    while(!isEmpty(q)){
        int node=dequeue(q);
        for(int i=0;i<n;i++)
        {
            if(adj[node][i]==1 && visited[i]==0)
            {
                enqueue(q,i);
                visited[i]=1;
                printf("%d ",i);
            }
        }
    }
}
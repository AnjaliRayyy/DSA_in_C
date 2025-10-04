#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Queue{
    int* arr;
    int capacity;
    int front;
    int rear;
};
bool isFull(struct Queue* q)
{
    //printf("Capacity =%d, Rear= %d\n",q->capacity,q->rear);
    if(q->rear==q->capacity-1)  return true;
    else    return false;
}
bool isEmpty(struct Queue* q)
{
    if(q->front==-1)    return true;
    else    return false;
}
void enqueue(struct Queue* q,int val)
{
    if(isFull(q))
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if(q->front==-1)    q->front=0;
        q->rear=q->rear+1;
        q->arr[q->rear]=val;
    }
}
int dequeue(struct Queue* q)
{
    if(isEmpty(q))  return -1;
    int val=q->arr[q->front];
    if(q->front == q->rear)
    {
        q->front=-1;
        q->rear=-1;
    }
    else
    {
        q->front=q->front+1;    
    }
    return val;
}
int peek(struct Queue* q)
{
    if(isEmpty(q))  return -1;
    else    return q->arr[q->front];
}
void display(struct Queue* q)
{
    if(isEmpty(q))  printf("Queue is Empty");
    else
    {
        for(int i=q->front;i<=q->rear;i++)
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}
void main()
{
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    printf("Enter the capacity of the queue : ");
    scanf("%d",&q->capacity);
    q->arr=(int*)malloc(q->capacity*sizeof(int));
    q->front=-1;
    q->rear=-1;

    printf("USER MENU :\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isFull\n5. isEmpty\n6. Display\n7. Exit\n");
    int ch=0,val;
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the value to be inserted to the queue : ");
                    scanf("%d",&val);
                    enqueue(q,val);
                    break;
                    case 2: val=dequeue(q);
                    if(val==-1) printf("Queue Underflow!\n");
                    else printf("Dequeued value = %d\n",val);
                    break;
            case 3: val=peek(q);
                    if(val==-1) printf("Queue is empty\n");
                    else    printf("Front value = %d\n",val);
                    break;
            case 4: if(isFull(q))   printf("Queue is full!\n");
                    else    printf("Queue is not full!\n");
                    break;
            case 5: if(isEmpty(q))  printf("Queue is empty!\n");
                    else    printf("Queue is not empty!\n");
                    break;
            case 6: display(q);
                    break;
            case 7: printf("Exited user menu........");
                    break;
            default : printf("Wrong choice!\n");
        }
    }while(ch!=7);
}
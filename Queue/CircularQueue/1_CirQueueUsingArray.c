#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct cirQueue{
    int* arr;
    int capacity;
    int front;
    int rear;
};
bool isFull(struct cirQueue* q)
{
    if((q->rear+1)%q->capacity == q->front) return true;
    else    return false;
}
bool isEmpty(struct cirQueue* q)
{
    if(q->front == -1)  return true;
    else    return false;
}
void enqueue(struct cirQueue* q,int data)
{
    if(isFull(q))   printf("Queue Overflow!\n");
    else
    {
        if(isEmpty(q))  q->front=0;
        q->rear=(q->rear+1)%q->capacity;
        q->arr[q->rear]=data;
    }
}
int dequeue(struct cirQueue* q)
{
    if(isEmpty(q))  return -1;
    int val=q->arr[q->front];
    if(q->rear==q->front)   q->rear=q->front=-1;
    else    q->front=(q->front+1)%q->capacity;
    return val;
} 
int peek(struct cirQueue* q)
{
    if(isEmpty(q))  return -1;
    else    return q->arr[q->front]; 
}
void display(struct cirQueue* q)
{
    if(isEmpty(q))  printf("Nothing to display, Queue is Empty\n");
    else
    {
        int i;
        for(i=q->front;i!=q->rear;)
        {
            printf("%d ",q->arr[i]);
            i=(i+1)%q->capacity;
        }
        printf("%d\n",q->arr[i]);
    }
}
void main()
{
     struct cirQueue* q=(struct cirQueue*)malloc(sizeof(struct cirQueue));
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
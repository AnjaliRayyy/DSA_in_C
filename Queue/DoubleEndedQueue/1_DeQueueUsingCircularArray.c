#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct deque{
    int* arr;
    int front;
    int rear;
    int size;
};
bool isEmpty(struct deque* q)
{
    if(q->front==-1)    return true;
    else    return false;
}
bool isFull(struct deque* q)
{
    if(q->rear==0 && q->front==q->size-1)    return true;
    else if((q->rear+1)%q->size==q->front)   return true;
    else    return false;
}
void enqueueFront(struct deque* q,int data)
{
    if(isFull(q)){
        printf("Dequeue Overflow!\n");
        return;
    }   
    else if(isEmpty(q))  q->front=q->rear=0;
    else if(q->front==0)    q->front=q->size-1;
    else    q->front--;
    q->arr[q->front]=data;
}
int dequeueFront(struct deque* q)
{
    if(isEmpty(q))  return -1;
    int val=q->arr[q->front];
    if(q->front==q->rear)   q->front=q->rear=-1;
    else q->front=(q->front+1)%q->size;
    return val;
}
void enqueueRear(struct deque* q,int data)
{
    if(isFull(q))
    {
        printf("Dequeue Overflow!\n");
        return;
    }
    if(isEmpty(q))  q->front=q->rear=0;
    else if(q->rear==q->size-1)  q->rear=0;
    else q->rear++;
    q->arr[q->rear]=data;
}
int dequeueRear(struct deque* q)
{
    if(isEmpty(q))  return -1;
    int val=q->arr[q->rear];
    if(q->front==q->rear)   q->front=q->rear=-1;
    else if (q->rear==0)    q->rear=q->size-1;
    else    q->rear--;
    return val;
}
int showFront(struct deque* q)
{
    if(isEmpty(q))  return -1;
    else    return q->arr[q->front];
}
int showRear(struct deque* q)
{
    if(isEmpty(q))  return -1;
    else    return q->arr[q->rear];
}
void display(struct deque* q)
{
    if(isEmpty(q))
    {
        printf("Nothing to display! Dequeue is Empty!\n");
        return;
    }
    int i=q->front;
    while(i!=q->rear){
        printf("%d ",q->arr[i]);
        i=(i+1)%q->size;
    }
    printf("%d\n",q->arr[i]);
}
void main()
{
    struct deque* q=(struct deque*)malloc(sizeof(struct deque));
    printf("Enter the size of the queue : ");
    scanf("%d",&q->size);
    q->front=-1;
    q->rear=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    printf("USER MENU:\n1. Insert from front\n2. Insert from rear\n3. Delete from front\n4. Delete from rear\n5. Show front\n6. Show rear\n7. isFull\n8. isEmpty\n9. Display\n10. Exit");
    int ch=0,val;
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the data to be inserted at front : ");
                    scanf("%d",&val);
                    enqueueFront(q,val);
                    //printf("FRONT = %d\tREAR = %d\n",q->arr[q->front],q->arr[q->rear]);
                    break;
            case 2: printf("Enter the data to be inserted at rear : ");
                    scanf("%d",&val);
                    enqueueRear(q,val);
                    //printf("FRONT = %d\tREAR = %d\n",q->arr[q->front],q->arr[q->rear]);
                    break;
            case 3: val=dequeueFront(q);
                    if(val==-1)  printf("Dequeue Undeflow!\n");
                    else printf("Element dequeued from front = %d\n",val);
                    //printf("FRONT = %d\tREAR = %d\n",q->arr[q->front],q->arr[q->rear]);
                    break;
            case 4: val=dequeueRear(q);
                    if(val==-1)  printf("Dequeue Undeflow!\n");
                    else printf("Element dequeued from rear = %d\n",val);
                    //printf("FRONT = %d\tREAR = %d\n",q->arr[q->front],q->arr[q->rear]);
                    break;
            case 5: val=showFront(q);
                    if(val==-1)  printf("Dequeue is Empty!\n");
                    else printf("Front element = %d\n",val);
                    break;
            case 6: val=showRear(q);
                    if(val==-1)  printf("Dequeue is Empty!\n");
                    else printf("Rear element = %d\n",val);
                    break;
            case 7: if(isFull(q))   printf("Dequeue is Full\n");
                    else    printf("Dequeue is not Full!\n");
                    break;
            case 8: if(isEmpty(q))  printf("Dequeue is Empty!\n");
                    else    printf("Dequeue is not Empty!\n");
                    break;
            case 9: display(q);
                    break;
            case 10: printf("Exited the user menu........\n");
                    break;
            default: printf("Wrong choice!\n");
        }
    }while(ch!=10);
}
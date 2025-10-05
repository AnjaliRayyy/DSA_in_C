//Here recursive approach has been used for implementing queue using stack
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack{
    int* arr;
    int capacity;
    int top;
};
bool isEmpty(struct stack* s)
{
    if(s->top==-1)  return true;
    else    return false;
}
bool isFull(struct stack* s)
{
    if(s->top==s->capacity-1)   return true;
    else    return false;
}
void push(struct stack* s,int data)
{
    if(isFull(s))   printf("Queue Overflow!\n");
    else{
        s->top=s->top+1;
        s->arr[s->top]=data;
    }
}
int pop(struct stack* s)
{
      return s->arr[s->top--];
}
int dequeue(struct stack* s){
    if(isEmpty(s))  return -1;
    int x=pop(s);
    if(s->top==-1)  return x;
    int res=dequeue(s);
    push(s,x);
    return res;
}
int peek(struct stack* s)
{
    if(isEmpty(s))  return -1;
    else    return s->arr[0];
}
void display(struct stack* s)
{
    if(isEmpty(s))
    {
        printf("Nothing to diplay! Queue is empty!\n");
        return;
    }
    for(int i=0;i<=s->top;i++)
    {
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
void main()
{
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    printf("Enter the capacity of the queue : ");
    scanf("%d",&s->capacity);
    s->arr=(int*)malloc(s->capacity*sizeof(int));
    s->top=-1;

     printf("USER MENU :\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isFull\n5. isEmpty\n6. Display\n7. Exit\n");
    int ch=0,val;
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the value to be inserted to the queue : ");
                    scanf("%d",&val);
                    push(s,val);
                    break;
                    case 2: val=dequeue(s);
                    if(val==-1) printf("Queue Underflow!\n");
                    else printf("Dequeued value = %d\n",val);
                    break;
            case 3: val=peek(s);
                    if(val==-1) printf("Queue is empty\n");
                    else    printf("Front value = %d\n",val);
                    break;
            case 4: if(isFull(s))   printf("Queue is full!\n");
                    else    printf("Queue is not full!\n");
                    break;
            case 5: if(isEmpty(s))  printf("Queue is empty!\n");
                    else    printf("Queue is not empty!\n");
                    break;
            case 6: display(s);
                    break;
            case 7: printf("Exited user menu........");
                    break;
            default : printf("Wrong choice!\n");
        }
    }while(ch!=7);

}
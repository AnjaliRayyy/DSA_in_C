#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
    int data;
    struct Node* next;
};
bool isEmpty(struct Node* front)
{
    if(front==NULL) return true;
    else    return false;
}
void enqueue(struct Node** front, struct Node** rear,int data)
{
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    if(isEmpty(*front))  *front=*rear=new;
    else
    {
        (*rear)->next=new;
        *rear=new;
    }
    new->next=*front;
}
int dequeue(struct Node** front,struct Node** rear)
{
    if(isEmpty(*front))  return -1;

    int val;
    if(*front==*rear){
        printf("Entered equals condition Front==Rear\n");
        val=(*front)->data;
        *front=*rear=NULL;
        return val;
    }
    else{
        struct Node* temp=*front;
        *front=temp->next;
        (*rear)->next=temp->next;
        val=temp->data;
        free(temp);
        return val;
    }
}
int peek(struct Node* front)
{
    if(isEmpty(front))  return -1;
    else    return front->data;
}
void display(struct Node* front)
{
    if(isEmpty(front))
    {
        printf("Nothing to display! Queue is Empty!\n");
        return;
    }
    struct Node* temp=front;
    while(temp->next!=front)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
void main()
{
    struct Node* front=NULL;
    struct Node* rear=NULL;
    printf("USER MENU :\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. Display\n6. Exit\n");
    int ch=0,val;
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the value to be inserted to the queue : ");
                    scanf("%d",&val);
                    enqueue(&front,&rear,val);
                    printf("FRONT = %d ; REAR= %d\n",front,rear);
                    break;
            case 2: val=dequeue(&front,&rear);
                    if(val==-1) printf("Queue Underflow!\n");
                    else printf("Dequeued value = %d\n",val);
                    printf("FRONT = %d ; REAR= %d\n",front,rear);
                    break;
            case 3: val=peek(front);
                    if(val==-1) printf("Queue is empty\n");
                    else    printf("Front value = %d\n",val);
                    break;
            case 4: if(isEmpty(front))  printf("Queue is empty!\n");
                    else    printf("Queue is not empty!\n");
                    break;
            case 5: display(front);
                    break;
            case 6: printf("Exited user menu........");
                    break;
            default : printf("Wrong choice!\n");
        }
    }while(ch!=6);      
}
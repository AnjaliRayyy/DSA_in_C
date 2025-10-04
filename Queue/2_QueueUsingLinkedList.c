#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
    int data;
    struct Node* next;
};
bool isEmpty(struct Node* head)
{
    if(head==NULL)    return true;
    else    return false;
}
void enqueue(struct Node** head,struct Node** rear,int data)
{
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    if(new==NULL){
        printf("Queue Overflow!");
        return;
    }
    if(isEmpty(*head))
    {
        *head=new;
        *rear=new;
    }
    else
    {
        (*rear)->next=new;
        *rear=new;
    }
    new->data=data;
    new->next=NULL;
}
int dequeue(struct Node** head,struct Node** rear)
{
    if(isEmpty(*head))  return -1;
    int val=(*head)->data;
    if(*head==*rear)  *head=*rear=NULL;
    else *head=(*head)->next;
    return val;
}
int peek(struct Node* head)
{
    if(head==NULL) return -1;
    else return head->data;
}
void display(struct Node* head,struct Node* rear)
{
    if(isEmpty(head))
    {
        printf("Nothing to Display! Queue is Empty\n");
        return;
    }
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    free(temp);
}
void main()
{
    struct Node* head=NULL;
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
                    enqueue(&head,&rear,val);
                    break;
            case 2: val=dequeue(&head,&rear);
            if(val==-1) printf("Queue Underflow!\n");
            else printf("Dequeued value = %d\n",val);
            break;
            case 3: val=peek(head);
                    if(val==-1) printf("Queue is empty\n");
                    else    printf("Front value = %d\n",val);
                    break;
            case 4: if(isEmpty(head))  printf("Queue is empty!\n");
                    else    printf("Queue is not empty!\n");
                    break;
            case 5: display(head,rear);
                    break;
            case 6: printf("Exited user menu........");
                    break;
            default : printf("Wrong choice!\n");
        }
    }while(ch!=6);
}
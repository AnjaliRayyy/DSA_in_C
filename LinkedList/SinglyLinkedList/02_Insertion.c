#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
// Function declaration
struct Node* insertAtBegin(struct Node* head,int item);
struct Node* insertAtAnyPosition(struct Node* head,int data,int pos);
struct Node* insertAtEnd(struct Node*head,int item);

struct Node* insertAtBegin(struct Node* head,int item)
{
    struct Node* p=(struct Node*) malloc(sizeof(struct Node));
    p->next=head;
    p->data=item;
    return p;
}

struct Node* insertAtAnyPosition(struct Node* head,int data,int pos){
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while(i!=pos-1 && p->next!=NULL)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=data;

    return head;
}

struct Node* insertAtEnd(struct Node* head,int data){
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    ptr->data=data;

    return head;
}
void display(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
void main()
{
    int item,index;

    struct Node* head;
    struct Node* second;
    struct Node* third;

    head=(struct Node*) malloc(sizeof(struct Node));
    second=(struct Node*) malloc(sizeof(struct Node));
    third=(struct Node*) malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=13;
    second->next=third;

    third->data=17;
    third->next=NULL;
    
    
    int ch;
    printf("\nUSER MENU :\n1. Insert at Begining\n2. Insert at Any Position\n3. Insert at End\n4. Display\n5. Exit");
    do{
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1: {
                printf("Enter the data of node to be inserted at beginning : ");
                scanf("%d",&item);
                head=insertAtBegin(head,item);
                break;
            }
            case 2:{
                printf("Enter the data of node to be inserted  : ");
                scanf("%d",&item);

                printf("Enter the position where the node will be inserted :  ");
                scanf("%d",&index);

                head=insertAtAnyPosition(head,item,index);
                break;
            }
            case 3:{
                printf("Enter the data pf the node to be inserted : ");
                scanf("%d",&item);
                head=insertAtEnd(head,item);
                break;
            }
            case 4:{
                display(head);
                break;
            }
            case 5 : {
                printf("\n<-------------Exited form user menu------------------->");
                break;
            }
        default: printf("Wrong Choice!!!");
            break;
        }
    }while(ch!=5);

}
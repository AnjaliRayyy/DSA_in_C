#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

//Function definitions
struct Node* deleteFirstNode(struct Node* head);
struct Node* deleteAtIndex(struct Node* head,int index);
struct Node* deleteLastNode(struct Node* head);
struct Node* deleteByValue(struct Node* head,int val);

struct Node* deleteFirstNode(struct Node* head)
{
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node* deleteAtIndex(struct Node* head,int index){
    struct Node* p=head;
    struct Node* q=head->next;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct Node* deleteLastNode(struct Node* head)
{
    struct Node* p=head;
    struct Node*q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
struct Node* deleteByValue(struct Node* head,int val)
{
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->data!=val && q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    if(q->data!= val) printf("Value not found");
    else{
        p->next=q->next;
        free(q);
    }
    return head;
}
void display(struct Node* ptr)
{
    if(ptr==NULL)   printf("Linked List is empty");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
void main()
{
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* second=(struct Node*)malloc(sizeof(struct Node));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth=(struct Node*)malloc(sizeof(struct Node));
    struct Node* sixth=(struct Node*)malloc(sizeof(struct Node));
    
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=fifth;

    fifth->data=50;
    fifth->next=NULL;

    int ch,value,index;
    printf("\nUSER MENU:\n1. Delete the first node\n2. Delete a node in between\n3. Delete the last node\n4. Delete a node with a given value\n5. Display\n6. Exit");

    do{
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:{
            head=deleteFirstNode(head);
            break;
        }
        case 2:{
            printf("Enter the index of node to be deleted : ");
            scanf("%d",&index);
            head=deleteAtIndex(head,index);
            break;
        }
        case 3:{
            head=deleteLastNode(head);
            break;
        }
        case 4:{

            printf("Enter the value : ");
            scanf("%d",&value);
            head=deleteByValue(head,value);
            break;
        }
        case 5:{
            display(head);
            break;
        }
        case 6:{
            printf("<----------Exited from user menu------------>");
            break;
        }
        
        default:
            break;
        }
    }while(ch!=6);
}
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head,int val);
struct Node* insertAtEnd(struct Node* head,int val);
struct Node* insertAtIndex(struct Node* head,int val,int index);

struct Node * insertAtBeginning(struct Node* head, int value){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;

    while(p->next!=head){
        p=p->next;
    }
    p->next=new;
    new->next=head;
    head=new;
    new->data=value;

    return head;
}

struct Node* insertAtEnd(struct Node* head,int data){
    struct Node* new=(struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=new;
    new->next=head;
    new->data=data;

    return head;
}

struct Node* insertAtIndex(struct Node* head,int data,int index){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    new->next=p->next;
    p->next=new;
    new->data=data;
    return head;
}

void display(struct Node* head){
    struct Node* p=head;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
}
void main()
{
    struct Node* head= (struct Node*)malloc(sizeof(struct Node));
    struct Node* second= (struct Node*)malloc(sizeof(struct Node));
    struct Node* third= (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth= (struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=head;

    int ch,index,value;

    printf("USER MENU :\n1. Insertion at Beginning\n2. Insertion at End\n3. Insertion at Index\n4. Display\n5. Exit");
    do{
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1 :{
                printf("Enter the value to be inserted : ");
                scanf("%d",&value);
                head=insertAtBeginning(head,value);
                break;        
            }
            case 2 :{
                printf("Enter the value to be inserted : ");
                scanf("%d",&value);
                head=insertAtEnd(head,value);
                break;        
            }
            case 3 :{
                printf("Enter the value to be inserted : ");
                scanf("%d",&value);
                printf("Enter the index : ");
                scanf("%d",&index);
                head=insertAtIndex(head,value,index);
                break;        
            }
            case 4 : {
                display(head);
                break;
            }
            case 5 :{
                printf("Exiting.....");
                break;        
            }
            default:{
                printf("Invalid Choice!!");
                break;        
            }
        }
    }while(ch!=5);
}
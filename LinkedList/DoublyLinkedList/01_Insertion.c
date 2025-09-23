#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* insertAtBeginning(struct Node* head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* insertAtIndex(struct Node* head, int index, int data);
struct Node* insertAfterNode(struct Node* head, int value, int data);
void display(struct Node* head);

struct Node* insertAtBeginning(struct Node* head,int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=head;
    newNode->prev=NULL;
    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
    return head;
}
struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(head=NULL){
        newNode->prev=NULL;
        head=newNode;
        return head;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}
struct Node* insertAtIndex(struct Node* head,int index,int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=head;
    int i=0;
    while(i<index-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("Index out of bounds\n");
        free(newNode);
        return head;
    }
    else{
        newNode->data=data;
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next!=NULL){
            temp->next->prev=newNode;
        }
        temp->next=newNode;
        return head;
    }
}

void main(){
    int ch,index,value,data;
    struct Node* head=NULL;
    printf("USER MENU:\n1. Insertion at Beginning\n2. Insertion at End\n3. Insertion at Index\n4. Insertion after Node\n5. Display\n6. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                head=insertAtBeginning(head,data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d",&data);
                head=insertAtEnd(head,data);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d",&index);
                printf("Enter data: ");
                scanf("%d",&data);
                head=insertAtIndex(head,index,data);
                break;
            case 4:
                printf("Enter the value of Node after which to insert: ");
                scanf("%d",&value);
                printf("Enter data: ");
                scanf("%d",&data);
                head=insertAfterNode(head,value,data);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(ch!=6);
}
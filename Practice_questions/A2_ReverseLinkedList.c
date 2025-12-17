/*Reverse a singly linked list iteratively or recursively.*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* reverseLinkedList(struct Node* head){
    struct Node* prev=NULL;
    struct Node* curr=head;
    struct Node* next=head;
    while(curr->next!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    curr->next=prev;
    return curr;
}
void display(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void main()
{
    int n;
    printf("Enter the number of nodes in the Linked List : ");
    scanf("%d",&n);
    printf("Enter the data of the respective nodes :\n");
    struct Node* head=NULL;
    struct Node* temp=head;
    for(int i=0;i<n;i++){
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Node %d : ",i);
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            temp=newNode;
        }else{
            temp->next=newNode;
            temp=temp->next;
        }
    }
    printf("Before Reversal : ");
    display(head);
    printf("After Reversal : ");
    head=reverseLinkedList(head);
    display(head);
}
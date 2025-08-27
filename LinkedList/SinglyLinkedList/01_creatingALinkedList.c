#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

void main()
{
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

    linkedListTraversal(head);
}
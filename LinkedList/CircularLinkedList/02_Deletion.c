#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* deleteAtBeginning(struct Node* head);
struct Node* deleteAtEnd(struct Node* head);
struct Node* deleteAtIndex(struct Node* head,int index);
struct Node* deleteByValue(struct Node* head,int value);
void display(struct Node* head);

struct Node* deleteAtBeginning(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next!=head){
        q=q->next;
    }
    q->next=p->next;
    head=p->next;
    free(p);
    return head;
}

struct Node* deleteAtEnd(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next!=head){
        p=p->next;
        q=q->next;
    }
    p->next=head;
    free(q);
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index){
    struct Node* p=head;
    struct Node* q=head->next;
    int i;
    if(index==0){
        head=deleteAtBeginning(head);
        return head;
    }
    else
    {
        while(i=index-1){
        p=p->next;
        q=q->next;
        i++;
        }
        p->next=q->next;
        free(q);
    }
   
    return head;
}

struct Node* deleteByValue(struct Node* head, int value){
    struct Node* p=head;
    struct Node* q=head->next;
    if(p->data==value){
        head=deleteAtBeginning(head);
        return head;
    }
    while(q->data!=value && q->next!=head){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
    return head;
}

void display(struct Node* head){
    struct Node* ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
void main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* second=(struct Node*)malloc(sizeof(struct Node));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=head;

    printf("USER MENU:\n1. Delete at Beginning\n2. Delete at End\n3. Delete at Index\n4. Delete by Value\n5. Display\n6. Exit\n");

    int ch, value, index;
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                head=deleteAtBeginning(head);
                printf("Node deleted at beginning\n");
                break;  

            case 2:
                head=deleteAtEnd(head);
                printf("Node deleted at end\n");
                break;

            case 3:
                printf("Enter the index : ");
                scanf("%d",&index);
                head=deleteAtIndex(head,index);
                printf("Node deleted at index %d\n",index);
                break;

            case 4:
                printf("Enter the value : ");
                scanf("%d",&value);
                head=deleteByValue(head,value);
                printf("Node with value %d deleted\n",value);
                break;

            case 5:
                display(head);
                break;
            
            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!!\n");
                break;
        }
    }while(ch!=6);
}
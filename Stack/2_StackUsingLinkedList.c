#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    int data;
    struct Node* next;
}node;

bool isEmpty(struct Node* top){
    if(top==NULL)
        return true;
    else
        return false;
}

void push(struct Node** top,int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    if (!new){
        printf("Stack overflow!");
    }
    else{
        new->data=data;
        new->next=*top;
        *top=new;
    }
}

int pop(struct Node** top){
    if(*top==NULL)
    {
        printf("Stack Underflow!");
        return -1;
    }
    else{
        struct Node* temp=*top;
        int poppedValue=temp->data;
        *top=(*top)->next;
        free(temp);
        return poppedValue;
    }
}

int peek(struct Node* top){
    return top->data;
}


void display(struct Node* top){
    if(top==NULL)
        printf("Stack is empty");
    else{
        struct Node* temp=top;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

}
void main()
{
    int ch,data;
    struct Node* top=NULL;
        printf("\nUser menu:\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n6. Exit\n");

    do{
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: {
                printf("Enter the data item to be pushed to stack : ");
                scanf("%d",&data);
                push(&top,data);
                break;
            }
            case 2:{
                int poppedValue=pop(&top);
                if(poppedValue!=-1)
                printf("%d was poped form the stack",poppedValue);
                break;
            }
            case 3:{
                if(isEmpty(top))
                printf("Stack is empty");
                else
                printf("%d is present at the top of the stack",peek(top));
                break;
            }
            case 4:{
                if(isEmpty(top))
                    printf("Stack is empty");
                else
                    printf("Stack is not empty");
                break;
            }
            case 5:{
                display(top);
                break;
            }
            case 6:{
                printf("Exited from User Menu........");
                break;
            }
            default: printf("Wrong Choice!!!!!!");
        }
    }while(ch!=6);
}
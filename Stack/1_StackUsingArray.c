#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Stack{
    int top;
    int *arr;
    int capacity;
}stack;
void push(stack *s,int data);
int pop(stack *s);
int peek(stack *s);
bool isEmpty(stack *s);
bool isFull(stack *s);

void initializeStack(stack *s,int capacity){
    s->top=-1;
    s->capacity=capacity;
    s->arr=(int *)malloc(capacity*sizeof(int));
}

void push(stack* s,int data){
    if (isFull(s)){
        printf("\nStack Overflow");
    }
    else{
        s->top=s->top+1;
        s->arr[s->top]=data;
        printf("%d was pushed to the stack",data);
    }
}

int pop(stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow");
        return -1;
    }
    else{
        int item=s->arr[s->top];
        s->top=s->top-1;
        return item;
    }
}

int peek(stack* s){
    return s->arr[s->top];
}

bool isEmpty(stack* s){
    if(s->top == -1)
    return true;
    else 
    return false;
}

bool isFull(stack* s){
    if(s->top==s->capacity-1)
    return true;
    else
    return false;
}

void display(stack* s){
    if(isEmpty(s))
        printf("Stack is Empty");
    else{
        for(int i=0;i<=s->top;i++){
            printf("%d ",s->arr[i]);
        }
        printf("\n");
    }
}
void main(){
    int n,ch=0,data;
    stack *s;
    printf("Enter the capacity of stack: ");
    scanf("%d",&n);
    initializeStack(s,n);

    printf("\nUser menu:\n1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.isFull\n6.Display\n7. Exit\n");

    do{
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: {
                printf("Enter the data item to be pushed to stack : ");
                scanf("%d",&data);
                push(s,data);
                break;
            }
            case 2:{
                printf("%d was poped form the stack",pop(s));
                break;
            }
            case 3:{
                printf("%d is present at the top of the stack",peek(s));
                break;
            }
            case 4:{
                if(isEmpty(s))
                    printf("Stack is empty");
                else
                    printf("Stack is not empty");
                break;
            }
            case 5:{
                if(isFull(s))
                    printf("Stack is full");
                else
                    printf("Stack is not full");
                break;
            }
            case 6:{
                display(s);
                break;
            }
            case 7:{
                printf("Exited from User Menu........");
                break;
            }
            default: printf("Wrong Choice!!!!!!");
        }
    }while(ch!=7);
}
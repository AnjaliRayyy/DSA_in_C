#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct stack{
    char* arr;
    int top;
};
bool isEmpty(struct stack* s)
{
    if(s->top==-1)  return true;
    else    return false;
}
void push(struct stack* s, char ch)
{
    s->top=s->top+1;
    s->arr[s->top]=ch;
}
char pop(struct stack* s)
{
    if(isEmpty(s))  return 'e';
    else
    {
        char poppedCh=s->arr[s->top];
        s->top=s->top-1;
        return poppedCh;
    }
}
int precedence(char ch)
{
    if(ch=='+' || ch=='-')  return 1;
    if(ch=='*' || ch=='/')  return 2;
    if(ch=='^') return 3;
}
void main(){
    char exp[100];
    printf("Enter the infix expression : ");
    scanf("%s",exp);

    struct stack *s=(struct stack*) malloc(sizeof(struct stack));
    s->top=-1;
    s->arr=(char*)malloc(100*sizeof(char));

    char* postfix=(char*) malloc(100*sizeof(char));
    int i=0,k=0;
    char ch;

    while(exp[i]!='\0')
    {
        ch=exp[i];
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        {
            if(s->top==-1 || s->arr[s->top]=='(')   push(s,ch);
            else
            {
                while(precedence(ch)<=precedence(s->arr[s->top]) && s->top!=-1)
                postfix[k++]=pop(s);
                push(s,ch);   
            }
        }
        else if(ch=='(')    push(s,ch);
        else if(ch==')')
        {
            while(s->arr[s->top]!='(')
            postfix[k++]=pop(s);
            pop(s);  //for removing ( from the stack
        }
        else    postfix[k++]=ch;
        i++;
    }
    while(!isEmpty(s))
    postfix[k++]=pop(s);

    postfix[k]='\0';
    printf("Postfix Expression : %s",postfix);
}
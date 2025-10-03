#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct stack{
    char* arr;
    int top;
};
int length(char* exp){
    int len=0;
    while((*exp)!='\0')
    {
        len++;
        exp++;
    }
    return len;
}
int precedence(char ch){
    if(ch=='+' || ch=='-')  return 1;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='^') return 3;
}
bool isEmpty(struct stack* s)
{
    if(s->top==-1)  return true;
    else    return false;
}
void push(struct stack* s,char ch)
{
    s->top=s->top+1;
    s->arr[s->top]=ch;
}
char pop(struct stack* s)
{
    if(isEmpty(s))  return 'e';
    else{
        char poppedCh=s->arr[s->top];
        s->top=s->top-1;
        return poppedCh;
    }
}
void reverse(char exp[]){
    int len=length(exp),k=0;
    for(int i=0;i<len/2;i++)
    {
        char prefix=exp[i];
        exp[i]=exp[len-i-1];
        exp[len-i-1]=prefix;
    }
}
void main(){
    char exp[100];
    char* prefix=(char*)malloc(100*sizeof(char));
    int i,k=0;
    char ch;
    
    // Taking the infix expression as user input
    printf("Enter the infix expression : ");
    scanf("%s",exp);

    //Decalring and initializing the stack
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->arr=(char*)malloc(100*sizeof(char));

    i=length(exp)-1;

    while(i>=0)
    {
        ch=exp[i];
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        {
            if(s->top==-1 || s->arr[s->top]==')')   push(s,ch);
            else{
                while(precedence(ch)<precedence(s->arr[s->top]))
                {
                    prefix[k++]=pop(s);
                }
                push(s,ch);
            }
        }   
        else if(ch=='(')
        {
            while(s->arr[s->top]!=')')
            {
                prefix[k++]=pop(s);
            }
            pop(s); //For removing the ) from the stack
        }
        else if(ch==')')    push(s,ch);
        else
        {
            prefix[k++]=ch;
        } 
        i--;
    }
    while(!isEmpty(s))
    {
        prefix[k++]=pop(s);
    }
    prefix[k]='\0';
    
    //Reverse the prefix string to obtain the final expression
    reverse(prefix);
    printf("Prefix expression : %s",prefix);
}
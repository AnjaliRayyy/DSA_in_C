#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Stack{
    char *arr;
    int top;
};
bool isEmpty(struct Stack* s)
{
    if(s->top==-1)
    return true;
    else
    return false;
}
void push(struct Stack* s,char ch){
    struct Stack* new=(struct Stack*)malloc(sizeof(struct Stack));
    s->top=s->top+1;
    s->arr[s->top]=ch;
    //printf("Pushed %c\n",ch);
}
char pop(struct Stack* s)
{
    if(isEmpty(s))
    return 'e';
    else{
        char poppedItem=s->arr[s->top];
        s->top=s->top-1;
        //printf("Popped = %c\n",poppedItem);
        return poppedItem;
    }
}
void main()
{
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s",exp);

    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
    s->top=-1;
    s->arr=(char* )malloc(100*sizeof(char));
    int i=0;
    char ch,poppedItem;
    bool key=true;
    while(exp[i]!='\0' && key==true)
    {
        ch=exp[i];
        if(ch=='(' || ch=='{' || ch=='['){
            push(s,ch);
        }
        if(ch==')'|| ch=='}' || ch==']')
        {
            poppedItem=pop(s);
            if(ch==')' && poppedItem!='('){
                key=false;
            }
            else if (ch=='}' && poppedItem!='{'){
                key=false;
            }
            else if(ch==']' && poppedItem!='['){
                key=false;
            }
            else if(ch=='e')
            {
                key=false;
            }
        }
        i++;
    }

    if(key==true && isEmpty(s)==true)
        printf("Parenthesis are matching!");
    else
        printf("Parenthesis are not matching!");
}
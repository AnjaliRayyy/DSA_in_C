/*Check whether a string of brackets is valid. A string is valid if brackets open and close in the correct order.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Stack{
    char* arr;
    int top;
};
void push(struct Stack* s,char val){
    s->top++;
    s->arr[s->top]=val;
}
bool isEmpty(struct Stack* s){
    return (s->top==-1);
}
char pop(struct Stack* s){
    if(isEmpty(s))  return 'e';
    char ch=s->arr[s->top];
    s->top=s->top-1;
    return ch;
}
bool isValid(char str[],int len){
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
    s->top=-1;
    s->arr = (char*)malloc(len * sizeof(char));
    for(int i=0;i<len;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')   push(s,str[i]);
        if(str[i]==')' || str[i]=='}' || str[i]==']'){
            char popped_ch=pop(s);
            if(popped_ch=='(' && str[i]!=')')   return false;
            if(popped_ch=='{' && str[i]!='}')   return false;
            if(popped_ch=='[' && str[i]!=']')   return false;
        }
    }
    if(isEmpty(s))  return true;
    else return false;
}
void main()
{
    int len;
    printf("Enter the length of the string : ");
    scanf("%d",&len);
    printf("Enter the string : ");
    char str[len];
    scanf("%s",str);
    if(isValid(str,len) == 1) printf("Valid\n");
    else printf("Invalid\n");
}
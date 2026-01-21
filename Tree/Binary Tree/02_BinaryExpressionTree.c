#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Node{
    char data;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};
struct Node* createNode(char data){
    struct Node* new=(struct Node*) malloc(sizeof(struct Node));
    if(!new)    return NULL;
    new->data=data;
    new->left=new->right=NULL;
    return new;
}
void pushOperand(struct Node** top,char data){
    struct Node* node=createNode(data);
    if(!node){
        printf("Stack Overflow!");
        return;
    }
    node->data=data;
    node->next=*top;
    *top=node;
}
void pushSubTree(struct Node** top,struct Node* tree){
    tree->next=*top;
    *top=tree;
}
struct Node* pop(struct Node** top){
    if(*top==NULL){
        printf("Stack underflow!");
        return NULL;
    }
    struct Node* temp=*top;
    *top=(*top)->next;
    temp->next=NULL;
    return temp;
}

//Inorder Traversal of the Binary Expression Tree
void inorder(struct Node* root){
    if(root==NULL)  return;
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right);
}

//Preorder Traversal of the Binary Expression Tree
void preorder(struct Node* root){
    if(root==NULL)  return;
    printf("%c",root->data);
    preorder(root->left);
    preorder(root->right);
}

//Postorder Traversal of the Binary Expression Tree
void postorder(struct Node* root){
    if(root==NULL)  return;
    postorder(root->left);
    postorder(root->right);
    printf("%c",root->data);
}

void main()
{
    int n;
    printf("Enter the length of the postfix expression : ");
    scanf("%d",&n);
    char exp[n];
    printf("Enter the postfix expression : ");
    scanf("%s",exp);

    struct Node* top=NULL;

    for(int i=0;i<n;i++){
        if(isalnum(exp[i])){
            pushOperand(&top,exp[i]);
        }else{
            struct Node* op=createNode(exp[i]);
            struct Node* operand1=pop(&top);
            struct Node* operand2=pop(&top);
            op->left=operand2;
            op->right=operand1;
            pushSubTree(&top,op);
        }
    }
    struct Node* root=top;
    printf("Inorder traversal of the Binary Expression Tree : ");
    inorder(root);
}
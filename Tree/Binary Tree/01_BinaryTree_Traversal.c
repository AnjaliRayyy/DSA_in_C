#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create()
{
    int x;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data (-1 for no node) : ");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    else{
        newnode->data=x;
        printf("Enter the left child of %d : ",newnode->data);
        newnode->left=create();
        printf("Enter the right child of %d : ",newnode->data);
        newnode->right=create();
        return newnode;
    }
}
void preorder(struct node* root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void main()
{
    int ch=0;
    struct node* root=NULL;
    printf("USER MENU :\n1. Create\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Exit");
    do{
        printf("\n\nEnter you choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: root=create();
            break;
    
            case 2: preorder(root);
            break;
    
            case 3: inorder(root);
            break;
    
            case 4: postorder(root);
            break;
    
            case 5: printf("\nExited the user menu....");
            break;

            default: printf("\nWrong Choice!!!");
        }
    }while(ch!=5);
}
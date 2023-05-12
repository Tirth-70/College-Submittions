#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define COUNT 5
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the data (-1 for not to insert data) :- ");
    scanf("%d",&x);

    if (x==-1)
    {
        return NULL;
    }

    newnode->data=x;

    printf("Enter the left child %d :-\n",x);
    newnode->left = create();

    printf("Enter the Right child %d :-\n",x);
    newnode->right = create();

    return newnode;

}

// Function to print binary tree in 2D
void print2u(struct node *root, int space)
{
    if (root == NULL)
        return;
 
    space += COUNT;
 
    print2u(root->right, space);
 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    print2u(root->left, space);
}
 
// Wrapper over print2u()
void print2D(struct node *root)
{
   print2u(root, 0);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
  
    printPostorder(node->left);
  
    printPostorder(node->right);
  
    printf("%d ", node->data);
}
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
  
    printInorder(node->left);
  
    printf("%d ", node->data);
  
    printInorder(node->right);
}
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
  
    printf("%d ", node->data);
  
    printPreorder(node->left);
  
    printPreorder(node->right);
}

int height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left_side;
        int right_side;
        left_side = height(node->left);
        right_side = height(node->right);
        if (left_side > right_side)
        {
            return left_side + 1;
        }
        else
            return right_side + 1;
    }
}



void main()
{
    struct node *root;

    printf("\n--------------------------------------------\n");
    printf("  Welcome To Implementation of Binary tree");
    printf("\n--------------------------------------------\n");
    root = NULL;
    printf("\nROOT NODE :-\n");
    root = create();

    printf("\n------------------------------------------------------\n");
    printf("  Visualization of tree which is tilted towards left");
    printf("\n------------------------------------------------------\n");
    print2D(root);

    printf("\nHeight of binary tree : %d", height(root));
    
    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);
  
    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);
  
    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int info;
    struct tree *left,*right;
}TREE;

TREE* insert(TREE *, int);
void preorder(TREE *);
void inorder(TREE *);
void postorder(TREE *);
int search(TREE *, int);

void main()
{
    TREE *root;
    int x,choice;
    
    root=NULL;
    while(1)
    {
        printf("\nEnter 1->Insertion\n2->Preorder\n3->Inorder\n4->Postorder\n5->Search\n6->exit\n");
        printf("\n Enter your choice :");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: {
                printf("Enter the value ");
                scanf("%d", &x);
                if (search(root, x)) {
                    printf("Value %d already exists in the tree. Duplicates are not allowed.\n", x);
                } else {
                    root = insert(root, x);
                    printf("Value %d inserted successfully.\n", x);
                }
                } break;
            case 2: {
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                } break;
            case 3: {
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                } break;
            case 4: {
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                } break;
            case 5: {
                printf("Enter value to search: ");
                scanf("%d", &x);
                if (search(root, x)) {
                    printf("Value %d found in the tree.\n", x);
                } else {
                    printf("Value %d not found in the tree.\n", x);
                }
                } break;
            default: exit(0);
        }
    }
}

TREE* insert(TREE *root, int x)
{
    TREE *newnode, *temp;
    newnode = (TREE *)(malloc(sizeof(TREE)));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        root = newnode;
    } else {
        temp = root;
        int flag = 1;
        while(flag)
        {
            if (x < temp->info) {
                if (temp->left == NULL) {
                    temp->left = newnode;
                    flag = 0;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = newnode;
                    flag = 0;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
    return root;
}

// Search function to check if value exists in the tree
int search(TREE *root, int x)
{
    TREE *temp = root;
    while (temp != NULL) {
        if (x == temp->info) {
            return 1;  // Value found
        } else if (x < temp->info) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return 0;  // Value not found
}

void preorder(TREE *root)
{
    if(root){
        printf("\t%d",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TREE *root)
{
    if(root){
        inorder(root->left);
        printf("\t%d",root->info);
        inorder(root->right);
    }
}

void postorder(TREE *root)
{
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("\t%d",root->info);
    }
}
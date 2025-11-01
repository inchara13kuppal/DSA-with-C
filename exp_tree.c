#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    char info;
    struct tree *left, *right;
} TREE;

TREE* create_exptree(char[]);
void preorder(TREE *);
void inorder(TREE *);
void postorder(TREE *);
int isoper(char);
void push(TREE *);
TREE* pop();

TREE *stk[20];
int top;

int main() {
    TREE *root = NULL;
    char postfix[20];
    
    printf("Enter the postfix expression:\n");
    scanf("%s", postfix);
    root = create_exptree(postfix);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

TREE* create_exptree(char postfix[])
{
    int i = 0;
    top = -1;
    char ch;
    TREE *temp;
    
    while((ch = postfix[i]) != '\0')
    {
        temp = (TREE *)malloc(sizeof(TREE));
        temp->info = ch;
        temp->left = NULL;
        temp->right = NULL;

        if(isoper(ch))
        {
            temp->right = pop();
            temp->left = pop();
            push(temp);
        }
        else 
        {
            push(temp);
        }
        i++;
    }
    return pop();
}

void preorder(TREE *root) {
    if (root) {
        printf("%c ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TREE *root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->info);
        inorder(root->right);
    }
}

void postorder(TREE *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->info);
    }
}

void push(TREE *node) {
    if (top < 19) {
        stk[++top] = node;
    }
}

TREE* pop() {
    if (top >= 0) {
        return stk[top--];
    }
    return NULL;
}

int isoper(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return 1;
        default: return 0;
    }
}
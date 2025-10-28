#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int info;
    struct tree *left, *right;
} TREE;

TREE *stk[10];
int top;

TREE* insert(TREE *, int);
void iterative_inorder(TREE*);
void push(TREE *t);
TREE* pop();
int isempty();

int main() {
    TREE *root = NULL;
    int x, choice;

    while (1) {
        printf("\nEnter 1->Insertion\n2->Inorder(iterative)\n3->Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                printf("Enter the value: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    continue;
                }
                root = insert(root, x);
                break;
            }
            case 2: {
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Inorder traversal (iterative): ");
                    iterative_inorder(root);
                    printf("\n");
                }
                break;
            }
            case 3: {
                printf("Exiting program.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
    return 0;
}

TREE* insert(TREE *root, int x) {
    TREE *newnode, *temp;
    int flag = 1;
     
    newnode = (TREE*)(malloc(sizeof(TREE)));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;
    
    if (root == NULL) {
        root = newnode;
    } else {
        temp = root;
        while (flag) {
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

void iterative_inorder(TREE *root) {
    TREE *temp = root;
    top = -1;
    
    while (temp != NULL) {
        push(temp);
        temp = temp->left;  
    }
    
    while (!isempty()) {
        temp = pop();
        printf("%d ", temp->info);
        
        if (temp->right != NULL) {
            temp = temp->right;
            while (temp != NULL) {
                push(temp);
                temp = temp->left;
            }
        }  
    }
}

void push(TREE *t) {
    if (top < 9) {
        top++;
        stk[top] = t;
    }
}

TREE* pop() {
    if (top >= 0) {
        TREE *t = stk[top];
        top--;
        return t;
    }
    return NULL;
}

int isempty() {
    return (top == -1);
}
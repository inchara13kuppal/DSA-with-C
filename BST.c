#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int info;
    struct tree *left, *right;
} TREE;

TREE* insert(TREE *root, int x);
void preorder(TREE *root);
void inorder(TREE *root);
void postorder(TREE *root);
int search(TREE *root, int key);
TREE* tree_delete(TREE *root, int key);
int mini(TREE *root);
int maxi(TREE *root);
int countNodes(TREE *root);
int countLeaves(TREE *root);
int countInternal(TREE *root);
void iterativePreorder(TREE *root);
void iterativePostorder(TREE *root);
int height(TREE *root);


TREE *stk[10];
int top;

void main() {
    TREE *root = NULL;
    int x, choice;

    while (1) {
        printf("\nEnter 1->Insertion\n2->Preorder\n3->Inorder\n4->Postorder\n5->Search\n6->Delete\n7->Exit\n8->Minimum\n9->Maximum\n10->Total Nodes\n11->Leaf Nodes\n12->Internal Nodes\n13->Iterative Preorder\n14->Iterative Postorder\n15->Height\n");
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
            } break;
            case 2: {
                if (root == NULL) printf("Tree is empty.\n");
                else {
                    printf("Preorder traversal: ");
                    preorder(root);
                    printf("\n");
                }
            } break;
            case 3: {
                if (root == NULL) printf("Tree is empty.\n");
                else {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
            } break;
            case 4: {
                if (root == NULL) printf("Tree is empty.\n");
                else {
                    printf("Postorder traversal: ");
                    postorder(root);
                    printf("\n");
                }
            } break;
            case 5: {
                printf("Enter the key value to search: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    continue;
                }
                int found = search(root, x);
                if (found == 0) printf("Element %d not found\n", x);
                else printf("Element %d found\n", x);
            } break;
            case 6: {
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    continue;
                }
                printf("Enter key value to delete: ");
                scanf("%d", &x);
                root = tree_delete(root, x);
            } break;
            case 7: {
                printf("Exiting program.\n");
                exit(0);
            }
            case 8: {
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    continue;
                }
                int min_val = mini(root);
                printf("Minimum value: %d\n", min_val);
            } break;
            case 9: {
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    continue;
                }
                int max_val = maxi(root);
                printf("Maximum value: %d\n", max_val);
            } break;
            case 10: {
                if (root == NULL) printf("Tree is empty.\n");
                else printf("Total nodes: %d\n", countNodes(root));
            } break;
            case 11: {
                if (root == NULL) printf("Tree is empty.\n");
                else printf("Leaf nodes: %d\n", countLeaves(root));
            } break;
            case 12: {
                if (root == NULL) printf("Tree is empty.\n");
                else printf("Internal nodes: %d\n", countInternal(root));
            } break;
            case 13: {
                if (root == NULL) printf("Tree is empty.\n");
                else {
                    printf("Iterative Preorder: ");
                    iterativePreorder(root);
                    printf("\n");
                }
            } break;
            case 14: {
                if (root == NULL) printf("Tree is empty.\n");
                else {
                    printf("Iterative Postorder: ");
                    iterativePostorder(root);
                    printf("\n");
                }
            } break;
            case 15: {
                if (root == NULL) printf("Tree is empty.\n");
                else printf("Height: %d\n", height(root));
            } break;
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
}

TREE* insert(TREE *root, int x) {
    TREE *newnode = (TREE *)malloc(sizeof(TREE));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) return newnode;

    TREE *temp = root;
    while (1) {
        if (x == temp->info) {
            printf("Duplicate value %d not inserted.\n", x);
            free(newnode);
            return root;
        }
        if (x < temp->info) {
            if (temp->left == NULL) {
                temp->left = newnode;
                break;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = newnode;
                break;
            }
            temp = temp->right;
        }
    }
    return root;
}

void preorder(TREE *root) {
    if (root) {
        printf("\t%d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TREE *root) {
    if (root) {
        inorder(root->left);
        printf("\t%d", root->info);
        inorder(root->right);
    }
}

void postorder(TREE *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("\t%d", root->info);
    }
}

int search(TREE *root, int key) {
    TREE *temp = root;
    while (temp != NULL) {
        if (key == temp->info) return 1;
        else if (key < temp->info) temp = temp->left;
        else temp = temp->right;
    }
    return 0;
}

TREE* tree_delete(TREE *root, int key) {
    TREE *temp = root, *parent = NULL, *q = NULL, *insucc;
    TREE *insucc_parent = temp;

    while (temp != NULL && key != temp->info) {
        parent = temp;
        if (key < temp->info) temp = temp->left;
        else temp = temp->right;
    }

    if (temp == NULL) {
        printf("Element %d not found\n", key);
        return root;
    }

    if (temp->left == NULL) q = temp->right;
    else if (temp->right == NULL) q = temp->left;
    else {
        insucc = temp->right;
        while (insucc->left != NULL) {
            insucc_parent = insucc;
            insucc = insucc->left;
        }
        insucc->left = temp->left;
        if (insucc_parent != temp) {
            insucc_parent->left = insucc->right;
            insucc->right = temp->right;
        }
        q = insucc;
    }

    if (parent == NULL) root = q;
    else if (parent->left == temp) parent->left = q;
    else parent->right = q;

    free(temp);
    printf("Element %d deleted\n", key);
    return root;
}

int mini(TREE *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    TREE *temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp->info;
}

int maxi(TREE *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    TREE *temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp->info;
}

int countNodes(TREE *root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(TREE *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int countInternal(TREE *root) {
    if (root == NULL) return 0;
    return countNodes(root) - countLeaves(root);
}

void iterativePreorder(TREE *root) {
    if (root == NULL) return;
    #define MAX 100
    TREE* stack[MAX];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        TREE* node = stack[top--];
        printf("\t%d", node->info);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

void iterativePostorder(TREE *root) {
    if (root == NULL) return;
    #define MAX 100
    TREE* stack[MAX];
    int top = -1;
    TREE *curr = root, *last = NULL;
    while (curr || top >= 0) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top];
        if (curr->right == NULL || curr->right == last) {
            printf("\t%d", curr->info);
            top--;
            last = curr;
            curr = NULL;
        } else {
            curr = curr->right;
        }
    }
}

int height(TREE *root) {
    if (root == NULL) return -1;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + (left > right ? left : right);
}


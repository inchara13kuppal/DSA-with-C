#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert_node(struct node *root, int data) {
    if (!root) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if (data < root->data) root->left = insert_node(root->left, data);
    else if (data > root->data) root->right = insert_node(root->right, data);
    return root;
}

void inorder_traversal(struct node *root) {
    if (root) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void main() {
    struct node *root = NULL;
    
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 70);
    printf("Inserting duplicate 50...\n");
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("Inorder Traversal (Should not show duplicates): ");
    inorder_traversal(root);
    printf("\n");
}

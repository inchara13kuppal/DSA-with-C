#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert_node(struct node *root, int data) {
    if (!root) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < root->data) root->left = insert_node(root->left, data);
    else root->right = insert_node(root->right, data);
    return root;
}

int count_nodes(struct node *root) {
    if (!root) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

void main() {
    struct node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 70);
    root = insert_node(root, 20);
    root = insert_node(root, 40);

    printf("Total number of nodes: %d\n", count_nodes(root));
}

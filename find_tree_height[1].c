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

int max(int a, int b) { return (a > b) ? a : b; }

int get_height(struct node *root) {
    if (!root) return -1;
    return 1 + max(get_height(root->left), get_height(root->right));
}

void main() {
    struct node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 70);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 10);

    printf("Height of the tree: %d\n", get_height(root));
}

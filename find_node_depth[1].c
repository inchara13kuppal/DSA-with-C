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

int get_depth(struct node *root, int target, int depth) {
    if (!root) return -1;
    if (root->data == target) return depth;
    int left_depth = get_depth(root->left, target, depth + 1);
    if (left_depth != -1) return left_depth;
    return get_depth(root->right, target, depth + 1);
}

void main() {
    struct node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 70);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    
    int target = 40;
    int depth = get_depth(root, target, 0);

    printf("Depth of node %d: %d\n", target, depth);
}

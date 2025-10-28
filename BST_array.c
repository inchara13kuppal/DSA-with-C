#include <stdio.h>
#include <stdlib.h>

void insert(int x);
void preorder(int i);
void inorder(int i);
void postorder(int i);

int t[100];

int main() {
    int x, choice, i;
    
    // Initialize array with zeros
    for(i = 0; i < 100; i++) {
        t[i] = 0;
    }

    while (1) {
        printf("\nEnter 1->Insertion\n2->Preorder\n3->Inorder\n4->Postorder\n5->Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the value to insert: ");
                scanf("%d", &x);
                insert(x);
                break;
            }
            case 2: {
                printf("Preorder traversal: ");
                preorder(0);
                printf("\n");
                break;
            }
            case 3: {
                printf("Inorder traversal: ");
                inorder(0);
                printf("\n");
                break;
            }
            case 4: {
                printf("Postorder traversal: ");
                postorder(0);
                printf("\n");
                break;
            }
            case 5: {
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

void insert(int x) {
    int i = 0;
    
    // If tree is empty, insert at root
    if(t[0] == 0) {
        t[0] = x;
        return;
    }
    
    // Find the correct position to insert
    while (i < 100 && t[i] != 0) {
        if(x < t[i]) {
            i = 2 * i + 1;  // Go to left child
        } else {
            i = 2 * i + 2;  // Go to right child
        }
    }
    
    // Check if we found a valid position
    if(i < 100) {
        t[i] = x;
    } else {
        printf("Tree is full! Cannot insert %d\n", x);
    }
}

void preorder(int i) {
    if(i < 100 && t[i] != 0) {
        printf("%d ", t[i]);
        preorder(2 * i + 1);
        preorder(2 * i + 2);
    }
}

void inorder(int i) {
    if(i < 100 && t[i] != 0) {
        inorder(2 * i + 1);
        printf("%d ", t[i]);
        inorder(2 * i + 2);
    }
}

void postorder(int i) {
    if(i < 100 && t[i] != 0) {
        postorder(2 * i + 1);
        postorder(2 * i + 2);
        printf("%d ", t[i]);
    }
}
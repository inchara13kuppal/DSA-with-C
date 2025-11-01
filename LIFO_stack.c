//(LIFO) Stack

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow or no node\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Pushed %d to stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped %d from stack\n", top->data);
    top = top->next;
    free(temp);
}

void display() {
    struct Node* temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }
    return 0;
}

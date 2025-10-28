#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} NODE;

NODE* frontEnqueue(NODE *rear, int x) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->info = x;
    
    if (rear == NULL) {
        newnode->next = newnode;
        return newnode;
    }
    
    newnode->next = rear->next;
    rear->next = newnode;
    return rear;
}

NODE* rearEnqueue(NODE *rear, int x) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->info = x;
    
    if (rear == NULL) {
        newnode->next = newnode;
        return newnode;
    }
    
    newnode->next = rear->next;
    rear->next = newnode;
    return newnode;
}

NODE* frontDequeue(NODE *rear) {
    if (rear == NULL) {
        printf("Queue Underflow\n");
        return NULL;
    }
    
    if (rear->next == rear) {
        free(rear);
        return NULL;
    }
    
    NODE *front = rear->next;
    rear->next = front->next;
    free(front);
    return rear;
}

NODE* rearDequeue(NODE *rear) {
    if (rear == NULL) {
        printf("Queue Underflow\n");
        return NULL;
    }
    
    if (rear->next == rear) {
        free(rear);
        return NULL;
    }
    
    // Find the node before rear
    NODE *temp = rear->next;
    while (temp->next != rear) {
        temp = temp->next;
    }
    
    temp->next = rear->next;
    free(rear);
    return temp;
}

void display(NODE *rear) {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return;
    }
    NODE *temp = rear->next;
    printf("Queue: ");
    printf("%d", temp->info);
    temp = temp->next;
    while (temp != rear->next) {
        printf(" -> %d", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE *rear = NULL;
    int choice, x;
    
    while(1) {
        printf("\n1->Front Enqueue\n2->Rear Enqueue\n3->Front Dequeue\n4->Rear Dequeue\n5->Display\n6->Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                rear = frontEnqueue(rear, x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                rear = rearEnqueue(rear, x);
                break;
            case 3:
                rear = frontDequeue(rear);
                break;
            case 4:
                rear = rearDequeue(rear);
                break;
            case 5:
                display(rear);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
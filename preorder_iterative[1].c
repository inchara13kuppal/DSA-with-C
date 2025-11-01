#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void enqueue(struct node **, struct node **, int);
void display(struct node *);
int dequeue(struct node **, struct node **);
int isqempty(struct node *);

void main() {
    struct node *front = NULL;
    struct node *rear = NULL;
    int choice, x;

    while(1) {
        printf("\nEnter 1->ENQUEUE\n2->DISPLAY\n3->DEQUEUE\n4->EXIT  ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to ENQUEUE: ");
                scanf("%d", &x);
                enqueue(&front, &rear, x);
                break;
            case 2:
                printf("The contents of the QUEUE are...\n");
                display(front);
                break;
            case 3:
                if(isqempty(front))
                    printf("Empty Queue..");
                else {
                    x = dequeue(&front, &rear);
                    printf("The element deleted is..%d ", x);
                }
                break;
            default:
                exit(0);
        }
    }
}

void enqueue(struct node **f, struct node **r, int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Memory allocation failed. Queue is full.\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    if(isqempty(*f)) {
        *f = newNode;
        *r = newNode;
    } else {
        (*r)->next = newNode;
        *r = newNode;
    }
}

int dequeue(struct node **f, struct node **r) {
    int x;
    struct node *temp;

    x = (*f)->data;
    temp = *f;
    *f = (*f)->next;

    if(*f == NULL) {
        *r = NULL;
    }

    free(temp);
    return x;
}

void display(struct node *f) {
    if(isqempty(f)) {
        printf("Empty Queue..\n");
        return;
    }
    printf("Front end -> ");
    while(f != NULL) {
        printf("%d -> ", f->data);
        f = f->next;
    }
    printf("Rear end\n");
}

int isqempty(struct node *f) {
    return (f == NULL);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL, *temp;
    int n, data, sum = 0;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data %d: ", i+1);
        scanf("%d", &data);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->info = data;
        newNode->next = head;
        head = newNode;
    }
    temp = head;
    while (temp) {
        if (temp->info % 2 == 0) sum += temp->info;
        temp = temp->next;
    }
    printf("Sum of even numbers: %d\n", sum);

    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
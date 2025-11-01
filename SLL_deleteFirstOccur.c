#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    int n, data, target;

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

    printf("Enter value to delete: ");
    scanf("%d", &target);
    
    Node** curr = &head;
    while (*curr) {
        if ((*curr)->info == target) {
            Node* toDelete = *curr;
            *curr = (*curr)->next;
            free(toDelete);
            printf("Node deleted successfully!\n");
            break;
        }
        curr = &(*curr)->next;
    }

    printf("Updated list: ");
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->info);
        temp = temp->next;
    }

    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
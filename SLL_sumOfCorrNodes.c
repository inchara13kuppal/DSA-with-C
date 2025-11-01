#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

int main() {
    Node *list1 = NULL, *list2 = NULL, *result = NULL, *curr;
    int n1, n2, data;
    
    printf("Enter number of nodes for list 1: ");
    scanf("%d", &n1);
    printf("Enter %d elements for list 1: ", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->info = data;
        newNode->next = list1;
        list1 = newNode;
    }
    
    printf("Enter number of nodes for list 2: ");
    scanf("%d", &n2);
    printf("Enter %d elements for list 2: ", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->info = data;
        newNode->next = list2;
        list2 = newNode;
    }
    
    Node *a = list1, *b = list2;
    while (a || b) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->info = (a ? a->info : 0) + (b ? b->info : 0);
        newNode->next = NULL;
        
        if (!result) result = newNode;
        else curr->next = newNode;
        curr = newNode;
        
        if (a) a = a->next;
        if (b) b = b->next;
    }

    printf("Result list: ");
    curr = result;
    while (curr) {
        printf("%d ", curr->info);
        curr = curr->next;
    }
    
    while (list1) { Node* t = list1; list1 = list1->next; free(t); }
    while (list2) { Node* t = list2; list2 = list2->next; free(t); }
    while (result) { Node* t = result; result = result->next; free(t); }
    return 0;
}
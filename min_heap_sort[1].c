#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int heap_arr[MAX_SIZE];
int heap_size = 0;

void swap(int *a, int *b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

void min_heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap_size && heap_arr[left] < heap_arr[smallest]) smallest = left;
    if (right < heap_size && heap_arr[right] < heap_arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(&heap_arr[i], &heap_arr[smallest]);
        min_heapify(smallest);
    }
}

void build_min_heap() {
    for (int i = heap_size / 2 - 1; i >= 0; i--) min_heapify(i);
}

void delete_min_and_sort(int sorted_arr[]) {
    int original_size = heap_size;
    for (int i = 0; i < original_size; i++) {
        sorted_arr[i] = heap_arr[0];
        heap_arr[0] = heap_arr[heap_size - 1];
        heap_size--;
        min_heapify(0);
    }
}

void main() {
    int heap_elements[] = {12, 11, 13, 5, 6, 7};
    heap_size = sizeof(heap_elements) / sizeof(heap_elements[0]);
    int n = heap_size;
    for(int i = 0; i < heap_size; i++) heap_arr[i] = heap_elements[i];
    int sorted_output[MAX_SIZE];

    build_min_heap();
    
    printf("Initial Min Heap Array: ");
    for(int i = 0; i < n; i++) printf("%d ", heap_arr[i]);
    printf("\n");

    delete_min_and_sort(sorted_output);
    printf("Elements sorted by deletion (Heap Sort): ");
    for(int i = 0; i < n; i++) printf("%d ", sorted_output[i]);
    printf("\n");
}

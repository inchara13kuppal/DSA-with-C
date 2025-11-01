#include <stdio.h>
#include <stdlib.h>

void heapify(int[], int);
void display(int[], int);
int mindel(int[], int*);
void adjust(int[], int);
void convertMaxToMinHeap(int[], int);

void main()
{
    int h[20], p, n, count;
    printf("enter the number of elements...\n");
    scanf("%d", &n);
    count = n;
    printf("enter the elements...\n");
    for(p = 0; p < n; p++)
        scanf("%d", &h[p]);

    heapify(h, count);

    printf("\nMax heap (Intermediate state):\n");
    display(h, count);

    convertMaxToMinHeap(h, count);

    printf("\nMin heap after conversion:\n");
    display(h, count);
    printf("\nthe min heap element......%d", mindel(h, &count));
    printf("\nthe elements after deletion in minheap......");
    display(h, count);
}

// heapify - maxheap bottom up algorithm
//maxheap - bottom up algorithm, here elements are upwards, index are downwards--------------------------------------------------

void heapify(int h[], int count)
{
    int k, i, key, j;
    for(k = 1; k < count; k++) 
    {
        i = k;
        key = h[i];
        j = (i - 1) / 2; // Parent index

        while(i > 0 && h[j] < key) // Max Heap property check (parent < child)
        {
            h[i] = h[j];
            i = j;
            j = (i - 1) / 2;
        }
        h[i] = key;
    }
}

void display(int h[], int count)
{
    int p;

    for(p = 0; p < count; p++)
        printf("\t%d", h[p]);
    printf("\n");
}

int mindel(int h[], int *count)
{
    int min;
    if(*count <= 0) { 
        printf("Heap is empty or invalid size!\n");
        return -1;
    }
    
    min = h[0];
    h[0] = h[*count - 1];
    (*count)--;
    adjust(h, *count);
    return min;
}

void adjust(int h[], int count)
{
    int i, key, j;
    j = 0;
    key = h[j];
    i = 2 * j + 1;

    while(i < count)
    {
        // Find the SMALLEST child
        if(i + 1 < count && h[i + 1] < h[i]) 
            i++;

        if(key <= h[i])
            break;

        h[j] = h[i];
        j = i;
        i = 2 * j + 1;
    }
    h[j] = key;
}

void convertMaxToMinHeap(int h[], int count)
{
    int k;
    for(k = (count - 2) / 2; k >= 0; k--)
    {
        int i, key, j;
        j = k;
        key = h[j];
        i = 2 * j + 1; 
        
        while(i < count)
        {
            if(i + 1 < count && h[i + 1] < h[i]) 
                i++;

            if(key <= h[i])
                break;

            h[j] = h[i];
            j = i;
            i = 2 * j + 1;
        }
        h[j] = key;
    }
}
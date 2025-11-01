#include <stdio.h>
#include <stdlib.h>

void heapify(int[], int);
void display(int[], int);
int mindel(int[], int*);
void adjust(int[], int);

void main()
{
    int h[20], p, n, count;
    printf("enter the number of elements...\n");
    scanf("%d", &n);
    count = n;
    printf("enter the elements...\n");
    for(p = 0; p < n; p++)
        scanf("%d", &h[p]);

    // heapify - maxheap bottom up algorithm
    //minheap -  up bottom algorithm, here elements are downwards, index are upwards--------------------------------------------------
    heapify(h, count);

    display(h, count);
    printf("\nthe min heap element......%d", mindel(h, &count));
    printf("\nthe elements after deletion in minheap......");
    display(h, count);
}

void heapify(int h[], int count)
{
    int k, i, key, j;
    for(k = 1; k < count; k++)//------------------------------- k should be incremented --------------------------------------------
    {
        i = k;
        key = h[i];
        j = (i - 1) / 2;

        while(i > 0 && h[j] > key)
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
    if(*count == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    
    min = h[0];
    h[0] = h[*count - 1];
    (*count)--;
    adjust(h, *count);
    return min;
}

//------------------------ down up or bottom to top approach----------------------------------------------------------------------------
void adjust(int h[], int count)
{
    int i, key, j;
    j = 0;
    key = h[j];
    i = 2 * j + 1;
    //as long as child exists -----h[i] is left child node---------------------h[i]+1 is right child node-------------------------------
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
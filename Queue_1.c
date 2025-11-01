#include <stdio.h>
#include <stdlib.h>
#define qsize 10

void enqueue(int[], int*, int*, int);
void display(int[], int, int);
int dequeue(int[], int*, int*);
int isqempty(int, int);
int isqfull(int);

void main()
{ 
    int que[qsize], choice, x, front, rear;
    front = -1; 
    rear = -1;
    
    while(1)
    {
        printf("\nEnter 1->ENQUEUE\n2->DISPLAY\n3->DEQUEUE\n4->EXIT  ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: {
                printf("Enter the element to ENQUEUE: ");
                scanf("%d", &x);
                enqueue(que, &front, &rear, x);
                break;
            }
            case 2: { 
                printf("The contents of the QUEUE are...");
                display(que, front, rear);
                break;
            }
            case 3: {
                if(isqempty(front, rear))
                    printf("Empty Queue..");
                else { 
                    x = dequeue(que, &front, &rear);
                    printf("The element deleted is..%d ", x);
                }
                break;
            }
            default: exit(0);
        }
    }
}

void enqueue(int q[], int *f, int *r, int x)
{
    if(isqfull(*r)) 
        printf("Queue Full");
    else {
        if(*f == -1 && *r == -1)
            (*f)++;
        q[++(*r)] = x;
    }
}

void display(int q[], int f, int r)
{ 
    int i;
    if(isqempty(f, r))
        printf("Empty Queue..");
    else {
        for(i = f; i <= r; i++)
            printf("\t%d", q[i]);
    }
}

int dequeue(int q[], int *f, int *r)
{
    int x = q[*f];
    (*f)++;
    return x;
}

int isqfull(int r)
{
    if(r == qsize - 1)
        return 1;
    return 0;
}

int isqempty(int f, int r)
{
    if((f == -1 && r == -1) || (f > r)) 
        return 1;
    return 0;
}
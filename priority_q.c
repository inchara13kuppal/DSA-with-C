#include <stdio.h>
#include <stdlib.h>
#define qsize 5

typedef struct pnode
{
    int info;
    int pty;
}PNODE;


void enqueue(PNODE[], int, int);
void display(PNODE[]);
PNODE dequeue(PNODE[]);

int count = 0;

void main()
{ 
    PNODE que[qsize];
    int choice, x,p;
    PNODE t;
    
    while(1)
    {
        printf("\nEnter 1->ENQUEUE\n2->DISPLAY\n3->DEQUEUE\n4->EXIT  ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: {
                printf("Enter the priority along with value to ENQUEUE: ");
                scanf("%d%d", &x, &p);
                enqueue(que, p, x);
                break;
            }
            case 2: {
                printf("The contents of the QUEUE are...");
                display(que);
                break;
            }
            case 3: {
                if(count == 0)
                    printf("Empty Queue..");
                else { 
                    t = dequeue(que);
                    printf("The element deleted is..%d with priority %d", t.info, t.pty);
                }
                break;
            }
            default: exit(0);
        }
    }
}

void enqueue(PNODE q[], int x, int p)
{
    //t is temporary variable 
    PNODE t;
    int j;
    t.info = x;
    t.pty = p;

    j=count-1;

    if (count==qsize) printf("Queue full....");
    else {
        while (j>=0 && q[j].pty>p)
        {
            q[j+1]=q[j]; //ordered insertion
            j--;

        }
        q[j+1] = t; //direct end insertion
        count ++;
    }
}

PNODE dequeue(PNODE q[])
{
    PNODE t;
    int j;
    j = 0;
    t=q[0];
    for(j = 0; j < count - 1; j++){
        q[j] = q[j+1];
    }
    count --;
    return t;
}

void display(PNODE q[])
{ 
    int i;
    if(count==0)
        printf("Empty Queue..");
    else {
        for(i = 0; i < count; i++)
            printf("\t%d with priority %d", q[i].info, q[i].pty);
    }
}
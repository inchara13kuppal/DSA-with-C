#include <stdio.h>
#include <stdlib.h>
#define size 5

void push(int[],int*,int);
void display(int[],int);
int pop(int [],int*);
int seek(int[], int *);
int peep(int[], int, int);

void main()
{ int st[size],choice,x,top,pos;
   top=-1;
	while(1)
	{
	printf("\nEnter 1->PUSH\n2->DISPLAY\n3->POP\n4->SEEK\n5->PEEP\n6->EXIT  ");
	scanf("%d",&choice);
	switch(choice)
	{
	  case 1: {
		  printf("Enter the element PUSH");
		  scanf("%d",&x);
		  push(st,&top,x);
	         }break;
	  case 2:{ printf("The contents of the stack are...");
	          display(st,top);
	         }break;
	  case 3:{
		      x=pop(st,&top);
			  if(x==-1)printf("Empty Stack..");
			  else printf("The element deleted is..%d ",x);
	         }break;
	  case 4:{
		      x=seek(st,&top);
			  printf("The element on top of the stack is..%d ",x);
	         }break;
	  case 5:{
		      printf("Enter position from top (0 = top): ");
			  scanf("%d",&pos);
		      x=peep(st,top,pos);
			  if(x==-1)printf("Invalid position!");
			  else printf("Element at position %d is..%d ",pos,x);
	         }break;

	default: exit(0);
  	}
  }
}

void push(int s[],int *t,int x)
{
 if((*t)==size-1)printf("Stack Full ");
 else {
	    (*t)++;
		s[*t]=x;	 
      }
}

void display(int s[],int t)
{ int i;
	if((t)==-1)printf("Empty Stack");
	else {
		for(i=t;i>=0;i--)
	printf("\t%d",s[i]);
	}
}

int pop(int s[],int *t)
{
	int x=-1;
	if((*t)==-1)return x;
	 x=s[*t];
	 (*t)--;
	return x;
}

int seek(int s[], int *t)
{
	return s[*t]; 	
}

int peep(int s[], int t, int pos)
{
    if (t == -1) return -1;  // Stack empty
    if (pos < 0 || pos > t) return -1;  // Invalid position
    
    return s[t - pos];
}
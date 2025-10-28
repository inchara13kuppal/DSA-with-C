#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node *next;
}NODE;

NODE* frontins(NODE *,int );
NODE* endins(NODE *,int);
NODE* frontdel(NODE *);
NODE* enddel(NODE *);
NODE* posins(NODE *, int, int);
NODE* posdel(NODE *, int);
void display(NODE *);

//Main driver code
void main()
{
	NODE *list;
	int x,choice,temp,pos;
	
	list=NULL;
	 while(1)
	 {
		 printf("\nEnter 1->Front Insertion\n2->end Insertion\n3->Front Deletion\n");
		 printf("4->end Deletion\n5->Display\n6->Position insertion\n7->Position deletion\n8->Exit");
		 printf("\n Enter your choice :");
		 scanf("%d",&choice);
		 
		 switch(choice)
		 {
			case 1: {
				printf("Enter the value ");
	            scanf("%d", &x);
				list=frontins(list,x);
			    }break;
			case 2: {
				printf("Enter the value ");
	            scanf("%d", &x);
				list=endins(list,x);
			    }break;
			case 3: {
				list=frontdel(list);
			    }break;
			case 4: {
				list=enddel(list);
			    }break;				
			case 5:{
					printf("\nThe list contains...");
					display(list);
				}break;
            case 6: {
                printf("Enter the value: ");
                scanf("%d", &x);
                printf("Enter the position: ");
                scanf("%d", &pos);
                list = posins(list, x, pos);
                break;
            }
            case 7: {
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                list = posdel(list, pos);
                break;
            }
			default: exit(0);
		 }
	 }	
}

 NODE* frontins(NODE *list,int x)
  {
	NODE *newnode, *temp;
	  
    newnode = (NODE *)(malloc(sizeof(NODE)));
	newnode->info=x;
	newnode->next=newnode;
	
	if(list==NULL)list=newnode;
	else {
		temp = list;
		while (temp -> next != list)
		temp = temp ->next;
		
	newnode->next=list;
	temp->next=newnode; //to connect to last node 
	list=newnode;
	}
	return list;
  }

  //front deletion
  NODE* frontdel(NODE *list)
  { NODE *temp,*temp1;
	if(list==NULL)printf("Empty List");

	else if(list->next==list) list=NULL;

	else {temp=list;
		temp1=temp;
	while(temp1->next!=list)
		temp1=temp1->next;

		temp1->next=list->next;
		list=list->next;
	}
	free(temp);
	return list;
  }

  //end insertion
  NODE* endins(NODE *list,int x)
  {
	NODE *newnode, *temp;
	  
    newnode = (NODE *)(malloc(sizeof(NODE)));
	newnode->info=x;
	newnode->next=newnode;
	
	if(list==NULL)list=newnode;
	else {
		temp = list;
		while (temp -> next != list)
		temp = temp ->next;
	newnode->next=list;
	temp->next=newnode; //to connect to last node 
	}
	return list;
  }

  //end deletion
  NODE* enddel(NODE *list)
  { NODE *temp,*prev;
	if(list==NULL)printf("Empty List");
	else if(list->next==list) list=NULL;
	else {
    temp = list;
    prev = NULL;
	while(temp->next!=list)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=list;
	}
	free(temp);
	return list;
  }

void display(NODE *list)
{
    NODE *temp;
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = list;
    printf("\n%d -> ", temp->info);
    temp = temp->next;
    while (temp != list) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("(back to start)\n");
}

//position insertion and position deletion assignment 

NODE* posins(NODE *list, int x, int pos)
{
    NODE *newnode, *temp, *last;
    int i = 1;
    if (pos < 1) {
        printf("Invalid position\n");
        return list;
    }

    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    newnode->next = NULL;

    if (list == NULL) {
        if (pos == 1) {
            newnode->next = newnode;
            list = newnode;
            return list;
        } else {
            printf("Invalid position for empty list\n");
            free(newnode);
            return list;
        }
    }

    if (pos == 1) {
        temp = list;
        while (temp->next != list) {
            temp = temp->next;
        }
        newnode->next = list;
        temp->next = newnode;
        list = newnode;
        return list;
    }
    temp = list;
    i = 1;
    while (temp->next != list && i < pos - 1) {
        temp = temp->next;
        i++;
    }
    if (i < pos - 1) {
        printf("Invalid position\n");
        free(newnode);
        return list;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return list;
}

//position deletion
NODE* posdel(NODE *list, int pos)
{
    NODE *temp, *prev, *toDelete;
    int i = 1;
    if (pos < 1) {
        printf("Invalid position\n");
        return list;
    }
    if (list == NULL) {
        printf("List is empty\n");
        return list;
    }
    if (list->next == list) {
        if (pos == 1) {
            free(list);
            return NULL;
        } else {
            printf("Invalid position\n");
            return list;
        }
    }
    if (pos == 1) {
        temp = list;
        while (temp->next != list) {
            temp = temp->next;
        }
        toDelete = list;
        list = list->next;
        temp->next = list;
        free(toDelete);
        return list;
    }
    temp = list;
    prev = NULL;
    i = 1;
    while (temp->next != list && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (i == pos) {
        prev->next = temp->next;
        free(temp);
        return list;
    }
    printf("Invalid position\n");
    return list;
}
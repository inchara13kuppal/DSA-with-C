#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node *next;
}NODE;

//prototype

NODE* frontins(NODE *,int );
NODE* endins(NODE *,int);
NODE* frontdel(NODE *);
NODE* enddel(NODE *);
void display(NODE *);
NODE* posins(NODE *,int,int);
NODE* posdel(NODE *, int);
NODE* orderins(NODE *, int);

//Main driver code
void main()
{
	NODE *list;
	int x,choice;
	
	list=NULL;
	 while(1)
	 {
		 printf("\nEnter 1->Front Insertion\n2->end Insertion\n3->Front Deletion\n");
		 printf("4->end Deletion\n5->Display\n6->Position Insertion\n7->Position Deletion\n8->Ordered Insertion\n9->Exit");
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
   					int pos, val;
					printf("Enter position to insert: ");
					scanf("%d", &pos);
					printf("Enter the value: ");
					scanf("%d", &val);
					list = posins(list, val, pos);
				} break;

			case 7: {
    			printf("Enter position to delete: ");
    			scanf("%d", &x);
    			list = posdel(list, x);
    			} break;
			case 8: {
    			printf("Enter the value for ordered insertion: ");
    			scanf("%d", &x);
    			list = orderins(list, x);
    			} break;
			default: exit(0);
		 }
	
	 }	
}

 NODE* frontins(NODE *list,int x)
  {
	NODE *newnode;
    newnode = (NODE *)(malloc(sizeof(NODE)));
	newnode->info=x;
	newnode->next=NULL;
	
	if(list==NULL)list=newnode;
	else {
		newnode->next=list;
		list=newnode;
	}
	return list;
  }
  
  NODE* endins(NODE *list,int x)
  {
	NODE *newnode, *temp;
	  
    newnode = (NODE *)(malloc(sizeof(NODE)));
	newnode->info=x;
	newnode->next=NULL;
	
	if(list==NULL)list=newnode;
	else { temp=list;
		while(temp->next!=NULL)
			temp=temp->next;
		
		temp->next=newnode;
	}
	return list;
  }
  
NODE* frontdel(NODE *list)
  { NODE *temp;
	if(list==NULL)printf("Empty List");
	else {
		temp=list;
		list=list->next;
		free(temp);
	}
	return list;
  }
  
NODE* enddel(NODE *list)
  { NODE *temp, *prev;
    temp=list;
	if(list==NULL)printf("Empty List");
	else if(list->next==NULL){list=NULL;
	                          free(temp);
							  }
	else { 
		while(temp->next!=NULL)
		{   prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		free(temp);
	}
	return list;
  }
  
void display(NODE *list)
{NODE *temp;
	 if(list==NULL)printf("Empty List");
	 else{
		temp=list;
		while(temp!=NULL)
		{   printf("\t%d",temp->info);
			temp=temp->next; 
	    }
	 }
}

NODE* posins(NODE *list,int x, int pos)
{
    NODE *newnode, *temp;
    int i = 1;

    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = x;
    newnode->next = NULL;

    if (pos == 1) {
        newnode->next = list;
        list = newnode;
        return list;
    }

    temp = list;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }//prev node of mentioned pos will be temp

    if (temp == NULL) {
        printf("Invalid Position");
        free(newnode);
        return list;
    }
//takes care of next field of prev position node
    newnode->next = temp->next;
    temp->next = newnode;
    return list;
}


// Position deletion function
NODE* posdel(NODE *list, int pos) {
    NODE *temp = list, *prev = NULL;
    int i = 1;
    if (list == NULL) {
        printf("Empty List");
        return list;
    }
    if (pos == 1) {
        list = list->next;
        free(temp);
        return list;
    }
    while (temp != NULL && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
        printf("Invalid Position");
    else {
        prev->next = temp->next;
        free(temp);
    }
    return list;
}

// Ordered insertion function
NODE* orderins(NODE *list, int x) {
    NODE *newnode, *temp = list, *prev = NULL;

	newnode= (NODE*)malloc(sizeof(NODE));
    newnode->info = x;
    newnode->next = NULL;

    if (list == NULL || x < list->info) {
        newnode->next = list;
		list = newnode;
        return list;
    }
    while (temp != NULL && x >= temp->info) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = temp;
    return list;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
	int info;
	struct dnode *left,*right;

}DNODE;

DNODE* frontins(DNODE *,int );
DNODE* endins(DNODE *,int);
DNODE* frontdel(DNODE *);
void display(DNODE *);
DNODE* succnodeins(DNODE *,int,int);
DNODE* succnodedel(DNODE *, int); //prenode ?? crete the function for this
DNODE* posins(DNODE *, int, int);
DNODE* posdel(DNODE *, int);
DNODE* orderins(DNODE *, int);

void main()
{
	DNODE *dlist;
	int x,choice,succ;
	
	dlist=NULL;
	 while(1)
	 {
		 printf("\nEnter 1->Front Insertion\n2->end Insertion\n3->Display\n4->Front Deletion\n5->Successor Insertion\n6->Successor Deletion\n7->Position Insertion\n8->Position Deletion\n9->Ordered Insertion");
         printf("\n Enter your choice :");
		 scanf("%d",&choice);
		 
		 switch(choice)
		 {
			case 1: {
				printf("Enter the value ");
	            scanf("%d", &x);
				dlist=frontins(dlist,x);
			    }break;
			case 2: {
				printf("Enter the value ");
	            scanf("%d", &x);
				dlist=endins(dlist,x);
			    }break;

            case 3:{
					printf("\nThe list contains...");
					display(dlist);
				}break;

            case 4: {
				dlist=frontdel(dlist);
			    }break;	

			case 5:{
				printf("Enter the value and (space) successor node info: ");
				scanf("%d %d", &x, &succ);
				dlist=succnodeins(dlist,x,succ);
				}break;
			
			case 6:{
				printf("Successor node value deletion: ");
				scanf("%d",&succ);
				dlist=succnodedel(dlist,succ);
				}break;

			case 7: {
				int pos;
				printf("Enter the value and position: ");
				scanf("%d %d", &x, &pos);
				dlist = posins(dlist, x, pos);
				}break;

			case 8: {
				int pos;
				printf("Enter the position to delete: ");
				scanf("%d", &pos);
				dlist = posdel(dlist, pos);
				}break;

			case 9: {
				int x;
				printf("Enter the value to insert in order: ");
				scanf("%d", &x);
				dlist = orderins(dlist, x);
				}break;

            default: exit(0);
        }
     }
}

DNODE* frontins(DNODE *dlist,int x)
{
	DNODE *newnode;
	  
    newnode = (DNODE *)(malloc(sizeof(DNODE)));
	newnode->info=x;
	newnode->left=NULL;
    newnode->right=NULL;
	
	if(dlist==NULL)dlist=newnode;
	else {
		newnode->right=dlist;
        dlist->left=newnode;
		dlist=newnode;
	}
	return dlist;
}

DNODE* endins(DNODE *dlist,int x)
  {
	DNODE *newnode, *temp;
	  
    newnode = (DNODE *)(malloc(sizeof(DNODE)));
	newnode->info=x;
	newnode->right=NULL;
	newnode->left=NULL;

	if(dlist==NULL)dlist=newnode;
	else { temp=dlist;
		while(temp->right!=NULL)
			temp=temp->right;
		
		temp->right=newnode;
        newnode->left=temp;
	}
	return dlist;
}

DNODE* frontdel(DNODE *dlist)
  {DNODE *temp;
    temp=dlist;
	if(dlist==NULL)printf("Empty List");
    else if(dlist->right==NULL) dlist=NULL;
	else {
		temp=dlist;
		dlist=dlist->right;
        dlist->left=NULL;
	}
    free(temp);
	return dlist;
  }

void display(DNODE *dlist)
{DNODE *temp;
	 if(dlist==NULL)printf("Empty List");
	 else{
		temp=dlist;
		while(temp!=NULL)
		{   printf("\t%d",temp->info);
			temp=temp->right; 
	    }
	 }
	 
}

DNODE* succnodeins(DNODE *dlist, int x, int succ)
{
    DNODE *newnode, *temp;

    newnode = (DNODE *)malloc(sizeof(DNODE));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (dlist == NULL) {
        printf("List is empty. Cannot insert before successor.\n");
        free(newnode);
        return dlist;
    }

    temp = dlist;
    while (temp != NULL && temp->info != succ)
        temp = temp->right;

    if (temp == NULL) {
        printf("Successor node not found.\n");
        free(newnode);
        return dlist;
    }

    newnode->right = temp;
    newnode->left = temp->left;

    if (temp->left != NULL)
        temp->left->right = newnode;
    else
        dlist = newnode;
    temp->left = newnode;
    return dlist;
}


  DNODE* succnodedel(DNODE *dlist, int succ)//end deletion is not possible and front deletion is possible
  {
	DNODE *temp;
	temp=dlist;
	if(dlist==NULL)printf("Empty List");
	if((dlist->right)->info==succ)
	{
		dlist=dlist->right;
		dlist->left=NULL;
	}
	else
	  { temp=dlist;
	   while(temp->right!=NULL && ((temp->right)->info)!=succ) 
		 temp=temp->right;
	 
	   if((temp->right)->info==succ)
	   {
		   (temp->left)->right=temp->right;
		   (temp->right)->left=temp->left;
	   }
	 else printf("Invalid  Successor node info");
	  }
	  free(temp);
	  return dlist;
  }

DNODE* posins(DNODE *dlist, int x, int pos)
{
    DNODE *newnode, *temp;
    int i = 1;

    newnode = (DNODE *)malloc(sizeof(DNODE));
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (pos == 1) {
        newnode->right = dlist;
        if (dlist != NULL)
            dlist->left = newnode;
        dlist = newnode;
        return dlist;
    }

    temp = dlist;
    while (temp != NULL && i < pos - 1) {
        temp = temp->right;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position\n");
        free(newnode);
        return dlist;
    }

    newnode->right = temp->right;
    newnode->left = temp;

    if (temp->right != NULL)
        temp->right->left = newnode;

    temp->right = newnode;

    return dlist;
}

DNODE* posdel(DNODE *dlist, int pos)
{
    DNODE *temp;
    int i = 1;

    if (dlist == NULL) {
        printf("List is empty\n");
        return dlist;
    }

    temp = dlist;
    if (pos == 1) {
        dlist = dlist->right;
        if (dlist != NULL)
            dlist->left = NULL;
        free(temp);
        return dlist;
    }

    while (temp != NULL && i < pos) {
        temp = temp->right;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position\n");
        return dlist;
    }

    if (temp->left != NULL)
        temp->left->right = temp->right;

    if (temp->right != NULL)
        temp->right->left = temp->left;

    free(temp);
    return dlist;
}

DNODE* orderins(DNODE *dlist, int x)
{
    DNODE *newnode = (DNODE*)malloc(sizeof(DNODE));
    DNODE *temp = dlist, *prev = NULL;

    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (dlist == NULL || x < dlist->info) {
        newnode->right = dlist;
        if (dlist != NULL)
            dlist->left = newnode;
        dlist = newnode;
        return dlist;
    }

    while (temp != NULL && x >= temp->info) {
        prev = temp;
        temp = temp->right;
    }

    prev->right = newnode;
    newnode->left = prev;
    newnode->right = temp;

    if (temp != NULL)
        temp->left = newnode;

    return dlist;
}

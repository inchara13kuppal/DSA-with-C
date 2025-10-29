#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
    int info;
    struct dnode *left,*right;

}DNODE;

// Function Prototypes
DNODE* frontins(DNODE *,int );
DNODE* endins(DNODE *,int);
DNODE* frontdel(DNODE *);
void display(DNODE *);
DNODE* succnodeins(DNODE *,int,int);
DNODE* succnodedel(DNODE *, int); 
DNODE* prenodeins(DNODE *,int,int);
DNODE* posins(DNODE *, int, int);
DNODE* posdel(DNODE *, int);
DNODE* orderins(DNODE *, int);

void main()
{
    DNODE *dlist;
    int x,choice,val;
    
    dlist=NULL;
      while(1)
      {
          printf("\n--- Doubly Linked List Menu ---\n");
          printf("1->Front Insertion\n2->End Insertion\n3->Display\n4->Front Deletion\n5->Successor Insertion (Insert BEFORE a node)\n6->Successor Deletion (Delete node with specified info)\n7->Position Insertion\n8->Position Deletion\n9->Ordered Insertion\n10->Predecessor Insertion (Insert AFTER a node)\n11->Exit");
          printf("\n Enter your choice :");
          scanf("%d",&choice);
          
          switch(choice)
          {
             case 1: {
                  printf("Enter the value: ");
                  scanf("%d", &x);
                  dlist=frontins(dlist,x);
                  }break;
             case 2: {
                  printf("Enter the value: ");
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
                  printf("Enter the value to insert and (space) successor node info (insert BEFORE): ");
                  scanf("%d %d", &x, &val);
                  dlist=succnodeins(dlist,x,val);
                  }break;
              
             case 6:{
                  printf("Enter the node info to delete: ");
                  scanf("%d",&val);
                  dlist=succnodedel(dlist,val);
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
                  printf("Enter the value to insert in order: ");
                  scanf("%d", &x);
                  dlist = orderins(dlist, x);
                  }break;

             case 10: { //CASE for Predecessor Insertion
                  printf("Enter the value to insert and (space) predecessor node info (insert AFTER): ");
                  scanf("%d %d", &x, &val);
                  dlist = prenodeins(dlist, x, val);
                  }break;

             default: exit(0);
          }
      }
}

// ----------------------------------------------------------------------
// CORRECTED Functions for Non-Circular Doubly Linked List
// ----------------------------------------------------------------------

DNODE* frontins(DNODE *dlist,int x)
{
    DNODE *newnode;
      
    newnode = (DNODE *)(malloc(sizeof(DNODE)));
    if (newnode == NULL) return dlist;
    newnode->info=x;
    newnode->left=NULL;
    newnode->right=NULL;
    
    if(dlist==NULL) // List is empty
    {
        dlist=newnode;
    }
    else { // List is not empty
        newnode->right = dlist;
        dlist->left = newnode;
        dlist = newnode; // newnode becomes the new head
    }
    return dlist;
}

DNODE* endins(DNODE *dlist,int x)
{
    DNODE *newnode, *temp;
      
    newnode = (DNODE *)(malloc(sizeof(DNODE)));
    if (newnode == NULL) return dlist;
    newnode->info=x;
    newnode->right=NULL;
    newnode->left=NULL;

    if(dlist==NULL) // List is empty
    {
        dlist=newnode;
    }
    else { 
        temp = dlist;
        while(temp->right != NULL) { // Traverse to the last node
            temp = temp->right;
        }
        // Insert newnode after temp
        temp->right = newnode;
        newnode->left = temp;
    }
    return dlist;
}

DNODE* frontdel(DNODE *dlist)
{
    DNODE *temp;
    
    if(dlist==NULL){
        printf("Empty List\n");
        return NULL;
    }
    
    temp = dlist; // temp points to the node to be deleted

    if(dlist->right==NULL) { // Only one node in the list
        dlist = NULL;
    }
    else {
        dlist = dlist->right; // New head
        dlist->left = NULL;
    }
    
    printf("Deleted node: %d\n", temp->info);
    free(temp);
    return dlist;
}

DNODE* succnodedel(DNODE *dlist, int succ)
{
    DNODE *temp;
    
    if(dlist==NULL){
        printf("Empty List\n");
        return NULL;
    }

    temp = dlist;
    // Find the node to delete
    while(temp != NULL && temp->info != succ) {
        temp = temp->right;
    }

    if (temp == NULL) {
        printf("Node with info %d not found.\n", succ);
        return dlist;
    }

    // temp is the node to delete
    if (temp == dlist) { // Deleting the head node
        dlist = dlist->right;
        if (dlist != NULL)
            dlist->left = NULL;
    } else { 
        // Update the predecessor's right pointer
        if (temp->left != NULL)
            temp->left->right = temp->right;

        // Update the successor's left pointer
        if (temp->right != NULL)
            temp->right->left = temp->left;
    }
    
    printf("Deleted node: %d\n", temp->info);
    free(temp);
    return dlist;
}

// ----------------------------------------------------------------------
// NEWLY ADDED Function: Predecessor Node Insertion (Inserts AFTER)
// ----------------------------------------------------------------------

DNODE* prenodeins(DNODE *dlist, int x, int pred)
{
    DNODE *newnode, *temp;

    newnode = (DNODE *)malloc(sizeof(DNODE));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return dlist;
    }
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (dlist == NULL) {
        printf("List is empty. Cannot insert after predecessor.\n");
        free(newnode);
        return dlist;
    }

    // Find the predecessor node
    temp = dlist;
    while (temp != NULL && temp->info != pred) {
        temp = temp->right;
    }

    if (temp == NULL) {
        printf("Predecessor node not found.\n");
        free(newnode);
        return dlist;
    }
    
    // temp is the predecessor node. Insert newnode after temp.
    newnode->right = temp->right;
    newnode->left = temp;

    if (temp->right != NULL)
        temp->right->left = newnode;

    temp->right = newnode;
    
    return dlist;
}

// ----------------------------------------------------------------------
// Original Functions (Correct)
// ----------------------------------------------------------------------

void display(DNODE *dlist)
{DNODE *temp;
     if(dlist==NULL)printf("Empty List\n");
     else{
         temp=dlist;
         while(temp!=NULL)
         {   printf("\t%d",temp->info);
             temp=temp->right; 
         }
         printf("\n");
     }
     
}

DNODE* succnodeins(DNODE *dlist, int x, int succ)
{
    DNODE *newnode, *temp;

    newnode = (DNODE *)malloc(sizeof(DNODE));
    if (newnode == NULL) return dlist;
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

    // temp is the successor node. Insert newnode before temp.
    newnode->right = temp;
    newnode->left = temp->left;

    if (temp->left != NULL)
        temp->left->right = newnode;
    else // Inserting before the head
        dlist = newnode;
    
    temp->left = newnode;
    return dlist;
}

DNODE* posins(DNODE *dlist, int x, int pos)
{
    DNODE *newnode, *temp;
    int i = 1;

    newnode = (DNODE *)malloc(sizeof(DNODE));
    if (newnode == NULL) return dlist;
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
    // Stop at the node BEFORE the desired insertion position
    while (temp != NULL && i < pos - 1) { 
        temp = temp->right;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position\n");
        free(newnode);
        return dlist;
    }

    // Insert newnode between temp and temp->right
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
    if (pos == 1) { // Deleting the first node
        dlist = dlist->right;
        if (dlist != NULL)
            dlist->left = NULL;
        printf("Deleted node: %d\n", temp->info);
        free(temp);
        return dlist;
    }

    // Stop at the node to be deleted
    while (temp != NULL && i < pos) {
        temp = temp->right;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position\n");
        return dlist;
    }

    // Link the predecessor to the successor
    if (temp->left != NULL)
        temp->left->right = temp->right;

    // Link the successor to the predecessor
    if (temp->right != NULL)
        temp->right->left = temp->left;

    printf("Deleted node: %d\n", temp->info);
    free(temp);
    return dlist;
}

DNODE* orderins(DNODE *dlist, int x)
{
    DNODE *newnode = (DNODE*)malloc(sizeof(DNODE));
    DNODE *temp = dlist, *prev = NULL;

    if (newnode == NULL) return dlist;
    newnode->info = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (dlist == NULL || x < dlist->info) { // Insert at the front
        newnode->right = dlist;
        if (dlist != NULL)
            dlist->left = newnode;
        dlist = newnode;
        return dlist;
    }

    // Find the position for ordered insertion
    while (temp != NULL && x >= temp->info) {
        prev = temp;
        temp = temp->right;
    }

    // Insert newnode between prev and temp
    prev->right = newnode;
    newnode->left = prev;
    newnode->right = temp;

    if (temp != NULL)
        temp->left = newnode;

    return dlist;
}
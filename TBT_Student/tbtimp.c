#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    //TODO
 
    tree->root =NULL;
    

}

void tree_insert(Tree *tree, int data)
{
    //TODO
    Node *temp,*curr,*p;
    curr=tree->root;
    temp=(Node *)(malloc(sizeof(Node)));
	temp->data = data;
	temp->leftThread = 1;
	temp->rightThread = 1;
	temp->left=NULL;
	temp->right=NULL;

    if(curr==NULL) tree->root=temp;//inserting a root node
    while(curr != NULL)
	{   
		if(data < curr->data)
		{ 
		  if(curr->leftThread==0)
			  curr=curr->left;
		  else break;	
		}
		else {
			if(curr->rightThread==0)
			  curr=curr->right;
		    else break;	
		}
	}
	//Assign the node
	if(data < curr->data)
	{
	  temp->left=curr->left;
	  temp->right=curr;
	  curr->leftThread=0;
	  curr->left=temp;
	}
	else {
	  temp->right=curr->right;
	  temp->left=curr;
	  curr->rightThread=0;
	  curr->right=temp;
	}
	

}

Node *inorder_predecessor(Node *ptr)
{
  if(ptr->leftThread==1) return ptr->left;
   ptr=ptr->left;
   while(ptr->rightThread==0)   // go to the left most node in the tree.
	  ptr=ptr->right;
  return ptr;
}

Node *inorder_successor(Node *ptr)
{
   //TODO
   if(ptr->rightThread==1) return ptr->right;
   ptr=ptr->right;
   while(ptr->leftThread==0)   // go to the left most node in the tree.
	  ptr=ptr->left;
  return ptr;
}

void print_ascending(Tree *tree)
{ Node *curr;
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
     curr=tree->root;
	  while(curr->leftThread==0)
		  curr=curr->left;
	  
	  while(curr !=NULL)
	  {
		  printfun(curr->data);
		  curr=inorder_successor(curr);
	  }  
       nextline();
}


    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement


void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
Node *curr;
    
    curr=tree->root;
	while(curr->rightThread==0)
		curr=curr->right;
	  
	while(curr !=NULL)
	  {
		  printfun(curr->data);
		  curr=inorder_predecessor(curr);
	  }  
    nextline();  
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement  
}

void destroy(Node *r)
{
    //TODO
    if(r==NULL) return;
    destroy(r->left);
    destroy(r->right);
    free(r);

}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}

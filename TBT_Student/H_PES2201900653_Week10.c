#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"
//PES2201900653
void tree_initialize(Tree *tree)
{
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    //TODO
	Node* curr,*temp;
	curr=tree->root;
	
	temp=(Node*)(malloc(sizeof(Node)));
	temp->data = data;
	temp->leftThread = 1;
	temp->rightThread = 1;
	temp->left=NULL;
	temp->right=NULL;
	
	if(curr==NULL) tree->root=temp;
	
	else
	{
	while(curr != NULL)
	{
		if(data < curr->data)//left tree
		{
		  if(curr->leftThread==0)//not found(something already attached over there) where to insert
			  curr=curr->left;
		  else break;	
		}
		else {
			if(curr->rightThread==0)//right tree 
			  curr=curr->right;
		    else break;	 //found so now go assign
		}
	}
	
	//Assign the node
	if(data < curr->data)
	{
	  temp->left=curr->left;//since ur connecting whatever curr of left has now temp of left should have which is basically null 
	  temp->right=curr;
	  curr->leftThread=0;
	  curr->left=temp;
	}
	else {
	  temp->right=curr->right;
	  temp->left=curr;
	  curr->rightThread=0;//now it has inordr succ so -99 
	  curr->right=temp;
	}
	}
}

Node *inorder_predecessor(Node *ptr)
{
   if(ptr->leftThread== 1) 
	  return ptr->left;  
  ptr=ptr->left;
  while(ptr->rightThread==0)   
	  ptr=ptr->right;
  return ptr;
}

Node *inorder_successor(Node *ptr)
{
	if(ptr->rightThread== 1) 
	  return ptr->right;  
  ptr=ptr->right;
  while(ptr->leftThread==0)   
	  ptr=ptr->left;//to find leftmost 
  return ptr;
}

void print_ascending(Tree *tree)
{
	Node *curr;
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
	else 
	{ 
	  curr=tree->root;
	  while(curr->leftThread==0)//to reach leftmost node in left subtree 
		  curr=curr->left;
	  
	  while(curr !=NULL)
	  {
		  printfun(curr->data);
		  curr=inorder_successor(curr);
	  }  
	  nextline();
     }  

    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void print_descending(Tree *tree)
{
	Node *curr;
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
	else 
	{ 
	  curr=tree->root;
	  while(curr->rightThread==0)
		  curr=curr->right;
	  
	  while(curr !=NULL)
	  {
		  printfun(curr->data);
		  curr=inorder_predecessor(curr);
	  }  
	   nextline();
     }  
	
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement  
}

void destroy(Node *r)
{
    
	if(r == NULL);//Empty tree 
	
	if(r->right == NULL && r->left == NULL)//single node 

	{
		free(r);
		return;
	}

	if(r->left != NULL)
		destroy(r->left);

	if(r->right != NULL)
		destroy(r->right);
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
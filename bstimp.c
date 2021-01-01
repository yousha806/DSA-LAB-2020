#include<stdio.h>
#include "bst.h"


void tree_initialize(Tree *tree)
{
  tree->root=NULL;    //sdafsdf
    //TODO 
}

void tree_insert(Tree *tree, int data)
{ 
  
  Node *new_node;
	Node *previous, *current;


	
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=data;
	new_node->left=new_node->right=NULL;
	


	if( tree->root==NULL)
	  tree->root=new_node;

	else
	{
	 current = tree->root;
	 previous=NULL;
	 
	 while(current!=NULL)
	 {
		 previous=current;
		 if(data<current->data)
			 current=current->left; 
		 else
			 current=current->right;
	 }
	if(data <previous->data)
		previous->left=new_node;
	else
		previous->right=new_node;
	}


// TODO : Insert element to create a BST
}


void tree_delete(Tree *tree, int element)
{

  Node *current, *temporary, *previous, *abc, *xyz;
	previous=NULL;


	current=tree->root;


	while((current!=NULL)&&(current->data!=element))
	{
		previous=current;
		if(element<current->data)
			current=current->left;
		else
			current=current->right;
	}



	if(current==NULL)
	{
		return;
	}
	
	// if node has one subtree or no subtrees
	if((current->left==NULL)||(current->right==NULL))
	{
		if(current->left==NULL)
			xyz=current->right;
		else
			xyz=current->left;
		
		//deleting root with one subtree
		if(previous==NULL)
		{
			free(current);
			
		}


		if(current==previous->left)
			previous->left =xyz;
		else
			previous->right=xyz;

      
		free(current);
	}


	else
	{
		//two subtrees present
		abc=NULL; //parent of inorder successor
	   	 temporary=current->right;
		while(temporary->left!=NULL)
		{
			abc=temporary;
			temporary=temporary->left;
		}
		current->data=temporary->data;
		if(abc!=NULL)
			abc->left=temporary->right;
		else
			current->right=temporary->right;
		free(temporary);
	}

   // TODO : Delete elements from BST   
}

void tree_inorder(Node *r)
{
  if(r!=NULL)
	{
	    tree_inorder(r->left);
      printf("%d ", r->data);
	    tree_inorder(r->right);
	}
 	//TODO :  use printf to print inorder 
}

void tree_preorder(Node *r)
{
  if(r!=NULL)
  {
    printf("%d ",r->data);
    tree_preorder(r->left);
    tree_preorder(r->right);

  }
    //TODO :  use printf to print preorder
}

void tree_postorder(Node *r)
{
    if(r!=NULL)
    {
      tree_postorder(r->left);
      tree_postorder(r->right);
      printf("%d ",r->data);
    }
    //TODO :  use printf to print postorder
}

void postorder(Tree *t)
{ 
  
  tree_postorder(t->root);
  printf("\n");
   //TODO
}

void preorder(Tree *t)
{
  
  tree_preorder(t->root);
  printf("\n");
     //TODO
}

void inorder(Tree *t)
{
  tree_inorder(t->root);
  printf("\n");
  //TODO   
}

void destroy(Node *r)
{ 
  if(!r) { return;}   //------------------sfdjflkajlfj
  destroy(r->left);
  
  destroy(r->right); //fsdagfsdh
  
  free(r);
  //TODO  
}

void tree_destroy(Tree *t)
{ 
  
  destroy(t->root);
  //-------------------------------------------------------
  
}

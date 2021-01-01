#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{    //tree=(Tree *)malloc(sizeof(Tree));
     tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
// TODO : Insert element to create a BST
  Node *temp,*p;int flag=1;
  temp=(Node *)malloc(sizeof(Node));
  temp->left=NULL;
  temp->right=NULL;
  temp->data=data;

  if(tree->root==NULL)tree->root=temp;//inserting root node
  else{p=tree->root;
  while(flag){
    if(data<p->data){
      if(p->left==NULL){
        p->left=temp;
        flag=0;
      }
      else p=p->left;}
     else{
       
      if(p->right==NULL){
        p->right=temp;
        flag=0;
      }
      else p=p->right;
    
  }
}}}
void tree_delete(Tree *tree, int element)
{
   // TODO : Delete elements from BST   
   Node *temp,*q,*parent,*insucc;
	q=NULL;
	temp=tree->root;
	parent=NULL;
	

		while(temp!=NULL && temp->data!=element)
		{
			parent=temp;
			if(element<temp->data)
				temp=temp->left;
			else temp=temp->right;
		}
		
	if (temp==NULL)	return;
  else if(temp->left==NULL)q=temp->right; 
	else if(temp->right==NULL)q=temp->left; 
	else { 
	  
		insucc=temp->right;
		while(insucc->left!=NULL)
			insucc=insucc->left;
		
		insucc->left = temp->left;
		           q = temp->right;
		}
		
		
		if(parent==NULL)
		    tree->root = q;
		else if(temp==parent->left)parent->left =q;
		else if(temp==parent->right)parent->right=q;
		   free(temp);

}

void tree_inorder(Node *r)
{
 	//TODO :  use printf to print inorder 
   if(r!=NULL)
	{
	  tree_inorder(r->left);
	  printf("%d ",r->data);
	  tree_inorder(r->right);
   }
}

void tree_preorder(Node *r)
{
    //TODO :  use printf to print preorder
   if(r!=NULL)
	{
	 printf("%d ",r->data);
   tree_preorder(r->left);
	 tree_preorder(r->right);
  }
}

void tree_postorder(Node *r)
{
    //TODO :  use printf to print postorder
    if(r!=NULL)
	{
	 tree_postorder(r->left);
	 tree_postorder(r->right);
	 printf("%d ",r->data);
	}
}

void postorder(Tree *t)
{
   //TODO
   tree_postorder(t->root);
   printf("\n");

}

void preorder(Tree *t)
{
     //TODO
     tree_preorder(t->root);
	 printf("\n");
}

void inorder(Tree *t)
{
  //TODO
    tree_inorder(t->root); 
	printf("\n");
}


void destroy(Node *r)
{
  //TODO  
  if(r!=NULL){
    destroy(r->left);
    destroy(r->right);
    free(r);
    if(r->left!=NULL){
      r->left=NULL;
    }
    if(r->right!=NULL){
      r->right=NULL;
    }
    r=NULL;
  }
}

void tree_destroy(Tree *t)
{ 
//TODO  
destroy(t->root);
  
 
}

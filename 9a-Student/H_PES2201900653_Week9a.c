#include "et.h"

Node * createExpressionTree(char* a,int len)
{
    //TODO
  char ch;
	Node *stk[len];
	int top=-1;
	int i=0;
	
	Node *temp,*p,*end;
	
	while(a[i]!='\0')
	{
      ch=a[i];
      temp=(Node *)malloc(sizeof(Node));	  
	  temp->left=temp->right=NULL;
	  temp->data = ch;
		
	  if((ch=='*'||ch=='/'||ch=='+'||ch=='-'))
	  {
	  p=stk[top];
	  (top)--;
		temp->right=p;
    p=stk[top];
	  (top)--;
		temp->left=p;
    (top)++;
    stk[top]=temp;
	  }	
     else 	{
       (top)++;
       stk[top]=temp;}
            i++;	 
	}
  end=stk[top];
  (top)--;
	return end;
}


void inorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
 if(root!=NULL)
  {inorder(root->left);
  printf("%c",root->data); 
  inorder(root->right);}
}

void preorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
 if(root!=NULL){
 
  printf("%c",root->data); 
  preorder(root->left);
 preorder(root->right);  
}}

void postorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
 if(root!=NULL){
   postorder(root->left);
  postorder(root->right);
  printf("%c",root->data);
  
}}

void freeTree(Node *root)
{
  if(root==NULL) return;
  freeTree(root->right);
  freeTree(root->left);

}


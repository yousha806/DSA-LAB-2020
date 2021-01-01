#include<stdio.h>
#include "trie.h"
struct trienode *getnode()
  {
    //TODO
    struct trienode *new;
    int i;
    new=(struct trienode *)malloc(sizeof(struct trienode));
    for(i=0;i<26;i++)
      new->child[i]=NULL;
    new->endofword=0;
    return new;
  }

  void insert(struct trienode *root, char *key)
  {
     //TODO
  struct trienode *curr;
  int i, index;
  
  curr = root;
  for(i=0;key[i]!='\0';i++)
   { index=key[i]-'a';
	    if(curr->child[index]==NULL)
		    curr->child[index]=getnode();
	  curr=curr->child[index];
   }
  curr->endofword=1;
  }

void display(struct trienode *curr)
{int i,j;

	for(i=0;i<26;i++)
	{
		if(curr->child[i]!=NULL)
		{
			word[length++]=i+97;
			if(curr->child[i]->endofword==1)
			{
				//print the word
				printnewline();
				for(j=0;j<length;j++)
					printfun(word[j]);
			}
			display(curr->child[i]);
		}
	}
	length--;
	return;
}


int search(struct trienode * root, char *key)
{
 int i,index;	
 struct trienode *curr;
 curr=root;
  for(i=0;key[i]!='\0';i++)
   { index=key[i]-'a';
	  if(curr->child[index]==NULL)
		  return 0;
	  curr=curr->child[index];
   }
   if(curr->endofword==1)
	   return 1;
   return 0;
}


void delete_trie(struct trienode *root,char *key)
{
 int i,k,index;	
 struct trienode *curr;
 struct stack x;
 
 curr =root;
 for(i=0;key[i]!='\0';i++)
   { index=key[i]-'a';
	  if(curr->child[index]==NULL)
	  {
		 
         return;		 
	  }
	  push(curr,index);
      curr=curr->child[index];
	}
	curr->endofword=0;
	push(curr,-1);
	
	while(1)
	{
		x=pop();
		if(x.index!=-1)
			x.m->child[x.index]=NULL;
		if(x.m==root)//if root
		break;
		k=check(x.m);
		if((k>=1)|| (x.m->endofword==1))break;
		else free(x.m);
	}
	return;
}

int check(struct trienode *x)
{
	int i,count=0;
	for(i=0;i<26;i++)
	{
		if(x->child[i]!=NULL) count++;
	}
	return count;
}

void push(struct trienode *x,int k)
{
	++top;
	s[top].m=x;
	s[top].index=k;
} 

struct stack pop()
{
	struct stack temp;
	temp=s[top--];
	return temp;
}

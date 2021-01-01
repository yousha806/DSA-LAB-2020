#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

Node *newNode(int);
void setLeft(Node*,int);
void setRight(Node*,int);

void tree_initialize(Tree *tree)
{
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node *ptr_node=tree->root, *par=NULL;
    while(ptr_node!=NULL){
        par=ptr_node;
        if(data<ptr_node->data){
            if(!ptr_node->leftThread)ptr_node=ptr_node->left;
            else break;
        }
        else{
            if(!ptr_node->rightThread)ptr_node=ptr_node->right;
            else break;
        }
    }
    if(par==NULL){
        tree->root=newNode(data);
        return ;
    }
    if(data<par->data)setLeft(par,data);
    else setRight(par,data);
}

Node *inorder_predecessor(Node *ptr)
{
    if(ptr->leftThread)return ptr->left;
    ptr=ptr->left;
    while(!ptr->rightThread)ptr=ptr->right;
    return ptr;
}

Node *inorder_successor(Node *ptr)
{
    if(ptr->rightThread)return ptr->right;
    ptr=ptr->right;
    while(!ptr->leftThread)ptr=ptr->left;
    return ptr;
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *ptr_node=tree->root;
    while(!ptr_node->leftThread)ptr_node=ptr_node->left;
    while(ptr_node!=NULL){
        printfun(ptr_node->data);
        ptr_node=inorder_successor(ptr_node);
    }
    nextline();
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *ptr_node=tree->root;
    while(!ptr_node->rightThread)ptr_node=ptr_node->right;
    while(ptr_node!=NULL){
        printfun(ptr_node->data);
        ptr_node=inorder_predecessor(ptr_node);
    }
    nextline();
}

void destroy(Node *r)
{
    //TODO
    Node *temp;
    while(r->left!=NULL)r=r->left;
    while(r!=NULL){
        temp=r;
        r=r->right;
        free(temp);
    }
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}

Node *newNode(int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->left=new_node->right=NULL;
    new_node->leftThread=new_node->rightThread=1;
    return new_node;
}

void setLeft(Node *ptr_node, int data){
    Node *new_node=newNode(data);
    new_node->left=ptr_node->left;
    ptr_node->left=new_node;
    new_node->right=ptr_node;
    ptr_node->leftThread=0;
}

void setRight(Node *ptr_node, int data){
    Node *new_node=newNode(data);
    new_node->right=ptr_node->right;
    ptr_node->right=new_node;
    new_node->left=ptr_node;
    ptr_node->rightThread=0;
}


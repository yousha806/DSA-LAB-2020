#include "poly.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void insert_at_end(List *list, int data)
{
	Node *temp,*p;//created p for traversal through ll
    temp=(Node*)malloc(sizeof(Node));//node block creation
    if(temp==NULL) return;//if allocation wrong exit
    temp->data=data;//add info
    temp->link=NULL;//end points to null
    p=list->head;//link list to p
    if(p==NULL){
        list->head=temp;//if node is empty, head points to new node
    }
    else{
    while(p->link!=NULL){
        p=p->link;//traverse till end
    }
    p->link=temp;//assign end to temp

}

list->number_of_nodes+=1;//increment no of nodes
return;
}

long long int evaluate(List *list, int x)
{
   Node *p;
   long long int sum=0;int pwr=0;
   p=list->head;
   if(p==NULL) return 0;//if empty exit
   //printf("%d",list->number_of_nodes);
   while(p!=NULL){
       sum=sum+(p->data)*pow(x,pwr);//add the evaluated part
       p=p->link;//traverse
       pwr++;

   }
   return sum;

}

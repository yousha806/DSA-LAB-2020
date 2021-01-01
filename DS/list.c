#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void init(LLIST *p1){
    p1->head=NULL;
}


int insertFirst(LLIST *p1,int e){
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->info=e;
    temp->next=p1->head;
    p1->head=temp;
    return 0;
}
int insertLast(LLIST *p1,int e){
    NODE *temp,*p;
    temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL) return 0;
    temp->info=e;
    temp->next=NULL;
    p=p1->head;
    if(p==NULL){
        p1->head=temp;
    }
    else{
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;}
    return 1;}
int delFirst(LLIST *p1,int *pe){
    NODE *p=p1->head;
    if(p1->head==NULL) return 0;
    p1->head=p->next;
    *pe=p->info;
    free(p);
    return 1;
    
}
int delLast(LLIST *p1,int *pe){
    NODE *p=p1->head;NODE *q;
    if(p1->head==NULL) return 0;
    //single node
    if(p->next==NULL){
        *pe=p->info;
        free(p);
        p1->head=NULL;
        return 1;
    }
    //multiple nodes
    q=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    q->next=NULL;
    *pe=p->info;
    free(p);
    return 1;
}
void disp(LLIST *p1){
    if(p1->head==NULL) printf("empty");
    else{
        NODE *p=p1->head;
        while(p!=NULL){
            printf("%d",p->info);
            p=p->next;
        }
    }
}
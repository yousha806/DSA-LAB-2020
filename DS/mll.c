#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int ele;
    int col;
    struct node *next;
}NODE;
typedef struct list{
    NODE *head;
    NODE *tail;
    struct list *down;
}LIST;

void init(LIST **pl){
    *pl=NULL;
}
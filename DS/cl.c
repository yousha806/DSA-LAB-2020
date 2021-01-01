#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int info;
    struct node *next;
}NODE;
typedef struct clist{
    NODE *head;

}CLIST;
void init(CLIST *p1){
    p1->head=NULL;
}
void create(CLIST *p1){
    NODE *p,*temp;char ch;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->info=-1;
    temp->next=temp;
    p1->head=temp;
    while((ch=getchar())!='\n')
    {
        temp=(NODE *)malloc(sizeof(NODE));
        temp->info=ch-'0';
        p=p1->head;
        p->next=temp;

    }
}
void disp(CLIST *p1){
    if(p1->head==NULL) printf("empty");
    else{
        NODE *p=p1->head->next;
        while(p->info!=-1){
            printf("%d",p->info);
            p=p->next;

        }}
           
}
void add(CLIST *p1,CLIST *p2,CLIST *p3){
    NODE *p,*q,*r,*temp;
    int carry=0,sum;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->info=-1;
    temp->next=temp;
    p3->head=temp;
    p=p1->head->next;
    q=p2->head->next;
    while(p->info!=-1 && q->info!=-1){
        sum=p->info+q->info+carry;
        temp=(NODE *)malloc(sizeof(NODE));
        temp->info=sum%10;
       // r=p3->head;
        temp->next=r->next;
        carry=sum/10;
        p=p->next;
        q=q->next;

    }


int main(){
    CLIST n1,n2,sum;
    init(&n1);
    init(&n2);
    init(&sum);
    printf("Enter a number");
    create(&n1);
    disp(&n1);
    printf("Enter another number");
    create(&n2);
    disp(&n2);
    printf("\n");
    disp(&sum);
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node{
    int coeff,power;
    struct node *next;
}NODE;

typedef struct list{
    NODE *head;
    NODE *tail;
}LIST;

void init(LIST *p1){
    p1->head=NULL;
    p1->tail=NULL;
}
void create(LIST *p1){
    NODE *temp;
    int wish;
    do{
        temp=(NODE *)malloc(sizeof(NODE));
        printf("enter the coeff and power for the term");
        scanf("%d %d",&temp->coeff,&temp->power);
        temp->next=NULL;
        if(p1->head==NULL){
            p1->head=temp;
            p1->tail=temp;
        }
        else{
            p1->tail->next=temp;
            p1->tail=temp;
        }
        printf("do you want to add another term");
        scanf("%d",&wish);
    }while(wish);
}

void disp(LIST *p1){
    NODE *p=p1->head;
    if(p1->head==NULL) printf("empty");
    else{
        while(p!=NULL){
            printf("%dx^%d+ ",p->coeff,p->power);
            p=p->next;
        }
    }
}

double eval(LIST *p1,int x){
    double sum=0.0;
    NODE *p=p1->head;
    if(p==NULL) return 0;
    while(p!=NULL){
        sum=sum+p->coeff*pow(x,p->power);
        p=p->next;
    }
    return sum;
}
void add(LIST *p1,LIST *p2,LIST *p3){
    NODE *p,*q,*r,*temp;
    p=p1->head;
    q=p2->head;
    r=p3->head;
    while(p!=NULL && q!=NULL){
        temp=(NODE *)malloc(sizeof(NODE));
        temp->next=NULL;
        if(p->power==q->power){
            temp->coeff=p->coeff+q->coeff;
            temp->power=p->power;
            p=p->next;
            q=q->next;
        }
        else if(p->power>q->power){
            temp->coeff=p->coeff;
            temp->power=p->power;
            p=p->next;
        }
        else if(p->power<q->power){
            temp->coeff=q->coeff;
            temp->power=p->power;
            q=q->next;

        }
        if(r==NULL){
            p3->head=temp;
            p3->tail=temp;
        }
        else{
            p3->tail->next=temp;
            p3->tail=temp;
        }
    }
    while(p!=NULL){
        temp=(NODE *)malloc(sizeof(NODE));
        temp->next=NULL;
        temp->coeff=p->coeff;
        temp->power=p->power;
        p=p->next;
    }
    while(q!=NULL){
        temp=(NODE *)malloc(sizeof(NODE));
        temp->next=NULL;
        temp->coeff=q->coeff;
        temp->power=q->power;
        q=q->next;
    }

}

int main(void){
    LIST lobj,lobj1,lobj2;
    init(&lobj);
    init(&lobj1);
    init(&lobj2);
    create(&lobj);
    disp(&lobj);
    create(&lobj1);
    disp(&lobj1);
    printf("%lf",eval(&lobj,2));
    add(&lobj,&lobj1,&lobj2);
    disp(&lobj2);

}
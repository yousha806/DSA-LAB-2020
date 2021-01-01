#include<stdio.h>
int main(void){
    DLIST dobj;// int a[]={2,3,12,5,24,32};
    init(&dobj);
    creat(&dobj,a);
    disp(&dobj);

}
void creat(DLIST *pd1,int a){
    do
    {   NODE *temp,*p;
        temp=(NODE *)malloc(sizeof(NODE));
        printf("enter the info");
        scanf("%d",&temp->info);
        p=pd1->head;
        if(p==NULL|| temp->info<p->info){

        }
        else{
            while(p!=NULL && temp->info<p->info){
                q=p;
                p=p->next;
            }
            if(p=NULL)
        }

    }

}
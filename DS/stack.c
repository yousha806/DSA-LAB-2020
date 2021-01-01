#include<stdio.h>
#define MAX 5
typedef struct stack{
    int s[MAX];
    int top;

}STACK;
int push(STACK *ps,int e){
    if(ps->top==MAX-1)
        return 0;
    ps->top++;
    ps->s[ps->top]=e;
    return 1;
}
int pop(STACK *ps,int *pe){
    if(ps->top==-1)
        return 0;
    *pe=ps->s[ps->top];
    ps->top--;
    return 1;
}
int isEmpty(STACK *ps){
    return ps->top==-1;
}
int stackTop(STACK *ps,int *pe){
    if(ps->top==-1) return 0;
    *pe=ps->s[ps->top];
    return 1;

}
void disp(STACK *ps){
    if(isEmpty(ps)) printf("Empty");
    else{
        int i=0;
        while(i<=ps->top){
            printf("%d ",ps->s[i]);
            i++;
        }
    }
}
void init(STACK *ps){
    ps->top=-1;
}
int main(){
    STACK sobj;int choice,ele,t;//instance of stack
    init(&sobj);//top =-1;
    do{
        printf("\n1.push 2.Pop 3.Empty 4.Peep 5.Disp\n");
        printf("Choose the option\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter element to be pushed");
            scanf("%d",&ele);
            t=push(&sobj,ele);
            if(t==0) printf("overflow");
            else printf("push is successful");
            break;
            case 2: t=pop(&sobj,&ele);
            if(t==0) printf("underflow");
            else printf("popped elemt is %d",ele);
            break;
            case 3: if(isEmpty(&sobj)) printf("empty");
            else printf("not empty");
            break;
            case 4: t=stackTop(&sobj,&ele);
            if(!t) printf("empty");
            else printf("peeped ele is %d",ele);
            break;
            case 5: disp(&sobj);
        }
    }while(choice<6);
}
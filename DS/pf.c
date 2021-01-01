#include<stdio.h>
#include<ctype.h>
typedef struct stack{
    float s[10];
    int top;
}STACK;
void init(STACK *ps){
    ps->top=-1;
}
int push(STACK *ps,float e){
    if(ps->top==9) return 0;
    ps->top++;
    ps->s[ps->top]=e;
    return 1;
}
int pop(STACK *ps,float *pe){
    if(ps->top==-1) return 0;
    *pe=ps->s[ps->top];
    ps->top--;
    return 1;
}
int main()
{
    char postfix[50];
    int i;STACK sobj;float op1,op2,res;
    init(&sobj);
    printf("enter the postfix string");
    scanf("%s",postfix);
    i=0;
    while(postfix[i]!='\0'){
        if(isdigit(postfix[i])){
            push(&sobj,postfix[i]-'0');
        }
        else{
            pop(&sobj,&op2);
            pop(&sobj,&op1);
            switch(postfix[i]){
                case '+':res=op1+op2;break;
                case '-':res=op1-op2;break;
                case '*':res=op1*op2;break;
                case '/':res=op1/op2;break;
            }
            push(&sobj,res);
            

        }
    i++;
    }pop(&sobj,&res);
    printf("evaluated value is %f",res);
    return 0;
}
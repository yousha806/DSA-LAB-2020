#include "6b.h"
stack* stack_initialize(int size)
{
//TODO
stack *ptr_stack;
ptr_stack=(stack*)malloc(sizeof(stack));
ptr_stack->arr=(int*)malloc(size*sizeof(int));
//ptr_stack->arr[size];
ptr_stack->top=-1;
return ptr_stack;
}

void stack_push(stack *ptr_stack, int key) 
{
//TODO
if(ptr_stack->top==sizeof(ptr_stack->arr)) return;
ptr_stack->top++;
ptr_stack->arr[ptr_stack->top]=key;
}

void stack_pop(stack *ptr_stack)
{
//TODO
if(ptr_stack->top==-1) return;
ptr_stack->top--;
}

int stack_is_empty(stack *ptr_stack)
{
//TODO
if(ptr_stack->top==-1){
    return 1;
}
else return 0;

}

int stack_peek(stack *ptr_stack) 
{
//TODO
return(ptr_stack->arr[ptr_stack->top]);
}

void stack_destroy(stack *ptr_stack) 
{
//TODO
free(&ptr_stack);
free(&ptr_stack->arr);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
//TODO
stack *ptr_stack;
ptr_stack=stack_initialize(strlen(source_infix));
char sym;
int i=0,j=0;
stack_push(ptr_stack,-1);
int ip;
int sp;
while(source_infix[i]!='\0'){
    sym=source_infix[i];
goto ip1;
goto sp1;
while(sp>ip){
    target_postfix[j++]=stack_peek(ptr_stack);
    stack_pop(ptr_stack);goto ip1;goto sp1;
if(sp!=ip){
    stack_push(ptr_stack,sym);}
else stack_pop(ptr_stack);
i++;

goto ip1;goto sp1;}
goto ip1;goto sp1;}
while(stack_is_empty(ptr_stack)!=1){
    target_postfix[j++]=stack_peek(ptr_stack);
    stack_pop(ptr_stack);
}
target_postfix[j]='\0';
ip1:
switch(sym)
	 {
	case '+':
	case '-': ip= 1;
	case '*':
	case '/': ip= 3;
	case '^': ip= 6;
	case '(': 
    case '{':
    case '[': ip= 9;
	case ')': 
    case '}':
    case ']': ip= 0;
	default : ip= 7;
		 }
	
sp1:
switch(stack_peek(ptr_stack))
	{
	case '+':
	case '-': sp= 2;
	case '*':
	case '/': sp= 4;
	case '^': sp= 5;
	case '(':
    case '{':
    case '[': sp= 0;
	case '#': sp= -1;
	default : sp= 8;
	}}
      //stack_destroy(&ptr_stack);}
/*int input_prec(char ch)
{
	 switch(ch)
	 {
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 3;
	case '^': return 6;
	case '(': return 9;
	case ')': return 0;
	default : return 7;
		 }
}
int stack_prec(char ch)
{
	 switch(ch)
	 {
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 4;
	case '^': return 5;
	case '(': return 0;
	case '#': return -1;
	default : return 8;
	}
}
}*/

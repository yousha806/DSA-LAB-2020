#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
//TODO	
ptr_List->head=NULL;
ptr_List->number_of_Nodes=0;
}

void List_insert_front(List* ptr_List, int data) 
{
//TODO	
Node *temp;
temp=create_Node(data,ptr_List->head);
ptr_List->head=temp;
ptr_List->number_of_Nodes++;
}

const int Node_get_data(Node *Node_ptr) 
{
	//TODO

return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{Node *p;
p=ptr_List->head;
if(p==NULL) return;
else{
    ptr_List->head=p->link;
    free(p);
    ptr_List->number_of_Nodes--;
	//TODO
}}

void List_destroy(List* ptr_List) 
{
	//TODO
Node *p=ptr_List->head;
Node *q=NULL;
while(p!=NULL){
    q=p;
    p=p->link;
    free(q);}
}


void stack_initialize(Stack *ptr_stack) 
{
	// TODO
ptr_stack->ptr_List=(List*)malloc(sizeof(List));
List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	// TODO
List_insert_front(ptr_stack->ptr_List,key);
}

void stack_pop(Stack *ptr_stack) 
{
	// TODO
List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack) 
{
	// TODO
if(ptr_stack->ptr_List->head==NULL){
    return 1;
}
else return 0;
}

const int stack_peek(Stack *ptr_stack)
{
	// TODO

return (Node_get_data(ptr_stack->ptr_List->head));

}

void stack_destroy(Stack *ptr_stack) 
{
	// TODO
List_destroy(ptr_stack->ptr_List);
}

int postfix_eval(const char* expression) 
{
   int i,res,a,b;Stack ptr_stack;
   stack_initialize(&ptr_stack);
   char ch;
   
   while(expression[i]!='\0'){
	   ch=expression[i];//printf("%c",ch);
	   if(ch>='0'&&ch<='9'){
		   stack_push(&ptr_stack,ch-'0');
	   }
	   else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
		   a=stack_peek(&ptr_stack);//printf("\t%d",a);
		   stack_pop(&ptr_stack);
		   b=stack_peek(&ptr_stack);//printf("\t%d",b);
		   stack_pop(&ptr_stack);
		   switch (ch) /* ch is an operator */
            {
            case '*':
                res = b * a;
                break;

            case '/':
                res = b / a;
                break;

            case '+':
                res = b + a;
                break;

            case '-':
                res = b - a;
                break;
            }
			stack_push(&ptr_stack,res);
			
			

	   }
	i++;
   }
   res=stack_peek(&ptr_stack);//printf("this is res end:%d",res);
   stack_pop(&ptr_stack);
   stack_destroy(&ptr_stack);
   return res;}

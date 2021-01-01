#include "5a.h"
/*YOUSHA MAHAMUNI PES2UG19CS468*/
static Node* create_Node(int data, Node* link)
 {
// TODO - create and allocate dynamic space
Node *temp;
temp=(Node *)malloc(sizeof(Node));
temp->data=data;
temp->link=link;
return temp;

}
void list_initialize(List* ptr_list) 
{
//TODO - initialize structure members to default values
ptr_list->head=NULL;
ptr_list->number_of_Nodes=0;
}

void list_insert_front(List* ptr_list, int data) 
{
//TODO - perform linked list implementation of push operation.
Node *temp;
temp=create_Node(data,ptr_list->head);
ptr_list->head=temp;
ptr_list->number_of_Nodes++;

}


const int Node_get_data(Node *Node_ptr) 
{
//TODO - return the top most element

return Node_ptr->data;
}


void list_delete_front(List* ptr_list) 
{
//TODO - perform linked list implementation of pop operation.
Node *p;
p=ptr_list->head;
if(p==NULL) return;
else{
    ptr_list->head=p->link;
    free(p);
    ptr_list->number_of_Nodes--;

}
}


void list_destroy(List* ptr_list) 
{
//TODO - free the allocated space
Node *p=ptr_list->head;
Node *q=NULL;
while(p!=NULL){
    q=p;
    p=p->link;
    free(q);
}
}

void Stack_initialize(Stack *ptr_Stack) 
{
//TODO - get the memory allocation for stack, and intern call list initialize
ptr_Stack->ptr_list=(List*)malloc(sizeof(List));
list_initialize(ptr_Stack->ptr_list);

}

void Stack_push(Stack *ptr_Stack, int key) 
{
//TODO	 - call the function list_insert_front
list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack *ptr_Stack) 
{
//TODO- call the function list_delete_front
list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
//TODO	- return 0 if stack is not empty
if(ptr_Stack->ptr_list->head==NULL){
    return 1;
}
else return 0;
}

const int Stack_peek(Stack *ptr_Stack) 
{
//TODO	- return the top most element of the stack
return (Node_get_data(ptr_Stack->ptr_list->head));
}

void Stack_destroy(Stack *ptr_Stack)
 {
//TODO	- deallocate
list_destroy(ptr_Stack->ptr_list);
}

int match_parenthesis(const char* string)
{
//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
Stack ptr_Stack; 
Stack_initialize(&ptr_Stack);
while((*string)!='\0'){

    switch(*string){
        case '(': Stack_push(&ptr_Stack,0);break;
        case '{':Stack_push(&ptr_Stack,1);break;
        case '[': Stack_push(&ptr_Stack,2);break;
        case ')': if(Stack_is_empty(&ptr_Stack))return 0;
                  if(Stack_peek(&ptr_Stack)==0){
                  Stack_pop(&ptr_Stack);}
                  else
                    return 0;
                  break;
        //break;
        
        case '}': if(Stack_is_empty(&ptr_Stack))return 0;
                  if(Stack_peek(&ptr_Stack)==1){
                  Stack_pop(&ptr_Stack);}
                  else
                    return 0;
                  break;
        //break;
        case ']': if(Stack_is_empty(&ptr_Stack))return 0;
                  if(Stack_peek(&ptr_Stack)==2){
                  Stack_pop(&ptr_Stack);}
                  else
                    return 0;
                  break;
        //break;
        default:break;
    }
++(string);
}


if(Stack_is_empty(&ptr_Stack)) {
    Stack_destroy(&ptr_Stack);
    return 1;}}
/*else{
    Stack_destroy(&ptr_Stack);
    return 0;
}*/
	


 


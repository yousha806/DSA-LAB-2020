#include "6b.h"
stack* stack_initialize(int size)
{
//TODO 
 stack * ptr_stack =  (stack*) malloc (sizeof(stack));  

 ptr_stack->arr=(int*)malloc(size*sizeof(int));  
 
 ptr_stack->top=-1;
  
  return ptr_stack;

}

void stack_push(stack *ptr_stack, int key) 
{
//TODO 
  ptr_stack->top++; 
  ptr_stack->arr[ptr_stack->top]=key;
}

void stack_pop(stack *ptr_stack)
{
//TODO  
  if(stack_is_empty(ptr_stack))
    {
        return;
    }
    ptr_stack->top--;
}

int stack_is_empty(stack *ptr_stack)
{
//TODO 
    if(ptr_stack->top==-1){ 
        return 1;
    } 
    else{ 
        return 0;
    }
}

int stack_peek(stack *ptr_stack) 
{
//TODO 
  return (ptr_stack->arr[ptr_stack->top]);
}

void stack_destroy(stack *ptr_stack) 
{
//TODO 
    free(ptr_stack);
    free(ptr_stack->arr);
} 

int input_prec(char val)
{
	switch(val)
	{
        
        case '*': return 30; 
        break;
        case '/': return 30; 
        break;
        case '^': return 65; 
        break;
        case '[':return 90; 
        break;
        case '{':return 90; 
        break;
        case '(': return 90; 
        break;
        case '}':return 5; 
        break;
        case ']':return 5; 
        break;
        case ')': return 5; 
        break;
        case '+': return 10; 
        break;
        case '-': return 10; 
        break;
        default : return 70; 
        break;
	}
}

int stack_prec(char val)
{
	switch(val)
	{
        case '^': return 50; 
        break; 
        case '+': return 20; 
        break;
        case '-': return 20; 
        break;
        case '{': return 5; 
        break;
        case '[': return 5; 
        break;
        case '(': return 5;  
        break;
        case '*': return 40; 
        break;
        case '/': return 40; 
        break;
        case '#': return -1; 
        break;
        default : return 80; 
        break;
	}
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
//TODO  
   stack *final_stack = stack_initialize(strlen(source_infix));
	int k; 
	stack_push(final_stack, '#'); 
    k=0;

	while((*source_infix)!='\0')
	{   
        while(stack_prec(stack_peek(final_stack))>input_prec((*source_infix)))
        {
            target_postfix[k++]=stack_peek(final_stack);
            stack_pop(final_stack);
        }
        
        if(stack_prec(stack_peek(final_stack))!=input_prec((*source_infix)))
        {
            stack_push(final_stack, (*source_infix));
        }
        
        else if(stack_prec(stack_peek(final_stack))==input_prec((*source_infix))){
            stack_pop(final_stack);
        }
        source_infix++;
    }
	
	while(stack_peek(final_stack)!='#'){
		target_postfix[k++]=stack_peek(final_stack);
        stack_pop(final_stack);
    }
    target_postfix[k]='\0';
    /*stack *final_stack;  
    final_stack= stack_initialize(strlen(source_infix));
    *target_postfix ='0';  
    
    int count=0;

    while( (*source_infix)!= '\0' ){ 
        if( ((*source_infix)>=65 && (*source_infix)<=90) || ((*source_infix)>=97 && (*source_infix)<=122) ){ 
            strcat(target_postfix,source_infix);
        } 

        else{  
            if(count==0){ 
                stack_push(final_stack,*source_infix); 
                count++; 
                continue;
            } 

            if((*source_infix)=='*'){ 
                if( stack_peek(final_stack)=='/' || stack_peek(final_stack)=='+' || stack_peek(final_stack)=='-' || stack_peek(final_stack)=='*'){ 
                    stack_push(final_stack,*source_infix);
                }  
              } 

            else if((*source_infix)=='/'){ 
                if( stack_peek(final_stack)=='*' || stack_peek(final_stack)=='+' || stack_peek(final_stack)=='-'){ 
                    stack_push(final_stack,*source_infix);
                }
            } 

        else if((*source_infix)=='+'){ 
            if( stack_peek(final_stack)=='+' || stack_peek(final_stack)=='-' ){ 
                stack_push(final_stack,*source_infix);
            } 

            else if(stack_peek(final_stack)=='*' || stack_peek(final_stack)=='/'){ 
                int check_for_end=stack_is_empty(final_stack); 

                while(check_for_end!=1){ 
                    char append=(stack_peek(final_stack));
                    char*append_pointer=&append;
                    strcat(target_postfix,append_pointer); 
                    stack_pop(final_stack); 
                    check_for_end=stack_is_empty(final_stack);
                } 
            }
        } 
        else if((*source_infix)=='-'){ 
            if( stack_peek(final_stack)=='+' || stack_peek(final_stack)=='-' ){ 
                stack_push(final_stack,*source_infix);
            } 

            else if(stack_peek(final_stack)=='*' || stack_peek(final_stack)=='/'){ 
                int check_for_end=stack_is_empty(final_stack); 

                while(check_for_end!=1){ 
                    char append=(stack_peek(final_stack));
                    char*append_pointer=&append;
                    strcat(target_postfix,append_pointer); 
                    stack_pop(final_stack); 
                    check_for_end=stack_is_empty(final_stack);
                } 
            }
        }
      } 
      source_infix++;    
    } 
     
    int check_for_end=stack_is_empty(final_stack); 

    while(check_for_end!=1){ 
        char append=(stack_peek(final_stack));
        char*append_pointer=&append;
        strcat(target_postfix,append_pointer); 
        stack_pop(final_stack); 
        check_for_end=stack_is_empty(final_stack);
    }*/

}
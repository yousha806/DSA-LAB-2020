#include <stdio.h>
#include <stdlib.h>
//Linear Queue or Simple Queue
#define Max 5


int remove1(int[],int *,int *);
void display(int[],int*,int*);
int insert(int [],int *,int *,int);

int main()
{ 
	int q[Max];
	int front =-1;
    int rear=-1;
	int choice,x,k;

	printf("Enter 1-> Insert\n\t2-> Pop\n\t3-> Display\n\t4->Peek\n");
	
	while(1)
	{	
    scanf("%d",&choice);
	switch(choice)
	{
		case 1:{ printf("Enter the element to Insert..");
		         scanf("%d",&x);
				 k=insert(q,&front,&rear,x);
                 if(k>0) printf("Successful Insertion..");

				} break;
		case 2:{ if(front==-1&& rear==-1)printf("Empty Queue");
		         else { remove1(q,&front,&rear);		
				      }
		             }break;	
		case 3:{ printf("The elements on the queue are ..");
                 display(q,&front,&rear);		
				} break;
		case 4:{ if(front==-1)printf("Empty Queue");
		         else display(q,&front,&rear);			
				      } break;	
		default: exit(0);
	}
  }
	
}
int remove1(int que[],int *f,int *r){
    int x;
    if(*f==*r){
    x=que[*f];*r=-1;*f=-1;}
    else{
        x=que[*f];
        (*f)++;}
    return x;
}
void display(int que[],int*f,int*r){
    int i;
    if ((*f)==-1&&(*r)==-1){
        printf("Empty Queue");
    }
    else for(i=*f;i<=*r;i++){
        printf("\t%d",que[i]);
    }

return;
}
int insert(int que[],int *f,int *r,int x){
    if(*r==Max-1)
        {printf("Queue Full");return -1;}
    else{
        if(*f==-1 &&*r==-1) (*f)++;
            (*r)++;
            que[*r]=x;

    }
    return 1;

}
/*void push(int s1[Max],int *top1,int x)
{
	if(*top1==Max-1) printf("Stack Overflow");			  
	else {
		  (*top1)++;
		  s1[*top1]=x;
	     }
}

int pop(int s1[Max],int *top1)
{int x;
		x=s1[*top1];
		(*top1)--;
		return x;
}

void display(int s1[Max],int *top1)
{int i;
	if(*top1==-1){printf("Empty Stack");
				return;
			   }
	else {
		for (i=*top1;i>=0;i--)
			printf("\t%d",s1[i]);
	}
}

int peek(int s1[Max],int *top1)
{
	if(*top1==-1)
	 return -1;
	else return s1[*top1];	
}*/

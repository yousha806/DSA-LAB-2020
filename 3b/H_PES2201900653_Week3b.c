//YOUSHA MAHAMUNI PES2UG19CS468
#include"dll.h"
int count_nodes(List* dll)
{   int cnt;
    cnt=dll->number_of_nodes;//stores the no of nodes
	return cnt;
	
}

void insert_front(List* dll, int data)
{
    Node *temp;
    temp=(Node *)malloc(sizeof(Node));
    if(temp==NULL) return;//memory misallocation exit
    temp->next=dll->head;//newnode pointing to original head
    temp->prev=NULL;//prev to NULL 
    temp->data=data;//adding info
    if(dll->head!=NULL){
        dll->head->prev=temp;//setting prev of original head to temp
    }
    dll->head=temp;//head now is temp
    dll->number_of_nodes+=1;//increment number of nodes
    return;
}


void dllist_delete_beginning(List* list)
{
    Node *p;//for traversal
    p=list->head;
    if(p==NULL) return;//if empty exit
    list->head=p->next;//delink the head from original 
    if(list->head!=NULL){//if list not single node
        list->head->prev=NULL;//set previous to null
    }
    list->number_of_nodes-=1;//decrement after deleting
    return;


}

//YOUSHA MAHAMUNI PES2UG19CS468
void position_delete(List* dll, int pos)
{
  Node* p;//p for traversal
  p = dll->head;
  if(p==NULL ||pos<0 || pos>dll->number_of_nodes-1){
      return;
  }
  for(int i=0;p!=NULL && i<pos;i++){
      p=p->next;
  }//printf("%d",pos);
  if(pos==0){
      dllist_delete_beginning(dll);//for head node deletion
  }
  if(p->next!=NULL){
      p->next->prev=p->prev;//as long as its not the last node this will delete
  }
  if(p->prev!=NULL){
      p->prev->next=p->next;//this is to help delete last node as well
  }
  //return;

}

int search_list(List* dll,int key)
{
    Node *p;int cnt=0;
    p=dll->head;
    while(p!=NULL){
        if(p->data==key) return cnt;//checks if matches and returns offset
        p=p->next;//if not traverses
        cnt++;
    }//YOUSHA MAHAMUNI PES2UG19CS468
    return -1;//if nothing found
    
}


void reverse_list(List* dll)
{
    Node *temp,*p;
    temp=NULL;
    p=dll->head;
    if(p==NULL) return;
    if(dll->head->next==NULL) return;//only single node, no need to reverse
    while(p!=NULL){
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        p=p->prev;//YOUSHA MAHAMUNI PES2UG19CS468
    }
    if(temp!=NULL){
        dll->head=temp->prev;
    }
  return;
}



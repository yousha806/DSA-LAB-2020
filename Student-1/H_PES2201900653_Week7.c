#include "queue.h"
static node *create_node(int id, int time, node *link)
{
//TODO
node *temp;
temp=(node *)malloc(sizeof(node));
temp->id=id;
temp->time=time;
temp->link=link;

return temp;

}

void list_initialize(List *ptr_list)
{
//TODO
//ptr_list=(List *)malloc(sizeof(List));
ptr_list->head=NULL;
ptr_list->tail=NULL;
ptr_list->number_of_nodes=0;

}
const int node_get_id(node *node_ptr)
{
//TODO	
return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
//TODO	
return node_ptr->time;	
}

void list_insert_rear(List *ptr_list, int id, int time)
{
//TODO	
node *temp;
node *link;link=NULL;
temp=create_node(id,time,link);
if(ptr_list->head==NULL){
	ptr_list->head=temp;
	ptr_list->tail=temp;return;
}
ptr_list->tail->link=temp;
ptr_list->tail=temp;
ptr_list->number_of_nodes++;
}

void list_delete_front(List *ptr_list)
{
//TODO	
node *q;
if(ptr_list->head==NULL) return;
//q=ptr_list->head;
q=create_node(ptr_list->head->id,ptr_list->head->time,ptr_list->head->link);


ptr_list->head=(ptr_list->head)->link;

if(ptr_list->head==NULL){
	ptr_list->tail=NULL;return;
}
/*if (ptr_list->head->link==NULL){
	ptr_list->head=NULL;
	ptr_list->tail=NULL;
}
ptr_list->head=ptr_list->head->link;
*/ptr_list->number_of_nodes--;
free(q);
return;
}

void list_destroy(List *ptr_list)
{
//TODO
node *p=ptr_list->head;
node *q=NULL;
while(p!=NULL){
    q=p;
    p=p->link;
    free(q);	
}}

void queue_initialize(Queue *queue_list)
{
//TODO	
queue_list->ptr_list=(List *)malloc(sizeof(List));
list_initialize(queue_list->ptr_list);

	}

void queue_enqueue(Queue *ptr, int id, int time)
{
//TODO	
list_insert_rear(ptr->ptr_list,id,time);
	}

void queue_dequeue(Queue *ptr)
{
//TODO		
list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
//TODO
if(ptr->ptr_list->head==NULL)	{
	return 1;
}
else return 0;
}

void queue_peek(Queue *ptr)
{
//TODO	
if(!queue_is_empty(ptr)){
printf("%d %d\n",ptr->ptr_list->head->id,ptr->ptr_list->head->time);
}
else{	
printf("Empty Queue\n");
return;}
}

void queue_destroy(Queue *ptr)
{
//TODO
//ptr->ptr_list->head=ptr->ptr_list->tail=NULL;
list_destroy(ptr->ptr_list);
//free(ptr);		
}

const int queue_find_person(Queue *ptr_queue, int t)
{
//TODO
int time_counter,y=1;
time_counter=0;
int time_sum;

while((!queue_is_empty(ptr_queue))&&y==1){

	time_counter+=node_get_time(ptr_queue->ptr_list->head);
	if(time_counter<=t){
		queue_dequeue(ptr_queue);
	}
	else y=0;

	 


}
if((queue_is_empty(ptr_queue))){
	printf("Empty Queue\n");return 0;
}

printf("%d\n",ptr_queue->ptr_list->head->id);return ptr_queue->ptr_list->head->id;

}
/*void list_destroy(List *ptr_list)
{
//TODO
}*/

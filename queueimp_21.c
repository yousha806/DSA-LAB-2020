#include "queue.h"
static node *create_node(int id, int time, node *link)
{
//TODO
	node * temp = (node *)malloc(sizeof(node));
	temp->id = id;
	temp->time = time;
	temp->link = link;
	return temp;
}
void list_initialize(List *ptr_list)
{
//TODO
	ptr_list->head = NULL;
	ptr_list->number_of_nodes = 0;
	ptr_list->tail = NULL;
	return;
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
	node * temp = create_node(id, time, NULL);
	(ptr_list->number_of_nodes)++;
	if(ptr_list->head == NULL){
		ptr_list->head = temp;
		ptr_list->tail = temp;

		return;
	}
	(ptr_list->tail)->link = temp;
	ptr_list->tail = temp;
	return;
}

void list_delete_front(List *ptr_list)
{
//TODO	
	if(ptr_list->head == NULL)
		return;

	node * temp = ptr_list->head;
	ptr_list->head = temp->link;
	free(temp);

	(ptr_list->number_of_nodes)--;
	return;
}

void list_destroy(List *ptr_list)
{
//TODO	
	node * temp, * current;
	current = NULL;
	temp = ptr_list->head;

	for(int i=0; i<ptr_list->number_of_nodes; i++){
		current = temp;
		temp = temp->link;
		free(current);
		ptr_list->number_of_nodes -= 1;
	}
	free(ptr_list);
	return;

}

void queue_initialize(Queue *queue_list)
{
//TODO
	queue_list->ptr_list = (List *)malloc(sizeof(List));
	list_initialize(queue_list->ptr_list);
	return;

}

void queue_enqueue(Queue *ptr, int id, int time)
{
//TODO	
	list_insert_rear(ptr->ptr_list, id, time);
	return;

    }

void queue_dequeue(Queue *ptr)
{
//TODO	
	
	list_delete_front(ptr->ptr_list);
	return;

    }

int queue_is_empty(Queue *ptr)
{
//TODO
	if((ptr->ptr_list->number_of_nodes) == 0)
		return 1;
	return 0; 
}

void queue_peek(Queue *ptr)
{
//TODO		
	if(queue_is_empty(ptr)==1){
		printf("Empty Queue\n");
		return;
	}

	printf("%d %d\n",ptr->ptr_list->head->id, ptr->ptr_list->head->time);
	return;
	
    }

void queue_destroy(Queue *ptr)
{
//TODO		
	list_destroy(ptr->ptr_list);
	return;
    }


const int queue_find_person(Queue *ptr_queue, int t)
{
//TODO		
	int k = 0;
	while(k < t){
		if(queue_is_empty(ptr_queue) == 1){
			printf("Empty Queue\n");
			return -1;
		}
		k += node_get_time(ptr_queue->ptr_list->head);

		if(k >= t)
			break;
		queue_dequeue(ptr_queue);
	}
	if(queue_is_empty(ptr_queue) == 1){
		printf("Empty Queue\n");
		return -1;
	}
	printf("%d\n", ptr_queue->ptr_list->head->id);
	return ptr_queue->ptr_list->head->id;
}
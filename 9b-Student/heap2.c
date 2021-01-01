


#include "heap.h"
heap* heap_construct(int n){
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}
void heap_destruct(heap* tmp){
    //TODO
    tmp->capacity=0;
    tmp->size=0;
    free(tmp);
}
int heap_get_capacity(heap* tmp){
    //TODO
    return tmp->capacity;
}
int heap_get_size(heap* tmp){
    //TODO
    return tmp->size;
}

int heap_insert(heap* tmp,int data){
    //TODO
    if(tmp->size==tmp->capacity) return 0;
    int i=tmp->size;
    tmp->elements[i]=data;
    tmp->size++;
    int parent=(i-1)/2;
    while(i!=0 &&tmp->elements[i]<tmp->elements[parent]){
        tmp->elements[i]=tmp->elements[parent];
        i=parent;
        parent=(i-1)/2;


    }

    return 1;
}
int heap_get_min(heap* tmp){
    //TODO
    return (tmp->elements[0]);
}
void heap_remove(heap* tmp){
    //TODO
    //int i,j=0,k;//variables for minheapify
    //need to replace root with last element
    tmp->elements[0]=tmp->elements[heap_get_size(tmp)-1];
    tmp->size--;
    /*int *h=tmp->elements;
    k=h[j];
    i=2*j+1;
    while(i<((heap_get_size(tmp))-1)){
        if((i+1)<=((heap_get_size(tmp)-1)))//right child exists
			if(h[i+1]<h[i])
				i++; 			
							
		if(k>h[i])
		{
			h[j]=h[i];
			j=i;
			i=2*j+1;
		}
		else
			break;//already min is on top, already sorted 
	}
	h[j]=k; 
    

return;*/
adjust_heap(tmp->elements,tmp->size);
}

void adjust_heap(int *h,int count)
{
	int i, j, key;
	j=0;
	key=h[j]; 
	i=2*j+1; // left child
	while(i<=count-1) //as long as left child exist
	{
		if((i+1)<=count-1)//right child exists
			if(h[i+1]<h[i])
				i++; 			
							
		if(key>h[i])
		{
			h[j]=h[i];
			j=i;
			i=2*j+1;
		}
		else
			break;//already min is on top, already sorted 
	}
	h[j]=key; 
}

#include "cll.h"//Yousha Mahamuni PES2UG19CS468
void position_insert(List* cll, int data, int pos)
{
	Node *temp,*p;//temp is the new node, p is for traversal
	p = cll->head;//linking p with the list 
    temp = create_node(data);//calling create node function
    if(temp==NULL) return;//checking if memory allocated correctly

    if (pos < 0 || pos > cll->length) return;//checking if pos out of bounds

    if (pos == 0) {//adding to head
        if (cll->head == NULL) {//if list is empty
            cll->head = temp;
            cll->head->next = cll->head;//linking end to itself
	cll->length ++;
        } else {
            p = cll->head;
            while (p->next != cll->head){
            p = p->next;}
            p->next = temp;//adding the node and linking the ends 
            temp->next = cll->head;
            cll->head = temp;
	cll->length ++;//incrememnting numer of nodes
        }
    } else {
        p = cll->head;
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
	cll->length ++;
    }
}




void position_delete(List* cll, int pos)
{
Node *temp,*p;//temp is the node which will be deleted, p is for traversal
    p = cll->head;

    if (pos < 0 || pos >= cll->length || p == NULL) return;
    if (pos == 0) { 
        while (p->next != cll->head)//while u have not reached the end of list
            p = p->next;
        if (cll->head == p) {//delete head node
            free(cll->head);
            cll->head = NULL;
	    cll->length --;//decrement
        } 
	else {
            p->next = cll->head->next;
            free(cll->head);
            cll->head = p->next;
	    cll->length --;
        }
    } else {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        temp = p->next;
        p->next = temp->next;
        free(temp);
        temp = NULL;
	cll->length --;
    }
}


int josephus(List* cll, int k)
{
Node *l1, *l2;
       int i;
    l1 =cll->head;
    l2 =cll-> head;
    if(l2!=NULL){
       while (l2->next != l2)//while not last node
       {
           for (i = 0; i <= k; i++)//traverse through while mainting i as count
           {
               l1 = l2;
               l2 = l2->next;
           }
           l1->next = l2->next;
           free(l2);//deleting the node
           cll->length--;//decrementing length
           l2 = l1->next;
       }
       cll->head = l2;
       return (l2->data);//returning the data of node in particular positon.
    }
    else{
    	return -1;	//l2 is empty.
    }}



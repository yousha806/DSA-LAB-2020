#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
//TODO

	Node *t,*p;
	p = cll->head;
    t = (Node *)malloc(sizeof(Node));
    t->data = data;

    if (pos < 0 || pos > cll->length || t == NULL)
	{return;
}

    if (pos == 0) {
        if (cll->head == NULL) {
            cll->head = t;
            cll->head->next = cll->head;
	cll->length ++;
        } else {
            p = cll->head;
            while (p->next != cll->head)
                p = p->next;
            p->next = t;
            t->next = cll->head;
            cll->head = t;
	cll->length ++;
        }
    } else {
        p = cll->head;
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
	cll->length ++;
    }
}

void position_delete(List* cll, int pos)
{
	//TODO
    Node *q,*p;
    p = cll->head;

    if (pos < 0 || pos >= cll->length || p == NULL)
        return ;
    if (pos == 0) { 
        while (p->next != cll->head)
            p = p->next;
        if (cll->head == p) {
            free(cll->head);
            cll->head = NULL;
	    cll->length --;
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
        q = p->next;
        p->next = q->next;
        free(q);
        q = NULL;
	cll->length --;
    }
}

int josephus(List* cll, int k)
{
//TODO
	Node *p, *q;
       int i;
    
    q =cll->head;
    p =cll-> head;
    if(p!=NULL){
       while (p->next != p)
       {
           for (i = 0; i <= k; i++)
           {
               q = p;
               p = p->next;
           }
           q->next = p->next;
          
           free(p);
           cll->length--;
           p = q->next;
       }
       cll->head = p;
       return (p->data);
    }

       
    else{
    	return -1;	
    }

}



typdef struct node {
    int info;
    struct node *next, *prev;
}NODE;
typedef struct dlist
{
    NODE *head;

}DLIST;

void init(DLIST *pd1);
int insertFirst(DLIST *pd1,int e);
int insertEnd(DLIST *pd1,int e);
int insertAfter(DLIST *pd1,int giveninfo,int e);//insert after information
int insertBefore(DLIST *pd1,int giveninfo,int e);//insert before information
int insertAfterPosn(DLIST *pd1,int posn,int e);
int insertBeforePosn(DLIST *pd1,int posn,int e);
int delFirst(DLIST *pd1,int *pe);
int delLast(DLIST *pd1,int *pe);
int delGivenPosn(DLIST *pd1,int *pe);
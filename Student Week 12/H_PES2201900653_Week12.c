#include "hash.h"
//PES2UG19CS468
HashTable *create_table(int size)
{
    //TODO
    int i;
    HashTable * htable = (HashTable*)malloc(sizeof(*htable));
    htable->size=size;
    htable->table=(int *)malloc(sizeof(int) * size);
    for(i=0;i<htable->size;i++) htable->table[i]=-1;
    return htable;
}

void insert(HashTable *htable, int element)
{
    //TODO
     int k;
     k=element%(htable->size);
    if(htable==NULL) return;
      while(htable->table[k]!=0 && htable->table[k]!=-1 )
    {
        ++k;
        k=k%(htable->size);    
    } htable->table[k]=element;
    return ;
}

int search(HashTable *htable, int element)
{
      //TODO
    int k;
    k=element%(htable->size);
   while(htable->table[k]!=-1 ){
        if(htable->table[k]==element)
        return 1;
        ++k;
        k=k%(htable->size);
   }
       return 0;
}

void delete (HashTable *htable, int element)
{
    //TODO
        int k;
        k=element%(htable->size);
    if(htable->table[k]==element)
    {
        htable->table[k]=-1;
        }
    else
        return;
}


void destroy_table(HashTable *htable)
{
    //TODO
    free(htable);

}

//Implementation for session1_seq_search.h
#include<stdio.h>
#include "ss.h"
//Search for the first occurrence of key in arr
//Returns the 0-based index of the first occurrence of key in arr on successful search.
//Otherwise, returns -1.
int seqsearch(int *arr, int n, int key) 
	{ //Program to find the position of the key and return it
    //pos variable is defined to keep count of the position of the array;
    //once the key element is found and matched, position is returned breaking the loop.
        for(int pos=0;pos<n;pos++){
            if(arr[pos]==key) return pos;  
        }
        return -1;/*If input of number of elements is 0, or if the key is not found in the array -1 is returned*/
    }
	
	
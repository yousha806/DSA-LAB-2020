#include "bfs.h"
#include<stdio.h>

int visited[100];
int y = 0;

int check_path(int **graph, int n, int v, int u)
{
    int j;
    

    if(y == 0)
    {
        int i;
        //int length=0;
        for(i=1; i<=n; i++) //initialise
            visited[i] = 0;
        y = 1;
    }
    
    
    visited[v] = 1;
    for(j=1; j<=n; j++)
    {
        if((graph[v][j] == 1) && (visited[j] == 0))
        {
           
           if((j == u)||check_path(graph, n, j, u))
             return 1;
        }
     }
    
    return 0;
}
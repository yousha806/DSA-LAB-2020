#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
	//TODO
	int visited[5]={0};
	int f=0,r=-1;
	int q[5];
	q[++r]=v;
	visited[v]=1;

	while(f<=r){
		int x=q[f++];
		if(x==u) return 1;
		for(int i=0;i<n;i++){
			if(graph[x][i]&&!visited[i]){
				q[++r]=1;
				visited[i]=1;
			}
		}
	}
	return 0;
}	

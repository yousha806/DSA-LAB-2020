#include<stdio.h>
int bfs(int s, int adj[5][5],int visited[5],int n,int d)
{
  int q[5],f=0,r=-1;//queue Data structuref>r is q empty condition
  q[++r]=s;
  visited[s]=1;
  while(f<=r)// q is not empty
   { 
    int x=q[f++];
    if(x==d) return 1;
    for(int i=0;i<n;i++)
     { if(adj[x][i] && !visited[i])
        { q[++r]=i;
          visited[i]=1;
        }
     }
    }
   return 0;
 }
      
  
void main()
{
 int adj[5][5];
 int visited[5]={0};
 int n,i,j,s,d,res;
 printf("enter the no of vertices");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
  scanf("%d",&adj[i][j]);
 printf("enter the src and dst vertices to find if a path exists");
 scanf("%d %d",&s,&d);
 res=bfs(s,adj,visited,n,d);
 if(res)
  printf("path exists between %d and %d",s,d);
 else
  printf("path does not exist between %d and %d",s,d);
}
